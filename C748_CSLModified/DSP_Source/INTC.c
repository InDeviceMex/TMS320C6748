/*
 * INTC.c
 *
 *  Created on: 16/04/2019
 *      Author: InDev
 */

#include "INTC.h"

static ISRRoutine ISRtable[INT_COUNT];
static ISRRoutine ECMtable[NUM_EVENTS];


#pragma NMI_INTERRUPT( INTC__vNmiHandler );
#pragma INTERRUPT ( INTC_vDefaultHandler );
#pragma INTERRUPT ( INTC__vRsvd2Handler );
#pragma INTERRUPT ( INTC__vRsvd3Handler );
#pragma INTERRUPT ( INTC__vInt4Handler );
#pragma INTERRUPT ( INTC__vInt5Handler );
#pragma INTERRUPT ( INTC__vInt6Handler );
#pragma INTERRUPT ( INTC__vInt7Handler );
#pragma INTERRUPT ( INTC__vInt8Handler );
#pragma INTERRUPT ( INTC__vInt9Handler );
#pragma INTERRUPT ( INTC__vInt10Handler );
#pragma INTERRUPT ( INTC__vInt11Handler );
#pragma INTERRUPT ( INTC__vInt12Handler );
#pragma INTERRUPT ( INTC__vInt14Handler );
#pragma INTERRUPT ( INTC__vInt13Handler );
#pragma INTERRUPT ( INTC__vInt15Handler );

#pragma FUNC_ALWAYS_INLINE( INTC__vVectorTable)
#pragma FUNC_ALWAYS_INLINE( INTC__vDspInit)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuIntRegisterRoutine)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuIntUnRegisterRoutine)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuNmiEnable)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuIntEnable)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuNmiDisable)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuIntDisable)
#pragma FUNC_ALWAYS_INLINE( INTC__enCpuIntReset)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventMap2CpuInt)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventSet)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventClear)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventCombineAdd)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventCombineRemove)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventCombineRegisterRoutine)
#pragma FUNC_ALWAYS_INLINE( INTC__enEventCombineInit)
#pragma FUNC_ALWAYS_INLINE( INTC__vExceptionGlobalEnable)
#pragma FUNC_ALWAYS_INLINE( INTC__enExceptionCombineAdd)
#pragma FUNC_ALWAYS_INLINE( INTC__ExceptionCombineRemove)


static void INTC_vDefaultHandler (void);
static void INTC_vEventCombineIsr0 (void);
static void INTC_vEventCombineIsr1 (void);
static void INTC_vEventCombineIsr2 (void);
static void INTC_vEventCombineIsr3 (void);
static void INTC_vEventCombinerDispatch (Intc_nEvent enEvtReg);



void INTC__vDspInit (void)
{
   uint32_t step = 0;

   #pragma MUST_ITERATE(16,,16)
   while(step != INT_COUNT)
       ISRtable[step++] = INTC_vDefaultHandler;

   ISTP = (uint32_t)INTC__vVectorTable;
   ICR = 0xFFF0;
   IER = (1 << NMI);
}




Intc_nStatus INTC__enCpuIntEnable (Intc_nMask enCpuInt)
{
    uint32_t u32RestoreVal;

    if((enCpuInt>15) || (enCpuInt<4) )
        return INTC_enERROR;

    u32RestoreVal =_disable_interrupts();

    IER |= (1 << enCpuInt);

    _restore_interrupts(u32RestoreVal);
    return INTC_enOK;
}


Intc_nStatus INTC__enCpuNmiEnable (Intc_nMask enCpuInt)
{
    uint32_t u32RestoreVal;

    if((enCpuInt!=MASK_enNMI) )
        return INTC_enERROR;

    u32RestoreVal =_disable_interrupts();

    IER |= (1 << enCpuInt);

    _restore_interrupts(u32RestoreVal);
    return INTC_enOK;
}

Intc_nStatus INTC__enCpuIntDisable (Intc_nMask enCpuInt)
{
    uint32_t u32RestoreVal;

    if((enCpuInt>15) || (enCpuInt<4) )
        return INTC_enERROR;

    u32RestoreVal =_disable_interrupts();

    IER &=~ (1 << enCpuInt);

    _restore_interrupts(u32RestoreVal);
    return INTC_enOK;
}


Intc_nStatus INTC__enCpuNmiDisable (Intc_nMask enCpuInt)
{
    uint32_t u32RestoreVal;

    if((enCpuInt!=MASK_enNMI) )
        return INTC_enERROR;

    u32RestoreVal =_disable_interrupts();

    IER &=~ (1 << enCpuInt);

    _restore_interrupts(u32RestoreVal);
    return INTC_enOK;
}
void INTC__enCpuIntReset (void)
{
    uint32_t u32RestoreVal;


    u32RestoreVal =_disable_interrupts();

    IER = 0x1;

    _restore_interrupts(u32RestoreVal);
}


Intc_nStatus INTC__enCpuIntRegisterRoutine (Intc_nMask enCpuInt, void (*userISR)(void))
{
    if((enCpuInt>15) || (enCpuInt<1) )
        return INTC_enERROR;
    ISRtable[enCpuInt] = userISR;

    return INTC_enOK;
}

Intc_nStatus INTC__enCpuIntUnRegisterRoutine (Intc_nMask enCpuInt)
{
    if((enCpuInt>15) || (enCpuInt<1) )
        return INTC_enERROR;

    ISRtable[enCpuInt] = INTC_vDefaultHandler;
    return INTC_enOK;
}






Intc_nStatus INTC__enEventMap2CpuInt (Intc_nMask enCpuInt, Intc_nEvent enSysInt)
{
    uint32_t u32DspIntcReg, u32RestoreVal;

    if((enCpuInt>15) || (enCpuInt<4) )
        return INTC_enERROR;

    if(enSysInt>127 )
        return INTC_enERROR;

    u32DspIntcReg = INTC->INTMUX[(enCpuInt >> 2)];
    //u32DspIntcReg = INTC->INTMUX[(enCpuInt >> 2)];
    u32RestoreVal=_disable_interrupts();

    //problem with the structure
    INTC->INTMUX[(enCpuInt >> 2)] = (u32DspIntcReg & ~INTC_INTMUX_R_INTSEL(enCpuInt)) |
            (enSysInt << INTC_INTMUX_R_INTSEL_SHIFT(enCpuInt));

    ICR = (1 << enCpuInt);
    _restore_interrupts(u32RestoreVal);

    return INTC_enOK;
}

Intc_nStatus INTC__enEventSet (Intc_nEvent enSysInt)
{
    if(enSysInt>127 )
        return INTC_enERROR;
    /* Set the corresponding bit within the event flag register */
    INTC_EVTSET_R((enSysInt >> 5)) = INTC_EVTSET_R_ES(enSysInt);

    return INTC_enOK;
}


Intc_nStatus INTC__enEventClear (Intc_nEvent enSysInt)
{
    if(enSysInt>127 )
        return INTC_enERROR;
    /* Set the corresponding bit within the event flag register */
    INTC_EVTCLR_R((enSysInt >> 5)) = INTC_EVTCLR_R_EC(enSysInt);

    return INTC_enOK;
}


Intc_nStatus INTC__enEventCombineAdd(Intc_nEvent enSysInt)
{
    uint32_t u32RestoreVal;

    if(enSysInt>127 )
        return INTC_enERROR;

    u32RestoreVal=_disable_interrupts();

    INTC_EVTMASK_R(enSysInt >> 5) &= ~INTC_EVTMASK_R_EM(enSysInt);

    _restore_interrupts(u32RestoreVal);

    return INTC_enOK;
}

Intc_nStatus INTC__enEventCombineRemove(Intc_nEvent enSysInt)
{
    uint32_t u32RestoreVal;

    if(enSysInt>127 )
        return INTC_enERROR;


    u32RestoreVal=_disable_interrupts();
    INTC_EVTMASK_R(enSysInt >> 5) |= INTC_EVTMASK_R_EM(enSysInt);

    _restore_interrupts(u32RestoreVal);

    return INTC_enOK;
}

Intc_nStatus INTC__enEventCombineRegisterRoutine(Intc_nEvent enSysInt, void (*userISR)(void))
{
    /* Check the system event number */
    if((enSysInt>127) || (enSysInt<4) )
        return INTC_enERROR;

    ECMtable[enSysInt] = userISR;
    return INTC_enOK;
}



Intc_nStatus INTC__enEventCombineInit(Intc_nMask enEcmInt0, Intc_nMask enEcmInt1, Intc_nMask enEcmInt2, Intc_nMask enEcmInt3)
{
    uint32_t u32Step = 0;

    /* Check the parameters */
    if(((enEcmInt0<4)  || (enEcmInt0>15)) && (enEcmInt0!=EVENT_enUnused))
        return INTC_enERROR;
    if(((enEcmInt1<4)  || (enEcmInt1>15)) && (enEcmInt1!=EVENT_enUnused))
        return INTC_enERROR;
    if(((enEcmInt2<4)  || (enEcmInt2>15)) && (enEcmInt2!=EVENT_enUnused))
        return INTC_enERROR;
    if(((enEcmInt3<4)  || (enEcmInt3>15)) && (enEcmInt3!=EVENT_enUnused))
        return INTC_enERROR;

    while(u32Step < NUM_EVENTS)
    {
        /* Remove system event from ECM */
        INTC__enEventCombineRemove((Intc_nEvent)u32Step);

        /* Set ISR to default "do-nothing" routine */
        ECMtable[u32Step++] = INTC_vDefaultHandler;
    }

    if(enEcmInt0 != EVENT_enUnused)
    {
        /* Register the ECM ISR to the CPU interrupt */
        INTC__enCpuIntRegisterRoutine(enEcmInt0, INTC_vEventCombineIsr0);

        /* Map the ECM system event to the CPU interrupt */
        INTC__enEventMap2CpuInt(enEcmInt0, EVENT_enEVT0);

        /* Enable the CPU interrupt */
        INTC__enCpuIntEnable(enEcmInt0);
    }

    if(enEcmInt1 != EVENT_enUnused)
    {
        /* Register the ECM ISR to the CPU interrupt */
        INTC__enCpuIntRegisterRoutine(enEcmInt1, INTC_vEventCombineIsr1);

        /* Map the ECM system event to the CPU interrupt */
        INTC__enEventMap2CpuInt(enEcmInt1, EVENT_enEVT1);

        /* Enable the CPU interrupt */
        INTC__enCpuIntEnable(enEcmInt1);
    }

    if(enEcmInt2 != EVENT_enUnused)
    {
        /* Register the ECM ISR to the CPU interrupt */
        INTC__enCpuIntRegisterRoutine(enEcmInt2, INTC_vEventCombineIsr2);

        /* Map the ECM system event to the CPU interrupt */
        INTC__enEventMap2CpuInt(enEcmInt2, EVENT_enEVT2);

        /* Enable the CPU interrupt */
        INTC__enCpuIntEnable(enEcmInt2);
    }

    if(enEcmInt3 != EVENT_enUnused)
    {
        /* Register the ECM ISR to the CPU interrupt */
        INTC__enCpuIntRegisterRoutine(enEcmInt2, INTC_vEventCombineIsr3);

        /* Map the ECM system event to the CPU interrupt */
        INTC__enEventMap2CpuInt(enEcmInt2, EVENT_enEVT3);

        /* Enable the CPU interrupt */
        INTC__enCpuIntEnable(enEcmInt2);
    }

    return INTC_enOK;
}


void INTC__vExceptionGlobalEnable (void)
{
    /* clear all exceptions */
    ECR = ~0u;

    /* enable all exceptions */
    TSR |= ((1 << GEE) | (1 << XEN));
}


Intc_nStatus INTC__enExceptionCombineAdd(Intc_nEvent enSysInt)
{

    /* Check the system event number */
    if(enSysInt>127)
        return INTC_enERROR;

    /* Get the address of the correct event combiner register */

    /* Unmask system event number to be included in the combined event */
    INTC_EXPMASK_R(enSysInt >> 5) &= ~INTC_EVTMASK_R_EM(enSysInt);
    return INTC_enOK;
}


Intc_nStatus INTC__ExceptionCombineRemove(Intc_nEvent enSysInt)
{

    /* Check the system event number */
    if(enSysInt>127)
        return INTC_enERROR;


    /* Mask system event number to be removed from the combined event */
    INTC_EXPMASK_R(enSysInt >> 5) |= INTC_EVTMASK_R_EM(enSysInt);
    return INTC_enOK;
}




static void INTC_vEventCombineIsr0 (void)
{
    INTC_vEventCombinerDispatch(EVENT_enEVT0);
}

static void INTC_vEventCombineIsr1 (void)
{
    INTC_vEventCombinerDispatch(EVENT_enEVT1);
}

static void INTC_vEventCombineIsr2 (void)
{
    INTC_vEventCombinerDispatch(EVENT_enEVT2);
}

static void INTC_vEventCombineIsr3 (void)
{
    INTC_vEventCombinerDispatch(EVENT_enEVT3);
}

static void INTC_vEventCombinerDispatch (Intc_nEvent enEvtReg)
{
    uint32_t  u32EvtRcv, u32EvtIndex, u32Offset;

    /* Get the address of the correct DSPINTC registers */


    u32Offset = enEvtReg * 32;
    u32EvtRcv = INTC_MEVTFLAG_R(enEvtReg);

    while(u32EvtRcv)
    {
        /* Clear system events */
        INTC_EVTCLR_R(enEvtReg) = u32EvtRcv;

        /* Service system events */
        do{
            u32EvtIndex = 31 - _lmbd(1, u32EvtRcv);
            u32EvtRcv &= ~(1 << u32EvtIndex);
            ECMtable[u32EvtIndex + u32Offset]();
        }while(u32EvtRcv);

        /* Check for new system events */
        u32EvtRcv = INTC_MEVTFLAG_R(enEvtReg);
    }
}


interrupt void INTC_vDefaultHandler (void)
{
    while(1);
}
interrupt void INTC__vNmiHandler (void)
{
    ISRtable[1]();
}

interrupt void INTC__vRsvd2Handler (void)
{
    ISRtable[2]();
}

interrupt void INTC__vRsvd3Handler (void)
{
    ISRtable[3]();
}

interrupt void INTC__vInt4Handler (void)
{
    ICR=0x10;
    ISRtable[4]();
}

interrupt void INTC__vInt5Handler (void)
{
    ICR=0x20;
    ISRtable[5]();
}

interrupt void INTC__vInt6Handler (void)
{
    ICR=0x40;
    ISRtable[6]();
}

interrupt void INTC__vInt7Handler (void)
{
    ICR=0x80;
    ISRtable[7]();
}

interrupt void INTC__vInt8Handler (void)
{
    ICR=0x100;
    ISRtable[8]();
}

interrupt void INTC__vInt9Handler (void)
{
    ICR=0x200;
    ISRtable[9]();
}

interrupt void INTC__vInt10Handler (void)
{
    ICR=0x400;
    ISRtable[10]();
}

interrupt void INTC__vInt11Handler (void)
{
    ICR=0x800;
    ISRtable[11]();
}

interrupt void INTC__vInt12Handler (void)
{
    ICR=0x1000;
    ISRtable[12]();
}

interrupt void INTC__vInt13Handler (void)
{
    ICR=0x2000;
    ISRtable[13]();
}

interrupt void INTC__vInt14Handler (void)
{
    ICR=0x4000;
    ISRtable[14]();
}

interrupt void INTC__vInt15Handler (void)
{
    ICR=0x8000;
    ISRtable[15]();
}


