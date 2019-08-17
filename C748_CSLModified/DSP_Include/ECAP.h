/*
 * ECAP.h
 *
 *  Created on: 18/07/2019
 *      Author: Lalo
 */

#ifndef DSP_INCLUDE_ECAP_H_
#define DSP_INCLUDE_ECAP_H_

#include "Core.h"
#include <stdint.h>


#define ECAP0_BASE            ((uint32_t)0x01F06000)
#define ECAP1_BASE            ((uint32_t)0x01F07000)
#define ECAP2_BASE            ((uint32_t)0x01F08000)


typedef __IO struct
{
    __IO uint32_t TSCTR       :32;
}ECAP_TSCTR_TypeDef;

typedef __IO struct
{
    __IO uint32_t CTRPHS       :32;
}ECAP_CTRPHS_TypeDef;

typedef __IO struct
{
    __IO uint32_t CAP1       :32;
}ECAP_CAP1_TypeDef;

typedef __IO struct
{
    __IO uint32_t CAP2       :32;
}ECAP_CAP2_TypeDef;

typedef __IO struct
{
    __IO uint32_t CAP3       :32;
}ECAP_CAP3_TypeDef;

typedef __IO struct
{
    __IO uint32_t CAP4       :32;
}ECAP_CAP4_TypeDef;

typedef __IO struct
{
    __IO uint16_t CAP1POL       :1;
    __IO uint16_t CTRRST1       :1;
    __IO uint16_t CAP2POL       :1;
    __IO uint16_t CTRRST2       :1;
    __IO uint16_t CAP3POL       :1;
    __IO uint16_t CTRRST3       :1;
    __IO uint16_t CAP4POL       :1;
    __IO uint16_t CTRRST4       :1;
    __IO uint16_t CAPLDEN       :1;
    __IO uint16_t PRESCALE      :5;
    __IO uint16_t FREE_SOFT     :2;
}ECAP_ECCTL1_TypeDef;

typedef __IO struct
{
    __IO uint16_t CONT_ONESHT   :1;
    __IO uint16_t STOP_WRAP     :2;
    __IO uint16_t RE_ARM        :1;
    __IO uint16_t TSCTRSTOP     :1;
    __IO uint16_t SYNCI_EN      :1;
    __IO uint16_t SYNCO_SEL     :2;
    __IO uint16_t SWSYNC        :1;
    __IO uint16_t CAP_APWM      :1;
    __IO uint16_t APWMPOL       :1;
         uint16_t reserved0     :5;
}ECAP_ECCTL2_TypeDef;

typedef __IO struct
{
         uint16_t reserved0     :1;
    __IO uint16_t CEVT1         :1;
    __IO uint16_t CEVT2         :1;
    __IO uint16_t CEVT3         :1;
    __IO uint16_t CEVT4         :1;
    __IO uint16_t CTROVF        :1;
    __IO uint16_t CTR_PRD       :1;
    __IO uint16_t CTR_CMP       :1;
         uint16_t reserved1     :8;
}ECAP_ECEINT_TypeDef;

typedef __IO struct
{
    __IO uint16_t INT           :1;
    __IO uint16_t CEVT1         :1;
    __IO uint16_t CEVT2         :1;
    __IO uint16_t CEVT3         :1;
    __IO uint16_t CEVT4         :1;
    __IO uint16_t CTROVF        :1;
    __IO uint16_t CTR_PRD       :1;
    __IO uint16_t CTR_CMP       :1;
         uint16_t reserved1     :8;
}ECAP_ECFLG_TypeDef;

typedef __IO struct
{
    __IO uint16_t INT           :1;
    __IO uint16_t CEVT1         :1;
    __IO uint16_t CEVT2         :1;
    __IO uint16_t CEVT3         :1;
    __IO uint16_t CEVT4         :1;
    __IO uint16_t CTROVF        :1;
    __IO uint16_t CTR_PRD       :1;
    __IO uint16_t CTR_CMP       :1;
         uint16_t reserved1     :8;
}ECAP_ECCLR_TypeDef;

typedef __IO struct
{
    __IO uint16_t INT           :1;
    __IO uint16_t CEVT1         :1;
    __IO uint16_t CEVT2         :1;
    __IO uint16_t CEVT3         :1;
    __IO uint16_t CEVT4         :1;
    __IO uint16_t CTROVF        :1;
    __IO uint16_t CTR_PRD       :1;
    __IO uint16_t CTR_CMP       :1;
         uint16_t reserved1     :8;
}ECAP_ECFRC_TypeDef;

typedef __IO struct
{
    __I uint32_t REV       :32;
}ECAP_REVID_TypeDef;

typedef struct  {

    union
    {
        __IO uint32_t            TSCTR;
        ECAP_TSCTR_TypeDef      TSCTR_Bit;
    };
    union
    {
        __IO uint32_t            CTRPHS;
        ECAP_CTRPHS_TypeDef      CTRPHS_Bit;
    };
    union
    {
        __IO uint32_t            CAP[4];
        ECAP_CAP1_TypeDef        CAP_Bit[4];
    };
    uint32_t reserved0[4];
    union
    {
        __IO uint16_t            ECCTL1;
        ECAP_ECCTL1_TypeDef      ECCTL1_Bit;
    };
    union
    {
        __IO uint16_t            ECCTL2;
        ECAP_ECCTL2_TypeDef      ECCTL2_Bit;
    };
    union
    {
        __IO uint16_t            ECEINT;
        ECAP_ECEINT_TypeDef      ECEINT_Bit;
    };
    union
    {
        __IO uint16_t            ECFLG;
        ECAP_ECFLG_TypeDef       ECFLG_Bit;
    };
    union
    {
        __IO uint16_t            ECCLR;
        ECAP_ECCLR_TypeDef       ECCLR_Bit;
    };
    union
    {
        __IO uint16_t            ECFRC;
        ECAP_ECFRC_TypeDef       ECFRC_Bit;
    };
    uint32_t reserved1[10];
    union
    {
        __IO uint16_t            REVID;
        ECAP_REVID_TypeDef       REVID_Bit;
    };
} ECAP_TypeDef;

#define ECAP0            (((ECAP_TypeDef*)(ECAP0_BASE)))
#define ECAP0_R(offset)  (*((__IO uint32_t *)(ECAP0_BASE+offset)))
#define ECAP1            (((ECAP_TypeDef*)(ECAP1_BASE)))
#define ECAP1_R(offset)  (*((__IO uint32_t *)(ECAP1_BASE+offset)))
#define ECAP2            (((ECAP_TypeDef*)(ECAP2_BASE)))
#define ECAP2_R(offset)  (*((__IO uint32_t *)(ECAP2_BASE+offset)))

#define ECAP_TSCTR_OFFSET                 ((uint32_t)0x0000)
#define ECAP_CTRPHS_OFFSET                ((uint32_t)0x0004)
#define ECAP_CAP1_OFFSET                  ((uint32_t)0x0008)
#define ECAP_CAP2_OFFSET                  ((uint32_t)0x000C)
#define ECAP_CAP3_OFFSET                  ((uint32_t)0x0010)
#define ECAP_CAP4_OFFSET                  ((uint32_t)0x0014)
#define ECAP_ECCTL1_OFFSET                ((uint32_t)0x0028)
#define ECAP_ECCTL2_OFFSET                ((uint32_t)0x002A)
#define ECAP_ECEINT_OFFSET                ((uint32_t)0x002C)
#define ECAP_ECFLG_OFFSET                 ((uint32_t)0x002E)
#define ECAP_ECCLR_OFFSET                 ((uint32_t)0x0030)
#define ECAP_ECFRC_OFFSET                 ((uint32_t)0x0032)
#define ECAP_REVID_OFFSET                 ((uint32_t)0x005C)


/**********************************************************************************************
************************************** 1 TSCTR ***********************************************
**********************************************************************************************/
#define ECAP0_TSCTR                    (((ECAP_TSCTR_TypeDef*)(ECAP0_BASE+ECAP_TSCTR_OFFSET )))
#define ECAP0_TSCTR_R                  (*((__IO uint32_t *)(ECAP0_BASE+ECAP_TSCTR_OFFSET)))
#define ECAP1_TSCTR                    (((ECAP_TSCTR_TypeDef*)(ECAP1_BASE+ECAP_TSCTR_OFFSET )))
#define ECAP1_TSCTR_R                  (*((__IO uint32_t *)(ECAP1_BASE+ECAP_TSCTR_OFFSET)))
#define ECAP2_TSCTR                    (((ECAP_TSCTR_TypeDef*)(ECAP2_BASE+ECAP_TSCTR_OFFSET )))
#define ECAP2_TSCTR_R                  (*((__IO uint32_t *)(ECAP2_BASE+ECAP_TSCTR_OFFSET)))

/*--------*/
#define ECAP_TSCTR_R_TSCTR_MASK        ((uint32_t)0xFFFFFFFF)
#define ECAP_TSCTR_R_TSCTR_SHIFT         (0)

#define ECAP_TSCTR_TSCTR_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 2 CTRPHS ***********************************************
**********************************************************************************************/
#define ECAP0_CTRPHS                    (((ECAP_CTRPHS_TypeDef*)(ECAP0_BASE+ECAP_CTRPHS_OFFSET )))
#define ECAP0_CTRPHS_R                  (*((__IO uint32_t *)(ECAP0_BASE+ECAP_CTRPHS_OFFSET)))
#define ECAP1_CTRPHS                    (((ECAP_CTRPHS_TypeDef*)(ECAP1_BASE+ECAP_CTRPHS_OFFSET )))
#define ECAP1_CTRPHS_R                  (*((__IO uint32_t *)(ECAP1_BASE+ECAP_CTRPHS_OFFSET)))
#define ECAP2_CTRPHS                    (((ECAP_CTRPHS_TypeDef*)(ECAP2_BASE+ECAP_CTRPHS_OFFSET )))
#define ECAP2_CTRPHS_R                  (*((__IO uint32_t *)(ECAP2_BASE+ECAP_CTRPHS_OFFSET)))

/*--------*/
#define ECAP_CTRPHS_R_CTRPHS_MASK        ((uint32_t)0xFFFFFFFF)
#define ECAP_CTRPHS_R_CTRPHS_SHIFT         (0)

#define ECAP_CTRPHS_CTRPHS_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 3 CAP1 ***********************************************
**********************************************************************************************/
#define ECAP0_CAP1                    (((ECAP_CAP1_TypeDef*)(ECAP0_BASE+ECAP_CAP1_OFFSET )))
#define ECAP0_CAP1_R                  (*((__IO uint32_t *)(ECAP0_BASE+ECAP_CAP1_OFFSET)))
#define ECAP1_CAP1                    (((ECAP_CAP1_TypeDef*)(ECAP1_BASE+ECAP_CAP1_OFFSET )))
#define ECAP1_CAP1_R                  (*((__IO uint32_t *)(ECAP1_BASE+ECAP_CAP1_OFFSET)))
#define ECAP2_CAP1                    (((ECAP_CAP1_TypeDef*)(ECAP2_BASE+ECAP_CAP1_OFFSET )))
#define ECAP2_CAP1_R                  (*((__IO uint32_t *)(ECAP2_BASE+ECAP_CAP1_OFFSET)))

/*--------*/
#define ECAP_CAP1_R_CAP1_MASK        ((uint32_t)0xFFFFFFFF)
#define ECAP_CAP1_R_CAP1_SHIFT         (0)

#define ECAP_CAP1_CAP1_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 4 CAP2 ***********************************************
**********************************************************************************************/
#define ECAP0_CAP2                    (((ECAP_CAP2_TypeDef*)(ECAP0_BASE+ECAP_CAP2_OFFSET )))
#define ECAP0_CAP2_R                  (*((__IO uint32_t *)(ECAP0_BASE+ECAP_CAP2_OFFSET)))
#define ECAP1_CAP2                    (((ECAP_CAP2_TypeDef*)(ECAP1_BASE+ECAP_CAP2_OFFSET )))
#define ECAP1_CAP2_R                  (*((__IO uint32_t *)(ECAP1_BASE+ECAP_CAP2_OFFSET)))
#define ECAP2_CAP2                    (((ECAP_CAP2_TypeDef*)(ECAP2_BASE+ECAP_CAP2_OFFSET )))
#define ECAP2_CAP2_R                  (*((__IO uint32_t *)(ECAP2_BASE+ECAP_CAP2_OFFSET)))

/*--------*/
#define ECAP_CAP2_R_CAP2_MASK        ((uint32_t)0xFFFFFFFF)
#define ECAP_CAP2_R_CAP2_SHIFT         (0)

#define ECAP_CAP2_CAP2_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 5 CAP3 ***********************************************
**********************************************************************************************/
#define ECAP0_CAP3                    (((ECAP_CAP3_TypeDef*)(ECAP0_BASE+ECAP_CAP3_OFFSET )))
#define ECAP0_CAP3_R                  (*((__IO uint32_t *)(ECAP0_BASE+ECAP_CAP3_OFFSET)))
#define ECAP1_CAP3                    (((ECAP_CAP3_TypeDef*)(ECAP1_BASE+ECAP_CAP3_OFFSET )))
#define ECAP1_CAP3_R                  (*((__IO uint32_t *)(ECAP1_BASE+ECAP_CAP3_OFFSET)))
#define ECAP2_CAP3                    (((ECAP_CAP3_TypeDef*)(ECAP2_BASE+ECAP_CAP3_OFFSET )))
#define ECAP2_CAP3_R                  (*((__IO uint32_t *)(ECAP2_BASE+ECAP_CAP3_OFFSET)))

/*--------*/
#define ECAP_CAP3_R_CAP3_MASK        ((uint32_t)0xFFFFFFFF)
#define ECAP_CAP3_R_CAP3_SHIFT         (0)

#define ECAP_CAP3_CAP3_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 6 CAP4 ***********************************************
**********************************************************************************************/
#define ECAP0_CAP4                    (((ECAP_CAP4_TypeDef*)(ECAP0_BASE+ECAP_CAP4_OFFSET )))
#define ECAP0_CAP4_R                  (*((__IO uint32_t *)(ECAP0_BASE+ECAP_CAP4_OFFSET)))
#define ECAP1_CAP4                    (((ECAP_CAP4_TypeDef*)(ECAP1_BASE+ECAP_CAP4_OFFSET )))
#define ECAP1_CAP4_R                  (*((__IO uint32_t *)(ECAP1_BASE+ECAP_CAP4_OFFSET)))
#define ECAP2_CAP4                    (((ECAP_CAP4_TypeDef*)(ECAP2_BASE+ECAP_CAP4_OFFSET )))
#define ECAP2_CAP4_R                  (*((__IO uint32_t *)(ECAP2_BASE+ECAP_CAP4_OFFSET)))

/*--------*/
#define ECAP_CAP4_R_CAP4_MASK        ((uint32_t)0xFFFFFFFF)
#define ECAP_CAP4_R_CAP4_SHIFT         (0)

#define ECAP_CAP4_CAP4_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 7 ECCTL1 ***********************************************
**********************************************************************************************/
#define ECAP0_ECCTL1                    (((ECAP_ECCTL1_TypeDef*)(ECAP0_BASE+ECAP_ECCTL1_OFFSET )))
#define ECAP0_ECCTL1_R                  (*((__IO uint32_t *)(ECAP0_BASE+ECAP_ECCTL1_OFFSET)))
#define ECAP1_ECCTL1                    (((ECAP_ECCTL1_TypeDef*)(ECAP1_BASE+ECAP_ECCTL1_OFFSET )))
#define ECAP1_ECCTL1_R                  (*((__IO uint32_t *)(ECAP1_BASE+ECAP_ECCTL1_OFFSET)))
#define ECAP2_ECCTL1                    (((ECAP_ECCTL1_TypeDef*)(ECAP2_BASE+ECAP_ECCTL1_OFFSET )))
#define ECAP2_ECCTL1_R                  (*((__IO uint32_t *)(ECAP2_BASE+ECAP_ECCTL1_OFFSET)))

/*--------*/
#define ECAP_ECCTL1_R_CAP1POL_MASK        ((uint32_t)0x00000001)
#define ECAP_ECCTL1_R_CAP1POL_SHIFT         (0)

#define ECAP_ECCTL1_CAP1POL_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL1_R_CTRRST1_MASK        ((uint32_t)0x00000002)
#define ECAP_ECCTL1_R_CTRRST1_SHIFT         (1)

#define ECAP_ECCTL1_CTRRST1_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL1_R_CAP2POL_MASK        ((uint32_t)0x00000004)
#define ECAP_ECCTL1_R_CAP2POL_SHIFT         (2)

#define ECAP_ECCTL1_CAP2POL_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL1_R_CTRRST2_MASK        ((uint32_t)0x00000008)
#define ECAP_ECCTL1_R_CTRRST2_SHIFT         (3)

#define ECAP_ECCTL1_CTRRST2_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL1_R_CAP3POL_MASK        ((uint32_t)0x00000010)
#define ECAP_ECCTL1_R_CAP3POL_SHIFT         (4)

#define ECAP_ECCTL1_CAP3POL_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL1_R_CTRRST3_MASK        ((uint32_t)0x00000020)
#define ECAP_ECCTL1_R_CTRRST3_SHIFT         (5)

#define ECAP_ECCTL1_CTRRST3_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL1_R_CAP4POL_MASK        ((uint32_t)0x00000040)
#define ECAP_ECCTL1_R_CAP4POL_SHIFT         (6)

#define ECAP_ECCTL1_CAP4POL_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL1_R_CTRRST4_MASK        ((uint32_t)0x00000080)
#define ECAP_ECCTL1_R_CTRRST4_SHIFT         (7)

#define ECAP_ECCTL1_CTRRST4_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL1_R_CAPLDEN_MASK        ((uint32_t)0x00000100)
#define ECAP_ECCTL1_R_CAPLDEN_SHIFT         (8)

#define ECAP_ECCTL1_CAPLDEN_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL1_R_PRESCALE_MASK        ((uint32_t)0x00003E00)
#define ECAP_ECCTL1_R_PRESCALE_SHIFT         (9)

#define ECAP_ECCTL1_PRESCALE_MASK          ((uint32_t)0x0000001F)
/*--------*/

/*--------*/
#define ECAP_ECCTL1_R_FREE_SOFT_MASK        ((uint32_t)0x0000C000)
#define ECAP_ECCTL1_R_FREE_SOFT_SHIFT         (14)

#define ECAP_ECCTL1_FREE_SOFT_MASK          ((uint32_t)0x00000003)
/*--------*/

/**********************************************************************************************
************************************** 8 ECCTL2 ***********************************************
**********************************************************************************************/
#define ECAP0_ECCTL2                    (((ECAP_ECCTL2_TypeDef*)(ECAP0_BASE+ECAP_ECCTL2_OFFSET )))
#define ECAP0_ECCTL2_R                  (*((__IO uint32_t *)(ECAP0_BASE+ECAP_ECCTL2_OFFSET)))
#define ECAP1_ECCTL2                    (((ECAP_ECCTL2_TypeDef*)(ECAP1_BASE+ECAP_ECCTL2_OFFSET )))
#define ECAP1_ECCTL2_R                  (*((__IO uint32_t *)(ECAP1_BASE+ECAP_ECCTL2_OFFSET)))
#define ECAP2_ECCTL2                    (((ECAP_ECCTL2_TypeDef*)(ECAP2_BASE+ECAP_ECCTL2_OFFSET )))
#define ECAP2_ECCTL2_R                  (*((__IO uint32_t *)(ECAP2_BASE+ECAP_ECCTL2_OFFSET)))

/*--------*/
#define ECAP_ECCTL2_R_CONT_ONESHT_MASK          ((uint32_t)0x00000001)
#define ECAP_ECCTL2_R_CONT_ONESHT_SHIFT         (0)

#define ECAP_ECCTL2_CONT_ONESHT_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL2_R_STOP_WRAP_MASK          ((uint32_t)0x00000006)
#define ECAP_ECCTL2_R_STOP_WRAP_SHIFT         (1)

#define ECAP_ECCTL2_STOP_WRAP_MASK            ((uint32_t)0x00000003)
/*--------*/

/*--------*/
#define ECAP_ECCTL2_R_RE_ARM_MASK          ((uint32_t)0x00000008)
#define ECAP_ECCTL2_R_RE_ARM_SHIFT         (3)

#define ECAP_ECCTL2_RE_ARM_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL2_R_TSCTRSTOP_MASK          ((uint32_t)0x00000010)
#define ECAP_ECCTL2_R_TSCTRSTOP_SHIFT         (4)

#define ECAP_ECCTL2_TSCTRSTOP_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL2_R_SYNCI_EN_MASK          ((uint32_t)0x00000020)
#define ECAP_ECCTL2_R_SYNCI_EN_SHIFT         (5)

#define ECAP_ECCTL2_SYNCI_EN_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL2_R_SYNCO_SEL_MASK          ((uint32_t)0x000000C0)
#define ECAP_ECCTL2_R_SYNCO_SEL_SHIFT         (6)

#define ECAP_ECCTL2_SYNCO_SEL_MASK            ((uint32_t)0x00000003)
/*--------*/

/*--------*/
#define ECAP_ECCTL2_R_SWSYNC_MASK          ((uint32_t)0x00000100)
#define ECAP_ECCTL2_R_SWSYNC_SHIFT         (8)

#define ECAP_ECCTL2_SWSYNC_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL2_R_CAP_APWM_MASK          ((uint32_t)0x00000200)
#define ECAP_ECCTL2_R_CAP_APWM_SHIFT         (9)

#define ECAP_ECCTL2_CAP_APWM_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCTL2_R_APWMPOL_MASK          ((uint32_t)0x00000400)
#define ECAP_ECCTL2_R_APWMPOL_SHIFT         (10)

#define ECAP_ECCTL2_APWMPOL_MASK            ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 9 ECEINT ***********************************************
**********************************************************************************************/
#define ECAP0_ECEINT                    (((ECAP_ECEINT_TypeDef*)(ECAP0_BASE+ECAP_ECEINT_OFFSET )))
#define ECAP0_ECEINT_R                  (*((__IO uint32_t *)(ECAP0_BASE+ECAP_ECEINT_OFFSET)))
#define ECAP1_ECEINT                    (((ECAP_ECEINT_TypeDef*)(ECAP1_BASE+ECAP_ECEINT_OFFSET )))
#define ECAP1_ECEINT_R                  (*((__IO uint32_t *)(ECAP1_BASE+ECAP_ECEINT_OFFSET)))
#define ECAP2_ECEINT                    (((ECAP_ECEINT_TypeDef*)(ECAP2_BASE+ECAP_ECEINT_OFFSET )))
#define ECAP2_ECEINT_R                  (*((__IO uint32_t *)(ECAP2_BASE+ECAP_ECEINT_OFFSET)))

/*--------*/
#define ECAP_ECEINT_R_CEVT1_MASK          ((uint32_t)0x00000002)
#define ECAP_ECEINT_R_CEVT1_SHIFT         (1)

#define ECAP_ECEINT_CEVT1_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECEINT_R_CEVT2_MASK          ((uint32_t)0x00000004)
#define ECAP_ECEINT_R_CEVT2_SHIFT         (2)

#define ECAP_ECEINT_CEVT2_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECEINT_R_CEVT3_MASK          ((uint32_t)0x00000008)
#define ECAP_ECEINT_R_CEVT3_SHIFT         (3)

#define ECAP_ECEINT_CEVT3_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECEINT_R_CEVT4_MASK          ((uint32_t)0x00000010)
#define ECAP_ECEINT_R_CEVT4_SHIFT         (4)

#define ECAP_ECEINT_CEVT4_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECEINT_R_CTROVF_MASK          ((uint32_t)0x00000020)
#define ECAP_ECEINT_R_CTROVF_SHIFT         (5)

#define ECAP_ECEINT_CTROVF_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECEINT_R_CTR_PRD_MASK          ((uint32_t)0x00000040)
#define ECAP_ECEINT_R_CTR_PRD_SHIFT         (6)

#define ECAP_ECEINT_CTR_PRD_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECEINT_R_CTR_CMP_MASK          ((uint32_t)0x00000080)
#define ECAP_ECEINT_R_CTR_CMP_SHIFT         (7)

#define ECAP_ECEINT_CTR_CMP_MASK            ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 10 ECFLG ***********************************************
**********************************************************************************************/
#define ECAP0_ECFLG                    (((ECAP_ECFLG_TypeDef*)(ECAP0_BASE+ECAP_ECFLG_OFFSET )))
#define ECAP0_ECFLG_R                  (*((__IO uint32_t *)(ECAP0_BASE+ECAP_ECFLG_OFFSET)))
#define ECAP1_ECFLG                    (((ECAP_ECFLG_TypeDef*)(ECAP1_BASE+ECAP_ECFLG_OFFSET )))
#define ECAP1_ECFLG_R                  (*((__IO uint32_t *)(ECAP1_BASE+ECAP_ECFLG_OFFSET)))
#define ECAP2_ECFLG                    (((ECAP_ECFLG_TypeDef*)(ECAP2_BASE+ECAP_ECFLG_OFFSET )))
#define ECAP2_ECFLG_R                  (*((__IO uint32_t *)(ECAP2_BASE+ECAP_ECFLG_OFFSET)))

/*--------*/
#define ECAP_ECFLG_R_INT_MASK          ((uint32_t)0x00000001)
#define ECAP_ECFLG_R_INT_SHIFT         (0)

#define ECAP_ECFLG_INT_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFLG_R_CEVT1_MASK          ((uint32_t)0x00000002)
#define ECAP_ECFLG_R_CEVT1_SHIFT         (1)

#define ECAP_ECFLG_CEVT1_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFLG_R_CEVT2_MASK          ((uint32_t)0x00000004)
#define ECAP_ECFLG_R_CEVT2_SHIFT         (2)

#define ECAP_ECFLG_CEVT2_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFLG_R_CEVT3_MASK          ((uint32_t)0x00000008)
#define ECAP_ECFLG_R_CEVT3_SHIFT         (3)

#define ECAP_ECFLG_CEVT3_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFLG_R_CEVT4_MASK          ((uint32_t)0x00000010)
#define ECAP_ECFLG_R_CEVT4_SHIFT         (4)

#define ECAP_ECFLG_CEVT4_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFLG_R_CTROVF_MASK          ((uint32_t)0x00000020)
#define ECAP_ECFLG_R_CTROVF_SHIFT         (5)

#define ECAP_ECFLG_CTROVF_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFLG_R_CTR_PRD_MASK          ((uint32_t)0x00000040)
#define ECAP_ECFLG_R_CTR_PRD_SHIFT         (6)

#define ECAP_ECFLG_CTR_PRD_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFLG_R_CTR_CMP_MASK          ((uint32_t)0x00000080)
#define ECAP_ECFLG_R_CTR_CMP_SHIFT         (7)

#define ECAP_ECFLG_CTR_CMP_MASK            ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 11 ECCLR ***********************************************
**********************************************************************************************/
#define ECAP0_ECCLR                    (((ECAP_ECCLR_TypeDef*)(ECAP0_BASE+ECAP_ECCLR_OFFSET )))
#define ECAP0_ECCLR_R                  (*((__IO uint32_t *)(ECAP0_BASE+ECAP_ECCLR_OFFSET)))
#define ECAP1_ECCLR                    (((ECAP_ECCLR_TypeDef*)(ECAP1_BASE+ECAP_ECCLR_OFFSET )))
#define ECAP1_ECCLR_R                  (*((__IO uint32_t *)(ECAP1_BASE+ECAP_ECCLR_OFFSET)))
#define ECAP2_ECCLR                    (((ECAP_ECCLR_TypeDef*)(ECAP2_BASE+ECAP_ECCLR_OFFSET )))
#define ECAP2_ECCLR_R                  (*((__IO uint32_t *)(ECAP2_BASE+ECAP_ECCLR_OFFSET)))

/*--------*/
#define ECAP_ECCLR_R_INT_MASK          ((uint32_t)0x00000001)
#define ECAP_ECCLR_R_INT_SHIFT         (0)

#define ECAP_ECCLR_INT_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCLR_R_CEVT1_MASK          ((uint32_t)0x00000002)
#define ECAP_ECCLR_R_CEVT1_SHIFT         (1)

#define ECAP_ECCLR_CEVT1_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCLR_R_CEVT2_MASK          ((uint32_t)0x00000004)
#define ECAP_ECCLR_R_CEVT2_SHIFT         (2)

#define ECAP_ECCLR_CEVT2_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCLR_R_CEVT3_MASK          ((uint32_t)0x00000008)
#define ECAP_ECCLR_R_CEVT3_SHIFT         (3)

#define ECAP_ECCLR_CEVT3_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCLR_R_CEVT4_MASK          ((uint32_t)0x00000010)
#define ECAP_ECCLR_R_CEVT4_SHIFT         (4)

#define ECAP_ECCLR_CEVT4_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCLR_R_CTROVF_MASK          ((uint32_t)0x00000020)
#define ECAP_ECCLR_R_CTROVF_SHIFT         (5)

#define ECAP_ECCLR_CTROVF_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCLR_R_CTR_PRD_MASK          ((uint32_t)0x00000040)
#define ECAP_ECCLR_R_CTR_PRD_SHIFT         (6)

#define ECAP_ECCLR_CTR_PRD_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECCLR_R_CTR_CMP_MASK          ((uint32_t)0x00000080)
#define ECAP_ECCLR_R_CTR_CMP_SHIFT         (7)

#define ECAP_ECCLR_CTR_CMP_MASK            ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 12 ECFRC ***********************************************
**********************************************************************************************/
#define ECAP0_ECFRC                    (((ECAP_ECFRC_TypeDef*)(ECAP0_BASE+ECAP_ECFRC_OFFSET )))
#define ECAP0_ECFRC_R                  (*((__IO uint32_t *)(ECAP0_BASE+ECAP_ECFRC_OFFSET)))
#define ECAP1_ECFRC                    (((ECAP_ECFRC_TypeDef*)(ECAP1_BASE+ECAP_ECFRC_OFFSET )))
#define ECAP1_ECFRC_R                  (*((__IO uint32_t *)(ECAP1_BASE+ECAP_ECFRC_OFFSET)))
#define ECAP2_ECFRC                    (((ECAP_ECFRC_TypeDef*)(ECAP2_BASE+ECAP_ECFRC_OFFSET )))
#define ECAP2_ECFRC_R                  (*((__IO uint32_t *)(ECAP2_BASE+ECAP_ECFRC_OFFSET)))

/*--------*/
#define ECAP_ECFRC_R_INT_MASK          ((uint32_t)0x00000001)
#define ECAP_ECFRC_R_INT_SHIFT         (0)

#define ECAP_ECFRC_INT_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFRC_R_CEVT1_MASK          ((uint32_t)0x00000002)
#define ECAP_ECFRC_R_CEVT1_SHIFT         (1)

#define ECAP_ECFRC_CEVT1_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFRC_R_CEVT2_MASK          ((uint32_t)0x00000004)
#define ECAP_ECFRC_R_CEVT2_SHIFT         (2)

#define ECAP_ECFRC_CEVT2_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFRC_R_CEVT3_MASK          ((uint32_t)0x00000008)
#define ECAP_ECFRC_R_CEVT3_SHIFT         (3)

#define ECAP_ECFRC_CEVT3_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFRC_R_CEVT4_MASK          ((uint32_t)0x00000010)
#define ECAP_ECFRC_R_CEVT4_SHIFT         (4)

#define ECAP_ECFRC_CEVT4_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFRC_R_CTROVF_MASK          ((uint32_t)0x00000020)
#define ECAP_ECFRC_R_CTROVF_SHIFT         (5)

#define ECAP_ECFRC_CTROVF_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFRC_R_CTR_PRD_MASK          ((uint32_t)0x00000040)
#define ECAP_ECFRC_R_CTR_PRD_SHIFT         (6)

#define ECAP_ECFRC_CTR_PRD_MASK            ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define ECAP_ECFRC_R_CTR_CMP_MASK          ((uint32_t)0x00000080)
#define ECAP_ECFRC_R_CTR_CMP_SHIFT         (7)

#define ECAP_ECFRC_CTR_CMP_MASK            ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 1 REVID ***********************************************
**********************************************************************************************/
#define ECAP0_REVID                    (((ECAP_REVID_TypeDef*)(ECAP0_BASE+ECAP_REVID_OFFSET )))
#define ECAP0_REVID_R                  (*((__IO uint32_t *)(ECAP0_BASE+ECAP_REVID_OFFSET)))
#define ECAP1_REVID                    (((ECAP_REVID_TypeDef*)(ECAP1_BASE+ECAP_REVID_OFFSET )))
#define ECAP1_REVID_R                  (*((__IO uint32_t *)(ECAP1_BASE+ECAP_REVID_OFFSET)))
#define ECAP2_REVID                    (((ECAP_REVID_TypeDef*)(ECAP2_BASE+ECAP_REVID_OFFSET )))
#define ECAP2_REVID_R                  (*((__IO uint32_t *)(ECAP2_BASE+ECAP_REVID_OFFSET)))

/*--------*/
#define ECAP_REVID_R_REV_MASK        ((uint32_t)0xFFFFFFFF)
#define ECAP_REVID_R_REV_SHIFT         (0)

#define ECAP_REVID_REV_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


typedef enum
{
    ECAP_enOK   =   0,
    ECAP_enERROR   =   1,
}Ecap_nStatus;

typedef enum
{
    ECAP_MODE_enAPWM   =   0,
    ECAP_MODE_enCAPTURE   =   1,
}Ecap_nMode;

typedef enum
{
    ECAP_CAPTURE_enEVENT1   =   0,
    ECAP_CAPTURE_enEVENT2   =   1,
    ECAP_CAPTURE_enEVENT3   =   2,
    ECAP_CAPTURE_enEVENT4   =   3,
}Ecap_nCapureEvent;

typedef enum
{
    ECAP_CAPTURE_enFALLING   =   0,
    ECAP_CAPTURE_enRISING   =   1,
}Ecap_nCapurePolarity;

typedef enum
{
    ECAP_CAPTURE_enNOTRESETCOUNTEr   =   0,
    ECAP_CAPTURE_enRESETCOUNTER   =   1,
}Ecap_nCapureResetCounter;

typedef enum
{
    ECAP_CAPTURE_enEVENTSTOP1   =    (0x00 << ECAP_ECCTL2_R_STOP_WRAP_SHIFT),
    ECAP_CAPTURE_enEVENTSTOP2   =    (0x01 << ECAP_ECCTL2_R_STOP_WRAP_SHIFT),
    ECAP_CAPTURE_enEVENTSTOP3   =    (0x02 << ECAP_ECCTL2_R_STOP_WRAP_SHIFT),
    ECAP_CAPTURE_enEVENTSTOP4   =    (0x03 << ECAP_ECCTL2_R_STOP_WRAP_SHIFT),
}Ecap_nCapureEventStop;

typedef enum
{
    ECAP_APWM_enACTIVEHIGH   =   0,
    ECAP_APWM_enACTIVELOW   =   1,
}Ecap_nApwmActive;

typedef enum
{
    ECAP_COUNTER_enSTOP   =   0,
    ECAP_COUNTER_enFREERUNNING   =   1,
}Ecap_nCounterControl;

typedef enum
{
    ECAP_SYNCIN_enDISABLE   =   0,
    ECAP_SYNCIN_enENABLE   =   (1 << ECAP_ECCTL2_R_SYNCI_EN_SHIFT),
}Ecap_nSyncIn;


typedef enum
{
    ECAP_SYNCOUT_enSYNCIN   =   (0 << ECAP_ECCTL2_R_SYNCI_EN_SHIFT),
    ECAP_SYNCOUT_enPRD_EQ   =   (1 << ECAP_ECCTL2_R_SYNCI_EN_SHIFT),
    ECAP_SYNCOUT_enDISABLE   =  (2 << ECAP_ECCTL2_R_SYNCO_SEL_SHIFT),
}Ecap_nSyncOut;


typedef enum
{
    ECAP_INT_enCEVT1   =   ECAP_ECEINT_R_CEVT1_MASK,
    ECAP_INT_enCEVT2   =   ECAP_ECEINT_R_CEVT2_MASK,
    ECAP_INT_enCEVT3   =   ECAP_ECEINT_R_CEVT3_MASK,
    ECAP_INT_enCEVT4   =   ECAP_ECEINT_R_CEVT4_MASK,
    ECAP_INT_enCTROVF   =   ECAP_ECEINT_R_CTROVF_MASK,
    ECAP_INT_enCTR_PRD   =   ECAP_ECEINT_R_CTR_PRD_MASK,
    ECAP_INT_enCTR_CMP   =   ECAP_ECEINT_R_CTR_CMP_MASK,
    ECAP_INT_enGLOBAL   =   ECAP_ECFLG_R_INT_MASK,
}Ecap_nInterrupt;


typedef struct {
    uint32_t TSCTR;
    uint32_t CAP1;
    uint32_t CAP2;
    uint16_t ECCTL2;
    uint16_t ECCLR;
    uint16_t ECEINT;
}ECAP_Context_TypeDef;


void        ECAP__vEnableCaptureLoading         (ECAP_TypeDef* ECAP_BASE);
void        ECAP__vDisableCaptureLoading        (ECAP_TypeDef* ECAP_BASE);
void        ECAP__vConfigPrescale               (ECAP_TypeDef* ECAP_BASE, uint8_t u8Prescale);
void        ECAP__vSelectOperatingMode          (ECAP_TypeDef* ECAP_BASE, Ecap_nMode enModeSelect);
uint32_t    ECAP__u32ReadTimeStamp              (ECAP_TypeDef* ECAP_BASE, Ecap_nCapureEvent enCaptureEvent);
void        ECAP__vConfigCounter                (ECAP_TypeDef* ECAP_BASE, uint32_t u32CountVal);
void        ECAP__vConfigCaptureEventPolarity   (ECAP_TypeDef* ECAP_BASE, Ecap_nCapurePolarity enCapEvent1Polarity,
                                  Ecap_nCapurePolarity enCapEvent2Polarity, Ecap_nCapurePolarity enCapEvent3Polarity,
                                  Ecap_nCapurePolarity enCapEvent4Polarity);
void        ECAP__vConfigCaptureEventCounterReset(ECAP_TypeDef* ECAP_BASE, Ecap_nCapureResetCounter enCounterRst1,
                                    Ecap_nCapureResetCounter enCounterRst2,Ecap_nCapureResetCounter enCounterRst3,
                                    Ecap_nCapureResetCounter enCounterRst4);
void        ECAP__vConfigContinousMode          (ECAP_TypeDef* ECAP_BASE);
void        ECAP__vConfigOneShotMode            (ECAP_TypeDef* ECAP_BASE, Ecap_nCapureEventStop enStopVal);

void        ECAP__vReArmOneShot                 (ECAP_TypeDef* ECAP_BASE);
void        ECAP__vConfigApwmPolarity           (ECAP_TypeDef* ECAP_BASE, Ecap_nApwmActive enFlag);
void        ECAP__vSetCounterControl            (ECAP_TypeDef* ECAP_BASE, Ecap_nCounterControl enFlag);
void        ECAP__vSelectSyncInOut              (ECAP_TypeDef* ECAP_BASE, Ecap_nSyncIn enSyncIn,
                            Ecap_nSyncOut ensSyncOut);
void        ECAP__vConfigApwmCapture            (ECAP_TypeDef* ECAP_BASE, uint32_t u32CompareVal,
                           uint32_t u32PeriodVal);
void        ECAP__vConfigApwmShadowCapture      (ECAP_TypeDef* ECAP_BASE, uint32_t u32CompareVal,
                                 uint32_t u32PeriodVal);
void        ECAP__vConfigCounterPhase           (ECAP_TypeDef* ECAP_BASE, uint32_t u32CountPhaseVal);
void        ECAP__vEnableGlobalInt              (ECAP_TypeDef* ECAP_BASE);
void        ECAP__vEnableInterrupt              (ECAP_TypeDef* ECAP_BASE, Ecap_nInterrupt enFlag);
void        ECAP__vDisableInterrupt             (ECAP_TypeDef* ECAP_BASE, Ecap_nInterrupt enFlag);
Ecap_nInterrupt ECAP__enGetStatusInterrupt      (ECAP_TypeDef* ECAP_BASE, Ecap_nInterrupt enFlag);
void        ECAP__vClearStatusInterrupt         (ECAP_TypeDef* ECAP_BASE, Ecap_nInterrupt enFlag);
uint32_t    ECAP__u32GetPeripheralId            (ECAP_TypeDef* ECAP_BASE);
void        ECAP_vSaveContext                   (ECAP_TypeDef* ECAP_BASE,ECAP_Context_TypeDef *psContext);
void        ECAP_vRestoreContext                   (ECAP_TypeDef* ECAP_BASE,ECAP_Context_TypeDef *psContext);



#endif /* DSP_INCLUDE_ECAP_H_ */
