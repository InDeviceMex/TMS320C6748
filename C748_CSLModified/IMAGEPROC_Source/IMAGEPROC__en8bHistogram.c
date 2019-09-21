/*
 * IMAGEPROC_enHistogram.c
 *
 *  Created on: 18/09/2019
 *      Author: Lalo
 */

#include <ImageProcessing.h>


#define OPT (18)
IMAGPROC_nStatus IMAGEPROC__en8bHistogram(LCDC_TFT_TypeDef *psLayerSource, LCDC_DIMENSIONS_TypeDef sDim,uint32_t* restrict u32Hist, uint8_t u8Bins)
{
    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;

    int32_t s32Index=0;

    uint16_t u16DimX0=sDim.X[0];
    uint16_t u16DimY0=sDim.Y[0];

    uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    uint16_t u16DimWidth=sDim.width;
    uint16_t u16DimHeight=sDim.height;

    uint8_t u8Aux=0;

    uint8_t u8Mod=0;


    if((psLayerSource->variableType != VARIABLETYPE_enUCHAR))
          return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
      return IMAGPROC_enERROR;
    if(u16DimY0>u32LayerSourceHeightTotal)
      return IMAGPROC_enERROR;


    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
      u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
      u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    Cache__vWbInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal);
    Cache__vWbInvL2 ((uint32_t)u32Hist,(u8Bins+1)*4);
      u8Mod=(u16DimWidth*u16DimHeight)%OPT;
    if(u8Mod)
      u8Mod=OPT-u8Mod;

    uint8_t* restrict pu8LayerSource = (uint8_t *) memalign(1024*1024,sizeof(uint8_t)*u16DimWidth*u16DimHeight+32);
    uint8_t* pu8LayerSourceInitial = pu8LayerSource;
    uint8_t* pu8LayerSourceFirst = ((uint8_t*)pu8LayerSource+(u16DimWidth*u16DimHeight));
    Cache__vWbInvL2 ((uint32_t)pu8LayerSource,u16DimWidth*u16DimHeight);

    sLayer.layerWidthTotal=u16DimWidth;
    sLayer.layerHeightTotal=u16DimHeight;
    sDimLayer.width=u16DimWidth;
    sDimLayer.height=u16DimHeight;

    sDimLayer.X[1]=0;
    sDimLayer.Y[1]=0;
    sDimLayer.X[0]=u16DimX0;
    sDimLayer.Y[0]=u16DimY0;
    sLayer.variableType=VARIABLETYPE_enUCHAR;
    sLayer.layerDataAddress=(uint32_t)pu8LayerSource;
    LCDC__enLayer_Copy(psLayerSource,&sLayer,sDimLayer);


    sLayer.layerWidthTotal=(u8Bins+1);
    sLayer.layerHeightTotal=2;

    sLayer.variableType=VARIABLETYPE_enUSHORT;
    sLayer.layerDataAddress=(uint32_t)u32Hist;
    LCDC__vLayer_Clear(&sLayer,0);

    _nassert ((int)(pu8LayerSource) % 8 == 0);
    #pragma UNROLL(16)
    #pragma MUST_ITERATE (16,32,16)
    for(s32Index=0;s32Index<32;s32Index++)
    {
        *((uint8_t*)pu8LayerSourceFirst)=0;
        pu8LayerSourceFirst++;
    }

    _nassert ((int)(pu8LayerSource) % 8 == 0);

    #pragma UNROLL(OPT)
    #pragma MUST_ITERATE (OPT,,OPT)
    for(s32Index=0;s32Index<(u16DimHeight*u16DimWidth)+u8Mod;s32Index++)
    {

        u8Aux=*((uint8_t*)pu8LayerSource);
        pu8LayerSource++;
        if(u8Aux<=u8Bins)
            u32Hist[u8Aux]++;
    }
    u32Hist[0]-=u8Mod;

    Cache__vWbL2 ((uint32_t)u32Hist, (u8Bins+1)*4);
    free(pu8LayerSourceInitial);
    return IMAGPROC_enOK;
}
