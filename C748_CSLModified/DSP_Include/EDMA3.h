/*
 * EDMA3.h
 *
 *  Created on: 19/07/2019
 *      Author: Lalo
 */

#ifndef DSP_INCLUDE_EDMA3_H_
#define DSP_INCLUDE_EDMA3_H_

#include "Core.h"
#include <stdint.h>

#define EDMA3_0_CC0_BASE            ((uint32_t)0x01C00000)
#define EDMA3_0_CC0_GLOBAL_BASE     ((uint32_t)0x01C00000)
#define EDMA3_0_CC0_ERROR_BASE      ((uint32_t)0x01C00000+0x0300)
#define EDMA3_0_CC0_ENABLE_BASE     ((uint32_t)0x01C00000+0x0340)
#define EDMA3_0_CC0_STATUS_BASE     ((uint32_t)0x01C00000+0x0400)
#define EDMA3_0_CC0_DMA_CHANNEL_BASE    ((uint32_t)0x01C00000+0x1000)
#define EDMA3_0_CC0_INTERRUPT_BASE      ((uint32_t)0x01C00000+0x1050)
#define EDMA3_0_CC0_QDMA_CHANNEL_BASE   ((uint32_t)0x01C00000+0x1080)
#define EDMA3_0_CC0_SHADOW0_BASE         ((uint32_t)0x01C00000+0x2000)
#define EDMA3_0_CC0_SHADOW1_BASE         ((uint32_t)0x01C00000+0x2200)
#define EDMA3_0_CC0_PaRAM_BASE          ((uint32_t)0x01C04000)

#define EDMA3_0_TC0_BASE                ((uint32_t)0x01C08000)
#define EDMA3_0_TC1_BASE                ((uint32_t)0x01C08400)

#define EDMA3_1_CC0_BASE            ((uint32_t)0x01E30000)
#define EDMA3_1_CC0_GLOBAL_BASE     ((uint32_t)0x01E30000)
#define EDMA3_1_CC0_ERROR_BASE      ((uint32_t)0x01E30000+0x0300)
#define EDMA3_1_CC0_ENABLE_BASE     ((uint32_t)0x01E30000+0x0340)
#define EDMA3_1_CC0_STATUS_BASE     ((uint32_t)0x01E30000+0x0400)
#define EDMA3_1_CC0_DMA_CHANNEL_BASE    ((uint32_t)0x01E30000+0x1000)
#define EDMA3_1_CC0_INTERRUPT_BASE      ((uint32_t)0x01E30000+0x1050)
#define EDMA3_1_CC0_QDMA_CHANNEL_BASE   ((uint32_t)0x01E30000+0x1080)
#define EDMA3_1_CC0_SHADOW0_BASE         ((uint32_t)0x01E30000+0x2000)
#define EDMA3_1_CC0_SHADOW1_BASE         ((uint32_t)0x01E30000+0x2200)
#define EDMA3_1_CC0_PaRAM_BASE          ((uint32_t)0x01E34000)

#define EDMA3_1_TC0_BASE                ((uint32_t)0x01E38000)



typedef __IO struct
{
    __IO uint32_t SAM           :1;
    __IO uint32_t DAM           :1;
    __IO uint32_t SYNCDIM       :1;
    __IO uint32_t STATIC        :1;
         uint32_t reserved0     :4;
    __IO uint32_t FWID          :3;
    __IO uint32_t TCCMOD        :1;
    __IO uint32_t TCC           :6;
         uint32_t reserved1     :2;
    __IO uint32_t TCINTEN       :1;
    __IO uint32_t ITCINTEN      :1;
    __IO uint32_t TCCHEN      :1;
    __IO uint32_t ITCCHEN       :1;
    __IO uint32_t PRIVID        :4;
         uint32_t reserved2     :4;
}EDMA3_PARAM_OPT_TypeDef;

typedef __IO struct
{
    __IO uint32_t SRC           :32;
}EDMA3_PARAM_SRC_TypeDef;

typedef __IO struct
{
    __IO uint32_t ACNT           :16;
    __IO uint32_t BCNT           :16;
}EDMA3_PARAM_A_B_CNT_TypeDef;

typedef __IO struct
{
    __IO uint32_t SRC           :32;
}EDMA3_PARAM_DST_TypeDef;

typedef __IO struct
{
    __IO uint32_t SRCBIDX           :16;
    __IO uint32_t DSTBIDX           :16;
}EDMA3_PARAM_SRC_DST_BIDX_TypeDef;

typedef __IO struct
{
    __IO uint32_t LINK           :16;
    __IO uint32_t BCNTRLD           :16;
}EDMA3_PARAM_LINK_BCNTRLD_TypeDef;

typedef __IO struct
{
    __IO uint32_t SRCCIDX           :16;
    __IO uint32_t DSTCIDX           :16;
}EDMA3_PARAM_SRC_DST_CIDX_TypeDef;

typedef __IO struct
{
    __IO uint32_t CCNT              :16;
         uint32_t reserved0           :16;
}EDMA3_PARAM_CCNT_TypeDef;

typedef struct  {
    union
    {
        __IO uint32_t                   OPT;
        EDMA3_PARAM_OPT_TypeDef         OPT_Bit;
    };
    union
    {
        __IO uint32_t                   SRC;
        EDMA3_PARAM_SRC_TypeDef         SRC_Bit;
    };
    union
    {
        __IO uint32_t                   A_B_CNT;
        EDMA3_PARAM_A_B_CNT_TypeDef     A_B_CNT_Bit;
    };
    union
    {
        __IO uint32_t                   DST;
        EDMA3_PARAM_DST_TypeDef         DST_Bit;
    };
    union
    {
        __IO uint32_t                       SRC_DST_BIDX;
        EDMA3_PARAM_SRC_DST_BIDX_TypeDef    SRC_DST_BIDX_Bit;
    };
    union
    {
        __IO uint32_t                       LINK_BCNTRLD;
        EDMA3_PARAM_LINK_BCNTRLD_TypeDef    LINK_BCNTRLD_Bit;
    };
    union
    {
        __IO uint32_t                       SRC_DST_CIDX;
        EDMA3_PARAM_SRC_DST_CIDX_TypeDef    SRC_DST_CIDX_Bit;
    };
    union
    {
        __IO uint32_t           CCNT;
        EDMA3_PARAM_CCNT_TypeDef       CCNT_Bit;
    };
} EDMA3_CC_PARAM_TypeDef;


typedef struct  {

    EDMA3_CC_PARAM_TypeDef       PaRAM[128];
} EDMA3_CC_PARAM_ARRAY_TypeDef;


typedef __IO struct
{
    __I uint32_t REV       :32;
}EDMA3_CC_REVID_TypeDef;

typedef __IO struct
{
    __IO uint32_t NUM_DMACH     :3;
         uint32_t reserved0     :1;
    __IO uint32_t NUM_QDMACH    :3;
         uint32_t reserved1     :1;
    __IO uint32_t NUM_INTCH     :3;
         uint32_t reserved2     :1;
    __IO uint32_t NUM_PAENTRY   :3;
         uint32_t reserved3     :1;
    __IO uint32_t NUM_EVQUE     :3;
         uint32_t reserved4     :1;
    __IO uint32_t NUM_REGN      :2;
         uint32_t reserved5     :2;
    __IO uint32_t CHMAP_EXIST   :1;
    __IO uint32_t MP_EXIST      :1;
         uint32_t reserved6     :6;
}EDMA3_CC_CCCFG_TypeDef;

typedef __IO struct
{
         uint32_t reserved0     :2;
    __IO uint32_t TRWORD        :3;
    __IO uint32_t PAENTRY       :9;
         uint32_t reserved1     :18;
}EDMA3_CC_QCHMAPn_TypeDef;

typedef __IO struct
{
    __IO uint32_t En0           :3;
         uint32_t reserved0     :1;
    __IO uint32_t En1           :3;
         uint32_t reserved1     :1;
    __IO uint32_t En2           :3;
         uint32_t reserved2     :1;
    __IO uint32_t En3           :3;
         uint32_t reserved3     :1;
    __IO uint32_t En4           :3;
         uint32_t reserved4     :1;
    __IO uint32_t En5           :3;
         uint32_t reserved5     :1;
    __IO uint32_t En6           :3;
         uint32_t reserved6     :1;
    __IO uint32_t En7           :3;
         uint32_t reserved7     :1;
}EDMA3_CC_DMAQNUMn_TypeDef;

typedef __IO struct
{
    __IO uint32_t E0           :3;
         uint32_t reserved0     :1;
    __IO uint32_t E1           :3;
         uint32_t reserved1     :1;
    __IO uint32_t E2           :3;
         uint32_t reserved2     :1;
    __IO uint32_t E3           :3;
         uint32_t reserved3     :1;
    __IO uint32_t E4           :3;
         uint32_t reserved4     :1;
    __IO uint32_t E5           :3;
         uint32_t reserved5     :1;
    __IO uint32_t E6           :3;
         uint32_t reserved6     :1;
    __IO uint32_t E7           :3;
         uint32_t reserved7     :1;
}EDMA3_CC_QDMAQNUM_TypeDef;

typedef struct  {

    union
    {
        __IO uint32_t                   REVID;
        EDMA3_CC_REVID_TypeDef          REVID_Bit;
    };
    union
    {
        __IO uint32_t                   CCCFG;
        EDMA3_CC_CCCFG_TypeDef          CCCFG_Bit;
    };
    uint32_t reserved0[126];
    union
    {
        __IO uint32_t                   QCHMAP[8];
        EDMA3_CC_QCHMAPn_TypeDef        QCHMAP_Bit[8];
    };
    uint32_t reserved1[8];
    union
    {
        __IO uint32_t                    DMAQNUM[4];
        EDMA3_CC_DMAQNUMn_TypeDef        DMAQNUM_Bit[4];
    };
    uint32_t reserved2[4];
    union
    {
        __IO uint32_t                    QDMAQNUM;
        EDMA3_CC_QDMAQNUM_TypeDef        QDMAQNUM_Bit;
    };
    uint32_t reserved3[8];
    uint32_t QUEPRI;

} EDMA3_CC_GLOBAL_TypeDef;



typedef __IO struct
{
    __IO uint32_t E0            :1;
    __IO uint32_t E1            :1;
    __IO uint32_t E2            :1;
    __IO uint32_t E3            :1;
    __IO uint32_t E4            :1;
    __IO uint32_t E5            :1;
    __IO uint32_t E6            :1;
    __IO uint32_t E7            :1;
    __IO uint32_t E8            :1;
    __IO uint32_t E9            :1;
    __IO uint32_t E10           :1;
    __IO uint32_t E11           :1;
    __IO uint32_t E12           :1;
    __IO uint32_t E13           :1;
    __IO uint32_t E14           :1;
    __IO uint32_t E15           :1;
    __IO uint32_t E16           :1;
    __IO uint32_t E17           :1;
    __IO uint32_t E18           :1;
    __IO uint32_t E19           :1;
    __IO uint32_t E20           :1;
    __IO uint32_t E21           :1;
    __IO uint32_t E22           :1;
    __IO uint32_t E23           :1;
    __IO uint32_t E24           :1;
    __IO uint32_t E25           :1;
    __IO uint32_t E26           :1;
    __IO uint32_t E27           :1;
    __IO uint32_t E28           :1;
    __IO uint32_t E29           :1;
    __IO uint32_t E30           :1;
    __IO uint32_t E31           :1;
}EDMA3_CC_EMR_TypeDef;

typedef __IO struct
{
    __IO uint32_t E0            :1;
    __IO uint32_t E1            :1;
    __IO uint32_t E2            :1;
    __IO uint32_t E3            :1;
    __IO uint32_t E4            :1;
    __IO uint32_t E5            :1;
    __IO uint32_t E6            :1;
    __IO uint32_t E7            :1;
    __IO uint32_t E8            :1;
    __IO uint32_t E9            :1;
    __IO uint32_t E10           :1;
    __IO uint32_t E11           :1;
    __IO uint32_t E12           :1;
    __IO uint32_t E13           :1;
    __IO uint32_t E14           :1;
    __IO uint32_t E15           :1;
    __IO uint32_t E16           :1;
    __IO uint32_t E17           :1;
    __IO uint32_t E18           :1;
    __IO uint32_t E19           :1;
    __IO uint32_t E20           :1;
    __IO uint32_t E21           :1;
    __IO uint32_t E22           :1;
    __IO uint32_t E23           :1;
    __IO uint32_t E24           :1;
    __IO uint32_t E25           :1;
    __IO uint32_t E26           :1;
    __IO uint32_t E27           :1;
    __IO uint32_t E28           :1;
    __IO uint32_t E29           :1;
    __IO uint32_t E30           :1;
    __IO uint32_t E31           :1;
}EDMA3_CC_EMCR_TypeDef;

typedef __IO struct
{
    __IO uint32_t E0            :1;
    __IO uint32_t E1            :1;
    __IO uint32_t E2            :1;
    __IO uint32_t E3            :1;
    __IO uint32_t E4            :1;
    __IO uint32_t E5            :1;
    __IO uint32_t E6            :1;
    __IO uint32_t E7            :1;
         uint32_t reserved0     :24;
}EDMA3_CC_QEMR_TypeDef;

typedef __IO struct
{
    __IO uint32_t E0            :1;
    __IO uint32_t E1            :1;
    __IO uint32_t E2            :1;
    __IO uint32_t E3            :1;
    __IO uint32_t E4            :1;
    __IO uint32_t E5            :1;
    __IO uint32_t E6            :1;
    __IO uint32_t E7            :1;
         uint32_t reserved0     :24;
}EDMA3_CC_QEMCR_TypeDef;

typedef __IO struct
{
    __IO uint32_t QTHRXCD0      :1;
    __IO uint32_t QTHRXCD1      :1;
         uint32_t reserved0     :14;
    __IO uint32_t TCCERR        :1;
         uint32_t reserved1     :15;
}EDMA3_CC_CCERR_TypeDef;

typedef __IO struct
{
    __IO uint32_t QTHRXCD0      :1;
    __IO uint32_t QTHRXCD1      :1;
         uint32_t reserved0     :14;
    __IO uint32_t TCCERR        :1;
         uint32_t reserved1     :15;
}EDMA3_CC_CCERRCLR_TypeDef;

typedef __IO struct
{
    __IO uint32_t EVAL          :1;
         uint32_t reserved0     :31;
}EDMA3_CC_EEVAL_TypeDef;



typedef struct  {
    union
    {
        __IO uint32_t               EMR;
        EDMA3_CC_EMR_TypeDef        EMR_Bit;
    };
    uint32_t reserved0;
    union
    {
        __IO uint32_t               EMCR;
        EDMA3_CC_EMCR_TypeDef       EMCR_Bit;
    };
    uint32_t reserved1;
    union
    {
        __IO uint32_t               QEMR;
        EDMA3_CC_QEMR_TypeDef       QEMR_Bit;
    };
    union
    {
        __IO uint32_t               QEMCR;
        EDMA3_CC_QEMCR_TypeDef      QEMCR_Bit;
    };
    union
    {
        __IO uint32_t               CCERR;
        EDMA3_CC_CCERR_TypeDef      CCERR_Bit;
    };
    union
    {
        __IO uint32_t               CCERRCLR;
        EDMA3_CC_CCERRCLR_TypeDef   CCERRCLR_Bit;
    };
    union
    {
        __IO uint32_t               EEVAL;
        EDMA3_CC_EEVAL_TypeDef   EEVAL_Bit;
    };
} EDMA3_CC_ERROR_TypeDef;




typedef __IO struct
{
    __IO uint64_t E0            :1;
    __IO uint64_t E1            :1;
    __IO uint64_t E2            :1;
    __IO uint64_t E3            :1;
    __IO uint64_t E4            :1;
    __IO uint64_t E5            :1;
    __IO uint64_t E6            :1;
    __IO uint64_t E7            :1;
    __IO uint64_t E8            :1;
    __IO uint64_t E9            :1;
    __IO uint64_t E10           :1;
    __IO uint64_t E11           :1;
    __IO uint64_t E12           :1;
    __IO uint64_t E13           :1;
    __IO uint64_t E14           :1;
    __IO uint64_t E15           :1;
    __IO uint64_t E16           :1;
    __IO uint64_t E17           :1;
    __IO uint64_t E18           :1;
    __IO uint64_t E19           :1;
    __IO uint64_t E20           :1;
    __IO uint64_t E21           :1;
    __IO uint64_t E22           :1;
    __IO uint64_t E23           :1;
    __IO uint64_t E24           :1;
    __IO uint64_t E25           :1;
    __IO uint64_t E26           :1;
    __IO uint64_t E27           :1;
    __IO uint64_t E28           :1;
    __IO uint64_t E29           :1;
    __IO uint64_t E30           :1;
    __IO uint64_t E31           :1;
    uint64_t reserved0          :32;
}EDMA3_CC_DRAEm_TypeDef;

typedef __IO struct
{
    __IO uint32_t E0            :1;
    __IO uint32_t E1            :1;
    __IO uint32_t E2            :1;
    __IO uint32_t E3            :1;
    __IO uint32_t E4            :1;
    __IO uint32_t E5            :1;
    __IO uint32_t E6            :1;
    __IO uint32_t E7            :1;
         uint32_t reserved0     :24;
}EDMA3_CC_QRAEm_TypeDef;

typedef struct  {
    union
    {
        __IO uint64_t               DRA[4];
        EDMA3_CC_DRAEm_TypeDef      DRA_Bit[4];
    };
    uint32_t reserved0[8];
    union
    {
        __IO uint32_t               QRAE[4];
        EDMA3_CC_QRAEm_TypeDef      QRAE_Bit[4];
    };
} EDMA3_CC_ENABLE_TypeDef;



typedef __IO struct
{
    __IO uint32_t ENUM          :5;
         uint32_t reserved0     :1;
    __IO uint32_t ETYPE         :2;
         uint32_t reserved1     :24;
}EDMA3_CC_QxEy_TypeDef;

typedef struct  {
    union
    {
        __IO uint32_t               EVENT[16];
        EDMA3_CC_QxEy_TypeDef      EVENT_Bit[16];
    };
} EDMA3_CC_QxEy_EVENT;

typedef __IO struct
{
    __IO uint32_t STRTPTR           :4;
         uint32_t reserved0         :4;
    __IO uint32_t NUMVAL            :5;
         uint32_t reserved1         :3;
    __IO uint32_t WM                :5;
         uint32_t reserved2         :3;
    __IO uint32_t THRXCD            :1;
         uint32_t reserved3         :7;
}EDMA3_CC_QSTATn_TypeDef;

typedef __IO struct
{
    __IO uint32_t Q0                :5;
         uint32_t reserved0         :3;
    __IO uint32_t Q1                :5;
         uint32_t reserved1         :19;
}EDMA3_CC_QWMTHRA_TypeDef;

typedef __IO struct
{
    __IO uint32_t EVTACTV           :1;
    __IO uint32_t QEVTACTV          :1;
    __IO uint32_t TRACTV            :1;
    __IO uint32_t WSTATACTV         :1;
    __IO uint32_t ACTV              :1;
         uint32_t reserved0         :3;
    __IO uint32_t COMPACTV          :6;
         uint32_t reserved1         :2;
    __IO uint32_t QUEACTV0          :1;
    __IO uint32_t QUEACTV1          :1;
         uint32_t reserved2         :14;
}EDMA3_CC_CCSTAT_TypeDef;

typedef struct  {
    EDMA3_CC_QxEy_EVENT QUEUE[2];
    uint32_t reserved0[96];
    union
    {
        __IO uint32_t               QSTAT[3];
        EDMA3_CC_QSTATn_TypeDef     QSTAT_Bit[3];
    };
    uint32_t reserved1[5];
    union
    {
        __IO uint32_t               QWMTHRA;
        EDMA3_CC_QWMTHRA_TypeDef    QWMTHRA_Bit;
    };
    uint32_t reserved2[7];
    union
    {
        __IO uint32_t               CCSTAT;
        EDMA3_CC_CCSTAT_TypeDef    CCSTAT_Bit;
    };
} EDMA3_CC_STATUS_TypeDef;


typedef __IO struct
{
    __IO uint32_t E0            :1;
    __IO uint32_t E1            :1;
    __IO uint32_t E2            :1;
    __IO uint32_t E3            :1;
    __IO uint32_t E4            :1;
    __IO uint32_t E5            :1;
    __IO uint32_t E6            :1;
    __IO uint32_t E7            :1;
    __IO uint32_t E8            :1;
    __IO uint32_t E9            :1;
    __IO uint32_t E10           :1;
    __IO uint32_t E11           :1;
    __IO uint32_t E12           :1;
    __IO uint32_t E13           :1;
    __IO uint32_t E14           :1;
    __IO uint32_t E15           :1;
    __IO uint32_t E16           :1;
    __IO uint32_t E17           :1;
    __IO uint32_t E18           :1;
    __IO uint32_t E19           :1;
    __IO uint32_t E20           :1;
    __IO uint32_t E21           :1;
    __IO uint32_t E22           :1;
    __IO uint32_t E23           :1;
    __IO uint32_t E24           :1;
    __IO uint32_t E25           :1;
    __IO uint32_t E26           :1;
    __IO uint32_t E27           :1;
    __IO uint32_t E28           :1;
    __IO uint32_t E29           :1;
    __IO uint32_t E30           :1;
    __IO uint32_t E31           :1;
}EDMA3_CC_DMA_TypeDef;

typedef struct  {
    union
    {
        __IO uint32_t               ER;
        EDMA3_CC_DMA_TypeDef         ER_Bit;
    };
    uint32_t reserved0;
    union
    {
      __IO uint32_t                 ECR;
      EDMA3_CC_DMA_TypeDef          ECR_Bit;
    };
    uint32_t reserved1;
    union
    {
      __IO uint32_t                 ESR;
      EDMA3_CC_DMA_TypeDef          ESR_Bit;
    };
    uint32_t reserved2;
    union
    {
      __IO uint32_t                 CER;
      EDMA3_CC_DMA_TypeDef          CER_Bit;
    };
    uint32_t reserved3;
    union
    {
      __IO uint32_t                 EER;
      EDMA3_CC_DMA_TypeDef          EER_Bit;
    };
    uint32_t reserved4;
    union
    {
      __IO uint32_t                 EECR;
      EDMA3_CC_DMA_TypeDef         EECR_Bit;
    };
    uint32_t reserved5;
    union
    {
      __IO uint32_t                 EESR;
      EDMA3_CC_DMA_TypeDef         EESR_Bit;
    };
    uint32_t reserved6;
    union
    {
      __IO uint32_t                 SER;
      EDMA3_CC_DMA_TypeDef          SER_Bit;
    };
    uint32_t reserved7;
    union
    {
      __IO uint32_t                 SECR;
      EDMA3_CC_DMA_TypeDef         SECR_Bit;
    };
    uint32_t reserved8[3];
} EDMA3_CC_DMA_CHANNEL_TypeDef;


typedef __IO struct
{
    __IO uint32_t I0            :1;
    __IO uint32_t I1            :1;
    __IO uint32_t I2            :1;
    __IO uint32_t I3            :1;
    __IO uint32_t I4            :1;
    __IO uint32_t I5            :1;
    __IO uint32_t I6            :1;
    __IO uint32_t I7            :1;
    __IO uint32_t I8            :1;
    __IO uint32_t I9            :1;
    __IO uint32_t I10           :1;
    __IO uint32_t I11           :1;
    __IO uint32_t I12           :1;
    __IO uint32_t I13           :1;
    __IO uint32_t I14           :1;
    __IO uint32_t I15           :1;
    __IO uint32_t I16           :1;
    __IO uint32_t I17           :1;
    __IO uint32_t I18           :1;
    __IO uint32_t I19           :1;
    __IO uint32_t I20           :1;
    __IO uint32_t I21           :1;
    __IO uint32_t I22           :1;
    __IO uint32_t I23           :1;
    __IO uint32_t I24           :1;
    __IO uint32_t I25           :1;
    __IO uint32_t I26           :1;
    __IO uint32_t I27           :1;
    __IO uint32_t I28           :1;
    __IO uint32_t I29           :1;
    __IO uint32_t I30           :1;
    __IO uint32_t I31           :1;
}EDMA3_CC_INT_TypeDef;

typedef __IO struct
{
    __IO uint32_t EVAL            :1;
         uint32_t reserved0       :31;
}EDMA3_CC_IEVAL_TypeDef;

typedef struct  {
    union
    {
      __IO uint32_t                 IER;
      EDMA3_CC_INT_TypeDef          IER_Bit;
    };
    uint32_t reserved0;
    union
    {
      __IO uint32_t                 IECR;
      EDMA3_CC_INT_TypeDef          IECR_Bit;
    };
    uint32_t reserved1;
    union
    {
      __IO uint32_t                 IESR;
      EDMA3_CC_INT_TypeDef         IESR_Bit;
    };
    uint32_t reserved2;
    union
    {
      __IO uint32_t                 IPR;
      EDMA3_CC_INT_TypeDef          IPR_Bit;
    };
    uint32_t reserved3;
    union
    {
      __IO uint32_t                 ICR;
      EDMA3_CC_INT_TypeDef          ICR_Bit;
    };
    uint32_t reserved4;
    union
    {
      __IO uint32_t                 IEVAL;
      EDMA3_CC_IEVAL_TypeDef          IEVAL_Bit;
    };
    uint32_t reserved5;
} EDMA3_CC_INTERRUPT_TypeDef;


typedef __IO struct
{
    __IO uint32_t E0            :1;
    __IO uint32_t E1            :1;
    __IO uint32_t E2            :1;
    __IO uint32_t E3            :1;
    __IO uint32_t E4            :1;
    __IO uint32_t E5            :1;
    __IO uint32_t E6            :1;
    __IO uint32_t E7            :1;
         uint32_t reserved0     :24;
}EDMA3_CC_QDMA_TypeDef;


typedef struct  {
    union
    {
      __IO uint32_t                 QER;
      EDMA3_CC_QDMA_TypeDef          QER_Bit;
    };
    union
    {
      __IO uint32_t                 QEER;
      EDMA3_CC_QDMA_TypeDef          QEER_Bit;
    };
    union
    {
      __IO uint32_t                 QEECR;
      EDMA3_CC_QDMA_TypeDef         QEECR_Bit;
    };
    union
    {
      __IO uint32_t                 QEESR;
      EDMA3_CC_QDMA_TypeDef        QEESR_Bit;
    };
    union
    {
      __IO uint32_t               QSER;
      EDMA3_CC_QDMA_TypeDef       QSER_Bit;
    };
    union
    {
      __IO uint32_t               QSECR;
      EDMA3_CC_QDMA_TypeDef       QSECR_Bit;
    };
} EDMA3_CC_QDMA_CHANNEL_TypeDef;


typedef struct  {
    EDMA3_CC_DMA_CHANNEL_TypeDef DMA_CHANNEL;
    EDMA3_CC_INTERRUPT_TypeDef   INTERRUPT;
    EDMA3_CC_QDMA_CHANNEL_TypeDef QDMA_CHANNEL;
    uint32_t reserved0[90];
} EDMA3_CC_SHADOW_TypeDef;


typedef struct  {
    EDMA3_CC_SHADOW_TypeDef SHADOW[2];
} EDMA3_CC_SHADOW_ARRAY_TypeDef;



#define EDMA3_0_CC0_PaRAM            (((EDMA3_CC_PARAM_ARRAY_TypeDef*)(EDMA3_0_CC0_PaRAM_BASE)))
#define EDMA3_0_CC0_PaRAM_R(offset)  (((EDMA3_CC_PARAM_TypeDef*)(EDMA3_0_CC0_PaRAM_BASE+(offset*0x20)))
#define EDMA3_1_CC0_PaRAM            (((EDMA3_CC_PARAM_ARRAY_TypeDef*)(EDMA3_1_CC0_PaRAM_BASE)))
#define EDMA3_1_CC0_PaRAM_R(offset)  (((EDMA3_CC_PARAM_TypeDef*)(EDMA3_1_CC0_PaRAM_BASE+(offset*0x20)))

#define EDMA3_0_CC0_GLOBAL            (((EDMA3_CC_GLOBAL_TypeDef*)(EDMA3_0_CC0_GLOBAL_BASE)))
#define EDMA3_0_CC0_GLOBAL_R(offset)  (*((uint32_t*)(EDMA3_0_CC0_GLOBAL_BASE+(offset)))
#define EDMA3_1_CC0_GLOBAL            (((EDMA3_CC_GLOBAL_TypeDef*)(EDMA3_1_CC0_GLOBAL_BASE)))
#define EDMA3_1_CC0_GLOBAL_R(offset)  (*((uint32_t*)(EDMA3_1_CC0_GLOBAL_BASE+(offset)))

#define EDMA3_0_CC0_ERROR            (((EDMA3_CC_ERROR_TypeDef*)(EDMA3_0_CC0_ERROR_BASE)))
#define EDMA3_0_CC0_ERROR_R(offset)  (*((uint32_t*)(EDMA3_0_CC0_ERROR_BASE+(offset)))
#define EDMA3_1_CC0_ERROR            (((EDMA3_CC_ERROR_TypeDef*)(EDMA3_1_CC0_ERROR_BASE)))
#define EDMA3_1_CC0_ERROR_R(offset)  (*((uint32_t*)(EDMA3_1_CC0_ERROR_BASE+(offset)))

#define EDMA3_0_CC0_ENABLE            (((EDMA3_CC_ENABLE_TypeDef*)(EDMA3_0_CC0_ENABLE_BASE)))
#define EDMA3_0_CC0_ENABLE_R(offset)  (*((uint32_t*)(EDMA3_0_CC0_ENABLE_BASE+(offset)))
#define EDMA3_1_CC0_ENABLE            (((EDMA3_CC_ENABLE_TypeDef*)(EDMA3_1_CC0_ENABLE_BASE)))
#define EDMA3_1_CC0_ENABLE_R(offset)  (*((uint32_t*)(EDMA3_1_CC0_ENABLE_BASE+(offset)))

#define EDMA3_0_CC0_STATUS            (((EDMA3_CC_STATUS_TypeDef*)(EDMA3_0_CC0_STATUS_BASE)))
#define EDMA3_0_CC0_STATUS_R(offset)  (*((uint32_t*)(EDMA3_0_CC0_STATUS_BASE+(offset)))
#define EDMA3_1_CC0_STATUS            (((EDMA3_CC_STATUS_TypeDef*)(EDMA3_1_CC0_STATUS_BASE)))
#define EDMA3_1_CC0_STATUS_R(offset)  (*((uint32_t*)(EDMA3_1_CC0_STATUS_BASE+(offset)))

#define EDMA3_0_CC0_DMA_CHANNEL            (((EDMA3_CC_DMA_CHANNEL_TypeDef*)(EDMA3_0_CC0_DMA_CHANNEL_BASE)))
#define EDMA3_0_CC0_DMA_CHANNEL_R(offset)  (*((uint32_t*)(EDMA3_0_CC0_DMA_CHANNEL_BASE+(offset)))
#define EDMA3_1_CC0_DMA_CHANNEL            (((EDMA3_CC_DMA_CHANNEL_TypeDef*)(EDMA3_1_CC0_DMA_CHANNEL_BASE)))
#define EDMA3_1_CC0_DMA_CHANNEL_R(offset)  (*((uint32_t*)(EDMA3_1_CC0_DMA_CHANNEL_BASE+(offset)))

#define EDMA3_0_CC0_INTERRUPT            (((EDMA3_CC_INTERRUPT_TypeDef*)(EDMA3_0_CC0_INTERRUPT_BASE)))
#define EDMA3_0_CC0_INTERRUPT_R(offset)  (*((uint32_t*)(EDMA3_0_CC0_INTERRUPT_BASE+(offset)))
#define EDMA3_1_CC0_INTERRUPT            (((EDMA3_CC_INTERRUPT_TypeDef*)(EDMA3_1_CC0_INTERRUPT_BASE)))
#define EDMA3_1_CC0_INTERRUPT_R(offset)  (*((uint32_t*)(EDMA3_1_CC0_INTERRUPT_BASE+(offset)))

#define EDMA3_0_CC0_QDMA_CHANNEL            (((EDMA3_CC_QDMA_CHANNEL_TypeDef*)(EDMA3_0_CC0_QDMA_CHANNEL_BASE)))
#define EDMA3_0_CC0_QDMA_CHANNEL_R(offset)  (*((uint32_t*)(EDMA3_0_CC0_QDMA_CHANNEL_BASE+(offset)))
#define EDMA3_1_CC0_QDMA_CHANNEL            (((EDMA3_CC_QDMA_CHANNEL_TypeDef*)(EDMA3_1_CC0_QDMA_CHANNEL_BASE)))
#define EDMA3_1_CC0_QDMA_CHANNEL_R(offset)  (*((uint32_t*)(EDMA3_1_CC0_QDMA_CHANNEL_BASE+(offset)))

#define EDMA3_0_CC0_SHADOW            (((EDMA3_CC_SHADOW_ARRAY_TypeDef*)(EDMA3_0_CC0_SHADOW0_BASE)))
#define EDMA3_0_CC0_SHADOW0_R(offset)  (((EDMA3_CC_SHADOW_TypeDef*)(EDMA3_0_CC0_SHADOW0_BASE+(offset)))
#define EDMA3_0_CC0_SHADOW1_R(offset)  (((EDMA3_CC_SHADOW_TypeDef*)(EDMA3_0_CC0_SHADOW1_BASE+(offset)))
#define EDMA3_1_CC0_SHADOW            (((EDMA3_CC_SHADOW_ARRAY_TypeDef*)(EDMA3_1_CC0_SHADOW0_BASE)))
#define EDMA3_1_CC0_SHADOW0_R(offset)  (((EDMA3_CC_SHADOW_TypeDef*)(EDMA3_1_CC0_SHADOW0_BASE+(offset)))
#define EDMA3_1_CC0_SHADOW1_R(offset)  (((EDMA3_CC_SHADOW_TypeDef*)(EDMA3_1_CC0_SHADOW1_BASE+(offset)))



#define EDMA3_CC_GLOBAL_REVID_OFFSET            ((uint32_t)0x0000)
#define EDMA3_CC_GLOBAL_CCCFG_OFFSET            ((uint32_t)0x0004)
#define EDMA3_CC_GLOBAL_QCHMAP0_OFFSET          ((uint32_t)0x0200)
#define EDMA3_CC_GLOBAL_QCHMAP1_OFFSET          ((uint32_t)0x0204)
#define EDMA3_CC_GLOBAL_QCHMAP2_OFFSET          ((uint32_t)0x0208)
#define EDMA3_CC_GLOBAL_QCHMAP3_OFFSET          ((uint32_t)0x020C)
#define EDMA3_CC_GLOBAL_QCHMAP4_OFFSET          ((uint32_t)0x0210)
#define EDMA3_CC_GLOBAL_QCHMAP5_OFFSET          ((uint32_t)0x0214)
#define EDMA3_CC_GLOBAL_QCHMAP6_OFFSET          ((uint32_t)0x0218)
#define EDMA3_CC_GLOBAL_QCHMAP7_OFFSET          ((uint32_t)0x021C)
#define EDMA3_CC_GLOBAL_DMAQNUM0_OFFSET          ((uint32_t)0x0240)
#define EDMA3_CC_GLOBAL_DMAQNUM1_OFFSET          ((uint32_t)0x0244)
#define EDMA3_CC_GLOBAL_DMAQNUM2_OFFSET          ((uint32_t)0x0248)
#define EDMA3_CC_GLOBAL_DMAQNUM3_OFFSET          ((uint32_t)0x024C)
#define EDMA3_CC_GLOBAL_QDMAQNUM_OFFSET          ((uint32_t)0x0260)
#define EDMA3_CC_GLOBAL_QUEPRI_OFFSET            ((uint32_t)0x0284)


#define EDMA3_CC_ERROR_EMR_OFFSET              ((uint32_t)0x0000)
#define EDMA3_CC_ERROR_EMCR_OFFSET             ((uint32_t)0x0008)
#define EDMA3_CC_ERROR_QEMR_OFFSET             ((uint32_t)0x0010)
#define EDMA3_CC_ERROR_QEMCR_OFFSET            ((uint32_t)0x0014)
#define EDMA3_CC_ERROR_CCERR_OFFSET            ((uint32_t)0x0018)
#define EDMA3_CC_ERROR_CCERRCLR_OFFSET         ((uint32_t)0x001C)
#define EDMA3_CC_ERROR_EEVAL_OFFSET            ((uint32_t)0x0020)


#define EDMA3_CC_ENABLE_DRAE0_OFFSET              ((uint32_t)0x0000)
#define EDMA3_CC_ENABLE_DRAE1_OFFSET              ((uint32_t)0x0008)
#define EDMA3_CC_ENABLE_DRAE2_OFFSET              ((uint32_t)0x0010)
#define EDMA3_CC_ENABLE_DRAE3_OFFSET              ((uint32_t)0x0018)
#define EDMA3_CC_ENABLE_QRAE0_OFFSET              ((uint32_t)0x0040)
#define EDMA3_CC_ENABLE_QRAE1_OFFSET              ((uint32_t)0x0044)
#define EDMA3_CC_ENABLE_QRAE2_OFFSET              ((uint32_t)0x0048)
#define EDMA3_CC_ENABLE_QRAE3_OFFSET              ((uint32_t)0x004C)

#define EDMA3_CC_STATUS_Q0E0_OFFSET              ((uint32_t)0x0000)
#define EDMA3_CC_STATUS_Q0E1_OFFSET              ((uint32_t)0x0004)
#define EDMA3_CC_STATUS_Q0E2_OFFSET              ((uint32_t)0x0008)
#define EDMA3_CC_STATUS_Q0E3_OFFSET              ((uint32_t)0x000C)
#define EDMA3_CC_STATUS_Q0E4_OFFSET              ((uint32_t)0x0010)
#define EDMA3_CC_STATUS_Q0E5_OFFSET              ((uint32_t)0x0014)
#define EDMA3_CC_STATUS_Q0E6_OFFSET              ((uint32_t)0x0018)
#define EDMA3_CC_STATUS_Q0E7_OFFSET              ((uint32_t)0x001C)
#define EDMA3_CC_STATUS_Q0E8_OFFSET              ((uint32_t)0x0020)
#define EDMA3_CC_STATUS_Q0E9_OFFSET              ((uint32_t)0x0024)
#define EDMA3_CC_STATUS_Q0E10_OFFSET              ((uint32_t)0x0028)
#define EDMA3_CC_STATUS_Q0E11_OFFSET              ((uint32_t)0x002C)
#define EDMA3_CC_STATUS_Q0E12_OFFSET              ((uint32_t)0x0030)
#define EDMA3_CC_STATUS_Q0E13_OFFSET              ((uint32_t)0x0034)
#define EDMA3_CC_STATUS_Q0E14_OFFSET              ((uint32_t)0x0038)
#define EDMA3_CC_STATUS_Q0E15_OFFSET              ((uint32_t)0x003C)
#define EDMA3_CC_STATUS_Q1E0_OFFSET              ((uint32_t)0x0040)
#define EDMA3_CC_STATUS_Q1E1_OFFSET              ((uint32_t)0x0044)
#define EDMA3_CC_STATUS_Q1E2_OFFSET              ((uint32_t)0x0048)
#define EDMA3_CC_STATUS_Q1E3_OFFSET              ((uint32_t)0x004C)
#define EDMA3_CC_STATUS_Q1E4_OFFSET              ((uint32_t)0x0050)
#define EDMA3_CC_STATUS_Q1E5_OFFSET              ((uint32_t)0x0054)
#define EDMA3_CC_STATUS_Q1E6_OFFSET              ((uint32_t)0x0058)
#define EDMA3_CC_STATUS_Q1E7_OFFSET              ((uint32_t)0x005C)
#define EDMA3_CC_STATUS_Q1E8_OFFSET              ((uint32_t)0x0060)
#define EDMA3_CC_STATUS_Q1E9_OFFSET              ((uint32_t)0x0064)
#define EDMA3_CC_STATUS_Q1E10_OFFSET              ((uint32_t)0x0068)
#define EDMA3_CC_STATUS_Q1E11_OFFSET              ((uint32_t)0x006C)
#define EDMA3_CC_STATUS_Q1E12_OFFSET              ((uint32_t)0x0070)
#define EDMA3_CC_STATUS_Q1E13_OFFSET              ((uint32_t)0x0074)
#define EDMA3_CC_STATUS_Q1E14_OFFSET              ((uint32_t)0x0078)
#define EDMA3_CC_STATUS_Q1E15_OFFSET              ((uint32_t)0x007C)
#define EDMA3_CC_STATUS_QSTAT0_OFFSET              ((uint32_t)0x0200)
#define EDMA3_CC_STATUS_QSTAT1_OFFSET              ((uint32_t)0x0204)
#define EDMA3_CC_STATUS_QWMTHRA_OFFSET              ((uint32_t)0x0220)
#define EDMA3_CC_STATUS_CCSTAT_OFFSET              ((uint32_t)0x0240)


#define EDMA3_CC_DMA_CHANNEL_ER_OFFSET               ((uint32_t)0x0000)
#define EDMA3_CC_DMA_CHANNEL_ECR_OFFSET              ((uint32_t)0x0008)
#define EDMA3_CC_DMA_CHANNEL_ESR_OFFSET              ((uint32_t)0x0010)
#define EDMA3_CC_DMA_CHANNEL_CER_OFFSET              ((uint32_t)0x0018)
#define EDMA3_CC_DMA_CHANNEL_EER_OFFSET              ((uint32_t)0x0020)
#define EDMA3_CC_DMA_CHANNEL_EECR_OFFSET             ((uint32_t)0x0028)
#define EDMA3_CC_DMA_CHANNEL_EESR_OFFSET             ((uint32_t)0x0030)
#define EDMA3_CC_DMA_CHANNEL_SER_OFFSET              ((uint32_t)0x0038)
#define EDMA3_CC_DMA_CHANNEL_SECR_OFFSET             ((uint32_t)0x0040)

#define EDMA3_CC_INTERRUPT_IER_OFFSET               ((uint32_t)0x0000)
#define EDMA3_CC_INTERRUPT_IECR_OFFSET              ((uint32_t)0x0008)
#define EDMA3_CC_INTERRUPT_IESR_OFFSET              ((uint32_t)0x0010)
#define EDMA3_CC_INTERRUPT_IPR_OFFSET              ((uint32_t)0x0018)
#define EDMA3_CC_INTERRUPT_ICR_OFFSET              ((uint32_t)0x0020)
#define EDMA3_CC_INTERRUPT_IEVAL_OFFSET             ((uint32_t)0x0028)


#define EQDMA3_CC_QDMA_CHANNEL_QER_OFFSET               ((uint32_t)0x0000)
#define EQDMA3_CC_QDMA_CHANNEL_QEER_OFFSET              ((uint32_t)0x0004)
#define EQDMA3_CC_QDMA_CHANNEL_QEECR_OFFSET              ((uint32_t)0x0008)
#define EQDMA3_CC_QDMA_CHANNEL_QEESR_OFFSET              ((uint32_t)0x000C)
#define EQDMA3_CC_QDMA_CHANNEL_QSER_OFFSET              ((uint32_t)0x0010)
#define EQDMA3_CC_QDMA_CHANNEL_QSECR_OFFSET             ((uint32_t)0x0014)

#define EDMA3_PARAM_OPT_OFFSET            ((uint32_t)0x0000)
#define EDMA3_PARAM_SRC_OFFSET            ((uint32_t)0x0004)
#define EDMA3_PARAM_A_B_CNT_OFFSET        ((uint32_t)0x0008)
#define EDMA3_PARAM_DST_OFFSET            ((uint32_t)0x000C)
#define EDMA3_PARAM_SRC_DST_BIDX_OFFSET   ((uint32_t)0x0010)
#define EDMA3_PARAM_LINK_BCNTRLD_OFFSET   ((uint32_t)0x0014)
#define EDMA3_PARAM_SRC_DST_CIDX_OFFSET   ((uint32_t)0x0018)
#define EDMA3_PARAM_CCNT_OFFSET           ((uint32_t)0x001C)

#define EDMA3_PARAM0_OFFSET            ((uint32_t)0x0000)
#define EDMA3_PARAM1_OFFSET            ((uint32_t)0x0020)
#define EDMA3_PARAM2_OFFSET            ((uint32_t)0x0040)
#define EDMA3_PARAM3_OFFSET            ((uint32_t)0x0060)
#define EDMA3_PARAM4_OFFSET            ((uint32_t)0x0080)
#define EDMA3_PARAM5_OFFSET            ((uint32_t)0x00A0)
#define EDMA3_PARAM6_OFFSET            ((uint32_t)0x00C0)
#define EDMA3_PARAM7_OFFSET            ((uint32_t)0x00E0)
#define EDMA3_PARAM8_OFFSET            ((uint32_t)0x0100)
#define EDMA3_PARAM9_OFFSET            ((uint32_t)0x0120)
#define EDMA3_PARAM10_OFFSET           ((uint32_t)0x0140)
#define EDMA3_PARAM11_OFFSET           ((uint32_t)0x0160)
#define EDMA3_PARAM12_OFFSET           ((uint32_t)0x0180)
#define EDMA3_PARAM13_OFFSET           ((uint32_t)0x01A0)
#define EDMA3_PARAM14_OFFSET           ((uint32_t)0x01C0)
#define EDMA3_PARAM15_OFFSET           ((uint32_t)0x01E0)
#define EDMA3_PARAM16_OFFSET           ((uint32_t)0x0200)
#define EDMA3_PARAM17_OFFSET           ((uint32_t)0x0220)
#define EDMA3_PARAM18_OFFSET           ((uint32_t)0x0240)
#define EDMA3_PARAM19_OFFSET           ((uint32_t)0x0260)
#define EDMA3_PARAM20_OFFSET           ((uint32_t)0x0280)
#define EDMA3_PARAM21_OFFSET           ((uint32_t)0x02A0)
#define EDMA3_PARAM22_OFFSET           ((uint32_t)0x02C0)
#define EDMA3_PARAM23_OFFSET           ((uint32_t)0x02E0)
#define EDMA3_PARAM24_OFFSET           ((uint32_t)0x0300)
#define EDMA3_PARAM25_OFFSET           ((uint32_t)0x0320)
#define EDMA3_PARAM26_OFFSET           ((uint32_t)0x0340)
#define EDMA3_PARAM27_OFFSET           ((uint32_t)0x0360)
#define EDMA3_PARAM28_OFFSET           ((uint32_t)0x0380)
#define EDMA3_PARAM29_OFFSET           ((uint32_t)0x03A0)
#define EDMA3_PARAM30_OFFSET           ((uint32_t)0x03C0)
#define EDMA3_PARAM31_OFFSET           ((uint32_t)0x03E0)
#define EDMA3_PARAM32_OFFSET           ((uint32_t)0x0400)
#define EDMA3_PARAM33_OFFSET           ((uint32_t)0x0420)
#define EDMA3_PARAM34_OFFSET           ((uint32_t)0x0440)
#define EDMA3_PARAM35_OFFSET           ((uint32_t)0x0460)
#define EDMA3_PARAM36_OFFSET           ((uint32_t)0x0480)
#define EDMA3_PARAM37_OFFSET           ((uint32_t)0x04A0)
#define EDMA3_PARAM38_OFFSET           ((uint32_t)0x04C0)
#define EDMA3_PARAM39_OFFSET           ((uint32_t)0x04E0)
#define EDMA3_PARAM40_OFFSET           ((uint32_t)0x0500)
#define EDMA3_PARAM41_OFFSET           ((uint32_t)0x0520)
#define EDMA3_PARAM42_OFFSET           ((uint32_t)0x0540)
#define EDMA3_PARAM43_OFFSET           ((uint32_t)0x0560)
#define EDMA3_PARAM44_OFFSET           ((uint32_t)0x0580)
#define EDMA3_PARAM45_OFFSET           ((uint32_t)0x05A0)
#define EDMA3_PARAM46_OFFSET           ((uint32_t)0x05C0)
#define EDMA3_PARAM47_OFFSET           ((uint32_t)0x05E0)
#define EDMA3_PARAM48_OFFSET           ((uint32_t)0x0600)
#define EDMA3_PARAM49_OFFSET           ((uint32_t)0x0620)
#define EDMA3_PARAM50_OFFSET           ((uint32_t)0x0640)
#define EDMA3_PARAM51_OFFSET           ((uint32_t)0x0660)
#define EDMA3_PARAM52_OFFSET           ((uint32_t)0x0680)
#define EDMA3_PARAM53_OFFSET           ((uint32_t)0x06A0)
#define EDMA3_PARAM54_OFFSET           ((uint32_t)0x06C0)
#define EDMA3_PARAM55_OFFSET           ((uint32_t)0x06E0)
#define EDMA3_PARAM56_OFFSET           ((uint32_t)0x0700)
#define EDMA3_PARAM57_OFFSET           ((uint32_t)0x0720)
#define EDMA3_PARAM58_OFFSET           ((uint32_t)0x0740)
#define EDMA3_PARAM59_OFFSET           ((uint32_t)0x0760)
#define EDMA3_PARAM60_OFFSET           ((uint32_t)0x0780)
#define EDMA3_PARAM61_OFFSET           ((uint32_t)0x07A0)
#define EDMA3_PARAM62_OFFSET           ((uint32_t)0x07C0)
#define EDMA3_PARAM63_OFFSET           ((uint32_t)0x07E0)
#define EDMA3_PARAM64_OFFSET           ((uint32_t)0x0800)
#define EDMA3_PARAM65_OFFSET           ((uint32_t)0x0820)
#define EDMA3_PARAM66_OFFSET           ((uint32_t)0x0840)
#define EDMA3_PARAM67_OFFSET           ((uint32_t)0x0860)
#define EDMA3_PARAM68_OFFSET           ((uint32_t)0x0880)
#define EDMA3_PARAM69_OFFSET           ((uint32_t)0x08A0)
#define EDMA3_PARAM70_OFFSET           ((uint32_t)0x08C0)
#define EDMA3_PARAM71_OFFSET           ((uint32_t)0x08E0)
#define EDMA3_PARAM72_OFFSET           ((uint32_t)0x0900)
#define EDMA3_PARAM73_OFFSET           ((uint32_t)0x0920)
#define EDMA3_PARAM74_OFFSET           ((uint32_t)0x0940)
#define EDMA3_PARAM75_OFFSET           ((uint32_t)0x0960)
#define EDMA3_PARAM76_OFFSET           ((uint32_t)0x0980)
#define EDMA3_PARAM77_OFFSET           ((uint32_t)0x09A0)
#define EDMA3_PARAM78_OFFSET           ((uint32_t)0x09C0)
#define EDMA3_PARAM79_OFFSET           ((uint32_t)0x09E0)
#define EDMA3_PARAM80_OFFSET           ((uint32_t)0x0A00)
#define EDMA3_PARAM81_OFFSET           ((uint32_t)0x0A20)
#define EDMA3_PARAM82_OFFSET           ((uint32_t)0x0A40)
#define EDMA3_PARAM83_OFFSET           ((uint32_t)0x0A60)
#define EDMA3_PARAM84_OFFSET           ((uint32_t)0x0A80)
#define EDMA3_PARAM85_OFFSET           ((uint32_t)0x0AA0)
#define EDMA3_PARAM86_OFFSET           ((uint32_t)0x0AC0)
#define EDMA3_PARAM87_OFFSET           ((uint32_t)0x0AE0)
#define EDMA3_PARAM88_OFFSET           ((uint32_t)0x0B00)
#define EDMA3_PARAM89_OFFSET           ((uint32_t)0x0B20)
#define EDMA3_PARAM90_OFFSET           ((uint32_t)0x0B40)
#define EDMA3_PARAM91_OFFSET           ((uint32_t)0x0B60)
#define EDMA3_PARAM92_OFFSET           ((uint32_t)0x0B80)
#define EDMA3_PARAM93_OFFSET           ((uint32_t)0x0BA0)
#define EDMA3_PARAM94_OFFSET           ((uint32_t)0x0BC0)
#define EDMA3_PARAM95_OFFSET           ((uint32_t)0x0BE0)
#define EDMA3_PARAM96_OFFSET           ((uint32_t)0x0C00)
#define EDMA3_PARAM97_OFFSET           ((uint32_t)0x0C20)
#define EDMA3_PARAM98_OFFSET           ((uint32_t)0x0C40)
#define EDMA3_PARAM99_OFFSET           ((uint32_t)0x0C60)
#define EDMA3_PARAM100_OFFSET          ((uint32_t)0x0C70)
#define EDMA3_PARAM101_OFFSET          ((uint32_t)0x0CA0)
#define EDMA3_PARAM102_OFFSET          ((uint32_t)0x0CC0)
#define EDMA3_PARAM103_OFFSET          ((uint32_t)0x0CE0)
#define EDMA3_PARAM104_OFFSET          ((uint32_t)0x0D00)
#define EDMA3_PARAM105_OFFSET          ((uint32_t)0x0D20)
#define EDMA3_PARAM106_OFFSET          ((uint32_t)0x0D40)
#define EDMA3_PARAM107_OFFSET          ((uint32_t)0x0D60)
#define EDMA3_PARAM108_OFFSET          ((uint32_t)0x0D80)
#define EDMA3_PARAM109_OFFSET          ((uint32_t)0x0DA0)
#define EDMA3_PARAM110_OFFSET          ((uint32_t)0x0DC0)
#define EDMA3_PARAM111_OFFSET          ((uint32_t)0x0DE0)
#define EDMA3_PARAM112_OFFSET          ((uint32_t)0x0E00)
#define EDMA3_PARAM113_OFFSET          ((uint32_t)0x0E20)
#define EDMA3_PARAM114_OFFSET          ((uint32_t)0x0E40)
#define EDMA3_PARAM115_OFFSET          ((uint32_t)0x0E60)
#define EDMA3_PARAM116_OFFSET          ((uint32_t)0x0E80)
#define EDMA3_PARAM117_OFFSET          ((uint32_t)0x0EA0)
#define EDMA3_PARAM118_OFFSET          ((uint32_t)0x0EC0)
#define EDMA3_PARAM119_OFFSET          ((uint32_t)0x0EE0)
#define EDMA3_PARAM120_OFFSET          ((uint32_t)0x0F00)
#define EDMA3_PARAM121_OFFSET          ((uint32_t)0x0F20)
#define EDMA3_PARAM122_OFFSET          ((uint32_t)0x0F40)
#define EDMA3_PARAM123_OFFSET          ((uint32_t)0x0F60)
#define EDMA3_PARAM124_OFFSET          ((uint32_t)0x0F80)
#define EDMA3_PARAM125_OFFSET          ((uint32_t)0x0FA0)
#define EDMA3_PARAM126_OFFSET          ((uint32_t)0x0FC0)
#define EDMA3_PARAM127_OFFSET          ((uint32_t)0x0FE0)


//todo all registers

typedef enum
{
    EDMA3_EVENT_enMCASP0_RX             =0,
    EDMA3_EVENT_enMCASP0_TX             =1,
    EDMA3_EVENT_enMCBSP0_RX             =2,
    EDMA3_EVENT_enMCBSP0_TX             =3,
    EDMA3_EVENT_enMCBSP1_RX             =4,
    EDMA3_EVENT_enMCBSP1_TX             =5,
    EDMA3_EVENT_enGPIO_BNKINT0          =6,
    EDMA3_EVENT_enGPIO_BNKINT1          =7,
    EDMA3_EVENT_enUART0_RX              =8,
    EDMA3_EVENT_enUART0_TX              =9,
    EDMA3_EVENT_enTIMER64P0_EVT12       =10,
    EDMA3_EVENT_enTIMER64P0_EVT34       =11,
    EDMA3_EVENT_enUART1_RX              =12,
    EDMA3_EVENT_enUART1_TX              =13,
    EDMA3_EVENT_enSPI0_RX               =14,
    EDMA3_EVENT_enSPI0_TX               =15,
    EDMA3_EVENT_enMMCSD0_RX             =16,
    EDMA3_EVENT_enMMCSD0_TX             =17,
    EDMA3_EVENT_enSPI1_RX               =18,
    EDMA3_EVENT_enSPI1_TX               =19,
    EDMA3_EVENT_enPRU_EVTOUT6           =20,
    EDMA3_EVENT_enPRU_EVTOUT7           =21,
    EDMA3_EVENT_enGPIO_BNKINT2          =22,
    EDMA3_EVENT_enGPIO_BNKINT3          =23,
    EDMA3_EVENT_enI2C0_RX               =24,
    EDMA3_EVENT_enI2C0_TX               =25,
    EDMA3_EVENT_enI2C1_RX               =26,
    EDMA3_EVENT_enI2C1_TX               =27,
    EDMA3_EVENT_enGPIO_BNKINT4          =28,
    EDMA3_EVENT_enGPIO_BNKINT5          =29,
    EDMA3_EVENT_enUART2_RX              =30,
    EDMA3_EVENT_enUART2_TX              =31,
}Edma3_0_CC0_Event;

typedef enum
{
    EDMA3_EVENT_enTIMER2_T12CMPEVT0         =0,
    EDMA3_EVENT_enTIMER2_T12CMPEVT1         =1,
    EDMA3_EVENT_enTIMER2_T12CMPEVT2         =2,
    EDMA3_EVENT_enTIMER2_T12CMPEVT3         =3,
    EDMA3_EVENT_enTIMER2_T12CMPEVT4         =4,
    EDMA3_EVENT_enTIMER2_T12CMPEVT5         =5,
    EDMA3_EVENT_enTIMER2_T12CMPEVT6         =6,
    EDMA3_EVENT_enTIMER2_T12CMPEVT7         =7,
    EDMA3_EVENT_enTIMER3_T12CMPEVT0         =8,
    EDMA3_EVENT_enTIMER3_T12CMPEVT1         =9,
    EDMA3_EVENT_enTIMER3_T12CMPEVT2         =10,
    EDMA3_EVENT_enTIMER3_T12CMPEVT3         =11,
    EDMA3_EVENT_enTIMER3_T12CMPEVT4         =12,
    EDMA3_EVENT_enTIMER3_T12CMPEVT5         =13,
    EDMA3_EVENT_enTIMER3_T12CMPEVT6         =14,
    EDMA3_EVENT_enTIMER3_T12CMPEVT7         =15,
    EDMA3_EVENT_enGPIO_BNKINT6          =16,
    EDMA3_EVENT_enGPIO_BNKINT7          =17,
    EDMA3_EVENT_enGPIO_BNKINT8          =18,
    EDMA3_EVENT_enTIMER64P2_EVT12       =24,
    EDMA3_EVENT_enTIMER64P2_EVT34       =25,
    EDMA3_EVENT_enTIMER64P3_EVT12       =26,
    EDMA3_EVENT_enTIMER64P3_EVT34       =27,
    EDMA3_EVENT_enMMCSD1_RX             =28,
    EDMA3_EVENT_enMMCSD1_TX             =29,
}Edma3_1_CC0_Event;



#endif /* DSP_INCLUDE_EDMA3_H_ */
