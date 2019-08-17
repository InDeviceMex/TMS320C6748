/*
 * PLLC.h
 *
 *  Created on: 18/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_PLLC_H_
#define INCLUDE_PLLC_H_

#include "Core.h"
#include "SYSCFG.h"
#include <stdint.h>

#define PLLC0_BASE            ((uint32_t)0x01C11000)
#define PLLC1_BASE            ((uint32_t)0x01E1A000)


typedef __IO struct
{
    __I uint32_t REV       :32;
}PLLC_REVID_TypeDef;

typedef __IO struct
{
    __IO uint32_t POR       :1;
    __IO uint32_t XWRST     :1;
    __IO uint32_t PLLSWRST  :1;
         uint32_t reserved0 :29;
}PLLC_RSTYPE_TypeDef;

typedef __IO struct
{
    __IO uint32_t KEY       :16;
    __IO uint32_t SWRST     :1;
         uint32_t reserved0 :15;
}PLLC_RSCTRL_TypeDef;

typedef __IO struct
{
    __IO uint32_t PLLEN       :1;
    __IO uint32_t PLLPWRDN    :1;
         uint32_t reserved0   :1;
    __IO uint32_t PLLRST      :1;
         uint32_t reserved1   :1;
    __IO uint32_t PLLENSRC    :1;
         uint32_t reserved2   :2;
    __IO uint32_t CLKMODE     :1;
    __IO uint32_t EXTCLKSRC   :1;
         uint32_t reserved3   :22;
}PLLC0_PLLCTL_TypeDef;

typedef __IO struct
{
    __IO uint32_t PLLEN       :1;
    __IO uint32_t PLLPWRDN    :1;
         uint32_t reserved0   :1;
    __IO uint32_t PLLRST      :1;
         uint32_t reserved1   :1;
    __IO uint32_t PLLENSRC    :1;
         uint32_t reserved2   :26;
}PLLC1_PLLCTL_TypeDef;

typedef __IO struct
{
    __IO uint32_t OCSRC       :5;
         uint32_t reserved0   :27;
}PLLC_OCSEL_TypeDef;

typedef __IO struct
{
    __IO uint32_t PLLM        :5;
         uint32_t reserved0   :27;
}PLLC_PLLM_TypeDef;

typedef __IO struct
{
    __IO uint32_t RATIO        :5;
         uint32_t reserved0    :10;
    __IO uint32_t PREDEN       :1;
         uint32_t reserved1    :16;
}PLLC_PREDIV_TypeDef;

typedef __IO struct
{
    __IO uint32_t RATIO        :5;
         uint32_t reserved0    :10;
    __IO uint32_t D1EN         :1;
         uint32_t reserved1    :16;
}PLLC_PLLDIV1_TypeDef;

typedef __IO struct
{
    __IO uint32_t RATIO        :5;
         uint32_t reserved0    :10;
    __IO uint32_t D2EN         :1;
         uint32_t reserved1    :16;
}PLLC_PLLDIV2_TypeDef;

typedef __IO struct
{
    __IO uint32_t RATIO        :5;
         uint32_t reserved0    :10;
    __IO uint32_t D3EN         :1;
         uint32_t reserved1    :16;
}PLLC_PLLDIV3_TypeDef;

typedef __IO struct
{
    __IO uint32_t RATIO        :5;
         uint32_t reserved0    :10;
    __IO uint32_t D4EN         :1;
         uint32_t reserved1    :16;
}PLLC_PLLDIV4_TypeDef;

typedef __IO struct
{
    __IO uint32_t RATIO        :5;
         uint32_t reserved0    :10;
    __IO uint32_t D5EN         :1;
         uint32_t reserved1    :16;
}PLLC_PLLDIV5_TypeDef;

typedef __IO struct
{
    __IO uint32_t RATIO        :5;
         uint32_t reserved0    :10;
    __IO uint32_t D6EN         :1;
         uint32_t reserved1    :16;
}PLLC_PLLDIV6_TypeDef;

typedef __IO struct
{
    __IO uint32_t RATIO        :5;
         uint32_t reserved0    :10;
    __IO uint32_t D7EN         :1;
         uint32_t reserved1    :16;
}PLLC_PLLDIV7_TypeDef;

typedef __IO struct
{
    __IO uint32_t RATIO        :5;
         uint32_t reserved0    :10;
    __IO uint32_t OD1EN        :1;
         uint32_t reserved1    :16;
}PLLC_OSCDIV_TypeDef;

typedef __IO struct
{
    __IO uint32_t RATIO        :5;
         uint32_t reserved0    :10;
    __IO uint32_t POSTDEN      :1;
         uint32_t reserved1    :16;
}PLLC_POSTDIV_TypeDef;

typedef __IO struct
{
    __IO uint32_t GOSET        :1;
         uint32_t reserved0    :31;
}PLLC_PLLCMD_TypeDef;

typedef __IO struct
{
    __IO uint32_t GOSTAT        :1;
         uint32_t reserved0    :1;
    __IO uint32_t STABLE        :1;
         uint32_t reserved1   :29;
}PLLC_PLLSTAT_TypeDef;

typedef __IO struct
{
    __IO uint32_t ALN1        :1;
    __IO uint32_t ALN2        :1;
    __IO uint32_t ALN3        :1;
    __IO uint32_t ALN4        :1;
    __IO uint32_t ALN5        :1;
    __IO uint32_t ALN6        :1;
    __IO uint32_t ALN7        :1;
         uint32_t reserved0   :25;
}PLLC0_ALNCTL_TypeDef;

typedef __IO struct
{
    __IO uint32_t ALN1        :1;
    __IO uint32_t ALN2        :1;
    __IO uint32_t ALN3        :1;
         uint32_t reserved0   :29;
}PLLC1_ALNCTL_TypeDef;

typedef __IO struct
{
    __IO uint32_t SYS1        :1;
    __IO uint32_t SYS2        :1;
    __IO uint32_t SYS3        :1;
    __IO uint32_t SYS4        :1;
    __IO uint32_t SYS5        :1;
    __IO uint32_t SYS6        :1;
    __IO uint32_t SYS7        :1;
         uint32_t reserved0   :25;
}PLLC0_DCHANGE_TypeDef;

typedef __IO struct
{
    __IO uint32_t SYS1        :1;
    __IO uint32_t SYS2        :1;
    __IO uint32_t SYS3        :1;
         uint32_t reserved0   :29;
}PLLC1_DCHANGE_TypeDef;

typedef __IO struct
{
    __IO uint32_t AUXEN        :1;
    __IO uint32_t OBSEN        :1;
         uint32_t reserved0   :30;
}PLLC0_CKEN_TypeDef;

typedef __IO struct
{
         uint32_t reserved0    :1;
    __IO uint32_t OBSEN        :1;
         uint32_t reserved1   :30;
}PLLC1_CKEN_TypeDef;

typedef __IO struct
{
    __IO uint32_t AUXEN        :1;
    __IO uint32_t OBSEN        :1;
         uint32_t reserved0   :30;
}PLLC0_CKSTAT_TypeDef;

typedef __IO struct
{
         uint32_t reserved0    :1;
    __IO uint32_t OBSEN        :1;
         uint32_t reserved1   :30;
}PLLC1_CKSTAT_TypeDef;

typedef __IO struct
{
    __IO uint32_t SYS1ON        :1;
    __IO uint32_t SYS2ON        :1;
    __IO uint32_t SYS3ON        :1;
    __IO uint32_t SYS4ON        :1;
    __IO uint32_t SYS5ON        :1;
    __IO uint32_t SYS6ON        :1;
    __IO uint32_t SYS7ON        :1;
         uint32_t reserved0   :25;
}PLLC0_SYSTAT_TypeDef;

typedef __IO struct
{
    __IO uint32_t SYS1ON        :1;
    __IO uint32_t SYS2ON        :1;
    __IO uint32_t SYS3ON        :1;
         uint32_t reserved0   :29;
}PLLC1_SYSTAT_TypeDef;

typedef __IO struct
{
    __IO uint32_t COUNT        :32;
}PLLC_EMUCNT0_TypeDef;

typedef __IO struct
{
    __IO uint32_t COUNT        :32;
}PLLC_EMUCNT1_TypeDef;





typedef struct  {
    union
    {
        __IO uint32_t       REVID;
        PLLC_REVID_TypeDef  REVID_Bit;
    };
    uint32_t reserved0[56];
    union
    {
        __IO uint32_t        RSTYPE;
        PLLC_RSTYPE_TypeDef  RSTYPE_Bit;
    };
    union
    {
        __IO uint32_t        RSCTRL;
        PLLC_RSCTRL_TypeDef  RSCTRL_Bit;
    };
    uint32_t reserved1[5];
    union
    {
        __IO uint32_t         PLLCTL;
        PLLC0_PLLCTL_TypeDef  PLLCTL_Bit;
    };
    union
    {
        __IO uint32_t         OCSEL;
        PLLC_OCSEL_TypeDef    OCSEL_Bit;
    };
    uint32_t reserved2[2];
    union
    {
        __IO uint32_t         PLLM;
        PLLC_PLLM_TypeDef     PLLM_Bit;
    };
    union
    {
        __IO uint32_t         PREDIV;
        PLLC_PREDIV_TypeDef   PREDIV_Bit;
    };
    union
    {
        __IO uint32_t          PLLDIV1;
        PLLC_PLLDIV1_TypeDef   PLLDIV1_Bit;
    };
    union
    {
        __IO uint32_t          PLLDIV2;
        PLLC_PLLDIV2_TypeDef   PLLDIV2_Bit;
    };
    union
    {
        __IO uint32_t          PLLDIV3;
        PLLC_PLLDIV3_TypeDef   PLLDIV3_Bit;
    };
    union
    {
        __IO uint32_t         OSCDIV;
        PLLC_OSCDIV_TypeDef   OSCDIV_Bit;
    };
    union
    {
        __IO uint32_t         POSTDIV;
        PLLC_POSTDIV_TypeDef   POSTDIV_Bit;
    };
    uint32_t reserved3[3];
    union
    {
        __IO uint32_t         PLLCMD;
        PLLC_PLLCMD_TypeDef   PLLCMD_Bit;
    };
    union
    {
        __IO uint32_t         PLLSTAT;
        PLLC_PLLSTAT_TypeDef  PLLSTAT_Bit;
    };
    union
    {
        __IO uint32_t         ALNCTL;
        PLLC0_ALNCTL_TypeDef  ALNCTL_Bit;
    };
    union
    {
        __IO uint32_t         DCHANGE;
        PLLC0_DCHANGE_TypeDef  DCHANGE_Bit;
    };
    union
    {
        __IO uint32_t         CKEN;
        PLLC0_CKEN_TypeDef     CKEN_Bit;
    };
    union
    {
        __IO uint32_t         CKSTAT;
        PLLC0_CKSTAT_TypeDef   CKSTAT_Bit;
    };
    union
    {
        __IO uint32_t         SYSTAT;
        PLLC0_SYSTAT_TypeDef   SYSTAT_Bit;
    };
    uint32_t reserved4[3];
    union
    {
        __IO uint32_t         PLLDIV4;
        PLLC_PLLDIV4_TypeDef  PLLDIV4_Bit;
    };
    union
    {
        __IO uint32_t         PLLDIV5;
        PLLC_PLLDIV5_TypeDef  PLLDIV5_Bit;
    };
    union
    {
        __IO uint32_t         PLLDIV6;
        PLLC_PLLDIV6_TypeDef  PLLDIV6_Bit;
    };
    union
    {
        __IO uint32_t         PLLDIV7;
        PLLC_PLLDIV7_TypeDef  PLLDIV7_Bit;
    };
    uint32_t reserved5[32];
    union
    {
        __IO uint32_t         EMUCNT0;
        PLLC_EMUCNT0_TypeDef  EMUCNT0_Bit;
    };
    union
    {
        __IO uint32_t         EMUCNT1;
        PLLC_EMUCNT1_TypeDef  EMUCNT1_Bit;
    };
} PLLC0_TypeDef;



typedef struct  {
    union
    {
        __IO uint32_t       REVID;
        PLLC_REVID_TypeDef  REVID_Bit;
    };
    uint32_t reserved0[63];
    union
    {
        __IO uint32_t         PLLCTL;
        PLLC1_PLLCTL_TypeDef  PLLCTL_Bit;
    };
    union
    {
        __IO uint32_t         OCSEL;
        PLLC_OCSEL_TypeDef    OCSEL_Bit;
    };
    uint32_t reserved1[2];
    union
    {
        __IO uint32_t         PLLM;
        PLLC_PLLM_TypeDef     PLLM_Bit;
    };
    uint32_t reserved2[1];
    union
    {
        __IO uint32_t          PLLDIV1;
        PLLC_PLLDIV1_TypeDef   PLLDIV1_Bit;
    };
    union
    {
        __IO uint32_t          PLLDIV2;
        PLLC_PLLDIV2_TypeDef   PLLDIV2_Bit;
    };
    union
    {
        __IO uint32_t          PLLDIV3;
        PLLC_PLLDIV3_TypeDef   PLLDIV3_Bit;
    };
    union
    {
        __IO uint32_t         OSCDIV;
        PLLC_OSCDIV_TypeDef   OSCDIV_Bit;
    };
    union
    {
        __IO uint32_t         POSTDIV;
        PLLC_POSTDIV_TypeDef   POSTDIV_Bit;
    };
    uint32_t reserved3[3];
    union
    {
        __IO uint32_t         PLLCMD;
        PLLC_PLLCMD_TypeDef   PLLCMD_Bit;
    };
    union
    {
        __IO uint32_t         PLLSTAT;
        PLLC_PLLSTAT_TypeDef  PLLSTAT_Bit;
    };
    union
    {
        __IO uint32_t         ALNCTL;
        PLLC1_ALNCTL_TypeDef  ALNCTL_Bit;
    };
    union
    {
        __IO uint32_t         DCHANGE;
        PLLC1_DCHANGE_TypeDef  DCHANGE_Bit;
    };
    union
    {
        __IO uint32_t         CKEN;
        PLLC1_CKEN_TypeDef     CKEN_Bit;
    };
    union
    {
        __IO uint32_t         CKSTAT;
        PLLC1_CKSTAT_TypeDef   CKSTAT_Bit;
    };
    union
    {
        __IO uint32_t         SYSTAT;
        PLLC1_SYSTAT_TypeDef   SYSTAT_Bit;
    };
    uint32_t reserved4[39];
    union
    {
        __IO uint32_t         EMUCNT0;
        PLLC_EMUCNT0_TypeDef  EMUCNT0_Bit;
    };
    union
    {
        __IO uint32_t         EMUCNT1;
        PLLC_EMUCNT1_TypeDef  EMUCNT1_Bit;
    };
} PLLC1_TypeDef;




#define PLLC0            (((PLLC0_TypeDef*)(PLLC0_BASE)))
#define PLLC0_R(offset)  (*((__IO uint32_t *)(PLLC0_BASE+offset)))
#define PLLC1            (((PLLC1_TypeDef*)(PLLC1_BASE)))
#define PLLC1_R(offset)  (*((__IO uint32_t *)(PLLC1_BASE+offset)))



#define PLLC_REVID_OFFSET       ((uint32_t)0x0000)
#define PLLC_RSTYPE_OFFSET      ((uint32_t)0x00E4)
#define PLLC_RSCTRL_OFFSET      ((uint32_t)0x00E8)
#define PLLC_PLLCTL_OFFSET      ((uint32_t)0x0100)
#define PLLC_OCSEL_OFFSET       ((uint32_t)0x0104)
#define PLLC_PLLM_OFFSET        ((uint32_t)0x0110)
#define PLLC_PREDIV_OFFSET      ((uint32_t)0x0114)
#define PLLC_PLLDIV1_OFFSET     ((uint32_t)0x0118)
#define PLLC_PLLDIV2_OFFSET     ((uint32_t)0x011C)
#define PLLC_PLLDIV3_OFFSET     ((uint32_t)0x0120)
#define PLLC_OSCDIV_OFFSET      ((uint32_t)0x0124)
#define PLLC_POSTDIV_OFFSET     ((uint32_t)0x0128)
#define PLLC_PLLCMD_OFFSET      ((uint32_t)0x0138)
#define PLLC_PLLSTAT_OFFSET     ((uint32_t)0x013C)
#define PLLC_ALNCTL_OFFSET      ((uint32_t)0x0140)
#define PLLC_DCHANGE_OFFSET     ((uint32_t)0x0144)
#define PLLC_CKEN_OFFSET        ((uint32_t)0x0148)
#define PLLC_CKSTAT_OFFSET      ((uint32_t)0x014C)
#define PLLC_SYSTAT_OFFSET      ((uint32_t)0x0150)
#define PLLC_PLLDIV4_OFFSET     ((uint32_t)0x0160)
#define PLLC_PLLDIV5_OFFSET     ((uint32_t)0x0164)
#define PLLC_PLLDIV6_OFFSET     ((uint32_t)0x0168)
#define PLLC_PLLDIV7_OFFSET     ((uint32_t)0x016C)
#define PLLC_EMUCNT0_OFFSET     ((uint32_t)0x01F0)
#define PLLC_EMUCNT1_OFFSET     ((uint32_t)0x01F4)


/**********************************************************************************************
************************************** 1 REVID ***********************************************
**********************************************************************************************/
#define PLLC0_REVID                    (((PLLC_REVID_TypeDef*)(PLLC0_BASE+PLLC_REVID_OFFSET )))
#define PLLC0_REVID_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_REVID_OFFSET)))
#define PLLC1_REVID                    (((PLLC_REVID_TypeDef*)(PLLC1_BASE+PLLC_REVID_OFFSET )))
#define PLLC1_REVID_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_REVID_OFFSET)))

/*--------*/
#define PLLC_REVID_R_REV_MASK        ((uint32_t)0xFFFFFFFF)
#define PLLC_REVID_R_REV_SHIFT         (0)

#define PLLC_REVID_REV_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 2 RSTYPE ***********************************************
**********************************************************************************************/
#define PLLC0_RSTYPE                    (((PLLC_RSTYPE_TypeDef*)(PLLC0_BASE+PLLC_RSTYPE_OFFSET )))
#define PLLC0_RSTYPE_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_RSTYPE_OFFSET)))

/*--------*/
#define PLLC_RSTYPE_R_POR_MASK        ((uint32_t)0x00000001)
#define PLLC_RSTYPE_R_POR_SHIFT         (0)

#define PLLC_RSTYPE_POR_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define PLLC_RSTYPE_R_XWRST_MASK        ((uint32_t)0x00000002)
#define PLLC_RSTYPE_R_XWRST_SHIFT         (1)

#define PLLC_RSTYPE_XWRST_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define PLLC_RSTYPE_R_PLLSWRST_MASK        ((uint32_t)0x00000004)
#define PLLC_RSTYPE_R_PLLSWRST_SHIFT         (2)

#define PLLC_RSTYPE_PLLSWRST_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 3 RSCTRL ***********************************************
**********************************************************************************************/
#define PLLC0_RSCTRL                    (((PLLC_RSCTRL_TypeDef*)(PLLC0_BASE+PLLC_RSCTRL_OFFSET )))
#define PLLC0_RSCTRL_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_RSCTRL_OFFSET)))

/*--------*/
#define PLLC_RSCTRL_R_KEY_MASK        ((uint32_t)0x0000FFFF)
#define PLLC_RSCTRL_R_KEY_SHIFT         (0)

#define PLLC_RSCTRL_KEY_MASK          ((uint32_t)0x0000FFFF)
/*--------*/
/*--------*/
#define PLLC_RSCTRL_R_SWRST_MASK        ((uint32_t)0x00010000)
#define PLLC_RSCTRL_R_SWRST_SHIFT         (16)

#define PLLC_RSCTRL_SWRST_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 4 PLLCTL ***********************************************
**********************************************************************************************/
#define PLLC0_PLLCTL                    (((PLLC0_PLLCTL_TypeDef*)(PLLC0_BASE+PLLC_PLLCTL_OFFSET )))
#define PLLC0_PLLCTL_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_PLLCTL_OFFSET)))
#define PLLC1_PLLCTL                    (((PLLC1_PLLCTL_TypeDef*)(PLLC1_BASE+PLLC_PLLCTL_OFFSET )))
#define PLLC1_PLLCTL_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_PLLCTL_OFFSET)))

/*--------*/
#define PLLC_PLLCTL_R_PLLEN_MASK        ((uint32_t)0x00000001)
#define PLLC_PLLCTL_R_PLLEN_SHIFT         (0)

#define PLLC_PLLCTL_PLLEN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC_PLLCTL_R_PLLPWRDN_MASK        ((uint32_t)0x00000002)
#define PLLC_PLLCTL_R_PLLPWRDN_SHIFT         (1)

#define PLLC_PLLCTL_PLLPWRDN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC_PLLCTL_R_PLLRST_MASK        ((uint32_t)0x00000008)
#define PLLC_PLLCTL_R_PLLRST_SHIFT         (3)

#define PLLC_PLLCTL_PLLRST_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC_PLLCTL_R_PLLENSRC_MASK        ((uint32_t)0x00000020)
#define PLLC_PLLCTL_R_PLLENSRC_SHIFT         (5)

#define PLLC_PLLCTL_PLLENSRC_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_PLLCTL_R_CLKMODE_MASK        ((uint32_t)0x00000100)
#define PLLC0_PLLCTL_R_CLKMODE_SHIFT         (8)

#define PLLC0_PLLCTL_CLKMODE_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_PLLCTL_R_EXTCLKSRC_MASK        ((uint32_t)0x00000200)
#define PLLC0_PLLCTL_R_EXTCLKSRC_SHIFT         (9)

#define PLLC0_PLLCTL_EXTCLKSRC_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 5 OCSEL ***********************************************
**********************************************************************************************/
#define PLLC0_OCSEL                    (((PLLC_OCSEL_TypeDef*)(PLLC0_BASE+PLLC_OCSEL_OFFSET )))
#define PLLC0_OCSEL_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_OCSEL_OFFSET)))
#define PLLC1_OCSEL                    (((PLLC_OCSEL_TypeDef*)(PLLC1_BASE+PLLC_OCSEL_OFFSET )))
#define PLLC1_OCSEL_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_OCSEL_OFFSET)))

/*--------*/
#define PLLC_OCSEL_R_OCSRC_MASK        ((uint32_t)0x0000001F)
#define PLLC_OCSEL_R_OCSRC_SHIFT         (0)

#define PLLC_OCSEL_OCSRC_MASK          ((uint32_t)0x0000001F)
/*--------*/


/**********************************************************************************************
************************************** 6 PLLM ***********************************************
**********************************************************************************************/
#define PLLC0_PLLM                    (((PLLC_PLLM_TypeDef*)(PLLC0_BASE+PLLC_PLLM_OFFSET )))
#define PLLC0_PLLM_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_PLLM_OFFSET)))
#define PLLC1_PLLM                    (((PLLC_PLLM_TypeDef*)(PLLC1_BASE+PLLC_PLLM_OFFSET )))
#define PLLC1_PLLM_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_PLLM_OFFSET)))

/*--------*/
#define PLLC_PLLM_R_PLLM_MASK        ((uint32_t)0x0000001F)
#define PLLC_PLLM_R_PLLM_SHIFT         (0)

#define PLLC_PLLM_PLLM_MASK          ((uint32_t)0x0000001F)
/*--------*/


/**********************************************************************************************
************************************** 7 PREDIV ***********************************************
**********************************************************************************************/
#define PLLC0_PREDIV                    (((PLLC_PREDIV_TypeDef*)(PLLC0_BASE+PLLC_PREDIV_OFFSET )))
#define PLLC0_PREDIV_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_PREDIV_OFFSET)))

/*--------*/
#define PLLC_PREDIV_R_RATIO_MASK        ((uint32_t)0x0000001F)
#define PLLC_PREDIV_R_RATIO_SHIFT         (0)

#define PLLC_PREDIV_RATIO_MASK          ((uint32_t)0x0000001F)
/*--------*/

/*--------*/
#define PLLC_PREDIV_R_PREDEN_MASK        ((uint32_t)0x00008000)
#define PLLC_PREDIV_R_PREDEN_SHIFT         (15)

#define PLLC_PREDIV_PREDEN_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 8 PLLDIV1 ***********************************************
**********************************************************************************************/
#define PLLC0_PLLDIV1                    (((PLLC_PLLDIV1_TypeDef*)(PLLC0_BASE+PLLC_PLLDIV1_OFFSET )))
#define PLLC0_PLLDIV1_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_PLLDIV1_OFFSET)))
#define PLLC1_PLLDIV1                    (((PLLC_PLLDIV1_TypeDef*)(PLLC1_BASE+PLLC_PLLDIV1_OFFSET )))
#define PLLC1_PLLDIV1_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_PLLDIV1_OFFSET)))

/*--------*/
#define PLLC_PLLDIV1_R_RATIO_MASK        ((uint32_t)0x0000001F)
#define PLLC_PLLDIV1_R_RATIO_SHIFT         (0)

#define PLLC_PLLDIV1_RATIO_MASK          ((uint32_t)0x0000001F)
/*--------*/

/*--------*/
#define PLLC_PLLDIV1_R_D1EN_MASK        ((uint32_t)0x00008000)
#define PLLC_PLLDIV1_R_D1EN_SHIFT         (15)

#define PLLC_PLLDIV1_D1EN_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 9 PLLDIV2 ***********************************************
**********************************************************************************************/
#define PLLC0_PLLDIV2                    (((PLLC_PLLDIV2_TypeDef*)(PLLC0_BASE+PLLC_PLLDIV2_OFFSET )))
#define PLLC0_PLLDIV2_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_PLLDIV2_OFFSET)))
#define PLLC1_PLLDIV2                    (((PLLC_PLLDIV2_TypeDef*)(PLLC1_BASE+PLLC_PLLDIV2_OFFSET )))
#define PLLC1_PLLDIV2_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_PLLDIV2_OFFSET)))

/*--------*/
#define PLLC_PLLDIV2_R_RATIO_MASK        ((uint32_t)0x0000001F)
#define PLLC_PLLDIV2_R_RATIO_SHIFT         (0)

#define PLLC_PLLDIV2_RATIO_MASK          ((uint32_t)0x0000001F)
/*--------*/

/*--------*/
#define PLLC_PLLDIV2_R_D2EN_MASK        ((uint32_t)0x00008000)
#define PLLC_PLLDIV2_R_D2EN_SHIFT         (15)

#define PLLC_PLLDIV2_D2EN_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 10 PLLDIV3 ***********************************************
**********************************************************************************************/
#define PLLC0_PLLDIV3                    (((PLLC_PLLDIV3_TypeDef*)(PLLC0_BASE+PLLC_PLLDIV3_OFFSET )))
#define PLLC0_PLLDIV3_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_PLLDIV3_OFFSET)))
#define PLLC1_PLLDIV3                    (((PLLC_PLLDIV3_TypeDef*)(PLLC1_BASE+PLLC_PLLDIV3_OFFSET )))
#define PLLC1_PLLDIV3_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_PLLDIV3_OFFSET)))

/*--------*/
#define PLLC_PLLDIV3_R_RATIO_MASK        ((uint32_t)0x0000001F)
#define PLLC_PLLDIV3_R_RATIO_SHIFT         (0)

#define PLLC_PLLDIV3_RATIO_MASK          ((uint32_t)0x0000001F)
/*--------*/

/*--------*/
#define PLLC_PLLDIV3_R_D3EN_MASK        ((uint32_t)0x00008000)
#define PLLC_PLLDIV3_R_D3EN_SHIFT         (15)

#define PLLC_PLLDIV3_D3EN_MASK          ((uint32_t)0x00000001)
/*--------*/




/**********************************************************************************************
************************************** 11 PLLDIV4 ***********************************************
**********************************************************************************************/
#define PLLC0_PLLDIV4                    (((PLLC_PLLDIV4_TypeDef*)(PLLC0_BASE+PLLC_PLLDIV4_OFFSET )))
#define PLLC0_PLLDIV4_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_PLLDIV4_OFFSET)))

/*--------*/
#define PLLC_PLLDIV4_R_RATIO_MASK        ((uint32_t)0x0000001F)
#define PLLC_PLLDIV4_R_RATIO_SHIFT         (0)

#define PLLC_PLLDIV4_RATIO_MASK          ((uint32_t)0x0000001F)
/*--------*/

/*--------*/
#define PLLC_PLLDIV4_R_D4EN_MASK        ((uint32_t)0x00008000)
#define PLLC_PLLDIV4_R_D4EN_SHIFT         (15)

#define PLLC_PLLDIV4_D4EN_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 12 PLLDIV5 ***********************************************
**********************************************************************************************/
#define PLLC0_PLLDIV5                    (((PLLC_PLLDIV5_TypeDef*)(PLLC0_BASE+PLLC_PLLDIV5_OFFSET )))
#define PLLC0_PLLDIV5_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_PLLDIV5_OFFSET)))

/*--------*/
#define PLLC_PLLDIV5_R_RATIO_MASK        ((uint32_t)0x0000001F)
#define PLLC_PLLDIV5_R_RATIO_SHIFT         (0)

#define PLLC_PLLDIV5_RATIO_MASK          ((uint32_t)0x0000001F)
/*--------*/

/*--------*/
#define PLLC_PLLDIV5_R_D5EN_MASK        ((uint32_t)0x00008000)
#define PLLC_PLLDIV5_R_D5EN_SHIFT         (15)

#define PLLC_PLLDIV5_D5EN_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 13 PLLDIV6 ***********************************************
**********************************************************************************************/
#define PLLC0_PLLDIV6                    (((PLLC_PLLDIV6_TypeDef*)(PLLC0_BASE+PLLC_PLLDIV6_OFFSET )))
#define PLLC0_PLLDIV6_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_PLLDIV6_OFFSET)))

/*--------*/
#define PLLC_PLLDIV6_R_RATIO_MASK        ((uint32_t)0x0000001F)
#define PLLC_PLLDIV6_R_RATIO_SHIFT         (0)

#define PLLC_PLLDIV6_RATIO_MASK          ((uint32_t)0x0000001F)
/*--------*/

/*--------*/
#define PLLC_PLLDIV6_R_D6EN_MASK        ((uint32_t)0x00008000)
#define PLLC_PLLDIV6_R_D6EN_SHIFT         (15)

#define PLLC_PLLDIV6_D6EN_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 14 PLLDIV7 ***********************************************
**********************************************************************************************/
#define PLLC0_PLLDIV7                    (((PLLC_PLLDIV7_TypeDef*)(PLLC0_BASE+PLLC_PLLDIV7_OFFSET )))
#define PLLC0_PLLDIV7_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_PLLDIV7_OFFSET)))

/*--------*/
#define PLLC_PLLDIV7_R_RATIO_MASK        ((uint32_t)0x0000001F)
#define PLLC_PLLDIV7_R_RATIO_SHIFT         (0)

#define PLLC_PLLDIV7_RATIO_MASK          ((uint32_t)0x0000001F)
/*--------*/

/*--------*/
#define PLLC_PLLDIV7_R_D7EN_MASK        ((uint32_t)0x00008000)
#define PLLC_PLLDIV7_R_D7EN_SHIFT         (15)

#define PLLC_PLLDIV7_D7EN_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 15 OSCDIV ***********************************************
**********************************************************************************************/
#define PLLC0_OSCDIV                    (((PLLC_OSCDIV_TypeDef*)(PLLC0_BASE+PLLC_OSCDIV_OFFSET )))
#define PLLC0_OSCDIV_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_OSCDIV_OFFSET)))
#define PLLC1_OSCDIV                    (((PLLC_OSCDIV_TypeDef*)(PLLC1_BASE+PLLC_OSCDIV_OFFSET )))
#define PLLC1_OSCDIV_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_OSCDIV_OFFSET)))

/*--------*/
#define PLLC_OSCDIV_R_RATIO_MASK        ((uint32_t)0x0000001F)
#define PLLC_OSCDIV_R_RATIO_SHIFT         (0)

#define PLLC_OSCDIV_RATIO_MASK          ((uint32_t)0x0000001F)
/*--------*/

/*--------*/
#define PLLC_OSCDIV_R_OD1EN_MASK        ((uint32_t)0x00008000)
#define PLLC_OSCDIV_R_OD1EN_SHIFT         (15)

#define PLLC_OSCDIV_OD1EN_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 16 POSTDIV ***********************************************
**********************************************************************************************/
#define PLLC0_POSTDIV                    (((PLLC_POSTDIV_TypeDef*)(PLLC0_BASE+PLLC_POSTDIV_OFFSET )))
#define PLLC0_POSTDIV_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_POSTDIV_OFFSET)))
#define PLLC1_POSTDIV                    (((PLLC_POSTDIV_TypeDef*)(PLLC1_BASE+PLLC_POSTDIV_OFFSET )))
#define PLLC1_POSTDIV_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_POSTDIV_OFFSET)))

/*--------*/
#define PLLC_POSTDIV_R_RATIO_MASK        ((uint32_t)0x0000001F)
#define PLLC_POSTDIV_R_RATIO_SHIFT         (0)

#define PLLC_POSTDIV_RATIO_MASK          ((uint32_t)0x0000001F)
/*--------*/

/*--------*/
#define PLLC_POSTDIV_R_POSTDEN_MASK        ((uint32_t)0x00008000)
#define PLLC_POSTDIV_R_POSTDEN_SHIFT         (15)

#define PLLC_POSTDIV_POSTDEN_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 17 PLLCMD ***********************************************
**********************************************************************************************/
#define PLLC0_PLLCMD                    (((PLLC_PLLCMD_TypeDef*)(PLLC0_BASE+PLLC_PLLCMD_OFFSET )))
#define PLLC0_PLLCMD_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_PLLCMD_OFFSET)))
#define PLLC1_PLLCMD                    (((PLLC_PLLCMD_TypeDef*)(PLLC1_BASE+PLLC_PLLCMD_OFFSET )))
#define PLLC1_PLLCMD_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_PLLCMD_OFFSET)))

/*--------*/
#define PLLC_PLLCMD_R_GOSET_MASK        ((uint32_t)0x00000001)
#define PLLC_PLLCMD_R_GOSET_SHIFT         (0)

#define PLLC_PLLCMD_GOSET_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 18 PLLSTAT ***********************************************
**********************************************************************************************/
#define PLLC0_PLLSTAT                    (((PLLC_PLLSTAT_TypeDef*)(PLLC0_BASE+PLLC_PLLSTAT_OFFSET )))
#define PLLC0_PLLSTAT_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_PLLSTAT_OFFSET)))
#define PLLC1_PLLSTAT                    (((PLLC_PLLSTAT_TypeDef*)(PLLC1_BASE+PLLC_PLLSTAT_OFFSET )))
#define PLLC1_PLLSTAT_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_PLLSTAT_OFFSET)))

/*--------*/
#define PLLC_PLLSTAT_R_GOSTAT_MASK        ((uint32_t)0x00000001)
#define PLLC_PLLSTAT_R_GOSTAT_SHIFT         (0)

#define PLLC_PLLSTAT_GOSTAT_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC_PLLSTAT_R_STABLE_MASK        ((uint32_t)0x00000004)
#define PLLC_PLLSTAT_R_STABLE_SHIFT         (2)

#define PLLC_PLLSTAT_STABLE_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 19 ALNCTL ***********************************************
**********************************************************************************************/
#define PLLC0_ALNCTL                    (((PLLC0_ALNCTL_TypeDef*)(PLLC0_BASE+PLLC_ALNCTL_OFFSET )))
#define PLLC0_ALNCTL_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_ALNCTL_OFFSET)))
#define PLLC1_ALNCTL                    (((PLLC1_ALNCTL_TypeDef*)(PLLC1_BASE+PLLC_ALNCTL_OFFSET )))
#define PLLC1_ALNCTL_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_ALNCTL_OFFSET)))

/*--------*/
#define PLLC_ALNCTL_R_ALN1_MASK        ((uint32_t)0x00000001)
#define PLLC_ALNCTL_R_ALN1_SHIFT         (0)

#define PLLC_ALNCTL_ALN1_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC_ALNCTL_R_ALN2_MASK        ((uint32_t)0x00000002)
#define PLLC_ALNCTL_R_ALN2_SHIFT         (1)

#define PLLC_ALNCTL_ALN2_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC_ALNCTL_R_ALN3_MASK        ((uint32_t)0x00000004)
#define PLLC_ALNCTL_R_ALN3_SHIFT         (2)

#define PLLC_ALNCTL_ALN3_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_ALNCTL_R_ALN4_MASK        ((uint32_t)0x00000008)
#define PLLC0_ALNCTL_R_ALN4_SHIFT         (3)

#define PLLC0_ALNCTL_ALN4_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_ALNCTL_R_ALN5_MASK        ((uint32_t)0x00000010)
#define PLLC0_ALNCTL_R_ALN5_SHIFT         (4)

#define PLLC0_ALNCTL_ALN5_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_ALNCTL_R_ALN6_MASK        ((uint32_t)0x00000020)
#define PLLC0_ALNCTL_R_ALN6_SHIFT         (5)

#define PLLC0_ALNCTL_ALN6_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_ALNCTL_R_ALN7_MASK        ((uint32_t)0x00000040)
#define PLLC0_ALNCTL_R_ALN7_SHIFT         (6)

#define PLLC0_ALNCTL_ALN7_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 20 DCHANGE ***********************************************
**********************************************************************************************/
#define PLLC0_DCHANGE                    (((PLLC0_DCHANGE_TypeDef*)(PLLC0_BASE+PLLC_DCHANGE_OFFSET )))
#define PLLC0_DCHANGE_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_DCHANGE_OFFSET)))
#define PLLC1_DCHANGE                    (((PLLC1_DCHANGE_TypeDef*)(PLLC1_BASE+PLLC_DCHANGE_OFFSET )))
#define PLLC1_DCHANGE_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_DCHANGE_OFFSET)))

/*--------*/
#define PLLC_DCHANGE_R_SYS1_MASK        ((uint32_t)0x00000001)
#define PLLC_DCHANGE_R_SYS1_SHIFT         (0)

#define PLLC_DCHANGE_SYS1_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC_DCHANGE_R_SYS2_MASK        ((uint32_t)0x00000002)
#define PLLC_DCHANGE_R_SYS2_SHIFT         (1)

#define PLLC_DCHANGE_SYS2_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC_DCHANGE_R_SYS3_MASK        ((uint32_t)0x00000004)
#define PLLC_DCHANGE_R_SYS3_SHIFT         (2)

#define PLLC_DCHANGE_SYS3_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_DCHANGE_R_SYS4_MASK        ((uint32_t)0x00000008)
#define PLLC0_DCHANGE_R_SYS4_SHIFT         (3)

#define PLLC0_DCHANGE_SYS4_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_DCHANGE_R_SYS5_MASK        ((uint32_t)0x00000010)
#define PLLC0_DCHANGE_R_SYS5_SHIFT         (4)

#define PLLC0_DCHANGE_SYS5_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_DCHANGE_R_SYS6_MASK        ((uint32_t)0x00000020)
#define PLLC0_DCHANGE_R_SYS6_SHIFT         (5)

#define PLLC0_DCHANGE_SYS6_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_DCHANGE_R_SYS7_MASK        ((uint32_t)0x00000040)
#define PLLC0_DCHANGE_R_SYS7_SHIFT         (6)

#define PLLC0_DCHANGE_SYS7_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 21 CKEN ***********************************************
**********************************************************************************************/
#define PLLC0_CKEN                    (((PLLC0_CKEN_TypeDef*)(PLLC0_BASE+PLLC_CKEN_OFFSET )))
#define PLLC0_CKEN_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_CKEN_OFFSET)))
#define PLLC1_CKEN                    (((PLLC1_CKEN_TypeDef*)(PLLC1_BASE+PLLC_CKEN_OFFSET )))
#define PLLC1_CKEN_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_CKEN_OFFSET)))

/*--------*/
#define PLLC0_CKEN_R_AUXEN_MASK        ((uint32_t)0x00000001)
#define PLLC0_CKEN_R_AUXEN_SHIFT         (0)

#define PLLC0_CKEN_AUXEN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC_CKEN_R_OBSEN_MASK        ((uint32_t)0x00000002)
#define PLLC_CKEN_R_OBSEN_SHIFT         (1)

#define PLLC_CKEN_OBSEN_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 21 CKSTAT ***********************************************
**********************************************************************************************/
#define PLLC0_CKSTAT                    (((PLLC0_CKSTAT_TypeDef*)(PLLC0_BASE+PLLC_CKSTAT_OFFSET )))
#define PLLC0_CKSTAT_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_CKSTAT_OFFSET)))
#define PLLC1_CKSTAT                    (((PLLC1_CKSTAT_TypeDef*)(PLLC1_BASE+PLLC_CKSTAT_OFFSET )))
#define PLLC1_CKSTAT_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_CKSTAT_OFFSET)))

/*--------*/
#define PLLC0_CKSTAT_R_AUXEN_MASK        ((uint32_t)0x00000001)
#define PLLC0_CKSTAT_R_AUXEN_SHIFT         (0)

#define PLLC0_CKSTAT_AUXEN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC_CKSTAT_R_OBSEN_MASK        ((uint32_t)0x00000002)
#define PLLC_CKSTAT_R_OBSEN_SHIFT         (1)

#define PLLC_CKSTAT_OBSEN_MASK          ((uint32_t)0x00000001)
/*--------*/



/**********************************************************************************************
************************************** 22 SYSTAT ***********************************************
**********************************************************************************************/
#define PLLC0_SYSTAT                    (((PLLC0_SYSTAT_TypeDef*)(PLLC0_BASE+PLLC_SYSTAT_OFFSET )))
#define PLLC0_SYSTAT_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_SYSTAT_OFFSET)))
#define PLLC1_SYSTAT                    (((PLLC1_SYSTAT_TypeDef*)(PLLC1_BASE+PLLC_SYSTAT_OFFSET )))
#define PLLC1_SYSTAT_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_SYSTAT_OFFSET)))

/*--------*/
#define PLLC_SYSTAT_R_SYS1ON_MASK        ((uint32_t)0x00000001)
#define PLLC_SYSTAT_R_SYS1ON_SHIFT         (0)

#define PLLC_SYSTAT_SYS1ON_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC_SYSTAT_R_SYS2ON_MASK        ((uint32_t)0x00000002)
#define PLLC_SYSTAT_R_SYS2ON_SHIFT         (1)

#define PLLC_SYSTAT_SYS2ON_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC_SYSTAT_R_SYS3ON_MASK        ((uint32_t)0x00000004)
#define PLLC_SYSTAT_R_SYS3ON_SHIFT         (2)

#define PLLC_SYSTAT_SYS3ON_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_SYSTAT_R_SYS4ON_MASK        ((uint32_t)0x00000008)
#define PLLC0_SYSTAT_R_SYS4ON_SHIFT         (3)

#define PLLC0_SYSTAT_SYS4ON_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_SYSTAT_R_SYS5ON_MASK        ((uint32_t)0x00000010)
#define PLLC0_SYSTAT_R_SYS5ON_SHIFT         (4)

#define PLLC0_SYSTAT_SYS5ON_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_SYSTAT_R_SYS6ON_MASK        ((uint32_t)0x00000020)
#define PLLC0_SYSTAT_R_SYS6ON_SHIFT         (5)

#define PLLC0_SYSTAT_SYS6ON_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PLLC0_SYSTAT_R_SYS7ON_MASK        ((uint32_t)0x00000040)
#define PLLC0_SYSTAT_R_SYS7ON_SHIFT         (6)

#define PLLC0_SYSTAT_SYS7ON_MASK          ((uint32_t)0x00000001)
/*--------*/




/**********************************************************************************************
************************************** 23 EMUCNT0 ***********************************************
**********************************************************************************************/
#define PLLC0_EMUCNT0                    (((PLLC_EMUCNT0_TypeDef*)(PLLC0_BASE+PLLC_EMUCNT0_OFFSET )))
#define PLLC0_EMUCNT0_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_EMUCNT0_OFFSET)))
#define PLLC1_EMUCNT0                    (((PLLC_EMUCNT0_TypeDef*)(PLLC1_BASE+PLLC_EMUCNT0_OFFSET )))
#define PLLC1_EMUCNT0_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_EMUCNT0_OFFSET)))

/*--------*/
#define PLLC_EMUCNT0_R_COUNT_MASK        ((uint32_t)0xFFFFFFFF)
#define PLLC_EMUCNT0_R_COUNT_SHIFT         (0)

#define PLLC_EMUCNT0_COUNT_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/



/**********************************************************************************************
************************************** 24 EMUCNT0 ***********************************************
**********************************************************************************************/
#define PLLC0_EMUCNT1                    (((PLLC_EMUCNT0_TypeDef*)(PLLC0_BASE+PLLC_EMUCNT0_OFFSET )))
#define PLLC0_EMUCNT1_R                  (*((__IO uint32_t *)(PLLC0_BASE+PLLC_EMUCNT0_OFFSET)))
#define PLLC1_EMUCNT1                    (((PLLC_EMUCNT0_TypeDef*)(PLLC1_BASE+PLLC_EMUCNT0_OFFSET )))
#define PLLC1_EMUCNT1_R                  (*((__IO uint32_t *)(PLLC1_BASE+PLLC_EMUCNT0_OFFSET)))

/*--------*/
#define PLLC_EMUCNT1_R_COUNT_MASK        ((uint32_t)0xFFFFFFFF)
#define PLLC_EMUCNT1_R_COUNT_SHIFT         (0)

#define PLLC_EMUCNT1_COUNT_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


#define PLLEN_MUX_SWITCH         4
#define PLL_LOCK_TIME_CNT        2400
#define PLL_STABILIZATION_TIME   2000
#define PLL_RESET_TIME_CNT       200


#pragma FUNC_ALWAYS_INLINE( PLLC__vSetCore400Mhz)
void PLLC__vSetCore400Mhz(void);

#endif /* INCLUDE_PLLC_H_ */
