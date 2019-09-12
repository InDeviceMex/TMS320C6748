/*
 * IMAGEPROC__en16bMaxRGB.c
 *
 *  Created on: 05/09/2019
 *      Author: Lalo
 */



#include <ImageProcessing.h>


#define OPT (4)
IMAGPROC_nStatus IMAGEPROC__en16bMaxRGB(LCDC_TFT_TypeDef *psLayerSource,LCDC_DIMENSIONS_TypeDef sDim, float* fRGB,IMAGEPROC_nNormalize enNorm)
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

    uint8_t u8RedMax = 0;
    uint8_t u8GreenMax = 0;
    uint8_t u8BlueMax = 0;
    uint16_t u16Max = 0;
    float fRedMax = 0;
    float fGreenMax = 0;
    float fBlueMax = 0;
    float fMax = 0;


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

        if(u8Blue>u8BlueMax)
            u8BlueMax=u8Blue;

        if(u8Green>u8GreenMax)
            u8GreenMax=u8Green;

        if(u8Red>u8RedMax)
            u8RedMax=u8Red;
    }

    if(enNorm==IMAGEPROC_enNORM1)
    {

        fMax=u8RedMax+u8GreenMax+u8BlueMax;
        fMax/=3;

        if(u8RedMax!=0)
            fRedMax=(float)fMax/(float)u8RedMax;
        if(u8GreenMax!=0)
            fGreenMax=(float)fMax/(float)u8GreenMax;
        if(u8BlueMax!=0)
            fBlueMax=(float)fMax/(float)u8BlueMax;
    }

    if(enNorm==IMAGEPROC_enNORM2)
    {
        u16Max=u8RedMax;
        if(u8GreenMax>u16Max)
            u16Max=u8GreenMax;
        if(u8BlueMax>u16Max)
            u16Max=u8BlueMax;

        if(u8RedMax!=0)
            fRedMax=(float)u16Max/(float)u8RedMax;
        if(u8GreenMax!=0)
            fGreenMax=(float)u16Max/(float)u8GreenMax;
        if(u8BlueMax!=0)
            fBlueMax=(float)u16Max/(float)u8BlueMax;

    }
    if(enNorm==IMAGEPROC_enNORM3)
    {
        fMax=sqrt((u8RedMax)*(u8RedMax)+(u8GreenMax)*(u8GreenMax)+(u8BlueMax)*(u8BlueMax));
        if(fMax!=0)
        {
            fRedMax=(float)(u8RedMax)/(float)fMax;
            fGreenMax=(float)(u8GreenMax)/(float)fMax;
            fBlueMax=(float)(u8BlueMax)/(float)fMax;
        }


        fMax=fRedMax;
        if(fGreenMax>fMax)
            fMax=fGreenMax;
        if(fBlueMax>fMax)
            fMax=fBlueMax;

        if(fRedMax!=0)
            fRedMax=(float)fMax/(float)fRedMax;

        if(fGreenMax!=0)
            fGreenMax=(float)fMax/(float)fGreenMax;

        if(fBlueMax!=0)
            fBlueMax=(float)fMax/(float)fBlueMax;

    }
    if(enNorm==IMAGEPROC_enNORM4)
    {

        if(u8RedMax!=0)
            fRedMax=63.0/(float)(u8RedMax);
        if(u8GreenMax!=0)
            fGreenMax=63.0/(float)u8GreenMax;
        if(u8BlueMax!=0)
            fBlueMax=63.0/(float)(u8BlueMax);
    }
    fRGB[0]=fRedMax;
    fRGB[1]=fGreenMax;
    fRGB[2]=fBlueMax;
    free(pu16LayerSourceInitial);
    return IMAGPROC_enOK;
}






