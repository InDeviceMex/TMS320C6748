//-----------------------------------------------------------------------------
// \file    rk6748_nor.c
// \brief   implementation of the nor driver for the C6748 EVM.
//
//-----------------------------------------------------------------------------
#include "types.h"
#include "rk6748.h"
#include "rk6748_timer.h"
#include "rk6748_emif.h"
#include "rk6748_nor.h"

#include <stdio.h>
#include <string.h>


#define AIS_SIZE             1500000//1M
#define AIS_DDR_ADDRESS      0xc1000000


#define SECTOR_SIZE             4096    /* Must be 4096 bytes for       */

#define SST_ID                  0xBF    /* SST Manufacturer's ID code   */
#define SST_39VF040             0x236D    /* SST 39VF040 device code      */
#define SST_ADRS				0x60000000


#define FALSE                   0
#define TRUE                    1


/************************************************************************/
/* PROCEDURE:   checkSST39VF040                                         */
/*                                                                      */
/* This procedure  decides whether a  physical hardware device has a    */
/* SST 39VF040 4 Mbit Multi-Purpose Flash installed or not.             */
/*                                                                      */
/* Input:                                                               */
/*          None                                                        */
/*                                                                      */
/* Output:                                                              */
/*          return TRUE:  indicates a SST 39VF040                       */
/*          return FALSE: indicates not a SST 39VF040                   */
/************************************************************************/

UINT32 NOR_init()
{
	UINT16 manID;
	UINT16 devID;
	UINT16 retStatus;
	UINT16 *temp;
	unsigned char printfbuf[100];
	
	/*  Issue the Software Product ID code to 39VF040   */
	temp=((UINT16 *)SST_ADRS+0x0555) ;
	*temp= 0x00AA;
	temp=((UINT16 *)SST_ADRS+0x02aa) ;
	*temp= 0x0055;
	temp=((UINT16 *)SST_ADRS+0x0555) ;
	*temp= 0x0090;
	
	MsDelay(1);				

	/* Read the product ID from 39VF040 */
	manID  = *(0x0000+(UINT16 *)SST_ADRS);
	devID  = *(0x0001+(UINT16 *)SST_ADRS);

	sprintf(printfbuf,"\r\nNOR FLASH:manID=0x%x,devID=0x%x\n",manID,devID);
	DebugPrintf(printfbuf);
	
	if ((manID == SST_ID)&&((devID == SST_39VF040)))
		retStatus = ERR_NO_ERROR;
	else
		retStatus = ERR_FAIL;

	/* Issue the Soffware Product ID Exit code thus returning the 39VF040   */
	/* to the read operating mode                                           */
	*((UINT16 *)SST_ADRS+0x0555) = 0x00AA;
	*((UINT16 *)SST_ADRS+0x02aa) = 0x0055;
	*((UINT16 *)SST_ADRS+0x0555) = 0x00F0;

	MsDelay(1);					

	return (retStatus);
}

//-----------------------------------------------------------------------------
// \brief   read data from nor flash.
//
// \param   .
//
// \return  UINT32
//    ERR_NO_ERROR - everything is ok...data copied to dest buffer.
//-----------------------------------------------------------------------------
UINT32 NOR_read(UINT32 in_addr, UINT16 *dest_buffer, UINT32 in_length)
{
   UINT16 *src;
   UINT32 i;
   UINT32 word_count = (in_length / 2);

   src = (UINT16 *)in_addr;
   for (i = 0; i < word_count; i++)
   {
     *dest_buffer++ = *src++;
   }
   
   return (ERR_NO_ERROR);
}


/************************************************************************/
/* PROCEDURE:   eraseEntireChip                                         */
/*                                                                      */
/* This procedure can be used to erase the entire chip.                 */
/*                                                                      */
/* Input:                                                               */
/*      dst     address which the erase operation will start            */
/*                                                                      */
/* Output:                                                              */
/*      NONE                                                            */
/************************************************************************/

void eraseEntireChip(void)
{
//	unsigned char *temp;

	/*  Issue the Sector Erase command to 39VF040   */

	*((UINT16 *)SST_ADRS+0x0555) = 0x00AA;
	*((UINT16 *)SST_ADRS+0x02AA) = 0x0055;
	*((UINT16 *)SST_ADRS+0x0555) = 0x0080;
	*((UINT16 *)SST_ADRS+0x0555) = 0x00AA;
	*((UINT16 *)SST_ADRS+0x02AA) = 0x0055;
	*((UINT16 *)SST_ADRS+0x0555) = 0x0010;

	MsDelay(1000);				/* delay 1000ms */
}



/************************************************************************/
/* PROCEDURE:   eraseOneSector                                          */
/*                                                                      */
/* This procedure can be used to erase a total of 4096 bytes.           */
/*                                                                      */
/* Input:                                                               */
/*      dst     address which the erase operation will start            */
/*                                                                      */
/* Output:                                                              */
/*      NONE                                                            */
/************************************************************************/

UINT32 NOR_eraseBlock(UINT32 in_block_addr)
{
	UINT16 *temp;

	*((UINT16 *)SST_ADRS+0x0555) = 0x00AA;
	*((UINT16 *)SST_ADRS+0x02AA) = 0x0055;
	*((UINT16 *)SST_ADRS+0x0555) = 0x0080;
	*((UINT16 *)SST_ADRS+0x0555) = 0x00AA;
	*((UINT16 *)SST_ADRS+0x02AA) = 0x0055;
	
	temp  = (UINT16 *)in_block_addr;
	*temp = 0x50;

	MsDelay(25);				/* delay 25ms */
	return (ERR_NO_ERROR);
}


/************************************************************************/
/* PROCEDURE:    checkToggleReady                                       */
/*                                                                      */
/* During the internal program cycle, any consecutive read operation    */
/* on DQ6 will produce alternating 0's and 1's i.e. toggling between    */
/* 0 and 1. When the program cycle is completed, DQ6 of the data will   */
/* stop toggling. After the DQ6 data bit stops toggling, the device is  */
/* ready for next operation.                                            */
/*                                                                      */
/* Input:                                                               */
/*           dst        must already set-up by the caller               */
/*                                                                      */
/* Output:                                                              */
/*           None                                                       */
/************************************************************************/

void checkToggleReady (UINT16 *dst)
{
	UINT16 loop = TRUE;
	UINT16 preData;
	UINT16 currData;
	unsigned long timeOut = 0;

	preData = *dst;
	preData = preData & 0x0040;
	while ((timeOut < 0x07FFFFFF) && (loop))
	{
	    currData = *dst;
	    currData = currData & 0x0040;
	    if (preData == currData)
			loop = FALSE;				/* ready to exit the while loop */
	    preData = currData;
	    timeOut++;
	}
}


/************************************************************************/
/* PROCEDURE:   checkDataPolling                                        */
/*                                                                      */
/* During the internal program cycle, any attempt to read DQ7 of the    */
/* last byte loaded during the page/byte-load cycle will receive the    */
/* complement of the true data.  Once the program cycle is completed,   */
/* DQ7 will show true data.                                             */
/*                                                                      */
/* Input:                                                               */
/*           dst        must already set-up by the caller               */
/*           trueData   Datathis is the original (true) data            */
/*                                                                      */
/* Output:                                                              */
/*           None                                                       */
/************************************************************************/

void checkDataPolling (unsigned char *dst, unsigned char trueData)
{
	unsigned char loop = TRUE;
	unsigned char currData;
	unsigned long timeOut = 0;

	trueData = trueData & 0x80;
	while ((timeOut < 0x07FFFFFF) && (loop))
	{
		currData = *dst;
		currData = currData & 0x80;
		if (trueData == currData)
			loop = FALSE;   /* ready to exit the while loop  */
		timeOut++;
	}
}


void NOR_BlockErase(int firstErasableBlock, int numOfErasableBlocks)
{
	int iBlock;
	unsigned int offset;
	UINT16 *pTemp;
    
	for (iBlock = 0; iBlock < numOfErasableBlocks; iBlock++)
	{
		offset = (firstErasableBlock + iBlock) * (256*256);//0x1000
		pTemp  =(UINT16 *)(SST_ADRS+offset);

		checkToggleReady(pTemp);

		*((UINT16 *)SST_ADRS+0x555) = 0xaa;
		*((UINT16 *)SST_ADRS+0x2aa) = 0x55;
		*((UINT16 *)SST_ADRS+0x555) = 0x80;
		*((UINT16 *)SST_ADRS+0x555) = 0xaa;
		*((UINT16 *)SST_ADRS+0x2aa) = 0x55;

		*pTemp = 0x30;//SECTOR_ERASE
		checkToggleReady(pTemp);
	}
	
}


//-----------------------------------------------------------------------------
// \brief   write data to nor flash.
//
// \param   UINT32 in_addr - start address of flash to be written.
//
// \param   UINT16 *src_buffer - pointer to data to write.
//
// \param   UINT32 in_length - number of bytes to write.
//
// \return  UINT32
//    ERR_NO_ERROR - everything is ok...data written to nor.
//    else - something happened during write.
//-----------------------------------------------------------------------------
UINT32 NOR_write(UINT32 in_addr, UINT16 *src_buffer, UINT32 in_length)
{
   	UINT16 *temp;
	UINT16 *sourceBuf;
	UINT16 *destBuf;
	unsigned int index;
	

	sourceBuf=src_buffer ;
	destBuf = (UINT16 *)in_addr;		

	for (index = 0; index < (in_length/2); index++)//500000-1M BYTE
	{
		*((UINT16 *)SST_ADRS+0x0555) = 0x00AA;
		*((UINT16 *)SST_ADRS+0x02AA) = 0x0055;
		*((UINT16 *)SST_ADRS+0x0555) = 0x00A0;
		temp = destBuf;
		*destBuf = *sourceBuf;
		checkToggleReady(temp);

		if(*destBuf!= *sourceBuf) 
		{
			LED1_OFF();
			return (ERR_FAIL);
		}
		destBuf++ ;
		sourceBuf++;
			
		if((index&0x00001fff)<0x0fff)
			LED2_ON();
		else 	
			LED2_OFF();

	}
   return (ERR_NO_ERROR);
}

void AIS_write(void)
{	
	if(NOR_init()==0)
	{
		LED1_ON();
		MsDelay(500);
		NOR_BlockErase(0,31);		
		MsDelay(500);

		DebugPrintf("\r\n--- write data to nor flash ---\r\n");
		NOR_write(SST_ADRS,(UINT16 *)AIS_DDR_ADDRESS,AIS_SIZE);
	}	
	else
		LED1_OFF();		
}

