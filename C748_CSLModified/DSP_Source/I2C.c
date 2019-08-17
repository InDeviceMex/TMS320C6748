/*
 * I2C.c
 *
 *  Created on: 01/08/2019
 *      Author: Lalo
 */


#include "I2C.h"


void I2C0_vIsr(void);
void I2C1_vIsr(void);


uint8_t* I2C_pu8RX[2];
uint8_t* I2C_pu8TX[2];
int32_t I2C_s32NumberTx[2];
int32_t I2C_s32NumberRx[2];
I2c_nCommStatus I2C_enbusy[2]={I2C_COMM_enREADY};


I2c_nStatus I2C__enInit(I2C_TypeDef *i2c, I2c_nClockKernel enClockRate)
{
    uint32_t u32ClockDivisor=0;
    uint32_t u32Counter = 0;
    Intc_nEvent enEvent = EVENT_enUnused;
    Intc_nMask enMask = MASK_enUNUSED;

    void (*isr) (void);
    switch ((uint32_t)i2c)
    {
       case I2C0_BASE:
           SYSCFG0->PINMUX_Bit[4].PINMUX_15_12=8;//GP1_4 = I2C0 SDA
           SYSCFG0->PINMUX_Bit[4].PINMUX_11_8=8;//GP1_5 = I2C0 SCL
           GPIO1->DIR_Bit.P5=0;
           GPIO1->DIR_Bit.P4=0;
           GPIO1->SET_DATA_Bit.P5=1;
           GPIO1->SET_DATA_Bit.P4=1;


           SYSCFG0->PINMUX_Bit[4].PINMUX_15_12=2;//GP1_4 = I2C0 SDA
           SYSCFG0->PINMUX_Bit[4].PINMUX_11_8=2;//GP1_5 = I2C0 SCL
           //kernel clock = 25MHz HSE
           u32ClockDivisor=25000000;
           isr=I2C0_vIsr;
           enEvent=EVENT_enI2C0_INT;
           enMask=MASK_enINT5;
          break;

       case I2C1_BASE:
          SYSCFG0->PINMUX_Bit[4].PINMUX_23_20=4;//GP1_2 = I2C1 SDA
          SYSCFG0->PINMUX_Bit[4].PINMUX_19_16=4;//GP1_3 = I2C1 SCL
          //kernel clock= sysclk/4=400/4 =100MHz
          u32ClockDivisor=100000000;
          isr=I2C1_vIsr;
          enEvent=EVENT_enI2C1_INT;
          enMask=MASK_enINT6;
          break;
       default:
          return I2C_enERROR;
    }
    i2c->ICMDR = 0;
    u32ClockDivisor/=12500000ul;
    i2c->ICPSC = (uint16_t)u32ClockDivisor-1; //12.5MHz

    switch (enClockRate)
    {
       case I2C_CLOCK_en100K: //100k=12.5m/(56+6)+(57+6)
          i2c->ICCLKL = 56;
          i2c->ICCLKH = 57;
          break;

       case I2C_CLOCK_en200K://200k=12.5m/(25+6)+(25+6)
          i2c->ICCLKL = 25;
          i2c->ICCLKH = 25;
          break;

       case I2C_CLOCK_en400K://400k=12.5m/(10+6)+(10+6)
          i2c->ICCLKL = 10;
          i2c->ICCLKH = 10;
          break;
    }
    i2c->ICSTR = i2c->ICSTR; //interrupt pending erase

    while ((i2c->ICIVR)&&(u32Counter++ < I2C_TIMEOUT)) ;
    if (u32Counter++ > I2C_TIMEOUT)
    {
         return (I2C_enTIMEOUT);
    }

    i2c->ICOAR=0xAA; //DSP address
    i2c->ICIMR_Bit.AAS=0; //own address recognition
    i2c->ICIMR_Bit.SCD=0; //stop condition deteced
    i2c->ICIMR_Bit.ICXRDY=0; //tranmitter empty
    i2c->ICIMR_Bit.ICRRDY=0; //received ready
    i2c->ICIMR_Bit.ARDY=0; //access register ready
    i2c->ICIMR_Bit.NACK=0; //no received ack
    i2c->ICIMR_Bit.AL=0; //arbitration lost

    i2c->ICMDR_Bit.BC=0; //8 bits
    i2c->ICMDR_Bit.DLB=0; //no loopback
    i2c->ICMDR_Bit.RM=0; //no repeast mode
    i2c->ICMDR_Bit.XA=0; //slave address 7 bit

    i2c->ICSTR_Bit.BB=1;
    // release i2c from reset.
    i2c->ICMDR|=I2C_ICMDR_R_IRS_MASK;

    INTC__enCpuIntRegisterRoutine(enMask,isr);
    INTC__enEventMap2CpuInt(enMask,enEvent);
    INTC__enCpuIntEnable(enMask);
    return (I2C_enOK);
}
//Todo handle NACK correctly
I2c_nStatus I2C_enMasterSendData(I2C_TypeDef *i2c,uint8_t u8SlaveAddress, uint16_t u16DataNumber, uint8_t* pu8DataSend)
{
    volatile uint8_t* pu8PointerTX=0;
    volatile int32_t ps32TimeOut=0;
    volatile int32_t* ps32PointerNumber=0;

    i2c->ICSTR = i2c->ICSTR; //interrupt pending erase

    while ((i2c->ICIVR!=I2C_enNONE)&&(ps32TimeOut++ < I2C_TIMEOUT)) ;
    if (ps32TimeOut++ > I2C_TIMEOUT)
    {
         return (I2C_enTIMEOUT);
    }

    i2c->ICMDR &= ~I2C_ICMDR_R_STB_MASK;
    i2c->ICSAR=u8SlaveAddress;

    switch((uint32_t)i2c)
    {
    case I2C_en0:
        I2C_pu8TX[0]=pu8DataSend;
        pu8PointerTX=I2C_pu8TX[0];
        ps32PointerNumber=&I2C_s32NumberTx[0];
        break;
    case I2C_en1:
        I2C_pu8TX[1]=pu8DataSend;
        pu8PointerTX=I2C_pu8TX[1];
        ps32PointerNumber=&I2C_s32NumberTx[1];
        break;
    default:
        return I2C_enERROR;
    }

    pu8PointerTX=pu8DataSend;
    i2c->ICCNT = u16DataNumber;
    *ps32PointerNumber=(int32_t)u16DataNumber-(int32_t)1;
    i2c->ICSTR_Bit.ICXRDY=1; //tranmitter empty
    i2c->ICIMR_Bit.ICXRDY=1; //tranmitter empty
    I2C0->ICDXR =*pu8PointerTX;
    i2c->ICMDR = I2C_ICMDR_R_IRS_MASK| I2C_ICMDR_R_MST_MASK|I2C_ICMDR_R_TRX_MASK|I2C_ICMDR_R_STT_MASK|I2C_ICMDR_R_STP_MASK;

    ps32TimeOut=0;
    while((*ps32PointerNumber>0)&&  (ps32TimeOut<I2C_TIMEOUT))
    {
        if((i2c->ICSTR & I2C_ICSTR_R_NACK_MASK))
        {
            pu8PointerTX=pu8DataSend;
            i2c->ICCNT = u16DataNumber;
            *ps32PointerNumber=(int32_t)u16DataNumber-(int32_t)1;
            i2c->ICSTR|=I2C_ICSTR_R_NACK_MASK;
            i2c->ICSTR_Bit.ICXRDY=1; //tranmitter empty
            i2c->ICIMR_Bit.ICXRDY=1; //tranmitter empty
            I2C0->ICDXR =*pu8PointerTX;
            i2c->ICMDR = I2C_ICMDR_R_IRS_MASK| I2C_ICMDR_R_MST_MASK|I2C_ICMDR_R_TRX_MASK|I2C_ICMDR_R_STT_MASK|I2C_ICMDR_R_STP_MASK;
        }
        if(ps32TimeOut== (I2C_TIMEOUT>>1))
        {
            i2c->ICMDR|=I2C_ICMDR_R_STP_MASK;
            while(i2c->ICSTR_Bit.BB);
            pu8PointerTX=pu8DataSend;
            i2c->ICCNT = u16DataNumber;
            *ps32PointerNumber=(int32_t)u16DataNumber-(int32_t)1;
            i2c->ICSTR_Bit.ICXRDY=1; //tranmitter empty
            i2c->ICIMR_Bit.ICXRDY=1; //tranmitter empty
            I2C0->ICDXR =*pu8PointerTX;
            i2c->ICMDR = I2C_ICMDR_R_IRS_MASK| I2C_ICMDR_R_MST_MASK|I2C_ICMDR_R_TRX_MASK|I2C_ICMDR_R_STT_MASK|I2C_ICMDR_R_STP_MASK;

        }
        ps32TimeOut++;

    }

    i2c->ICIMR_Bit.ICXRDY=0; //tranmitter empty
    while((i2c->ICSTR & I2C_ICSTR_R_XSMT_MASK)==0);
    while((i2c->ICSTR & I2C_ICSTR_R_ICXRDY_MASK)==0);
    while((i2c->ICSTR & I2C_ICSTR_R_BB_MASK)==I2C_ICSTR_R_BB_MASK);
    return I2C_enOK;
}

I2c_nStatus I2C_enMasterSendReadData(I2C_TypeDef *i2c,uint8_t u8SlaveAddress, uint16_t u16DataNumberSend, uint8_t* pu8DataSend, uint16_t u16DataNumberRead, uint8_t* pu8DataRead)
{

    I2C_enMasterSendData(i2c,u8SlaveAddress,u16DataNumberSend,pu8DataSend);
    I2C_enMasterReadData(i2c,u8SlaveAddress,u16DataNumberRead,pu8DataRead);

    return I2C_enOK;
}


I2c_nStatus I2C_enMasterReadData(I2C_TypeDef *i2c,uint8_t u8SlaveAddress, uint16_t u16DataNumber, uint8_t* pu8DataReceive)
{
    volatile int32_t* ps32PointerNumber=0;
    uint8_t* pu8PointerRX=0;
    int32_t ps32TimeOut=0;

    i2c->ICSTR = i2c->ICSTR; //interrupt pending erase

    while ((i2c->ICIVR!=0)&&(ps32TimeOut++ < I2C_TIMEOUT)) ;
    if (ps32TimeOut++ > I2C_TIMEOUT)
    {
         return (I2C_enTIMEOUT);
    }
    i2c->ICMDR &= ~I2C_ICMDR_R_STB_MASK;
    i2c->ICSAR=u8SlaveAddress;
    switch((uint32_t)i2c)
    {
    case I2C_en0:
        I2C_pu8RX[0]=pu8DataReceive;
        pu8PointerRX=I2C_pu8RX[0];
        ps32PointerNumber=&I2C_s32NumberRx[0];
        break;
    case I2C_en1:
        I2C_pu8RX[1]=pu8DataReceive;
        pu8PointerRX=I2C_pu8RX[0];
        ps32PointerNumber=&I2C_s32NumberRx[1];
        break;
    default:
        return I2C_enERROR;
    }
    i2c->ICCNT = u16DataNumber;
    *ps32PointerNumber=u16DataNumber;
    i2c->ICSTR_Bit.ICRRDY=0; //tranmitter empty
    i2c->ICIMR_Bit.ICRRDY=1; //tranmitter empty
    i2c->ICMDR =I2C_ICMDR_R_IRS_MASK|  I2C_ICMDR_R_MST_MASK|I2C_ICMDR_R_STT_MASK|I2C_ICMDR_R_STP_MASK;

    while(*ps32PointerNumber>0)
    {
        if((i2c->ICSTR & I2C_ICSTR_R_NACK_MASK))
        {
            pu8PointerRX=pu8PointerRX-1;
            i2c->ICCNT = *ps32PointerNumber+1;
            *ps32PointerNumber=(int32_t)u16DataNumber-(int32_t)1;
            i2c->ICSTR|=I2C_ICSTR_R_NACK_MASK;
            i2c->ICSTR_Bit.ICRRDY=0; //tranmitter empty
            i2c->ICIMR_Bit.ICRRDY=1; //tranmitter empty
         }
    }
    i2c->ICIMR_Bit.ICRRDY=0; //tranmitter empty
    while((i2c->ICSTR & I2C_ICSTR_R_BB_MASK)==I2C_ICSTR_R_BB_MASK);
    return I2C_enOK;
}
void I2C0_vIsr(void)
{
    INTC__enEventClear(EVENT_enI2C0_INT);
    switch (I2C0_ICIVR_R)
    {
    case I2C_enICRRDY:
            *I2C_pu8RX[0]=I2C0->ICDRR;
            I2C_pu8RX[0]++;
            I2C_s32NumberRx[0]--;

        break;
    case I2C_enICXRDY:
            I2C_pu8TX[0]++;
            I2C_s32NumberTx[0]--;
            I2C0->ICDXR =*I2C_pu8TX[0];
        break;
    default:
        break;
    }

}


void I2C1_vIsr(void)
{
    INTC__enEventClear(EVENT_enI2C1_INT);
    switch (I2C1_ICIVR_R)
    {
    case I2C_enNONE:

        break;
    case I2C_enAL:

        break;
    case I2C_enNACK:

        break;
    case I2C_enARDY:

        break;
    case I2C_enICRRDY:

        break;
    case I2C_enICXRDY:

        break;
    case I2C_enSCD:

        break;
    case I2C_enAAS:

        break;
    default:
        break;
    }

}
