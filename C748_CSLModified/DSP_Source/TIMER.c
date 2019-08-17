/*
 * TIMER.c
 *
 *  Created on: 16/07/2019
 *      Author: Lalo
 */


#include "TIMER.h"


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


void TIMER__vEnable(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enEnableTim,
                    Timer_nEnableMode enEnableMode)
{
    TIMER_BASE->TCR&= ~((enEnableTim &(TIMER_TCR_R_ENAMODE12_MASK |TIMER_TCR_R_ENAMODE34_MASK)));
    TIMER_BASE->TCR |= (enEnableMode & enEnableTim);
}

void TIMER__vDisable(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enEnableTim)
{
    /* Disable the timer; the Timer stops couting */
    TIMER_BASE->TCR &= ~((enEnableTim & (TIMER_TCR_R_ENAMODE12_MASK | TIMER_TCR_R_ENAMODE34_MASK)));
}

void TIMER__vConfig(TIMER_TypeDef* TIMER_BASE, Timer_nConfig enConfig)
{

    TIMER_BASE->TCR &=~ ((TIMER_TCR_R_CLKSRC12_MASK | TIMER_TCR_R_CLKSRC34_MASK));
    TIMER_BASE->TCR |= (enConfig& (TIMER_TCR_R_CLKSRC12_MASK | TIMER_TCR_R_CLKSRC34_MASK));

    TIMER_BASE->TIM12 = 0x0;
    TIMER_BASE->TIM34 = 0x0;
    TIMER_BASE->TGCR &= ~( TIMER_TGCR_R_TIMMODE_MASK | TIMER_TGCR_R_TIM34RS_MASK | TIMER_TGCR_R_TIM12RS_MASK   );

    TIMER_BASE->TGCR |= (enConfig & (TIMER_TGCR_R_TIMMODE_MASK | TIMER_TGCR_R_TIM34RS_MASK |
                                           TIMER_TGCR_R_TIM12RS_MASK | TIMER_TGCR_R_PLUSEN_MASK));
}

void TIMER__vActivateWatchdog(TIMER_TypeDef* TIMER_BASE)
{
    TIMER_BASE->WDTCR = ((TIMER_WDTCR_R_WDEN_MASK | TIMER_WDTCR_R_WDFLAG_MASK) |(WATCHDOG_enKEY1));
    TIMER_BASE->WDTCR = ((TIMER_BASE->WDTCR &(~TIMER_WDTCR_R_WDKEY_MASK)) |(WATCHDOG_enKEY2));
}

void TIMER__vReactivateWatchdog(TIMER_TypeDef* TIMER_BASE)
{
    TIMER_BASE->WDTCR  = (( TIMER_BASE->WDTCR  & (~TIMER_WDTCR_R_WDKEY_MASK)) |(WATCHDOG_enKEY1));
    TIMER_BASE->WDTCR  = ( (TIMER_BASE->WDTCR  & (~TIMER_WDTCR_R_WDKEY_MASK)) |(WATCHDOG_enKEY2));

}

void TIMER__vSetPeriod(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer,
                    uint32_t u32Period)
{
    if(TIMER_enTIMER12 & enTimer)
        TIMER_BASE->PRD12 = u32Period;

    if(TIMER_enTIMER34 & enTimer)
        TIMER_BASE->PRD34 = u32Period;
}

uint32_t TIMER__u32GetPeriod(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    return((enTimer == TIMER_enTIMER12) ? TIMER_BASE->PRD12 :TIMER_BASE->PRD34);
}

void TIMER__vSetCounter(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer,uint32_t u32Counter)
{
    if(TIMER_enTIMER12 & enTimer)
        TIMER_BASE->TIM12 = u32Counter;

    if(TIMER_enTIMER34 & enTimer)
        TIMER_BASE->TIM34 = u32Counter;
}

uint32_t TIMER__u32GetCounter(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    return((enTimer == TIMER_enTIMER12) ? TIMER_BASE->TIM12 :TIMER_BASE->TIM34);
}

void TIMER__vSetReload(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer,uint32_t u32Reload)
{
    if(TIMER_enTIMER12 & enTimer)
        TIMER_BASE->REL12 = u32Reload;

    if(TIMER_enTIMER34 & enTimer)
        TIMER_BASE->REL34 = u32Reload;
}

uint32_t TIMER__u32GetReload(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    return((enTimer == TIMER_enTIMER12) ? TIMER_BASE->REL12 :TIMER_BASE->REL34);
}

uint32_t TIMER__u32GetCapture(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    return((enTimer == TIMER_enTIMER12) ? TIMER_BASE->CAP12 :TIMER_BASE->CAP34);
}

void TIMER__vSetCompare(TIMER_TypeDef* TIMER_BASE, Timer_nCompare enCompareUnit,uint32_t u32Compare)
{
    TIMER_BASE->CMP[enCompareUnit] = u32Compare;
}

uint32_t TIMER__u32GetCompare(TIMER_TypeDef* TIMER_BASE, Timer_nCompare enCompareUnit)
{
    /* Return the counter value according to the index requested */
    return(TIMER_BASE->CMP[enCompareUnit]);
}

void TIMER__vEnableInterrupt(TIMER_TypeDef* TIMER_BASE, Timer_nInterrupt enInterrupt)
{
    TIMER_BASE->INTCTLSTAT |= enInterrupt;
}

void TIMER__vDisableInterrupt(TIMER_TypeDef* TIMER_BASE, Timer_nInterrupt enInterrupt)
{
    TIMER_BASE->INTCTLSTAT &=~( enInterrupt);
}

Timer_nInterrupt TIMER__enGetInterruptStatus(TIMER_TypeDef* TIMER_BASE, Timer_nInterrupt enInterrupt)
{
    return (Timer_nInterrupt)((TIMER_BASE->INTCTLSTAT) & (uint32_t)enInterrupt);

}

Timer_nInterrupt TIMER__enClearInterruptStatus(TIMER_TypeDef* TIMER_BASE, Timer_nInterrupt enInterrupt)
{
    volatile Timer_nInterrupt enStatus =(Timer_nInterrupt)((TIMER_BASE->INTCTLSTAT)  & (uint32_t)enInterrupt);

    TIMER_BASE->INTCTLSTAT |= enStatus;
    return enStatus;

}

void TIMER__vSetPrescalarCount34(TIMER_TypeDef* TIMER_BASE, uint32_t u32Prescalar)
{
    TIMER_BASE->TGCR &= ~TIMER_TGCR_R_PSC34_MASK;
    TIMER_BASE->TGCR |= ((u32Prescalar<<TIMER_TGCR_R_PSC34_SHIFT) & TIMER_TGCR_R_PSC34_MASK);
}

uint32_t TIMER__u32GetPrescalarCount34(TIMER_TypeDef* TIMER_BASE)
{

    return(( TIMER_BASE->TGCR  & TIMER_TGCR_R_PSC34_MASK) >>
            TIMER_TGCR_R_PSC34_SHIFT);
}


void TIMER__vSetDivideDownRatio34(TIMER_TypeDef* TIMER_BASE,uint32_t u32DivideDown)
{
    TIMER_BASE->TGCR &= ~(TIMER_TGCR_R_TDDR34_MASK);

    TIMER_BASE->TGCR |= ((u32DivideDown<<TIMER_TGCR_R_TDDR34_SHIFT) & TIMER_TGCR_R_TDDR34_MASK);
}

uint32_t TIMER__u32GetDivideDownRatio34(TIMER_TypeDef* TIMER_BASE)
{
    return((TIMER_BASE->TGCR & TIMER_TGCR_R_TDDR34_MASK) >>
            TIMER_TGCR_R_TDDR34_SHIFT);
}

void TIMER__vConfigureCaptureModule(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer,
                           Timer_nCaptMode enConfigCapture)
{
    TIMER_BASE->TCR &= ~(enTimer & (TIMER_TCR_R_CAPVTMODE12_MASK | TIMER_TCR_R_CAPMODE12_MASK |
                                    TIMER_TCR_R_CAPVTMODE34_MASK | TIMER_TCR_R_CAPMODE34_MASK) );

    TIMER_BASE->TCR |= (enConfigCapture & enTimer);
}

void TIMER__vEnableReadResetCounter(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    TIMER_BASE->TCR |= (enTimer & (TIMER_TCR_R_READRSTMODE12_MASK | TIMER_TCR_R_READRSTMODE34_MASK));
}

void TIMER__vDisableReadResetCounter(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    TIMER_BASE->TCR &= ~(enTimer & (TIMER_TCR_R_READRSTMODE12_MASK | TIMER_TCR_R_READRSTMODE34_MASK));
}


void TIMER__vEnableInputGate(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    TIMER_BASE->TCR |= (enTimer & (TIMER_TCR_R_TIEN12_MASK | TIMER_TCR_R_TIEN34_MASK));
}


void TIMER__vDisableInputGate(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    TIMER_BASE->TCR &= ~(enTimer & (TIMER_TCR_R_TIEN12_MASK | TIMER_TCR_R_TIEN34_MASK));
}


void TIMER__vSetPulseWidth(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer,
                           Timer_nPulseWidth enPulseWidth)
{
    TIMER_BASE->TCR &= ~(enTimer & (TIMER_TCR_R_PWID34_MASK | TIMER_TCR_R_PWID12_MASK));

    TIMER_BASE->TCR |= (enPulseWidth & (TIMER_TCR_R_PWID34_MASK | TIMER_TCR_R_PWID12_MASK));
}

void TIMER__vSetClockMode(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    TIMER_BASE->TCR |= (enTimer & (TIMER_TCR_R_CP12_MASK | TIMER_TCR_R_CP34_MASK));
}

void TIMER__vSetPulseMode(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    TIMER_BASE->TCR &= ~(enTimer & (TIMER_TCR_R_CP12_MASK |TIMER_TCR_R_CP34_MASK));
}

Timer_nOutStatus TIMER__enGetOUTStatus(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    return(Timer_nOutStatus)(TIMER_BASE->TCR & (enTimer & (TIMER_TCR_R_TSTAT12_MASK |TIMER_TCR_R_TSTAT34_MASK)));
}

void TIMER__vEnableInvertIN(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    TIMER_BASE->TCR |= (enTimer & (TIMER_TCR_R_INVINP12_MASK | TIMER_TCR_R_INVINP34_MASK));
}

void TIMER__vDisableInvertIN(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    TIMER_BASE->TCR &= ~(enTimer & (TIMER_TCR_R_INVINP12_MASK | TIMER_TCR_R_INVINP34_MASK));
}


void TIMER__vEnableInvertOUT(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    TIMER_BASE->TCR |= (enTimer & (TIMER_TCR_R_INVOUTP12_MASK | TIMER_TCR_R_INVOUTP34_MASK));
}

void TIMER__vDisableInvertOUT(TIMER_TypeDef* TIMER_BASE, Timer_nEnable enTimer)
{
    TIMER_BASE->TCR &= ~(enTimer & (TIMER_TCR_R_INVOUTP12_MASK | TIMER_TCR_R_INVOUTP34_MASK));
}
