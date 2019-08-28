/*
 * IMAGEPROC__en8bSubtractionABS.c
 *
 *  Created on: 21/08/2019
 *      Author: Lalo
 */



#include "ImageProcessing.h"

IMAGPROC_nStatus IMAGEPROC__en8bSubtractionABS(LCDC_TFT_TypeDef* psLayerSource1,LCDC_TFT_TypeDef* psLayerSource2, LCDC_TFT_TypeDef* psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{

    LCDC_TFT_TypeDef sLayerSource1;
    LCDC_DIMENSIONS_TypeDef sDimLayer1;
    uint32_t u32Index=0;


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

    int16_t s16Value = 0;

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
    Cache__vWbInvL2 ((uint32_t)psLayerSource1->layerDataAddress,psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal);
    Cache__vWbInvL2 ((uint32_t)psLayerSource2->layerDataAddress,psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal);

    uint8_t* restrict pu8LayerSource1 =(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*u16DimWidth*u16DimHeight+32);
    uint8_t* restrict pu8LayerSource2 =(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*u16DimWidth*u16DimHeight+32);
    uint8_t* restrict pu8LayerDest =(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*u16DimWidth*u16DimHeight+32);

    uint8_t* restrict pu8LayerSource1Initial =pu8LayerSource1;
    uint8_t* restrict pu8LayerSource2Initial =pu8LayerSource2;
    uint8_t* restrict pu8LayerDestInitial =pu8LayerDest;
    Cache__vWbInvL2 ((uint32_t)pu8LayerSource1,u16DimWidth*u16DimHeight);
    Cache__vWbInvL2 ((uint32_t)pu8LayerSource2,u16DimWidth*u16DimHeight);

    sLayerSource1.layerWidthTotal=u16DimWidth;
    sLayerSource1.layerHeightTotal=u16DimHeight;
    sLayerSource1.variableType=VARIABLETYPE_enUCHAR;
    sDimLayer1.X[1]=0;
    sDimLayer1.Y[1]=0;
    sDimLayer1.width=u16DimWidth;
    sDimLayer1.height=u16DimHeight;

    sDimLayer1.X[0]=u16DimX0;
    sDimLayer1.Y[0]=u16DimY0;
    sLayerSource1.layerDataAddress=(uint32_t)pu8LayerSource1;
    LCDC__enLayer_Copy(psLayerSource1,&sLayerSource1,sDimLayer1);

    sLayerSource1.layerDataAddress=(uint32_t)pu8LayerSource2;
    sDimLayer1.X[0]=u16DimX1;
    sDimLayer1.Y[0]=u16DimY1;
    LCDC__enLayer_Copy(psLayerSource2,&sLayerSource1,sDimLayer1);
    _nassert ((int)(pu8LayerSource1) % 8 == 0);
    _nassert ((int)(pu8LayerSource2) % 8 == 0);
    _nassert ((int)(pu8LayerDest) % 8 == 0);

    #pragma UNROLL(16)
    #pragma MUST_ITERATE (16,,16)
    for(u32Index=0;u32Index<(u16DimHeight*u16DimWidth);u32Index++)
    {

            s16Value=*((uint8_t*)pu8LayerSource1);
            pu8LayerSource1++;
            s16Value-=*((uint8_t*)pu8LayerSource2);
            pu8LayerSource2++;
            if(s16Value<0)
                s16Value=-s16Value;
            *((uint8_t*)pu8LayerDest)=(uint8_t)s16Value;
            pu8LayerDest++;
    }

    Cache__vWbL2 ((uint32_t)pu8LayerDestInitial,u16DimHeight*u16DimWidth);

    sDimLayer1.X[1]=u16DimX2;
    sDimLayer1.Y[1]=u16DimY2;
    sDimLayer1.width=u16DimWidth;
    sDimLayer1.height=u16DimHeight;

    sDimLayer1.X[0]=0;
    sDimLayer1.Y[0]=0;
    sLayerSource1.layerDataAddress=(uint32_t)pu8LayerDestInitial;
    LCDC__enLayer_Copy(&sLayerSource1,psLayerDest,sDimLayer1);

    free(pu8LayerDestInitial);
    free(pu8LayerSource2Initial);
    free(pu8LayerSource1Initial);
    return IMAGPROC_enOK;
}

