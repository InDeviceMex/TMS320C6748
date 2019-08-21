/*
 * IMAGEPROC__en8bGrayScale_16bGrayScale.c
 *
 *  Created on: 21/08/2019
 *      Author: Lalo
 */



#include "ImageProcessing.h"



IMAGPROC_nStatus IMAGEPROC__en8bGrayScale_16bGrayScale(LCDC_TFT_TypeDef *restrict psLayerSource, LCDC_TFT_TypeDef *restrict psLayerDest,LCDC_DIMENSIONS_TypeDef sDim)
{

    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;
    register uint32_t u32Index=0;

    register  uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    register uint16_t u16All=0;
    register uint8_t  u8Aux=0;
    if((psLayerSource->variableType != VARIABLETYPE_enUCHAR) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;
    Cache__vWbInvL2 ((uint32_t)psLayerSource->layerDataAddress,psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal);

    register uint8_t* restrict pu8LayerSource=(uint8_t *) memalign(4,sizeof(uint8_t)*u16DimWidth*u16DimHeight);
    register uint16_t* restrict pu16LayerDest =(uint16_t *) memalign(4,sizeof(uint16_t)*u16DimWidth*u16DimHeight);

    register uint8_t* restrict pu8LayerSourceInitial =pu8LayerSource;
    register uint16_t* restrict pu16LayerDestInitial =pu16LayerDest;

    Cache__vWbInvL2 ((uint32_t)pu8LayerSource,u16DimWidth*u16DimHeight);

    sLayer.layerWidthTotal=u16DimWidth;
    sLayer.layerHeightTotal=u16DimHeight;
    sLayer.variableType=VARIABLETYPE_enUCHAR;
    sDimLayer.X[1]=0;
    sDimLayer.Y[1]=0;
    sDimLayer.width=u16DimWidth;
    sDimLayer.height=u16DimHeight;

    sDimLayer.X[0]=u16DimX0;
    sDimLayer.Y[0]=u16DimY0;
    sLayer.layerDataAddress=(uint32_t)pu8LayerSource;
    LCDC__enLayer_Copy(psLayerSource,&sLayer,sDimLayer);

    #pragma UNROLL(8)
    for(u32Index=0;u32Index<u16DimHeight*u16DimWidth;u32Index++)
    {
            u8Aux=*((uint8_t*)pu8LayerSource);
            u16All =((uint16_t)u8Aux<<8)&0xF800;
            pu8LayerSource++;
            u16All|=((uint16_t)u8Aux<<3)&0x07E0;
            u16All|=((uint16_t)u8Aux>>3)&0x001F;
            *((uint16_t*)pu16LayerDest)= u16All;
            pu16LayerDest++;
    }
    Cache__vWbL2 ((uint32_t)pu16LayerDestInitial,u16DimHeight*u16DimWidth*2);

    sLayer.variableType=VARIABLETYPE_enUSHORT;
    sDimLayer.X[1]=u16DimX1;
    sDimLayer.Y[1]=u16DimY1;
    sDimLayer.width=u16DimWidth;
    sDimLayer.height=u16DimHeight;

    sDimLayer.X[0]=0;
    sDimLayer.Y[0]=0;
    sLayer.layerDataAddress=(uint32_t)pu16LayerDestInitial;
    LCDC__enLayer_Copy(&sLayer,psLayerDest,sDimLayer);

    free(pu16LayerDestInitial);
    free(pu8LayerSourceInitial);
    return IMAGPROC_enOK;
}