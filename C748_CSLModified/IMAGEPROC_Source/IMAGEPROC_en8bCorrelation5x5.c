/*
 * IMAGEPROC_en8bCorrelation5x5.c
 *
 *  Created on: 07/02/2020
 *      Author: vyldram
 */



#include <ImageProcessing.h>

#define KERNEL_LONG (25u)

__inline void CORRELATION_vCompute(uint8_t* restrict pu8SubImage, uint8_t  u8Pixel[KERNEL_LONG],int16_t  s16Kernel[KERNEL_LONG],uint16_t u16Div);
__inline void CORRELATION_vFillPixelArray(uint8_t u8Pixel[KERNEL_LONG],uint8_t* restrict pu8LayerSource, uint16_t u16DimWidth );

#define OPT (8)
IMAGPROC_nStatus IMAGEPROC__en8bCorrelation5x5(LCDC_TFT_TypeDef *psLayerSource, LCDC_TFT_TypeDef*psLayerDest, int16_t ps16Kernel[KERNEL_LONG],LCDC_DIMENSIONS_TypeDef sDim)
{
    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;

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

    uint16_t u16Width=0;
    uint16_t u16Height=0;

    int16_t s16Division=0;
    uint16_t u16Count=0;
    uint8_t u8Mod=0;
    if((psLayerSource->variableType != VARIABLETYPE_enUCHAR) || (psLayerDest->variableType != VARIABLETYPE_enUCHAR))
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


    if(u16DimWidth<=KERNEL_LONG) //size kernel
        return IMAGPROC_enERROR;

    if(u16DimHeight<=KERNEL_LONG) //size kernel
        return IMAGPROC_enERROR;


    Cache__vWbInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal);

    u8Mod=(u16DimWidth*u16DimHeight)%OPT;
    if(u8Mod)
        u8Mod=OPT-u8Mod;

    uint8_t* restrict pu8SubImage =(uint8_t *) memalign(64,sizeof(uint8_t)*16);
    uint8_t* restrict pu8LayerSource =(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint8_t* restrict pu8LayerDest =(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint8_t* restrict u8Pixel =(uint8_t *) memalign(16,sizeof(uint8_t)*32);

    uint8_t* pu8LayerSourceInitial =pu8LayerSource;
    uint8_t* pu8LayerDestInitial =pu8LayerDest;

    if((pu8SubImage == 0) || (pu8LayerSourceInitial == 0) || (pu8LayerDestInitial == 0) || (u8Pixel==0))
    {
     free(pu8LayerDestInitial);
     free(pu8LayerSourceInitial);
     free(u8Pixel);
     free(pu8SubImage);
     return IMAGPROC_enALLOCERROR;
    }

    Cache__vWbInvL2 ((uint32_t)pu8LayerSource,u16DimWidth*u16DimHeight);
    Cache__vWbInvL2 ((uint32_t)pu8LayerDest,u16DimWidth*u16DimHeight);

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

    sLayer.layerDataAddress=(uint32_t)pu8LayerDestInitial;
    LCDC__vLayer_Clear(&sLayer,0);

    for(u16Count=0; u16Count<KERNEL_LONG; u16Count++)
    {
        s16Division+=ps16Kernel[u16Count];
    }

    if(s16Division==0)
    {
        s16Division=1;
    }

    _nassert ((int)(u8Pixel) % 8 == 0);
    _nassert ((int)(pu8SubImage) % 8 == 0);
    _nassert ((int)(pu8LayerSource) % 8 == 0);
    _nassert ((int)(pu8LayerDest) % 8 == 0);

    pu8LayerSource+=(2*u16DimWidth)+2;
    pu8LayerDest+=(2*u16DimWidth)+2;

    #pragma UNROLL(1)
    #pragma MUST_ITERATE (1,,1)
    for(u16Height=0;u16Height<(u16DimHeight-4);u16Height++)
    {
        for(u16Width=0;u16Width<(u16DimWidth-4);u16Width++)
        {
            CORRELATION_vFillPixelArray(u8Pixel,(uint8_t*)pu8LayerSource,u16DimWidth);
            CORRELATION_vCompute(pu8SubImage,u8Pixel,ps16Kernel,s16Division);

            *((uint8_t*)pu8LayerDest)= *pu8SubImage;

            pu8LayerDest++;
            pu8LayerSource++;

        }
        pu8LayerSource+=4;
        pu8LayerDest+=4;
    }


    Cache__vWbL2 ((uint32_t)pu8LayerDestInitial, u16DimHeight*u16DimWidth);



    sLayer.layerWidthTotal=u16DimWidth;
    sLayer.layerHeightTotal=u16DimHeight;
    sDimLayer.width=u16DimWidth;
    sDimLayer.height=u16DimHeight;
    sLayer.variableType=VARIABLETYPE_enUCHAR;
    sDimLayer.X[1]=u16DimX1;
    sDimLayer.Y[1]=u16DimY1;
    sDimLayer.X[0]=0;
    sDimLayer.Y[0]=0;
    sLayer.layerDataAddress=(uint32_t)pu8LayerDestInitial;
    LCDC__enLayer_Copy(&sLayer,psLayerDest,sDimLayer);

    free(pu8LayerDestInitial);
    free(pu8LayerSourceInitial);
    free(u8Pixel);
    free(pu8SubImage);
    return IMAGPROC_enOK;

}
__inline void CORRELATION_vFillPixelArray(uint8_t u8Pixel[KERNEL_LONG],uint8_t* restrict pu8LayerSource, uint16_t u16DimWidth )
{

    u8Pixel[0]= *((uint8_t*)pu8LayerSource-2-u16DimWidth-u16DimWidth);
    u8Pixel[1]= *((uint8_t*)pu8LayerSource-1-u16DimWidth-u16DimWidth);
    u8Pixel[2]= *((uint8_t*)pu8LayerSource-u16DimWidth-u16DimWidth);
    u8Pixel[3]= *((uint8_t*)pu8LayerSource+1-u16DimWidth-u16DimWidth);
    u8Pixel[4]= *((uint8_t*)pu8LayerSource+2-u16DimWidth-u16DimWidth);

    u8Pixel[5]= *((uint8_t*)pu8LayerSource-2-u16DimWidth);
    u8Pixel[6]= *((uint8_t*)pu8LayerSource-1-u16DimWidth);
    u8Pixel[7]= *((uint8_t*)pu8LayerSource-u16DimWidth); //top
    u8Pixel[8]= *((uint8_t*)pu8LayerSource+1-u16DimWidth);
    u8Pixel[9]= *((uint8_t*)pu8LayerSource+2-u16DimWidth);

    u8Pixel[10]= *((uint8_t*)pu8LayerSource-2); //left
    u8Pixel[11]= *((uint8_t*)pu8LayerSource-1); //left
    u8Pixel[12]= *((uint8_t*)pu8LayerSource);   //center
    u8Pixel[13]= *((uint8_t*)pu8LayerSource+1); //right
    u8Pixel[14]= *((uint8_t*)pu8LayerSource+2); //right

    u8Pixel[15]= *((uint8_t*)pu8LayerSource-2+u16DimWidth);
    u8Pixel[16]= *((uint8_t*)pu8LayerSource-1+u16DimWidth);
    u8Pixel[17]= *((uint8_t*)pu8LayerSource+u16DimWidth); //bottom
    u8Pixel[18]= *((uint8_t*)pu8LayerSource+1+u16DimWidth);
    u8Pixel[19]= *((uint8_t*)pu8LayerSource+2+u16DimWidth);

    u8Pixel[20]= *((uint8_t*)pu8LayerSource-2+u16DimWidth+u16DimWidth);
    u8Pixel[21]= *((uint8_t*)pu8LayerSource-1+u16DimWidth+u16DimWidth);
    u8Pixel[22]= *((uint8_t*)pu8LayerSource+u16DimWidth+u16DimWidth); //bottom
    u8Pixel[23]= *((uint8_t*)pu8LayerSource+1+u16DimWidth+u16DimWidth);
    u8Pixel[24]= *((uint8_t*)pu8LayerSource+2+u16DimWidth+u16DimWidth);


}

__inline void CORRELATION_vCompute(uint8_t* restrict pu8SubImage, uint8_t  u8Pixel[KERNEL_LONG],int16_t  s16Kernel[KERNEL_LONG],uint16_t u16Div)
{
    int32_t s32MaxValue =0;

    *pu8SubImage=0;
    _nassert ((int)(pu8SubImage) % 8 == 0);
    _nassert ((int)(u8Pixel) % 8 == 0);

    s32MaxValue+=u8Pixel[0]*s16Kernel[0];
    s32MaxValue+=u8Pixel[1]*s16Kernel[1];
    s32MaxValue+=u8Pixel[2]*s16Kernel[2];
    s32MaxValue+=u8Pixel[3]*s16Kernel[3];
    s32MaxValue+=u8Pixel[4]*s16Kernel[4];
    s32MaxValue+=u8Pixel[5]*s16Kernel[5];
    s32MaxValue+=u8Pixel[6]*s16Kernel[6];
    s32MaxValue+=u8Pixel[7]*s16Kernel[7];
    s32MaxValue+=u8Pixel[8]*s16Kernel[8];

    s32MaxValue+=u8Pixel[9]*s16Kernel[9];
    s32MaxValue+=u8Pixel[10]*s16Kernel[10];
    s32MaxValue+=u8Pixel[11]*s16Kernel[11];
    s32MaxValue+=u8Pixel[12]*s16Kernel[12];
    s32MaxValue+=u8Pixel[13]*s16Kernel[13];
    s32MaxValue+=u8Pixel[14]*s16Kernel[14];
    s32MaxValue+=u8Pixel[15]*s16Kernel[15];
    s32MaxValue+=u8Pixel[16]*s16Kernel[16];
    s32MaxValue+=u8Pixel[17]*s16Kernel[17];

    s32MaxValue+=u8Pixel[18]*s16Kernel[18];
    s32MaxValue+=u8Pixel[19]*s16Kernel[19];
    s32MaxValue+=u8Pixel[20]*s16Kernel[20];
    s32MaxValue+=u8Pixel[21]*s16Kernel[21];
    s32MaxValue+=u8Pixel[22]*s16Kernel[22];
    s32MaxValue+=u8Pixel[23]*s16Kernel[23];
    s32MaxValue+=u8Pixel[24]*s16Kernel[24];

    s32MaxValue/=u16Div;
    if(s32MaxValue<0)
        s32MaxValue=0;
    if(s32MaxValue>0xFF)
        s32MaxValue=0xFF;

    *pu8SubImage=(uint8_t)s32MaxValue;

}

