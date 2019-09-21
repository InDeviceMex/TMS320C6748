/*
*IMAGEPROC_enLBPU.c
*
*Createdon:19/09/2019
*Author:Lalo
*/

#include <ImageProcessing.h>

uint8_t LBPU_u8Decision(uint8_t LBPU[58][9],uint8_t pu8SubImage[9]);
void LBPU_vComparative(uint8_t pu8SubImage[9], uint8_t  u8Pixel[9]);
void LBPU_vFillPixelArray(uint8_t u8Pixel[9],uint8_t*restrict pu8LayerSource, uint16_t u16DimWidth );



#pragma DATA_SECTION(LBPU, ".MyBuffer")
#pragma DATA_ALIGN(LBPU, 8)//2^15
uint8_t LBPU[58][9]=
{
{0,0,0,0,0,0,0,0,0},
{1,1,1,1,0,1,1,1,1},
{0,1,1,1,0,1,1,1,1},
{1,0,1,1,0,1,1,1,1},
{1,1,0,1,0,1,1,1,1},
{1,1,1,1,0,0,1,1,1},
{1,1,1,1,0,1,1,1,0},
{1,1,1,1,0,1,1,0,1},
{1,1,1,1,0,1,0,1,1},
{1,1,1,0,0,1,1,1,1},
{0,0,1,1,0,1,1,1,1},
{1,0,0,1,0,1,1,1,1},
{1,1,0,1,0,0,1,1,1},
{1,1,1,1,0,0,1,1,0},
{1,1,1,1,0,1,1,0,0},
{1,1,1,1,0,1,0,0,1},
{1,1,1,0,0,1,0,1,1},
{0,1,1,0,0,1,1,1,1},
{0,0,0,1,0,1,1,1,1},
{1,0,0,1,0,0,1,1,1},
{1,1,0,1,0,0,1,1,0},
{1,1,1,1,0,0,1,0,0},
{1,1,1,1,0,1,0,0,0},
{1,1,1,0,0,1,0,0,1},
{0,1,1,0,0,1,0,1,1},
{0,0,1,0,0,1,1,1,1},
{0,0,0,1,0,0,1,1,1},
{1,0,0,1,0,0,1,1,0},
{1,1,0,1,0,0,1,0,0},
{1,1,1,1,0,0,0,0,0},
{1,1,1,0,0,1,0,0,0},
{0,1,1,0,0,1,0,0,1},
{0,0,1,0,0,1,0,1,1},
{0,0,0,0,0,1,1,1,1},
{0,0,0,1,0,0,1,1,0},
{1,0,0,1,0,0,1,0,0},
{1,1,0,1,0,0,0,0,0},
{1,1,1,0,0,0,0,0,0},
{0,1,1,0,0,1,0,0,0},
{0,0,1,0,0,1,0,0,1},
{0,0,0,0,0,1,0,1,1},
{0,0,0,0,0,0,1,1,1},
{0,0,0,1,0,0,1,0,0},
{1,0,0,1,0,0,0,0,0},
{1,1,0,0,0,0,0,0,0},
{0,1,1,0,0,0,0,0,0},
{0,0,1,0,0,1,0,0,0},
{0,0,0,0,0,1,0,0,1},
{0,0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,1,1,0},
{0,0,0,1,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0},
{0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0,0},
};


#define OPT (4)
IMAGPROC_nStatus IMAGEPROC__enLBPU(LCDC_TFT_TypeDef *psLayerSource,LCDC_TFT_TypeDef *psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
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


    uint8_t u8LBPUValue=0;

    int16_t s16Count=0;

    uint8_t u8Pixel[9];
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

    if(u16DimHeight<=2)
        return IMAGPROC_enERROR;

    Cache__vWbInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal);
    u8Mod=(u16DimWidth*u16DimHeight)%OPT;
    if(u8Mod)
      u8Mod=OPT-u8Mod;

    //uint8_t* restrict u8Pixel =(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*16);
    uint8_t* restrict pu8SubImage =(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*16);
    uint8_t* restrict pu8LayerSource =(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint8_t* restrict pu8LayerDest =(uint8_t *) memalign(1024*1024,sizeof(uint8_t)*u16DimWidth*u16DimHeight+u8Mod);

    uint8_t* pu8LayerSourceInitial =pu8LayerSource;
    uint8_t* pu8LayerDestInitial =pu8LayerDest;

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


    _nassert ((int)(u8Pixel) % 8 == 0);
    _nassert ((int)(pu8SubImage) % 8 == 0);
    _nassert ((int)(pu8LayerSource) % 8 == 0);
    _nassert ((int)(pu8LayerDest) % 8 == 0);
    pu8LayerSource+=u16DimWidth;

    #pragma UNROLL(1)
    #pragma MUST_ITERATE (1,,1)
    for(s32Index=0;s32Index<(u16DimHeight*u16DimWidth)-(u16DimWidth<<1);s32Index++)
    {
        if(s16Count>0)
        {
            if(s16Count<(u16DimWidth-1))
            {
                LBPU_vFillPixelArray(u8Pixel,(uint8_t*)pu8LayerSource,u16DimWidth);
                LBPU_vComparative(pu8SubImage,u8Pixel);
                u8LBPUValue= LBPU_u8Decision(LBPU,pu8SubImage);

                *((uint8_t*)pu8LayerDest)= u8LBPUValue<<2;
            }
            else
            {
                s16Count=-1;
                *((uint8_t*)pu8LayerDest)=0;
            }
        }
        else
        {

            *((uint8_t*)pu8LayerDest)=0;
        }

        s16Count++;
        pu8LayerDest++;
        pu8LayerSource++;

    }


    Cache__vWbL2 ((uint32_t)pu8LayerDestInitial, u16DimHeight*u16DimWidth);


    sLayer.layerWidthTotal=u16DimWidth;
    sLayer.layerHeightTotal=1;


    sLayer.variableType=VARIABLETYPE_enUCHAR;
    sLayer.layerDataAddress=(uint32_t)pu8LayerDestInitial;
    LCDC__vLayer_Clear(&sLayer,0);
    sLayer.layerDataAddress=(uint32_t)pu8LayerDest;
    LCDC__vLayer_Clear(&sLayer,0);


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
    free(pu8SubImage);
    //free(u8Pixel);
    return IMAGPROC_enOK;
}

void LBPU_vFillPixelArray(uint8_t u8Pixel[9],uint8_t* restrict pu8LayerSource, uint16_t u16DimWidth )
{
    u8Pixel[0]= *((uint8_t*)pu8LayerSource-1-u16DimWidth);
    u8Pixel[1]= *((uint8_t*)pu8LayerSource-u16DimWidth); //top
    u8Pixel[2]= *((uint8_t*)pu8LayerSource+1-u16DimWidth);
    u8Pixel[3]= *((uint8_t*)pu8LayerSource-1); //left
    u8Pixel[4]= *((uint8_t*)pu8LayerSource);
    u8Pixel[5]= *((uint8_t*)pu8LayerSource+1); //right
    u8Pixel[6]= *((uint8_t*)pu8LayerSource-1+u16DimWidth);
    u8Pixel[7]= *((uint8_t*)pu8LayerSource+u16DimWidth); //bottom
    u8Pixel[8]= *((uint8_t*)pu8LayerSource+1+u16DimWidth);
}

void LBPU_vComparative(uint8_t pu8SubImage[9], uint8_t u8Pixel[9])
{
    uint8_t u8PixelCenter =u8Pixel[4];
    int32_t s32Index=0;

   // _nassert ((int)(u8Pixel) % 8 == 0);
    _nassert ((int)(pu8SubImage) % 8 == 0);
    #pragma UNROLL(3)
    #pragma MUST_ITERATE (3,9,3)
    for (s32Index=0; s32Index<9; s32Index++)
    {
        if(u8PixelCenter>=u8Pixel[s32Index])
            pu8SubImage[s32Index]=1;
        else
            pu8SubImage[s32Index]=0;
    }
    pu8SubImage[4]=0;

}

uint8_t LBPU_u8Decision(uint8_t LBPU[58][9],uint8_t pu8SubImage[9])
{
    uint32_t s32Sub=0;
    uint8_t u8LBPUValue=58;
    uint8_t u8LBPUCounter=0;

    _nassert ((int)(pu8SubImage) % 8 == 0);
    _nassert ((int)(LBPU) % 8 == 0);
    #pragma UNROLL(1)
    #pragma MUST_ITERATE (1,58,1)
    for(s32Sub=0;s32Sub<58;s32Sub++)
    {
        u8LBPUCounter=0;
        if(LBPU[s32Sub][0]==pu8SubImage[0]) u8LBPUCounter|=1;
        if(LBPU[s32Sub][1]==pu8SubImage[1]) u8LBPUCounter++;
        if(LBPU[s32Sub][2]==pu8SubImage[2]) u8LBPUCounter|=4;
        if(LBPU[s32Sub][3]==pu8SubImage[3]) u8LBPUCounter++;
        if(LBPU[s32Sub][4]==pu8SubImage[4]) u8LBPUCounter|=8;
        if(LBPU[s32Sub][5]==pu8SubImage[5]) u8LBPUCounter++;
        if(LBPU[s32Sub][6]==pu8SubImage[6]) u8LBPUCounter|=0x20;
        if(LBPU[s32Sub][7]==pu8SubImage[7]) u8LBPUCounter++;
        if(LBPU[s32Sub][8]==pu8SubImage[8]) u8LBPUCounter|=0x40;
        if(u8LBPUCounter==113)
        {
            u8LBPUValue=s32Sub;
            break;
        }

    }
    return u8LBPUValue;

}
