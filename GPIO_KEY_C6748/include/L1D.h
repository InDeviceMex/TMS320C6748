/*
 * CacheL1.h
 *
 *  Created on: 13/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_L1D_H_
#define INCLUDE_L1D_H_

#include "Core.h"
#include <stdint.h>

#define L1D_BASE            ((uint32_t)0x01840040)

typedef __IO struct
{
    __IO uint32_t MODE       :3;
         uint32_t reserved0  :29;
}L1D_CFG_TypeDef;

typedef __IO struct
{
    __IO uint32_t OPER       :1;
         uint32_t reserved0  :15;
    __I  uint32_t POPER      :1;
         uint32_t reserved1  :15;
}L1D_CC_TypeDef;



typedef __IO struct
{
    __IO uint32_t INVALIDATE       :32;
}L1D_IBAR_TypeDef;

typedef __IO struct
{
    __IO uint32_t INV_COUNT       :16;
         uint32_t reserved0       :16;
}L1D_IWC_TypeDef;



typedef __IO struct
{
    __IO uint32_t WRITEBACK       :32;
}L1D_WBAR_TypeDef;

typedef __IO struct
{
    __IO uint32_t WB_COUNT       :16;
         uint32_t reserved0       :16;
}L1D_WWC_TypeDef;

typedef __IO struct
{
    __IO uint32_t WBINVALIDATE       :32;
}L1D_WIBAR_TypeDef;

typedef __IO struct
{
    __IO uint32_t WBINV_COUNT       :16;
         uint32_t reserved0       :16;
}L1D_WIWC_TypeDef;

typedef __IO struct
{
    __IO uint32_t I       :1;
        uint32_t reserved0       :31;
}L1D_INV_TypeDef;

typedef __IO struct
{
    __IO uint32_t C       :1;
        uint32_t reserved0       :31;
}L1D_WB_TypeDef;

typedef __IO struct
{
    __IO uint32_t C       :1;
        uint32_t reserved0       :31;
}L1D_WBINV_TypeDef;

typedef __IO struct
{
    __IO uint32_t UX       :1;
    __IO uint32_t UW       :1;
    __IO uint32_t UR       :1;
    __IO uint32_t SX       :1;
    __IO uint32_t SW       :1;
    __IO uint32_t SR       :1;
         uint32_t reserved0  :2;
    __IO uint32_t LOCAL      :1;
    __IO uint32_t AIDX      :1;
    __IO uint32_t AID0      :1;
    __IO uint32_t AID1      :1;
    __IO uint32_t AID2      :1;
    __IO uint32_t AID3      :1;
    __IO uint32_t AID4      :1;
    __IO uint32_t AID5      :1;
         uint32_t reserved1  :16;
}L1D_MPPA_TypeDef;

typedef __IO struct
{
    __IO uint32_t LOCK       :32;
}L1D_MPLK_TypeDef;

typedef __IO struct
{
    __IO uint32_t UNLOCK      :1;
    __IO uint32_t LOCK       :1;
    __IO uint32_t KEYR       :1;
         uint32_t reserved0  :29;
}L1D_MPLKCMD_TypeDef;

typedef __IO struct
{
    __I uint32_t LK      :1;
         uint32_t reserved0  :31;
}L1D_MPLKSTAT_TypeDef;

typedef __IO struct
{
    __I uint32_t ADDRESS      :32;
}L1D_MPFAR_TypeDef;

typedef __IO struct
{
         uint32_t reserved0   :1;
         __I uint32_t UW      :1;
         __I uint32_t UR      :1;
         uint32_t reserved1   :1;
         __I uint32_t SW      :1;
         __I uint32_t SR      :1;
         uint32_t reserved2   :2;
         __I uint32_t LOCAL   :1;
         __I uint32_t FID     :7;
         uint32_t reserved3   :16;
}L1D_MPFSR_TypeDef;

typedef __IO struct
{
    __IO uint32_t MPFCLR      :1;
         uint32_t reserved0   :31;
}L1D_MPFCLR_TypeDef;






typedef __IO struct
{
    union
    {
        __IO uint32_t       CFG;
        L1D_CFG_TypeDef     CFG_Bit;
    };
    union
    {
        __IO uint32_t       CC;
        L1D_CC_TypeDef      CC_Bit;
    };
    uint32_t Reserved0[4090];
    union
    {
        __IO uint32_t       WIBAR;
        L1D_WIBAR_TypeDef    WIBAR_Bit;
    };
    union
    {
        __IO uint32_t       WIWC;
        L1D_WIWC_TypeDef    WIWC_Bit;
    };
    uint32_t Reserved1[2];
    union
    {
        __IO uint32_t       WBAR;
        L1D_WBAR_TypeDef    WBAR_Bit;
    };
    union
    {
        __IO uint32_t       WWC;
        L1D_WWC_TypeDef     WWC_Bit;
    };
    union
    {
        __IO uint32_t       IBAR;
        L1D_IBAR_TypeDef    IBAR_Bit;
    };
    union
    {
        __IO uint32_t       IWC;
        L1D_IWC_TypeDef     IWC_Bit;
    };
    uint32_t Reserved2[1020];
    union
    {
        __IO uint32_t       WB;
        L1D_WB_TypeDef    WB_Bit;
    };
    union
    {
        __IO uint32_t       WBINV;
        L1D_WBINV_TypeDef   WBINV_Bit;
    };
    union
    {
        __IO uint32_t       INV;
        L1D_INV_TypeDef    INV_Bit;
    };

    uint32_t Reserved3[5869];

    union
    {
        __I uint32_t       MPFAR;
        L1D_MPFAR_TypeDef MPFAR_Bit;
    };

    union
    {
        __I uint32_t       MPFSR;
        L1D_MPFSR_TypeDef  MPFSR_Bit;
    };

    union
    {
        __IO uint32_t       MPFCLR;
        L1D_MPFCLR_TypeDef   MPFCLR_Bit;
    };

    uint32_t Reserved4[61];

    union
    {
        __IO uint32_t       MPLK[4];
        L1D_MPLK_TypeDef    MPLK_Bit[4];
    };
    union
    {
        __IO uint32_t       MPLKCMD;
        L1D_MPLKCMD_TypeDef MPLKCMD_Bit;
    };
    union
    {
        __IO uint32_t        MPLKSTAT;
        L1D_MPLKSTAT_TypeDef MPLKSTAT_Bit;
    };

    uint32_t Reserved5[58];
    union
    {
        __IO uint32_t       MPPA[32];
        L1D_MPPA_TypeDef    MPPA_Bit[32];
    };
}L1D_TypeDef;

#define L1D            (((L1D_TypeDef*)(L1D_BASE)))
#define L1D_R(offset)  (*((__IO uint32_t *)(L1D_BASE+offset)))


#define L1D_CFG_OFFSET      ((uint32_t)0x0000)
#define L1D_CC_OFFSET       ((uint32_t)0x0004)

#define L1D_WIBAR_OFFSET    ((uint32_t)0x3FF0)
#define L1D_WIWC_OFFSET     ((uint32_t)0x3FF4)
#define L1D_WBAR_OFFSET     ((uint32_t)0x4000)
#define L1D_WWC_OFFSET      ((uint32_t)0x4004)
#define L1D_IBAR_OFFSET     ((uint32_t)0x4008)
#define L1D_IWC_OFFSET      ((uint32_t)0x400C)

#define L1D_WB_OFFSET       ((uint32_t)0x5000)
#define L1D_WBINV_OFFSET    ((uint32_t)0x5004)
#define L1D_INV_OFFSET      ((uint32_t)0x5008)



#define L1D_MPFAR_OFFSET    ((uint32_t)0xABC0)
#define L1D_MPFSR_OFFSET    ((uint32_t)0xABC4)
#define L1D_MPFCLR_OFFSET   ((uint32_t)0xABC8)

#define L1D_MPLK0_OFFSET    ((uint32_t)0xACC0)
#define L1D_MPLK1_OFFSET    ((uint32_t)0xACC4)
#define L1D_MPLK2_OFFSET    ((uint32_t)0xACC8)
#define L1D_MPLK3_OFFSET    ((uint32_t)0ACCC)
#define L1D_MPLKCMD_OFFSET  ((uint32_t)0xACD0)
#define L1D_MPLKSTAT_OFFSET ((uint32_t)0xACD4)


#define L1D_MPPA0_OFFSET    ((uint32_t)0xADC0)
#define L1D_MPPA1_OFFSET    ((uint32_t)0xADC4)
#define L1D_MPPA2_OFFSET    ((uint32_t)0xADC8)
#define L1D_MPPA3_OFFSET    ((uint32_t)0xADCC)
#define L1D_MPPA4_OFFSET    ((uint32_t)0xADD0)
#define L1D_MPPA5_OFFSET    ((uint32_t)0xADD4)
#define L1D_MPPA6_OFFSET    ((uint32_t)0xADD8)
#define L1D_MPPA7_OFFSET    ((uint32_t)0xADDC)
#define L1D_MPPA8_OFFSET    ((uint32_t)0xADE0)
#define L1D_MPPA9_OFFSET    ((uint32_t)0xADE4)
#define L1D_MPPA10_OFFSET    ((uint32_t)0xADE8)
#define L1D_MPPA11_OFFSET    ((uint32_t)0xADEC)
#define L1D_MPPA12_OFFSET    ((uint32_t)0xADF0)
#define L1D_MPPA13_OFFSET    ((uint32_t)0xADF4)
#define L1D_MPPA14_OFFSET    ((uint32_t)0xADF8)
#define L1D_MPPA15_OFFSET    ((uint32_t)0xADFC)
#define L1D_MPPA16_OFFSET    ((uint32_t)0xAE00)
#define L1D_MPPA17_OFFSET    ((uint32_t)0xAE04)
#define L1D_MPPA18_OFFSET    ((uint32_t)0xAE08)
#define L1D_MPPA19_OFFSET    ((uint32_t)0xAE0C)
#define L1D_MPPA20_OFFSET    ((uint32_t)0xAE10)
#define L1D_MPPA21_OFFSET    ((uint32_t)0xAE14)
#define L1D_MPPA22_OFFSET    ((uint32_t)0xAE18)
#define L1D_MPPA23_OFFSET    ((uint32_t)0xAE1C)
#define L1D_MPPA24_OFFSET    ((uint32_t)0xAE20)
#define L1D_MPPA25_OFFSET    ((uint32_t)0xAE24)
#define L1D_MPPA26_OFFSET    ((uint32_t)0xAE28)
#define L1D_MPPA27_OFFSET    ((uint32_t)0xAE2C)
#define L1D_MPPA28_OFFSET    ((uint32_t)0xAE30)
#define L1D_MPPA29_OFFSET    ((uint32_t)0xAE34)
#define L1D_MPPA30_OFFSET    ((uint32_t)0xAE38)
#define L1D_MPPA31_OFFSET    ((uint32_t)0xAE3C)


/**********************************************************************************************
************************************** 2 CFG ***********************************************
**********************************************************************************************/
#define L1D_CFG                    (((L1D_CFG_TypeDef*)(L1D_BASE+L1D_CFG_OFFSET )))
#define L1D_CFG_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_CFG_OFFSET)))


/*--------*/
#define L1D_CFG_R_MODE_MASK        ((uint32_t)0x00000007)
#define L1D_CFG_R_MODE_SHIFT         (0)

#define L1D_CFG_MODE_MASK          ((uint32_t)0x00000007)
/*--------*/

/**********************************************************************************************
************************************** 2 CC ***********************************************
**********************************************************************************************/

#define L1D_CC                    (((L1D_CC_TypeDef*)(L1D_BASE+L1D_CC_OFFSET )))
#define L1D_CC_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_CC_OFFSET)))


/*--------*/
#define L1D_CC_R_OPER_MASK        ((uint32_t)0x00000001)
#define L1D_CC_R_OPER_SHIFT         (0)

#define L1D_CC_OPER_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_CC_R_POPER_MASK        ((uint32_t)0x00010000)
#define L1D_CC_R_POPER_SHIFT         (16)

#define L1D_CC_POPER_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 3 IBAR ***********************************************
**********************************************************************************************/
#define L1D_IBAR                    (((L1D_IBAR_TypeDef*)(L1D_BASE+L1D_IBAR_OFFSET )))
#define L1D_IBAR_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_IBAR_OFFSET)))


/*--------*/
#define L1D_IBAR_R_INVALIDATE_MASK        ((uint32_t)0xFFFFFFFF)
#define L1D_IBAR_R_INVALIDATE_SHIFT         (0)

#define L1D_IBAR_INVALIDATE_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 4 IWC ***********************************************
**********************************************************************************************/
#define L1D_IWC                    (((L1D_IWC_TypeDef*)(L1D_BASE+L1D_IWC_OFFSET )))
#define L1D_IWC_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_IWC_OFFSET)))


/*--------*/
#define L1D_IWC_R_INV_COUNT_MASK        ((uint32_t)0x0000FFFF)
#define L1D_IWC_R_INV_COUNT_SHIFT         (0)

#define L1D_IWC_INV_COUNT_MASK          ((uint32_t)0x0000FFFF)
/*--------*/


/**********************************************************************************************
************************************** 3 WBAR ***********************************************
**********************************************************************************************/
#define L1D_WBAR                    (((L1D_WBAR_TypeDef*)(L1D_BASE+L1D_WBAR_OFFSET )))
#define L1D_WBAR_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_WBAR_OFFSET)))


/*--------*/
#define L1D_WBAR_R_INVALIDATE_MASK        ((uint32_t)0xFFFFFFFF)
#define L1D_WBAR_R_INVALIDATE_SHIFT         (0)

#define L1D_WBAR_INVALIDATE_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 4 WWC ***********************************************
**********************************************************************************************/
#define L1D_WWC                    (((L1D_WWC_TypeDef*)(L1D_BASE+L1D_WWC_OFFSET )))
#define L1D_WWC_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_WWC_OFFSET)))


/*--------*/
#define L1D_WWC_R_WB_COUNT_MASK        ((uint32_t)0x0000FFFF)
#define L1D_WWC_R_WB_COUNT_SHIFT         (0)

#define L1D_WWC_WB_COUNT_MASK          ((uint32_t)0x0000FFFF)
/*--------*/



/**********************************************************************************************
************************************** 3 WIBAR ***********************************************
**********************************************************************************************/
#define L1D_WIBAR                    (((L1D_WIBAR_TypeDef*)(L1D_BASE+L1D_WIBAR_OFFSET )))
#define L1D_WIBAR_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_WIBAR_OFFSET)))


/*--------*/
#define L1D_WIBAR_R_WBINVALIDATE_MASK        ((uint32_t)0xFFFFFFFF)
#define L1D_WIBAR_R_WBINVALIDATE_SHIFT         (0)

#define L1D_WIBAR_WBINVALIDATE_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 4 WIWC ***********************************************
**********************************************************************************************/
#define L1D_WIWC                    (((L1D_WIWC_TypeDef*)(L1D_BASE+L1D_WIWC_OFFSET )))
#define L1D_WIWC_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_WIWC_OFFSET)))


/*--------*/
#define L1D_WIWC_R_WBINV_COUNT_MASK        ((uint32_t)0x0000FFFF)
#define L1D_WIWC_R_WBINV_COUNT_SHIFT         (0)

#define L1D_WIWC_WBINV_COUNT_MASK          ((uint32_t)0x0000FFFF)
/*--------*/



/**********************************************************************************************
************************************** 5 INV ***********************************************
**********************************************************************************************/
#define L1D_INV                    (((L1D_INV_TypeDef*)(L1D_BASE+L1D_INV_OFFSET )))
#define L1D_INV_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_INV_OFFSET)))


/*--------*/
#define L1D_INV_R_I_MASK        ((uint32_t)0x00000001)
#define L1D_INV_R_I_SHIFT         (0)

#define L1D_INV_I_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 5 WB ***********************************************
**********************************************************************************************/
#define L1D_WB                    (((L1D_WB_TypeDef*)(L1D_BASE+L1D_WB_OFFSET )))
#define L1D_WB_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_WB_OFFSET)))


/*--------*/
#define L1D_WB_R_C_MASK        ((uint32_t)0x00000001)
#define L1D_WB_R_C_SHIFT         (0)

#define L1D_WB_C_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 5 WBINV ***********************************************
**********************************************************************************************/
#define L1D_WBINV                    (((L1D_WBINV_TypeDef*)(L1D_BASE+L1D_WBINV_OFFSET )))
#define L1D_WBINV_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_WBINV_OFFSET)))


/*--------*/
#define L1D_WBINV_R_C_MASK        ((uint32_t)0x00000001)
#define L1D_WBINV_R_C_SHIFT         (0)

#define L1D_WBINV_C_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 6-28 MPPA ***********************************************
**********************************************************************************************/
#define L1D_MPPA0                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA0_OFFSET )))
#define L1D_MPPA0_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA0_OFFSET)))
#define L1D_MPPA1                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA1_OFFSET )))
#define L1D_MPPA1_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA1_OFFSET)))
#define L1D_MPPA2                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA2_OFFSET )))
#define L1D_MPPA2_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA2_OFFSET)))
#define L1D_MPPA3                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA3_OFFSET )))
#define L1D_MPPA3_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA3_OFFSET)))
#define L1D_MPPA4                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA4_OFFSET )))
#define L1D_MPPA4_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA4_OFFSET)))
#define L1D_MPPA5                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA5_OFFSET )))
#define L1D_MPPA5_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA5_OFFSET)))
#define L1D_MPPA6                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA6_OFFSET )))
#define L1D_MPPA6_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA6_OFFSET)))
#define L1D_MPPA7                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA7_OFFSET )))
#define L1D_MPPA7_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA7_OFFSET)))
#define L1D_MPPA8                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA8_OFFSET )))
#define L1D_MPPA8_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA8_OFFSET)))
#define L1D_MPPA9                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA9_OFFSET )))
#define L1D_MPPA9_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA9_OFFSET)))
#define L1D_MPPA10                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA10_OFFSET )))
#define L1D_MPPA10_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA10_OFFSET)))
#define L1D_MPPA11                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA11_OFFSET )))
#define L1D_MPPA11_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA11_OFFSET)))
#define L1D_MPPA12                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA12_OFFSET )))
#define L1D_MPPA12_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA12_OFFSET)))
#define L1D_MPPA13                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA13_OFFSET )))
#define L1D_MPPA13_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA13_OFFSET)))
#define L1D_MPPA14                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA14_OFFSET )))
#define L1D_MPPA14_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA14_OFFSET)))
#define L1D_MPPA15                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA15_OFFSET )))
#define L1D_MPPA15_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA15_OFFSET)))
#define L1D_MPPA16                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA16_OFFSET )))
#define L1D_MPPA16_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA16_OFFSET)))
#define L1D_MPPA17                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA17_OFFSET )))
#define L1D_MPPA17_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA17_OFFSET)))
#define L1D_MPPA18                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA18_OFFSET )))
#define L1D_MPPA18_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA18_OFFSET)))
#define L1D_MPPA19                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA19_OFFSET )))
#define L1D_MPPA19_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA19_OFFSET)))
#define L1D_MPPA20                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA20_OFFSET )))
#define L1D_MPPA20_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA20_OFFSET)))
#define L1D_MPPA21                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA21_OFFSET )))
#define L1D_MPPA21_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA21_OFFSET)))
#define L1D_MPPA22                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA22_OFFSET )))
#define L1D_MPPA22_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA22_OFFSET)))
#define L1D_MPPA23                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA23_OFFSET )))
#define L1D_MPPA23_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA23_OFFSET)))
#define L1D_MPPA24                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA24_OFFSET )))
#define L1D_MPPA24_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA24_OFFSET)))
#define L1D_MPPA25                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA25_OFFSET )))
#define L1D_MPPA25_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA25_OFFSET)))
#define L1D_MPPA26                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA26_OFFSET )))
#define L1D_MPPA26_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA26_OFFSET)))
#define L1D_MPPA27                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA27_OFFSET )))
#define L1D_MPPA27_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA27_OFFSET)))
#define L1D_MPPA28                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA28_OFFSET )))
#define L1D_MPPA28_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA28_OFFSET)))
#define L1D_MPPA29                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA29_OFFSET )))
#define L1D_MPPA29_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA29_OFFSET)))
#define L1D_MPPA30                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA30_OFFSET )))
#define L1D_MPPA30_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA30_OFFSET)))
#define L1D_MPPA31                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA31_OFFSET )))
#define L1D_MPPA31_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA31_OFFSET)))
#define L1D_MPPA(n)                    (((L1D_MPPA_TypeDef*)(L1D_BASE+L1D_MPPA0_OFFSET +((n)*4) )))
#define L1D_MPPA_R(n)                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPPA0_OFFSET +((n)*4))))


/*--------*/
#define L1D_MPPA_R_UX_MASK        ((uint32_t)0x00000001)
#define L1D_MPPA_R_UX_SHIFT         (0)

#define L1D_MPPA_UX_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPPA_R_UW_MASK        ((uint32_t)0x00000002)
#define L1D_MPPA_R_UW_SHIFT         (1)

#define L1D_MPPA_UW_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPPA_R_UR_MASK        ((uint32_t)0x00000004)
#define L1D_MPPA_R_UR_SHIFT         (2)

#define L1D_MPPA_UR_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPPA_R_SX_MASK        ((uint32_t)0x00000008)
#define L1D_MPPA_R_SX_SHIFT         (3)

#define L1D_MPPA_SX_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPPA_R_SW_MASK        ((uint32_t)0x00000010)
#define L1D_MPPA_R_SW_SHIFT         (4)

#define L1D_MPPA_SW_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPPA_R_SR_MASK        ((uint32_t)0x00000020)
#define L1D_MPPA_R_SR_SHIFT         (5)

#define L1D_MPPA_SR_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPPA_R_LOCAL_MASK        ((uint32_t)0x00000100)
#define L1D_MPPA_R_LOCAL_SHIFT         (8)

#define L1D_MPPA_LOCAL_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPPA_R_AIDX_MASK        ((uint32_t)0x00000200)
#define L1D_MPPA_R_AIDX_SHIFT         (9)

#define L1D_MPPA_AIDX_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPPA_R_AID0_MASK        ((uint32_t)0x00000400)
#define L1D_MPPA_R_AID0_SHIFT         (10)

#define L1D_MPPA_AID0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPPA_R_AID1_MASK        ((uint32_t)0x00000800)
#define L1D_MPPA_R_AID1_SHIFT         (11)

#define L1D_MPPA_AID1_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPPA_R_AID2_MASK        ((uint32_t)0x00001000)
#define L1D_MPPA_R_AID2_SHIFT         (12)

#define L1D_MPPA_AID2_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPPA_R_AID3_MASK        ((uint32_t)0x00002000)
#define L1D_MPPA_R_AID3_SHIFT         (13)

#define L1D_MPPA_AID3_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPPA_R_AID4_MASK        ((uint32_t)0x00004000)
#define L1D_MPPA_R_AID4_SHIFT         (14)

#define L1D_MPPA_AID4_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPPA_R_AID5_MASK        ((uint32_t)0x00008000)
#define L1D_MPPA_R_AID5_SHIFT         (15)

#define L1D_MPPA_AID5_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 29-32 MPLK ***********************************************
**********************************************************************************************/
#define L1D_MPLK0                    (((L1D_MPLK_TypeDef*)(L1D_BASE+L1D_MPLK0_OFFSET )))
#define L1D_MPLK0_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPLK0_OFFSET)))
#define L1D_MPLK1                    (((L1D_MPLK_TypeDef*)(L1D_BASE+L1D_MPLK1_OFFSET )))
#define L1D_MPLK1_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPLK1_OFFSET)))
#define L1D_MPLK2                    (((L1D_MPLK_TypeDef*)(L1D_BASE+L1D_MPLK2_OFFSET )))
#define L1D_MPLK2_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPLK2_OFFSET)))
#define L1D_MPLK3                    (((L1D_MPLK_TypeDef*)(L1D_BASE+L1D_MPLK3_OFFSET )))
#define L1D_MPLK3_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPLK3_OFFSET)))


/*--------*/
#define L1D_MPLK_R_LOCK_MASK        ((uint32_t)0xFFFFFFFF)
#define L1D_MPLK_R_LOCK_SHIFT         (0)

#define L1D_MPLK_LOCK_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


/**********************************************************************************************
************************************** 33 MPLKCMD ***********************************************
**********************************************************************************************/
#define L1D_MPLKCMD                    (((L1D_MPLKCMD_TypeDef*)(L1D_BASE+L1D_MPLKCMD_OFFSET )))
#define L1D_MPLKCMD_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPLKCMD_OFFSET)))

/*--------*/
#define L1D_MPLKCMD_R_UNLOCK_MASK        ((uint32_t)0x00000001)
#define L1D_MPLKCMD_R_UNLOCK_SHIFT         (0)

#define L1D_MPLKCMD_UNLOCK_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPLKCMD_R_LOCK_MASK        ((uint32_t)0x00000002)
#define L1D_MPLKCMD_R_LOCK_SHIFT         (1)

#define L1D_MPLKCMD_LOCK_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPLKCMD_R_KEYR_MASK        ((uint32_t)0x00000004)
#define L1D_MPLKCMD_R_KEYR_SHIFT         (2)

#define L1D_MPLKCMD_KEYR_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 34 MPLKSTAT ***********************************************
**********************************************************************************************/
#define L1D_MPLKSTAT                    (((L1D_MPLKSTAT_TypeDef*)(L1D_BASE+L1D_MPLKSTAT_OFFSET )))
#define L1D_MPLKSTAT_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPLKSTAT_OFFSET)))

/*--------*/
#define L1D_MPLKSTAT_R_LK_MASK        ((uint32_t)0x00000001)
#define L1D_MPLKSTAT_R_LK_SHIFT         (0)

#define L1D_MPLKSTAT_LK_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 35 MPFAR ***********************************************
**********************************************************************************************/
#define L1D_MPFAR                    (((L1D_MPFAR_TypeDef*)(L1D_BASE+L1D_MPFAR_OFFSET )))
#define L1D_MPFAR_R                  (*((__I uint32_t *)(L1D_BASE+L1D_MPFAR_OFFSET)))

/*--------*/
#define L1D_MPFAR_R_ADDRESS_MASK        ((uint32_t)0xFFFFFFFF)
#define L1D_MPFAR_R_ADDRESS_SHIFT         (0)

#define L1D_MPFAR_ADDRESS_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


/**********************************************************************************************
************************************** 36 MPFSR ***********************************************
**********************************************************************************************/
#define L1D_MPFSR                    (((L1D_MPFSR_TypeDef*)(L1D_BASE+L1D_MPFSR_OFFSET )))
#define L1D_MPFSR_R                  (*((__I uint32_t *)(L1D_BASE+L1D_MPFSR_OFFSET)))

/*--------*/
#define L1D_MPFSR_R_UW_MASK        ((uint32_t)0x00000002)
#define L1D_MPFSR_R_UW_SHIFT         (1)

#define L1D_MPFSR_UW_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPFSR_R_UR_MASK        ((uint32_t)0x00000004)
#define L1D_MPFSR_R_UR_SHIFT         (2)

#define L1D_MPFSR_UR_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPFSR_R_SW_MASK        ((uint32_t)0x00000010)
#define L1D_MPFSR_R_SW_SHIFT         (4)

#define L1D_MPFSR_SW_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPFSR_R_SR_MASK        ((uint32_t)0x00000020)
#define L1D_MPFSR_R_SR_SHIFT         (2)

#define L1D_MPFSR_SR_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPFSR_R_LOCAL_MASK        ((uint32_t)0x00000100)
#define L1D_MPFSR_R_LOCAL_SHIFT         (8)

#define L1D_MPFSR_LOCAL_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1D_MPFSR_R_FID_MASK        ((uint32_t)0x0000FE00)
#define L1D_MPFSR_R_FID_SHIFT         (9)

#define L1D_MPFSR_FID_MASK          ((uint32_t)0x0000007F)
/*--------*/


/**********************************************************************************************
************************************** 36 MPFCLR ***********************************************
**********************************************************************************************/
#define L1D_MPFCLR                    (((L1D_MPFCLR_TypeDef*)(L1D_BASE+L1D_MPFCLR_OFFSET )))
#define L1D_MPFCLR_R                  (*((__IO uint32_t *)(L1D_BASE+L1D_MPFCLR_OFFSET)))

/*--------*/
#define L1D_MPFCLR_R_MPFCLR_MASK        ((uint32_t)0x00000001)
#define L1D_MPFCLR_R_MPFCLR_SHIFT         (0)

#define L1D_MPFCLR_MPFCLR_MASK          ((uint32_t)0x00000001)
/*--------*/


#endif /* INCLUDE_L1D_H_ */

