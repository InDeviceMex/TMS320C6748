/*
 * Core.h
 *
 *  Created on: 13/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_CORE_H_
#define INCLUDE_CORE_H_

#include <ti/mathlib/mathlib.h>
#include <math.h>
#include <mathl.h>
#include <mathf.h>
#include <ti/dsplib/dsplib.h>
#include <ti/imglib/imglib.h>
#include <c6x.h>
#include <stdlib.h>

 //   _enable_interrupts();
 //   value=_disable_interrupts();
 //   _restore_interrupts(value);

#define   __I     volatile const       /*!< Defines 'read only' permissions */
#define   __O     volatile             /*!< Defines 'write only' permissions */
#define   __IO    volatile             /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */

#define DSPL2ROM_START  ((uint32_t)0x00700000u)
#define DSPL2RAM_START  ((uint32_t)0x00800000u)
#define DSPL1PRAM_START ((uint32_t)0x00E00000u)
#define DSPL1DRAM_START ((uint32_t)0x00F00000u)
#define DSPL2ROM_LENGHT  ((uint32_t)0x00100000u)   /* 1MB L2 Internal ROM */
#define DSPL2RAM_LENGHT  ((uint32_t)0x00040000u)   /* 256kB L2 Internal RAM */
#define DSPL1PRAM_LENGHT ((uint32_t)0x00008000u)   /* 32kB L1 Internal Program RAM */
#define DSPL1DRAM_LENGHT ((uint32_t)0x00008000u)   /* 32kB L1 Internal Data RAM */


#define SHDSPL2ROM_START  ((uint32_t)0x11700000u)
#define SHDSPL2RAM_START  ((uint32_t)0x11800000u)
#define SHDSPL1PRAM_START ((uint32_t)0x11E00000u)
#define SHDSPL1DRAM_START ((uint32_t)0x11F00000u)
#define SHDSPL2ROM_LENGHT  ((uint32_t)0x00100000u)   /* 1MB L2 Internal ROM */
#define SHDSPL2RAM_LENGHT  ((uint32_t)0x00040000u)   /* 256kB L2 Internal RAM */
#define SHDSPL1PRAM_LENGHT ((uint32_t)0x00008000u)   /* 32kB L1 Internal Program RAM */
#define SHDSPL1DRAM_LENGHT ((uint32_t)0x00008000u)   /* 32kB L1 Internal Data RAM */


#define EMIFACS0_START  ((uint32_t)0x40000000u)
#define EMIFACS2_START  ((uint32_t)0x60000000u)
#define EMIFACS3_START  ((uint32_t)0x62000000u)
#define EMIFACS4_START  ((uint32_t)0x64000000u)
#define EMIFACS5_START  ((uint32_t)0x66000000u)
#define SHRAM_START     ((uint32_t)0x80000000u)
#define DDR2_CODE_START ((uint32_t)0xC0000000u)
#define DDR2_CONSTANT_START   ((uint32_t)0xC0800000u)
#define DDR2_DATA_Stack_START ((uint32_t)0xC1000000u)
#define DDR2_DATA_Heap_START  ((uint32_t)0xC1800000u)
#define DDR2_DATA_Cache_START      ((uint32_t)0xC2000000u)
#define DDR2_DATA_NCache_START      ((uint32_t)0xC6000000u)


#define EMIFACS0_LENGHT  ((uint32_t)0x20000000u)  /* 512MB SDRAM Data (CS0) */
#define EMIFACS2_LENGHT  ((uint32_t)0x02000000u)    /* 32MB Async Data (CS2) */
#define EMIFACS3_LENGHT ((uint32_t)0x02000000u)   /* 32MB Async Data (CS3) */
#define EMIFACS4_LENGHT ((uint32_t)0x02000000u)    /* 32MB Async Data (CS4) */
#define EMIFACS5_LENGHT ((uint32_t)0x02000000u)    /* 32MB Async Data (CS5) */
#define SHRAM_LENGHT    ((uint32_t)0x00020000u)   /* 128kB Shared RAM */
#define DDR2_CODE_LENGHT         ((uint32_t)0x00800000u)  /* 8MB DDR2 Data */
#define DDR2_CONSTANT_LENGHT     ((uint32_t)0x00800000u)  /* 8MB DDR2 Data */
#define DDR2_DATA_Stack_LENGHT   ((uint32_t)0x00800000u) /* 8MB DDR2 Data */
#define DDR2_DATA_Heap_LENGHT    ((uint32_t)0x00800000u) /* 8MB DDR2 Data */
#define DDR2_DATA_Cache_LENGHT   ((uint32_t)0x04000000u)  /* 64MB DDR2 Data */
#define DDR2_DATA_NCache_LENGHT  ((uint32_t)0x02000000u)  /* 32MB DDR2 Data */


#endif /* INCLUDE_CORE_H_ */
