/*
 * IMAGEPROC_enHistogram.c
 *
 *  Created on: 18/09/2019
 *      Author: Lalo
 */

#include <ImageProcessing.h>


#define OPT (1)
IMAGPROC_nStatus IMAGEPROC_en16bHistogram(LCDC_TFT_TypeDef *psLayerSource, LCDC_DIMENSIONS_TypeDef sDim,uint32_t u32Hist[256])
{
    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;

    int32_t s32Width=0,s32Height=0;

    uint16_t u16DimX0=sDim.X[0];
    uint16_t u16DimY0=sDim.Y[0];

    uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    uint16_t u16DimWidth=sDim.width;
    uint16_t u16DimHeight=sDim.height;

    uint16_t u16Value=0;
    uint32_t u32Value=0;

    int32_t s32i=0,s32Aux=0;

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
    Cache__vWbInvL2 ((uint32_t)u32Hist,256*2);
      u8Mod=(u16DimWidth*u16DimHeight)%OPT;
    if(u8Mod)
      u8Mod=OPT-u8Mod;

    uint16_t* restrict pu16LayerSource = (uint16_t *) memalign(1024*1024,sizeof(uint16_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint16_t* pu16LayerSourceInitial = pu16LayerSource;
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


    sLayer.layerWidthTotal=256;
    sLayer.layerHeightTotal=1;

    sLayer.variableType=VARIABLETYPE_enUSHORT;
    sLayer.layerDataAddress=(uint32_t)u32Hist;
    LCDC__vLayer_Clear(&sLayer,0);

    _nassert ((int)(pu16LayerSource) % 8 == 0);



}
