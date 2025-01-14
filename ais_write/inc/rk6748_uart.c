/*========================================================*
 * 文件模块说明:
 *C6748的串口驱动，1和2是RS232，0是TTL    
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
#include "rk6748.h"

#include "test_uart.h"

// pinmux defines.
#define PINMUX_UART0_REG      (3)
#define PINMUX_UART0_MASK     (0x0000FFFF)
#define PINMUX_UART0_VAL      (0x00002222)
#define PINMUX_UART1_REG_0    (0)
#define PINMUX_UART1_MASK_0   (0x00FF0000)
#define PINMUX_UART1_VAL_0    (0x00220000)
#define PINMUX_UART1_REG_1    (4)
#define PINMUX_UART1_MASK_1   (0xFF000000)
#define PINMUX_UART1_VAL_1    (0x22000000)
#define PINMUX_UART2_REG_0    (0)
#define PINMUX_UART2_MASK_0   (0xFF000000)
#define PINMUX_UART2_VAL_0    (0x44000000)
#define PINMUX_UART2_REG_1    (4)
#define PINMUX_UART2_MASK_1   (0x00FF0000)
#define PINMUX_UART2_VAL_1    (0x00220000)


#define UART_REG_READ(base,reg, result) \
    ((result) = (*(volatile UINT32 *)((UINT32)base + (reg))))
#define UART_REG_WRITE(base,reg, data) \
	((*(volatile UINT32 *)((UINT32)base + (reg))) = (data))
 
UINT8 LRecvBuf[1024];
UINT32 LBufRecvCounter;
UINT32 RK6748_uartBase[]={UART0_BASE,UART1_BASE,UART2_BASE};


UINT8 RK6748_uartInit(UINT8 bySioNum,UINT32 dwBaudRate)//int baudrate
{
	UINT32 base,divisor;
    UINT8  byLCR;

	UINT32 i;

	switch (bySioNum)
   	{
      case 0:
         RK6748_lpscTransition(PSC0, DOMAIN0, LPSC_UART0, PSC_ENABLE);
         RK6748_pinmuxConfig(PINMUX_UART0_REG, PINMUX_UART0_MASK, PINMUX_UART0_VAL);
         break;
         
      case 1:
         RK6748_lpscTransition(PSC1, DOMAIN0, LPSC_UART1, PSC_ENABLE);
         RK6748_pinmuxConfig(PINMUX_UART1_REG_0, PINMUX_UART1_MASK_0, PINMUX_UART1_VAL_0);
         RK6748_pinmuxConfig(PINMUX_UART1_REG_1, PINMUX_UART1_MASK_1, PINMUX_UART1_VAL_1);
         break;
         
      case 2:
         RK6748_lpscTransition(PSC1, DOMAIN0, LPSC_UART2, PSC_ENABLE);
         RK6748_pinmuxConfig(PINMUX_UART2_REG_0, PINMUX_UART2_MASK_0, PINMUX_UART2_VAL_0);
         RK6748_pinmuxConfig(PINMUX_UART2_REG_1, PINMUX_UART2_MASK_1, PINMUX_UART2_VAL_1);
         break;

      default:
         return (ERR_INIT_FAIL);
   	}

	base=RK6748_uartBase[bySioNum];//通道号3--4，应用接口是3--4

	if(bySioNum>=4)     
		return ERR_FAIL;


	byLCR = 0x03;// 8-Data's Bit-Length  1-Stopping Bit-Length  no-Parity & Parity
	
	/* initialize each channel's driver function pointers */
	divisor = 200000000 / ( dwBaudRate * 16);//24000000 / ( baudrate * 16);

	//divisor = 200000000 / ( g_tSioCtrl[bySioNum].dwBaudRate * 16);
	/* reset the chip */
	UART_REG_WRITE(base,UART_PWREMU_MGMT,0x0000);

	for(i=0;i<10000;i++);
	//设置波特率
	UART_REG_WRITE(base,UART_LCR,byLCR|0x80);
   	UART_REG_WRITE(base,UART_THR,divisor & 0xff);
   	UART_REG_WRITE(base,UART_IER,divisor >> 8); 
	UART_REG_WRITE(base,UART_LCR,byLCR); 
	//配置寄存器，使能fifo，8字节
	UART_REG_WRITE(base,UART_FCR,0x0001);
   	UART_REG_WRITE(base,UART_FCR,0x0006);
   	UART_REG_WRITE(base,UART_IER,0x0000);
	UART_REG_WRITE(base,UART_LCR,byLCR);
	UART_REG_WRITE(base,UART_MCR,0x0000);
	UART_REG_WRITE(base,UART_FCR,0x0089);
	UART_REG_WRITE(base,UART_PWREMU_MGMT,0x6001);
	
	UART_REG_WRITE(base,UART_FCR,0x00cf);
	// 禁止发送和接受中断
//	UART_REG_WRITE(base,UART_IER, 0x00);
	
	// 使能接受中断，禁止发送中断
	UART_REG_WRITE(base,UART_IER, 0x05);

	return (ERR_NO_ERROR);
}

//-----------------------------------------------------------------------------
// helper function to compute the number of bytes in a string.
//-----------------------------------------------------------------------------
static UINT32 getStringLength(char *in_string)
{
   UINT32 numBytes = 0;

   while (in_string[numBytes] != 0)
   {
      numBytes++;
   }

   return numBytes;
}

//串口发送
void RK6748_uartSend(UINT8 bySioNum ,char *pData)//2/从2开始打印口，前置通信口
{
	UINT32  i,base;
	UINT32  status_lsr=0;

	int len=0;

	len=getStringLength(pData);
	 
	base=RK6748_uartBase[bySioNum];	
  	
	//等待发送fifo空
	while((status_lsr & 0x40) != 0x40) 
		UART_REG_READ(base,UART_LSR, status_lsr);

	for(i=0;i<500;i++);//delay 30us
	
	for(i=0;i<len;i++)
	{
		status_lsr=0;
		UART_REG_WRITE(base,UART_THR, *pData++);
		//等待发送fifo空
		while((status_lsr & 0x40) != 0x40) 
			UART_REG_READ(base,UART_LSR, status_lsr);
	}

	//等待发送fifo空
	while((status_lsr & 0x40) != 0x40) 
		UART_REG_READ(base,UART_LSR, status_lsr);
}     


//串口接收
void RK6748_uartRx(UINT8 bySioNum)
{

    UINT32    status_iir,inData, status_lsr,status;
    int	 	  rxdloop = 0; 
	UINT32  base;
		
	base=RK6748_uartBase[bySioNum];	
	
    UART_REG_READ(base,UART_IIR, status_iir); 
	status_iir &=0x0e;
 	if((status_iir == 0x04)|(status_iir == 0x0C)|(status_iir == 0x06)) //rx-int
	{	
		UART_REG_READ(base,UART_LSR, status_lsr);	 
		while((status_lsr & 0x01) == 0x01)
        {
        	UART_REG_READ(base,UART_RBR, inData);	
			LRecvBuf[LBufRecvCounter++]=(char)inData;		
			UART_REG_READ(base,UART_LSR, status_lsr);
			 
			rxdloop++;
			if(rxdloop>=8)
				break; //8字节FIFO，读到8就跳出来，多读会出错
		}
	}

}

