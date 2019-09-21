/*
 * LCDC.h
 *
 *  Created on: 20/07/2019
 *      Author: Lalo
 */

#ifndef DSP_INCLUDE_LCDC_H_
#define DSP_INCLUDE_LCDC_H_

#include "Core.h"
#include "Font.h"
#include "SYSCFG.h"
#include "CACHE.h"
#include "EDMA3.h"
#include "DDR2.h"
#include "SysTick.h"
#include "Cache.h"
#include "Colors.h"
#include "CONV.h"
#include <stdarg.h>
#include <stdint.h>

#define LCDC_BASE            ((uint32_t)0x01E13000)

typedef __IO struct
{
    __I uint32_t REV       :32;
}LCDC_REVID_TypeDef;

typedef __IO struct
{
    __IO uint32_t MODESEL    :1;
         uint32_t reserved0  :7;
    __IO uint32_t CLKDIV     :8;
         uint32_t reserved1  :16;
}LCDC_LCD_CTRL_TypeDef;

typedef __IO struct
{
    __IO uint32_t DONE      :1;
         uint32_t reserved0 :1;
    __IO uint32_t SYNC      :1;
    __IO uint32_t ABC       :1;
         uint32_t reserved1 :1;
    __IO uint32_t FUF       :1;
    __IO uint32_t PL        :1;
         uint32_t reserved2 :1;
    __IO uint32_t EOF0      :1;
    __IO uint32_t EOF1      :1;
         uint32_t reserved3 :22;
}LCDC_LCD_STAT_TypeDef;

typedef __IO struct
{
    __IO uint32_t LIDD_MODE_SEL  :3;
    __IO uint32_t RSPOL          :1;
    __IO uint32_t RS_EN_POL      :1;
    __IO uint32_t WS_DIR_POL     :1;
    __IO uint32_t CS0_E0_POL     :1;
    __IO uint32_t CS1_E1_POL     :1;
    __IO uint32_t LIDD_DMA_EN    :1;
    __IO uint32_t DMA_CS0_CS1    :1;
    __IO uint32_t DONE_INT_EN    :1;
         uint32_t reserved0      :21;
}LCDC_LIDD_CTRL_TypeDef;

typedef __IO struct
{
    __IO uint32_t TA            :2;
    __IO uint32_t R_HOLD        :4;
    __IO uint32_t R_STROBE      :6;
    __IO uint32_t R_SU          :5;
    __IO uint32_t W_HOLD        :4;
    __IO uint32_t W_STROBE      :6;
    __IO uint32_t W_SU          :5;
}LCDC_LIDD_CSn_CONF_TypeDef;

typedef __IO struct
{
    __IO uint32_t ADDR            :16;
         uint32_t reserved0       :16;
}LCDC_LIDD_CSn_ADDR_TypeDef;

typedef __IO struct
{
    __IO uint32_t DATA            :16;
         uint32_t reserved0       :16;
}LCDC_LIDD_CSn_DATA_TypeDef;

typedef __IO struct
{
    __IO uint32_t RASTER_EN  :1;
    __IO uint32_t MONO_COLOR :1;
    __IO uint32_t AC_EN      :1;
    __IO uint32_t DONE_EN    :1;
    __IO uint32_t PL_EN      :1;
    __IO uint32_t SL_EN      :1;
    __IO uint32_t FUF_EN     :1;
    __IO uint32_t TFT_STN    :1;
    __IO uint32_t RD_ORDER   :1;
    __IO uint32_t MONO8B     :1;
         uint32_t reserved0  :2;
    __IO uint32_t FIFO_DMA_DELAY   :8;
    __IO uint32_t PLM        :2;
    __IO uint32_t NIB_MODE   :1;
    __IO uint32_t TFT_ALT_MAP:1;
    __IO uint32_t STN_565    :1;
         uint32_t reserved1  :7;
}LCDC_RASTER_CTRL_TypeDef;

typedef __IO struct
{
         uint32_t reserved0  :4;
    __IO uint32_t PPL        :6;
    __IO uint32_t HSW        :6;
    __IO uint32_t HFP        :8;
    __IO uint32_t HBP        :8;
}LCDC_RASTER_TIMING_0_TypeDef;

typedef __IO struct
{
    __IO uint32_t LPP        :10;
    __IO uint32_t VSW        :6;
    __IO uint32_t VFP        :8;
    __IO uint32_t VBP        :8;
}LCDC_RASTER_TIMING_1_TypeDef;

typedef __IO struct
{
         uint32_t reserved0  :8;
    __IO uint32_t ACB        :8;
    __IO uint32_t ACB_I      :4;
    __IO uint32_t IVS        :1;
    __IO uint32_t IHS        :1;
    __IO uint32_t IPC        :1;
    __IO uint32_t BIAS       :1;
    __IO uint32_t SYNC_EDGE  :1;
    __IO uint32_t SYNC_CTRL  :1;
         uint32_t reserved1  :6;
}LCDC_RASTER_TIMING_2_TypeDef;

typedef __IO struct
{
         uint32_t reserved0  :4;
    __IO uint32_t DPD        :12;
    __IO uint32_t LPPT       :10;
         uint32_t reserved1  :3;
    __IO uint32_t HOLS       :1;
         uint32_t reserved2  :1;
    __IO uint32_t SPEN       :1;
}LCDC_RASTER_SUBPANEL_TypeDef;

typedef __IO struct
{
    __IO uint32_t FRAME_MODE :1;
    __IO uint32_t BIGENDIAN  :1;
    __IO uint32_t EOF_INTEN  :1;
         uint32_t reserved0  :1;
    __IO uint32_t BURST_SIZE :3;
         uint32_t reserved1  :1;
    __IO uint32_t TH_FIFO_READY:3;
         uint32_t reserved2  :21;
}LCDC_LCDDMA_CTRL_TypeDef;

typedef __IO struct
{
    __IO uint32_t BASE            :32;
}LCDC_LCDDMA_FBn_BASE_TypeDef;

typedef __IO struct
{
    __IO uint32_t CEIL            :32;
}LCDC_LCDDMA_FBn_CEILING_TypeDef;



typedef struct  {
    union
    {
        __IO uint32_t           REVID;
        LCDC_REVID_TypeDef      REVID_Bit;
    };
    union
    {
        __IO uint32_t           LCD_CTRL;
        LCDC_LCD_CTRL_TypeDef   LCD_CTRL_Bit;
    };
    union
    {
        __IO uint32_t           LCD_STAT;
        LCDC_LCD_STAT_TypeDef   LCD_STAT_Bit;
    };
    union
    {
        __IO uint32_t               LIDD_CTRL;
        LCDC_LIDD_CTRL_TypeDef      LIDD_CTRL_Bit;
    };
    union
    {
        __IO uint32_t               LIDD_CS0_CONF;
        LCDC_LIDD_CSn_CONF_TypeDef  LIDD_CS0_CONF_Bit;
    };
    union
    {
        __IO uint32_t               LIDD_CS0_ADDR;
        LCDC_LIDD_CSn_ADDR_TypeDef  LIDD_CS0_ADDR_Bit;
    };
    union
    {
        __IO uint32_t               LIDD_CS0_DATA;
        LCDC_LIDD_CSn_DATA_TypeDef  LIDD_CS0_DATA_Bit;
    };
    union
    {
        __IO uint32_t               LIDD_CS1_CONF;
        LCDC_LIDD_CSn_CONF_TypeDef  LIDD_CS1_CONF_Bit;
    };
    union
    {
        __IO uint32_t               LIDD_CS1_ADDR;
        LCDC_LIDD_CSn_ADDR_TypeDef  LIDD_CS1_ADDR_Bit;
    };
    union
    {
        __IO uint32_t               LIDD_CS1_DATA;
        LCDC_LIDD_CSn_DATA_TypeDef  LIDD_CS1_DATA_Bit;
    };
    union
    {
        __IO uint32_t               RASTER_CTRL;
        LCDC_RASTER_CTRL_TypeDef  RASTER_CTRL_Bit;
    };
    union
    {
        __IO uint32_t               RASTER_TIMING_0;
        LCDC_RASTER_TIMING_0_TypeDef  RASTER_TIMING_0_Bit;
    };
    union
    {
        __IO uint32_t               RASTER_TIMING_1;
        LCDC_RASTER_TIMING_1_TypeDef  RASTER_TIMING_1_Bit;
    };
    union
    {
        __IO uint32_t               RASTER_TIMING_2;
        LCDC_RASTER_TIMING_2_TypeDef  RASTER_TIMING_2_Bit;
    };
    union
    {
        __IO uint32_t               RASTER_SUBPANEL;
        LCDC_RASTER_SUBPANEL_TypeDef  RASTER_SUBPANEL_Bit;
    };
    uint32_t reserved0;
    union
    {
        __IO uint32_t               LCDDMA_CTRL;
        LCDC_LCDDMA_CTRL_TypeDef    LCDDMA_CTRL_Bit;
    };
    union
    {
        __IO uint32_t               LCDDMA_FB0_BASE;
        LCDC_LCDDMA_FBn_BASE_TypeDef    LCDDMA_FB0_BASE_Bit;
    };
    union
    {
        __IO uint32_t               LCDDMA_FB0_CEILING;
        LCDC_LCDDMA_FBn_CEILING_TypeDef LCDDMA_FB0_CEILING_Bit;
    };
    union
    {
        __IO uint32_t               LCDDMA_FB1_BASE;
        LCDC_LCDDMA_FBn_BASE_TypeDef    LCDDMA_FB1_BASE_Bit;
    };
    union
    {
        __IO uint32_t               LCDDMA_FB1_CEILING;
        LCDC_LCDDMA_FBn_CEILING_TypeDef LCDDMA_FB1_CEILING_Bit;
    };
} LCDC_TypeDef;

#define LCDC            (((LCDC_TypeDef*)(LCDC_BASE)))
#define LCDC_R(offset)  (*((__IO uint32_t *)(LCDC_BASE+offset)))

#define LCDC_REVID_OFFSET           ((uint32_t)0x0000)
#define LCDC_LCD_CTRL_OFFSET        ((uint32_t)0x0004)
#define LCDC_LCD_STAT_OFFSET        ((uint32_t)0x0008)
#define LCDC_LIDD_CTRL_OFFSET       ((uint32_t)0x000C)
#define LCDC_LIDD_CS0_CONF_OFFSET   ((uint32_t)0x0010)
#define LCDC_LIDD_CS0_ADDR_OFFSET   ((uint32_t)0x0014)
#define LCDC_LIDD_CS0_DATA_OFFSET   ((uint32_t)0x0018)
#define LCDC_LIDD_CS1_CONF_OFFSET   ((uint32_t)0x001C)
#define LCDC_LIDD_CS1_ADDR_OFFSET   ((uint32_t)0x0020)
#define LCDC_LIDD_CS1_DATA_OFFSET   ((uint32_t)0x0024)
#define LCDC_RASTER_CTRL_OFFSET     ((uint32_t)0x0028)
#define LCDC_RASTER_TIMING_0_OFFSET     ((uint32_t)0x002C)
#define LCDC_RASTER_TIMING_1_OFFSET     ((uint32_t)0x0030)
#define LCDC_RASTER_TIMING_2_OFFSET     ((uint32_t)0x0034)
#define LCDC_RASTER_SUBPANEL_OFFSET     ((uint32_t)0x0038)
#define LCDC_LCDDMA_CTRL_OFFSET     ((uint32_t)0x0040)
#define LCDC_LCDDMA_FB0_BASE_OFFSET     ((uint32_t)0x0044)
#define LCDC_LCDDMA_FB0_CEILING_OFFSET  ((uint32_t)0x0048)
#define LCDC_LCDDMA_FB1_BASE_OFFSET     ((uint32_t)0x004C)
#define LCDC_LCDDMA_FB1_CEILING_OFFSET  ((uint32_t)0x0050)

/**********************************************************************************************
************************************** 1 REVID ***********************************************
**********************************************************************************************/
#define LCDC_REVID                    (((LCDC_REVID_TypeDef*)(LCDC_BASE+LCDC_REVID_OFFSET )))
#define LCDC_REVID_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_REVID_OFFSET)))

/*--------*/
#define LCDC_REVID_R_REV_MASK        ((uint32_t)0xFFFFFFFF)
#define LCDC_REVID_R_REV_SHIFT         (0)

#define LCDC_REVID_REV_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 2 LCD_CTRL ***********************************************
**********************************************************************************************/
#define LCDC_LCD_CTRL                    (((LCDC_LCD_CTRL_TypeDef*)(LCDC_BASE+LCDC_LCD_CTRL_OFFSET )))
#define LCDC_LCD_CTRL_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LCD_CTRL_OFFSET)))

/*--------*/
#define LCDC_LCD_CTRL_R_MODESEL_MASK        ((uint32_t)0x00000001u)
#define LCDC_LCD_CTRL_R_MODESEL_SHIFT         (0)

#define LCDC_LCD_CTRL_MODESEL_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LCD_CTRL_R_CLKDIV_MASK        ((uint32_t)0x0000FF00u)
#define LCDC_LCD_CTRL_R_CLKDIV_SHIFT         (8)

#define LCDC_LCD_CTRL_CLKDIV_MASK          ((uint32_t)0x000000FFu)
/*--------*/


/**********************************************************************************************
************************************** 3 LCD_STAT ***********************************************
**********************************************************************************************/
#define LCDC_LCD_STAT                    (((LCDC_LCD_STAT_TypeDef*)(LCDC_BASE+LCDC_LCD_STAT_OFFSET )))
#define LCDC_LCD_STAT_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LCD_STAT_OFFSET)))

/*--------*/
#define LCDC_LCD_STAT_R_DONE_MASK        ((uint32_t)0x00000001u)
#define LCDC_LCD_STAT_R_DONE_SHIFT         (0)

#define LCDC_LCD_STAT_DONE_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LCD_STAT_R_SYNC_MASK        ((uint32_t)0x00000004u)
#define LCDC_LCD_STAT_R_SYNC_SHIFT         (2)

#define LCDC_LCD_STAT_SYNC_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LCD_STAT_R_ABC_MASK        ((uint32_t)0x00000008u)
#define LCDC_LCD_STAT_R_ABC_SHIFT         (3)

#define LCDC_LCD_STAT_ABC_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LCD_STAT_R_FUF_MASK        ((uint32_t)0x00000020u)
#define LCDC_LCD_STAT_R_FUF_SHIFT         (5)

#define LCDC_LCD_STAT_FUF_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LCD_STAT_R_PL_MASK        ((uint32_t)0x00000040u)
#define LCDC_LCD_STAT_R_PL_SHIFT         (6)

#define LCDC_LCD_STAT_PL_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LCD_STAT_R_EOF0_MASK        ((uint32_t)0x00000100u)
#define LCDC_LCD_STAT_R_EOF0_SHIFT         (8)

#define LCDC_LCD_STAT_EOF0_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LCD_STAT_R_EOF1_MASK        ((uint32_t)0x00000200u)
#define LCDC_LCD_STAT_R_EOF1_SHIFT         (9)

#define LCDC_LCD_STAT_EOF1_MASK          ((uint32_t)0x00000001u)
/*--------*/

/**********************************************************************************************
************************************** 4 LIDD_CTRL ***********************************************
**********************************************************************************************/
#define LCDC_LIDD_CTRL                    (((LCDC_LIDD_CTRL_TypeDef*)(LCDC_BASE+LCDC_LIDD_CTRL_OFFSET )))
#define LCDC_LIDD_CTRL_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LIDD_CTRL_OFFSET)))

/*--------*/
#define LCDC_LIDD_CTRL_R_LIDD_MODE_SEL_MASK        ((uint32_t)0x00000007u)
#define LCDC_LIDD_CTRL_R_LIDD_MODE_SEL_SHIFT         (0)

#define LCDC_LIDD_CTRL_LIDD_MODE_SEL_MASK          ((uint32_t)0x00000007u)
/*--------*/

/*--------*/
#define LCDC_LIDD_CTRL_R_RSPOL_MASK        ((uint32_t)0x00000008u)
#define LCDC_LIDD_CTRL_R_RSPOL_SHIFT         (3)

#define LCDC_LIDD_CTRL_RSPOL_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LIDD_CTRL_R_RS_EN_POL_MASK        ((uint32_t)0x00000010u)
#define LCDC_LIDD_CTRL_R_RS_EN_POL_SHIFT         (4)

#define LCDC_LIDD_CTRL_RS_EN_POL_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LIDD_CTRL_R_WS_DIR_POL_MASK        ((uint32_t)0x00000020u)
#define LCDC_LIDD_CTRL_R_WS_DIR_POL_SHIFT         (5)

#define LCDC_LIDD_CTRL_WS_DIR_POL_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LIDD_CTRL_R_CS0_E0_POL_MASK        ((uint32_t)0x00000040u)
#define LCDC_LIDD_CTRL_R_CS0_E0_POL_SHIFT         (6)

#define LCDC_LIDD_CTRL_CS0_E0_POL_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LIDD_CTRL_R_CS1_E1_POL_MASK        ((uint32_t)0x00000080u)
#define LCDC_LIDD_CTRL_R_CS1_E1_POL_SHIFT         (7)

#define LCDC_LIDD_CTRL_CS1_E1_POL_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LIDD_CTRL_R_LIDD_DMA_EN_MASK        ((uint32_t)0x00000100u)
#define LCDC_LIDD_CTRL_R_LIDD_DMA_EN_SHIFT         (8)

#define LCDC_LIDD_CTRL_LIDD_DMA_EN_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LIDD_CTRL_R_DMA_CS0_CS1_MASK        ((uint32_t)0x00000200u)
#define LCDC_LIDD_CTRL_R_DMA_CS0_CS1_SHIFT         (9)

#define LCDC_LIDD_CTRL_DMA_CS0_CS1_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LIDD_CTRL_R_DONE_INT_EN_MASK        ((uint32_t)0x00000400u)
#define LCDC_LIDD_CTRL_R_DONE_INT_EN_SHIFT         (10)

#define LCDC_LIDD_CTRL_DONE_INT_EN_MASK          ((uint32_t)0x00000001u)
/*--------*/

/**********************************************************************************************
************************************** 5 LIDD_CSn_CONF ***********************************************
**********************************************************************************************/
#define LCDC_LIDD_CS0_CONF                    (((LCDC_LIDD_CSn_CONF_TypeDef*)(LCDC_BASE+LCDC_LIDD_CS0_CONF_OFFSET )))
#define LCDC_LIDD_CS0_CONF_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LIDD_CS0_CONF_OFFSET)))
#define LCDC_LIDD_CS1_CONF                    (((LCDC_LIDD_CSn_CONF_TypeDef*)(LCDC_BASE+LCDC_LIDD_CS1_CONF_OFFSET )))
#define LCDC_LIDD_CS1_CONF_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LIDD_CS1_CONF_OFFSET)))

/*--------*/
#define LCDC_LIDD_CSn_CONF_R_TA_MASK        ((uint32_t)0x00000003u)
#define LCDC_LIDD_CSn_CONF_R_TA_SHIFT         (0)

#define LCDC_LIDD_CSn_CONF_TA_MASK          ((uint32_t)0x00000003u)
/*--------*/

/*--------*/
#define LCDC_LIDD_CSn_CONF_R_R_HOLD_MASK        ((uint32_t)0x0000003Cu)
#define LCDC_LIDD_CSn_CONF_R_R_HOLD_SHIFT         (2)

#define LCDC_LIDD_CSn_CONF_R_HOLD_MASK          ((uint32_t)0x0000000Fu)
/*--------*/

/*--------*/
#define LCDC_LIDD_CSn_CONF_R_R_STROBE_MASK        ((uint32_t)0x00000FC0u)
#define LCDC_LIDD_CSn_CONF_R_R_STROBE_SHIFT         (6)

#define LCDC_LIDD_CSn_CONF_R_STROBE_MASK          ((uint32_t)0x0000003Fu)
/*--------*/

/*--------*/
#define LCDC_LIDD_CSn_CONF_R_R_SU_MASK        ((uint32_t)0x0001F000u)
#define LCDC_LIDD_CSn_CONF_R_R_SU_SHIFT         (12)

#define LCDC_LIDD_CSn_CONF_R_SU_MASK          ((uint32_t)0x0000001Fu)
/*--------*/

/*--------*/
#define LCDC_LIDD_CSn_CONF_R_W_HOLD_MASK        ((uint32_t)0x001E0000u)
#define LCDC_LIDD_CSn_CONF_R_W_HOLD_SHIFT         (17)

#define LCDC_LIDD_CSn_CONF_W_HOLD_MASK          ((uint32_t)0x0000000Fu)
/*--------*/

/*--------*/
#define LCDC_LIDD_CSn_CONF_R_W_STROBE_MASK        ((uint32_t)0x07E00000u)
#define LCDC_LIDD_CSn_CONF_R_W_STROBE_SHIFT         (21)

#define LCDC_LIDD_CSn_CONF_W_STROBE_MASK          ((uint32_t)0x0000003Fu)
/*--------*/

/*--------*/
#define LCDC_LIDD_CSn_CONF_R_W_SU_MASK        ((uint32_t)0xF8000000u)
#define LCDC_LIDD_CSn_CONF_R_W_SU_SHIFT         (27)

#define LCDC_LIDD_CSn_CONFW_SU_MASK          ((uint32_t)0x0000001Fu)
/*--------*/


/**********************************************************************************************
************************************** 6 LIDD_CSn_ADDR ***********************************************
**********************************************************************************************/
#define LCDC_LIDD_CS0_ADDR                    (((LCDC_LIDD_CS0_ADDR_TypeDef*)(LCDC_BASE+LCDC_LIDD_CS0_ADDR_OFFSET )))
#define LCDC_LIDD_CS0_ADDR_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LIDD_CS0_ADDR_OFFSET)))
#define LCDC_LIDD_CS1_ADDR                    (((LCDC_LIDD_CS1_ADDR_TypeDef*)(LCDC_BASE+LCDC_LIDD_CS1_ADDR_OFFSET )))
#define LCDC_LIDD_CS1_ADDR_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LIDD_CS1_ADDR_OFFSET)))

/*--------*/
#define LCDC_LIDD_CSn_ADDR_R_ADR_INDX_MASK        ((uint32_t)0x0000FFFFu)
#define LCDC_LIDD_CSn_ADDR_R_ADR_INDX_SHIFT         (0)

#define LCDC_LIDD_CSn_ADDR_ADR_INDX_MASK          ((uint32_t)0x0000FFFFu)
/*--------*/

/**********************************************************************************************
************************************** 7 LIDD_CSn_DATA ***********************************************
**********************************************************************************************/
#define LCDC_LIDD_CS0_DATA                    (((LCDC_LIDD_CS0_DATA_TypeDef*)(LCDC_BASE+LCDC_LIDD_CS0_DATA_OFFSET )))
#define LCDC_LIDD_CS0_DATA_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LIDD_CS0_DATA_OFFSET)))
#define LCDC_LIDD_CS1_DATA                    (((LCDC_LIDD_CS1_DATA_TypeDef*)(LCDC_BASE+LCDC_LIDD_CS1_DATA_OFFSET )))
#define LCDC_LIDD_CS1_DATA_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LIDD_CS1_DATA_OFFSET)))

/*--------*/
#define LCDC_LIDD_CSn_DATA_R_DATA_MASK        ((uint32_t)0x0000FFFFu)
#define LCDC_LIDD_CSn_DATA_R_DATA_SHIFT         (0)

#define LCDC_LIDD_CSn_DATA_DATA_MASK          ((uint32_t)0x0000FFFFu)
/*--------*/

/**********************************************************************************************
************************************** 8 RASTER_CTRL ***********************************************
**********************************************************************************************/
#define LCDC_RASTER_CTRL                    (((LCDC_RASTER_CTRL_TypeDef*)(LCDC_BASE+LCDC_RASTER_CTRL_OFFSET )))
#define LCDC_RASTER_CTRL_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_RASTER_CTRL_OFFSET)))

/*--------*/
#define LCDC_RASTER_CTRL_R_RASTER_EN_MASK        ((uint32_t)0x00000001u)
#define LCDC_RASTER_CTRL_R_RASTER_EN_SHIFT         (0)

#define LCDC_RASTER_CTRL_RASTER_EN_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_MONO_COLOR_MASK        ((uint32_t)0x00000002u)
#define LCDC_RASTER_CTRL_R_MONO_COLOR_SHIFT         (1)

#define LCDC_RASTER_CTRL_MONO_COLOR_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_AC_EN_MASK        ((uint32_t)0x00000004u)
#define LCDC_RASTER_CTRL_R_AC_EN_SHIFT         (2)

#define LCDC_RASTER_CTRL_AC_EN_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_DONE_EN_MASK        ((uint32_t)0x00000008u)
#define LCDC_RASTER_CTRL_R_DONE_EN_SHIFT         (3)

#define LCDC_RASTER_CTRL_DONE_EN_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_PL_EN_MASK        ((uint32_t)0x00000010u)
#define LCDC_RASTER_CTRL_R_PL_EN_SHIFT         (4)

#define LCDC_RASTER_CTRL_PL_EN_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_SL_EN_MASK        ((uint32_t)0x00000020u)
#define LCDC_RASTER_CTRL_R_SL_EN_SHIFT         (5)

#define LCDC_RASTER_CTRL_SL_EN_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_FUF_EN_MASK        ((uint32_t)0x00000040u)
#define LCDC_RASTER_CTRL_R_FUF_EN_SHIFT         (6)

#define LCDC_RASTER_CTRL_FUF_EN_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_TFT_STN_MASK        ((uint32_t)0x00000080u)
#define LCDC_RASTER_CTRL_R_TFT_STN_SHIFT         (7)

#define LCDC_RASTER_CTRL_TFT_STN_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_RD_ORDER_MASK        ((uint32_t)0x00000100u)
#define LCDC_RASTER_CTRL_R_RD_ORDER_SHIFT         (8)

#define LCDC_RASTER_CTRL_RD_ORDER_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_MONO8B_MASK        ((uint32_t)0x00000200u)
#define LCDC_RASTER_CTRL_R_MONO8B_SHIFT         (9)

#define LCDC_RASTER_CTRL_MONO8B_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_FIFO_DMA_DELAY_MASK        ((uint32_t)0x000FF000u)
#define LCDC_RASTER_CTRL_R_FIFO_DMA_DELAY_SHIFT         (12)

#define LCDC_RASTER_CTRL_FIFO_DMA_DELAY_MASK          ((uint32_t)0x000000FFu)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_PLM_MASK        ((uint32_t)0x00300000u)
#define LCDC_RASTER_CTRL_R_PLM_SHIFT         (20)

#define LCDC_RASTER_CTRL_PLM_MASK          ((uint32_t)0x00000003u)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_NIB_MODE_MASK        ((uint32_t)0x00400000u)
#define LCDC_RASTER_CTRL_R_NIB_MODE_SHIFT         (22)

#define LCDC_RASTER_CTRL_NIB_MODE_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_TFT_ALT_MAP_MASK        ((uint32_t)0x00800000u)
#define LCDC_RASTER_CTRL_R_TFT_ALT_MAP_SHIFT         (23)

#define LCDC_RASTER_CTRL_TFT_ALT_MAP_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_CTRL_R_STN_565_MASK        ((uint32_t)0x01000000u)
#define LCDC_RASTER_CTRL_R_STN_565_SHIFT         (24)

#define LCDC_RASTER_CTRL_STN_565_MASK          ((uint32_t)0x00000001u)
/*--------*/

/**********************************************************************************************
************************************** 9 RASTER_TIMING_0 ***********************************************
**********************************************************************************************/
#define LCDC_RASTER_TIMING_0                    (((LCDC_RASTER_TIMING_0_TypeDef*)(LCDC_BASE+LCDC_RASTER_TIMING_0_OFFSET )))
#define LCDC_RASTER_TIMING_0_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_RASTER_TIMING_0_OFFSET)))

/*--------*/
#define LCDC_RASTER_TIMING_0_R_PPL_MASK        ((uint32_t)0x000003F0u)
#define LCDC_RASTER_TIMING_0_R_PPL_SHIFT         (4)

#define LCDC_RASTER_TIMING_0_PPL_MASK          ((uint32_t)0x0000003Fu)
/*--------*/

/*--------*/
#define LCDC_RASTER_TIMING_0_R_HSW_MASK        ((uint32_t)0x0000FC00u)
#define LCDC_RASTER_TIMING_0_R_HSW_SHIFT         (10)

#define LCDC_RASTER_TIMING_0_HSW_MASK          ((uint32_t)0x0000003Fu)
/*--------*/

/*--------*/
#define LCDC_RASTER_TIMING_0_R_HFP_MASK        ((uint32_t)0x00FF0000u)
#define LCDC_RASTER_TIMING_0_R_HFP_SHIFT         (16)

#define LCDC_RASTER_TIMING_0_HFP_MASK          ((uint32_t)0x000000FFu)
/*--------*/

/*--------*/
#define LCDC_RASTER_TIMING_0_R_HBP_MASK        ((uint32_t)0xFF000000u)
#define LCDC_RASTER_TIMING_0_R_HBP_SHIFT         (24)

#define LCDC_RASTER_TIMING_0_HBP_MASK          ((uint32_t)0x000000FFu)
/*--------*/

/**********************************************************************************************
************************************** 10 RASTER_TIMING_1 ***********************************************
**********************************************************************************************/
#define LCDC_RASTER_TIMING_1                    (((LCDC_RASTER_TIMING_1_TypeDef*)(LCDC_BASE+LCDC_RASTER_TIMING_1_OFFSET )))
#define LCDC_RASTER_TIMING_1_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_RASTER_TIMING_1_OFFSET)))

/*--------*/
#define LCDC_RASTER_TIMING_1_R_LPP_MASK        ((uint32_t)0x000003FFu)
#define LCDC_RASTER_TIMING_1_R_LPP_SHIFT         (0)

#define LCDC_RASTER_TIMING_1_LPP_MASK          ((uint32_t)0x000003FFu)
/*--------*/

/*--------*/
#define LCDC_RASTER_TIMING_1_R_VSW_MASK        ((uint32_t)0x0000FC00u)
#define LCDC_RASTER_TIMING_1_R_VSW_SHIFT         (10)

#define LCDC_RASTER_TIMING_1_VSW_MASK          ((uint32_t)0x0000003Fu)
/*--------*/

/*--------*/
#define LCDC_RASTER_TIMING_1_R_VFP_MASK        ((uint32_t)0x00FF0000u)
#define LCDC_RASTER_TIMING_1_R_VFP_SHIFT         (16)

#define LCDC_RASTER_TIMING_1_VFP_MASK          ((uint32_t)0x000000FFu)
/*--------*/

/*--------*/
#define LCDC_RASTER_TIMING_1_R_VBP_MASK        ((uint32_t)0xFF000000u)
#define LCDC_RASTER_TIMING_1_R_VBP_SHIFT         (24)

#define LCDC_RASTER_TIMING_1_VBP_MASK          ((uint32_t)0x000000FFu)
/*--------*/

/**********************************************************************************************
************************************** 11 RASTER_TIMING_2 ***********************************************
**********************************************************************************************/
#define LCDC_RASTER_TIMING_2                    (((LCDC_RASTER_TIMING_2_TypeDef*)(LCDC_BASE+LCDC_RASTER_TIMING_2_OFFSET )))
#define LCDC_RASTER_TIMING_2_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_RASTER_TIMING_2_OFFSET)))

/*--------*/
#define LCDC_RASTER_TIMING_2_R_ACB_MASK        ((uint32_t)0x0000FF00u)
#define LCDC_RASTER_TIMING_2_R_ACB_SHIFT         (8)

#define LCDC_RASTER_TIMING_2_ACB_MASK          ((uint32_t)0x000000FFu)
/*--------*/

/*--------*/
#define LCDC_RASTER_TIMING_2_R_ACB_I_MASK        ((uint32_t)0x000F0000u)
#define LCDC_RASTER_TIMING_2_R_ACB_I_SHIFT         (16)

#define LCDC_RASTER_TIMING_2_ACB_I_MASK          ((uint32_t)0x0000000Fu)
/*--------*/

/*--------*/
#define LCDC_RASTER_TIMING_2_R_IVS_MASK        ((uint32_t)0x00100000u)
#define LCDC_RASTER_TIMING_2_R_IVS_SHIFT         (20)

#define LCDC_RASTER_TIMING_2_IVS_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_TIMING_2_R_IHS_MASK        ((uint32_t)0x00200000u)
#define LCDC_RASTER_TIMING_2_R_IHS_SHIFT         (21)

#define LCDC_RASTER_TIMING_2_IHS_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_TIMING_2_R_IPC_MASK        ((uint32_t)0x00400000u)
#define LCDC_RASTER_TIMING_2_R_IPC_SHIFT         (22)

#define LCDC_RASTER_TIMING_2_IPC_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_TIMING_2_R_BIAS_MASK        ((uint32_t)0x00800000u)
#define LCDC_RASTER_TIMING_2_R_BIAS_SHIFT         (23)

#define LCDC_RASTER_TIMING_2_BIAS_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_TIMING_2_R_SYNC_EDGE_MASK        ((uint32_t)0x01000000u)
#define LCDC_RASTER_TIMING_2_R_SYNC_EDGE_SHIFT         (24)

#define LCDC_RASTER_TIMING_2_SYNC_EDGE_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_TIMING_2_R_SYNC_CTRL_MASK        ((uint32_t)0x02000000u)
#define LCDC_RASTER_TIMING_2_R_SYNC_CTRL_SHIFT         (25)

#define LCDC_RASTER_TIMING_2_SYNC_CTRL_MASK          ((uint32_t)0x00000001u)
/*--------*/

/**********************************************************************************************
************************************** 12 RASTER_SUBPANEL ***********************************************
**********************************************************************************************/
#define LCDC_RASTER_SUBPANEL                    (((LCDC_RASTER_SUBPANEL_TypeDef*)(LCDC_BASE+LCDC_RASTER_SUBPANEL_OFFSET )))
#define LCDC_RASTER_SUBPANEL_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_RASTER_SUBPANEL_OFFSET)))

/*--------*/
#define LCDC_RASTER_SUBPANEL_R_DPD_MASK        ((uint32_t)0x0000FFF0u)
#define LCDC_RASTER_SUBPANEL_R_DPD_SHIFT         (4)

#define LCDC_RASTER_SUBPANEL_DPD_MASK          ((uint32_t)0x00000FFFu)
/*--------*/

/*--------*/
#define LCDC_RASTER_SUBPANEL_R_LPPT_MASK        ((uint32_t)0x03FF0000u)
#define LCDC_RASTER_SUBPANEL_R_LPPT_SHIFT         (16)

#define LCDC_RASTER_SUBPANEL_LPPT_MASK          ((uint32_t)0x000003FFu)
/*--------*/

/*--------*/
#define LCDC_RASTER_SUBPANEL_R_HOLS_MASK        ((uint32_t)0x20000000u)
#define LCDC_RASTER_SUBPANEL_R_HOLS_SHIFT         (29)

#define LCDC_RASTER_SUBPANEL_HOLS_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_RASTER_SUBPANEL_R_SPEN_MASK        ((uint32_t)0x80000000u)
#define LCDC_RASTER_SUBPANEL_R_SPEN_SHIFT         (31)

#define LCDC_RASTER_SUBPANEL_SPEN_MASK          ((uint32_t)0x00000001u)
/*--------*/

/**********************************************************************************************
************************************** 13 LCDDMA_CTRL ***********************************************
**********************************************************************************************/
#define LCDC_LCDDMA_CTRL                    (((LCDC_LCDDMA_CTRL_TypeDef*)(LCDC_BASE+LCDC_LCDDMA_CTRL_OFFSET )))
#define LCDC_LCDDMA_CTRL_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LCDDMA_CTRL_OFFSET)))

/*--------*/
#define LCDC_LCDDMA_CTRL_R_FRAME_MODE_MASK        ((uint32_t)0x00000001u)
#define LCDC_LCDDMA_CTRL_R_FRAME_MODE_SHIFT         (0)

#define LCDC_LCDDMA_CTRL_FRAME_MODE_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LCDDMA_CTRL_R_BIGENDIAN_MASK        ((uint32_t)0x00000002u)
#define LCDC_LCDDMA_CTRL_R_BIGENDIAN_SHIFT         (1)

#define LCDC_LCDDMA_CTRL_BIGENDIAN_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LCDDMA_CTRL_R_EOF_INTEN_MASK        ((uint32_t)0x00000004u)
#define LCDC_LCDDMA_CTRL_R_EOF_INTEN_SHIFT         (2)

#define LCDC_LCDDMA_CTRL_EOF_INTEN_MASK          ((uint32_t)0x00000001u)
/*--------*/

/*--------*/
#define LCDC_LCDDMA_CTRL_R_BURST_SIZE_MASK        ((uint32_t)0x00000070u)
#define LCDC_LCDDMA_CTRL_R_BURST_SIZE_SHIFT         (4)

#define LCDC_LCDDMA_CTRL_BURST_SIZE_MASK          ((uint32_t)0x00000007u)
/*--------*/

/*--------*/
#define LCDC_LCDDMA_CTRL_R_TH_FIFO_READY_MASK        ((uint32_t)0x00000700u)
#define LCDC_LCDDMA_CTRL_R_TH_FIFO_READY_SHIFT         (8)

#define LCDC_LCDDMA_CTRL_TH_FIFO_READY_MASK          ((uint32_t)0x00000007u)
/*--------*/

/**********************************************************************************************
************************************** 14 LCDDMA_FBn_BASE ***********************************************
**********************************************************************************************/
#define LCDC_LCDDMA_FB0_BASE                    (((LCDC_LCDDMA_FB0_BASE_TypeDef*)(LCDC_BASE+LCDC_LCDDMA_FB0_BASE_OFFSET )))
#define LCDC_LCDDMA_FB0_BASE_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LCDDMA_FB0_BASE_OFFSET)))
#define LCDC_LCDDMA_FB1_BASE                    (((LCDC_LCDDMA_FB1_BASE_TypeDef*)(LCDC_BASE+LCDC_LCDDMA_FB1_BASE_OFFSET )))
#define LCDC_LCDDMA_FB1_BASE_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LCDDMA_FB1_BASE_OFFSET)))

/*--------*/
#define LCDC_LCDDMA_FBn_BASE_R_BASE_MASK        ((uint32_t)0xFFFFFFFFu)
#define LCDC_LCDDMA_FBn_BASE_R_BASE_SHIFT         (0)

#define LCDC_LCDDMA_FBn_BASE_BASE_MASK          ((uint32_t)0xFFFFFFFFu)
/*--------*/

/**********************************************************************************************
************************************** 15 LCDDMA_FBn_CEILING ***********************************************
**********************************************************************************************/
#define LCDC_LCDDMA_FB0_CEILING                    (((LCDC_LCDDMA_FB0_CEILING_TypeDef*)(LCDC_BASE+LCDC_LCDDMA_FB0_CEILING_OFFSET )))
#define LCDC_LCDDMA_FB0_CEILING_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LCDDMA_FB0_CEILING_OFFSET)))
#define LCDC_LCDDMA_FB1_CEILING                    (((LCDC_LCDDMA_FB1_CEILING_TypeDef*)(LCDC_BASE+LCDC_LCDDMA_FB1_CEILING_OFFSET )))
#define LCDC_LCDDMA_FB1_CEILING_R                  (*((__IO uint32_t *)(LCDC_BASE+LCDC_LCDDMA_FB1_CEILING_OFFSET)))

/*--------*/
#define LCDC_LCDDMA_FBn_CEILING_R_CEIL_MASK        ((uint32_t)0xFFFFFFFFu)
#define LCDC_LCDDMA_FBn_CEILING_R_CEIL_SHIFT         (0)

#define LCDC_LCDDMA_FBn_CEILING_CEIL_MASK          ((uint32_t)0xFFFFFFFFu)
/*--------*/

#define SUB_LAYER_CANT (100)
#define LCDC_X (640)
#define LCDC_Y (480)



typedef enum
{
    LCDC_enVERTICAL=0,
    LCDC_enHORIZONTAL= 1,
}Lcdc_nDir;

typedef enum
{
    VARIABLETYPE_enUCHAR=0,
    VARIABLETYPE_enUSHORT= 2,
    VARIABLETYPE_enKERNEL= 3,
    VARIABLETYPE_enFLOAT=4,
    VARIABLETYPE_enCOMPLEX=8,
}VARIABLETYPE_nType;

typedef enum
{
    LAYER_TYPE_enIMAGE_NOHEADER             =0,
    LAYER_TYPE_enIMAGE_BMP                  ,
    LAYER_TYPE_enLINECOMPLETE_HORIZONTAL        ,
    LAYER_TYPE_enLINECOMPLETE_VERTICAL      ,
    LAYER_TYPE_enFONTLINE                       ,
    LAYER_TYPE_enFONTLINECOMPLETE               ,
    LAYER_TYPE_enPIXEL                      ,
    LAYER_TYPE_enLINE_VERTICAL              ,
    LAYER_TYPE_enLINE_HORIZONTAL                ,
    LAYER_TYPE_enCROSS                      ,
    LAYER_TYPE_enXMARK                      ,
    LAYER_TYPE_enLINEXY                     ,
    LAYER_TYPE_enRECTANGLE_FILL             ,
    LAYER_TYPE_enRECTANGLE                  ,
    LAYER_TYPE_enRECTANGLE_SEMI                 ,
    LAYER_TYPE_enCIRCLE_FILL                    ,
    LAYER_TYPE_enCIRCLE                     ,
    LAYER_TYPE_enELLIPSE_FILL                   ,
    LAYER_TYPE_enELLIPSE                        ,
    LAYER_TYPE_enTRIANGLE_FILL              ,
    LAYER_TYPE_enTRIANGLE                       ,
    LAYER_TYPE_enMULTILINE_FILL             ,
    LAYER_TYPE_enMULTILINE                  ,
    LAYER_TYPE_enMULTILINECLOSE_FILL                ,
    LAYER_TYPE_enMULTILINECLOSE                 ,
    LAYER_TYPE_enSTRING_SIMPLE_BACKGROUND                   ,
    LAYER_TYPE_enSTRING_SIMPLE                  ,


}LAYER_nType;

typedef enum
{
    DITHER_enDIS    =0,
    DITHER_enEN =1,
}DITHER_nStatus;

typedef enum
{
    BACKLIGHT_enON  =0,
    BACKLIGHT_enOFF =1,
}BACKLIGHT_nStatus;
typedef enum
{
    COLOR_enCOMPLETE_DIS    =0,
    COLOR_enCOMPLETE_EN     =1,
}COLOR_nComplete;
typedef enum
{
    COLOR_enMODE_ARGB8888   =0,
    COLOR_enMODE_RGB888 =1,
    COLOR_enMODE_RGB565 =2,
}COLOR_nMode;

typedef enum
{
    LCDC_ALPHA_MODE_enNOMOD    =0,
    LCDC_ALPHA_MODE_enCONSTANT =1,
    LCDC_ALPHA_MODE_enMULTI    =2,
}Lcdc_nAlphaMode;



typedef enum
{
    LCDC_enLAYERBG=0,
    LCDC_enLAYERFG=1,
    LCDC_enLAYERAUX=2,
}Lcdc_nLayerNumber;

typedef enum
{
    LCDC_enNone=0,
    LCDC_en4_3_480x272,
    LCDC_en7_0_800x480,
    LCDC_en7_0_1024x600,
    LCDC_en7_0_1280x800,
    LCDC_en8_0_1024x600,
    LCDC_en10_1_1280x800,
}Lcdc_nTypeTFT;


typedef enum
{
    LCDC_enOK=0,
    LCDC_enERROR=1,
}Lcdc_nStatus;

typedef enum
{
    LCDC_REFRESH_enDONE=0,
    LCDC_REFRESH_enPENDING=1,
}LCDC_nRefresh;

typedef enum
{
    LCDC_enARGB8888=0,
    LCDC_enRGB888 ,
    LCDC_enRGB565 ,
    LCDC_enARGB1555 ,
    LCDC_enARGB4444 ,
    LCDC_enL8 ,
    LCDC_enAL44 ,
    LCDC_enAL88 ,
}Lcdc_nPixelFormat;


typedef enum
{
    LCDC_MODE_enLIDD = 0x00000000u,
    LCDC_MODE_enRASTER = 0x00000001u,
}Lcdc_nMode;



typedef struct
{
    uint16_t Palette[16];
    uint16_t Data[LCDC_Y][LCDC_X];
}LCDC_Frame_TypeDef;
typedef struct LCDC_TFT_TypeDef LCDC_TFT_TypeDef;
struct LCDC_TFT_TypeDef
{
    LCDC_TypeDef *layerTFT; //solo utilizado en BackGround y Foreground

    uint32_t layerHeaderAddress; //direccion de memoria inicial de la layer
    uint32_t layerDataAddress; //direccion de memoria inicial de la layer
    uint32_t layerCLUTAddress; //direccion de memoria inicial de la layer


    uint32_t layerDataHue; //direccion de memoria inicial de la layer
    uint32_t layerDataSaturation; //direccion de memoria inicial de la layer
    uint32_t layerDataIntensity; //direccion de memoria inicial de la layer

    //uint32_t layerAlphaMode;      //modo de alpha, sin cambio, cambio por contante, constante x pixel alpha ,utilizado solamente en conversiones hacia ARGB
    //uint32_t layerAlphaConstant;  //valor de alpha que se sustituira cuando el modo sea constant
    //uint32_t layerColorMode;      //modo del color RGB565, RGB888, ARGB8888
    uint16_t layerColorBG;
    uint16_t layerColorFont; //color para el BG color de la layer
    FONT_TypeDef* layerFont; //tamaño de la fuente de la layer
    char* layerString; //tamaño de la fuente de la layer

    uint16_t layerWidthTotal;  //ancho de la layer
    uint16_t layerHeightTotal; //altura de la layer
    uint16_t layerWidth;  //ancho de la layer
    uint16_t layerHeight; //altura de la layer

    uint8_t  layerBGXCount;
    uint8_t  layerBGYCount;
    uint8_t  layerXCount;
    uint8_t  layerYCount;
    uint16_t  layerBGXInit;
    uint16_t* layerBGX;    //posicion X inciial de la layer
    uint16_t  layerBGYInit;
    uint16_t* layerBGY;   //posicion X inciial de la layer

    uint16_t  layerXInit;
    uint16_t* layerX;    //posicion X inciial de la layer
    uint16_t  layerYInit;
    uint16_t* layerY;   //posicion X inciial de la layer
    uint16_t  layerRadiusInit;
    uint16_t* layerRadius;   //posicion X inciial de la layer

    uint8_t  layerRadiusCount;
    uint8_t subLayerNum;
    uint8_t subLayersCreated;
    uint8_t subLayersMaximum;

    LCDC_TFT_TypeDef* layerBG;
    LCDC_TFT_TypeDef** subLayers;
    LAYER_nType layerType;
    VARIABLETYPE_nType variableType;
} ;

typedef __IO struct
{
    uint32_t pwidth;
    uint32_t pheight;
    uint16_t hsw;
    uint16_t vsw;
    uint16_t hbp;
    uint16_t vbp;
    uint16_t hfp;
    uint16_t vfp;
    uint32_t pixsize;
    uint16_t activelayer;
    uint16_t dir;
    uint16_t width;
    uint16_t height;
}LCDC_CONFIGURATION_TypeDef;



typedef struct
{

    //uint32_t colorModeOriginal;
    //uint32_t colorModeReplace;
    uint16_t color;
    //uint32_t colorOriginal;
    //uint32_t colorReplace;
    uint16_t colorComplete;
    //uint32_t dither;
    //uint32_t AlphaMode;
    //uint32_t AlphaConstant;
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    //uint32_t Alpha;
}LCDC_COLOR_TypeDef;


typedef __IO struct
{
    uint16_t XInit          ;
    uint16_t YInit;
    uint16_t X[4]       ;
    uint16_t Y[4]       ;
    uint16_t radius[3]      ;
    uint16_t radiusInit;
    uint16_t width          ;
    uint16_t height         ;
    uint16_t widthTotal         ;
    uint16_t heightTotal        ;
}LCDC_DIMENSIONS_TypeDef;


typedef struct {
    uint32_t area;
    uint16_t Xmin;
    uint16_t Ymin;
    uint16_t Xmax;
    uint16_t Ymax;
}LCDC_AREA_TypeDef;

typedef __IO struct
{
    uint32_t X          ;
    uint32_t Y          ;
}LCDC_COORD_TypeDef;



#pragma FUNC_ALWAYS_INLINE( TIMER__vEnable)

uint8_t Lcd_bmp(uint16_t* addrBmp, uint32_t x,uint32_t y,uint32_t x_len,uint32_t y_len);
void Lcd_SetPixel(uint8_t *vaddr,uint16_t x,uint16_t y,uint16_t color);

void SetColor(uint16_t color);

void LCDC__vInit(void);
void LCDC__vInitQDMA(void);
void LCDC__vBackLight(BACKLIGHT_nStatus enState);
void LCDC__vRefresh(void);
LCDC_TFT_TypeDef*   LCDC__sLayerBG_GetPointer(void);
LCDC_TFT_TypeDef*   LCDC__sLayerBG_SetPointer(LCDC_TFT_TypeDef* restrict   psLayer);

uint16_t LCDC__u16SetColorRed_FormatRGB565      (LCDC_COLOR_TypeDef* sColor);
uint16_t LCDC__u16SetColorGreen_FormatRGB565    (LCDC_COLOR_TypeDef* sColor);
uint16_t LCDC__u16SetColorBlue_FormatRGB565     (LCDC_COLOR_TypeDef* sColor);
uint8_t LCDC__u8GetColorRed_FormatRGB565      (LCDC_COLOR_TypeDef* sColor);
uint8_t LCDC__u8GetColorGreen_FormatRGB565    (LCDC_COLOR_TypeDef* sColor);
uint8_t LCDC__u8GetColorBlue_FormatRGB565     (LCDC_COLOR_TypeDef* sColor);

Lcdc_nStatus LCDC__enSetColorSplit_FormatRGB565  (LCDC_COLOR_TypeDef* sColor);
uint16_t LCDC__enGetColorSplit_FormatRGB565     (LCDC_COLOR_TypeDef* sColor);

uint32_t LCDC__u32Layer_GetDataAddress          (LCDC_TFT_TypeDef* restrict   sLayer);
uint32_t LCDC__u32LayerBG_GetDataAddress        (void);
uint32_t LCDC__u32Layer_SetDataAddress          (LCDC_TFT_TypeDef* restrict   pslayer, uint32_t u32Address);
uint32_t LCDC__u32LayerBG_SetDataAddress   (uint32_t u32Address);

uint32_t LCDC__u32Layer_GetHeaderAddress        (LCDC_TFT_TypeDef* restrict   sLayer);
uint32_t LCDC__u32LayerBG_GetHeaderAddress      (void);
uint32_t LCDC__u32Layer_SetHeaderAddress        (LCDC_TFT_TypeDef* restrict   pslayer, uint32_t u32Address);
uint32_t LCDC__u32LayerBG_SetHeaderAddress      (uint32_t u32Address);

uint32_t LCDC__u32Layer_GetCLUTAddress          (LCDC_TFT_TypeDef* restrict   sLayer);
uint32_t LCDC__u32LayerBG_GetCLUTAddress        (void);
uint32_t LCDC__u32Layer_SetCLUTAddress          (LCDC_TFT_TypeDef* restrict   pslayer, uint32_t u32Address);
uint32_t LCDC__u32LayerBG_SetCLUTAddress        (uint32_t u32Address);


uint16_t LCDC__u16Layer_GetColorBG              (LCDC_TFT_TypeDef* restrict   psLayer);
uint16_t LCDC__u16LayerBG_GetColorBG            (void);
uint16_t LCDC__u16Layer_SetColorBG              (LCDC_TFT_TypeDef* restrict   psLayer, uint16_t u16ColorBG);
uint16_t LCDC__u16LayerBG_SetColorBG            (uint16_t u16ColorBG);

uint8_t LCDC__u8Layer_GetColorBGRed           (LCDC_TFT_TypeDef* restrict   psLayer);
uint8_t LCDC__u8LayerBG_GetColorBGRed         (void);
uint16_t LCDC__u16Layer_SetColorBGRed           (LCDC_TFT_TypeDef* restrict   psLayer, uint8_t u8RedBG);
uint16_t LCDC__u16LayerBG_SetColorBGRed         (uint8_t u8RedBG);

uint8_t LCDC__u8Layer_GetColorBGGreen         (LCDC_TFT_TypeDef* restrict   psLayer);
uint8_t LCDC__u8LayerBG_GetColorBGGreen       (void);
uint16_t LCDC__u16Layer_SetColorBGGreen         (LCDC_TFT_TypeDef* restrict   psLayer, uint8_t u8GreenBG);
uint16_t LCDC__u16LayerBG_SetColorBGGreen       (uint8_t u8GreenBG);

uint8_t LCDC__u8Layer_GetColorBGBlue          (LCDC_TFT_TypeDef* restrict   psLayer);
uint8_t LCDC__u8LayerBG_GetColorBGBlue        (void);
uint16_t LCDC__u16Layer_SetColorBGBlue          (LCDC_TFT_TypeDef* restrict   psLayer, uint8_t u8BlueBG);
uint16_t LCDC__u16LayerBG_SetColorBGBlue        (uint8_t u8BlueBG);



uint16_t LCDC__u16Layer_GetColorFont            (LCDC_TFT_TypeDef* restrict   psLayer);
uint16_t LCDC__u16LayerBG_GetColorFont          (void);
uint16_t LCDC__u16Layer_SetColorFont            (LCDC_TFT_TypeDef* restrict   psLayer, uint16_t u16ColorFont);
uint16_t LCDC__u16LayerBG_SetColorFont          (uint16_t u16ColorFont);

uint8_t LCDC__u8Layer_GetColorFontRed         (LCDC_TFT_TypeDef* restrict   psLayer);
uint8_t LCDC__u8LayerBG_GetColorFontRed       (void);
uint16_t LCDC__u16Layer_SetColorFontRed         (LCDC_TFT_TypeDef* restrict   psLayer, uint8_t u8RedBG);
uint16_t LCDC__u16LayerBG_SetColorFontRed       (uint8_t u8RedBG);

uint8_t LCDC__u8Layer_GetColorFontGreen       (LCDC_TFT_TypeDef* restrict   psLayer);
uint8_t LCDC__u8LayerBG_GetColorFontGreen     (void);
uint16_t LCDC__u16Layer_SetColorFontGreen       (LCDC_TFT_TypeDef* restrict   psLayer, uint8_t u8GreenBG);
uint16_t LCDC__u16LayerBG_SetColorFontGreen     (uint8_t u8GreenBG);

uint8_t LCDC__u8Layer_GetColorFontBlue        (LCDC_TFT_TypeDef* restrict   psLayer);
uint8_t LCDC__u8LayerBG_GetColorFontBlue      (void);
uint16_t LCDC__u16Layer_SetColorFontBlue        (LCDC_TFT_TypeDef* restrict   psLayer, uint8_t u8BlueBG);
uint16_t LCDC__u16LayerBG_SetColorFontBlue      (uint8_t u8BlueBG);


FONT_TypeDef* LCDC__sLayer_GetFontType          (LCDC_TFT_TypeDef* restrict   sLayer);
FONT_TypeDef* LCDC__sLayerBG_GetFontType        (void);


FONT_TypeDef* LCDC__sLayer_SetFontType          (LCDC_TFT_TypeDef* restrict   psLayer, FONT_nSize enFontSize);
FONT_TypeDef* LCDC__sLayerBG_SetFontType        (FONT_nSize enFontSize);



uint16_t LCDC__u16Layer_GetWidthTotal           (LCDC_TFT_TypeDef* restrict   psLayer);
uint16_t LCDC__u16LayerBG_GetWidthTotal         (void);
uint16_t LCDC__u16Layer_SetWidthTotal           (LCDC_TFT_TypeDef* restrict   psLayer,  uint16_t u16WidthTotal);
uint16_t LCDC__u16LayerBG_SetWidthTotal           (uint16_t u16WidthTotal);


uint16_t LCDC__u16Layer_GetHeightTotal          (LCDC_TFT_TypeDef* restrict   psLayer);
uint16_t LCDC__u16LayerBG_GetHeightTotal        (void);
uint16_t LCDC__u16Layer_SetHeightTotal          (LCDC_TFT_TypeDef* restrict   psLayer,  uint16_t u16HeightTotal);
uint16_t LCDC__u16LayerBG_SetHeightTotal        (uint16_t u16HeightTotal);


uint16_t LCDC__u16Layer_GetWidth                (LCDC_TFT_TypeDef* restrict   psLayer);
uint16_t LCDC__u16LayerBG_GetWidth              (void);

uint16_t LCDC__u16Layer_SetWidth                (LCDC_TFT_TypeDef* restrict   psLayer,  uint16_t u16Width);
uint16_t LCDC__u16LayerBG_SetWidth              (uint16_t u16Width);

uint16_t LCDC__u16Layer_GetHeight               (LCDC_TFT_TypeDef* restrict   psLayer);
uint16_t LCDC__u16LayerBG_GetHeight             (void);

uint16_t LCDC__u16Layer_SetHeight               (LCDC_TFT_TypeDef* restrict   psLayer,  uint16_t u16Height);
uint16_t LCDC__u16LayerBG_SetHeight             (uint16_t u16Height);


uint16_t LCDC__u16Layer_GetBGX          (LCDC_TFT_TypeDef* restrict   psLayer, uint16_t* u16BGX);
uint16_t LCDC__u16LayerBG_GetBGX        (uint16_t* u16BGX);
uint16_t LCDC__u16LayerFG_GetBGX        (uint16_t* u16BGX);
uint16_t LCDC__u16Layer_GetBGY          (LCDC_TFT_TypeDef* restrict   psLayer, uint16_t* u16BGY);
uint16_t LCDC__u16LayerBG_GetBGY        (uint16_t* u16BGY);
uint16_t LCDC__u16LayerFG_GetBGY        (uint16_t* u16BGY);
uint16_t LCDC__u16Layer_GetRadius       (LCDC_TFT_TypeDef* restrict   psLayer, uint16_t* u16Radius);
uint16_t LCDC__u16LayerBG_GetRadius     (uint16_t* u16Radius);
uint16_t LCDC__u16LayerFG_GetRadius     (uint16_t* u16Radius);
uint16_t LCDC__u16Layer_GetX            (LCDC_TFT_TypeDef* restrict   psLayer, uint16_t* u16X);
uint16_t LCDC__u16LayerBG_GetX          (uint16_t* u16X);
uint16_t LCDC__u16LayerFG_GetX          (uint16_t* u16X);
uint16_t LCDC__u16Layer_GetY            (LCDC_TFT_TypeDef* restrict   psLayer, uint16_t* u16Y);
uint16_t LCDC__u16LayerBG_GetY          (uint16_t* u16Y);
uint16_t LCDC__u16LayerFG_GetY          (uint16_t* u16Y);


uint16_t LCDC__u16Layer_SetBGX          (LCDC_TFT_TypeDef* restrict   psLayer, uint16_t* u16BGX);
uint16_t LCDC__u16LayerBG_SetBGX        (uint16_t* u16BGX);
uint16_t LCDC__u16Layer_SetBGY          (LCDC_TFT_TypeDef* restrict   psLayer, uint16_t* u16BGY);
uint16_t LCDC__u16LayerBG_SetBGY        (uint16_t* u16BGY);
uint16_t LCDC__u16Layer_SetRadius       (LCDC_TFT_TypeDef* restrict   psLayer, uint16_t* u16Radius);
uint16_t LCDC__u16LayerBG_SetRadius     (uint16_t* u16Radius);
uint16_t LCDC__u16Layer_SetX            (LCDC_TFT_TypeDef* restrict   psLayer, uint16_t* u16X);
uint16_t LCDC__u16LayerBG_SetX          (uint16_t* u16X);
uint16_t LCDC__u16Layer_SetY            (LCDC_TFT_TypeDef* restrict   psLayer, uint16_t* u16Y);
uint16_t LCDC__u16LayerBG_SetY          (uint16_t* u16Y);


LAYER_nType LCDC__enLayer_GetType           (LCDC_TFT_TypeDef* restrict   psLayer);
LAYER_nType LCDC__enLayerBG_GetType         (void);

LAYER_nType LCDC__enLayer_SetType           (LCDC_TFT_TypeDef* restrict   psLayer,LAYER_nType enType);
LAYER_nType LCDC__enLayerBG_GetType         (void);


LCDC_TFT_TypeDef*   LCDC__sLayer_GetSubLayer      (LCDC_TFT_TypeDef* restrict   psLayer,uint8_t u8Number);
LCDC_TFT_TypeDef*   LCDC__sLayerBG_GetSubLayer    (uint8_t u8Number);

uint8_t LCDC__u8Layer_AddSubLayer             (LCDC_TFT_TypeDef* restrict   psLayer,LCDC_TFT_TypeDef* restrict   psSubLayer);
uint8_t LCDC__u8LayerBG_AddSubLayer           (LCDC_TFT_TypeDef* restrict   psSubLayer);

Lcdc_nStatus LCDC__enLayer_DeleteSubLayer        (LCDC_TFT_TypeDef* restrict   psLayer,uint8_t u8Number);
Lcdc_nStatus LCDC__enLayerBG_DeleteSubLayer      (uint8_t u8Number);

Lcdc_nStatus LCDC__enLayer_RefreshSubLayer       (LCDC_TFT_TypeDef* restrict   psLayer,uint8_t u8Number);
Lcdc_nStatus LCDC__enLayerBG_RefreshSubLayer     (uint8_t u8Number);

Lcdc_nStatus LCDC__enLayer_RefreshAllSubLayer(LCDC_TFT_TypeDef* restrict   psLayer);
Lcdc_nStatus LCDC__enLayerBG_RefreshAllSubLayer(void);

Lcdc_nStatus LCDC__enLayer_RefreshSubLayersArray(LCDC_TFT_TypeDef* restrict   psLayer,uint8_t u8SubLayerInit, uint8_t u8Cant);
Lcdc_nStatus LCDC__enLayerBG_RefreshSubLayersArray(uint8_t u32SubLayerInit, uint8_t u8Cant);


__inline void LCDC__vLayer_Clear(LCDC_TFT_TypeDef* restrict   psLayer, uint16_t u16Color);
__inline void LCDC__vLayerBG_Clear(uint16_t u16Color);

__inline void LCDC__vLayer_ClearSection  (LCDC_TFT_TypeDef* restrict   psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint32_t u32Color);
__inline void LCDC__vLayerBG_ClearSection  (LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color);

Lcdc_nStatus LCDC__enLayer_Copy (LCDC_TFT_TypeDef* restrict   layerSource,LCDC_TFT_TypeDef* restrict   layerDest,LCDC_DIMENSIONS_TypeDef dim);
Lcdc_nStatus LCDC__enLayer_ImageNoHeaderType(LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);

__inline void  LCDC__vLayer_Print_RectanguleFill (LCDC_TFT_TypeDef* restrict   psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color);
__inline void  LCDC__vLayer_RectangleFillType(LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);


__inline void  LCDC__vLayer_Print_LineCompleteHorizontal (LCDC_TFT_TypeDef* restrict   psLayer,uint16_t u16Line,uint16_t u16color);
__inline void  LCDC__vLayer_LineCompleteHorizontalType(LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);

__inline void  LCDC__vLayer_Print_LineCompleteVertical (LCDC_TFT_TypeDef* restrict   psLayer,uint16_t u16Column,uint16_t u16color);
__inline void LCDC__vLayer_LineCompleteVerticalType(LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);

__inline void LCDC__vLayer_Print_FontLineComplete   (LCDC_TFT_TypeDef* restrict   psLayer,LCDC_DIMENSIONS_TypeDef sDim, uint16_t u16Color);
__inline void LCDC__vLayer_FontLineCompleteType (LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);

__inline void LCDC__vLayer_Print_FontLine   (LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim, uint16_t u16Color);
__inline void LCDC__vLayer_FontLineType (LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest);

__inline void LCDC__vLayer_Print_LineVertical (LCDC_TFT_TypeDef* restrict   psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16olor);
__inline void LCDC__vLayer_LineVerticalType(LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);


__inline void LCDC__vLayer_Print_LineHorizontal (LCDC_TFT_TypeDef* restrict   psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16olor);
__inline void LCDC__vLayer_LineHorizontalType(LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);

__inline void LCDC__vLayer_Print_Rectangle (LCDC_TFT_TypeDef* restrict   psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color);
__inline void LCDC__vLayer_RectangleType (LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);

__inline void LCDC__vLayer_Print_RectangleSemi (LCDC_TFT_TypeDef* restrict   psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color);
__inline void LCDC__vLayer_RectangleSemiType(LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);

#define LCDC__vLayer_Print_Pixel(psLayer,sDim,u16Color)    (*(uint16_t*)(psLayer->layerDataAddress+((sDim.YInit*psLayer->layerWidthTotal + sDim.XInit)*2))=u16Color)
__inline void LCDC__vLayer_PixelType(LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);

Lcdc_nStatus LCDC__enLayer_Print_LineXY(LCDC_TFT_TypeDef* restrict   psLayer,LCDC_DIMENSIONS_TypeDef dim,uint16_t u16Color);
Lcdc_nStatus LCDC__enLayer_LineXYType(LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);

Lcdc_nStatus LCDC__enLayer_Print_Circle (LCDC_TFT_TypeDef* restrict   psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color);
Lcdc_nStatus LCDC__enLayer_CircleType(LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);


Lcdc_nStatus LCDC__enLayer_Print_CircleFill (LCDC_TFT_TypeDef* restrict   psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color);
Lcdc_nStatus LCDC__enLayer_CircleFillType(LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);

Lcdc_nStatus LCDC__enLayer_Print_Cross  (LCDC_TFT_TypeDef* restrict   psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color);
Lcdc_nStatus LCDC__enLayer_CrossType(LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);

Lcdc_nStatus LCDC__enLayer_Print_Ellipse            (LCDC_TFT_TypeDef* restrict   layer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color);
Lcdc_nStatus LCDC__enLayer_EllipseType(LCDC_TFT_TypeDef* restrict   layerSource,LCDC_TFT_TypeDef* restrict   layerDest);


Lcdc_nStatus LCDC__enLayer_Print_EllipseFill            (LCDC_TFT_TypeDef* restrict   psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color);
Lcdc_nStatus LCDC__enLayer_EllipseFillType(LCDC_TFT_TypeDef* restrict   psLayerSource,LCDC_TFT_TypeDef* restrict   psLayerDest);

Lcdc_nStatus LCDC__enLayer_Print_Triangle           (LCDC_TFT_TypeDef* psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color);
Lcdc_nStatus LCDC__enLayer_TriangleType(LCDC_TFT_TypeDef* psLayerSource,LCDC_TFT_TypeDef* psLayerDest);

Lcdc_nStatus LCDC__enLayer_Print_TriangleFill(LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color);
Lcdc_nStatus LCDC__enLayer_TriangleFillType(LCDC_TFT_TypeDef* restrict psLayerSource,LCDC_TFT_TypeDef* restrict psLayerDest);

LCDC_COORD_TypeDef LCDC__sLayer_Print_Char(LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,char cASCII,uint16_t u16Color,FONT_TypeDef* sFontType);
LCDC_COORD_TypeDef LCDC__sLayer_Print_CharBG(LCDC_TFT_TypeDef* restrict psLayer,LCDC_DIMENSIONS_TypeDef sDim,char cASCII,uint16_t u16ColorFont, uint16_t u16ColorBG,FONT_TypeDef* sFontType);

uint32_t LCDC__u32Layer_Print_String(LCDC_TFT_TypeDef* psLayer,LCDC_DIMENSIONS_TypeDef sDim,LCDC_COORD_TypeDef* sCoord,char* pcString,uint16_t u16ColorFont,FONT_TypeDef* sFontType);
uint32_t LCDC__u32Layer_StringSimpleType(LCDC_TFT_TypeDef* psLayerSource,LCDC_TFT_TypeDef* psLayerDest);

uint32_t LCDC__u32Layer_Print_StringBG(LCDC_TFT_TypeDef* psLayer,LCDC_DIMENSIONS_TypeDef sDim,LCDC_COORD_TypeDef* sCoord,char* pcString,uint16_t u16ColorFont, uint16_t u16ColorBG,FONT_TypeDef* sFontType);
uint32_t LCDC__u32Layer_StringSimpleBGType(LCDC_TFT_TypeDef* psLayerSource,LCDC_TFT_TypeDef* psLayerDest);


uint64_t LTDC__u64Layer_Printf(char* restrict pcStringIn,char* restrict pcStringOut,...);
#endif /* DSP_INCLUDE_LCDC_H_ */
