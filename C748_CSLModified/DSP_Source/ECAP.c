/*
 * ECAP.c
 *
 *  Created on: 19/07/2019
 *      Author: Lalo
 */

#include "ECAP.h"

void ECAP__vEnableCaptureLoading(ECAP_TypeDef* ECAP_BASE)
{
    ECAP_BASE->ECCTL1 |= ECAP_ECCTL1_R_CAPLDEN_MASK;
}

void ECAP__vDisableCaptureLoading(ECAP_TypeDef* ECAP_BASE)
{
    ECAP_BASE->ECCTL1&= ~ECAP_ECCTL1_R_CAPLDEN_MASK;
}


void ECAP__vConfigPrescale(ECAP_TypeDef* ECAP_BASE, uint8_t u8Prescale)
{
    if(u8Prescale>0x1F)
        u8Prescale=0x1F;
    ECAP_BASE->ECCTL1&= 0xffffc1ff;
    ECAP_BASE->ECCTL1 |= (u8Prescale << ECAP_ECCTL1_R_PRESCALE_SHIFT);
}

void ECAP__vSelectOperatingMode(ECAP_TypeDef* ECAP_BASE, Ecap_nMode enModeSelect)
{
    if(enModeSelect)
         ECAP_BASE->ECCTL2&= ~ECAP_ECCTL2_R_CAP_APWM_MASK;
    else
         ECAP_BASE->ECCTL2 |=  ECAP_ECCTL2_R_CAP_APWM_MASK;
}


uint32_t ECAP__u32ReadTimeStamp(ECAP_TypeDef* ECAP_BASE, Ecap_nCapureEvent enCaptureEvent)
{
    return (ECAP_BASE->CAP[enCaptureEvent]);

}


void ECAP__vConfigCounter(ECAP_TypeDef* ECAP_BASE, uint32_t u32CountVal)
{
    ECAP_BASE->TSCTR= u32CountVal;
}

void ECAP__vConfigCaptureEventPolarity(ECAP_TypeDef* ECAP_BASE, Ecap_nCapurePolarity enCapEvent1Polarity,
                                  Ecap_nCapurePolarity enCapEvent2Polarity, Ecap_nCapurePolarity enCapEvent3Polarity,
                                  Ecap_nCapurePolarity enCapEvent4Polarity)
{
    ECAP_BASE->ECCTL1 |= enCapEvent1Polarity << 0;
    ECAP_BASE->ECCTL1 |= enCapEvent2Polarity << 2;
    ECAP_BASE->ECCTL1 |= enCapEvent3Polarity << 4;
    ECAP_BASE->ECCTL1 |= enCapEvent4Polarity << 6;
}

void ECAP__vConfigCaptureEventCounterReset(ECAP_TypeDef* ECAP_BASE, Ecap_nCapureResetCounter enCounterRst1,
                                    Ecap_nCapureResetCounter enCounterRst2,Ecap_nCapureResetCounter enCounterRst3,
                                    Ecap_nCapureResetCounter enCounterRst4)
{
    ECAP_BASE->ECCTL1 |= enCounterRst1 << 1;
    ECAP_BASE->ECCTL1 |= enCounterRst2 << 3;
    ECAP_BASE->ECCTL1 |= enCounterRst3 << 5;
    ECAP_BASE->ECCTL1 |= enCounterRst4 << 7;
}


void ECAP__vConfigContinousMode(ECAP_TypeDef* ECAP_BASE)
{
    ECAP_BASE->ECCTL2&= ~ECAP_ECCTL2_R_CONT_ONESHT_MASK;
}

void ECAP__vConfigOneShotMode(ECAP_TypeDef* ECAP_BASE, Ecap_nCapureEventStop enStopVal)
{
    ECAP_BASE->ECCTL2 |= ECAP_ECCTL2_R_CONT_ONESHT_MASK;
    ECAP_BASE->ECCTL2&= 0xfffffff9;
    ECAP_BASE->ECCTL2 |= enStopVal;
}

void ECAP__vReArmOneShot(ECAP_TypeDef* ECAP_BASE)
{
    ECAP_BASE->ECCTL2 |= ECAP_ECCTL2_R_RE_ARM_MASK;
}

void ECAP__vConfigApwmPolarity(ECAP_TypeDef* ECAP_BASE, Ecap_nApwmActive enFlag)
{
    if(enFlag)
         ECAP_BASE->ECCTL2 |= ECAP_ECCTL2_R_APWMPOL_MASK;
    else
         ECAP_BASE->ECCTL2&= ~ECAP_ECCTL2_R_APWMPOL_MASK;
}


void ECAP__vSetCounterControl(ECAP_TypeDef* ECAP_BASE, Ecap_nCounterControl enFlag)
{
    if(enFlag)
         ECAP_BASE->ECCTL2 |= ECAP_ECCTL2_R_TSCTRSTOP_MASK;
    else
         ECAP_BASE->ECCTL2&= ~ECAP_ECCTL2_R_TSCTRSTOP_MASK;
}

void ECAP__vSelectSyncInOut(ECAP_TypeDef* ECAP_BASE, Ecap_nSyncIn enSyncIn,
                            Ecap_nSyncOut ensSyncOut)
{
    ECAP_BASE->ECCTL2&= 0xffffffdf;
    ECAP_BASE->ECCTL2 |= enSyncIn;
    ECAP_BASE->ECCTL2&= 0xffffff3f;
    ECAP_BASE->ECCTL2 |= ensSyncOut;
}


void ECAP__vConfigApwmCapture(ECAP_TypeDef* ECAP_BASE, uint32_t u32CompareVal,
                           uint32_t u32PeriodVal)
{
    ECAP_BASE->CAP[0]= u32PeriodVal;
    ECAP_BASE->CAP[1]= u32CompareVal;
}


void ECAP__vConfigApwmShadowCapture(ECAP_TypeDef* ECAP_BASE, uint32_t u32CompareVal,
                                 uint32_t u32PeriodVal)
{
    ECAP_BASE->CAP[0]= u32PeriodVal;
    ECAP_BASE->CAP[1]= u32CompareVal;
}

void ECAP__vConfigCounterPhase(ECAP_TypeDef* ECAP_BASE, uint32_t u32CountPhaseVal)
{
    ECAP_BASE->CTRPHS= u32CountPhaseVal;
}


void ECAP__vEnableGlobalInt(ECAP_TypeDef* ECAP_BASE)
{
    ECAP_BASE->ECCLR |= ECAP_ECCLR_R_INT_MASK;
}

void ECAP__vEnableInterrupt(ECAP_TypeDef* ECAP_BASE, Ecap_nInterrupt enFlag)
{
    ECAP_BASE->ECEINT |= enFlag;
}
void ECAP__vDisableInterrupt(ECAP_TypeDef* ECAP_BASE, Ecap_nInterrupt enFlag)
{
    ECAP_BASE->ECEINT &=~ enFlag;
}

Ecap_nInterrupt ECAP__enGetStatusInterrupt(ECAP_TypeDef* ECAP_BASE, Ecap_nInterrupt enFlag)
{
    return (Ecap_nInterrupt)(ECAP_BASE->ECFLG &(uint32_t) enFlag);
}

void ECAP__vClearStatusInterrupt(ECAP_TypeDef* ECAP_BASE, Ecap_nInterrupt enFlag)
{
    ECAP_BASE->ECCLR= ECAP_BASE->ECCLR& enFlag;
}


uint32_t ECAP__u32GetPeripheralId(ECAP_TypeDef* ECAP_BASE)
{
    return(ECAP_BASE->REVID);
}

void ECAP_vSaveContext(ECAP_TypeDef* ECAP_BASE,ECAP_Context_TypeDef *psContext)
{
    psContext->TSCTR = ECAP_BASE->TSCTR;
    psContext->ECEINT = ECAP_BASE->ECEINT;
    psContext->ECCLR = ECAP_BASE->ECCLR;
    psContext->ECCTL2 = ECAP_BASE->ECCTL2;
    psContext->CAP1 = ECAP_BASE->CAP[0];
    psContext->CAP2 = ECAP_BASE->CAP[1];
}

void ECAP_vRestoreContext(ECAP_TypeDef* ECAP_BASE,ECAP_Context_TypeDef *psContext)
{
    ECAP_BASE->TSCTR= psContext->TSCTR;
    ECAP_BASE->ECEINT= psContext->ECEINT;
    ECAP_BASE->ECCLR= psContext->ECCLR;
    ECAP_BASE->ECCTL2= psContext->ECCTL2;
    ECAP_BASE->CAP[0]= psContext->CAP1;
    ECAP_BASE->CAP[1]= psContext->CAP2;
}



