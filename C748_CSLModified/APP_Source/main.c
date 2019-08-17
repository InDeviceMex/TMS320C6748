
/**
 * main.c
 */

#include <Core.h>
#include <Cache.h>
#include <INTC.h>
#include <PSC.h>
#include <TIMER.h>
#include <ECAP.h>
#include <EDMA3.h>
#include <LCDC.h>
#include <VPIF.h>
#include <I2C.h>
#include <SysTick.h>

#include <Images.h>
#include <ImageProcessing.h>
#include <OV5640.h>



#define  CAMERA_WIDTH (120)
#define  CAMERA_HEIGHT (120)
void MAIN_vInitBaseSystem(void);
void MAIN_vInitInterrupt(void);
void MAIN_vInitTimer2(void);

void TIMER2_vIsr(void);
void GPIO0_vIsr(void);


#define MAIN_SUBLAYERMAX (20)
#pragma DATA_SECTION(MAIN_sLayerBGBuffer, ".MyData")
#pragma DATA_ALIGN(MAIN_sLayerBGBuffer, 1024*1024)
volatile uint16_t MAIN_sLayerBGBuffer[480][640];


#pragma DATA_SECTION(MAIN__u16CameraBuffer, ".MyData")
#pragma DATA_ALIGN(MAIN__u16CameraBuffer, 1024*1024)
volatile uint16_t MAIN__u16CameraBuffer[CAMERA_HEIGHT][CAMERA_WIDTH];

//#pragma DATA_SECTION(MAIN__u16ProcessingBuffer, ".MyData")
//#pragma DATA_ALIGN(MAIN__u16ProcessingBuffer, 1024*1024)
volatile uint16_t MAIN__u16ProcessingBuffer[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint16_t MAIN__u16ProcessingBuffer1[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint16_t MAIN__u16ProcessingBuffer2[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint16_t MAIN__u16ProcessingBuffer3[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint8_t MAIN__u8ProcessingBuffer4[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint16_t MAIN__u16ProcessingBuffer5[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint16_t MAIN__u16ProcessingBuffer6[179][280];
volatile uint16_t MAIN__u16ProcessingBuffer7[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint8_t MAIN__u8ProcessingBuffer8[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint8_t MAIN__u8ProcessingBuffer9[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint8_t MAIN__u8ProcessingBuffer10[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile float MAIN__fProcessingBuffer11[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile float MAIN__fProcessingBuffer12[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile float MAIN__fProcessingBuffer13[CAMERA_HEIGHT][CAMERA_WIDTH];


char     MAIN_cStringBG[30];
uint16_t MAIN_u16LayerBG_BGX[2]={0};
uint16_t MAIN_u16LayerBG_BGY[2]={0};
uint16_t MAIN_u16layerBG_X[2]={0};
uint16_t MAIN_u16layerBG_Y[2]={0};
LCDC_TFT_TypeDef* MAIN_psLayerBG_SubLayers[MAIN_SUBLAYERMAX];

LCDC_TFT_TypeDef MAIN_sLayerBG={
        LCDC, //registros
        0, (uint32_t)MAIN_sLayerBGBuffer, 0, 0, 0, 0,//direcciones de memoria

        0xF800, 0x001F, //colores BG y Font
        &FONT_s16x24, MAIN_cStringBG, //font utilizada y memoria para strings

        640,480,640,480,  //tamaño del layer

        2,2,2,2,
        0,(uint16_t*)MAIN_u16LayerBG_BGX,   //posicion de inicio layerBGXi
        0,(uint16_t*)MAIN_u16LayerBG_BGY,   //posicion de inicio layerBGYi
        0,(uint16_t*)MAIN_u16layerBG_X,     //posicion de inicio layerXi
        0,(uint16_t*)MAIN_u16layerBG_Y,     //posicion de inicio layerYi
        0,0,0,                                  //posiciones para radio


        0,//sublayer num
        0,//sublayers creadas
        MAIN_SUBLAYERMAX,//sublayer maximas
        0,//layerBG
        MAIN_psLayerBG_SubLayers,//puntero a sus sublayers
        LAYER_TYPE_enIMAGE_NOHEADER,            //tipo de layer
        VARIABLETYPE_enUSHORT,//tipo de variable utilizada en la layer
};



LCDC_TFT_TypeDef* MAIN_psLayerBG=&MAIN_sLayerBG;
LCDC_TFT_TypeDef MAIN_sSubLayerBG_Generic[MAIN_SUBLAYERMAX]={0};
uint32_t MAIN_sLayerBG_Number[MAIN_SUBLAYERMAX]={0};


uint16_t MAIN_sSubLayer0BG_BGX[2]={0};
uint16_t MAIN_sSubLayer0BG_BGY[2]={0};
uint16_t MAIN_sSubLayer0BG_X[2]={0};
uint16_t MAIN_sSubLayer0BG_Y[2]={0};

uint16_t MAIN_sSubLayer2BG_BGX[2]={0};
uint16_t MAIN_sSubLayer2BG_BGY[2]={0};
uint16_t MAIN_sSubLayer2BG_X[2]={0};
uint16_t MAIN_sSubLayer2BG_Y[2]={0};

uint16_t MAIN_sSubLayer3BG_BGX[2]={0};
uint16_t MAIN_sSubLayer3BG_BGY[2]={0};
uint16_t MAIN_sSubLayer3BG_X[2]={0};
uint16_t MAIN_sSubLayer3BG_Y[2]={0};

uint16_t MAIN_sSubLayer4BG_BGX[2]={0};
uint16_t MAIN_sSubLayer4BG_BGY[2]={0};
uint16_t MAIN_sSubLayer4BG_X[2]={0};
uint16_t MAIN_sSubLayer4BG_Y[2]={0};

uint16_t MAIN_sSubLayer5BG_BGX[2]={0};
uint16_t MAIN_sSubLayer5BG_BGY[2]={0};
uint16_t MAIN_sSubLayer5BG_X[2]={0};
uint16_t MAIN_sSubLayer5BG_Y[2]={0};

uint16_t MAIN_sSubLayer6BG_BGX[2]={0};
uint16_t MAIN_sSubLayer6BG_BGY[2]={0};
uint16_t MAIN_sSubLayer6BG_X[2]={0};
uint16_t MAIN_sSubLayer6BG_Y[2]={0};

uint16_t MAIN_sSubLayer7BG_BGX[2]={0};
uint16_t MAIN_sSubLayer7BG_BGY[2]={0};
uint16_t MAIN_sSubLayer7BG_X[2]={0};
uint16_t MAIN_sSubLayer7BG_Y[2]={0};


uint16_t MAIN_sSubLayer9BG_BGX[2]={0};
uint16_t MAIN_sSubLayer9BG_BGY[2]={0};


uint16_t MAIN_sSubLayer13BG_Radius[2]={0};

uint16_t MAIN_sSubLayer15BG_BGX[3]={0};
uint16_t MAIN_sSubLayer15BG_BGY[3]={0};

char MAIN_cSubLayer16BG_String[60]="Hola Mundo";
char MAIN_cSubLayer2BG_String[60]="Image Original";
char MAIN_cSubLayer4BG_String[60]="Image GrayScale";
char MAIN_cSubLayer6BG_String[60]="Image Add";
uint8_t pu8ValueMemory[102];
uint8_t pu8ReadMemory[100];

uint32_t valuesDMA[100];

uint8_t u8State[2]={1,1};
OV5640_LIGHTMODE_nValue enLight=OV5640_LIGHTMODE_enAUTO;
OV5640_SPECIALEFFECTS_nValue enEffects=OV5640_SPECIALEFFECTS_enNORMAL;
LCDC_DIMENSIONS_TypeDef Dim,DimImage,DimProcessing,DimProcessing1,DimProcessing2;
int main(void)
 {

    MAIN_vInitBaseSystem();
    MAIN_vInitInterrupt();
    SysTick__enInitUs(100);


    SYSCFG0->PINMUX_Bit[1].PINMUX_31_28=8;//GP0_0
    SYSCFG0->PINMUX_Bit[1].PINMUX_27_24=8;//GP0_1
    SYSCFG0->PINMUX_Bit[0].PINMUX_11_8=8;//GP0_13


    GPIO0_SET_FAL_TRIG_R|=(GPIO_R_P1_MASK|GPIO_R_P0_MASK);
    GPIO0_CLR_RIS_TRIG_R|=(GPIO_R_P1_MASK|GPIO_R_P0_MASK);
    GPIO0_DIR_R|=(GPIO_R_P1_MASK|GPIO_R_P0_MASK);
    GPIO0_DIR_R&=~(GPIO_R_P13_MASK);
    GPIO0_CLR_DATA_R|=(GPIO_R_P13_MASK);
    GPIO0_INTSTAT_R=(GPIO_R_P1_MASK|GPIO_R_P0_MASK);
    GPIO_BINTEN_R|=GPIO_R_P0_MASK;

    LCDC__vInit();

    OV5640__enInit();
    OV5640__vModeRGB565();
    OV5640__enInitFocus();
    OV5640__vSetLightMode(OV5640_LIGHTMODE_enAUTO);
    OV5640__vSetColorSaturation(OV5640_SATURATION_en0);
    OV5640__vSetBrightness(OV5640_BRIGHTNESS_en0);
    OV5640__vSetContrast(OV5640_CONTRAST_en0);
    OV5640__vSetSharpness(33);
    OV5640__enContinueFocus();
    OV5640__vSetOutSize(4,0,CAMERA_WIDTH,CAMERA_HEIGHT);


    SysTick__vDelayUs(5000);
    VPIF__vInitReceive((uint32_t)MAIN__u16CameraBuffer,CAMERA_WIDTH);

    LCDC__u8LayerBG_AddSubLayer(MAIN_psLayerBG);

    MAIN_sSubLayerBG_Generic[0].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[0].layerDataAddress=(uint32_t)&gImage_comic;
    MAIN_sSubLayerBG_Generic[0].layerX=(uint16_t*)MAIN_sSubLayer0BG_X;
    MAIN_sSubLayerBG_Generic[0].layerXInit=0;
    MAIN_sSubLayerBG_Generic[0].layerY=(uint16_t*)MAIN_sSubLayer0BG_Y;
    MAIN_sSubLayerBG_Generic[0].layerYInit=0;
    MAIN_sSubLayerBG_Generic[0].layerWidthTotal=640;
    MAIN_sSubLayerBG_Generic[0].layerHeightTotal=480;
    MAIN_sSubLayerBG_Generic[0].layerBGX=(uint16_t*)MAIN_sSubLayer0BG_BGX;
    MAIN_sSubLayerBG_Generic[0].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[0].layerBGY=(uint16_t*)MAIN_sSubLayer0BG_BGY;
    MAIN_sSubLayerBG_Generic[0].layerBGYInit=0;
    MAIN_sSubLayerBG_Generic[0].layerWidth=640;
    MAIN_sSubLayerBG_Generic[0].layerHeight=480;

    MAIN_sLayerBG_Number[0]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[0]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[0]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[1].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[1].layerDataAddress=(uint32_t)&MAIN__u16CameraBuffer;
    MAIN_sSubLayerBG_Generic[1].layerX=(uint16_t*)MAIN_sSubLayer2BG_X;
    MAIN_sSubLayerBG_Generic[1].layerXInit=0;
    MAIN_sSubLayerBG_Generic[1].layerY=(uint16_t*)MAIN_sSubLayer2BG_Y;
    MAIN_sSubLayerBG_Generic[1].layerYInit=0;
    MAIN_sSubLayerBG_Generic[1].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[1].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[1].layerBGX=(uint16_t*)MAIN_sSubLayer2BG_BGX;
    MAIN_sSubLayerBG_Generic[1].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[1].layerBGY=(uint16_t*)MAIN_sSubLayer2BG_BGY;
    MAIN_sSubLayerBG_Generic[1].layerBGYInit=0;
    MAIN_sSubLayerBG_Generic[1].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[1].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[1].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[1]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[1]);

    MAIN_sSubLayerBG_Generic[2].layerType=LAYER_TYPE_enSTRING_SIMPLE_BACKGROUND;
    MAIN_sSubLayerBG_Generic[2].layerFont=&FONT_s8x16_System;
    MAIN_sSubLayerBG_Generic[2].layerColorFont=0x6885;
    MAIN_sSubLayerBG_Generic[2].layerColorBG=0xFFFF;
    MAIN_sSubLayerBG_Generic[2].layerString=MAIN_cSubLayer2BG_String;
    MAIN_sSubLayerBG_Generic[2].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[2].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[2].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[2].layerBGYInit=CAMERA_HEIGHT+10;
    MAIN_sSubLayerBG_Generic[2].layerWidth=14;
    MAIN_sSubLayerBG_Generic[2].layerHeight=1;
    MAIN_sLayerBG_Number[2]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[2]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[2]);
    LCDC__enLayerBG_RefreshSubLayer(1);


    DimProcessing.X[0]=0;
    DimProcessing.X[1]=0;
    DimProcessing.Y[0]=0;
    DimProcessing.Y[1]=0;
    DimProcessing.width=CAMERA_WIDTH;
    DimProcessing.height=CAMERA_HEIGHT;

    DimProcessing1.X[0]=200;
    DimProcessing1.X[1]=0;
    DimProcessing1.X[2]=0;
    DimProcessing1.Y[0]=200;
    DimProcessing1.Y[1]=0;
    DimProcessing1.Y[2]=0;
    DimProcessing1.width=CAMERA_WIDTH;
    DimProcessing1.height=CAMERA_HEIGHT;

    DimProcessing2.X[0]=0;
    DimProcessing2.X[1]=0;
    DimProcessing2.X[2]=0;
    DimProcessing2.Y[0]=0;
    DimProcessing2.Y[1]=0;
    DimProcessing2.Y[2]=0;
    DimProcessing2.width=280;
    DimProcessing2.height=179;

    MAIN_sSubLayerBG_Generic[3].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[3].layerDataAddress=(uint32_t)&MAIN__u16ProcessingBuffer;
    MAIN_sSubLayerBG_Generic[3].layerX=(uint16_t*)MAIN_sSubLayer3BG_X;
    MAIN_sSubLayerBG_Generic[3].layerXInit=0;
    MAIN_sSubLayerBG_Generic[3].layerY=(uint16_t*)MAIN_sSubLayer3BG_Y;
    MAIN_sSubLayerBG_Generic[3].layerYInit=0;
    MAIN_sSubLayerBG_Generic[3].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[3].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[3].layerBGX=(uint16_t*)MAIN_sSubLayer3BG_BGX;
    MAIN_sSubLayerBG_Generic[3].layerBGXInit=CAMERA_WIDTH+100;
    MAIN_sSubLayerBG_Generic[3].layerBGY=(uint16_t*)MAIN_sSubLayer3BG_BGY;
    MAIN_sSubLayerBG_Generic[3].layerBGYInit=0;
    MAIN_sSubLayerBG_Generic[3].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[3].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[3].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[3]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[3]);

    MAIN_sSubLayerBG_Generic[4].layerType=LAYER_TYPE_enSTRING_SIMPLE_BACKGROUND;
    MAIN_sSubLayerBG_Generic[4].layerFont=&FONT_s8x16_System;
    MAIN_sSubLayerBG_Generic[4].layerColorFont=0x6885;
    MAIN_sSubLayerBG_Generic[4].layerColorBG=0xFFFF;
    MAIN_sSubLayerBG_Generic[4].layerString=MAIN_cSubLayer4BG_String;
    MAIN_sSubLayerBG_Generic[4].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[4].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[4].layerBGXInit=CAMERA_WIDTH+100;
    MAIN_sSubLayerBG_Generic[4].layerBGYInit=CAMERA_HEIGHT+10;
    MAIN_sSubLayerBG_Generic[4].layerWidth=15;
    MAIN_sSubLayerBG_Generic[4].layerHeight=1;
    MAIN_sLayerBG_Number[4]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[4]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[4]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[5].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[5].layerDataAddress=(uint32_t)&MAIN__u16ProcessingBuffer1;
    MAIN_sSubLayerBG_Generic[5].layerX=(uint16_t*)MAIN_sSubLayer4BG_X;
    MAIN_sSubLayerBG_Generic[5].layerXInit=0;
    MAIN_sSubLayerBG_Generic[5].layerY=(uint16_t*)MAIN_sSubLayer4BG_Y;
    MAIN_sSubLayerBG_Generic[5].layerYInit=0;
    MAIN_sSubLayerBG_Generic[5].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[5].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[5].layerBGX=(uint16_t*)MAIN_sSubLayer4BG_BGX;
    MAIN_sSubLayerBG_Generic[5].layerBGXInit=(CAMERA_WIDTH+100)*2;
    MAIN_sSubLayerBG_Generic[5].layerBGY=(uint16_t*)MAIN_sSubLayer4BG_BGY;
    MAIN_sSubLayerBG_Generic[5].layerBGYInit=0;
    MAIN_sSubLayerBG_Generic[5].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[5].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[5].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[5]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[5]);

    MAIN_sSubLayerBG_Generic[6].layerType=LAYER_TYPE_enSTRING_SIMPLE_BACKGROUND;
    MAIN_sSubLayerBG_Generic[6].layerFont=&FONT_s8x16_System;
    MAIN_sSubLayerBG_Generic[6].layerColorFont=0x6885;
    MAIN_sSubLayerBG_Generic[6].layerColorBG=0xFFFF;
    MAIN_sSubLayerBG_Generic[6].layerString=MAIN_cSubLayer6BG_String;
    MAIN_sSubLayerBG_Generic[6].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[6].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[6].layerBGXInit=(CAMERA_WIDTH+100)*2;
    MAIN_sSubLayerBG_Generic[6].layerBGYInit=CAMERA_HEIGHT+10;
    MAIN_sSubLayerBG_Generic[6].layerWidth=14;
    MAIN_sSubLayerBG_Generic[6].layerHeight=1;
    MAIN_sLayerBG_Number[6]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[6]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[6]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[7].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[7].layerDataAddress=(uint32_t)&MAIN__u8ProcessingBuffer4;
    MAIN_sSubLayerBG_Generic[7].layerX=(uint16_t*)MAIN_sSubLayer7BG_X;
    MAIN_sSubLayerBG_Generic[7].layerXInit=0;
    MAIN_sSubLayerBG_Generic[7].layerY=(uint16_t*)MAIN_sSubLayer7BG_Y;
    MAIN_sSubLayerBG_Generic[7].layerYInit=0;
    MAIN_sSubLayerBG_Generic[7].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[7].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[7].layerBGX=(uint16_t*)MAIN_sSubLayer7BG_BGX;
    MAIN_sSubLayerBG_Generic[7].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[7].layerBGY=(uint16_t*)MAIN_sSubLayer7BG_BGY;
    MAIN_sSubLayerBG_Generic[7].layerBGYInit=CAMERA_HEIGHT*2+10;
    MAIN_sSubLayerBG_Generic[7].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[7].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[7].variableType=VARIABLETYPE_enUCHAR;
    MAIN_sLayerBG_Number[7]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[7]);

    MAIN_sSubLayerBG_Generic[8].layerType=LAYER_TYPE_enSTRING_SIMPLE_BACKGROUND;
    MAIN_sSubLayerBG_Generic[8].layerFont=&FONT_s8x16_System;
    MAIN_sSubLayerBG_Generic[8].layerColorFont=0x6885;
    MAIN_sSubLayerBG_Generic[8].layerColorBG=0xFFFF;
    MAIN_sSubLayerBG_Generic[8].layerString="Kurapika";
    MAIN_sSubLayerBG_Generic[8].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[8].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[8].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[8].layerBGYInit=CAMERA_HEIGHT*2+50;
    MAIN_sSubLayerBG_Generic[8].layerWidth=14;
    MAIN_sSubLayerBG_Generic[8].layerHeight=1;
    MAIN_sLayerBG_Number[8]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[8]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[8]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[9].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[9].layerDataAddress=(uint32_t)&gImage_kurapica;
    MAIN_sSubLayerBG_Generic[9].layerX=(uint16_t*)MAIN_sSubLayer7BG_X;
    MAIN_sSubLayerBG_Generic[9].layerXInit=200;
    MAIN_sSubLayerBG_Generic[9].layerY=(uint16_t*)MAIN_sSubLayer7BG_Y;
    MAIN_sSubLayerBG_Generic[9].layerYInit=200;
    MAIN_sSubLayerBG_Generic[9].layerWidthTotal=640;
    MAIN_sSubLayerBG_Generic[9].layerHeightTotal=480;
    MAIN_sSubLayerBG_Generic[9].layerBGX=(uint16_t*)MAIN_sSubLayer7BG_BGX;
    MAIN_sSubLayerBG_Generic[9].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[9].layerBGY=(uint16_t*)MAIN_sSubLayer7BG_BGY;
    MAIN_sSubLayerBG_Generic[9].layerBGYInit=CAMERA_HEIGHT+40;
    MAIN_sSubLayerBG_Generic[9].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[9].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[9].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[9]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[9]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[9]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[10].layerType=LAYER_TYPE_enSTRING_SIMPLE_BACKGROUND;
    MAIN_sSubLayerBG_Generic[10].layerFont=&FONT_s8x16_System;
    MAIN_sSubLayerBG_Generic[10].layerColorFont=0x6885;
    MAIN_sSubLayerBG_Generic[10].layerColorBG=0xFFFF;
    MAIN_sSubLayerBG_Generic[10].layerString="Add Blend";
    MAIN_sSubLayerBG_Generic[10].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[10].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[10].layerBGXInit=(CAMERA_WIDTH+100);
    MAIN_sSubLayerBG_Generic[10].layerBGYInit=CAMERA_HEIGHT*2+50;
    MAIN_sSubLayerBG_Generic[10].layerWidth=14;
    MAIN_sSubLayerBG_Generic[10].layerHeight=1;
    MAIN_sLayerBG_Number[10]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[10]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[10]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[11].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[11].layerDataAddress=(uint32_t)&MAIN__u16ProcessingBuffer5;
    MAIN_sSubLayerBG_Generic[11].layerX=(uint16_t*)MAIN_sSubLayer7BG_X;
    MAIN_sSubLayerBG_Generic[11].layerXInit=0;
    MAIN_sSubLayerBG_Generic[11].layerY=(uint16_t*)MAIN_sSubLayer7BG_Y;
    MAIN_sSubLayerBG_Generic[11].layerYInit=0;
    MAIN_sSubLayerBG_Generic[11].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[11].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[11].layerBGX=(uint16_t*)MAIN_sSubLayer7BG_BGX;
    MAIN_sSubLayerBG_Generic[11].layerBGXInit=CAMERA_WIDTH+100;
    MAIN_sSubLayerBG_Generic[11].layerBGY=(uint16_t*)MAIN_sSubLayer7BG_BGY;
    MAIN_sSubLayerBG_Generic[11].layerBGYInit=CAMERA_HEIGHT+40;
    MAIN_sSubLayerBG_Generic[11].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[11].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[11].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[11]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[11]);



    MAIN_sSubLayerBG_Generic[12].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[12].layerDataAddress=(uint32_t)&gImage_bic;
    MAIN_sSubLayerBG_Generic[12].layerXInit=0;
    MAIN_sSubLayerBG_Generic[12].layerYInit=0;
    MAIN_sSubLayerBG_Generic[12].layerWidthTotal=280;
    MAIN_sSubLayerBG_Generic[12].layerHeightTotal=179;
    MAIN_sSubLayerBG_Generic[12].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[12].layerBGYInit=CAMERA_HEIGHT*2+50;
    MAIN_sSubLayerBG_Generic[12].layerWidth=280;
    MAIN_sSubLayerBG_Generic[12].layerHeight=179;
    MAIN_sSubLayerBG_Generic[12].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[12]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[12]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[12]);
    LCDC__enLayerBG_RefreshSubLayer(1);




    MAIN_sSubLayerBG_Generic[13].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[13].layerDataAddress=(uint32_t)&gImage_del;
    MAIN_sSubLayerBG_Generic[13].layerXInit=0;
    MAIN_sSubLayerBG_Generic[13].layerYInit=0;
    MAIN_sSubLayerBG_Generic[13].layerWidthTotal=280;
    MAIN_sSubLayerBG_Generic[13].layerHeightTotal=179;
    MAIN_sSubLayerBG_Generic[13].layerBGXInit=280+10;
    MAIN_sSubLayerBG_Generic[13].layerBGYInit=CAMERA_HEIGHT*2+50;
    MAIN_sSubLayerBG_Generic[13].layerWidth=280;
    MAIN_sSubLayerBG_Generic[13].layerHeight=179;
    MAIN_sSubLayerBG_Generic[13].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[13]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[13]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[13]);
    LCDC__enLayerBG_RefreshSubLayer(1);


    MAIN_sSubLayerBG_Generic[14].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[14].layerDataAddress=(uint32_t)&MAIN__u16ProcessingBuffer6;
    MAIN_sSubLayerBG_Generic[14].layerXInit=0;
    MAIN_sSubLayerBG_Generic[14].layerYInit=0;
    MAIN_sSubLayerBG_Generic[14].layerWidthTotal=280;
    MAIN_sSubLayerBG_Generic[14].layerHeightTotal=179;
    MAIN_sSubLayerBG_Generic[14].layerBGXInit=350;
    MAIN_sSubLayerBG_Generic[14].layerBGYInit=0;
    MAIN_sSubLayerBG_Generic[14].layerWidth=280;
    MAIN_sSubLayerBG_Generic[14].layerHeight=179;
    MAIN_sSubLayerBG_Generic[14].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[14]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[14]);


    MAIN_sSubLayerBG_Generic[15].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[15].layerDataAddress=(uint32_t)&MAIN__u16ProcessingBuffer7;
    MAIN_sSubLayerBG_Generic[15].layerXInit=0;
    MAIN_sSubLayerBG_Generic[15].layerYInit=0;
    MAIN_sSubLayerBG_Generic[15].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[15].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[15].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[15].layerBGYInit=0;
    MAIN_sSubLayerBG_Generic[15].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[15].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[15].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[15]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[15]);



    MAIN_sSubLayerBG_Generic[16].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[16].layerDataAddress=(uint32_t)&MAIN__u8ProcessingBuffer8;
    MAIN_sSubLayerBG_Generic[16].layerXInit=0;
    MAIN_sSubLayerBG_Generic[16].layerYInit=0;
    MAIN_sSubLayerBG_Generic[16].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[16].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[16].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[16].layerBGYInit=0;
    MAIN_sSubLayerBG_Generic[16].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[16].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[16].variableType=VARIABLETYPE_enUCHAR;
    MAIN_sLayerBG_Number[16]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[16]);

    MAIN_sSubLayerBG_Generic[17].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[17].layerDataAddress=(uint32_t)&MAIN__u8ProcessingBuffer9;
    MAIN_sSubLayerBG_Generic[17].layerXInit=0;
    MAIN_sSubLayerBG_Generic[17].layerYInit=0;
    MAIN_sSubLayerBG_Generic[17].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[17].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[17].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[17].layerBGYInit=0;
    MAIN_sSubLayerBG_Generic[17].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[17].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[17].variableType=VARIABLETYPE_enUCHAR;
    MAIN_sLayerBG_Number[17]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[17]);

    MAIN_sSubLayerBG_Generic[18].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[18].layerDataAddress=(uint32_t)&MAIN__u8ProcessingBuffer10;
    MAIN_sSubLayerBG_Generic[18].layerXInit=0;
    MAIN_sSubLayerBG_Generic[18].layerYInit=0;
    MAIN_sSubLayerBG_Generic[18].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[18].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[18].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[18].layerBGYInit=0;
    MAIN_sSubLayerBG_Generic[18].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[18].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[18].variableType=VARIABLETYPE_enUCHAR;
    MAIN_sLayerBG_Number[18]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[18]);

    MAIN_sSubLayerBG_Generic[19].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[19].layerDataIntensity=(uint32_t)&MAIN__fProcessingBuffer11;
    MAIN_sSubLayerBG_Generic[19].layerDataHue=(uint32_t)&MAIN__fProcessingBuffer12;
    MAIN_sSubLayerBG_Generic[19].layerDataSaturation=(uint32_t)&MAIN__fProcessingBuffer13;
    MAIN_sSubLayerBG_Generic[19].layerXInit=0;
    MAIN_sSubLayerBG_Generic[19].layerYInit=0;
    MAIN_sSubLayerBG_Generic[19].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[19].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[19].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[19].layerBGYInit=0;
    MAIN_sSubLayerBG_Generic[19].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[19].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[19].variableType=VARIABLETYPE_enFLOAT;
    MAIN_sLayerBG_Number[19]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[19]);

    LCDC__vBackLight(BACKLIGHT_enON);

    while(1)
    {

        if(u8State[0]>0)
        {
            LCDC__enLayer_Copy(&MAIN_sSubLayerBG_Generic[1],&MAIN_sSubLayerBG_Generic[15],DimProcessing);
            IMAGEPROC__en16bRGBScale_8bGrayScale(&MAIN_sSubLayerBG_Generic[15],&MAIN_sSubLayerBG_Generic[16],DimProcessing);
            u8State[0]=0;
        }

        //IMAGEPROC__en16bRGBScale_16bGrayScale(&MAIN_sSubLayerBG_Generic[1],&MAIN_sSubLayerBG_Generic[3],DimProcessing);
        //IMAGEPROC__en16bRGBScale_8bGrayScale(&MAIN_sSubLayerBG_Generic[1],&MAIN_sSubLayerBG_Generic[7],DimProcessing);
        //IMAGEPROC__en8bGrayScale_16bGrayScale(&MAIN_sSubLayerBG_Generic[7],&MAIN_sSubLayerBG_Generic[5],DimProcessing);
        IMAGEPROC__enGet16bRGBScaleHSI(&MAIN_sSubLayerBG_Generic[1],&MAIN_sSubLayerBG_Generic[19],DimProcessing);
        IMAGEPROC__enGetHSI16bRGBScale(&MAIN_sSubLayerBG_Generic[19],&MAIN_sSubLayerBG_Generic[3],DimProcessing);
        IMAGEPROC__en16bRGBScale_8bGrayScale(&MAIN_sSubLayerBG_Generic[1],&MAIN_sSubLayerBG_Generic[17],DimProcessing);
        IMAGEPROC__en8bSubtractionABS(&MAIN_sSubLayerBG_Generic[17],&MAIN_sSubLayerBG_Generic[16],&MAIN_sSubLayerBG_Generic[18],DimProcessing);
        IMAGEPROC__en8bGrayScale_16bGrayScale(&MAIN_sSubLayerBG_Generic[18],&MAIN_sSubLayerBG_Generic[11],DimProcessing);

        IMAGEPROC__en16bSubtraction(&MAIN_sSubLayerBG_Generic[13],&MAIN_sSubLayerBG_Generic[12],&MAIN_sSubLayerBG_Generic[14],DimProcessing2);
        LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[3]);
        //LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[3]);
        //LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[5]);
        LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[11]);
        LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[14]);
        LCDC__enLayerBG_RefreshSubLayer(1);
        GPIO0_OUT_DATA_R^=GPIO_R_P13_MASK;
    }
}

void MAIN_vInitInterrupt(void)
{
    INTC__vDspInit();
    INTC__enCpuIntRegisterRoutine(MASK_enINT7,TIMER2_vIsr);
    INTC__enEventMap2CpuInt(MASK_enINT7,EVENT_enT64P2_TINTALL);
    INTC__enCpuIntEnable(MASK_enINT7);

    INTC__enCpuIntRegisterRoutine(MASK_enINT8,GPIO0_vIsr);
    INTC__enEventMap2CpuInt(MASK_enINT8,EVENT_enGPIO_B0INT);
    INTC__enCpuIntEnable(MASK_enINT8);

    INTC__vIntGlobalEnable();
}

void MAIN_vInitTimer2(void)
{
    TIMER__vConfig(TIMER2,TIMER_CFG_en64BIT_NOCLOCK);
    TIMER__vDisable(TIMER2,TIMER_enTIMER12);
    SYSCFG0->CFGCHIP3_Bit.ASYNC3_CLKSRC=0;
    SYSCFG0->PINMUX_Bit[4].PINMUX_11_8=4;//GP1_5=timer 2 out12
    TIMER2->EMUMGT_Bit.FREE=0;
    TIMER__vConfig(TIMER2,TIMER_CFG_en32BIT_UNCHAINED_CLK_BOTH_INT);
    TIMER__vEnableInvertOUT(TIMER2,TIMER_enTIMER12);
    TIMER__vSetPulseWidth(TIMER2,TIMER_enTIMER12,TIMER_PULSE_en4_CLK);
    TIMER__vSetPulseMode(TIMER2,TIMER_enTIMER12);
    TIMER__vSetPeriod(TIMER2,TIMER_enTIMER12,64-1);
    TIMER__vSetCounter(TIMER2,TIMER_enTIMER12,0);
    TIMER__vEnableInterrupt(TIMER2,TIMER_INT_enTMR12_NON_CAPT_MODE);
    TIMER__vEnable(TIMER2,TIMER_enTIMER12,TIMER_MODE_enCONTINUOS);

}
void MAIN_vInitBaseSystem(void)
{

    PSC0__enEnableDsp();
    PSC__enInit();

    Cache__enEnable(MEMCFG1_en32K,MEMCFG1_en32K,MEMCFG2_en256K);

    Cache__vDisableMARL2(DDR2_DATA_NCache_START,DDR2_DATA_NCache_LENGHT);

    Cache__vEnableMARL2(DDR2_CODE_START,DDR2_CODE_LENGHT);
    Cache__vEnableMARL2(DDR2_CONSTANT_START,DDR2_CONSTANT_LENGHT);
    Cache__vEnableMARL2(DDR2_DATA_Stack_START,DDR2_DATA_Stack_LENGHT);
    Cache__vEnableMARL2(DDR2_DATA_Heap_START,DDR2_DATA_Heap_LENGHT);
    Cache__vEnableMARL2(DDR2_DATA_Heap_START,DDR2_DATA_Heap_LENGHT);
    Cache__vEnableMARL2(DDR2_DATA_Cache_START,DDR2_DATA_Cache_LENGHT);
    Cache__vEnableMARL2(SHRAM_START,SHRAM_LENGHT);
    Cache__vWbInvL1DAll();
    Cache__vInvL1PAll();
    Cache__vWbInvL2All();
}

void TIMER2_vIsr(void)
{
   INTC__enEventClear(EVENT_enT64P2_TINTALL);
   TIMER2->INTCTLSTAT_Bit.PRDINTSTAT12=1;
}

void GPIO0_vIsr(void)
{
    INTC__enEventClear(EVENT_enGPIO_B0INT);

    if(GPIO0_INTSTAT_R & GPIO_R_P0_MASK)
    {
        GPIO0_INTSTAT_R=GPIO_R_P0_MASK;
        u8State[0]++;

    }
    if(GPIO0_INTSTAT_R & GPIO_R_P1_MASK)
    {
        GPIO0_INTSTAT_R=GPIO_R_P1_MASK;
        u8State[1]++;

    }

}


