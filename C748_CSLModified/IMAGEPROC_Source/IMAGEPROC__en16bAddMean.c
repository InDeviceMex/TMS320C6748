/*
 * IMAGEPROC__en16bAddMean.c
 *
 *  Created on: 21/08/2019
 *      Author: Lalo
 */


#include "ImageProcessing.h"

IMAGPROC_nStatus IMAGEPROC__en16bAddMean(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{

    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;
    register uint32_t u32Index=0;

    register uint16_t u16Value1 = 0;
    register uint16_t u16Value2 = 0;
    register uint32_t u32Byte1 = 0;
    register uint32_t u32Byte2 = 0;

    register uint32_t u32Aux = 0;
    register uint16_t u16Result = 0;


    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];

     uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
     uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
     uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
     uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

     uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
     uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    if((psLayerSource1->variableType != VARIABLETYPE_enUSHORT) || (psLayerSource2->variableType != VARIABLETYPE_enUSHORT)
            || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
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

    Cache__vWbInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal*2);
    Cache__vWbInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal*2);

    register uint16_t* restrict pu16LayerSource1 =(uint16_t *) memalign(4,sizeof(uint16_t)*u16DimWidth*u16DimHeight);
    register uint16_t* restrict pu16LayerSource2 =(uint16_t *) memalign(4,sizeof(uint16_t)*u16DimWidth*u16DimHeight);
    register uint16_t* restrict pu16LayerDest =(uint16_t *) memalign(4,sizeof(uint16_t)*u16DimWidth*u16DimHeight);

    register uint16_t* restrict pu16LayerSource1Initial =pu16LayerSource1;
    register uint16_t* restrict pu16LayerSource2Initial =pu16LayerSource2;
    register uint16_t* restrict pu16LayerDestInitial =pu16LayerDest;

    Cache__vWbInvL2 ((uint32_t)pu16LayerSource1,u16DimWidth*u16DimHeight*2);
    Cache__vWbInvL2 ((uint32_t)pu16LayerSource2,u16DimWidth*u16DimHeight*2);

    sLayer.layerWidthTotal=u16DimWidth;
    sLayer.layerHeightTotal=u16DimHeight;
    sDimLayer.width=u16DimWidth;
    sDimLayer.height=u16DimHeight;

    sDimLayer.X[1]=0;
    sDimLayer.Y[1]=0;
    sDimLayer.X[0]=u16DimX0;
    sDimLayer.Y[0]=u16DimY0;
    sLayer.variableType=VARIABLETYPE_enUSHORT;
    sLayer.layerDataAddress=(uint32_t)pu16LayerSource1;
    LCDC__enLayer_Copy(psLayerSource1,&sLayer,sDimLayer);

    sDimLayer.X[1]=0;
    sDimLayer.Y[1]=0;
    sDimLayer.X[0]=u16DimX1;
    sDimLayer.Y[0]=u16DimY1;
    sLayer.variableType=VARIABLETYPE_enUSHORT;
    sLayer.layerDataAddress=(uint32_t)pu16LayerSource2;
    LCDC__enLayer_Copy(psLayerSource2,&sLayer,sDimLayer);
#pragma UNROLL(8)
    for(u32Index=0;u32Index<u16DimHeight*u16DimWidth;u32Index++)
    {
        u16Value1=*((uint16_t*)pu16LayerSource1);
        pu16LayerSource1++;

        u32Byte1 =(u16Value1&0x001F);
        u32Byte1|=(u16Value1&0x07E0)<<3;
        u16Value2=*((uint16_t*)pu16LayerSource2);
        pu16LayerSource2++;
        u32Byte1|=(u16Value1&0xF800)<<5;
        u32Byte2 =(u16Value2&0x001F);
        u32Byte2|=(u16Value2&0x07E0)<<3;
        u32Byte2|=(u16Value2&0xF800)<<5;

        u32Aux=_avgu4(u32Byte1,u32Byte2);

        u16Result=u32Aux &0x001F;
        u16Result|=(u32Aux>>3)&0x07E0;
        u16Result|=(u32Aux>>5)&0xF800;
        *((uint16_t*)pu16LayerDest)= u16Result;
        pu16LayerDest++;
    }
    Cache__vWbL2 ((uint32_t)pu16LayerDestInitial, u16DimHeight*u16DimWidth*2);

    sLayer.variableType=VARIABLETYPE_enUSHORT;
    sDimLayer.X[1]=u16DimX1;
    sDimLayer.Y[1]=u16DimY1;
    sDimLayer.X[0]=0;
    sDimLayer.Y[0]=0;
    sLayer.layerDataAddress=(uint32_t)pu16LayerDestInitial;
    LCDC__enLayer_Copy(&sLayer,psLayerDest,sDimLayer);

    free(pu16LayerDestInitial);
    free(pu16LayerSource2Initial);
    free(pu16LayerSource1Initial);
    return IMAGPROC_enOK;
}


