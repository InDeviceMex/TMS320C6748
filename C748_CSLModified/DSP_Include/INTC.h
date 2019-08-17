/*
 * INTC.h
 *
 *  Created on: 16/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_INTC_H_
#define INCLUDE_INTC_H_


#define INTC_BASE            ((uint32_t)0x01800000)
#include <c6x.h>
#include "Core.h"
#include <stdint.h>

typedef __IO struct
{
    __IO uint32_t EF0 :1;
    __IO uint32_t EF1 :1;
    __IO uint32_t EF2 :1;
    __IO uint32_t EF3 :1;
    __IO uint32_t EF4 :1;
    __IO uint32_t EF5 :1;
    __IO uint32_t EF6 :1;
    __IO uint32_t EF7 :1;
    __IO uint32_t EF8 :1;
    __IO uint32_t EF9 :1;
    __IO uint32_t EF10 :1;
    __IO uint32_t EF11 :1;
    __IO uint32_t EF12 :1;
    __IO uint32_t EF13 :1;
    __IO uint32_t EF14 :1;
    __IO uint32_t EF15 :1;
    __IO uint32_t EF16 :1;
    __IO uint32_t EF17 :1;
    __IO uint32_t EF18 :1;
    __IO uint32_t EF19 :1;
    __IO uint32_t EF20 :1;
    __IO uint32_t EF21 :1;
    __IO uint32_t EF22 :1;
    __IO uint32_t EF23 :1;
    __IO uint32_t EF24 :1;
    __IO uint32_t EF25 :1;
    __IO uint32_t EF26 :1;
    __IO uint32_t EF27 :1;
    __IO uint32_t EF28 :1;
    __IO uint32_t EF29 :1;
    __IO uint32_t EF30 :1;
    __IO uint32_t EF31 :1;
}INTC_EVTFLAG_TypeDef;

typedef __IO struct
{
    __IO uint32_t ES0 :1;
    __IO uint32_t ES1 :1;
    __IO uint32_t ES2 :1;
    __IO uint32_t ES3 :1;
    __IO uint32_t ES4 :1;
    __IO uint32_t ES5 :1;
    __IO uint32_t ES6 :1;
    __IO uint32_t ES7 :1;
    __IO uint32_t ES8 :1;
    __IO uint32_t ES9 :1;
    __IO uint32_t ES10 :1;
    __IO uint32_t ES11 :1;
    __IO uint32_t ES12 :1;
    __IO uint32_t ES13 :1;
    __IO uint32_t ES14 :1;
    __IO uint32_t ES15 :1;
    __IO uint32_t ES16 :1;
    __IO uint32_t ES17 :1;
    __IO uint32_t ES18 :1;
    __IO uint32_t ES19 :1;
    __IO uint32_t ES20 :1;
    __IO uint32_t ES21 :1;
    __IO uint32_t ES22 :1;
    __IO uint32_t ES23 :1;
    __IO uint32_t ES24 :1;
    __IO uint32_t ES25 :1;
    __IO uint32_t ES26 :1;
    __IO uint32_t ES27 :1;
    __IO uint32_t ES28 :1;
    __IO uint32_t ES29 :1;
    __IO uint32_t ES30 :1;
    __IO uint32_t ES31 :1;
}INTC_EVTSET_TypeDef;

typedef __IO struct
{
    __IO uint32_t EC0 :1;
    __IO uint32_t EC1 :1;
    __IO uint32_t EC2 :1;
    __IO uint32_t EC3 :1;
    __IO uint32_t EC4 :1;
    __IO uint32_t EC5 :1;
    __IO uint32_t EC6 :1;
    __IO uint32_t EC7 :1;
    __IO uint32_t EC8 :1;
    __IO uint32_t EC9 :1;
    __IO uint32_t EC10 :1;
    __IO uint32_t EC11 :1;
    __IO uint32_t EC12 :1;
    __IO uint32_t EC13 :1;
    __IO uint32_t EC14 :1;
    __IO uint32_t EC15 :1;
    __IO uint32_t EC16 :1;
    __IO uint32_t EC17 :1;
    __IO uint32_t EC18 :1;
    __IO uint32_t EC19 :1;
    __IO uint32_t EC20 :1;
    __IO uint32_t EC21 :1;
    __IO uint32_t EC22 :1;
    __IO uint32_t EC23 :1;
    __IO uint32_t EC24 :1;
    __IO uint32_t EC25 :1;
    __IO uint32_t EC26 :1;
    __IO uint32_t EC27 :1;
    __IO uint32_t EC28 :1;
    __IO uint32_t EC29 :1;
    __IO uint32_t EC30 :1;
    __IO uint32_t EC31 :1;
}INTC_EVTCLR_TypeDef;

typedef __IO struct
{
    __IO uint32_t EM0 :1;
    __IO uint32_t EM1 :1;
    __IO uint32_t EM2 :1;
    __IO uint32_t EM3 :1;
    __IO uint32_t EM4 :1;
    __IO uint32_t EM5 :1;
    __IO uint32_t EM6 :1;
    __IO uint32_t EM7 :1;
    __IO uint32_t EM8 :1;
    __IO uint32_t EM9 :1;
    __IO uint32_t EM10 :1;
    __IO uint32_t EM11 :1;
    __IO uint32_t EM12 :1;
    __IO uint32_t EM13 :1;
    __IO uint32_t EM14 :1;
    __IO uint32_t EM15 :1;
    __IO uint32_t EM16 :1;
    __IO uint32_t EM17 :1;
    __IO uint32_t EM18 :1;
    __IO uint32_t EM19 :1;
    __IO uint32_t EM20 :1;
    __IO uint32_t EM21 :1;
    __IO uint32_t EM22 :1;
    __IO uint32_t EM23 :1;
    __IO uint32_t EM24 :1;
    __IO uint32_t EM25 :1;
    __IO uint32_t EM26 :1;
    __IO uint32_t EM27 :1;
    __IO uint32_t EM28 :1;
    __IO uint32_t EM29 :1;
    __IO uint32_t EM30 :1;
    __IO uint32_t EM31 :1;
}INTC_EVTMASK_TypeDef;

typedef __IO struct
{
    __IO uint32_t EMF0 :1;
    __IO uint32_t EMF1 :1;
    __IO uint32_t EMF2 :1;
    __IO uint32_t EMF3 :1;
    __IO uint32_t EMF4 :1;
    __IO uint32_t EMF5 :1;
    __IO uint32_t EMF6 :1;
    __IO uint32_t EMF7 :1;
    __IO uint32_t EMF8 :1;
    __IO uint32_t EMF9 :1;
    __IO uint32_t EMF10 :1;
    __IO uint32_t EMF11 :1;
    __IO uint32_t EMF12 :1;
    __IO uint32_t EMF13 :1;
    __IO uint32_t EMF14 :1;
    __IO uint32_t EMF15 :1;
    __IO uint32_t EMF16 :1;
    __IO uint32_t EMF17 :1;
    __IO uint32_t EMF18 :1;
    __IO uint32_t EMF19 :1;
    __IO uint32_t EMF20 :1;
    __IO uint32_t EMF21 :1;
    __IO uint32_t EMF22 :1;
    __IO uint32_t EMF23 :1;
    __IO uint32_t EMF24 :1;
    __IO uint32_t EMF25 :1;
    __IO uint32_t EMF26 :1;
    __IO uint32_t EMF27 :1;
    __IO uint32_t EMF28 :1;
    __IO uint32_t EMF29 :1;
    __IO uint32_t EMF30 :1;
    __IO uint32_t EMF31 :1;
}INTC_MEVTFLAG_TypeDef;


typedef __IO struct
{
    __IO uint32_t INTSEL0 :7;
         uint32_t reserved0 :1;
    __IO uint32_t INTSEL1 :7;
         uint32_t reserved1 :1;
    __IO uint32_t INTSEL2 :7;
         uint32_t reserved2 :1;
    __IO uint32_t INTSEL3 :7;
         uint32_t reserved3 :1;
}INTC_INTMUX_TypeDef;

typedef __IO struct
{
    __IO uint32_t INTSEL4 :7;
         uint32_t reserved0 :1;
    __IO uint32_t INTSEL5 :7;
         uint32_t reserved1 :1;
    __IO uint32_t INTSEL6 :7;
         uint32_t reserved2 :1;
    __IO uint32_t INTSEL7 :7;
         uint32_t reserved3 :1;
}INTC_INTMUX1_TypeDef;

typedef __IO struct
{
    __IO uint32_t INTSEL8 :7;
         uint32_t reserved0 :1;
    __IO uint32_t INTSEL9 :7;
         uint32_t reserved1 :1;
    __IO uint32_t INTSEL10 :7;
         uint32_t reserved2 :1;
    __IO uint32_t INTSEL11 :7;
         uint32_t reserved3 :1;
}INTC_INTMUX2_TypeDef;

typedef __IO struct
{
    __IO uint32_t INTSEL12 :7;
         uint32_t reserved0 :1;
    __IO uint32_t INTSEL13 :7;
         uint32_t reserved1 :1;
    __IO uint32_t INTSEL14 :7;
         uint32_t reserved2 :1;
    __IO uint32_t INTSEL15 :7;
         uint32_t reserved3 :1;
}INTC_INTMUX3_TypeDef;

typedef __IO struct
{
    __IO uint32_t DROP :1;
         uint32_t reserved0 :15 ;
    __IO uint32_t CPUINT :8;
    __IO uint32_t SYSINT :8;
}INTC_INTXSTAT_TypeDef;

typedef __IO struct
{
    __IO uint32_t CLEAR :16;
         uint32_t reserved0 :16 ;
}INTC_INTXCLR_TypeDef;

typedef __IO struct
{
         uint32_t reserved0 :4 ;
    __IO uint32_t IDM4 :1;
    __IO uint32_t IDM5 :1;
    __IO uint32_t IDM6 :1;
    __IO uint32_t IDM7 :1;
    __IO uint32_t IDM8 :1;
    __IO uint32_t IDM9 :1;
    __IO uint32_t IDM10 :1;
    __IO uint32_t IDM11:1;
    __IO uint32_t IDM12 :1;
    __IO uint32_t IDM13 :1;
    __IO uint32_t IDM14 :1;
    __IO uint32_t IDM15 :1;
         uint32_t reserved1 :16 ;
}INTC_INTDMASK_TypeDef;

typedef __IO struct
{
    __IO uint32_t XM0 :1;
    __IO uint32_t XM1 :1;
    __IO uint32_t XM2 :1;
    __IO uint32_t XM3 :1;
    __IO uint32_t XM4 :1;
    __IO uint32_t XM5 :1;
    __IO uint32_t XM6 :1;
    __IO uint32_t XM7 :1;
    __IO uint32_t XM8 :1;
    __IO uint32_t XM9 :1;
    __IO uint32_t XM10 :1;
    __IO uint32_t XM11 :1;
    __IO uint32_t XM12 :1;
    __IO uint32_t XM13 :1;
    __IO uint32_t XM14 :1;
    __IO uint32_t XM15 :1;
    __IO uint32_t XM16 :1;
    __IO uint32_t XM17 :1;
    __IO uint32_t XM18 :1;
    __IO uint32_t XM19 :1;
    __IO uint32_t XM20 :1;
    __IO uint32_t XM21 :1;
    __IO uint32_t XM22 :1;
    __IO uint32_t XM23 :1;
    __IO uint32_t XM24 :1;
    __IO uint32_t XM25 :1;
    __IO uint32_t XM26 :1;
    __IO uint32_t XM27 :1;
    __IO uint32_t XM28 :1;
    __IO uint32_t XM29 :1;
    __IO uint32_t XM30 :1;
    __IO uint32_t XM31 :1;
}INTC_EXPMASK_TypeDef;

typedef __IO struct
{
    __IO uint32_t MXF0 :1;
    __IO uint32_t MXF1 :1;
    __IO uint32_t MXF2 :1;
    __IO uint32_t MXF3 :1;
    __IO uint32_t MXF4 :1;
    __IO uint32_t MXF5 :1;
    __IO uint32_t MXF6 :1;
    __IO uint32_t MXF7 :1;
    __IO uint32_t MXF8 :1;
    __IO uint32_t MXF9 :1;
    __IO uint32_t MXF10 :1;
    __IO uint32_t MXF11 :1;
    __IO uint32_t MXF12 :1;
    __IO uint32_t MXF13 :1;
    __IO uint32_t MXF14 :1;
    __IO uint32_t MXF15 :1;
    __IO uint32_t MXF16 :1;
    __IO uint32_t MXF17 :1;
    __IO uint32_t MXF18 :1;
    __IO uint32_t MXF19 :1;
    __IO uint32_t MXF20 :1;
    __IO uint32_t MXF21 :1;
    __IO uint32_t MXF22 :1;
    __IO uint32_t MXF23 :1;
    __IO uint32_t MXF24 :1;
    __IO uint32_t MXF25 :1;
    __IO uint32_t MXF26 :1;
    __IO uint32_t MXF27 :1;
    __IO uint32_t MXF28 :1;
    __IO uint32_t MXF29 :1;
    __IO uint32_t MXF30 :1;
    __IO uint32_t MXF31 :1;
}INTC_MEXPFLAG_TypeDef;

typedef __IO struct
{
    __IO uint32_t AEGSEL0 :8;
    __IO uint32_t AEGSEL1 :8;
    __IO uint32_t AEGSEL2 :8;
    __IO uint32_t AEGSEL3 :8;
}INTC_AEGMUX_TypeDef;

typedef __IO struct
{
    union
    {
        __IO uint32_t         EVTFLAG[4];
        INTC_EVTFLAG_TypeDef  EVTFLAG_Bit[4];
    };
    uint32_t reserved0[4];
    union
    {
        __IO uint32_t         EVTSET[4];
        INTC_EVTSET_TypeDef  EVTSET_Bit[4];
    };
    uint32_t reserved1[4];
    union
    {
        __IO uint32_t         EVTCLR[4];
        INTC_EVTCLR_TypeDef  EVTCLR_Bit[4];
    };
    uint32_t reserved2[12];
    union
    {
        __IO uint32_t         EVTMASK[4];
        INTC_EVTMASK_TypeDef  EVTMASK_Bit[4];
    };
    uint32_t reserved3[4];
    union
    {
        __IO uint32_t         MEVTFLAG[4];
        INTC_MEVTFLAG_TypeDef  MEVTFLAG_Bit[4];
    };
    uint32_t reserved4[4];
    union
    {
        __IO uint32_t         EXPMASK[4];
        INTC_EXPMASK_TypeDef EXPMASK_Bit[4];
    };
    uint32_t reserved5[4];
    union
    {
        __IO uint32_t         MEXPFLAG[4];
        INTC_MEXPFLAG_TypeDef MEXPFLAG_Bit[4];
    };
    uint32_t reserved6[4];
    union
    {
        __IO uint32_t         INTMUX[4];
        INTC_INTMUX_TypeDef INTMUX_Bit[4];
    };
    uint32_t reserved7[28];
    //union
    //{
       // __IO uint32_t         AEGMUX[4];
      //  INTC_AEGMUX_TypeDef AEGMUX_Bit[4];
    //};
    //uint32_t reserved8[12];
    union
    {
        __IO uint32_t          INTXSTAT;
        INTC_INTXSTAT_TypeDef  INTXSTAT_Bit;
    };
    union
    {
        __IO uint32_t          INTXCLR;
        INTC_INTXCLR_TypeDef  INTXCLR_Bit;
    };
    union
    {
        __IO uint32_t          INTDMASK;
        INTC_INTDMASK_TypeDef  INTDMASK_Bit;
    };
    uint32_t reserved9[13];
    //union
    //{
        __IO uint32_t          EVTASRT;
       // INTC_EVTASRT_TypeDef   EVTASRT_Bit;
    //};

     uint32_t reserved10[16351];
    union
    {
        __IO uint32_t         AEGMUX[4];
        INTC_AEGMUX_TypeDef   AEGMUX_Bit[4];
    };

}INTC_TypeDef;





#define INTC            (((INTC_TypeDef*)(INTC_BASE)))
#define INTC_R(offset)  (*((__IO uint32_t *)(INTC_BASE+offset)))


#define INTC_EVTFLAG0_OFFSET      ((uint32_t)0x0000)
#define INTC_EVTFLAG1_OFFSET      ((uint32_t)0x0004)
#define INTC_EVTFLAG2_OFFSET      ((uint32_t)0x0008)
#define INTC_EVTFLAG3_OFFSET      ((uint32_t)0x000C)
#define INTC_EVTSET0_OFFSET       ((uint32_t)0x0020)
#define INTC_EVTSET1_OFFSET       ((uint32_t)0x0024)
#define INTC_EVTSET2_OFFSET       ((uint32_t)0x0028)
#define INTC_EVTSET3_OFFSET       ((uint32_t)0x002C)
#define INTC_EVTCLR0_OFFSET       ((uint32_t)0x0040)
#define INTC_EVTCLR1_OFFSET       ((uint32_t)0x0044)
#define INTC_EVTCLR2_OFFSET       ((uint32_t)0x0048)
#define INTC_EVTCLR3_OFFSET       ((uint32_t)0x004C)
#define INTC_EVTMASK0_OFFSET      ((uint32_t)0x0080)
#define INTC_EVTMASK1_OFFSET      ((uint32_t)0x0084)
#define INTC_EVTMASK2_OFFSET      ((uint32_t)0x0088)
#define INTC_EVTMASK3_OFFSET      ((uint32_t)0x008C)
#define INTC_MEVTFLAG0_OFFSET     ((uint32_t)0x00A0)
#define INTC_MEVTFLAG1_OFFSET     ((uint32_t)0x00A4)
#define INTC_MEVTFLAG2_OFFSET     ((uint32_t)0x00A8)
#define INTC_MEVTFLAG3_OFFSET     ((uint32_t)0x00AC)
#define INTC_EXPMASK0_OFFSET      ((uint32_t)0x00C0)
#define INTC_EXPMASK1_OFFSET      ((uint32_t)0x00C4)
#define INTC_EXPMASK2_OFFSET      ((uint32_t)0x00C8)
#define INTC_EXPMASK3_OFFSET      ((uint32_t)0x00CC)
#define INTC_MEXPFLAG0_OFFSET     ((uint32_t)0x00E0)
#define INTC_MEXPFLAG1_OFFSET     ((uint32_t)0x00E4)
#define INTC_MEXPFLAG2_OFFSET     ((uint32_t)0x00E8)
#define INTC_MEXPFLAG3_OFFSET     ((uint32_t)0x00EC)
#define INTC_INTMUX0_OFFSET       ((uint32_t)0x0100)
#define INTC_INTMUX1_OFFSET       ((uint32_t)0x0104)
#define INTC_INTMUX2_OFFSET       ((uint32_t)0x0108)
#define INTC_INTMUX3_OFFSET       ((uint32_t)0x010C)
#define INTC_INTXSTAT_OFFSET      ((uint32_t)0x0180)
#define INTC_INTXCLR_OFFSET       ((uint32_t)0x0184)
#define INTC_INTDMASK_OFFSET      ((uint32_t)0x0188)
#define INTC_EVTASRT_OFFSET       ((uint32_t)0x01C0)
#define INTC_AEGMUX0_OFFSET       ((uint32_t)0x10140)
#define INTC_AEGMUX1_OFFSET       ((uint32_t)0x10144)



/**********************************************************************************************
************************************** 1 EVTFLAG ***********************************************
**********************************************************************************************/
#define INTC_EVTFLAG0                   (((INTC_EVTFLAG_TypeDef*)(INTC_BASE+INTC_EVTFLAG0_OFFSET )))
#define INTC_EVTFLAG0_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTFLAG0_OFFSET)))
#define INTC_EVTFLAG1                   (((INTC_EVTFLAG_TypeDef*)(INTC_BASE+INTC_EVTFLAG1_OFFSET )))
#define INTC_EVTFLAG1_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTFLAG1_OFFSET)))
#define INTC_EVTFLAG2                   (((INTC_EVTFLAG_TypeDef*)(INTC_BASE+INTC_EVTFLAG2_OFFSET )))
#define INTC_EVTFLAG2_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTFLAG2_OFFSET)))
#define INTC_EVTFLAG3                   (((INTC_EVTFLAG_TypeDef*)(INTC_BASE+INTC_EVTFLAG3_OFFSET )))
#define INTC_EVTFLAG3_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTFLAG3_OFFSET)))
#define INTC_EVTFLAG(n)                (((INTC_EVTFLAG_TypeDef*)(INTC_BASE+INTC_EVTFLAG0_OFFSET +((n)*4) )))
#define INTC_EVTFLAG_R(n)              (*((__IO uint32_t *)(INTC_BASE+INTC_EVTFLAG0_OFFSET +((n)*4))))


#define INTC_EVTFLAG_R_EF(n)           (0x1 << ((n) & 31))
/*--------*/
#define INTC_EVTFLAG_R_EF0_MASK        ((uint32_t)0x00000001)
#define INTC_EVTFLAG_R_EF0_SHIFT         (0)

#define INTC_EVTFLAG_EF0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF1_MASK        ((uint32_t)0x00000002)
#define INTC_EVTFLAG_R_EF1_SHIFT         (1)

#define INTC_EVTFLAG_EF1_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF2_MASK        ((uint32_t)0x00000004)
#define INTC_EVTFLAG_R_EF2_SHIFT         (2)

#define INTC_EVTFLAG_EF2_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF3_MASK        ((uint32_t)0x00000008)
#define INTC_EVTFLAG_R_EF3_SHIFT         (3)

#define INTC_EVTFLAG_EF3_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF4_MASK        ((uint32_t)0x00000010)
#define INTC_EVTFLAG_R_EF4_SHIFT         (4)

#define INTC_EVTFLAG_EF4_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF5_MASK        ((uint32_t)0x00000020)
#define INTC_EVTFLAG_R_EF5_SHIFT         (5)

#define INTC_EVTFLAG_EF5_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF6_MASK        ((uint32_t)0x00000040)
#define INTC_EVTFLAG_R_EF6_SHIFT         (6)

#define INTC_EVTFLAG_EF6_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF7_MASK        ((uint32_t)0x00000080)
#define INTC_EVTFLAG_R_EF7_SHIFT         (7)

#define INTC_EVTFLAG_EF7_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF8_MASK        ((uint32_t)0x00000100)
#define INTC_EVTFLAG_R_EF8_SHIFT         (8)

#define INTC_EVTFLAG_EF8_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF9_MASK        ((uint32_t)0x00000200)
#define INTC_EVTFLAG_R_EF9_SHIFT         (9)

#define INTC_EVTFLAG_EF9_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF10_MASK        ((uint32_t)0x00000400)
#define INTC_EVTFLAG_R_EF10_SHIFT         (10)

#define INTC_EVTFLAG_EF10_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF11_MASK        ((uint32_t)0x00000800)
#define INTC_EVTFLAG_R_EF11_SHIFT         (11)

#define INTC_EVTFLAG_EF11_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF12_MASK        ((uint32_t)0x00001000)
#define INTC_EVTFLAG_R_EF12_SHIFT         (12)

#define INTC_EVTFLAG_EF12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF13_MASK        ((uint32_t)0x00002000)
#define INTC_EVTFLAG_R_EF13_SHIFT         (13)

#define INTC_EVTFLAG_EF13_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF14_MASK        ((uint32_t)0x00004000)
#define INTC_EVTFLAG_R_EF14_SHIFT         (14)

#define INTC_EVTFLAG_EF14_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF15_MASK        ((uint32_t)0x00008000)
#define INTC_EVTFLAG_R_EF15_SHIFT         (15)

#define INTC_EVTFLAG_EF15_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_EVTFLAG_R_EF16_MASK        ((uint32_t)0x00010000)
#define INTC_EVTFLAG_R_EF16_SHIFT         (16)

#define INTC_EVTFLAG_EF16_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF17_MASK        ((uint32_t)0x00020000)
#define INTC_EVTFLAG_R_EF17_SHIFT         (17)

#define INTC_EVTFLAG_EF17_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF18_MASK        ((uint32_t)0x00040000)
#define INTC_EVTFLAG_R_EF18_SHIFT         (18)

#define INTC_EVTFLAG_EF18_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF19_MASK        ((uint32_t)0x00080000)
#define INTC_EVTFLAG_R_EF19_SHIFT         (19)

#define INTC_EVTFLAG_EF19_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF20_MASK        ((uint32_t)0x00100000)
#define INTC_EVTFLAG_R_EF20_SHIFT         (20)

#define INTC_EVTFLAG_EF20_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF21_MASK        ((uint32_t)0x00200000)
#define INTC_EVTFLAG_R_EF21_SHIFT         (21)

#define INTC_EVTFLAG_EF21_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF22_MASK        ((uint32_t)0x00400000)
#define INTC_EVTFLAG_R_EF22_SHIFT         (22)

#define INTC_EVTFLAG_EF22_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF23_MASK        ((uint32_t)0x00800000)
#define INTC_EVTFLAG_R_EF23_SHIFT         (23)

#define INTC_EVTFLAG_EF23_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF24_MASK        ((uint32_t)0x01000000)
#define INTC_EVTFLAG_R_EF24_SHIFT         (24)

#define INTC_EVTFLAG_EF24_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF25_MASK        ((uint32_t)0x02000000)
#define INTC_EVTFLAG_R_EF25_SHIFT         (25)

#define INTC_EVTFLAG_EF25_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_EVTFLAG_R_EF26_MASK        ((uint32_t)0x04000000)
#define INTC_EVTFLAG_R_EF26_SHIFT         (26)

#define INTC_EVTFLAG_EF26_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF27_MASK        ((uint32_t)0x08000000)
#define INTC_EVTFLAG_R_EF27_SHIFT         (27)

#define INTC_EVTFLAG_EF27_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF28_MASK        ((uint32_t)0x10000000)
#define INTC_EVTFLAG_R_EF28_SHIFT         (28)

#define INTC_EVTFLAG_EF28_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF29_MASK        ((uint32_t)0x20000000)
#define INTC_EVTFLAG_R_EF29_SHIFT         (29)

#define INTC_EVTFLAG_EF29_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF30_MASK        ((uint32_t)0x40000000)
#define INTC_EVTFLAG_R_EF30_SHIFT         (30)

#define INTC_EVTFLAG_EF30_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTFLAG_R_EF31_MASK        ((uint32_t)0x80000000)
#define INTC_EVTFLAG_R_EF31_SHIFT         (31)

#define INTC_EVTFLAG_EF31_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 2 EVTSET ***********************************************
**********************************************************************************************/
#define INTC_EVTSET0                   (((INTC_EVTSET_TypeDef*)(INTC_BASE+INTC_EVTSET0_OFFSET )))
#define INTC_EVTSET0_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTSET0_OFFSET)))
#define INTC_EVTSET1                   (((INTC_EVTSET_TypeDef*)(INTC_BASE+INTC_EVTSET1_OFFSET )))
#define INTC_EVTSET1_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTSET1_OFFSET)))
#define INTC_EVTSET2                   (((INTC_EVTSET_TypeDef*)(INTC_BASE+INTC_EVTSET2_OFFSET )))
#define INTC_EVTSET2_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTSET2_OFFSET)))
#define INTC_EVTSET3                   (((INTC_EVTSET_TypeDef*)(INTC_BASE+INTC_EVTSET3_OFFSET )))
#define INTC_EVTSET3_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTSET3_OFFSET)))
#define INTC_EVTSET(n)                (((INTC_EVTSET_TypeDef*)(INTC_BASE+INTC_EVTSET0_OFFSET +((n)*4) )))
#define INTC_EVTSET_R(n)              (*((__IO uint32_t *)(INTC_BASE+INTC_EVTSET0_OFFSET +((n)*4))))

#define INTC_EVTSET_R_ES(n)           (0x1 << ((n) & 31))
/*--------*/
#define INTC_EVTSET_R_ES0_MASK        ((uint32_t)0x00000001)
#define INTC_EVTSET_R_ES0_SHIFT         (0)

#define INTC_EVTSET_ES0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES1_MASK        ((uint32_t)0x00000002)
#define INTC_EVTSET_R_ES1_SHIFT         (1)

#define INTC_EVTSET_ES1_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES2_MASK        ((uint32_t)0x00000004)
#define INTC_EVTSET_R_ES2_SHIFT         (2)

#define INTC_EVTSET_ES2_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES3_MASK        ((uint32_t)0x00000008)
#define INTC_EVTSET_R_ES3_SHIFT         (3)

#define INTC_EVTSET_ES3_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES4_MASK        ((uint32_t)0x00000010)
#define INTC_EVTSET_R_ES4_SHIFT         (4)

#define INTC_EVTSET_ES4_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES5_MASK        ((uint32_t)0x00000020)
#define INTC_EVTSET_R_ES5_SHIFT         (5)

#define INTC_EVTSET_ES5_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES6_MASK        ((uint32_t)0x00000040)
#define INTC_EVTSET_R_ES6_SHIFT         (6)

#define INTC_EVTSET_ES6_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES7_MASK        ((uint32_t)0x00000080)
#define INTC_EVTSET_R_ES7_SHIFT         (7)

#define INTC_EVTSET_ES7_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES8_MASK        ((uint32_t)0x00000100)
#define INTC_EVTSET_R_ES8_SHIFT         (8)

#define INTC_EVTSET_ES8_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES9_MASK        ((uint32_t)0x00000200)
#define INTC_EVTSET_R_ES9_SHIFT         (9)

#define INTC_EVTSET_ES9_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES10_MASK        ((uint32_t)0x00000400)
#define INTC_EVTSET_R_ES10_SHIFT         (10)

#define INTC_EVTSET_ES10_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES11_MASK        ((uint32_t)0x00000800)
#define INTC_EVTSET_R_ES11_SHIFT         (11)

#define INTC_EVTSET_ES11_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES12_MASK        ((uint32_t)0x00001000)
#define INTC_EVTSET_R_ES12_SHIFT         (12)

#define INTC_EVTSET_ES12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES13_MASK        ((uint32_t)0x00002000)
#define INTC_EVTSET_R_ES13_SHIFT         (13)

#define INTC_EVTSET_ES13_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES14_MASK        ((uint32_t)0x00004000)
#define INTC_EVTSET_R_ES14_SHIFT         (14)

#define INTC_EVTSET_ES14_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES15_MASK        ((uint32_t)0x00008000)
#define INTC_EVTSET_R_ES15_SHIFT         (15)

#define INTC_EVTSET_ES15_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_EVTSET_R_ES16_MASK        ((uint32_t)0x00010000)
#define INTC_EVTSET_R_ES16_SHIFT         (16)

#define INTC_EVTSET_ES16_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES17_MASK        ((uint32_t)0x00020000)
#define INTC_EVTSET_R_ES17_SHIFT         (17)

#define INTC_EVTSET_ES17_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES18_MASK        ((uint32_t)0x00040000)
#define INTC_EVTSET_R_ES18_SHIFT         (18)

#define INTC_EVTSET_ES18_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES19_MASK        ((uint32_t)0x00080000)
#define INTC_EVTSET_R_ES19_SHIFT         (19)

#define INTC_EVTSET_ES19_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES20_MASK        ((uint32_t)0x00100000)
#define INTC_EVTSET_R_ES20_SHIFT         (20)

#define INTC_EVTSET_ES20_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES21_MASK        ((uint32_t)0x00200000)
#define INTC_EVTSET_R_ES21_SHIFT         (21)

#define INTC_EVTSET_ES21_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES22_MASK        ((uint32_t)0x00400000)
#define INTC_EVTSET_R_ES22_SHIFT         (22)

#define INTC_EVTSET_ES22_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES23_MASK        ((uint32_t)0x00800000)
#define INTC_EVTSET_R_ES23_SHIFT         (23)

#define INTC_EVTSET_ES23_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES24_MASK        ((uint32_t)0x01000000)
#define INTC_EVTSET_R_ES24_SHIFT         (24)

#define INTC_EVTSET_ES24_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES25_MASK        ((uint32_t)0x02000000)
#define INTC_EVTSET_R_ES25_SHIFT         (25)

#define INTC_EVTSET_ES25_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_EVTSET_R_ES26_MASK        ((uint32_t)0x04000000)
#define INTC_EVTSET_R_ES26_SHIFT         (26)

#define INTC_EVTSET_ES26_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES27_MASK        ((uint32_t)0x08000000)
#define INTC_EVTSET_R_ES27_SHIFT         (27)

#define INTC_EVTSET_ES27_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES28_MASK        ((uint32_t)0x10000000)
#define INTC_EVTSET_R_ES28_SHIFT         (28)

#define INTC_EVTSET_ES28_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES29_MASK        ((uint32_t)0x20000000)
#define INTC_EVTSET_R_ES29_SHIFT         (29)

#define INTC_EVTSET_ES29_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES30_MASK        ((uint32_t)0x40000000)
#define INTC_EVTSET_R_ES30_SHIFT         (30)

#define INTC_EVTSET_ES30_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTSET_R_ES31_MASK        ((uint32_t)0x80000000)
#define INTC_EVTSET_R_ES31_SHIFT         (31)

#define INTC_EVTSET_ES31_MASK          ((uint32_t)0x00000001)
/*--------*/



/**********************************************************************************************
************************************** 3 EVTCLR ***********************************************
**********************************************************************************************/
#define INTC_EVTCLR0                   (((INTC_EVTCLR_TypeDef*)(INTC_BASE+INTC_EVTCLR0_OFFSET )))
#define INTC_EVTCLR0_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTCLR0_OFFSET)))
#define INTC_EVTCLR1                   (((INTC_EVTCLR_TypeDef*)(INTC_BASE+INTC_EVTCLR1_OFFSET )))
#define INTC_EVTCLR1_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTCLR1_OFFSET)))
#define INTC_EVTCLR2                   (((INTC_EVTCLR_TypeDef*)(INTC_BASE+INTC_EVTCLR2_OFFSET )))
#define INTC_EVTCLR2_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTCLR2_OFFSET)))
#define INTC_EVTCLR3                   (((INTC_EVTCLR_TypeDef*)(INTC_BASE+INTC_EVTCLR3_OFFSET )))
#define INTC_EVTCLR3_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTCLR3_OFFSET)))
#define INTC_EVTCLR(n)                (((INTC_EVTCLR_TypeDef*)(INTC_BASE+INTC_EVTCLR0_OFFSET +((n)*4) )))
#define INTC_EVTCLR_R(n)              (*((__IO uint32_t *)(INTC_BASE+INTC_EVTCLR0_OFFSET +((n)*4))))

#define INTC_EVTCLR_R_EC(n)           (0x1 << ((n) & 31))
/*--------*/
#define INTC_EVTCLR_R_EC0_MASK        ((uint32_t)0x00000001)
#define INTC_EVTCLR_R_EC0_SHIFT         (0)

#define INTC_EVTCLR_EC0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC1_MASK        ((uint32_t)0x00000002)
#define INTC_EVTCLR_R_EC1_SHIFT         (1)

#define INTC_EVTCLR_EC1_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC2_MASK        ((uint32_t)0x00000004)
#define INTC_EVTCLR_R_EC2_SHIFT         (2)

#define INTC_EVTCLR_EC2_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC3_MASK        ((uint32_t)0x00000008)
#define INTC_EVTCLR_R_EC3_SHIFT         (3)

#define INTC_EVTCLR_EC3_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC4_MASK        ((uint32_t)0x00000010)
#define INTC_EVTCLR_R_EC4_SHIFT         (4)

#define INTC_EVTCLR_EC4_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC5_MASK        ((uint32_t)0x00000020)
#define INTC_EVTCLR_R_EC5_SHIFT         (5)

#define INTC_EVTCLR_EC5_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC6_MASK        ((uint32_t)0x00000040)
#define INTC_EVTCLR_R_EC6_SHIFT         (6)

#define INTC_EVTCLR_EC6_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC7_MASK        ((uint32_t)0x00000080)
#define INTC_EVTCLR_R_EC7_SHIFT         (7)

#define INTC_EVTCLR_EC7_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC8_MASK        ((uint32_t)0x00000100)
#define INTC_EVTCLR_R_EC8_SHIFT         (8)

#define INTC_EVTCLR_EC8_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC9_MASK        ((uint32_t)0x00000200)
#define INTC_EVTCLR_R_EC9_SHIFT         (9)

#define INTC_EVTCLR_EC9_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC10_MASK        ((uint32_t)0x00000400)
#define INTC_EVTCLR_R_EC10_SHIFT         (10)

#define INTC_EVTCLR_EC10_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC11_MASK        ((uint32_t)0x00000800)
#define INTC_EVTCLR_R_EC11_SHIFT         (11)

#define INTC_EVTCLR_EC11_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC12_MASK        ((uint32_t)0x00001000)
#define INTC_EVTCLR_R_EC12_SHIFT         (12)

#define INTC_EVTCLR_EC12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC13_MASK        ((uint32_t)0x00002000)
#define INTC_EVTCLR_R_EC13_SHIFT         (13)

#define INTC_EVTCLR_EC13_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC14_MASK        ((uint32_t)0x00004000)
#define INTC_EVTCLR_R_EC14_SHIFT         (14)

#define INTC_EVTCLR_EC14_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC15_MASK        ((uint32_t)0x00008000)
#define INTC_EVTCLR_R_EC15_SHIFT         (15)

#define INTC_EVTCLR_EC15_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_EVTCLR_R_EC16_MASK        ((uint32_t)0x00010000)
#define INTC_EVTCLR_R_EC16_SHIFT         (16)

#define INTC_EVTCLR_EC16_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC17_MASK        ((uint32_t)0x00020000)
#define INTC_EVTCLR_R_EC17_SHIFT         (17)

#define INTC_EVTCLR_EC17_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC18_MASK        ((uint32_t)0x00040000)
#define INTC_EVTCLR_R_EC18_SHIFT         (18)

#define INTC_EVTCLR_EC18_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC19_MASK        ((uint32_t)0x00080000)
#define INTC_EVTCLR_R_EC19_SHIFT         (19)

#define INTC_EVTCLR_EC19_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC20_MASK        ((uint32_t)0x00100000)
#define INTC_EVTCLR_R_EC20_SHIFT         (20)

#define INTC_EVTCLR_EC20_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC21_MASK        ((uint32_t)0x00200000)
#define INTC_EVTCLR_R_EC21_SHIFT         (21)

#define INTC_EVTCLR_EC21_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC22_MASK        ((uint32_t)0x00400000)
#define INTC_EVTCLR_R_EC22_SHIFT         (22)

#define INTC_EVTCLR_EC22_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC23_MASK        ((uint32_t)0x00800000)
#define INTC_EVTCLR_R_EC23_SHIFT         (23)

#define INTC_EVTCLR_EC23_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC24_MASK        ((uint32_t)0x01000000)
#define INTC_EVTCLR_R_EC24_SHIFT         (24)

#define INTC_EVTCLR_EC24_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC25_MASK        ((uint32_t)0x02000000)
#define INTC_EVTCLR_R_EC25_SHIFT         (25)

#define INTC_EVTCLR_EC25_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_EVTCLR_R_EC26_MASK        ((uint32_t)0x04000000)
#define INTC_EVTCLR_R_EC26_SHIFT         (26)

#define INTC_EVTCLR_EC26_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC27_MASK        ((uint32_t)0x08000000)
#define INTC_EVTCLR_R_EC27_SHIFT         (27)

#define INTC_EVTCLR_EC27_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC28_MASK        ((uint32_t)0x10000000)
#define INTC_EVTCLR_R_EC28_SHIFT         (28)

#define INTC_EVTCLR_EC28_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC29_MASK        ((uint32_t)0x20000000)
#define INTC_EVTCLR_R_EC29_SHIFT         (29)

#define INTC_EVTCLR_EC29_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC30_MASK        ((uint32_t)0x40000000)
#define INTC_EVTCLR_R_EC30_SHIFT         (30)

#define INTC_EVTCLR_EC30_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTCLR_R_EC31_MASK        ((uint32_t)0x80000000)
#define INTC_EVTCLR_R_EC31_SHIFT         (31)

#define INTC_EVTCLR_EC31_MASK          ((uint32_t)0x00000001)
/*--------*/



/**********************************************************************************************
************************************** 4 EVTMASK ***********************************************
**********************************************************************************************/
#define INTC_EVTMASK0                   (((INTC_EVTMASK_TypeDef*)(INTC_BASE+INTC_EVTMASK0_OFFSET )))
#define INTC_EVTMASK0_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTMASK0_OFFSET)))
#define INTC_EVTMASK1                   (((INTC_EVTMASK_TypeDef*)(INTC_BASE+INTC_EVTMASK1_OFFSET )))
#define INTC_EVTMASK1_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTMASK1_OFFSET)))
#define INTC_EVTMASK2                   (((INTC_EVTMASK_TypeDef*)(INTC_BASE+INTC_EVTMASK2_OFFSET )))
#define INTC_EVTMASK2_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTMASK2_OFFSET)))
#define INTC_EVTMASK3                   (((INTC_EVTMASK_TypeDef*)(INTC_BASE+INTC_EVTMASK3_OFFSET )))
#define INTC_EVTMASK3_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EVTMASK3_OFFSET)))
#define INTC_EVTMASK(n)                (((INTC_EVTMASK_TypeDef*)(INTC_BASE+INTC_EVTMASK0_OFFSET +((n)*4) )))
#define INTC_EVTMASK_R(n)              (*((__IO uint32_t *)(INTC_BASE+INTC_EVTMASK0_OFFSET +((n)*4))))

#define INTC_EVTMASK_R_EM(n)           (0x1 << ((n) & 31))
/*--------*/
#define INTC_EVTMASK_R_EM0_MASK        ((uint32_t)0x00000001)
#define INTC_EVTMASK_R_EM0_SHIFT         (0)

#define INTC_EVTMASK_EM0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM1_MASK        ((uint32_t)0x00000002)
#define INTC_EVTMASK_R_EM1_SHIFT         (1)

#define INTC_EVTMASK_EM1_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM2_MASK        ((uint32_t)0x00000004)
#define INTC_EVTMASK_R_EM2_SHIFT         (2)

#define INTC_EVTMASK_EM2_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM3_MASK        ((uint32_t)0x00000008)
#define INTC_EVTMASK_R_EM3_SHIFT         (3)

#define INTC_EVTMASK_EM3_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM4_MASK        ((uint32_t)0x00000010)
#define INTC_EVTMASK_R_EM4_SHIFT         (4)

#define INTC_EVTMASK_EM4_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM5_MASK        ((uint32_t)0x00000020)
#define INTC_EVTMASK_R_EM5_SHIFT         (5)

#define INTC_EVTMASK_EM5_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM6_MASK        ((uint32_t)0x00000040)
#define INTC_EVTMASK_R_EM6_SHIFT         (6)

#define INTC_EVTMASK_EM6_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM7_MASK        ((uint32_t)0x00000080)
#define INTC_EVTMASK_R_EM7_SHIFT         (7)

#define INTC_EVTMASK_EM7_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM8_MASK        ((uint32_t)0x00000100)
#define INTC_EVTMASK_R_EM8_SHIFT         (8)

#define INTC_EVTMASK_EM8_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM9_MASK        ((uint32_t)0x00000200)
#define INTC_EVTMASK_R_EM9_SHIFT         (9)

#define INTC_EVTMASK_EM9_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM10_MASK        ((uint32_t)0x00000400)
#define INTC_EVTMASK_R_EM10_SHIFT         (10)

#define INTC_EVTMASK_EM10_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM11_MASK        ((uint32_t)0x00000800)
#define INTC_EVTMASK_R_EM11_SHIFT         (11)

#define INTC_EVTMASK_EM11_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM12_MASK        ((uint32_t)0x00001000)
#define INTC_EVTMASK_R_EM12_SHIFT         (12)

#define INTC_EVTMASK_EM12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM13_MASK        ((uint32_t)0x00002000)
#define INTC_EVTMASK_R_EM13_SHIFT         (13)

#define INTC_EVTMASK_EM13_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM14_MASK        ((uint32_t)0x00004000)
#define INTC_EVTMASK_R_EM14_SHIFT         (14)

#define INTC_EVTMASK_EM14_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM15_MASK        ((uint32_t)0x00008000)
#define INTC_EVTMASK_R_EM15_SHIFT         (15)

#define INTC_EVTMASK_EM15_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_EVTMASK_R_EM16_MASK        ((uint32_t)0x00010000)
#define INTC_EVTMASK_R_EM16_SHIFT         (16)

#define INTC_EVTMASK_EM16_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM17_MASK        ((uint32_t)0x00020000)
#define INTC_EVTMASK_R_EM17_SHIFT         (17)

#define INTC_EVTMASK_EM17_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM18_MASK        ((uint32_t)0x00040000)
#define INTC_EVTMASK_R_EM18_SHIFT         (18)

#define INTC_EVTMASK_EM18_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM19_MASK        ((uint32_t)0x00080000)
#define INTC_EVTMASK_R_EM19_SHIFT         (19)

#define INTC_EVTMASK_EM19_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM20_MASK        ((uint32_t)0x00100000)
#define INTC_EVTMASK_R_EM20_SHIFT         (20)

#define INTC_EVTMASK_EM20_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM21_MASK        ((uint32_t)0x00200000)
#define INTC_EVTMASK_R_EM21_SHIFT         (21)

#define INTC_EVTMASK_EM21_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM22_MASK        ((uint32_t)0x00400000)
#define INTC_EVTMASK_R_EM22_SHIFT         (22)

#define INTC_EVTMASK_EM22_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM23_MASK        ((uint32_t)0x00800000)
#define INTC_EVTMASK_R_EM23_SHIFT         (23)

#define INTC_EVTMASK_EM23_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM24_MASK        ((uint32_t)0x01000000)
#define INTC_EVTMASK_R_EM24_SHIFT         (24)

#define INTC_EVTMASK_EM24_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM25_MASK        ((uint32_t)0x02000000)
#define INTC_EVTMASK_R_EM25_SHIFT         (25)

#define INTC_EVTMASK_EM25_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_EVTMASK_R_EM26_MASK        ((uint32_t)0x04000000)
#define INTC_EVTMASK_R_EM26_SHIFT         (26)

#define INTC_EVTMASK_EM26_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM27_MASK        ((uint32_t)0x08000000)
#define INTC_EVTMASK_R_EM27_SHIFT         (27)

#define INTC_EVTMASK_EM27_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM28_MASK        ((uint32_t)0x10000000)
#define INTC_EVTMASK_R_EM28_SHIFT         (28)

#define INTC_EVTMASK_EM28_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM29_MASK        ((uint32_t)0x20000000)
#define INTC_EVTMASK_R_EM29_SHIFT         (29)

#define INTC_EVTMASK_EM29_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM30_MASK        ((uint32_t)0x40000000)
#define INTC_EVTMASK_R_EM30_SHIFT         (30)

#define INTC_EVTMASK_EM30_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EVTMASK_R_EM31_MASK        ((uint32_t)0x80000000)
#define INTC_EVTMASK_R_EM31_SHIFT         (31)

#define INTC_EVTMASK_EM31_MASK          ((uint32_t)0x00000001)
/*--------*/



/**********************************************************************************************
************************************** 5 MEVTFLAG ***********************************************
**********************************************************************************************/
#define INTC_MEVTFLAG0                   (((INTC_MEVTFLAG_TypeDef*)(INTC_BASE+INTC_MEVTFLAG0_OFFSET )))
#define INTC_MEVTFLAG0_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_MEVTFLAG0_OFFSET)))
#define INTC_MEVTFLAG1                   (((INTC_MEVTFLAG_TypeDef*)(INTC_BASE+INTC_MEVTFLAG1_OFFSET )))
#define INTC_MEVTFLAG1_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_MEVTFLAG1_OFFSET)))
#define INTC_MEVTFLAG2                   (((INTC_MEVTFLAG_TypeDef*)(INTC_BASE+INTC_MEVTFLAG2_OFFSET )))
#define INTC_MEVTFLAG2_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_MEVTFLAG2_OFFSET)))
#define INTC_MEVTFLAG3                   (((INTC_MEVTFLAG_TypeDef*)(INTC_BASE+INTC_MEVTFLAG3_OFFSET )))
#define INTC_MEVTFLAG3_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_MEVTFLAG3_OFFSET)))
#define INTC_MEVTFLAG(n)                (((INTC_MEVTFLAG_TypeDef*)(INTC_BASE+INTC_MEVTFLAG0_OFFSET +((n)*4) )))
#define INTC_MEVTFLAG_R(n)              (*((__IO uint32_t *)(INTC_BASE+INTC_MEVTFLAG0_OFFSET +((n)*4))))

#define INTC_MEVTFLAG_R_EMF(n)           (0x1 << ((n) & 31))
/*--------*/
#define INTC_MEVTFLAG_R_EMF0_MASK        ((uint32_t)0x00000001)
#define INTC_MEVTFLAG_R_EMF0_SHIFT         (0)

#define INTC_MEVTFLAG_EMF0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF1_MASK        ((uint32_t)0x00000002)
#define INTC_MEVTFLAG_R_EMF1_SHIFT         (1)

#define INTC_MEVTFLAG_EMF1_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF2_MASK        ((uint32_t)0x00000004)
#define INTC_MEVTFLAG_R_EMF2_SHIFT         (2)

#define INTC_MEVTFLAG_EMF2_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF3_MASK        ((uint32_t)0x00000008)
#define INTC_MEVTFLAG_R_EMF3_SHIFT         (3)

#define INTC_MEVTFLAG_EMF3_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF4_MASK        ((uint32_t)0x00000010)
#define INTC_MEVTFLAG_R_EMF4_SHIFT         (4)

#define INTC_MEVTFLAG_EMF4_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF5_MASK        ((uint32_t)0x00000020)
#define INTC_MEVTFLAG_R_EMF5_SHIFT         (5)

#define INTC_MEVTFLAG_EMF5_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF6_MASK        ((uint32_t)0x00000040)
#define INTC_MEVTFLAG_R_EMF6_SHIFT         (6)

#define INTC_MEVTFLAG_EMF6_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF7_MASK        ((uint32_t)0x00000080)
#define INTC_MEVTFLAG_R_EMF7_SHIFT         (7)

#define INTC_MEVTFLAG_EMF7_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF8_MASK        ((uint32_t)0x00000100)
#define INTC_MEVTFLAG_R_EMF8_SHIFT         (8)

#define INTC_MEVTFLAG_EMF8_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF9_MASK        ((uint32_t)0x00000200)
#define INTC_MEVTFLAG_R_EMF9_SHIFT         (9)

#define INTC_MEVTFLAG_EMF9_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF10_MASK        ((uint32_t)0x00000400)
#define INTC_MEVTFLAG_R_EMF10_SHIFT         (10)

#define INTC_MEVTFLAG_EMF10_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF11_MASK        ((uint32_t)0x00000800)
#define INTC_MEVTFLAG_R_EMF11_SHIFT         (11)

#define INTC_MEVTFLAG_EMF11_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF12_MASK        ((uint32_t)0x00001000)
#define INTC_MEVTFLAG_R_EMF12_SHIFT         (12)

#define INTC_MEVTFLAG_EMF12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF13_MASK        ((uint32_t)0x00002000)
#define INTC_MEVTFLAG_R_EMF13_SHIFT         (13)

#define INTC_MEVTFLAG_EMF13_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF14_MASK        ((uint32_t)0x00004000)
#define INTC_MEVTFLAG_R_EMF14_SHIFT         (14)

#define INTC_MEVTFLAG_EMF14_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF15_MASK        ((uint32_t)0x00008000)
#define INTC_MEVTFLAG_R_EMF15_SHIFT         (15)

#define INTC_MEVTFLAG_EMF15_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_MEVTFLAG_R_EMF16_MASK        ((uint32_t)0x00010000)
#define INTC_MEVTFLAG_R_EMF16_SHIFT         (16)

#define INTC_MEVTFLAG_EMF16_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF17_MASK        ((uint32_t)0x00020000)
#define INTC_MEVTFLAG_R_EMF17_SHIFT         (17)

#define INTC_MEVTFLAG_EMF17_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF18_MASK        ((uint32_t)0x00040000)
#define INTC_MEVTFLAG_R_EMF18_SHIFT         (18)

#define INTC_MEVTFLAG_EMF18_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF19_MASK        ((uint32_t)0x00080000)
#define INTC_MEVTFLAG_R_EMF19_SHIFT         (19)

#define INTC_MEVTFLAG_EMF19_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF20_MASK        ((uint32_t)0x00100000)
#define INTC_MEVTFLAG_R_EMF20_SHIFT         (20)

#define INTC_MEVTFLAG_EMF20_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF21_MASK        ((uint32_t)0x00200000)
#define INTC_MEVTFLAG_R_EMF21_SHIFT         (21)

#define INTC_MEVTFLAG_EMF21_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF22_MASK        ((uint32_t)0x00400000)
#define INTC_MEVTFLAG_R_EMF22_SHIFT         (22)

#define INTC_MEVTFLAG_EMF22_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF23_MASK        ((uint32_t)0x00800000)
#define INTC_MEVTFLAG_R_EMF23_SHIFT         (23)

#define INTC_MEVTFLAG_EMF23_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF24_MASK        ((uint32_t)0x01000000)
#define INTC_MEVTFLAG_R_EMF24_SHIFT         (24)

#define INTC_MEVTFLAG_EMF24_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF25_MASK        ((uint32_t)0x02000000)
#define INTC_MEVTFLAG_R_EMF25_SHIFT         (25)

#define INTC_MEVTFLAG_EMF25_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_MEVTFLAG_R_EMF26_MASK        ((uint32_t)0x04000000)
#define INTC_MEVTFLAG_R_EMF26_SHIFT         (26)

#define INTC_MEVTFLAG_EMF26_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF27_MASK        ((uint32_t)0x08000000)
#define INTC_MEVTFLAG_R_EMF27_SHIFT         (27)

#define INTC_MEVTFLAG_EMF27_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF28_MASK        ((uint32_t)0x10000000)
#define INTC_MEVTFLAG_R_EMF28_SHIFT         (28)

#define INTC_MEVTFLAG_EMF28_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF29_MASK        ((uint32_t)0x20000000)
#define INTC_MEVTFLAG_R_EMF29_SHIFT         (29)

#define INTC_MEVTFLAG_EMF29_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF30_MASK        ((uint32_t)0x40000000)
#define INTC_MEVTFLAG_R_EMF30_SHIFT         (30)

#define INTC_MEVTFLAG_EMF30_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEVTFLAG_R_EMF31_MASK        ((uint32_t)0x80000000)
#define INTC_MEVTFLAG_R_EMF31_SHIFT         (31)

#define INTC_MEVTFLAG_EMF31_MASK          ((uint32_t)0x00000001)
/*--------*/



/**********************************************************************************************
************************************** 6 EXPMASK ***********************************************
**********************************************************************************************/
#define INTC_EXPMASK0                   (((INTC_EXPMASK_TypeDef*)(INTC_BASE+INTC_EXPMASK0_OFFSET )))
#define INTC_EXPMASK0_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EXPMASK0_OFFSET)))
#define INTC_EXPMASK1                   (((INTC_EXPMASK_TypeDef*)(INTC_BASE+INTC_EXPMASK1_OFFSET )))
#define INTC_EXPMASK1_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EXPMASK1_OFFSET)))
#define INTC_EXPMASK2                   (((INTC_EXPMASK_TypeDef*)(INTC_BASE+INTC_EXPMASK2_OFFSET )))
#define INTC_EXPMASK2_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EXPMASK2_OFFSET)))
#define INTC_EXPMASK3                   (((INTC_EXPMASK_TypeDef*)(INTC_BASE+INTC_EXPMASK3_OFFSET )))
#define INTC_EXPMASK3_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_EXPMASK3_OFFSET)))
#define INTC_EXPMASK(n)                (((INTC_EXPMASK_TypeDef*)(INTC_BASE+INTC_EXPMASK0_OFFSET +((n)*4) )))
#define INTC_EXPMASK_R(n)              (*((__IO uint32_t *)(INTC_BASE+INTC_EXPMASK0_OFFSET +((n)*4))))

#define INTC_EXPMASK_R_XM(n)           (0x1 << ((n) & 31))
/*--------*/
#define INTC_EXPMASK_R_XM0_MASK        ((uint32_t)0x00000001)
#define INTC_EXPMASK_R_XM0_SHIFT         (0)

#define INTC_EXPMASK_XM0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM1_MASK        ((uint32_t)0x00000002)
#define INTC_EXPMASK_R_XM1_SHIFT         (1)

#define INTC_EXPMASK_XM1_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM2_MASK        ((uint32_t)0x00000004)
#define INTC_EXPMASK_R_XM2_SHIFT         (2)

#define INTC_EXPMASK_XM2_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM3_MASK        ((uint32_t)0x00000008)
#define INTC_EXPMASK_R_XM3_SHIFT         (3)

#define INTC_EXPMASK_XM3_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM4_MASK        ((uint32_t)0x00000010)
#define INTC_EXPMASK_R_XM4_SHIFT         (4)

#define INTC_EXPMASK_XM4_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM5_MASK        ((uint32_t)0x00000020)
#define INTC_EXPMASK_R_XM5_SHIFT         (5)

#define INTC_EXPMASK_XM5_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM6_MASK        ((uint32_t)0x00000040)
#define INTC_EXPMASK_R_XM6_SHIFT         (6)

#define INTC_EXPMASK_XM6_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM7_MASK        ((uint32_t)0x00000080)
#define INTC_EXPMASK_R_XM7_SHIFT         (7)

#define INTC_EXPMASK_XM7_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM8_MASK        ((uint32_t)0x00000100)
#define INTC_EXPMASK_R_XM8_SHIFT         (8)

#define INTC_EXPMASK_XM8_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM9_MASK        ((uint32_t)0x00000200)
#define INTC_EXPMASK_R_XM9_SHIFT         (9)

#define INTC_EXPMASK_XM9_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM10_MASK        ((uint32_t)0x00000400)
#define INTC_EXPMASK_R_XM10_SHIFT         (10)

#define INTC_EXPMASK_XM10_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM11_MASK        ((uint32_t)0x00000800)
#define INTC_EXPMASK_R_XM11_SHIFT         (11)

#define INTC_EXPMASK_XM11_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM12_MASK        ((uint32_t)0x00001000)
#define INTC_EXPMASK_R_XM12_SHIFT         (12)

#define INTC_EXPMASK_XM12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM13_MASK        ((uint32_t)0x00002000)
#define INTC_EXPMASK_R_XM13_SHIFT         (13)

#define INTC_EXPMASK_XM13_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM14_MASK        ((uint32_t)0x00004000)
#define INTC_EXPMASK_R_XM14_SHIFT         (14)

#define INTC_EXPMASK_XM14_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM15_MASK        ((uint32_t)0x00008000)
#define INTC_EXPMASK_R_XM15_SHIFT         (15)

#define INTC_EXPMASK_XM15_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_EXPMASK_R_XM16_MASK        ((uint32_t)0x00010000)
#define INTC_EXPMASK_R_XM16_SHIFT         (16)

#define INTC_EXPMASK_XM16_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM17_MASK        ((uint32_t)0x00020000)
#define INTC_EXPMASK_R_XM17_SHIFT         (17)

#define INTC_EXPMASK_XM17_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM18_MASK        ((uint32_t)0x00040000)
#define INTC_EXPMASK_R_XM18_SHIFT         (18)

#define INTC_EXPMASK_XM18_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM19_MASK        ((uint32_t)0x00080000)
#define INTC_EXPMASK_R_XM19_SHIFT         (19)

#define INTC_EXPMASK_XM19_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM20_MASK        ((uint32_t)0x00100000)
#define INTC_EXPMASK_R_XM20_SHIFT         (20)

#define INTC_EXPMASK_XM20_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM21_MASK        ((uint32_t)0x00200000)
#define INTC_EXPMASK_R_XM21_SHIFT         (21)

#define INTC_EXPMASK_XM21_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM22_MASK        ((uint32_t)0x00400000)
#define INTC_EXPMASK_R_XM22_SHIFT         (22)

#define INTC_EXPMASK_XM22_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM23_MASK        ((uint32_t)0x00800000)
#define INTC_EXPMASK_R_XM23_SHIFT         (23)

#define INTC_EXPMASK_XM23_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM24_MASK        ((uint32_t)0x01000000)
#define INTC_EXPMASK_R_XM24_SHIFT         (24)

#define INTC_EXPMASK_XM24_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM25_MASK        ((uint32_t)0x02000000)
#define INTC_EXPMASK_R_XM25_SHIFT         (25)

#define INTC_EXPMASK_XM25_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_EXPMASK_R_XM26_MASK        ((uint32_t)0x04000000)
#define INTC_EXPMASK_R_XM26_SHIFT         (26)

#define INTC_EXPMASK_XM26_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM27_MASK        ((uint32_t)0x08000000)
#define INTC_EXPMASK_R_XM27_SHIFT         (27)

#define INTC_EXPMASK_XM27_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM28_MASK        ((uint32_t)0x10000000)
#define INTC_EXPMASK_R_XM28_SHIFT         (28)

#define INTC_EXPMASK_XM28_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM29_MASK        ((uint32_t)0x20000000)
#define INTC_EXPMASK_R_XM29_SHIFT         (29)

#define INTC_EXPMASK_XM29_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM30_MASK        ((uint32_t)0x40000000)
#define INTC_EXPMASK_R_XM30_SHIFT         (30)

#define INTC_EXPMASK_XM30_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_EXPMASK_R_XM31_MASK        ((uint32_t)0x80000000)
#define INTC_EXPMASK_R_XM31_SHIFT         (31)

#define INTC_EXPMASK_XM31_MASK          ((uint32_t)0x00000001)
/*--------*/




/**********************************************************************************************
************************************** 7 MEXPFLAG ***********************************************
**********************************************************************************************/
#define INTC_MEXPFLAG0                   (((INTC_MEXPFLAG_TypeDef*)(INTC_BASE+INTC_MEXPFLAG0_OFFSET )))
#define INTC_MEXPFLAG0_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_MEXPFLAG0_OFFSET)))
#define INTC_MEXPFLAG1                   (((INTC_MEXPFLAG_TypeDef*)(INTC_BASE+INTC_MEXPFLAG1_OFFSET )))
#define INTC_MEXPFLAG1_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_MEXPFLAG1_OFFSET)))
#define INTC_MEXPFLAG2                   (((INTC_MEXPFLAG_TypeDef*)(INTC_BASE+INTC_MEXPFLAG2_OFFSET )))
#define INTC_MEXPFLAG2_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_MEXPFLAG2_OFFSET)))
#define INTC_MEXPFLAG3                   (((INTC_MEXPFLAG_TypeDef*)(INTC_BASE+INTC_MEXPFLAG3_OFFSET )))
#define INTC_MEXPFLAG3_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_MEXPFLAG3_OFFSET)))
#define INTC_MEXPFLAG(n)                (((INTC_MEXPFLAG_TypeDef*)(INTC_BASE+INTC_MEXPFLAG0_OFFSET +((n)*4) )))
#define INTC_MEXPFLAG_R(n)              (*((__IO uint32_t *)(INTC_BASE+INTC_MEXPFLAG0_OFFSET +((n)*4))))

#define INTC_MEXPFLAG_R_MXF(n)           (0x1 << ((n) & 31))
/*--------*/
#define INTC_MEXPFLAG_R_MXF0_MASK        ((uint32_t)0x00000001)
#define INTC_MEXPFLAG_R_MXF0_SHIFT         (0)

#define INTC_MEXPFLAG_MXF0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF1_MASK        ((uint32_t)0x00000002)
#define INTC_MEXPFLAG_R_MXF1_SHIFT         (1)

#define INTC_MEXPFLAG_MXF1_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF2_MASK        ((uint32_t)0x00000004)
#define INTC_MEXPFLAG_R_MXF2_SHIFT         (2)

#define INTC_MEXPFLAG_MXF2_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF3_MASK        ((uint32_t)0x00000008)
#define INTC_MEXPFLAG_R_MXF3_SHIFT         (3)

#define INTC_MEXPFLAG_MXF3_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF4_MASK        ((uint32_t)0x00000010)
#define INTC_MEXPFLAG_R_MXF4_SHIFT         (4)

#define INTC_MEXPFLAG_MXF4_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF5_MASK        ((uint32_t)0x00000020)
#define INTC_MEXPFLAG_R_MXF5_SHIFT         (5)

#define INTC_MEXPFLAG_MXF5_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF6_MASK        ((uint32_t)0x00000040)
#define INTC_MEXPFLAG_R_MXF6_SHIFT         (6)

#define INTC_MEXPFLAG_MXF6_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF7_MASK        ((uint32_t)0x00000080)
#define INTC_MEXPFLAG_R_MXF7_SHIFT         (7)

#define INTC_MEXPFLAG_MXF7_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF8_MASK        ((uint32_t)0x00000100)
#define INTC_MEXPFLAG_R_MXF8_SHIFT         (8)

#define INTC_MEXPFLAG_MXF8_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF9_MASK        ((uint32_t)0x00000200)
#define INTC_MEXPFLAG_R_MXF9_SHIFT         (9)

#define INTC_MEXPFLAG_MXF9_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF10_MASK        ((uint32_t)0x00000400)
#define INTC_MEXPFLAG_R_MXF10_SHIFT         (10)

#define INTC_MEXPFLAG_MXF10_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF11_MASK        ((uint32_t)0x00000800)
#define INTC_MEXPFLAG_R_MXF11_SHIFT         (11)

#define INTC_MEXPFLAG_MXF11_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF12_MASK        ((uint32_t)0x00001000)
#define INTC_MEXPFLAG_R_MXF12_SHIFT         (12)

#define INTC_MEXPFLAG_MXF12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF13_MASK        ((uint32_t)0x00002000)
#define INTC_MEXPFLAG_R_MXF13_SHIFT         (13)

#define INTC_MEXPFLAG_MXF13_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF14_MASK        ((uint32_t)0x00004000)
#define INTC_MEXPFLAG_R_MXF14_SHIFT         (14)

#define INTC_MEXPFLAG_MXF14_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF15_MASK        ((uint32_t)0x00008000)
#define INTC_MEXPFLAG_R_MXF15_SHIFT         (15)

#define INTC_MEXPFLAG_MXF15_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_MEXPFLAG_R_MXF16_MASK        ((uint32_t)0x00010000)
#define INTC_MEXPFLAG_R_MXF16_SHIFT         (16)

#define INTC_MEXPFLAG_MXF16_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF17_MASK        ((uint32_t)0x00020000)
#define INTC_MEXPFLAG_R_MXF17_SHIFT         (17)

#define INTC_MEXPFLAG_MXF17_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF18_MASK        ((uint32_t)0x00040000)
#define INTC_MEXPFLAG_R_MXF18_SHIFT         (18)

#define INTC_MEXPFLAG_MXF18_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF19_MASK        ((uint32_t)0x00080000)
#define INTC_MEXPFLAG_R_MXF19_SHIFT         (19)

#define INTC_MEXPFLAG_MXF19_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF20_MASK        ((uint32_t)0x00100000)
#define INTC_MEXPFLAG_R_MXF20_SHIFT         (20)

#define INTC_MEXPFLAG_MXF20_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF21_MASK        ((uint32_t)0x00200000)
#define INTC_MEXPFLAG_R_MXF21_SHIFT         (21)

#define INTC_MEXPFLAG_MXF21_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF22_MASK        ((uint32_t)0x00400000)
#define INTC_MEXPFLAG_R_MXF22_SHIFT         (22)

#define INTC_MEXPFLAG_MXF22_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF23_MASK        ((uint32_t)0x00800000)
#define INTC_MEXPFLAG_R_MXF23_SHIFT         (23)

#define INTC_MEXPFLAG_MXF23_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF24_MASK        ((uint32_t)0x01000000)
#define INTC_MEXPFLAG_R_MXF24_SHIFT         (24)

#define INTC_MEXPFLAG_MXF24_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF25_MASK        ((uint32_t)0x02000000)
#define INTC_MEXPFLAG_R_MXF25_SHIFT         (25)

#define INTC_MEXPFLAG_MXF25_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define INTC_MEXPFLAG_R_MXF26_MASK        ((uint32_t)0x04000000)
#define INTC_MEXPFLAG_R_MXF26_SHIFT         (26)

#define INTC_MEXPFLAG_MXF26_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF27_MASK        ((uint32_t)0x08000000)
#define INTC_MEXPFLAG_R_MXF27_SHIFT         (27)

#define INTC_MEXPFLAG_MXF27_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF28_MASK        ((uint32_t)0x10000000)
#define INTC_MEXPFLAG_R_MXF28_SHIFT         (28)

#define INTC_MEXPFLAG_MXF28_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF29_MASK        ((uint32_t)0x20000000)
#define INTC_MEXPFLAG_R_MXF29_SHIFT         (29)

#define INTC_MEXPFLAG_MXF29_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF30_MASK        ((uint32_t)0x40000000)
#define INTC_MEXPFLAG_R_MXF30_SHIFT         (30)

#define INTC_MEXPFLAG_MXF30_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_MEXPFLAG_R_MXF31_MASK        ((uint32_t)0x80000000)
#define INTC_MEXPFLAG_R_MXF31_SHIFT         (31)

#define INTC_MEXPFLAG_MXF31_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 8 INTMUX ***********************************************
**********************************************************************************************/
#define INTC_INTMUX0                   (((INTC_INTMUX_TypeDef*)(INTC_BASE+INTC_INTMUX0_OFFSET )))
#define INTC_INTMUX0_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_INTMUX0_OFFSET)))
#define INTC_INTMUX1                   (((INTC_INTMUX1_TypeDef*)(INTC_BASE+INTC_INTMUX1_OFFSET )))
#define INTC_INTMUX1_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_INTMUX1_OFFSET)))
#define INTC_INTMUX2                   (((INTC_INTMUX2_TypeDef*)(INTC_BASE+INTC_INTMUX2_OFFSET )))
#define INTC_INTMUX2_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_INTMUX2_OFFSET)))
#define INTC_INTMUX3                   (((INTC_INTMUX3_TypeDef*)(INTC_BASE+INTC_INTMUX3_OFFSET )))
#define INTC_INTMUX3_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_INTMUX3_OFFSET)))
#define INTC_INTMUX(n)                (((INTC_INTMUX_TypeDef*)(INTC_BASE+INTC_INTMUX0_OFFSET +((n)*4) )))
#define INTC_INTMUX_R(n)              (*((__IO uint32_t *)(INTC_BASE+INTC_INTMUX0_OFFSET +((n)*4))))



#define INTC_INTMUX_R_INTSEL_SHIFT(n)     ((n<<3) & 31)
#define INTC_INTMUX_R_INTSEL(n)           (0x7F << ((n<<3) & 31))
/*--------*/
#define INTC_INTMUX_R_INTSEL0_MASK        ((uint32_t)0x0000007F)
#define INTC_INTMUX_R_INTSEL0_SHIFT         (0)

#define INTC_INTMUX_INTSEL0_MASK          ((uint32_t)0x0000007F)
/*--------*/

/*--------*/
#define INTC_INTMUX_R_INTSEL1_MASK        ((uint32_t)0x00007F00)
#define INTC_INTMUX_R_INTSEL1_SHIFT         (8)

#define INTC_INTMUX_INTSEL1_MASK          ((uint32_t)0x0000007F)
/*--------*/

/*--------*/
#define INTC_INTMUX_R_INTSEL2_MASK        ((uint32_t)0x007F0000)
#define INTC_INTMUX_R_INTSEL2_SHIFT         (16)

#define INTC_INTMUX_INTSEL2_MASK          ((uint32_t)0x0000007F)
/*--------*/

/*--------*/
#define INTC_INTMUX_R_INTSEL3_MASK        ((uint32_t)0x7F000000)
#define INTC_INTMUX_R_INTSEL3_SHIFT         (24)

#define INTC_INTMUX_INTSEL3_MASK          ((uint32_t)0x0000007F)
/*--------*/

/**********************************************************************************************
************************************** 9 AEGMUX ***********************************************
**********************************************************************************************/
#define INTC_AEGMUX0                   (((INTC_AEGMUX_TypeDef*)(INTC_BASE+INTC_AEGMUX0_OFFSET )))
#define INTC_AEGMUX0_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_AEGMUX0_OFFSET)))
#define INTC_AEGMUX1                   (((INTC_AEGMUX_TypeDef*)(INTC_BASE+INTC_AEGMUX1_OFFSET )))
#define INTC_AEGMUX1_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_AEGMUX1_OFFSET)))
#define INTC_AEGMUX(n)                (((INTC_AEGMUX_TypeDef*)(INTC_BASE+INTC_AEGMUX0_OFFSET +((n)*4) )))
#define INTC_AEGMUX_R(n)              (*((__IO uint32_t *)(INTC_BASE+INTC_AEGMUX0_OFFSET +((n)*4))))

#define INTC_AEGMUX_R_AEGSEL(n)           (0xFF << ((n<<3) & 31))
/*--------*/
#define INTC_AEGMUX_R_AEGSEL0_MASK        ((uint32_t)0x000000FF)
#define INTC_AEGMUX_R_AEGSEL0_SHIFT         (0)

#define INTC_AEGMUX_AEGSEL0_MASK          ((uint32_t)0x000000FF)
/*--------*/

/*--------*/
#define INTC_AEGMUX_R_AEGSEL1_MASK        ((uint32_t)0x0000FF00)
#define INTC_AEGMUX_R_AEGSEL1_SHIFT         (8)

#define INTC_AEGMUX_AEGSEL1_MASK          ((uint32_t)0x000000FF)
/*--------*/

/*--------*/
#define INTC_AEGMUX_R_AEGSEL2_MASK        ((uint32_t)0x00FF0000)
#define INTC_AEGMUX_R_AEGSEL2_SHIFT         (16)

#define INTC_AEGMUX_AEGSEL2_MASK          ((uint32_t)0x000000FF)
/*--------*/

/*--------*/
#define INTC_AEGMUX_R_AEGSEL3_MASK        ((uint32_t)0xFF000000)
#define INTC_AEGMUX_R_AEGSEL3_SHIFT         (24)

#define INTC_AEGMUX_AEGSEL3_MASK          ((uint32_t)0x000000FF)
/*--------*/

/**********************************************************************************************
************************************** 10 INTXSTAT ***********************************************
**********************************************************************************************/
#define INTC_INTXSTAT                   (((INTC_INTXSTAT_TypeDef*)(INTC_BASE+INTC_INTXSTAT_OFFSET )))
#define INTC_INTXSTAT_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_INTXSTAT_OFFSET)))

/*--------*/
#define INTC_INTXSTAT_R_DROP_MASK        ((uint32_t)0x00000001)
#define INTC_INTXSTAT_R_DROP_SHIFT         (0)

#define INTC_INTXSTAT_DROP_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define INTC_INTXSTAT_R_CPUINT_MASK        ((uint32_t)0x00FF0000)
#define INTC_INTXSTAT_R_CPUINTSHIFT         (16)

#define INTC_INTXSTAT_CPUINT_MASK          ((uint32_t)0x000000FF)
/*--------*/

/*--------*/
#define INTC_INTXSTAT_R_SYSINT_MASK        ((uint32_t)0xFF000000)
#define INTC_INTXSTAT_R_SYSINT_SHIFT       (24)

#define INTC_INTXSTAT_SYSINT_MASK          ((uint32_t)0x000000FF)
/*--------*/

/**********************************************************************************************
************************************** 11 INTXCLR ***********************************************
**********************************************************************************************/
#define INTC_INTXCLR                   (((INTC_INTXCLR_TypeDef*)(INTC_BASE+INTC_INTXCLR_OFFSET )))
#define INTC_INTXCLR_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_INTXCLR_OFFSET)))

/*--------*/
#define INTC_INTXCLR_R_CLEAR_MASK        ((uint32_t)0x00000001)
#define INTC_INTXCLR_R_CLEAR_SHIFT         (0)

#define INTC_INTXCLR_CLEAR_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 12 INTDMASK ***********************************************
**********************************************************************************************/
#define INTC_INTDMASK                   (((INTC_INTDMASK_TypeDef*)(INTC_BASE+INTC_INTDMASK_OFFSET )))
#define INTC_INTDMASK_R                  (*((__IO uint32_t *)(INTC_BASE+INTC_INTDMASK_OFFSET)))

#define INTC_INTDMASK_R_IDM(n)           (0x1 << ((n) & 15))
/*--------*/
#define INTC_INTDMASK_R_IDM4_MASK        ((uint32_t)0x00000010)
#define INTC_INTDMASK_R_IDM4_SHIFT         (4)

#define INTC_INTDMASK_IDM4_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define INTC_INTDMASK_R_IDM5_MASK        ((uint32_t)0x00000020)
#define INTC_INTDMASK_R_IDM5_SHIFT         (5)

#define INTC_INTDMASK_IDM5_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define INTC_INTDMASK_R_IDM6_MASK        ((uint32_t)0x00000040)
#define INTC_INTDMASK_R_IDM6_SHIFT         (6)

#define INTC_INTDMASK_IDM6_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define INTC_INTDMASK_R_IDM7_MASK        ((uint32_t)0x00000080)
#define INTC_INTDMASK_R_IDM7_SHIFT         (7)

#define INTC_INTDMASK_IDM7_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define INTC_INTDMASK_R_IDM8_MASK        ((uint32_t)0x00000100)
#define INTC_INTDMASK_R_IDM8_SHIFT         (8)

#define INTC_INTDMASK_IDM8_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define INTC_INTDMASK_R_IDM9_MASK        ((uint32_t)0x00000200)
#define INTC_INTDMASK_R_IDM9_SHIFT         (9)

#define INTC_INTDMASK_IDM9_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define INTC_INTDMASK_R_IDM10_MASK        ((uint32_t)0x00000400)
#define INTC_INTDMASK_R_IDM10_SHIFT         (10)

#define INTC_INTDMASK_IDM10_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define INTC_INTDMASK_R_IDM11_MASK        ((uint32_t)0x00000800)
#define INTC_INTDMASK_R_IDM11_SHIFT         (11)

#define INTC_INTDMASK_IDM11_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define INTC_INTDMASK_R_IDM12_MASK        ((uint32_t)0x00001000)
#define INTC_INTDMASK_R_IDM12_SHIFT         (12)

#define INTC_INTDMASK_IDM12_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define INTC_INTDMASK_R_IDM13_MASK        ((uint32_t)0x00002000)
#define INTC_INTDMASK_R_IDM13_SHIFT         (13)

#define INTC_INTDMASK_IDM13_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define INTC_INTDMASK_R_IDM14_MASK        ((uint32_t)0x00004000)
#define INTC_INTDMASK_R_IDM14_SHIFT         (14)

#define INTC_INTDMASK_IDM14_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define INTC_INTDMASK_R_IDM15_MASK        ((uint32_t)0x00008000)
#define INTC_INTDMASK_R_IDM15_SHIFT         (15)

#define INTC_INTDMASK_IDM15_MASK          ((uint32_t)0x00000001)
/*--------*/



#define ECM0_UNUSED -1
#define ECM1_UNUSED -1
#define ECM2_UNUSED -1
#define ECM3_UNUSED -1

#define NMI 1
#define GEE 2
#define XEN 3
#define INT_COUNT  16
#define NUM_EVENTS 128


typedef enum
{
    EVENT_enEVT0                = 0,
    EVENT_enEVT1                = 1,
    EVENT_enEVT2                = 2,
    EVENT_enEVT3                = 3,

    EVENT_enT64P0_TINT12        = 4,
    EVENT_enSYSCFG_CHIPINT2     = 5,
    EVENT_enPRU_EVTOUT0         = 6,
    EVENT_enEHRPWM0             = 7,
    EVENT_enEDMA3_0_CC0_INT1    = 8,
    EVENT_enEMU_DTDMA           = 9,
    EVENT_enEHRPWM0TZ           = 10,
    EVENT_enEMU_RTDXRX          = 11,
    EVENT_enEMU_RTDXTX          = 12,
    EVENT_enIDMAINT0            = 13,
    EVENT_enIDMAINT1            = 14,
    EVENT_enMMCSD0_INT0         = 15,
    EVENT_enMMCSD0_INT1         = 16,
    EVENT_enPRU_EVTOUT1         = 17,
    EVENT_enEHRPWM1             = 18,
    EVENT_enUSB0                = 19,
    EVENT_enUSB1_HCINT          = 20,
    EVENT_enUSB1_RWAKEUP        = 21,
    EVENT_enPRU_EVTOUT2         = 22,
    EVENT_enEHRPWM1TZ           = 23,
    EVENT_enSATA_INT            = 24,
    EVENT_enT64P2_TINTALL       = 25,
    EVENT_enEMAC_C0RXTHRESH     = 26,
    EVENT_enEMAC_C0RX           = 27,
    EVENT_enEMAC_C0TX           = 28,
    EVENT_enEMAC_C0MISC         = 29,
    EVENT_enEMAC_C1RXTHRESH     = 30,
    EVENT_enEMAC_C1RX           = 31,
    EVENT_enEMAC_C1TX           = 32,
    EVENT_enEMAC_C1MISC         = 33,
    EVENT_enUHPI_DSPINT         = 34,
    EVENT_enPRU_EVTOUT3         = 35,
    EVENT_enI2C0_INT            = 36,
    EVENT_enSPI0_INT            = 37,
    EVENT_enUART0_INT           = 38,
    EVENT_enPRU_EVTOUT5         = 39,
    EVENT_enT64P1_TINT12        = 40,
    EVENT_enGPIO_B1INT          = 41,
    EVENT_enI2C1_INT            = 42,
    EVENT_enSPI1_INT            = 43,
    EVENT_enPRU_EVTOUT6         = 44,
    EVENT_enECAP0               = 45,
    EVENT_enUART1_INT           = 46,
    EVENT_enECAP1               = 47,
    EVENT_enT64P1_TINT34        = 48,
    EVENT_enGPIO_B2INT          = 49,
    EVENT_enPRU_EVTOUT7         = 50,
    EVENT_enECAP2               = 51,
    EVENT_enGPIO_B3INT          = 52,
    EVENT_enMMCSD1_INT1         = 53,
    EVENT_enGPIO_B4INT          = 54,
    EVENT_enEMIFA_INT           = 55,
    EVENT_enEDMA3_0_CC0_ERRINT  = 56,
    EVENT_enEDMA3_0_TC0_ERRINT  = 57,
    EVENT_enEDMA3_0_TC1_ERRINT  = 58,
    EVENT_enGPIO_B5INT          = 59,
    EVENT_enDDR2_MEMERR         = 60,
    EVENT_enMCASP0_INT          = 61,
    EVENT_enGPIO_B6INT          = 62,
    EVENT_enRTC_IRQS            = 63,
    EVENT_enT64P0_TINT34        = 64,
    EVENT_enGPIO_B0INT          = 65,
    EVENT_enPRU_EVTOUT4         = 66,
    EVENT_enSYSCFG_CHIPINT3     = 67,
    EVENT_enMMCSD1_INT0         = 68,
    EVENT_enUART2_INT           = 69,
    EVENT_enPSC0_ALLINT         = 70,
    EVENT_enPSC1_ALLINT         = 71,
    EVENT_enGPIO_B7INT          = 72,
    EVENT_enLCDC_INT            = 73,
    EVENT_enPROTERR             = 74,
    EVENT_enGPIO_B8INT          = 75,
    EVENT_enRESERVED0           = 76,
    EVENT_enRESERVED1           = 77,
    EVENT_enT64P2_CMPINT0       = 78,
    EVENT_enT64P2_CMPINT1       = 79,
    EVENT_enT64P2_CMPINT2       = 80,
    EVENT_enT64P2_CMPINT3       = 81,
    EVENT_enT64P2_CMPINT4       = 82,
    EVENT_enT64P2_CMPINT5       = 83,
    EVENT_enT64P2_CMPINT6       = 84,
    EVENT_enT64P2_CMPINT7       = 85,
    EVENT_enT64P3_TINTALL       = 86,
    EVENT_enMCBSP0_RINT         = 87,
    EVENT_enMCBSP0_XINT         = 88,
    EVENT_enMCBSP1_RINT         = 89,
    EVENT_enMCBSP1_XINT         = 90,
    EVENT_enEDMA3_1_CC0_INT1    = 91,
    EVENT_enEDMA3_1_CC0_ERRINT  = 92,
    EVENT_enEDMA3_1_TC0_ERRINT  = 93,
    EVENT_enUPP_INT             = 94,
    EVENT_enVPIF_INT            = 95,
    EVENT_enINTERR              = 96,
    EVENT_enEMC_IDMAERR         = 97,
    EVENT_enRESERVED2           = 98,
    EVENT_enRESERVED3           = 99,
    EVENT_enRESERVED4           = 100,
    EVENT_enRESERVED5           = 101,
    EVENT_enRESERVED6           = 102,
    EVENT_enRESERVED7           = 103,
    EVENT_enRESERVED8           = 104,
    EVENT_enRESERVED9           = 105,
    EVENT_enRESERVED10          = 106,
    EVENT_enRESERVED11          = 107,
    EVENT_enRESERVED12          = 108,
    EVENT_enRESERVED13          = 109,
    EVENT_enRESERVED14          = 110,
    EVENT_enRESERVED15          = 111,
    EVENT_enRESERVED16          = 112,
    EVENT_enPMC_ED              = 113,
    EVENT_enRESERVED17          = 114,
    EVENT_enRESERVED18          = 115,
    EVENT_enUMC_ED1             = 116,
    EVENT_enUMC_ED2             = 117,
    EVENT_enPDC_INT             = 118,
    EVENT_enSYS_CMPA            = 119,
    EVENT_enPMC_CMPA            = 120,
    EVENT_enPMC_DMPA            = 121,
    EVENT_enDMC_CMPA            = 122,
    EVENT_enDMC_DMPA            = 123,
    EVENT_enUMC_CMPA            = 124,
    EVENT_enUMC_DMPA            = 125,
    EVENT_enEMC_CMPA            = 126,
    EVENT_enEMC_BUSERR          = 127,
    EVENT_enUnused              = 0xFFFF,
}Intc_nEvent;



typedef enum
{
    MASK_enNMI      =1,
    MASK_enEXC      =1,
    MASK_enRSV2     =2,
    MASK_enRSV3     =3,
    MASK_enINT4     =4,
    MASK_enINT5     =5,
    MASK_enINT6     =6,
    MASK_enINT7     =7,
    MASK_enINT8     =8,
    MASK_enINT9     =9,
    MASK_enINT10    =10,
    MASK_enINT11    =11,
    MASK_enINT12    =12,
    MASK_enINT13    =13,
    MASK_enINT14    =14,
    MASK_enINT15    =15,
    MASK_enUNUSED    =0xFF,
}Intc_nMask;


typedef enum
{
    INTC_enOK      =0,
    INTC_enERROR      =1,
}Intc_nStatus;

typedef void (*ISRRoutine)(void);



#pragma FUNC_ALWAYS_INLINE( INTC__vVectorTable)
#pragma FUNC_ALWAYS_INLINE( INTC__vDspInit)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuIntRegisterRoutine)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuIntUnRegisterRoutine)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuNmiEnable)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuIntEnable)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuNmiDisable)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuIntDisable)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuIntReset)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventMap2CpuInt)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventSet)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventClear)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventCombineAdd)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventCombineRemove)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventCombineRegisterRoutine)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventCombineInit)
#pragma FUNC_ALWAYS_INLINE( INTC__vExceptionGlobalEnable)
#pragma FUNC_ALWAYS_INLINE( INTC__enExceptionCombineAdd)
#pragma FUNC_ALWAYS_INLINE( INTC__ExceptionCombineRemove)

void INTC__vVectorTable (void);
void INTC__vDspInit (void);
Intc_nStatus INTC__enCpuIntRegisterRoutine (Intc_nMask enCpuInt, void (*userISR)(void));
Intc_nStatus INTC__enCpuIntUnRegisterRoutine (Intc_nMask enCpuInts);
Intc_nStatus INTC__enCpuNmiEnable (Intc_nMask enCpuInt);
Intc_nStatus INTC__enCpuIntEnable (Intc_nMask enCpuInt);
Intc_nStatus INTC__enCpuNmiDisable (Intc_nMask enCpuInt);
Intc_nStatus INTC__enCpuIntDisable (Intc_nMask enCpuInt);
void INTC__enCpuIntReset (void);

Intc_nStatus INTC__enEventMap2CpuInt (Intc_nMask enCpuInt, Intc_nEvent enSysInt);
Intc_nStatus INTC__enEventSet (Intc_nEvent enSysInt);
Intc_nStatus INTC__enEventClear (Intc_nEvent enSysInt);
Intc_nStatus INTC__enEventCombineAdd(Intc_nEvent enSysInt);
Intc_nStatus INTC__enEventCombineRemove(Intc_nEvent enSysInt);
Intc_nStatus INTC__enEventCombineRegisterRoutine(Intc_nEvent enSysInt, void (*userISR)(void));
Intc_nStatus INTC__enEventCombineInit(Intc_nMask enEcmInt0, Intc_nMask enEcmInt1, Intc_nMask enEcmInt2, Intc_nMask enEcmInt3);


#define INTC__vIntGlobalEnable()     _enable_interrupts()
#define INTC__vIntGlobalDisable()  _disable_interrupts()
#define INTC__vIntGlobalRestore(restoreValue) _restore_interrupts(restoreValue)

void INTC__vExceptionGlobalEnable (void);
Intc_nStatus INTC__enExceptionCombineAdd(Intc_nEvent enSysInt);
Intc_nStatus INTC__ExceptionCombineRemove(Intc_nEvent enSysInt);

#endif /* INCLUDE_INTC_H_ */
