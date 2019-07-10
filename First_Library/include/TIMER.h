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
        __IO uint32_t            CMP0;
        TIMER_CMP_TypeDef        CMP0_Bit;
    };
    union
    {
        __IO uint32_t            CMP1;
        TIMER_CMP_TypeDef        CMP1_Bit;
    };
    union
    {
        __IO uint32_t            CMP2;
        TIMER_CMP_TypeDef        CMP2_Bit;
    };
    union
    {
        __IO uint32_t            CMP3;
        TIMER_CMP_TypeDef        CMP3_Bit;
    };
    union
    {
        __IO uint32_t            CMP4;
        TIMER_CMP_TypeDef        CMP4_Bit;
    };
    union
    {
        __IO uint32_t            CMP5;
        TIMER_CMP_TypeDef        CMP5_Bit;
    };
    union
    {
        __IO uint32_t            CMP6;
        TIMER_CMP_TypeDef        CMP6_Bit;
    };
    union
    {
        __IO uint32_t            CMP7;
        TIMER_CMP_TypeDef        CMP7_Bit;
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
#define TIMER_EMUMGT_R_FREE_MASK            ((uint32_t)0x00000001)
#define TIMER_EMUMGT_R_FREE_SHIFT           (0)

#define TIMER_EMUMGT_FREE_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_EMUMGT_R_SOFT_MASK            ((uint32_t)0x00000002)
#define TIMER_EMUMGT_R_SOFT_SHIFT           (1)

#define TIMER_EMUMGT_SOFT_MASK               ((uint32_t)0x00000001)
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
#define TIMER_GPINTGPEN_R_GPINT12ENI_MASK            ((uint32_t)0x00000001)
#define TIMER_GPINTGPEN_R_GPINT12ENI_SHIFT           (0)

#define TIMER_GPINTGPEN_GPINT12ENI_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_GPINTGPEN_R_GPINT12ENO_MASK            ((uint32_t)0x00000002)
#define TIMER_GPINTGPEN_R_GPINT12ENO_SHIFT           (1)

#define TIMER_GPINTGPEN_GPINT12ENO_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_GPINTGPEN_R_GPINT12INVI_MASK            ((uint32_t)0x00000010)
#define TIMER_GPINTGPEN_R_GPINT12INVI_SHIFT           (4)

#define TIMER_GPINTGPEN_GPINT12INVI_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_GPINTGPEN_R_GPINT12INVO_MASK            ((uint32_t)0x00000020)
#define TIMER_GPINTGPEN_R_GPINT12INVO_SHIFT           (5)

#define TIMER_GPINTGPEN_GPINT12INVO_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_GPINTGPEN_R_GPENI12_MASK            ((uint32_t)0x00010000)
#define TIMER_GPINTGPEN_R_GPENI12_SHIFT           (16)

#define TIMER_GPINTGPEN_GPENI12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_GPINTGPEN_R_GPENO12_MASK            ((uint32_t)0x00020000)
#define TIMER_GPINTGPEN_R_GPENO12_SHIFT           (17)

#define TIMER_GPINTGPEN_GPENO12_MASK               ((uint32_t)0x00000001)
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
#define TIMER_GPDATGPDIR_R_GPDATI12_MASK            ((uint32_t)0x00000001)
#define TIMER_GPDATGPDIR_R_GPDATI12_SHIFT           (0)

#define TIMER_GPDATGPDIR_GPDATI12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_GPDATGPDIR_R_GPDATO12_MASK            ((uint32_t)0x00000002)
#define TIMER_GPDATGPDIR_R_GPDATO12_SHIFT           (1)

#define TIMER_GPDATGPDIR_GPDATO12_MASK               ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_GPDATGPDIR_R_GPDIRI12_MASK            ((uint32_t)0x00010000)
#define TIMER_GPDATGPDIR_R_GPDIRI12_SHIFT           (16)

#define TIMER_GPDATGPDIR_GPDIRI12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_GPDATGPDIR_R_GPDIRO12_MASK            ((uint32_t)0x00020000)
#define TIMER_GPDATGPDIR_R_GPDIRO12_SHIFT           (17)

#define TIMER_GPDATGPDIR_GPDIRO12_MASK               ((uint32_t)0x00000001)
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
#define TIMER_TCR_R_TSTAT12_MASK            ((uint32_t)0x00000001)
#define TIMER_TCR_R_TSTAT12_SHIFT           (0)

#define TIMER_TCR_TSTAT12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_TCR_R_INVOUTP12_MASK            ((uint32_t)0x00000002)
#define TIMER_TCR_R_INVOUTP12_SHIFT           (1)

#define TIMER_TCR_INVOUTP12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_TCR_R_INVINP12_MASK            ((uint32_t)0x00000004)
#define TIMER_TCR_R_INVINP12_SHIFT           (2)

#define TIMER_TCR_INVINP12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_TCR_R_CP12_MASK            ((uint32_t)0x00000008)
#define TIMER_TCR_R_CP12_SHIFT           (3)

#define TIMER_TCR_CP12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_TCR_R_PWID12_MASK            ((uint32_t)0x00000030)
#define TIMER_TCR_R_PWID12_SHIFT           (4)

#define TIMER_TCR_PWID12_MASK               ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define TIMER_TCR_R_ENAMODE12_MASK            ((uint32_t)0x000000C0)
#define TIMER_TCR_R_ENAMODE12_SHIFT           (6)

#define TIMER_TCR_ENAMODE12_MASK               ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define TIMER_TCR_R_CLKSRC12_MASK            ((uint32_t)0x00000100)
#define TIMER_TCR_R_CLKSRC12_SHIFT           (8)

#define TIMER_TCR_CLKSRC12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_TCR_R_TIEN12_MASK            ((uint32_t)0x00000200)
#define TIMER_TCR_R_TIEN12_SHIFT           (9)

#define TIMER_TCR_TIEN12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_TCR_R_READRSTMODE12_MASK            ((uint32_t)0x00000400)
#define TIMER_TCR_R_READRSTMODE12_SHIFT           (10)

#define TIMER_TCR_READRSTMODE12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_TCR_R_CAPMODE12_MASK            ((uint32_t)0x00000800)
#define TIMER_TCR_R_CAPMODE12_SHIFT           (11)

#define TIMER_TCR_CAPMODE12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_TCR_R_CAPVTMODE12_MASK            ((uint32_t)0x00003000)
#define TIMER_TCR_R_CAPVTMODE12_SHIFT           (12)

#define TIMER_TCR_CAPVTMODE12_MASK               ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define TIMER_TCR_R_ENAMODE34_MASK            ((uint32_t)0x00C00000)
#define TIMER_TCR_R_ENAMODE34_SHIFT           (22)

#define TIMER_TCR_ENAMODE34_MASK               ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define TIMER_TCR_R_READRSTMODE34_MASK            ((uint32_t)0x04000000)
#define TIMER_TCR_R_READRSTMODE34_SHIFT           (26)

#define TIMER_TCR_READRSTMODE34_MASK               ((uint32_t)0x00000001)
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
#define TIMER_TGCR_R_TIM12RS_MASK            ((uint32_t)0x00000001)
#define TIMER_TGCR_R_TIM12RS_SHIFT           (0)

#define TIMER_TGCR_TIM12RS_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_TGCR_R_TIM34RS_MASK            ((uint32_t)0x00000002)
#define TIMER_TGCR_R_TIM34RS_SHIFT           (1)

#define TIMER_TGCR_TIM34RS_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_TGCR_R_TIMMODE_MASK            ((uint32_t)0x0000000C)
#define TIMER_TGCR_R_TIMMODE_SHIFT           (2)

#define TIMER_TGCR_TIMMODE_MASK               ((uint32_t)0x00000003)
/*--------*/
/*--------*/
#define TIMER_TGCR_R_PLUSEN_MASK            ((uint32_t)0x00000010)
#define TIMER_TGCR_R_PLUSEN_SHIFT           (4)

#define TIMER_TGCR_PLUSEN_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_TGCR_R_PSC34_MASK            ((uint32_t)0x00000F00)
#define TIMER_TGCR_R_PSC34_SHIFT           (8)

#define TIMER_TGCR_PSC34_MASK               ((uint32_t)0x0000000F)
/*--------*/

/*--------*/
#define TIMER_TGCR_R_TDDR34_MASK            ((uint32_t)0x0000F000)
#define TIMER_TGCR_R_TDDR34_SHIFT           (12)

#define TIMER_TGCR_TDDR34_MASK               ((uint32_t)0x0000000F)
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
#define TIMER_WDTCR_R_WDEN_MASK            ((uint32_t)0x00004000)
#define TIMER_WDTCR_R_WDEN_SHIFT           (14)

#define TIMER_WDTCR_WDEN_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_WDTCR_R_WDFLAG_MASK            ((uint32_t)0x00008000)
#define TIMER_WDTCR_R_WDFLAG_SHIFT           (15)

#define TIMER_WDTCR_WDFLAG_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_WDTCR_R_WDKEY_MASK            ((uint32_t)0xFFFF0000)
#define TIMER_WDTCR_R_WDKEY_KEY1            ((uint32_t)0xA5C60000)
#define TIMER_WDTCR_R_WDKEY_KEY2            ((uint32_t)0xDA7E0000)
#define TIMER_WDTCR_R_WDKEY_SHIFT           (16)

#define TIMER_WDTCR_WDKEY_MASK               ((uint32_t)0x0000FFFF)
#define TIMER_WDTCR_WDKEY_KEY1               ((uint32_t)0x0000A5C6)
#define TIMER_WDTCR_WDKEY_KEY2               ((uint32_t)0x0000DA7E)
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
************************************** 14 CAP12 ***********************************************
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
************************************** 15 CAP34 ***********************************************
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
************************************** 16 INTCTLSTAT ***********************************************
**********************************************************************************************/
#define TIMER0_INTCTLSTAT                    (((TIMER_INTCTLSTAT_TypeDef*)(TIMER0_BASE+TIMER_INTCTLSTAT_OFFSET )))
#define TIMER0_INTCTLSTAT_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_INTCTLSTAT_OFFSET)))
#define TIMER1_INTCTLSTAT                    (((TIMER_INTCTLSTAT_TypeDef*)(TIMER1_BASE+TIMER_INTCTLSTAT_OFFSET )))
#define TIMER1_INTCTLSTAT_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_INTCTLSTAT_OFFSET)))
#define TIMER2_INTCTLSTAT                    (((TIMER_INTCTLSTAT_TypeDef*)(TIMER2_BASE+TIMER_INTCTLSTAT_OFFSET )))
#define TIMER2_INTCTLSTAT_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_INTCTLSTAT_OFFSET)))
#define TIMER3_INTCTLSTAT                    (((TIMER_INTCTLSTAT_TypeDef*)(TIMER3_BASE+TIMER_INTCTLSTAT_OFFSET )))
#define TIMER3_INTCTLSTAT_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_INTCTLSTAT_OFFSET)))

/*--------*/
#define TIMER_INTCTLSTAT_R_PRDINTEN12_MASK            ((uint32_t)0x00000001)
#define TIMER_INTCTLSTAT_R_PRDINTEN12_SHIFT           (0)

#define TIMER_INTCTLSTAT_PRDINTEN12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_INTCTLSTAT_R_PRDINTSTAT12_MASK            ((uint32_t)0x00000002)
#define TIMER_INTCTLSTAT_R_PRDINTSTAT12_SHIFT           (1)

#define TIMER_INTCTLSTAT_PRDINTSTAT12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_INTCTLSTAT_R_EVTINTEN12_MASK            ((uint32_t)0x00000004)
#define TIMER_INTCTLSTAT_R_EVTINTEN12_SHIFT           (2)

#define TIMER_INTCTLSTAT_EVTINTEN12_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_INTCTLSTAT_R_EVTINTSTAT12_MASK            ((uint32_t)0x00000008)
#define TIMER_INTCTLSTAT_R_EVTINTSTAT12_SHIFT           (3)

#define TIMER_INTCTLSTAT_EVTINTSTAT12_MASK               ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define TIMER_INTCTLSTAT_R_PRDINTEN34_MASK            ((uint32_t)0x00010000)
#define TIMER_INTCTLSTAT_R_PRDINTEN34_SHIFT           (16)

#define TIMER_INTCTLSTAT_PRDINTEN34_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_INTCTLSTAT_R_PRDINTSTAT34_MASK            ((uint32_t)0x00020000)
#define TIMER_INTCTLSTAT_R_PRDINTSTAT34_SHIFT           (17)

#define TIMER_INTCTLSTAT_PRDINTSTAT34_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_INTCTLSTAT_R_EVTINTEN34_MASK            ((uint32_t)0x00040000)
#define TIMER_INTCTLSTAT_R_EVTINTEN34_SHIFT           (18)

#define TIMER_INTCTLSTAT_EVTINTEN34_MASK               ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define TIMER_INTCTLSTAT_R_EVTINTSTAT34_MASK            ((uint32_t)0x00080000)
#define TIMER_INTCTLSTAT_R_EVTINTSTAT34_SHIFT           (19)

#define TIMER_INTCTLSTAT_EVTINTSTAT34_MASK               ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 17-24 CMP ***********************************************
**********************************************************************************************/
#define TIMER0_CMP0                    (((TIMER_CMP_TypeDef*)(TIMER0_BASE+TIMER_CMP0_OFFSET )))
#define TIMER0_CMP0_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP0_OFFSET)))
#define TIMER0_CMP1                    (((TIMER_CMP_TypeDef*)(TIMER0_BASE+TIMER_CMP1_OFFSET )))
#define TIMER0_CMP1_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP1_OFFSET)))
#define TIMER0_CMP2                    (((TIMER_CMP_TypeDef*)(TIMER0_BASE+TIMER_CMP2_OFFSET )))
#define TIMER0_CMP2_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP2_OFFSET)))
#define TIMER0_CMP3                    (((TIMER_CMP_TypeDef*)(TIMER0_BASE+TIMER_CMP3_OFFSET )))
#define TIMER0_CMP3_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP3_OFFSET)))
#define TIMER0_CMP4                    (((TIMER_CMP_TypeDef*)(TIMER0_BASE+TIMER_CMP4_OFFSET )))
#define TIMER0_CMP4_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP4_OFFSET)))
#define TIMER0_CMP5                    (((TIMER_CMP_TypeDef*)(TIMER0_BASE+TIMER_CMP5_OFFSET )))
#define TIMER0_CMP5_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP5_OFFSET)))
#define TIMER0_CMP6                    (((TIMER_CMP_TypeDef*)(TIMER0_BASE+TIMER_CMP6_OFFSET )))
#define TIMER0_CMP6_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP6_OFFSET)))
#define TIMER0_CMP7                    (((TIMER_CMP_TypeDef*)(TIMER0_BASE+TIMER_CMP7_OFFSET )))
#define TIMER0_CMP7_R                  (*((__IO uint32_t *)(TIMER0_BASE+TIMER_CMP7_OFFSET)))

#define TIMER1_CMP0                    (((TIMER_CMP_TypeDef*)(TIMER1_BASE+TIMER_CMP0_OFFSET )))
#define TIMER1_CMP0_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP0_OFFSET)))
#define TIMER1_CMP1                    (((TIMER_CMP_TypeDef*)(TIMER1_BASE+TIMER_CMP1_OFFSET )))
#define TIMER1_CMP1_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP1_OFFSET)))
#define TIMER1_CMP2                    (((TIMER_CMP_TypeDef*)(TIMER1_BASE+TIMER_CMP2_OFFSET )))
#define TIMER1_CMP2_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP2_OFFSET)))
#define TIMER1_CMP3                    (((TIMER_CMP_TypeDef*)(TIMER1_BASE+TIMER_CMP3_OFFSET )))
#define TIMER1_CMP3_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP3_OFFSET)))
#define TIMER1_CMP4                    (((TIMER_CMP_TypeDef*)(TIMER1_BASE+TIMER_CMP4_OFFSET )))
#define TIMER1_CMP4_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP4_OFFSET)))
#define TIMER1_CMP5                    (((TIMER_CMP_TypeDef*)(TIMER1_BASE+TIMER_CMP5_OFFSET )))
#define TIMER1_CMP5_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP5_OFFSET)))
#define TIMER1_CMP6                    (((TIMER_CMP_TypeDef*)(TIMER1_BASE+TIMER_CMP6_OFFSET )))
#define TIMER1_CMP6_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP6_OFFSET)))
#define TIMER1_CMP7                    (((TIMER_CMP_TypeDef*)(TIMER1_BASE+TIMER_CMP7_OFFSET )))
#define TIMER1_CMP7_R                  (*((__IO uint32_t *)(TIMER1_BASE+TIMER_CMP7_OFFSET)))

#define TIMER2_CMP0                    (((TIMER_CMP_TypeDef*)(TIMER2_BASE+TIMER_CMP0_OFFSET )))
#define TIMER2_CMP0_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP0_OFFSET)))
#define TIMER2_CMP1                    (((TIMER_CMP_TypeDef*)(TIMER2_BASE+TIMER_CMP1_OFFSET )))
#define TIMER2_CMP1_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP1_OFFSET)))
#define TIMER2_CMP2                    (((TIMER_CMP_TypeDef*)(TIMER2_BASE+TIMER_CMP2_OFFSET )))
#define TIMER2_CMP2_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP2_OFFSET)))
#define TIMER2_CMP3                    (((TIMER_CMP_TypeDef*)(TIMER2_BASE+TIMER_CMP3_OFFSET )))
#define TIMER2_CMP3_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP3_OFFSET)))
#define TIMER2_CMP4                    (((TIMER_CMP_TypeDef*)(TIMER2_BASE+TIMER_CMP4_OFFSET )))
#define TIMER2_CMP4_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP4_OFFSET)))
#define TIMER2_CMP5                    (((TIMER_CMP_TypeDef*)(TIMER2_BASE+TIMER_CMP5_OFFSET )))
#define TIMER2_CMP5_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP5_OFFSET)))
#define TIMER2_CMP6                    (((TIMER_CMP_TypeDef*)(TIMER2_BASE+TIMER_CMP6_OFFSET )))
#define TIMER2_CMP6_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP6_OFFSET)))
#define TIMER2_CMP7                    (((TIMER_CMP_TypeDef*)(TIMER2_BASE+TIMER_CMP7_OFFSET )))
#define TIMER2_CMP7_R                  (*((__IO uint32_t *)(TIMER2_BASE+TIMER_CMP7_OFFSET)))

#define TIMER3_CMP0                    (((TIMER_CMP_TypeDef*)(TIMER3_BASE+TIMER_CMP0_OFFSET )))
#define TIMER3_CMP0_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP0_OFFSET)))
#define TIMER3_CMP1                    (((TIMER_CMP_TypeDef*)(TIMER3_BASE+TIMER_CMP1_OFFSET )))
#define TIMER3_CMP1_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP1_OFFSET)))
#define TIMER3_CMP2                    (((TIMER_CMP_TypeDef*)(TIMER3_BASE+TIMER_CMP2_OFFSET )))
#define TIMER3_CMP2_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP2_OFFSET)))
#define TIMER3_CMP3                    (((TIMER_CMP_TypeDef*)(TIMER3_BASE+TIMER_CMP3_OFFSET )))
#define TIMER3_CMP3_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP3_OFFSET)))
#define TIMER3_CMP4                    (((TIMER_CMP_TypeDef*)(TIMER3_BASE+TIMER_CMP4_OFFSET )))
#define TIMER3_CMP4_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP4_OFFSET)))
#define TIMER3_CMP5                    (((TIMER_CMP_TypeDef*)(TIMER3_BASE+TIMER_CMP5_OFFSET )))
#define TIMER3_CMP5_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP5_OFFSET)))
#define TIMER3_CMP6                    (((TIMER_CMP_TypeDef*)(TIMER3_BASE+TIMER_CMP6_OFFSET )))
#define TIMER3_CMP6_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP6_OFFSET)))
#define TIMER3_CMP7                    (((TIMER_CMP_TypeDef*)(TIMER3_BASE+TIMER_CMP7_OFFSET )))
#define TIMER3_CMP7_R                  (*((__IO uint32_t *)(TIMER3_BASE+TIMER_CMP7_OFFSET)))
/*--------*/
#define TIMER_CMP_R_CMP_MASK        ((uint32_t)0xFFFFFFFF)
#define TIMER_CMP_R_CMP_SHIFT         (0)

#define TIMER_CMP_CMP_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


#endif /* INCLUDE_TIMER_H_ */
