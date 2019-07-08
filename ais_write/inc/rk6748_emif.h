
#ifndef _EMIFA_H
#define _EMIFA_H

//-----------------------------------------------------------------------------
// Register Structure & Defines
//-----------------------------------------------------------------------------
typedef struct
{
   volatile UINT32 REVID;               // 0x0000
   volatile UINT32 AWCC;                // 0x0004
   volatile UINT32 SDCR;                // 0x0008
   volatile UINT32 SDRCR;               // 0x000C
   volatile UINT32 CE2CFG;              // 0x0010
   volatile UINT32 CE3CFG;              // 0x0014
   volatile UINT32 CE4CFG;              // 0x0018
   volatile UINT32 CE5CFG;              // 0x001C
   volatile UINT32 SDTIMR;              // 0x0020
   volatile UINT32 RSVD0[6];            // 0x0024
   volatile UINT32 SDSRETR;             // 0x003C
   volatile UINT32 INTRAW;              // 0x0040
   volatile UINT32 INTMASK;             // 0x0044
   volatile UINT32 INTMASKSET;          // 0x0048
   volatile UINT32 INTMASKCLR;          // 0x004C
   volatile UINT32 RSVD1[4];            // 0x0050
   volatile UINT32 NANDFCR;             // 0x0060
   volatile UINT32 NANDFSR;             // 0x0064
   volatile UINT32 PMCR;                // 0x0068
   volatile UINT32 NANDF1ECC;           // 0x0070
   volatile UINT32 NANDF2ECC;           // 0x0074
   volatile UINT32 NANDF3ECC;           // 0x0078
   volatile UINT32 NANDF4ECC;           // 0x007C
   volatile UINT32 RSVD2[15];           // 0x0080
   volatile UINT32 NAND4BITECCLOAD;     // 0x00BC
   volatile UINT32 NAND4BITECC1;        // 0x00C0
   volatile UINT32 NAND4BITECC2;        // 0x00C4
   volatile UINT32 NAND4BITECC3;        // 0x00C8
   volatile UINT32 NAND4BITECC4;        // 0x00CC
   volatile UINT32 NANDERRADDR1;        // 0x00D0
   volatile UINT32 NANDERRADDR2;        // 0x00D4
   volatile UINT32 NANDERRVAL1;         // 0x00D8
   volatile UINT32 NANDERRVAL2;         // 0x00DC
} emifa_regs_t;

#define EMIFA        ((emifa_regs_t *)EMIFA_REG_BASE)

#define EMIFA_CS2_BASE     (0x60000000) 
#define EMIFA_CS3_BASE     (0x62000000)

#define ASIZE              (0x00000001)   // bits 0-1
#define ASIZE_MASK         (0x00000003)

#define TA_MASK            (0x0000000C)
#define R_HOLD_MASK        (0x00000070)
#define R_STROBE_MASK      (0x00001F80)
#define R_SETUP_MASK       (0x0001E000)
#define W_HOLD_MASK        (0x000E0000)
#define W_STROBE_MASK      (0x03F00000)
#define W_SETUP_MASK       (0x3C000000)
#define EW_MASK       	   (0x40000000)
#define SS_MASK       	   (0x80000000)

#define TA_OFFSET          (2)
#define R_HOLD_OFFSET        (4)
#define R_STROBE_OFFSET      (7)
#define R_SETUP_OFFSET      (13)
#define W_HOLD_OFFSET      (17)
#define W_STROBE_OFFSET      (20)
#define W_SETUP_OFFSET       (26)
#define EW_OFFSET       (30)
#define SS_OFFSET       (31)

#define MAX_EXT_WAIT_MASK       	   (0x000000FF)
#define MAX_EXT_WAIT_OFFSET                (0)

#define setReg(addr,mask,value,offset) (addr &= ~(mask));(addr += value << offset)	


UINT32 EmifaRead(UINT32 in_addrbase,UINT32 in_addr, UINT16 *dest_buffer, UINT32 in_length);
UINT32 EmifaWrite(UINT32 in_addrbase,UINT32 in_addr, UINT16 *src_buffer, UINT32 in_length);

void EMIFA_init(void);

#endif

