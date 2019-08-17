/*
 * VPIF.h
 *
 *  Created on: 04/08/2019
 *      Author: Lalo
 */

#ifndef DSP_INCLUDE_VPIF_H_
#define DSP_INCLUDE_VPIF_H_

#include "Core.h"
#include "SYSCFG.h"
#include <stdint.h>

#define VPIF_BASE            ((uint32_t)0x01E17000)
#define VPIF_CH0_BASE            ((uint32_t)VPIF_BASE + 0x40)
#define VPIF_CH1_BASE            ((uint32_t)VPIF_BASE + 0x80)
#define VPIF_CH2_BASE            ((uint32_t)VPIF_BASE + 0xC0)
#define VPIF_CH3_BASE            ((uint32_t)VPIF_BASE + 0x140)


typedef __IO struct
{
    __I uint32_t REV       :32;
}VPIF_REVID_TypeDef;


typedef __IO struct
{
    __IO uint32_t CHANEN            :1;
         uint32_t reserved0         :1;
    __IO uint32_t CAPMODE           :1;
    __IO uint32_t YCMUX             :1;
         uint32_t reserved1         :1;
    __IO uint32_t FID               :1;
    __IO uint32_t INTFRAME          :2;
    __IO uint32_t HANC              :1;
    __IO uint32_t VANC              :1;
    __IO uint32_t INTRPROG          :1;
         uint32_t reserved2         :1;
    __IO uint32_t FIELDFRAME        :1;
    __IO uint32_t HVINV             :1;
    __IO uint32_t VVINV             :1;
    __IO uint32_t FIDINV            :1;
    __IO uint32_t INTLINE           :12;
    __IO uint32_t DATAWIDTH         :2;
         uint32_t reserved3         :1;
    __IO uint32_t CLKEDGE           :1;
}VPIF_C0CTRL_TypeDef;

typedef __IO struct
{
    __IO uint32_t CHANEN            :1;
         uint32_t reserved0         :1;
    __IO uint32_t CAPMODE           :1;
    __IO uint32_t YCMUX             :1;
         uint32_t reserved1         :1;
    __IO uint32_t FID               :1;
    __IO uint32_t INTFRAME          :2;
    __IO uint32_t HANC              :1;
    __IO uint32_t VANC              :1;
    __IO uint32_t INTRPROG          :1;
         uint32_t reserved2         :20;
    __IO uint32_t CLKEDGE           :1;
}VPIF_C1CTRL_TypeDef;

typedef __IO struct
{
    __IO uint32_t CHANEN            :1;
    __IO uint32_t CLKEN             :1;
         uint32_t reserved0         :1;
    __IO uint32_t YCMUX             :1;
         uint32_t reserved1         :1;
    __IO uint32_t FID               :1;
    __IO uint32_t INTFRAME          :2;
    __IO uint32_t HANC              :1;
    __IO uint32_t VANC              :1;
    __IO uint32_t PIXEL             :1;
    __IO uint32_t INTRPROG          :1;
    __IO uint32_t FIELDFRAME        :1;
    __IO uint32_t CLIPVID           :1;
    __IO uint32_t CLIPANC           :1;
         uint32_t reserved2         :16;
    __IO uint32_t CLKEDGE           :1;
}VPIF_C2CTRL_TypeDef;

typedef __IO struct
{
    __IO uint32_t CHANEN            :1;
    __IO uint32_t CLKEN             :1;
         uint32_t reserved0         :1;
    __IO uint32_t YCMUX             :1;
         uint32_t reserved1         :1;
    __IO uint32_t FID               :1;
    __IO uint32_t INTFRAME          :2;
    __IO uint32_t HANC              :1;
    __IO uint32_t VANC              :1;
    __IO uint32_t PIXEL             :1;
    __IO uint32_t INTRPROG          :1;
         uint32_t reserved2         :1;
    __IO uint32_t CLIPVID           :1;
    __IO uint32_t CLIPANC           :1;
         uint32_t reserved3         :16;
    __IO uint32_t CLKEDGE           :1;
}VPIF_C3CTRL_TypeDef;

typedef __IO struct
{
    __IO uint32_t FRAME0            :1;
    __IO uint32_t FRAME1            :1;
    __IO uint32_t FRAME2            :1;
    __IO uint32_t FRAME3            :1;
    __IO uint32_t ERROR             :1;
         uint32_t reserved0         :27;
}VPIF_INTEN_TypeDef;

typedef __IO struct
{
    __IO uint32_t FRAME0            :1;
    __IO uint32_t FRAME1            :1;
    __IO uint32_t FRAME2            :1;
    __IO uint32_t FRAME3            :1;
    __IO uint32_t ERROR             :1;
         uint32_t reserved0         :27;
}VPIF_INTSET_TypeDef;

typedef __IO struct
{
    __IO uint32_t FRAME0            :1;
    __IO uint32_t FRAME1            :1;
    __IO uint32_t FRAME2            :1;
    __IO uint32_t FRAME3            :1;
    __IO uint32_t ERROR             :1;
         uint32_t reserved0         :27;
}VPIF_INTCLR_TypeDef;

typedef __IO struct
{
    __IO uint32_t FRAME0            :1;
    __IO uint32_t FRAME1            :1;
    __IO uint32_t FRAME2            :1;
    __IO uint32_t FRAME3            :1;
    __IO uint32_t ERROR             :1;
         uint32_t reserved0         :27;
}VPIF_INTSTAT_TypeDef;

typedef __IO struct
{
    __IO uint32_t FRAME0            :1;
    __IO uint32_t FRAME1            :1;
    __IO uint32_t FRAME2            :1;
    __IO uint32_t FRAME3            :1;
    __IO uint32_t ERROR             :1;
         uint32_t reserved0         :27;
}VPIF_INTSTATCLR_TypeDef;

typedef __IO struct
{
    __IO uint32_t FREE              :1;
         uint32_t reserved0         :31;
}VPIF_EMUCTRL_TypeDef;

typedef __IO struct
{
    __IO uint32_t BYTES              :9;
         uint32_t reserved0          :22;
}VPIF_REQSIZE_TypeDef;

typedef __IO struct
{
    __IO uint32_t TLUMA              :32;
}VPIF_CnTLUMA_TypeDef;

typedef __IO struct
{
    __IO uint32_t BLUMA              :32;
}VPIF_CnBLUMA_TypeDef;

typedef __IO struct
{
    __IO uint32_t TCHROMA              :32;
}VPIF_CnTCHROMA_TypeDef;

typedef __IO struct
{
    __IO uint32_t BCHROMA              :32;
}VPIF_CnBCHROMA_TypeDef;

typedef __IO struct
{
    __IO uint32_t THANC              :32;
}VPIF_CnTHANC_TypeDef;

typedef __IO struct
{
    __IO uint32_t BHANC              :32;
}VPIF_CnBHANC_TypeDef;

typedef __IO struct
{
    __IO uint32_t TVANC              :32;
}VPIF_CnTVANC_TypeDef;

typedef __IO struct
{
    __IO uint32_t BVANC              :32;
}VPIF_CnBVANC_TypeDef;

typedef __IO struct
{
    __IO uint32_t MGOFFSET              :32;
}VPIF_CnIMGOFFSET_TypeDef;

typedef __IO struct
{
    __IO uint32_t HANCOFFSET              :32;
}VPIF_CnHANCOFFSET_TypeDef;

typedef __IO struct
{
    __IO uint32_t SAV2EAV           :13;
         uint32_t reserved0         :3;
    __IO uint32_t EAV2SAV           :13;
         uint32_t reserved1         :3;
}VPIF_C01HCFG_TypeDef;

typedef __IO struct
{
    __IO uint32_t L3                :12;
         uint32_t reserved0         :4;
    __IO uint32_t L1                :12;
         uint32_t reserved1         :4;
}VPIF_C01VCFG0_TypeDef;

typedef __IO struct
{
    __IO uint32_t L7                :12;
         uint32_t reserved0         :4;
    __IO uint32_t L5                :12;
         uint32_t reserved1         :4;
}VPIF_C01VCFG1_TypeDef;

typedef __IO struct
{
    __IO uint32_t L11               :12;
         uint32_t reserved0         :4;
    __IO uint32_t L9                :12;
         uint32_t reserved1         :4;
}VPIF_C01VCFG2_TypeDef;

typedef __IO struct
{
    __IO uint32_t VSIZE              :12;
         uint32_t reserved0          :20;
}VPIF_C01VSIZE_TypeDef;

typedef __IO struct
{
    __IO uint32_t SAV2EAV           :11;
         uint32_t reserved0         :5;
    __IO uint32_t EAV2SAV           :11;
         uint32_t reserved1         :5;
}VPIF_C23HCFG_TypeDef;

typedef __IO struct
{
    __IO uint32_t L3                :11;
         uint32_t reserved0         :5;
    __IO uint32_t L1                :11;
         uint32_t reserved1         :5;
}VPIF_C23VCFG0_TypeDef;

typedef __IO struct
{
    __IO uint32_t L7                :11;
         uint32_t reserved0         :5;
    __IO uint32_t L5                :11;
         uint32_t reserved1         :5;
}VPIF_C23VCFG1_TypeDef;

typedef __IO struct
{
    __IO uint32_t L11               :11;
         uint32_t reserved0         :5;
    __IO uint32_t L9                :11;
         uint32_t reserved1         :5;
}VPIF_C23VCFG2_TypeDef;

typedef __IO struct
{
    __IO uint32_t VSIZE              :11;
         uint32_t reserved0          :21;
}VPIF_C23VSIZE_TypeDef;

typedef __IO struct
{
    __IO uint32_t HPOS              :11;
         uint32_t reserved0         :5;
    __IO uint32_t VPOS              :11;
         uint32_t reserved1         :5;
}VPIF_C23THANCPOS_TypeDef;

typedef __IO struct
{
    __IO uint32_t HSIZE             :11;
         uint32_t reserved0         :5;
    __IO uint32_t VSIZE             :11;
         uint32_t reserved1         :5;
}VPIF_C23THANCSIZE_TypeDef;

typedef __IO struct
{
    __IO uint32_t HPOS              :11;
         uint32_t reserved0         :5;
    __IO uint32_t VPOS              :11;
         uint32_t reserved1         :5;
}VPIF_C23BHANCPOS_TypeDef;

typedef __IO struct
{
    __IO uint32_t HSIZE             :11;
         uint32_t reserved0         :5;
    __IO uint32_t VSIZE             :11;
         uint32_t reserved1         :5;
}VPIF_C23BHANCSIZE_TypeDef;

typedef __IO struct
{
    __IO uint32_t HPOS              :11;
         uint32_t reserved0         :5;
    __IO uint32_t VPOS              :11;
         uint32_t reserved1         :5;
}VPIF_C23TVANCPOS_TypeDef;

typedef __IO struct
{
    __IO uint32_t HSIZE             :11;
         uint32_t reserved0         :5;
    __IO uint32_t VSIZE             :11;
         uint32_t reserved1         :5;
}VPIF_C23TVANCSIZE_TypeDef;

typedef __IO struct
{
    __IO uint32_t HPOS              :11;
         uint32_t reserved0         :5;
    __IO uint32_t VPOS              :11;
         uint32_t reserved1         :5;
}VPIF_C23BVANCPOS_TypeDef;

typedef __IO struct
{
    __IO uint32_t HSIZE             :11;
         uint32_t reserved0         :5;
    __IO uint32_t VSIZE             :11;
         uint32_t reserved1         :5;
}VPIF_C23BVANCSIZE_TypeDef;

typedef struct {
    union
    {
        __IO uint32_t            TLUMA;
        VPIF_CnTLUMA_TypeDef     TLUMA_Bit;
    };
    union
    {
        __IO uint32_t            BLUMA;
        VPIF_CnBLUMA_TypeDef     BLUMA_Bit;
    };
    union
    {
        __IO uint32_t            TCHROMA;
        VPIF_CnTCHROMA_TypeDef     TCHROMA_Bit;
    };
    union
    {
        __IO uint32_t            BCHROMA;
        VPIF_CnBCHROMA_TypeDef   BCHROMA_Bit;
    };
    union
    {
        __IO uint32_t            THANC;
        VPIF_CnTHANC_TypeDef   THANC_Bit;
    };
    union
    {
        __IO uint32_t            BHANC;
        VPIF_CnBHANC_TypeDef   BHANC_Bit;
    };
    union
    {
        __IO uint32_t            TVANC;
        VPIF_CnTVANC_TypeDef   TVANC_Bit;
    };
    union
    {
        __IO uint32_t            BVANC;
        VPIF_CnBVANC_TypeDef   BVANC_Bit;
    };
    __IO uint32_t reserved0;
    union
    {
        __IO uint32_t            IMGOFFSET;
        VPIF_CnIMGOFFSET_TypeDef  IMGOFFSET_Bit;
    };
    union
    {
        __IO uint32_t            HANCOFFSET;
        VPIF_CnHANCOFFSET_TypeDef  HANCOFFSET_Bit;
    };
    union
    {
        __IO uint32_t            HCFG;
        VPIF_C01HCFG_TypeDef  HCFG_Bit;
    };
    union
    {
        __IO uint32_t            VCFG0;
        VPIF_C01VCFG0_TypeDef  VCFG0_Bit;
    };
    union
    {
        __IO uint32_t            VCFG1;
        VPIF_C01VCFG1_TypeDef  VCFG1_Bit;
    };
    union
    {
        __IO uint32_t            VCFG2;
        VPIF_C01VCFG2_TypeDef  VCFG2_Bit;
    };
    union
    {
        __IO uint32_t            VSIZE;
        VPIF_C01VSIZE_TypeDef  VSIZE_Bit;
    };
}VPIF_CHANNEL01_TypeDef;

typedef struct {
    union
    {
        __IO uint32_t            TLUMA;
        VPIF_CnTLUMA_TypeDef     TLUMA_Bit;
    };
    union
    {
        __IO uint32_t            BLUMA;
        VPIF_CnBLUMA_TypeDef     BLUMA_Bit;
    };
    union
    {
        __IO uint32_t            TCHROMA;
        VPIF_CnTCHROMA_TypeDef     TCHROMA_Bit;
    };
    union
    {
        __IO uint32_t            BCHROMA;
        VPIF_CnBCHROMA_TypeDef   BCHROMA_Bit;
    };
    union
    {
        __IO uint32_t            THANC;
        VPIF_CnTHANC_TypeDef   THANC_Bit;
    };
    union
    {
        __IO uint32_t            BHANC;
        VPIF_CnBHANC_TypeDef   BHANC_Bit;
    };
    union
    {
        __IO uint32_t            TVANC;
        VPIF_CnTVANC_TypeDef   TVANC_Bit;
    };
    union
    {
        __IO uint32_t            BVANC;
        VPIF_CnBVANC_TypeDef   BVANC_Bit;
    };
    __IO uint32_t reserved0;
    union
    {
        __IO uint32_t            IMGOFFSET;
        VPIF_CnIMGOFFSET_TypeDef  IMGOFFSET_Bit;
    };
    union
    {
        __IO uint32_t            HANCOFFSET;
        VPIF_CnHANCOFFSET_TypeDef  HANCOFFSET_Bit;
    };

    union
    {
        __IO uint32_t            HCFG;
        VPIF_C23HCFG_TypeDef  HCFG_Bit;
    };
    union
    {
        __IO uint32_t            VCFG0;
        VPIF_C23VCFG0_TypeDef  VCFG0_Bit;
    };
    union
    {
        __IO uint32_t            VCFG1;
        VPIF_C23VCFG1_TypeDef  VCFG1_Bit;
    };
    union
    {
        __IO uint32_t            VCFG2;
        VPIF_C23VCFG2_TypeDef  VCFG2_Bit;
    };
    union
    {
        __IO uint32_t            VSIZE;
        VPIF_C23VSIZE_TypeDef  VSIZE_Bit;
    };
    union
    {
        __IO uint32_t            THANCPOS;
        VPIF_C23THANCPOS_TypeDef  THANCPOS_Bit;
    };
    union
    {
        __IO uint32_t            THANCSIZE;
        VPIF_C23THANCSIZE_TypeDef  THANCSIZE_Bit;
    };
    union
    {
        __IO uint32_t            BHANCPOS;
        VPIF_C23BHANCPOS_TypeDef  BHANCPOS_Bit;
    };
    union
    {
        __IO uint32_t            BHANCSIZE;
        VPIF_C23BHANCSIZE_TypeDef  BHANCSIZE_Bit;
    };
    union
    {
        __IO uint32_t            TVANCPOS;
        VPIF_C23TVANCPOS_TypeDef  TVANCPOS_Bit;
    };
    union
    {
        __IO uint32_t            TVANCSIZE;
        VPIF_C23TVANCSIZE_TypeDef  TVANCSIZE_Bit;
    };
    union
    {
        __IO uint32_t            BVANCPOS;
        VPIF_C23BVANCPOS_TypeDef  BVANCPOS_Bit;
    };
    union
    {
        __IO uint32_t            BVANCSIZE;
        VPIF_C23BVANCSIZE_TypeDef BVANCSIZE_Bit;
    };
    __IO uint32_t reserved1[8];
}VPIF_CHANNEL23_TypeDef;

typedef struct {
    union
    {
        __IO uint32_t            REVID;
        VPIF_REVID_TypeDef REVID_Bit;
    };
    union
    {
        __IO uint32_t            C0CTRL;
        VPIF_C0CTRL_TypeDef C0CTRL_Bit;
    };
    union
    {
        __IO uint32_t            C1CTRL;
        VPIF_C1CTRL_TypeDef C1CTRL_Bit;
    };
    union
    {
        __IO uint32_t            C2CTRL;
        VPIF_C2CTRL_TypeDef C2CTRL_Bit;
    };
    union
    {
        __IO uint32_t            C3CTRL;
        VPIF_C3CTRL_TypeDef C3CTRL_Bit;
    };
    __IO uint32_t reserved0[3];
    union
    {
        __IO uint32_t            INTEN;
        VPIF_INTEN_TypeDef INTEN_Bit;
    };
    union
    {
        __IO uint32_t            INTSET;
        VPIF_INTSET_TypeDef INTSET_Bit;
    };
    union
    {
        __IO uint32_t            INTCLR;
        VPIF_INTCLR_TypeDef INTCLR_Bit;
    };
    union
    {
        __IO uint32_t            INTSTAT;
        VPIF_INTSTAT_TypeDef INTSTAT_Bit;
    };
    union
    {
        __IO uint32_t            INTSTATCLR;
        VPIF_INTSTATCLR_TypeDef INTSTATCLR_Bit;
    };
    union
    {
        __IO uint32_t            EMUCTRL;
        VPIF_EMUCTRL_TypeDef EMUCTRL_Bit;
    };
    union
    {
        __IO uint32_t            REQSIZE;
        VPIF_REQSIZE_TypeDef REQSIZE_Bit;
    };
    __IO uint32_t reserved1;
    VPIF_CHANNEL01_TypeDef CAPTURE[2];
    VPIF_CHANNEL23_TypeDef DISPLAY[2];
} VPIF_TypeDef;

#define VPIF            (((VPIF_TypeDef*)(VPIF_BASE)))
#define VPIF_R(offset)  (*((__IO uint32_t *)(VPIF_BASE+offset)))

#define VPIF_CH0            (((VPIF_CHANNEL01_TypeDef*)(VPIF_CH0_BASE)))
#define VPIF_CH0_R(offset)  (*((__IO uint32_t *)(VPIF_CH0_BASE+offset)))
#define VPIF_CH1            (((VPIF_CHANNEL01_TypeDef*)(VPIF_CH1_BASE)))
#define VPIF_CH1_R(offset)  (*((__IO uint32_t *)(VPIF_CH1_BASE+offset)))
#define VPIF_CH2            (((VPIF_CHANNEL23_TypeDef*)(VPIF_CH2_BASE)))
#define VPIF_CH2_R(offset)  (*((__IO uint32_t *)(VPIF_CH2_BASE+offset)))
#define VPIF_CH3            (((VPIF_CHANNEL23_TypeDef*)(VPIF_CH3_BASE)))
#define VPIF_CH3_R(offset)  (*((__IO uint32_t *)(VPIF_CH3_BASE+offset)))


//todo registers


typedef enum
{
    VPIF_enOK = 0,
    VPIF_enERROR,
    VPIF_enTIMEOUT
} VPIF_nStatus;


void VPIF__vInitReceive(uint32_t u32BufferAddress, uint16_t u16Width);

#endif /* DSP_INCLUDE_VPIF_H_ */
