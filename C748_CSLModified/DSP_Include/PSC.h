/*
 * PSC.h
 *
 *  Created on: 19/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_PSC_H_
#define INCLUDE_PSC_H_

#include "SYSCFG.h"
#include "Core.h"
#include <stdint.h>

#define PSC0_BASE            ((uint32_t)0x01C10000)
#define PSC1_BASE            ((uint32_t)0x01E27000)


typedef __IO struct
{
    __I uint32_t REV       :32;
}PSC_REVID_TypeDef;

typedef __IO struct
{
    __IO uint32_t ALLEV     :1;
         uint32_t reserved0 :31;
}PSC_INTEVAL_TypeDef;

typedef __IO struct
{
         uint32_t reserved0 :15;
    __IO uint32_t M15       :1;
         uint32_t reserved1 :16;
}PSC0_MERRPR0_TypeDef;

typedef __IO struct
{
         uint32_t reserved0 :32;
}PSC1_MERRPR0_TypeDef;

typedef __IO struct
{
         uint32_t reserved0 :15;
    __IO uint32_t M15       :1;
         uint32_t reserved1 :16;
}PSC0_MERRCR0_TypeDef;

typedef __IO struct
{
         uint32_t reserved0 :32;
}PSC1_MERRCR0_TypeDef;

typedef __IO struct
{
         uint32_t reserved0 :1;
    __IO uint32_t P1        :1;
         uint32_t reserved1 :30;
}PSC_PERRPR_TypeDef;

typedef __IO struct
{
         uint32_t reserved0 :1;
    __IO uint32_t P1        :1;
         uint32_t reserved1 :30;
}PSC_PERRCR_TypeDef;

typedef __IO struct
{
    __IO uint32_t G00        :1;
    __IO uint32_t G01        :1;
         uint32_t reserved0 :30;
}PSC_PTCMD_TypeDef;

typedef __IO struct
{
    __IO uint32_t GOSTAT0        :1;
    __IO uint32_t GOSTAT1        :1;
         uint32_t reserved0 :30;
}PSC_PTSTAT_TypeDef;

typedef __IO struct
{
    __IO uint32_t STATE         :5;
         uint32_t reserved0     :3;
    __IO uint32_t POR           :1;
    __IO uint32_t PORDONE       :1;
         uint32_t reserved1     :1;
    __IO uint32_t EMUIHB        :1;
         uint32_t reserved2     :20;
}PSC_PDSTAT_TypeDef;

typedef __IO struct
{
    __IO uint32_t NEXT          :1;
         uint32_t reserved0     :8;
    __IO uint32_t EMUIHBIE      :1;
         uint32_t reserved1     :2;
    __IO uint32_t PDMODE        :4;
    __IO uint32_t WAKECNT       :8;
         uint32_t reserved2     :8;
}PSC_PDCTL_TypeDef;

typedef __IO struct
{
    __IO uint32_t ALWAYSON      :1;
    __IO uint32_t RAM_PSM       :1;
    __IO uint32_t ICEPICK       :1;
    __IO uint32_t PD_LOCK       :1;
         uint32_t reserved0     :28;
}PSC_PDCFG_TypeDef;


typedef __IO struct
{
    __IO uint32_t STATE         :6;
         uint32_t reserved0     :2;
    __IO uint32_t LRST          :1;
    __IO uint32_t LRSTDONE      :1;
    __IO uint32_t MRST          :1;
         uint32_t reserved1     :1;
    __IO uint32_t MCKOUT        :1;
         uint32_t reserved2     :3;
    __IO uint32_t EMURST        :1;
    __IO uint32_t EMUIHB        :1;
         uint32_t reserved3     :14;
}PSC_MDSTAT_TypeDef;



typedef __IO struct
{
    __IO uint32_t NEXT          :3;
         uint32_t reserved0     :5;
    __IO uint32_t LRST          :1;
    __IO uint32_t EMURSTIE      :1;
    __IO uint32_t EMUIHBIE      :1;
         uint32_t reserved1     :5;
         uint32_t reserved2     :15;
    __IO uint32_t FORCE         :1;
}PSC0_MDCTL_TypeDef;

typedef __IO struct
{
    __IO uint32_t NEXT          :3;
         uint32_t reserved0     :28;
    __IO uint32_t FORCE         :1;
}PSC1_MDCTL_TypeDef;



typedef struct  {
    union
    {
        __IO uint32_t       REVID;
        PSC_REVID_TypeDef   REVID_Bit;
    };
    uint32_t reserved0[5];
    union
    {
        __IO uint32_t       INTEVAL;
        PSC_INTEVAL_TypeDef   INTEVAL_Bit;
    };
    uint32_t reserved1[9];
    union
    {
        __IO uint32_t       MERRPR0;
        PSC0_MERRPR0_TypeDef   MERRPR0_Bit;
    };
    uint32_t reserved2[3];
    union
    {
        __IO uint32_t       MERRCR0;
        PSC0_MERRCR0_TypeDef  MERRCR0_Bit;
    };
    uint32_t reserved3[3];
    union
    {
        __IO uint32_t       PERRPR;
        PSC_PERRPR_TypeDef  PERRPR_Bit;
    };
    uint32_t reserved4[1];
    union
    {
        __IO uint32_t       PERRCR;
        PSC_PERRCR_TypeDef  PERRCR_Bit;
    };
    uint32_t reserved5[45];
    union
    {
        __IO uint32_t       PTCMD;
        PSC_PTCMD_TypeDef  PTCMD_Bit;
    };
    uint32_t reserved6[1];
    union
    {
        __IO uint32_t       PTSTAT;
        PSC_PTSTAT_TypeDef  PTSTAT_Bit;
    };
    uint32_t reserved7[53];
    union
    {
        __IO uint32_t       PDSTAT0;
        PSC_PDSTAT_TypeDef  PDSTAT0_Bit;
    };
    union
    {
        __IO uint32_t       PDSTAT1;
        PSC_PDSTAT_TypeDef  PDSTAT1_Bit;
    };
    uint32_t reserved8[62];
    union
    {
        __IO uint32_t       PDCTL0;
        PSC_PDCTL_TypeDef  PDCTL0_Bit;
    };
    union
    {
        __IO uint32_t       PDCTL1;
        PSC_PDCTL_TypeDef  PDCTL1_Bit;
    };
    uint32_t reserved9[62];
    union
    {
        __IO uint32_t       PDCFG0;
        PSC_PDCFG_TypeDef  PDCFG0_Bit;
    };
    union
    {
        __IO uint32_t       PDCFG1;
        PSC_PDCFG_TypeDef  PDCFG1_Bit;
    };
    uint32_t reserved10[254];
    union
    {
        __IO uint32_t       MDSTAT[16];
        PSC_MDSTAT_TypeDef  MDSTAT_Bit[16];
    };
    uint32_t reserved11[112];
    union
    {
        __IO uint32_t       MDCTL[16];
        PSC0_MDCTL_TypeDef  MDCTL_Bit[16];
    };

} PSC0_TypeDef;


typedef struct  {
    union
    {
        __IO uint32_t       REVID;
        PSC_REVID_TypeDef   REVID_Bit;
    };
    uint32_t reserved0[5];
    union
    {
        __IO uint32_t       INTEVAL;
        PSC_INTEVAL_TypeDef   INTEVAL_Bit;
    };
    uint32_t reserved1[9];
    union
    {
        __IO uint32_t       MERRPR0;
        PSC1_MERRPR0_TypeDef   MERRPR0_Bit;
    };
    uint32_t reserved2[3];
    union
    {
        __IO uint32_t       MERRCR0;
        PSC1_MERRCR0_TypeDef  MERRCR0_Bit;
    };
    uint32_t reserved3[3];
    union
    {
        __IO uint32_t       PERRPR;
        PSC_PERRPR_TypeDef  PERRPR_Bit;
    };
    uint32_t reserved4[1];
    union
    {
        __IO uint32_t       PERRCR;
        PSC_PERRCR_TypeDef  PERRCR_Bit;
    };
    uint32_t reserved5[45];
    union
    {
        __IO uint32_t       PTCMD;
        PSC_PTCMD_TypeDef  PTCMD_Bit;
    };
    uint32_t reserved6[1];
    union
    {
        __IO uint32_t       PTSTAT;
        PSC_PTSTAT_TypeDef  PTSTAT_Bit;
    };
    uint32_t reserved7[53];
    union
    {
        __IO uint32_t       PDSTAT0;
        PSC_PDSTAT_TypeDef  PDSTAT0_Bit;
    };
    union
    {
        __IO uint32_t       PDSTAT1;
        PSC_PDSTAT_TypeDef  PDSTAT1_Bit;
    };
    uint32_t reserved8[62];
    union
    {
        __IO uint32_t       PDCTL0;
        PSC_PDCTL_TypeDef  PDCTL0_Bit;
    };
    union
    {
        __IO uint32_t       PDCTL1;
        PSC_PDCTL_TypeDef  PDCTL1_Bit;
    };
    uint32_t reserved9[62];
    union
    {
        __IO uint32_t       PDCFG0;
        PSC_PDCFG_TypeDef  PDCFG0_Bit;
    };
    union
    {
        __IO uint32_t       PDCFG1;
        PSC_PDCFG_TypeDef  PDCFG1_Bit;
    };
    uint32_t reserved10[254];
    union
    {
        __IO uint32_t       MDSTAT[32];
        PSC_MDSTAT_TypeDef  MDSTAT_Bit[32];
    };
    uint32_t reserved11[96];
    union
    {
        __IO uint32_t       MDCTL[32];
        PSC1_MDCTL_TypeDef  MDCTL_Bit[32];
    };

} PSC1_TypeDef;




#define PSC0            (((PSC0_TypeDef*)(PSC0_BASE)))
#define PSC0_R(offset)  (*((__IO uint32_t *)(PSC0_BASE+offset)))
#define PSC1            (((PSC1_TypeDef*)(PSC1_BASE)))
#define PSC1_R(offset)  (*((__IO uint32_t *)(PSC1_BASE+offset)))



#define PSC_REVID_OFFSET       ((uint32_t)0x0000)
#define PSC_INTEVAL_OFFSET     ((uint32_t)0x0018)
#define PSC_MERRPR0_OFFSET     ((uint32_t)0x0040)
#define PSC_MERRCR0_OFFSET     ((uint32_t)0x0050)
#define PSC_PERRPR_OFFSET      ((uint32_t)0x0060)
#define PSC_PERRCR_OFFSET      ((uint32_t)0x0068)
#define PSC_PTCMD_OFFSET       ((uint32_t)0x0120)
#define PSC_PTSTAT_OFFSET      ((uint32_t)0x0128)
#define PSC_PDSTAT0_OFFSET     ((uint32_t)0x0200)
#define PSC_PDSTAT1_OFFSET     ((uint32_t)0x0204)
#define PSC_PDCTL0_OFFSET      ((uint32_t)0x0300)
#define PSC_PDCTL1_OFFSET      ((uint32_t)0x0304)
#define PSC_PDCFG0_OFFSET      ((uint32_t)0x0400)
#define PSC_PDCFG1_OFFSET      ((uint32_t)0x0404)
#define PSC_MDSTAT0_OFFSET     ((uint32_t)0x0800)
#define PSC_MDSTAT1_OFFSET     ((uint32_t)0x0804)
#define PSC_MDSTAT2_OFFSET     ((uint32_t)0x0808)
#define PSC_MDSTAT3_OFFSET     ((uint32_t)0x080C)
#define PSC_MDSTAT4_OFFSET     ((uint32_t)0x0810)
#define PSC_MDSTAT5_OFFSET     ((uint32_t)0x0814)
#define PSC_MDSTAT6_OFFSET     ((uint32_t)0x0818)
#define PSC_MDSTAT7_OFFSET     ((uint32_t)0x081C)
#define PSC_MDSTAT8_OFFSET     ((uint32_t)0x0820)
#define PSC_MDSTAT9_OFFSET     ((uint32_t)0x0824)
#define PSC_MDSTAT10_OFFSET     ((uint32_t)0x0828)
#define PSC_MDSTAT11_OFFSET     ((uint32_t)0x082C)
#define PSC_MDSTAT12_OFFSET     ((uint32_t)0x0830)
#define PSC_MDSTAT13_OFFSET     ((uint32_t)0x0834)
#define PSC_MDSTAT14_OFFSET     ((uint32_t)0x0838)
#define PSC_MDSTAT15_OFFSET     ((uint32_t)0x083C)
#define PSC_MDSTAT16_OFFSET     ((uint32_t)0x0840)
#define PSC_MDSTAT17_OFFSET     ((uint32_t)0x0844)
#define PSC_MDSTAT18_OFFSET     ((uint32_t)0x0848)
#define PSC_MDSTAT19_OFFSET     ((uint32_t)0x084C)
#define PSC_MDSTAT20_OFFSET     ((uint32_t)0x0850)
#define PSC_MDSTAT21_OFFSET     ((uint32_t)0x0854)
#define PSC_MDSTAT22_OFFSET     ((uint32_t)0x0858)
#define PSC_MDSTAT23_OFFSET     ((uint32_t)0x085C)
#define PSC_MDSTAT24_OFFSET     ((uint32_t)0x0860)
#define PSC_MDSTAT25_OFFSET     ((uint32_t)0x0864)
#define PSC_MDSTAT26_OFFSET     ((uint32_t)0x0868)
#define PSC_MDSTAT27_OFFSET     ((uint32_t)0x086C)
#define PSC_MDSTAT28_OFFSET     ((uint32_t)0x0870)
#define PSC_MDSTAT29_OFFSET     ((uint32_t)0x0874)
#define PSC_MDSTAT30_OFFSET     ((uint32_t)0x0878)
#define PSC_MDSTAT31_OFFSET     ((uint32_t)0x087C)
#define PSC_MDCTL0_OFFSET     ((uint32_t)0x0A00)
#define PSC_MDCTL1_OFFSET     ((uint32_t)0x0A04)
#define PSC_MDCTL2_OFFSET     ((uint32_t)0x0A08)
#define PSC_MDCTL3_OFFSET     ((uint32_t)0x0A0C)
#define PSC_MDCTL4_OFFSET     ((uint32_t)0x0A10)
#define PSC_MDCTL5_OFFSET     ((uint32_t)0x0A14)
#define PSC_MDCTL6_OFFSET     ((uint32_t)0x0A18)
#define PSC_MDCTL7_OFFSET     ((uint32_t)0x0A1C)
#define PSC_MDCTL8_OFFSET     ((uint32_t)0x0A20)
#define PSC_MDCTL9_OFFSET     ((uint32_t)0x0A24)
#define PSC_MDCTL10_OFFSET     ((uint32_t)0x0A28)
#define PSC_MDCTL11_OFFSET     ((uint32_t)0x0A2C)
#define PSC_MDCTL12_OFFSET     ((uint32_t)0x0A30)
#define PSC_MDCTL13_OFFSET     ((uint32_t)0x0A34)
#define PSC_MDCTL14_OFFSET     ((uint32_t)0x0A38)
#define PSC_MDCTL15_OFFSET     ((uint32_t)0x0A3C)
#define PSC_MDCTL16_OFFSET     ((uint32_t)0x0A40)
#define PSC_MDCTL17_OFFSET     ((uint32_t)0x0A44)
#define PSC_MDCTL18_OFFSET     ((uint32_t)0x0A48)
#define PSC_MDCTL19_OFFSET     ((uint32_t)0x0A4C)
#define PSC_MDCTL20_OFFSET     ((uint32_t)0x0A50)
#define PSC_MDCTL21_OFFSET     ((uint32_t)0x0A54)
#define PSC_MDCTL22_OFFSET     ((uint32_t)0x0A58)
#define PSC_MDCTL23_OFFSET     ((uint32_t)0x0A5C)
#define PSC_MDCTL24_OFFSET     ((uint32_t)0x0A60)
#define PSC_MDCTL25_OFFSET     ((uint32_t)0x0A64)
#define PSC_MDCTL26_OFFSET     ((uint32_t)0x0A68)
#define PSC_MDCTL27_OFFSET     ((uint32_t)0x0A6C)
#define PSC_MDCTL28_OFFSET     ((uint32_t)0x0A70)
#define PSC_MDCTL29_OFFSET     ((uint32_t)0x0A74)
#define PSC_MDCTL30_OFFSET     ((uint32_t)0x0A78)
#define PSC_MDCTL31_OFFSET     ((uint32_t)0x0A7C)



/**********************************************************************************************
************************************** 1 REVID ***********************************************
**********************************************************************************************/
#define PSC0_REVID                    (((PSC_REVID_TypeDef*)(PSC0_BASE+PSC_REVID_OFFSET )))
#define PSC0_REVID_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_REVID_OFFSET)))
#define PSC1_REVID                    (((PSC_REVID_TypeDef*)(PSC1_BASE+PSC_REVID_OFFSET )))
#define PSC1_REVID_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_REVID_OFFSET)))

/*--------*/
#define PSC_REVID_R_REV_MASK        ((uint32_t)0xFFFFFFFF)
#define PSC_REVID_R_REV_SHIFT         (0)

#define PSC_REVID_REV_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 2 INTEVAL ***********************************************
**********************************************************************************************/
#define PSC0_INTEVAL                    (((PSC_INTEVAL_TypeDef*)(PSC0_BASE+PSC_INTEVAL_OFFSET )))
#define PSC0_INTEVAL_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_INTEVAL_OFFSET)))
#define PSC1_INTEVAL                    (((PSC_INTEVAL_TypeDef*)(PSC1_BASE+PSC_INTEVAL_OFFSET )))
#define PSC1_INTEVAL_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_INTEVAL_OFFSET)))

/*--------*/
#define PSC_INTEVAL_R_ALLEV_MASK        ((uint32_t)0x00000001)
#define PSC_INTEVAL_R_ALLEV_SHIFT         (0)

#define PSC_INTEVAL_ALLEV_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 3 MERRPR0 ***********************************************
**********************************************************************************************/
#define PSC0_MERRPR0                    (((PSC0_MERRPR0_TypeDef*)(PSC0_BASE+PSC_MERRPR0_OFFSET )))
#define PSC0_MERRPR0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MERRPR0_OFFSET)))
#define PSC1_MERRPR0                    (((PSC1_MERRPR0_TypeDef*)(PSC1_BASE+PSC_MERRPR0_OFFSET )))
#define PSC1_MERRPR0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MERRPR0_OFFSET)))

/*--------*/
#define PSC0_MERRPR0_R_ALLEV_MASK        ((uint32_t)0x00008000)
#define PSC0_MERRPR0_R_ALLEV_SHIFT         (15)

#define PSC0_MERRPR0_ALLEV_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 4 MERRCR0 ***********************************************
**********************************************************************************************/
#define PSC0_MERRCR0                    (((PSC0_MERRCR0_TypeDef*)(PSC0_BASE+PSC_MERRCR0_OFFSET )))
#define PSC0_MERRCR0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MERRCR0_OFFSET)))
#define PSC1_MERRCR0                    (((PSC1_MERRCR0_TypeDef*)(PSC1_BASE+PSC_MERRCR0_OFFSET )))
#define PSC1_MERRCR0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MERRCR0_OFFSET)))

/*--------*/
#define PSC0_MERRCR0_R_ALLEV_MASK        ((uint32_t)0x00008000)
#define PSC0_MERRCR0_R_ALLEV_SHIFT         (15)

#define PSC0_MERRCR0_ALLEV_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 5 PERRPR ***********************************************
**********************************************************************************************/
#define PSC0_PERRPR                    (((PSC_PERRPR_TypeDef*)(PSC0_BASE+PSC_PERRPR_OFFSET )))
#define PSC0_PERRPR_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_PERRPR_OFFSET)))
#define PSC1_PERRPR                    (((PSC_PERRPR_TypeDef*)(PSC1_BASE+PSC_PERRPR_OFFSET )))
#define PSC1_PERRPR_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_PERRPR_OFFSET)))

/*--------*/
#define PSC_PERRPR_R_P1_MASK        ((uint32_t)0x00000002)
#define PSC_PERRPR_R_P1_SHIFT         (1)

#define PSC_PERRPR_P1_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 6 PERRCR ***********************************************
**********************************************************************************************/
#define PSC0_PERRCR                    (((PSC_PERRCR_TypeDef*)(PSC0_BASE+PSC_PERRCR_OFFSET )))
#define PSC0_PERRCR_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_PERRCR_OFFSET)))
#define PSC1_PERRCR                    (((PSC_PERRCR_TypeDef*)(PSC1_BASE+PSC_PERRCR_OFFSET )))
#define PSC1_PERRCR_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_PERRCR_OFFSET)))

/*--------*/
#define PSC_PERRCR_R_P1_MASK        ((uint32_t)0x00000002)
#define PSC_PERRCR_R_P1_SHIFT         (1)

#define PSC_PERRCR_P1_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 7 PTCMD ***********************************************
**********************************************************************************************/
#define PSC0_PTCMD                    (((PSC_PTCMD_TypeDef*)(PSC0_BASE+PSC_PTCMD_OFFSET )))
#define PSC0_PTCMD_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_PTCMD_OFFSET)))
#define PSC1_PTCMD                    (((PSC_PTCMD_TypeDef*)(PSC1_BASE+PSC_PTCMD_OFFSET )))
#define PSC1_PTCMD_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_PTCMD_OFFSET)))

/*--------*/
#define PSC_PTCMD_R_GO0_MASK        ((uint32_t)0x00000001)
#define PSC_PTCMD_R_GO0_SHIFT         (0)

#define PSC_PTCMD_GO0_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_PTCMD_R_GO1_MASK        ((uint32_t)0x00000002)
#define PSC_PTCMD_R_GO1_SHIFT         (1)

#define PSC_PTCMD_GO1_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 8 PTSTAT ***********************************************
**********************************************************************************************/
#define PSC0_PTSTAT                    (((PSC_PTSTAT_TypeDef*)(PSC0_BASE+PSC_PTSTAT_OFFSET )))
#define PSC0_PTSTAT_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_PTSTAT_OFFSET)))
#define PSC1_PTSTAT                    (((PSC_PTSTAT_TypeDef*)(PSC1_BASE+PSC_PTSTAT_OFFSET )))
#define PSC1_PTSTAT_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_PTSTAT_OFFSET)))

/*--------*/
#define PSC_PTSTAT_R_GOSTAT0_MASK        ((uint32_t)0x00000001)
#define PSC_PTSTAT_R_GOSTAT0_SHIFT         (0)

#define PSC_PTSTAT_GOSTAT0_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_PTSTAT_R_GOSTAT1_MASK        ((uint32_t)0x00000002)
#define PSC_PTSTAT_R_GOSTAT1_SHIFT         (1)

#define PSC_PTSTAT_GOSTAT1_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 9-10 PDSTAT ***********************************************
**********************************************************************************************/
#define PSC0_PDSTAT0                    (((PSC_PDSTAT_TypeDef*)(PSC0_BASE+PSC_PDSTAT0_OFFSET )))
#define PSC0_PDSTAT0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_PDSTAT0_OFFSET)))
#define PSC0_PDSTAT1                    (((PSC_PDSTAT_TypeDef*)(PSC0_BASE+PSC_PDSTAT1_OFFSET )))
#define PSC0_PDSTAT1_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_PDSTAT1_OFFSET)))
#define PSC1_PDSTAT0                    (((PSC_PDSTAT_TypeDef*)(PSC1_BASE+PSC_PDSTAT0_OFFSET )))
#define PSC1_PDSTAT0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_PDSTAT0_OFFSET)))
#define PSC1_PDSTAT1                    (((PSC_PDSTAT_TypeDef*)(PSC1_BASE+PSC_PDSTAT1_OFFSET )))
#define PSC1_PDSTAT1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_PDSTAT1_OFFSET)))
/*--------*/
#define PSC_PDSTAT_R_STATE_MASK        ((uint32_t)0x0000001F)
#define PSC_PDSTAT_R_STATE_SHIFT         (0)

#define PSC_PDSTAT_STATE_MASK          ((uint32_t)0x0000001F)
/*--------*/
/*--------*/
#define PSC_PDSTAT_R_POR_MASK        ((uint32_t)0x00000100)
#define PSC_PDSTAT_R_POR_SHIFT         (8)

#define PSC_PDSTAT_POR_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_PDSTAT_R_PORDONE_MASK        ((uint32_t)0x00000200)
#define PSC_PDSTAT_R_PORDONE_SHIFT         (9)

#define PSC_PDSTAT_PORDONE_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_PDSTAT_R_EMUIHB_MASK        ((uint32_t)0x00000800)
#define PSC_PDSTAT_R_EMUIHB_SHIFT         (11)

#define PSC_PDSTAT_EMUIHB_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 11-12 PDCTL ***********************************************
**********************************************************************************************/
#define PSC0_PDCTL0                    (((PSC_PDCTL_TypeDef*)(PSC0_BASE+PSC_PDCTL0_OFFSET )))
#define PSC0_PDCTL0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_PDCTL0_OFFSET)))
#define PSC0_PDCTL1                    (((PSC_PDCTL_TypeDef*)(PSC0_BASE+PSC_PDCTL1_OFFSET )))
#define PSC0_PDCTL1_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_PDCTL1_OFFSET)))
#define PSC1_PDCTL0                    (((PSC_PDCTL_TypeDef*)(PSC1_BASE+PSC_PDCTL0_OFFSET )))
#define PSC1_PDCTL0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_PDCTL0_OFFSET)))
#define PSC1_PDCTL1                    (((PSC_PDCTL_TypeDef*)(PSC1_BASE+PSC_PDCTL1_OFFSET )))
#define PSC1_PDCTL1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_PDCTL1_OFFSET)))

/*--------*/
#define PSC_PDCTL_R_NEXT_MASK        ((uint32_t)0x00000001)
#define PSC_PDCTL_R_NEXT_SHIFT         (0)

#define PSC_PDCTL_NEXT_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_PDCTL_R_EMUIHBIE_MASK        ((uint32_t)0x00000200)
#define PSC_PDCTL_R_EMUIHBIE_SHIFT         (9)

#define PSC_PDCTL_EMUIHBIE  _MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_PDCTL_R_PDMODE_MASK        ((uint32_t)0x0000F000)
#define PSC_PDCTL_R_PDMODE_SHIFT         (12)

#define PSC_PDCTL_PDMODE_MASK          ((uint32_t)0x0000000F)
/*--------*/
/*--------*/
#define PSC_PDCTL_R_WAKECNT_MASK        ((uint32_t)0x00FF0000)
#define PSC_PDCTL_R_WAKECNT_SHIFT         (16   )

#define PSC_PDCTL_WAKECNT_MASK          ((uint32_t)0x000000FF)
/*--------*/

/**********************************************************************************************
************************************** 13-14 PDCFG ***********************************************
**********************************************************************************************/
#define PSC0_PDCFG0                    (((PSC_PDCFG_TypeDef*)(PSC0_BASE+PSC_PDCFG0_OFFSET )))
#define PSC0_PDCFG0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_PDCFG0_OFFSET)))
#define PSC0_PDCFG1                    (((PSC_PDCFG_TypeDef*)(PSC0_BASE+PSC_PDCFG1_OFFSET )))
#define PSC0_PDCFG1_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_PDCFG1_OFFSET)))
#define PSC1_PDCFG0                    (((PSC_PDCFG_TypeDef*)(PSC1_BASE+PSC_PDCFG0_OFFSET )))
#define PSC1_PDCFG0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_PDCFG0_OFFSET)))
#define PSC1_PDCFG1                    (((PSC_PDCFG_TypeDef*)(PSC1_BASE+PSC_PDCFG1_OFFSET )))
#define PSC1_PDCFG1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_PDCFG1_OFFSET)))

/*--------*/
#define PSC_PDCFG_R_ALWAYSON_MASK        ((uint32_t)0x00000001)
#define PSC_PDCFG_R_ALWAYSON_SHIFT         (0)

#define PSC_PDCFG_ALWAYSONT_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_PDCFG_R_RAM_PSM_MASK        ((uint32_t)0x00000002)
#define PSC_PDCFG_R_RAM_PSM_SHIFT         (1)

#define PSC_PDCFG_RAM_PSM_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_PDCFG_R_ICEPICK_MASK        ((uint32_t)0x00000004)
#define PSC_PDCFG_R_ICEPICK_SHIFT         (2)

#define PSC_PDCFG_ICEPICK_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_PDCFG_R_PD_LOCK_MASK        ((uint32_t)0x00000008)
#define PSC_PDCFG_R_PD_LOCK_SHIFT         (3)

#define PSC_PDCFG_PD_LOCK_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 15-47 MDSTAT ***********************************************
**********************************************************************************************/

#define PSC0_MDSTAT0                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT0_OFFSET )))
#define PSC0_MDSTAT0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT0_OFFSET)))
#define PSC0_MDSTAT_EDMA_CC0                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT0_OFFSET )))
#define PSC0_MDSTAT_EDMA_CC0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT0_OFFSET)))

#define PSC0_MDSTAT1                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT1_OFFSET )))
#define PSC0_MDSTAT1_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT1_OFFSET)))
#define PSC0_MDSTAT_EDMA_TC0                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT1_OFFSET )))
#define PSC0_MDSTAT_EDMA_TC0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT1_OFFSET)))

#define PSC0_MDSTAT2                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT2_OFFSET )))
#define PSC0_MDSTAT2_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT2_OFFSET)))
#define PSC0_MDSTAT_EDMA_TC1                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT2_OFFSET )))
#define PSC0_MDSTAT_EDMA_TC1_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT2_OFFSET)))

#define PSC0_MDSTAT3                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT3_OFFSET )))
#define PSC0_MDSTAT3_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT3_OFFSET)))
#define PSC0_MDSTAT_EMIFA                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT3_OFFSET )))
#define PSC0_MDSTAT_EMIFA_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT3_OFFSET)))

#define PSC0_MDSTAT4                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT4_OFFSET )))
#define PSC0_MDSTAT4_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT4_OFFSET)))
#define PSC0_MDSTAT_SPI0                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT4_OFFSET )))
#define PSC0_MDSTAT_SPI0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT4_OFFSET)))

#define PSC0_MDSTAT5                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT5_OFFSET )))
#define PSC0_MDSTAT5_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT5_OFFSET)))
#define PSC0_MDSTAT_MMCSD0                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT5_OFFSET )))
#define PSC0_MDSTAT_MMCSD0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT5_OFFSET)))

#define PSC0_MDSTAT6                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT6_OFFSET )))
#define PSC0_MDSTAT6_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT6_OFFSET)))
#define PSC0_MDSTAT_Reserved0                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT6_OFFSET )))
#define PSC0_MDSTAT_Reserved0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT6_OFFSET)))

#define PSC0_MDSTAT7                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT7_OFFSET )))
#define PSC0_MDSTAT7_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT7_OFFSET)))
#define PSC0_MDSTAT_Reserved1                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT7_OFFSET )))
#define PSC0_MDSTAT_Reserved1_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT7_OFFSET)))

#define PSC0_MDSTAT8                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT8_OFFSET )))
#define PSC0_MDSTAT8_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT8_OFFSET)))
#define PSC0_MDSTAT_Reserved2                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT8_OFFSET )))
#define PSC0_MDSTAT_Reserved2_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT8_OFFSET)))

#define PSC0_MDSTAT9                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT9_OFFSET )))
#define PSC0_MDSTAT9_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT9_OFFSET)))
#define PSC0_MDSTAT_UART0                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT9_OFFSET )))
#define PSC0_MDSTAT_UART0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT9_OFFSET)))

#define PSC0_MDSTAT10                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT10_OFFSET )))
#define PSC0_MDSTAT10_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT10_OFFSET)))
#define PSC0_MDSTAT_SCR0                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT10_OFFSET )))
#define PSC0_MDSTAT_SCR0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT10_OFFSET)))

#define PSC0_MDSTAT11                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT11_OFFSET )))
#define PSC0_MDSTAT11_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT11_OFFSET)))
#define PSC0_MDSTAT_SCR1                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT11_OFFSET )))
#define PSC0_MDSTAT_SCR1_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT11_OFFSET)))

#define PSC0_MDSTAT12                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT12_OFFSET )))
#define PSC0_MDSTAT12_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT12_OFFSET)))
#define PSC0_MDSTAT_SCR2                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT12_OFFSET )))
#define PSC0_MDSTAT_SCR2_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT12_OFFSET)))

#define PSC0_MDSTAT13                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT13_OFFSET )))
#define PSC0_MDSTAT13_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT13_OFFSET)))
#define PSC0_MDSTAT_PRUSS                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT13_OFFSET )))
#define PSC0_MDSTAT_PRUSS_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT13_OFFSET)))

#define PSC0_MDSTAT14                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT14_OFFSET )))
#define PSC0_MDSTAT14_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT14_OFFSET)))
#define PSC0_MDSTAT_Reserved3                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT14_OFFSET )))
#define PSC0_MDSTAT_Reserved3_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT14_OFFSET)))

#define PSC0_MDSTAT15                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT15_OFFSET )))
#define PSC0_MDSTAT15_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT15_OFFSET)))
#define PSC0_MDSTAT_DSP                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT15_OFFSET )))
#define PSC0_MDSTAT_DSP_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT15_OFFSET)))

#define PSC0_MDSTAT(n)                    (((PSC_MDSTAT_TypeDef*)(PSC0_BASE+PSC_MDSTAT0_OFFSET +((n)*4) )))
#define PSC0_MDSTAT_R(n)                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDSTAT0_OFFSET +((n)*4))))



#define PSC1_MDSTAT0                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT0_OFFSET )))
#define PSC1_MDSTAT0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT0_OFFSET)))
#define PSC1_MDSTAT_EDMA_CC1                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT0_OFFSET )))
#define PSC1_MDSTAT_EDMA_CC1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT0_OFFSET)))

#define PSC1_MDSTAT1                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT1_OFFSET )))
#define PSC1_MDSTAT1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT1_OFFSET)))
#define PSC1_MDSTAT_USB20                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT1_OFFSET )))
#define PSC1_MDSTAT_USB20_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT1_OFFSET)))

#define PSC1_MDSTAT2                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT2_OFFSET )))
#define PSC1_MDSTAT2_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT2_OFFSET)))
#define PSC1_MDSTAT_USB11                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT2_OFFSET )))
#define PSC1_MDSTAT_USB11_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT2_OFFSET)))

#define PSC1_MDSTAT3                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT3_OFFSET )))
#define PSC1_MDSTAT3_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT3_OFFSET)))
#define PSC1_MDSTAT_GPIO                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT3_OFFSET )))
#define PSC1_MDSTAT_GPIO_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT3_OFFSET)))

#define PSC1_MDSTAT4                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT4_OFFSET )))
#define PSC1_MDSTAT4_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT4_OFFSET)))
#define PSC1_MDSTAT_UHPI                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT4_OFFSET )))
#define PSC1_MDSTAT_UHPI_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT4_OFFSET)))

#define PSC1_MDSTAT5                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT5_OFFSET )))
#define PSC1_MDSTAT5_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT5_OFFSET)))
#define PSC1_MDSTAT_EMAC                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT5_OFFSET )))
#define PSC1_MDSTAT_EMAC_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT5_OFFSET)))

#define PSC1_MDSTAT6                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT6_OFFSET )))
#define PSC1_MDSTAT6_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT6_OFFSET)))
#define PSC1_MDSTAT_DDR                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT6_OFFSET )))
#define PSC1_MDSTAT_DDR_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT6_OFFSET)))

#define PSC1_MDSTAT7                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT7_OFFSET )))
#define PSC1_MDSTAT7_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT7_OFFSET)))
#define PSC1_MDSTAT_MCASP0                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT7_OFFSET )))
#define PSC1_MDSTAT_MCASP0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT7_OFFSET)))

#define PSC1_MDSTAT8                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT8_OFFSET )))
#define PSC1_MDSTAT8_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT8_OFFSET)))
#define PSC1_MDSTAT_SATA                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT8_OFFSET )))
#define PSC1_MDSTAT_SATA_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT8_OFFSET)))

#define PSC1_MDSTAT9                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT9_OFFSET )))
#define PSC1_MDSTAT9_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT9_OFFSET)))
#define PSC1_MDSTAT_VPIF                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT9_OFFSET )))
#define PSC1_MDSTAT_VPIF_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT9_OFFSET)))

#define PSC1_MDSTAT10                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT10_OFFSET )))
#define PSC1_MDSTAT10_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT10_OFFSET)))
#define PSC1_MDSTAT_SPI1                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT10_OFFSET )))
#define PSC1_MDSTAT_SPI1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT10_OFFSET)))

#define PSC1_MDSTAT11                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT11_OFFSET )))
#define PSC1_MDSTAT11_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT11_OFFSET)))
#define PSC1_MDSTAT_I2C1                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT11_OFFSET )))
#define PSC1_MDSTAT_I2C1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT11_OFFSET)))

#define PSC1_MDSTAT12                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT12_OFFSET )))
#define PSC1_MDSTAT12_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT12_OFFSET)))
#define PSC1_MDSTAT_UART1                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT12_OFFSET )))
#define PSC1_MDSTAT_UART1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT12_OFFSET)))

#define PSC1_MDSTAT13                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT13_OFFSET )))
#define PSC1_MDSTAT13_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT13_OFFSET)))
#define PSC1_MDSTAT_UART2                   (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT13_OFFSET )))
#define PSC1_MDSTAT_UART2_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT13_OFFSET)))

#define PSC1_MDSTAT14                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT14_OFFSET )))
#define PSC1_MDSTAT14_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT14_OFFSET)))
#define PSC1_MDSTAT_MCBSP0                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT14_OFFSET )))
#define PSC1_MDSTAT_MCBSP0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT14_OFFSET)))

#define PSC1_MDSTAT15                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT15_OFFSET )))
#define PSC1_MDSTAT15_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT15_OFFSET)))
#define PSC1_MDSTAT_MCBSP1                  (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT15_OFFSET )))
#define PSC1_MDSTAT_MCBSP1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT15_OFFSET)))

#define PSC1_MDSTAT16                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT16_OFFSET )))
#define PSC1_MDSTAT16_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT16_OFFSET)))
#define PSC1_MDSTAT_LCDC                   (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT16_OFFSET )))
#define PSC1_MDSTAT_LCDC_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT16_OFFSET)))

#define PSC1_MDSTAT17                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT17_OFFSET )))
#define PSC1_MDSTAT17_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT17_OFFSET)))
#define PSC1_MDSTAT_EPWM                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT17_OFFSET )))
#define PSC1_MDSTAT_EPWM_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT17_OFFSET)))

#define PSC1_MDSTAT18                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT18_OFFSET )))
#define PSC1_MDSTAT18_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT18_OFFSET)))
#define PSC1_MDSTAT_MMCSD1                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT18_OFFSET )))
#define PSC1_MDSTAT_MMCSD1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT18_OFFSET)))

#define PSC1_MDSTAT19                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT19_OFFSET )))
#define PSC1_MDSTAT19_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT19_OFFSET)))
#define PSC1_MDSTAT_UPP                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT19_OFFSET )))
#define PSC1_MDSTAT_UPP_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT19_OFFSET)))

#define PSC1_MDSTAT20                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT20_OFFSET )))
#define PSC1_MDSTAT20_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT20_OFFSET)))
#define PSC1_MDSTAT_ECAP                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT20_OFFSET )))
#define PSC1_MDSTAT_ECAP_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT20_OFFSET)))

#define PSC1_MDSTAT21                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT21_OFFSET )))
#define PSC1_MDSTAT21_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT21_OFFSET)))
#define PSC1_MDSTAT_EDMA_TC2                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT21_OFFSET )))
#define PSC1_MDSTAT_EDMA_TC2_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT21_OFFSET)))

#define PSC1_MDSTAT22                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT22_OFFSET )))
#define PSC1_MDSTAT22_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT22_OFFSET)))
#define PSC1_MDSTAT_Reserved0                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT22_OFFSET )))
#define PSC1_MDSTAT_Reserved0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT22_OFFSET)))

#define PSC1_MDSTAT23                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT23_OFFSET )))
#define PSC1_MDSTAT23_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT23_OFFSET)))
#define PSC1_MDSTAT_Reserved1                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT23_OFFSET )))
#define PSC1_MDSTAT_Reserved1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT23_OFFSET)))

#define PSC1_MDSTAT24                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT24_OFFSET )))
#define PSC1_MDSTAT24_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT24_OFFSET)))
#define PSC1_MDSTAT_SCR_F0                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT24_OFFSET )))
#define PSC1_MDSTAT_SCR_F0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT24_OFFSET)))

#define PSC1_MDSTAT25                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT25_OFFSET )))
#define PSC1_MDSTAT25_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT25_OFFSET)))
#define PSC1_MDSTAT_SCR_F1                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT25_OFFSET )))
#define PSC1_MDSTAT_SCR_F1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT25_OFFSET)))

#define PSC1_MDSTAT26                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT26_OFFSET )))
#define PSC1_MDSTAT26_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT26_OFFSET)))
#define PSC1_MDSTAT_SCR_F2                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT26_OFFSET )))
#define PSC1_MDSTAT_SCR_F2_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT26_OFFSET)))

#define PSC1_MDSTAT27                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT27_OFFSET )))
#define PSC1_MDSTAT27_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT27_OFFSET)))
#define PSC1_MDSTAT_SCR_F6                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT27_OFFSET )))
#define PSC1_MDSTAT_SCR_F6_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT27_OFFSET)))

#define PSC1_MDSTAT28                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT28_OFFSET )))
#define PSC1_MDSTAT28_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT28_OFFSET)))
#define PSC1_MDSTAT_SCR_F7                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT28_OFFSET )))
#define PSC1_MDSTAT_SCR_F7_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT28_OFFSET)))

#define PSC1_MDSTAT29                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT29_OFFSET )))
#define PSC1_MDSTAT29_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT29_OFFSET)))
#define PSC1_MDSTAT_SCR_F8                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT29_OFFSET )))
#define PSC1_MDSTAT_SCR_F8_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT29_OFFSET)))

#define PSC1_MDSTAT30                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT30_OFFSET )))
#define PSC1_MDSTAT30_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT30_OFFSET)))
#define PSC1_MDSTAT_BR_F7                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT30_OFFSET )))
#define PSC1_MDSTAT_BR_F7_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT30_OFFSET)))

#define PSC1_MDSTAT31                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT31_OFFSET )))
#define PSC1_MDSTAT31_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT31_OFFSET)))
#define PSC1_MDSTAT_SHARED_RAM                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT31_OFFSET )))
#define PSC1_MDSTAT_SHARED_RAM_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT31_OFFSET)))

#define PSC1_MDSTAT(n)                    (((PSC_MDSTAT_TypeDef*)(PSC1_BASE+PSC_MDSTAT0_OFFSET +((n)*4) )))
#define PSC1_MDSTAT_R(n)                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDSTAT0_OFFSET +((n)*4))))

/*--------*/
#define PSC_MDSTAT_R_STATE_MASK        ((uint32_t)0x0000003F)
#define PSC_MDSTAT_R_STATE_SHIFT         (0)

#define PSC_MDSTAT_STATE_MASK          ((uint32_t)0x0000003F)
/*--------*/
/*--------*/
#define PSC_MDSTAT_R_LRST_MASK        ((uint32_t)0x00000100)
#define PSC_MDSTAT_R_LRST_SHIFT         (8)

#define PSC_MDSTAT_LRST_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_MDSTAT_R_LRSTDONE_MASK        ((uint32_t)0x00000200)
#define PSC_MDSTAT_R_LRSTDONE_SHIFT         (9)

#define PSC_MDSTAT_LRSTDONE_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_MDSTAT_R_MRST_MASK        ((uint32_t)0x00000400)
#define PSC_MDSTAT_R_MRST_SHIFT         (10)

#define PSC_MDSTAT_MRST_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_MDSTAT_R_MCKOUT_MASK        ((uint32_t)0x00001000)
#define PSC_MDSTAT_R_MCKOUT_SHIFT         (12)

#define PSC_MDSTAT_MCKOUT_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_MDSTAT_R_EMURST_MASK        ((uint32_t)0x00010000)
#define PSC_MDSTAT_R_EMURST_SHIFT         (16)

#define PSC_MDSTAT_EMURST_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_MDSTAT_R_EMUIHB_MASK        ((uint32_t)0x00020000)
#define PSC_MDSTAT_R_EMUIHB_SHIFT         (17)

#define PSC_MDSTAT_EMUIHB_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 15-47 MDCTL ***********************************************
**********************************************************************************************/

#define PSC0_MDCTL0                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL0_OFFSET )))
#define PSC0_MDCTL0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL0_OFFSET)))
#define PSC0_MDCTL_EDMA_CC0                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL0_OFFSET )))
#define PSC0_MDCTL_EDMA_CC0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL0_OFFSET)))

#define PSC0_MDCTL1                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL1_OFFSET )))
#define PSC0_MDCTL1_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL1_OFFSET)))
#define PSC0_MDCTL_EDMA_TC0                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL1_OFFSET )))
#define PSC0_MDCTL_EDMA_TC0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL1_OFFSET)))

#define PSC0_MDCTL2                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL2_OFFSET )))
#define PSC0_MDCTL2_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL2_OFFSET)))
#define PSC0_MDCTL_EDMA_TC1                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL2_OFFSET )))
#define PSC0_MDCTL_EDMA_TC1_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL2_OFFSET)))

#define PSC0_MDCTL3                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL3_OFFSET )))
#define PSC0_MDCTL3_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL3_OFFSET)))
#define PSC0_MDCTL_EMIFA                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL3_OFFSET )))
#define PSC0_MDCTL_EMIFA_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL3_OFFSET)))

#define PSC0_MDCTL4                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL4_OFFSET )))
#define PSC0_MDCTL4_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL4_OFFSET)))
#define PSC0_MDCTL_SPI0                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL4_OFFSET )))
#define PSC0_MDCTL_SPI0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL4_OFFSET)))

#define PSC0_MDCTL5                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL5_OFFSET )))
#define PSC0_MDCTL5_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL5_OFFSET)))
#define PSC0_MDCTL_MMCSD0                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL5_OFFSET )))
#define PSC0_MDCTL_MMCSD0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL5_OFFSET)))

#define PSC0_MDCTL6                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL6_OFFSET )))
#define PSC0_MDCTL6_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL6_OFFSET)))
#define PSC0_MDCTL_Reserved0                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL6_OFFSET )))
#define PSC0_MDCTL_Reserved0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL6_OFFSET)))

#define PSC0_MDCTL7                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL7_OFFSET )))
#define PSC0_MDCTL7_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL7_OFFSET)))
#define PSC0_MDCTL_Reserved1                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL7_OFFSET )))
#define PSC0_MDCTL_Reserved1_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL7_OFFSET)))

#define PSC0_MDCTL8                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL8_OFFSET )))
#define PSC0_MDCTL8_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL8_OFFSET)))
#define PSC0_MDCTL_Reserved2                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL8_OFFSET )))
#define PSC0_MDCTL_Reserved2_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL8_OFFSET)))

#define PSC0_MDCTL9                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL9_OFFSET )))
#define PSC0_MDCTL9_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL9_OFFSET)))
#define PSC0_MDCTL_UART0                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL9_OFFSET )))
#define PSC0_MDCTL_UART0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL9_OFFSET)))

#define PSC0_MDCTL10                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL10_OFFSET )))
#define PSC0_MDCTL10_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL10_OFFSET)))
#define PSC0_MDCTL_SCR0                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL10_OFFSET )))
#define PSC0_MDCTL_SCR0_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL10_OFFSET)))

#define PSC0_MDCTL11                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL11_OFFSET )))
#define PSC0_MDCTL11_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL11_OFFSET)))
#define PSC0_MDCTL_SCR1                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL11_OFFSET )))
#define PSC0_MDCTL_SCR1_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL11_OFFSET)))

#define PSC0_MDCTL12                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL12_OFFSET )))
#define PSC0_MDCTL12_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL12_OFFSET)))
#define PSC0_MDCTL_SCR2                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL12_OFFSET )))
#define PSC0_MDCTL_SCR2_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL12_OFFSET)))

#define PSC0_MDCTL13                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL13_OFFSET )))
#define PSC0_MDCTL13_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL13_OFFSET)))
#define PSC0_MDCTL_PRUSS                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL13_OFFSET )))
#define PSC0_MDCTL_PRUSS_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL13_OFFSET)))

#define PSC0_MDCTL14                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL14_OFFSET )))
#define PSC0_MDCTL14_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL14_OFFSET)))
#define PSC0_MDCTL_Reserved3                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL14_OFFSET )))
#define PSC0_MDCTL_Reserved3_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL14_OFFSET)))

#define PSC0_MDCTL15                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL15_OFFSET )))
#define PSC0_MDCTL15_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL15_OFFSET)))
#define PSC0_MDCTL_DSP                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL15_OFFSET )))
#define PSC0_MDCTL_DSP_R                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL15_OFFSET)))

#define PSC0_MDCTL(n)                    (((PSC0_MDCTL_TypeDef*)(PSC0_BASE+PSC_MDCTL0_OFFSET +((n)*4) )))
#define PSC0_MDCTL_R(n)                  (*((__IO uint32_t *)(PSC0_BASE+PSC_MDCTL0_OFFSET +((n)*4))))



#define PSC1_MDCTL0                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL0_OFFSET )))
#define PSC1_MDCTL0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL0_OFFSET)))
#define PSC1_MDCTL_EDMA_CC1                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL0_OFFSET )))
#define PSC1_MDCTL_EDMA_CC1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL0_OFFSET)))

#define PSC1_MDCTL1                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL1_OFFSET )))
#define PSC1_MDCTL1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL1_OFFSET)))
#define PSC1_MDCTL_USB20                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL1_OFFSET )))
#define PSC1_MDCTL_USB20_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL1_OFFSET)))

#define PSC1_MDCTL2                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL2_OFFSET )))
#define PSC1_MDCTL2_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL2_OFFSET)))
#define PSC1_MDCTL_USB11                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL2_OFFSET )))
#define PSC1_MDCTL_USB11_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL2_OFFSET)))

#define PSC1_MDCTL3                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL3_OFFSET )))
#define PSC1_MDCTL3_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL3_OFFSET)))
#define PSC1_MDCTL_GPIO                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL3_OFFSET )))
#define PSC1_MDCTL_GPIO_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL3_OFFSET)))

#define PSC1_MDCTL4                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL4_OFFSET )))
#define PSC1_MDCTL4_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL4_OFFSET)))
#define PSC1_MDCTL_UHPI                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL4_OFFSET )))
#define PSC1_MDCTL_UHPI_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL4_OFFSET)))

#define PSC1_MDCTL5                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL5_OFFSET )))
#define PSC1_MDCTL5_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL5_OFFSET)))
#define PSC1_MDCTL_EMAC                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL5_OFFSET )))
#define PSC1_MDCTL_EMAC_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL5_OFFSET)))

#define PSC1_MDCTL6                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL6_OFFSET )))
#define PSC1_MDCTL6_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL6_OFFSET)))
#define PSC1_MDCTL_DDR                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL6_OFFSET )))
#define PSC1_MDCTL_DDR_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL6_OFFSET)))

#define PSC1_MDCTL7                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL7_OFFSET )))
#define PSC1_MDCTL7_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL7_OFFSET)))
#define PSC1_MDCTL_MCASP0                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL7_OFFSET )))
#define PSC1_MDCTL_MCASP0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL7_OFFSET)))

#define PSC1_MDCTL8                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL8_OFFSET )))
#define PSC1_MDCTL8_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL8_OFFSET)))
#define PSC1_MDCTL_SATA                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL8_OFFSET )))
#define PSC1_MDCTL_SATA_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL8_OFFSET)))

#define PSC1_MDCTL9                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL9_OFFSET )))
#define PSC1_MDCTL9_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL9_OFFSET)))
#define PSC1_MDCTL_VPIF                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL9_OFFSET )))
#define PSC1_MDCTL_VPIF_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL9_OFFSET)))

#define PSC1_MDCTL10                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL10_OFFSET )))
#define PSC1_MDCTL10_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL10_OFFSET)))
#define PSC1_MDCTL_SPI1                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL10_OFFSET )))
#define PSC1_MDCTL_SPI1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL10_OFFSET)))

#define PSC1_MDCTL11                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL11_OFFSET )))
#define PSC1_MDCTL11_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL11_OFFSET)))
#define PSC1_MDCTL_I2C1                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL11_OFFSET )))
#define PSC1_MDCTL_I2C1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL11_OFFSET)))

#define PSC1_MDCTL12                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL12_OFFSET )))
#define PSC1_MDCTL12_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL12_OFFSET)))
#define PSC1_MDCTL_UART1                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL12_OFFSET )))
#define PSC1_MDCTL_UART1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL12_OFFSET)))

#define PSC1_MDCTL13                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL13_OFFSET )))
#define PSC1_MDCTL13_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL13_OFFSET)))
#define PSC1_MDCTL_UART2                   (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL13_OFFSET )))
#define PSC1_MDCTL_UART2_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL13_OFFSET)))

#define PSC1_MDCTL14                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL14_OFFSET )))
#define PSC1_MDCTL14_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL14_OFFSET)))
#define PSC1_MDCTL_MCBSP0                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL14_OFFSET )))
#define PSC1_MDCTL_MCBSP0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL14_OFFSET)))

#define PSC1_MDCTL15                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL15_OFFSET )))
#define PSC1_MDCTL15_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL15_OFFSET)))
#define PSC1_MDCTL_MCBSP1                  (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL15_OFFSET )))
#define PSC1_MDCTL_MCBSP1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL15_OFFSET)))

#define PSC1_MDCTL16                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL16_OFFSET )))
#define PSC1_MDCTL16_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL16_OFFSET)))
#define PSC1_MDCTL_LCDC                   (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL16_OFFSET )))
#define PSC1_MDCTL_LCDC_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL16_OFFSET)))

#define PSC1_MDCTL17                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL17_OFFSET )))
#define PSC1_MDCTL17_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL17_OFFSET)))
#define PSC1_MDCTL_EPWM                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL17_OFFSET )))
#define PSC1_MDCTL_EPWM_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL17_OFFSET)))

#define PSC1_MDCTL18                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL18_OFFSET )))
#define PSC1_MDCTL18_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL18_OFFSET)))
#define PSC1_MDCTL_MMCSD1                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL18_OFFSET )))
#define PSC1_MDCTL_MMCSD1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL18_OFFSET)))

#define PSC1_MDCTL19                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL19_OFFSET )))
#define PSC1_MDCTL19_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL19_OFFSET)))
#define PSC1_MDCTL_UPP                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL19_OFFSET )))
#define PSC1_MDCTL_UPP_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL19_OFFSET)))

#define PSC1_MDCTL20                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL20_OFFSET )))
#define PSC1_MDCTL20_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL20_OFFSET)))
#define PSC1_MDCTL_ECAP                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL20_OFFSET )))
#define PSC1_MDCTL_ECAP_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL20_OFFSET)))

#define PSC1_MDCTL21                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL21_OFFSET )))
#define PSC1_MDCTL21_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL21_OFFSET)))
#define PSC1_MDCTL_EDMA_TC2                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL21_OFFSET )))
#define PSC1_MDCTL_EDMA_TC2_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL21_OFFSET)))

#define PSC1_MDCTL22                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL22_OFFSET )))
#define PSC1_MDCTL22_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL22_OFFSET)))
#define PSC1_MDCTL_Reserved0                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL22_OFFSET )))
#define PSC1_MDCTL_Reserved0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL22_OFFSET)))

#define PSC1_MDCTL23                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL23_OFFSET )))
#define PSC1_MDCTL23_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL23_OFFSET)))
#define PSC1_MDCTL_Reserved1                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL23_OFFSET )))
#define PSC1_MDCTL_Reserved1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL23_OFFSET)))

#define PSC1_MDCTL24                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL24_OFFSET )))
#define PSC1_MDCTL24_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL24_OFFSET)))
#define PSC1_MDCTL_SCR_F0                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL24_OFFSET )))
#define PSC1_MDCTL_SCR_F0_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL24_OFFSET)))

#define PSC1_MDCTL25                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL25_OFFSET )))
#define PSC1_MDCTL25_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL25_OFFSET)))
#define PSC1_MDCTL_SCR_F1                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL25_OFFSET )))
#define PSC1_MDCTL_SCR_F1_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL25_OFFSET)))

#define PSC1_MDCTL26                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL26_OFFSET )))
#define PSC1_MDCTL26_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL26_OFFSET)))
#define PSC1_MDCTL_SCR_F2                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL26_OFFSET )))
#define PSC1_MDCTL_SCR_F2_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL26_OFFSET)))

#define PSC1_MDCTL27                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL27_OFFSET )))
#define PSC1_MDCTL27_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL27_OFFSET)))
#define PSC1_MDCTL_SCR_F6                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL27_OFFSET )))
#define PSC1_MDCTL_SCR_F6_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL27_OFFSET)))

#define PSC1_MDCTL28                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL28_OFFSET )))
#define PSC1_MDCTL28_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL28_OFFSET)))
#define PSC1_MDCTL_SCR_F7                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL28_OFFSET )))
#define PSC1_MDCTL_SCR_F7_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL28_OFFSET)))

#define PSC1_MDCTL29                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL29_OFFSET )))
#define PSC1_MDCTL29_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL29_OFFSET)))
#define PSC1_MDCTL_SCR_F8                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL29_OFFSET )))
#define PSC1_MDCTL_SCR_F8_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL29_OFFSET)))

#define PSC1_MDCTL30                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL30_OFFSET )))
#define PSC1_MDCTL30_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL30_OFFSET)))
#define PSC1_MDCTL_BR_F7                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL30_OFFSET )))
#define PSC1_MDCTL_BR_F7_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL30_OFFSET)))

#define PSC1_MDCTL31                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL31_OFFSET )))
#define PSC1_MDCTL31_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL31_OFFSET)))
#define PSC1_MDCTL_SHARED_RAM                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL31_OFFSET )))
#define PSC1_MDCTL_SHARED_RAM_R                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL31_OFFSET)))

#define PSC1_MDCTL(n)                    (((PSC1_MDCTL_TypeDef*)(PSC1_BASE+PSC_MDCTL0_OFFSET +((n)*4) )))
#define PSC1_MDCTL_R(n)                  (*((__IO uint32_t *)(PSC1_BASE+PSC_MDCTL0_OFFSET +((n)*4))))


/*--------*/
#define PSC_MDCTL_R_NEXT_MASK        ((uint32_t)0x00000007)
#define PSC_MDCTL_R_NEXT_SHIFT         (0)

#define PSC_MDCTL_NEXT_MASK          ((uint32_t)0x00000007)
/*--------*/
/*--------*/
#define PSC0_MDCTL_R_LRST_MASK        ((uint32_t)0x00000100)
#define PSC0_MDCTL_R_LRST_SHIFT         (8)

#define PSC0_MDCTL_LRST_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC0_MDCTL_R_EMURSTIE_MASK        ((uint32_t)0x00000200)
#define PSC0_MDCTL_R_EMURSTIE_SHIFT         (9)

#define PSC0_MDCTL_EMURSTIE_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC0_MDCTL_R_EMUIHBIE_MASK        ((uint32_t)0x00000400)
#define PSC0_MDCTL_R_EMUIHBIE_SHIFT         (10)

#define PSC0_MDCTL_EMUIHBIE_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define PSC_MDCTL_R_FORCE_MASK        ((uint32_t)0x10000000)
#define PSC_MDCTL_R_FORCE_SHIFT         (31)

#define PSC_MDCTL_FORCE_MASK          ((uint32_t)0x00000001)
/*--------*/



typedef enum
{
     LPSC0_enEDMA_CC0   =0,
     LPSC0_enEDMA_TC0    =1,
     LPSC0_enEDMA_TC1    =2,
     LPSC0_enEMIFA       =3,   /*PSC0*/
     LPSC0_enSPI0        =4,   /*PSC0*/
     LPSC0_enMMCSD0      =5,   /*PSC0*/
     LPSC0_enReserved0   =6,
     LPSC0_enReserved1   =7,   /*PSC0*/
     LPSC0_enReserved2   =8,   /*PSC0*/
     LPSC0_enUART0       =9,   /*PSC0*/
     LPSC0_enSCR0        =10,
     LPSC0_enSCR1        =11,
     LPSC0_enSCR2        =12,
     LPSC0_enPRUSS       =13,
     LPSC0_enReserved3   =14,  /*PSC0*/
     LPSC0_enDSP         =15,  /*PSC0*/

}Lpsc0_nNumber;

typedef enum
{
     LPSC1_enEDMA_CC1    =0,
     LPSC1_enUSB20       =1,   /*PSC1*/
     LPSC1_enUSB11       =2,   /*PSC1*/
     LPSC1_enGPIO        =3,   /*PSC1*/
     LPSC1_enUHPI        =4,   /*PSC1*/
     LPSC1_enEMAC        =5,   /*PSC1*/
     LPSC1_enDDR         =6,   /*PSC1*/
     LPSC1_enMCASP0      =7,   /*PSC1*/
     LPSC1_enSATA        =8,   /*PSC1*/
     LPSC1_enVPIF        =9,   /*PSC1*/
     LPSC1_enSPI1        =10,  /*PSC1*/
     LPSC1_enI2C1        =11,  /*PSC1*/
     LPSC1_enUART1       =12,  /*PSC1*/
     LPSC1_enUART2       =13,  /*PSC1*/
     LPSC1_enMCBSP0      =14,  /*PSC1*/
     LPSC1_enMCBSP1      =15,  /*PSC1*/
     LPSC1_enLCDC        =16,  /*PSC1*/
     LPSC1_enEPWM        =17,  /*PSC1*/
     LPSC1_enMMCSD1      =18,
     LPSC1_enUPP         =19,
     LPSC1_enECAP        =20,
     LPSC1_enEDMA_TC2    =21,
     LPSC1_enReserved0   =22,
     LPSC1_enReserved1   =23,
     LPSC1_enSCR_F0      =24,
     LPSC1_enSCR_F1      =25,
     LPSC1_enSCR_F2      =26,
     LPSC1_enSCR_F6      =27,
     LPSC1_enSCR_F7      =28,
     LPSC1_enSCR_F8      =29,
     LPSC1_enBR_F7       =30,
     LPSC1_enSHARED_RAM  =31,
}Lpsc1_nNumber;



typedef enum
{
    DOMAIN_enD0 = 0,
    DOMAIN_enD1 ,
}Psc_nDomain;

typedef enum
{
    PSC_enOK = 0,
    PSC_enERROR ,
}Psc_nStatus;

#pragma FUNC_ALWAYS_INLINE( PSC__enInit)
#pragma FUNC_ALWAYS_INLINE( PSC0__enEnableDsp)
#pragma FUNC_ALWAYS_INLINE( PSC0__enEnableCore)
#pragma FUNC_ALWAYS_INLINE( PSC0__enEnableLPSC)
#pragma FUNC_ALWAYS_INLINE( PSC0__enSyncReset)
#pragma FUNC_ALWAYS_INLINE( PSC1__enForceLPSC)
#pragma FUNC_ALWAYS_INLINE( PSC1__enEnableLPSC)
#pragma FUNC_ALWAYS_INLINE( PSC1__enSyncReset)

extern Psc_nStatus PSC__enInit(void);
extern Psc_nStatus PSC0__enEnableDsp(void);
extern Psc_nStatus PSC0__enEnableCore(Psc_nDomain nPd, Lpsc0_nNumber nLpscNum);
extern Psc_nStatus PSC0__enEnableLPSC(Psc_nDomain nPd, Lpsc0_nNumber nLpscNum);
extern Psc_nStatus PSC0__enSyncReset(Psc_nDomain nPd, Lpsc0_nNumber nLpscNum);
extern Psc_nStatus PSC1__enForceLPSC(Lpsc1_nNumber nLpscNum);
extern Psc_nStatus PSC1__enEnableLPSC(Psc_nDomain nPd, Lpsc1_nNumber nLpscNum);
extern Psc_nStatus PSC1__enSyncReset(Psc_nDomain nPd, Lpsc1_nNumber nLpscNum);

#endif /* INCLUDE_PSC_H_ */
