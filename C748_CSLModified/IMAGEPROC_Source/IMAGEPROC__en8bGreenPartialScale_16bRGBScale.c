/*
 * IMAGEPROC__en8bGreenPartialScale_16bRGBScale.c
 *
 *  Created on: 31/08/2019
 *      Author: Lalo
 */






#include "ImageProcessing.h"

#define OPT (8)
IMAGPROC_nStatus IMAGEPROC__en8bGreenPartialScale_16bRGBScale(LCDC_TFT_TypeDef*psLayerSourceGreen,LCDC_TFT_TypeDef *psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{

    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;
    int32_t s32Index=0;

    uint16_t u16DimX0=sDim.X[0];
    uint16_t u16DimX1=sDim.X[1];
    uint16_t u16DimY0=sDim.Y[0];
    uint16_t u16DimY1=sDim.Y[1];

    uint32_t u32LayerSourceGreenWidthTotal=psLayerSourceGreen->layerWidthTotal;
    uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    uint32_t u32LayerSourceGreenHeightTotal=psLayerSourceGreen->layerHeightTotal;
    uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    uint16_t u16DimWidth=sDim.width;
    uint16_t u16DimHeight=sDim.height;

    uint16_t u16Green = 0;
    uint8_t u8Mod=0;

    if((psLayerDest->variableType != VARIABLETYPE_enUSHORT) || (psLayerSourceGreen->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;

    if(u16DimX0>u32LayerSourceGreenWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceGreenHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceGreenWidthTotal)
        u16DimWidth= u32LayerSourceGreenWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceGreenHeightTotal)
        u16DimHeight= u32LayerSourceGreenHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;


    Cache__vWbInvL2 ((uint32_t)psLayerSourceGreen->layerDataAddress,psLayerSourceGreen->layerWidthTotal*psLayerSourceGreen->layerHeightTotal);
       u8Mod=(u16DimWidth*u16DimHeight)%OPT;
    if(u8Mod)
        u8Mod=OPT-u8Mod;
    uint8_t* restrict pu8LayerSourceGreen=(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint16_t* restrict pu16LayerDest =(uint16_t *) memalign(1024*1024,sizeof(uint16_t)*u16DimWidth*u16DimHeight+u8Mod);

    uint8_t* pu8LayerSourceGreenInitial =pu8LayerSourceGreen;
    uint16_t* pu16LayerDestInitial =pu16LayerDest;

    if((pu8LayerSourceGreenInitial == 0) || (pu16LayerDestInitial==0))
    {
        free(pu16LayerDestInitial);
        free(pu8LayerSourceGreenInitial);
        return IMAGPROC_enALLOCERROR;
    }

    Cache__vWbInvL2 ((uint32_t)pu8LayerSourceGreen,u16DimWidth*u16DimHeight);

    sLayer.layerWidthTotal=u16DimWidth;
    sLayer.layerHeightTotal=u16DimHeight;
    sLayer.variableType=VARIABLETYPE_enUCHAR;
    sDimLayer.X[1]=0;
    sDimLayer.Y[1]=0;
    sDimLayer.width=u16DimWidth;
    sDimLayer.height=u16DimHeight;

    sDimLayer.X[0]=u16DimX0;
    sDimLayer.Y[0]=u16DimY0;
    sLayer.layerDataAddress=(uint32_t)pu8LayerSourceGreen;
    LCDC__enLayer_Copy(psLayerSourceGreen,&sLayer,sDimLayer);


    _nassert ((int)(pu8LayerSourceGreen) % 8 == 0);
    _nassert ((int)(pu16LayerDest) % 8 == 0);

    #pragma UNROLL(OPT)
    #pragma MUST_ITERATE (OPT,,OPT)
    for(s32Index=0;s32Index<(u16DimHeight*u16DimWidth)+u8Mod;s32Index++)
    {
        u16Green=*((uint8_t*)pu8LayerSourceGreen);
        if(u16Green>0x3F)
            u16Green=0x3F;
        u16Green<<=5;
        *((uint16_t*)pu16LayerDest)&= ~0x07E0;
        *((uint16_t*)pu16LayerDest)|= (u16Green);

         pu8LayerSourceGreen++;
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
    free(pu8LayerSourceGreenInitial);
    return IMAGPROC_enOK;
}














