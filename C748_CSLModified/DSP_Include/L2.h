/*
 * CacheL1.h
 *
 *  Created on: 13/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_L2_H_
#define INCLUDE_L2_H_

#include "Core.h"
#include <stdint.h>

#define L2_BASE            ((uint32_t)0x01840000)

typedef __IO struct
{
    __IO uint32_t MODE       :3;
    __IO uint32_t CC         :1;
         uint32_t reserved0  :4;
    __IO uint32_t ID         :1;
    __IO uint32_t IP         :1;
         uint32_t reserved1  :6;
    __I  uint32_t MMID       :4;
         uint32_t reserved2  :4;
    __I  uint32_t NUMMM      :4;
         uint32_t reserved3  :4;
}L2_CFG_TypeDef;


typedef __IO struct
{
    __IO uint32_t INVALIDATE       :32;
}L2_IBAR_TypeDef;

typedef __IO struct
{
    __IO uint32_t INV_COUNT       :16;
         uint32_t reserved0       :16;
}L2_IWC_TypeDef;



typedef __IO struct
{
    __IO uint32_t WRITEBACK       :32;
}L2_WBAR_TypeDef;

typedef __IO struct
{
    __IO uint32_t WB_COUNT       :16;
         uint32_t reserved0       :16;
}L2_WWC_TypeDef;

typedef __IO struct
{
    __IO uint32_t WBINVALIDATE       :32;
}L2_WIBAR_TypeDef;

typedef __IO struct
{
    __IO uint32_t WBINV_COUNT       :16;
         uint32_t reserved0       :16;
}L2_WIWC_TypeDef;

typedef __IO struct
{
    __IO uint32_t I       :1;
        uint32_t reserved0       :31;
}L2_INV_TypeDef;

typedef __IO struct
{
    __IO uint32_t C       :1;
        uint32_t reserved0       :31;
}L2_WB_TypeDef;

typedef __IO struct
{
    __IO uint32_t C       :1;
        uint32_t reserved0       :31;
}L2_WBINV_TypeDef;

typedef __IO struct
{
    __IO uint32_t PC       :1;
        uint32_t reserved0       :31;
}L2_MAR_TypeDef;

typedef __IO struct
{
    __IO uint32_t UX       :1;
    __IO uint32_t UW       :1;
    __IO uint32_t UR       :1;
    __IO uint32_t SX       :1;
    __IO uint32_t SW       :1;
    __IO uint32_t SR       :1;
         uint32_t reserved0  :2;
    __IO uint32_t LOCAL      :1;
    __IO uint32_t AIDX      :1;
    __IO uint32_t AID0      :1;
    __IO uint32_t AID1      :1;
    __IO uint32_t AID2      :1;
    __IO uint32_t AID3      :1;
    __IO uint32_t AID4      :1;
    __IO uint32_t AID5      :1;
         uint32_t reserved1  :16;
}L2_MPPA_TypeDef;

typedef __IO struct
{
    __IO uint32_t LOCK       :32;
}L2_MPLK_TypeDef;

typedef __IO struct
{
    __IO uint32_t UNLOCK      :1;
    __IO uint32_t LOCK       :1;
    __IO uint32_t KEYR       :1;
         uint32_t reserved0  :29;
}L2_MPLKCMD_TypeDef;

typedef __IO struct
{
    __I uint32_t LK      :1;
         uint32_t reserved0  :31;
}L2_MPLKSTAT_TypeDef;

typedef __IO struct
{
    __I uint32_t ADDRESS      :32;
}L2_MPFAR_TypeDef;

typedef __IO struct
{
         uint32_t reserved0   :1;
         __I uint32_t UW      :1;
         __I uint32_t UR      :1;
         uint32_t reserved1   :1;
         __I uint32_t SW      :1;
         __I uint32_t SR      :1;
         uint32_t reserved2   :2;
         __I uint32_t LOCAL   :1;
         __I uint32_t FID     :7;
         uint32_t reserved3   :16;
}L2_MPFSR_TypeDef;

typedef __IO struct
{
    __IO uint32_t MPFCLR      :1;
         uint32_t reserved0   :31;
}L2_MPFCLR_TypeDef;

typedef __IO struct
{
    __IO uint32_t P0      :1;
    __IO uint32_t P1      :1;
         uint32_t reserved0   :30;
}L2_PDWAKE_TypeDef;

typedef __IO struct
{
    __IO uint32_t P0      :1;
    __IO uint32_t P1      :1;
         uint32_t reserved0   :30;
}L2_PDSLEEP_TypeDef;

typedef __IO struct
{
    __IO uint32_t P0      :1;
    __IO uint32_t P1      :1;
         uint32_t reserved0   :30;
}L2_PDSTAT_TypeDef;






typedef __IO struct
{
    union
    {
        __IO uint32_t       CFG;
        L2_CFG_TypeDef     CFG_Bit;
    };
    uint32_t Reserved0[4095];
    union
    {
        __IO uint32_t       WBAR;
        L2_WBAR_TypeDef    WBAR_Bit;
    };
    union
    {
        __IO uint32_t       WWC;
        L2_WWC_TypeDef     WWC_Bit;
    };
    uint32_t Reserved1[2];
    union
    {
        __IO uint32_t       WIBAR;
        L2_WIBAR_TypeDef    WIBAR_Bit;
    };
    union
    {
        __IO uint32_t       WIWC;
        L2_WIWC_TypeDef    WIWC_Bit;
    };
    union
    {
        __IO uint32_t       IBAR;
        L2_IBAR_TypeDef    IBAR_Bit;
    };
    union
    {
        __IO uint32_t       IWC;
        L2_IWC_TypeDef     IWC_Bit;
    };
    uint32_t Reserved2[1016];
    union
    {
        __IO uint32_t       WB;
        L2_WB_TypeDef    WB_Bit;
    };
    union
    {
        __IO uint32_t       WBINV;
        L2_WBINV_TypeDef   WBINV_Bit;
    };
    union
    {
        __IO uint32_t       INV;
        L2_INV_TypeDef    INV_Bit;
    };

    uint32_t Reserved3[3069];
    //uint32_t Reserved3[5869];

    union
    {
        __IO uint32_t       MAR[256];
        L2_MAR_TypeDef    MAR_Bit[256];
    };
    uint32_t Reserved4[1792];
    union
    {
        __I uint32_t       MPFAR;
        L2_MPFAR_TypeDef MPFAR_Bit;
    };

    union
    {
        __I uint32_t       MPFSR;
        L2_MPFSR_TypeDef  MPFSR_Bit;
    };

    union
    {
        __IO uint32_t       MPFCLR;
        L2_MPFCLR_TypeDef   MPFCLR_Bit;
    };

    uint32_t Reserved5[61];

    union
    {
        __IO uint32_t       MPLK[4];
        L2_MPLK_TypeDef    MPLK_Bit[4];
    };
    union
    {
        __IO uint32_t       MPLKCMD;
        L2_MPLKCMD_TypeDef MPLKCMD_Bit;
    };
    union
    {
        __IO uint32_t        MPLKSTAT;
        L2_MPLKSTAT_TypeDef MPLKSTAT_Bit;
    };

    uint32_t Reserved6[58];
    union
    {
        __IO uint32_t       MPPA[64];
        L2_MPPA_TypeDef    MPPA_Bit[64];
    };
    uint32_t Reserved7[1872];
    union
    {
        __IO uint32_t       PDWAKE[2];
        L2_PDWAKE_TypeDef   PDWAKE_Bit[2];
    };
    uint32_t Reserved8[2];
    union
    {
        __IO uint32_t       PDSLEEP[2];
        L2_PDSLEEP_TypeDef    PDSLEEP_Bit[2];
    };
    uint32_t Reserved9[2];
    union
    {
        __IO uint32_t       PDSTAT[2];
        L2_PDSTAT_TypeDef    PDSTAT_Bit[2];
    };

}L2_TypeDef;

#define L2            (((L2_TypeDef*)(L2_BASE)))
#define L2_R(offset)  (*((__IO uint32_t *)(L2_BASE+offset)))


#define L2_CFG_OFFSET      ((uint32_t)0x0000)

#define L2_WBAR_OFFSET     ((uint32_t)0x4000)
#define L2_WWC_OFFSET      ((uint32_t)0x4004)
#define L2_WIBAR_OFFSET    ((uint32_t)0x4010)
#define L2_WIWC_OFFSET     ((uint32_t)0x4014)
#define L2_IBAR_OFFSET     ((uint32_t)0x4018)
#define L2_IWC_OFFSET      ((uint32_t)0x401C)

#define L2_WB_OFFSET       ((uint32_t)0x5000)
#define L2_WBINV_OFFSET    ((uint32_t)0x5004)
#define L2_INV_OFFSET      ((uint32_t)0x5008)


#define L2_MAR0_OFFSET       ((uint32_t)0x8000)
#define L2_MAR1_OFFSET       ((uint32_t)0x8004)
#define L2_MAR2_OFFSET       ((uint32_t)0x8008)
#define L2_MAR3_OFFSET       ((uint32_t)0x800C)
#define L2_MAR4_OFFSET       ((uint32_t)0x8010)
#define L2_MAR5_OFFSET       ((uint32_t)0x8014)
#define L2_MAR6_OFFSET       ((uint32_t)0x8018)
#define L2_MAR7_OFFSET       ((uint32_t)0x801C)
#define L2_MAR8_OFFSET       ((uint32_t)0x8020)
#define L2_MAR9_OFFSET       ((uint32_t)0x8024)
#define L2_MAR10_OFFSET       ((uint32_t)0x8028)
#define L2_MAR11_OFFSET       ((uint32_t)0x802C)
#define L2_MAR12_OFFSET       ((uint32_t)0x8030)
#define L2_MAR13_OFFSET       ((uint32_t)0x8034)
#define L2_MAR14_OFFSET       ((uint32_t)0x8038)
#define L2_MAR15_OFFSET       ((uint32_t)0x803C)
#define L2_MAR16_OFFSET       ((uint32_t)0x8040)
#define L2_MAR17_OFFSET       ((uint32_t)0x8044)
#define L2_MAR18_OFFSET       ((uint32_t)0x8048)
#define L2_MAR19_OFFSET       ((uint32_t)0x804C)
#define L2_MAR20_OFFSET       ((uint32_t)0x8050)
#define L2_MAR21_OFFSET       ((uint32_t)0x8054)
#define L2_MAR22_OFFSET       ((uint32_t)0x8058)
#define L2_MAR23_OFFSET       ((uint32_t)0x805C)
#define L2_MAR24_OFFSET       ((uint32_t)0x8060)
#define L2_MAR25_OFFSET       ((uint32_t)0x8064)
#define L2_MAR26_OFFSET       ((uint32_t)0x8068)
#define L2_MAR27_OFFSET       ((uint32_t)0x806C)
#define L2_MAR28_OFFSET       ((uint32_t)0x8070)
#define L2_MAR29_OFFSET       ((uint32_t)0x8074)
#define L2_MAR30_OFFSET       ((uint32_t)0x8078)
#define L2_MAR31_OFFSET       ((uint32_t)0x807C)
#define L2_MAR32_OFFSET       ((uint32_t)0x8080)
#define L2_MAR33_OFFSET       ((uint32_t)0x8084)
#define L2_MAR34_OFFSET       ((uint32_t)0x8088)
#define L2_MAR35_OFFSET       ((uint32_t)0x808C)
#define L2_MAR36_OFFSET       ((uint32_t)0x8090)
#define L2_MAR37_OFFSET       ((uint32_t)0x8094)
#define L2_MAR38_OFFSET       ((uint32_t)0x8098)
#define L2_MAR39_OFFSET       ((uint32_t)0x809C)
#define L2_MAR40_OFFSET       ((uint32_t)0x80A0)
#define L2_MAR41_OFFSET       ((uint32_t)0x80A4)
#define L2_MAR42_OFFSET       ((uint32_t)0x80A8)
#define L2_MAR43_OFFSET       ((uint32_t)0x80AC)
#define L2_MAR44_OFFSET       ((uint32_t)0x80B0)
#define L2_MAR45_OFFSET       ((uint32_t)0x80B4)
#define L2_MAR46_OFFSET       ((uint32_t)0x80B8)
#define L2_MAR47_OFFSET       ((uint32_t)0x80BC)
#define L2_MAR48_OFFSET       ((uint32_t)0x80C0)
#define L2_MAR49_OFFSET       ((uint32_t)0x80C4)
#define L2_MAR50_OFFSET       ((uint32_t)0x80C8)
#define L2_MAR51_OFFSET       ((uint32_t)0x80CC)
#define L2_MAR52_OFFSET       ((uint32_t)0x80D0)
#define L2_MAR53_OFFSET       ((uint32_t)0x80D4)
#define L2_MAR54_OFFSET       ((uint32_t)0x80D8)
#define L2_MAR55_OFFSET       ((uint32_t)0x80DC)
#define L2_MAR56_OFFSET       ((uint32_t)0x80E0)
#define L2_MAR57_OFFSET       ((uint32_t)0x80E4)
#define L2_MAR58_OFFSET       ((uint32_t)0x80E8)
#define L2_MAR59_OFFSET       ((uint32_t)0x80EC)
#define L2_MAR60_OFFSET       ((uint32_t)0x80F0)
#define L2_MAR61_OFFSET       ((uint32_t)0x80F4)
#define L2_MAR62_OFFSET       ((uint32_t)0x80F8)
#define L2_MAR63_OFFSET       ((uint32_t)0x80FC)
#define L2_MAR64_OFFSET       ((uint32_t)0x8100)
#define L2_MAR65_OFFSET       ((uint32_t)0x8104)
#define L2_MAR66_OFFSET       ((uint32_t)0x8108)
#define L2_MAR67_OFFSET       ((uint32_t)0x810C)
#define L2_MAR68_OFFSET       ((uint32_t)0x8110)
#define L2_MAR69_OFFSET       ((uint32_t)0x8114)
#define L2_MAR70_OFFSET       ((uint32_t)0x8118)
#define L2_MAR71_OFFSET       ((uint32_t)0x811C)
#define L2_MAR72_OFFSET       ((uint32_t)0x8120)
#define L2_MAR73_OFFSET       ((uint32_t)0x8124)
#define L2_MAR74_OFFSET       ((uint32_t)0x8128)
#define L2_MAR75_OFFSET       ((uint32_t)0x812C)
#define L2_MAR76_OFFSET       ((uint32_t)0x8130)
#define L2_MAR77_OFFSET       ((uint32_t)0x8134)
#define L2_MAR78_OFFSET       ((uint32_t)0x8138)
#define L2_MAR79_OFFSET       ((uint32_t)0x813C)
#define L2_MAR80_OFFSET       ((uint32_t)0x8140)
#define L2_MAR81_OFFSET       ((uint32_t)0x8144)
#define L2_MAR82_OFFSET       ((uint32_t)0x8148)
#define L2_MAR83_OFFSET       ((uint32_t)0x814C)
#define L2_MAR84_OFFSET       ((uint32_t)0x8150)
#define L2_MAR85_OFFSET       ((uint32_t)0x8154)
#define L2_MAR86_OFFSET       ((uint32_t)0x8158)
#define L2_MAR87_OFFSET       ((uint32_t)0x815C)
#define L2_MAR88_OFFSET       ((uint32_t)0x8160)
#define L2_MAR89_OFFSET       ((uint32_t)0x8164)
#define L2_MAR90_OFFSET       ((uint32_t)0x8168)
#define L2_MAR91_OFFSET       ((uint32_t)0x816C)
#define L2_MAR92_OFFSET       ((uint32_t)0x8170)
#define L2_MAR93_OFFSET       ((uint32_t)0x8174)
#define L2_MAR94_OFFSET       ((uint32_t)0x8178)
#define L2_MAR95_OFFSET       ((uint32_t)0x817C)
#define L2_MAR96_OFFSET       ((uint32_t)0x8180)
#define L2_MAR97_OFFSET       ((uint32_t)0x8184)
#define L2_MAR98_OFFSET       ((uint32_t)0x8188)
#define L2_MAR99_OFFSET       ((uint32_t)0x818C)
#define L2_MAR100_OFFSET       ((uint32_t)0x8190)
#define L2_MAR101_OFFSET       ((uint32_t)0x8194)
#define L2_MAR102_OFFSET       ((uint32_t)0x8198)
#define L2_MAR103_OFFSET       ((uint32_t)0x819C)
#define L2_MAR104_OFFSET       ((uint32_t)0x81A0)
#define L2_MAR105_OFFSET       ((uint32_t)0x81A4)
#define L2_MAR106_OFFSET       ((uint32_t)0x81A8)
#define L2_MAR107_OFFSET       ((uint32_t)0x81AC)
#define L2_MAR108_OFFSET       ((uint32_t)0x81B0)
#define L2_MAR109_OFFSET       ((uint32_t)0x81B4)
#define L2_MAR110_OFFSET       ((uint32_t)0x81B8)
#define L2_MAR111_OFFSET       ((uint32_t)0x81BC)
#define L2_MAR112_OFFSET       ((uint32_t)0x81C0)
#define L2_MAR113_OFFSET       ((uint32_t)0x81C4)
#define L2_MAR114_OFFSET       ((uint32_t)0x81C8)
#define L2_MAR115_OFFSET       ((uint32_t)0x81CC)
#define L2_MAR116_OFFSET       ((uint32_t)0x81D0)
#define L2_MAR117_OFFSET       ((uint32_t)0x81D4)
#define L2_MAR118_OFFSET       ((uint32_t)0x81D8)
#define L2_MAR119_OFFSET       ((uint32_t)0x81DC)
#define L2_MAR120_OFFSET       ((uint32_t)0x81E0)
#define L2_MAR121_OFFSET       ((uint32_t)0x81E4)
#define L2_MAR122_OFFSET       ((uint32_t)0x81E8)
#define L2_MAR123_OFFSET       ((uint32_t)0x81EC)
#define L2_MAR124_OFFSET       ((uint32_t)0x81F0)
#define L2_MAR125_OFFSET       ((uint32_t)0x81F4)
#define L2_MAR126_OFFSET       ((uint32_t)0x81F8)
#define L2_MAR127_OFFSET       ((uint32_t)0x81FC)
#define L2_MAR128_OFFSET       ((uint32_t)0x8200)
#define L2_MAR129_OFFSET       ((uint32_t)0x8204)
#define L2_MAR130_OFFSET       ((uint32_t)0x8208)
#define L2_MAR131_OFFSET       ((uint32_t)0x820C)
#define L2_MAR132_OFFSET       ((uint32_t)0x8210)
#define L2_MAR133_OFFSET       ((uint32_t)0x8214)
#define L2_MAR134_OFFSET       ((uint32_t)0x8218)
#define L2_MAR135_OFFSET       ((uint32_t)0x821C)
#define L2_MAR136_OFFSET       ((uint32_t)0x8220)
#define L2_MAR137_OFFSET       ((uint32_t)0x8224)
#define L2_MAR138_OFFSET       ((uint32_t)0x8228)
#define L2_MAR139_OFFSET       ((uint32_t)0x822C)
#define L2_MAR140_OFFSET       ((uint32_t)0x8230)
#define L2_MAR141_OFFSET       ((uint32_t)0x8234)
#define L2_MAR142_OFFSET       ((uint32_t)0x8238)
#define L2_MAR143_OFFSET       ((uint32_t)0x823C)
#define L2_MAR144_OFFSET       ((uint32_t)0x8240)
#define L2_MAR145_OFFSET       ((uint32_t)0x8244)
#define L2_MAR146_OFFSET       ((uint32_t)0x8248)
#define L2_MAR147_OFFSET       ((uint32_t)0x824C)
#define L2_MAR148_OFFSET       ((uint32_t)0x8250)
#define L2_MAR149_OFFSET       ((uint32_t)0x8254)
#define L2_MAR150_OFFSET       ((uint32_t)0x8258)
#define L2_MAR151_OFFSET       ((uint32_t)0x825C)
#define L2_MAR152_OFFSET       ((uint32_t)0x8260)
#define L2_MAR153_OFFSET       ((uint32_t)0x8264)
#define L2_MAR154_OFFSET       ((uint32_t)0x8268)
#define L2_MAR155_OFFSET       ((uint32_t)0x826C)
#define L2_MAR156_OFFSET       ((uint32_t)0x8270)
#define L2_MAR157_OFFSET       ((uint32_t)0x8274)
#define L2_MAR158_OFFSET       ((uint32_t)0x8278)
#define L2_MAR159_OFFSET       ((uint32_t)0x827C)
#define L2_MAR160_OFFSET       ((uint32_t)0x8280)
#define L2_MAR161_OFFSET       ((uint32_t)0x8284)
#define L2_MAR162_OFFSET       ((uint32_t)0x8288)
#define L2_MAR163_OFFSET       ((uint32_t)0x828C)
#define L2_MAR164_OFFSET       ((uint32_t)0x8290)
#define L2_MAR165_OFFSET       ((uint32_t)0x8294)
#define L2_MAR166_OFFSET       ((uint32_t)0x8298)
#define L2_MAR167_OFFSET       ((uint32_t)0x829C)
#define L2_MAR168_OFFSET       ((uint32_t)0x82A0)
#define L2_MAR169_OFFSET       ((uint32_t)0x82A4)
#define L2_MAR170_OFFSET       ((uint32_t)0x82A8)
#define L2_MAR171_OFFSET       ((uint32_t)0x82AC)
#define L2_MAR172_OFFSET       ((uint32_t)0x82B0)
#define L2_MAR173_OFFSET       ((uint32_t)0x82B4)
#define L2_MAR174_OFFSET       ((uint32_t)0x82B8)
#define L2_MAR175_OFFSET       ((uint32_t)0x82BC)
#define L2_MAR176_OFFSET       ((uint32_t)0x82C0)
#define L2_MAR177_OFFSET       ((uint32_t)0x82C4)
#define L2_MAR178_OFFSET       ((uint32_t)0x82C8)
#define L2_MAR179_OFFSET       ((uint32_t)0x82CC)
#define L2_MAR180_OFFSET       ((uint32_t)0x82D0)
#define L2_MAR181_OFFSET       ((uint32_t)0x82D4)
#define L2_MAR182_OFFSET       ((uint32_t)0x82D8)
#define L2_MAR183_OFFSET       ((uint32_t)0x82DC)
#define L2_MAR184_OFFSET       ((uint32_t)0x82E0)
#define L2_MAR185_OFFSET       ((uint32_t)0x82E4)
#define L2_MAR186_OFFSET       ((uint32_t)0x82E8)
#define L2_MAR187_OFFSET       ((uint32_t)0x82EC)
#define L2_MAR188_OFFSET       ((uint32_t)0x82F0)
#define L2_MAR189_OFFSET       ((uint32_t)0x82F4)
#define L2_MAR190_OFFSET       ((uint32_t)0x82F8)
#define L2_MAR191_OFFSET       ((uint32_t)0x82FC)
#define L2_MAR192_OFFSET       ((uint32_t)0x8300)
#define L2_MAR193_OFFSET       ((uint32_t)0x8304)
#define L2_MAR194_OFFSET       ((uint32_t)0x8308)
#define L2_MAR195_OFFSET       ((uint32_t)0x830C)
#define L2_MAR196_OFFSET       ((uint32_t)0x8310)
#define L2_MAR197_OFFSET       ((uint32_t)0x8314)
#define L2_MAR198_OFFSET       ((uint32_t)0x8318)
#define L2_MAR199_OFFSET       ((uint32_t)0x831C)
#define L2_MAR200_OFFSET       ((uint32_t)0x8320)
#define L2_MAR201_OFFSET       ((uint32_t)0x8324)
#define L2_MAR202_OFFSET       ((uint32_t)0x8328)
#define L2_MAR203_OFFSET       ((uint32_t)0x832C)
#define L2_MAR204_OFFSET       ((uint32_t)0x8330)
#define L2_MAR205_OFFSET       ((uint32_t)0x8334)
#define L2_MAR206_OFFSET       ((uint32_t)0x8338)
#define L2_MAR207_OFFSET       ((uint32_t)0x833C)
#define L2_MAR208_OFFSET       ((uint32_t)0x8340)
#define L2_MAR209_OFFSET       ((uint32_t)0x8344)
#define L2_MAR210_OFFSET       ((uint32_t)0x8348)
#define L2_MAR211_OFFSET       ((uint32_t)0x834C)
#define L2_MAR212_OFFSET       ((uint32_t)0x8350)
#define L2_MAR213_OFFSET       ((uint32_t)0x8354)
#define L2_MAR214_OFFSET       ((uint32_t)0x8358)
#define L2_MAR215_OFFSET       ((uint32_t)0x835C)
#define L2_MAR216_OFFSET       ((uint32_t)0x8360)
#define L2_MAR217_OFFSET       ((uint32_t)0x8364)
#define L2_MAR218_OFFSET       ((uint32_t)0x8368)
#define L2_MAR219_OFFSET       ((uint32_t)0x836C)
#define L2_MAR220_OFFSET       ((uint32_t)0x8370)
#define L2_MAR221_OFFSET       ((uint32_t)0x8374)
#define L2_MAR222_OFFSET       ((uint32_t)0x8378)
#define L2_MAR223_OFFSET       ((uint32_t)0x837C)
#define L2_MAR224_OFFSET       ((uint32_t)0x8380)
#define L2_MAR225_OFFSET       ((uint32_t)0x8384)
#define L2_MAR226_OFFSET       ((uint32_t)0x8388)
#define L2_MAR227_OFFSET       ((uint32_t)0x838C)
#define L2_MAR228_OFFSET       ((uint32_t)0x8390)
#define L2_MAR229_OFFSET       ((uint32_t)0x8394)
#define L2_MAR230_OFFSET       ((uint32_t)0x8398)
#define L2_MAR231_OFFSET       ((uint32_t)0x839C)
#define L2_MAR232_OFFSET       ((uint32_t)0x83A0)
#define L2_MAR233_OFFSET       ((uint32_t)0x83A4)
#define L2_MAR234_OFFSET       ((uint32_t)0x83A8)
#define L2_MAR235_OFFSET       ((uint32_t)0x83AC)
#define L2_MAR236_OFFSET       ((uint32_t)0x83B0)
#define L2_MAR237_OFFSET       ((uint32_t)0x83B4)
#define L2_MAR238_OFFSET       ((uint32_t)0x83B8)
#define L2_MAR239_OFFSET       ((uint32_t)0x83BC)
#define L2_MAR240_OFFSET       ((uint32_t)0x83C0)
#define L2_MAR241_OFFSET       ((uint32_t)0x83C4)
#define L2_MAR242_OFFSET       ((uint32_t)0x83C8)
#define L2_MAR243_OFFSET       ((uint32_t)0x83CC)
#define L2_MAR244_OFFSET       ((uint32_t)0x83D0)
#define L2_MAR245_OFFSET       ((uint32_t)0x83D4)
#define L2_MAR246_OFFSET       ((uint32_t)0x83D8)
#define L2_MAR247_OFFSET       ((uint32_t)0x83DC)
#define L2_MAR248_OFFSET       ((uint32_t)0x83E0)
#define L2_MAR249_OFFSET       ((uint32_t)0x83E4)
#define L2_MAR250_OFFSET       ((uint32_t)0x83E8)
#define L2_MAR251_OFFSET       ((uint32_t)0x83EC)
#define L2_MAR252_OFFSET       ((uint32_t)0x83F0)
#define L2_MAR253_OFFSET       ((uint32_t)0x83F4)
#define L2_MAR254_OFFSET       ((uint32_t)0x83F8)
#define L2_MAR255_OFFSET       ((uint32_t)0x83FC)


#define L2_MPFAR_OFFSET    ((uint32_t)0xA000)
#define L2_MPFSR_OFFSET    ((uint32_t)0xA004)
#define L2_MPFCLR_OFFSET   ((uint32_t)0xA008)

#define L2_MPLK0_OFFSET    ((uint32_t)0xA100)
#define L2_MPLK1_OFFSET    ((uint32_t)0xA104)
#define L2_MPLK2_OFFSET    ((uint32_t)0xA108)
#define L2_MPLK3_OFFSET    ((uint32_t)0A10C)
#define L2_MPLKCMD_OFFSET  ((uint32_t)0xA110)
#define L2_MPLKSTAT_OFFSET ((uint32_t)0xA114)


#define L2_MPPA0_OFFSET    ((uint32_t)0xA200)
#define L2_MPPA1_OFFSET    ((uint32_t)0xA204)
#define L2_MPPA2_OFFSET    ((uint32_t)0xA208)
#define L2_MPPA3_OFFSET    ((uint32_t)0xA20C)
#define L2_MPPA4_OFFSET    ((uint32_t)0xA210)
#define L2_MPPA5_OFFSET    ((uint32_t)0xA214)
#define L2_MPPA6_OFFSET    ((uint32_t)0xA218)
#define L2_MPPA7_OFFSET    ((uint32_t)0xA21C)
#define L2_MPPA8_OFFSET    ((uint32_t)0xA220)
#define L2_MPPA9_OFFSET    ((uint32_t)0xA224)
#define L2_MPPA10_OFFSET    ((uint32_t)0xA228)
#define L2_MPPA11_OFFSET    ((uint32_t)0xA22C)
#define L2_MPPA12_OFFSET    ((uint32_t)0xA230)
#define L2_MPPA13_OFFSET    ((uint32_t)0xA234)
#define L2_MPPA14_OFFSET    ((uint32_t)0xA238)
#define L2_MPPA15_OFFSET    ((uint32_t)0xA23C)
#define L2_MPPA16_OFFSET    ((uint32_t)0xA240)
#define L2_MPPA17_OFFSET    ((uint32_t)0xA244)
#define L2_MPPA18_OFFSET    ((uint32_t)0xA248)
#define L2_MPPA19_OFFSET    ((uint32_t)0xA24C)
#define L2_MPPA20_OFFSET    ((uint32_t)0xA250)
#define L2_MPPA21_OFFSET    ((uint32_t)0xA254)
#define L2_MPPA22_OFFSET    ((uint32_t)0xA258)
#define L2_MPPA23_OFFSET    ((uint32_t)0xA25C)
#define L2_MPPA24_OFFSET    ((uint32_t)0xA260)
#define L2_MPPA25_OFFSET    ((uint32_t)0xA264)
#define L2_MPPA26_OFFSET    ((uint32_t)0xA268)
#define L2_MPPA27_OFFSET    ((uint32_t)0xA26C)
#define L2_MPPA28_OFFSET    ((uint32_t)0xA270)
#define L2_MPPA29_OFFSET    ((uint32_t)0xA274)
#define L2_MPPA30_OFFSET    ((uint32_t)0xA278)
#define L2_MPPA31_OFFSET    ((uint32_t)0xA27C)
#define L2_MPPA32_OFFSET    ((uint32_t)0xA280)
#define L2_MPPA33_OFFSET    ((uint32_t)0xA284)
#define L2_MPPA34_OFFSET    ((uint32_t)0xA288)
#define L2_MPPA35_OFFSET    ((uint32_t)0xA28C)
#define L2_MPPA36_OFFSET    ((uint32_t)0xA290)
#define L2_MPPA37_OFFSET    ((uint32_t)0xA294)
#define L2_MPPA38_OFFSET    ((uint32_t)0xA298)
#define L2_MPPA39_OFFSET    ((uint32_t)0xA29C)
#define L2_MPPA40_OFFSET    ((uint32_t)0xA2A0)
#define L2_MPPA41_OFFSET    ((uint32_t)0xA2A4)
#define L2_MPPA42_OFFSET    ((uint32_t)0xA2A8)
#define L2_MPPA43_OFFSET    ((uint32_t)0xA2AC)
#define L2_MPPA44_OFFSET    ((uint32_t)0xA2B0)
#define L2_MPPA45_OFFSET    ((uint32_t)0xA2B4)
#define L2_MPPA46_OFFSET    ((uint32_t)0xA2B8)
#define L2_MPPA47_OFFSET    ((uint32_t)0xA2BC)
#define L2_MPPA48_OFFSET    ((uint32_t)0xA2C0)
#define L2_MPPA49_OFFSET    ((uint32_t)0xA2C4)
#define L2_MPPA50_OFFSET    ((uint32_t)0xA2C8)
#define L2_MPPA51_OFFSET    ((uint32_t)0xA2CC)
#define L2_MPPA52_OFFSET    ((uint32_t)0xA2D0)
#define L2_MPPA53_OFFSET    ((uint32_t)0xA2D4)
#define L2_MPPA54_OFFSET    ((uint32_t)0xA2D8)
#define L2_MPPA55_OFFSET    ((uint32_t)0xA2DC)
#define L2_MPPA56_OFFSET    ((uint32_t)0xA2E0)
#define L2_MPPA57_OFFSET    ((uint32_t)0xA2E4)
#define L2_MPPA58_OFFSET    ((uint32_t)0xA2E8)
#define L2_MPPA59_OFFSET    ((uint32_t)0xA2EC)
#define L2_MPPA60_OFFSET    ((uint32_t)0xA2F0)
#define L2_MPPA61_OFFSET    ((uint32_t)0xA2F4)
#define L2_MPPA62_OFFSET    ((uint32_t)0xA2F8)
#define L2_MPPA63_OFFSET    ((uint32_t)0xA2FC)


#define L2_PDWAKE0_OFFSET    ((uint32_t)0xC040)
#define L2_PDWAKE1_OFFSET    ((uint32_t)0xC044)
#define L2_PDSLEEP0_OFFSET   ((uint32_t)0xC050)
#define L2_PDSLEEP1_OFFSET   ((uint32_t)0xC054)
#define L2_PDSTAT0_OFFSET    ((uint32_t)0xC060)
#define L2_PDSTAT1_OFFSET    ((uint32_t)0xC064)

/**********************************************************************************************
************************************** 2 CFG ***********************************************
**********************************************************************************************/
#define L2_CFG                    (((L2_CFG_TypeDef*)(L2_BASE+L2_CFG_OFFSET )))
#define L2_CFG_R                  (*((__IO uint32_t *)(L2_BASE+L2_CFG_OFFSET)))


/*--------*/
#define L2_CFG_R_MODE_MASK        ((uint32_t)0x00000007)
#define L2_CFG_R_MODE_SHIFT         (0)

#define L2_CFG_MODE_MASK          ((uint32_t)0x00000007)
/*--------*/

/*--------*/
#define L2_CFG_R_LCC_MASK        ((uint32_t)0x00000008)
#define L2_CFG_R_LCC_SHIFT         (3)

#define L2_CFG_LCC_MASK          ((uint32_t)0x00000008)
/*--------*/

/*--------*/
#define L2_CFG_R_ID_MASK        ((uint32_t)0x00000100)
#define L2_CFG_R_ID_SHIFT         (8)

#define L2_CFG_ID_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_CFG_R_IP_MASK        ((uint32_t)0x00000200)
#define L2_CFG_R_IP_SHIFT         (9)

#define L2_CFG_IP_MASK          ((uint32_t)0x00000002)
/*--------*/

/*--------*/
#define L2_CFG_R_MMID_MASK        ((uint32_t)0x000F0000)
#define L2_CFG_R_MMID_SHIFT         (16)

#define L2_CFG_MMID_MASK          ((uint32_t)0x0000000F)
/*--------*/

/*--------*/
#define L2_CFG_R_NUMMM_MASK        ((uint32_t)0x0F000000)
#define L2_CFG_R_NUMMM_SHIFT         (24)

#define L2_CFG_NUMMM_MASK          ((uint32_t)0x0000000F)
/*--------*/


/**********************************************************************************************
************************************** 3 IBAR ***********************************************
**********************************************************************************************/
#define L2_IBAR                    (((L2_IBAR_TypeDef*)(L2_BASE+L2_IBAR_OFFSET )))
#define L2_IBAR_R                  (*((__IO uint32_t *)(L2_BASE+L2_IBAR_OFFSET)))


/*--------*/
#define L2_IBAR_R_INVALIDATE_MASK        ((uint32_t)0xFFFFFFFF)
#define L2_IBAR_R_INVALIDATE_SHIFT         (0)

#define L2_IBAR_INVALIDATE_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 4 IWC ***********************************************
**********************************************************************************************/
#define L2_IWC                    (((L2_IWC_TypeDef*)(L2_BASE+L2_IWC_OFFSET )))
#define L2_IWC_R                  (*((__IO uint32_t *)(L2_BASE+L2_IWC_OFFSET)))


/*--------*/
#define L2_IWC_R_INV_COUNT_MASK        ((uint32_t)0x0000FFFF)
#define L2_IWC_R_INV_COUNT_SHIFT         (0)

#define L2_IWC_INV_COUNT_MASK          ((uint32_t)0x0000FFFF)
/*--------*/


/**********************************************************************************************
************************************** 3 WBAR ***********************************************
**********************************************************************************************/
#define L2_WBAR                    (((L2_WBAR_TypeDef*)(L2_BASE+L2_WBAR_OFFSET )))
#define L2_WBAR_R                  (*((__IO uint32_t *)(L2_BASE+L2_WBAR_OFFSET)))


/*--------*/
#define L2_WBAR_R_INVALIDATE_MASK        ((uint32_t)0xFFFFFFFF)
#define L2_WBAR_R_INVALIDATE_SHIFT         (0)

#define L2_WBAR_INVALIDATE_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 4 WWC ***********************************************
**********************************************************************************************/
#define L2_WWC                    (((L2_WWC_TypeDef*)(L2_BASE+L2_WWC_OFFSET )))
#define L2_WWC_R                  (*((__IO uint32_t *)(L2_BASE+L2_WWC_OFFSET)))


/*--------*/
#define L2_WWC_R_WB_COUNT_MASK        ((uint32_t)0x0000FFFF)
#define L2_WWC_R_WB_COUNT_SHIFT         (0)

#define L2_WWC_WB_COUNT_MASK          ((uint32_t)0x0000FFFF)
/*--------*/



/**********************************************************************************************
************************************** 3 WIBAR ***********************************************
**********************************************************************************************/
#define L2_WIBAR                    (((L2_WIBAR_TypeDef*)(L2_BASE+L2_WIBAR_OFFSET )))
#define L2_WIBAR_R                  (*((__IO uint32_t *)(L2_BASE+L2_WIBAR_OFFSET)))


/*--------*/
#define L2_WIBAR_R_WBINVALIDATE_MASK        ((uint32_t)0xFFFFFFFF)
#define L2_WIBAR_R_WBINVALIDATE_SHIFT         (0)

#define L2_WIBAR_WBINVALIDATE_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 4 WIWC ***********************************************
**********************************************************************************************/
#define L2_WIWC                    (((L2_WIWC_TypeDef*)(L2_BASE+L2_WIWC_OFFSET )))
#define L2_WIWC_R                  (*((__IO uint32_t *)(L2_BASE+L2_WIWC_OFFSET)))


/*--------*/
#define L2_WIWC_R_WBINV_COUNT_MASK        ((uint32_t)0x0000FFFF)
#define L2_WIWC_R_WBINV_COUNT_SHIFT         (0)

#define L2_WIWC_WBINV_COUNT_MASK          ((uint32_t)0x0000FFFF)
/*--------*/



/**********************************************************************************************
************************************** 5 INV ***********************************************
**********************************************************************************************/
#define L2_INV                    (((L2_INV_TypeDef*)(L2_BASE+L2_INV_OFFSET )))
#define L2_INV_R                  (*((__IO uint32_t *)(L2_BASE+L2_INV_OFFSET)))


/*--------*/
#define L2_INV_R_I_MASK        ((uint32_t)0x00000001)
#define L2_INV_R_I_SHIFT         (0)

#define L2_INV_I_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 5 WB ***********************************************
**********************************************************************************************/
#define L2_WB                    (((L2_WB_TypeDef*)(L2_BASE+L2_WB_OFFSET )))
#define L2_WB_R                  (*((__IO uint32_t *)(L2_BASE+L2_WB_OFFSET)))


/*--------*/
#define L2_WB_R_C_MASK        ((uint32_t)0x00000001)
#define L2_WB_R_C_SHIFT         (0)

#define L2_WB_C_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 5 WBINV ***********************************************
**********************************************************************************************/
#define L2_WBINV                    (((L2_WBINV_TypeDef*)(L2_BASE+L2_WBINV_OFFSET )))
#define L2_WBINV_R                  (*((__IO uint32_t *)(L2_BASE+L2_WBINV_OFFSET)))


/*--------*/
#define L2_WBINV_R_C_MASK        ((uint32_t)0x00000001)
#define L2_WBINV_R_C_SHIFT         (0)

#define L2_WBINV_C_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 6-28 MPPA ***********************************************
**********************************************************************************************/
#define L2_MPPA0                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA0_OFFSET )))
#define L2_MPPA0_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA0_OFFSET)))
#define L2_MPPA1                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA1_OFFSET )))
#define L2_MPPA1_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA1_OFFSET)))
#define L2_MPPA2                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA2_OFFSET )))
#define L2_MPPA2_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA2_OFFSET)))
#define L2_MPPA3                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA3_OFFSET )))
#define L2_MPPA3_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA3_OFFSET)))
#define L2_MPPA4                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA4_OFFSET )))
#define L2_MPPA4_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA4_OFFSET)))
#define L2_MPPA5                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA5_OFFSET )))
#define L2_MPPA5_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA5_OFFSET)))
#define L2_MPPA6                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA6_OFFSET )))
#define L2_MPPA6_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA6_OFFSET)))
#define L2_MPPA7                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA7_OFFSET )))
#define L2_MPPA7_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA7_OFFSET)))
#define L2_MPPA8                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA8_OFFSET )))
#define L2_MPPA8_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA8_OFFSET)))
#define L2_MPPA9                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA9_OFFSET )))
#define L2_MPPA9_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA9_OFFSET)))
#define L2_MPPA10                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA10_OFFSET )))
#define L2_MPPA10_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA10_OFFSET)))
#define L2_MPPA11                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA11_OFFSET )))
#define L2_MPPA11_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA11_OFFSET)))
#define L2_MPPA12                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA12_OFFSET )))
#define L2_MPPA12_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA12_OFFSET)))
#define L2_MPPA13                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA13_OFFSET )))
#define L2_MPPA13_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA13_OFFSET)))
#define L2_MPPA14                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA14_OFFSET )))
#define L2_MPPA14_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA14_OFFSET)))
#define L2_MPPA15                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA15_OFFSET )))
#define L2_MPPA15_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA15_OFFSET)))
#define L2_MPPA16                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA16_OFFSET )))
#define L2_MPPA16_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA16_OFFSET)))
#define L2_MPPA17                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA17_OFFSET )))
#define L2_MPPA17_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA17_OFFSET)))
#define L2_MPPA18                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA18_OFFSET )))
#define L2_MPPA18_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA18_OFFSET)))
#define L2_MPPA19                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA19_OFFSET )))
#define L2_MPPA19_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA19_OFFSET)))
#define L2_MPPA20                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA20_OFFSET )))
#define L2_MPPA20_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA20_OFFSET)))
#define L2_MPPA21                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA21_OFFSET )))
#define L2_MPPA21_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA21_OFFSET)))
#define L2_MPPA22                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA22_OFFSET )))
#define L2_MPPA22_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA22_OFFSET)))
#define L2_MPPA23                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA23_OFFSET )))
#define L2_MPPA23_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA23_OFFSET)))
#define L2_MPPA24                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA24_OFFSET )))
#define L2_MPPA24_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA24_OFFSET)))
#define L2_MPPA25                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA25_OFFSET )))
#define L2_MPPA25_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA25_OFFSET)))
#define L2_MPPA26                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA26_OFFSET )))
#define L2_MPPA26_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA26_OFFSET)))
#define L2_MPPA27                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA27_OFFSET )))
#define L2_MPPA27_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA27_OFFSET)))
#define L2_MPPA28                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA28_OFFSET )))
#define L2_MPPA28_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA28_OFFSET)))
#define L2_MPPA29                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA29_OFFSET )))
#define L2_MPPA29_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA29_OFFSET)))
#define L2_MPPA30                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA30_OFFSET )))
#define L2_MPPA30_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA30_OFFSET)))
#define L2_MPPA31                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA31_OFFSET )))
#define L2_MPPA31_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA31_OFFSET)))
#define L2_MPPA32                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA32_OFFSET )))
#define L2_MPPA32_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA32_OFFSET)))
#define L2_MPPA33                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA33_OFFSET )))
#define L2_MPPA33_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA33_OFFSET)))
#define L2_MPPA34                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA34_OFFSET )))
#define L2_MPPA34_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA34_OFFSET)))
#define L2_MPPA35                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA35_OFFSET )))
#define L2_MPPA35_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA35_OFFSET)))
#define L2_MPPA36                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA36_OFFSET )))
#define L2_MPPA36_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA36_OFFSET)))
#define L2_MPPA37                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA37_OFFSET )))
#define L2_MPPA37_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA37_OFFSET)))
#define L2_MPPA38                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA38_OFFSET )))
#define L2_MPPA38_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA38_OFFSET)))
#define L2_MPPA39                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA39_OFFSET )))
#define L2_MPPA39_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA39_OFFSET)))
#define L2_MPPA40                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA40_OFFSET )))
#define L2_MPPA40_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA40_OFFSET)))
#define L2_MPPA41                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA41_OFFSET )))
#define L2_MPPA41_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA41_OFFSET)))
#define L2_MPPA42                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA42_OFFSET )))
#define L2_MPPA42_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA42_OFFSET)))
#define L2_MPPA43                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA43_OFFSET )))
#define L2_MPPA43_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA43_OFFSET)))
#define L2_MPPA44                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA44_OFFSET )))
#define L2_MPPA44_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA44_OFFSET)))
#define L2_MPPA45                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA45_OFFSET )))
#define L2_MPPA45_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA45_OFFSET)))
#define L2_MPPA46                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA46_OFFSET )))
#define L2_MPPA46_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA46_OFFSET)))
#define L2_MPPA47                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA47_OFFSET )))
#define L2_MPPA47_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA47_OFFSET)))
#define L2_MPPA48                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA48_OFFSET )))
#define L2_MPPA48_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA48_OFFSET)))
#define L2_MPPA49                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA49_OFFSET )))
#define L2_MPPA49_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA49_OFFSET)))
#define L2_MPPA50                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA50_OFFSET )))
#define L2_MPPA50_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA50_OFFSET)))
#define L2_MPPA51                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA51_OFFSET )))
#define L2_MPPA51_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA51_OFFSET)))
#define L2_MPPA52                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA52_OFFSET )))
#define L2_MPPA52_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA52_OFFSET)))
#define L2_MPPA53                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA53_OFFSET )))
#define L2_MPPA53_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA53_OFFSET)))
#define L2_MPPA54                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA54_OFFSET )))
#define L2_MPPA54_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA54_OFFSET)))
#define L2_MPPA55                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA55_OFFSET )))
#define L2_MPPA55_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA55_OFFSET)))
#define L2_MPPA56                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA56_OFFSET )))
#define L2_MPPA56_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA56_OFFSET)))
#define L2_MPPA57                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA57_OFFSET )))
#define L2_MPPA57_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA57_OFFSET)))
#define L2_MPPA58                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA58_OFFSET )))
#define L2_MPPA58_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA58_OFFSET)))
#define L2_MPPA59                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA59_OFFSET )))
#define L2_MPPA59_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA59_OFFSET)))
#define L2_MPPA60                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA60_OFFSET )))
#define L2_MPPA60_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA60_OFFSET)))
#define L2_MPPA61                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA61_OFFSET )))
#define L2_MPPA61_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA61_OFFSET)))
#define L2_MPPA62                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA62_OFFSET )))
#define L2_MPPA62_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA62_OFFSET)))
#define L2_MPPA63                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA63_OFFSET )))
#define L2_MPPA63_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA63_OFFSET)))
#define L2_MPPA(n)                    (((L2_MPPA_TypeDef*)(L2_BASE+L2_MPPA0_OFFSET +((n)*4) )))
#define L2_MPPA_R(n)                  (*((__IO uint32_t *)(L2_BASE+L2_MPPA0_OFFSET +((n)*4))))


/*--------*/
#define L2_MPPA_R_UX_MASK        ((uint32_t)0x00000001)
#define L2_MPPA_R_UX_SHIFT         (0)

#define L2_MPPA_UX_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPPA_R_UW_MASK        ((uint32_t)0x00000002)
#define L2_MPPA_R_UW_SHIFT         (1)

#define L2_MPPA_UW_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPPA_R_UR_MASK        ((uint32_t)0x00000004)
#define L2_MPPA_R_UR_SHIFT         (2)

#define L2_MPPA_UR_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPPA_R_SX_MASK        ((uint32_t)0x00000008)
#define L2_MPPA_R_SX_SHIFT         (3)

#define L2_MPPA_SX_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPPA_R_SW_MASK        ((uint32_t)0x00000010)
#define L2_MPPA_R_SW_SHIFT         (4)

#define L2_MPPA_SW_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPPA_R_SR_MASK        ((uint32_t)0x00000020)
#define L2_MPPA_R_SR_SHIFT         (5)

#define L2_MPPA_SR_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPPA_R_LOCAL_MASK        ((uint32_t)0x00000100)
#define L2_MPPA_R_LOCAL_SHIFT         (8)

#define L2_MPPA_LOCAL_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPPA_R_AIDX_MASK        ((uint32_t)0x00000200)
#define L2_MPPA_R_AIDX_SHIFT         (9)

#define L2_MPPA_AIDX_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPPA_R_AID0_MASK        ((uint32_t)0x00000400)
#define L2_MPPA_R_AID0_SHIFT         (10)

#define L2_MPPA_AID0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPPA_R_AID1_MASK        ((uint32_t)0x00000800)
#define L2_MPPA_R_AID1_SHIFT         (11)

#define L2_MPPA_AID1_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPPA_R_AID2_MASK        ((uint32_t)0x00001000)
#define L2_MPPA_R_AID2_SHIFT         (12)

#define L2_MPPA_AID2_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPPA_R_AID3_MASK        ((uint32_t)0x00002000)
#define L2_MPPA_R_AID3_SHIFT         (13)

#define L2_MPPA_AID3_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPPA_R_AID4_MASK        ((uint32_t)0x00004000)
#define L2_MPPA_R_AID4_SHIFT         (14)

#define L2_MPPA_AID4_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPPA_R_AID5_MASK        ((uint32_t)0x00008000)
#define L2_MPPA_R_AID5_SHIFT         (15)

#define L2_MPPA_AID5_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 29-32 MPLK ***********************************************
**********************************************************************************************/
#define L2_MPLK0                    (((L2_MPLK_TypeDef*)(L2_BASE+L2_MPLK0_OFFSET )))
#define L2_MPLK0_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPLK0_OFFSET)))
#define L2_MPLK1                    (((L2_MPLK_TypeDef*)(L2_BASE+L2_MPLK1_OFFSET )))
#define L2_MPLK1_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPLK1_OFFSET)))
#define L2_MPLK2                    (((L2_MPLK_TypeDef*)(L2_BASE+L2_MPLK2_OFFSET )))
#define L2_MPLK2_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPLK2_OFFSET)))
#define L2_MPLK3                    (((L2_MPLK_TypeDef*)(L2_BASE+L2_MPLK3_OFFSET )))
#define L2_MPLK3_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPLK3_OFFSET)))


/*--------*/
#define L2_MPLK_R_LOCK_MASK        ((uint32_t)0xFFFFFFFF)
#define L2_MPLK_R_LOCK_SHIFT         (0)

#define L2_MPLK_LOCK_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


/**********************************************************************************************
************************************** 33 MPLKCMD ***********************************************
**********************************************************************************************/
#define L2_MPLKCMD                    (((L2_MPLKCMD_TypeDef*)(L2_BASE+L2_MPLKCMD_OFFSET )))
#define L2_MPLKCMD_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPLKCMD_OFFSET)))

/*--------*/
#define L2_MPLKCMD_R_UNLOCK_MASK        ((uint32_t)0x00000001)
#define L2_MPLKCMD_R_UNLOCK_SHIFT         (0)

#define L2_MPLKCMD_UNLOCK_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPLKCMD_R_LOCK_MASK        ((uint32_t)0x00000002)
#define L2_MPLKCMD_R_LOCK_SHIFT         (1)

#define L2_MPLKCMD_LOCK_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPLKCMD_R_KEYR_MASK        ((uint32_t)0x00000004)
#define L2_MPLKCMD_R_KEYR_SHIFT         (2)

#define L2_MPLKCMD_KEYR_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 34 MPLKSTAT ***********************************************
**********************************************************************************************/
#define L2_MPLKSTAT                    (((L2_MPLKSTAT_TypeDef*)(L2_BASE+L2_MPLKSTAT_OFFSET )))
#define L2_MPLKSTAT_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPLKSTAT_OFFSET)))

/*--------*/
#define L2_MPLKSTAT_R_LK_MASK        ((uint32_t)0x00000001)
#define L2_MPLKSTAT_R_LK_SHIFT         (0)

#define L2_MPLKSTAT_LK_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 35 MPFAR ***********************************************
**********************************************************************************************/
#define L2_MPFAR                    (((L2_MPFAR_TypeDef*)(L2_BASE+L2_MPFAR_OFFSET )))
#define L2_MPFAR_R                  (*((__I uint32_t *)(L2_BASE+L2_MPFAR_OFFSET)))

/*--------*/
#define L2_MPFAR_R_ADDRESS_MASK        ((uint32_t)0xFFFFFFFF)
#define L2_MPFAR_R_ADDRESS_SHIFT         (0)

#define L2_MPFAR_ADDRESS_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


/**********************************************************************************************
************************************** 36 MPFSR ***********************************************
**********************************************************************************************/
#define L2_MPFSR                    (((L2_MPFSR_TypeDef*)(L2_BASE+L2_MPFSR_OFFSET )))
#define L2_MPFSR_R                  (*((__I uint32_t *)(L2_BASE+L2_MPFSR_OFFSET)))

/*--------*/
#define L2_MPFSR_R_UW_MASK        ((uint32_t)0x00000002)
#define L2_MPFSR_R_UW_SHIFT         (1)

#define L2_MPFSR_UW_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPFSR_R_UR_MASK        ((uint32_t)0x00000004)
#define L2_MPFSR_R_UR_SHIFT         (2)

#define L2_MPFSR_UR_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPFSR_R_SW_MASK        ((uint32_t)0x00000010)
#define L2_MPFSR_R_SW_SHIFT         (4)

#define L2_MPFSR_SW_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPFSR_R_SR_MASK        ((uint32_t)0x00000020)
#define L2_MPFSR_R_SR_SHIFT         (2)

#define L2_MPFSR_SR_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPFSR_R_LOCAL_MASK        ((uint32_t)0x00000100)
#define L2_MPFSR_R_LOCAL_SHIFT         (8)

#define L2_MPFSR_LOCAL_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define L2_MPFSR_R_FID_MASK        ((uint32_t)0x0000FE00)
#define L2_MPFSR_R_FID_SHIFT         (9)

#define L2_MPFSR_FID_MASK          ((uint32_t)0x0000007F)
/*--------*/


/**********************************************************************************************
************************************** 36 MPFCLR ***********************************************
**********************************************************************************************/
#define L2_MPFCLR                    (((L2_MPFCLR_TypeDef*)(L2_BASE+L2_MPFCLR_OFFSET )))
#define L2_MPFCLR_R                  (*((__IO uint32_t *)(L2_BASE+L2_MPFCLR_OFFSET)))

/*--------*/
#define L2_MPFCLR_R_MPFCLR_MASK        ((uint32_t)0x00000001)
#define L2_MPFCLR_R_MPFCLR_SHIFT         (0)

#define L2_MPFCLR_MPFCLR_MASK          ((uint32_t)0x00000001)
/*--------*/


/**********************************************************************************************
************************************** 36 PDWAKE ***********************************************
**********************************************************************************************/
#define L2_PDWAKE0                    (((L2_PDWAKE_TypeDef*)(L2_BASE+L2_PDWAKE0_OFFSET )))
#define L2_PDWAKE0_R                  (*((__IO uint32_t *)(L2_BASE+L2_PDWAKE0_OFFSET)))
#define L2_PDWAKE1                    (((L2_PDWAKE_TypeDef*)(L2_BASE+L2_PDWAKE1_OFFSET )))
#define L2_PDWAKE1_R                  (*((__IO uint32_t *)(L2_BASE+L2_PDWAKE1_OFFSET)))
/*--------*/
#define L2_PDWAKE_R_P0_MASK        ((uint32_t)0x00000001)
#define L2_PDWAKE_R_P0_SHIFT         (0)
#define L2_PDWAKE_R_P1_MASK        ((uint32_t)0x00000002)
#define L2_PDWAKE_R_P1_SHIFT         (1)

#define L2_PDWAKE_P0_MASK          ((uint32_t)0x00000001)
#define L2_PDWAKE_P1_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 36 PDSLEEP ***********************************************
**********************************************************************************************/
#define L2_PDSLEEP0                    (((L2_PDSLEEP_TypeDef*)(L2_BASE+L2_PDSLEEP0_OFFSET )))
#define L2_PDSLEEP0_R                  (*((__IO uint32_t *)(L2_BASE+L2_PDSLEEP0_OFFSET)))
#define L2_PDSLEEP1                    (((L2_PDSLEEP_TypeDef*)(L2_BASE+L2_PDSLEEP1_OFFSET )))
#define L2_PDSLEEP1_R                  (*((__IO uint32_t *)(L2_BASE+L2_PDSLEEP1_OFFSET)))
/*--------*/
#define L2_PDSLEEP_R_P0_MASK        ((uint32_t)0x00000001)
#define L2_PDSLEEP_R_P0_SHIFT         (0)
#define L2_PDSLEEP_R_P1_MASK        ((uint32_t)0x00000002)
#define L2_PDSLEEP_R_P1_SHIFT         (1)

#define L2_PDSLEEP_P0_MASK          ((uint32_t)0x00000001)
#define L2_PDSLEEP_P1_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 36 PDSTAT ***********************************************
**********************************************************************************************/
#define L2_PDSTAT0                    (((L2_PDSTAT_TypeDef*)(L2_BASE+L2_PDSTAT0_OFFSET )))
#define L2_PDSTAT0_R                  (*((__IO uint32_t *)(L2_BASE+L2_PDSTAT0_OFFSET)))
#define L2_PDSTAT1                    (((L2_PDSTAT_TypeDef*)(L2_BASE+L2_PDSTAT1_OFFSET )))
#define L2_PDSTAT1_R                  (*((__IO uint32_t *)(L2_BASE+L2_PDSTAT1_OFFSET)))
/*--------*/
#define L2_PDSTAT_R_P0_MASK        ((uint32_t)0x00000001)
#define L2_PDSTAT_R_P0_SHIFT         (0)
#define L2_PDSTAT_R_P1_MASK        ((uint32_t)0x00000002)
#define L2_PDSTAT_R_P1_SHIFT         (1)

#define L2_PDSTAT_P0_MASK          ((uint32_t)0x00000001)
#define L2_PDSTAT_P1_MASK          ((uint32_t)0x00000001)
/*--------*/




/**********************************************************************************************
************************************** 36 PDSTAT ***********************************************
**********************************************************************************************/

#define L2_MAR(n)                    (((L2_MAR_TypeDef*)(L2_BASE+L2_MAR0_OFFSET +((n)*4) )))
#define L2_MAR_R(n)                  (*((__IO uint32_t *)(L2_BASE+L2_MAR0_OFFSET +((n)*4))))



#endif /* INCLUDE_L2_H_ */

