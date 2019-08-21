/*
 * IMAGEPROC__en16bAdd.c
 *
 *  Created on: 21/08/2019
 *      Author: Lalo
 */

#include "ImageProcessing.h"




IMAGPROC_nStatus IMAGEPROC__en16bAdd(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{
    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;
    register uint32_t u32Index=0;


     register uint16_t u16Value1 = 0;
     register uint16_t u16Value2 = 0;

     register uint16_t u16Blue1 = 0;
     register uint16_t u16Green1 = 0;
     register uint16_t u16Red1 = 0;

     register uint32_t u32Blue = 0;
     register uint32_t u32Green = 0;
     register uint32_t u32Red = 0;

    register uint32_t u32AuxRed = 0;
    register uint32_t u32AuxGreen = 0;
    register uint32_t u32AuxBlue = 0;
    register float    fResultRed = 0;
    register float    fResultGreen = 0;
    register float    fResultBlue = 0;
    register float    fAuxRed = 0;
    register float    fAuxGreen = 0;
    register float    fAuxBlue = 0;


     uint16_t u16DimX0=sDim.X[0];
     uint16_t u16DimX1=sDim.X[1];
     uint16_t u16DimX2=sDim.X[2];
     uint16_t u16DimY0=sDim.Y[0];
     uint16_t u16DimY1=sDim.Y[1];
     uint16_t u16DimY2=sDim.Y[2];

     uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
     uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
     uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
     uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

     uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
     uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    if((psLayerSource1->variableType != VARIABLETYPE_enUSHORT) || (psLayerSource2->variableType != VARIABLETYPE_enUSHORT)
            || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vWbInvL2 ((uint32_t)psLayerSource1->layerDataAddress,psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal*2);
    Cache__vWbInvL2 ((uint32_t)psLayerSource2->layerDataAddress,psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal*2);
    register uint16_t* restrict pu16LayerSource1 =(uint16_t *) memalign(4,sizeof(uint16_t)*u16DimWidth*u16DimHeight);
    register uint16_t* restrict pu16LayerSource2 =(uint16_t *) memalign(4,sizeof(uint16_t)*u16DimWidth*u16DimHeight);
    register uint16_t* restrict pu16LayerDest =(uint16_t *) memalign(4,sizeof(uint16_t)*u16DimWidth*u16DimHeight);

    register uint16_t* restrict pu16LayerSource1Initial =pu16LayerSource1;
    register uint16_t* restrict pu16LayerSource2Initial =pu16LayerSource2;
    register uint16_t* restrict pu16LayerDestInitial =pu16LayerDest;

    Cache__vWbInvL2 ((uint32_t)pu16LayerSource1,u16DimWidth*u16DimHeight*2);
    Cache__vWbInvL2 ((uint32_t)pu16LayerSource2,u16DimWidth*u16DimHeight*2);

    sLayer.layerWidthTotal=u16DimWidth;
    sLayer.layerHeightTotal=u16DimHeight;
    sDimLayer.width=u16DimWidth;
    sDimLayer.height=u16DimHeight;

    sDimLayer.X[1]=0;
    sDimLayer.Y[1]=0;
    sDimLayer.X[0]=u16DimX0;
    sDimLayer.Y[0]=u16DimY0;
    sLayer.variableType=VARIABLETYPE_enUSHORT;
    sLayer.layerDataAddress=(uint32_t)pu16LayerSource1;
    LCDC__enLayer_Copy(psLayerSource1,&sLayer,sDimLayer);

    sDimLayer.X[0]=u16DimX1;
    sDimLayer.Y[0]=u16DimY1;
    sLayer.variableType=VARIABLETYPE_enUSHORT;
    sLayer.layerDataAddress=(uint32_t)pu16LayerSource2;
    LCDC__enLayer_Copy(psLayerSource2,&sLayer,sDimLayer);
    #pragma UNROLL(8)
    for(u32Index=0;u32Index<u16DimHeight*u16DimWidth;u32Index++)
    {
        u16Value1=*((uint16_t*)pu16LayerSource1);
        u16Value2=*((uint16_t*)pu16LayerSource2);
        pu16LayerSource1++;
        pu16LayerSource2++;


        u16Blue1 =u16Value1&0x001F;
        u32Blue =(u16Value2&0x001F)<<16;
        u32Blue|=u16Blue1;
        u32AuxBlue=(uint32_t)_dotp2(u32Blue,u32Blue);

        fAuxBlue = _rsqrsp((float)u32AuxBlue);
        fAuxBlue = fAuxBlue * (1.5f - ((float)u32AuxBlue * fAuxBlue * fAuxBlue * 0.5f));
        fAuxBlue = fAuxBlue * (1.5f - ((float)u32AuxBlue * fAuxBlue * fAuxBlue * 0.5f));
        fResultBlue = (float)u32AuxBlue * fAuxBlue;

        u16Blue1=(uint16_t)fResultBlue;
        if(u16Blue1>0x1F)
            u16Blue1=0x1F;
        *((uint16_t*)pu16LayerDest)= u16Blue1;
        pu16LayerDest++;

    }

    pu16LayerSource1=pu16LayerSource1Initial;
    pu16LayerSource2=pu16LayerSource2Initial;
    pu16LayerDest=pu16LayerDestInitial;
#pragma UNROLL(8)
    for(u32Index=0;u32Index<u16DimHeight*u16DimWidth;u32Index++)
    {
        u16Value1=*((uint16_t*)pu16LayerSource1);
        u16Value2=*((uint16_t*)pu16LayerSource2);
        pu16LayerSource1++;
        pu16LayerSource2++;
        u16Green1 =(u16Value1&0x07E0)>>5;
        u32Green =(u16Value2&0x07E0)<<11;
        u32Green|=u16Green1;

        u32AuxGreen=(uint32_t)_dotp2(u32Green,u32Green);

        fAuxGreen = _rsqrsp((float)u32AuxGreen);
        fAuxGreen = fAuxGreen * (1.5f - ((float)u32AuxGreen * fAuxGreen * fAuxGreen * 0.5f));
        fAuxGreen = fAuxGreen * (1.5f - ((float)u32AuxGreen * fAuxGreen * fAuxGreen * 0.5f));
        fResultGreen = (float)u32AuxGreen * fAuxGreen;

        u16Green1=(uint16_t)fResultGreen;
        if(u16Green1>0x3F)
            u16Green1=0x3F;
        u16Green1<<=5;
        *((uint16_t*)pu16LayerDest)|= u16Green1;
        pu16LayerDest++;

    }

    pu16LayerSource1=pu16LayerSource1Initial;
    pu16LayerSource2=pu16LayerSource2Initial;
    pu16LayerDest=pu16LayerDestInitial;
#pragma UNROLL(8)
    for(u32Index=0;u32Index<u16DimHeight*u16DimWidth;u32Index++)
    {
            u16Value1=*((uint16_t*)pu16LayerSource1);
            u16Value2=*((uint16_t*)pu16LayerSource2);
            pu16LayerSource1++;
            pu16LayerSource2++;
            u16Red1 =(u16Value1&0xF800)>>11;
            u32Red =(u16Value2&0xF800)<<5;
            u32Red|=u16Red1;
            u32AuxRed=(uint32_t)_dotp2(u32Red,u32Red);

            fAuxRed = _rsqrsp((float)u32AuxRed);
            fAuxRed = fAuxRed * (1.5f - ((float)u32AuxRed * fAuxRed * fAuxRed * 0.5f));
            fAuxRed = fAuxRed * (1.5f - ((float)u32AuxRed * fAuxRed * fAuxRed * 0.5f));
            fResultRed = (float)u32AuxRed * fAuxRed;

            u16Red1=(uint16_t)fResultRed;
            if(u16Red1>0x1F)
                u16Red1=0x1F;
            u16Red1<<=11;
            *((uint16_t*)pu16LayerDest)|= u16Red1;
            pu16LayerDest++;
    }

    Cache__vWbL2 ((uint32_t)pu16LayerDestInitial, u16DimHeight*u16DimWidth*2);

    sLayer.variableType=VARIABLETYPE_enUSHORT;
    sDimLayer.X[1]=u16DimX2;
    sDimLayer.Y[1]=u16DimY2;
    sDimLayer.X[0]=0;
    sDimLayer.Y[0]=0;
    sLayer.layerDataAddress=(uint32_t)pu16LayerDestInitial;
    LCDC__enLayer_Copy(&sLayer,psLayerDest,sDimLayer);

    free(pu16LayerDestInitial);
    free(pu16LayerSource2Initial);
    free(pu16LayerSource1Initial);
    return IMAGPROC_enOK;
}

