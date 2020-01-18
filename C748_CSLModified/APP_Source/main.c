
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


#define MAIN_SUBLAYERMAX (40)
#pragma DATA_SECTION(MAIN_sLayerBGBuffer, ".MyData")
#pragma DATA_ALIGN(MAIN_sLayerBGBuffer, 8)
volatile uint16_t MAIN_sLayerBGBuffer[480][640];


#pragma DATA_SECTION(MAIN__u16CameraBuffer, ".MyData")
#pragma DATA_ALIGN(MAIN__u16CameraBuffer, 8)
volatile uint16_t MAIN__u16CameraBuffer[CAMERA_HEIGHT][CAMERA_WIDTH];

#pragma DATA_SECTION(MAIN__u16ProcessingBuffer, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__u16ProcessingBuffer, 8)//2^15
#pragma DATA_SECTION(MAIN__u16ProcessingBuffer1, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__u16ProcessingBuffer1, 8)
#pragma DATA_SECTION(MAIN__u16ProcessingBuffer2, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__u16ProcessingBuffer2, 8)
#pragma DATA_SECTION(MAIN__u16ProcessingBuffer3, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__u16ProcessingBuffer3, 8)
#pragma DATA_SECTION(MAIN__u8ProcessingBuffer4, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__u8ProcessingBuffer4, 8)
#pragma DATA_SECTION(MAIN__u16ProcessingBuffer5, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__u16ProcessingBuffer5, 8)
#pragma DATA_SECTION(MAIN__u16ProcessingBuffer6, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__u16ProcessingBuffer6, 8)
#pragma DATA_SECTION(MAIN__u16ProcessingBuffer7, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__u16ProcessingBuffer7, 8)
#pragma DATA_SECTION(MAIN__u16ProcessingBuffer8, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__u16ProcessingBuffer8, 8)
#pragma DATA_SECTION(MAIN__u16ProcessingBuffer9, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__u16ProcessingBuffer9, 8)
#pragma DATA_SECTION(MAIN__u8ProcessingBuffer8, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__u8ProcessingBuffer8, 8)
#pragma DATA_SECTION(MAIN__u8ProcessingBuffer9, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__u8ProcessingBuffer9, 8)
#pragma DATA_SECTION(MAIN__u8ProcessingBuffer10, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__u8ProcessingBuffer10, 8)
#pragma DATA_SECTION(MAIN__fProcessingBuffer11, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__fProcessingBuffer11, 8)
#pragma DATA_SECTION(MAIN__fProcessingBuffer12, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__fProcessingBuffer12, 8)
#pragma DATA_SECTION(MAIN__fProcessingBuffer13, ".MyBuffer")
#pragma DATA_ALIGN(MAIN__fProcessingBuffer13, 8)

float MAIN__fHist[256];
uint32_t MAIN__u32Hist[256];
volatile uint16_t MAIN__u16ProcessingBuffer[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint16_t MAIN__u16ProcessingBuffer1[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint16_t MAIN__u16ProcessingBuffer2[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint16_t MAIN__u16ProcessingBuffer3[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint8_t MAIN__u8ProcessingBuffer4[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint16_t MAIN__u16ProcessingBuffer5[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint16_t MAIN__u16ProcessingBuffer6[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint16_t MAIN__u16ProcessingBuffer7[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint16_t MAIN__u16ProcessingBuffer8[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint16_t MAIN__u16ProcessingBuffer9[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint8_t MAIN__u8ProcessingBuffer8[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint8_t MAIN__u8ProcessingBuffer9[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile uint8_t MAIN__u8ProcessingBuffer10[120][76];
volatile float MAIN__fProcessingBuffer11[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile float MAIN__fProcessingBuffer12[CAMERA_HEIGHT][CAMERA_WIDTH];
volatile float MAIN__fProcessingBuffer13[CAMERA_HEIGHT][CAMERA_WIDTH];


float fCountOld=0,fCountNew=0;
volatile float fValue=0;
uint8_t u8Count=0;

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

        640,480,640,480,  //tama�o del layer

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
char MAIN_cTime_String[60]="Time:";
char MAIN_cTime1_String[60]="Time:";
char MAIN_cTime2_String[60]="Time:";
uint8_t pu8ValueMemory[102];
uint8_t pu8ReadMemory[100];

uint32_t valuesDMA[100];

uint8_t u8State[2]={1,1};
OV5640_LIGHTMODE_nValue enLight=OV5640_LIGHTMODE_enAUTO;
OV5640_SPECIALEFFECTS_nValue enEffects=OV5640_SPECIALEFFECTS_enNORMAL;
LCDC_DIMENSIONS_TypeDef Dim,DimImage,DimProcessing,DimProcessing1,DimProcessing2;
LCDC_AREA_TypeDef sArea[100];
int main(void)
 {

    MAIN_vInitBaseSystem();
    MAIN_vInitInterrupt();
    SysTick__enInitUs(10);


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


    GPIO0_SET_DATA_R=GPIO_R_P13_MASK;
    SysTick__vDelayUs(5000);
    GPIO0_CLR_DATA_R=GPIO_R_P13_MASK;
    VPIF__vInitReceive((uint32_t)MAIN__u16CameraBuffer,CAMERA_WIDTH);

    LCDC__u8LayerBG_AddSubLayer(MAIN_psLayerBG);
    LCDC__vLayer_Clear(MAIN_psLayerBG,COLORS_enPURPLE);

    MAIN_sSubLayerBG_Generic[0].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[0].layerDataAddress=(uint32_t)&MAIN__u16CameraBuffer;
    MAIN_sSubLayerBG_Generic[0].layerXInit=0;
    MAIN_sSubLayerBG_Generic[0].layerYInit=0;
    MAIN_sSubLayerBG_Generic[0].layerBGXInit=5;
    MAIN_sSubLayerBG_Generic[0].layerBGYInit=5;
    MAIN_sSubLayerBG_Generic[0].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[0].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[0].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[0].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[0].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[0]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[0]);
    SysTick__vDelayUs(5000);

    MAIN_sSubLayerBG_Generic[2].layerType=LAYER_TYPE_enSTRING_SIMPLE;
    MAIN_sSubLayerBG_Generic[2].layerFont=&FONT_s16x24;
    MAIN_sSubLayerBG_Generic[2].layerColorFont=COLORS_enYELLOW;
    MAIN_sSubLayerBG_Generic[2].layerString="#InDeviceMex";
    MAIN_sSubLayerBG_Generic[2].layerBGXInit=(640-(12*MAIN_sSubLayerBG_Generic[2].layerFont->width))/2;
    MAIN_sSubLayerBG_Generic[2].layerBGYInit=420;
    MAIN_sSubLayerBG_Generic[2].layerWidth=12;
    MAIN_sSubLayerBG_Generic[2].layerHeight=1;
    MAIN_sLayerBG_Number[2]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[2]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[2]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[1].layerType=LAYER_TYPE_enSTRING_SIMPLE;
    MAIN_sSubLayerBG_Generic[1].layerFont=&FONT_s16x24;
    MAIN_sSubLayerBG_Generic[1].layerColorFont=COLORS_enYELLOW;
    MAIN_sSubLayerBG_Generic[1].layerString="Procesamiento Basico";
    MAIN_sSubLayerBG_Generic[1].layerBGXInit=(640-(20*MAIN_sSubLayerBG_Generic[1].layerFont->width))/2;
    MAIN_sSubLayerBG_Generic[1].layerBGYInit=383;
    MAIN_sSubLayerBG_Generic[1].layerWidth=20;
    MAIN_sSubLayerBG_Generic[1].layerHeight=1;
    MAIN_sLayerBG_Number[1]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[1]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[1]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[3].layerType=LAYER_TYPE_enSTRING_SIMPLE;
    MAIN_sSubLayerBG_Generic[3].layerFont=&FONT_s11x16;
    MAIN_sSubLayerBG_Generic[3].layerColorFont=COLORS_enYELLOW;
    MAIN_sSubLayerBG_Generic[3].layerString="Eduardo Alvarez Lopez";
    MAIN_sSubLayerBG_Generic[3].layerBGXInit=(640-(21*MAIN_sSubLayerBG_Generic[3].layerFont->width))/2;
    MAIN_sSubLayerBG_Generic[3].layerBGYInit=442;
    MAIN_sSubLayerBG_Generic[3].layerWidth=21;
    MAIN_sSubLayerBG_Generic[3].layerHeight=1;
    MAIN_sLayerBG_Number[3]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[3]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[3]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[4].layerType=LAYER_TYPE_enSTRING_SIMPLE;
    MAIN_sSubLayerBG_Generic[4].layerFont=&FONT_s8x16_MS_Gothic;
    MAIN_sSubLayerBG_Generic[4].layerColorFont=COLORS_enYELLOW;
    MAIN_sSubLayerBG_Generic[4].layerString="Procesamiento Digital de Imagenes";
    MAIN_sSubLayerBG_Generic[4].layerBGXInit=(640-(33*MAIN_sSubLayerBG_Generic[4].layerFont->width))/2;
    MAIN_sSubLayerBG_Generic[4].layerBGYInit=459;
    MAIN_sSubLayerBG_Generic[4].layerWidth=33;
    MAIN_sSubLayerBG_Generic[4].layerHeight=1;
    MAIN_sLayerBG_Number[4]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[4]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[4]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[5].layerType=LAYER_TYPE_enSTRING_SIMPLE;
    MAIN_sSubLayerBG_Generic[5].layerFont=&FONT_s8x16_MS_Gothic;
    MAIN_sSubLayerBG_Generic[5].layerColorFont=COLORS_enYELLOW;
    MAIN_sSubLayerBG_Generic[5].layerString="Peripheral:";
    MAIN_sSubLayerBG_Generic[5].layerBGXInit=10;
    MAIN_sSubLayerBG_Generic[5].layerBGYInit=400;
    MAIN_sSubLayerBG_Generic[5].layerWidth=11;
    MAIN_sSubLayerBG_Generic[5].layerHeight=1;
    MAIN_sLayerBG_Number[5]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[5]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[5]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[6].layerType=LAYER_TYPE_enSTRING_SIMPLE;
    MAIN_sSubLayerBG_Generic[6].layerFont=&FONT_s8x8;
    MAIN_sSubLayerBG_Generic[6].layerColorFont=COLORS_enYELLOW;
    MAIN_sSubLayerBG_Generic[6].layerString="CPU: 400 MHz\n\r\n\rDDR2: 300 MHz\n\r\n\rVPIF\n\r\n\rLTDC: 640x480";
    MAIN_sSubLayerBG_Generic[6].layerBGXInit=20;
    MAIN_sSubLayerBG_Generic[6].layerBGYInit=420;
    MAIN_sSubLayerBG_Generic[6].layerWidth=15;
    MAIN_sSubLayerBG_Generic[6].layerHeight=6;
    MAIN_sLayerBG_Number[6]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[6]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[6]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[7].layerType=LAYER_TYPE_enSTRING_SIMPLE;
    MAIN_sSubLayerBG_Generic[7].layerFont=&FONT_s8x16_MS_Gothic;
    MAIN_sSubLayerBG_Generic[7].layerColorFont=COLORS_enYELLOW;
    MAIN_sSubLayerBG_Generic[7].layerString="Hardware: RK6748";
    MAIN_sSubLayerBG_Generic[7].layerBGXInit=470;
    MAIN_sSubLayerBG_Generic[7].layerBGYInit=410;
    MAIN_sSubLayerBG_Generic[7].layerWidth=16;
    MAIN_sSubLayerBG_Generic[7].layerHeight=1;
    MAIN_sLayerBG_Number[7]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[7]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[7]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[8].layerType=LAYER_TYPE_enSTRING_SIMPLE;
    MAIN_sSubLayerBG_Generic[8].layerFont=&FONT_s8x8;
    MAIN_sSubLayerBG_Generic[8].layerColorFont=COLORS_enYELLOW;
    MAIN_sSubLayerBG_Generic[8].layerString="TMS320C6748 DSP TI\n\r\n\rOV9655\n\r\n\rAT056TN53 5.6\"";
    MAIN_sSubLayerBG_Generic[8].layerBGXInit=480;
    MAIN_sSubLayerBG_Generic[8].layerBGYInit=430;
    MAIN_sSubLayerBG_Generic[8].layerWidth=19;
    MAIN_sSubLayerBG_Generic[8].layerHeight=5;
    MAIN_sLayerBG_Number[8]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[8]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[8]);
    LCDC__enLayerBG_RefreshSubLayer(1);

/*
    MAIN_sSubLayerBG_Generic[9].layerType=LAYER_TYPE_enSTRING_SIMPLE_BACKGROUND;
    MAIN_sSubLayerBG_Generic[9].layerFont=&FONT_s8x8;
    MAIN_sSubLayerBG_Generic[9].layerColorFont=COLORS_enYELLOW;
    MAIN_sSubLayerBG_Generic[9].layerColorBG=COLORS_enPURPLE;
    MAIN_sSubLayerBG_Generic[9].layerString=MAIN_cTime_String;
    MAIN_sSubLayerBG_Generic[9].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[9].layerBGYInit=150;
    MAIN_sSubLayerBG_Generic[9].layerWidth=23;
    MAIN_sSubLayerBG_Generic[9].layerHeight=1;
    MAIN_sLayerBG_Number[9]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[9]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[9]);
    LCDC__enLayerBG_RefreshSubLayer(1);
*/

    MAIN_sSubLayerBG_Generic[10].layerType=LAYER_TYPE_enRECTANGLE_FILL;
    MAIN_sSubLayerBG_Generic[10].layerColorBG=COLORS_enORANGE;
    MAIN_sSubLayerBG_Generic[10].layerBGXInit=0;
    MAIN_sSubLayerBG_Generic[10].layerBGYInit=0;
    MAIN_sSubLayerBG_Generic[10].layerWidth=640;
    MAIN_sSubLayerBG_Generic[10].layerHeight=130;
    MAIN_sLayerBG_Number[10]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[10]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[10]);
    LCDC__enLayerBG_RefreshSubLayer(1);



    MAIN_sSubLayerBG_Generic[11].layerType=LAYER_TYPE_enSTRING_SIMPLE_BACKGROUND;
    MAIN_sSubLayerBG_Generic[11].layerFont=&FONT_s8x8;
    MAIN_sSubLayerBG_Generic[11].layerColorFont=COLORS_enYELLOW;
    MAIN_sSubLayerBG_Generic[11].layerColorBG=COLORS_enPURPLE;
    MAIN_sSubLayerBG_Generic[11].layerString="[Image Cam]";
    MAIN_sSubLayerBG_Generic[11].layerBGXInit=(130-(11*MAIN_sSubLayerBG_Generic[11].layerFont->width))/2;
    MAIN_sSubLayerBG_Generic[11].layerBGYInit=132;
    MAIN_sSubLayerBG_Generic[11].layerWidth=15;
    MAIN_sSubLayerBG_Generic[11].layerHeight=1;
    MAIN_sLayerBG_Number[11]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[11]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[11]);
    LCDC__enLayerBG_RefreshSubLayer(1);


    MAIN_sSubLayerBG_Generic[11].layerString="[White Patch]";
    MAIN_sSubLayerBG_Generic[11].layerBGXInit=125+((130)-(13*MAIN_sSubLayerBG_Generic[11].layerFont->width))/2;
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[11]);
    LCDC__enLayerBG_RefreshSubLayer(1);
    MAIN_sSubLayerBG_Generic[11].layerString="[GrayWorld]";
    MAIN_sSubLayerBG_Generic[11].layerBGXInit=125*2+((130)-(11*MAIN_sSubLayerBG_Generic[11].layerFont->width))/2;
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[11]);
    LCDC__enLayerBG_RefreshSubLayer(1);
    MAIN_sSubLayerBG_Generic[11].layerString="[GrayWld Max]";
    MAIN_sSubLayerBG_Generic[11].layerBGXInit=125*3+((130)-(13*MAIN_sSubLayerBG_Generic[11].layerFont->width))/2;
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[11]);
    LCDC__enLayerBG_RefreshSubLayer(1);
    MAIN_sSubLayerBG_Generic[11].layerString="[GrayWld Sqr]";
    MAIN_sSubLayerBG_Generic[11].layerBGXInit=125*4+((130)-(13*MAIN_sSubLayerBG_Generic[11].layerFont->width))/2;
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[11]);
    LCDC__enLayerBG_RefreshSubLayer(1);




    MAIN_sSubLayerBG_Generic[12].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[12].layerDataAddress=(uint32_t)&MAIN__u16ProcessingBuffer3;//;&gImage_del;
    MAIN_sSubLayerBG_Generic[12].layerXInit=0;
    MAIN_sSubLayerBG_Generic[12].layerYInit=0;
    MAIN_sSubLayerBG_Generic[12].layerBGXInit=120+5+5;
    MAIN_sSubLayerBG_Generic[12].layerBGYInit=5;
    MAIN_sSubLayerBG_Generic[12].layerWidthTotal=120;
    MAIN_sSubLayerBG_Generic[12].layerHeightTotal=120;
    MAIN_sSubLayerBG_Generic[12].layerWidth=120;
    MAIN_sSubLayerBG_Generic[12].layerHeight=120;
    MAIN_sSubLayerBG_Generic[12].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[12]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[12]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[12]);
    LCDC__enLayerBG_RefreshSubLayer(1);


    MAIN_sSubLayerBG_Generic[13].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[13].layerDataAddress=(uint32_t)&MAIN__u16ProcessingBuffer5;
    MAIN_sSubLayerBG_Generic[13].layerXInit=0;
    MAIN_sSubLayerBG_Generic[13].layerYInit=0;
    MAIN_sSubLayerBG_Generic[13].layerBGXInit=120+5+5+120+5;
    MAIN_sSubLayerBG_Generic[13].layerBGYInit=5;
    MAIN_sSubLayerBG_Generic[13].layerWidthTotal=120;
    MAIN_sSubLayerBG_Generic[13].layerHeightTotal=120;
    MAIN_sSubLayerBG_Generic[13].layerWidth=120;
    MAIN_sSubLayerBG_Generic[13].layerHeight=120;
    MAIN_sSubLayerBG_Generic[13].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[13]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[13]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[13]);
    LCDC__enLayerBG_RefreshSubLayer(1);


    MAIN_sSubLayerBG_Generic[14].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[14].layerDataAddress=(uint32_t)&MAIN__u16ProcessingBuffer6;
    MAIN_sSubLayerBG_Generic[14].layerXInit=0;
    MAIN_sSubLayerBG_Generic[14].layerYInit=0;
    MAIN_sSubLayerBG_Generic[14].layerBGXInit=120+5+5+120+5+120+5;
    MAIN_sSubLayerBG_Generic[14].layerBGYInit=5;
    MAIN_sSubLayerBG_Generic[14].layerWidthTotal=120;
    MAIN_sSubLayerBG_Generic[14].layerHeightTotal=120;
    MAIN_sSubLayerBG_Generic[14].layerWidth=120;
    MAIN_sSubLayerBG_Generic[14].layerHeight=120;
    MAIN_sSubLayerBG_Generic[14].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[14]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[14]);

    MAIN_sSubLayerBG_Generic[15].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[15].layerDataAddress=(uint32_t)&MAIN__u16ProcessingBuffer7;
    MAIN_sSubLayerBG_Generic[15].layerXInit=0;
    MAIN_sSubLayerBG_Generic[15].layerYInit=0;
    MAIN_sSubLayerBG_Generic[15].layerBGXInit=120+5+5+120+5+120+5+120+5;
    MAIN_sSubLayerBG_Generic[15].layerBGYInit=5;
    MAIN_sSubLayerBG_Generic[15].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[15].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[15].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[15].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[15].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[15]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[15]);

    MAIN_sSubLayerBG_Generic[16].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[16].layerDataAddress=(uint32_t)&gImage_manos240x240;
    MAIN_sSubLayerBG_Generic[16].layerXInit=0;
    MAIN_sSubLayerBG_Generic[16].layerYInit=0;
    MAIN_sSubLayerBG_Generic[16].layerBGXInit=5;
    MAIN_sSubLayerBG_Generic[16].layerBGYInit=150;
    MAIN_sSubLayerBG_Generic[16].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[16].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[16].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[16].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[16].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[16]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[16]);
/*
    MAIN_sSubLayerBG_Generic[16].layerType=LAYER_TYPE_enSTRING_SIMPLE_BACKGROUND;
    MAIN_sSubLayerBG_Generic[16].layerFont=&FONT_s8x8;
    MAIN_sSubLayerBG_Generic[16].layerColorFont=COLORS_enYELLOW;
    MAIN_sSubLayerBG_Generic[16].layerColorBG=COLORS_enPURPLE;
    MAIN_sSubLayerBG_Generic[16].layerString=MAIN_cTime1_String;
    MAIN_sSubLayerBG_Generic[16].layerBGXInit=360+20;
    MAIN_sSubLayerBG_Generic[16].layerBGYInit=150;
    MAIN_sSubLayerBG_Generic[16].layerWidth=15;
    MAIN_sSubLayerBG_Generic[16].layerHeight=1;
    MAIN_sLayerBG_Number[16]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[16]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[16]);
    LCDC__enLayerBG_RefreshSubLayer(1);
*/
    MAIN_sSubLayerBG_Generic[17].layerType=LAYER_TYPE_enSTRING_SIMPLE_BACKGROUND;
    MAIN_sSubLayerBG_Generic[17].layerFont=&FONT_s8x8;
    MAIN_sSubLayerBG_Generic[17].layerColorFont=COLORS_enYELLOW;
    MAIN_sSubLayerBG_Generic[17].layerColorBG=COLORS_enPURPLE;
    MAIN_sSubLayerBG_Generic[17].layerString=MAIN_cTime2_String;
    MAIN_sSubLayerBG_Generic[17].layerBGXInit=480+25;
    MAIN_sSubLayerBG_Generic[17].layerBGYInit=150;
    MAIN_sSubLayerBG_Generic[17].layerWidth=15;
    MAIN_sSubLayerBG_Generic[17].layerHeight=1;
    MAIN_sLayerBG_Number[17]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[17]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[17]);
    LCDC__enLayerBG_RefreshSubLayer(1);

    MAIN_sSubLayerBG_Generic[18].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[18].layerDataAddress=(uint32_t)&MAIN__u16ProcessingBuffer1;
    MAIN_sSubLayerBG_Generic[18].layerXInit=0;
    MAIN_sSubLayerBG_Generic[18].layerYInit=0;
    MAIN_sSubLayerBG_Generic[18].layerBGXInit=120+5+5;
    MAIN_sSubLayerBG_Generic[18].layerBGYInit=150;
    MAIN_sSubLayerBG_Generic[18].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[18].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[18].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[18].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[18].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[18]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[18]);

    MAIN_sSubLayerBG_Generic[19].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[19].layerDataAddress=(uint32_t)&MAIN__u16ProcessingBuffer2;
    MAIN_sSubLayerBG_Generic[19].layerXInit=0;
    MAIN_sSubLayerBG_Generic[19].layerYInit=0;
    MAIN_sSubLayerBG_Generic[19].layerBGXInit=120+5+5+120+5;
    MAIN_sSubLayerBG_Generic[19].layerBGYInit=150;
    MAIN_sSubLayerBG_Generic[19].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[19].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[19].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[19].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[19].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[19]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[19]);

    MAIN_sSubLayerBG_Generic[20].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[20].layerDataAddress=(uint32_t)&gImage_cabeza120x120;
    MAIN_sSubLayerBG_Generic[20].layerXInit=0;
    MAIN_sSubLayerBG_Generic[20].layerYInit=0;
    MAIN_sSubLayerBG_Generic[20].layerBGXInit=120+5+5+120+5+120+5;
    MAIN_sSubLayerBG_Generic[20].layerBGYInit=150;
    MAIN_sSubLayerBG_Generic[20].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[20].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[20].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[20].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[20].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[20]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[20]);

    MAIN_sSubLayerBG_Generic[21].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[21].layerDataAddress=(uint32_t)&MAIN__u16ProcessingBuffer9;
    MAIN_sSubLayerBG_Generic[21].layerXInit=0;
    MAIN_sSubLayerBG_Generic[21].layerYInit=0;
    MAIN_sSubLayerBG_Generic[21].layerBGXInit=120+5+5+120+5+120+5+120+5;
    MAIN_sSubLayerBG_Generic[21].layerBGYInit=150;
    MAIN_sSubLayerBG_Generic[21].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[21].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[21].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[21].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[21].variableType=VARIABLETYPE_enUSHORT;
    MAIN_sLayerBG_Number[21]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[21]);

    MAIN_sSubLayerBG_Generic[22].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[22].layerDataAddress=(uint32_t)&MAIN__u8ProcessingBuffer8;
    MAIN_sSubLayerBG_Generic[22].layerXInit=0;
    MAIN_sSubLayerBG_Generic[22].layerYInit=0;
    MAIN_sSubLayerBG_Generic[22].layerBGXInit=120+5+5+120+5+120+5+120+5;
    MAIN_sSubLayerBG_Generic[22].layerBGYInit=150;
    MAIN_sSubLayerBG_Generic[22].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[22].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[22].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[22].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[22].variableType=VARIABLETYPE_enUCHAR;
    MAIN_sLayerBG_Number[22]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[22]);

    MAIN_sSubLayerBG_Generic[23].layerType=LAYER_TYPE_enIMAGE_NOHEADER;
    MAIN_sSubLayerBG_Generic[23].layerDataAddress=(uint32_t)&MAIN__u8ProcessingBuffer9;
    MAIN_sSubLayerBG_Generic[23].layerXInit=0;
    MAIN_sSubLayerBG_Generic[23].layerYInit=0;
    MAIN_sSubLayerBG_Generic[23].layerBGXInit=120+5+5+120+5+120+5+120+5;
    MAIN_sSubLayerBG_Generic[23].layerBGYInit=150;
    MAIN_sSubLayerBG_Generic[23].layerWidthTotal=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[23].layerHeightTotal=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[23].layerWidth=CAMERA_WIDTH;
    MAIN_sSubLayerBG_Generic[23].layerHeight=CAMERA_HEIGHT;
    MAIN_sSubLayerBG_Generic[23].variableType=VARIABLETYPE_enUCHAR;
    MAIN_sLayerBG_Number[23]=LCDC__u8Layer_AddSubLayer(MAIN_psLayerBG,&MAIN_sSubLayerBG_Generic[23]);




    DimProcessing.X[0]=0;
    DimProcessing.X[1]=0;
    DimProcessing.Y[0]=0;
    DimProcessing.Y[1]=0;
    DimProcessing.width=CAMERA_WIDTH;
    DimProcessing.height=CAMERA_HEIGHT;

    DimProcessing1.X[0]=0;
    DimProcessing1.X[1]=0;
    DimProcessing1.Y[0]=0;
    DimProcessing1.Y[1]=0;
    DimProcessing1.width=CAMERA_WIDTH;
    DimProcessing1.height=CAMERA_HEIGHT;



    IMAGEPROC__en16bRGBScale_8bGrayScale(&MAIN_sSubLayerBG_Generic[20],&MAIN_sSubLayerBG_Generic[22],DimProcessing);

    IMAGEPROC__enLBPU(&MAIN_sSubLayerBG_Generic[22],&MAIN_sSubLayerBG_Generic[23],DimProcessing);
    IMAGEPROC__en8bHistogramNorm(&MAIN_sSubLayerBG_Generic[23],DimProcessing,MAIN__fHist,255);

    IMAGEPROC__en8bGrayScale_16bGrayScale(&MAIN_sSubLayerBG_Generic[23],&MAIN_sSubLayerBG_Generic[21],DimProcessing);




    DimProcessing2.X[0]=0;
    DimProcessing2.X[1]=0;
    DimProcessing2.X[2]=0;
    DimProcessing2.Y[0]=0;
    DimProcessing2.Y[1]=0;
    DimProcessing2.Y[2]=0;
    DimProcessing2.width=120;
    DimProcessing2.height=176;

    LCDC__vBackLight(BACKLIGHT_enON);
    DimProcessing1.Y[0]=0;
    DimProcessing1.Y[1]=0;
    DimProcessing1.width=CAMERA_WIDTH;
    DimProcessing1.height=40;

    IMAGEPROC__en16bWhitePatch(&MAIN_sSubLayerBG_Generic[16],&MAIN_sSubLayerBG_Generic[18],DimProcessing1);
    IMAGEPROC__en16bUmbral(&MAIN_sSubLayerBG_Generic[18],&MAIN_sSubLayerBG_Generic[18],DimProcessing1,0x7204,0xE,0x14,0xb);
    IMAGEPROC__en16bGrayWorld(&MAIN_sSubLayerBG_Generic[16],&MAIN_sSubLayerBG_Generic[19],DimProcessing1);
    IMAGEPROC__en16bUmbral(&MAIN_sSubLayerBG_Generic[19],&MAIN_sSubLayerBG_Generic[19],DimProcessing1,0x7204,0xE,0x14,0xb);

    DimProcessing1.Y[0]=40;
    DimProcessing1.Y[1]=40;
    DimProcessing1.width=CAMERA_WIDTH;
    DimProcessing1.height=39;

    IMAGEPROC__en16bWhitePatch(&MAIN_sSubLayerBG_Generic[16],&MAIN_sSubLayerBG_Generic[18],DimProcessing1);
    IMAGEPROC__en16bUmbral(&MAIN_sSubLayerBG_Generic[18],&MAIN_sSubLayerBG_Generic[18],DimProcessing1,0x7204,0xE,0x14,0xb);
    IMAGEPROC__en16bGrayWorld(&MAIN_sSubLayerBG_Generic[16],&MAIN_sSubLayerBG_Generic[19],DimProcessing1);
    IMAGEPROC__en16bUmbral(&MAIN_sSubLayerBG_Generic[19],&MAIN_sSubLayerBG_Generic[19],DimProcessing1,0x7204,0xE,0x14,0xb);

    DimProcessing1.Y[0]=80;
    DimProcessing1.Y[1]=80;
    DimProcessing1.width=CAMERA_WIDTH;
    DimProcessing1.height=39;

    IMAGEPROC__en16bWhitePatch(&MAIN_sSubLayerBG_Generic[16],&MAIN_sSubLayerBG_Generic[18],DimProcessing1);
    IMAGEPROC__en16bUmbral(&MAIN_sSubLayerBG_Generic[18],&MAIN_sSubLayerBG_Generic[18],DimProcessing1,0x7204,0xE,0x14,0xb);
    IMAGEPROC__en16bGrayWorld(&MAIN_sSubLayerBG_Generic[16],&MAIN_sSubLayerBG_Generic[19],DimProcessing1);
    IMAGEPROC__en16bUmbral(&MAIN_sSubLayerBG_Generic[19],&MAIN_sSubLayerBG_Generic[19],DimProcessing1,0x7204,0xE,0x14,0xb);

    valuesDMA[1]=IMAGEPROC__en16bConectivity8(&MAIN_sSubLayerBG_Generic[18],&MAIN_sSubLayerBG_Generic[18],DimProcessing,sArea,&valuesDMA[0]);
    valuesDMA[0]/=2;
    for(u8State[0]=0;u8State[0]<valuesDMA[1];u8State[0]++)
    {
        if(sArea[u8State[0]].area>valuesDMA[0])
        {
            Dim.XInit=sArea[u8State[0]].Xmin;
            Dim.YInit=sArea[u8State[0]].Ymin;
            Dim.width=sArea[u8State[0]].Xmax-sArea[u8State[0]].Xmin;
            Dim.height=sArea[u8State[0]].Ymax-sArea[u8State[0]].Ymin;
            LCDC__vLayer_Print_Rectangle(&MAIN_sSubLayerBG_Generic[18],Dim,0xf800);
        }
    }
    valuesDMA[3]=IMAGEPROC__en16bConectivity8(&MAIN_sSubLayerBG_Generic[19],&MAIN_sSubLayerBG_Generic[19],DimProcessing,sArea,&valuesDMA[2]);
    valuesDMA[2]/=2;
    for(u8State[0]=0;u8State[0]<valuesDMA[3];u8State[0]++)
    {
        if(sArea[u8State[0]].area>valuesDMA[2])
        {
            Dim.XInit=sArea[u8State[0]].Xmin;
            Dim.YInit=sArea[u8State[0]].Ymin;
            Dim.width=sArea[u8State[0]].Xmax-sArea[u8State[0]].Xmin;
            Dim.height=sArea[u8State[0]].Ymax-sArea[u8State[0]].Ymin;
            LCDC__vLayer_Print_Rectangle(&MAIN_sSubLayerBG_Generic[19],Dim,0xf800);
        }
    }

    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[18]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[19]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[20]);
    LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[21]);
    while(1)
    {

        IMAGEPROC__en16bWhitePatch(&MAIN_sSubLayerBG_Generic[0],&MAIN_sSubLayerBG_Generic[13],DimProcessing);
        IMAGEPROC__en16bRGBScale_8bGrayScale(&MAIN_sSubLayerBG_Generic[13],&MAIN_sSubLayerBG_Generic[22],DimProcessing);


        fCountOld=SysTick__fGetTimeUs();
        GPIO0_SET_DATA_R=GPIO_R_P13_MASK;
        IMAGEPROC__enLBPU(&MAIN_sSubLayerBG_Generic[22],&MAIN_sSubLayerBG_Generic[23],DimProcessing);
        IMAGEPROC__en8bHistogramNorm(&MAIN_sSubLayerBG_Generic[23],DimProcessing,MAIN__fHist,255);
        IMAGEPROC__en8bGrayScale_16bGrayScale(&MAIN_sSubLayerBG_Generic[23],&MAIN_sSubLayerBG_Generic[12],DimProcessing);
        GPIO0_CLR_DATA_R=GPIO_R_P13_MASK;
        fCountNew=SysTick__fGetTimeUs();



        IMAGEPROC__en16bWhitePatch(&MAIN_sSubLayerBG_Generic[0],&MAIN_sSubLayerBG_Generic[13],DimProcessing);
        IMAGEPROC__en16bUmbral(&MAIN_sSubLayerBG_Generic[13],&MAIN_sSubLayerBG_Generic[13],DimProcessing,0x7204,0xE,0x14,0xb);
        IMAGEPROC__en16bGrayWorld(&MAIN_sSubLayerBG_Generic[0],&MAIN_sSubLayerBG_Generic[14],DimProcessing);
        IMAGEPROC__en16bUmbral(&MAIN_sSubLayerBG_Generic[14],&MAIN_sSubLayerBG_Generic[14],DimProcessing,0x7204,0xE,0x14,0xb);



        valuesDMA[9]=IMAGEPROC__en16bConectivity8(&MAIN_sSubLayerBG_Generic[13],&MAIN_sSubLayerBG_Generic[13],DimProcessing,sArea,&valuesDMA[8]);
        valuesDMA[11]=IMAGEPROC__en16bConectivity8(&MAIN_sSubLayerBG_Generic[14],&MAIN_sSubLayerBG_Generic[14],DimProcessing,sArea,&valuesDMA[10]);
        valuesDMA[13]=IMAGEPROC__en16bConectivity8(&MAIN_sSubLayerBG_Generic[15],&MAIN_sSubLayerBG_Generic[15],DimProcessing,sArea,&valuesDMA[12]);

        u8Count++;
        if((u8Count%30)==0)
        {
            u8Count=0;
            LTDC__u64Layer_Printf("%f",&MAIN_cTime2_String[5],(double)(fCountNew-fCountOld));
            LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[17]);
            SysTick__vRestart();
        }
        LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[12]);
        LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[13]);
        LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[14]);
        LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[16]);
        LCDC__enLayer_RefreshSubLayer(MAIN_psLayerBG,MAIN_sLayerBG_Number[0]);
        LCDC__enLayerBG_RefreshSubLayer(1);

    }
}


/*      fCountNew=SysTick__fGetTimeUs();
  if(u8State[0]>0)
  {
      LCDC__enLayer_Copy(&MAIN_sSubLayerBG_Generic[0],&MAIN_sSubLayerBG_Generic[15],DimProcessing);
      IMAGEPROC__en16bRGBScale_8bGrayScale(&MAIN_sSubLayerBG_Generic[15],&MAIN_sSubLayerBG_Generic[16],DimProcessing);
      u8State[0]=0;
  }
  */
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

