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


#endif /* INCLUDE_TIMER_H_ */
