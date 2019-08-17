/*
 * SYSCFG.c
 *
 *  Created on: 21/04/2019
 *      Author: InDev
 */

#include "SYSCFG.h"


#pragma FUNC_ALWAYS_INLINE( SYSCFG__vResgistersUnlock)
#pragma FUNC_ALWAYS_INLINE( SYSCFG__vResgistersLock)

void SYSCFG__vResgistersUnlock(void)
{
    SYSCFG0_KICK0R_R= SYSCFG_KICK0R_R_KICK0_KEY;
    SYSCFG0_KICK1R_R= SYSCFG_KICK1R_R_KICK1_KEY;
}

void SYSCFG__vResgistersLock(void)
{
    SYSCFG0_KICK0R_R= SYSCFG_KICK0R_R_KICK0_MASK;
    SYSCFG0_KICK1R_R= SYSCFG_KICK1R_R_KICK1_MASK;
}
