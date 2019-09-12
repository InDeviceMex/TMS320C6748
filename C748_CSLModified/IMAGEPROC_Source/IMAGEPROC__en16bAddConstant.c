/*
 * IMAGEPROC__en16bAddConstant.c
 *
 *  Created on: 01/09/2019
 *      Author: Lalo
 */



#include <ImageProcessing.h>


#define OPT (2)
IMAGPROC_nStatus IMAGEPROC__en16bAddConstant(LCDC_TFT_TypeDef* psLayerSource, LCDC_TFT_TypeDef* psLayerDest, LCDC_DIMENSIONS_TypeDef sDim,uint8_t u8Red,uint8_t u8Green,uint8_t u8Blue)
{
    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;
    int32_t s32Index=0;

    uint16_t u16DimX0=sDim.X[0];
    uint16_t u16DimX1=sDim.X[1];
    uint16_t u16DimY0=sDim.Y[0];
    uint16_t u16DimY1=sDim.Y[1];

    uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    uint16_t u16DimWidth=sDim.width;
    uint16_t u16DimHeight=sDim.height;

    uint16_t u16Value = 0;
    uint32_t u32Byte1 = 0;
    uint32_t u32Byte2 = 0;

    uint8_t u8Blue_ = 0;
    uint16_t u16Green = 0;
    uint32_t u32Red = 0;

    uint32_t u32Aux = 0;

    uint8_t u8Mod=0;
    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
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

    Cache__vWbInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);
    u8Mod=(u16DimWidth*u16DimHeight)%OPT;
    if(u8Mod)
        u8Mod=OPT-u8Mod;
    uint16_t* restrict pu16LayerSource =(uint16_t *) memalign(8,sizeof(uint16_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint16_t* restrict pu16LayerDest =(uint16_t *) memalign(8,sizeof(uint16_t)*u16DimWidth*u16DimHeight+u8Mod);

    uint16_t* restrict pu16LayerSourceInitial =pu16LayerSource;
    uint16_t* restrict pu16LayerDestInitial =pu16LayerDest;


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
    _nassert ((int)(pu16LayerDest) % 8 == 0);

    u32Byte2=(((uint32_t)u8Red<<13)&0x1F0000)|(((uint32_t)u8Green<<6)&0x003F00)|(((uint32_t)u8Blue>>3)&0x00001F);

    #pragma UNROLL(OPT)
    #pragma MUST_ITERATE (OPT,,OPT)
    for(s32Index=0;s32Index<(u16DimHeight*u16DimWidth)+u8Mod;s32Index++)
    {
        u16Value=*((uint16_t*)pu16LayerSource);
        pu16LayerSource++;


        u8Blue_=u16Value&0x001F;
        u16Green=(u16Value<<3)&0x3f00;
        u32Red =(u16Value<<5)&0x1F0000;
        u32Byte1=u32Red|u16Green|u8Blue_;


        u32Aux=_avgu4(u32Byte1,u32Byte2);

        u8Blue_=(u32Aux)&0x001F;
        u16Green=(u32Aux>>3)&0x07E0;
        u32Red =(u32Aux>>5)&0xF800;

        *((uint16_t*)pu16LayerDest)= (uint16_t)((uint16_t)u32Red|u16Green|u8Blue_);
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
    free(pu16LayerSourceInitial);
    return IMAGPROC_enOK;
}



