/*
 * IMAGEPROC__en16bConectivity8.c
 *
 *  Created on: 06/09/2019
 *      Author: Lalo
 */


#include <ImageProcessing.h>

typedef struct {
    uint16_t* stack;
    uint16_t width;
    uint16_t height;
    uint16_t input;
    uint16_t output;
    int16_t labelNo;
    uint16_t x;
    uint16_t y;
}CONECTIVITY8_TypeDef;

#define LABELCOMPONENT(xs,ys,xd,yd,returnLabel) { sConectivity.stack[s32SP] = xs; sConectivity.stack[s32SP+1] = ys; sConectivity.stack[s32SP+2] = xd; sConectivity.stack[s32SP+3] = yd; sConectivity.stack[s32SP+4] = returnLabel; s32SP += 5; goto START; }

#define XSOURCE (sConectivity.stack[s32SP-5])
#define YSOURCE (sConectivity.stack[s32SP-4])
#define XDEST (sConectivity.stack[s32SP-3])
#define YDEST (sConectivity.stack[s32SP-2])

#define RETURN8C { s32SP -= 5;                \
                 switch (sConectivity.stack[s32SP+4])    \
                 {                       \
                 case 1 : goto RETURN1;  \
                 case 2 : goto RETURN2;  \
                 case 3 : goto RETURN3;  \
                 case 4 : goto RETURN4;  \
                 case 5 : goto RETURN5;  \
                 case 6 : goto RETURN6;  \
                 case 7 : goto RETURN7;  \
                 case 8 : goto RETURN8;  \
                 default: return;        \
                 }                         \
               }




void vLabelComponent8(CONECTIVITY8_TypeDef sConectivity,LCDC_AREA_TypeDef* sArea)
{

    sConectivity.stack[0] = sConectivity.x;
    sConectivity.stack[1] = sConectivity.y;
    sConectivity.stack[2] = sConectivity.x;
    sConectivity.stack[3] = sConectivity.y;
    sConectivity.stack[4] = 0;  /* return - component is labelled */
    int32_t s32SP   = 5;
    uint32_t u32IndexSource;
    uint32_t u32IndexDest;

    START: /* Recursive routine starts here */

    u32IndexSource = XSOURCE + sConectivity.width*YSOURCE;
    u32IndexDest = XDEST + sConectivity.width*YDEST;
    if (*((uint16_t* )sConectivity.input+u32IndexSource) == 0) RETURN8C;   /* This pixel is not part of a component */
    if (*((uint16_t* )sConectivity.output+u32IndexDest) != 0) RETURN8C;   /* This pixel has already been labelled  */
    if(XDEST<sArea->Xmin)
      sArea->Xmin=XDEST;
    if(XDEST>sArea->Xmax)
      sArea->Xmax=XDEST;
    if(YDEST<sArea->Ymin)
      sArea->Ymin=YDEST;
    if(YDEST>sArea->Ymax)
      sArea->Ymax=YDEST;
    sArea->area++;
    *((uint16_t* )sConectivity.output+u32IndexDest) = sConectivity.labelNo;

    if ((XSOURCE) > 0)
      LABELCOMPONENT(XSOURCE-1, YSOURCE,XDEST-1, YDEST, 1);   /* left  pixel */

    RETURN1:
    if ((XSOURCE )< (sConectivity.width-1))
      LABELCOMPONENT(XSOURCE+1, YSOURCE,XDEST+1, YDEST, 2);   /* rigth pixel */

    RETURN2:
    if ((YSOURCE)> 0)
      LABELCOMPONENT(XSOURCE, YSOURCE-1,XDEST, YDEST-1, 3);   /* upper pixel */

    RETURN3:
    if ((YSOURCE) < (sConectivity.height-1))
      LABELCOMPONENT(XSOURCE, YSOURCE+1,XDEST, YDEST+1, 4);   /* lower pixel */

    RETURN4:
    if (((XSOURCE) > 0)&& ((YSOURCE) > 0))
        LABELCOMPONENT(XSOURCE-1, YSOURCE-1,XDEST-1, YDEST-1, 5);   /* left  pixel */

    RETURN5:
    if (((XSOURCE) < (sConectivity.width-1))&& ((YSOURCE) > 0))
        LABELCOMPONENT(XSOURCE+1, YSOURCE-1,XDEST+1, YDEST-1, 6);   /* left  pixel */

    RETURN6:
    if (((XSOURCE) > 0)&& ((YSOURCE)< (sConectivity.height-1)))
        LABELCOMPONENT(XSOURCE-1, YSOURCE+1,XDEST-1, YDEST+1, 7);   /* left  pixel */

    RETURN7:
    if (((XSOURCE) < (sConectivity.width-1))&& ((YSOURCE) < (sConectivity.height-1)))
        LABELCOMPONENT(XSOURCE+1, YSOURCE+1,XDEST+1, YDEST+1, 8);   /* left  pixel */

    RETURN8:
      RETURN8C;
}

#define OPT (1)
IMAGPROC_nStatus IMAGEPROC__en16bConectivity8(LCDC_TFT_TypeDef *psLayerSource,LCDC_TFT_TypeDef *psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, LCDC_AREA_TypeDef* sArea)
{
    LCDC_TFT_TypeDef sLayer;
    LCDC_DIMENSIONS_TypeDef sDimLayer;

    int32_t s32Width=0,s32Height=0,s32HeightDest=0;
    uint32_t u32LayerAddressDest;

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


    LCDC_AREA_TypeDef* psActualArea=sArea;
    int32_t s32LabelNo = 0;
    CONECTIVITY8_TypeDef sConectivity;

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
    uint16_t* volatile restrict pu16LayerSource =(uint16_t *) memalign(8,sizeof(uint16_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint16_t* volatile restrict pu16LayerDest =(uint16_t *) memalign(8,sizeof(uint16_t)*u16DimWidth*u16DimHeight+u8Mod);
    uint16_t* volatile restrict pu16LayerStack = (uint16_t*) memalign(8,5*sizeof(uint16_t)*(u16DimWidth*u16DimHeight + 1));
    uint16_t* pu16LayerSourceInitial =pu16LayerSource;
    uint16_t* pu16LayerDestInitial =pu16LayerDest;
    uint16_t* volatile restrict pu16LayerStackInitial =pu16LayerStack;


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


    sLayer.layerDataAddress=(uint32_t)pu16LayerDest;
    LCDC__vLayer_Clear(&sLayer,0);

    _nassert ((int)(pu16LayerStack) % 8 == 0);
    _nassert ((int)(pu16LayerSource) % 8 == 0);
    _nassert ((int)(pu16LayerDest) % 8 == 0);

    #pragma UNROLL(OPT)
    #pragma MUST_ITERATE (OPT,,OPT)
    for ( s32Height = 0; s32Height < u16DimHeight; s32Height++)
    {
      for ( s32Width = 0; s32Width < u16DimWidth; s32Width++)
      {
          if(*((uint16_t*)pu16LayerSource+s32Width+(s32Height*u16DimWidth))==0) continue;
          if(*((uint16_t*)pu16LayerDest+s32Width+(s32Height*u16DimWidth))!=0) continue;
          /* New component found */
          psActualArea->Xmin=s32Width;
          psActualArea->Xmax=s32Width;
          psActualArea->Ymin=s32Height;
          psActualArea->Ymax=s32Height;
          psActualArea->area=1;
          s32LabelNo++;

          sConectivity.stack=pu16LayerStack;
          sConectivity.width=u16DimWidth;
          sConectivity.height=u16DimHeight;
          sConectivity.input=psLayerSource->layerDataAddress;
          sConectivity.output=psLayerDest->layerDataAddress;
          sConectivity.labelNo=s32LabelNo;
          sConectivity.x=s32Width;
          sConectivity.y=s32Height;

          vLabelComponent8(sConectivity,psActualArea);
          psActualArea++;

      }

    }


    Cache__vWbL2 ((uint32_t)pu16LayerDestInitial, u16DimHeight*u16DimWidth*2);

    sLayer.variableType=VARIABLETYPE_enUSHORT;
    sDimLayer.X[1]=u16DimX1;
    sDimLayer.Y[1]=u16DimY1;
    sDimLayer.X[0]=0;
    sDimLayer.Y[0]=0;
    sLayer.layerDataAddress=(uint32_t)pu16LayerDestInitial;
    LCDC__enLayer_Copy(&sLayer,psLayerDest,sDimLayer);

    free(pu16LayerSourceInitial);
    free(pu16LayerDestInitial);
    return IMAGPROC_enOK;

}
