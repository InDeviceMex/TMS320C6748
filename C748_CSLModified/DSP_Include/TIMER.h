/*
 * TIMER.h
 *
 *  Created on: 27/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_TIMER_H_
#define INCLUDE_TIMER_H_

#include "Core.h"
#include <stdint.h>


#define TIMER0_BASE            ((uint32_t)0x01C20000)
#define TIMER1_BASE            ((uint32_t)0x01C21000)
#define TIMER2_BASE            ((uint32_t)0x01F0C000)
#define TIMER3_BASE            ((uint32_t)0x01F0D000)


typedef __IO struct
{
    __I uint32_t REV       :32;
}TIMER_REVID_TypeDef;

typedef __IO struct
{
    __IO uint32_t FREE       :1;
    __IO uint32_t SOFT       :1;
         uint32_t reserved0  :30;
}TIMER_EMUMGT_TypeDef;

typedef __IO struct
{
    __IO uint32_t GPINT12ENI       :1;
    __IO uint32_t GPINT12ENO       :1;
         uint32_t reserved0        :2;
    __IO uint32_t GPINT12INVI      :1;
    __IO uint32_t GPINT12INVO      :1;
         uint32_t reserved1        :10;
    __IO uint32_t GPENI12          :1;
    __IO uint32_t GPENO12          :1;
         uint32_t reserved2        :14;
}TIMER_GPINTGPEN_TypeDef;

typedef __IO struct
{
    __IO uint32_t GPDATI12       :1;
    __IO uint32_t GPDATO12       :1;
         uint32_t reserved0      :14;
    __IO uint32_t GPDIRI12       :1;
    __IO uint32_t GPDIRO12       :1;
         uint32_t reserved1       :14;
}TIMER_GPDATGPDIR_TypeDef;

typedef __IO struct
{
    __IO uint32_t TIM12       :32;
}TIMER_TIM12_TypeDef;

typedef __IO struct
{
    __IO uint32_t TIM34       :32;
}TIMER_TIM34_TypeDef;

typedef __IO struct
{
    __IO uint32_t PRD12       :32;
}TIMER_PRD12_TypeDef;

typedef __IO struct
{
    __IO uint32_t PRD34       :32;
}TIMER_PRD34_TypeDef;

typedef __IO struct
{
    __IO uint32_t TSTAT12       :1;
    __IO uint32_t INVOUTP12     :1;
    __IO uint32_t INVINP12      :1;
    __IO uint32_t CP12          :1;
    __IO uint32_t PWID12        :2;
    __IO uint32_t ENAMODE12     :2;

    __IO uint32_t CLKSRC12      :1;
    __IO uint32_t TIEN12        :1;
    __IO uint32_t READRSTMODE12 :1;
    __IO uint32_t CAPMODE12     :1;
    __IO uint32_t CAPVTMODE12   :2;
         uint32_t reserved0     :8;
    __IO uint32_t ENAMODE34     :2;
         uint32_t reserved1     :2;
    __IO uint32_t READRSTMODE34 :1;
         uint32_t reserved2     :5;
}TIMER_TCR_TypeDef;

typedef __IO struct
{
    __IO uint32_t TIM12RS       :1;
    __IO uint32_t TIM34RS       :1;
    __IO uint32_t TIMMODE       :2;
    __IO uint32_t PLUSEN        :1;
         uint32_t reserved0     :3;
    __IO uint32_t PSC34         :4;
    __IO uint32_t TDDR34        :4;
         uint32_t reserved1     :16;
}TIMER_TGCR_TypeDef;

typedef __IO struct
{
         uint32_t reserved0     :14;
    __IO uint32_t WDEN          :1;
    __IO uint32_t WDFLAG        :1;
    __IO uint32_t WDKEY         :16;
}TIMER_WDTCR_TypeDef;

typedef __IO struct
{
    __IO uint32_t REL12       :32;
}TIMER_REL12_TypeDef;

typedef __IO struct
{
    __IO uint32_t REL34       :32;
}TIMER_REL34_TypeDef;

typedef __IO struct
{
    __IO uint32_t CAP12       :32;
}TIMER_CAP12_TypeDef;

typedef __IO struct
{
    __IO uint32_t CAP34       :32;
}TIMER_CAP34_TypeDef;

typedef __IO struct
{
    __IO uint32_t PRDINTEN12       :1;
    __IO uint32_t PRDINTSTAT12     :1;
    __IO uint32_t EVTINTEN12       :1;
    __IO uint32_t EVTINTSTAT12     :1;
         uint32_t reserved0        :12;
    __IO uint32_t PRDINTEN34       :1;
    __IO uint32_t PRDINTSTAT34     :1;
    __IO uint32_t EVTINTEN34       :1;
    __IO uint32_t EVTINTSTAT34     :1;
         uint32_t reserved1        :12;
}TIMER_INTCTLSTAT_TypeDef;

typedef __IO struct
{
    __IO uint32_t CMP       :32;
}TIMER_CMP_TypeDef;


typedef struct  {

    union
    {
        __IO uint32_t            REVID;
        TIMER_REVID_TypeDef      REVID_Bit;
    };
    union
    {
        __IO uint32_t            EMUMGT;
        TIMER_EMUMGT_TypeDef     EMUMGT_Bit;
    };
    union
    {
        __IO uint32_t            GPINTGPEN;
        TIMER_GPINTGPEN_TypeDef  GPINTGPEN_Bit;
    };
    union
    {
        __IO uint32_t            GPDATGPDIR;
        TIMER_GPDATGPDIR_TypeDef GPDATGPDIR_Bit;
    };
    union
    {
        __IO uint32_t            TIM12;
        TIMER_TIM12_TypeDef      TIM12_Bit;
    };
    union
    {
        __IO uint32_t            TIM34;
        TIMER_TIM34_TypeDef      TIM34_Bit;
    };
    union
    {
        __IO uint32_t            PRD12;
        TIMER_PRD12_TypeDef      PRD12_Bit;
    };
    union
    {
        __IO uint32_t            PRD34;
        TIMER_PRD34_TypeDef      PRD34_Bit;
    };
    union
    {
        __IO uint32_t            TCR;
        TIMER_TCR_TypeDef        TCR_Bit;
    };
    union
    {
        __IO uint32_t            TGCR;
        TIMER_TGCR_TypeDef       TGCR_Bit;
    };
    union
    {
        __IO uint32_t            WDTCR;
        TIMER_WDTCR_TypeDef       WDTCR_Bit;
    };
    uint32_t reserved0[2];
    union
    {
        __IO uint32_t            REL12;
        TIMER_REL12_TypeDef      REL12_Bit;
    };
    union
    {
        __IO uint32_t            REL34;
        TIMER_REL34_TypeDef      REL34_Bit;
    };
    union
    {
        __IO uint32_t            CAP12;
        TIMER_CAP12_TypeDef      CAP12_Bit;
    };
    union
    {
        __IO uint32_t            CAP34;
        TIMER_CAP34_TypeDef      CAP34_Bit;
    };
    union
    {
        __IO uint32_t            INTCTLSTAT;
        TIMER_INTCTLSTAT_TypeDef INTCTLSTAT_Bit;
    };
    uint32_t reserved1[6];
    union
    {
        __IO uint32_t            CMP[8];
        TIMER_CMP_TypeDef        CMP0_Bit[8];
    };
} TIMER_TypeDef;


#define TIMER0            (((TIMER_TypeDef*)(TIMER0_BASE)))
#define TIMER0_R(offset)  (*((__IO uint32_t *)(TIMER0_BASE+offset)))
#define TIMER1            (((TIMER_TypeDef*)(TIMER1_BASE)))
#define TIMER1_R(offset)  (*((__IO uint32_t *)(TIMER1_BASE+offset)))
#define TIMER2            (((TIMER_TypeDef*)(TIMER2_BASE)))
#define TIMER2_R(offset)  (*((__IO uint32_t *)(TIMER2_BASE+offset)))
#define TIMER3            (((TIMER_TypeDef*)(TIMER3_BASE)))
#define TIMER3_R(offset)  (*((__IO uint32_t *)(TIMER3_BASE+offset)))

#define TIMER_REVID_OFFSET                 ((uint32_t)0x0000)
#define TIMER_EMUMGT_OFFSET                ((uint32_t)0x0004)
#define TIMER_GPINTGPEN_OFFSET             ((uint32_t)0x0008)
#define TIMER_GPDATGPDIR_OFFSET            ((uint32_t)0x000C)
#define TIMER_TIM12_OFFSET                 ((uint32_t)0x0010)
#define TIMER_TIM34_OFFSET                 ((uint32_t)0x0014)
#define TIMER_PRD12_OFFSET                 ((uint32_t)0x0018)
#define TIMER_PRD34_OFFSET                 ((uint32_t)0x001C)
#define TIMER_TCR_OFFSET                   ((uint32_t)0x0020)
#define TIMER_TGCR_OFFSET                  ((uint32_t)0x0024)
#define TIMER_WDTCR_OFFSET                 ((uint32_t)0x0028)
#define TIMER_REL12_OFFSET                 ((uint32_t)0x0034)
#define TIMER_REL34_OFFSET                 ((uint32_t)0x0038)
#define TIMER_CAP12_OFFSET                 ((uint32_t)0x003C)
#define TIMER_CAP34_OFFSET                 ((uint32_t)0x0040)
#define TIMER_INTCTLSTAT_OFFSET            ((uint32_t)0x0044)
#define TIMER_CMP0_OFFSET                  ((uint32_t)0x0060)
#define TIMER_CMP1_OFFSET                  ((uint32_t)0x0064)
#define TIMER_CMP2_OFFSET                  ((uint32_t)0x0068)
#define TIMER_CMP3_OFFSET                  ((uint32_t)0x006C)
#define TIMER_CMP4_OFFSET                  ((uint32_t)0x0070)
#define TIMER_CMP5_OFFSET                  ((uint32_t)0x0074)
#define TIMER_CMP6_OFFSET                  ((uint32_t)0x0078)
#define TIMER_CMP7_OFFSET                  ((uint32_t)0x007C)

/**********************************************************************************************
************************************** 1 REVID ***********************************************
**********************************************************************************************/
#define TIMER0_REVID                    (((TIMER_REVID_TypeDef*)(TIMER0_BASE+TIMER_REVID_OFFSET )))
#define TIMER0_REVID_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_REVID_OFFSET)))
#define TIMER1_REVID                    (((TIMER_REVID_TypeDef*)(TIMER1_BASE+TIMER_REVID_OFFSET )))
#define TIMER1_REVID_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_REVID_OFFSET)))
#define TIMER2_REVID                    (((TIMER_REVID_TypeDef*)(TIMER2_BASE+TIMER_REVID_OFFSET )))
#define TIMER2_REVID_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_REVID_OFFSET)))
#define TIMER3_REVID                    (((TIMER_REVID_TypeDef*)(TIMER3_BASE+TIMER_REVID_OFFSET )))
#define TIMER3_REVID_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_REVID_OFFSET)))

/*--------*/
#define TIMER_REVID_R_REV_MASK        ((uint32_t)0xFFFFFFFF)
#define TIMER_REVID_R_REV_SHIFT         (0)

#define TIMER_REVID_REV_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 2 EMUMGT ***********************************************
**********************************************************************************************/
#define TIMER0_EMUMGT                    (((TIMER_EMUMGT_TypeDef*)(TIMER0_BASE+TIMER_EMUMGT_OFFSET )))
#define TIMER0_EMUMGT_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_EMUMGT_OFFSET)))
#define TIMER1_EMUMGT                    (((TIMER_EMUMGT_TypeDef*)(TIMER1_BASE+TIMER_EMUMGT_OFFSET )))
#define TIMER1_EMUMGT_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_EMUMGT_OFFSET)))
#define TIMER2_EMUMGT                    (((TIMER_EMUMGT_TypeDef*)(TIMER2_BASE+TIMER_EMUMGT_OFFSET )))
#define TIMER2_EMUMGT_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_EMUMGT_OFFSET)))
#define TIMER3_EMUMGT                    (((TIMER_EMUMGT_TypeDef*)(TIMER3_BASE+TIMER_EMUMGT_OFFSET )))
#define TIMER3_EMUMGT_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_EMUMGT_OFFSET)))

/*--------*/
#define TIMER_EMUMGT_R_FREE_MASK        ((uint32_t)0x00000001)
#define TIMER_EMUMGT_R_FREE_SHIFT         (0)

#define TIMER_EMUMGT_FREE_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_EMUMGT_R_SOFT_MASK        ((uint32_t)0x00000002)
#define TIMER_EMUMGT_R_SOFT_SHIFT         (1)

#define TIMER_EMUMGT_SOFT_MASK          ((uint32_t)0x00000002)
/*--------*/

/**********************************************************************************************
************************************** 3 GPINTGPEN ***********************************************
**********************************************************************************************/
#define TIMER0_GPINTGPEN                    (((TIMER_GPINTGPEN_TypeDef*)(TIMER0_BASE+TIMER_GPINTGPEN_OFFSET )))
#define TIMER0_GPINTGPEN_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_GPINTGPEN_OFFSET)))
#define TIMER1_GPINTGPEN                    (((TIMER_GPINTGPEN_TypeDef*)(TIMER1_BASE+TIMER_GPINTGPEN_OFFSET )))
#define TIMER1_GPINTGPEN_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_GPINTGPEN_OFFSET)))
#define TIMER2_GPINTGPEN                    (((TIMER_GPINTGPEN_TypeDef*)(TIMER2_BASE+TIMER_GPINTGPEN_OFFSET )))
#define TIMER2_GPINTGPEN_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_GPINTGPEN_OFFSET)))
#define TIMER3_GPINTGPEN                    (((TIMER_GPINTGPEN_TypeDef*)(TIMER3_BASE+TIMER_GPINTGPEN_OFFSET )))
#define TIMER3_GPINTGPEN_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_GPINTGPEN_OFFSET)))

/*--------*/
#define TIMER_GPINTGPEN_R_GPINT12ENI_MASK        ((uint32_t)0x00000001)
#define TIMER_GPINTGPEN_R_GPINT12ENI_SHIFT         (0)

#define TIMER_GPINTGPEN_GPINT12ENI_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_GPINTGPEN_R_GPINT12ENO_MASK        ((uint32_t)0x00000002)
#define TIMER_GPINTGPEN_R_GPINT12ENO_SHIFT         (1)

#define TIMER_GPINTGPEN_GPINT12ENO_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_GPINTGPEN_R_GPINT12INVI_MASK        ((uint32_t)0x00000010)
#define TIMER_GPINTGPEN_R_GPINT12INVI_SHIFT         (4)

#define TIMER_GPINTGPEN_GPINT12INVI_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_GPINTGPEN_R_GPINT12INVO_MASK        ((uint32_t)0x00000020)
#define TIMER_GPINTGPEN_R_GPINT12INVO_SHIFT         (5)

#define TIMER_GPINTGPEN_GPINT12INVO_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_GPINTGPEN_R_GPENI12_MASK        ((uint32_t)0x00010000)
#define TIMER_GPINTGPEN_R_GPENI12_SHIFT         (16)

#define TIMER_GPINTGPEN_GPENI12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_GPINTGPEN_R_GPENO12_MASK        ((uint32_t)0x00020000)
#define TIMER_GPINTGPEN_R_GPENO12_SHIFT         (17)

#define TIMER_GPINTGPEN_GPENO12_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 4 GPDATGPDIR ***********************************************
**********************************************************************************************/
#define TIMER0_GPDATGPDIR                    (((TIMER_GPDATGPDIR_TypeDef*)(TIMER0_BASE+TIMER_GPDATGPDIR_OFFSET )))
#define TIMER0_GPDATGPDIR_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_GPDATGPDIR_OFFSET)))
#define TIMER1_GPDATGPDIR                    (((TIMER_GPDATGPDIR_TypeDef*)(TIMER1_BASE+TIMER_GPDATGPDIR_OFFSET )))
#define TIMER1_GPDATGPDIR_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_GPDATGPDIR_OFFSET)))
#define TIMER2_GPDATGPDIR                    (((TIMER_GPDATGPDIR_TypeDef*)(TIMER2_BASE+TIMER_GPDATGPDIR_OFFSET )))
#define TIMER2_GPDATGPDIR_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_GPDATGPDIR_OFFSET)))
#define TIMER3_GPDATGPDIR                    (((TIMER_GPDATGPDIR_TypeDef*)(TIMER3_BASE+TIMER_GPDATGPDIR_OFFSET )))
#define TIMER3_GPDATGPDIR_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_GPDATGPDIR_OFFSET)))

/*--------*/
#define TIMER_GPDATGPDIR_R_GPDATI12_MASK        ((uint32_t)0x00000001)
#define TIMER_GPDATGPDIR_R_GPDATI12_SHIFT         (0)

#define TIMER_GPDATGPDIR_GPDATI12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_GPDATGPDIR_R_GPDATO12_MASK        ((uint32_t)0x00000002)
#define TIMER_GPDATGPDIR_R_GPDATO12_SHIFT         (1)

#define TIMER_GPDATGPDIR_GPDATO12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_GPDATGPDIR_R_GPDIRI12_MASK        ((uint32_t)0x00010000)
#define TIMER_GPDATGPDIR_R_GPDIRI12_SHIFT         (16)

#define TIMER_GPDATGPDIR_GPDIRI12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_GPDATGPDIR_R_GPDIRO12_MASK        ((uint32_t)0x00020000)
#define TIMER_GPDATGPDIR_R_GPDIRO12_SHIFT         (17)

#define TIMER_GPDATGPDIR_GPDIRO12_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 5 TIM12 ***********************************************
**********************************************************************************************/
#define TIMER0_TIM12                    (((TIMER_TIM12_TypeDef*)(TIMER0_BASE+TIMER_TIM12_OFFSET )))
#define TIMER0_TIM12_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_TIM12_OFFSET)))
#define TIMER1_TIM12                    (((TIMER_TIM12_TypeDef*)(TIMER1_BASE+TIMER_TIM12_OFFSET )))
#define TIMER1_TIM12_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_TIM12_OFFSET)))
#define TIMER2_TIM12                    (((TIMER_TIM12_TypeDef*)(TIMER2_BASE+TIMER_TIM12_OFFSET )))
#define TIMER2_TIM12_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_TIM12_OFFSET)))
#define TIMER3_TIM12                    (((TIMER_TIM12_TypeDef*)(TIMER3_BASE+TIMER_TIM12_OFFSET )))
#define TIMER3_TIM12_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_TIM12_OFFSET)))

/*--------*/
#define TIMER_TIM12_R_TIM12_MASK        ((uint32_t)0xFFFFFFFF)
#define TIMER_TIM12_R_TIM12_SHIFT         (0)

#define TIMER_TIM12_TIM12_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 6 TIM34 ***********************************************
**********************************************************************************************/
#define TIMER0_TIM34                    (((TIMER_TIM34_TypeDef*)(TIMER0_BASE+TIMER_TIM34_OFFSET )))
#define TIMER0_TIM34_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_TIM34_OFFSET)))
#define TIMER1_TIM34                    (((TIMER_TIM34_TypeDef*)(TIMER1_BASE+TIMER_TIM34_OFFSET )))
#define TIMER1_TIM34_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_TIM34_OFFSET)))
#define TIMER2_TIM34                    (((TIMER_TIM34_TypeDef*)(TIMER2_BASE+TIMER_TIM34_OFFSET )))
#define TIMER2_TIM34_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_TIM34_OFFSET)))
#define TIMER3_TIM34                    (((TIMER_TIM34_TypeDef*)(TIMER3_BASE+TIMER_TIM34_OFFSET )))
#define TIMER3_TIM34_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_TIM34_OFFSET)))

/*--------*/
#define TIMER_TIM34_R_TIM34_MASK        ((uint32_t)0xFFFFFFFF)
#define TIMER_TIM34_R_TIM34_SHIFT         (0)

#define TIMER_TIM34_TIM34_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 7 PRD12 ***********************************************
**********************************************************************************************/
#define TIMER0_PRD12                    (((TIMER_PRD12_TypeDef*)(TIMER0_BASE+TIMER_PRD12_OFFSET )))
#define TIMER0_PRD12_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_PRD12_OFFSET)))
#define TIMER1_PRD12                    (((TIMER_PRD12_TypeDef*)(TIMER1_BASE+TIMER_PRD12_OFFSET )))
#define TIMER1_PRD12_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_PRD12_OFFSET)))
#define TIMER2_PRD12                    (((TIMER_PRD12_TypeDef*)(TIMER2_BASE+TIMER_PRD12_OFFSET )))
#define TIMER2_PRD12_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_PRD12_OFFSET)))
#define TIMER3_PRD12                    (((TIMER_PRD12_TypeDef*)(TIMER3_BASE+TIMER_PRD12_OFFSET )))
#define TIMER3_PRD12_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_PRD12_OFFSET)))

/*--------*/
#define TIMER_PRD12_R_PRD12_MASK        ((uint32_t)0xFFFFFFFF)
#define TIMER_PRD12_R_PRD12_SHIFT         (0)

#define TIMER_PRD12_PRD12_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 8 PRD34 ***********************************************
**********************************************************************************************/
#define TIMER0_PRD34                    (((TIMER_PRD34_TypeDef*)(TIMER0_BASE+TIMER_PRD34_OFFSET )))
#define TIMER0_PRD34_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_PRD34_OFFSET)))
#define TIMER1_PRD34                    (((TIMER_PRD34_TypeDef*)(TIMER1_BASE+TIMER_PRD34_OFFSET )))
#define TIMER1_PRD34_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_PRD34_OFFSET)))
#define TIMER2_PRD34                    (((TIMER_PRD34_TypeDef*)(TIMER2_BASE+TIMER_PRD34_OFFSET )))
#define TIMER2_PRD34_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_PRD34_OFFSET)))
#define TIMER3_PRD34                    (((TIMER_PRD34_TypeDef*)(TIMER3_BASE+TIMER_PRD34_OFFSET )))
#define TIMER3_PRD34_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_PRD34_OFFSET)))

/*--------*/
#define TIMER_PRD34_R_PRD34_MASK        ((uint32_t)0xFFFFFFFF)
#define TIMER_PRD34_R_PRD34_SHIFT         (0)

#define TIMER_PRD34_PRD34_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 9 TCR ***********************************************
**********************************************************************************************/
#define TIMER0_TCR                    (((TIMER_TCR_TypeDef*)(TIMER0_BASE+TIMER_TCR_OFFSET )))
#define TIMER0_TCR_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_TCR_OFFSET)))
#define TIMER1_TCR                    (((TIMER_TCR_TypeDef*)(TIMER1_BASE+TIMER_TCR_OFFSET )))
#define TIMER1_TCR_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_TCR_OFFSET)))
#define TIMER2_TCR                    (((TIMER_TCR_TypeDef*)(TIMER2_BASE+TIMER_TCR_OFFSET )))
#define TIMER2_TCR_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_TCR_OFFSET)))
#define TIMER3_TCR                    (((TIMER_TCR_TypeDef*)(TIMER3_BASE+TIMER_TCR_OFFSET )))
#define TIMER3_TCR_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_TCR_OFFSET)))

/*--------*/
#define TIMER_TCR_R_TSTAT12_MASK        ((uint32_t)0x00000001)
#define TIMER_TCR_R_TSTAT12_SHIFT         (0)

#define TIMER_TCR_TSTAT12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_INVOUTP12_MASK        ((uint32_t)0x00000002)
#define TIMER_TCR_R_INVOUTP12_SHIFT         (1)

#define TIMER_TCR_INVOUTP12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_INVINP12_MASK        ((uint32_t)0x00000004)
#define TIMER_TCR_R_INVINP12_SHIFT         (2)

#define TIMER_TCR_INVINP12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_CP12_MASK        ((uint32_t)0x00000008)
#define TIMER_TCR_R_CP12_SHIFT         (3)

#define TIMER_TCR_CP12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_PWID12_MASK        ((uint32_t)0x00000030)
#define TIMER_TCR_R_PWID12_SHIFT         (4)

#define TIMER_TCR_PWID12_MASK          ((uint32_t)0x00000003)
/*--------*/

/*--------*/
#define TIMER_TCR_R_ENAMODE12_MASK        ((uint32_t)0x000000C0)
#define TIMER_TCR_R_ENAMODE12_SHIFT         (6)

#define TIMER_TCR_ENAMODE12_MASK          ((uint32_t)0x00000003)
/*--------*/

/*--------*/
#define TIMER_TCR_R_CLKSRC12_MASK        ((uint32_t)0x00000100)
#define TIMER_TCR_R_CLKSRC12_SHIFT         (8)

#define TIMER_TCR_CLKSRC12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_TIEN12_MASK        ((uint32_t)0x00000200)
#define TIMER_TCR_R_TIEN12_SHIFT         (9)

#define TIMER_TCR_TIEN12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_READRSTMODE12_MASK        ((uint32_t)0x00000400)
#define TIMER_TCR_R_READRSTMODE12_SHIFT         (10)

#define TIMER_TCR_READRSTMODE12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_CAPMODE12_MASK        ((uint32_t)0x00000800)
#define TIMER_TCR_R_CAPMODE12_SHIFT         (11)

#define TIMER_TCR_CAPMODE12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_CAPVTMODE12_MASK        ((uint32_t)0x00003000)
#define TIMER_TCR_R_CAPVTMODE12_SHIFT         (12)

#define TIMER_TCR_CAPVTMODE12_MASK          ((uint32_t)0x00000003)
/*--------*/

/*--------*/
#define TIMER_TCR_R_TSTAT34_MASK        ((uint32_t)0x00010000)
#define TIMER_TCR_R_TSTAT34_SHIFT         (16)

#define TIMER_TCR_TSTAT34_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_INVOUTP34_MASK        ((uint32_t)0x00020000)
#define TIMER_TCR_R_INVOUTP34_SHIFT         (17)

#define TIMER_TCR_INVOUTP34_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_INVINP34_MASK        ((uint32_t)0x00040000)
#define TIMER_TCR_R_INVINP34_SHIFT         (18)

#define TIMER_TCR_INVINP34_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_CP34_MASK        ((uint32_t)0x00080000)
#define TIMER_TCR_R_CP34_SHIFT         (19)

#define TIMER_TCR_CP34_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_PWID34_MASK        ((uint32_t)0x00030000)
#define TIMER_TCR_R_PWID34_SHIFT         (20)

#define TIMER_TCR_PWID34_MASK          ((uint32_t)0x00000003)
/*--------*/

/*--------*/
#define TIMER_TCR_R_ENAMODE34_MASK        ((uint32_t)0x000C0000)
#define TIMER_TCR_R_ENAMODE34_SHIFT         (22)

#define TIMER_TCR_ENAMODE34_MASK          ((uint32_t)0x00000003)
/*--------*/

/*--------*/
#define TIMER_TCR_R_CLKSRC34_MASK        ((uint32_t)0x00100000)
#define TIMER_TCR_R_CLKSRC34_SHIFT         (24)

#define TIMER_TCR_CLKSRC34_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_TIEN34_MASK        ((uint32_t)0x00200000)
#define TIMER_TCR_R_TIEN34_SHIFT         (25)

#define TIMER_TCR_TIEN34_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_READRSTMODE34_MASK        ((uint32_t)0x04000000)
#define TIMER_TCR_R_READRSTMODE34_SHIFT         (26)

#define TIMER_TCR_READRSTMODE34_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define TIMER_TCR_R_CAPMODE34_MASK        ((uint32_t)0x08000000)
#define TIMER_TCR_R_CAPMODE34_SHIFT         (27)

#define TIMER_TCR_CAPMODE34_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TCR_R_CAPVTMODE34_MASK        ((uint32_t)0x30000000)
#define TIMER_TCR_R_CAPVTMODE34_SHIFT         (28)

#define TIMER_TCR_CAPVTMODE34_MASK          ((uint32_t)0x00000003)
/*--------*/

/**********************************************************************************************
************************************** 10 TGCR ***********************************************
**********************************************************************************************/
#define TIMER0_TGCR                    (((TIMER_TGCR_TypeDef*)(TIMER0_BASE+TIMER_TGCR_OFFSET )))
#define TIMER0_TGCR_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_TGCR_OFFSET)))
#define TIMER1_TGCR                    (((TIMER_TGCR_TypeDef*)(TIMER1_BASE+TIMER_TGCR_OFFSET )))
#define TIMER1_TGCR_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_TGCR_OFFSET)))
#define TIMER2_TGCR                    (((TIMER_TGCR_TypeDef*)(TIMER2_BASE+TIMER_TGCR_OFFSET )))
#define TIMER2_TGCR_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_TGCR_OFFSET)))
#define TIMER3_TGCR                    (((TIMER_TGCR_TypeDef*)(TIMER3_BASE+TIMER_TGCR_OFFSET )))
#define TIMER3_TGCR_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_TGCR_OFFSET)))

/*--------*/
#define TIMER_TGCR_R_TIM12RS_MASK        ((uint32_t)0x00000001)
#define TIMER_TGCR_R_TIM12RS_SHIFT         (0)

#define TIMER_TGCR_TIM12RS_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TGCR_R_TIM34RS_MASK        ((uint32_t)0x00000002)
#define TIMER_TGCR_R_TIM34RS_SHIFT         (1)

#define TIMER_TGCR_TIM34RS_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TGCR_R_TIMMODE_MASK        ((uint32_t)0x0000000C)
#define TIMER_TGCR_R_TIMMODE_SHIFT         (2)

#define TIMER_TGCR_TIMMODE_MASK          ((uint32_t)0x00000003)
/*--------*/

/*--------*/
#define TIMER_TGCR_R_PLUSEN_MASK        ((uint32_t)0x00000010)
#define TIMER_TGCR_R_PLUSEN_SHIFT         (4)

#define TIMER_TGCR_PLUSEN_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_TGCR_R_PSC34_MASK        ((uint32_t)0x00000F00)
#define TIMER_TGCR_R_PSC34_SHIFT         (8)

#define TIMER_TGCR_PSC34_MASK          ((uint32_t)0x0000000F)
/*--------*/

/*--------*/
#define TIMER_TGCR_R_TDDR34_MASK        ((uint32_t)0x0000F000)
#define TIMER_TGCR_R_TDDR34_SHIFT         (12)

#define TIMER_TGCR_TDDR34_MASK          ((uint32_t)0x0000000F)
/*--------*/

/**********************************************************************************************
************************************** 11 WDTCR ***********************************************
**********************************************************************************************/
#define TIMER0_WDTCR                    (((TIMER_WDTCR_TypeDef*)(TIMER0_BASE+TIMER_WDTCR_OFFSET )))
#define TIMER0_WDTCR_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_WDTCR_OFFSET)))
#define TIMER1_WDTCR                    (((TIMER_WDTCR_TypeDef*)(TIMER1_BASE+TIMER_WDTCR_OFFSET )))
#define TIMER1_WDTCR_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_WDTCR_OFFSET)))
#define TIMER2_WDTCR                    (((TIMER_WDTCR_TypeDef*)(TIMER2_BASE+TIMER_WDTCR_OFFSET )))
#define TIMER2_WDTCR_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_WDTCR_OFFSET)))
#define TIMER3_WDTCR                    (((TIMER_WDTCR_TypeDef*)(TIMER3_BASE+TIMER_WDTCR_OFFSET )))
#define TIMER3_WDTCR_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_WDTCR_OFFSET)))

/*--------*/
#define TIMER_WDTCR_R_WDEN_MASK        ((uint32_t)0x00004000)
#define TIMER_WDTCR_R_WDEN_SHIFT         (14)

#define TIMER_WDTCR_WDEN_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_WDTCR_R_WDFLAG_MASK        ((uint32_t)0x00008000)
#define TIMER_WDTCR_R_WDFLAG_SHIFT         (15)

#define TIMER_WDTCR_WDFLAG_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_WDTCR_R_WDKEY_MASK        ((uint32_t)0xFFFF0000)
#define TIMER_WDTCR_R_WDKEY_SHIFT         (16)

#define TIMER_WDTCR_WDKEY_MASK          ((uint32_t)0x0000FFFF)
/*--------*/


/**********************************************************************************************
************************************** 12 REL12 ***********************************************
**********************************************************************************************/
#define TIMER0_REL12                    (((TIMER_REL12_TypeDef*)(TIMER0_BASE+TIMER_REL12_OFFSET )))
#define TIMER0_REL12_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_REL12_OFFSET)))
#define TIMER1_REL12                    (((TIMER_REL12_TypeDef*)(TIMER1_BASE+TIMER_REL12_OFFSET )))
#define TIMER1_REL12_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_REL12_OFFSET)))
#define TIMER2_REL12                    (((TIMER_REL12_TypeDef*)(TIMER2_BASE+TIMER_REL12_OFFSET )))
#define TIMER2_REL12_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_REL12_OFFSET)))
#define TIMER3_REL12                    (((TIMER_REL12_TypeDef*)(TIMER3_BASE+TIMER_REL12_OFFSET )))
#define TIMER3_REL12_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_REL12_OFFSET)))

/*--------*/
#define TIMER_REL12_R_REL12_MASK        ((uint32_t)0xFFFFFFFF)
#define TIMER_REL12_R_REL12_SHIFT         (0)

#define TIMER_REL12_REL12_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


/**********************************************************************************************
************************************** 13 REL34 ***********************************************
**********************************************************************************************/
#define TIMER0_REL34                    (((TIMER_REL34_TypeDef*)(TIMER0_BASE+TIMER_REL34_OFFSET )))
#define TIMER0_REL34_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_REL34_OFFSET)))
#define TIMER1_REL34                    (((TIMER_REL34_TypeDef*)(TIMER1_BASE+TIMER_REL34_OFFSET )))
#define TIMER1_REL34_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_REL34_OFFSET)))
#define TIMER2_REL34                    (((TIMER_REL34_TypeDef*)(TIMER2_BASE+TIMER_REL34_OFFSET )))
#define TIMER2_REL34_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_REL34_OFFSET)))
#define TIMER3_REL34                    (((TIMER_REL34_TypeDef*)(TIMER3_BASE+TIMER_REL34_OFFSET )))
#define TIMER3_REL34_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_REL34_OFFSET)))

/*--------*/
#define TIMER_REL34_R_REL34_MASK        ((uint32_t)0xFFFFFFFF)
#define TIMER_REL34_R_REL34_SHIFT         (0)

#define TIMER_REL34_REL34_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


/**********************************************************************************************
************************************** 14 REL12 ***********************************************
**********************************************************************************************/
#define TIMER0_CAP12                    (((TIMER_CAP12_TypeDef*)(TIMER0_BASE+TIMER_CAP12_OFFSET )))
#define TIMER0_CAP12_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CAP12_OFFSET)))
#define TIMER1_CAP12                    (((TIMER_CAP12_TypeDef*)(TIMER1_BASE+TIMER_CAP12_OFFSET )))
#define TIMER1_CAP12_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CAP12_OFFSET)))
#define TIMER2_CAP12                    (((TIMER_CAP12_TypeDef*)(TIMER2_BASE+TIMER_CAP12_OFFSET )))
#define TIMER2_CAP12_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CAP12_OFFSET)))
#define TIMER3_CAP12                    (((TIMER_CAP12_TypeDef*)(TIMER3_BASE+TIMER_CAP12_OFFSET )))
#define TIMER3_CAP12_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CAP12_OFFSET)))

/*--------*/
#define TIMER_CAP12_R_CAP12_MASK        ((uint32_t)0xFFFFFFFF)
#define TIMER_CAP12_R_CAP12_SHIFT         (0)

#define TIMER_CAP12_CAP12_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


/**********************************************************************************************
************************************** 15 REL34 ***********************************************
**********************************************************************************************/
#define TIMER0_CAP34                    (((TIMER_CAP34_TypeDef*)(TIMER0_BASE+TIMER_CAP34_OFFSET )))
#define TIMER0_CAP34_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CAP34_OFFSET)))
#define TIMER1_CAP34                    (((TIMER_CAP34_TypeDef*)(TIMER1_BASE+TIMER_CAP34_OFFSET )))
#define TIMER1_CAP34_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CAP34_OFFSET)))
#define TIMER2_CAP34                    (((TIMER_CAP34_TypeDef*)(TIMER2_BASE+TIMER_CAP34_OFFSET )))
#define TIMER2_CAP34_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CAP34_OFFSET)))
#define TIMER3_CAP34                    (((TIMER_CAP34_TypeDef*)(TIMER3_BASE+TIMER_CAP34_OFFSET )))
#define TIMER3_CAP34_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CAP34_OFFSET)))

/*--------*/
#define TIMER_CAP34_R_CAP34_MASK        ((uint32_t)0xFFFFFFFF)
#define TIMER_CAP34_R_CAP34_SHIFT         (0)

#define TIMER_CAP34_CAP34_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


/**********************************************************************************************
************************************** 15 INTCTLSTAT ***********************************************
**********************************************************************************************/
#define TIMER0_INTCTLSTAT                    (((TIMER_INTCTLSTAT_TypeDef*)(TIMER0_BASE+TIMER_INTCTLSTAT_OFFSET )))
#define TIMER0_INTCTLSTAT_R                      (*((__IO uint32_t *)(TIMER0_BASE+TIMER_INTCTLSTAT_OFFSET)))
#define TIMER1_INTCTLSTAT                    (((TIMER_INTCTLSTAT_TypeDef*)(TIMER1_BASE+TIMER_INTCTLSTAT_OFFSET )))
#define TIMER1_INTCTLSTAT_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_INTCTLSTAT_OFFSET)))
#define TIMER2_INTCTLSTAT                    (((TIMER_INTCTLSTAT_TypeDef*)(TIMER2_BASE+TIMER_INTCTLSTAT_OFFSET )))
#define TIMER2_INTCTLSTAT_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_INTCTLSTAT_OFFSET)))
#define TIMER3_INTCTLSTAT                    (((TIMER_INTCTLSTAT_TypeDef*)(TIMER3_BASE+TIMER_INTCTLSTAT_OFFSET )))
#define TIMER3_INTCTLSTAT_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_INTCTLSTAT_OFFSET)))

/*--------*/
#define TIMER_INTCTLSTAT_R_PRDINTEN12_MASK        ((uint32_t)0x00000001)
#define TIMER_INTCTLSTAT_R_PRDINTEN12_SHIFT         (0)

#define TIMER_INTCTLSTAT_PRDINTEN12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_INTCTLSTAT_R_PRDINTSTAT12_MASK        ((uint32_t)0x00000002)
#define TIMER_INTCTLSTAT_R_PRDINTSTAT12_SHIFT         (1)

#define TIMER_INTCTLSTAT_PRDINTSTAT12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_INTCTLSTAT_R_EVTINTEN12_MASK        ((uint32_t)0x00000004)
#define TIMER_INTCTLSTAT_R_EVTINTEN12_SHIFT         (2)

#define TIMER_INTCTLSTAT_EVTINTEN12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_INTCTLSTAT_R_EVTINTSTAT12_MASK        ((uint32_t)0x00000008)
#define TIMER_INTCTLSTAT_R_EVTINTSTAT12_SHIFT         (3)

#define TIMER_INTCTLSTAT_EVTINTSTAT12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_INTCTLSTAT_R_PRDINTEN34_MASK        ((uint32_t)0x00010000)
#define TIMER_INTCTLSTAT_R_PRDINTEN34_SHIFT         (16)

#define TIMER_INTCTLSTAT_PRDINTEN34_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_INTCTLSTAT_R_PRDINTSTAT34_MASK        ((uint32_t)0x00020000)
#define TIMER_INTCTLSTAT_R_PRDINTSTAT34_SHIFT         (17)

#define TIMER_INTCTLSTAT_PRDINTSTAT34_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_INTCTLSTAT_R_EVTINTEN34_MASK        ((uint32_t)0x00040000)
#define TIMER_INTCTLSTAT_R_EVTINTEN34_SHIFT         (18)

#define TIMER_INTCTLSTAT_EVTINTEN34_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_INTCTLSTAT_R_EVTINTSTAT34_MASK        ((uint32_t)0x00080000)
#define TIMER_INTCTLSTAT_R_EVTINTSTAT34_SHIFT         (19)

#define TIMER_INTCTLSTAT_EVTINTSTAT34_MASK          ((uint32_t)0x00000001)
/*--------*/



/**********************************************************************************************
************************************** 15 CMP0 ***********************************************
**********************************************************************************************/
#define TIMER0_CMP0                    (((TIMER_CMP0_TypeDef*)(TIMER0_BASE+TIMER_CMP0_OFFSET )))
#define TIMER0_CMP0_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP0_OFFSET)))
#define TIMER0_CMP1                    (((TIMER_CMP1_TypeDef*)(TIMER0_BASE+TIMER_CMP1_OFFSET )))
#define TIMER0_CMP1_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP1_OFFSET)))
#define TIMER0_CMP2                    (((TIMER_CMP2_TypeDef*)(TIMER0_BASE+TIMER_CMP2_OFFSET )))
#define TIMER0_CMP2_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP2_OFFSET)))
#define TIMER0_CMP3                    (((TIMER_CMP3_TypeDef*)(TIMER0_BASE+TIMER_CMP3_OFFSET )))
#define TIMER0_CMP3_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP3_OFFSET)))
#define TIMER0_CMP4                    (((TIMER_CMP4_TypeDef*)(TIMER0_BASE+TIMER_CMP4_OFFSET )))
#define TIMER0_CMP4_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP4_OFFSET)))
#define TIMER0_CMP5                    (((TIMER_CMP5_TypeDef*)(TIMER0_BASE+TIMER_CMP5_OFFSET )))
#define TIMER0_CMP5_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP5_OFFSET)))
#define TIMER0_CMP6                    (((TIMER_CMP6_TypeDef*)(TIMER0_BASE+TIMER_CMP6_OFFSET )))
#define TIMER0_CMP6_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP6_OFFSET)))
#define TIMER0_CMP7                    (((TIMER_CMP7_TypeDef*)(TIMER0_BASE+TIMER_CMP7_OFFSET )))
#define TIMER0_CMP7_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP7_OFFSET)))
#define TIMER0_CMP(offset)                    (((TIMER_CMP7_TypeDef*)(TIMER0_BASE+TIMER_CMP0_OFFSET + offset )))
#define TIMER0_CMP_R(offset)                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP0_OFFSET+ offset)))

#define TIMER1_CMP0                    (((TIMER_CMP0_TypeDef*)(TIMER1_BASE+TIMER_CMP0_OFFSET )))
#define TIMER1_CMP0_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP0_OFFSET)))
#define TIMER1_CMP1                    (((TIMER_CMP1_TypeDef*)(TIMER1_BASE+TIMER_CMP1_OFFSET )))
#define TIMER1_CMP1_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP1_OFFSET)))
#define TIMER1_CMP2                    (((TIMER_CMP2_TypeDef*)(TIMER1_BASE+TIMER_CMP2_OFFSET )))
#define TIMER1_CMP2_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP2_OFFSET)))
#define TIMER1_CMP3                    (((TIMER_CMP3_TypeDef*)(TIMER1_BASE+TIMER_CMP3_OFFSET )))
#define TIMER1_CMP3_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP3_OFFSET)))
#define TIMER1_CMP4                    (((TIMER_CMP4_TypeDef*)(TIMER1_BASE+TIMER_CMP4_OFFSET )))
#define TIMER1_CMP4_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP4_OFFSET)))
#define TIMER1_CMP5                    (((TIMER_CMP5_TypeDef*)(TIMER1_BASE+TIMER_CMP5_OFFSET )))
#define TIMER1_CMP5_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP5_OFFSET)))
#define TIMER1_CMP6                    (((TIMER_CMP6_TypeDef*)(TIMER1_BASE+TIMER_CMP6_OFFSET )))
#define TIMER1_CMP6_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP6_OFFSET)))
#define TIMER1_CMP7                    (((TIMER_CMP7_TypeDef*)(TIMER1_BASE+TIMER_CMP7_OFFSET )))
#define TIMER1_CMP7_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP7_OFFSET)))
#define TIMER1_CMP(offset)                    (((TIMER_CMP7_TypeDef*)(TIMER1_BASE+TIMER_CMP0_OFFSET + offset )))
#define TIMER1_CMP_R(offset)                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP0_OFFSET+ offset)))

#define TIMER2_CMP0                    (((TIMER_CMP0_TypeDef*)(TIMER2_BASE+TIMER_CMP0_OFFSET )))
#define TIMER2_CMP0_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP0_OFFSET)))
#define TIMER2_CMP1                    (((TIMER_CMP1_TypeDef*)(TIMER2_BASE+TIMER_CMP1_OFFSET )))
#define TIMER2_CMP1_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP1_OFFSET)))
#define TIMER2_CMP2                    (((TIMER_CMP2_TypeDef*)(TIMER2_BASE+TIMER_CMP2_OFFSET )))
#define TIMER2_CMP2_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP2_OFFSET)))
#define TIMER2_CMP3                    (((TIMER_CMP3_TypeDef*)(TIMER2_BASE+TIMER_CMP3_OFFSET )))
#define TIMER2_CMP3_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP3_OFFSET)))
#define TIMER2_CMP4                    (((TIMER_CMP4_TypeDef*)(TIMER2_BASE+TIMER_CMP4_OFFSET )))
#define TIMER2_CMP4_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP4_OFFSET)))
#define TIMER2_CMP5                    (((TIMER_CMP5_TypeDef*)(TIMER2_BASE+TIMER_CMP5_OFFSET )))
#define TIMER2_CMP5_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP5_OFFSET)))
#define TIMER2_CMP6                    (((TIMER_CMP6_TypeDef*)(TIMER2_BASE+TIMER_CMP6_OFFSET )))
#define TIMER2_CMP6_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP6_OFFSET)))
#define TIMER2_CMP7                    (((TIMER_CMP7_TypeDef*)(TIMER2_BASE+TIMER_CMP7_OFFSET )))
#define TIMER2_CMP7_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP7_OFFSET)))
#define TIMER2_CMP(offset)                    (((TIMER_CMP7_TypeDef*)(TIMER2_BASE+TIMER_CMP0_OFFSET + offset )))
#define TIMER2_CMP_R(offset)                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP0_OFFSET+ offset)))


#define TIMER3_CMP0                    (((TIMER_CMP0_TypeDef*)(TIMER3_BASE+TIMER_CMP0_OFFSET )))
#define TIMER3_CMP0_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP0_OFFSET)))
#define TIMER3_CMP1                    (((TIMER_CMP1_TypeDef*)(TIMER3_BASE+TIMER_CMP1_OFFSET )))
#define TIMER3_CMP1_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP1_OFFSET)))
#define TIMER3_CMP2                    (((TIMER_CMP2_TypeDef*)(TIMER3_BASE+TIMER_CMP2_OFFSET )))
#define TIMER3_CMP2_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP2_OFFSET)))
#define TIMER3_CMP3                    (((TIMER_CMP3_TypeDef*)(TIMER3_BASE+TIMER_CMP3_OFFSET )))
#define TIMER3_CMP3_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP3_OFFSET)))
#define TIMER3_CMP4                    (((TIMER_CMP4_TypeDef*)(TIMER3_BASE+TIMER_CMP4_OFFSET )))
#define TIMER3_CMP4_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP4_OFFSET)))
#define TIMER3_CMP5                    (((TIMER_CMP5_TypeDef*)(TIMER3_BASE+TIMER_CMP5_OFFSET )))
#define TIMER3_CMP5_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP5_OFFSET)))
#define TIMER3_CMP6                    (((TIMER_CMP6_TypeDef*)(TIMER3_BASE+TIMER_CMP6_OFFSET )))
#define TIMER3_CMP6_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP6_OFFSET)))
#define TIMER3_CMP7                    (((TIMER_CMP7_TypeDef*)(TIMER3_BASE+TIMER_CMP7_OFFSET )))
#define TIMER3_CMP7_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP7_OFFSET)))
#define TIMER3_CMP(offset)                    (((TIMER_CMP7_TypeDef*)(TIMER3_BASE+TIMER_CMP0_OFFSET + offset )))
#define TIMER3_CMP_R(offset)                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP0_OFFSET+ offset)))


typedef enum
{
    WATCHDOG_enKEY1 = 0xA5C60000u,
    WATCHDOG_enKEY2 = 0xDA7E0000u,
}Timer_nWatchdogKey;

typedef enum
{
    TIMER_enTIMER12   =   0x00003FFEu,
    TIMER_enTIMER34   =   0x3FFE0000u,
    TIMER_enTIMERBOTH =   0x3FFE3FFEu,
}Timer_nEnable;

typedef enum
{
    TIMER_MODE_enONCE       =   0x00400040u,
    TIMER_MODE_enCONTINUOS  =   0x00800080u,
    TIMER_MODE_enRELOAD     =   0x00C000C0u,
}Timer_nEnableMode;

typedef enum
{
    TIMER_CFG_en64BIT_NOCLOCK           =   0x00000000u,
    TIMER_CFG_en64BIT_CLK_INT           =   0x00000013u,
    TIMER_CFG_en64BIT_CLK_EXT           =   0x01000113u,
    TIMER_CFG_en64BIT_WATCHDOG          =   0x0000001Bu,

    TIMER_CFG_en32BIT_CHAINED_CLK_INT   =   0x0000001Fu,
    TIMER_CFG_en32BIT_CHAINED_CLK_EXT   =   0x0100011Fu,

    TIMER_CFG_en32BIT_UNCHAINED_CLK_BOTH_INT        =   0x00000017u,
    TIMER_CFG_en32BIT_UNCHAINED_CLK_12INT_34EXT     =   0x01000017u,
    TIMER_CFG_en32BIT_UNCHAINED_CLK_12EXT_34INT     =   0x00000117u,
    TIMER_CFG_en32BIT_UNCHAINED_CLK_BOTH_EXT        =   0x01000117u,
}Timer_nConfig;

typedef enum
{
    TIMER_enCOMPARE0       =   0x0u,
    TIMER_enCOMPARE1       =   0x1u,
    TIMER_enCOMPARE2       =   0x2u,
    TIMER_enCOMPARE3       =   0x3u,
    TIMER_enCOMPARE4       =   0x4u,
    TIMER_enCOMPARE5       =   0x5u,
    TIMER_enCOMPARE6       =   0x6u,
    TIMER_enCOMPARE7       =   0x7u,
}Timer_nCompare;

typedef enum
{
    TIMER_CAPT_enDISABLE                =   0x00000000u,
    TIMER_CAPT_enENABLE_RIS_EDGE        =   0x08000800u,
    TIMER_CAPT_enENABLE_FALL_EDGE       =   0x18001800u,
    TIMER_CAPT_enENABLE_BOTH_EDGE       =   0x28002800u,
}Timer_nCaptMode;

typedef enum
{
    TIMER_PULSE_en1_CLK                =   0x00000000u,
    TIMER_PULSE_en2_CLK        =   0x00100010,
    TIMER_PULSE_en3_CLK       =   0x00200020,
    TIMER_PULSE_en4_CLK       =   0x00300030,
}Timer_nPulseWidth;

typedef enum
{

    TIMER_OUT_enNOASSERTED                =   0x00000000u,
    TIMER_OUT_enASSERTED12                =   TIMER_TCR_R_TSTAT12_MASK,
    TIMER_OUT_enASSERTED34        =   TIMER_TCR_R_TSTAT34_MASK,
    TIMER_PULSE_enASSERTED1234       =   TIMER_TCR_R_TSTAT12_MASK|TIMER_TCR_R_TSTAT34_MASK,
}Timer_nOutStatus;


typedef enum
{
    TIMER_INT_enNO_INTERRUPT              =   0,
    TIMER_INT_enTMR12_CAPT              =   TIMER_INTCTLSTAT_R_EVTINTEN12_MASK,
    TIMER_INT_enTMR12_NON_CAPT_MODE      =   TIMER_INTCTLSTAT_R_PRDINTEN12_MASK,
    TIMER_INT_enTMR34_CAPT                  =   TIMER_INTCTLSTAT_R_EVTINTEN34_MASK,
    TIMER_INT_enTMR34_NON_CAPT_MODE       =   TIMER_INTCTLSTAT_R_PRDINTEN34_MASK,

    TIMER_INT_enTMR12_CAPT_TMR34_NON_CAPT_MODE    =   TIMER_INTCTLSTAT_R_EVTINTEN12_MASK|TIMER_INTCTLSTAT_R_PRDINTEN34_MASK,
    TIMER_INT_enTMR34_CAPT_TMR12_NON_CAPT_MODE    =   TIMER_INTCTLSTAT_R_EVTINTEN34_MASK|TIMER_INTCTLSTAT_R_PRDINTEN12_MASK,

    TIMER_INT_enTMR1234_NON_CAPT_MODE       =   TIMER_INTCTLSTAT_R_PRDINTEN12_MASK|TIMER_INTCTLSTAT_R_PRDINTEN34_MASK,
    TIMER_INT_enTMR1234_CAPT       =   TIMER_INTCTLSTAT_R_EVTINTEN12_MASK|TIMER_INTCTLSTAT_R_EVTINTEN34_MASK,
    TIMER_INT_enTMR1234_CAPT_TMR1234_NON_CAPT_MODE       =   TIMER_INTCTLSTAT_R_PRDINTEN12_MASK|TIMER_INTCTLSTAT_R_PRDINTEN34_MASK|TIMER_INTCTLSTAT_R_EVTINTEN12_MASK|TIMER_INTCTLSTAT_R_EVTINTEN34_MASK,
}Timer_nInterrupt;




#pragma FUNC_ALWAYS_INLINE( TIMER__vEnable)
#pragma FUNC_ALWAYS_INLINE( TIMER__vDisable)
#pragma FUNC_ALWAYS_INLINE( TIMER__vConfig)
#pragma FUNC_ALWAYS_INLINE( TIMER__vActivateWatchdog)
#pragma FUNC_ALWAYS_INLINE( TIMER__vReactivateWatchdog)
#pragma FUNC_ALWAYS_INLINE( TIMER__vSetPeriod)
#pragma FUNC_ALWAYS_INLINE( TIMER__u32GetPeriod)
#pragma FUNC_ALWAYS_INLINE( TIMER__vSetCounter)
#pragma FUNC_ALWAYS_INLINE( TIMER__u32GetCounter)
#pragma FUNC_ALWAYS_INLINE( TIMER__vSetReload)
#pragma FUNC_ALWAYS_INLINE( TIMER__u32GetReload)
#pragma FUNC_ALWAYS_INLINE( TIMER__u32GetCapture)
#pragma FUNC_ALWAYS_INLINE( TIMER__vSetCompare)
#pragma FUNC_ALWAYS_INLINE( TIMER__u32GetCompare)
#pragma FUNC_ALWAYS_INLINE( TIMER__vEnableInterrupt)
#pragma FUNC_ALWAYS_INLINE( TIMER__vDisableInterrupt)
#pragma FUNC_ALWAYS_INLINE( TIMER__enGetInterruptStatus)
#pragma FUNC_ALWAYS_INLINE( TIMER__enClearInterruptStatus)
#pragma FUNC_ALWAYS_INLINE( TIMER__vSetPrescalarCount34)
#pragma FUNC_ALWAYS_INLINE( TIMER__u32GetPrescalarCount34)
#pragma FUNC_ALWAYS_INLINE( TIMER__vSetDivideDownRatio34)
#pragma FUNC_ALWAYS_INLINE( TIMER__u32GetDivideDownRatio34)
#pragma FUNC_ALWAYS_INLINE( TIMER__vConfigureCaptureModule)
#pragma FUNC_ALWAYS_INLINE( TIMER__vEnableReadResetCounter)
#pragma FUNC_ALWAYS_INLINE( TIMER__vDisableReadResetCounter)
#pragma FUNC_ALWAYS_INLINE( TIMER__vEnableInputGate)
#pragma FUNC_ALWAYS_INLINE( TIMER__vDisableInputGate)
#pragma FUNC_ALWAYS_INLINE( TIMER__vSetPulseWidth)
#pragma FUNC_ALWAYS_INLINE( TIMER__vSetPulseMode)
#pragma FUNC_ALWAYS_INLINE( TIMER__vSetClockMode)
#pragma FUNC_ALWAYS_INLINE( TIMER__enGetOUTStatus)
#pragma FUNC_ALWAYS_INLINE( TIMER__vEnableInvertOUT)
#pragma FUNC_ALWAYS_INLINE( TIMER__vDisableInvertOUT)
#pragma FUNC_ALWAYS_INLINE( TIMER__vEnableInvertIN)
#pragma FUNC_ALWAYS_INLINE( TIMER__vDisableInvertIN)

void        TIMER__vEnable                  (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enEnableTim,Timer_nEnableMode enEnableMode);
void        TIMER__vDisable                 (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enEnableTim);
void        TIMER__vConfig                  (TIMER_TypeDef* TIMER_BASE, Timer_nConfig enConfig);
void        TIMER__vActivateWatchdog        (TIMER_TypeDef* TIMER_BASE);
void        TIMER__vReactivateWatchdog      (TIMER_TypeDef* TIMER_BASE);
void        TIMER__vSetPeriod               (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer,uint32_t u32Period);
uint32_t    TIMER__u32GetPeriod             (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
void        TIMER__vSetCounter              (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer,uint32_t u32Counter);
uint32_t    TIMER__u32GetCounter            (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
void        TIMER__vSetReload               (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer,uint32_t u32Reload);
uint32_t    TIMER__u32GetReload             (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
uint32_t    TIMER__u32GetCapture            (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
void        TIMER__vSetCompare              (TIMER_TypeDef* TIMER_BASE, Timer_nCompare enCompareUnit,uint32_t u32Compare);
uint32_t    TIMER__u32GetCompare            (TIMER_TypeDef* TIMER_BASE, Timer_nCompare enCompareUnit);
void        TIMER__vEnableInterrupt         (TIMER_TypeDef* TIMER_BASE, Timer_nInterrupt enInterrupt);
void        TIMER__vDisableInterrupt        (TIMER_TypeDef* TIMER_BASE, Timer_nInterrupt enInterrupt);
void        TIMER__vSetPrescalarCount34     (TIMER_TypeDef* TIMER_BASE, uint32_t u32Prescalar);
uint32_t    TIMER__u32GetPrescalarCount34   (TIMER_TypeDef* TIMER_BASE);
void        TIMER__vSetDivideDownRatio34    (TIMER_TypeDef* TIMER_BASE,uint32_t u32DivideDown);
uint32_t    TIMER__u32GetDivideDownRatio34  (TIMER_TypeDef* TIMER_BASE);
void        TIMER__vConfigureCaptureModule  (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer,Timer_nCaptMode enConfigCapture);
void        TIMER__vEnableReadResetCounter  (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
void        TIMER__vDisableReadResetCounter (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
void        TIMER__vEnableInputGate         (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
void        TIMER__vDisableInputGate        (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
void        TIMER__vSetPulseWidth           (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer,Timer_nPulseWidth enPulseWidth);
void        TIMER__vSetPulseMode            (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
void        TIMER__vSetClockMode            (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
void        TIMER__vEnableInvertOUT         (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
void        TIMER__vDisableInvertOUT        (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
void        TIMER__vEnableInvertIN          (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
void        TIMER__vDisableInvertIN         (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
Timer_nOutStatus TIMER__enGetOUTStatus       (TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer);
Timer_nInterrupt TIMER__enGetInterruptStatus(TIMER_TypeDef* TIMER_BASE, Timer_nInterrupt enInterrupt);
Timer_nInterrupt TIMER__enClearInterruptStatus(TIMER_TypeDef* TIMER_BASE, Timer_nInterrupt enInterrupt);
#endif /* INCLUDE_TIMER_H_ */
