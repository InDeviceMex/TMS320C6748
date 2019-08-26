/*
 * LCDC.c
 *
 *  Created on: 20/07/2019
 *      Author: Lalo
 */

#include "LCDC.h"


int32_t LCDC__s32Layer_ConvString( char* pcStringIn,char* pcStringOut);

#pragma DATA_SECTION(LCDC_sLayerBGBuffer, ".MyData")
#pragma DATA_ALIGN(LCDC_sLayerBGBuffer, 0x8000)
volatile LCDC_Frame_TypeDef LCDC_sLayerBGBuffer;
uint16_t LCDC_u16LayerBGPosInitBGX[2]={0};//{(1024-640)/2,0};
uint16_t LCDC_u16LayerBGPosInitBGY[2]={0};//{(600-480)/2,0};
uint16_t LCDC_u16LayerBGPosInitX[2]={0};
uint16_t LCDC_u16LayerBGPosInitY[2]={0};
char LCDC_cLayerBGString[10];
#define LCDC_LayerBG_SubLayerMAX (10)
LCDC_TFT_TypeDef* LCDC_u32LayerBGSubLayers[LCDC_LayerBG_SubLayerMAX];

LCDC_TFT_TypeDef LCDC_sLayerBG={
        LCDC, //registros
        (uint32_t)LCDC_sLayerBGBuffer.Palette, (uint32_t)LCDC_sLayerBGBuffer.Data, 0, 0, 0, 0,//direcciones de memoria

        0xF800, 0x001F, //colores BG y Font
        &FONT_s16x24, LCDC_cLayerBGString, //font utilizada y memoria para strings

        640,480,640,480,  //tamaño del layer

        1,1,1,1,
        0,(uint16_t*)LCDC_u16LayerBGPosInitBGX,   //posicion de inicio layerBGXi
        0,(uint16_t*)LCDC_u16LayerBGPosInitBGY,   //posicion de inicio layerBGYi
        0,(uint16_t*)LCDC_u16LayerBGPosInitX,     //posicion de inicio layerXi
        0,(uint16_t*)LCDC_u16LayerBGPosInitY,     //posicion de inicio layerYi
        0,0,0,                                  //posiciones para radio

        0,//sublayer num
        0,//sublayers creadas
        LCDC_LayerBG_SubLayerMAX,//sublayer maximas
        0,//layerBG
        LCDC_u32LayerBGSubLayers,//puntero a sus sublayers
        LAYER_TYPE_enIMAGE_NOHEADER,            //tipo de layer
        VARIABLETYPE_enUSHORT,//tipo de variable utilizada en la layer
};




LCDC_TFT_TypeDef    *LCDC_psLayerBG=&LCDC_sLayerBG;
LCDC_CONFIGURATION_TypeDef LCDC_sConfigParameter;




void LCDC__vInit(void)
{

    LCDC_sConfigParameter.pwidth=LCDC_X;
    LCDC_sConfigParameter.pheight=LCDC_Y;

    LCDC_sConfigParameter.hbp=134;
    LCDC_sConfigParameter.hfp=16;
    LCDC_sConfigParameter.hsw=10;

    LCDC_sConfigParameter.vbp=11;
    LCDC_sConfigParameter.vfp=32;
    LCDC_sConfigParameter.vsw=2;

    DDR2_PBBPR->PR_OLD_COUNT = 0x30;


    /* Palette */
    LCDC_sLayerBGBuffer.Palette[0]=0x4000;

    LCDC_sLayerBGBuffer.Palette[1] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[2] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[3] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[4] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[5] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[6] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[7] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[8] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[9] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[10] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[11] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[12] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[13] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[14] = 0x0000;
    LCDC_sLayerBGBuffer.Palette[15] = 0x0000;


    SYSCFG0->PINMUX_Bit[0].PINMUX_19_16=2;//GP7_13=LCD_D[5]
    SYSCFG0->PINMUX_Bit[0].PINMUX_23_20=2;//GP7_13=LCD_D[5]
    SYSCFG0->PINMUX_Bit[1].PINMUX_27_24=2;//GP7_11=LCD_D[3]
    SYSCFG0->PINMUX_Bit[1].PINMUX_31_28=2;//GP7_10=LCD_D[2]

    SYSCFG0->PINMUX_Bit[16].PINMUX_11_8=2;//GP7_15=LCD_D[7]
    SYSCFG0->PINMUX_Bit[16].PINMUX_15_12=2;//GP7_14=LCD_D[6]
    SYSCFG0->PINMUX_Bit[16].PINMUX_19_16=2;//GP7_13=LCD_D[5]
    SYSCFG0->PINMUX_Bit[16].PINMUX_23_20=2;//GP7_12=LCD_D[4]
    SYSCFG0->PINMUX_Bit[16].PINMUX_27_24=2;//GP7_11=LCD_D[3]
    SYSCFG0->PINMUX_Bit[16].PINMUX_31_28=2;//GP7_10=LCD_D[2]


    SYSCFG0->PINMUX_Bit[16].PINMUX_11_8=2;//GP7_15=LCD_D[7]
    SYSCFG0->PINMUX_Bit[16].PINMUX_15_12=2;//GP7_14=LCD_D[6]
    SYSCFG0->PINMUX_Bit[16].PINMUX_19_16=2;//GP7_13=LCD_D[5]
    SYSCFG0->PINMUX_Bit[16].PINMUX_23_20=2;//GP7_12=LCD_D[4]
    SYSCFG0->PINMUX_Bit[16].PINMUX_27_24=2;//GP7_11=LCD_D[3]
    SYSCFG0->PINMUX_Bit[16].PINMUX_31_28=2;//GP7_10=LCD_D[2]

    SYSCFG0->PINMUX_Bit[17].PINMUX_3_0=2;//GP7_9=LCD_D[1]
    SYSCFG0->PINMUX_Bit[17].PINMUX_7_4=2;//GP7_8=LCD_D[0]
    SYSCFG0->PINMUX_Bit[17].PINMUX_11_8=2;//GP7_7=LCD_D[15]
    SYSCFG0->PINMUX_Bit[17].PINMUX_15_12=2;//GP7_6=LCD_D[14]
    SYSCFG0->PINMUX_Bit[17].PINMUX_19_16=2;//GP7_5=LCD_D[13]
    SYSCFG0->PINMUX_Bit[17].PINMUX_23_20=2;//GP7_4=LCD_D[12]
    SYSCFG0->PINMUX_Bit[17].PINMUX_27_24=2;//GP7_3=LCD_D[11]
    SYSCFG0->PINMUX_Bit[17].PINMUX_31_28=2;//GP7_2=LCD_D[10]

    SYSCFG0->PINMUX_Bit[18].PINMUX_3_0=2;//GP7_1=LCD_D[9]
    SYSCFG0->PINMUX_Bit[18].PINMUX_7_4=2;//GP7_0=LCD_D[8]

    SYSCFG0->PINMUX_Bit[18].PINMUX_27_24=2;//GP8_11=LCD_PCLK
    SYSCFG0->PINMUX_Bit[18].PINMUX_31_28=2;//GP8_10=LCD_MCLK //not used

    SYSCFG0->PINMUX_Bit[19].PINMUX_3_0=2;//GP8_9=LCD_HSYNC
    SYSCFG0->PINMUX_Bit[19].PINMUX_7_4=2;//GP8_8=LCD_VSYNC
    SYSCFG0->PINMUX_Bit[19].PINMUX_27_24=2;//GP6_0= LCD_AC_ENB_CS


    SYSCFG0->PINMUX_Bit[18].PINMUX_31_28=8;//GP8_10=BackLight

    GPIO8_DIR_R&=~GPIO_R_P10_MASK;
    GPIO8_CLR_DATA_R=GPIO_R_P10_MASK;


   SYSCFG0_CFGCHIP1->EDMA31TC0DBS=2;
   SYSCFG0_CFGCHIP0->EDMA30TC0DBS=2;
   SYSCFG0_CFGCHIP0->EDMA30TC1DBS=2;

    *((uint32_t*)(EDMA3_0_TC0_BASE+0x140))=0;
    *((uint32_t*)(EDMA3_0_TC1_BASE+0x140))=0;
    SYSCFG0_MSTPRI2->LCDC_ = 0; //Prioridad LCDC maxima-1
    SYSCFG0_MSTPRI1->VPIF_DMA_0 = 1; //Prioridad LCDC maxima-1
    SYSCFG0_MSTPRI1->VPIF_DMA_1 = 1; //Prioridad LCDC maxima-1
    SYSCFG0_MSTPRI1->EDMA30TC0 = 1; //Prioridad DMA minima-1
    SYSCFG0_MSTPRI1->EDMA30TC1 = 1; //Prioridad DMA minima-1
    SysTick__vDelayUs(10000);

    LCDC_RASTER_CTRL->RASTER_EN= 0;         // Turn raster controller off
    SysTick__vDelayUs(10000);
    LCDC_LCD_STAT_R= 0x000003ff;    // Clear status bits
    LCDC_LCD_CTRL->MODESEL=1; //rasterMode  = 0x00000601;
    LCDC_LCD_CTRL->CLKDIV=6;   // PCLK = 150MHz / 6 = 25 MHz maximo;
    // Horiz Back  Porch = 134;
    // Horiz Front Porch = 16;
    // Horiz Sync  Widht = 10;
    // Pixel Per   Line  = (40-1+1)*16 =640
    LCDC_RASTER_TIMING_0->HBP=LCDC_sConfigParameter.hbp-1;
    LCDC_RASTER_TIMING_0->HFP=LCDC_sConfigParameter.hfp-1;
    LCDC_RASTER_TIMING_0->HSW=LCDC_sConfigParameter.hsw-1;
    LCDC_RASTER_TIMING_0->PPL=(LCDC_sConfigParameter.pwidth/16)-1;

    // Vertical Back  Porch = 11;
    // Vertical Front Porch = 32;
    // Vertical Sync  Widht = 2;
    // Line     Per   Panel  = (480-1+1) =480
    LCDC_RASTER_TIMING_1->VBP=LCDC_sConfigParameter.vbp ;
    LCDC_RASTER_TIMING_1->VFP=LCDC_sConfigParameter.vfp ;
    LCDC_RASTER_TIMING_1->VSW=LCDC_sConfigParameter.vsw-1 ;
    LCDC_RASTER_TIMING_1->LPP=LCDC_sConfigParameter.pheight-1 ;

    LCDC_RASTER_TIMING_2->ACB=0;
    LCDC_RASTER_TIMING_2->ACB_I=0;
    LCDC_RASTER_TIMING_2->IVS=1;   //VSYNC active Low
    LCDC_RASTER_TIMING_2->IHS=1;   //HSYNC active Low
    LCDC_RASTER_TIMING_2->IPC=1;   //DATA falling active
    LCDC_RASTER_TIMING_2->BIAS=0;   //DE  active high
    LCDC_RASTER_TIMING_2->SYNC_EDGE=0;   //Sync  active rising
    LCDC_RASTER_TIMING_2->SYNC_CTRL=1;   //sync active

    LCDC_RASTER_SUBPANEL_R     = 0x0; //disable subpanel
    LCDC_LCDDMA_CTRL_R         = 0x00000000;
    LCDC_LCDDMA_CTRL->BURST_SIZE=4;//2;
    LCDC_LCDDMA_CTRL->TH_FIFO_READY=6;//6;

    LCDC_LCDDMA_FB0_BASE_R     = (uint32_t)&LCDC_sLayerBGBuffer.Palette[0];   // Frame buffer start
    LCDC_LCDDMA_FB0_CEILING_R  =  (uint32_t)&LCDC_sLayerBGBuffer.Palette[0]+(LCDC_X*LCDC_Y*2)+32-1;


    SysTick__vDelayUs(10000);

    LCDC_RASTER_CTRL->TFT_STN  = 1;
    LCDC_RASTER_CTRL->PLM=1  ;
    LCDC_RASTER_CTRL->STN_565  = 1;
    LCDC_RASTER_CTRL->RD_ORDER  = 0;

    SysTick__vDelayUs(10000);
    LCDC_RASTER_CTRL->RASTER_EN = 1;    // Enable controller

    while(((LCDC_LCD_STAT_R)&LCDC_LCD_STAT_R_PL_MASK) == 0);

    LCDC_RASTER_CTRL->RASTER_EN =0;    // Turn raster controller off
    LCDC_LCDDMA_FB0_BASE_R  = (uint32_t)(&LCDC_sLayerBGBuffer.Data);
    SysTick__vDelayUs(10000);
    LCDC_RASTER_CTRL->TFT_STN  = 1;
    LCDC_RASTER_CTRL->STN_565  = 1;
    LCDC_RASTER_CTRL->RD_ORDER  = 0;
    LCDC_RASTER_CTRL->PLM=2  ;
    SysTick__vDelayUs(10000);
    LCDC_RASTER_CTRL->RASTER_EN = 1;    // Enable controller

    SysTick__vDelayUs(10000);
    LCDC__vInitQDMA();
}

void LCDC__vInitQDMA(void)
{

    EDMA3_0_CC0_ERROR->EMCR=0xFFFFFFFF;
    EDMA3_0_CC0_ERROR->QEMCR=0xFF;
    EDMA3_0_CC0_ERROR->CCERRCLR_Bit.QTHRXCD0=1;
    EDMA3_0_CC0_ERROR->CCERRCLR_Bit.QTHRXCD1=1;
    EDMA3_0_CC0_ERROR->CCERRCLR_Bit.TCCERR=1;

    EDMA3_0_CC0_GLOBAL->QCHMAP_Bit[7].TRWORD=7;
    EDMA3_0_CC0_GLOBAL->QCHMAP_Bit[7].PAENTRY=127;
    EDMA3_0_CC0_GLOBAL->QDMAQNUM_Bit.E7=1;


    EDMA3_0_CC0_INTERRUPT->ICR_Bit.I31=1;

    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT=0;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.TCC=31;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.STATIC=1;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.TCINTEN =1;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.SYNCDIM =1;
    EDMA3_0_CC0_PaRAM->PaRAM[127].LINK_BCNTRLD_Bit.LINK=0xFFFF;
    EDMA3_0_CC0_QDMA_CHANNEL->QEESR|=0x80;

}


void LCDC__vBackLight(BACKLIGHT_nStatus enState)
{
    if(enState== BACKLIGHT_enON)
    {
        GPIO8_SET_DATA_R=GPIO_R_P10_MASK;
    }
    else
    {
        GPIO8_CLR_DATA_R=GPIO_R_P10_MASK;
    }

}

void LCDC__vRefresh(void)
{
    LCDC_LCD_STAT_R|=LCDC_LCD_STAT_R_EOF0_MASK;
    while((LCDC_LCD_STAT_R&LCDC_LCD_STAT_R_EOF0_MASK)==0);
    LCDC_LCD_STAT_R|=LCDC_LCD_STAT_R_EOF0_MASK;
}

LCDC_TFT_TypeDef* LCDC__sLayerBG_GetPointer(void)
{
    return LCDC_psLayerBG;
}

LCDC_TFT_TypeDef* LCDC__sLayerBG_SetPointer(LCDC_TFT_TypeDef* restrict psLayer)
{
    LCDC_psLayerBG=psLayer;

    /* Palette */
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress)=0x4000;

    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+1) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+2) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+3) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+4) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+5) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+6) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+7) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+8) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+9) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+10) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+11) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+12) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+13) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+14) = 0x0000;
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+15) = 0x0000;

    LCDC_RASTER_CTRL->RASTER_EN = 0;    // Disable controller
    LCDC_LCDDMA_FB0_BASE_R     = LCDC_psLayerBG->layerHeaderAddress;   // Frame buffer start
    LCDC_LCDDMA_FB0_CEILING_R  = LCDC_psLayerBG->layerHeaderAddress+(LCDC_psLayerBG->layerWidthTotal*LCDC_psLayerBG->layerHeightTotal*2)+32-1;


    SysTick__vDelayUs(5000);

    LCDC_RASTER_CTRL->TFT_STN  = 1;
    LCDC_RASTER_CTRL->PLM=1  ;
    LCDC_RASTER_CTRL->STN_565  = 1;

    SysTick__vDelayUs(5000);
    LCDC_RASTER_CTRL->RASTER_EN = 1;    // Enable controller

    while(((LCDC_LCD_STAT_R)&LCDC_LCD_STAT_R_PL_MASK) == 0);

    LCDC_RASTER_CTRL->RASTER_EN =0;    // Turn raster controller off
    LCDC_LCDDMA_FB0_BASE_R  =LCDC_psLayerBG->layerDataAddress;
    SysTick__vDelayUs(5000);
    LCDC_RASTER_CTRL->TFT_STN  = 1;
    LCDC_RASTER_CTRL->STN_565  = 1;
    LCDC_RASTER_CTRL->PLM=2  ;
    SysTick__vDelayUs(5000);
    LCDC_RASTER_CTRL->RASTER_EN = 1;    // Enable controller

    SysTick__vDelayUs(5000);
    return LCDC_psLayerBG;
}

uint16_t LCDC__u16SetColorRed_FormatRGB565   (LCDC_COLOR_TypeDef* psColor)
{
    uint16_t u16ColorTemp=psColor->color;

    switch(psColor->colorComplete)
    {
    case COLOR_enCOMPLETE_EN:
        u16ColorTemp=(psColor->red&0x1F)<<11;
        break;
    case COLOR_enCOMPLETE_DIS:
        u16ColorTemp&=~0xF800;
        u16ColorTemp|=(psColor->red&0x1F)<<11;
        break;
    default:
        return 0xFF;
    }
    psColor->color=u16ColorTemp;
    return psColor->color;
}
uint16_t LCDC__u16SetColorGreen_FormatRGB565   (LCDC_COLOR_TypeDef* psColor)
{
    uint16_t u16ColorTemp=psColor->color;

    switch(psColor->colorComplete)
    {
    case COLOR_enCOMPLETE_EN:
        u16ColorTemp=(psColor->green&0x3F)<<5;
        break;
    case COLOR_enCOMPLETE_DIS:
        u16ColorTemp&=~0x07E0;
        u16ColorTemp|=(psColor->green&0x3F)<<5;
        break;
    default:
        return 0xFF;
    }
    psColor->color=u16ColorTemp;
    return psColor->color;
}
uint16_t LCDC__u16SetColorBlue_FormatRGB565   (LCDC_COLOR_TypeDef* psColor)
{
    uint16_t u16ColorTemp=psColor->color;

    switch(psColor->colorComplete)
    {
    case COLOR_enCOMPLETE_EN:
        u16ColorTemp=(psColor->blue&0x1F);
        break;
    case COLOR_enCOMPLETE_DIS:
        u16ColorTemp&=~0x001F;
        u16ColorTemp|=(psColor->blue&0x1F);
        break;
    default:
        return 0xFF;
    }
    psColor->color=u16ColorTemp;
    return psColor->color;
}

uint8_t LCDC__u8GetColorRed_FormatRGB565(LCDC_COLOR_TypeDef* psColor)
{
    uint16_t u16ColorTemp=psColor->color;

    u16ColorTemp&=0xF800;
    u16ColorTemp>>=11;
    psColor->red=(uint8_t)u16ColorTemp;
    return psColor->red;
}

uint8_t LCDC__u8GetColorGreen_FormatRGB565(LCDC_COLOR_TypeDef* psColor)
{
    uint16_t u16ColorTemp=psColor->color;

    u16ColorTemp&=0x07E0;
    u16ColorTemp>>=5;
    psColor->green=(uint8_t)u16ColorTemp;
    return psColor->green;
}

uint8_t LCDC__u8GetColorBlue_FormatRGB565(LCDC_COLOR_TypeDef* psColor)
{
    uint16_t u16ColorTemp=psColor->color;

    u16ColorTemp&=0x001F;
    psColor->blue=(uint8_t)u16ColorTemp;
    return psColor->blue;
}

Lcdc_nStatus LCDC__enSetColorSplit_FormatRGB565 (LCDC_COLOR_TypeDef* psColor)
{
    Lcdc_nStatus enStatus = LCDC_enERROR;
    if( psColor->colorComplete ==COLOR_enCOMPLETE_DIS)
    {
        LCDC__u16SetColorRed_FormatRGB565(psColor);
        LCDC__u16SetColorGreen_FormatRGB565(psColor);
        LCDC__u16SetColorBlue_FormatRGB565(psColor);
        enStatus= LCDC_enOK;
    }
    return enStatus;

}
uint16_t LCDC__enGetColorSplit_FormatRGB565 (LCDC_COLOR_TypeDef* psColor)
{
    LCDC__u8GetColorRed_FormatRGB565(psColor);
    LCDC__u8GetColorGreen_FormatRGB565(psColor);
    LCDC__u8GetColorBlue_FormatRGB565(psColor);
    return psColor->color;
}


uint32_t LCDC__u32Layer_GetDataAddress(LCDC_TFT_TypeDef* restrict psLayer)
{
    return psLayer->layerDataAddress;
}
uint32_t LCDC__u32LayerBG_GetDataAddress(void)
{
    return LCDC_psLayerBG->layerDataAddress;
}

uint32_t LCDC__u32Layer_SetDataAddress(LCDC_TFT_TypeDef* restrict pslayer, uint32_t u32Address)
{
    pslayer->layerDataAddress=u32Address;
    return pslayer->layerDataAddress;
}
uint32_t LCDC__u32LayerBG_SetDataAddress(uint32_t u32Address)
{
    uint32_t u32I=0;
    LCDC_psLayerBG->layerDataAddress=u32Address;
    /* Palette */
       *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress)=0x4000;
       for (u32I = 1; u32I < 16; u32I++)
           *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+u32I) = 0x0000;

       LCDC_RASTER_CTRL->RASTER_EN = 0;    // Disable controller
       LCDC_LCDDMA_FB0_BASE_R     = LCDC_psLayerBG->layerHeaderAddress;   // Frame buffer start
       LCDC_LCDDMA_FB0_CEILING_R  = LCDC_psLayerBG->layerHeaderAddress+(LCDC_psLayerBG->layerWidthTotal*LCDC_psLayerBG->layerHeightTotal*2)+32-1;


       SysTick__vDelayUs(5000);

       LCDC_RASTER_CTRL->TFT_STN  = 1;
       LCDC_RASTER_CTRL->PLM=1  ;
       LCDC_RASTER_CTRL->STN_565  = 1;

       SysTick__vDelayUs(5000);
       LCDC_RASTER_CTRL->RASTER_EN = 1;    // Enable controller

       while(((LCDC_LCD_STAT_R)&LCDC_LCD_STAT_R_PL_MASK) == 0);

       LCDC_RASTER_CTRL->RASTER_EN =0;    // Turn raster controller off
       LCDC_LCDDMA_FB0_BASE_R  =LCDC_psLayerBG->layerDataAddress;
       SysTick__vDelayUs(5000);
       LCDC_RASTER_CTRL->TFT_STN  = 1;
       LCDC_RASTER_CTRL->STN_565  = 1;
       LCDC_RASTER_CTRL->PLM=2  ;
       SysTick__vDelayUs(5000);
       LCDC_RASTER_CTRL->RASTER_EN = 1;    // Enable controller

       SysTick__vDelayUs(5000);
    return LCDC_psLayerBG->layerDataAddress;
}


uint32_t LCDC__u32Layer_GetHeaderAddress(LCDC_TFT_TypeDef* restrict psLayer)
{
    return psLayer->layerHeaderAddress;
}
uint32_t LCDC__u32LayerBG_GetHeaderAddress(void)
{
    return LCDC_psLayerBG->layerHeaderAddress;
}

uint32_t LCDC__u32Layer_SetHeaderAddress(LCDC_TFT_TypeDef* restrict pslayer, uint32_t u32Address)
{
    pslayer->layerHeaderAddress=u32Address;
    return pslayer->layerHeaderAddress;
}
uint32_t LCDC__u32LayerBG_SetHeaderAddress(uint32_t u32Address)
{
    uint32_t u32I=0;
    LCDC_psLayerBG->layerHeaderAddress=u32Address;    /* Palette */
    *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress)=0x4000;
    for (u32I = 1; u32I < 16; u32I++)
        *((uint16_t*)LCDC_psLayerBG->layerHeaderAddress+u32I) = 0x0000;

    LCDC_RASTER_CTRL->RASTER_EN = 0;    // Disable controller
    LCDC_LCDDMA_FB0_BASE_R     = LCDC_psLayerBG->layerHeaderAddress;   // Frame buffer start
    LCDC_LCDDMA_FB0_CEILING_R  = LCDC_psLayerBG->layerHeaderAddress+(LCDC_psLayerBG->layerWidthTotal*LCDC_psLayerBG->layerHeightTotal*2)+32-1;


    SysTick__vDelayUs(5000);

    LCDC_RASTER_CTRL->TFT_STN  = 1;
    LCDC_RASTER_CTRL->PLM=1  ;
    LCDC_RASTER_CTRL->STN_565  = 1;

    SysTick__vDelayUs(5000);
    LCDC_RASTER_CTRL->RASTER_EN = 1;    // Enable controller

    while(((LCDC_LCD_STAT_R)&LCDC_LCD_STAT_R_PL_MASK) == 0);

    LCDC_RASTER_CTRL->RASTER_EN =0;    // Turn raster controller off
    LCDC_LCDDMA_FB0_BASE_R  =LCDC_psLayerBG->layerDataAddress;
    SysTick__vDelayUs(5000);
    LCDC_RASTER_CTRL->TFT_STN  = 1;
    LCDC_RASTER_CTRL->STN_565  = 1;
    LCDC_RASTER_CTRL->PLM=2  ;
    SysTick__vDelayUs(5000);
    LCDC_RASTER_CTRL->RASTER_EN = 1;    // Enable controller

    SysTick__vDelayUs(5000);
    return LCDC_psLayerBG->layerHeaderAddress;
}

uint32_t LCDC__u32Layer_GetCLUTAddress(LCDC_TFT_TypeDef* restrict psLayer)
{
    return psLayer->layerCLUTAddress;
}
uint32_t LCDC__u32LayerBG_GetCLUTAddress(void)
{
    return LCDC_psLayerBG->layerCLUTAddress;
}


uint32_t LCDC__u32Layer_SetCLUTAddress(LCDC_TFT_TypeDef* restrict pslayer, uint32_t u32Address)
{
    pslayer->layerCLUTAddress=u32Address;
    return pslayer->layerCLUTAddress;
}
uint32_t LCDC__u32LayerBG_SetCLUTAddress(uint32_t u32Address)
{
    LCDC_psLayerBG->layerCLUTAddress=u32Address;
    return LCDC_psLayerBG->layerCLUTAddress;
}





uint16_t LCDC__u16Layer_GetColorBG(LCDC_TFT_TypeDef* restrict psLayer)
{
    return psLayer->layerColorBG;
}
uint16_t LCDC__u16LayerBG_GetColorBG(void)
{
    return LCDC_psLayerBG->layerColorBG;
}


uint16_t LCDC__u16Layer_SetColorBG      (LCDC_TFT_TypeDef* restrict psLayer, uint16_t u16ColorBG)
{
    psLayer->layerColorBG=u16ColorBG;
    return psLayer->layerColorBG;
}

uint16_t LCDC__u16LayerBG_SetColorBG        (uint16_t u16ColorBG)
{
    LCDC_psLayerBG->layerColorBG=u16ColorBG;
    return LCDC_psLayerBG->layerColorBG;
}


uint8_t LCDC__u8Layer_GetColorBGRed(LCDC_TFT_TypeDef* restrict psLayer)
{
    uint16_t u16ColorTemp=psLayer->layerColorBG;

    u16ColorTemp&=0xF800;
    u16ColorTemp>>=11;
    return (uint8_t)u16ColorTemp;
}

uint8_t LCDC__u8LayerBG_GetColorBGRed(void)
{
    return LCDC__u8Layer_GetColorBGRed(LCDC_psLayerBG);
}


uint16_t LCDC__u16Layer_SetColorBGRed           (LCDC_TFT_TypeDef* restrict psLayer, uint8_t u8RedBG)
{
    uint16_t u16ColorTemp=psLayer->layerColorBG;

    u16ColorTemp&=~0xF800;
    u16ColorTemp|=(u8RedBG&0x1F)<<11;

    psLayer->layerColorBG=u16ColorTemp;
    return psLayer->layerColorBG;
}
uint16_t LCDC__u16LayerBG_SetColorBGRed         (uint8_t u8RedBG)
{
    return LCDC__u16Layer_SetColorBGRed(LCDC_psLayerBG,u8RedBG);
}




uint8_t LCDC__u8Layer_GetColorBGGreen(LCDC_TFT_TypeDef* restrict psLayer)
{
    uint16_t u16ColorTemp=psLayer->layerColorBG;

    u16ColorTemp&=0x07E0;
    u16ColorTemp>>=5;
    return (uint8_t)u16ColorTemp;
}

uint8_t LCDC__u8LayerBG_GetColorBGGreen(void)
{
    return LCDC__u8Layer_GetColorBGGreen(LCDC_psLayerBG);
}


uint16_t LCDC__u16Layer_SetColorBGGreen         (LCDC_TFT_TypeDef* restrict psLayer, uint8_t u8GreenBG)
{
    uint16_t u16ColorTemp=psLayer->layerColorBG;

    u16ColorTemp&=~0x07E0;
    u16ColorTemp|=(u8GreenBG&0x3F)<<5;

    psLayer->layerColorBG=u16ColorTemp;
    return psLayer->layerColorBG;
}
uint16_t LCDC__u16LayerBG_SetColorBGGreen           (uint8_t u8GreenBG)
{

    return LCDC__u16Layer_SetColorBGGreen(LCDC_psLayerBG,u8GreenBG);
}



uint8_t LCDC__u8Layer_GetColorBGBlue(LCDC_TFT_TypeDef* restrict psLayer)
{
    uint16_t u16ColorTemp=psLayer->layerColorBG;

    u16ColorTemp&=0x001F;
    return (uint8_t)u16ColorTemp;
}

uint8_t LCDC__u8LayerBG_GetColorBGBlue(void)
{
    return LCDC__u8Layer_GetColorBGBlue(LCDC_psLayerBG);
}


uint16_t LCDC__u16Layer_SetColorBGBlue          (LCDC_TFT_TypeDef* restrict psLayer, uint8_t u8BlueBG)
{
    uint16_t u16ColorTemp=psLayer->layerColorBG;


    u16ColorTemp&=~0x001F;
    u16ColorTemp|=(u8BlueBG&0x1F);

    psLayer->layerColorBG=u16ColorTemp;
    return psLayer->layerColorBG;
}
uint16_t LCDC__u16LayerBG_SetColorBGBlue            (uint8_t u8BlueBG)
{
    return LCDC__u16Layer_SetColorBGBlue(LCDC_psLayerBG,u8BlueBG);
}








uint16_t LCDC__u16Layer_GetColorFont(LCDC_TFT_TypeDef* restrict psLayer)
{
    return psLayer->layerColorFont;
}
uint16_t LCDC__u16LayerBG_GetColorFont(void)
{
    return LCDC_psLayerBG->layerColorFont;
}
uint16_t LCDC__u16Layer_SetColorFont        (LCDC_TFT_TypeDef* restrict psLayer, uint16_t u16ColorFont)
{
    psLayer->layerColorFont=u16ColorFont;
    return psLayer->layerColorFont;
}

uint16_t LCDC__u16LayerBG_SetColorFont      (uint16_t u16ColorFont)
{
    LCDC_psLayerBG->layerColorFont=u16ColorFont;
    return LCDC_psLayerBG->layerColorFont;
}

uint8_t LCDC__u8Layer_GetColorFontRed(LCDC_TFT_TypeDef* restrict psLayer)
{
    uint16_t u16ColorTemp=psLayer->layerColorFont;

    u16ColorTemp&=0xF800;
    u16ColorTemp>>=11;
    return (uint8_t)u16ColorTemp;
}

uint8_t LCDC__u8LayerBG_GetColorFontRed(void)
{
    return LCDC__u8Layer_GetColorFontRed(LCDC_psLayerBG);
}

uint16_t LCDC__u16Layer_SetColorFontRed         (LCDC_TFT_TypeDef* restrict psLayer, uint8_t u8RedBG)
{
    uint16_t u16ColorTemp=psLayer->layerColorFont;

    u16ColorTemp&=~0xF800;
    u16ColorTemp|=(u8RedBG&0x1F)<<11;

    psLayer->layerColorFont=u16ColorTemp;
    return psLayer->layerColorFont;
}
uint16_t LCDC__u16LayerBG_SetColorFontRed           (uint8_t u8RedBG)
{

    return LCDC__u16Layer_SetColorFontRed(LCDC_psLayerBG,u8RedBG);
}



uint8_t LCDC__u8Layer_GetColorFontGreen(LCDC_TFT_TypeDef* restrict psLayer)
{
    uint16_t u16ColorTemp=psLayer->layerColorFont;

    u16ColorTemp&=0x07E0;
    u16ColorTemp>>=5;
    return (uint8_t)u16ColorTemp;
}

uint8_t LCDC__u8LayerBG_GetColorFontGreen(void)
{

    return LCDC__u8Layer_GetColorFontGreen(LCDC_psLayerBG);
}


uint16_t LCDC__u16Layer_SetColorFontGreen           (LCDC_TFT_TypeDef* restrict psLayer, uint8_t u8GreenBG)
{
    uint16_t u16ColorTemp=psLayer->layerColorFont;

    u16ColorTemp&=~0x07E0;
    u16ColorTemp|=(u8GreenBG&0x3F)<<5;

    psLayer->layerColorFont=u16ColorTemp;
    return psLayer->layerColorFont;
}
uint16_t LCDC__u16LayerBG_SetColorFontGreen         (uint8_t u8GreenBG)
{

    return LCDC__u16Layer_SetColorFontGreen(LCDC_psLayerBG,u8GreenBG);
}

uint8_t LCDC__u8Layer_GetColorFontBlue(LCDC_TFT_TypeDef* restrict psLayer)
{
    uint16_t u16ColorTemp=psLayer->layerColorFont;

    u16ColorTemp&=0x001F;
    return u16ColorTemp;
}

uint8_t LCDC__u8LayerBG_GetColorFontBlue(void)
{
    return LCDC__u8Layer_GetColorFontBlue(LCDC_psLayerBG);
}

uint16_t LCDC__u16Layer_SetColorFontBlue            (LCDC_TFT_TypeDef* restrict psLayer, uint8_t u8BlueBG)
{
    uint16_t u16ColorTemp=psLayer->layerColorFont;


    u16ColorTemp&=~0x001F;
    u16ColorTemp|=(u8BlueBG&0x1F);

    psLayer->layerColorFont=u16ColorTemp;
    return psLayer->layerColorFont;
}
uint16_t LCDC__u16LayerBG_SetColorFontBlue          (uint8_t u8BlueBG)
{
    return LCDC__u16Layer_SetColorFontBlue(LCDC_psLayerBG,u8BlueBG);
}













FONT_TypeDef* LCDC__sLayer_GetFontType(LCDC_TFT_TypeDef* restrict psLayer)
{
    return psLayer->layerFont;
}


FONT_TypeDef* LCDC__sLayerBG_GetFontType(void)
{
    return LCDC_psLayerBG->layerFont;
}


FONT_TypeDef* LCDC__sLayer_SetFontType(LCDC_TFT_TypeDef* restrict psLayer, FONT_nSize enFontSize)
{
    switch(enFontSize)
    {
    case    FONT_enSize_16x24:
        psLayer->layerFont= &FONT_s16x24;
        break;
    case FONT_enSize_11x16:
        psLayer->layerFont= &FONT_s11x16;
        break;
    case FONT_enSize_8x16:
        psLayer->layerFont= &FONT_s8x16;
        break;
    case FONT_enSize_12x12:
        psLayer->layerFont= &FONT_s12x12;
        break;
    case FONT_enSize_8x12:
        psLayer->layerFont= &FONT_s8x12;
        break;
    case FONT_enSize_8x8:
        psLayer->layerFont= &FONT_s8x8;
        break;
    case FONT_enSize_6x8:
        psLayer->layerFont= &FONT_s6x8;
        break;
    case FONT_enSize_5x7:
        psLayer->layerFont= &FONT_s5x7;
        break;
    case FONT_enSize_8x16_MS_Gothic:
        psLayer->layerFont= &FONT_s8x16_MS_Gothic;
        break;
    case FONT_enSize_8x16_System:
        psLayer->layerFont= &FONT_s8x16_System;
        break;
    default:
        break;
    }
    return psLayer->layerFont;
}


FONT_TypeDef* LCDC__sLayerBG_SetFontType(FONT_nSize enFontSize)
{
    return LCDC__sLayer_SetFontType(LCDC_psLayerBG,enFontSize);

}








uint16_t LCDC__u16Layer_GetWidthTotal(LCDC_TFT_TypeDef* restrict psLayer)
{
    return psLayer->layerWidthTotal;
}
uint16_t LCDC__u16LayerBG_GetWidthTotal(void)
{
    return LCDC_psLayerBG->layerWidthTotal;
}

uint16_t LCDC__u16Layer_SetWidthTotal(LCDC_TFT_TypeDef* restrict psLayer,  uint16_t u16WidthTotal)
{
    psLayer->layerWidthTotal=u16WidthTotal;
    return psLayer->layerWidthTotal;
}

uint16_t LCDC__u16LayerBG_SetWidthTotal( uint16_t u16WidthTotal)
{
    LCDC_psLayerBG->layerWidthTotal=u16WidthTotal;
    LCDC_RASTER_TIMING_0->PPL=(LCDC_psLayerBG->layerWidthTotal/16)-1;
    return LCDC_psLayerBG->layerWidthTotal;
}


uint16_t LCDC__u16Layer_GetHeightTotal(LCDC_TFT_TypeDef* restrict psLayer)
{
    return psLayer->layerHeightTotal;
}
uint16_t LCDC__u16LayerBG_GetHeightTotal(void)
{
    return LCDC_psLayerBG->layerHeightTotal;
}
uint16_t LCDC__u16Layer_SetHeightTotal(LCDC_TFT_TypeDef* restrict psLayer,  uint16_t u16HeightTotal)
{
    psLayer->layerHeightTotal=u16HeightTotal;
    return psLayer->layerHeightTotal;
}
uint16_t LCDC__u16LayerBG_SetHeightTotal(uint16_t u16HeightTotal)
{
    LCDC_psLayerBG->layerHeightTotal=u16HeightTotal;
    LCDC_RASTER_TIMING_1->LPP=LCDC_psLayerBG->layerHeightTotal-1 ;
    return LCDC_psLayerBG->layerHeightTotal;
}

uint16_t LCDC__u16Layer_GetWidth(LCDC_TFT_TypeDef* restrict psLayer)
{
    return psLayer->layerWidth;
}
uint16_t LCDC__u16LayerBG_GetWidth(void)
{
    return LCDC_psLayerBG->layerWidth;
}

uint16_t LCDC__u16Layer_SetWidth(LCDC_TFT_TypeDef* restrict psLayer,  uint16_t u16Width)
{

    psLayer->layerWidth=u16Width;

    if((u16Width+ psLayer->layerXInit)>psLayer->layerWidthTotal)
        psLayer->layerWidth= psLayer->layerWidthTotal- psLayer->layerXInit;

    u16Width=psLayer->layerWidth;
    if(psLayer->layerBG!=0)
    {
        if((u16Width+ psLayer->layerBGXInit)>psLayer->layerBG->layerWidthTotal)
            psLayer->layerWidth= psLayer->layerBG->layerWidthTotal- psLayer->layerBGXInit;
    }

    return psLayer->layerWidth;
}

uint16_t LCDC__u16LayerBG_SetWidth(uint16_t u16Width)
{
    LCDC_psLayerBG->layerWidth=u16Width;

    if((u16Width+ LCDC_psLayerBG->layerXInit)>LCDC_psLayerBG->layerWidthTotal)
        LCDC_psLayerBG->layerWidth= LCDC_psLayerBG->layerWidthTotal- LCDC_psLayerBG->layerXInit;

    u16Width=LCDC_psLayerBG->layerWidth;
    if(LCDC_psLayerBG->layerBG!=0)
    {
        if((u16Width+ LCDC_psLayerBG->layerBGXInit)>LCDC_psLayerBG->layerBG->layerWidthTotal)
            LCDC_psLayerBG->layerWidth= LCDC_psLayerBG->layerBG->layerWidthTotal- LCDC_psLayerBG->layerBGXInit;
    }

    LCDC_RASTER_TIMING_0->PPL=(LCDC_psLayerBG->layerWidthTotal/16)-1;

    return LCDC_psLayerBG->layerWidth;
}


uint16_t LCDC__u16Layer_GetHeight(LCDC_TFT_TypeDef* restrict psLayer)
{
    return psLayer->layerHeight;
}
uint16_t LCDC__u16LayerBG_GetHeight(void)
{
    return LCDC_psLayerBG->layerHeight;
}

uint16_t LCDC__u16Layer_SetHeight(LCDC_TFT_TypeDef* restrict psLayer,  uint16_t u16Height)
{

    psLayer->layerHeight=u16Height;

    if((u16Height+ psLayer->layerXInit)>psLayer->layerHeightTotal)
        psLayer->layerHeight= psLayer->layerHeightTotal- psLayer->layerXInit;

    u16Height=psLayer->layerHeight;
    if(psLayer->layerBG!=0)
    {
        if((u16Height+ psLayer->layerBGXInit)>psLayer->layerBG->layerHeightTotal)
            psLayer->layerHeight= psLayer->layerBG->layerHeightTotal- psLayer->layerBGXInit;
    }

    return psLayer->layerHeight;
}

uint16_t LCDC__u16LayerBG_SetHeight(uint16_t u16Height)
{
    if((u16Height+ LCDC_psLayerBG->layerXInit)>LCDC_psLayerBG->layerHeightTotal)
        LCDC_psLayerBG->layerHeight= LCDC_psLayerBG->layerHeightTotal- LCDC_psLayerBG->layerXInit;

    u16Height=LCDC_psLayerBG->layerHeight;
    if(LCDC_psLayerBG->layerBG!=0)
    {
        if((u16Height+ LCDC_psLayerBG->layerBGXInit)>LCDC_psLayerBG->layerBG->layerHeightTotal)
            LCDC_psLayerBG->layerHeight= LCDC_psLayerBG->layerBG->layerHeightTotal- LCDC_psLayerBG->layerBGXInit;
    }

    LCDC_RASTER_TIMING_1->LPP=LCDC_psLayerBG->layerHeightTotal-1 ;
    return LCDC_psLayerBG->layerHeight;
}


uint16_t LCDC__u16Layer_GetBGX(LCDC_TFT_TypeDef* restrict psLayer, uint16_t* restrict u16BGX)
{
    uint16_t u16BGXCount =psLayer->layerBGXCount;
    int32_t s32Index=0;
    while(s32Index<(int32_t)u16BGXCount)
    {
        if(u16BGXCount==1)
        {
            u16BGX[(uint16_t)s32Index]=psLayer->layerBGXInit;
        }
        else
        {
            u16BGX[(uint16_t)s32Index]=psLayer->layerBGX[s32Index];

        }
        s32Index++;
    }
    return u16BGXCount;
}

uint16_t LCDC__u16LayerBG_GetBGX(uint16_t* u16BGX)
{
    return LCDC__u16Layer_GetBGX(LCDC_psLayerBG,u16BGX);
}

uint16_t LCDC__u16Layer_GetBGY(LCDC_TFT_TypeDef* restrict psLayer, uint16_t* restrict u16BGY)
{
    uint16_t u16BGYCount =psLayer->layerBGYCount;
    int32_t s32Index=0;
    while(s32Index<(int32_t)u16BGYCount)
    {
        if(u16BGYCount==1)
        {
            u16BGY[(uint16_t)s32Index]=psLayer->layerBGYInit;
        }
        else
        {
            u16BGY[(uint16_t)s32Index]=psLayer->layerBGY[s32Index];

        }
        s32Index++;
    }
    return u16BGYCount;
}

uint16_t LCDC__u16LayerBG_GetBGY(uint16_t* u16BGY)
{

    return LCDC__u16Layer_GetBGY(LCDC_psLayerBG,u16BGY);
}



uint16_t LCDC__u16Layer_GetRadius(LCDC_TFT_TypeDef* restrict psLayer, uint16_t* restrict u16Radius)
{
    uint16_t u16RadiusCount =psLayer->layerRadiusCount;
    int32_t s32Index=0;
    while(s32Index<(int32_t)u16RadiusCount)
    {
        if(u16RadiusCount==1)
        {
            u16Radius[(uint16_t)s32Index]=psLayer->layerRadiusInit;
        }
        else
        {
            u16Radius[(uint16_t)s32Index]=psLayer->layerRadius[s32Index];

        }
        s32Index++;
    }
    return u16RadiusCount;
}

uint16_t LCDC__u16LayerBG_GetRadius(uint16_t* u16Radius)
{

    return LCDC__u16Layer_GetRadius(LCDC_psLayerBG,u16Radius);
}


uint16_t LCDC__u16Layer_GetX(LCDC_TFT_TypeDef* restrict psLayer, uint16_t* restrict u16X)
{
    uint16_t u16XCount =psLayer->layerXCount;
    int32_t s32Index=0;
    while(s32Index<(int32_t)u16XCount)
    {
        if(u16XCount==1)
        {
            u16X[(uint16_t)s32Index]=psLayer->layerXInit;
        }
        else
        {
            u16X[(uint16_t)s32Index]=psLayer->layerX[s32Index];

        }
        s32Index++;
    }
    return u16XCount;
}

uint16_t LCDC__u16LayerBG_GetX(uint16_t* u16X)
{

    return LCDC__u16Layer_GetX(LCDC_psLayerBG,u16X);
}


uint16_t LCDC__u16Layer_GetY(LCDC_TFT_TypeDef* restrict psLayer, uint16_t* restrict u16Y)
{
    uint16_t u16YCount =psLayer->layerYCount;
    int32_t s32Index=0;
    while(s32Index<(int32_t)u16YCount)
    {
        if(u16YCount==1)
        {
            u16Y[(uint16_t)s32Index]=psLayer->layerYInit;
        }
        else
        {
            u16Y[(uint16_t)s32Index]=psLayer->layerY[s32Index];

        }
        s32Index++;
    }
    return u16YCount;
}

uint16_t LCDC__u16LayerBG_GetY(uint16_t* u16Y)
{

    return LCDC__u16Layer_GetY(LCDC_psLayerBG,u16Y);
}

uint16_t LCDC__u16Layer_SetBGX(LCDC_TFT_TypeDef* restrict psLayer, uint16_t* restrict u16BGX)
{
    uint16_t u16BGXCount =psLayer->layerBGXCount;
    int32_t s32Index=0;
    while(s32Index<(int32_t)u16BGXCount)
    {
        if(u16BGXCount==1)
        {
            psLayer->layerBGXInit=u16BGX[(uint16_t)s32Index];
        }
        else
        {
            psLayer->layerBGX[s32Index]=u16BGX[(uint16_t)s32Index];

        }
        s32Index++;
    }
    return u16BGXCount;
}

uint16_t LCDC__u16LayerBG_SetBGX(uint16_t* u16BGX)
{

    return LCDC__u16Layer_SetBGX(LCDC_psLayerBG,u16BGX);
}



uint16_t LCDC__u16Layer_SetBGY(LCDC_TFT_TypeDef* restrict psLayer, uint16_t* restrict u16BGY)
{
    uint16_t u16BGYCount =psLayer->layerBGYCount;
    int32_t s32Index=0;
    while(s32Index<(int32_t)u16BGYCount)
    {
        if(u16BGYCount==1)
        {
            psLayer->layerBGYInit=u16BGY[(uint16_t)s32Index];
        }
        else
        {
            psLayer->layerBGY[s32Index]=u16BGY[(uint16_t)s32Index];

        }
        s32Index++;
    }
    return u16BGYCount;
}

uint16_t LCDC__u16LayerBG_SetBGY(uint16_t* u16BGY)
{

    return LCDC__u16Layer_SetBGY(LCDC_psLayerBG,u16BGY);
}

uint16_t LCDC__u16Layer_SetRadius(LCDC_TFT_TypeDef* restrict psLayer, uint16_t* restrict u16Radius)
{
    uint16_t u16RadiusCount =psLayer->layerRadiusCount;
    int32_t s32Index=0;
    while(s32Index<(int32_t)u16RadiusCount)
    {
        if(u16RadiusCount==1)
        {
            psLayer->layerRadiusInit=u16Radius[(uint16_t)s32Index];
        }
        else
        {
            psLayer->layerRadius[s32Index]=u16Radius[(uint16_t)s32Index];

        }
        s32Index++;
    }
    return u16RadiusCount;
}

uint16_t LCDC__u16LayerBG_SetRadius(uint16_t* u16Radius)
{
    return LCDC__u16Layer_SetRadius(LCDC_psLayerBG,u16Radius);
}

uint16_t LCDC__u16Layer_SetX(LCDC_TFT_TypeDef* restrict psLayer, uint16_t* restrict u16X)
{
    uint16_t u16XCount =psLayer->layerXCount;
    int32_t s32Index=0;
    while(s32Index<(int32_t)u16XCount)
    {
        if(u16XCount==1)
        {
            psLayer->layerXInit=u16X[(uint16_t)s32Index];
        }
        else
        {
            psLayer->layerX[s32Index]=u16X[(uint16_t)s32Index];

        }
        s32Index++;
    }
    return u16XCount;
}

uint16_t LCDC__u16LayerBG_SetX(uint16_t* u16X)
{

    return LCDC__u16Layer_SetX(LCDC_psLayerBG,u16X);
}


uint16_t LCDC__u16Layer_SetY(LCDC_TFT_TypeDef* restrict psLayer, uint16_t* restrict u16Y)
{
    uint16_t u16YCount =psLayer->layerYCount;
    int32_t s32Index=0;
    while(s32Index<(int32_t)u16YCount)
    {
        if(u16YCount==1)
        {
            psLayer->layerYInit=u16Y[(uint16_t)s32Index];
        }
        else
        {
            psLayer->layerY[s32Index]=u16Y[(uint16_t)s32Index];

        }
        s32Index++;
    }
    return u16YCount;
}

uint16_t LCDC__u16LayerBG_SetY(uint16_t* u16Y)
{

    return LCDC__u16Layer_SetY(LCDC_psLayerBG,u16Y);
}

LAYER_nType LCDC__enLayer_GetType(LCDC_TFT_TypeDef* restrict psLayer)
{
    return (LAYER_nType)psLayer->layerType;
}
LAYER_nType LCDC__enLayerBG_GetType(void)
{
    return (LAYER_nType)LCDC_psLayerBG->layerType;
}


LAYER_nType LCDC__enLayer_SetType(LCDC_TFT_TypeDef* restrict psLayer,LAYER_nType enType)
{
    psLayer->layerType=enType;
    return(LAYER_nType) psLayer->layerType;
}
LAYER_nType LCDC__enLayerBG_SetType(LAYER_nType enType)
{
    LCDC_psLayerBG->layerType=enType;
    return (LAYER_nType)LCDC_psLayerBG->layerType;
}

/***************Appearance Functions***********/



LCDC_TFT_TypeDef* LCDC__sLayer_GetSubLayer  (LCDC_TFT_TypeDef* restrict psLayer,uint8_t u8Number)
{
    if(psLayer->subLayersCreated<u8Number)
        return 0;
    return psLayer->subLayers[u8Number];
}

LCDC_TFT_TypeDef* LCDC__sLayerBG_GetSubLayer    (uint8_t u8Number)
{
    return LCDC__sLayer_GetSubLayer(LCDC_psLayerBG,u8Number);
}
uint8_t LCDC__u8Layer_AddSubLayer(LCDC_TFT_TypeDef* restrict psLayer,LCDC_TFT_TypeDef* restrict psSubLayer)
{

    /*Checa si puede crear SubLayer en la psSubLayer BG*/
    if(psLayer->subLayersCreated>psLayer->subLayersMaximum)
        return 0xFF;

    /*si ya tiene asignado una psLayer no puede asigarlo a otro*/
    if(psSubLayer->layerBG!=0)
        return 0xFF;
    /*asigna en la posicion correspondiente la nueva sublayer*/
    psLayer->subLayers[psLayer->subLayersCreated]=psSubLayer;
    /* a la sublayer se le indica cual es su psLayer*/
    psSubLayer->layerBG=psLayer;
    /* le indica el numero de sublayer*/
    psSubLayer->subLayerNum=psLayer->subLayersCreated;
    /*aumenta el numero de sublayer creadas*/
    psLayer->subLayersCreated++;

    return psLayer->subLayersCreated;
}
uint8_t LCDC__u8LayerBG_AddSubLayer(LCDC_TFT_TypeDef* restrict psSubLayer)
{
    return LCDC__u8Layer_AddSubLayer(LCDC_psLayerBG,psSubLayer);
}

Lcdc_nStatus LCDC__enLayer_DeleteSubLayer(LCDC_TFT_TypeDef* restrict psLayer,uint8_t u8Number)
{
    uint8_t u8Cycle= u8Number;
    if(psLayer->subLayersCreated<u8Cycle)
        return LCDC_enERROR;

    psLayer->subLayers[u8Cycle-1]->layerBG=0;
    psLayer->subLayers[u8Cycle-1]->subLayerNum=0;
    for(u8Cycle= u8Number-1; u8Cycle<psLayer->subLayersCreated-1; u8Cycle++)
    {
        psLayer->subLayers[u8Cycle-1]=psLayer->subLayers[u8Cycle];
        psLayer->subLayers[u8Cycle-1]->subLayerNum--;
    }

    psLayer->subLayersCreated--;
    return LCDC_enOK;

}
Lcdc_nStatus LCDC__enLayerBG_DeleteSubLayer(uint8_t u8Number)
{
    return LCDC__enLayer_DeleteSubLayer(LCDC_psLayerBG,u8Number);
}



Lcdc_nStatus LCDC__enLayer_RefreshSubLayer(LCDC_TFT_TypeDef* restrict psLayer,uint8_t u8Number)
{
    LCDC_TFT_TypeDef* restrict psSubLayer;
    if (u8Number==0)
        return LCDC_enERROR;
    if(psLayer->subLayersCreated<(u8Number-1))
        return LCDC_enERROR;
    psSubLayer=psLayer->subLayers[u8Number-1];
    switch(psSubLayer->layerType)
    {
    case LAYER_TYPE_enIMAGE_NOHEADER:
        LCDC__enLayer_ImageNoHeaderType(psSubLayer,psLayer);
        break;
    case LAYER_TYPE_enLINECOMPLETE_HORIZONTAL:
        LCDC__vLayer_LineCompleteHorizontalType(psSubLayer,psLayer);
        break;
    case LAYER_TYPE_enLINECOMPLETE_VERTICAL:
        LCDC__vLayer_LineCompleteVerticalType(psSubLayer,psLayer);
        break;

    case LAYER_TYPE_enRECTANGLE_FILL:
        LCDC__vLayer_RectangleFillType(psSubLayer,psLayer);
        break;
    case LAYER_TYPE_enLINE_HORIZONTAL:
        LCDC__vLayer_LineHorizontalType(psSubLayer,psLayer);
        break;
    case LAYER_TYPE_enLINE_VERTICAL:
        LCDC__vLayer_LineVerticalType(psSubLayer,psLayer);
        break;
   case LAYER_TYPE_enRECTANGLE:
        LCDC__vLayer_RectangleType(psSubLayer,psLayer);
        break;
   case LAYER_TYPE_enRECTANGLE_SEMI:
       LCDC__vLayer_RectangleSemiType(psSubLayer,psLayer);
        break;
    case LAYER_TYPE_enPIXEL:
        LCDC__vLayer_PixelType(psSubLayer,psLayer);
        break;
    case LAYER_TYPE_enLINEXY:
        LCDC__enLayer_LineXYType(psSubLayer,psLayer);
        break;
    case LAYER_TYPE_enCIRCLE:
        LCDC__enLayer_CircleType(psSubLayer,psLayer);
        break;
    case LAYER_TYPE_enCIRCLE_FILL:
        LCDC__enLayer_CircleFillType(psSubLayer,psLayer);
        break;
    case LAYER_TYPE_enCROSS:
        LCDC__enLayer_CrossType(psSubLayer,psLayer);
        break;
   case LAYER_TYPE_enELLIPSE:
       LCDC__enLayer_EllipseType(psSubLayer,psLayer);
        break;
   case LAYER_TYPE_enELLIPSE_FILL:
         LCDC__enLayer_EllipseFillType(psSubLayer,psLayer);
        break;
       case LAYER_TYPE_enTRIANGLE:
           LCDC__enLayer_TriangleType(psSubLayer,psLayer);
        break;
         case LAYER_TYPE_enTRIANGLE_FILL:
             LCDC__enLayer_TriangleFillType(psSubLayer,psLayer);
        break;
        /*  case LAYER_TYPE_enMULTILINE:
        //Layer_MultilineType(psSubLayer,psLayer);
        break;
    case LAYER_TYPE_enMULTILINECLOSE:
        //Layer_MultilineCloseType(psSubLayer,psLayer);
        break;
   */ case LAYER_TYPE_enFONTLINECOMPLETE:
       LCDC__vLayer_FontLineCompleteType(psSubLayer,psLayer);
        break;
   case LAYER_TYPE_enFONTLINE:
       LCDC__vLayer_FontLineType(psSubLayer,psLayer);
        break;
    case LAYER_TYPE_enSTRING_SIMPLE:
        LCDC__u32Layer_StringSimpleType(psSubLayer,psLayer);
        break;
   case LAYER_TYPE_enSTRING_SIMPLE_BACKGROUND:
       LCDC__u32Layer_StringSimpleBGType(psSubLayer,psLayer);
        break;

    default:
        break;
    }
    return LCDC_enOK;
}


Lcdc_nStatus LCDC__enLayerBG_RefreshSubLayer(uint8_t u8Number)
{
    return LCDC__enLayer_RefreshSubLayer(LCDC_psLayerBG,u8Number);
}

Lcdc_nStatus LCDC__enLayer_RefreshAllSubLayer(LCDC_TFT_TypeDef* restrict psLayer)
{
    int32_t s32I;
    if(psLayer->subLayersCreated)
    {
    for (s32I=1; s32I<=psLayer->subLayersCreated;s32I++)
        LCDC__enLayer_RefreshSubLayer(psLayer,s32I);

    return LCDC_enOK;
    }
    else
        return LCDC_enERROR;
}

Lcdc_nStatus LCDC__enLayerBG_RefreshAllSubLayer(void)
{
    return LCDC__enLayer_RefreshAllSubLayer(LCDC_psLayerBG);
}


Lcdc_nStatus LCDC__enLayer_RefreshSubLayersArray(LCDC_TFT_TypeDef* restrict psLayer,uint8_t u8SubLayerInit, uint8_t u8Cant)
{
    int16_t s16Differ=(int16_t)psLayer->subLayersCreated-(int16_t)-u8SubLayerInit;
    int16_t s16I;
    if(s16Differ<(int16_t)u8Cant)
        return LCDC_enERROR;

    if(u8SubLayerInit==0)
        return LCDC_enERROR;

    if(psLayer->subLayersCreated)
    {
        if(psLayer->subLayersCreated>=u8SubLayerInit)
        {
            for (s16I=u8SubLayerInit; s16I<=(u8SubLayerInit+u8Cant);s16I++)
                LCDC__enLayer_RefreshSubLayer(psLayer,s16I);

            return LCDC_enOK;
        }
    }
    return LCDC_enERROR;
}

Lcdc_nStatus LCDC__enLayerBG_RefreshSubLayersArray(uint8_t u8SubLayerInit, uint8_t u8Cant)
{
    return LCDC__enLayer_RefreshSubLayersArray(LCDC_psLayerBG,u8SubLayerInit,u8Cant);
}

#define LCDC_TIMEOUTQDMA (120000000)

#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_ClearSection)
__inline void  LCDC__vLayer_ClearSection  (LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t  u16Color)
{
    uint32_t u32TimeOut=LCDC_TIMEOUTQDMA;
    uint32_t u32DataAddress=psLayer->layerDataAddress;
    uint32_t u32WidthTotal=psLayer->layerWidthTotal;

   // GPIO8_SET_DATA_R=GPIO_R_P12_MASK;
    if((sDim.height+ sDim.YInit)>psLayer->layerHeightTotal)
        return;
    if((sDim.width+ sDim.XInit)>psLayer->layerWidthTotal)
        return;

    Cache__vWbInvL2((uint32_t)&u16Color,4);


    u32DataAddress+=((sDim.YInit*u32WidthTotal + sDim.XInit)*2);
/*
    EDMA3_0_CC0_PaRAM->PaRAM[126].OPT=0;
    EDMA3_0_CC0_PaRAM->PaRAM[126].OPT_Bit.TCC=31;
    EDMA3_0_CC0_PaRAM->PaRAM[126].OPT_Bit.STATIC=1;
    EDMA3_0_CC0_PaRAM->PaRAM[126].OPT_Bit.TCINTEN =1;
    EDMA3_0_CC0_PaRAM->PaRAM[126].OPT_Bit.SYNCDIM =1;


    EDMA3_0_CC0_PaRAM->PaRAM[126].LINK_BCNTRLD_Bit.LINK=0xFFFF;
    EDMA3_0_CC0_PaRAM->PaRAM[126].SRC=(uint32_t)u32DataAddress;
    EDMA3_0_CC0_PaRAM->PaRAM[126].DST=(uint32_t)u32DataAddress+(u32WidthTotal*2);
    EDMA3_0_CC0_PaRAM->PaRAM[126].A_B_CNT_Bit.ACNT=sDim.width*2;//
    EDMA3_0_CC0_PaRAM->PaRAM[126].A_B_CNT_Bit.BCNT=sDim.height-1;
    EDMA3_0_CC0_PaRAM->PaRAM[126].SRC_DST_CIDX=0;
    EDMA3_0_CC0_PaRAM->PaRAM[126].SRC_DST_BIDX_Bit.DSTBIDX=(u32WidthTotal*2);
    EDMA3_0_CC0_PaRAM->PaRAM[126].SRC_DST_BIDX_Bit.SRCBIDX=0;//-psLayer->layerWidthTotal;
    EDMA3_0_CC0_PaRAM->PaRAM[126].LINK_BCNTRLD_Bit.BCNTRLD=0;
    EDMA3_0_CC0_PaRAM->PaRAM[126].CCNT=1;
*/


    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT=0;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.TCC=31;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.STATIC=1;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.TCINTEN =1;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.TCCHEN =1;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.SYNCDIM =1;

    EDMA3_0_CC0_PaRAM->PaRAM[127].LINK_BCNTRLD_Bit.LINK=((uint32_t)(EDMA3_0_CC0_PaRAM->PaRAM)+126*8*4)&0xFFFF;
    EDMA3_0_CC0_PaRAM->PaRAM[127].SRC=(uint32_t)&u16Color;
    EDMA3_0_CC0_PaRAM->PaRAM[127].DST=(uint32_t)u32DataAddress;
    EDMA3_0_CC0_PaRAM->PaRAM[127].A_B_CNT_Bit.ACNT=2;//
    EDMA3_0_CC0_PaRAM->PaRAM[127].A_B_CNT_Bit.BCNT=sDim.width;
    EDMA3_0_CC0_PaRAM->PaRAM[127].SRC_DST_CIDX=0;
    EDMA3_0_CC0_PaRAM->PaRAM[127].SRC_DST_BIDX_Bit.DSTBIDX=2;
    EDMA3_0_CC0_PaRAM->PaRAM[127].SRC_DST_BIDX_Bit.SRCBIDX=0;//-psLayer->layerWidthTotal;
    EDMA3_0_CC0_PaRAM->PaRAM[127].LINK_BCNTRLD_Bit.BCNTRLD=0;
    EDMA3_0_CC0_INTERRUPT->ICR|=0x80000000;
    EDMA3_0_CC0_PaRAM->PaRAM[127].CCNT=1;
    while (((EDMA3_0_CC0_INTERRUPT->IPR&0x80000000)==0)&& (u32TimeOut!=0))
    {
        u32TimeOut--;
    }
    if(u32TimeOut==0)
        return;

    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT=0;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.TCC=31;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.STATIC=1;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.TCINTEN =1;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.SYNCDIM =1;


    EDMA3_0_CC0_PaRAM->PaRAM[127].LINK_BCNTRLD_Bit.LINK=0xFFFF;
    EDMA3_0_CC0_PaRAM->PaRAM[127].SRC=(uint32_t)u32DataAddress;
    EDMA3_0_CC0_PaRAM->PaRAM[127].DST=(uint32_t)u32DataAddress+(u32WidthTotal*2);
    EDMA3_0_CC0_PaRAM->PaRAM[127].A_B_CNT_Bit.ACNT=sDim.width*2;//
    EDMA3_0_CC0_PaRAM->PaRAM[127].A_B_CNT_Bit.BCNT=sDim.height-1;
    EDMA3_0_CC0_PaRAM->PaRAM[127].SRC_DST_CIDX=0;
    EDMA3_0_CC0_PaRAM->PaRAM[127].SRC_DST_BIDX_Bit.DSTBIDX=(u32WidthTotal*2);
    EDMA3_0_CC0_PaRAM->PaRAM[127].SRC_DST_BIDX_Bit.SRCBIDX=0;//-psLayer->layerWidthTotal;
    EDMA3_0_CC0_PaRAM->PaRAM[127].LINK_BCNTRLD_Bit.BCNTRLD=0;
    EDMA3_0_CC0_PaRAM->PaRAM[127].CCNT=1;
    while (((EDMA3_0_CC0_INTERRUPT->IPR&0x80000000)==0)&& (u32TimeOut!=0))
    {
        u32TimeOut--;
    }
    if(u32TimeOut==0)
        return;
    EDMA3_0_CC0_INTERRUPT->ICR|=0x80000000;

    //Cache__vInvL2((uint32_t)u32DataAddress,u32WidthTotal*psLayer->layerHeightTotal*2);

    return;

}

#pragma FUNC_ALWAYS_INLINE( LCDC__vLayerBG_ClearSection)
__inline void LCDC__vLayerBG_ClearSection    (LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{
    LCDC__vLayer_ClearSection  (LCDC_psLayerBG,sDim,u16Color);
}
#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_Clear)
__inline void LCDC__vLayer_Clear(LCDC_TFT_TypeDef* restrict psLayer, uint16_t u16Color)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    sDim.XInit= 0;
    sDim.YInit=0;
    sDim.width= psLayer->layerWidthTotal;
    sDim.height=psLayer->layerHeightTotal;
    sDim.widthTotal=  psLayer->layerWidthTotal;
    sDim.heightTotal=psLayer->layerHeightTotal;
    LCDC__vLayer_ClearSection  (psLayer,sDim,u16Color);
}

#pragma FUNC_ALWAYS_INLINE( LCDC__vLayerBG_Clear)
__inline void LCDC__vLayerBG_Clear(uint16_t u16Color)
{
    LCDC__vLayer_Clear(LCDC_psLayerBG,u16Color);
}


Lcdc_nStatus LCDC__enLayer_Copy (LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest,LCDC_DIMENSIONS_TypeDef sDim)
{
    uint32_t u32TimeOut=LCDC_TIMEOUTQDMA;
    uint32_t u32SourceAddress, u32DestAddress;
    uint8_t u8MultSource=1, u8MultDest=1;
    uint32_t u32SourceWidthTotal, u32DestWidthTotal;
    uint32_t u32SourceHeightTotal, u32DestHeightTotal;
    u32SourceWidthTotal=psLayerSource->layerWidthTotal;
    u32DestWidthTotal=psLayerDest->layerWidthTotal;
    u32SourceHeightTotal=psLayerSource->layerHeightTotal;
    u32DestHeightTotal=psLayerDest->layerHeightTotal;



    if(sDim.X[0]>u32SourceWidthTotal)
        return LCDC_enERROR;
    if(sDim.X[1]>u32DestWidthTotal)
        return LCDC_enERROR;
    if(sDim.Y[0]>u32SourceHeightTotal)
        return LCDC_enERROR;
    if(sDim.Y[1]>u32DestHeightTotal)
        return LCDC_enERROR;

    if((sDim.width+ sDim.X[0])>u32SourceWidthTotal)
        sDim.width=u32SourceWidthTotal- sDim.X[0];
    if((sDim.height+ sDim.Y[0])>u32SourceHeightTotal)
        sDim.height= u32SourceHeightTotal- sDim.Y[0];

    if((sDim.width+ sDim.X[1])>u32DestWidthTotal)
        sDim.width= u32DestWidthTotal- sDim.X[1];
    if((sDim.height+ sDim.Y[1])>u32DestHeightTotal)
        sDim.height= u32DestHeightTotal- sDim.Y[1];

    if(psLayerSource->variableType == VARIABLETYPE_enUSHORT )
    {
        u8MultSource=2;
    }
    if(psLayerDest->variableType == VARIABLETYPE_enUSHORT)
    {
        u8MultDest=2;
    }
    u32SourceAddress=psLayerSource->layerDataAddress+((u32SourceWidthTotal*sDim.Y[0]+sDim.X[0])*u8MultSource);
    u32DestAddress=psLayerDest->layerDataAddress+((u32DestWidthTotal*sDim.Y[1]+sDim.X[1])*u8MultDest);

    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT=0;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.TCC=31;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.STATIC=1;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.TCINTEN =1;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.TCCHEN =0;
    EDMA3_0_CC0_PaRAM->PaRAM[127].OPT_Bit.SYNCDIM =1;

    EDMA3_0_CC0_PaRAM->PaRAM[127].LINK_BCNTRLD_Bit.LINK=((uint32_t)(EDMA3_0_CC0_PaRAM->PaRAM)+126*8*4)&0xFFFF;
    EDMA3_0_CC0_PaRAM->PaRAM[127].SRC=(uint32_t)u32SourceAddress;
    EDMA3_0_CC0_PaRAM->PaRAM[127].DST=(uint32_t)u32DestAddress;
    EDMA3_0_CC0_PaRAM->PaRAM[127].A_B_CNT_Bit.ACNT=sDim.width*u8MultSource;//
    EDMA3_0_CC0_PaRAM->PaRAM[127].A_B_CNT_Bit.BCNT=sDim.height;
    EDMA3_0_CC0_PaRAM->PaRAM[127].SRC_DST_CIDX=0;
    EDMA3_0_CC0_PaRAM->PaRAM[127].SRC_DST_BIDX_Bit.DSTBIDX=u32DestWidthTotal*u8MultDest;
    EDMA3_0_CC0_PaRAM->PaRAM[127].SRC_DST_BIDX_Bit.SRCBIDX=u32SourceWidthTotal*u8MultSource;//-psLayer->layerWidthTotal;
    EDMA3_0_CC0_PaRAM->PaRAM[127].LINK_BCNTRLD_Bit.BCNTRLD=0;
    EDMA3_0_CC0_INTERRUPT->ICR|=0x80000000;
    EDMA3_0_CC0_PaRAM->PaRAM[127].CCNT=1;
    while (((EDMA3_0_CC0_INTERRUPT->IPR&0x80000000)==0)&&(u32TimeOut!=0))
    {
        u32TimeOut--;
    }
    if(u32TimeOut==0)
        return LCDC_enERROR;
    EDMA3_0_CC0_INTERRUPT->ICR|=0x80000000;

    //GPIO8_CLR_DATA_R=GPIO_R_P12_MASK;
    return LCDC_enOK;
}


Lcdc_nStatus LCDC__enLayer_ImageNoHeaderType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;

    sDim.width=psLayerSource->layerWidth;
    sDim.height=psLayerSource->layerHeight;
    sDim.X[0]=psLayerSource->layerXInit;
    sDim.Y[0]=psLayerSource->layerYInit;
    sDim.X[1]=psLayerSource->layerBGXInit;
    sDim.Y[1]=psLayerSource->layerBGYInit;

    return LCDC__enLayer_Copy(psLayerSource,psLayerDest,sDim);
}


#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_Print_RectanguleFill)
__inline void LCDC__vLayer_Print_RectanguleFill (LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{
    LCDC__vLayer_ClearSection(psLayer,sDim,u16Color);
}



#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_RectangleFillType)
__inline void LCDC__vLayer_RectangleFillType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;

    sDim.width=psLayerSource->layerWidth;
    sDim.height=psLayerSource->layerHeight;
    sDim.XInit=psLayerSource->layerBGXInit;
    sDim.YInit=psLayerSource->layerBGYInit;

    LCDC__vLayer_Print_RectanguleFill(psLayerDest,sDim,psLayerSource->layerColorBG);
}





#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_Print_LineCompleteHorizontal)
__inline void LCDC__vLayer_Print_LineCompleteHorizontal (LCDC_TFT_TypeDef* restrict psLayer,uint16_t u16Line,uint16_t u16color)
{
    LCDC_DIMENSIONS_TypeDef sDim;

    sDim.width=psLayer->layerWidthTotal;
    sDim.height=1;
    sDim.XInit=0;
    sDim.YInit=u16Line;

    LCDC__vLayer_ClearSection(psLayer,sDim,u16color);

}

#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_LineCompleteHorizontalType)
__inline void LCDC__vLayer_LineCompleteHorizontalType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC__vLayer_Print_LineCompleteHorizontal(psLayerDest,psLayerSource->layerBGYInit,psLayerSource->layerColorBG);
}


#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_Print_LineCompleteVertical)
__inline void LCDC__vLayer_Print_LineCompleteVertical (LCDC_TFT_TypeDef* restrict psLayer,uint16_t u16Column,uint16_t u16color)
{
    LCDC_DIMENSIONS_TypeDef sDim;

    sDim.width=1;
    sDim.height=psLayer->layerHeightTotal;
    sDim.XInit=u16Column;
    sDim.YInit=0;

    LCDC__vLayer_ClearSection(psLayer,sDim,u16color);

}

#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_LineCompleteVerticalType)
__inline void LCDC__vLayer_LineCompleteVerticalType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC__vLayer_Print_LineCompleteVertical(psLayerDest,psLayerSource->layerBGXInit,psLayerSource->layerColorBG);
}


#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_Print_FontLineComplete)
__inline void LCDC__vLayer_Print_FontLineComplete   (LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim, uint16_t u16Color)
{

    sDim.width=psLayer->layerWidthTotal;
    sDim.XInit=0;
    LCDC__vLayer_ClearSection(psLayer,sDim,u16Color);
}

#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_FontLineCompleteType)
__inline void LCDC__vLayer_FontLineCompleteType (LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;

    if(((psLayerSource->layerFont->height*psLayerSource->layerHeight)+(psLayerSource->layerFont->height*psLayerSource->layerBGYInit+1))>psLayerDest->layerHeightTotal)
        return;
    sDim.height=psLayerSource->layerFont->height*psLayerSource->layerHeight;
    sDim.YInit = psLayerSource->layerFont->height*psLayerSource->layerBGYInit;

    LCDC__vLayer_Print_FontLineComplete(psLayerDest,sDim,psLayerSource->layerColorBG);
}


#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_Print_FontLine)
__inline void LCDC__vLayer_Print_FontLine   (LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim, uint16_t u16Color)
{
    LCDC__vLayer_ClearSection(psLayer,sDim,u16Color);
}

#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_FontLineType)
__inline void LCDC__vLayer_FontLineType (LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;

    if(((psLayerSource->layerFont->height*psLayerSource->layerHeight)+(psLayerSource->layerFont->height*psLayerSource->layerBGYInit+1))>psLayerDest->layerHeightTotal)
        return;
    if(((psLayerSource->layerFont->width*psLayerSource->layerBGXInit)+(psLayerSource->layerFont->width*psLayerSource->layerWidth))>psLayerDest->layerWidthTotal)
        return;
    sDim.height=psLayerSource->layerFont->height*psLayerSource->layerHeight;
    sDim.width=psLayerSource->layerFont->width*psLayerSource->layerWidth;
    sDim.YInit= psLayerSource->layerFont->height*psLayerSource->layerBGYInit;
    sDim.XInit = psLayerSource->layerFont->width*psLayerSource->layerBGXInit;

    LCDC__vLayer_Print_FontLine(psLayerDest,sDim,psLayerSource->layerColorBG);
}


#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_Print_LineVertical)
__inline void LCDC__vLayer_Print_LineVertical (LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{
    sDim.width=1;
    LCDC__vLayer_ClearSection(psLayer,sDim,u16Color);
}


#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_LineVerticalType)
__inline void LCDC__vLayer_LineVerticalType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;

    sDim.height=psLayerSource->layerHeight;
    sDim.XInit=psLayerSource->layerBGXInit;
    sDim.YInit=psLayerSource->layerBGYInit;

    LCDC__vLayer_Print_LineVertical(psLayerDest,sDim,psLayerSource->layerColorBG);
}

#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_Print_LineHorizontal)
__inline void LCDC__vLayer_Print_LineHorizontal (LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{
    sDim.height=1;
    LCDC__vLayer_ClearSection(psLayer,sDim,u16Color);
}


#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_LineHorizontalType)
__inline void LCDC__vLayer_LineHorizontalType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;

    sDim.width=psLayerSource->layerWidth;
    sDim.XInit=psLayerSource->layerBGXInit;
    sDim.YInit=psLayerSource->layerBGYInit;

    LCDC__vLayer_Print_LineHorizontal(psLayerDest,sDim,psLayerSource->layerColorBG);
}



#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_Print_Rectangle)
__inline void LCDC__vLayer_Print_Rectangle (LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{

    uint16_t u16Temp1=0;

    u16Temp1=sDim.YInit;
    LCDC__vLayer_Print_LineHorizontal(psLayer,sDim,u16Color);
    sDim.YInit+=sDim.height;
    LCDC__vLayer_Print_LineHorizontal(psLayer,sDim,u16Color);
    sDim.YInit=u16Temp1;

    u16Temp1=sDim.XInit;
    LCDC__vLayer_Print_LineVertical(psLayer,sDim,u16Color);
    sDim.XInit+=sDim.width;
    LCDC__vLayer_Print_LineVertical(psLayer,sDim,u16Color);
    sDim.XInit=u16Temp1;
}

#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_RectangleType)
__inline void LCDC__vLayer_RectangleType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    sDim.width=psLayerSource->layerWidth;
    sDim.height=psLayerSource->layerHeight;
    sDim.XInit=psLayerSource->layerBGXInit;
    sDim.YInit=psLayerSource->layerBGYInit;
    LCDC__vLayer_Print_Rectangle(psLayerDest,sDim,psLayerSource->layerColorBG);
}

#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_Print_RectangleSemi)
__inline void LCDC__vLayer_Print_RectangleSemi (LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{
    uint16_t u16TempYInit=0,u16Temp=0,u16TempHeight=0;

    u16TempYInit=sDim.YInit;
    u16TempHeight=sDim.height;

    if(sDim.height<sDim.width)
    {
        u16Temp=sDim.height*sDim.radiusInit;
        u16Temp/=200;
    }
    else
    {
        u16Temp=sDim.width*sDim.radiusInit;
        u16Temp/=200;
    }

    sDim.height=u16Temp;
    LCDC__vLayer_Print_RectanguleFill(psLayer,sDim,u16Color);
    sDim.YInit+=u16TempHeight-u16Temp;
    LCDC__vLayer_Print_RectanguleFill(psLayer,sDim,u16Color);

    sDim.YInit=u16TempYInit;
    sDim.height=u16TempHeight;

    u16TempYInit=sDim.XInit;


    u16TempHeight=sDim.width;
    sDim.width=u16Temp;
    LCDC__vLayer_Print_RectanguleFill(psLayer,sDim,u16Color);
    sDim.XInit+=u16TempHeight-u16Temp;
    LCDC__vLayer_Print_RectanguleFill(psLayer,sDim,u16Color);
    sDim.XInit=u16TempYInit;
    sDim.width=u16TempHeight;
}
#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_RectangleSemiType)
__inline void LCDC__vLayer_RectangleSemiType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    sDim.width=psLayerSource->layerWidth;
    sDim.height=psLayerSource->layerHeight;
    sDim.XInit=psLayerSource->layerBGXInit;
    sDim.YInit=psLayerSource->layerBGYInit;
    sDim.radiusInit=psLayerSource->layerRadiusInit;
    LCDC__vLayer_Print_RectangleSemi(psLayerDest,sDim,psLayerSource->layerColorBG);
}



#pragma FUNC_ALWAYS_INLINE( LCDC__vLayer_PixelType)
__inline void LCDC__vLayer_PixelType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    sDim.XInit=psLayerSource->layerBGXInit;
    sDim.YInit=psLayerSource->layerBGYInit;
    LCDC__vLayer_Print_Pixel(psLayerDest,sDim,psLayerSource->layerColorBG);
}


Lcdc_nStatus LCDC__enLayer_Print_LineXY(LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{
  int32_t s32DeltaX = 0, s32DeltaY = 0, s32IncrementX1 = 0, s32IncrementX2 = 0,
  s32IncrementY1 = 0, s32IncrementY2 = 0, s32Denominator = 0, s32Numerator = 0, s32AddNum = 0, s32PixelsNumber = 0,
  s32CurrentPixel = 0;
  LCDC_DIMENSIONS_TypeDef sDimensions;

  if((sDim.X[0] > psLayer->layerWidthTotal) || (sDim.X[1] > psLayer->layerWidthTotal) ||
          (sDim.Y[0] > psLayer->layerHeightTotal) || (sDim.Y[1] > psLayer->layerHeightTotal))
          return LCDC_enERROR;

  s32DeltaX=(int32_t)((int32_t)sDim.X[1] -(int32_t)sDim.X[0]);
  if(s32DeltaX<0)
      s32DeltaX*=-1;
  s32DeltaY=(int32_t)((int32_t)sDim.Y[1] -(int32_t)sDim.Y[0]);
  if(s32DeltaY<0)
      s32DeltaY*=-1;

  sDimensions.XInit = sDim.X[0];
  sDimensions.YInit = sDim.Y[0];

  if (sDim.X[1] >= sDim.X[0])
  {
    s32IncrementX1 = 1;
    s32IncrementX2 = 1;
  }
  else
  {
    s32IncrementX1 = -1;
    s32IncrementX2 = -1;
  }

  if (sDim.Y[1] >= sDim.Y[0])
  {
    s32IncrementY1 = 1;
    s32IncrementY2 = 1;
  }
  else
  {
    s32IncrementY1 = -1;
    s32IncrementY2 = -1;
  }

  if (s32DeltaX >= s32DeltaY)
  {
    s32IncrementX1 = 0;
    s32IncrementY2 = 0;
    s32Denominator = s32DeltaX;
    s32Numerator = s32DeltaX >>1;
    s32AddNum = s32DeltaY;
    s32PixelsNumber = s32DeltaX;
  }
  else
  {
    s32IncrementX2 = 0;
    s32IncrementY1 = 0;
    s32Denominator = s32DeltaY;
    s32Numerator = s32DeltaY >>1;
    s32AddNum = s32DeltaX;
    s32PixelsNumber = s32DeltaY;
  }
  #pragma MUST_ITERATE(16,,16)
  for (s32CurrentPixel = 0; s32CurrentPixel <= s32PixelsNumber; s32CurrentPixel++)
  {

    LCDC__vLayer_Print_Pixel(psLayer,sDimensions,u16Color);
    s32Numerator += s32AddNum;
    if (s32Numerator >= s32Denominator)
    {
      s32Numerator -= s32Denominator;
      sDimensions.XInit += s32IncrementX1;
      sDimensions.YInit += s32IncrementY1;
    }
    sDimensions.XInit += s32IncrementX2;
    sDimensions.YInit += s32IncrementY2;
  }
  return LCDC_enOK;
}


Lcdc_nStatus LCDC__enLayer_LineXYType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    sDim.X[0]=psLayerSource->layerBGX[0];
    sDim.Y[0]=psLayerSource->layerBGY[0];
    sDim.X[1]=psLayerSource->layerBGX[1];
    sDim.Y[1]=psLayerSource->layerBGY[1];
    return LCDC__enLayer_Print_LineXY(psLayerDest,sDim,psLayerSource->layerColorBG);
}



Lcdc_nStatus LCDC__enLayer_Print_Circle (LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{
    LCDC_DIMENSIONS_TypeDef sDimensions;
    int16_t s16Radius=sDim.radiusInit;
    int16_t s16PosX=sDim.XInit;
    int16_t s16PosY=sDim.YInit;
    int16_t s16X = s16Radius;
    int16_t s16Y = 0;
    int16_t s16AddX = 1 - (s16Radius<<1);
    int16_t s16AddY = 1;
    int16_t s16RadiusError = 0;

    if(((s16PosX+s16Radius) >( psLayer->layerWidthTotal)) || ((s16PosY+s16Radius) >( psLayer->layerHeightTotal) ))
    {
        return LCDC_enERROR;
    }

    if(((int32_t)(s16PosX-s16Radius) <0) || ((int32_t)(s16PosY-s16Radius) <0 ))
    {
        return LCDC_enERROR;
    }

    while (s16X >= s16Y) {

        sDimensions.XInit = s16PosX-s16X;
        sDimensions.YInit = s16PosY+s16Y;
        LCDC__vLayer_Print_Pixel(psLayer,sDimensions,u16Color);
        sDimensions.YInit = (s16PosY-s16Y);
        LCDC__vLayer_Print_Pixel(psLayer,sDimensions,u16Color);

        sDimensions.XInit = (s16PosX+s16X);
        sDimensions.YInit = (s16PosY+s16Y);
        LCDC__vLayer_Print_Pixel(psLayer,sDimensions,u16Color);
        sDimensions.YInit = (s16PosY-s16Y);
        LCDC__vLayer_Print_Pixel(psLayer,sDimensions,u16Color);


        sDimensions.XInit = (s16PosX-s16Y);
        sDimensions.YInit = (s16PosY+s16X);
        LCDC__vLayer_Print_Pixel(psLayer,sDimensions,u16Color);
        sDimensions.YInit = (s16PosY-s16X);
        LCDC__vLayer_Print_Pixel(psLayer,sDimensions,u16Color);

        sDimensions.XInit = (s16PosX+s16Y);
        sDimensions.YInit = (s16PosY+s16X);
        LCDC__vLayer_Print_Pixel(psLayer,sDimensions,u16Color);
        sDimensions.YInit = (s16PosY-s16X);
        LCDC__vLayer_Print_Pixel(psLayer,sDimensions,u16Color);

        s16Y++;
        s16RadiusError += s16AddY;
        s16AddY += 2;
        if ((s16RadiusError<<1) + s16AddX > 0) {
            s16X--;
            s16RadiusError += s16AddX;
            s16AddX += 2;
        }
    }
    return LCDC_enOK;
}

Lcdc_nStatus LCDC__enLayer_CircleType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    sDim.XInit=psLayerSource->layerBGXInit;
    sDim.YInit=psLayerSource->layerBGYInit;
    sDim.radiusInit =psLayerSource->layerRadiusInit;
    return LCDC__enLayer_Print_Circle(psLayerDest,sDim,psLayerSource->layerColorBG);
}


Lcdc_nStatus LCDC__enLayer_Print_CircleFill (LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{
    LCDC_DIMENSIONS_TypeDef sDimensions;
    int16_t s16Radius=sDim.radiusInit;
    int16_t s16PosX=sDim.XInit;
    int16_t s16PosY=sDim.YInit;
    int16_t s16D;
    int16_t s16CurrentX;
    int16_t s16CurrentY;

    if(((s16PosX+s16Radius) >( psLayer->layerWidthTotal)) || ((s16PosY+s16Radius) >( psLayer->layerHeightTotal) ))
    {
        return LCDC_enERROR;
    }

    if(((int32_t)(s16PosX-s16Radius) <0) || ((int32_t)(s16PosY-s16Radius) <0 ))
    {
        return LCDC_enERROR;
    }

    s16D = 3 - (s16Radius << 1);

    s16CurrentY = 0;
    s16CurrentX = s16Radius;

    while (s16CurrentY <= s16CurrentX)
    {
        if(s16CurrentX > 0)
        {


            sDimensions.width=2*s16CurrentX;
            sDimensions.YInit=s16PosY - s16CurrentY;
            sDimensions.XInit=s16PosX - s16CurrentX;
            LCDC__vLayer_Print_LineHorizontal(psLayer,sDimensions,u16Color);
            sDimensions.YInit=s16PosY + s16CurrentY;
            LCDC__vLayer_Print_LineHorizontal(psLayer,sDimensions,u16Color);
        }

        if(s16CurrentY > 0)
        {
            sDimensions.width=2*s16CurrentY;
            sDimensions.YInit=s16PosY - s16CurrentX;
            sDimensions.XInit= s16PosX - s16CurrentY;
            LCDC__vLayer_Print_LineHorizontal(psLayer,sDimensions,u16Color);
            sDimensions.YInit=s16PosY + s16CurrentX;
            LCDC__vLayer_Print_LineHorizontal(psLayer,sDimensions,u16Color);
        }
        if (s16D < 0)
        {
         s16D += (s16CurrentY << 2) + 6;
        }
        else
        {
         s16D += ((s16CurrentY - s16CurrentX) << 2) + 10;
         s16CurrentX--;
        }
        s16CurrentY++;
    }
    return LCDC_enOK;
}


Lcdc_nStatus LCDC__enLayer_CircleFillType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    sDim.XInit=psLayerSource->layerBGXInit;
    sDim.YInit=psLayerSource->layerBGYInit;
    sDim.radiusInit =psLayerSource->layerRadiusInit;
    return LCDC__enLayer_Print_CircleFill(psLayerDest,sDim,psLayerSource->layerColorBG);
}




Lcdc_nStatus LCDC__enLayer_Print_Cross  (LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{

    LCDC_DIMENSIONS_TypeDef sDimensions;
    int16_t s16Radius=sDim.radiusInit;
    int16_t s16PosX=sDim.XInit;
    int16_t s16PosY=sDim.YInit;

    if(((s16PosX+s16Radius) >( psLayer->layerWidthTotal)) || ((s16PosY+s16Radius) >( psLayer->layerHeightTotal) ))
    {
        return LCDC_enERROR;
    }

    if(((int32_t)(s16PosX-s16Radius) <0) || ((int32_t)(s16PosY-s16Radius) <0 ))
    {
        return LCDC_enERROR;
    }

    sDimensions.height=sDim.height;
    sDimensions.XInit=s16PosX;
    sDimensions.YInit= s16PosY - s16Radius;
    LCDC__vLayer_Print_LineVertical(psLayer,sDimensions,u16Color);
    sDimensions.YInit= s16PosY + s16Radius-sDimensions.height;
    LCDC__vLayer_Print_LineVertical(psLayer,sDimensions,u16Color);

    sDimensions.width=sDim.width;
    sDimensions.YInit= s16PosY ;
    sDimensions.XInit=s16PosX- s16Radius;
    LCDC__vLayer_Print_LineHorizontal(psLayer,sDimensions,u16Color);
    sDimensions.XInit= s16PosX + s16Radius-sDimensions.width;
    LCDC__vLayer_Print_LineHorizontal(psLayer,sDimensions,u16Color);


    return LCDC_enOK;

}

Lcdc_nStatus LCDC__enLayer_CrossType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    sDim.height=psLayerSource->layerHeight;
    sDim.width=psLayerSource->layerWidth;
    sDim.XInit=psLayerSource->layerBGXInit;
    sDim.YInit=psLayerSource->layerBGYInit;
    sDim.radiusInit =psLayerSource->layerRadiusInit;
    return LCDC__enLayer_Print_Cross(psLayerDest,sDim,psLayerSource->layerColorBG);
}




Lcdc_nStatus LCDC__enLayer_Print_Ellipse            (LCDC_TFT_TypeDef* restrict layer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{
    LCDC_DIMENSIONS_TypeDef sDimensions;
    int16_t s16Radius=sDim.radius[0];
    int16_t s16Radius2=sDim.radius[1];
    int16_t s16PosX=sDim.XInit;
    int16_t s16PosY=sDim.YInit;
    int16_t s16X = -s16Radius, s16Y = 0, s16Error = 2-2*s16Radius, s16Error2;
    int32_t s32aux=0;
    float fK = 0, fRad1 = 0, fRad2 = 0;

    if(((s16PosX+s16Radius) >( layer->layerWidthTotal)) || ((s16PosY+s16Radius2) >( layer->layerHeightTotal) ))
    {
        return LCDC_enERROR;
    }

    if(((int32_t)(s16PosX-s16Radius) <0) || ((int32_t)(s16PosY-s16Radius2) <0 ))
    {
        return LCDC_enERROR;
    }

    if(s16Radius<=0 || s16Radius2<=0)
    {
          return LCDC_enERROR;
    }

      fRad1 = s16Radius;
      fRad2 = s16Radius2;

      if (s16Radius > s16Radius2)
      {
        do {
          fK = (float)(fRad2/fRad1);
          s32aux=(int32_t)((float)s16Y*fK);
            sDimensions.XInit = (s16PosX-s16X);
            sDimensions.YInit = (s16PosY+(int32_t)(s32aux));
            LCDC__vLayer_Print_Pixel(layer,sDimensions,u16Color);
            sDimensions.YInit = (s16PosY-(int32_t)(s32aux));
            LCDC__vLayer_Print_Pixel(layer,sDimensions,u16Color);
            sDimensions.XInit = (s16PosX+s16X);
            sDimensions.YInit = (s16PosY+(int32_t)(s32aux));
            LCDC__vLayer_Print_Pixel(layer,sDimensions,u16Color);
            sDimensions.YInit = (s16PosY-(int32_t)(s32aux));
            LCDC__vLayer_Print_Pixel(layer,sDimensions,u16Color);


          s16Error2 = s16Error;
          if (s16Error2 <= s16Y) {
            s16Error += ++s16Y*2+1;
            if (-s16X == s16Y && s16Error2 <= s16X) s16Error2 = 0;
          }
          if (s16Error2 > s16X) s16Error += ++s16X*2+1;
        }
        while (s16X <= 0);
      }
      else
      {
        s16Y = -s16Radius2;
        s16X = 0;
        do {
          fK = (float)(fRad1/fRad2);

          s32aux=(int32_t)((float)s16X*fK);

            sDimensions.YInit = (s16PosY+s16Y);
            sDimensions.XInit = (s16PosX-(int32_t)(s32aux));
            LCDC__vLayer_Print_Pixel(layer,sDimensions,u16Color);
            sDimensions.XInit = (s16PosX+(int32_t)(s32aux));
            LCDC__vLayer_Print_Pixel(layer,sDimensions,u16Color);

            sDimensions.YInit = (s16PosY-s16Y);
            sDimensions.XInit = (s16PosX+(int32_t)(s32aux));
            LCDC__vLayer_Print_Pixel(layer,sDimensions,u16Color);
            sDimensions.XInit = (s16PosX-(int32_t)(s32aux));
            LCDC__vLayer_Print_Pixel(layer,sDimensions,u16Color);

          s16Error2 = s16Error;
          if (s16Error2 <= s16X) {
            s16Error += ++s16X*2+1;
            if (-s16Y == s16X && s16Error2 <= s16Y) s16Error2 = 0;
          }
          if (s16Error2 > s16Y) s16Error += ++s16Y*2+1;
        }
        while (s16Y <= 0);
      }
      return LCDC_enOK;
}


Lcdc_nStatus LCDC__enLayer_EllipseType(LCDC_TFT_TypeDef* restrict layerSource,LCDC_TFT_TypeDef* restrict layerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    sDim.XInit=layerSource->layerBGXInit;
    sDim.YInit=layerSource->layerBGYInit;
    sDim.radius[0] =layerSource->layerRadius[0];
    sDim.radius[1] =layerSource->layerRadius[1];
    return LCDC__enLayer_Print_Ellipse(layerDest,sDim,layerSource->layerColorBG);
}



Lcdc_nStatus LCDC__enLayer_Print_EllipseFill            (LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{
    LCDC_DIMENSIONS_TypeDef sDimensions;
    int16_t s16Radius=sDim.radius[0];
    int16_t s16Radius2=sDim.radius[1];
    int16_t s16PosX=sDim.XInit;
    int16_t s16PosY=sDim.YInit;
    int16_t s16X = -s16Radius, s16Y = 0, s16Error = 2-2*s16Radius, s16Error2;
    int32_t s32aux=0;
    float fK = 0, fRadius1 = 0, fRadius2 = 0;

    if(((s16PosX+s16Radius) >( psLayer->layerWidthTotal)) || ((s16PosY+s16Radius2) >( psLayer->layerHeightTotal) ))
    {
        return LCDC_enERROR;
    }

    if(((int32_t)(s16PosX-s16Radius) <0) || ((int32_t)(s16PosY-s16Radius2) <0 ))
    {
        return LCDC_enERROR;
    }

    if(s16Radius<=0 || s16Radius2<=0)
    {
          return LCDC_enERROR;
    }


      fRadius1 = s16Radius;
      fRadius2 = s16Radius2;

      if (s16Radius > s16Radius2)
      {
        do {
          fK = (float)(fRadius2/fRadius1);
          s32aux=(int32_t)((float)s16Y*fK);
            sDimensions.height=(((uint32_t)(s32aux)*2 )+ 1);
            sDimensions.XInit =  (s16PosX+s16X);
            sDimensions.YInit = (s16PosY-(uint32_t)(s32aux));
            LCDC__vLayer_Print_LineVertical(psLayer,sDimensions,u16Color);
            sDimensions.XInit =  (s16PosX-s16X);
            LCDC__vLayer_Print_LineVertical(psLayer,sDimensions,u16Color);

          s16Error2 = s16Error;
          if (s16Error2 <= s16Y) {
              s16Error += ((++s16Y)<<1)+1;
            if (-s16X == s16Y && s16Error2 <= s16X) s16Error2 = 0;
          }
          if (s16Error2 > s16X) s16Error += ((++s16X)<<1)+1;
        }
        while (s16X <= 0);
      }
      else
      {
        s16Y = -s16Radius2;
        s16X = 0;
        do {
          fK = (float)(fRadius1/fRadius2);

          s32aux=(int32_t)((float)s16X*fK);
            sDimensions.width=(((uint32_t)(s32aux)*2 )+ 1);
            sDimensions.XInit =(s16PosX-(uint32_t)(s32aux));
            sDimensions.YInit = (s16PosY+s16Y);
            LCDC__vLayer_Print_LineHorizontal(psLayer,sDimensions,u16Color);
            sDimensions.YInit = (s16PosY-s16Y);
            LCDC__vLayer_Print_LineHorizontal(psLayer,sDimensions,u16Color);

          s16Error2 = s16Error;
          if (s16Error2 <= s16X) {
            s16Error += ++s16X*2+1;
            if (-s16Y == s16X && s16Error2 <= s16Y) s16Error2 = 0;
          }
          if (s16Error2 > s16Y) s16Error += ++s16Y*2+1;
        }
        while (s16Y <= 0);
      }
      return LCDC_enOK;
}

Lcdc_nStatus LCDC__enLayer_EllipseFillType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    sDim.XInit=psLayerSource->layerBGXInit;
    sDim.YInit=psLayerSource->layerBGYInit;
    sDim.radius[0] =psLayerSource->layerRadius[0];
    sDim.radius[1] =psLayerSource->layerRadius[1];
    return LCDC__enLayer_Print_EllipseFill(psLayerDest,sDim,psLayerSource->layerColorBG);
}


Lcdc_nStatus LCDC__enLayer_Print_Triangle           (LCDC_TFT_TypeDef* psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{

    LCDC_DIMENSIONS_TypeDef sDimensions;
    sDimensions.X[0]=sDim.X[0];
    sDimensions.Y[0]=sDim.Y[0];
    sDimensions.X[1]=sDim.X[1];
    sDimensions.Y[1]=sDim.Y[1];
    if(LCDC__enLayer_Print_LineXY(psLayer,sDimensions,u16Color)==LCDC_enERROR)
        return LCDC_enERROR;
    sDimensions.X[0]=sDim.X[1];
    sDimensions.Y[0]=sDim.Y[1];
    sDimensions.X[1]=sDim.X[2];
    sDimensions.Y[1]=sDim.Y[2];
    if(LCDC__enLayer_Print_LineXY(psLayer,sDimensions,u16Color)==LCDC_enERROR)
        return LCDC_enERROR;
    sDimensions.X[0]=sDim.X[2];
    sDimensions.Y[0]=sDim.Y[2];
    sDimensions.X[1]=sDim.X[0];
    sDimensions.Y[1]=sDim.Y[0];
    if(LCDC__enLayer_Print_LineXY(psLayer,sDimensions,u16Color)==LCDC_enERROR)
        return LCDC_enERROR;

    return LCDC_enOK;
}


Lcdc_nStatus LCDC__enLayer_TriangleType(LCDC_TFT_TypeDef* psLayerSource,LCDC_TFT_TypeDef* psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    sDim.X[0]=psLayerSource->layerBGX[0];
    sDim.X[1]=psLayerSource->layerBGX[1];
    sDim.X[2]=psLayerSource->layerBGX[2];
    sDim.Y[0]=psLayerSource->layerBGY[0];
    sDim.Y[1]=psLayerSource->layerBGY[1];
    sDim.Y[2]=psLayerSource->layerBGY[2];
    return LCDC__enLayer_Print_Triangle(psLayerDest,sDim,psLayerSource->layerColorBG);
}

Lcdc_nStatus LCDC__enLayer_Print_TriangleFill(LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{
  int16_t s16X1,s16Y1,s16X2,s16Y2,s16X3,s16Y3,s16Temp;
  float fDeltaX1,fDeltaX2,fDeltaX3;
  float fX,fDifer;
  LCDC_DIMENSIONS_TypeDef sDimensions;




  s16X1= sDim.X[0];
  s16X2= sDim.X[1];
  s16X3= sDim.X[2];


  s16Y1= sDim.Y[0];
  s16Y2= sDim.Y[1];
  s16Y3= sDim.Y[2];

  if((s16X1> psLayer->layerWidthTotal) || (s16X2 > psLayer->layerWidthTotal) || (s16X3 > psLayer->layerWidthTotal) ||
          (s16Y1> psLayer->layerHeightTotal) || (s16Y2> psLayer->layerHeightTotal)||(s16Y3> psLayer->layerHeightTotal))
          return LCDC_enOK;

  if(s16Y1>s16Y2)
  {
      s16Temp=s16Y2;
      s16Y2=s16Y1;
      s16Y1=s16Temp;

      s16Temp=s16X2;
      s16X2=s16X1;
      s16X1=s16Temp;
  }

  if(s16Y2>s16Y3)
  {
      s16Temp=s16Y3;
      s16Y3=s16Y2;
      s16Y2=s16Temp;

      s16Temp=s16X3;
      s16X3=s16X2;
      s16X2=s16Temp;
  }

  if(s16Y1>s16Y2)
  {
      s16Temp=s16Y2;
      s16Y2=s16Y1;
      s16Y1=s16Temp;

      s16Temp=s16X2;
      s16X2=s16X1;
      s16X1=s16Temp;
  }


  if((s16Y2-s16Y1)>0)
      fDeltaX1= (float)(((float)s16X2-(float)s16X1)/((float)s16Y2-(float)s16Y1));
  else
      fDeltaX1=0;

  if((s16Y3-s16Y1)>0)
      fDeltaX2= (float)(((float)s16X3-(float)s16X1)/((float)s16Y3-(float)s16Y1));
  else
      fDeltaX2=0;

  if((s16Y3-s16Y2)>0)
      fDeltaX3= (float)(((float)s16X3-(float)s16X2)/((float)s16Y3-(float)s16Y2));
  else
      fDeltaX3=0;

  fX = s16X1;
  sDimensions.YInit = s16Y1;
  fDifer = s16X1;

  if(fDeltaX1>fDeltaX2)
  {
      for(;sDimensions.YInit<=s16Y2;sDimensions.YInit++,fX+=fDeltaX2,fDifer+=fDeltaX1)
      {
          sDimensions.width=(int32_t)(fX-fDifer);
          if(fX<fDifer)
          {

              sDimensions.width=(int32_t)(fDifer-fX);
              sDimensions.XInit=(int32_t)fX;
          }
          else
          {

              sDimensions.width=(int32_t)(fX-fDifer);
              sDimensions.XInit=(int32_t)fDifer;
          }
          LCDC__vLayer_Print_LineHorizontal(psLayer,sDimensions,u16Color);
      }
      fDifer=s16X2;
      for(;sDimensions.YInit<=s16Y3;sDimensions.YInit++,fX+=fDeltaX2,fDifer+=fDeltaX3)
      {
          if(fX<fDifer)
          {

              sDimensions.width=(int32_t)(fDifer-fX);
              sDimensions.XInit=(int32_t)fX;
          }
          else
          {

              sDimensions.width=(int32_t)(fX-fDifer);
              sDimensions.XInit=(int32_t)fDifer;
          }
          LCDC__vLayer_Print_LineHorizontal(psLayer,sDimensions,u16Color);

      }
  }
  else
  {
      for(;sDimensions.YInit<=s16Y2;sDimensions.YInit++,fX+=fDeltaX1,fDifer+=fDeltaX2)
      {
          if(fX<fDifer)
          {

              sDimensions.width=(int32_t)(fDifer-fX);
              sDimensions.XInit=(int32_t)fX;
          }
          else
          {

              sDimensions.width=(int32_t)(fX-fDifer);
              sDimensions.XInit=(int32_t)fDifer;
          }
          LCDC__vLayer_Print_LineHorizontal(psLayer,sDimensions,u16Color);
      }
      fX = s16X2;
      sDimensions.YInit = s16Y2;
      for(;sDimensions.YInit<=s16Y3;sDimensions.YInit++,fX+=fDeltaX3,fDifer+=fDeltaX2)
      {
          if(fX<fDifer)
          {

              sDimensions.width=(int32_t)(fDifer-fX);
              sDimensions.XInit=(int32_t)fX;
          }
          else
          {

              sDimensions.width=(int32_t)(fX-fDifer);
              sDimensions.XInit=(int32_t)fDifer;
          }
          LCDC__vLayer_Print_LineHorizontal(psLayer,sDimensions,u16Color);

      }
  }
  return LCDC_enOK;
}



Lcdc_nStatus LCDC__enLayer_TriangleFillType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    sDim.X[0]=psLayerSource->layerBGX[0];
    sDim.X[1]=psLayerSource->layerBGX[1];
    sDim.X[2]=psLayerSource->layerBGX[2];
    sDim.Y[0]=psLayerSource->layerBGY[0];
    sDim.Y[1]=psLayerSource->layerBGY[1];
    sDim.Y[2]=psLayerSource->layerBGY[2];
    return LCDC__enLayer_Print_TriangleFill(psLayerDest,sDim,psLayerSource->layerColorBG);
}




LCDC_COORD_TypeDef LCDC__sLayer_Print_Char(LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,char cASCII,uint16_t u16Color,FONT_TypeDef* restrict sFontType)
{
  uint16_t u16Row = 0, u16Column = 0;
  uint32_t  u32AddressX = sDim.XInit, u32PosY =0;
  LCDC_COORD_TypeDef sCoord={0};

  const uint16_t* restrict character;

  if((sDim.YInit+sFontType->height)>psLayer->layerHeightTotal)
      return sCoord;

  if((sDim.XInit+sFontType->width)>psLayer->layerWidthTotal)
      return sCoord;

  character=(const uint16_t*)(&sFontType->ascii[(cASCII-' ') * sFontType->height]);

  u32PosY = sDim.YInit*psLayer->layerWidthTotal*2;

  if(sFontType->width==11  )
  {
      character=(const uint16_t*)(&sFontType->ascii[(cASCII-0x20) * sFontType->width]);
      u32PosY = sDim.YInit;
      for(u16Row = 0; u16Row < sFontType->height; u16Row++)
      {
            for(u16Column = 0; u16Column < sFontType->width;u16Column++)
            {
                if((((character[u16Column] )>>(u16Row))&1) )
                    *(__IO uint16_t*) (psLayer->layerDataAddress + (2*((u32PosY*psLayer->layerWidthTotal) + u32AddressX ))) = u16Color;
                u32AddressX++;
            }
        u32AddressX =  sDim.XInit;
        u32PosY++;
      }
  }
  else if (sFontType->width==7)
  {
      for(u16Row = 0; u16Row < sFontType->width; u16Row++)
      {
            for(u16Column = 0; u16Column < sFontType->height;u16Column++)
            {
                if((((character[u16Column] )>>(u16Row))&1) )
                    *(__IO uint16_t*) (psLayer->layerDataAddress + (2*u32AddressX) + u32PosY) = u16Color;
                u32AddressX++;
            }
        u32AddressX += (psLayer->layerWidthTotal - sFontType->height);
      }
  }
  else
    for(u16Row = 0; u16Row < sFontType->height; u16Row++)
    {
        if(sFontType->height==24)
            for(u16Column = 0; u16Column < sFontType->width;u16Column++)
            {
                if((((character[u16Row] )>>(u16Column))&1) )
                    *( uint16_t*) (psLayer->layerDataAddress + (2*u32AddressX) + u32PosY) = u16Color;
                u32AddressX++;
            }
        else
            for(u16Column = sFontType->bits; u16Column > (sFontType->bits-sFontType->width);u16Column--)
            {
                if((((character[u16Row] )>>(u16Column-1))&1) )
                    *(__IO uint16_t*) (psLayer->layerDataAddress + (2*u32AddressX) + u32PosY) = u16Color;
                u32AddressX++;
            }
        u32AddressX += (psLayer->layerWidthTotal - sFontType->width);
    }
  sCoord.X=sDim.XInit+sFontType->width;
  sCoord.Y=sDim.YInit;
  return sCoord;
}

LCDC_COORD_TypeDef LCDC__sLayer_Print_CharBG(LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,char cASCII,uint16_t u16ColorFont, uint16_t u16ColorBG,FONT_TypeDef* restrict sFontType)
{
  uint32_t u16Row = 0, u16Column = 0;
  uint32_t  u32AddressX = sDim.XInit, u32PosY =0;
  LCDC_COORD_TypeDef sCoord={0};

  const uint16_t* restrict character;

  if((sDim.YInit+sFontType->height)>psLayer->layerHeightTotal)
      return sCoord;

  if((sDim.XInit+sFontType->width)>psLayer->layerWidthTotal)
      return sCoord;

  character=(const uint16_t*)(&sFontType->ascii[(cASCII-' ') * sFontType->height]);

  u32PosY = sDim.YInit*psLayer->layerWidthTotal*2;

  if((sFontType->height==11 || sFontType->width==7) )
      for(u16Row = 0; u16Row < sFontType->width; u16Row++)
      {

            #pragma MUST_ITERATE(2,,2)
            for(u16Column = 0; u16Column < sFontType->height;u16Column++)
            {
                if((((character[u16Column] )>>(u16Row))&1) )
                    *(__IO uint16_t*) (psLayer->layerDataAddress + (2*u32AddressX) + u32PosY) = u16ColorFont;
                else
                    *(__IO uint16_t*) (psLayer->layerDataAddress + (2*u32AddressX) + u32PosY) = u16ColorBG;
                u32AddressX++;
            }
        u32AddressX += (psLayer->layerWidthTotal - sFontType->height);
      }
  else
    for(u16Row = 0; u16Row < sFontType->height; u16Row++)
    {
        if(sFontType->height==24)
            for(u16Column = 0; u16Column < sFontType->width;u16Column++)
            {
                if((((character[u16Row] )>>(u16Column))&1) )
                    *( uint16_t*) (psLayer->layerDataAddress + (2*u32AddressX) + u32PosY) = u16ColorFont;
                else
                    *(__IO uint16_t*) (psLayer->layerDataAddress + (2*u32AddressX) + u32PosY) = u16ColorBG;
                u32AddressX++;
            }
        else
            for(u16Column = sFontType->bits; u16Column > (sFontType->bits-sFontType->width);u16Column--)
            {
                if((((character[u16Row] )>>(u16Column-1))&1) )
                    *(__IO uint16_t*) (psLayer->layerDataAddress + (2*u32AddressX) + u32PosY) = u16ColorFont;
                else
                    *(__IO uint16_t*) (psLayer->layerDataAddress + (2*u32AddressX) + u32PosY) = u16ColorBG;
                u32AddressX++;
            }
        u32AddressX += (psLayer->layerWidthTotal - sFontType->width);
    }
  sCoord.X=sDim.XInit+sFontType->width;
  sCoord.Y=sDim.YInit;
  return sCoord;
}


uint32_t LCDC__u32Layer_Print_String(LCDC_TFT_TypeDef* psLayer,LCDC_DIMENSIONS_TypeDef sDim,LCDC_COORD_TypeDef* sCoord,char* pcString,uint16_t u16ColorFont,FONT_TypeDef* sFontType)
{
    uint32_t u32CharCounter=0;//variable usada para saber cuentos caracteres se imprimieron
    LCDC_DIMENSIONS_TypeDef sDimensions;


    if((sDim.YInit+sDim.height)>psLayer->layerHeightTotal)
      return u32CharCounter;

    if((sDim.XInit+sDim.width)>psLayer->layerWidthTotal)
      return u32CharCounter;

    sDimensions.XInit=sDim.XInit;
    sDimensions.YInit=sDim.YInit;
     while(*pcString)
     {

         switch(*pcString)

         {
         case '\n':
             sDimensions.YInit+=sFontType->height;
             if((sDimensions.YInit-sDim.YInit)>(sDim.height))
                 return u32CharCounter;
             break;
         case '\r':
             sDimensions.XInit=sDim.XInit;
             break;
         default:
             *sCoord=LCDC__sLayer_Print_Char(psLayer,sDimensions,*pcString,u16ColorFont,sFontType);
             if((sCoord->X-sDim.XInit+ sFontType->width)>(sDim.width))
             {
                 sDimensions.XInit=sDim.XInit;
                 sDimensions.YInit=sCoord->Y+sFontType->height;
                 if((sDimensions.YInit-sDim.YInit)>(sDim.height-sFontType->height))
                     return u32CharCounter;
             }
             else
             {
                sDimensions.XInit=sCoord->X;
                sDimensions.YInit=sCoord->Y;
             }
             break;
         }
         pcString++; //el puntero apunta al siguiente caracter
         u32CharCounter++; //suma 1 al conteo total de caracter enviados a la LCD
     }
     return u32CharCounter;
}


uint32_t LCDC__u32Layer_StringSimpleType(LCDC_TFT_TypeDef* psLayerSource,LCDC_TFT_TypeDef* psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    LCDC_COORD_TypeDef sCoord;
    sDim.XInit=psLayerSource->layerBGXInit;
    sDim.YInit=psLayerSource->layerBGYInit;
    sDim.width=psLayerSource->layerWidth*psLayerSource->layerFont->width;
    sDim.height=psLayerSource->layerHeight*(psLayerSource->layerFont->height);

    return LCDC__u32Layer_Print_String(psLayerDest,sDim,&sCoord,psLayerSource->layerString,psLayerSource->layerColorFont,psLayerSource->layerFont);
}


uint32_t LCDC__u32Layer_Print_StringBG(LCDC_TFT_TypeDef* psLayer,LCDC_DIMENSIONS_TypeDef sDim,LCDC_COORD_TypeDef* sCoord,char* pcString,uint16_t u16ColorFont, uint16_t u16ColorBG,FONT_TypeDef* sFontType)
{
    uint32_t u32CountChar=0;//variable usada para saber cuentos caracteres se imprimieron
    LCDC_DIMENSIONS_TypeDef sDimensions;


    if((sDim.YInit+sDim.height)>psLayer->layerHeightTotal)
      return u32CountChar;

    if((sDim.XInit+sDim.width)>psLayer->layerWidthTotal)
      return u32CountChar;

    sDimensions.XInit=sDim.XInit;
    sDimensions.YInit=sDim.YInit;
     while(*pcString)
     {
         switch(*pcString)

         {
         case '\n':
             sDimensions.YInit=sCoord->Y+sFontType->height;
             if((sDimensions.YInit-sDim.YInit)>(sDim.height))
                 return u32CountChar;
             break;
         case '\r':
             sDimensions.XInit=sDim.XInit;
             break;
         default:
             *sCoord=LCDC__sLayer_Print_CharBG(psLayer,sDimensions,*pcString,u16ColorFont,u16ColorBG,sFontType);
             if((sCoord->X-sDim.XInit+ sFontType->width)>(sDim.width))
             {
                 sDimensions.XInit=sDim.XInit;
                 sDimensions.YInit=sCoord->Y+sFontType->height;
                 if((sDimensions.YInit-sDim.YInit)>(sDim.height-sFontType->height))
                     return u32CountChar;
             }
             else
             {
                sDimensions.XInit=sCoord->X;
                sDimensions.YInit=sCoord->Y;
             }
             break;
         }
         pcString++; //el puntero apunta al siguiente caracter
         u32CountChar++; //suma 1 al conteo total de caracter enviados a la LCD
     }
     return u32CountChar;
}
uint32_t LCDC__u32Layer_StringSimpleBGType(LCDC_TFT_TypeDef* psLayerSource,LCDC_TFT_TypeDef* psLayerDest)
{
    LCDC_DIMENSIONS_TypeDef sDim;
    LCDC_COORD_TypeDef sCoord;
    sDim.XInit=psLayerSource->layerBGXInit;
    sDim.YInit=psLayerSource->layerBGYInit;
    sDim.width=psLayerSource->layerWidth*psLayerSource->layerFont->width;
    sDim.height=psLayerSource->layerHeight*(psLayerSource->layerFont->height);

    LCDC__vLayer_Print_RectanguleFill(psLayerDest,sDim,psLayerSource->layerColorBG);
    return LCDC__u32Layer_Print_StringBG(psLayerDest,sDim,&sCoord,psLayerSource->layerString,psLayerSource->layerColorFont,psLayerSource->layerColorBG,psLayerSource->layerFont);
}


int32_t LCDC__s32Layer_ConvString( char* restrict pcStringIn,char* restrict pcStringOut)
{
     int32_t s32CountChar=0;

     while(*pcStringIn)
     {
         *pcStringOut=*pcStringIn;
         pcStringOut++;
         pcStringIn++;
         s32CountChar++;
     }
     return s32CountChar;
}

uint64_t LTDC__u64Layer_Printf(char* pcStringIn,char* pcStringOut,...)
{
    volatile int32_t s32Count=0,s32Aux=0;//variable usada para saber cuantos caracteres se mandaron a la LCD

    va_list ap; //crea puntero de los argumentos
    double valueARGd; //variable donde guardara el valor del argumento
    char* valueARGc; //variable donde guardara el valor del argumento
    int32_t valueARGi; //variable donde guardara el valor del argumento
    int64_t valueARGii; //variable donde guardara el valor del argumento
    uint64_t valueARGuu; //variable donde guardara el valor del argumento
    void* valueARGcl; //variable donde guardara el valor del argumento
    uint32_t valueARGclAux; //variable donde guardara el valor del argumento
    char conversion[60];
    va_start(ap, pcStringOut);//maneja la memoria de los argumentos empezando desde el ultimo conocido ingresado
    while(*pcStringIn)// realiza el ciclo mientras la pcString tenga algun valor
    {
        switch (*pcStringIn) //detecta si existe un caracter especial
        {
        case '%':
            pcStringIn++;
            switch(*pcStringIn)
            {
                case 'd': //"%d o %i"
                case 'i':
                    valueARGi=(int32_t)va_arg(ap, int32_t);
                    CONV__u8IntToString((int64_t)valueARGi,conversion);
                    s32Aux=LCDC__s32Layer_ConvString(conversion,pcStringOut)-1;
                    s32Count+=s32Aux;
                    pcStringOut+=s32Aux;
                    break;
                case 'u':// "%u"
                    valueARGi=(uint32_t)va_arg(ap, uint32_t);
                    CONV__u8UIntToString((uint32_t)valueARGi,conversion);
                    s32Aux=LCDC__s32Layer_ConvString(conversion,pcStringOut)-1;
                    s32Count+=s32Aux;
                    pcStringOut+=s32Aux;
                    break;
                case 'x': //"%x"
                    valueARGi=(uint32_t)va_arg(ap, uint32_t);
                    CONV__u8HexToString((uint32_t)valueARGi,conversion);
                    s32Aux=LCDC__s32Layer_ConvString(conversion,pcStringOut)-1;
                    s32Count+=s32Aux;
                    pcStringOut+=s32Aux;
                    break;
                case 'X':// "%X"
                    valueARGi=(uint32_t)va_arg(ap, uint32_t);
                    CONV__u8HEXToString((uint32_t)valueARGi,conversion);
                    s32Aux=LCDC__s32Layer_ConvString(conversion,pcStringOut)-1;
                    s32Count+=s32Aux;
                    pcStringOut+=s32Aux;
                    break;
                case 'o': //"%o"
                    valueARGi=(uint32_t)va_arg(ap, uint32_t);
                    CONV__u8OctToString((uint32_t)valueARGi,conversion);
                    s32Aux=LCDC__s32Layer_ConvString(conversion,pcStringOut)-1;
                    s32Count+=s32Aux;
                    pcStringOut+=s32Aux;
                    break;
               case 'p': //"%p"
                    valueARGcl=(void*)va_arg(ap, void*);
                    valueARGclAux=(uint32_t)valueARGcl;
                    CONV__u8BinToString((uint64_t)valueARGclAux,conversion);
                    s32Aux=LCDC__s32Layer_ConvString(conversion,pcStringOut)-1;
                    s32Count+=s32Aux;
                    pcStringOut+=s32Aux;
                        break;
                case 'f': //"%f"
                    valueARGd=(double)va_arg(ap, double);
                    CONV__u8FloatToString((double)(float)valueARGd,0,0,1,3,conversion);
                    s32Aux=LCDC__s32Layer_ConvString(conversion,pcStringOut)-1;
                    s32Count+=s32Aux;
                    pcStringOut+=s32Aux;
                    break;




                case 'c': //"%c"
                    valueARGi=(uint8_t)va_arg(ap, int32_t);
                    *pcStringOut=valueARGi;
                    break;
                case 's':// "%s"
                    valueARGc=(char*)va_arg(ap,char*);  //el siguiente argumento es un puntero
                    s32Aux=LCDC__s32Layer_ConvString((char*)valueARGc,pcStringOut)-1;
                    s32Count+=s32Aux;
                    pcStringOut+=s32Aux;
                    break;
                case 'l'://"%lf" "%8.4lf" "%5.3f" "%l"
                    pcStringIn++; //aumenta en uno la posicion del pcString
                    if(*pcStringIn=='f') //si es 'f' el sig caracter significa que vamos a convertir un double
                    {
                        valueARGd=(double)va_arg(ap, double);
                        CONV__u8FloatToString((double)valueARGd,0,0,1,5,conversion);
                        s32Aux=LCDC__s32Layer_ConvString(conversion,pcStringOut)-1;
                        s32Count+=s32Aux;
                        pcStringOut+=s32Aux;
                        break; //break de este caso
                    }
                    if(*pcStringIn=='l' ) //si es 'f' el sig caracter significa que vamos a convertir un double
                    {
                        pcStringIn++;
                        if(*pcStringIn=='d' || *pcStringIn=='i' ) //si es 'f' el sig caracter significa que vamos a convertir un double
                          {
                          valueARGii=(int64_t)va_arg(ap, int64_t);
                          CONV__u8IntToString((int64_t)valueARGii,conversion);
                          s32Aux=LCDC__s32Layer_ConvString(conversion,pcStringOut)-1;
                          s32Count+=s32Aux;
                          pcStringOut+=s32Aux;
                          break; //break de este caso
                          }
                        if(*pcStringIn=='u' ) //si es 'f' el sig caracter significa que vamos a convertir un double
                          {
                          valueARGuu=(uint64_t)va_arg(ap, uint64_t);
                          CONV__u8UIntToString((uint64_t)valueARGuu,conversion);
                          s32Aux=LCDC__s32Layer_ConvString(conversion,pcStringOut)-1;
                          s32Count+=s32Aux;
                          pcStringOut+=s32Aux;
                          break; //break de este caso
                          }
                    }
                    if(*pcStringIn=='d' || *pcStringIn=='i' ) //si es 'f' el sig caracter significa que vamos a convertir un double
                    {
                    valueARGi=(int32_t)va_arg(ap, int32_t);
                    CONV__u8IntToString((int32_t)valueARGi,conversion);
                    s32Aux=LCDC__s32Layer_ConvString(conversion,pcStringOut)-1;
                    s32Count+=s32Aux;
                    pcStringOut+=s32Aux;
                    break; //break de este caso
                    }
                    if(*pcStringIn=='u' ) //si es 'f' el sig caracter significa que vamos a convertir un double
                    {
                    valueARGi=(uint32_t)va_arg(ap, uint32_t);
                    CONV__u8IntToString((uint32_t)valueARGi,conversion);
                    s32Aux=LCDC__s32Layer_ConvString(conversion,pcStringOut)-1;
                    s32Count+=s32Aux;
                    pcStringOut+=s32Aux;
                    break; //break de este caso
                    }
                    else
                    {
                        pcStringIn--; //si no encuentra la 'f' regresa a la 'l'
                    pcStringIn--;//si no es ningun caso anterior regresa al '%'
                    *pcStringOut=*pcStringIn;
                    break;
                    }
                default:// "%p"
                    pcStringIn--;//si no es ningun caso anterior regresa al '%'
                    *pcStringOut=*pcStringIn;
                    break;

           }
            break;



        default :
            *pcStringOut=*pcStringIn;
            break;
        }
        pcStringOut++;
        pcStringIn++; //el puntero apunta al siguiente caracter
        s32Count++; //suma 1 al conteo total de caracter enviados a la LCD
    }
    *pcStringOut=0;
    va_end(ap); //reinicia el puntero

     return s32Count; //regresa el conteo de caracteres y caracteres especiales
}

