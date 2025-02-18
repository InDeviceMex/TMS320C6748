/*
 * IMAGEPROC__en8bAddMean.c
 *
 *  Created on: 03/09/2019
 *      Author: Lalo
 */



#include "ImageProcessing.h"


#define OPT (88)
IMAGPROC_nStatus IMAGEPROC__en8bAddMean(LCDC_TFT_TypeDef* psLayerSource1,LCDC_TFT_TypeDef* psLayerSource2, LCDC_TFT_TypeDef* psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, uint8_t u8Umbral)
{

    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;
    int32_t s32Index=0;

    uint16_t u16DimX0=sDim.X[0];
    uint16_t u16DimX1=sDim.X[1];
    uint16_t u16DimX2=sDim.X[2];
    uint16_t u16DimY0=sDim.Y[0];
    uint16_t u16DimY1=sDim.Y[1];
    uint16_t u16DimY2=sDim.Y[2];

    uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
    uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
    uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
    uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

    uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    uint16_t u16DimWidth=sDim.width;
    uint16_t u16DimHeight=sDim.height;

    uint16_t u16Value = 0;
    uint8_t u8Value1 = 0;
    uint8_t u8Value2 = 0;
    uint8_t  u8Result = 0;

    uint8_t u8Mod=0;
    if((psLayerSource1->variableType != VARIABLETYPE_enUCHAR) || (psLayerSource2->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerDest->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vWbInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal);
    Cache__vWbInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal);
    u8Mod=(u16DimWidth*u16DimHeight)%OPT;
    if(u8Mod)
        u8Mod=OPT-u8Mod;

    uint8_t* restrict pu8LayerSource1 =(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*(u16DimWidth*u16DimHeight+u8Mod));
    uint8_t* restrict pu8LayerSource2 =(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*(u16DimWidth*u16DimHeight+u8Mod));
    uint8_t* restrict pu8LayerDest =(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*(u16DimWidth*u16DimHeight+u8Mod));

    uint8_t* restrict pu8LayerSource1Initial =pu8LayerSource1;
    uint8_t* restrict pu8LayerSource2Initial =pu8LayerSource2;
    uint8_t* pu8LayerDestInitial =pu8LayerDest;

    if((pu8LayerSource1Initial == 0) ||(pu8LayerSource2Initial == 0) ||  (pu8LayerDestInitial==0))
    {
        free(pu8LayerDestInitial);
        free(pu8LayerSource2Initial);
        free(pu8LayerSource1Initial);
        return IMAGPROC_enALLOCERROR;
    }

    Cache__vWbInvL2 ((uint32_t)pu8LayerSource1,u16DimWidth*u16DimHeight);
    Cache__vWbInvL2 ((uint32_t)pu8LayerSource2,u16DimWidth*u16DimHeight);

    sLayer.layerWidthTotal=u16DimWidth;
    sLayer.layerHeightTotal=u16DimHeight;
    sDimLayer.width=u16DimWidth;
    sDimLayer.height=u16DimHeight;

    sDimLayer.X[1]=0;
    sDimLayer.Y[1]=0;
    sDimLayer.X[0]=u16DimX0;
    sDimLayer.Y[0]=u16DimY0;
    sLayer.variableType=VARIABLETYPE_enUCHAR;
    sLayer.layerDataAddress=(uint32_t)pu8LayerSource1;
    LCDC__enLayer_Copy(psLayerSource1,&sLayer,sDimLayer);

    sDimLayer.X[1]=0;
    sDimLayer.Y[1]=0;
    sDimLayer.X[0]=u16DimX1;
    sDimLayer.Y[0]=u16DimY1;
    sLayer.variableType=VARIABLETYPE_enUCHAR;
    sLayer.layerDataAddress=(uint32_t)pu8LayerSource2;
    LCDC__enLayer_Copy(psLayerSource2,&sLayer,sDimLayer);

    _nassert ((int)(pu8LayerSource1) % 8 == 0);
    _nassert ((int)(pu8LayerSource2) % 8 == 0);
    _nassert ((int)(pu8LayerDest) % 8 == 0);

    #pragma UNROLL(OPT)
    #pragma MUST_ITERATE (OPT,,OPT)
    for(s32Index=0;s32Index<(u16DimHeight*u16DimWidth)+u8Mod;s32Index++)
    {
        u8Value1=*((uint8_t*)pu8LayerSource1);
        u8Value2=*((uint8_t*)pu8LayerSource2);
        pu8LayerSource1++;
        pu8LayerSource2++;

        u16Value=(u8Value1+u8Value2+1)>>1;
        u8Result=(uint8_t)u16Value;
        if(u8Result>u8Umbral)
            u8Result=u8Umbral;

        *((uint8_t*)pu8LayerDest)=u8Result;
        pu8LayerDest++;

    }

    Cache__vWbL2 ((uint32_t)pu8LayerDestInitial, u16DimHeight*u16DimWidth);

    sLayer.variableType=VARIABLETYPE_enUCHAR;
    sDimLayer.X[1]=u16DimX2;
    sDimLayer.Y[1]=u16DimY2;
    sDimLayer.X[0]=0;
    sDimLayer.Y[0]=0;
    sLayer.layerDataAddress=(uint32_t)pu8LayerDestInitial;
    LCDC__enLayer_Copy(&sLayer,psLayerDest,sDimLayer);

    free(pu8LayerDestInitial);
    free(pu8LayerSource2Initial);
    free(pu8LayerSource1Initial);
    return IMAGPROC_enOK;
}






