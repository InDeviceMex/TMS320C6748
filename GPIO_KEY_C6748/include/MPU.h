/*
 * MPU.h
 *
 *  Created on: 17/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_MPU_H_
#define INCLUDE_MPU_H_

#include "Core.h"
#include <stdint.h>

#define MPU1_BASE            ((uint32_t)0x01E14000)
#define MPU2_BASE            ((uint32_t)0x01E15000)


typedef __IO struct
{
    __I uint32_t REV       :32;
}MPU_REVID_TypeDef;


typedef __IO struct
{
    __I uint32_t ASSUME_ALLOWED  :1;
        uint32_t reserved0       :11;
    __I uint32_t NUM_AIDS        :4;
    __I uint32_t NUM_PROG        :4;
    __I uint32_t NUM_FIXED       :4;
    __I uint32_t ADDR_WIDTH      :8;
}MPU_CONFIG_TypeDef;


typedef __IO struct
{
    __IO uint32_t PROTERR   :1;
    __IO uint32_t ADDRERR   :1;
         uint32_t reserved0 :30;
}MPU_IRAWSTAT_TypeDef;


typedef __IO struct
{
    __IO uint32_t PROTERR   :1;
    __IO uint32_t ADDRERR   :1;
         uint32_t reserved0 :30;
}MPU_IENSTAT_TypeDef;


typedef __IO struct
{
    __IO uint32_t PROTERR_EN    :1;
    __IO uint32_t ADDRERR_EN    :1;
         uint32_t reserved0     :30;
}MPU_IENSET_TypeDef;


typedef __IO struct
{
    __IO uint32_t PROTERR_CLR   :1;
    __IO uint32_t ADDRERR_CLR   :1;
         uint32_t reserved0     :30;
}MPU_IENCLR_TypeDef;


typedef __IO struct
{
         uint32_t reserved0 :32;
}MPU_FXD_MPSAR_TypeDef;


typedef __IO struct
{
         uint32_t reserved0 :32;
}MPU_FXD_MPEAR_TypeDef;


typedef __IO struct
{
    __IO uint32_t UX        :1;
    __IO uint32_t UW        :1;
    __IO uint32_t UR        :1;
    __IO uint32_t SX        :1;
    __IO uint32_t SW        :1;
    __IO uint32_t SR        :1;
         uint32_t reserved0 :3;
    __IO uint32_t AIDX      :1;
    __IO uint32_t AID0      :1;
    __IO uint32_t AID1      :1;
    __IO uint32_t AID2      :1;
    __IO uint32_t AID3      :1;
    __IO uint32_t AID4      :1;
    __IO uint32_t AID5      :1;
    __IO uint32_t AID6      :1;
    __IO uint32_t AID7      :1;
    __IO uint32_t AID8      :1;
    __IO uint32_t AID9      :1;
    __IO uint32_t AID10     :1;
    __IO uint32_t AID11     :1;
         uint32_t reserved1 :10;
}MPU_FXD_MPPA_TypeDef;


typedef __IO struct
{
         uint32_t reserved0   :10;
    __IO uint32_t START_ADDR  :22;
}MPU_PROGn_MPSAR_TypeDef;


typedef __IO struct
{
         uint32_t reserved0  :10;
    __IO uint32_t END_ADDR   :22;
}MPU_PROGn_MPEAR_TypeDef;
typedef __IO struct
{
    __IO uint32_t UX        :1;
    __IO uint32_t UW        :1;
    __IO uint32_t UR        :1;
    __IO uint32_t SX        :1;
    __IO uint32_t SW        :1;
    __IO uint32_t SR        :1;
         uint32_t reserved0 :3;
    __IO uint32_t AIDX      :1;
    __IO uint32_t AID0      :1;
    __IO uint32_t AID1      :1;
    __IO uint32_t AID2      :1;
    __IO uint32_t AID3      :1;
    __IO uint32_t AID4      :1;
    __IO uint32_t AID5      :1;
    __IO uint32_t AID6      :1;
    __IO uint32_t AID7      :1;
    __IO uint32_t AID8      :1;
    __IO uint32_t AID9      :1;
    __IO uint32_t AID10     :1;
    __IO uint32_t AID11     :1;
         uint32_t reserved1 :10;
}MPU_PROGn_MPPA_TypeDef;


typedef __IO struct
{
    __I uint32_t FLTADDR   :32;
}MPU_FLTADDRR_TypeDef;

typedef __IO struct
{
    __I uint32_t TYPE       :6;
        uint32_t reserved0  :3;
    __I uint32_t PRIVID     :4;
        uint32_t reserved1  :3;
    __I uint32_t MSTID      :8;
        uint32_t reserved2  :8;
}MPU_FLTSTAT_TypeDef;

typedef __IO struct
{
    __IO uint32_t CLEAR     :1;
        uint32_t reserved0  :31;
}MPU_FLTCLR_TypeDef;




typedef __IO struct
{
    union
    {
        __IO uint32_t       REVID;
        MPU_REVID_TypeDef   REVID_Bit;
    };
    union
    {
        __IO uint32_t       CONFIG;
        MPU_CONFIG_TypeDef  CONFIG_Bit;
    };
    uint32_t reserved0[2];

    union
    {
        __IO uint32_t           IRAWSTAT;
        MPU_IRAWSTAT_TypeDef    IRAWSTAT_Bit;
    };
    union
    {
        __IO uint32_t           IENSTAT;
        MPU_IENSTAT_TypeDef     IENSTAT_Bit;
    };
    union
    {
        __IO uint32_t           IENSET;
        MPU_IENSET_TypeDef      IENSET_Bit;
    };
    union
    {
        __IO uint32_t           IENCLR;
        MPU_IENCLR_TypeDef      IENCLR_Bit;
    };
    uint32_t reserved1[120];
    union
    {
        __IO uint32_t           PROG1_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG1_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG1_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG1_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG1_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG1_MPPA_Bit;
    };
    uint32_t reserved2[1];
    union
    {
        __IO uint32_t           PROG2_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG2_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG2_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG2_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG2_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG2_MPPA_Bit;
    };
    uint32_t reserved3[1];
    union
    {
        __IO uint32_t           PROG3_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG3_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG3_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG3_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG3_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG3_MPPA_Bit;
    };
    uint32_t reserved4[1];
    union
    {
        __IO uint32_t           PROG4_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG4_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG4_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG4_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG4_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG4_MPPA_Bit;
    };
    uint32_t reserved5[1];
    union
    {
        __IO uint32_t           PROG5_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG5_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG5_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG5_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG5_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG5_MPPA_Bit;
    };
    uint32_t reserved6[1];
    union
    {
        __IO uint32_t           PROG6_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG6_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG6_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG6_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG6_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG6_MPPA_Bit;
    };
    uint32_t reserved7[41];


    union
    {
        __IO uint32_t       FLTADDRR;
        MPU_FLTADDRR_TypeDef  FLTADDRR_Bit;
    };
    union
    {
        __IO uint32_t       FLTSTAT;
        MPU_FLTSTAT_TypeDef  FLTSTAT_Bit;
    };
    union
    {
        __IO uint32_t       FLTCLR;
        MPU_FLTCLR_TypeDef  FLTCLR_Bit;
    };

}MPU1_TypeDef;

typedef __IO struct
{
    union
    {
        __IO uint32_t       REVID;
        MPU_REVID_TypeDef   REVID_Bit;
    };
    union
    {
        __IO uint32_t       CONFIG;
        MPU_CONFIG_TypeDef  CONFIG_Bit;
    };
    uint32_t reserved0[2];

    union
    {
        __IO uint32_t           IRAWSTAT;
        MPU_IRAWSTAT_TypeDef    IRAWSTAT_Bit;
    };
    union
    {
        __IO uint32_t           IENSTAT;
        MPU_IENSTAT_TypeDef     IENSTAT_Bit;
    };
    union
    {
        __IO uint32_t           IENSET;
        MPU_IENSET_TypeDef      IENSET_Bit;
    };
    union
    {
        __IO uint32_t           IENCLR;
        MPU_IENCLR_TypeDef      IENCLR_Bit;
    };
    uint32_t reserved1[56];
    union
    {
        __IO uint32_t           FXD_MPSAR;
        MPU_FXD_MPSAR_TypeDef   FXD_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           FXD_MPEAR;
        MPU_FXD_MPEAR_TypeDef   FXD_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           FXD_MPPA;
        MPU_FXD_MPPA_TypeDef    FXD_MPPA_Bit;
    };
    uint32_t reserved2[61];
    union
    {
        __IO uint32_t           PROG1_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG1_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG1_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG1_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG1_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG1_MPPA_Bit;
    };
    uint32_t reserved3[1];
    union
    {
        __IO uint32_t           PROG2_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG2_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG2_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG2_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG2_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG2_MPPA_Bit;
    };
    uint32_t reserve4[1];
    union
    {
        __IO uint32_t           PROG3_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG3_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG3_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG3_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG3_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG3_MPPA_Bit;
    };
    uint32_t reserved5[1];
    union
    {
        __IO uint32_t           PROG4_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG4_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG4_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG4_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG4_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG4_MPPA_Bit;
    };
    uint32_t reserved6[1];
    union
    {
        __IO uint32_t           PROG5_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG5_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG5_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG5_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG5_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG5_MPPA_Bit;
    };
    uint32_t reserved7[1];
    union
    {
        __IO uint32_t           PROG6_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG6_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG6_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG6_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG6_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG6_MPPA_Bit;
    };

    uint32_t reserved14[1];
    union
    {
        __IO uint32_t           PROG7_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG7_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG7_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG7_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG7_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG7_MPPA_Bit;
    };
    uint32_t reserved8[1];
    union
    {
        __IO uint32_t           PROG8_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG8_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG8_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG8_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG8_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG8_MPPA_Bit;
    };
    uint32_t reserved9[1];
    union
    {
        __IO uint32_t           PROG9_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG9_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG9_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG9_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG9_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG9_MPPA_Bit;
    };
    uint32_t reserved10[1];
    union
    {
        __IO uint32_t           PROG10_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG10_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG10_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG10_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG10_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG10_MPPA_Bit;
    };
    uint32_t reserved11[1];
    union
    {
        __IO uint32_t           PROG11_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG11_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG11_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG11_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG11_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG11_MPPA_Bit;
    };
    uint32_t reserved12[1];
    union
    {
        __IO uint32_t           PROG12_MPSAR;
        MPU_PROGn_MPSAR_TypeDef PROG12_MPSAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG12_MPEAR;
        MPU_PROGn_MPEAR_TypeDef PROG12_MPEAR_Bit;
    };
    union
    {
        __IO uint32_t           PROG12_MPPA;
        MPU_PROGn_MPPA_TypeDef PROG12_MPPA_Bit;
    };
    uint32_t reserved13[17];

    union
    {
        __IO uint32_t       FLTADDRR;
        MPU_FLTADDRR_TypeDef  FLTADDRR_Bit;
    };
    union
    {
        __IO uint32_t       FLTSTAT;
        MPU_FLTSTAT_TypeDef  FLTSTAT_Bit;
    };
    union
    {
        __IO uint32_t       FLTCLR;
        MPU_FLTCLR_TypeDef  FLTCLR_Bit;
    };

}MPU2_TypeDef;


#define MPU1            (((MPU1_TypeDef*)(MPU1_BASE)))
#define MPU1_R(offset)  (*((__IO uint32_t *)(MPU1_BASE+offset)))
#define MPU2            (((MPU2_TypeDef*)(MPU2_BASE)))
#define MPU2_R(offset)  (*((__IO uint32_t *)(MPU2_BASE+offset)))

#define MPU_REVID_OFFSET       ((uint32_t)0x0000)
#define MPU_CONFIG_OFFSET      ((uint32_t)0x0004)
#define MPU_IRAWSTAT_OFFSET    ((uint32_t)0x0010)
#define MPU_IENSTAT_OFFSET     ((uint32_t)0x0014)
#define MPU_IENSET_OFFSET      ((uint32_t)0x0018)
#define MPU_IENCLR_OFFSET      ((uint32_t)0x001C)
#define MPU_FXD_MPSAR_OFFSET   ((uint32_t)0x0100)
#define MPU_FXD_MPEAR_OFFSET   ((uint32_t)0x0104)
#define MPU_FXD_MPPA_OFFSET    ((uint32_t)0x0108)
#define MPU_PROG1_MPSAR_OFFSET ((uint32_t)0x0200)
#define MPU_PROG1_MPEAR_OFFSET ((uint32_t)0x0204)
#define MPU_PROG1_MPPA_OFFSET  ((uint32_t)0x0208)
#define MPU_PROG2_MPSAR_OFFSET ((uint32_t)0x0210)
#define MPU_PROG2_MPEAR_OFFSET ((uint32_t)0x0214)
#define MPU_PROG2_MPPA_OFFSET  ((uint32_t)0x0218)
#define MPU_PROG3_MPSAR_OFFSET ((uint32_t)0x0220)
#define MPU_PROG3_MPEAR_OFFSET ((uint32_t)0x0224)
#define MPU_PROG3_MPPA_OFFSET  ((uint32_t)0x0228)
#define MPU_PROG4_MPSAR_OFFSET ((uint32_t)0x0230)
#define MPU_PROG4_MPEAR_OFFSET ((uint32_t)0x0234)
#define MPU_PROG4_MPPA_OFFSET  ((uint32_t)0x0238)
#define MPU_PROG5_MPSAR_OFFSET ((uint32_t)0x0240)
#define MPU_PROG5_MPEAR_OFFSET ((uint32_t)0x0244)
#define MPU_PROG5_MPPA_OFFSET  ((uint32_t)0x0248)
#define MPU_PROG6_MPSAR_OFFSET ((uint32_t)0x0250)
#define MPU_PROG6_MPEAR_OFFSET ((uint32_t)0x0254)
#define MPU_PROG6_MPPA_OFFSET  ((uint32_t)0x0258)
#define MPU_PROG7_MPSAR_OFFSET ((uint32_t)0x0260)
#define MPU_PROG7_MPEAR_OFFSET ((uint32_t)0x0264)
#define MPU_PROG7_MPPA_OFFSET  ((uint32_t)0x0268)
#define MPU_PROG8_MPSAR_OFFSET ((uint32_t)0x0270)
#define MPU_PROG8_MPEAR_OFFSET ((uint32_t)0x0274)
#define MPU_PROG8_MPPA_OFFSET  ((uint32_t)0x0278)
#define MPU_PROG9_MPSAR_OFFSET ((uint32_t)0x0280)
#define MPU_PROG9_MPEAR_OFFSET ((uint32_t)0x0284)
#define MPU_PROG9_MPPA_OFFSET  ((uint32_t)0x0288)
#define MPU_PROG10_MPSAR_OFFSET ((uint32_t)0x0290)
#define MPU_PROG10_MPEAR_OFFSET ((uint32_t)0x0294)
#define MPU_PROG10_MPPA_OFFSET  ((uint32_t)0x0298)
#define MPU_PROG11_MPSAR_OFFSET ((uint32_t)0x02A0)
#define MPU_PROG11_MPEAR_OFFSET ((uint32_t)0x02A4)
#define MPU_PROG11_MPPA_OFFSET  ((uint32_t)0x02A8)
#define MPU_PROG12_MPSAR_OFFSET ((uint32_t)0x02B0)
#define MPU_PROG12_MPEAR_OFFSET ((uint32_t)0x02B4)
#define MPU_PROG12_MPPA_OFFSET  ((uint32_t)0x02B8)
#define MPU_FLTADDRR_OFFSET     ((uint32_t)0x0300)
#define MPU_FLTSTAT_OFFSET      ((uint32_t)0x0304)
#define MPU_FLTCLR_OFFSET       ((uint32_t)0x0308)


/**********************************************************************************************
************************************** 1 REVID ***********************************************
**********************************************************************************************/
#define MPU1_REVID                    (((MPU_REVID_TypeDef*)(MPU1_BASE+MPU_REVID_OFFSET )))
#define MPU1_REVID_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_REVID_OFFSET)))
#define MPU2_REVID                    (((MPU_REVID_TypeDef*)(MPU2_BASE+MPU_REVID_OFFSET )))
#define MPU2_REVID_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_REVID_OFFSET)))

/*--------*/
#define MPU_REVID_R_REV_MASK        ((uint32_t)0xFFFFFFFF)
#define MPU_REVID_R_REV_SHIFT         (0)

#define MPU_REVID_REV_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 1 CONFIG ***********************************************
**********************************************************************************************/
#define MPU1_CONFIG                    (((MPU_CONFIG_TypeDef*)(MPU1_BASE+MPU_CONFIG_OFFSET )))
#define MPU1_CONFIG_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_CONFIG_OFFSET)))
#define MPU2_CONFIG                    (((MPU_CONFIG_TypeDef*)(MPU2_BASE+MPU_CONFIG_OFFSET )))
#define MPU2_CONFIG_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_CONFIG_OFFSET)))

/*--------*/
#define MPU_CONFIG_R_ASSUME_ALLOWED_MASK        ((uint32_t)0x00000001)
#define MPU_CONFIG_R_ASSUME_ALLOWED_SHIFT         (0)

#define MPU_CONFIG_ASSUME_ALLOWED_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_CONFIG_R_NUM_AIDS_MASK        ((uint32_t)0x0000F000)
#define MPU_CONFIG_R_NUM_AIDS_SHIFT         (12)

#define MPU_CONFIG_NUM_AIDS_MASK          ((uint32_t)0x0000000F)
/*--------*/
/*--------*/
#define MPU_CONFIG_R_NUM_PROG_MASK        ((uint32_t)0x000F0000)
#define MPU_CONFIG_R_NUM_PROG_SHIFT         (16)

#define MPU_CONFIG_NUM_PROG_MASK          ((uint32_t)0x0000000F)
/*--------*/
/*--------*/
#define MPU_CONFIG_R_NUM_FIXED_MASK        ((uint32_t)0x00F00000)
#define MPU_CONFIG_R_NUM_FIXED_SHIFT         (20)

#define MPU_CONFIG_NUM_FIXED_MASK          ((uint32_t)0x0000000F)
/*--------*/
/*--------*/
#define MPU_CONFIG_R_ADDR_WIDTH_MASK        ((uint32_t)0xFF000000)
#define MPU_CONFIG_R_ADDR_WIDTH_SHIFT         (24)

#define MPU_CONFIG_ADDR_WIDTH_MASK          ((uint32_t)0x0000000F)
/*--------*/


/**********************************************************************************************
************************************** 1 IRAWSTAT ***********************************************
**********************************************************************************************/
#define MPU1_IRAWSTAT                    (((MPU_IRAWSTAT_TypeDef*)(MPU1_BASE+MPU_IRAWSTAT_OFFSET )))
#define MPU1_IRAWSTAT_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_IRAWSTAT_OFFSET)))
#define MPU2_IRAWSTAT                    (((MPU_IRAWSTAT_TypeDef*)(MPU2_BASE+MPU_IRAWSTAT_OFFSET )))
#define MPU2_IRAWSTAT_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_IRAWSTAT_OFFSET)))

/*--------*/
#define MPU_IRAWSTAT_R_PROTERR_MASK        ((uint32_t)0x00000001)
#define MPU_IRAWSTAT_R_PROTERR_SHIFT         (0)

#define MPU_IRAWSTAT_PROTERR_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_IRAWSTAT_R_ADDRERR_MASK        ((uint32_t)0x00000002)
#define MPU_IRAWSTAT_R_ADDRERR_SHIFT         (1)

#define MPU_IRAWSTAT_ADDRERR_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 1 IENSTAT ***********************************************
**********************************************************************************************/
#define MPU1_IENSTAT                    (((MPU_IENSTAT_TypeDef*)(MPU1_BASE+MPU_IENSTAT_OFFSET )))
#define MPU1_IENSTAT_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_IENSTAT_OFFSET)))
#define MPU2_IENSTAT                    (((MPU_IENSTAT_TypeDef*)(MPU2_BASE+MPU_IENSTAT_OFFSET )))
#define MPU2_IENSTAT_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_IENSTAT_OFFSET)))

/*--------*/
#define MPU_IENSTAT_R_PROTERR_MASK        ((uint32_t)0x00000001)
#define MPU_IENSTAT_R_PROTERR_SHIFT         (0)

#define MPU_IENSTAT_PROTERR_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_IENSTAT_R_ADDRERR_MASK        ((uint32_t)0x00000002)
#define MPU_IENSTAT_R_ADDRERR_SHIFT         (1)

#define MPU_IENSTAT_ADDRERR_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 1 IENSET ***********************************************
**********************************************************************************************/
#define MPU1_IENSET                    (((MPU_IENSET_TypeDef*)(MPU1_BASE+MPU_IENSET_OFFSET )))
#define MPU1_IENSET_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_IENSET_OFFSET)))
#define MPU2_IENSET                    (((MPU_IENSET_TypeDef*)(MPU2_BASE+MPU_IENSET_OFFSET )))
#define MPU2_IENSET_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_IENSET_OFFSET)))

/*--------*/
#define MPU_IENSET_R_PROTERR_EN_MASK        ((uint32_t)0x00000001)
#define MPU_IENSET_R_PROTERR_EN_SHIFT         (0)

#define MPU_IENSET_PROTERR_EN_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_IENSET_R_ADDRERR_EN_MASK        ((uint32_t)0x00000002)
#define MPU_IENSET_R_ADDRERR_EN_SHIFT         (1)

#define MPU_IENSET_ADDRERR_EN_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 1 IENCLR ***********************************************
**********************************************************************************************/
#define MPU1_IENCLR                    (((MPU_IENCLR_TypeDef*)(MPU1_BASE+MPU_IENCLR_OFFSET )))
#define MPU1_IENCLR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_IENCLR_OFFSET)))
#define MPU2_IENCLR                    (((MPU_IENCLR_TypeDef*)(MPU2_BASE+MPU_IENCLR_OFFSET )))
#define MPU2_IENCLR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_IENCLR_OFFSET)))

/*--------*/
#define MPU_IENCLR_R_PROTERR_CLR_MASK        ((uint32_t)0x00000001)
#define MPU_IENCLR_R_PROTERR_CLR_SHIFT         (0)

#define MPU_IENCLR_PROTERR_CLR_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_IENCLR_R_ADDRERR_CLR_MASK        ((uint32_t)0x00000002)
#define MPU_IENCLR_R_ADDRERR_CLR_SHIFT         (1)

#define MPU_IENCLR_ADDRERR_CLR_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 1 MPSAR ***********************************************
**********************************************************************************************/
#define MPU2_FXD_MPSAR                    (((MPU_FXD_MPSAR_TypeDef*)(MPU2_BASE+MPU_FXD_MPSAR_OFFSET )))
#define MPU2_FXD_MPSAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_FXD_MPSAR_OFFSET)))

#define MPU1_PROG1_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU1_BASE+MPU_PROG1_MPSAR_OFFSET )))
#define MPU1_PROG1_MPSAR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG1_MPSAR_OFFSET)))
#define MPU1_PROG2_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU1_BASE+MPU_PROG2_MPSAR_OFFSET )))
#define MPU1_PROG2_MPSAR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG2_MPSAR_OFFSET)))
#define MPU1_PROG3_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU1_BASE+MPU_PROG3_MPSAR_OFFSET )))
#define MPU1_PROG3_MPSAR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG3_MPSAR_OFFSET)))
#define MPU1_PROG4_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU1_BASE+MPU_PROG4_MPSAR_OFFSET )))
#define MPU1_PROG4_MPSAR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG4_MPSAR_OFFSET)))
#define MPU1_PROG5_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU1_BASE+MPU_PROG5_MPSAR_OFFSET )))
#define MPU1_PROG5_MPSAR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG5_MPSAR_OFFSET)))
#define MPU1_PROG6_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU1_BASE+MPU_PROG6_MPSAR_OFFSET )))
#define MPU1_PROG6_MPSAR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG6_MPSAR_OFFSET)))
#define MPU1_PROG_MPSAR(n)                   (((MPU_PROGn_MPSAR_TypeDef*)(MPU1_BASE+MPU1_PROG0_MPSAR_OFFSET +((n)*4*4) )))
#define MPU1_PROG_MPSAR_R(n)                 (*((__IO uint32_t *)(MPU1_BASE+MPU1_PROG0_MPSAR_OFFSET +((n)*4*4))))

#define MPU2_PROG1_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU2_BASE+MPU_PROG1_MPSAR_OFFSET )))
#define MPU2_PROG1_MPSAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG1_MPSAR_OFFSET)))
#define MPU2_PROG2_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU2_BASE+MPU_PROG2_MPSAR_OFFSET )))
#define MPU2_PROG2_MPSAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG2_MPSAR_OFFSET)))
#define MPU2_PROG3_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU2_BASE+MPU_PROG3_MPSAR_OFFSET )))
#define MPU2_PROG3_MPSAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG3_MPSAR_OFFSET)))
#define MPU2_PROG4_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU2_BASE+MPU_PROG4_MPSAR_OFFSET )))
#define MPU2_PROG4_MPSAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG4_MPSAR_OFFSET)))
#define MPU2_PROG5_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU2_BASE+MPU_PROG5_MPSAR_OFFSET )))
#define MPU2_PROG5_MPSAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG5_MPSAR_OFFSET)))
#define MPU2_PROG6_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU2_BASE+MPU_PROG6_MPSAR_OFFSET )))
#define MPU2_PROG6_MPSAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG6_MPSAR_OFFSET)))
#define MPU2_PROG7_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU2_BASE+MPU_PROG7_MPSAR_OFFSET )))
#define MPU2_PROG7_MPSAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG7_MPSAR_OFFSET)))
#define MPU2_PROG8_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU2_BASE+MPU_PROG8_MPSAR_OFFSET )))
#define MPU2_PROG8_MPSAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG8_MPSAR_OFFSET)))
#define MPU2_PROG9_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU2_BASE+MPU_PROG9_MPSAR_OFFSET )))
#define MPU2_PROG9_MPSAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG9_MPSAR_OFFSET)))
#define MPU2_PROG10_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU2_BASE+MPU_PROG10_MPSAR_OFFSET )))
#define MPU2_PROG10_MPSAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG10_MPSAR_OFFSET)))
#define MPU2_PROG11_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU2_BASE+MPU_PROG11_MPSAR_OFFSET )))
#define MPU2_PROG11_MPSAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG11_MPSAR_OFFSET)))
#define MPU2_PROG12_MPSAR                    (((MPU_PROGn_MPSAR_TypeDef*)(MPU2_BASE+MPU_PROG12_MPSAR_OFFSET )))
#define MPU2_PROG12_MPSAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG12_MPSAR_OFFSET)))
#define MPU2_PROG_MPSAR(n)                   (((MPU_PROGn_MPSAR_TypeDef*)(MPU2_BASE+MPU2_PROG0_MPSAR_OFFSET +((n)*4*4) )))
#define MPU2_PROG_MPSAR_R(n)                 (*((__IO uint32_t *)(MPU2_BASE+MPU2_PROG0_MPSAR_OFFSET +((n)*4*4))))

/*--------*/
#define MPU1_GROUP_MPSAR_R_START_ADDR_MASK        ((uint32_t)0xFFFFFC00)
#define MPU1_GROUP_MPSAR_R_START_ADDR_SHIFT         (10)

#define MPU1_GROUP_MPSAR_START_ADDR_MASK          ((uint32_t)0x003FFFFF)
/*--------*/

/*--------*/
#define MPU2_GROUP_MPSAR_R_START_ADDR_MASK        ((uint32_t)0xFFFF0000)
#define MPU2_GROUP_MPSAR_R_START_ADDR_SHIFT         (16)

#define MPU2_GROUP_MPSAR_START_ADDR_MASK          ((uint32_t)0x0000FFFF)
/*--------*/



/**********************************************************************************************
************************************** 1 MPEAR ***********************************************
**********************************************************************************************/
#define MPU2_FXD_MPEAR                    (((MPU_FXD_MPEAR_TypeDef*)(MPU2_BASE+MPU_FXD_MPEAR_OFFSET )))
#define MPU2_FXD_MPEAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_FXD_MPEAR_OFFSET)))

#define MPU1_PROG1_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU1_BASE+MPU_PROG1_MPEAR_OFFSET )))
#define MPU1_PROG1_MPEAR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG1_MPEAR_OFFSET)))
#define MPU1_PROG2_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU1_BASE+MPU_PROG2_MPEAR_OFFSET )))
#define MPU1_PROG2_MPEAR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG2_MPEAR_OFFSET)))
#define MPU1_PROG3_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU1_BASE+MPU_PROG3_MPEAR_OFFSET )))
#define MPU1_PROG3_MPEAR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG3_MPEAR_OFFSET)))
#define MPU1_PROG4_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU1_BASE+MPU_PROG4_MPEAR_OFFSET )))
#define MPU1_PROG4_MPEAR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG4_MPEAR_OFFSET)))
#define MPU1_PROG5_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU1_BASE+MPU_PROG5_MPEAR_OFFSET )))
#define MPU1_PROG5_MPEAR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG5_MPEAR_OFFSET)))
#define MPU1_PROG6_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU1_BASE+MPU_PROG6_MPEAR_OFFSET )))
#define MPU1_PROG6_MPEAR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG6_MPEAR_OFFSET)))
#define MPU1_PROG_MPEAR(n)                   (((MPU_PROGn_MPEAR_TypeDef*)(MPU1_BASE+MPU1_PROG0_MPEAR_OFFSET +((n)*4*4) )))
#define MPU1_PROG_MPEAR_R(n)                 (*((__IO uint32_t *)(MPU1_BASE+MPU1_PROG0_MPEAR_OFFSET +((n)*4*4))))

#define MPU2_PROG1_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU2_BASE+MPU_PROG1_MPEAR_OFFSET )))
#define MPU2_PROG1_MPEAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG1_MPEAR_OFFSET)))
#define MPU2_PROG2_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU2_BASE+MPU_PROG2_MPEAR_OFFSET )))
#define MPU2_PROG2_MPEAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG2_MPEAR_OFFSET)))
#define MPU2_PROG3_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU2_BASE+MPU_PROG3_MPEAR_OFFSET )))
#define MPU2_PROG3_MPEAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG3_MPEAR_OFFSET)))
#define MPU2_PROG4_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU2_BASE+MPU_PROG4_MPEAR_OFFSET )))
#define MPU2_PROG4_MPEAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG4_MPEAR_OFFSET)))
#define MPU2_PROG5_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU2_BASE+MPU_PROG5_MPEAR_OFFSET )))
#define MPU2_PROG5_MPEAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG5_MPEAR_OFFSET)))
#define MPU2_PROG6_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU2_BASE+MPU_PROG6_MPEAR_OFFSET )))
#define MPU2_PROG6_MPEAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG6_MPEAR_OFFSET)))
#define MPU2_PROG7_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU2_BASE+MPU_PROG7_MPEAR_OFFSET )))
#define MPU2_PROG7_MPEAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG7_MPEAR_OFFSET)))
#define MPU2_PROG8_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU2_BASE+MPU_PROG8_MPEAR_OFFSET )))
#define MPU2_PROG8_MPEAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG8_MPEAR_OFFSET)))
#define MPU2_PROG9_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU2_BASE+MPU_PROG9_MPEAR_OFFSET )))
#define MPU2_PROG9_MPEAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG9_MPEAR_OFFSET)))
#define MPU2_PROG10_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU2_BASE+MPU_PROG10_MPEAR_OFFSET )))
#define MPU2_PROG10_MPEAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG10_MPEAR_OFFSET)))
#define MPU2_PROG11_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU2_BASE+MPU_PROG11_MPEAR_OFFSET )))
#define MPU2_PROG11_MPEAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG11_MPEAR_OFFSET)))
#define MPU2_PROG12_MPEAR                    (((MPU_PROGn_MPEAR_TypeDef*)(MPU2_BASE+MPU_PROG12_MPEAR_OFFSET )))
#define MPU2_PROG12_MPEAR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG12_MPEAR_OFFSET)))
#define MPU2_PROG_MPEAR(n)                   (((MPU_PROGn_MPEAR_TypeDef*)(MPU2_BASE+MPU2_PROG0_MPEAR_OFFSET +((n)*4*4) )))
#define MPU2_PROG_MPEAR_R(n)                 (*((__IO uint32_t *)(MPU2_BASE+MPU2_PROG0_MPEAR_OFFSET +((n)*4*4))))

/*--------*/
#define MPU1_GROUP_MPEAR_R_END_ADDR_MASK        ((uint32_t)0xFFFFFC00)
#define MPU1_GROUP_MPEAR_R_END_ADDR_SHIFT         (10)

#define MPU1_GROUP_MPEAR_END_ADDR_MASK          ((uint32_t)0x003FFFFF)
/*--------*/

/*--------*/
#define MPU2_GROUP_MPEAR_R_END_ADDR_MASK        ((uint32_t)0xFFFF0000)
#define MPU2_GROUP_MPEAR_R_END_ADDR_SHIFT         (16)

#define MPU2_GROUP_MPEAR_END_ADDR_MASK          ((uint32_t)0x0000FFFF)
/*--------*/

/**********************************************************************************************
************************************** 1 MPPA ***********************************************
**********************************************************************************************/
#define MPU2_FXD_MPPA                    (((MPU_FXD_MPPA_TypeDef*)(MPU2_BASE+MPU_FXD_MPPA_OFFSET )))
#define MPU2_FXD_MPPA_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_FXD_MPPA_OFFSET)))

#define MPU1_PROG1_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU1_BASE+MPU_PROG1_MPPA_OFFSET )))
#define MPU1_PROG1_MPPA_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG1_MPPA_OFFSET)))
#define MPU1_PROG2_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU1_BASE+MPU_PROG2_MPPA_OFFSET )))
#define MPU1_PROG2_MPPA_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG2_MPPA_OFFSET)))
#define MPU1_PROG3_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU1_BASE+MPU_PROG3_MPPA_OFFSET )))
#define MPU1_PROG3_MPPA_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG3_MPPA_OFFSET)))
#define MPU1_PROG4_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU1_BASE+MPU_PROG4_MPPA_OFFSET )))
#define MPU1_PROG4_MPPA_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG4_MPPA_OFFSET)))
#define MPU1_PROG5_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU1_BASE+MPU_PROG5_MPPA_OFFSET )))
#define MPU1_PROG5_MPPA_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG5_MPPA_OFFSET)))
#define MPU1_PROG6_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU1_BASE+MPU_PROG6_MPPA_OFFSET )))
#define MPU1_PROG6_MPPA_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG6_MPPA_OFFSET)))
#define MPU1_PROG_MPPA(n)                   (((MPU_PROGn_MPPA_TypeDef*)(MPU1_BASE+MPU_PROG1_MPPA_OFFSET +((n)*4*4) )))
#define MPU1_PROG_MPPA_R(n)                 (*((__IO uint32_t *)(MPU1_BASE+MPU_PROG1_MPPA_OFFSET +((n)*4*4))))

#define MPU2_PROG1_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU2_BASE+MPU_PROG1_MPPA_OFFSET )))
#define MPU2_PROG1_MPPA_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG1_MPPA_OFFSET)))
#define MPU2_PROG2_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU2_BASE+MPU_PROG2_MPPA_OFFSET )))
#define MPU2_PROG2_MPPA_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG2_MPPA_OFFSET)))
#define MPU2_PROG3_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU2_BASE+MPU_PROG3_MPPA_OFFSET )))
#define MPU2_PROG3_MPPA_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG3_MPPA_OFFSET)))
#define MPU2_PROG4_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU2_BASE+MPU_PROG4_MPPA_OFFSET )))
#define MPU2_PROG4_MPPA_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG4_MPPA_OFFSET)))
#define MPU2_PROG5_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU2_BASE+MPU_PROG5_MPPA_OFFSET )))
#define MPU2_PROG5_MPPA_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG5_MPPA_OFFSET)))
#define MPU2_PROG6_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU2_BASE+MPU_PROG6_MPPA_OFFSET )))
#define MPU2_PROG6_MPPA_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG6_MPPA_OFFSET)))
#define MPU2_PROG7_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU2_BASE+MPU_PROG7_MPPA_OFFSET )))
#define MPU2_PROG7_MPPA_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG7_MPPA_OFFSET)))
#define MPU2_PROG8_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU2_BASE+MPU_PROG8_MPPA_OFFSET )))
#define MPU2_PROG8_MPPA_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG8_MPPA_OFFSET)))
#define MPU2_PROG9_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU2_BASE+MPU_PROG9_MPPA_OFFSET )))
#define MPU2_PROG9_MPPA_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG9_MPPA_OFFSET)))
#define MPU2_PROG10_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU2_BASE+MPU_PROG10_MPPA_OFFSET )))
#define MPU2_PROG10_MPPA_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG10_MPPA_OFFSET)))
#define MPU2_PROG11_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU2_BASE+MPU_PROG11_MPPA_OFFSET )))
#define MPU2_PROG11_MPPA_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG11_MPPA_OFFSET)))
#define MPU2_PROG12_MPPA                    (((MPU_PROGn_MPPA_TypeDef*)(MPU2_BASE+MPU_PROG12_MPPA_OFFSET )))
#define MPU2_PROG12_MPPA_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG12_MPPA_OFFSET)))
#define MPU2_PROG_MPPA(n)                   (((MPU_PROGn_MPPA_TypeDef*)(MPU2_BASE+MPU_PROG1_MPPA_OFFSET +((n)*4*4) )))
#define MPU2_PROG_MPPA_R(n)                 (*((__IO uint32_t *)(MPU2_BASE+MPU_PROG1_MPPA_OFFSET +((n)*4*4))))

/*--------*/
#define MPU_FXD_MPPA_R_UX_MASK        ((uint32_t)0x00000001)
#define MPU_FXD_MPPA_R_UX_SHIFT         (0)

#define MPU_FXD_MPPA_UX_MASK          ((uint32_t)0x00000001)
/*--------*/
/*-------*/
#define MPU_FXD_MPPA_R_UW_MASK        ((uint32_t)0x00000002)
#define MPU_FXD_MPPA_R_UW_SHIFT         (1)

#define MPU_FXD_MPPA_UW_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_UR_MASK        ((uint32_t)0x00000004)
#define MPU_FXD_MPPA_R_UR_SHIFT         (2)

#define MPU_FXD_MPPA_UR_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_SX_MASK        ((uint32_t)0x00000008)
#define MPU_FXD_MPPA_R_SX_SHIFT         (3)

#define MPU_FXD_MPPA_SX_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_SW_MASK        ((uint32_t)0x00000010)
#define MPU_FXD_MPPA_R_SW_SHIFT         (4)

#define MPU_FXD_MPPA_SW_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_SR_MASK        ((uint32_t)0x00000020)
#define MPU_FXD_MPPA_R_SR_SHIFT         (5)

#define MPU_FXD_MPPA_SR_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_AIDX_MASK        ((uint32_t)0x00000200)
#define MPU_FXD_MPPA_R_AIDX_SHIFT         (9)

#define MPU_FXD_MPPA_AIDX_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_AID0_MASK        ((uint32_t)0x00000400)
#define MPU_FXD_MPPA_R_AID0_SHIFT         (10)

#define MPU_FXD_MPPA_AID0_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_AID1_MASK        ((uint32_t)0x00000800)
#define MPU_FXD_MPPA_R_AID1_SHIFT         (11)

#define MPU_FXD_MPPA_AID1_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_AID2_MASK        ((uint32_t)0x00001000)
#define MPU_FXD_MPPA_R_AID2_SHIFT         (12)

#define MPU_FXD_MPPA_AID2_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_AID3_MASK        ((uint32_t)0x00002000)
#define MPU_FXD_MPPA_R_AID3_SHIFT         (13)

#define MPU_FXD_MPPA_AID3_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_AID4_MASK        ((uint32_t)0x00004000)
#define MPU_FXD_MPPA_R_AID4_SHIFT         (14)

#define MPU_FXD_MPPA_AID4_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_AID5_MASK        ((uint32_t)0x00008000)
#define MPU_FXD_MPPA_R_AID5_SHIFT         (15)

#define MPU_FXD_MPPA_AID5_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_AID6_MASK        ((uint32_t)0x00010000)
#define MPU_FXD_MPPA_R_AID6_SHIFT         (16)

#define MPU_FXD_MPPA_AID6_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_AID7_MASK        ((uint32_t)0x00020000)
#define MPU_FXD_MPPA_R_AID7_SHIFT         (17)

#define MPU_FXD_MPPA_AID7_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_AID8_MASK        ((uint32_t)0x00040000)
#define MPU_FXD_MPPA_R_AID8_SHIFT         (18)

#define MPU_FXD_MPPA_AID8_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_AID9_MASK        ((uint32_t)0x00080000)
#define MPU_FXD_MPPA_R_AID9_SHIFT         (19)

#define MPU_FXD_MPPA_AID9_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_AID10_MASK        ((uint32_t)0x00100000)
#define MPU_FXD_MPPA_R_AID10_SHIFT         (20)

#define MPU_FXD_MPPA_AID10_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_FXD_MPPA_R_AID11_MASK        ((uint32_t)0x00200000)
#define MPU_FXD_MPPA_R_AID11_SHIFT         (21)

#define MPU_FXD_MPPA_AID11_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_UX_MASK        ((uint32_t)0x00000001)
#define MPU_PROG_MPPA_R_UX_SHIFT         (0)

#define MPU_PROG_MPPA_UX_MASK          ((uint32_t)0x00000001)
/*--------*/
/*-------*/
#define MPU_PROG_MPPA_R_UW_MASK        ((uint32_t)0x00000002)
#define MPU_PROG_MPPA_R_UW_SHIFT         (1)

#define MPU_PROG_MPPA_UW_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_UR_MASK        ((uint32_t)0x00000004)
#define MPU_PROG_MPPA_R_UR_SHIFT         (2)

#define MPU_PROG_MPPA_UR_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_SX_MASK        ((uint32_t)0x00000008)
#define MPU_PROG_MPPA_R_SX_SHIFT         (3)

#define MPU_PROG_MPPA_SX_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_SW_MASK        ((uint32_t)0x00000010)
#define MPU_PROG_MPPA_R_SW_SHIFT         (4)

#define MPU_PROG_MPPA_SW_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_SR_MASK        ((uint32_t)0x00000020)
#define MPU_PROG_MPPA_R_SR_SHIFT         (5)

#define MPU_PROG_MPPA_SR_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_AIDX_MASK        ((uint32_t)0x00000200)
#define MPU_PROG_MPPA_R_AIDX_SHIFT         (9)

#define MPU_PROG_MPPA_AIDX_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_AID0_MASK        ((uint32_t)0x00000400)
#define MPU_PROG_MPPA_R_AID0_SHIFT         (10)

#define MPU_PROG_MPPA_AID0_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_AID1_MASK        ((uint32_t)0x00000800)
#define MPU_PROG_MPPA_R_AID1_SHIFT         (11)

#define MPU_PROG_MPPA_AID1_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_AID2_MASK        ((uint32_t)0x00001000)
#define MPU_PROG_MPPA_R_AID2_SHIFT         (12)

#define MPU_PROG_MPPA_AID2_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_AID3_MASK        ((uint32_t)0x00002000)
#define MPU_PROG_MPPA_R_AID3_SHIFT         (13)

#define MPU_PROG_MPPA_AID3_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_AID4_MASK        ((uint32_t)0x00004000)
#define MPU_PROG_MPPA_R_AID4_SHIFT         (14)

#define MPU_PROG_MPPA_AID4_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_AID5_MASK        ((uint32_t)0x00008000)
#define MPU_PROG_MPPA_R_AID5_SHIFT         (15)

#define MPU_PROG_MPPA_AID5_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_AID6_MASK        ((uint32_t)0x00010000)
#define MPU_PROG_MPPA_R_AID6_SHIFT         (16)

#define MPU_PROG_MPPA_AID6_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_AID7_MASK        ((uint32_t)0x00020000)
#define MPU_PROG_MPPA_R_AID7_SHIFT         (17)

#define MPU_PROG_MPPA_AID7_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_AID8_MASK        ((uint32_t)0x00040000)
#define MPU_PROG_MPPA_R_AID8_SHIFT         (18)

#define MPU_PROG_MPPA_AID8_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_AID9_MASK        ((uint32_t)0x00080000)
#define MPU_PROG_MPPA_R_AID9_SHIFT         (19)

#define MPU_PROG_MPPA_AID9_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_AID10_MASK        ((uint32_t)0x00100000)
#define MPU_PROG_MPPA_R_AID10_SHIFT         (20)

#define MPU_PROG_MPPA_AID10_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define MPU_PROG_MPPA_R_AID11_MASK        ((uint32_t)0x00200000)
#define MPU_PROG_MPPA_R_AID11_SHIFT         (21)

#define MPU_PROG_MPPA_AID11_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 1 FLTADDRR ***********************************************
**********************************************************************************************/
#define MPU1_FLTADDRR                    (((MPU_FLTADDRR_TypeDef*)(MPU1_BASE+MPU_FLTADDRR_OFFSET )))
#define MPU1_FLTADDRR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_FLTADDRR_OFFSET)))
#define MPU2_FLTADDRR                    (((MPU_FLTADDRR_TypeDef*)(MPU2_BASE+MPU_FLTADDRR_OFFSET )))
#define MPU2_FLTADDRR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_FLTADDRR_OFFSET)))

/*--------*/
#define MPU_FLTADDRR_R_FLTADDR_MASK        ((uint32_t)0xFFFFFFFF)
#define MPU_FLTADDRR_R_FLTADDR_SHIFT         (0)

#define MPU_FLTADDRR_FLTADDR_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 1 FLTSTAT ***********************************************
**********************************************************************************************/
#define MPU1_FLTSTAT                    (((MPU_FLTSTAT_TypeDef*)(MPU1_BASE+MPU_FLTSTAT_OFFSET )))
#define MPU1_FLTSTAT_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_FLTSTAT_OFFSET)))
#define MPU2_FLTSTAT                    (((MPU_FLTSTAT_TypeDef*)(MPU2_BASE+MPU_FLTSTAT_OFFSET )))
#define MPU2_FLTSTAT_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_FLTSTAT_OFFSET)))

/*--------*/
#define MPU_FLTSTAT_R_TYPE_MASK        ((uint32_t)0x0000003F)
#define MPU_FLTSTAT_R_TYPE_SHIFT         (0)

#define MPU_FLTSTAT_TYPE_MASK          ((uint32_t)0x0000003F)
/*--------*/

/*--------*/
#define MPU_FLTSTAT_R_PRIVID_MASK        ((uint32_t)0x00001E00)
#define MPU_FLTSTAT_R_PRIVID_SHIFT         (9)

#define MPU_FLTSTAT_PRIVID_MASK          ((uint32_t)0x0000000F)
/*--------*/

/*--------*/
#define MPU_FLTSTAT_R_MSTID_MASK        ((uint32_t)0x00FF0000)
#define MPU_FLTSTAT_R_MSTID_SHIFT         (16)

#define MPU_FLTSTAT_MSTID_MASK          ((uint32_t)0x000000FF)
/*--------*/

/**********************************************************************************************
************************************** 1 FLTCLR ***********************************************
**********************************************************************************************/
#define MPU1_FLTCLR                    (((MPU_FLTCLR_TypeDef*)(MPU1_BASE+MPU_FLTCLR_OFFSET )))
#define MPU1_FLTCLR_R                  (*((__IO uint32_t *)(MPU1_BASE+MPU_FLTCLR_OFFSET)))
#define MPU2_FLTCLR                    (((MPU_FLTCLR_TypeDef*)(MPU2_BASE+MPU_FLTCLR_OFFSET )))
#define MPU2_FLTCLR_R                  (*((__IO uint32_t *)(MPU2_BASE+MPU_FLTCLR_OFFSET)))

/*--------*/
#define MPU_FLTCLR_R_CLEAR_MASK        ((uint32_t)0x00000001)
#define MPU_FLTCLR_R_CLEAR_SHIFT         (0)

#define MPU_FLTCLR_CLEAR_MASK          ((uint32_t)0x00000001)
/*--------*/

#endif /* INCLUDE_MPU_H_ */
