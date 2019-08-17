/*
 * OV5640.h
 *
 *  Created on: 06/08/2019
 *      Author: Lalo
 */

#ifndef APP_INCLUDE_OV5640_H_
#define APP_INCLUDE_OV5640_H_

#include <OV5640_Registers.h>
#include <Core.h>
#include <VPIF.h>
#include <I2C.h>
#include <SysTick.h>
#include <stdint.h>
#include <stdio.h>

#define OV5640_CHIPIDH          0X300A      //OV5640 ID high
#define OV5640_CHIPIDL          0X300B      //OV5640 ID low
#define OV5640_ID               0X5640      //OV5640

#define I2C_ADDR_OV5640      (0x3C) //7 bits

#define I2C_ADDR_BUSSW        (0x0073)
// i2c bus switch defines.
#define I2C_BUSSW_CH0EN       (0x01)
#define I2C_BUSSW_CH1EN       (0x02)ID



typedef enum
{
    OV5640_enOK = 0,
   OV5640_enERROR,
   OV5640_enTIMEOUT
} OV5640_nStatus;

typedef enum
{
    OV5640_FLASH_enON = 0,
   OV5640_FLASH_enOFF,
} OV5640_FLASH_nState;

typedef enum
{
    OV5640_EXPOSURE_enMINUS_3 = 0,
    OV5640_EXPOSURE_enMINUS_2 = 1,
    OV5640_EXPOSURE_enMINUS_1 = 2,
    OV5640_EXPOSURE_en0 = 3,
    OV5640_EXPOSURE_enPLUS_1 = 4,
    OV5640_EXPOSURE_enPLUS_2 = 5,
    OV5640_EXPOSURE_enPLUS_3 = 6,
} OV5640_EXPOSURE_nValue;

typedef enum
{
    OV5640_LIGHTMODE_enAUTO = 0,
    OV5640_LIGHTMODE_enSUNNY = 1,
    OV5640_LIGHTMODE_enOFFICE = 2,
    OV5640_LIGHTMODE_enCLOUDY = 3,
    OV5640_LIGHTMODE_enHOME = 4,
} OV5640_LIGHTMODE_nValue;

typedef enum
{
    OV5640_SATURATION_enMINUS_3 = 0,
    OV5640_SATURATION_enMINUS_2 = 1,
    OV5640_SATURATION_enMINUS_1 = 2,
    OV5640_SATURATION_en0 = 3,
    OV5640_SATURATION_enPLUS_1 = 4,
    OV5640_SATURATION_enPLUS_2 = 5,
    OV5640_SATURATION_enPLUS_3 = 6,
} OV5640_SATURATION_nValue;

typedef enum
{
    OV5640_BRIGHTNESS_enMINUS_4 = 0,
    OV5640_BRIGHTNESS_enMINUS_3 = 1,
    OV5640_BRIGHTNESS_enMINUS_2 = 2,
    OV5640_BRIGHTNESS_enMINUS_1 = 3,
    OV5640_BRIGHTNESS_en0 = 4,
    OV5640_BRIGHTNESS_enPLUS_1 = 5,
    OV5640_BRIGHTNESS_enPLUS_2 = 6,
    OV5640_BRIGHTNESS_enPLUS_3 = 7,
    OV5640_BRIGHTNESS_enPLUS_4 = 8,
} OV5640_BRIGHTNESS_nValue;

typedef enum
{
    OV5640_CONTRAST_enMINUS_3 = 0,
    OV5640_CONTRAST_enMINUS_2 = 1,
    OV5640_CONTRAST_enMINUS_1 = 2,
    OV5640_CONTRAST_en0 = 3,
    OV5640_CONTRAST_enPLUS_1 = 4,
    OV5640_CONTRAST_enPLUS_2 = 5,
    OV5640_CONTRAST_enPLUS_3 = 6,
} OV5640_CONTRAST_nValue;

typedef enum
{
    OV5640_SPECIALEFFECTS_enNORMAL = 0,
    OV5640_SPECIALEFFECTS_enCOLD = 1,
    OV5640_SPECIALEFFECTS_enWARM = 2,
    OV5640_SPECIALEFFECTS_enBLACKWHITE = 3,
    OV5640_SPECIALEFFECTS_enYELLOW = 4,
    OV5640_SPECIALEFFECTS_enINVERSE = 5,
    OV5640_SPECIALEFFECTS_enGREEN = 6,
} OV5640_SPECIALEFFECTS_nValue;

typedef enum
{
    OV5640_PATTERN_enNORMAL = 0,
    OV5640_PATTERN_enBAR = 1,
    OV5640_PATTERN_enBLOCK = 2,
} OV5640_PATTERN_nValue;




OV5640_nStatus OV5640__enReadRegister(uint16_t u16Register, uint8_t *pu8Value);
OV5640_nStatus OV5640__enWriteRegister(uint16_t u16Register,uint8_t u8Value);
OV5640_nStatus OV5640__enInit(void);
void OV5640__vCtrlFlash(OV5640_FLASH_nState enState);
void OV5640__vModeRGB565(void);
void OV5640__vSetExposure(OV5640_EXPOSURE_nValue enExposure);
void OV5640__vSetLightMode(OV5640_LIGHTMODE_nValue enLightMode);
void OV5640__vSetColorSaturation(OV5640_SATURATION_nValue enColorSaturation);
void OV5640__vSetBrightness(OV5640_BRIGHTNESS_nValue enBrightness);
void OV5640__vSetContrast(OV5640_CONTRAST_nValue enContrast);
void OV5640__vSetSharpness(uint8_t u8Sharpness);
void OV5640__vSetSpecialEffects(OV5640_SPECIALEFFECTS_nValue enSpecialEffects);
void OV5640__vTestPattern(OV5640_PATTERN_nValue enMode);
void OV5640__vSetOutSize(uint16_t u16OffsetX,uint16_t u16OffsetY,uint16_t u16Width,uint16_t u16Height);
void OV5640__vSetImageWindow(uint16_t u16OffsetX,uint16_t u16OffsetY,uint16_t u16Width,uint16_t u16Height);
OV5640_nStatus OV5640__enInitFocus(void);
OV5640_nStatus OV5640__enSingleFocus(void);
OV5640_nStatus OV5640__enContinueFocus(void);


#endif /* APP_INCLUDE_OV5640_H_ */
