/*
 * OV5640.c
 *
 *  Created on: 06/08/2019
 *      Author: Lalo
 */

#include <OV5640.h>


__inline OV5640_nStatus OV5640__enReadRegister(uint16_t u16Register, uint8_t *pu8Value)
{
    OV5640_nStatus enReturn;
    uint8_t u8Data[3];

    u8Data[0] = (uint8_t)((u16Register & 0xFF00) >> 8);
    u8Data[1] = (uint8_t)(u16Register & 0x00FF);

   // write the register address that we want to read.
    enReturn = (OV5640_nStatus)I2C_enMasterSendData(I2C0, I2C_ADDR_OV5640, 2,u8Data);
   if (enReturn != OV5640_enOK)
      return (enReturn);
   SysTick__vDelayUs(100);
   // write the register address that we want to read.
    enReturn = (OV5640_nStatus)I2C_enMasterReadData(I2C0, I2C_ADDR_OV5640,1, &u8Data[2]);
   if (enReturn != OV5640_enOK)
      return (enReturn);
   *pu8Value = u8Data[2];
   SysTick__vDelayUs(100);

   return (OV5640_nStatus)(enReturn);
}
__inline OV5640_nStatus OV5640__enWriteRegister(uint16_t u16Register,uint8_t u8Value)
{
    OV5640_nStatus enReturn;
    uint8_t  u8Data[3];

    u8Data[0] = (uint8_t)((u16Register & 0xFF00) >> 8);
    u8Data[1] = (uint8_t)(u16Register & 0x00FF);
    u8Data[2] = u8Value;

    // write the register that we want to read.
    enReturn = (OV5640_nStatus)I2C_enMasterSendData(I2C0, I2C_ADDR_OV5640,3,u8Data);

    SysTick__vDelayUs(10);
    return (OV5640_nStatus)(enReturn);
}

OV5640_nStatus OV5640__enInit(void)
{
    uint16_t i=0;
    uint16_t u16Register;
    uint8_t u8Reg;

    SYSCFG0->PINMUX_Bit[13].PINMUX_31_28=8;//GP6_8
    SYSCFG0->PINMUX_Bit[13].PINMUX_23_20=8;//GP6_10
    GPIO6->DIR_Bit.P8=0; //RST
    GPIO6->DIR_Bit.P10=0; //POWER
    GPIO6->SET_DATA_Bit.P8=0;//El pin RST del OV5640 debe estar bajo antes de encenderlo.
    SysTick__vDelayUs(5000);
    GPIO6->SET_DATA_Bit.P10=0;
    SysTick__vDelayUs(5000);
    GPIO6->SET_DATA_Bit.P8=1;
    SysTick__vDelayUs(5000);


    I2C__enInit(I2C0, I2C_CLOCK_en100K);

    OV5640__enReadRegister(OV5640_CHIPIDH,&u8Reg);  //Leer ID alta ocho
    u16Register=(uint16_t)u8Reg<<8;
    OV5640__enReadRegister(OV5640_CHIPIDL,&u8Reg); //Leer ID bja ocho
    u16Register|=u8Reg;
    //printf("ID:0x%04X\r\n",u16Register);

    //reg write test
    /*
    reg=OV5640_RD_Reg(0x3c01);
    printf("ID:0x%02X\r\n",reg);
    OV5640__enWriteRegister(0x3c01,0X34); //system clock from pad, bit[1]
    reg=OV5640_RD_Reg(0x3c01);
    printf("ID:0x%02X\r\n",reg);
    */

    //SysTick__vDelayUs(5000);
    OV5640__enWriteRegister(0x3103,0X11); //system clock from pad, bit[1]
    OV5640__enWriteRegister(0X3008,0X82); //Restablecimiento parcial
    //Inicializar OV5640
    for(i=0;i<sizeof(OV5640_u16RegistersInit)/4;i++)
    {
        OV5640__enWriteRegister(OV5640_u16RegistersInit[i][0],OV5640_u16RegistersInit[i][1]);
    }
    //Compruebe si el flash es normal
    //OV5640__vCtrlFlash(OV5640_FLASH_enON);
    //SysTick__vDelayUs(50000);
    //OV5640__vCtrlFlash(OV5640_FLASH_enOFF);
    return OV5640_enOK;

}


void OV5640__vCtrlFlash(OV5640_FLASH_nState enState)
{
    OV5640__enWriteRegister(0x3016,0X02);
    OV5640__enWriteRegister(0x301C,0X02);
    switch(enState)
    {
    case OV5640_FLASH_enON:
        OV5640__enWriteRegister(0X3019,0X02);
    case OV5640_FLASH_enOFF:
        OV5640__enWriteRegister(0X3019,0X00);
    default:
        break;
    }
}
//OV5640 cambia al modo RGB565
void OV5640__vModeRGB565(void)
{
    uint16_t i=0;
    for(i=0;i<(sizeof(OV5640_u16RegistersRGB565)/4);i++)
    {
        OV5640__enWriteRegister(OV5640_u16RegistersRGB565[i][0],OV5640_u16RegistersRGB565[i][1]);
    }
}

void OV5640__vSetExposure(OV5640_EXPOSURE_nValue enExposure)
{
    OV5640__enWriteRegister(0x3212,0x03); //start group 3
    OV5640__enWriteRegister(0x3a0f,OV5640_u8ValueEXPOSURE[(uint8_t)enExposure][0]);
    OV5640__enWriteRegister(0x3a10,OV5640_u8ValueEXPOSURE[(uint8_t)enExposure][1]);
    OV5640__enWriteRegister(0x3a1b,OV5640_u8ValueEXPOSURE[(uint8_t)enExposure][2]);
    OV5640__enWriteRegister(0x3a1e,OV5640_u8ValueEXPOSURE[(uint8_t)enExposure][3]);
    OV5640__enWriteRegister(0x3a11,OV5640_u8ValueEXPOSURE[(uint8_t)enExposure][4]);
    OV5640__enWriteRegister(0x3a1f,OV5640_u8ValueEXPOSURE[(uint8_t)enExposure][5]);
    OV5640__enWriteRegister(0x3212,0x13); //end group 3
    OV5640__enWriteRegister(0x3212,0xa3); //launch group 3
}

void OV5640__vSetLightMode(OV5640_LIGHTMODE_nValue enLightMode)
{
    OV5640__enWriteRegister(0x3212,0x03); //start group 3
    OV5640__enWriteRegister(0x3400,OV5640_u8ModeLIGHT[(uint8_t)enLightMode][0]);
    OV5640__enWriteRegister(0x3401,OV5640_u8ModeLIGHT[(uint8_t)enLightMode][1]);
    OV5640__enWriteRegister(0x3402,OV5640_u8ModeLIGHT[(uint8_t)enLightMode][2]);
    OV5640__enWriteRegister(0x3403,OV5640_u8ModeLIGHT[(uint8_t)enLightMode][3]);
    OV5640__enWriteRegister(0x3404,OV5640_u8ModeLIGHT[(uint8_t)enLightMode][4]);
    OV5640__enWriteRegister(0x3405,OV5640_u8ModeLIGHT[(uint8_t)enLightMode][5]);
    OV5640__enWriteRegister(0x3406,OV5640_u8ModeLIGHT[(uint8_t)enLightMode][6]);
    OV5640__enWriteRegister(0x3212,0x13); //end group 3
    OV5640__enWriteRegister(0x3212,0xa3); //launch group 3
}

void OV5640__vSetColorSaturation(OV5640_SATURATION_nValue enColorSaturation)
{
    uint8_t i;
    OV5640__enWriteRegister(0x3212,0x03); //start group 3
    OV5640__enWriteRegister(0x5381,0x1c);
    OV5640__enWriteRegister(0x5382,0x5a);
    OV5640__enWriteRegister(0x5383,0x06);
    for(i=0;i<6;i++)
        OV5640__enWriteRegister(0x5384+i,OV5640_u8ValueSATURATION[(uint8_t)enColorSaturation][i]);
    OV5640__enWriteRegister(0x538b, 0x98);
    OV5640__enWriteRegister(0x538a, 0x01);
    OV5640__enWriteRegister(0x3212, 0x13); //end group 3
    OV5640__enWriteRegister(0x3212, 0xa3); //launch group 3
}
void OV5640__vSetBrightness(OV5640_BRIGHTNESS_nValue enBrightness)
{
    uint8_t u8BrightValue=(uint8_t)enBrightness;
    if(u8BrightValue<4)
        u8BrightValue=4-u8BrightValue;
    else
        u8BrightValue=u8BrightValue-4;
    OV5640__enWriteRegister(0x3212,0x03); //start group 3
    OV5640__enWriteRegister(0x5587,u8BrightValue<<4);
    if((uint8_t)enBrightness < 4)
        OV5640__enWriteRegister(0x5588,0x09);
    else
        OV5640__enWriteRegister(0x5588,0x01);
    OV5640__enWriteRegister(0x3212,0x13); //end group 3
    OV5640__enWriteRegister(0x3212,0xa3); //launch group 3
}

void OV5640__vSetContrast(OV5640_CONTRAST_nValue enContrast)
{
    uint8_t u8Reg0Val=0X00;//contrast=OV5640_CONTRAST_en0
    uint8_t u8Reg1Val=0X20;
    switch(enContrast)
    {
        case OV5640_CONTRAST_enMINUS_3://-3
            u8Reg1Val=u8Reg0Val=0X14;
            break;
        case OV5640_CONTRAST_enMINUS_2://-2
            u8Reg1Val=u8Reg0Val=0X18;
            break;
        case OV5640_CONTRAST_enMINUS_1://-1
            u8Reg1Val=u8Reg0Val=0X1C;
            break;
        case OV5640_CONTRAST_enPLUS_1://1
            u8Reg0Val=0X10;
            u8Reg1Val=0X24;
            break;
        case OV5640_CONTRAST_enPLUS_2://2
            u8Reg0Val=0X18;
            u8Reg1Val=0X28;
            break;
        case OV5640_CONTRAST_enPLUS_3://3
            u8Reg0Val=0X1C;
            u8Reg1Val=0X2C;
            break;
    }
    OV5640__enWriteRegister(0x3212,0x03); //start group 3
    OV5640__enWriteRegister(0x5585,u8Reg0Val);
    OV5640__enWriteRegister(0x5586,u8Reg1Val);
    OV5640__enWriteRegister(0x3212,0x13); //end group 3
    OV5640__enWriteRegister(0x3212,0xa3); //launch group 3
}

// ajuste de nitidez
// sharp: 0 ~ 33,0, off; 33, auto; otros valores, rango de nitidez.
void OV5640__vSetSharpness(uint8_t u8Sharpness)
{
    if(u8Sharpness<33)
    {
        OV5640__enWriteRegister(0x5308,0x65);
        OV5640__enWriteRegister(0x5302,u8Sharpness);
    }else
    {
        OV5640__enWriteRegister(0x5308,0x25);
        OV5640__enWriteRegister(0x5300,0x08);
        OV5640__enWriteRegister(0x5301,0x30);
        OV5640__enWriteRegister(0x5302,0x10);
        OV5640__enWriteRegister(0x5303,0x00);
        OV5640__enWriteRegister(0x5309,0x08);
        OV5640__enWriteRegister(0x530a,0x30);
        OV5640__enWriteRegister(0x530b,0x04);
        OV5640__enWriteRegister(0x530c,0x06);
    }

}

void OV5640__vSetSpecialEffects(OV5640_SPECIALEFFECTS_nValue enSpecialEffects)
{
    OV5640__enWriteRegister(0x3212,0x03); //start group 3
    OV5640__enWriteRegister(0x5580,OV5640_u8ValueSPECIALEFFECTS[(uint8_t)enSpecialEffects][0]);
    OV5640__enWriteRegister(0x5583,OV5640_u8ValueSPECIALEFFECTS[(uint8_t)enSpecialEffects][1]);// sat U
    OV5640__enWriteRegister(0x5584,OV5640_u8ValueSPECIALEFFECTS[(uint8_t)enSpecialEffects][2]);// sat V
    OV5640__enWriteRegister(0x5003,0x08);
    OV5640__enWriteRegister(0x3212,0x13); //end group 3
    OV5640__enWriteRegister(0x3212,0xa3); //launch group 3
}

void OV5640__vTestPattern(OV5640_PATTERN_nValue enMode)
{
    switch(enMode)
    {
    case OV5640_PATTERN_enNORMAL:
        OV5640__enWriteRegister(0X503D,0X00);
        break;
    case OV5640_PATTERN_enBAR:
        OV5640__enWriteRegister(0X503D,0X80);
        break;
    case OV5640_PATTERN_enBLOCK:
        OV5640__enWriteRegister(0X503D,0X82);
        break;
    default:
        break;
    }
}

// Set the image output size
// OV5640 output image size (resolution), completely determined by the function
//offx, offy, the offset of the output image in the OV5640__vSetImageWin setting window (assuming the length and width are xsize and ysize)
//Because the scale function is turned on, the image window for output is: xsize-2*offx, ysize-2*offy
//width, height: the width and height of the actual output image
//The actual output (width, height) is scaled on the basis of xsize-2*offx, ysize-2*offy.
//Generally set the values of offx and offy to 16 and 4, smaller is OK, but the default is 16 and 4.
// Return value: 0, set successfully
// Other, setup failed
void OV5640__vSetOutSize(uint16_t u16OffsetX,uint16_t u16OffsetY,uint16_t u16Width,uint16_t u16Height)
{
    OV5640__enWriteRegister(0X3212,0X03);      //start group 3
    //The following settings determine the actual output size (with zoom)
    OV5640__enWriteRegister(0x3808,u16Width>>8); //    Set the actual output width high byte
    OV5640__enWriteRegister(0x3809,u16Width&0xff);//Set the actual output width low byte
    OV5640__enWriteRegister(0x380a,u16Height>>8);//Set the actual output height high byte
    OV5640__enWriteRegister(0x380b,u16Height&0xff);//Set the actual output height low byte
    //The following settings determine the output size of the ISP above the drawing range
    //Range: xsize-2*offx, ysize-2*offy
    OV5640__enWriteRegister(0x3810,u16OffsetX>>8);  //Set the X offset high byte
    OV5640__enWriteRegister(0x3811,u16OffsetX&0xff);//Set the X offset low byte

    OV5640__enWriteRegister(0x3812,u16OffsetY>>8);  //Set the Y offset high byte
    OV5640__enWriteRegister(0x3813,u16OffsetY&0xff);//Set the Y offset low byte

    OV5640__enWriteRegister(0X3212,0X13);     //end group 3
    OV5640__enWriteRegister(0X3212,0Xa3);    //launch group 3
}

// Set the image window size (ISP size), non-essential, generally do not need to call this function
//Open the window above the sensor (maximum 2592*1944) for the output of OV5640__vSetOutSize
//Note: The width and height of this function must be greater than or equal to the width and height of the OV5640__vSetOutSize function.
// OV5640__vSetOutSize sets the width and height, according to the width and height set by this function, by DSP
// Automatically calculate the scaling and output to external devices.
//width, height: width (corresponding to: horizontal) and height (corresponding to: vertical)
void OV5640__vSetImageWindow(uint16_t u16OffsetX,uint16_t u16OffsetY,uint16_t u16Width,uint16_t u16Height)
{
    uint16_t u16StartX,u16StartY,u16EndX,u167EndY;
    u16StartX=u16OffsetX;
    u16StartY=u16OffsetY;
    u16EndX=u16OffsetX+u16Width-1;
    u167EndY=u16OffsetY+u16Height-1;
    OV5640__enWriteRegister(0X3212,0X03);
    OV5640__enWriteRegister(0X3800,u16StartX>>8);
    OV5640__enWriteRegister(0X3801,u16StartX&0XFF);
    OV5640__enWriteRegister(0X3802,u16StartY>>8);
    OV5640__enWriteRegister(0X3803,u16StartY&0XFF);
    OV5640__enWriteRegister(0X3804,u16EndX>>8);
    OV5640__enWriteRegister(0X3805,u16EndX&0XFF);
    OV5640__enWriteRegister(0X3806,u167EndY>>8);
    OV5640__enWriteRegister(0X3807,u167EndY&0XFF);
    OV5640__enWriteRegister(0X3212,0X13);
    OV5640__enWriteRegister(0X3212,0Xa3);
}

OV5640_nStatus OV5640__enInitFocus(void)
{
    uint16_t i;
    uint16_t u16Address=0x8000;
    uint8_t u8State=0x8F;
    OV5640__enWriteRegister(0x3000, 0x20);            //reset MCU
    for(i=0;i<sizeof(OV5640_u8ConfigAF);i++) //Send configuration array
    {
        OV5640__enWriteRegister(u16Address,OV5640_u8ConfigAF[i]);
        u16Address++;
    }
    OV5640__enWriteRegister(0x3022,0x00);
    OV5640__enWriteRegister(0x3023,0x00);
    OV5640__enWriteRegister(0x3024,0x00);
    OV5640__enWriteRegister(0x3025,0x00);
    OV5640__enWriteRegister(0x3026,0x00);
    OV5640__enWriteRegister(0x3027,0x00);
    OV5640__enWriteRegister(0x3028,0x00);
    OV5640__enWriteRegister(0x3029,0x7f);
    OV5640__enWriteRegister(0x3000,0x00);
    i=0;
    do
    {
        OV5640__enReadRegister(0x3029,&u8State);
        SysTick__vDelayUs(5000);
        i++;
        if(i>1000)
            return OV5640_enERROR;
    }while(u8State!=0x70);
    return OV5640_enOK;
}


OV5640_nStatus OV5640__enSingleFocus(void)
{
    uint8_t u8Temp;
    uint16_t u16Retry=0;
    OV5640__enWriteRegister(0x3022,0x03);
    while(1)
    {
        u16Retry++;
        OV5640__enReadRegister(0x3029,&u8Temp);
        if(u8Temp==0x10)
            break;        // focus completed
        SysTick__vDelayUs(5000);
        if(u16Retry>1000)
            return OV5640_enERROR;
    }
    return OV5640_enOK;
}

OV5640_nStatus OV5640__enContinueFocus(void)
{
    uint8_t u8Temp;
    uint16_t u16Retry=0;
    OV5640__enWriteRegister(0x3023,0x01);
    OV5640__enWriteRegister(0x3022,0x08);//Send IDLE instruction
    do
    {
        OV5640__enReadRegister(0x3023,&u8Temp);
        u16Retry++;
        if(u16Retry>1000)
            return OV5640_enERROR;
        SysTick__vDelayUs(5000);
    } while(u8Temp!=0x00);
    OV5640__enWriteRegister(0x3023,0x01);
    OV5640__enWriteRegister(0x3022,0x04);//Send a continuous focus command
    u16Retry=0;
    do
    {
        OV5640__enReadRegister(0x3023,&u8Temp);
        u16Retry++;
        if(u16Retry>1000)
            return OV5640_enERROR;
        SysTick__vDelayUs(5000);
    }while(u8Temp!=0x00);
    return OV5640_enOK;
}
