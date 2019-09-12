/****************************************************************************/
/*  C6748.cmd                                                               */
/*  Copyright (c) 2010 Texas Instruments Incorporated                       */
/*  Author: Rafael de Souza                                                 */
/*                                                                          */
/*    Description: This file is a sample linker command file that can be    */
/*                 used for linking programs built with the C compiler and  */
/*                 running the resulting .out file on a C6748               */
/*                 device.  Use it as a guideline.  You will want to        */
/*                 change the memory layout to match your specific C6xxx    */
/*                 target system.  You may want to change the allocation    */
/*                 scheme according to the size of your program.            */
/*                                                                          */
/****************************************************************************/
-heap 0x007F0000
MEMORY
{
    DSPL2ROM     o = 0x00700000  l = 0x00100000   /* 1MB L2 Internal ROM */
    DSPL2RAM     o = 0x00800000  l = 0x00040000   /* 256kB L2 Internal RAM */
    DSPL1PRAM    o = 0x00E00000  l = 0x00008000   /* 32kB L1 Internal Program RAM */
    DSPL1DRAM    o = 0x00F00000  l = 0x00008000   /* 32kB L1 Internal Data RAM */

    SHDSPL2ROM   o = 0x11700000  l = 0x00100000   /* 1MB L2 Shared Internal ROM */
    SHDSPL2RAM   o = 0x11800000  l = 0x00040000   /* 256kB L2 Shared Internal RAM */
    SHDSPL1PRAM  o = 0x11E00000  l = 0x00008000   /* 32kB L1 Shared Internal Program RAM */
    SHDSPL1DRAM  o = 0x11F00000  l = 0x00008000   /* 32kB L1 Shared Internal Data RAM */

    EMIFACS0     o = 0x40000000  l = 0x20000000   /* 512MB SDRAM Data (CS0) */
    EMIFACS2     o = 0x60000000  l = 0x02000000   /* 32MB Async Data (CS2) */
    EMIFACS3     o = 0x62000000  l = 0x02000000   /* 32MB Async Data (CS3) */
    EMIFACS4     o = 0x64000000  l = 0x02000000   /* 32MB Async Data (CS4) */
    EMIFACS5     o = 0x66000000  l = 0x02000000   /* 32MB Async Data (CS5) */
    SHRAM        o = 0x80000000  l = 0x00020000   /* 128kB Shared RAM */
    DDR2_CODE    o = 0xC0000000  l = 0x00800000   /* 8MB DDR2 Data */
    DDR2_CONSTANT    o = 0xC0800000  l = 0x00800000   /* 8MB DDR2 Data */
    DDR2_DATA_Stack  o = 0xC1000000  l = 0x00800000   /* 8MB DDR2 Data */
    DDR2_DATA_Heap   o = 0xC1800000  l = 0x00800000   /* 8MB DDR2 Data */
    DDR2_DATA_Cache  o = 0xC2000000  l = 0x02000000   /* 32MB DDR2 Data */
    DDR2_DATA_CacheBuffer  o = 0xC4000000  l = 0x02000000   /* 32MB DDR2 Data */
    DDR2_DATA_NCache o = 0xC6000000  l = 0x02000000   /* 32MB DDR2 Data */
}

SECTIONS                                       
{
    /* EABI sections */
	.text:_c_int00 >  0xC0000000 //0x00800000//0xc2000000
    .text          >  DDR2_CODE
    .switch        >  DDR2_CODE
    .const         >  DDR2_CONSTANT
    .cinit         >  DDR2_CONSTANT
    .binit         >  DDR2_CONSTANT
    .init_array    >  DDR2_CODE
    .c6xabi.exidx  >  DDR2_CODE
    .c6xabi.extab  >  DDR2_CODE

    .neardata      >  DDR2_DATA_Cache
    .rodata        >  DDR2_CONSTANT
    .bss           >  DDR2_DATA_Cache

    .fardata       >  DDR2_DATA_Cache
    .far           >  DDR2_DATA_Cache
    .stack         >  DDR2_DATA_Stack
    .sysmem        >  DDR2_DATA_Heap


    .cio           >  DDR2_CODE
    .args          >  DDR2_CODE
    .ppinfo        >  DDR2_CODE
    .ppdata        >  DDR2_CODE
	.vecs		   >  DDR2_CODE				/* Interrupt Vectors				*/
  
    /* COFF sections */
    //.pinit         >  SHRAM
    //.data          >  SHRAM
  
    /* USER */
    .MyData >DDR2_DATA_NCache
    .MyBuffer >DDR2_DATA_CacheBuffer



}
