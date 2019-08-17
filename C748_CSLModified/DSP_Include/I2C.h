/*
 * I2C.h
 *
 *  Created on: 31/07/2019
 *      Author: Lalo
 */

#ifndef DSP_INCLUDE_I2C_H_
#define DSP_INCLUDE_I2C_H_

#include "Core.h"
#include "SYSCFG.h"
#include "INTC.h"
#include "GPIO.h"
#include <SysTick.h>
#include <stdint.h>


#define I2C0_BASE            ((uint32_t)0x01C22000)
#define I2C1_BASE            ((uint32_t)0x01E28000)


typedef __IO struct
{
    __IO uint32_t OADDR         :10;
         uint32_t reserved0     :22;
}I2C_ICOAR_TypeDef;

typedef __IO struct
{
    __IO uint32_t AL            :1;
    __IO uint32_t NACK          :1;
    __IO uint32_t ARDY          :1;
    __IO uint32_t ICRRDY        :1;
    __IO uint32_t ICXRDY        :1;
    __IO uint32_t SCD           :1;
    __IO uint32_t AAS           :1;
         uint32_t reserved0     :25;
}I2C_ICIMR_TypeDef;

typedef __IO struct
{
    __IO uint32_t AL            :1;
    __IO uint32_t NACK          :1;
    __IO uint32_t ARDY          :1;
    __IO uint32_t ICRRDY        :1;
    __IO uint32_t ICXRDY        :1;
    __IO uint32_t SCD           :1;
         uint32_t reserved0     :2;
    __IO uint32_t AD0           :1;
    __IO uint32_t AAS           :1;
    __IO uint32_t XSMT          :1;
    __IO uint32_t RSFULL        :1;
    __IO uint32_t BB            :1;
    __IO uint32_t NACKSNT       :1;
    __IO uint32_t SDIR          :1;
         uint32_t reserved1     :17;
}I2C_ICSTR_TypeDef;

typedef __IO struct
{
    __IO uint32_t ICCL          :16;
         uint32_t reserved0     :16;
}I2C_ICCLKL_TypeDef;

typedef __IO struct
{
    __IO uint32_t ICCH          :16;
         uint32_t reserved0     :16;
}I2C_ICCLKH_TypeDef;

typedef __IO struct
{
    __IO uint32_t ICDC          :16;
         uint32_t reserved0     :16;
}I2C_ICCNT_TypeDef;

typedef __IO struct
{
    __IO uint32_t D             :8;
         uint32_t reserved0     :24;
}I2C_ICDRR_TypeDef;

typedef __IO struct
{
    __IO uint32_t SADDR         :10;
         uint32_t reserved0     :22;
}I2C_ICSAR_TypeDef;

typedef __IO struct
{
    __IO uint32_t D             :8;
         uint32_t reserved0     :24;
}I2C_ICDXR_TypeDef;

typedef __IO struct
{
    __IO uint32_t BC            :3;
    __IO uint32_t FDF           :1;
    __IO uint32_t STB           :1;
    __IO uint32_t IRS           :1;
    __IO uint32_t DLB           :1;
    __IO uint32_t RM            :1;
    __IO uint32_t XA            :1;
    __IO uint32_t TRX           :1;
    __IO uint32_t MST           :1;
    __IO uint32_t STP           :1;
         uint32_t reserved0     :1;
    __IO uint32_t STT           :1;
    __IO uint32_t FREE          :1;
    __IO uint32_t NACKMOD       :1;
         uint32_t reserved1     :16;
}I2C_ICMDR_TypeDef;

typedef __IO struct
{
    __IO uint32_t INTCODE        :3;
         uint32_t reserved0     :29;
}I2C_ICIVR_TypeDef;

typedef __IO struct
{
    __IO uint32_t BCM           :1;
    __IO uint32_t IGNACK        :1;
         uint32_t reserved0     :30;
}I2C_ICEMDR_TypeDef;

typedef __IO struct
{
    __IO uint32_t IPSC          :8;
         uint32_t reserved0     :24;
}I2C_ICPSC_TypeDef;

typedef __IO struct
{
    __IO uint32_t REVID1          :32;
}I2C_REVID1_TypeDef;

typedef __IO struct
{
    __IO uint32_t REVID2          :32;
}I2C_REVID2_TypeDef;

typedef __IO struct
{
    __IO uint32_t RXDMAEN       :1;
    __IO uint32_t TXDMAEN       :1;
         uint32_t reserved0     :30;
}I2C_ICDMAC_TypeDef;

typedef __IO struct
{
    __IO uint32_t PFUNC0        :1;
         uint32_t reserved0     :31;
}I2C_ICPFUNC_TypeDef;

typedef __IO struct
{
    __IO uint32_t PDIR0       :1;
    __IO uint32_t PDIR1       :1;
         uint32_t reserved0     :30;
}I2C_ICPDIR_TypeDef;

typedef __IO struct
{
    __IO uint32_t PDIN0       :1;
    __IO uint32_t PDIN1       :1;
         uint32_t reserved0     :30;
}I2C_ICPDIN_TypeDef;

typedef __IO struct
{
    __IO uint32_t PDOUT0       :1;
    __IO uint32_t PDOUT1       :1;
         uint32_t reserved0     :30;
}I2C_ICPDOUT_TypeDef;

typedef __IO struct
{
    __IO uint32_t PDSET0       :1;
    __IO uint32_t PDSET1       :1;
         uint32_t reserved0     :30;
}I2C_ICPDSET_TypeDef;

typedef __IO struct
{
    __IO uint32_t PDCLR0       :1;
    __IO uint32_t PDCLR1       :1;
         uint32_t reserved0     :30;
}I2C_ICPDCLR_TypeDef;


typedef struct  {

    union
    {
        __IO uint32_t            ICOAR;
        I2C_ICOAR_TypeDef      ICOAR_Bit;
    };
    union
    {
        __IO uint32_t            ICIMR;
        I2C_ICIMR_TypeDef      ICIMR_Bit;
    };
    union
    {
        __IO uint32_t            ICSTR;
        I2C_ICSTR_TypeDef      ICSTR_Bit;
    };
    union
    {
        __IO uint32_t            ICCLKL;
        I2C_ICCLKL_TypeDef      ICCLKL_Bit;
    };
    union
    {
        __IO uint32_t            ICCLKH;
        I2C_ICCLKH_TypeDef      ICCLKH_Bit;
    };
    union
    {
        __IO uint32_t            ICCNT;
        I2C_ICCNT_TypeDef      ICCNT_Bit;
    };
    union
    {
        __IO uint32_t            ICDRR;
        I2C_ICDRR_TypeDef      ICDRR_Bit;
    };
    union
    {
        __IO uint32_t            ICSAR;
        I2C_ICSAR_TypeDef      ICSAR_Bit;
    };
    union
    {
        __IO uint32_t            ICDXR;
        I2C_ICDXR_TypeDef      ICDXR_Bit;
    };
    union
    {
        __IO uint32_t            ICMDR;
        I2C_ICMDR_TypeDef      ICMDR_Bit;
    };
    union
    {
        __IO uint32_t            ICIVR;
        I2C_ICIVR_TypeDef      ICIVR_Bit;
    };
    union
    {
        __IO uint32_t            ICEMDR;
        I2C_ICEMDR_TypeDef      ICEMDR_Bit;
    };
    union
    {
        __IO uint32_t            ICPSC;
        I2C_ICPSC_TypeDef      ICPSC_Bit;
    };
    union
    {
        __IO uint32_t            REVID1;
        I2C_REVID1_TypeDef      REVID1_Bit;
    };
    union
    {
        __IO uint32_t            REVID2;
        I2C_REVID2_TypeDef      REVID2_Bit;
    };
    union
    {
        __IO uint32_t            ICDMAC;
        I2C_ICDMAC_TypeDef      ICDMAC_Bit;
    };
    uint32_t reserved0[2];
    union
    {
        __IO uint32_t            ICPFUNC;
        I2C_ICPFUNC_TypeDef      ICPFUNC_Bit;
    };
    union
    {
        __IO uint32_t            ICPDIR;
        I2C_ICPDIR_TypeDef      ICPDIR_Bit;
    };
    union
    {
        __IO uint32_t            ICPDIN;
        I2C_ICPDIN_TypeDef      ICPDIN_Bit;
    };
    union
    {
        __IO uint32_t            ICPDOUT;
        I2C_ICPDOUT_TypeDef      ICPDOUT_Bit;
    };
    union
    {
        __IO uint32_t            ICPDSET;
        I2C_ICPDSET_TypeDef      ICPDSET_Bit;
    };
    union
    {
        __IO uint32_t            ICPDCLR;
        I2C_ICPDCLR_TypeDef      ICPDCLR_Bit;
    };
} I2C_TypeDef;


#define I2C0            (((I2C_TypeDef*)(I2C0_BASE)))
#define I2C0_R(offset)  (*((__IO uint32_t *)(I2C0_BASE+offset)))
#define I2C1            (((I2C_TypeDef*)(I2C1_BASE)))
#define I2C1_R(offset)  (*((__IO uint32_t *)(I2C1_BASE+offset)))


#define I2C_ICOAR_OFFSET                 ((uint32_t)0x0000)
#define I2C_ICIMR_OFFSET                 ((uint32_t)0x0004)
#define I2C_ICSTR_OFFSET                 ((uint32_t)0x0008)
#define I2C_ICCLKL_OFFSET                ((uint32_t)0x000C)
#define I2C_ICCLKH_OFFSET                 ((uint32_t)0x0010)
#define I2C_ICCNT_OFFSET                 ((uint32_t)0x0014)
#define I2C_ICDRR_OFFSET                 ((uint32_t)0x0018)
#define I2C_ICSAR_OFFSET                ((uint32_t)0x001C)
#define I2C_ICDXR_OFFSET                 ((uint32_t)0x0020)
#define I2C_ICMDR_OFFSET                 ((uint32_t)0x0024)
#define I2C_ICIVR_OFFSET                 ((uint32_t)0x0028)
#define I2C_ICEMDR_OFFSET                ((uint32_t)0x002C)
#define I2C_ICPSC_OFFSET                 ((uint32_t)0x0030)
#define I2C_REVID1_OFFSET                 ((uint32_t)0x0034)
#define I2C_REVID2_OFFSET                 ((uint32_t)0x0038)
#define I2C_ICDMAC_OFFSET                ((uint32_t)0x003C)
#define I2C_ICPFUNC_OFFSET                 ((uint32_t)0x0048)
#define I2C_ICPDIR_OFFSET                ((uint32_t)0x004C)
#define I2C_ICPDIN_OFFSET                 ((uint32_t)0x0050)
#define I2C_ICPDOUT_OFFSET                 ((uint32_t)0x0054)
#define I2C_ICPDSET_OFFSET                 ((uint32_t)0x0058)
#define I2C_ICPDCLR_OFFSET                ((uint32_t)0x005C)


/**********************************************************************************************
************************************** 1 ICOAR ***********************************************
**********************************************************************************************/
#define I2C0_ICOAR                    (((I2C_ICOAR_TypeDef*)(I2C0_BASE+I2C_ICOAR_OFFSET )))
#define I2C0_ICOAR_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICOAR_OFFSET)))
#define I2C1_ICOAR                    (((I2C_ICOAR_TypeDef*)(I2C1_BASE+I2C_ICOAR_OFFSET )))
#define I2C1_ICOAR_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICOAR_OFFSET)))

/*--------*/
#define I2C_ICOAR_R_OADDR_MASK        ((uint32_t)0x000003FF)
#define I2C_ICOAR_R_OADDR_SHIFT         (0)

#define I2C_ICOAR_OADDR_MASK          ((uint32_t)0x000003FF)
/*--------*/

/**********************************************************************************************
************************************** 2 ICIMR ***********************************************
**********************************************************************************************/
#define I2C0_ICIMR                    (((I2C_ICIMR_TypeDef*)(I2C0_BASE+I2C_ICIMR_OFFSET )))
#define I2C0_ICIMR_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICIMR_OFFSET)))
#define I2C1_ICIMR                    (((I2C_ICIMR_TypeDef*)(I2C1_BASE+I2C_ICIMR_OFFSET )))
#define I2C1_ICIMR_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICIMR_OFFSET)))

/*--------*/
#define I2C_ICIMR_R_AL_MASK        ((uint32_t)0x00000001)
#define I2C_ICIMR_R_AL_SHIFT         (0)

#define I2C_ICIMR_AL_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICIMR_R_NACK_MASK        ((uint32_t)0x00000002)
#define I2C_ICIMR_R_NACK_SHIFT         (1)

#define I2C_ICIMR_NACK_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICIMR_R_ARDY_MASK        ((uint32_t)0x00000004)
#define I2C_ICIMR_R_ARDY_SHIFT         (2)

#define I2C_ICIMR_ARDY_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICIMR_R_ICRRDY_MASK        ((uint32_t)0x00000008)
#define I2C_ICIMR_R_ICRRDY_SHIFT         (3)

#define I2C_ICIMR_ICRRDY_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICIMR_R_ICXRDY_MASK        ((uint32_t)0x00000010)
#define I2C_ICIMR_R_ICXRDY_SHIFT         (4)

#define I2C_ICIMR_ICXRDY_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICIMR_R_SCD_MASK        ((uint32_t)0x00000020)
#define I2C_ICIMR_R_SCD_SHIFT         (5)

#define I2C_ICIMR_SCD_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICIMR_R_AAS_MASK        ((uint32_t)0x00000040)
#define I2C_ICIMR_R_AAS_SHIFT         (6)

#define I2C_ICIMR_AAS_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 3 ICSTR ***********************************************
**********************************************************************************************/
#define I2C0_ICSTR                    (((I2C_ICSTR_TypeDef*)(I2C0_BASE+I2C_ICSTR_OFFSET )))
#define I2C0_ICSTR_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICSTR_OFFSET)))
#define I2C1_ICSTR                    (((I2C_ICSTR_TypeDef*)(I2C1_BASE+I2C_ICSTR_OFFSET )))
#define I2C1_ICSTR_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICSTR_OFFSET)))

/*--------*/
#define I2C_ICSTR_R_AL_MASK        ((uint32_t)0x00000001)
#define I2C_ICSTR_R_AL_SHIFT         (0)

#define I2C_ICSTR_AL_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICSTR_R_NACK_MASK        ((uint32_t)0x00000002)
#define I2C_ICSTR_R_NACK_SHIFT         (1)

#define I2C_ICSTR_NACK_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICSTR_R_ARDY_MASK        ((uint32_t)0x00000004)
#define I2C_ICSTR_R_ARDY_SHIFT         (2)

#define I2C_ICSTR_ARDY_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICSTR_R_ICRRDY_MASK        ((uint32_t)0x00000008)
#define I2C_ICSTR_R_ICRRDY_SHIFT         (3)

#define I2C_ICSTR_ICRRDY_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICSTR_R_ICXRDY_MASK        ((uint32_t)0x00000010)
#define I2C_ICSTR_R_ICXRDY_SHIFT         (4)

#define I2C_ICSTR_ICXRDY_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICSTR_R_SCD_MASK        ((uint32_t)0x00000020)
#define I2C_ICSTR_R_SCD_SHIFT         (5)

#define I2C_ICSTR_SCD_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICSTR_R_AD0_MASK        ((uint32_t)0x00000100)
#define I2C_ICSTR_R_AD0_SHIFT         (8)

#define I2C_ICSTR_AD0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICSTR_R_AAS_MASK        ((uint32_t)0x00000200)
#define I2C_ICSTR_R_AAS_SHIFT         (9)

#define I2C_ICSTR_AAS_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICSTR_R_XSMT_MASK        ((uint32_t)0x00000400)
#define I2C_ICSTR_R_XSMT_SHIFT         (10)

#define I2C_ICSTR_XSMT_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICSTR_R_RSFULL_MASK        ((uint32_t)0x00000800)
#define I2C_ICSTR_R_RSFULL_SHIFT         (11)

#define I2C_ICSTR_RSFULL_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICSTR_R_BB_MASK        ((uint32_t)0x00001000)
#define I2C_ICSTR_R_BB_SHIFT         (12)

#define I2C_ICSTR_BB_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICSTR_R_NACKSNT_MASK        ((uint32_t)0x00002000)
#define I2C_ICSTR_R_NACKSNT_SHIFT         (13)

#define I2C_ICSTR_NACKSNT_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICSTR_R_SDIR_MASK        ((uint32_t)0x00004000)
#define I2C_ICSTR_R_SDIR_SHIFT         (14)

#define I2C_ICSTR_SDIR_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 4 ICCLKL ***********************************************
**********************************************************************************************/
#define I2C0_ICCLKL                    (((I2C_ICCLKL_TypeDef*)(I2C0_BASE+I2C_ICCLKL_OFFSET )))
#define I2C0_ICCLKL_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICCLKL_OFFSET)))
#define I2C1_ICCLKL                    (((I2C_ICCLKL_TypeDef*)(I2C1_BASE+I2C_ICCLKL_OFFSET )))
#define I2C1_ICCLKL_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICCLKL_OFFSET)))

/*--------*/
#define I2C_ICCLKL_R_ICCL_MASK        ((uint32_t)0x0000FFFF)
#define I2C_ICCLKL_R_ICCL_SHIFT         (0)

#define I2C_ICCLKL_ICCL_MASK          ((uint32_t)0x0000FFFF)
/*--------*/

/**********************************************************************************************
************************************** 5 ICCLKH ***********************************************
**********************************************************************************************/
#define I2C0_ICCLKH                    (((I2C_ICCLKH_TypeDef*)(I2C0_BASE+I2C_ICCLKH_OFFSET )))
#define I2C0_ICCLKH_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICCLKH_OFFSET)))
#define I2C1_ICCLKH                    (((I2C_ICCLKH_TypeDef*)(I2C1_BASE+I2C_ICCLKH_OFFSET )))
#define I2C1_ICCLKH_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICCLKH_OFFSET)))

/*--------*/
#define I2C_ICCLKH_R_ICCH_MASK        ((uint32_t)0x0000FFFF)
#define I2C_ICCLKH_R_ICCH_SHIFT         (0)

#define I2C_ICCLKH_ICCH_MASK          ((uint32_t)0x0000FFFF)
/*--------*/

/**********************************************************************************************
************************************** 6 ICCNT ***********************************************
**********************************************************************************************/
#define I2C0_ICCNT                    (((I2C_ICCNT_TypeDef*)(I2C0_BASE+I2C_ICCNT_OFFSET )))
#define I2C0_ICCNT_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICCNT_OFFSET)))
#define I2C1_ICCNT                    (((I2C_ICCNT_TypeDef*)(I2C1_BASE+I2C_ICCNT_OFFSET )))
#define I2C1_ICCNT_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICCNT_OFFSET)))

/*--------*/
#define I2C_ICCNT_R_ICDC_MASK        ((uint32_t)0x0000FFFF)
#define I2C_ICCNT_R_ICDC_SHIFT         (0)

#define I2C_ICCNT_ICDC_MASK          ((uint32_t)0x0000FFFF)
/*--------*/

/**********************************************************************************************
************************************** 7 ICDRR ***********************************************
**********************************************************************************************/
#define I2C0_ICDRR                    (((I2C_ICDRR_TypeDef*)(I2C0_BASE+I2C_ICDRR_OFFSET )))
#define I2C0_ICDRR_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICDRR_OFFSET)))
#define I2C1_ICDRR                    (((I2C_ICDRR_TypeDef*)(I2C1_BASE+I2C_ICDRR_OFFSET )))
#define I2C1_ICDRR_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICDRR_OFFSET)))

/*--------*/
#define I2C_ICDRR_R_D_MASK        ((uint32_t)0x000000FF)
#define I2C_ICDRR_R_D_SHIFT         (0)

#define I2C_ICDRR_D_MASK          ((uint32_t)0x000000FF)
/*--------*/

/**********************************************************************************************
************************************** 8 ICSAR ***********************************************
**********************************************************************************************/
#define I2C0_ICSAR                    (((I2C_ICSAR_TypeDef*)(I2C0_BASE+I2C_ICSAR_OFFSET )))
#define I2C0_ICSAR_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICSAR_OFFSET)))
#define I2C1_ICSAR                    (((I2C_ICSAR_TypeDef*)(I2C1_BASE+I2C_ICSAR_OFFSET )))
#define I2C1_ICSAR_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICSAR_OFFSET)))

/*--------*/
#define I2C_ICSAR_R_SADDR_MASK        ((uint32_t)0x000003FF)
#define I2C_ICSAR_R_SADDR_SHIFT         (0)

#define I2C_ICSAR_SADDR_MASK          ((uint32_t)0x000003FF)
/*--------*/

/**********************************************************************************************
************************************** 9 ICDXR ***********************************************
**********************************************************************************************/
#define I2C0_ICDXR                    (((I2C_ICDXR_TypeDef*)(I2C0_BASE+I2C_ICDXR_OFFSET )))
#define I2C0_ICDXR_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICDXR_OFFSET)))
#define I2C1_ICDXR                    (((I2C_ICDXR_TypeDef*)(I2C1_BASE+I2C_ICDXR_OFFSET )))
#define I2C1_ICDXR_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICDXR_OFFSET)))

/*--------*/
#define I2C_ICDXR_R_D_MASK        ((uint32_t)0x000000FF)
#define I2C_ICDXR_R_D_SHIFT         (0)

#define I2C_ICDXR_D_MASK          ((uint32_t)0x000000FF)
/*--------*/

/**********************************************************************************************
************************************** 10 ICMDR ***********************************************
**********************************************************************************************/
#define I2C0_ICMDR                    (((I2C_ICMDR_TypeDef*)(I2C0_BASE+I2C_ICMDR_OFFSET )))
#define I2C0_ICMDR_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICMDR_OFFSET)))
#define I2C1_ICMDR                    (((I2C_ICMDR_TypeDef*)(I2C1_BASE+I2C_ICMDR_OFFSET )))
#define I2C1_ICMDR_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICMDR_OFFSET)))

/*--------*/
#define I2C_ICMDR_R_BC_MASK        ((uint32_t)0x00000007)
#define I2C_ICMDR_R_BC_SHIFT         (0)

#define I2C_ICMDR_BC_MASK          ((uint32_t)0x00000007)
/*--------*/

/*--------*/
#define I2C_ICMDR_R_FDF_MASK        ((uint32_t)0x00000008)
#define I2C_ICMDR_R_FDF_SHIFT         (3)

#define I2C_ICMDR_FDF_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICMDR_R_STB_MASK        ((uint32_t)0x00000010)
#define I2C_ICMDR_R_STB_SHIFT         (4)

#define I2C_ICMDR_STB_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICMDR_R_IRS_MASK        ((uint32_t)0x00000020)
#define I2C_ICMDR_R_IRS_SHIFT         (5)

#define I2C_ICMDR_IRS_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICMDR_R_DLB_MASK        ((uint32_t)0x00000040)
#define I2C_ICMDR_R_DLB_SHIFT         (6)

#define I2C_ICMDR_DLB_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICMDR_R_RM_MASK        ((uint32_t)0x00000080)
#define I2C_ICMDR_R_RM_SHIFT         (7)

#define I2C_ICMDR_RM_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICMDR_R_XA_MASK        ((uint32_t)0x00000100)
#define I2C_ICMDR_R_XA_SHIFT         (8)

#define I2C_ICMDR_XA_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICMDR_R_TRX_MASK        ((uint32_t)0x00000200)
#define I2C_ICMDR_R_TRX_SHIFT         (9)

#define I2C_ICMDR_TRX_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICMDR_R_MST_MASK        ((uint32_t)0x00000400)
#define I2C_ICMDR_R_MST_SHIFT         (10)

#define I2C_ICMDR_MST_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICMDR_R_STP_MASK        ((uint32_t)0x00000800)
#define I2C_ICMDR_R_STP_SHIFT         (11)

#define I2C_ICMDR_STP_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICMDR_R_STT_MASK        ((uint32_t)0x00002000)
#define I2C_ICMDR_R_STT_SHIFT         (13)

#define I2C_ICMDR_STT_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICMDR_R_FREE_MASK        ((uint32_t)0x00004000)
#define I2C_ICMDR_R_FREE_SHIFT         (14)

#define I2C_ICMDR_FREE_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICMDR_R_NACKMOD_MASK        ((uint32_t)0x00008000)
#define I2C_ICMDR_R_NACKMOD_SHIFT         (15)

#define I2C_ICMDR_NACKMOD_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 11 ICIVR ***********************************************
**********************************************************************************************/
#define I2C0_ICIVR                    (((I2C_ICIVR_TypeDef*)(I2C0_BASE+I2C_ICIVR_OFFSET )))
#define I2C0_ICIVR_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICIVR_OFFSET)))
#define I2C1_ICIVR                    (((I2C_ICIVR_TypeDef*)(I2C1_BASE+I2C_ICIVR_OFFSET )))
#define I2C1_ICIVR_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICIVR_OFFSET)))

/*--------*/
#define I2C_ICIVR_R_INTCODE_MASK        ((uint32_t)0x00000007)
#define I2C_ICIVR_R_INTCODE_SHIFT         (0)

#define I2C_ICIVR_INTCODE_MASK          ((uint32_t)0x00000007)
/*--------*/

/**********************************************************************************************
************************************** 12 ICEMDR ***********************************************
**********************************************************************************************/
#define I2C0_ICEMDR                    (((I2C_ICEMDR_TypeDef*)(I2C0_BASE+I2C_ICEMDR_OFFSET )))
#define I2C0_ICEMDR_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICEMDR_OFFSET)))
#define I2C1_ICEMDR                    (((I2C_ICEMDR_TypeDef*)(I2C1_BASE+I2C_ICEMDR_OFFSET )))
#define I2C1_ICEMDR_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICEMDR_OFFSET)))

/*--------*/
#define I2C_ICEMDR_R_BCM_MASK        ((uint32_t)0x00000001)
#define I2C_ICEMDR_R_BCM_SHIFT         (0)

#define I2C_ICEMDR_BCM_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICEMDR_R_IGNACK_MASK        ((uint32_t)0x00000002)
#define I2C_ICEMDR_R_IGNACK_SHIFT         (1)

#define I2C_ICEMDR_IGNACK_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 13 ICPSC ***********************************************
**********************************************************************************************/
#define I2C0_ICPSC                    (((I2C_ICPSC_TypeDef*)(I2C0_BASE+I2C_ICPSC_OFFSET )))
#define I2C0_ICPSC_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICPSC_OFFSET)))
#define I2C1_ICPSC                    (((I2C_ICPSC_TypeDef*)(I2C1_BASE+I2C_ICPSC_OFFSET )))
#define I2C1_ICPSC_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICPSC_OFFSET)))

/*--------*/
#define I2C_ICPSC_R_IPSC_MASK        ((uint32_t)0x000000FF)
#define I2C_ICPSC_R_IPSC_SHIFT         (0)

#define I2C_ICPSC_IPSC_MASK          ((uint32_t)0x000000FF)
/*--------*/

/**********************************************************************************************
************************************** 14 REVID1 ***********************************************
**********************************************************************************************/
#define I2C0_REVID1                    (((I2C_REVID1_TypeDef*)(I2C0_BASE+I2C_REVID1_OFFSET )))
#define I2C0_REVID1_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_REVID1_OFFSET)))
#define I2C1_REVID1                    (((I2C_REVID1_TypeDef*)(I2C1_BASE+I2C_REVID1_OFFSET )))
#define I2C1_REVID1_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_REVID1_OFFSET)))

/*--------*/
#define I2C_REVID1_R_REVID1_MASK        ((uint32_t)0xFFFFFFFF)
#define I2C_REVID1_R_REVID1_SHIFT         (0)

#define I2C_REVID1_REVID1_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 15 REVID2 ***********************************************
**********************************************************************************************/
#define I2C0_REVID2                    (((I2C_REVID2_TypeDef*)(I2C0_BASE+I2C_REVID2_OFFSET )))
#define I2C0_REVID2_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_REVID2_OFFSET)))
#define I2C1_REVID2                    (((I2C_REVID2_TypeDef*)(I2C1_BASE+I2C_REVID2_OFFSET )))
#define I2C1_REVID2_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_REVID2_OFFSET)))

/*--------*/
#define I2C_REVID2_R_REVID2_MASK        ((uint32_t)0xFFFFFFFF)
#define I2C_REVID2_R_REVID2_SHIFT         (0)

#define I2C_REVID2_REVID2_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 16 ICDMAC ***********************************************
**********************************************************************************************/
#define I2C0_ICDMAC                    (((I2C_ICDMAC_TypeDef*)(I2C0_BASE+I2C_ICDMAC_OFFSET )))
#define I2C0_ICDMAC_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICDMAC_OFFSET)))
#define I2C1_ICDMAC                    (((I2C_ICDMAC_TypeDef*)(I2C1_BASE+I2C_ICDMAC_OFFSET )))
#define I2C1_ICDMAC_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICDMAC_OFFSET)))

/*--------*/
#define I2C_ICDMAC_R_RXDMAEN_MASK        ((uint32_t)0x00000001)
#define I2C_ICDMAC_R_RXDMAEN_SHIFT         (0)

#define I2C_ICDMAC_RXDMAEN_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICDMAC_R_TXDMAEN_MASK        ((uint32_t)0x00000002)
#define I2C_ICDMAC_R_TXDMAEN_SHIFT         (1)

#define I2C_ICDMAC_TXDMAEN_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 17 ICPFUNC ***********************************************
**********************************************************************************************/
#define I2C0_ICPFUNC                    (((I2C_ICPFUNC_TypeDef*)(I2C0_BASE+I2C_ICPFUNC_OFFSET )))
#define I2C0_ICPFUNC_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICPFUNC_OFFSET)))
#define I2C1_ICPFUNC                    (((I2C_ICPFUNC_TypeDef*)(I2C1_BASE+I2C_ICPFUNC_OFFSET )))
#define I2C1_ICPFUNC_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICPFUNC_OFFSET)))

/*--------*/
#define I2C_ICPFUNC_R_PFUNC0_MASK        ((uint32_t)0x00000001)
#define I2C_ICPFUNC_R_PFUNC0_SHIFT         (0)

#define I2C_ICPFUNC_PFUNC0_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 18 ICPDIR ***********************************************
**********************************************************************************************/
#define I2C0_ICPDIR                    (((I2C_ICPDIR_TypeDef*)(I2C0_BASE+I2C_ICPDIR_OFFSET )))
#define I2C0_ICPDIR_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICPDIR_OFFSET)))
#define I2C1_ICPDIR                    (((I2C_ICPDIR_TypeDef*)(I2C1_BASE+I2C_ICPDIR_OFFSET )))
#define I2C1_ICPDIR_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICPDIR_OFFSET)))

/*--------*/
#define I2C_ICPDIR_R_PDIR0_MASK        ((uint32_t)0x00000001)
#define I2C_ICPDIR_R_PDIR0_SHIFT         (0)

#define I2C_ICPDIR_PDIR0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICPDIR_R_PDIR1_MASK        ((uint32_t)0x00000002)
#define I2C_ICPDIR_R_PDIR1_SHIFT         (1)

#define I2C_ICPDIR_PDIR1_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 19 ICPDIN ***********************************************
**********************************************************************************************/
#define I2C0_ICPDIN                    (((I2C_ICPDIN_TypeDef*)(I2C0_BASE+I2C_ICPDIN_OFFSET )))
#define I2C0_ICPDIN_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICPDIN_OFFSET)))
#define I2C1_ICPDIN                    (((I2C_ICPDIN_TypeDef*)(I2C1_BASE+I2C_ICPDIN_OFFSET )))
#define I2C1_ICPDIN_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICPDIN_OFFSET)))

/*--------*/
#define I2C_ICPDIN_R_PDIN0_MASK        ((uint32_t)0x00000001)
#define I2C_ICPDIN_R_PDIN0_SHIFT         (0)

#define I2C_ICPDIN_PDIN0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICPDIN_R_PDIN1_MASK        ((uint32_t)0x00000002)
#define I2C_ICPDIN_R_PDIN1_SHIFT         (1)

#define I2C_ICPDIN_PDIN1_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 20 ICPDOUT ***********************************************
**********************************************************************************************/
#define I2C0_ICPDOUT                    (((I2C_ICPDOUT_TypeDef*)(I2C0_BASE+I2C_ICPDOUT_OFFSET )))
#define I2C0_ICPDOUT_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICPDOUT_OFFSET)))
#define I2C1_ICPDOUT                    (((I2C_ICPDOUT_TypeDef*)(I2C1_BASE+I2C_ICPDOUT_OFFSET )))
#define I2C1_ICPDOUT_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICPDOUT_OFFSET)))

/*--------*/
#define I2C_ICPDOUT_R_PDOUT0_MASK        ((uint32_t)0x00000001)
#define I2C_ICPDOUT_R_PDOUT0_SHIFT         (0)

#define I2C_ICPDOUT_PDOUT0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICPDOUT_R_PDOUT1_MASK        ((uint32_t)0x00000002)
#define I2C_ICPDOUT_R_PDOUT1_SHIFT         (1)

#define I2C_ICPDOUT_PDOUT1_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 21 ICPDSET ***********************************************
**********************************************************************************************/
#define I2C0_ICPDSET                    (((I2C_ICPDSET_TypeDef*)(I2C0_BASE+I2C_ICPDSET_OFFSET )))
#define I2C0_ICPDSET_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICPDSET_OFFSET)))
#define I2C1_ICPDSET                    (((I2C_ICPDSET_TypeDef*)(I2C1_BASE+I2C_ICPDSET_OFFSET )))
#define I2C1_ICPDSET_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICPDSET_OFFSET)))

/*--------*/
#define I2C_ICPDSET_R_PDSET0_MASK        ((uint32_t)0x00000001)
#define I2C_ICPDSET_R_PDSET0_SHIFT         (0)

#define I2C_ICPDSET_PDSET0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICPDSET_R_PDSET1_MASK        ((uint32_t)0x00000002)
#define I2C_ICPDSET_R_PDSET1_SHIFT         (1)

#define I2C_ICPDSET_PDSET1_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 22 ICPDCLR ***********************************************
**********************************************************************************************/
#define I2C0_ICPDCLR                    (((I2C_ICPDCLR_TypeDef*)(I2C0_BASE+I2C_ICPDCLR_OFFSET )))
#define I2C0_ICPDCLR_R                  (*((__IO uint32_t *)(I2C0_BASE+I2C_ICPDCLR_OFFSET)))
#define I2C1_ICPDCLR                    (((I2C_ICPDCLR_TypeDef*)(I2C1_BASE+I2C_ICPDCLR_OFFSET )))
#define I2C1_ICPDCLR_R                  (*((__IO uint32_t *)(I2C1_BASE+I2C_ICPDCLR_OFFSET)))

/*--------*/
#define I2C_ICPDCLR_R_PDCLR0_MASK        ((uint32_t)0x00000001)
#define I2C_ICPDCLR_R_PDCLR0_SHIFT         (0)

#define I2C_ICPDCLR_PDCLR0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define I2C_ICPDCLR_R_PDCLR1_MASK        ((uint32_t)0x00000002)
#define I2C_ICPDCLR_R_PDCLR1_SHIFT         (1)

#define I2C_ICPDCLR_PDCLR1_MASK          ((uint32_t)0x00000001)
/*--------*/


typedef enum
{
   I2C_CLOCK_en100K = 0,
   I2C_CLOCK_en200K,
   I2C_CLOCK_en400K
} I2c_nClockKernel;


typedef enum
{
   I2C_enOK = 0,
   I2C_enERROR,
   I2C_enTIMEOUT
} I2c_nStatus;

typedef enum
{
   I2C_en0 = I2C0_BASE,
   I2C_en1 =I2C1_BASE,
} I2c_nDev;

typedef enum
{
   I2C_COMM_enREADY = 0,
   I2C_COMM_enBUSY,
} I2c_nCommStatus;

typedef enum
{
   I2C_enNONE = 0,
   I2C_enAL =1,
   I2C_enNACK=2,
   I2C_enARDY=3,
   I2C_enICRRDY=4,
   I2C_enICXRDY=5,
   I2C_enSCD=6,
   I2C_enAAS=7,
} I2c_nIntCode;


typedef struct
{
    uint32_t init :1 ;
    uint32_t newLine :1 ;
    uint32_t carrigeReturn :1 ;
    uint32_t reserved0 :29 ;
}I2C_STATUS_TypeDef;

#define I2C_MAX (30)
typedef struct  {
  int16_t u16Put;                                // Next In Index
  int16_t u16Get;                               // Next Out Index
  union
  {
      I2C_STATUS_TypeDef sStatus_Bit;
      uint32_t  u32Status;
  };
  char pcFifo [I2C_MAX];                           // Buffer

}I2cFifo_TypeDef;


#define I2C_TIMEOUT           (100000)
#define I2C_DEV (16)

I2c_nStatus I2C__enInit(I2C_TypeDef *i2c, I2c_nClockKernel in_clock_rate);
I2c_nStatus I2C__enRead(I2C_TypeDef *i2c, uint16_t in_addr, uint8_t *dest_buffer, uint16_t in_length, uint8_t chk_busy);
I2c_nStatus I2C__enWrite(I2C_TypeDef *i2c, uint16_t in_addr, uint8_t *src_buffer, uint16_t in_length, uint8_t set_stop);
I2c_nStatus I2C_enMasterSendData(I2C_TypeDef *i2c,uint8_t u8SlaveAddress, uint16_t u16DataNumber, uint8_t* pu8DataSend);
I2c_nStatus I2C_enMasterReadData(I2C_TypeDef *i2c,uint8_t u8SlaveAddress, uint16_t u16DataNumber, uint8_t* pu8DataReceive);
I2c_nStatus I2C_enMasterSendReadData(I2C_TypeDef *i2c,uint8_t u8SlaveAddress, uint16_t u16DataNumberSend, uint8_t* pu8DataSend, uint16_t u16DataNumberRead, uint8_t* pu8DataRead);

#endif /* DSP_INCLUDE_I2C_H_ */
