/*
 * IMAGEPROC__en16bRGBScale_8bGrayScale.c
 *
 *  Created on: 21/08/2019
 *      Author: Lalo
 */

#include <ImageProcessing.h>
IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bGrayScale(LCDC_TFT_TypeDef *restrict psLayerSource, LCDC_TFT_TypeDef *restrict psLayerDest,LCDC_DIMENSIONS_TypeDef sDim)
{

    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;
    register uint32_t u32Index=0;

    register uint8_t u8Red = 0;
    register uint8_t u8Green = 0;
    register uint8_t u8Blue = 0;
    register uint8_t u8Add=0;

    uint16_t u16DimX0=sDim.X[0];
    uint16_t u16DimX1=sDim.X[1];
    uint16_t u16DimY0=sDim.Y[0];
    uint16_t u16DimY1=sDim.Y[1];

    uint32_t psLayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    uint32_t psLayerDestWidthTotal=psLayerDest->layerWidthTotal;
    uint32_t psLayerSourceHeightTotal=psLayerSource->layerHeightTotal;
    uint32_t psLayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    register uint16_t u16Aux=0;

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

    register uint16_t* restrict pu16LayerSource =(uint16_t *) memalign(4,sizeof(uint16_t)*u16DimWidth*u16DimHeight);
    register uint8_t* restrict pu8LayerDest =(uint8_t *) memalign(4,sizeof(uint8_t)*u16DimWidth*u16DimHeight);

    register uint16_t* restrict pu16LayerSourceInitial=pu16LayerSource;
    register uint8_t* restrict pu8LayerDestInitial=pu8LayerDest;
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

    _nassert((int)(pu16LayerSource)  == 0);
    _nassert((int)(pu8LayerDest)  == 0);
    #pragma UNROLL(8)
    for(u32Index=0;u32Index<(u16DimHeight*u16DimWidth);u32Index++)
    {

            u16Aux=*((uint16_t*)pu16LayerSource);
            pu16LayerSource++;
            u8Red=(uint8_t)((uint16_t)(u16Aux&0xF800)>>10)&0x3F;
            u8Green=(uint8_t)((uint16_t)(u16Aux&0x07E0)>>5)&0x3F;
            u8Blue=(uint8_t)((uint16_t)u16Aux<<1)&0x3F;


            u8Add= (u8Red+u8Green);
            u8Add+=u8Blue;
            u8Add/=3;
            u8Add<<=2;
            *((uint8_t*)pu8LayerDest)=(uint8_t) u8Add;
            pu8LayerDest++;

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

