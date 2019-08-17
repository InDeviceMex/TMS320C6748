/*
 * DDR2.h
 *
 *  Created on: 21/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_DDR2_H_
#define INCLUDE_DDR2_H_



#include "Core.h"
#include "SYSCFG.h"
#include "PSC.h"
#include <stdint.h>

#define DDR2_BASE            ((uint32_t)0xB0000000)



typedef __IO struct
{
    __I uint32_t REV       :32;
}DDR2_REVID_TypeDef;

typedef __IO struct
{
         uint32_t reserved0  :2;
    __IO uint32_t PHYRDY     :1;
         uint32_t reserved1  :27;
    __IO uint32_t DUALCLK    :1;
         uint32_t reserved2  :1;
}DDR2_SDRSTAT_TypeDef;

typedef __IO struct
{
    __IO uint32_t PAGESIZE   :3;
         uint32_t reserved0  :1;
    __IO uint32_t IBANK      :3;
         uint32_t reserved1  :2;
    __IO uint32_t CL         :3;
         uint32_t reserved2  :2;
    __IO uint32_t NM         :1;
    __IO uint32_t TIMUNLOCK  :1;
    __IO uint32_t SDRAMEN    :1;
    __IO uint32_t DDREN      :1;
    __IO uint32_t DDRDRIVE0  :1;
    __IO uint32_t DDRDLL_DIS :1;
    __IO uint32_t DDR2EN     :1;
    __IO uint32_t DDR2TERM0  :1;
    __IO uint32_t DDR2DDQS   :1;
    __IO uint32_t BOOTUNLOCK :1;
    __IO uint32_t DDRDRIVE1  :1;
    __IO uint32_t MSDRAMEN   :1;
    __IO uint32_t IBANK_POS  :1;
    __IO uint32_t DDR2TERM1  :1;
         uint32_t reserved3  :4;
}DDR2_SDCR_TypeDef;

typedef __IO struct
{
    __IO uint32_t RR         :16;
         uint32_t reserved0  :7;
    __IO uint32_t SR_PD      :1;
         uint32_t reserved1  :6;
    __IO uint32_t MCLKSTOPEN :1;
    __IO uint32_t LPMODEN    :1;
}DDR2_SDRCR_TypeDef;

typedef __IO struct
{
    __IO uint32_t T_WTR      :2;
         uint32_t reserved0  :1;
    __IO uint32_t T_RRD      :3;
    __IO uint32_t T_RC       :5;
    __IO uint32_t T_RAS      :5;
    __IO uint32_t T_WR       :3;
    __IO uint32_t T_RCD      :3;
    __IO uint32_t T_RP       :3;
    __IO uint32_t T_RFC      :7;
}DDR2_SDTIMR1_TypeDef;

typedef __IO struct
{
    __IO uint32_t T_CKE      :5;
    __IO uint32_t T_RTP      :3;
    __IO uint32_t T_XSRD     :8;
    __IO uint32_t T_XSNR     :7;
    __IO uint32_t T_ODT      :2;
    __IO uint32_t T_XP       :2;
    __IO uint32_t T_RASMAX   :4;
         uint32_t reserved0  :1;
}DDR2_SDTIMR2_TypeDef;

typedef __IO struct
{
    __IO uint32_t ROWSIZE    :3;
         uint32_t reserved0  :13;
    __IO uint32_t PASR       :3;
         uint32_t reserved1  :13;
}DDR2_SDCR2_TypeDef;

typedef __IO struct
{
    __IO uint32_t PR_OLD_COUNT    :8;
         uint32_t reserved0  :24;
}DDR2_PBBPR_TypeDef;

typedef __IO struct
{
    __IO uint32_t Counter1    :32;
}DDR2_PC1_TypeDef;

typedef __IO struct
{
    __IO uint32_t Counter2    :32;
}DDR2_PC2_TypeDef;

typedef __IO struct
{
    __IO uint32_t CNTR1_CFG         :4;
         uint32_t reserved0         :10;
    __IO uint32_t CNTR1_REGION_EN   :1;
    __IO uint32_t CNTR1_MSTID_EN    :1;
    __IO uint32_t CNTR2_CFG         :4;
         uint32_t reserved1         :10;
    __IO uint32_t CNTR2_REGION_EN   :1;
    __IO uint32_t CNTR2_MSTID_EN    :1;
}DDR2_PCC_TypeDef;

typedef __IO struct
{
    __IO uint32_t REGION_SEL1       :4;
         uint32_t reserved0         :4;
    __IO uint32_t MST_ID1           :8;
    __IO uint32_t REGION_SEL2       :4;
         uint32_t reserved1         :4;
    __IO uint32_t MST_ID2           :8;
}DDR2_PCMRS_TypeDef;

typedef __IO struct
{
    __IO uint32_t TOTAL_TIME       :32;
}DDR2_PCT_TypeDef;

typedef __IO struct
{
         uint32_t reserved0         :10;
    __IO uint32_t RESET_PHY         :1;
         uint32_t reserved1         :21;
}DDR2_DRPYRCR_TypeDef;

typedef __IO struct
{
         uint32_t reserved0         :2;
    __IO uint32_t LT                :1;
         uint32_t reserved1         :29;
}DDR2_IRR_TypeDef;

typedef __IO struct
{
         uint32_t reserved0         :2;
    __IO uint32_t LTM                :1;
         uint32_t reserved1         :29;
}DDR2_IMR_TypeDef;

typedef __IO struct
{
         uint32_t reserved0         :2;
    __IO uint32_t LTMSET                :1;
         uint32_t reserved1         :29;
}DDR2_IMSR_TypeDef;

typedef __IO struct
{
         uint32_t reserved0         :2;
    __IO uint32_t LTMCLR                :1;
         uint32_t reserved1         :29;
}DDR2_IMCR_TypeDef;

typedef __IO struct
{
    __IO uint32_t RL                :3;
         uint32_t reserved0         :3;
    __IO uint32_t PWRDNEN           :1;
    __IO uint32_t EXT_STRBEN        :1;
         uint32_t reserved1         :4;
    __IO uint32_t CONFIG_DLL_MODE   :3;
         uint32_t reserved2         :17;
}DDR2_DRPYC1R_TypeDef;



typedef struct  {
    union
    {
        __IO uint32_t           REVID;
        DDR2_REVID_TypeDef    REVID_Bit;
    };
    union
    {
        __IO uint32_t           SDRSTAT;
        DDR2_SDRSTAT_TypeDef    SDRSTAT_Bit;
    };
    union
    {
        __IO uint32_t           SDCR;
        DDR2_SDCR_TypeDef       SDCR_Bit;
    };
    union
    {
        __IO uint32_t            SDRCR;
        DDR2_SDRCR_TypeDef       SDRCR_Bit;
    };
    union
    {
        __IO uint32_t            SDTIMR1;
        DDR2_SDTIMR1_TypeDef     SDTIMR1_Bit;
    };
    union
    {
        __IO uint32_t            SDTIMR2;
        DDR2_SDTIMR2_TypeDef     SDTIMR2_Bit;
    };
    uint32_t reserved0[1];
    union
    {
        __IO uint32_t            SDCR2;
        DDR2_SDCR2_TypeDef       SDCR2_Bit;
    };
    union
    {
        __IO uint32_t            PBBPR;
        DDR2_PBBPR_TypeDef       PBBPR_Bit;
    };
    uint32_t reserved1[7];
    union
    {
        __IO uint32_t            PC1;
        DDR2_PC1_TypeDef         PC1_Bit;
    };
    union
    {
        __IO uint32_t            PC2;
        DDR2_PC2_TypeDef         PC2_Bit;
    };
    union
    {
        __IO uint32_t            PCC;
        DDR2_PCC_TypeDef         PCC_Bit;
    };
    union
    {
        __IO uint32_t            PCMRS;
        DDR2_PCMRS_TypeDef       PCMRS_Bit;
    };
    union
    {
        __IO uint32_t            PCT;
        DDR2_PCT_TypeDef         PCT_Bit;
    };
    uint32_t reserved2[27];
    union
    {
        __IO uint32_t            IRR;
        DDR2_IRR_TypeDef         IRR_Bit;
    };

    union
    {
        __IO uint32_t            IMR;
        DDR2_IMR_TypeDef         IMR_Bit;
    };
    union
    {
        __IO uint32_t            IMSR;
        DDR2_IMSR_TypeDef        IMSR_Bit;
    };
    union
    {
        __IO uint32_t            IMCR;
        DDR2_IMCR_TypeDef        IMCR_Bit;
    };
    uint32_t reserved3[5];
    union
    {
        __IO uint32_t            DRPYC1R;
        DDR2_DRPYC1R_TypeDef     DRPYC1R_Bit;
    };
} DDR2_TypeDef;

#define DDR2            (((DDR2_TypeDef*)(DDR2_BASE)))
#define DDR2_R(offset)  (*((__IO uint32_t *)(DDR2_BASE+offset)))


#define DDR2_REVID_OFFSET         ((uint32_t)0x0000)
#define DDR2_SDRSTAT_OFFSET       ((uint32_t)0x0004)
#define DDR2_SDCR_OFFSET          ((uint32_t)0x0008)
#define DDR2_SDRCR_OFFSET         ((uint32_t)0x000C)
#define DDR2_SDTIMR1_OFFSET       ((uint32_t)0x0010)
#define DDR2_SDTIMR2_OFFSET       ((uint32_t)0x0014)
#define DDR2_SDCR2_OFFSET         ((uint32_t)0x001C)
#define DDR2_PBBPR_OFFSET         ((uint32_t)0x0020)
#define DDR2_PC1_OFFSET           ((uint32_t)0x0040)
#define DDR2_PC2_OFFSET           ((uint32_t)0x0044)
#define DDR2_PCC_OFFSET           ((uint32_t)0x0048)
#define DDR2_PCMRS_OFFSET         ((uint32_t)0x004C)
#define DDR2_PCT_OFFSET           ((uint32_t)0x0050)
#define DDR2_DRPYRCR_OFFSET       ((uint32_t)0x0060)
#define DDR2_IRR_OFFSET           ((uint32_t)0x00C0)
#define DDR2_IMR_OFFSET           ((uint32_t)0x00C4)
#define DDR2_IMSR_OFFSET          ((uint32_t)0x00C8)
#define DDR2_IMCR_OFFSET          ((uint32_t)0x00CC)
#define DDR2_DRPYC1R_OFFSET       ((uint32_t)0x00E4)



/**********************************************************************************************
************************************** 1 REVID ***********************************************
**********************************************************************************************/
#define DDR2_REVID                    (((DDR2_REVID_TypeDef*)(DDR2_BASE+DDR2_REVID_OFFSET )))
#define DDR2_REVID_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_REVID_OFFSET)))

/*--------*/
#define DDR2_REVID_R_REV_MASK        ((uint32_t)0xFFFFFFFF)
#define DDR2_REVID_R_REV_SHIFT         (0)

#define DDR2_REVID_REV_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 2 SDRSTAT ***********************************************
**********************************************************************************************/
#define DDR2_SDRSTAT                    (((DDR2_SDRSTAT_TypeDef*)(DDR2_BASE+DDR2_SDRSTAT_OFFSET )))
#define DDR2_SDRSTAT_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_SDRSTAT_OFFSET)))

/*--------*/
#define DDR2_SDRSTAT_R_PHYRDY_MASK        ((uint32_t)0x00000004)
#define DDR2_SDRSTAT_R_PHYRDY_SHIFT       (2)

#define DDR2_SDRSTAT_PHYRDY_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDRSTAT_R_DUALCLK_MASK        ((uint32_t)0x40000000)
#define DDR2_SDRSTAT_R_DUALCLK_SHIFT       (30)

#define DDR2_SDRSTAT_DUALCLK_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 3 SDCR ***********************************************
**********************************************************************************************/
#define DDR2_SDCR                    (((DDR2_SDCR_TypeDef*)(DDR2_BASE+DDR2_SDCR_OFFSET )))
#define DDR2_SDCR_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_SDCR_OFFSET)))

/*--------*/
#define DDR2_SDCR_R_PAGESIZE_MASK        ((uint32_t)0x00000007)
#define DDR2_SDCR_R_PAGESIZE_SHIFT       (0)

#define DDR2_SDCR_PAGESIZE_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_IBANK_MASK        ((uint32_t)0x00000070)
#define DDR2_SDCR_R_IBANK_SHIFT       (4)

#define DDR2_SDCR_IBANK_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_CL_MASK        ((uint32_t)0x00000E00)
#define DDR2_SDCR_R_CL_SHIFT       (9)

#define DDR2_SDCR_CL_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_NM_MASK        ((uint32_t)0x00004000)
#define DDR2_SDCR_R_NM_SHIFT       (14)

#define DDR2_SDCR_NM_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_TIMUNLOCK_MASK        ((uint32_t)0x00008000)
#define DDR2_SDCR_R_TIMUNLOCK_SHIFT       (15)

#define DDR2_SDCR_TIMUNLOCK_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_SDRAMEN_MASK        ((uint32_t)0x00010000)
#define DDR2_SDCR_R_SDRAMEN_SHIFT       (16)

#define DDR2_SDCR_SDRAMEN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_DDREN_MASK        ((uint32_t)0x00020000)
#define DDR2_SDCR_R_DDREN_SHIFT       (17)

#define DDR2_SDCR_DDREN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_DDRDRIVE0_MASK        ((uint32_t)0x00040000)
#define DDR2_SDCR_R_DDRDRIVE0_SHIFT       (18)

#define DDR2_SDCR_DDRDRIVE0_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_DDRDLL_DIS_MASK        ((uint32_t)0x00080000)
#define DDR2_SDCR_R_DDRDLL_DIS_SHIFT       (19)

#define DDR2_SDCR_DDRDLL_DIS_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_DDR2EN_MASK        ((uint32_t)0x00100000)
#define DDR2_SDCR_R_DDR2EN_SHIFT       (20)

#define DDR2_SDCR_DDR2EN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_DDR2TERM0_MASK        ((uint32_t)0x00200000)
#define DDR2_SDCR_R_DDR2TERM0_SHIFT       (21)

#define DDR2_SDCR_DDR2TERM0_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_DDR2DDQS_MASK        ((uint32_t)0x00400000)
#define DDR2_SDCR_R_DDR2DDQS_SHIFT       (22)

#define DDR2_SDCR_DDR2DDQS_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_BOOTUNLOCK_MASK        ((uint32_t)0x00800000)
#define DDR2_SDCR_R_BOOTUNLOCK_SHIFT       (23)

#define DDR2_SDCR_BOOTUNLOCK_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_DDRDRIVE1_MASK        ((uint32_t)0x01000000)
#define DDR2_SDCR_R_DDRDRIVE1_SHIFT       (24)

#define DDR2_SDCR_DDRDRIVE1_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_MSDRAMEN_MASK        ((uint32_t)0x02000000)
#define DDR2_SDCR_R_MSDRAMEN_SHIFT       (25)

#define DDR2_SDCR_MSDRAMEN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_IBANK_POS_MASK        ((uint32_t)0x04000000)
#define DDR2_SDCR_R_IBANK_POS_SHIFT       (26)

#define DDR2_SDCR_IBANK_POS_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDCR_R_DDR2TERM1_MASK        ((uint32_t)0x08000000)
#define DDR2_SDCR_R_DDR2TERM1_SHIFT       (27)

#define DDR2_SDCR_DDR2TERM1_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 4 SDRCR ***********************************************
**********************************************************************************************/
#define DDR2_SDRCR                    (((DDR2_SDRCR_TypeDef*)(DDR2_BASE+DDR2_SDRCR_OFFSET )))
#define DDR2_SDRCR_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_SDRCR_OFFSET)))

/*--------*/
#define DDR2_SDRCR_R_SR_PD_MASK        ((uint32_t)0x00800000)
#define DDR2_SDRCR_R_SR_PD_SHIFT       (23)

#define DDR2_SDRCR_SR_PD_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDRCR_R_MCLKSTOPEN_MASK        ((uint32_t)0x40000000)
#define DDR2_SDRCR_R_MCLKSTOPEN_SHIFT       (30)

#define DDR2_SDRCR_MCLKSTOPEN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_SDRCR_R_LPMODEN_MASK        ((uint32_t)0x80000000)
#define DDR2_SDRCR_R_LPMODEN_SHIFT       (31)

#define DDR2_SDRCR_LPMODEN_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 5 SDTIMR1 ***********************************************
**********************************************************************************************/
#define DDR2_SDTIMR1                    (((DDR2_SDTIMR1_TypeDef*)(DDR2_BASE+DDR2_SDTIMR1_OFFSET )))
#define DDR2_SDTIMR1_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_SDTIMR1_OFFSET)))

/*--------*/
#define DDR2_SDTIMR1_R_T_WTR_MASK        ((uint32_t)0x00000003)
#define DDR2_SDTIMR1_R_T_WTR_SHIFT       (0)

#define DDR2_SDTIMR1_T_WTR_MASK          ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define DDR2_SDTIMR1_R_T_RRD_MASK        ((uint32_t)0x00000038)
#define DDR2_SDTIMR1_R_T_RRD_SHIFT       (3)

#define DDR2_SDTIMR1_T_RRD_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define DDR2_SDTIMR1_R_T_RC_MASK        ((uint32_t)0x000007C0)
#define DDR2_SDTIMR1_R_T_RC_SHIFT       (6)

#define DDR2_SDTIMR1_T_RC_MASK          ((uint32_t)0x0000001F)
/*--------*/
/*--------*/
#define DDR2_SDTIMR1_R_T_RAS_MASK        ((uint32_t)0x0000F800)
#define DDR2_SDTIMR1_R_T_RAS_SHIFT       (11)

#define DDR2_SDTIMR1_T_RAS_MASK          ((uint32_t)0x0000001F)
/*--------*/
/*--------*/
#define DDR2_SDTIMR1_R_T_WR_MASK        ((uint32_t)0x00070000)
#define DDR2_SDTIMR1_R_T_WR_SHIFT       (16)

#define DDR2_SDTIMR1_T_WR_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define DDR2_SDTIMR1_R_T_RCD_MASK        ((uint32_t)0x00380000)
#define DDR2_SDTIMR1_R_T_RCD_SHIFT       (19)

#define DDR2_SDTIMR1_T_RCD_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define DDR2_SDTIMR1_R_T_RP_MASK        ((uint32_t)0x01C00000)
#define DDR2_SDTIMR1_R_T_RP_SHIFT       (22)

#define DDR2_SDTIMR1_T_RP_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define DDR2_SDTIMR1_R_T_RFC_MASK        ((uint32_t)0xFE000000)
#define DDR2_SDTIMR1_R_T_RFC_SHIFT       (25)

#define DDR2_SDTIMR1_T_RFC_MASK          ((uint32_t)0x0000007F)
/*--------*/

/**********************************************************************************************
************************************** 6 SDTIMR2 ***********************************************
**********************************************************************************************/
#define DDR2_SDTIMR2                    (((DDR2_SDTIMR2_TypeDef*)(DDR2_BASE+DDR2_SDTIMR2_OFFSET )))
#define DDR2_SDTIMR2_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_SDTIMR2_OFFSET)))

/*--------*/
#define DDR2_SDTIMR2_R_T_CKE_MASK        ((uint32_t)0x0000001F)
#define DDR2_SDTIMR2_R_T_CKE_SHIFT       (0)

#define DDR2_SDTIMR2_T_CKE_MASK          ((uint32_t)0x0000001F)
/*--------*/
/*--------*/
#define DDR2_SDTIMR2_R_T_RTP_MASK        ((uint32_t)0x000000E0)
#define DDR2_SDTIMR2_R_T_RTP_SHIFT       (5)

#define DDR2_SDTIMR2_T_RTP_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define DDR2_SDTIMR2_R_T_XSRD_MASK        ((uint32_t)0x000FF00)
#define DDR2_SDTIMR2_R_T_XSRD_SHIFT       (8)

#define DDR2_SDTIMR2_T_XSRD_MASK          ((uint32_t)0x000000FF)
/*--------*/
/*--------*/
#define DDR2_SDTIMR2_R_T_XSNR_MASK        ((uint32_t)0x007F0000)
#define DDR2_SDTIMR2_R_T_XSNR_SHIFT       (16)

#define DDR2_SDTIMR2_T_XSNR_MASK          ((uint32_t)0x0000007F)
/*--------*/
/*--------*/
#define DDR2_SDTIMR2_R_T_ODT_MASK        ((uint32_t)0x01800000)
#define DDR2_SDTIMR2_R_T_ODT_SHIFT       (23)

#define DDR2_SDTIMR2_T_ODT_MASK          ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define DDR2_SDTIMR2_R_T_XP_MASK        ((uint32_t)0x06000000)
#define DDR2_SDTIMR2_R_T_XP_SHIFT       (25)

#define DDR2_SDTIMR2_T_XP_MASK          ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define DDR2_SDTIMR2_R_T_RASMAX_MASK        ((uint32_t)0x78000000)
#define DDR2_SDTIMR2_R_T_RASMAX_SHIFT       (27)

#define DDR2_SDTIMR2_T_RASMAX_MASK          ((uint32_t)0x0000000F)
/*--------*/

/**********************************************************************************************
************************************** 7 SDCR2 ***********************************************
**********************************************************************************************/
#define DDR2_SDCR2                    (((DDR2_SDCR2_TypeDef*)(DDR2_BASE+DDR2_SDCR2_OFFSET )))
#define DDR2_SDCR2_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_SDCR2_OFFSET)))

/*--------*/
#define DDR2_SDCR2_R_ROWSIZE_MASK        ((uint32_t)0x00000007)
#define DDR2_SDCR2_R_ROWSIZE_SHIFT       (0)

#define DDR2_SDCR2_ROWSIZE_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define DDR2_SDCR2_R_PASR_MASK        ((uint32_t)0x00070000)
#define DDR2_SDCR2_R_PASR_SHIFT       (16)

#define DDR2_SDCR2_PASR_MASK          ((uint32_t)0x00000007)
/*--------*/

/**********************************************************************************************
************************************** 8 PBBPR ***********************************************
**********************************************************************************************/
#define DDR2_PBBPR                    (((DDR2_PBBPR_TypeDef*)(DDR2_BASE+DDR2_PBBPR_OFFSET )))
#define DDR2_PBBPR_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_PBBPR_OFFSET)))

/*--------*/
#define DDR2_PBBPR_R_PR_OLD_COUNT_MASK        ((uint32_t)0x000000FF)
#define DDR2_PBBPR_R_PR_OLD_COUNT_SHIFT       (0)

#define DDR2_PBBPR_PR_OLD_COUNT_MASK          ((uint32_t)0x000000FF)
/*--------*/

/**********************************************************************************************
************************************** 9 PC1 ***********************************************
**********************************************************************************************/
#define DDR2_PC1                    (((DDR2_PC1_TypeDef*)(DDR2_BASE+DDR2_PC1_OFFSET )))
#define DDR2_PC1_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_PC1_OFFSET)))

/*--------*/
#define DDR2_PC1_R_Counter1_MASK        ((uint32_t)0xFFFFFFFF)
#define DDR2_PC1_R_Counter1_SHIFT       (0)

#define DDR2_PC1_Counter1_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 10 PC2 ***********************************************
**********************************************************************************************/
#define DDR2_PC2                    (((DDR2_PC2_TypeDef*)(DDR2_BASE+DDR2_PC2_OFFSET )))
#define DDR2_PC2_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_PC2_OFFSET)))

/*--------*/
#define DDR2_PC2_R_Counter2_MASK        ((uint32_t)0xFFFFFFFF)
#define DDR2_PC2_R_Counter2_SHIFT       (0)

#define DDR2_PC2_Counter2_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 11 PCC ***********************************************
**********************************************************************************************/
#define DDR2_PCC                    (((DDR2_PCC_TypeDef*)(DDR2_BASE+DDR2_PCC_OFFSET )))
#define DDR2_PCC_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_PCC_OFFSET)))

/*--------*/
#define DDR2_PCC_R_CNTR1_CFG_MASK        ((uint32_t)0x0000000F)
#define DDR2_PCC_R_CNTR1_CFG_SHIFT       (0)

#define DDR2_PCC_CNTR1_CFG_MASK          ((uint32_t)0x0000000F)
/*--------*/
/*--------*/
#define DDR2_PCC_R_CNTR1_REGION_EN_MASK        ((uint32_t)0x00004000)
#define DDR2_PCC_R_CNTR1_REGION_EN_SHIFT       (14)

#define DDR2_PCC_CNTR1_REGION_EN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_PCC_R_CNTR1_MSTID_EN_MASK        ((uint32_t)0x00008000)
#define DDR2_PCC_R_CNTR1_MSTID_EN_SHIFT       (15)

#define DDR2_PCC_CNTR1_MSTID_EN_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define DDR2_PCC_R_CNTR2_CFG_MASK        ((uint32_t)0x000F0000)
#define DDR2_PCC_R_CNTR2_CFG_SHIFT       (16)

#define DDR2_PCC_CNTR2_CFG_MASK          ((uint32_t)0x0000000F)
/*--------*/
/*--------*/
#define DDR2_PCC_R_CNTR2_REGION_EN_MASK        ((uint32_t)0x40000000)
#define DDR2_PCC_R_CNTR2_REGION_EN_SHIFT       (30)

#define DDR2_PCC_CNTR2_REGION_EN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_PCC_R_CNTR2_MSTID_EN_MASK        ((uint32_t)0x80000000)
#define DDR2_PCC_R_CNTR2_MSTID_EN_SHIFT       (31)

#define DDR2_PCC_CNTR2_MSTID_EN_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 12 PCMRS ***********************************************
**********************************************************************************************/
#define DDR2_PCMRS                    (((DDR2_PCMRS_TypeDef*)(DDR2_BASE+DDR2_PCMRS_OFFSET )))
#define DDR2_PCMRS_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_PCMRS_OFFSET)))

/*--------*/
#define DDR2_PCMRS_R_REGION_SEL1_MASK        ((uint32_t)0x0000000F)
#define DDR2_PCMRS_R_REGION_SEL1_SHIFT       (0)

#define DDR2_PCMRS_REGION_SEL1_MASK          ((uint32_t)0x0000000F)
/*--------*/
/*--------*/
#define DDR2_PCMRS_R_MST_ID1_MASK        ((uint32_t)0x0000FF00)
#define DDR2_PCMRS_R_MST_ID1_SHIFT       (8)

#define DDR2_PCMRS_MST_ID1_MASK          ((uint32_t)0x000000FF)
/*--------*/

/*--------*/
#define DDR2_PCMRS_R_REGION_SEL2_MASK        ((uint32_t)0x000F0000)
#define DDR2_PCMRS_R_REGION_SEL2_SHIFT       (16)

#define DDR2_PCMRS_REGION_SEL2_MASK          ((uint32_t)0x0000000F)
/*--------*/
/*--------*/
#define DDR2_PCMRS_R_MST_ID2_MASK        ((uint32_t)0xFF000000)
#define DDR2_PCMRS_R_MST_ID2_SHIFT       (24)

#define DDR2_PCMRS_MST_ID2_MASK          ((uint32_t)0x000000FF)
/*--------*/

/**********************************************************************************************
************************************** 13 PCT ***********************************************
**********************************************************************************************/
#define DDR2_PCT                    (((DDR2_PCT_TypeDef*)(DDR2_BASE+DDR2_PCT_OFFSET )))
#define DDR2_PCT_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_PCT_OFFSET)))

/*--------*/
#define DDR2_PCT_R_TOTAL_TIME_MASK        ((uint32_t)0xFFFFFFFF)
#define DDR2_PCT_R_TOTAL_TIME_SHIFT       (0)

#define DDR2_PCT_TOTAL_TIME_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 14 DRPYRCR ***********************************************
**********************************************************************************************/
#define DDR2_DRPYRCR                    (((DDR2_DRPYRCR_TypeDef*)(DDR2_BASE+DDR2_DRPYRCR_OFFSET )))
#define DDR2_DRPYRCR_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_DRPYRCR_OFFSET)))

/*--------*/
#define DDR2_DRPYRCR_R_RESET_PHY_MASK        ((uint32_t)0x00000400)
#define DDR2_DRPYRCR_R_RESET_PHY_SHIFT       (10)

#define DDR2_DRPYRCR_RESET_PHY_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 15 IRR ***********************************************
**********************************************************************************************/
#define DDR2_IRR                    (((DDR2_IRR_TypeDef*)(DDR2_BASE+DDR2_IRR_OFFSET )))
#define DDR2_IRR_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_IRR_OFFSET)))

/*--------*/
#define DDR2_IRR_R_LT_MASK        ((uint32_t)0x00000004)
#define DDR2_IRR_R_LT_SHIFT       (2)

#define DDR2_IRR_LT_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 16 IMR ***********************************************
**********************************************************************************************/
#define DDR2_IMR                    (((DDR2_IMR_TypeDef*)(DDR2_BASE+DDR2_IMR_OFFSET )))
#define DDR2_IMR_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_IMR_OFFSET)))

/*--------*/
#define DDR2_IMR_R_LTM_MASK        ((uint32_t)0x00000004)
#define DDR2_IMR_R_LTM_SHIFT       (2)

#define DDR2_IMR_LTM_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 17 IMSR ***********************************************
**********************************************************************************************/
#define DDR2_IMSR                    (((DDR2_IMSR_TypeDef*)(DDR2_BASE+DDR2_IMSR_OFFSET )))
#define DDR2_IMSR_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_IMSR_OFFSET)))

/*--------*/
#define DDR2_IMSR_R_LTMSET_MASK        ((uint32_t)0x00000004)
#define DDR2_IMSR_R_LTMSET_SHIFT       (2)

#define DDR2_IMSR_LTMSET_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 18 IMCR ***********************************************
**********************************************************************************************/
#define DDR2_IMCR                    (((DDR2_IMCR_TypeDef*)(DDR2_BASE+DDR2_IMCR_OFFSET )))
#define DDR2_IMCR_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_IMCR_OFFSET)))

/*--------*/
#define DDR2_IMCR_R_LTMCLR_MASK        ((uint32_t)0x00000004)
#define DDR2_IMCR_R_LTMCLR_SHIFT       (2)

#define DDR2_IMCR_LTMCLR_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 19 DRPYC1R ***********************************************
**********************************************************************************************/
#define DDR2_DRPYC1R                    (((DDR2_DRPYC1R_TypeDef*)(DDR2_BASE+DDR2_DRPYC1R_OFFSET )))
#define DDR2_DRPYC1R_R                  (*((__IO uint32_t *)(DDR2_BASE+DDR2_DRPYC1R_OFFSET)))

/*--------*/
#define DDR2_DRPYC1R_R_RL_MASK        ((uint32_t)0x00000007)
#define DDR2_DRPYC1R_R_RL_SHIFT       (0)

#define DDR2_DRPYC1R_RL_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define DDR2_DRPYC1R_R_PWRDNEN_MASK        ((uint32_t)0x00000040)
#define DDR2_DRPYC1R_R_PWRDNEN_SHIFT       (6)

#define DDR2_DRPYC1R_PWRDNEN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_DRPYC1R_R_EXT_STRBEN_MASK        ((uint32_t)0x00000080)
#define DDR2_DRPYC1R_R_EXT_STRBEN_SHIFT       (7)

#define DDR2_DRPYC1R_EXT_STRBEN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define DDR2_DRPYC1R_R_CONFIG_DLL_MODE_MASK        ((uint32_t)0x00007000)
#define DDR2_DRPYC1R_R_CONFIG_DLL_MODE_SHIFT       (12)

#define DDR2_DRPYC1R_CONFIG_DLL_MODE_MASK          ((uint32_t)0x00000007)
/*--------*/


typedef enum
{
    DDR2_enOK = 0,
    DDR2_enERROR ,
}Ddr2_nStatus;

#pragma FUNC_ALWAYS_INLINE( DDR2__enInit)
extern Ddr2_nStatus DDR2__enInit(void);
#endif /* INCLUDE_DDR2_H_ */
