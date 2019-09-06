/*
 * IMAGEPROC__en16bUmbral.c
 *
 *  Created on: 04/09/2019
 *      Author: Lalo
 */



#include <ImageProcessing.h>


#define OPT (2)
IMAGPROC_nStatus IMAGEPROC__en16bUmbral(LCDC_TFT_TypeDef *psLayerSource,LCDC_TFT_TypeDef *psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, uint16_t u16UmbralCenter, uint8_t u8UmbralLengthRed, uint8_t u8UmbralLengthGreen, uint8_t u8UmbralLengthBlue)
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
    uint16_t u16Result=0;
    uint8_t u8UmbralFlag = 0;
    uint8_t u8CompFlag=0;


    uint8_t u8UmbralAux=0;
    int8_t  s8UmbralArithSub=0;
    int8_t  s8UmbralArithAdd=0;
    uint8_t u8UmbralMinRed=0;
    uint8_t u8UmbralMaxRed=0x1F;
    uint8_t u8UmbralMinGreen=0;
    uint8_t u8UmbralMaxGreen=0x3F;
    uint8_t u8UmbralMinBlue=0;
    uint8_t u8UmbralMaxBlue=0x1F;

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

    if(u8UmbralLengthRed>0x1F)
        u8UmbralLengthRed=0x1F;
    if(u8UmbralLengthGreen>0x3F)
        u8UmbralLengthGreen=0x3F;
    if(u8UmbralLengthBlue>0x1F)
        u8UmbralLengthBlue=0x1F;

    u8UmbralAux=(u16UmbralCenter&0xF800)>>10;
    s8UmbralArithSub=u8UmbralAux-u8UmbralLengthRed;
    s8UmbralArithAdd=u8UmbralAux+u8UmbralLengthRed;
    if (s8UmbralArithSub>0)
        u8UmbralMinRed=(s8UmbralArithSub+1)>>1;
    if (s8UmbralArithAdd<0x3F)
        u8UmbralMaxRed=(s8UmbralArithAdd+1)>>1;

    u8UmbralAux=(u16UmbralCenter&0x07E0)>>4;
    s8UmbralArithSub=u8UmbralAux-u8UmbralLengthGreen;
    s8UmbralArithAdd=u8UmbralAux+u8UmbralLengthGreen;
    if (s8UmbralArithSub>0)
        u8UmbralMinGreen=(s8UmbralArithSub+1)>>1;
    if (s8UmbralArithAdd<0x7F)
        u8UmbralMaxGreen=(s8UmbralArithAdd+1)>>1;

    u8UmbralAux=(u16UmbralCenter&0x1F)<<1;
    s8UmbralArithSub=u8UmbralAux-u8UmbralLengthBlue;
    s8UmbralArithAdd=u8UmbralAux+u8UmbralLengthBlue;
    if (s8UmbralArithSub>0)
        u8UmbralMinBlue=(s8UmbralArithSub+1)>>1;
    if (s8UmbralArithAdd<0x7F)
        u8UmbralMaxBlue=(s8UmbralArithAdd+1)>>1;

    Cache__vWbInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);
    u8Mod=(u16DimWidth*u16DimHeight)%OPT;
    if(u8Mod)
        u8Mod=OPT-u8Mod;
    uint16_t* restrict pu16LayerSource =(uint16_t *) memalign(1024*1024,sizeof(uint16_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint16_t* restrict pu16LayerDest =(uint16_t *) memalign(1024*1024,sizeof(uint16_t)*u16DimWidth*u16DimHeight+u8Mod);

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

    #pragma UNROLL(OPT)
    #pragma MUST_ITERATE (OPT,,OPT)
    for(s32Index=0;s32Index<(u16DimHeight*u16DimWidth)+u8Mod;s32Index++)
    {
        u16Value=*((uint16_t*)pu16LayerSource);
        u8CompFlag=0;
        u16Result=0;
        pu16LayerSource++;

        u8UmbralFlag=u16Value&0x1F;
        if((u8UmbralFlag>=u8UmbralMinBlue) && (u8UmbralFlag<=u8UmbralMaxBlue))
            u8CompFlag++;

        u8UmbralFlag=(u16Value&0x07E0)>>5;
        if((u8UmbralFlag>=u8UmbralMinGreen) && (u8UmbralFlag<=u8UmbralMaxGreen))
            u8CompFlag++;

        u8UmbralFlag=(u16Value&0xF800)>>11;
        if((u8UmbralFlag>=u8UmbralMinRed) && (u8UmbralFlag<=u8UmbralMaxRed))
            u8CompFlag++;

        if(u8CompFlag==3)
            u16Result=0xFFFF;

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
    free(pu16LayerSourceInitial);
    return IMAGPROC_enOK;
}
