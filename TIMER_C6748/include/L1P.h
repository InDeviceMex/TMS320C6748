/*
 * CacheL1.h
 *
 *  Created on: 13/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_L1P_H_
#define INCLUDE_L1P_H_

#include "Core.h"
#include <stdint.h>

#define L1P_BASE            ((uint32_t)0x01840020)

typedef __IO struct
{
    __IO uint32_t MODE       :3;
         uint32_t reserved0  :29;
}L1P_CFG_TypeDef;

typedef __IO struct
{
    __IO uint32_t OPER       :1;
         uint32_t reserved0  :15;
    __I  uint32_t POPER      :1;
         uint32_t reserved1  :15;
}L1P_CC_TypeDef;

typedef __IO struct
{
    __IO uint32_t INVALIDATE       :32;
}L1P_IBAR_TypeDef;

typedef __IO struct
{
    __IO uint32_t INV_COUNT       :16;
         uint32_t reserved0       :16;
}L1P_IWC_TypeDef;

typedef __IO struct
{
    __IO uint32_t I       :1;
        uint32_t reserved0       :31;
}L1P_INV_TypeDef;

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
}L1P_MPPA_TypeDef;

typedef __IO struct
{
    __IO uint32_t LOCK       :32;
}L1P_MPLK_TypeDef;

typedef __IO struct
{
    __IO uint32_t UNLOCK      :1;
    __IO uint32_t LOCK       :1;
    __IO uint32_t KEYR       :1;
         uint32_t reserved0  :29;
}L1P_MPLKCMD_TypeDef;

typedef __IO struct
{
    __I uint32_t LK      :1;
         uint32_t reserved0  :31;
}L1P_MPLKSTAT_TypeDef;

typedef __IO struct
{
    __I uint32_t ADDRESS      :32;
}L1P_MPFAR_TypeDef;

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
}L1P_MPFSR_TypeDef;

typedef __IO struct
{
    __IO uint32_t MPFCLR      :1;
         uint32_t reserved0   :31;
}L1P_MPFCLR_TypeDef;






typedef __IO struct
{
    union
    {
        __IO uint32_t       CFG;
        L1P_CFG_TypeDef     CFG_Bit;
    };
    union
    {
        __IO uint32_t       CC;
        L1P_CC_TypeDef      CC_Bit;
    };
    uint32_t Reserved0[4094];
    union
    {
        __IO uint32_t       IBAR;
        L1P_IBAR_TypeDef    IBAR_Bit;
    };
    union
    {
        __IO uint32_t       IWC;
        L1P_IWC_TypeDef     IWC_Bit;
    };
    uint32_t Reserved1[1024];
    union
    {
        __IO uint32_t       INV;
        L1P_INV_TypeDef    INV_Bit;
    };

    uint32_t Reserved2[5365];

    union
    {
        __I uint32_t       MPFAR;
        L1P_MPFAR_TypeDef MPFAR_Bit;
    };

    union
    {
        __I uint32_t       MPFSR;
        L1P_MPFSR_TypeDef  MPFSR_Bit;
    };

    union
    {
        __IO uint32_t       MPFCLR;
        L1P_MPFCLR_TypeDef   MPFCLR_Bit;
    };

    uint32_t Reserved3[61];

    union
    {
        __IO uint32_t       MPLK[4];
        L1P_MPLK_TypeDef    MPLK_Bit[4];
    };
    union
    {
        __IO uint32_t       MPLKCMD;
        L1P_MPLKCMD_TypeDef MPLKCMD_Bit;
    };
    union
    {
        __IO uint32_t        MPLKSTAT;
        L1P_MPLKSTAT_TypeDef MPLKSTAT_Bit;
    };

    uint32_t Reserved4[58];
    union
    {
        __IO uint32_t       MPPA[32];
        L1P_MPPA_TypeDef    MPPA_Bit[32];
    };
}L1P_TypeDef;

#define L1P            (((L1P_TypeDef*)(L1P_BASE)))
#define L1P_R(offset)  (*((__IO uint32_t *)(L1P_BASE+offset)))


#define L1P_CFG_OFFSET      ((uint32_t)0x0000)
#define L1P_CC_OFFSET       ((uint32_t)0x0004)
#define L1P_IBAR_OFFSET     ((uint32_t)0x4000)
#define L1P_IWC_OFFSET      ((uint32_t)0x4004)
#define L1P_INV_OFFSET      ((uint32_t)0x5008)



#define L1P_MPFAR_OFFSET    ((uint32_t)0xA3E0)
#define L1P_MPFSR_OFFSET    ((uint32_t)0xA3E4)
#define L1P_MPFCLR_OFFSET   ((uint32_t)0xA3E8)

#define L1P_MPLK0_OFFSET    ((uint32_t)0xA4E0)
#define L1P_MPLK1_OFFSET    ((uint32_t)0xA4E4)
#define L1P_MPLK2_OFFSET    ((uint32_t)0xA4E8)
#define L1P_MPLK3_OFFSET    ((uint32_t)0xA4EC)
#define L1P_MPLKCMD_OFFSET  ((uint32_t)0xA4F0)
#define L1P_MPLKSTAT_OFFSET ((uint32_t)0xA4F4)


#define L1P_MPPA0_OFFSET    ((uint32_t)0xA5E0)
#define L1P_MPPA1_OFFSET    ((uint32_t)0xA5E4)
#define L1P_MPPA2_OFFSET    ((uint32_t)0xA5E8)
#define L1P_MPPA3_OFFSET    ((uint32_t)0xA5EC)
#define L1P_MPPA4_OFFSET    ((uint32_t)0xA5F0)
#define L1P_MPPA5_OFFSET    ((uint32_t)0xA5F4)
#define L1P_MPPA6_OFFSET    ((uint32_t)0xA5F8)
#define L1P_MPPA7_OFFSET    ((uint32_t)0xA5FC)
#define L1P_MPPA8_OFFSET    ((uint32_t)0xA600)
#define L1P_MPPA9_OFFSET    ((uint32_t)0xA604)
#define L1P_MPPA10_OFFSET    ((uint32_t)0xA608)
#define L1P_MPPA11_OFFSET    ((uint32_t)0xA60C)
#define L1P_MPPA12_OFFSET    ((uint32_t)0xA610)
#define L1P_MPPA13_OFFSET    ((uint32_t)0xA614)
#define L1P_MPPA14_OFFSET    ((uint32_t)0xA618)
#define L1P_MPPA15_OFFSET    ((uint32_t)0xA61C)
#define L1P_MPPA16_OFFSET    ((uint32_t)0xA620)
#define L1P_MPPA17_OFFSET    ((uint32_t)0xA624)
#define L1P_MPPA18_OFFSET    ((uint32_t)0xA628)
#define L1P_MPPA19_OFFSET    ((uint32_t)0xA62C)
#define L1P_MPPA20_OFFSET    ((uint32_t)0xA630)
#define L1P_MPPA21_OFFSET    ((uint32_t)0xA634)
#define L1P_MPPA22_OFFSET    ((uint32_t)0xA638)
#define L1P_MPPA23_OFFSET    ((uint32_t)0xA63C)
#define L1P_MPPA24_OFFSET    ((uint32_t)0xA640)
#define L1P_MPPA25_OFFSET    ((uint32_t)0xA644)
#define L1P_MPPA26_OFFSET    ((uint32_t)0xA648)
#define L1P_MPPA27_OFFSET    ((uint32_t)0xA64C)
#define L1P_MPPA28_OFFSET    ((uint32_t)0xA650)
#define L1P_MPPA29_OFFSET    ((uint32_t)0xA654)
#define L1P_MPPA30_OFFSET    ((uint32_t)0xA658)
#define L1P_MPPA31_OFFSET    ((uint32_t)0xA65C)


/**********************************************************************************************
************************************** 2 CFG ***********************************************
**********************************************************************************************/
#define L1P_CFG                    (((L1P_CFG_TypeDef*)(L1P_BASE+L1P_CFG_OFFSET )))
#define L1P_CFG_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_CFG_OFFSET)))


/*--------*/
#define L1P_CFG_R_MODE_MASK        ((uint32_t)0x00000007)
#define L1P_CFG_R_MODE_SHIFT         (0)

#define L1P_CFG_MODE_MASK          ((uint32_t)0x00000007)
/*--------*/

/**********************************************************************************************
************************************** 2 CC ***********************************************
**********************************************************************************************/

#define L1P_CC                    (((L1P_CC_TypeDef*)(L1P_BASE+L1P_CC_OFFSET )))
#define L1P_CC_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_CC_OFFSET)))


/*--------*/
#define L1P_CC_R_OPER_MASK        ((uint32_t)0x00000001)
#define L1P_CC_R_OPER_SHIFT         (0)

#define L1P_CC_OPER_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_CC_R_POPER_MASK        ((uint32_t)0x00010000)
#define L1P_CC_R_POPER_SHIFT         (16)

#define L1P_CC_POPER_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 3 IBAR ***********************************************
**********************************************************************************************/
#define L1P_IBAR                    (((L1P_IBAR_TypeDef*)(L1P_BASE+L1P_IBAR_OFFSET )))
#define L1P_IBAR_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_IBAR_OFFSET)))


/*--------*/
#define L1P_IBAR_R_MODE_MASK        ((uint32_t)0xFFFFFFFF)
#define L1P_IBAR_R_MODE_SHIFT         (0)

#define L1P_IBAR_MODE_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 4 IWC ***********************************************
**********************************************************************************************/
#define L1P_IWC                    (((L1P_IWC_TypeDef*)(L1P_BASE+L1P_IWC_OFFSET )))
#define L1P_IWC_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_IWC_OFFSET)))


/*--------*/
#define L1P_IWC_R_INV_COUNT_MASK        ((uint32_t)0x0000FFFF)
#define L1P_IWC_R_INV_COUNT_SHIFT         (0)

#define L1P_IWC_INV_COUNT_MASK          ((uint32_t)0x0000FFFF)
/*--------*/


/**********************************************************************************************
************************************** 5 INV ***********************************************
**********************************************************************************************/
#define L1P_INV                    (((L1P_INV_TypeDef*)(L1P_BASE+L1P_INV_OFFSET )))
#define L1P_INV_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_INV_OFFSET)))


/*--------*/
#define L1P_INV_R_I_MASK        ((uint32_t)0x00000001)
#define L1P_INV_R_I_SHIFT         (0)

#define L1P_INV_I_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 6-28 MPPA ***********************************************
**********************************************************************************************/
#define L1P_MPPA0                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA0_OFFSET )))
#define L1P_MPPA0_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA0_OFFSET)))
#define L1P_MPPA1                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA1_OFFSET )))
#define L1P_MPPA1_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA1_OFFSET)))
#define L1P_MPPA2                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA2_OFFSET )))
#define L1P_MPPA2_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA2_OFFSET)))
#define L1P_MPPA3                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA3_OFFSET )))
#define L1P_MPPA3_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA3_OFFSET)))
#define L1P_MPPA4                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA4_OFFSET )))
#define L1P_MPPA4_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA4_OFFSET)))
#define L1P_MPPA5                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA5_OFFSET )))
#define L1P_MPPA5_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA5_OFFSET)))
#define L1P_MPPA6                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA6_OFFSET )))
#define L1P_MPPA6_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA6_OFFSET)))
#define L1P_MPPA7                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA7_OFFSET )))
#define L1P_MPPA7_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA7_OFFSET)))
#define L1P_MPPA8                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA8_OFFSET )))
#define L1P_MPPA8_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA8_OFFSET)))
#define L1P_MPPA9                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA9_OFFSET )))
#define L1P_MPPA9_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA9_OFFSET)))
#define L1P_MPPA10                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA10_OFFSET )))
#define L1P_MPPA10_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA10_OFFSET)))
#define L1P_MPPA11                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA11_OFFSET )))
#define L1P_MPPA11_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA11_OFFSET)))
#define L1P_MPPA12                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA12_OFFSET )))
#define L1P_MPPA12_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA12_OFFSET)))
#define L1P_MPPA13                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA13_OFFSET )))
#define L1P_MPPA13_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA13_OFFSET)))
#define L1P_MPPA14                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA14_OFFSET )))
#define L1P_MPPA14_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA14_OFFSET)))
#define L1P_MPPA15                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA15_OFFSET )))
#define L1P_MPPA15_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA15_OFFSET)))
#define L1P_MPPA16                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA16_OFFSET )))
#define L1P_MPPA16_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA16_OFFSET)))
#define L1P_MPPA17                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA17_OFFSET )))
#define L1P_MPPA17_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA17_OFFSET)))
#define L1P_MPPA18                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA18_OFFSET )))
#define L1P_MPPA18_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA18_OFFSET)))
#define L1P_MPPA19                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA19_OFFSET )))
#define L1P_MPPA19_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA19_OFFSET)))
#define L1P_MPPA20                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA20_OFFSET )))
#define L1P_MPPA20_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA20_OFFSET)))
#define L1P_MPPA21                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA21_OFFSET )))
#define L1P_MPPA21_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA21_OFFSET)))
#define L1P_MPPA22                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA22_OFFSET )))
#define L1P_MPPA22_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA22_OFFSET)))
#define L1P_MPPA23                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA23_OFFSET )))
#define L1P_MPPA23_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA23_OFFSET)))
#define L1P_MPPA24                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA24_OFFSET )))
#define L1P_MPPA24_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA24_OFFSET)))
#define L1P_MPPA25                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA25_OFFSET )))
#define L1P_MPPA25_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA25_OFFSET)))
#define L1P_MPPA26                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA26_OFFSET )))
#define L1P_MPPA26_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA26_OFFSET)))
#define L1P_MPPA27                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA27_OFFSET )))
#define L1P_MPPA27_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA27_OFFSET)))
#define L1P_MPPA28                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA28_OFFSET )))
#define L1P_MPPA28_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA28_OFFSET)))
#define L1P_MPPA29                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA29_OFFSET )))
#define L1P_MPPA29_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA29_OFFSET)))
#define L1P_MPPA30                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA30_OFFSET )))
#define L1P_MPPA30_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA30_OFFSET)))
#define L1P_MPPA31                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA31_OFFSET )))
#define L1P_MPPA31_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA31_OFFSET)))

#define L1P_MPPA(n)                    (((L1P_MPPA_TypeDef*)(L1P_BASE+L1P_MPPA0_OFFSET +((n)*4) )))
#define L1P_MPPA_R(n)                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPPA0_OFFSET +((n)*4))))

/*--------*/
#define L1P_MPPA_R_UX_MASK        ((uint32_t)0x00000001)
#define L1P_MPPA_R_UX_SHIFT         (0)

#define L1P_MPPA_UX_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPPA_R_UW_MASK        ((uint32_t)0x00000002)
#define L1P_MPPA_R_UW_SHIFT         (1)

#define L1P_MPPA_UW_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPPA_R_UR_MASK        ((uint32_t)0x00000004)
#define L1P_MPPA_R_UR_SHIFT         (2)

#define L1P_MPPA_UR_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPPA_R_SX_MASK        ((uint32_t)0x00000008)
#define L1P_MPPA_R_SX_SHIFT         (3)

#define L1P_MPPA_SX_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPPA_R_SW_MASK        ((uint32_t)0x00000010)
#define L1P_MPPA_R_SW_SHIFT         (4)

#define L1P_MPPA_SW_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPPA_R_SR_MASK        ((uint32_t)0x00000020)
#define L1P_MPPA_R_SR_SHIFT         (5)

#define L1P_MPPA_SR_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPPA_R_LOCAL_MASK        ((uint32_t)0x00000100)
#define L1P_MPPA_R_LOCAL_SHIFT         (8)

#define L1P_MPPA_LOCAL_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPPA_R_AIDX_MASK        ((uint32_t)0x00000200)
#define L1P_MPPA_R_AIDX_SHIFT         (9)

#define L1P_MPPA_AIDX_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPPA_R_AID0_MASK        ((uint32_t)0x00000400)
#define L1P_MPPA_R_AID0_SHIFT         (10)

#define L1P_MPPA_AID0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPPA_R_AID1_MASK        ((uint32_t)0x00000800)
#define L1P_MPPA_R_AID1_SHIFT         (11)

#define L1P_MPPA_AID1_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPPA_R_AID2_MASK        ((uint32_t)0x00001000)
#define L1P_MPPA_R_AID2_SHIFT         (12)

#define L1P_MPPA_AID2_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPPA_R_AID3_MASK        ((uint32_t)0x00002000)
#define L1P_MPPA_R_AID3_SHIFT         (13)

#define L1P_MPPA_AID3_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPPA_R_AID4_MASK        ((uint32_t)0x00004000)
#define L1P_MPPA_R_AID4_SHIFT         (14)

#define L1P_MPPA_AID4_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPPA_R_AID5_MASK        ((uint32_t)0x00008000)
#define L1P_MPPA_R_AID5_SHIFT         (15)

#define L1P_MPPA_AID5_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 29-32 MPLK ***********************************************
**********************************************************************************************/
#define L1P_MPLK0                    (((L1P_MPLK_TypeDef*)(L1P_BASE+L1P_MPLK0_OFFSET )))
#define L1P_MPLK0_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPLK0_OFFSET)))
#define L1P_MPLK1                    (((L1P_MPLK_TypeDef*)(L1P_BASE+L1P_MPLK1_OFFSET )))
#define L1P_MPLK1_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPLK1_OFFSET)))
#define L1P_MPLK2                    (((L1P_MPLK_TypeDef*)(L1P_BASE+L1P_MPLK2_OFFSET )))
#define L1P_MPLK2_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPLK2_OFFSET)))
#define L1P_MPLK3                    (((L1P_MPLK_TypeDef*)(L1P_BASE+L1P_MPLK3_OFFSET )))
#define L1P_MPLK3_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPLK3_OFFSET)))

#define L1P_MPLK(n)                   (((L1P_MPLK_TypeDef*)(L1P_BASE+L1P_MPLK0_OFFSET +((n)*4))))
#define L1P_MPLK_R(n)                 (*((__IO uint32_t *)(L1P_BASE+L1P_MPLK0_OFFSET +((n)*4))))

/*--------*/
#define L1P_MPLK_R_LOCK_MASK        ((uint32_t)0xFFFFFFFF)
#define L1P_MPLK_R_LOCK_SHIFT         (0)

#define L1P_MPLK_LOCK_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


/**********************************************************************************************
************************************** 33 MPLKCMD ***********************************************
**********************************************************************************************/
#define L1P_MPLKCMD                    (((L1P_MPLKCMD_TypeDef*)(L1P_BASE+L1P_MPLKCMD_OFFSET )))
#define L1P_MPLKCMD_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPLKCMD_OFFSET)))

/*--------*/
#define L1P_MPLKCMD_R_UNLOCK_MASK        ((uint32_t)0x00000001)
#define L1P_MPLKCMD_R_UNLOCK_SHIFT         (0)

#define L1P_MPLKCMD_UNLOCK_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPLKCMD_R_LOCK_MASK        ((uint32_t)0x00000002)
#define L1P_MPLKCMD_R_LOCK_SHIFT         (1)

#define L1P_MPLKCMD_LOCK_MASK          ((uint32_t)0x00000002)
/*--------*/

/*--------*/
#define L1P_MPLKCMD_R_KEYR_MASK        ((uint32_t)0x00000004)
#define L1P_MPLKCMD_R_KEYR_SHIFT         (2)

#define L1P_MPLKCMD_KEYR_MASK          ((uint32_t)0x00000004)
/*--------*/


/**********************************************************************************************
************************************** 34 MPLKSTAT ***********************************************
**********************************************************************************************/
#define L1P_MPLKSTAT                    (((L1P_MPLKSTAT_TypeDef*)(L1P_BASE+L1P_MPLKSTAT_OFFSET )))
#define L1P_MPLKSTAT_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPLKSTAT_OFFSET)))

/*--------*/
#define L1P_MPLKSTAT_R_LK_MASK        ((uint32_t)0x00000001)
#define L1P_MPLKSTAT_R_LK_SHIFT         (0)

#define L1P_MPLKSTAT_LK_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 35 MPFAR ***********************************************
**********************************************************************************************/
#define L1P_MPFAR                    (((L1P_MPFAR_TypeDef*)(L1P_BASE+L1P_MPFAR_OFFSET )))
#define L1P_MPFAR_R                  (*((__I uint32_t *)(L1P_BASE+L1P_MPFAR_OFFSET)))

/*--------*/
#define L1P_MPFAR_R_ADDRESS_MASK        ((uint32_t)0xFFFFFFFF)
#define L1P_MPFAR_R_ADDRESS_SHIFT         (0)

#define L1P_MPFAR_ADDRESS_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


/**********************************************************************************************
************************************** 36 MPFSR ***********************************************
**********************************************************************************************/
#define L1P_MPFSR                    (((L1P_MPFSR_TypeDef*)(L1P_BASE+L1P_MPFSR_OFFSET )))
#define L1P_MPFSR_R                  (*((__I uint32_t *)(L1P_BASE+L1P_MPFSR_OFFSET)))

/*--------*/
#define L1P_MPFSR_R_UW_MASK        ((uint32_t)0x00000002)
#define L1P_MPFSR_R_UW_SHIFT         (1)

#define L1P_MPFSR_UW_MASK          ((uint32_t)0x00000002)
/*--------*/

/*--------*/
#define L1P_MPFSR_R_UR_MASK        ((uint32_t)0x00000004)
#define L1P_MPFSR_R_UR_SHIFT         (2)

#define L1P_MPFSR_UR_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPFSR_R_SW_MASK        ((uint32_t)0x00000010)
#define L1P_MPFSR_R_SW_SHIFT         (4)

#define L1P_MPFSR_SW_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPFSR_R_SR_MASK        ((uint32_t)0x00000020)
#define L1P_MPFSR_R_SR_SHIFT         (2)

#define L1P_MPFSR_SR_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPFSR_R_LOCAL_MASK        ((uint32_t)0x00000100)
#define L1P_MPFSR_R_LOCAL_SHIFT         (8)

#define L1P_MPFSR_LOCAL_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L1P_MPFSR_R_FID_MASK        ((uint32_t)0x0000FE00)
#define L1P_MPFSR_R_FID_SHIFT         (9)

#define L1P_MPFSR_FID_MASK          ((uint32_t)0x0000007F)
/*--------*/


/**********************************************************************************************
************************************** 36 MPFCLR ***********************************************
**********************************************************************************************/
#define L1P_MPFCLR                    (((L1P_MPFCLR_TypeDef*)(L1P_BASE+L1P_MPFCLR_OFFSET )))
#define L1P_MPFCLR_R                  (*((__IO uint32_t *)(L1P_BASE+L1P_MPFCLR_OFFSET)))

/*--------*/
#define L1P_MPFCLR_R_MPFCLR_MASK        ((uint32_t)0x00000001)
#define L1P_MPFCLR_R_MPFCLR_SHIFT         (0)

#define L1P_MPFCLR_MPFCLR_MASK          ((uint32_t)0x00000001)
/*--------*/


#endif /* INCLUDE_L1P_H_ */

