/*
 * IMAGEPROC__en16bRGBScale_8bGrayScale.c
 *
 *  Created on: 21/08/2019
 *      Author: Lalo
 */

#include <ImageProcessing.h>

#define OPT (11)
IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bGrayScale(LCDC_TFT_TypeDef * psLayerSource, LCDC_TFT_TypeDef * psLayerDest,LCDC_DIMENSIONS_TypeDef sDim)
{

    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;
    int32_t s32Index=0;
    uint8_t u8Add=0;
    uint8_t u8Red=0;
    uint8_t u8Green=0;
    uint8_t u8Blue=0;

    uint16_t u16DimX0=sDim.X[0];
    uint16_t u16DimX1=sDim.X[1];
    uint16_t u16DimY0=sDim.Y[0];
    uint16_t u16DimY1=sDim.Y[1];

    uint32_t psLayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    uint32_t psLayerDestWidthTotal=psLayerDest->layerWidthTotal;
    uint32_t psLayerSourceHeightTotal=psLayerSource->layerHeightTotal;
    uint32_t psLayerDestHeightTotal=psLayerDest->layerHeightTotal;

    uint16_t u16DimWidth=sDim.width;
    uint16_t u16DimHeight=sDim.height;
    uint16_t u16Aux=0;

    uint8_t u8Mod=0;

    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDest->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>psLayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>psLayerDestWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimY0>psLayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>psLayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>psLayerSourceWidthTotal)
        u16DimWidth= psLayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>psLayerSourceHeightTotal)
        u16DimHeight= psLayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>psLayerDestWidthTotal)
        u16DimWidth= psLayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>psLayerDestHeightTotal)
        u16DimHeight= psLayerDestHeightTotal- u16DimY1;

    Cache__vWbInvL2 ((uint32_t)psLayerSource->layerDataAddress,psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);
    u8Mod=(u16DimWidth*u16DimHeight)%OPT;
    if(u8Mod)
        u8Mod=OPT-u8Mod;
    uint16_t* restrict pu16LayerSource =(uint16_t *) memalign(8,sizeof(uint16_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint8_t* restrict pu8LayerDest =(uint8_t *) memalign(8,sizeof(uint8_t)*u16DimWidth*u16DimHeight+u8Mod);

    uint16_t* pu16LayerSourceInitial=pu16LayerSource;
    uint8_t* pu8LayerDestInitial=pu8LayerDest;
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
    _nassert ((int)(pu8LayerDest) % 8 == 0);

    #pragma UNROLL(OPT)
    #pragma MUST_ITERATE (OPT,,OPT)
    for(s32Index=0;s32Index<(u16DimHeight*u16DimWidth)+u8Mod;s32Index++)
    {

            u16Aux=*((uint16_t*)pu16LayerSource);
            u8Red=(uint8_t)((u16Aux&0xF800)>>10);
            u8Green=(uint8_t)((u16Aux&0x07E0)>>5);
            u8Blue=(uint8_t)((u16Aux&0x1F)*2);

            u8Add=(u8Red+u8Green+u8Blue+1)/3;
            *((uint8_t*)pu8LayerDest)=(u8Add*4);
            pu8LayerDest++;
            pu16LayerSource++;

    }
    Cache__vWbL2 ((uint32_t)pu8LayerDestInitial, u16DimHeight*u16DimWidth);

    sLayer.variableType=VARIABLETYPE_enUCHAR;
    sDimLayer.X[1]=u16DimX1;
    sDimLayer.Y[1]=u16DimY1;
    sDimLayer.X[0]=0;
    sDimLayer.Y[0]=0;
    sLayer.layerDataAddress=(uint32_t)pu8LayerDestInitial;
    LCDC__enLayer_Copy(&sLayer,psLayerDest,sDimLayer);

    free(pu8LayerDestInitial);
    free(pu16LayerSourceInitial);
    return IMAGPROC_enOK;

}


