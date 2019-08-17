/*
 * SysTick.c
 *
 *  Created on: 18/07/2019
 *      Author: Lalo
 */


#include "SysTick.h"

#pragma FUNC_ALWAYS_INLINE( SysTick_vInitTimer0)
#pragma FUNC_ALWAYS_INLINE( SysTick__enInitTick)
#pragma FUNC_ALWAYS_INLINE( SysTick__enInitFrec)
#pragma FUNC_ALWAYS_INLINE( SysTick__enInitUs)
#pragma FUNC_ALWAYS_INLINE( SysTick__vDelayUs)
#pragma FUNC_ALWAYS_INLINE( SysTick__vRestart)
#pragma FUNC_ALWAYS_INLINE( SysTick__fGetTimeUs)
#pragma FUNC_ALWAYS_INLINE( SysTick__fGetFrec)
#pragma FUNC_ALWAYS_INLINE( SysTick__u64GetCount)
#pragma FUNC_ALWAYS_INLINE( SysTick__u64GetCountMax)
#pragma FUNC_ALWAYS_INLINE(SysTick__u64GetCountOv)



void SysTick_vInitTimer0(uint32_t u32Ticks);
void SysTick_vIsr(void);

volatile uint32_t SysTick_u32CountOv=0;
volatile uint32_t SysTick_u32Count=0;
volatile float SysTick_fUsTick=0;
volatile float SysTick_fFrecTick=0;
volatile uint32_t SysTick_u32CountTick=0;

void SysTick_vInitTimer0(uint32_t u32Ticks)
{

    TIMER0_GPINTGPEN_R=0;
    TIMER0_GPDATGPDIR_R=0;
    TIMER0_TGCR->PSC34=0;
    TIMER0_TGCR->TDDR34=0;
    TIMER0_PRD12_R=u32Ticks-1;
    TIMER0_PRD34_R=0;
    TIMER0_TIM12_R=0;
    TIMER0_TIM34_R=0;

    TIMER0_TCR_R=0;
    TIMER0_TCR->ENAMODE12=2;
    TIMER0_TGCR->PLUSEN=1;
    TIMER0_TGCR->TIMMODE=1;
    TIMER0_TGCR->TIM12RS=1;
    TIMER0_INTCTLSTAT_R=0;
    TIMER0_INTCTLSTAT->PRDINTSTAT12=1;
    TIMER0_INTCTLSTAT->PRDINTEN12=1;
}

SysTick_nStatus SysTick__enInitTick(uint32_t u32Tick)
{
    volatile uint32_t u32CPUFrec=0;
    volatile float fCPUFrec=0,fCPUUs;

    TIMER0_TGCR->TIM34RS=0;
    TIMER0_TGCR->TIM12RS=0;
    INTC__enCpuIntRegisterRoutine(MASK_enINT4,SysTick_vIsr);
    INTC__enEventMap2CpuInt(MASK_enINT4,EVENT_enT64P0_TINT12);
    INTC__enCpuIntEnable(MASK_enINT4);


    u32CPUFrec=25000000u;//PLL__u32GetSysClockFreq();

    if(u32Tick==0)
    {
        SysTick_fFrecTick=0;
        SysTick_fUsTick=0;
        return SysTick_enERROR;
    }

    fCPUFrec=(float)u32CPUFrec;
    fCPUFrec/=(float)u32Tick;
    fCPUUs=1000000.0;
    fCPUUs/=fCPUFrec;

    SysTick_u32Count=0;
    SysTick_fFrecTick=fCPUFrec;
    SysTick_fUsTick=fCPUUs;
    SysTick_u32CountTick=u32Tick;

    SysTick_vInitTimer0(u32Tick);
    return SysTick_enOK;
}


SysTick_nStatus SysTick__enInitFrec(float fFrec)
{
    volatile uint32_t u32CPUFrec=0,u64Count=0;
    volatile float fCPUFrec=0,fCount=0;


    TIMER0_TGCR->TIM34RS=0;
    TIMER0_TGCR->TIM12RS=0;
    INTC__enCpuIntRegisterRoutine(MASK_enINT4,SysTick_vIsr);
    INTC__enEventMap2CpuInt(MASK_enINT4,EVENT_enT64P0_TINT12);
    INTC__enCpuIntEnable(MASK_enINT4);


    u32CPUFrec=25000000u;//PLL__u32GetSysClockFreq();

    fCPUFrec=(float)u32CPUFrec;
    fCount=fCPUFrec/fFrec;
    u64Count=(uint32_t)fCount;
    if(u64Count>0xFFFFFFFF)
    {
        SysTick_fFrecTick=0;
        SysTick_fUsTick=0;
        return SysTick_enERROR;
    }

    if(u64Count<10)
    {
        SysTick_fFrecTick=0;
        SysTick_fUsTick=0;
        return SysTick_enERROR;
    }



    SysTick_u32Count=0;
    SysTick_fFrecTick=fFrec;
    SysTick_fUsTick=1000000.0;
    SysTick_fUsTick/=fFrec;
    SysTick_u32CountTick=u64Count;

    SysTick_vInitTimer0((uint32_t)u64Count);
    return SysTick_enOK;
}

SysTick_nStatus SysTick__enInitUs(float fTimeUs)
{
    volatile uint32_t u32CPUFrec=0,u64Count=0;
    volatile float fCPUFrec=0,fCount=0;

    TIMER0_TGCR->TIM34RS=0;
    TIMER0_TGCR->TIM12RS=0;
    INTC__enCpuIntRegisterRoutine(MASK_enINT4,SysTick_vIsr);
    INTC__enEventMap2CpuInt(MASK_enINT4,EVENT_enT64P0_TINT12);
    INTC__enCpuIntEnable(MASK_enINT4);


    u32CPUFrec=25000000u;//PLL__u32GetSysClockFreq();
    fCPUFrec=(float)u32CPUFrec;
    fCPUFrec/=1000000;
    fCount=fCPUFrec*fTimeUs;
    u64Count=(uint32_t)fCount;
    if(u64Count>0xFFFFFFFF)
    {
        SysTick_fFrecTick=0;
        SysTick_fUsTick=0;
        return SysTick_enERROR;
    }
    if(u64Count<10)
    {
        SysTick_fFrecTick=0;
        SysTick_fUsTick=0;
        return SysTick_enERROR;
    }


    SysTick_u32Count=0;

    SysTick_fFrecTick=1000000.0;
    SysTick_fFrecTick/=fTimeUs;
    SysTick_fUsTick=fTimeUs;
    SysTick_u32CountTick=u64Count;

    SysTick_vInitTimer0((uint32_t)u64Count);
    return SysTick_enOK;
}


void SysTick__vRestart(void)
{
    SysTick_u32Count=0;
}


float SysTick__fGetTimeUs(void)
{
    return (float)SysTick_u32Count*SysTick_fUsTick;
}

float SysTick__fGetFrec(void)
{
    return SysTick_fFrecTick/(float)SysTick_u32Count;
}


uint64_t SysTick__u64GetCount(void)
{
    return (uint64_t)SysTick_u32CountTick*(uint64_t)SysTick_u32Count;
}
uint64_t SysTick__u64GetCountOv(void)
{
    return (uint64_t)SysTick_u32CountOv;
}
uint64_t SysTick__u64GetCountMax(void)
{
    return (uint64_t)SysTick_u32CountTick*(uint64_t)0xFFFFFFFF;
}

__inline void SysTick__vDelayUs(float fTimeUs)
{
    volatile uint64_t u64Count=0;
    volatile uint64_t u64Dif=0;
    volatile uint64_t u64DifOv=0;

    volatile uint64_t u64Max=SysTick__u64GetCountMax();
    volatile float fCount= fTimeUs/SysTick_fUsTick;
    fCount*= (float)SysTick_u32CountTick;
    u64Count= (uint64_t)fCount;


    volatile uint64_t u64ActualUs=0;
    volatile uint64_t u64TempUs=0;
    volatile uint32_t u32TempOv=0;

    volatile uint64_t u64AnteriorUs=SysTick__u64GetCount();
    volatile uint64_t u64AnteriorOv=SysTick__u64GetCountOv();
    while((uint64_t)u64Count>(uint64_t)u64ActualUs)
    {
        u32TempOv=SysTick__u64GetCountOv();
        u64DifOv=u32TempOv-u64AnteriorOv;
        u64AnteriorOv=u32TempOv;

        u64TempUs=SysTick__u64GetCount();
        u64Dif=(u64TempUs-u64AnteriorUs);

        if(u64DifOv>0){
            u64DifOv*=u64Max;
            u64Dif+=u64DifOv;

        }
        u64AnteriorUs=u64TempUs;
        u64ActualUs+=u64Dif;
    }
}

void SysTick_vIsr(void)
{
    INTC__enEventClear(EVENT_enT64P0_TINT12);
    TIMER0_INTCTLSTAT_R|=TIMER_INTCTLSTAT_R_PRDINTSTAT12_MASK;
    SysTick_u32Count++;
    if(SysTick_u32Count==0)
        SysTick_u32CountOv++;
}


