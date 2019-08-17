/*
 * SysTick.h
 *
 *  Created on: 18/07/2019
 *      Author: Lalo
 */

#ifndef APP_INCLUDE_SYSTICK_H_
#define APP_INCLUDE_SYSTICK_H_

#include "Core.h"
#include "TIMER.h"
#include "INTC.h"
#include "GPIO.h"
#include <stdint.h>                             /* standard types definitions                      */




typedef enum
{
    SysTick_enOK = 0,
    SysTick_enERROR = 1,
}SysTick_nStatus;


#pragma FUNC_ALWAYS_INLINE( SysTick__enInitTick)
#pragma FUNC_ALWAYS_INLINE( SysTick__enInitFrec)
#pragma FUNC_ALWAYS_INLINE( SysTick__enInitUs)
#pragma FUNC_ALWAYS_INLINE( SysTick__vDelayUs)
#pragma FUNC_ALWAYS_INLINE( SysTick__vRestart)
#pragma FUNC_ALWAYS_INLINE( SysTick__fGetTimeUs)
#pragma FUNC_ALWAYS_INLINE( SysTick__fGetFrec)
#pragma FUNC_ALWAYS_INLINE( SysTick__u64GetCount)

SysTick_nStatus SysTick__enInitTick(uint32_t u32Tick);
SysTick_nStatus SysTick__enInitFrec(float fFrec);
SysTick_nStatus SysTick__enInitUs(float fTimeUs);

__inline void SysTick__vDelayUs(float fTimeUs);
void SysTick__vRestart(void);
float SysTick__fGetTimeUs(void);
float SysTick__fGetFrec(void);
uint64_t SysTick__u64GetCount(void);
uint64_t SysTick__u64GetCountMax(void);
uint64_t SysTick__u64GetCountOv(void);




#endif /* APP_INCLUDE_SYSTICK_H_ */
