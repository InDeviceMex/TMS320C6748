//-----------------------------------------------------------------------------
// \file    main.c
// \brief   implementation of main() to test bsl drivers.
//
//-----------------------------------------------------------------------------
#include "types.h"
#include "stdio.h"
#include "test_led.h"

#include <stdio.h>
#include <string.h>

//-----------------------------------------------------------------------------
// \brief   entry point for bsl test code.
//
// \param   none.
//
// \return  none.
//-----------------------------------------------------------------------------
void main(void)
{	
	USTIMER_init();
	LED_init();
	DebugUartInit();
	

	TEST_lcd();

	TEST_led();
}

