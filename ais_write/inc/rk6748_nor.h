//-----------------------------------------------------------------------------
// \file    rk6748_nor.h
// \brief   C6748 nand defines and function prototypes.
//
//-----------------------------------------------------------------------------

#ifndef EVMC6748_NOR_H
#define EVMC6748_NOR_H

//-----------------------------------------------------------------------------
// Return Error Defines
//-----------------------------------------------------------------------------
#define ERR_NO_ERROR             (0)
#define ERR_FAIL                 (1)
#define ERR_INIT_FAIL            (2)
#define ERR_NO_UI_BOARD          (3)
#define ERR_INVALID_PARAMETER    (4)
#define ERR_TIMEOUT              (5)
#define ERR_UART_RX_FIFO_EMPTY   (6)

//-----------------------------------------------------------------------------
// Public Defines and Macros
//-----------------------------------------------------------------------------
#define NOR_FLASH_BASE              (0x60000000)
#define NOR_FLASH_BLOCK_SIZE_BYTES  (128 * 1024)

//-----------------------------------------------------------------------------
// Public Function Prototypes
//-----------------------------------------------------------------------------

UINT32 NOR_init(void);
UINT32 NOR_read(UINT32 in_addr, UINT16 *dest_buffer, UINT32 in_length);
UINT32 NOR_write(UINT32 in_addr, UINT16 *src_buffer, UINT32 in_length);
UINT32 NOR_eraseBlock(UINT32 in_block_addr);
UINT32 NOR_unlockBlock(UINT32 in_block_addr);

#endif


