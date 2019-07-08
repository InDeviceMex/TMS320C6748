/*========================================================*
 * �ļ�ģ��˵��:
 *C6748�Ĵ���   
 * �ļ��汾: V1.0.0
 * ������Ա: Rock
 * ����ʱ��: 2013-11-01 
 * Copyright(c) 2013-2015  Rock-Embed Limited Co.
 *========================================================*
 * �����޸ļ�¼��
 * <�汾��> <�޸�����>, <�޸���Ա>: <�޸Ĺ��ܸ���>
 *      V1.0.0           2013-11-01              Rock                        ����
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
