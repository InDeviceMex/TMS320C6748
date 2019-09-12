/*
 * IMAGEPROC__en16bMeanNormRGB.c
 *
 *  Created on: 05/09/2019
 *      Author: Lalo
 */




#include <ImageProcessing.h>


#define OPT (8)
IMAGPROC_nStatus IMAGEPROC__en16bMeanNormRGB(LCDC_TFT_TypeDef *psLayerSource,LCDC_DIMENSIONS_TypeDef sDim, float* fRGB,IMAGEPROC_nNormalize enNorm)
{
    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;
    int32_t s32Index=0;

    uint16_t u16DimX0=sDim.X[0];
    uint16_t u16DimY0=sDim.Y[0];

    uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    uint16_t u16DimWidth=sDim.width;
    uint16_t u16DimHeight=sDim.height;

    uint16_t u16Value = 0;
    uint8_t u8Blue=0;
    uint8_t u8Green=0;
    uint8_t u8Red=0;

    uint32_t u32RedMean = 0;
    uint32_t u32GreenMean = 0;
    uint32_t u32BlueMean = 0;
    uint16_t u16Mean = 0;
    float fRedMean = 0;
    float fGreenMean = 0;
    float fBlueMean = 0;
    float fMean = 0;


    fRGB[0]=0;
    fRGB[1]=0;
    fRGB[2]=0;

    uint8_t u8Mod=0;
    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    Cache__vWbInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);
    u8Mod=(u16DimWidth*u16DimHeight)%OPT;
    if(u8Mod)
        u8Mod=OPT-u8Mod;
    uint16_t* restrict pu16LayerSource =(uint16_t *) memalign(8,sizeof(uint16_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint16_t* pu16LayerSourceInitial =pu16LayerSource;


    Cache__vWbInvL2 ((uint32_t)pu16LayerSource,u16DimWidth*u16DimHeight*2);
    sLayer.layerWidthTotal=u16DimWidth;
    sLayer.layerHeightTotal=u16DimHeight;
    sDimLayer.width=u16DimWidth;
    sDimLayer.height=u16DimHeight;

    sDimLayer.X[1]=0;
    sDimLayer.Y[1]=0;
    sDimLayer.X[0]=u16DimX0;
    sDimLayer.Y[0]=u16DimY0;
    sLayer.variableType=VARIABLETYPE_enUSHORT;
    sLayer.layerDataAddress=(uint32_t)pu16LayerSource;
    LCDC__enLayer_Copy(psLayerSource,&sLayer,sDimLayer);
    _nassert ((int)(pu16LayerSource) % 8 == 0);

    #pragma MUST_ITERATE (0,OPT,)
    for(s32Index=0;s32Index<u8Mod;s32Index++)
        *((uint16_t*)pu16LayerSource+(u16DimHeight*u16DimWidth)+s32Index)=0;

    #pragma UNROLL(OPT)
    #pragma MUST_ITERATE (OPT,,OPT)
    for(s32Index=0;s32Index<(u16DimHeight*u16DimWidth)+u8Mod;s32Index++)
    {
        u16Value=*((uint16_t*)pu16LayerSource);
        pu16LayerSource++;

        u8Blue =((u16Value&0x001F)<<1)+1; //blue
        u8Green=((u16Value&0x07E0)>>5);   //green
        u8Red  =((u16Value&0xF800)>>10)+1; //red

        u32BlueMean+= u8Blue;
        u32GreenMean+=u8Green;
        u32RedMean  +=u8Red;
    }

    u32BlueMean/=(u16DimHeight*u16DimWidth); //blue
    u32GreenMean/=(u16DimHeight*u16DimWidth);   //green
    u32RedMean/=(u16DimHeight*u16DimWidth); //red

    if(enNorm==IMAGEPROC_enNORM1)
    {

        fMean=u32RedMean+u32GreenMean+u32BlueMean;
        fMean/=3;

        if(u32RedMean!=0)
            fRedMean=(float)fMean/(float)u32RedMean;
        if(u32GreenMean!=0)
            fGreenMean=(float)fMean/(float)u32GreenMean;
        if(u32BlueMean!=0)
            fBlueMean=(float)fMean/(float)u32BlueMean;
    }

    if(enNorm==IMAGEPROC_enNORM2)
    {
        u16Mean=u32RedMean;
        if(u32GreenMean>u16Mean)
            u16Mean=u32GreenMean;
        if(u32BlueMean>u16Mean)
            u16Mean=u32BlueMean;

        if(u32RedMean!=0)
            fRedMean=(float)u16Mean/(float)u32RedMean;
        if(u32GreenMean!=0)
            fGreenMean=(float)u16Mean/(float)u32GreenMean;
        if(u32BlueMean!=0)
            fBlueMean=(float)u16Mean/(float)u32BlueMean;

    }
    if(enNorm==IMAGEPROC_enNORM3)
    {
        fMean=sqrt((u32RedMean)*(u32RedMean)+(u32GreenMean)*(u32GreenMean)+(u32BlueMean)*(u32BlueMean));
        if(fMean!=0)
        {
            fRedMean=(float)(u32RedMean)/(float)fMean;
            fGreenMean=(float)(u32GreenMean)/(float)fMean;
            fBlueMean=(float)(u32BlueMean)/(float)fMean;
        }


        fMean=fRedMean;
        if(fGreenMean>fMean)
            fMean=fGreenMean;
        if(fBlueMean>fMean)
            fMean=fBlueMean;

        if(fRedMean!=0)
            fRedMean=(float)fMean/(float)fRedMean;

        if(fGreenMean!=0)
            fGreenMean=(float)fMean/(float)fGreenMean;

        if(fBlueMean!=0)
            fBlueMean=(float)fMean/(float)fBlueMean;

    }
    if(enNorm==IMAGEPROC_enNORM4)
    {

        if(u32RedMean!=0)
            fRedMean=63.0/(float)(u32RedMean);
        if(u32GreenMean!=0)
            fGreenMean=63.0/(float)u32GreenMean;
        if(u32BlueMean!=0)
            fBlueMean=63.0/(float)(u32BlueMean);
    }
    fRGB[0]=fRedMean;
    fRGB[1]=fGreenMean;
    fRGB[2]=fBlueMean;
    free(pu16LayerSourceInitial);
    return IMAGPROC_enOK;
}








