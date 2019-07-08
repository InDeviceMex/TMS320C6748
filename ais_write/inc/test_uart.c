/*========================================================*
 * 文件模块说明:
 *C6748的串口   
 * 文件版本: V1.0.0
 * 开发人员: Rock
 * 创建时间: 2013-11-01 
 * Copyright(c) 2013-2015  Rock-Embed Limited Co.
 *========================================================*
 * 程序修改记录：
 * <版本号> <修改日期>, <修改人员>: <修改功能概述>
 *      V1.0.0           2013-11-01              Rock                        创建
 *========================================================*/
#include "types.h"
#include "test_uart.h"
#include <stdio.h>
#include <string.h>


#define DEBUG_PORT           (1)//uart1
#define DEBUG_PORT_BaudRate  (57600)//uart1


void DebugUartInit(void)
{  
	RK6748_uartInit(DEBUG_PORT,DEBUG_PORT_BaudRate);
}


void DebugPrintf(UINT8 *pData)
{
	RK6748_uartSend(DEBUG_PORT,pData);
	printf(pData);
}
