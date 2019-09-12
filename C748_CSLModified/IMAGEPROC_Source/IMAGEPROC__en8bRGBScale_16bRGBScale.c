/*
 * IMAGEPROC__en8bRGBScale_16bRGBScale.c
 *
 *  Created on: 27/08/2019
 *      Author: Lalo
 */


#include "ImageProcessing.h"

#define OPT (7)
IMAGPROC_nStatus IMAGEPROC__en8bRGBScale_16bRGBScale(LCDC_TFT_TypeDef*psLayerSourceRed, LCDC_TFT_TypeDef *psLayerSourceGreen,LCDC_TFT_TypeDef *psLayerSourceBlue,LCDC_TFT_TypeDef *psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{

    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;
    int32_t s32Index=0;

    uint16_t u16DimX0=sDim.X[0];
    uint16_t u16DimX1=sDim.X[1];
    uint16_t u16DimX2=sDim.X[2];
    uint16_t u16DimX3=sDim.X[3];
    uint16_t u16DimY0=sDim.Y[0];
    uint16_t u16DimY1=sDim.Y[1];
    uint16_t u16DimY2=sDim.Y[2];
     uint16_t u16DimY3=sDim.Y[3];

    uint32_t u32LayerSourceRedWidthTotal=psLayerSourceRed->layerWidthTotal;
    uint32_t u32LayerSourceGreenWidthTotal=psLayerSourceGreen->layerWidthTotal;
    uint32_t u32LayerSourceBlueWidthTotal=psLayerSourceBlue->layerWidthTotal;
    uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    uint32_t u32LayerSourceRedHeightTotal=psLayerSourceRed->layerHeightTotal;
    uint32_t u32LayerSourceGreenHeightTotal=psLayerSourceGreen->layerHeightTotal;
    uint32_t u32LayerSourceBlueHeightTotal=psLayerSourceBlue->layerHeightTotal;
    uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    uint16_t u16DimWidth=sDim.width;
    uint16_t u16DimHeight=sDim.height;

    uint16_t u16Result=0;
    uint8_t u8Red = 0;
    uint8_t u8Green = 0;
    uint8_t u8Blue = 0;
    uint8_t u8Mod=0;

    if((psLayerDest->variableType != VARIABLETYPE_enUSHORT) || (psLayerSourceRed->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerSourceGreen->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerSourceBlue->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;

    if(u16DimX3>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceRedWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerSourceBlueWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSourceGreenWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY3>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY0>u32LayerSourceRedHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSourceGreenHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerSourceBlueHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX3)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX3;
    if((u16DimHeight+ u16DimY3)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY3;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceRedWidthTotal)
        u16DimWidth= u32LayerSourceRedWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceRedHeightTotal)
        u16DimHeight= u32LayerSourceRedHeightTotal- u16DimY0;


    if((u16DimWidth+ u16DimX1)>u32LayerSourceGreenWidthTotal)
        u16DimWidth= u32LayerSourceGreenWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSourceGreenHeightTotal)
        u16DimHeight= u32LayerSourceGreenHeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerSourceBlueWidthTotal)
        u16DimWidth= u32LayerSourceBlueWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerSourceBlueHeightTotal)
        u16DimHeight= u32LayerSourceBlueHeightTotal- u16DimY2;

    Cache__vWbInvL2 ((uint32_t)psLayerSourceRed->layerDataAddress,psLayerSourceRed->layerWidthTotal*psLayerSourceRed->layerHeightTotal);
    Cache__vWbInvL2 ((uint32_t)psLayerSourceGreen->layerDataAddress,psLayerSourceGreen->layerWidthTotal*psLayerSourceGreen->layerHeightTotal);
    Cache__vWbInvL2 ((uint32_t)psLayerSourceBlue->layerDataAddress,psLayerSourceBlue->layerWidthTotal*psLayerSourceBlue->layerHeightTotal);
    u8Mod=(u16DimWidth*u16DimHeight)%OPT;
    if(u8Mod)
        u8Mod=OPT-u8Mod;
    uint8_t* restrict pu8LayerSourceRed=(uint8_t *) memalign(8,sizeof(uint8_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint8_t* restrict pu8LayerSourceGreen=(uint8_t *) memalign(8,sizeof(uint8_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint8_t* restrict pu8LayerSourceBlue=(uint8_t *) memalign(8,sizeof(uint8_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint16_t* restrict pu16LayerDest =(uint16_t *) memalign(8,sizeof(uint16_t)*u16DimWidth*u16DimHeight+u8Mod);

    uint8_t* restrict pu8LayerSourceRedInitial =pu8LayerSourceRed;
    uint8_t* restrict pu8LayerSourceGreenInitial =pu8LayerSourceGreen;
    uint8_t* restrict pu8LayerSourceBlueInitial =pu8LayerSourceBlue;
    uint16_t* restrict pu16LayerDestInitial =pu16LayerDest;

    Cache__vWbInvL2 ((uint32_t)pu8LayerSourceRed,u16DimWidth*u16DimHeight);
    Cache__vWbInvL2 ((uint32_t)pu8LayerSourceGreen,u16DimWidth*u16DimHeight);
    Cache__vWbInvL2 ((uint32_t)pu8LayerSourceBlue,u16DimWidth*u16DimHeight);

    sLayer.layerWidthTotal=u16DimWidth;
    sLayer.layerHeightTotal=u16DimHeight;
    sLayer.variableType=VARIABLETYPE_enUCHAR;
    sDimLayer.X[1]=0;
    sDimLayer.Y[1]=0;
    sDimLayer.width=u16DimWidth;
    sDimLayer.height=u16DimHeight;

    sDimLayer.X[0]=u16DimX0;
    sDimLayer.Y[0]=u16DimY0;
    sLayer.layerDataAddress=(uint32_t)pu8LayerSourceRed;
    LCDC__enLayer_Copy(psLayerSourceRed,&sLayer,sDimLayer);

    sDimLayer.X[0]=u16DimX1;
    sDimLayer.Y[0]=u16DimY1;
    sLayer.layerDataAddress=(uint32_t)pu8LayerSourceGreen;
    LCDC__enLayer_Copy(psLayerSourceGreen,&sLayer,sDimLayer);

    sDimLayer.X[0]=u16DimX2;
    sDimLayer.Y[0]=u16DimY2;
    sLayer.layerDataAddress=(uint32_t)pu8LayerSourceBlue;
    LCDC__enLayer_Copy(psLayerSourceBlue,&sLayer,sDimLayer);

    _nassert ((int)(pu8LayerSourceRed) % 8 == 0);
    _nassert ((int)(pu8LayerSourceGreen) % 8 == 0);
    _nassert ((int)(pu8LayerSourceBlue) % 8 == 0);
    _nassert ((int)(pu16LayerDest) % 8 == 0);

    #pragma UNROLL(OPT)
    #pragma MUST_ITERATE (OPT,,OPT)
    for(s32Index=0;s32Index<(u16DimHeight*u16DimWidth)+u8Mod;s32Index++)
    {
        u8Red=*((uint8_t*)pu8LayerSourceRed)&0xF8;
        u8Green=*((uint8_t*)pu8LayerSourceGreen)&0xFC;
        u8Blue=*((uint8_t*)pu8LayerSourceBlue)&0xF8;

        u16Result =((uint16_t)u8Red<<8);
        u16Result|=((uint16_t)u8Green<<3);
        u16Result|=((uint16_t)u8Blue>>3);

         *((uint16_t*)pu16LayerDest)= u16Result;
         pu8LayerSourceRed++;
         pu8LayerSourceGreen++;
         pu8LayerSourceBlue++;
         pu16LayerDest++;
    }
    Cache__vWbL2 ((uint32_t)pu16LayerDestInitial,u16DimHeight*u16DimWidth*2);

    sLayer.variableType=VARIABLETYPE_enUSHORT;
    sDimLayer.X[1]=u16DimX3;
    sDimLayer.Y[1]=u16DimY3;
    sDimLayer.width=u16DimWidth;
    sDimLayer.height=u16DimHeight;

    sDimLayer.X[0]=0;
    sDimLayer.Y[0]=0;
    sLayer.layerDataAddress=(uint32_t)pu16LayerDestInitial;
    LCDC__enLayer_Copy(&sLayer,psLayerDest,sDimLayer);

    free(pu16LayerDestInitial);
    free(pu8LayerSourceBlueInitial);
    free(pu8LayerSourceGreenInitial);
    free(pu8LayerSourceRedInitial);
    return IMAGPROC_enOK;
}




