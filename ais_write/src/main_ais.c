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
	EMIFA_init();
	
	DebugPrintf("------------------------------------------------------------\r\n");
	DebugPrintf("                    C6748 AIS_Write Test\r\n\r\n");

	
	AIS_write();

	DebugPrintf("                    C6748 AIS_Write OK!\r\n\r\n");
	DebugPrintf("------------------------------------------------------------\r\n");
	
	while (1)
   	{
      	MsDelay(500);
		LED1_ON();
		MsDelay(500);
		LED1_OFF();
   	}	
}
