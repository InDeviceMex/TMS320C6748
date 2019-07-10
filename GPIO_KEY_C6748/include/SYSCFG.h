/*
 * SYSCFG.h
 *
 *  Created on: 19/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_SYSCFG_H_
#define INCLUDE_SYSCFG_H_




#include "Core.h"
#include <stdint.h>

#define SYSCFG0_BASE            ((uint32_t)0x01C14000)
#define SYSCFG1_BASE            ((uint32_t)0x01E2C000)

typedef __IO struct
{
    __I uint32_t REV       :32;
}SYSCFG_REVID_TypeDef;

typedef __IO struct
{
    __I uint32_t DEVID0       :32;
}SYSCFG_DEVIDR0_TypeDef;

typedef __IO struct
{
    __I uint32_t BOOTMODE       :16;
        uint32_t reserved0      :16;
}SYSCFG_BOOTCFG_TypeDef;

typedef __IO struct
{
    __I uint32_t CHIPREVID       :6;
        uint32_t reserved0       :26;
}SYSCFG_CHIPREVIDR_TypeDef;

typedef __IO struct
{
    __IO uint32_t KICK0     :32;
}SYSCFG_KICK0R_TypeDef;

typedef __IO struct
{
    __IO uint32_t KICK1     :32;
}SYSCFG_KICK1R_TypeDef;

typedef __IO struct
{
         uint32_t reserved0 :10;
    __IO uint32_t DSP_ISTP_RST_VAL    :22;
}SYSCFG_HOST1CFG_TypeDef;


typedef __IO struct
{
    __IO uint32_t PROTERR       :1;
    __IO uint32_t ADDRERR       :1;
        uint32_t reserved0       :30;
}SYSCFG_IRAWSTAT_TypeDef;


typedef __IO struct
{
    __IO uint32_t PROTERR       :1;
    __IO uint32_t ADDRERR       :1;
        uint32_t reserved0       :30;
}SYSCFG_IENSTAT_TypeDef;


typedef __IO struct
{
    __IO uint32_t PROTERR_EN       :1;
    __IO uint32_t ADDRERR_EN      :1;
        uint32_t reserved0       :30;
}SYSCFG_IENSET_TypeDef;


typedef __IO struct
{
    __IO uint32_t PROTERR_CLR       :1;
    __IO uint32_t ADDRERR_CLR      :1;
        uint32_t reserved0       :30;
}SYSCFG_IENCLR_TypeDef;


typedef __IO struct
{
    __IO uint32_t EOIVECT       :8;
        uint32_t reserved0       :24;
}SYSCFG_EOI_TypeDef;

typedef __IO struct
{
    __I uint32_t FLTADDR       :32;
}SYSCFG_FLTADDRR_TypeDef;

typedef __IO struct
{
    __I uint32_t TYPE       :6;
        uint32_t reserved0  :3;
    __I uint32_t PRIVID     :4;
        uint32_t reserved1  :3;
    __I uint32_t MSTID      :8;
    __I uint32_t ID         :8;
}SYSCFG_FLTSTAT_TypeDef;

typedef __IO struct
{
         uint32_t reserved0    :8;
    __IO uint32_t DSP_MDMA     :3;
         uint32_t reserved1    :1;
    __IO uint32_t DSP_CFG      :3;
         uint32_t reserved2    :1;
    __IO uint32_t UPP          :3;
         uint32_t reserved3    :1;
    __IO uint32_t SATA         :3;
         uint32_t reserved4    :9;
}SYSCFG_MSTPRI0_TypeDef;

typedef __IO struct
{
    __IO uint32_t PRU0         :3;
         uint32_t reserved0    :1;
    __IO uint32_t PRU1         :3;
         uint32_t reserved1    :1;
    __IO uint32_t EDMA30TC0    :3;
         uint32_t reserved2    :1;
    __IO uint32_t EDMA30TC1    :3;
         uint32_t reserved3    :1;
    __IO uint32_t EDMA31TC0    :3;
         uint32_t reserved4    :5;
    __IO uint32_t VPIF_DMA_0   :3;
         uint32_t reserved5    :1;
    __IO uint32_t VPIF_DMA_1   :3;
         uint32_t reserved6    :1;
}SYSCFG_MSTPRI1_TypeDef;

typedef __IO struct
{
    __IO uint32_t EMAC         :3;
         uint32_t reserved0    :5;
    __IO uint32_t USB0CFG      :3;
         uint32_t reserved1    :1;
    __IO uint32_t USB0CDMA     :3;
         uint32_t reserved2    :5;
    __IO uint32_t UHPI         :3;
         uint32_t reserved3    :1;
    __IO uint32_t USB1         :3;
         uint32_t reserved4    :1;
    __IO uint32_t LCDC         :3;
         uint32_t reserved5    :1;
}SYSCFG_MSTPRI2_TypeDef;

typedef __IO struct
{
    __IO uint32_t PINMUX_3_0   :4;
    __IO uint32_t PINMUX_7_4   :4;
    __IO uint32_t PINMUX_11_8  :4;
    __IO uint32_t PINMUX_15_12 :4;
    __IO uint32_t PINMUX_19_16 :4;
    __IO uint32_t PINMUX_23_20 :4;
    __IO uint32_t PINMUX_27_24 :4;
    __IO uint32_t PINMUX_31_28 :4;
}SYSCFG_PINMUX_TypeDef;

typedef __IO struct
{
    __IO uint32_t ECAP0SRC     :1;
    __IO uint32_t ECAP1SRC     :1;
    __IO uint32_t ECAP2SRC     :1;
    __IO uint32_t TIMER64P_3SRC:1;
    __IO uint32_t UPPSRC       :1;
    __IO uint32_t EMACSRC      :1;
    __IO uint32_t PRUSRC       :1;
    __IO uint32_t MCBSP0SRC    :1;
    __IO uint32_t MCBSP1SRC    :1;
    __IO uint32_t USB0SRC      :1;
         uint32_t reserved0    :2;
    __IO uint32_t HPISRC       :1;
    __IO uint32_t SATASRC      :1;
    __IO uint32_t VPIFSRC      :1;
         uint32_t reserved1    :1;
    __IO uint32_t I2C0SRC      :1;
    __IO uint32_t I2C1SRC      :1;
    __IO uint32_t UART0SRC     :1;
    __IO uint32_t UART1SRC     :1;
    __IO uint32_t UART2SRC     :1;
    __IO uint32_t SPI0SRC      :1;
    __IO uint32_t SPI1SRC      :1;
    __IO uint32_t EPWM0SRC     :1;
    __IO uint32_t EPWM1SRC     :1;
         uint32_t reserved2    :2;
    __IO uint32_t TIMER64P_0SRC:1;
    __IO uint32_t TIMER64P_1SRC:1;
    __IO uint32_t TIMER64P_2SRC:1;
         uint32_t reserved3    :2;
}SYSCFG_SUSPSRC_TypeDef;

typedef __IO struct
{
         uint32_t reserved0     :2;
    __IO uint32_t CHIPSIG2      :1;
    __IO uint32_t CHIPSIG3      :1;
    __IO uint32_t CHIPSIG4      :1;
         uint32_t reserved1     :27;
}SYSCFG_CHIPSIG_TypeDef;

typedef __IO struct
{
         uint32_t reserved0     :2;
    __IO uint32_t CHIPSIG2      :1;
    __IO uint32_t CHIPSIG3      :1;
    __IO uint32_t CHIPSIG4      :1;
         uint32_t reserved1     :27;
}SYSCFG_CHIPSIG_CLR_TypeDef;

typedef __IO struct
{
    __IO uint32_t EDMA30TC0DBS   :2;
    __IO uint32_t EDMA30TC1DBS   :2;
    __IO uint32_t PLL_MASTER_LOCK:1;
         uint32_t reserved0      :27;
}SYSCFG_CFGCHIP0_TypeDef;

typedef __IO struct
{
    __IO uint32_t AMUTESEL0      :4;
         uint32_t reserved0      :8;
    __IO uint32_t TBCLKSYNC      :1;
    __IO uint32_t EDMA31TC0DBS   :2;
    __IO uint32_t HPIENA         :1;
    __IO uint32_t HPIBYTEAD      :1;
    __IO uint32_t CAP0SRC        :5;
    __IO uint32_t CAP1SRC        :5;
    __IO uint32_t CAP2SRC        :5;
}SYSCFG_CFGCHIP1_TypeDef;

typedef __IO struct
{
    __IO uint32_t USB0REF_FREQ   :4;
    __IO uint32_t USB0VBDTCTEN   :1;
    __IO uint32_t USB0SESNDEN    :1;
    __IO uint32_t USB0PHY_PLLON  :1;
    __IO uint32_t USB1SUSPENDM   :1;
    __IO uint32_t USB0DATPOL     :1;
    __IO uint32_t USB0OTGPWRDN   :1;
    __IO uint32_t USB0PHYPWDN    :1;
    __IO uint32_t USB0PHYCLKMUX  :1;
    __IO uint32_t USB1PHYCLKMUX  :1;
    __IO uint32_t USB0OTGMODE    :2;
    __IO uint32_t RESET          :1;
    __IO uint32_t USB0VBUSSENSE  :1;
    __IO uint32_t USB0PHYCLKGD   :1;
         uint32_t reserved0      :14;
}SYSCFG_CFGCHIP2_TypeDef;

typedef __IO struct
{
         uint32_t reserved0      :1;
    __IO uint32_t EMA_CLKSRC     :1;
    __IO uint32_t DIV45PENA      :1;
    __IO uint32_t PRUEVTSEL      :1;
    __IO uint32_t ASYNC3_CLKSRC  :1;
    __IO uint32_t PLL1_MASTER_LOCK   :1;
    __IO uint32_t UPP_TX_CLKSRC  :1;
         uint32_t reserved1      :1;
    __IO uint32_t RMII_SEL       :1;
         uint32_t reserved2      :23;
}SYSCFG_CFGCHIP3_TypeDef;

typedef __IO struct
{
    __IO uint32_t AMUTECLR0     :1;
         uint32_t reserved2     :31;
}SYSCFG_CFGCHIP4_TypeDef;

typedef __IO struct
{
    __IO uint32_t F         :3;
    __IO uint32_t D         :3;
    __IO uint32_t POWERDN   :1;
    __IO uint32_t LOCK      :1;
    __IO uint32_t PWRSAVE   :1;
    __IO uint32_t reserved0 :4;
    __IO uint32_t CLKRZ     :1;
    __IO uint32_t IOPWRDN   :1;
    __IO uint32_t READY     :1;
    __IO uint32_t VREFTAP   :2;
    __IO uint32_t VREFEN    :1;
         uint32_t reserved1 :13;
}SYSCFG_VTPIO_CTL_TypeDef;

typedef __IO struct
{
    __IO uint32_t DDR_CMDSLEW :2;
    __IO uint32_t DDR_DATASLEW:2;
    __IO uint32_t CMOSEN      :1;
    __IO uint32_t DDR_PDENA   :1;
    __IO uint32_t reserved0   :2;
    __IO uint32_t ODT_TERMOFF :2;
    __IO uint32_t ODT_TERMON  :2;
         uint32_t reserved1   :20;
}SYSCFG_DDR_SLEW_TypeDef;

typedef __IO struct
{
    __IO uint32_t SLEEPCOUNT  :16;
    __IO uint32_t reserved0   :14;
    __IO uint32_t SLEEPCOMPLETE :1;
    __IO uint32_t SLEEPENABLE  :1;
}SYSCFG_DEEPSLEEP_TypeDef;

typedef __IO struct
{
    __IO uint32_t PUPDENA0  :1;
    __IO uint32_t PUPDENA1  :1;
    __IO uint32_t PUPDENA2  :1;
    __IO uint32_t PUPDENA3  :1;
    __IO uint32_t PUPDENA4  :1;
    __IO uint32_t PUPDENA5  :1;
    __IO uint32_t PUPDENA6  :1;
    __IO uint32_t PUPDENA7  :1;
    __IO uint32_t PUPDENA8  :1;
    __IO uint32_t PUPDENA9  :1;
    __IO uint32_t PUPDENA10  :1;
    __IO uint32_t PUPDENA11  :1;
    __IO uint32_t PUPDENA12  :1;
    __IO uint32_t PUPDENA13  :1;
    __IO uint32_t PUPDENA14  :1;
    __IO uint32_t PUPDENA15  :1;
    __IO uint32_t PUPDENA16  :1;
    __IO uint32_t PUPDENA17  :1;
    __IO uint32_t PUPDENA18  :1;
    __IO uint32_t PUPDENA19  :1;
    __IO uint32_t PUPDENA20  :1;
    __IO uint32_t PUPDENA21  :1;
    __IO uint32_t PUPDENA22  :1;
    __IO uint32_t PUPDENA23  :1;
    __IO uint32_t PUPDENA24  :1;
    __IO uint32_t PUPDENA25  :1;
    __IO uint32_t PUPDENA26  :1;
    __IO uint32_t PUPDENA27  :1;
    __IO uint32_t PUPDENA28  :1;
    __IO uint32_t PUPDENA29  :1;
    __IO uint32_t PUPDENA30  :1;
    __IO uint32_t PUPDENA31  :1;
}SYSCFG_PUPD_ENA_TypeDef;

typedef __IO struct
{
    __IO uint32_t PUPDSEL0  :1;
    __IO uint32_t PUPDSEL1  :1;
    __IO uint32_t PUPDSEL2  :1;
    __IO uint32_t PUPDSEL3  :1;
    __IO uint32_t PUPDSEL4  :1;
    __IO uint32_t PUPDSEL5  :1;
    __IO uint32_t PUPDSEL6  :1;
    __IO uint32_t PUPDSEL7  :1;
    __IO uint32_t PUPDSEL8  :1;
    __IO uint32_t PUPDSEL9  :1;
    __IO uint32_t PUPDSEL10  :1;
    __IO uint32_t PUPDSEL11  :1;
    __IO uint32_t PUPDSEL12  :1;
    __IO uint32_t PUPDSEL13  :1;
    __IO uint32_t PUPDSEL14  :1;
    __IO uint32_t PUPDSEL15  :1;
    __IO uint32_t PUPDSEL16  :1;
    __IO uint32_t PUPDSEL17  :1;
    __IO uint32_t PUPDSEL18  :1;
    __IO uint32_t PUPDSEL19  :1;
    __IO uint32_t PUPDSEL20  :1;
    __IO uint32_t PUPDSEL21  :1;
    __IO uint32_t PUPDSEL22  :1;
    __IO uint32_t PUPDSEL23  :1;
    __IO uint32_t PUPDSEL24  :1;
    __IO uint32_t PUPDSEL25  :1;
    __IO uint32_t PUPDSEL26  :1;
    __IO uint32_t PUPDSEL27  :1;
    __IO uint32_t PUPDSEL28  :1;
    __IO uint32_t PUPDSEL29  :1;
    __IO uint32_t PUPDSEL30  :1;
    __IO uint32_t PUPDSEL31  :1;
}SYSCFG_PUPD_SEL_TypeDef;

typedef __IO struct
{
    __IO uint32_t RXACTIVE0  :1;
    __IO uint32_t RXACTIVE1  :1;
    __IO uint32_t RXACTIVE2  :1;
    __IO uint32_t RXACTIVE3  :1;
    __IO uint32_t RXACTIVE4  :1;
    __IO uint32_t RXACTIVE5  :1;
    __IO uint32_t RXACTIVE6  :1;
    __IO uint32_t RXACTIVE7  :1;
    __IO uint32_t RXACTIVE8  :1;
    __IO uint32_t RXACTIVE9  :1;
    __IO uint32_t RXACTIVE10  :1;
    __IO uint32_t RXACTIVE11  :1;
    __IO uint32_t RXACTIVE12  :1;
    __IO uint32_t RXACTIVE13  :1;
    __IO uint32_t RXACTIVE14  :1;
    __IO uint32_t RXACTIVE15  :1;
    __IO uint32_t RXACTIVE16  :1;
    __IO uint32_t RXACTIVE17  :1;
    __IO uint32_t RXACTIVE18  :1;
    __IO uint32_t RXACTIVE19  :1;
    __IO uint32_t RXACTIVE20  :1;
    __IO uint32_t RXACTIVE21  :1;
    __IO uint32_t RXACTIVE22  :1;
    __IO uint32_t RXACTIVE23  :1;
    __IO uint32_t RXACTIVE24  :1;
    __IO uint32_t RXACTIVE25  :1;
    __IO uint32_t RXACTIVE26  :1;
    __IO uint32_t RXACTIVE27  :1;
    __IO uint32_t RXACTIVE28  :1;
    __IO uint32_t RXACTIVE29  :1;
    __IO uint32_t RXACTIVE30  :1;
    __IO uint32_t RXACTIVE31  :1;
}SYSCFG_RXACTIVE_TypeDef;

typedef __IO struct
{
    __IO uint32_t SATACLK_PWRDN :1;
    __IO uint32_t reserved0   :31;
}SYSCFG_PWRDN_TypeDef;





typedef struct  {
    union
    {
        __IO uint32_t           REVID;
        SYSCFG_REVID_TypeDef    REVID_Bit;
    };
    uint32_t reserved0[1];
    __IO uint32_t DIEIDR0;
    __IO uint32_t DIEIDR1;
    __IO uint32_t DIEIDR2;
    __IO uint32_t DIEIDR3;
    union
    {
        __IO uint32_t           DEVIDR0;
        SYSCFG_DEVIDR0_TypeDef  DEVIDR0_Bit;
    };
    uint32_t reserved1[1];
    union
    {
        __IO uint32_t           BOOTCFG;
        SYSCFG_BOOTCFG_TypeDef  BOOTCFG_Bit;
    };
    union
    {
        __IO uint32_t               CHIPREVIDR;
        SYSCFG_CHIPREVIDR_TypeDef   CHIPREVIDR_Bit;
    };
    uint32_t reserved2[4];
    union
    {
        __IO uint32_t               KICK0R;
        SYSCFG_KICK0R_TypeDef       KICK0R_Bit;
    };
    union
    {
        __IO uint32_t               KICK1R;
        SYSCFG_KICK1R_TypeDef       KICK1R_Bit;
    };
    uint32_t reserved3[1];
    union
    {
        __IO uint32_t               HOST1CFG;
        SYSCFG_HOST1CFG_TypeDef     HOST1CFG_Bit;
    };
    uint32_t reserved4[38];
    union
    {
        __IO uint32_t               IRAWSTAT;
        SYSCFG_IRAWSTAT_TypeDef     IRAWSTAT_Bit;
    };
    union
    {
        __IO uint32_t               IENSTAT;
        SYSCFG_IENSTAT_TypeDef      IENSTAT_Bit;
    };
    union
    {
        __IO uint32_t               IENSET;
        SYSCFG_IENSET_TypeDef      IENSET_Bit;
    };
    union
    {
        __IO uint32_t               IENCLR;
        SYSCFG_IENCLR_TypeDef       IENCLR_Bit;
    };
    union
    {
        __IO uint32_t               EOI;
        SYSCFG_EOI_TypeDef          EOI_Bit;
    };
    union
    {
        __IO uint32_t               FLTADDRR;
        SYSCFG_FLTADDRR_TypeDef     FLTADDRR_Bit;
    };
    union
    {
        __IO uint32_t               FLTSTAT;
        SYSCFG_FLTSTAT_TypeDef      FLTSTAT_Bit;
    };
    uint32_t reserved5[5];
    union
    {
        __IO uint32_t               MSTPRI0;
        SYSCFG_MSTPRI0_TypeDef      MSTPRI0_Bit;
    };
    union
    {
        __IO uint32_t               MSTPRI1;
        SYSCFG_MSTPRI1_TypeDef      MSTPRI1_Bit;
    };
    union
    {
        __IO uint32_t               MSTPRI2;
        SYSCFG_MSTPRI2_TypeDef      MSTPRI2_Bit;
    };
    uint32_t reserved6[1];
    union
    {
        __IO uint32_t               PINMUX[20];
        SYSCFG_PINMUX_TypeDef       PINMUX_Bit[20];
    };
    union
    {
        __IO uint32_t               SUSPSRC;
        SYSCFG_SUSPSRC_TypeDef      SUSPSRC_Bit;
    };
    union
    {
        __IO uint32_t               CHIPSIG;
        SYSCFG_CHIPSIG_TypeDef      CHIPSIG_Bit;
    };
    union
    {
        __IO uint32_t               CHIPSIG_CLR;
        SYSCFG_CHIPSIG_CLR_TypeDef  CHIPSIG_CLR_Bit;
    };
    union
    {
        __IO uint32_t               CFGCHIP0;
        SYSCFG_CFGCHIP0_TypeDef  CFGCHIP0_Bit;
    };
    union
    {
        __IO uint32_t               CFGCHIP1;
        SYSCFG_CFGCHIP1_TypeDef     CFGCHIP1_Bit;
    };
    union
    {
        __IO uint32_t               CFGCHIP2;
        SYSCFG_CFGCHIP2_TypeDef     CFGCHIP2_Bit;
    };
    union
    {
        __IO uint32_t               CFGCHIP3;
        SYSCFG_CFGCHIP3_TypeDef     CFGCHIP3_Bit;
    };
    union
    {
        __IO uint32_t               CFGCHIP4;
        SYSCFG_CFGCHIP4_TypeDef     CFGCHIP4_Bit;
    };

} SYSCFG0_TypeDef;



typedef struct  {
    union
    {
        __IO uint32_t               VTPIO_CTL;
        SYSCFG_VTPIO_CTL_TypeDef    VTPIO_CTL_Bit;
    };
    union
    {
        __IO uint32_t               DDR_SLEW;
        SYSCFG_DDR_SLEW_TypeDef     DDR_SLEW_Bit;
    };
    union
    {
        __IO uint32_t               DEEPSLEEP;
        SYSCFG_DEEPSLEEP_TypeDef     DEEPSLEEP_Bit;
    };
    union
    {
        __IO uint32_t               PUPD_ENA;
        SYSCFG_PUPD_ENA_TypeDef     PUPD_ENA_Bit;
    };
    union
    {
        __IO uint32_t               PUPD_SEL;
        SYSCFG_PUPD_SEL_TypeDef     PUPD_SEL_Bit;
    };
    union
    {
        __IO uint32_t               RXACTIVE;
        SYSCFG_RXACTIVE_TypeDef     RXACTIVE_Bit;
    };
    union
    {
        __IO uint32_t               PWRDN;
        SYSCFG_PWRDN_TypeDef     PWRDN_Bit;
    };


} SYSCFG1_TypeDef;


#define SYSCFG0            (((SYSCFG0_TypeDef*)(SYSCFG0_BASE)))
#define SYSCFG0_R(offset)  (*((__IO uint32_t *)(SYSCFG0_BASE+offset)))
#define SYSCFG1            (((SYSCFG1_TypeDef*)(SYSCFG1_BASE)))
#define SYSCFG1_R(offset)  (*((__IO uint32_t *)(SYSCFG1_BASE+offset)))


#define SYSCFG_REVID_OFFSET       ((uint32_t)0x0000)
#define SYSCFG_DIEIDR0_OFFSET     ((uint32_t)0x0008)
#define SYSCFG_DIEIDR1_OFFSET     ((uint32_t)0x000C)
#define SYSCFG_DIEIDR2_OFFSET     ((uint32_t)0x0010)
#define SYSCFG_DIEIDR3_OFFSET     ((uint32_t)0x0014)
#define SYSCFG_DEVIDR0_OFFSET     ((uint32_t)0x0018)
#define SYSCFG_BOOTCFG_OFFSET     ((uint32_t)0x0020)
#define SYSCFG_CHIPREVIDR_OFFSET  ((uint32_t)0x0024)
#define SYSCFG_KICK0R_OFFSET      ((uint32_t)0x0038)
#define SYSCFG_KICK1R_OFFSET      ((uint32_t)0x003C)
#define SYSCFG_HOST1CFG_OFFSET    ((uint32_t)0x0044)
#define SYSCFG_IRAWSTAT_OFFSET    ((uint32_t)0x00E0)
#define SYSCFG_IENSTAT_OFFSET     ((uint32_t)0x00E4)
#define SYSCFG_IENSET_OFFSET      ((uint32_t)0x00E8)
#define SYSCFG_IENCLR_OFFSET      ((uint32_t)0x00EC)
#define SYSCFG_EOI_OFFSET         ((uint32_t)0x00F0)
#define SYSCFG_FLTADDRR_OFFSET    ((uint32_t)0x00F4)
#define SYSCFG_FLTSTAT_OFFSET     ((uint32_t)0x00F8)
#define SYSCFG_MSTPRI0_OFFSET     ((uint32_t)0x0110)
#define SYSCFG_MSTPRI1_OFFSET     ((uint32_t)0x0114)
#define SYSCFG_MSTPRI2_OFFSET     ((uint32_t)0x0118)
#define SYSCFG_PINMUX0_OFFSET     ((uint32_t)0x0120)
#define SYSCFG_PINMUX1_OFFSET     ((uint32_t)0x0124)
#define SYSCFG_PINMUX2_OFFSET     ((uint32_t)0x0128)
#define SYSCFG_PINMUX3_OFFSET     ((uint32_t)0x012C)
#define SYSCFG_PINMUX4_OFFSET     ((uint32_t)0x0130)
#define SYSCFG_PINMUX5_OFFSET     ((uint32_t)0x0134)
#define SYSCFG_PINMUX6_OFFSET     ((uint32_t)0x0138)
#define SYSCFG_PINMUX7_OFFSET     ((uint32_t)0x013C)
#define SYSCFG_PINMUX8_OFFSET     ((uint32_t)0x0140)
#define SYSCFG_PINMUX9_OFFSET     ((uint32_t)0x0144)
#define SYSCFG_PINMUX10_OFFSET     ((uint32_t)0x0148)
#define SYSCFG_PINMUX11_OFFSET     ((uint32_t)0x014C)
#define SYSCFG_PINMUX12_OFFSET     ((uint32_t)0x0150)
#define SYSCFG_PINMUX13_OFFSET     ((uint32_t)0x0154)
#define SYSCFG_PINMUX14_OFFSET     ((uint32_t)0x0158)
#define SYSCFG_PINMUX15_OFFSET     ((uint32_t)0x015C)
#define SYSCFG_PINMUX16_OFFSET     ((uint32_t)0x0160)
#define SYSCFG_PINMUX17_OFFSET     ((uint32_t)0x0164)
#define SYSCFG_PINMUX18_OFFSET     ((uint32_t)0x0168)
#define SYSCFG_PINMUX19_OFFSET     ((uint32_t)0x016C)
#define SYSCFG_SUSPSRC_OFFSET      ((uint32_t)0x0170)
#define SYSCFG_CHIPSIG_OFFSET      ((uint32_t)0x0174)
#define SYSCFG_CHIPSIG_CLR_OFFSET ((uint32_t)0x0178)
#define SYSCFG_CFGCHIP0_OFFSET    ((uint32_t)0x017C)
#define SYSCFG_CFGCHIP1_OFFSET    ((uint32_t)0x0180)
#define SYSCFG_CFGCHIP2_OFFSET    ((uint32_t)0x0184)
#define SYSCFG_CFGCHIP3_OFFSET    ((uint32_t)0x0188)
#define SYSCFG_CFGCHIP4_OFFSET    ((uint32_t)0x018C)

#define SYSCFG_VTPIO_CTL_OFFSET    ((uint32_t)0x0000)
#define SYSCFG_DDR_SLEW_OFFSET     ((uint32_t)0x0004)
#define SYSCFG_DEEPSLEEP_OFFSET    ((uint32_t)0x0008)
#define SYSCFG_PUPD_ENA_OFFSET     ((uint32_t)0x000C)
#define SYSCFG_PUPD_SEL_OFFSET     ((uint32_t)0x0010)
#define SYSCFG_RXACTIVE_OFFSET     ((uint32_t)0x0014)
#define SYSCFG_PWRDN_OFFSET        ((uint32_t)0x0018)


/**********************************************************************************************
************************************** 1 REVID ***********************************************
**********************************************************************************************/
#define SYSCFG0_REVID                    (((SYSCFG_REVID_TypeDef*)(SYSCFG0_BASE+SYSCFG_REVID_OFFSET )))
#define SYSCFG0_REVID_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_REVID_OFFSET)))

/*--------*/
#define SYSCFG_REVID_R_REV_MASK        ((uint32_t)0xFFFFFFFF)
#define SYSCFG_REVID_R_REV_SHIFT         (0)

#define SYSCFG_REVID_REV_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 2 DEVIDR0 ***********************************************
**********************************************************************************************/
#define SYSCFG0_DEVIDR0                    (((SYSCFG_DEVIDR0_TypeDef*)(SYSCFG0_BASE+SYSCFG_DEVIDR0_OFFSET )))
#define SYSCFG0_DEVIDR0_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_DEVIDR0_OFFSET)))

/*--------*/
#define SYSCFG_DEVIDR0_R_DEVID0_MASK        ((uint32_t)0xFFFFFFFF)
#define SYSCFG_DEVIDR0_R_DEVID0_SHIFT         (0)

#define SYSCFG_DEVIDR0_DEVID0_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 3 BOOTCFG ***********************************************
**********************************************************************************************/
#define SYSCFG0_BOOTCFG                    (((SYSCFG_BOOTCFG_TypeDef*)(SYSCFG0_BASE+SYSCFG_BOOTCFG_OFFSET )))
#define SYSCFG0_BOOTCFG_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_BOOTCFG_OFFSET)))

/*--------*/
#define SYSCFG_BOOTCFG_R_BOOTMODE_MASK        ((uint32_t)0x0000FFFF)
#define SYSCFG_BOOTCFG_R_BOOTMODE_SHIFT         (0)

#define SYSCFG_BOOTCFG_BOOTMODE_MASK          ((uint32_t)0x0000FFFF)
/*--------*/

/**********************************************************************************************
************************************** 4 CHIPREVIDR ***********************************************
**********************************************************************************************/
#define SYSCFG0_CHIPREVIDR                    (((SYSCFG_CHIPREVIDR_TypeDef*)(SYSCFG0_BASE+SYSCFG_CHIPREVIDR_OFFSET )))
#define SYSCFG0_CHIPREVIDR_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_CHIPREVIDR_OFFSET)))

/*--------*/
#define SYSCFG_CHIPREVIDR_R_CHIPREVID_MASK        ((uint32_t)0x0000003F)
#define SYSCFG_CHIPREVIDR_R_CHIPREVID_SHIFT         (0)

#define SYSCFG_CHIPREVIDR_CHIPREVID_MASK          ((uint32_t)0x0000003F)
/*--------*/

/**********************************************************************************************
************************************** 5 KICK0R ***********************************************
**********************************************************************************************/
#define SYSCFG0_KICK0R                    (((SYSCFG_KICK0R_TypeDef*)(SYSCFG0_BASE+SYSCFG_KICK0R_OFFSET )))
#define SYSCFG0_KICK0R_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_KICK0R_OFFSET)))

/*--------*/
#define SYSCFG_KICK0R_R_KICK0_KEY        ((uint32_t)0x83E70B13)
#define SYSCFG_KICK0R_R_KICK0_MASK        ((uint32_t)0xFFFFFFFF)
#define SYSCFG_KICK0R_R_KICK0_SHIFT         (0)

#define SYSCFG_KICK0R_KICK0_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 6 KICK1R ***********************************************
**********************************************************************************************/
#define SYSCFG0_KICK1R                    (((SYSCFG_KICK1R_TypeDef*)(SYSCFG0_BASE+SYSCFG_KICK1R_OFFSET )))
#define SYSCFG0_KICK1R_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_KICK1R_OFFSET)))

/*--------*/
#define SYSCFG_KICK1R_R_KICK1_KEY        ((uint32_t)0x95A4F1E0)
#define SYSCFG_KICK1R_R_KICK1_MASK        ((uint32_t)0xFFFFFFFF)
#define SYSCFG_KICK1R_R_KICK1_SHIFT         (0)

#define SYSCFG_KICK1R_KICK1_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 7 HOST1CFG ***********************************************
**********************************************************************************************/
#define SYSCFG0_HOST1CFG                    (((SYSCFG_HOST1CFG_TypeDef*)(SYSCFG0_BASE+SYSCFG_HOST1CFG_OFFSET )))
#define SYSCFG0_HOST1CFG_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_HOST1CFG_OFFSET)))

/*--------*/
#define SYSCFG_HOST1CFG_R_DSP_ISTP_RST_VAL_MASK        ((uint32_t)0x0000FC00)
#define SYSCFG_HOST1CFG_R_DSP_ISTP_RST_VAL_SHIFT         (10)

#define SYSCFG_HOST1CFG_DSP_ISTP_RST_VAL_MASK          ((uint32_t)0x0000003F)
/*--------*/


/**********************************************************************************************
************************************** 8 IRAWSTAT ***********************************************
**********************************************************************************************/
#define SYSCFG0_IRAWSTAT                    (((SYSCFG_IRAWSTAT_TypeDef*)(SYSCFG0_BASE+SYSCFG_IRAWSTAT_OFFSET )))
#define SYSCFG0_IRAWSTAT_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_IRAWSTAT_OFFSET)))

/*--------*/
#define SYSCFG_IRAWSTAT_R_PROTERR_MASK        ((uint32_t)0x00000001)
#define SYSCFG_IRAWSTAT_R_PROTERR_SHIFT         (0)

#define SYSCFG_IRAWSTAT_PROTERR_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_IRAWSTAT_R_ADDRERR_MASK        ((uint32_t)0x00000002)
#define SYSCFG_IRAWSTAT_R_ADDRERR_SHIFT         (1)

#define SYSCFG_IRAWSTAT_ADDRERR_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 9 IENSTAT ***********************************************
**********************************************************************************************/
#define SYSCFG0_IENSTAT                    (((SYSCFG_IENSTAT_TypeDef*)(SYSCFG0_BASE+SYSCFG_IENSTAT_OFFSET )))
#define SYSCFG0_IENSTAT_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_IENSTAT_OFFSET)))

/*--------*/
#define SYSCFG_IENSTAT_R_PROTERR_MASK        ((uint32_t)0x00000001)
#define SYSCFG_IENSTAT_R_PROTERR_SHIFT         (0)

#define SYSCFG_IENSTAT_PROTERR_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_IENSTAT_R_ADDRERR_MASK        ((uint32_t)0x00000002)
#define SYSCFG_IENSTAT_R_ADDRERR_SHIFT         (1)

#define SYSCFG_IENSTAT_ADDRERR_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 10 IENSET ***********************************************
**********************************************************************************************/
#define SYSCFG0_IENSET                    (((SYSCFG_IENSET_TypeDef*)(SYSCFG0_BASE+SYSCFG_IENSET_OFFSET )))
#define SYSCFG0_IENSET_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_IENSET_OFFSET)))

/*--------*/
#define SYSCFG_IENSET_R_PROTERR_EN_MASK        ((uint32_t)0x00000001)
#define SYSCFG_IENSET_R_PROTERR_EN_SHIFT         (0)

#define SYSCFG_IENSET_PROTERR_EN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_IENSET_R_ADDRERR_EN_MASK        ((uint32_t)0x00000002)
#define SYSCFG_IENSET_R_ADDRERR_EN_SHIFT         (1)

#define SYSCFG_IENSET_ADDRERR_EN_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 11 IENCLR ***********************************************
**********************************************************************************************/
#define SYSCFG0_IENCLR                    (((SYSCFG_IENCLR_TypeDef*)(SYSCFG0_BASE+SYSCFG_IENCLR_OFFSET )))
#define SYSCFG0_IENCLR_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_IENCLR_OFFSET)))

/*--------*/
#define SYSCFG_IENCLR_R_PROTERR_CLR_MASK        ((uint32_t)0x00000001)
#define SYSCFG_IENCLR_R_PROTERR_CLR_SHIFT         (0)

#define SYSCFG_IENCLR_PROTERR_CLR_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_IENCLR_R_ADDRERR_CLR_MASK        ((uint32_t)0x00000002)
#define SYSCFG_IENCLR_R_ADDRERR_CLR_SHIFT         (1)

#define SYSCFG_IENCLR_ADDRERR_CLR_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 12 EOI ***********************************************
**********************************************************************************************/
#define SYSCFG0_EOI                    (((SYSCFG_EOI_TypeDef*)(SYSCFG0_BASE+SYSCFG_EOI_OFFSET )))
#define SYSCFG0_EOI_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_EOI_OFFSET)))

/*--------*/
#define SYSCFG_EOI_R_EOIVECT_MASK        ((uint32_t)0x000000FF)
#define SYSCFG_EOI_R_EOIVECT_SHIFT         (0)

#define SYSCFG_EOI_EOIVECT_MASK          ((uint32_t)0x000000FF)
/*--------*/

/**********************************************************************************************
************************************** 13 FLTADDR ***********************************************
**********************************************************************************************/
#define SYSCFG0_FLTADDR                    (((SYSCFG_FLTADDR_TypeDef*)(SYSCFG0_BASE+SYSCFG_FLTADDR_OFFSET )))
#define SYSCFG0_FLTADDR_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_FLTADDR_OFFSET)))

/*--------*/
#define SYSCFG_FLTADDR_R_REV_MASK        ((uint32_t)0xFFFFFFFF)
#define SYSCFG_FLTADDR_R_REV_SHIFT         (0)

#define SYSCFG_FLTADDR_REV_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 14 FLTSTAT ***********************************************
**********************************************************************************************/
#define SYSCFG0_FLTSTAT                    (((SYSCFG_FLTSTAT_TypeDef*)(SYSCFG0_BASE+SYSCFG_FLTSTAT_OFFSET )))
#define SYSCFG0_FLTSTAT_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_FLTSTAT_OFFSET)))

/*--------*/
#define SYSCFG_FLTSTAT_R_TYPE_MASK         ((uint32_t)0x0000003F)
#define SYSCFG_FLTSTAT_R_TYPE_SHIFT        (0)

#define SYSCFG_FLTSTAT_TYPE_MASK          ((uint32_t)0x0000003F)
/*--------*/
/*--------*/
#define SYSCFG_FLTSTAT_R_PRIVID_MASK         ((uint32_t)0x00001E00)
#define SYSCFG_FLTSTAT_R_PRIVID_SHIFT        (9)

#define SYSCFG_FLTSTAT_PRIVID_MASK          ((uint32_t)0x0000000F)
/*--------*/
/*--------*/
#define SYSCFG_FLTSTAT_R_MSTID_MASK         ((uint32_t)0x00FF0000)
#define SYSCFG_FLTSTAT_R_MSTID_SHIFT        (16)

#define SYSCFG_FLTSTAT_MSTID_MASK          ((uint32_t)0x000000FF)
/*--------*/
/**********************************************************************************************
************************************** 15 MSTPRI0 ***********************************************
**********************************************************************************************/
#define SYSCFG0_MSTPRI0                    (((SYSCFG_MSTPRI0_TypeDef*)(SYSCFG0_BASE+SYSCFG_MSTPRI0_OFFSET )))
#define SYSCFG0_MSTPRI0_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_MSTPRI0_OFFSET)))

/*--------*/
#define SYSCFG_MSTPRI0_R_DSP_MDMA_MASK         ((uint32_t)0x00000700)
#define SYSCFG_MSTPRI0_R_DSP_MDMA_SHIFT        (8)

#define SYSCFG_MSTPRI0_DSP_MDMA_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI0_R_DSP_CFG_MASK         ((uint32_t)0x00007000)
#define SYSCFG_MSTPRI0_R_DSP_CFG_SHIFT        (12)

#define SYSCFG_MSTPRI0_DSP_CFG_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI0_R_UPP_MASK         ((uint32_t)0x00070000)
#define SYSCFG_MSTPRI0_R_UPP_SHIFT        (16)

#define SYSCFG_MSTPRI0_UPP_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI0_R_SATA_MASK        ((uint32_t)0x00700000)
#define SYSCFG_MSTPRI0_R_SATA_SHIFT       (20)

#define SYSCFG_MSTPRI0_SATA_MASK          ((uint32_t)0x00000007)
/*--------*/
/**********************************************************************************************
************************************** 16 MSTPRI1 ***********************************************
**********************************************************************************************/
#define SYSCFG0_MSTPRI1                    (((SYSCFG_MSTPRI1_TypeDef*)(SYSCFG0_BASE+SYSCFG_MSTPRI1_OFFSET )))
#define SYSCFG0_MSTPRI1_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_MSTPRI1_OFFSET)))
/*--------*/
#define SYSCFG_MSTPRI1_R_PRU0_MASK        ((uint32_t)0x00000007)
#define SYSCFG_MSTPRI1_R_PRU0_SHIFT       (0)

#define SYSCFG_MSTPRI1_PRU0_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI1_R_PRU1_MASK         ((uint32_t)0x00000070)
#define SYSCFG_MSTPRI1_R_PRU1_SHIFT        (4)

#define SYSCFG_MSTPRI1_PRU1_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI1_R_EDMA30TC0_MASK         ((uint32_t)0x00000700)
#define SYSCFG_MSTPRI1_R_EDMA30TC0_SHIFT        (8)

#define SYSCFG_MSTPRI1_EDMA30TC0_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI1_R_EDMA30TC1_MASK         ((uint32_t)0x00007000)
#define SYSCFG_MSTPRI1_R_EDMA30TC1_SHIFT        (12)

#define SYSCFG_MSTPRI1_EDMA30TC1_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI1_R_EDMA31TC0_MASK         ((uint32_t)0x00070000)
#define SYSCFG_MSTPRI1_R_EDMA31TC0_SHIFT        (16)

#define SYSCFG_MSTPRI1_EDMA31TC0_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI1_R_VPIF_DMA_0_MASK        ((uint32_t)0x07000000)
#define SYSCFG_MSTPRI1_R_VPIF_DMA_0_SHIFT       (24)

#define SYSCFG_MSTPRI1_VPIF_DMA_0_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI1_R_VPIF_DMA_1_MASK        ((uint32_t)0x70000000)
#define SYSCFG_MSTPRI1_R_VPIF_DMA_1_SHIFT       (28)

#define SYSCFG_MSTPRI1_VPIF_DMA_1_MASK          ((uint32_t)0x00000007)
/*--------*/
/**********************************************************************************************
************************************** 17 MSTPRI2 ***********************************************
**********************************************************************************************/
#define SYSCFG0_MSTPRI2                    (((SYSCFG_MSTPRI2_TypeDef*)(SYSCFG0_BASE+SYSCFG_MSTPRI2_OFFSET )))
#define SYSCFG0_MSTPRI2_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_MSTPRI2_OFFSET)))
/*--------*/
#define SYSCFG_MSTPRI2_R_EMAC_MASK        ((uint32_t)0x00000007)
#define SYSCFG_MSTPRI2_R_EMAC_SHIFT       (0)

#define SYSCFG_MSTPRI2_EMAC_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI2_R_USB0CFG_MASK         ((uint32_t)0x00000700)
#define SYSCFG_MSTPRI2_R_USB0CFG_SHIFT        (8)

#define SYSCFG_MSTPRI2_USB0CFG_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI2_R_USB0CDMA_MASK         ((uint32_t)0x00007000)
#define SYSCFG_MSTPRI2_R_USB0CDMA_SHIFT        (12)

#define SYSCFG_MSTPRI2_USB0CDMA_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI2_R_UHPI_MASK         ((uint32_t)0x00700000)
#define SYSCFG_MSTPRI2_R_UHPI_SHIFT        (20)

#define SYSCFG_MSTPRI2_UHPI_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI2_R_USB1_MASK        ((uint32_t)0x07000000)
#define SYSCFG_MSTPRI2_R_USB1_SHIFT       (24)

#define SYSCFG_MSTPRI2_USB1_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_MSTPRI2_R_LCDC_MASK        ((uint32_t)0x70000000)
#define SYSCFG_MSTPRI2_R_LCDC_SHIFT       (28)

#define SYSCFG_MSTPRI2_LCDC_MASK          ((uint32_t)0x00000007)
/*--------*/




/**********************************************************************************************
************************************** 18-37 PINMUX ***********************************************
**********************************************************************************************/
#define SYSCFG0_PINMUX0                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX0_OFFSET )))
#define SYSCFG0_PINMUX0_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX0_OFFSET)))
#define SYSCFG0_PINMUX1                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX1_OFFSET )))
#define SYSCFG0_PINMUX1_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX1_OFFSET)))
#define SYSCFG0_PINMUX2                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX2_OFFSET )))
#define SYSCFG0_PINMUX2_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX2_OFFSET)))
#define SYSCFG0_PINMUX3                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX3_OFFSET )))
#define SYSCFG0_PINMUX3_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX3_OFFSET)))
#define SYSCFG0_PINMUX4                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX4_OFFSET )))
#define SYSCFG0_PINMUX4_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX4_OFFSET)))
#define SYSCFG0_PINMUX5                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX5_OFFSET )))
#define SYSCFG0_PINMUX5_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX5_OFFSET)))
#define SYSCFG0_PINMUX6                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX6_OFFSET )))
#define SYSCFG0_PINMUX6_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX6_OFFSET)))
#define SYSCFG0_PINMUX7                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX7_OFFSET )))
#define SYSCFG0_PINMUX7_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX7_OFFSET)))
#define SYSCFG0_PINMUX8                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX8_OFFSET )))
#define SYSCFG0_PINMUX8_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX8_OFFSET)))
#define SYSCFG0_PINMUX9                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX9_OFFSET )))
#define SYSCFG0_PINMUX9_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX9_OFFSET)))
#define SYSCFG0_PINMUX10                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX10_OFFSET )))
#define SYSCFG0_PINMUX10_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX10_OFFSET)))
#define SYSCFG0_PINMUX11                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX11_OFFSET )))
#define SYSCFG0_PINMUX11_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX11_OFFSET)))
#define SYSCFG0_PINMUX12                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX12_OFFSET )))
#define SYSCFG0_PINMUX12_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX12_OFFSET)))
#define SYSCFG0_PINMUX13                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX13_OFFSET )))
#define SYSCFG0_PINMUX13_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX13_OFFSET)))
#define SYSCFG0_PINMUX14                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX14_OFFSET )))
#define SYSCFG0_PINMUX14_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX14_OFFSET)))
#define SYSCFG0_PINMUX15                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX15_OFFSET )))
#define SYSCFG0_PINMUX15_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX15_OFFSET)))
#define SYSCFG0_PINMUX16                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX16_OFFSET )))
#define SYSCFG0_PINMUX16_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX16_OFFSET)))
#define SYSCFG0_PINMUX17                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX17_OFFSET )))
#define SYSCFG0_PINMUX17_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX17_OFFSET)))
#define SYSCFG0_PINMUX18                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX18_OFFSET )))
#define SYSCFG0_PINMUX18_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX18_OFFSET)))
#define SYSCFG0_PINMUX19                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX19_OFFSET )))
#define SYSCFG0_PINMUX19_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX19_OFFSET)))
#define SYSCFG0_PINMUX(n)                    (((SYSCFG_PINMUX_TypeDef*)(SYSCFG0_BASE+SYSCFG0_PINMUX0_OFFSET +((n)*4) )))
#define SYSCFG0_PINMUX_R(n)                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG0_PINMUX0_OFFSET +((n)*4))))

/*--------*/
#define SYSCFG_PINMUX_R_PINMUX_3_0_MASK        ((uint32_t)0x0000000F)
#define SYSCFG_PINMUX_R_PINMUX_3_0_SHIFT       (0)

#define SYSCFG_PINMUX_PINMUX_3_0_MASK          ((uint32_t)0x0000000F)
/*--------*/

/*--------*/
#define SYSCFG_PINMUX_R_PINMUX_7_4_MASK        ((uint32_t)0x000000F0)
#define SYSCFG_PINMUX_R_PINMUX_7_4_SHIFT       (4)

#define SYSCFG_PINMUX_PINMUX_7_4_MASK          ((uint32_t)0x0000000F)
/*--------*/

/*--------*/
#define SYSCFG_PINMUX_R_PINMUX_11_8_MASK        ((uint32_t)0x00000F00)
#define SYSCFG_PINMUX_R_PINMUX_11_8_SHIFT       (8)

#define SYSCFG_PINMUX_PINMUX_11_8_MASK          ((uint32_t)0x0000000F)
/*--------*/

/*--------*/
#define SYSCFG_PINMUX_R_PINMUX_15_12_MASK        ((uint32_t)0x0000F000)
#define SYSCFG_PINMUX_R_PINMUX_15_12_SHIFT       (12)

#define SYSCFG_PINMUX_PINMUX_15_12_MASK          ((uint32_t)0x0000000F)
/*--------*/

/*--------*/
#define SYSCFG_PINMUX_R_PINMUX_19_16_MASK        ((uint32_t)0x000F0000)
#define SYSCFG_PINMUX_R_PINMUX_19_16_SHIFT       (16)

#define SYSCFG_PINMUX_PINMUX_19_16_MASK          ((uint32_t)0x0000000F)
/*--------*/

/*--------*/
#define SYSCFG_PINMUX_R_PINMUX_23_20_MASK        ((uint32_t)0x00F00000)
#define SYSCFG_PINMUX_R_PINMUX_23_20_SHIFT       (20)

#define SYSCFG_PINMUX_PINMUX_23_20_MASK          ((uint32_t)0x0000000F)
/*--------*/

/*--------*/
#define SYSCFG_PINMUX_R_PINMUX_27_24_MASK        ((uint32_t)0x0F000000)
#define SYSCFG_PINMUX_R_PINMUX_27_24_SHIFT       (24)

#define SYSCFG_PINMUX_PINMUX_27_24_MASK          ((uint32_t)0x0000000F)
/*--------*/

/*--------*/
#define SYSCFG_PINMUX_R_PINMUX_31_28_MASK        ((uint32_t)0xF0000000)
#define SYSCFG_PINMUX_R_PINMUX_31_28_SHIFT       (28)

#define SYSCFG_PINMUX_PINMUX_31_28_MASK          ((uint32_t)0x0000000F)
/*--------*/

/**********************************************************************************************
************************************** 38 SUSPSRC ***********************************************
**********************************************************************************************/
#define SYSCFG0_SUSPSRC                    (((SYSCFG_SUSPSRC_TypeDef*)(SYSCFG0_BASE+SYSCFG_SUSPSRC_OFFSET )))
#define SYSCFG0_SUSPSRC_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_SUSPSRC_OFFSET)))
/*--------*/
#define SYSCFG_SUSPSRC_R_ECAP0SRC_MASK        ((uint32_t)0x00000001)
#define SYSCFG_SUSPSRC_R_ECAP0SRC_SHIFT       (0)

#define SYSCFG_SUSPSRC_ECAP0SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_ECAP1SRC_MASK        ((uint32_t)0x00000002)
#define SYSCFG_SUSPSRC_R_ECAP1SRC_SHIFT       (1)

#define SYSCFG_SUSPSRC_ECAP1SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_ECAP2SRC_MASK        ((uint32_t)0x00000004)
#define SYSCFG_SUSPSRC_R_ECAP2SRC_SHIFT       (2)

#define SYSCFG_SUSPSRC_ECAP2SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_TIMER64P_3SRC_MASK        ((uint32_t)0x00000008)
#define SYSCFG_SUSPSRC_R_TIMER64P_3SRC_SHIFT       (3)

#define SYSCFG_SUSPSRC_TIMER64P_3SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_UPPSRC_MASK        ((uint32_t)0x00000010)
#define SYSCFG_SUSPSRC_R_UPPSRC_SHIFT       (4)

#define SYSCFG_SUSPSRC_UPPSRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_EMACSRC_MASK        ((uint32_t)0x00000020)
#define SYSCFG_SUSPSRC_R_EMACSRC_SHIFT       (5)

#define SYSCFG_SUSPSRC_EMACSRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_PRUSRC_MASK        ((uint32_t)0x00000040)
#define SYSCFG_SUSPSRC_R_PRUSRC_SHIFT       (6)

#define SYSCFG_SUSPSRC_PRUSRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_MCBSP0SRC_MASK        ((uint32_t)0x00000080)
#define SYSCFG_SUSPSRC_R_MCBSP0SRC_SHIFT       (7)

#define SYSCFG_SUSPSRC_MCBSP0SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_MCBSP1SRC_MASK        ((uint32_t)0x00000100)
#define SYSCFG_SUSPSRC_R_MCBSP1SRC_SHIFT       (8)

#define SYSCFG_SUSPSRC_MCBSP1SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_USB0SRC_MASK        ((uint32_t)0x00000200)
#define SYSCFG_SUSPSRC_R_USB0SRC_SHIFT       (9)

#define SYSCFG_SUSPSRC_USB0SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_HPISRC_MASK        ((uint32_t)0x00001000)
#define SYSCFG_SUSPSRC_R_HPISRC_SHIFT       (12)

#define SYSCFG_SUSPSRC_HPISRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_SATASRC_MASK        ((uint32_t)0x00002000)
#define SYSCFG_SUSPSRC_R_SATASRC_SHIFT       (13)

#define SYSCFG_SUSPSRC_SATASRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_VPIFSRC_MASK        ((uint32_t)0x00004000)
#define SYSCFG_SUSPSRC_R_VPIFSRC_SHIFT       (14)

#define SYSCFG_SUSPSRC_VPIFSRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_I2C0SRC_MASK        ((uint32_t)0x00010000)
#define SYSCFG_SUSPSRC_R_I2C0SRC_SHIFT       (16)

#define SYSCFG_SUSPSRC_I2C0SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_I2C1SRC_MASK        ((uint32_t)0x00020000)
#define SYSCFG_SUSPSRC_R_I2C1SRC_SHIFT       (17)

#define SYSCFG_SUSPSRC_I2C1SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_UART0SRC_MASK        ((uint32_t)0x00040000)
#define SYSCFG_SUSPSRC_R_UART0SRC_SHIFT       (18)

#define SYSCFG_SUSPSRC_UART0SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_UART1SRC_MASK        ((uint32_t)0x00080000)
#define SYSCFG_SUSPSRC_R_UART1SRC_SHIFT       (19)

#define SYSCFG_SUSPSRC_UART1SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_UART2SRC_MASK        ((uint32_t)0x00100000)
#define SYSCFG_SUSPSRC_R_UART2SRC_SHIFT       (20)

#define SYSCFG_SUSPSRC_UART2SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_SPI0SRC_MASK        ((uint32_t)0x00200000)
#define SYSCFG_SUSPSRC_R_SPI0SRC_SHIFT       (21)

#define SYSCFG_SUSPSRC_SPI0SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_SPI1SRC_MASK        ((uint32_t)0x00400000)
#define SYSCFG_SUSPSRC_R_SPI1SRC_SHIFT       (22)

#define SYSCFG_SUSPSRC_SPI1SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_EPWM0SRC_MASK        ((uint32_t)0x00800000)
#define SYSCFG_SUSPSRC_R_EPWM0SRC_SHIFT       (23)

#define SYSCFG_SUSPSRC_EPWM0SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_EPWM1SRC_MASK        ((uint32_t)0x01000000)
#define SYSCFG_SUSPSRC_R_EPWM1SRC_SHIFT       (24)

#define SYSCFG_SUSPSRC_EPWM1SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_TIMER64P_0SRC_MASK        ((uint32_t)0x08000000)
#define SYSCFG_SUSPSRC_R_TIMER64P_0SRC_SHIFT       (27)

#define SYSCFG_SUSPSRC_TIMER64P_0SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_TIMER64P_1SRC_MASK        ((uint32_t)0x10000000)
#define SYSCFG_SUSPSRC_R_TIMER64P_1SRC_SHIFT       (28)

#define SYSCFG_SUSPSRC_TIMER64P_1SRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_SUSPSRC_R_TIMER64P_2SRC_MASK        ((uint32_t)0x20000000)
#define SYSCFG_SUSPSRC_R_TIMER64P_2SRC_SHIFT       (29)

#define SYSCFG_SUSPSRC_TIMER64P_2SRC_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 38 CHIPSIG ***********************************************
**********************************************************************************************/
#define SYSCFG0_CHIPSIG                    (((SYSCFG_CHIPSIG_TypeDef*)(SYSCFG0_BASE+SYSCFG_CHIPSIG_OFFSET )))
#define SYSCFG0_CHIPSIG_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_CHIPSIG_OFFSET)))
/*--------*/
#define SYSCFG_CHIPSIG_R_CHIPSIG2_MASK        ((uint32_t)0x00000002)
#define SYSCFG_CHIPSIG_R_CHIPSIG2_SHIFT       (1)

#define SYSCFG_CHIPSIG_CHIPSIG2_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CHIPSIG_R_CHIPSIG3_MASK        ((uint32_t)0x00000004)
#define SYSCFG_CHIPSIG_R_CHIPSIG3_SHIFT       (2)

#define SYSCFG_CHIPSIG_CHIPSIG3_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CHIPSIG_R_CHIPSIG4_MASK        ((uint32_t)0x00000008)
#define SYSCFG_CHIPSIG_R_CHIPSIG4_SHIFT       (3)

#define SYSCFG_CHIPSIG_CHIPSIG4_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 39 CHIPSIG_CLR ***********************************************
**********************************************************************************************/
#define SYSCFG0_CHIPSIG_CLR                    (((SYSCFG_CHIPSIG_CLR_TypeDef*)(SYSCFG0_BASE+SYSCFG_CHIPSIG_CLR_OFFSET )))
#define SYSCFG0_CHIPSIG_CLR_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_CHIPSIG_CLR_OFFSET)))
/*--------*/
#define SYSCFG_CHIPSIG_CLR_R_CHIPSIG2_MASK        ((uint32_t)0x00000002)
#define SYSCFG_CHIPSIG_CLR_R_CHIPSIG2_SHIFT       (1)

#define SYSCFG_CHIPSIG_CLR_CHIPSIG2_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CHIPSIG_CLR_R_CHIPSIG3_MASK        ((uint32_t)0x00000004)
#define SYSCFG_CHIPSIG_CLR_R_CHIPSIG3_SHIFT       (2)

#define SYSCFG_CHIPSIG_CLR_CHIPSIG3_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CHIPSIG_CLR_R_CHIPSIG4_MASK        ((uint32_t)0x00000008)
#define SYSCFG_CHIPSIG_CLR_R_CHIPSIG4_SHIFT       (3)

#define SYSCFG_CHIPSIG_CLR_CHIPSIG4_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 39 CFGCHIP0 ***********************************************
**********************************************************************************************/
#define SYSCFG0_CFGCHIP0                    (((SYSCFG_CFGCHIP0_TypeDef*)(SYSCFG0_BASE+SYSCFG_CFGCHIP0_OFFSET )))
#define SYSCFG0_CFGCHIP0_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_CFGCHIP0_OFFSET)))
/*--------*/
#define SYSCFG_CFGCHIP0_R_EDMA30TC0DBS_MASK        ((uint32_t)0x00000003)
#define SYSCFG_CFGCHIP0_R_EDMA30TC0DBS_SHIFT       (0)

#define SYSCFG_CFGCHIP0_EDMA30TC0DBS_MASK          ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP0_R_EDMA30TC1DBS_MASK        ((uint32_t)0x0000000C)
#define SYSCFG_CFGCHIP0_R_EDMA30TC1DBS_SHIFT       (2)

#define SYSCFG_CFGCHIP0_EDMA30TC1DBS_MASK          ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP0_R_PLL_MASTER_LOCK_MASK        ((uint32_t)0x00000010)
#define SYSCFG_CFGCHIP0_R_PLL_MASTER_LOCK_SHIFT       (4)

#define SYSCFG_CFGCHIP0_PLL_MASTER_LOCK_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 40 CFGCHIP1 ***********************************************
**********************************************************************************************/
#define SYSCFG0_CFGCHIP1                    (((SYSCFG_CFGCHIP1_TypeDef*)(SYSCFG0_BASE+SYSCFG_CFGCHIP1_OFFSET )))
#define SYSCFG0_CFGCHIP1_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_CFGCHIP1_OFFSET)))
/*--------*/
#define SYSCFG_CFGCHIP1_R_AMUTESEL0_MASK        ((uint32_t)0x0000000F)
#define SYSCFG_CFGCHIP1_R_AMUTESEL0_SHIFT       (0)

#define SYSCFG_CFGCHIP1_AMUTESEL0_MASK          ((uint32_t)0x0000000F)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP1_R_TBCLKSYNC_MASK        ((uint32_t)0x00001000)
#define SYSCFG_CFGCHIP1_R_TBCLKSYNC_SHIFT       (12)

#define SYSCFG_CFGCHIP1_TBCLKSYNC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP1_R_EDMA31TC0DBS_MASK        ((uint32_t)0x00006000)
#define SYSCFG_CFGCHIP1_R_EDMA31TC0DBS_SHIFT       (13)

#define SYSCFG_CFGCHIP1_EDMA31TC0DBS_MASK          ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP1_R_HPIENA_MASK        ((uint32_t)0x00008000)
#define SYSCFG_CFGCHIP1_R_HPIENA_SHIFT       (15)

#define SYSCFG_CFGCHIP1_HPIENA_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP1_R_HPIBYTEAD_MASK        ((uint32_t)0x00010000)
#define SYSCFG_CFGCHIP1_R_HPIBYTEAD_SHIFT       (16)

#define SYSCFG_CFGCHIP1_HPIBYTEAD_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP1_R_CAP0SRC_MASK        ((uint32_t)0x003E0000)
#define SYSCFG_CFGCHIP1_R_CAP0SRC_SHIFT       (17)

#define SYSCFG_CFGCHIP1_CAP0SRC_MASK          ((uint32_t)0x0000001F)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP1_R_CAP1SRC_MASK        ((uint32_t)0x07C00000)
#define SYSCFG_CFGCHIP1_R_CAP1SRC_SHIFT       (22)

#define SYSCFG_CFGCHIP1_CAP1SRC_MASK          ((uint32_t)0x0000001F)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_CAP1SRC_MASK        ((uint32_t)0xF1000000)
#define SYSCFG_CFGCHIP2_R_CAP1SRC_SHIFT       (27)

#define SYSCFG_CFGCHIP2_CAP1SRC_MASK          ((uint32_t)0x0000001F)
/*--------*/



/**********************************************************************************************
************************************** 41 CFGCHIP2 ***********************************************
**********************************************************************************************/
#define SYSCFG0_CFGCHIP2                    (((SYSCFG_CFGCHIP2_TypeDef*)(SYSCFG0_BASE+SYSCFG_CFGCHIP2_OFFSET )))
#define SYSCFG0_CFGCHIP2_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_CFGCHIP2_OFFSET)))
/*--------*/
#define SYSCFG_CFGCHIP2_R_USB0REF_FREQ_MASK        ((uint32_t)0x0000000F)
#define SYSCFG_CFGCHIP2_R_USB0REF_FREQ_SHIFT       (0)

#define SYSCFG_CFGCHIP2_USB0REF_FREQ_MASK          ((uint32_t)0x0000000F)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_USB0VBDTCTEN_MASK        ((uint32_t)0x00000010)
#define SYSCFG_CFGCHIP2_R_USB0VBDTCTEN_SHIFT       (4)

#define SYSCFG_CFGCHIP2_USB0VBDTCTEN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_USB0SESNDEN_MASK        ((uint32_t)0x00000020)
#define SYSCFG_CFGCHIP2_R_USB0SESNDEN_SHIFT       (5)

#define SYSCFG_CFGCHIP2_USB0SESNDEN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_USB0PHY_PLLON_MASK        ((uint32_t)0x00000040)
#define SYSCFG_CFGCHIP2_R_USB0PHY_PLLON_SHIFT       (6)

#define SYSCFG_CFGCHIP2_USB0PHY_PLLON_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_USB1SUSPENDM_MASK        ((uint32_t)0x00000080)
#define SYSCFG_CFGCHIP2_R_USB1SUSPENDM_SHIFT       (7)

#define SYSCFG_CFGCHIP2_USB1SUSPENDM_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_USB0DATPOL_MASK        ((uint32_t)0x00000100)
#define SYSCFG_CFGCHIP2_R_USB0DATPOL_SHIFT       (8)

#define SYSCFG_CFGCHIP2_USB0DATPOL_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_USB0OTGPWRDN_MASK        ((uint32_t)0x00000200)
#define SYSCFG_CFGCHIP2_R_USB0OTGPWRDN_SHIFT       (9)

#define SYSCFG_CFGCHIP2_USB0OTGPWRDN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_USB0PHYPWDN_MASK        ((uint32_t)0x00000400)
#define SYSCFG_CFGCHIP2_R_USB0PHYPWDN_SHIFT       (10)

#define SYSCFG_CFGCHIP2_USB0PHYPWDN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_USB0PHYCLKMUX_MASK        ((uint32_t)0x00000800)
#define SYSCFG_CFGCHIP2_R_USB0PHYCLKMUX_SHIFT       (11)

#define SYSCFG_CFGCHIP2_USB0PHYCLKMUX_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_USB1PHYCLKMUX_MASK        ((uint32_t)0x00001000)
#define SYSCFG_CFGCHIP2_R_USB1PHYCLKMUX_SHIFT       (12)

#define SYSCFG_CFGCHIP2_USB1PHYCLKMUX_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_USB0OTGMODE_MASK        ((uint32_t)0x00006000)
#define SYSCFG_CFGCHIP2_R_USB0OTGMODE_SHIFT       (13)

#define SYSCFG_CFGCHIP2_USB0OTGMODE_MASK          ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_RESET_MASK        ((uint32_t)0x00008000)
#define SYSCFG_CFGCHIP2_R_RESET_SHIFT       (15)

#define SYSCFG_CFGCHIP2_RESET_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_USB0VBUSSENSE_MASK        ((uint32_t)0x00010000)
#define SYSCFG_CFGCHIP2_R_USB0VBUSSENSE_SHIFT       (16)

#define SYSCFG_CFGCHIP2_USB0VBUSSENSE_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP2_R_USB0PHYCLKGD_MASK        ((uint32_t)0x00020000)
#define SYSCFG_CFGCHIP2_R_USB0PHYCLKGD_SHIFT       (17)

#define SYSCFG_CFGCHIP2_USB0PHYCLKGD_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 42 CFGCHIP3 ***********************************************
**********************************************************************************************/
#define SYSCFG0_CFGCHIP3                    (((SYSCFG_CFGCHIP3_TypeDef*)(SYSCFG0_BASE+SYSCFG_CFGCHIP3_OFFSET )))
#define SYSCFG0_CFGCHIP3_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_CFGCHIP3_OFFSET)))
/*--------*/
#define SYSCFG_CFGCHIP3_R_EMA_CLKSRC_MASK        ((uint32_t)0x00000002)
#define SYSCFG_CFGCHIP3_R_EMA_CLKSRC_SHIFT       (1)

#define SYSCFG_CFGCHIP3_EMA_CLKSRC_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 43 CFGCHIP3 ***********************************************
**********************************************************************************************/
#define SYSCFG0_CFGCHIP3                    (((SYSCFG_CFGCHIP3_TypeDef*)(SYSCFG0_BASE+SYSCFG_CFGCHIP3_OFFSET )))
#define SYSCFG0_CFGCHIP3_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_CFGCHIP3_OFFSET)))
/*--------*/
#define SYSCFG_CFGCHIP3_R_EMA_CLKSRC_MASK        ((uint32_t)0x00000002)
#define SYSCFG_CFGCHIP3_R_EMA_CLKSRC_SHIFT       (1)

#define SYSCFG_CFGCHIP3_EMA_CLKSRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP3_R_DIV45PENA_MASK        ((uint32_t)0x00000004)
#define SYSCFG_CFGCHIP3_R_DIV45PENA_SHIFT       (2)

#define SYSCFG_CFGCHIP3_DIV45PENA_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP3_R_PRUEVTSEL_MASK        ((uint32_t)0x00000008)
#define SYSCFG_CFGCHIP3_R_PRUEVTSEL_SHIFT       (3)

#define SYSCFG_CFGCHIP3_PRUEVTSEL_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP3_R_ASYNC3_CLKSRC_MASK        ((uint32_t)0x00000010)
#define SYSCFG_CFGCHIP3_R_ASYNC3_CLKSRC_SHIFT       (4)

#define SYSCFG_CFGCHIP3_ASYNC3_CLKSRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP3_R_PLL1_MASTER_LOCK_MASK        ((uint32_t)0x00000020)
#define SYSCFG_CFGCHIP3_R_PLL1_MASTER_LOCK_SHIFT       (5)

#define SYSCFG_CFGCHIP3_PLL1_MASTER_LOCK_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP3_R_UPP_TX_CLKSRC_MASK        ((uint32_t)0x00000040)
#define SYSCFG_CFGCHIP3_R_UPP_TX_CLKSRC_SHIFT       (6)

#define SYSCFG_CFGCHIP3_UPP_TX_CLKSRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_CFGCHIP3_R_RMII_SEL_MASK        ((uint32_t)0x00000100)
#define SYSCFG_CFGCHIP3_R_RMII_SELSHIFT       (8)

#define SYSCFG_CFGCHIP3_RMII_SEL_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 44 CFGCHIP4 ***********************************************
**********************************************************************************************/
#define SYSCFG0_CFGCHIP4                    (((SYSCFG_CFGCHIP4_TypeDef*)(SYSCFG0_BASE+SYSCFG_CFGCHIP4_OFFSET )))
#define SYSCFG0_CFGCHIP4_R                  (*((__IO uint32_t *)(SYSCFG0_BASE+SYSCFG_CFGCHIP4_OFFSET)))
/*--------*/
#define SYSCFG_CFGCHIP4_R_AMUTECLR0_MASK        ((uint32_t)0x00000001)
#define SYSCFG_CFGCHIP4_R_AMUTECLR0_SHIFT       (0)

#define SYSCFG_CFGCHIP4_AMUTECLR0_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 45 VTPIO_CTL ***********************************************
**********************************************************************************************/
#define SYSCFG1_VTPIO_CTL                    (((SYSCFG_VTPIO_CTL_TypeDef*)(SYSCFG1_BASE+SYSCFG_VTPIO_CTL_OFFSET )))
#define SYSCFG1_VTPIO_CTL_R                  (*((__IO uint32_t *)(SYSCFG1_BASE+SYSCFG_VTPIO_CTL_OFFSET)))
/*--------*/
#define SYSCFG_VTPIO_CTL_R_F_MASK        ((uint32_t)0x00000007)
#define SYSCFG_VTPIO_CTL_R_F_SHIFT       (0)

#define SYSCFG_VTPIO_CTL_F_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_VTPIO_CTL_R_D_MASK        ((uint32_t)0x00000038)
#define SYSCFG_VTPIO_CTL_R_D_SHIFT       (3)

#define SYSCFG_VTPIO_CTL_D_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define SYSCFG_VTPIO_CTL_R_POWERDN_MASK        ((uint32_t)0x00000040)
#define SYSCFG_VTPIO_CTL_R_POWERDN_SHIFT       (6)

#define SYSCFG_VTPIO_CTL_POWERDN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_VTPIO_CTL_R_LOCK_MASK        ((uint32_t)0x00000080)
#define SYSCFG_VTPIO_CTL_R_LOCK_SHIFT       (7)

#define SYSCFG_VTPIO_CTL_LOCK_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_VTPIO_CTL_R_PWRSAVE_MASK        ((uint32_t)0x00000100)
#define SYSCFG_VTPIO_CTL_R_PWRSAVE_SHIFT       (8)

#define SYSCFG_VTPIO_CTL_PWRSAVE_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_VTPIO_CTL_R_CLKRZ_MASK        ((uint32_t)0x00002000)
#define SYSCFG_VTPIO_CTL_R_CLKRZ_SHIFT       (13)

#define SYSCFG_VTPIO_CTL_CLKRZ_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_VTPIO_CTL_R_IOPWRDN_MASK        ((uint32_t)0x00004000)
#define SYSCFG_VTPIO_CTL_R_IOPWRDN_SHIFT       (14)

#define SYSCFG_VTPIO_CTL_IOPWRDN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_VTPIO_CTL_R_READY_MASK        ((uint32_t)0x00008000)
#define SYSCFG_VTPIO_CTL_R_READY_SHIFT       (15)

#define SYSCFG_VTPIO_CTL_READY_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_VTPIO_CTL_R_VREFTAP_MASK        ((uint32_t)0x00030000)
#define SYSCFG_VTPIO_CTL_R_VREFTAP_SHIFT       (16)

#define SYSCFG_VTPIO_CTL_VREFTAP_MASK          ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define SYSCFG_VTPIO_CTL_R_VREFEN_MASK        ((uint32_t)0x00040000)
#define SYSCFG_VTPIO_CTL_R_VREFEN_SHIFT       (18)

#define SYSCFG_VTPIO_CTL_VREFEN_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 45 DDR_SLEW ***********************************************
**********************************************************************************************/
#define SYSCFG1_DDR_SLEW                    (((SYSCFG_DDR_SLEW_TypeDef*)(SYSCFG1_BASE+SYSCFG_DDR_SLEW_OFFSET )))
#define SYSCFG1_DDR_SLEW_R                  (*((__IO uint32_t *)(SYSCFG1_BASE+SYSCFG_DDR_SLEW_OFFSET)))
/*--------*/
#define SYSCFG_DDR_SLEW_R_DDR_CMDSLEW_MASK        ((uint32_t)0x00000003)
#define SYSCFG_DDR_SLEW_R_DDR_CMDSLEW_SHIFT       (0)

#define SYSCFG_DDR_SLEW_DDR_CMDSLEW_MASK          ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define SYSCFG_DDR_SLEW_R_DDR_DATASLEW_MASK        ((uint32_t)0x0000000C)
#define SYSCFG_DDR_SLEW_R_DDR_DATASLEW_SHIFT       (2)

#define SYSCFG_DDR_SLEW_DDR_DATASLEW_MASK          ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define SYSCFG_DDR_SLEW_R_CMOSEN_MASK        ((uint32_t)0x00000010)
#define SYSCFG_DDR_SLEW_R_CMOSEN_SHIFT       (4)

#define SYSCFG_DDR_SLEW_CMOSEN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_DDR_SLEW_R_DDR_PDENA_MASK        ((uint32_t)0x00000020)
#define SYSCFG_DDR_SLEW_R_DDR_PDENA_SHIFT       (5)

#define SYSCFG_DDR_SLEW_DDR_PDENA_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_DDR_SLEW_R_ODT_TERMOFF_MASK        ((uint32_t)0x00000300)
#define SYSCFG_DDR_SLEW_R_ODT_TERMOFF_SHIFT       (8)

#define SYSCFG_DDR_SLEW_ODT_TERMOFF_MASK          ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define SYSCFG_DDR_SLEW_R_ODT_TERMON_MASK        ((uint32_t)0x00000C00)
#define SYSCFG_DDR_SLEW_R_ODT_TERMON_SHIFT       (10)

#define SYSCFG_DDR_SLEW_ODT_TERMON_MASK          ((uint32_t)0x00000003)
/*--------*/

/**********************************************************************************************
************************************** 46 DEEPSLEEP ***********************************************
**********************************************************************************************/
#define SYSCFG1_DEEPSLEEP                    (((SYSCFG_DEEPSLEEP_TypeDef*)(SYSCFG1_BASE+SYSCFG_DEEPSLEEP_OFFSET )))
#define SYSCFG1_DEEPSLEEP_R                  (*((__IO uint32_t *)(SYSCFG1_BASE+SYSCFG_DEEPSLEEP_OFFSET)))
/*--------*/
#define SYSCFG_DEEPSLEEP_R_SLEEPCOUNT_MASK        ((uint32_t)0x0000FFFF)
#define SYSCFG_DEEPSLEEP_R_SLEEPCOUNT_SHIFT       (0)

#define SYSCFG_DEEPSLEEP_SLEEPCOUNT_MASK          ((uint32_t)0x0000FFFF)
/*--------*/
/*--------*/
#define SYSCFG_DEEPSLEEP_R_SLEEPCOMPLETE_MASK        ((uint32_t)0x40000000)
#define SYSCFG_DEEPSLEEP_R_SLEEPCOMPLETE_SHIFT       (30)

#define SYSCFG_DEEPSLEEP_SLEEPCOMPLETE_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_DEEPSLEEP_R_SLEEPENABLE_MASK        ((uint32_t)0x80000000)
#define SYSCFG_DEEPSLEEP_R_SLEEPENABLE_SHIFT       (31)

#define SYSCFG_DEEPSLEEP_SLEEPENABLE_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 46 PUPD_ENA ***********************************************
**********************************************************************************************/
#define SYSCFG1_PUPD_ENA                    (((SYSCFG_PUPD_ENA_TypeDef*)(SYSCFG1_BASE+SYSCFG_PUPD_ENA_OFFSET )))
#define SYSCFG1_PUPD_ENA_R                  (*((__IO uint32_t *)(SYSCFG1_BASE+SYSCFG_PUPD_ENA_OFFSET)))
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA0_MASK        ((uint32_t)0x00000001)
#define SYSCFG_PUPD_ENA_R_PUPDENA0_SHIFT       (0)

#define SYSCFG_PUPD_ENA_PUPDENA0_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA1_MASK        ((uint32_t)0x00000002)
#define SYSCFG_PUPD_ENA_R_PUPDENA1_SHIFT       (1)

#define SYSCFG_PUPD_ENA_PUPDENA1_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA2_MASK        ((uint32_t)0x00000004)
#define SYSCFG_PUPD_ENA_R_PUPDENA2_SHIFT       (2)

#define SYSCFG_PUPD_ENA_PUPDENA2_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA3_MASK        ((uint32_t)0x00000008)
#define SYSCFG_PUPD_ENA_R_PUPDENA3_SHIFT       (3)

#define SYSCFG_PUPD_ENA_PUPDENA3_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA4_MASK        ((uint32_t)0x00000010)
#define SYSCFG_PUPD_ENA_R_PUPDENA4_SHIFT       (4)

#define SYSCFG_PUPD_ENA_PUPDENA4_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA5_MASK        ((uint32_t)0x00000020)
#define SYSCFG_PUPD_ENA_R_PUPDENA5_SHIFT       (5)

#define SYSCFG_PUPD_ENA_PUPDENA5_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA6_MASK        ((uint32_t)0x00000040)
#define SYSCFG_PUPD_ENA_R_PUPDENA6_SHIFT       (6)

#define SYSCFG_PUPD_ENA_PUPDENA6_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA7_MASK        ((uint32_t)0x00000080)
#define SYSCFG_PUPD_ENA_R_PUPDENA7_SHIFT       (7)

#define SYSCFG_PUPD_ENA_PUPDENA7_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA8_MASK        ((uint32_t)0x00000100)
#define SYSCFG_PUPD_ENA_R_PUPDENA8_SHIFT       (8)

#define SYSCFG_PUPD_ENA_PUPDENA8_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA9_MASK        ((uint32_t)0x00000200)
#define SYSCFG_PUPD_ENA_R_PUPDENA9_SHIFT       (9)

#define SYSCFG_PUPD_ENA_PUPDENA9_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA10_MASK        ((uint32_t)0x00000400)
#define SYSCFG_PUPD_ENA_R_PUPDENA10_SHIFT       (10)

#define SYSCFG_PUPD_ENA_PUPDENA10_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA11_MASK        ((uint32_t)0x00000800)
#define SYSCFG_PUPD_ENA_R_PUPDENA11_SHIFT       (11)

#define SYSCFG_PUPD_ENA_PUPDENA11_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA12_MASK        ((uint32_t)0x00001000)
#define SYSCFG_PUPD_ENA_R_PUPDENA12_SHIFT       (12)

#define SYSCFG_PUPD_ENA_PUPDENA12_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA13_MASK        ((uint32_t)0x00002000)
#define SYSCFG_PUPD_ENA_R_PUPDENA13_SHIFT       (13)

#define SYSCFG_PUPD_ENA_PUPDENA13_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA14_MASK        ((uint32_t)0x00004000)
#define SYSCFG_PUPD_ENA_R_PUPDENA14_SHIFT       (14)

#define SYSCFG_PUPD_ENA_PUPDENA14_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA15_MASK        ((uint32_t)0x00008000)
#define SYSCFG_PUPD_ENA_R_PUPDENA15_SHIFT       (15)

#define SYSCFG_PUPD_ENA_PUPDENA15_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA16_MASK        ((uint32_t)0x00010000)
#define SYSCFG_PUPD_ENA_R_PUPDENA16_SHIFT       (16)

#define SYSCFG_PUPD_ENA_PUPDENA16_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA17_MASK        ((uint32_t)0x00020000)
#define SYSCFG_PUPD_ENA_R_PUPDENA17_SHIFT       (17)

#define SYSCFG_PUPD_ENA_PUPDENA17_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA18_MASK        ((uint32_t)0x00040000)
#define SYSCFG_PUPD_ENA_R_PUPDENA18_SHIFT       (18)

#define SYSCFG_PUPD_ENA_PUPDENA18_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA19_MASK        ((uint32_t)0x00080000)
#define SYSCFG_PUPD_ENA_R_PUPDENA19_SHIFT       (19)

#define SYSCFG_PUPD_ENA_PUPDENA19_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA20_MASK        ((uint32_t)0x00100000)
#define SYSCFG_PUPD_ENA_R_PUPDENA20_SHIFT       (20)

#define SYSCFG_PUPD_ENA_PUPDENA20_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA21_MASK        ((uint32_t)0x00200000)
#define SYSCFG_PUPD_ENA_R_PUPDENA21_SHIFT       (21)

#define SYSCFG_PUPD_ENA_PUPDENA21_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA22_MASK        ((uint32_t)0x00400000)
#define SYSCFG_PUPD_ENA_R_PUPDENA22_SHIFT       (22)

#define SYSCFG_PUPD_ENA_PUPDENA22_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA23_MASK        ((uint32_t)0x00800000)
#define SYSCFG_PUPD_ENA_R_PUPDENA23_SHIFT       (23)

#define SYSCFG_PUPD_ENA_PUPDENA23_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA24_MASK        ((uint32_t)0x01000000)
#define SYSCFG_PUPD_ENA_R_PUPDENA24_SHIFT       (24)

#define SYSCFG_PUPD_ENA_PUPDENA24_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA25_MASK        ((uint32_t)0x02000000)
#define SYSCFG_PUPD_ENA_R_PUPDENA25_SHIFT       (25)

#define SYSCFG_PUPD_ENA_PUPDENA25_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA26_MASK        ((uint32_t)0x04000000)
#define SYSCFG_PUPD_ENA_R_PUPDENA26_SHIFT       (26)

#define SYSCFG_PUPD_ENA_PUPDENA26_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA27_MASK        ((uint32_t)0x08000000)
#define SYSCFG_PUPD_ENA_R_PUPDENA27_SHIFT       (27)

#define SYSCFG_PUPD_ENA_PUPDENA27_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA28_MASK        ((uint32_t)0x10000000)
#define SYSCFG_PUPD_ENA_R_PUPDENA28_SHIFT       (28)

#define SYSCFG_PUPD_ENA_PUPDENA28_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA29_MASK        ((uint32_t)0x20000000)
#define SYSCFG_PUPD_ENA_R_PUPDENA29_SHIFT       (29)

#define SYSCFG_PUPD_ENA_PUPDENA29_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA30_MASK        ((uint32_t)0x40000000)
#define SYSCFG_PUPD_ENA_R_PUPDENA30_SHIFT       (30)

#define SYSCFG_PUPD_ENA_PUPDENA30_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_ENA_R_PUPDENA31_MASK        ((uint32_t)0x80000000)
#define SYSCFG_PUPD_ENA_R_PUPDENA31_SHIFT       (31)

#define SYSCFG_PUPD_ENA_PUPDENA31_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 46 PUPD_SEL ***********************************************
**********************************************************************************************/
#define SYSCFG1_PUPD_SEL                    (((SYSCFG_PUPD_SEL_TypeDef*)(SYSCFG1_BASE+SYSCFG_PUPD_SEL_OFFSET )))
#define SYSCFG1_PUPD_SEL_R                  (*((__IO uint32_t *)(SYSCFG1_BASE+SYSCFG_PUPD_SEL_OFFSET)))
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL0_MASK        ((uint32_t)0x00000001)
#define SYSCFG_PUPD_SEL_R_PUPDSEL0_SHIFT       (0)

#define SYSCFG_PUPD_SEL_PUPDSEL0_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL1_MASK        ((uint32_t)0x00000002)
#define SYSCFG_PUPD_SEL_R_PUPDSEL1_SHIFT       (1)

#define SYSCFG_PUPD_SEL_PUPDSEL1_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL2_MASK        ((uint32_t)0x00000004)
#define SYSCFG_PUPD_SEL_R_PUPDSEL2_SHIFT       (2)

#define SYSCFG_PUPD_SEL_PUPDSEL2_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL3_MASK        ((uint32_t)0x00000008)
#define SYSCFG_PUPD_SEL_R_PUPDSEL3_SHIFT       (3)

#define SYSCFG_PUPD_SEL_PUPDSEL3_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL4_MASK        ((uint32_t)0x00000010)
#define SYSCFG_PUPD_SEL_R_PUPDSEL4_SHIFT       (4)

#define SYSCFG_PUPD_SEL_PUPDSEL4_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL5_MASK        ((uint32_t)0x00000020)
#define SYSCFG_PUPD_SEL_R_PUPDSEL5_SHIFT       (5)

#define SYSCFG_PUPD_SEL_PUPDSEL5_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL6_MASK        ((uint32_t)0x00000040)
#define SYSCFG_PUPD_SEL_R_PUPDSEL6_SHIFT       (6)

#define SYSCFG_PUPD_SEL_PUPDSEL6_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL7_MASK        ((uint32_t)0x00000080)
#define SYSCFG_PUPD_SEL_R_PUPDSEL7_SHIFT       (7)

#define SYSCFG_PUPD_SEL_PUPDSEL7_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL8_MASK        ((uint32_t)0x00000100)
#define SYSCFG_PUPD_SEL_R_PUPDSEL8_SHIFT       (8)

#define SYSCFG_PUPD_SEL_PUPDSEL8_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL9_MASK        ((uint32_t)0x00000200)
#define SYSCFG_PUPD_SEL_R_PUPDSEL9_SHIFT       (9)

#define SYSCFG_PUPD_SEL_PUPDSEL9_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL10_MASK        ((uint32_t)0x00000400)
#define SYSCFG_PUPD_SEL_R_PUPDSEL10_SHIFT       (10)

#define SYSCFG_PUPD_SEL_PUPDSEL10_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL11_MASK        ((uint32_t)0x00000800)
#define SYSCFG_PUPD_SEL_R_PUPDSEL11_SHIFT       (11)

#define SYSCFG_PUPD_SEL_PUPDSEL11_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL12_MASK        ((uint32_t)0x00001000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL12_SHIFT       (12)

#define SYSCFG_PUPD_SEL_PUPDSEL12_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL13_MASK        ((uint32_t)0x00002000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL13_SHIFT       (13)

#define SYSCFG_PUPD_SEL_PUPDSEL13_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL14_MASK        ((uint32_t)0x00004000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL14_SHIFT       (14)

#define SYSCFG_PUPD_SEL_PUPDSEL14_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL15_MASK        ((uint32_t)0x00008000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL15_SHIFT       (15)

#define SYSCFG_PUPD_SEL_PUPDSEL15_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL16_MASK        ((uint32_t)0x00010000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL16_SHIFT       (16)

#define SYSCFG_PUPD_SEL_PUPDSEL16_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL17_MASK        ((uint32_t)0x00020000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL17_SHIFT       (17)

#define SYSCFG_PUPD_SEL_PUPDSEL17_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL18_MASK        ((uint32_t)0x00040000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL18_SHIFT       (18)

#define SYSCFG_PUPD_SEL_PUPDSEL18_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL19_MASK        ((uint32_t)0x00080000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL19_SHIFT       (19)

#define SYSCFG_PUPD_SEL_PUPDSEL19_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL20_MASK        ((uint32_t)0x00100000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL20_SHIFT       (20)

#define SYSCFG_PUPD_SEL_PUPDSEL20_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL21_MASK        ((uint32_t)0x00200000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL21_SHIFT       (21)

#define SYSCFG_PUPD_SEL_PUPDSEL21_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL22_MASK        ((uint32_t)0x00400000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL22_SHIFT       (22)

#define SYSCFG_PUPD_SEL_PUPDSEL22_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL23_MASK        ((uint32_t)0x00800000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL23_SHIFT       (23)

#define SYSCFG_PUPD_SEL_PUPDSEL23_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL24_MASK        ((uint32_t)0x01000000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL24_SHIFT       (24)

#define SYSCFG_PUPD_SEL_PUPDSEL24_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL25_MASK        ((uint32_t)0x02000000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL25_SHIFT       (25)

#define SYSCFG_PUPD_SEL_PUPDSEL25_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL26_MASK        ((uint32_t)0x04000000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL26_SHIFT       (26)

#define SYSCFG_PUPD_SEL_PUPDSEL26_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL27_MASK        ((uint32_t)0x08000000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL27_SHIFT       (27)

#define SYSCFG_PUPD_SEL_PUPDSEL27_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL28_MASK        ((uint32_t)0x10000000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL28_SHIFT       (28)

#define SYSCFG_PUPD_SEL_PUPDSEL28_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL29_MASK        ((uint32_t)0x20000000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL29_SHIFT       (29)

#define SYSCFG_PUPD_SEL_PUPDSEL29_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL30_MASK        ((uint32_t)0x40000000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL30_SHIFT       (30)

#define SYSCFG_PUPD_SEL_PUPDSEL30_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_PUPD_SEL_R_PUPDSEL31_MASK        ((uint32_t)0x80000000)
#define SYSCFG_PUPD_SEL_R_PUPDSEL31_SHIFT       (31)

#define SYSCFG_PUPD_SEL_PUPDSEL31_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 46 RXACTIVE ***********************************************
**********************************************************************************************/
#define SYSCFG1_RXACTIVE                    (((SYSCFG_RXACTIVE_TypeDef*)(SYSCFG1_BASE+SYSCFG_RXACTIVE_OFFSET )))
#define SYSCFG1_RXACTIVE_R                  (*((__IO uint32_t *)(SYSCFG1_BASE+SYSCFG_RXACTIVE_OFFSET)))
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE0_MASK        ((uint32_t)0x00000001)
#define SYSCFG_RXACTIVE_R_RXACTIVE0_SHIFT       (0)

#define SYSCFG_RXACTIVE_RXACTIVE0_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE1_MASK        ((uint32_t)0x00000002)
#define SYSCFG_RXACTIVE_R_RXACTIVE1_SHIFT       (1)

#define SYSCFG_RXACTIVE_RXACTIVE1_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE2_MASK        ((uint32_t)0x00000004)
#define SYSCFG_RXACTIVE_R_RXACTIVE2_SHIFT       (2)

#define SYSCFG_RXACTIVE_RXACTIVE2_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE3_MASK        ((uint32_t)0x00000008)
#define SYSCFG_RXACTIVE_R_RXACTIVE3_SHIFT       (3)

#define SYSCFG_RXACTIVE_RXACTIVE3_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE4_MASK        ((uint32_t)0x00000010)
#define SYSCFG_RXACTIVE_R_RXACTIVE4_SHIFT       (4)

#define SYSCFG_RXACTIVE_RXACTIVE4_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE5_MASK        ((uint32_t)0x00000020)
#define SYSCFG_RXACTIVE_R_RXACTIVE5_SHIFT       (5)

#define SYSCFG_RXACTIVE_RXACTIVE5_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE6_MASK        ((uint32_t)0x00000040)
#define SYSCFG_RXACTIVE_R_RXACTIVE6_SHIFT       (6)

#define SYSCFG_RXACTIVE_RXACTIVE6_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE7_MASK        ((uint32_t)0x00000080)
#define SYSCFG_RXACTIVE_R_RXACTIVE7_SHIFT       (7)

#define SYSCFG_RXACTIVE_RXACTIVE7_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE8_MASK        ((uint32_t)0x00000100)
#define SYSCFG_RXACTIVE_R_RXACTIVE8_SHIFT       (8)

#define SYSCFG_RXACTIVE_RXACTIVE8_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE9_MASK        ((uint32_t)0x00000200)
#define SYSCFG_RXACTIVE_R_RXACTIVE9_SHIFT       (9)

#define SYSCFG_RXACTIVE_RXACTIVE9_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE10_MASK        ((uint32_t)0x00000400)
#define SYSCFG_RXACTIVE_R_RXACTIVE10_SHIFT       (10)

#define SYSCFG_RXACTIVE_RXACTIVE10_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE11_MASK        ((uint32_t)0x00000800)
#define SYSCFG_RXACTIVE_R_RXACTIVE11_SHIFT       (11)

#define SYSCFG_RXACTIVE_RXACTIVE11_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE12_MASK        ((uint32_t)0x00001000)
#define SYSCFG_RXACTIVE_R_RXACTIVE12_SHIFT       (12)

#define SYSCFG_RXACTIVE_RXACTIVE12_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE13_MASK        ((uint32_t)0x00002000)
#define SYSCFG_RXACTIVE_R_RXACTIVE13_SHIFT       (13)

#define SYSCFG_RXACTIVE_RXACTIVE13_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE14_MASK        ((uint32_t)0x00004000)
#define SYSCFG_RXACTIVE_R_RXACTIVE14_SHIFT       (14)

#define SYSCFG_RXACTIVE_RXACTIVE14_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE15_MASK        ((uint32_t)0x00008000)
#define SYSCFG_RXACTIVE_R_RXACTIVE15_SHIFT       (15)

#define SYSCFG_RXACTIVE_RXACTIVE15_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE16_MASK        ((uint32_t)0x00010000)
#define SYSCFG_RXACTIVE_R_RXACTIVE16_SHIFT       (16)

#define SYSCFG_RXACTIVE_RXACTIVE16_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE17_MASK        ((uint32_t)0x00020000)
#define SYSCFG_RXACTIVE_R_RXACTIVE17_SHIFT       (17)

#define SYSCFG_RXACTIVE_RXACTIVE17_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE18_MASK        ((uint32_t)0x00040000)
#define SYSCFG_RXACTIVE_R_RXACTIVE18_SHIFT       (18)

#define SYSCFG_RXACTIVE_RXACTIVE18_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE19_MASK        ((uint32_t)0x00080000)
#define SYSCFG_RXACTIVE_R_RXACTIVE19_SHIFT       (19)

#define SYSCFG_RXACTIVE_RXACTIVE19_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE20_MASK        ((uint32_t)0x00100000)
#define SYSCFG_RXACTIVE_R_RXACTIVE20_SHIFT       (20)

#define SYSCFG_RXACTIVE_RXACTIVE20_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE21_MASK        ((uint32_t)0x00200000)
#define SYSCFG_RXACTIVE_R_RXACTIVE21_SHIFT       (21)

#define SYSCFG_RXACTIVE_RXACTIVE21_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE22_MASK        ((uint32_t)0x00400000)
#define SYSCFG_RXACTIVE_R_RXACTIVE22_SHIFT       (22)

#define SYSCFG_RXACTIVE_RXACTIVE22_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE23_MASK        ((uint32_t)0x00800000)
#define SYSCFG_RXACTIVE_R_RXACTIVE23_SHIFT       (23)

#define SYSCFG_RXACTIVE_RXACTIVE23_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE24_MASK        ((uint32_t)0x01000000)
#define SYSCFG_RXACTIVE_R_RXACTIVE24_SHIFT       (24)

#define SYSCFG_RXACTIVE_RXACTIVE24_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE25_MASK        ((uint32_t)0x02000000)
#define SYSCFG_RXACTIVE_R_RXACTIVE25_SHIFT       (25)

#define SYSCFG_RXACTIVE_RXACTIVE25_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE26_MASK        ((uint32_t)0x04000000)
#define SYSCFG_RXACTIVE_R_RXACTIVE26_SHIFT       (26)

#define SYSCFG_RXACTIVE_RXACTIVE26_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE27_MASK        ((uint32_t)0x08000000)
#define SYSCFG_RXACTIVE_R_RXACTIVE27_SHIFT       (27)

#define SYSCFG_RXACTIVE_RXACTIVE27_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE28_MASK        ((uint32_t)0x10000000)
#define SYSCFG_RXACTIVE_R_RXACTIVE28_SHIFT       (28)

#define SYSCFG_RXACTIVE_RXACTIVE28_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE29_MASK        ((uint32_t)0x20000000)
#define SYSCFG_RXACTIVE_R_RXACTIVE29_SHIFT       (29)

#define SYSCFG_RXACTIVE_RXACTIVE29_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE30_MASK        ((uint32_t)0x40000000)
#define SYSCFG_RXACTIVE_R_RXACTIVE30_SHIFT       (30)

#define SYSCFG_RXACTIVE_RXACTIVE30_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define SYSCFG_RXACTIVE_R_RXACTIVE31_MASK        ((uint32_t)0x80000000)
#define SYSCFG_RXACTIVE_R_RXACTIVE31_SHIFT       (31)

#define SYSCFG_RXACTIVE_RXACTIVE31_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 46 PWRDN ***********************************************
**********************************************************************************************/
#define SYSCFG1_PWRDN                    (((SYSCFG_PWRDN_TypeDef*)(SYSCFG1_BASE+SYSCFG_PWRDN_OFFSET )))
#define SYSCFG1_PWRDN_R                  (*((__IO uint32_t *)(SYSCFG1_BASE+SYSCFG_PWRDN_OFFSET)))
/*--------*/
#define SYSCFG_PWRDN_R_SATACLK_PWRDN_MASK        ((uint32_t)0x00000001)
#define SYSCFG_PWRDN_R_SATACLK_PWRDN_SHIFT       (0)

#define SYSCFG_PWRDN_SATACLK_PWRDN_MASK          ((uint32_t)0x00000001)
/*--------*/

extern void SYSCFG__vResgistersUnlock(void);
extern void SYSCFG__vResgistersLock(void);

#endif /* INCLUDE_SYSCFG_H_ */
