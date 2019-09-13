/*
 * IMAGEPROC__en16bRGBScale_8bGreenPartialScale.c
 *
 *  Created on: 29/08/2019
 *      Author: Lalo
 */



#include <ImageProcessing.h>

#define OPT (12)
IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bGreenPartialScale(LCDC_TFT_TypeDef *psLayerSource, LCDC_TFT_TypeDef*psLayerDestGreen,LCDC_DIMENSIONS_TypeDef sDim)
{

    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;
    int32_t s32Index=0;

    uint16_t u16DimX0=sDim.X[0];
    uint16_t u16DimX1=sDim.X[1];
    uint16_t u16DimY0=sDim.Y[0];
    uint16_t u16DimY1=sDim.Y[1];

    uint32_t u32LayerDestGreenWidthTotal=psLayerDestGreen->layerWidthTotal;
    uint32_t u32LayerDestGreenHeightTotal=psLayerDestGreen->layerHeightTotal;

    uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    uint16_t u16DimWidth=sDim.width;
    uint16_t u16DimHeight=sDim.height;

    uint8_t u8Mod=0;

    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDestGreen->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;

    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestGreenWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestGreenHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestGreenWidthTotal)
        u16DimWidth= u32LayerDestGreenWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestGreenHeightTotal)
        u16DimHeight= u32LayerDestGreenHeightTotal- u16DimY1;


    Cache__vWbInvL2 ((uint32_t)psLayerSource->layerDataAddress,psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);
    u8Mod=(u16DimWidth*u16DimHeight)%OPT;
    if(u8Mod)
        u8Mod=OPT-u8Mod;
    uint16_t* restrict pu16LayerSource =(uint16_t *) memalign(1024*1024,sizeof(uint16_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint8_t* restrict pu8LayerDestGreen =(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*u16DimWidth*u16DimHeight+u8Mod);

    uint16_t* pu16LayerSourceInitial=pu16LayerSource;
    uint8_t* pu8LayerDestGreenInitial=pu8LayerDestGreen;

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
    _nassert ((int)(pu8LayerDestGreen) % 8 == 0);

    #pragma UNROLL(OPT)
    #pragma MUST_ITERATE (OPT,,OPT)
    for(s32Index=0;s32Index<(u16DimHeight*u16DimWidth)+u8Mod;s32Index++)
    {

        *((uint8_t*)pu8LayerDestGreen)=((*((uint16_t*)pu16LayerSource)>>5)&0x003F);
        pu16LayerSource++;
        pu8LayerDestGreen++;


    }
    Cache__vWbL2 ((uint32_t)pu8LayerDestGreenInitial, u16DimHeight*u16DimWidth);

    sLayer.variableType=VARIABLETYPE_enUCHAR;
    sDimLayer.X[1]=u16DimX1;
    sDimLayer.Y[1]=u16DimY1;
    sDimLayer.X[0]=0;
    sDimLayer.Y[0]=0;
    sLayer.layerDataAddress=(uint32_t)pu8LayerDestGreenInitial;
    LCDC__enLayer_Copy(&sLayer,psLayerDestGreen,sDimLayer);

    free(pu8LayerDestGreenInitial);
    free(pu16LayerSourceInitial);
    return IMAGPROC_enOK;
}



