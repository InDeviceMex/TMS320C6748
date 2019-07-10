/*
 * GPIO.h
 *
 *  Created on: 21/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_


#include "Core.h"
#include <stdint.h>

#define GPIO_BASE            ((uint32_t)0x01E26000)
#define GPIO0_BASE           ((uint32_t)0x01E26010)
#define GPIO1_BASE           ((uint32_t)0x01E26012)
#define GPIO2_BASE           ((uint32_t)0x01E26038)
#define GPIO3_BASE           ((uint32_t)0x01E26040)
#define GPIO4_BASE           ((uint32_t)0x01E26060)
#define GPIO5_BASE           ((uint32_t)0x01E26062)
#define GPIO6_BASE           ((uint32_t)0x01E26088)
#define GPIO7_BASE           ((uint32_t)0x01E2608A)
#define GPIO8_BASE           ((uint32_t)0x01E260B0)

typedef __IO struct
{
    __I uint32_t REV       :32;
}GPIO_REVID_TypeDef;

typedef __IO struct
{
    __IO uint32_t EN0       :1;
    __IO uint32_t EN1       :1;
    __IO uint32_t EN2       :1;
    __IO uint32_t EN3       :1;
    __IO uint32_t EN4       :1;
    __IO uint32_t EN5       :1;
    __IO uint32_t EN6       :1;
    __IO uint32_t EN7       :1;
    __IO uint32_t EN8       :1;
         uint32_t reserved0 :23;
}GPIO_BINTEN_TypeDef;

typedef __IO struct
{
    __IO uint32_t GP0P0       :1;
    __IO uint32_t GP0P1       :1;
    __IO uint32_t GP0P2       :1;
    __IO uint32_t GP0P3       :1;
    __IO uint32_t GP0P4       :1;
    __IO uint32_t GP0P5       :1;
    __IO uint32_t GP0P6       :1;
    __IO uint32_t GP0P7       :1;
    __IO uint32_t GP0P8       :1;
    __IO uint32_t GP0P9       :1;
    __IO uint32_t GP0P10       :1;
    __IO uint32_t GP0P11       :1;
    __IO uint32_t GP0P12       :1;
    __IO uint32_t GP0P13       :1;
    __IO uint32_t GP0P14       :1;
    __IO uint32_t GP0P15       :1;
    __IO uint32_t GP1P0       :1;
    __IO uint32_t GP1P1       :1;
    __IO uint32_t GP1P2       :1;
    __IO uint32_t GP1P3       :1;
    __IO uint32_t GP1P4       :1;
    __IO uint32_t GP1P5       :1;
    __IO uint32_t GP1P6       :1;
    __IO uint32_t GP1P7       :1;
    __IO uint32_t GP1P8       :1;
    __IO uint32_t GP1P9       :1;
    __IO uint32_t GP1P10       :1;
    __IO uint32_t GP1P11       :1;
    __IO uint32_t GP1P12       :1;
    __IO uint32_t GP1P13       :1;
    __IO uint32_t GP1P14       :1;
    __IO uint32_t GP1P15       :1;
}GPIO_BANK01_TypeDef;

typedef __IO struct
{
    __IO uint32_t GP2P0       :1;
    __IO uint32_t GP2P1       :1;
    __IO uint32_t GP2P2       :1;
    __IO uint32_t GP2P3       :1;
    __IO uint32_t GP2P4       :1;
    __IO uint32_t GP2P5       :1;
    __IO uint32_t GP2P6       :1;
    __IO uint32_t GP2P7       :1;
    __IO uint32_t GP2P8       :1;
    __IO uint32_t GP2P9       :1;
    __IO uint32_t GP2P10       :1;
    __IO uint32_t GP2P11       :1;
    __IO uint32_t GP2P12       :1;
    __IO uint32_t GP2P13       :1;
    __IO uint32_t GP2P14       :1;
    __IO uint32_t GP2P15       :1;
    __IO uint32_t GP3P0       :1;
    __IO uint32_t GP3P1       :1;
    __IO uint32_t GP3P2       :1;
    __IO uint32_t GP3P3       :1;
    __IO uint32_t GP3P4       :1;
    __IO uint32_t GP3P5       :1;
    __IO uint32_t GP3P6       :1;
    __IO uint32_t GP3P7       :1;
    __IO uint32_t GP3P8       :1;
    __IO uint32_t GP3P9       :1;
    __IO uint32_t GP3P10       :1;
    __IO uint32_t GP3P11       :1;
    __IO uint32_t GP3P12       :1;
    __IO uint32_t GP3P13       :1;
    __IO uint32_t GP3P14       :1;
    __IO uint32_t GP3P15       :1;
}GPIO_BANK23_TypeDef;


typedef __IO struct
{
    __IO uint32_t GP4P0       :1;
    __IO uint32_t GP4P1       :1;
    __IO uint32_t GP4P2       :1;
    __IO uint32_t GP4P3       :1;
    __IO uint32_t GP4P4       :1;
    __IO uint32_t GP4P5       :1;
    __IO uint32_t GP4P6       :1;
    __IO uint32_t GP4P7       :1;
    __IO uint32_t GP4P8       :1;
    __IO uint32_t GP4P9       :1;
    __IO uint32_t GP4P10       :1;
    __IO uint32_t GP4P11       :1;
    __IO uint32_t GP4P12       :1;
    __IO uint32_t GP4P13       :1;
    __IO uint32_t GP4P14       :1;
    __IO uint32_t GP4P15       :1;
    __IO uint32_t GP5P0       :1;
    __IO uint32_t GP5P1       :1;
    __IO uint32_t GP5P2       :1;
    __IO uint32_t GP5P3       :1;
    __IO uint32_t GP5P4       :1;
    __IO uint32_t GP5P5       :1;
    __IO uint32_t GP5P6       :1;
    __IO uint32_t GP5P7       :1;
    __IO uint32_t GP5P8       :1;
    __IO uint32_t GP5P9       :1;
    __IO uint32_t GP5P10       :1;
    __IO uint32_t GP5P11       :1;
    __IO uint32_t GP5P12       :1;
    __IO uint32_t GP5P13       :1;
    __IO uint32_t GP5P14       :1;
    __IO uint32_t GP5P15       :1;
}GPIO_BANK45_TypeDef;


typedef __IO struct
{
    __IO uint32_t GP6P0       :1;
    __IO uint32_t GP6P1       :1;
    __IO uint32_t GP6P2       :1;
    __IO uint32_t GP6P3       :1;
    __IO uint32_t GP6P4       :1;
    __IO uint32_t GP6P5       :1;
    __IO uint32_t GP6P6       :1;
    __IO uint32_t GP6P7       :1;
    __IO uint32_t GP6P8       :1;
    __IO uint32_t GP6P9       :1;
    __IO uint32_t GP6P10       :1;
    __IO uint32_t GP6P11       :1;
    __IO uint32_t GP6P12       :1;
    __IO uint32_t GP6P13       :1;
    __IO uint32_t GP6P14       :1;
    __IO uint32_t GP6P15       :1;
    __IO uint32_t GP7P0       :1;
    __IO uint32_t GP7P1       :1;
    __IO uint32_t GP7P2       :1;
    __IO uint32_t GP7P3       :1;
    __IO uint32_t GP7P4       :1;
    __IO uint32_t GP7P5       :1;
    __IO uint32_t GP7P6       :1;
    __IO uint32_t GP7P7       :1;
    __IO uint32_t GP7P8       :1;
    __IO uint32_t GP7P9       :1;
    __IO uint32_t GP7P10       :1;
    __IO uint32_t GP7P11       :1;
    __IO uint32_t GP7P12       :1;
    __IO uint32_t GP7P13       :1;
    __IO uint32_t GP7P14       :1;
    __IO uint32_t GP7P15       :1;
}GPIO_BANK67_TypeDef;

typedef __IO struct
{
    __IO uint32_t GP8P0       :1;
    __IO uint32_t GP8P1       :1;
    __IO uint32_t GP8P2       :1;
    __IO uint32_t GP8P3       :1;
    __IO uint32_t GP8P4       :1;
    __IO uint32_t GP8P5       :1;
    __IO uint32_t GP8P6       :1;
    __IO uint32_t GP8P7       :1;
    __IO uint32_t GP8P8       :1;
    __IO uint32_t GP8P9       :1;
    __IO uint32_t GP8P10       :1;
    __IO uint32_t GP8P11       :1;
    __IO uint32_t GP8P12       :1;
    __IO uint32_t GP8P13       :1;
    __IO uint32_t GP8P14       :1;
    __IO uint32_t GP8P15       :1;
         uint32_t reserved0       :16;
}GPIO_BANK8_TypeDef;

typedef __IO struct
{
    __IO uint16_t P0       :1;
    __IO uint16_t P1       :1;
    __IO uint16_t P2       :1;
    __IO uint16_t P3       :1;
    __IO uint16_t P4       :1;
    __IO uint16_t P5       :1;
    __IO uint16_t P6       :1;
    __IO uint16_t P7       :1;
    __IO uint16_t P8       :1;
    __IO uint16_t P9       :1;
    __IO uint16_t P10       :1;
    __IO uint16_t P11       :1;
    __IO uint16_t P12       :1;
    __IO uint16_t P13       :1;
    __IO uint16_t P14       :1;
    __IO uint16_t P15       :1;
}GPIO_REG_TypeDef;



typedef struct  {

    union
    {
        __IO uint32_t            REVID;
        GPIO_REVID_TypeDef         REVID_Bit;
    };
    uint32_t reserved0[1];
    union
    {
        __IO uint32_t            BINTEN;
        GPIO_BINTEN_TypeDef      BINTEN_Bit;
    };
    uint32_t reserved1[1];
    union
    {
        __IO uint32_t            DIR01;
        GPIO_BANK01_TypeDef      DIR01_Bit;
    };
    union
    {
        __IO uint32_t            SET_DATA01;
        GPIO_BANK01_TypeDef      SET_DATA01_Bit;
    };
    union
    {
        __IO uint32_t            CLR_DATA01;
        GPIO_BANK01_TypeDef      CLR_DATA01_Bit;
    };
    union
    {
        __IO uint32_t            IN_DATA01;
        GPIO_BANK01_TypeDef      IN_DATA01_Bit;
    };
    union
    {
        __IO uint32_t            SET_RIS_TRIG01;
        GPIO_BANK01_TypeDef      SET_RIS_TRIG01_Bit;
    };
    union
    {
        __IO uint32_t            CLR_RIS_TRIG01;
        GPIO_BANK01_TypeDef      CLR_RIS_TRIG01_Bit;
    };
    union
    {
        __IO uint32_t            SET_FAL_TRIG01;
        GPIO_BANK01_TypeDef      SET_FAL_TRIG01_Bit;
    };
    union
    {
        __IO uint32_t            CLR_FAL_TRIG01;
        GPIO_BANK01_TypeDef      CLR_FAL_TRIG01_Bit;
    };
    union
    {
        __IO uint32_t            INTSTAT01;
        GPIO_BANK01_TypeDef      INTSTAT01_Bit;
    };
    union
    {
        __IO uint32_t            DIR23;
        GPIO_BANK23_TypeDef      DIR23_Bit;
    };
    union
    {
        __IO uint32_t            SET_DATA23;
        GPIO_BANK23_TypeDef      SET_DATA23_Bit;
    };
    union
    {
        __IO uint32_t            CLR_DATA23;
        GPIO_BANK23_TypeDef      CLR_DATA23_Bit;
    };
    union
    {
        __IO uint32_t            IN_DATA23;
        GPIO_BANK23_TypeDef      IN_DATA23_Bit;
    };
    union
    {
        __IO uint32_t            SET_RIS_TRIG23;
        GPIO_BANK23_TypeDef      SET_RIS_TRIG23_Bit;
    };
    union
    {
        __IO uint32_t            CLR_RIS_TRIG23;
        GPIO_BANK23_TypeDef      CLR_RIS_TRIG23_Bit;
    };
    union
    {
        __IO uint32_t            SET_FAL_TRIG23;
        GPIO_BANK23_TypeDef      SET_FAL_TRIG23_Bit;
    };
    union
    {
        __IO uint32_t            CLR_FAL_TRIG23;
        GPIO_BANK23_TypeDef      CLR_FAL_TRIG23_Bit;
    };
    union
    {
        __IO uint32_t            INTSTAT23;
        GPIO_BANK23_TypeDef      INTSTAT23_Bit;
    };
    union
    {
        __IO uint32_t            DIR45;
        GPIO_BANK45_TypeDef      DIR45_Bit;
    };
    union
    {
        __IO uint32_t            SET_DATA45;
        GPIO_BANK45_TypeDef      SET_DATA45_Bit;
    };
    union
    {
        __IO uint32_t            CLR_DATA45;
        GPIO_BANK45_TypeDef      CLR_DATA45_Bit;
    };
    union
    {
        __IO uint32_t            IN_DATA45;
        GPIO_BANK45_TypeDef      IN_DATA45_Bit;
    };
    union
    {
        __IO uint32_t            SET_RIS_TRIG45;
        GPIO_BANK45_TypeDef      SET_RIS_TRIG45_Bit;
    };
    union
    {
        __IO uint32_t            CLR_RIS_TRIG45;
        GPIO_BANK45_TypeDef      CLR_RIS_TRIG45_Bit;
    };
    union
    {
        __IO uint32_t            SET_FAL_TRIG45;
        GPIO_BANK45_TypeDef      SET_FAL_TRIG45_Bit;
    };
    union
    {
        __IO uint32_t            CLR_FAL_TRIG45;
        GPIO_BANK45_TypeDef      CLR_FAL_TRIG45_Bit;
    };
    union
    {
        __IO uint32_t            INTSTAT45;
        GPIO_BANK45_TypeDef      INTSTAT45_Bit;
    };
    union
    {
        __IO uint32_t            DIR67;
        GPIO_BANK67_TypeDef      DIR67_Bit;
    };
    union
    {
        __IO uint32_t            SET_DATA67;
        GPIO_BANK67_TypeDef      SET_DATA67_Bit;
    };
    union
    {
        __IO uint32_t            CLR_DATA67;
        GPIO_BANK67_TypeDef      CLR_DATA67_Bit;
    };
    union
    {
        __IO uint32_t            IN_DATA67;
        GPIO_BANK67_TypeDef      IN_DATA67_Bit;
    };
    union
    {
        __IO uint32_t            SET_RIS_TRIG67;
        GPIO_BANK67_TypeDef      SET_RIS_TRIG67_Bit;
    };
    union
    {
        __IO uint32_t            CLR_RIS_TRIG67;
        GPIO_BANK67_TypeDef      CLR_RIS_TRIG67_Bit;
    };
    union
    {
        __IO uint32_t            SET_FAL_TRIG67;
        GPIO_BANK67_TypeDef      SET_FAL_TRIG67_Bit;
    };
    union
    {
        __IO uint32_t            CLR_FAL_TRIG67;
        GPIO_BANK67_TypeDef      CLR_FAL_TRIG67_Bit;
    };
    union
    {
        __IO uint32_t            INTSTAT67;
        GPIO_BANK67_TypeDef      INTSTAT67_Bit;
    };
    union
    {
        __IO uint32_t            DIR8;
        GPIO_BANK8_TypeDef      DIR8_Bit;
    };
    union
    {
        __IO uint32_t            SET_DATA8;
        GPIO_BANK8_TypeDef      SET_DATA8_Bit;
    };
    union
    {
        __IO uint32_t            CLR_DATA8;
        GPIO_BANK8_TypeDef      CLR_DATA8_Bit;
    };
    union
    {
        __IO uint32_t            IN_DATA8;
        GPIO_BANK8_TypeDef      IN_DATA8_Bit;
    };
    union
    {
        __IO uint32_t            SET_RIS_TRIG8;
        GPIO_BANK8_TypeDef      SET_RIS_TRIG8_Bit;
    };
    union
    {
        __IO uint32_t            CLR_RIS_TRIG8;
        GPIO_BANK8_TypeDef      CLR_RIS_TRIG8_Bit;
    };
    union
    {
        __IO uint32_t            SET_FAL_TRIG8;
        GPIO_BANK8_TypeDef      SET_FAL_TRIG8_Bit;
    };
    union
    {
        __IO uint32_t            CLR_FAL_TRIG8;
        GPIO_BANK8_TypeDef      CLR_FAL_TRIG8_Bit;
    };
    union
    {
        __IO uint32_t            INTSTAT8;
        GPIO_BANK8_TypeDef      INTSTAT8_Bit;
    };
} GPIO_TypeDef;

typedef struct  {

    union
    {
        __IO uint16_t            DIR;
        GPIO_REG_TypeDef         DIR_Bit;
    };
    uint16_t reserved0[1];
    union
    {
        __IO uint16_t            OUT_DATA;
        GPIO_REG_TypeDef         OUT_DATA_Bit;
    };
    uint16_t reserved1[1];
    union
    {
        __IO uint16_t            SET_DATA;
        GPIO_REG_TypeDef         SET_DATA_Bit;
    };
    uint16_t reserved2[1];
    union
    {
        __IO uint16_t            CLR_DATA;
        GPIO_REG_TypeDef         CLR_DATA_Bit;
    };
    uint16_t reserved3[1];
    union
    {
        __IO uint16_t            IN_DATA;
        GPIO_REG_TypeDef         IN_DATA_Bit;
    };
    uint16_t reserved4[1];
    union
    {
        __IO uint16_t            SET_RIS_TRIG;
        GPIO_REG_TypeDef         SET_RIS_TRIG_Bit;
    };
    uint16_t reserved5[1];
    union
    {
        __IO uint16_t            CLR_RIS_TRIG;
        GPIO_REG_TypeDef         CLR_RIS_TRIG_Bit;
    };
    uint16_t reserved6[1];
    union
    {
        __IO uint16_t            SET_FAL_TRIG;
        GPIO_REG_TypeDef         SET_FAL_TRIG_Bit;
    };
    uint16_t reserved7[1];
    union
    {
        __IO uint16_t            CLR_FAL_TRIG;
        GPIO_REG_TypeDef         CLR_FAL_TRIG_Bit;
    };
    uint16_t reserved8[1];
    union
    {
        __IO uint16_t            INTSTAT;
        GPIO_REG_TypeDef         INTSTAT_Bit;
    };
    uint16_t reserved9[1];

} GPIO_BANK_PAR_TypeDef;



typedef struct  {

    uint16_t reserved0[1];
    union
    {
        __IO uint16_t            DIR;
        GPIO_REG_TypeDef         DIR_Bit;
    };
    uint16_t reserved1[1];
    union
    {
        __IO uint16_t            OUT_DATA;
        GPIO_REG_TypeDef         OUT_DATA_Bit;
    };
    uint16_t reserved2[1];
    union
    {
        __IO uint16_t            SET_DATA;
        GPIO_REG_TypeDef         SET_DATA_Bit;
    };
    uint16_t reserved3[1];
    union
    {
        __IO uint16_t            CLR_DATA;
        GPIO_REG_TypeDef         CLR_DATA_Bit;
    };
    uint16_t reserved4[1];
    union
    {
        __IO uint16_t            IN_DATA;
        GPIO_REG_TypeDef         IN_DATA_Bit;
    };
    uint16_t reserved5[1];
    union
    {
        __IO uint16_t            SET_RIS_TRIG;
        GPIO_REG_TypeDef         SET_RIS_TRIG_Bit;
    };
    uint16_t reserved6[1];
    union
    {
        __IO uint16_t            CLR_RIS_TRIG;
        GPIO_REG_TypeDef         CLR_RIS_TRIG_Bit;
    };
    uint16_t reserved7[1];
    union
    {
        __IO uint16_t            SET_FAL_TRIG;
        GPIO_REG_TypeDef         SET_FAL_TRIG_Bit;
    };
    uint16_t reserved8[1];
    union
    {
        __IO uint16_t            CLR_FAL_TRIG;
        GPIO_REG_TypeDef         CLR_FAL_TRIG_Bit;
    };
    uint16_t reserved9[1];
    union
    {
        __IO uint16_t            INTSTAT;
        GPIO_REG_TypeDef         INTSTAT_Bit;
    };
} GPIO_BANK_IMPAR_TypeDef;


typedef struct  {

    union
    {
        __IO uint32_t            DIR;
        GPIO_BANK01_TypeDef         DIR_Bit;
    };
    union
    {
        __IO uint32_t            OUT_DATA;
        GPIO_BANK01_TypeDef         OUT_DATA_Bit;
    };
    union
    {
        __IO uint32_t            SET_DATA;
        GPIO_BANK01_TypeDef         SET_DATA_Bit;
    };
    union
    {
        __IO uint32_t            CLR_DATA;
        GPIO_BANK01_TypeDef         CLR_DATA_Bit;
    };
    union
    {
        __IO uint32_t            IN_DATA;
        GPIO_BANK01_TypeDef         IN_DATA_Bit;
    };
    union
    {
        __IO uint32_t            SET_RIS_TRIG;
        GPIO_BANK01_TypeDef         SET_RIS_TRIG_Bit;
    };
    union
    {
        __IO uint32_t            CLR_RIS_TRIG;
        GPIO_BANK01_TypeDef         CLR_RIS_TRIG_Bit;
    };
    union
    {
        __IO uint32_t            SET_FAL_TRIG;
        GPIO_BANK01_TypeDef         SET_FAL_TRIG_Bit;
    };
    union
    {
        __IO uint32_t            CLR_FAL_TRIG;
        GPIO_BANK01_TypeDef         CLR_FAL_TRIG_Bit;
    };
    union
    {
        __IO uint32_t            INTSTAT;
        GPIO_BANK01_TypeDef         INTSTAT_Bit;
    };

} GPIO_BANK_TypeDef;


#define GPIO            (((GPIO_TypeDef*)(GPIO_BASE)))
#define GPIO_R(offset)  (*((__IO uint32_t *)(GPIO_BASE+offset)))

#define GPIO0            (((GPIO_BANK_PAR_TypeDef*)(GPIO0_BASE)))
#define GPIO0_R(offset)  (*((__IO uint32_t *)(GPIO0_BASE+offset)))

#define GPIO1            (((GPIO_BANK_IMPAR_TypeDef*)(GPIO0_BASE)))
#define GPIO1_R(offset)  (*((__IO uint32_t *)(GPIO0_BASE+offset)))

#define GPIO2            (((GPIO_BANK_PAR_TypeDef*)(GPIO2_BASE)))
#define GPIO2_R(offset)  (*((__IO uint32_t *)(GPIO2_BASE+offset)))

#define GPIO3            (((GPIO_BANK_IMPAR_TypeDef*)(GPIO2_BASE)))
#define GPIO3_R(offset)  (*((__IO uint32_t *)(GPIO2_BASE+offset)))

#define GPIO4            (((GPIO_BANK_PAR_TypeDef*)(GPIO4_BASE)))
#define GPIO4_R(offset)  (*((__IO uint32_t *)(GPIO4_BASE+offset)))

#define GPIO5            (((GPIO_BANK_IMPAR_TypeDef*)(GPIO4_BASE)))
#define GPIO5_R(offset)  (*((__IO uint32_t *)(GPIO4_BASE+offset)))

#define GPIO6            (((GPIO_BANK_PAR_TypeDef*)(GPIO6_BASE)))
#define GPIO6_R(offset)  (*((__IO uint32_t *)(GPIO6_BASE+offset)))

#define GPIO7            (((GPIO_BANK_IMPAR_TypeDef*)(GPIO6_BASE)))
#define GPIO7_R(offset)  (*((__IO uint32_t *)(GPIO6_BASE+offset)))

#define GPIO8            (((GPIO_BANK_PAR_TypeDef*)(GPIO8_BASE)))
#define GPIO8_R(offset)  (*((__IO uint32_t *)(GPIO8_BASE+offset)))

#define GPIO01            (((GPIO_BANK_TypeDef*)(GPIO0_BASE)))
#define GPIO01_R(offset)  (*((__IO uint32_t *)(GPIO0_BASE+offset)))

#define GPIO23            (((GPIO_BANK_TypeDef*)(GPIO2_BASE)))
#define GPIO23_R(offset)  (*((__IO uint32_t *)(GPIO2_BASE+offset)))

#define GPIO45            (((GPIO_BANK_TypeDef*)(GPIO4_BASE)))
#define GPIO45_R(offset)  (*((__IO uint32_t *)(GPIO4_BASE+offset)))

#define GPIO67            (((GPIO_BANK_TypeDef*)(GPIO6_BASE)))
#define GPIO67_R(offset)  (*((__IO uint32_t *)(GPIO6_BASE+offset)))


#define GPIO_BANK_DIR_OFFSET                 ((uint32_t)0x0000)
#define GPIO_BANK_OUT_DATA_OFFSET            ((uint32_t)0x0004)
#define GPIO_BANK_SET_DATA_OFFSET            ((uint32_t)0x0008)
#define GPIO_BANK_CLR_DATA_OFFSET            ((uint32_t)0x000C)
#define GPIO_BANK_IN_DATA_OFFSET             ((uint32_t)0x0010)
#define GPIO_BANK_SET_RIS_TRIG_OFFSET        ((uint32_t)0x0014)
#define GPIO_BANK_CLR_RIS_TRIG_OFFSET        ((uint32_t)0x0018)
#define GPIO_BANK_SET_FAL_TRIG_OFFSET        ((uint32_t)0x001C)
#define GPIO_BANK_CLR_FAL_TRIG_OFFSET        ((uint32_t)0x0020)
#define GPIO_BANK_INTSTAT_OFFSET             ((uint32_t)0x0024)

#define GPIO_BANK_PAR_DIR_OFFSET                 ((uint32_t)0x0000)
#define GPIO_BANK_PAR_OUT_DATA_OFFSET            ((uint32_t)0x0004)
#define GPIO_BANK_PAR_SET_DATA_OFFSET            ((uint32_t)0x0008)
#define GPIO_BANK_PAR_CLR_DATA_OFFSET            ((uint32_t)0x000C)
#define GPIO_BANK_PAR_IN_DATA_OFFSET             ((uint32_t)0x0010)
#define GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET        ((uint32_t)0x0014)
#define GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET        ((uint32_t)0x0018)
#define GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET        ((uint32_t)0x001C)
#define GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET        ((uint32_t)0x0020)
#define GPIO_BANK_PAR_INTSTAT_OFFSET             ((uint32_t)0x0024)

#define GPIO_BANK_IMPAR_DIR_OFFSET                 ((uint32_t)0x0002)
#define GPIO_BANK_IMPAR_OUT_DATA_OFFSET            ((uint32_t)0x0006)
#define GPIO_BANK_IMPAR_SET_DATA_OFFSET            ((uint32_t)0x000A)
#define GPIO_BANK_IMPAR_CLR_DATA_OFFSET            ((uint32_t)0x000E)
#define GPIO_BANK_IMPAR_IN_DATA_OFFSET             ((uint32_t)0x0012)
#define GPIO_BANK_IMPAR_SET_RIS_TRIG_OFFSET        ((uint32_t)0x0016)
#define GPIO_BANK_IMPAR_CLR_RIS_TRIG_OFFSET        ((uint32_t)0x001A)
#define GPIO_BANK_IMPAR_SET_FAL_TRIG_OFFSET        ((uint32_t)0x001E)
#define GPIO_BANK_IMPAR_CLR_FAL_TRIG_OFFSET        ((uint32_t)0x0022)
#define GPIO_BANK_IMPAR_INTSTAT_OFFSET             ((uint32_t)0x0026)

#define GPIO_REVID_OFFSET           ((uint32_t)0x0000)
#define GPIO_BINTEN_OFFSET          ((uint32_t)0x0008)
#define GPIO_DIR01_OFFSET           ((uint32_t)0x0010)
#define GPIO_OUT_DATA01_OFFSET      ((uint32_t)0x0014)
#define GPIO_SET_DATA01_OFFSET      ((uint32_t)0x0018)
#define GPIO_CLR_DATA01_OFFSET      ((uint32_t)0x001C)
#define GPIO_IN_DATA01_OFFSET       ((uint32_t)0x0020)
#define GPIO_SET_RIS_TRIG01_OFFSET  ((uint32_t)0x0024)
#define GPIO_CLR_RIS_TRIG01_OFFSET  ((uint32_t)0x0028)
#define GPIO_SET_FAL_TRIG01_OFFSET  ((uint32_t)0x002C)
#define GPIO_CLR_FAL_TRIG01_OFFSET  ((uint32_t)0x0030)
#define GPIO_INTSTAT01_OFFSET       ((uint32_t)0x0034)
#define GPIO_DIR23_OFFSET           ((uint32_t)0x0038)
#define GPIO_OUT_DATA23_OFFSET      ((uint32_t)0x003C)
#define GPIO_SET_DATA23_OFFSET      ((uint32_t)0x0040)
#define GPIO_CLR_DATA23_OFFSET      ((uint32_t)0x0044)
#define GPIO_IN_DATA23_OFFSET       ((uint32_t)0x0048)
#define GPIO_SET_RIS_TRIG23_OFFSET  ((uint32_t)0x004C)
#define GPIO_CLR_RIS_TRIG23_OFFSET  ((uint32_t)0x0050)
#define GPIO_SET_FAL_TRIG23_OFFSET  ((uint32_t)0x0054)
#define GPIO_CLR_FAL_TRIG23_OFFSET  ((uint32_t)0x0058)
#define GPIO_INTSTAT23_OFFSET       ((uint32_t)0x005C)
#define GPIO_DIR45_OFFSET           ((uint32_t)0x0060)
#define GPIO_OUT_DATA45_OFFSET      ((uint32_t)0x0064)
#define GPIO_SET_DATA45_OFFSET      ((uint32_t)0x0068)
#define GPIO_CLR_DATA45_OFFSET      ((uint32_t)0x006C)
#define GPIO_IN_DATA45_OFFSET       ((uint32_t)0x0070)
#define GPIO_SET_RIS_TRIG45_OFFSET  ((uint32_t)0x0074)
#define GPIO_CLR_RIS_TRIG45_OFFSET  ((uint32_t)0x0078)
#define GPIO_SET_FAL_TRIG45_OFFSET  ((uint32_t)0x007C)
#define GPIO_CLR_FAL_TRIG45_OFFSET  ((uint32_t)0x0080)
#define GPIO_INTSTAT45_OFFSET       ((uint32_t)0x0084)
#define GPIO_DIR67_OFFSET           ((uint32_t)0x0088)
#define GPIO_OUT_DATA67_OFFSET      ((uint32_t)0x008C)
#define GPIO_SET_DATA67_OFFSET      ((uint32_t)0x0090)
#define GPIO_CLR_DATA67_OFFSET      ((uint32_t)0x0094)
#define GPIO_IN_DATA67_OFFSET       ((uint32_t)0x0098)
#define GPIO_SET_RIS_TRIG67_OFFSET  ((uint32_t)0x009C)
#define GPIO_CLR_RIS_TRIG67_OFFSET  ((uint32_t)0x00A0)
#define GPIO_SET_FAL_TRIG67_OFFSET  ((uint32_t)0x00A4)
#define GPIO_CLR_FAL_TRIG67_OFFSET  ((uint32_t)0x00A8)
#define GPIO_INTSTAT67_OFFSET       ((uint32_t)0x00AC)
#define GPIO_DIR8_OFFSET           ((uint32_t)0x00B0)
#define GPIO_OUT_DATA8_OFFSET      ((uint32_t)0x00B4)
#define GPIO_SET_DATA8_OFFSET      ((uint32_t)0x00B8)
#define GPIO_CLR_DATA8_OFFSET      ((uint32_t)0x00BC)
#define GPIO_IN_DATA8_OFFSET       ((uint32_t)0x00C0)
#define GPIO_SET_RIS_TRIG8_OFFSET  ((uint32_t)0x00C4)
#define GPIO_CLR_RIS_TRIG8_OFFSET  ((uint32_t)0x00C8)
#define GPIO_SET_FAL_TRIG8_OFFSET  ((uint32_t)0x00CC)
#define GPIO_CLR_FAL_TRIG8_OFFSET  ((uint32_t)0x00D0)
#define GPIO_INTSTAT8_OFFSET       ((uint32_t)0x00D4)


/**********************************************************************************************
************************************** 1 REVID ***********************************************
**********************************************************************************************/
#define GPIO_REVID                    (((GPIO_REVID_TypeDef*)(GPIO_BASE+GPIO_REVID_OFFSET )))
#define GPIO_REVID_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_REVID_OFFSET)))

/*--------*/
#define GPIO_REVID_R_REV_MASK        ((uint32_t)0xFFFFFFFF)
#define GPIO_REVID_R_REV_SHIFT         (0)

#define GPIO_REVID_REV_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


/**********************************************************************************************
************************************** 2 BINTEN ***********************************************
**********************************************************************************************/
#define GPIO_BINTEN                    (((GPIO_BINTEN_TypeDef*)(GPIO_BASE+GPIO_BINTEN_OFFSET )))
#define GPIO_BINTEN_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_BINTEN_OFFSET)))

/*--------*/
#define GPIO_BINTEN_R_EN0_MASK        ((uint32_t)0x00000001)
#define GPIO_BINTEN_R_EN0_SHIFT         (0)

#define GPIO_BINTEN_EN0_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_BINTEN_R_EN1_MASK        ((uint32_t)0x00000002)
#define GPIO_BINTEN_R_EN1_SHIFT         (1)

#define GPIO_BINTEN_EN1_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define GPIO_BINTEN_R_EN2_MASK        ((uint32_t)0x00000004)
#define GPIO_BINTEN_R_EN2_SHIFT         (2)

#define GPIO_BINTEN_EN2_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_BINTEN_R_EN3_MASK        ((uint32_t)0x00000008)
#define GPIO_BINTEN_R_EN3_SHIFT         (3)

#define GPIO_BINTEN_EN3_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_BINTEN_R_EN4_MASK        ((uint32_t)0x00000010)
#define GPIO_BINTEN_R_EN4_SHIFT         (4)

#define GPIO_BINTEN_EN4_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_BINTEN_R_EN5_MASK        ((uint32_t)0x00000020)
#define GPIO_BINTEN_R_EN5_SHIFT         (5)

#define GPIO_BINTEN_EN5_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_BINTEN_R_EN6_MASK        ((uint32_t)0x00000040)
#define GPIO_BINTEN_R_EN6_SHIFT         (6)

#define GPIO_BINTEN_EN6_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_BINTEN_R_EN7_MASK        ((uint32_t)0x00000080)
#define GPIO_BINTEN_R_EN7_SHIFT         (7)

#define GPIO_BINTEN_EN7_MASK          ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_BINTEN_R_EN8_MASK        ((uint32_t)0x00000100)
#define GPIO_BINTEN_R_EN8_SHIFT         (8)

#define GPIO_BINTEN_EN8_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 3 DIR ***********************************************
**********************************************************************************************/
#define GPIO_DIR01                    (((GPIO_BANK01_TypeDef*)(GPIO_BASE+GPIO_DIR01_OFFSET )))
#define GPIO_DIR01_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_DIR01_OFFSET)))
#define GPIO_DIR23                    (((GPIO_BANK23_TypeDef*)(GPIO_BASE+GPIO_DIR23_OFFSET )))
#define GPIO_DIR23_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_DIR23_OFFSET)))
#define GPIO_DIR45                    (((GPIO_BANK45_TypeDef*)(GPIO_BASE+GPIO_DIR45_OFFSET )))
#define GPIO_DIR45_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_DIR45_OFFSET)))
#define GPIO_DIR67                    (((GPIO_BANK67_TypeDef*)(GPIO_BASE+GPIO_DIR67_OFFSET )))
#define GPIO_DIR67_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_DIR67_OFFSET)))
#define GPIO_DIR8                    (((GPIO_BANK8_TypeDef*)(GPIO_BASE+GPIO_DIR8_OFFSET )))
#define GPIO_DIR8_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_DIR8_OFFSET)))

#define GPIO01_DIR                    (((GPIO_BANK01_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_DIR_OFFSET )))
#define GPIO01_DIR_R                  (*((__IO uint32_t *)(GPIO0_BASE+GPIO_BANK_PAR_DIR_OFFSET)))
#define GPIO23_DIR                    (((GPIO_BANK23_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_DIR_OFFSET )))
#define GPIO23_DIR_R                  (*((__IO uint32_t *)(GPIO2_BASE+GPIO_BANK_PAR_DIR_OFFSET)))
#define GPIO45_DIR                    (((GPIO_BANK45_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_DIR_OFFSET )))
#define GPIO45_DIR_R                  (*((__IO uint32_t *)(GPIO4_BASE+GPIO_BANK_PAR_DIR_OFFSET)))
#define GPIO67_DIR                    (((GPIO_BANK67_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_DIR_OFFSET )))
#define GPIO67_DIR_R                  (*((__IO uint32_t *)(GPIO6_BASE+GPIO_BANK_PAR_DIR_OFFSET)))
#define GPIO8_DIR                    (((GPIO_BANK8_TypeDef*)(GPIO8_BASE+GPIO_BANK_PAR_DIR_OFFSET )))
#define GPIO8_DIR_R                  (*((__IO uint16_t *)(GPIO8_BASE+GPIO_BANK_PAR_DIR_OFFSET)))

#define GPIO0_DIR                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_DIR_OFFSET )))
#define GPIO0_DIR_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_PAR_DIR_OFFSET)))
#define GPIO1_DIR                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_IMPAR_DIR_OFFSET )))
#define GPIO1_DIR_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_IMPAR_DIR_OFFSET)))

#define GPIO2_DIR                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_DIR_OFFSET )))
#define GPIO2_DIR_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_PAR_DIR_OFFSET)))
#define GPIO3_DIR                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_IMPAR_DIR_OFFSET )))
#define GPIO3_DIR_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_IMPAR_DIR_OFFSET)))

#define GPIO4_DIR                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_DIR_OFFSET )))
#define GPIO4_DIR_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_PAR_DIR_OFFSET)))
#define GPIO5_DIR                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_IMPAR_DIR_OFFSET )))
#define GPIO5_DIR_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_IMPAR_DIR_OFFSET)))

#define GPIO6_DIR                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_DIR_OFFSET )))
#define GPIO6_DIR_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_PAR_DIR_OFFSET)))
#define GPIO7_DIR                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_IMPAR_DIR_OFFSET )))
#define GPIO7_DIR_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_IMPAR_DIR_OFFSET)))


/**********************************************************************************************
************************************** 4 OUT_DATA ***********************************************
**********************************************************************************************/
#define GPIO_OUT_DATA01                    (((GPIO_BANK01_TypeDef*)(GPIO_BASE+GPIO_OUT_DATA01_OFFSET )))
#define GPIO_OUT_DATA01_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_OUT_DATA01_OFFSET)))
#define GPIO_OUT_DATA23                    (((GPIO_BANK23_TypeDef*)(GPIO_BASE+GPIO_OUT_DATA23_OFFSET )))
#define GPIO_OUT_DATA23_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_OUT_DATA23_OFFSET)))
#define GPIO_OUT_DATA45                    (((GPIO_BANK45_TypeDef*)(GPIO_BASE+GPIO_OUT_DATA45_OFFSET )))
#define GPIO_OUT_DATA45_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_OUT_DATA45_OFFSET)))
#define GPIO_OUT_DATA67                    (((GPIO_BANK67_TypeDef*)(GPIO_BASE+GPIO_OUT_DATA67_OFFSET )))
#define GPIO_OUT_DATA67_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_OUT_DATA67_OFFSET)))
#define GPIO_OUT_DATA8                    (((GPIO_BANK8_TypeDef*)(GPIO_BASE+GPIO_OUT_DATA8_OFFSET )))
#define GPIO_OUT_DATA8_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_OUT_DATA8_OFFSET)))

#define GPIO01_OUT_DATA                    (((GPIO_BANK01_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET )))
#define GPIO01_OUT_DATA_R                  (*((__IO uint32_t *)(GPIO0_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET)))
#define GPIO23_OUT_DATA                    (((GPIO_BANK23_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET )))
#define GPIO23_OUT_DATA_R                  (*((__IO uint32_t *)(GPIO2_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET)))
#define GPIO45_OUT_DATA                    (((GPIO_BANK45_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET )))
#define GPIO45_OUT_DATA_R                  (*((__IO uint32_t *)(GPIO4_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET)))
#define GPIO67_OUT_DATA                    (((GPIO_BANK67_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET )))
#define GPIO67_OUT_DATA_R                  (*((__IO uint32_t *)(GPIO6_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET)))
#define GPIO8_OUT_DATA                    (((GPIO_BANK8_TypeDef*)(GPIO8_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET )))
#define GPIO8_OUT_DATA_R                  (*((__IO uint16_t *)(GPIO8_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET)))

#define GPIO0_OUT_DATA                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET )))
#define GPIO0_OUT_DATA_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET)))
#define GPIO1_OUT_DATA                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_IMPAR_OUT_DATA_OFFSET )))
#define GPIO1_OUT_DATA_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_IMPAR_OUT_DATA_OFFSET)))

#define GPIO2_OUT_DATA                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET )))
#define GPIO2_OUT_DATA_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET)))
#define GPIO3_OUT_DATA                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_IMPAR_OUT_DATA_OFFSET )))
#define GPIO3_OUT_DATA_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_IMPAR_OUT_DATA_OFFSET)))

#define GPIO4_OUT_DATA                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET )))
#define GPIO4_OUT_DATA_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET)))
#define GPIO5_OUT_DATA                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_IMPAR_OUT_DATA_OFFSET )))
#define GPIO5_OUT_DATA_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_IMPAR_OUT_DATA_OFFSET)))

#define GPIO6_OUT_DATA                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET )))
#define GPIO6_OUT_DATA_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_PAR_OUT_DATA_OFFSET)))
#define GPIO7_OUT_DATA                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_IMPAR_OUT_DATA_OFFSET )))
#define GPIO7_OUT_DATA_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_IMPAR_OUT_DATA_OFFSET)))



/**********************************************************************************************
************************************** 5 SET_DATA ***********************************************
**********************************************************************************************/
#define GPIO_SET_DATA01                    (((GPIO_BANK01_TypeDef*)(GPIO_BASE+GPIO_SET_DATA01_OFFSET )))
#define GPIO_SET_DATA01_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_DATA01_OFFSET)))
#define GPIO_SET_DATA23                    (((GPIO_BANK23_TypeDef*)(GPIO_BASE+GPIO_SET_DATA23_OFFSET )))
#define GPIO_SET_DATA23_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_DATA23_OFFSET)))
#define GPIO_SET_DATA45                    (((GPIO_BANK45_TypeDef*)(GPIO_BASE+GPIO_SET_DATA45_OFFSET )))
#define GPIO_SET_DATA45_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_DATA45_OFFSET)))
#define GPIO_SET_DATA67                    (((GPIO_BANK67_TypeDef*)(GPIO_BASE+GPIO_SET_DATA67_OFFSET )))
#define GPIO_SET_DATA67_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_DATA67_OFFSET)))
#define GPIO_SET_DATA8                    (((GPIO_BANK8_TypeDef*)(GPIO_BASE+GPIO_SET_DATA8_OFFSET )))
#define GPIO_SET_DATA8_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_DATA8_OFFSET)))

#define GPIO01_SET_DATA                    (((GPIO_BANK01_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET )))
#define GPIO01_SET_DATA_R                  (*((__IO uint32_t *)(GPIO0_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET)))
#define GPIO23_SET_DATA                    (((GPIO_BANK23_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET )))
#define GPIO23_SET_DATA_R                  (*((__IO uint32_t *)(GPIO2_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET)))
#define GPIO45_SET_DATA                    (((GPIO_BANK45_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET )))
#define GPIO45_SET_DATA_R                  (*((__IO uint32_t *)(GPIO4_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET)))
#define GPIO67_SET_DATA                    (((GPIO_BANK67_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET )))
#define GPIO67_SET_DATA_R                  (*((__IO uint32_t *)(GPIO6_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET)))
#define GPIO8_SET_DATA                    (((GPIO_BANK8_TypeDef*)(GPIO8_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET )))
#define GPIO8_SET_DATA_R                  (*((__IO uint16_t *)(GPIO8_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET)))

#define GPIO0_SET_DATA                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET )))
#define GPIO0_SET_DATA_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET)))
#define GPIO1_SET_DATA                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_IMPAR_SET_DATA_OFFSET )))
#define GPIO1_SET_DATA_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_IMPAR_SET_DATA_OFFSET)))

#define GPIO2_SET_DATA                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET )))
#define GPIO2_SET_DATA_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET)))
#define GPIO3_SET_DATA                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_IMPAR_SET_DATA_OFFSET )))
#define GPIO3_SET_DATA_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_IMPAR_SET_DATA_OFFSET)))

#define GPIO4_SET_DATA                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET )))
#define GPIO4_SET_DATA_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET)))
#define GPIO5_SET_DATA                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_IMPAR_SET_DATA_OFFSET )))
#define GPIO5_SET_DATA_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_IMPAR_SET_DATA_OFFSET)))

#define GPIO6_SET_DATA                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET )))
#define GPIO6_SET_DATA_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_PAR_SET_DATA_OFFSET)))
#define GPIO7_SET_DATA                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_IMPAR_SET_DATA_OFFSET )))
#define GPIO7_SET_DATA_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_IMPAR_SET_DATA_OFFSET)))

/**********************************************************************************************
************************************** 6 CLR_DATA ***********************************************
**********************************************************************************************/
#define GPIO_CLR_DATA01                    (((GPIO_BANK01_TypeDef*)(GPIO_BASE+GPIO_CLR_DATA01_OFFSET )))
#define GPIO_CLR_DATA01_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_DATA01_OFFSET)))
#define GPIO_CLR_DATA23                    (((GPIO_BANK23_TypeDef*)(GPIO_BASE+GPIO_CLR_DATA23_OFFSET )))
#define GPIO_CLR_DATA23_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_DATA23_OFFSET)))
#define GPIO_CLR_DATA45                    (((GPIO_BANK45_TypeDef*)(GPIO_BASE+GPIO_CLR_DATA45_OFFSET )))
#define GPIO_CLR_DATA45_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_DATA45_OFFSET)))
#define GPIO_CLR_DATA67                    (((GPIO_BANK67_TypeDef*)(GPIO_BASE+GPIO_CLR_DATA67_OFFSET )))
#define GPIO_CLR_DATA67_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_DATA67_OFFSET)))
#define GPIO_CLR_DATA8                    (((GPIO_BANK8_TypeDef*)(GPIO_BASE+GPIO_CLR_DATA8_OFFSET )))
#define GPIO_CLR_DATA8_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_DATA8_OFFSET)))

#define GPIO01_CLR_DATA                    (((GPIO_BANK01_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET )))
#define GPIO01_CLR_DATA_R                  (*((__IO uint32_t *)(GPIO0_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET)))
#define GPIO23_CLR_DATA                    (((GPIO_BANK23_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET )))
#define GPIO23_CLR_DATA_R                  (*((__IO uint32_t *)(GPIO2_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET)))
#define GPIO45_CLR_DATA                    (((GPIO_BANK45_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET )))
#define GPIO45_CLR_DATA_R                  (*((__IO uint32_t *)(GPIO4_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET)))
#define GPIO67_CLR_DATA                    (((GPIO_BANK67_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET )))
#define GPIO67_CLR_DATA_R                  (*((__IO uint32_t *)(GPIO6_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET)))
#define GPIO8_CLR_DATA                    (((GPIO_BANK8_TypeDef*)(GPIO8_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET )))
#define GPIO8_CLR_DATA_R                  (*((__IO uint16_t *)(GPIO8_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET)))

#define GPIO0_CLR_DATA                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET )))
#define GPIO0_CLR_DATA_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET)))
#define GPIO1_CLR_DATA                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_IMPAR_CLR_DATA_OFFSET )))
#define GPIO1_CLR_DATA_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_IMPAR_CLR_DATA_OFFSET)))

#define GPIO2_CLR_DATA                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET )))
#define GPIO2_CLR_DATA_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET)))
#define GPIO3_CLR_DATA                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_IMPAR_CLR_DATA_OFFSET )))
#define GPIO3_CLR_DATA_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_IMPAR_CLR_DATA_OFFSET)))

#define GPIO4_CLR_DATA                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET )))
#define GPIO4_CLR_DATA_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET)))
#define GPIO5_CLR_DATA                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_IMPAR_CLR_DATA_OFFSET )))
#define GPIO5_CLR_DATA_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_IMPAR_CLR_DATA_OFFSET)))

#define GPIO6_CLR_DATA                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET )))
#define GPIO6_CLR_DATA_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_PAR_CLR_DATA_OFFSET)))
#define GPIO7_CLR_DATA                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_IMPAR_CLR_DATA_OFFSET )))
#define GPIO7_CLR_DATA_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_IMPAR_CLR_DATA_OFFSET)))


/**********************************************************************************************
************************************** 7 IN_DATA ***********************************************
**********************************************************************************************/
#define GPIO_IN_DATA01                    (((GPIO_BANK01_TypeDef*)(GPIO_BASE+GPIO_IN_DATA01_OFFSET )))
#define GPIO_IN_DATA01_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_IN_DATA01_OFFSET)))
#define GPIO_IN_DATA23                    (((GPIO_BANK23_TypeDef*)(GPIO_BASE+GPIO_IN_DATA23_OFFSET )))
#define GPIO_IN_DATA23_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_IN_DATA23_OFFSET)))
#define GPIO_IN_DATA45                    (((GPIO_BANK45_TypeDef*)(GPIO_BASE+GPIO_IN_DATA45_OFFSET )))
#define GPIO_IN_DATA45_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_IN_DATA45_OFFSET)))
#define GPIO_IN_DATA67                    (((GPIO_BANK67_TypeDef*)(GPIO_BASE+GPIO_IN_DATA67_OFFSET )))
#define GPIO_IN_DATA67_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_IN_DATA67_OFFSET)))
#define GPIO_IN_DATA8                    (((GPIO_BANK8_TypeDef*)(GPIO_BASE+GPIO_IN_DATA8_OFFSET )))
#define GPIO_IN_DATA8_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_IN_DATA8_OFFSET)))

#define GPIO01_IN_DATA                    (((GPIO_BANK01_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET )))
#define GPIO01_IN_DATA_R                  (*((__IO uint32_t *)(GPIO0_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET)))
#define GPIO23_IN_DATA                    (((GPIO_BANK23_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET )))
#define GPIO23_IN_DATA_R                  (*((__IO uint32_t *)(GPIO2_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET)))
#define GPIO45_IN_DATA                    (((GPIO_BANK45_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET )))
#define GPIO45_IN_DATA_R                  (*((__IO uint32_t *)(GPIO4_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET)))
#define GPIO67_IN_DATA                    (((GPIO_BANK67_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET )))
#define GPIO67_IN_DATA_R                  (*((__IO uint32_t *)(GPIO6_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET)))
#define GPIO8_IN_DATA                    (((GPIO_BANK8_TypeDef*)(GPIO8_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET )))
#define GPIO8_IN_DATA_R                  (*((__IO uint16_t *)(GPIO8_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET)))

#define GPIO0_IN_DATA                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET )))
#define GPIO0_IN_DATA_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET)))
#define GPIO1_IN_DATA                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_IMPAR_IN_DATA_OFFSET )))
#define GPIO1_IN_DATA_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_IMPAR_IN_DATA_OFFSET)))

#define GPIO2_IN_DATA                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET )))
#define GPIO2_IN_DATA_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET)))
#define GPIO3_IN_DATA                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_IMPAR_IN_DATA_OFFSET )))
#define GPIO3_IN_DATA_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_IMPAR_IN_DATA_OFFSET)))

#define GPIO4_IN_DATA                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET )))
#define GPIO4_IN_DATA_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET)))
#define GPIO5_IN_DATA                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_IMPAR_IN_DATA_OFFSET )))
#define GPIO5_IN_DATA_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_IMPAR_IN_DATA_OFFSET)))

#define GPIO6_IN_DATA                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET )))
#define GPIO6_IN_DATA_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_PAR_IN_DATA_OFFSET)))
#define GPIO7_IN_DATA                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_IMPAR_IN_DATA_OFFSET )))
#define GPIO7_IN_DATA_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_IMPAR_IN_DATA_OFFSET)))


/**********************************************************************************************
************************************** 8 SET_RIS_TRIG ***********************************************
**********************************************************************************************/
#define GPIO_SET_RIS_TRIG01                    (((GPIO_BANK01_TypeDef*)(GPIO_BASE+GPIO_SET_RIS_TRIG01_OFFSET )))
#define GPIO_SET_RIS_TRIG01_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_RIS_TRIG01_OFFSET)))
#define GPIO_SET_RIS_TRIG23                    (((GPIO_BANK23_TypeDef*)(GPIO_BASE+GPIO_SET_RIS_TRIG23_OFFSET )))
#define GPIO_SET_RIS_TRIG23_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_RIS_TRIG23_OFFSET)))
#define GPIO_SET_RIS_TRIG45                    (((GPIO_BANK45_TypeDef*)(GPIO_BASE+GPIO_SET_RIS_TRIG45_OFFSET )))
#define GPIO_SET_RIS_TRIG45_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_RIS_TRIG45_OFFSET)))
#define GPIO_SET_RIS_TRIG67                    (((GPIO_BANK67_TypeDef*)(GPIO_BASE+GPIO_SET_RIS_TRIG67_OFFSET )))
#define GPIO_SET_RIS_TRIG67_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_RIS_TRIG67_OFFSET)))
#define GPIO_SET_RIS_TRIG8                    (((GPIO_BANK8_TypeDef*)(GPIO_BASE+GPIO_SET_RIS_TRIG8_OFFSET )))
#define GPIO_SET_RIS_TRIG8_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_RIS_TRIG8_OFFSET)))

#define GPIO01_SET_RIS_TRIG                    (((GPIO_BANK01_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET )))
#define GPIO01_SET_RIS_TRIG_R                  (*((__IO uint32_t *)(GPIO0_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET)))
#define GPIO23_SET_RIS_TRIG                    (((GPIO_BANK23_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET )))
#define GPIO23_SET_RIS_TRIG_R                  (*((__IO uint32_t *)(GPIO2_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET)))
#define GPIO45_SET_RIS_TRIG                    (((GPIO_BANK45_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET )))
#define GPIO45_SET_RIS_TRIG_R                  (*((__IO uint32_t *)(GPIO4_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET)))
#define GPIO67_SET_RIS_TRIG                    (((GPIO_BANK67_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET )))
#define GPIO67_SET_RIS_TRIG_R                  (*((__IO uint32_t *)(GPIO6_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET)))
#define GPIO8_SET_RIS_TRIG                    (((GPIO_BANK8_TypeDef*)(GPIO8_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET )))
#define GPIO8_SET_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO8_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET)))

#define GPIO0_SET_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET )))
#define GPIO0_SET_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET)))
#define GPIO1_SET_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_IMPAR_SET_RIS_TRIG_OFFSET )))
#define GPIO1_SET_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_IMPAR_SET_RIS_TRIG_OFFSET)))

#define GPIO2_SET_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET )))
#define GPIO2_SET_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET)))
#define GPIO3_SET_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_IMPAR_SET_RIS_TRIG_OFFSET )))
#define GPIO3_SET_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_IMPAR_SET_RIS_TRIG_OFFSET)))

#define GPIO4_SET_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET )))
#define GPIO4_SET_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET)))
#define GPIO5_SET_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_IMPAR_SET_RIS_TRIG_OFFSET )))
#define GPIO5_SET_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_IMPAR_SET_RIS_TRIG_OFFSET)))

#define GPIO6_SET_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET )))
#define GPIO6_SET_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_PAR_SET_RIS_TRIG_OFFSET)))
#define GPIO7_SET_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_IMPAR_SET_RIS_TRIG_OFFSET )))
#define GPIO7_SET_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_IMPAR_SET_RIS_TRIG_OFFSET)))

/**********************************************************************************************
************************************** 9 CLR_RIS_TRIG ***********************************************
**********************************************************************************************/
#define GPIO_CLR_RIS_TRIG01                    (((GPIO_BANK01_TypeDef*)(GPIO_BASE+GPIO_CLR_RIS_TRIG01_OFFSET )))
#define GPIO_CLR_RIS_TRIG01_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_RIS_TRIG01_OFFSET)))
#define GPIO_CLR_RIS_TRIG23                    (((GPIO_BANK23_TypeDef*)(GPIO_BASE+GPIO_CLR_RIS_TRIG23_OFFSET )))
#define GPIO_CLR_RIS_TRIG23_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_RIS_TRIG23_OFFSET)))
#define GPIO_CLR_RIS_TRIG45                    (((GPIO_BANK45_TypeDef*)(GPIO_BASE+GPIO_CLR_RIS_TRIG45_OFFSET )))
#define GPIO_CLR_RIS_TRIG45_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_RIS_TRIG45_OFFSET)))
#define GPIO_CLR_RIS_TRIG67                    (((GPIO_BANK67_TypeDef*)(GPIO_BASE+GPIO_CLR_RIS_TRIG67_OFFSET )))
#define GPIO_CLR_RIS_TRIG67_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_RIS_TRIG67_OFFSET)))
#define GPIO_CLR_RIS_TRIG8                    (((GPIO_BANK8_TypeDef*)(GPIO_BASE+GPIO_CLR_RIS_TRIG8_OFFSET )))
#define GPIO_CLR_RIS_TRIG8_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_RIS_TRIG8_OFFSET)))

#define GPIO01_CLR_RIS_TRIG                    (((GPIO_BANK01_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET )))
#define GPIO01_CLR_RIS_TRIG_R                  (*((__IO uint32_t *)(GPIO0_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET)))
#define GPIO23_CLR_RIS_TRIG                    (((GPIO_BANK23_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET )))
#define GPIO23_CLR_RIS_TRIG_R                  (*((__IO uint32_t *)(GPIO2_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET)))
#define GPIO45_CLR_RIS_TRIG                    (((GPIO_BANK45_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET )))
#define GPIO45_CLR_RIS_TRIG_R                  (*((__IO uint32_t *)(GPIO4_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET)))
#define GPIO67_CLR_RIS_TRIG                    (((GPIO_BANK67_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET )))
#define GPIO67_CLR_RIS_TRIG_R                  (*((__IO uint32_t *)(GPIO6_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET)))
#define GPIO8_CLR_RIS_TRIG                    (((GPIO_BANK8_TypeDef*)(GPIO8_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET )))
#define GPIO8_CLR_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO8_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET)))

#define GPIO0_CLR_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET )))
#define GPIO0_CLR_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET)))
#define GPIO1_CLR_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_IMPAR_CLR_RIS_TRIG_OFFSET )))
#define GPIO1_CLR_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_IMPAR_CLR_RIS_TRIG_OFFSET)))

#define GPIO2_CLR_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET )))
#define GPIO2_CLR_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET)))
#define GPIO3_CLR_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_IMPAR_CLR_RIS_TRIG_OFFSET )))
#define GPIO3_CLR_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_IMPAR_CLR_RIS_TRIG_OFFSET)))

#define GPIO4_CLR_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET )))
#define GPIO4_CLR_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET)))
#define GPIO5_CLR_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_IMPAR_CLR_RIS_TRIG_OFFSET )))
#define GPIO5_CLR_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_IMPAR_CLR_RIS_TRIG_OFFSET)))

#define GPIO6_CLR_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET )))
#define GPIO6_CLR_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_PAR_CLR_RIS_TRIG_OFFSET)))
#define GPIO7_CLR_RIS_TRIG                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_IMPAR_CLR_RIS_TRIG_OFFSET )))
#define GPIO7_CLR_RIS_TRIG_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_IMPAR_CLR_RIS_TRIG_OFFSET)))

/**********************************************************************************************
************************************** 10 SET_FAL_TRIG ***********************************************
**********************************************************************************************/
#define GPIO_SET_FAL_TRIG01                    (((GPIO_BANK01_TypeDef*)(GPIO_BASE+GPIO_SET_FAL_TRIG01_OFFSET )))
#define GPIO_SET_FAL_TRIG01_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_FAL_TRIG01_OFFSET)))
#define GPIO_SET_FAL_TRIG23                    (((GPIO_BANK23_TypeDef*)(GPIO_BASE+GPIO_SET_FAL_TRIG23_OFFSET )))
#define GPIO_SET_FAL_TRIG23_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_FAL_TRIG23_OFFSET)))
#define GPIO_SET_FAL_TRIG45                    (((GPIO_BANK45_TypeDef*)(GPIO_BASE+GPIO_SET_FAL_TRIG45_OFFSET )))
#define GPIO_SET_FAL_TRIG45_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_FAL_TRIG45_OFFSET)))
#define GPIO_SET_FAL_TRIG67                    (((GPIO_BANK67_TypeDef*)(GPIO_BASE+GPIO_SET_FAL_TRIG67_OFFSET )))
#define GPIO_SET_FAL_TRIG67_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_FAL_TRIG67_OFFSET)))
#define GPIO_SET_FAL_TRIG8                    (((GPIO_BANK8_TypeDef*)(GPIO_BASE+GPIO_SET_FAL_TRIG8_OFFSET )))
#define GPIO_SET_FAL_TRIG8_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_SET_FAL_TRIG8_OFFSET)))

#define GPIO01_SET_FAL_TRIG                    (((GPIO_BANK01_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET )))
#define GPIO01_SET_FAL_TRIG_R                  (*((__IO uint32_t *)(GPIO0_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET)))
#define GPIO23_SET_FAL_TRIG                    (((GPIO_BANK23_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET )))
#define GPIO23_SET_FAL_TRIG_R                  (*((__IO uint32_t *)(GPIO2_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET)))
#define GPIO45_SET_FAL_TRIG                    (((GPIO_BANK45_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET )))
#define GPIO45_SET_FAL_TRIG_R                  (*((__IO uint32_t *)(GPIO4_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET)))
#define GPIO67_SET_FAL_TRIG                    (((GPIO_BANK67_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET )))
#define GPIO67_SET_FAL_TRIG_R                  (*((__IO uint32_t *)(GPIO6_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET)))
#define GPIO8_SET_FAL_TRIG                    (((GPIO_BANK8_TypeDef*)(GPIO8_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET )))
#define GPIO8_SET_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO8_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET)))

#define GPIO0_SET_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET )))
#define GPIO0_SET_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET)))
#define GPIO1_SET_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_IMPAR_SET_FAL_TRIG_OFFSET )))
#define GPIO1_SET_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_IMPAR_SET_FAL_TRIG_OFFSET)))

#define GPIO2_SET_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET )))
#define GPIO2_SET_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET)))
#define GPIO3_SET_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_IMPAR_SET_FAL_TRIG_OFFSET )))
#define GPIO3_SET_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_IMPAR_SET_FAL_TRIG_OFFSET)))

#define GPIO4_SET_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET )))
#define GPIO4_SET_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET)))
#define GPIO5_SET_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_IMPAR_SET_FAL_TRIG_OFFSET )))
#define GPIO5_SET_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_IMPAR_SET_FAL_TRIG_OFFSET)))

#define GPIO6_SET_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET )))
#define GPIO6_SET_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_PAR_SET_FAL_TRIG_OFFSET)))
#define GPIO7_SET_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_IMPAR_SET_FAL_TRIG_OFFSET )))
#define GPIO7_SET_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_IMPAR_SET_FAL_TRIG_OFFSET)))

/**********************************************************************************************
************************************** 11 SET_FAL_TRIG ***********************************************
**********************************************************************************************/
#define GPIO_CLR_FAL_TRIG01                    (((GPIO_BANK01_TypeDef*)(GPIO_BASE+GPIO_CLR_FAL_TRIG01_OFFSET )))
#define GPIO_CLR_FAL_TRIG01_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_FAL_TRIG01_OFFSET)))
#define GPIO_CLR_FAL_TRIG23                    (((GPIO_BANK23_TypeDef*)(GPIO_BASE+GPIO_CLR_FAL_TRIG23_OFFSET )))
#define GPIO_CLR_FAL_TRIG23_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_FAL_TRIG23_OFFSET)))
#define GPIO_CLR_FAL_TRIG45                    (((GPIO_BANK45_TypeDef*)(GPIO_BASE+GPIO_CLR_FAL_TRIG45_OFFSET )))
#define GPIO_CLR_FAL_TRIG45_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_FAL_TRIG45_OFFSET)))
#define GPIO_CLR_FAL_TRIG67                    (((GPIO_BANK67_TypeDef*)(GPIO_BASE+GPIO_CLR_FAL_TRIG67_OFFSET )))
#define GPIO_CLR_FAL_TRIG67_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_FAL_TRIG67_OFFSET)))
#define GPIO_CLR_FAL_TRIG8                    (((GPIO_BANK8_TypeDef*)(GPIO_BASE+GPIO_CLR_FAL_TRIG8_OFFSET )))
#define GPIO_CLR_FAL_TRIG8_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_CLR_FAL_TRIG8_OFFSET)))

#define GPIO01_CLR_FAL_TRIG                    (((GPIO_BANK01_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET )))
#define GPIO01_CLR_FAL_TRIG_R                  (*((__IO uint32_t *)(GPIO0_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET)))
#define GPIO23_CLR_FAL_TRIG                    (((GPIO_BANK23_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET )))
#define GPIO23_CLR_FAL_TRIG_R                  (*((__IO uint32_t *)(GPIO2_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET)))
#define GPIO45_CLR_FAL_TRIG                    (((GPIO_BANK45_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET )))
#define GPIO45_CLR_FAL_TRIG_R                  (*((__IO uint32_t *)(GPIO4_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET)))
#define GPIO67_CLR_FAL_TRIG                    (((GPIO_BANK67_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET )))
#define GPIO67_CLR_FAL_TRIG_R                  (*((__IO uint32_t *)(GPIO6_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET)))
#define GPIO8_CLR_FAL_TRIG                    (((GPIO_BANK8_TypeDef*)(GPIO8_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET )))
#define GPIO8_CLR_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO8_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET)))

#define GPIO0_CLR_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET )))
#define GPIO0_CLR_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET)))
#define GPIO1_CLR_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_IMPAR_CLR_FAL_TRIG_OFFSET )))
#define GPIO1_CLR_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_IMPAR_CLR_FAL_TRIG_OFFSET)))

#define GPIO2_CLR_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET )))
#define GPIO2_CLR_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET)))
#define GPIO3_CLR_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_IMPAR_CLR_FAL_TRIG_OFFSET )))
#define GPIO3_CLR_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_IMPAR_CLR_FAL_TRIG_OFFSET)))

#define GPIO4_CLR_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET )))
#define GPIO4_CLR_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET)))
#define GPIO5_CLR_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_IMPAR_CLR_FAL_TRIG_OFFSET )))
#define GPIO5_CLR_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_IMPAR_CLR_FAL_TRIG_OFFSET)))

#define GPIO6_CLR_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET )))
#define GPIO6_CLR_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_PAR_CLR_FAL_TRIG_OFFSET)))
#define GPIO7_CLR_FAL_TRIG                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_IMPAR_CLR_FAL_TRIG_OFFSET )))
#define GPIO7_CLR_FAL_TRIG_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_IMPAR_CLR_FAL_TRIG_OFFSET)))

/**********************************************************************************************
************************************** 12 SET_FAL_TRIG ***********************************************
**********************************************************************************************/
#define GPIO_INTSTAT01                    (((GPIO_BANK01_TypeDef*)(GPIO_BASE+GPIO_INTSTAT01_OFFSET )))
#define GPIO_INTSTAT01_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_INTSTAT01_OFFSET)))
#define GPIO_INTSTAT23                    (((GPIO_BANK23_TypeDef*)(GPIO_BASE+GPIO_INTSTAT23_OFFSET )))
#define GPIO_INTSTAT23_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_INTSTAT23_OFFSET)))
#define GPIO_INTSTAT45                    (((GPIO_BANK45_TypeDef*)(GPIO_BASE+GPIO_INTSTAT45_OFFSET )))
#define GPIO_INTSTAT45_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_INTSTAT45_OFFSET)))
#define GPIO_INTSTAT67                    (((GPIO_BANK67_TypeDef*)(GPIO_BASE+GPIO_INTSTAT67_OFFSET )))
#define GPIO_INTSTAT67_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_INTSTAT67_OFFSET)))
#define GPIO_INTSTAT8                    (((GPIO_BANK8_TypeDef*)(GPIO_BASE+GPIO_INTSTAT8_OFFSET )))
#define GPIO_INTSTAT8_R                  (*((__IO uint32_t *)(GPIO_BASE+GPIO_INTSTAT8_OFFSET)))

#define GPIO01_INTSTAT                    (((GPIO_BANK01_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET )))
#define GPIO01_INTSTAT_R                  (*((__IO uint32_t *)(GPIO0_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET)))
#define GPIO23_INTSTAT                    (((GPIO_BANK23_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET )))
#define GPIO23_INTSTAT_R                  (*((__IO uint32_t *)(GPIO2_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET)))
#define GPIO45_INTSTAT                    (((GPIO_BANK45_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET )))
#define GPIO45_INTSTAT_R                  (*((__IO uint32_t *)(GPIO4_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET)))
#define GPIO67_INTSTAT                    (((GPIO_BANK67_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET )))
#define GPIO67_INTSTAT_R                  (*((__IO uint32_t *)(GPIO6_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET)))
#define GPIO8_INTSTAT                    (((GPIO_BANK8_TypeDef*)(GPIO8_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET )))
#define GPIO8_INTSTAT_R                  (*((__IO uint16_t *)(GPIO8_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET)))

#define GPIO0_INTSTAT                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET )))
#define GPIO0_INTSTAT_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET)))
#define GPIO1_INTSTAT                    (((GPIO_REG_TypeDef*)(GPIO0_BASE+GPIO_BANK_IMPAR_INTSTAT_OFFSET )))
#define GPIO1_INTSTAT_R                  (*((__IO uint16_t *)(GPIO0_BASE+GPIO_BANK_IMPAR_INTSTAT_OFFSET)))

#define GPIO2_INTSTAT                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET )))
#define GPIO2_INTSTAT_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET)))
#define GPIO3_INTSTAT                    (((GPIO_REG_TypeDef*)(GPIO2_BASE+GPIO_BANK_IMPAR_INTSTAT_OFFSET )))
#define GPIO3_INTSTAT_R                  (*((__IO uint16_t *)(GPIO2_BASE+GPIO_BANK_IMPAR_INTSTAT_OFFSET)))

#define GPIO4_INTSTAT                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET )))
#define GPIO4_INTSTAT_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET)))
#define GPIO5_INTSTAT                    (((GPIO_REG_TypeDef*)(GPIO4_BASE+GPIO_BANK_IMPAR_INTSTAT_OFFSET )))
#define GPIO5_INTSTAT_R                  (*((__IO uint16_t *)(GPIO4_BASE+GPIO_BANK_IMPAR_INTSTAT_OFFSET)))

#define GPIO6_INTSTAT                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET )))
#define GPIO6_INTSTAT_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_PAR_INTSTAT_OFFSET)))
#define GPIO7_INTSTAT                    (((GPIO_REG_TypeDef*)(GPIO6_BASE+GPIO_BANK_IMPAR_INTSTAT_OFFSET )))
#define GPIO7_INTSTAT_R                  (*((__IO uint16_t *)(GPIO6_BASE+GPIO_BANK_IMPAR_INTSTAT_OFFSET)))



/*--------*/
#define GPIO_R_P0_MASK        ((uint32_t)0x00000001)
#define GPIO_R_P0_SHIFT       (0)

#define GPIO_P0_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P1_MASK        ((uint32_t)0x00000002)
#define GPIO_R_P1_SHIFT       (1)

#define GPIO_P1_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P2_MASK        ((uint32_t)0x00000004)
#define GPIO_R_P2_SHIFT       (2)

#define GPIO_P2_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P3_MASK        ((uint32_t)0x00000008)
#define GPIO_R_P3_SHIFT       (3)

#define GPIO_P3_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P4_MASK        ((uint32_t)0x00000010)
#define GPIO_R_P4_SHIFT       (4)

#define GPIO_P4_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P5_MASK        ((uint32_t)0x00000020)
#define GPIO_R_P5_SHIFT       (5)

#define GPIO_P5_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P6_MASK        ((uint32_t)0x00000040)
#define GPIO_R_P6_SHIFT       (6)

#define GPIO_P6_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P7_MASK        ((uint32_t)0x00000080)
#define GPIO_R_P7_SHIFT       (7)

#define GPIO_P7_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P8_MASK        ((uint32_t)0x00000100)
#define GPIO_R_P8_SHIFT       (8)

#define GPIO_P8_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P9_MASK        ((uint32_t)0x00000200)
#define GPIO_R_P9_SHIFT       (9)

#define GPIO_P9_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P10_MASK        ((uint32_t)0x00000400)
#define GPIO_R_P10_SHIFT       (10)

#define GPIO_P10_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P11_MASK        ((uint32_t)0x00000800)
#define GPIO_R_P11_SHIFT       (11)

#define GPIO_P11_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P12_MASK        ((uint32_t)0x00001000)
#define GPIO_R_P12_SHIFT       (12)

#define GPIO_P12_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P13_MASK        ((uint32_t)0x00002000)
#define GPIO_R_P13_SHIFT       (13)

#define GPIO_P13_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P14_MASK        ((uint32_t)0x00004000)
#define GPIO_R_P14_SHIFT       (14)

#define GPIO_P14_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P15_MASK        ((uint32_t)0x00008000)
#define GPIO_R_P15_SHIFT       (15)

#define GPIO_P15_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P16_MASK        ((uint32_t)0x00010000)
#define GPIO_R_P16_SHIFT       (16)

#define GPIO_P16_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P17_MASK        ((uint32_t)0x00020000)
#define GPIO_R_P17_SHIFT       (17)

#define GPIO_P17_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P18_MASK        ((uint32_t)0x00040000)
#define GPIO_R_P18_SHIFT       (18)

#define GPIO_P18_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P19_MASK        ((uint32_t)0x00080000)
#define GPIO_R_P19_SHIFT       (19)

#define GPIO_P19_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P20_MASK        ((uint32_t)0x00100000)
#define GPIO_R_P20_SHIFT       (20)

#define GPIO_P20_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P21_MASK        ((uint32_t)0x00200000)
#define GPIO_R_P21_SHIFT       (21)

#define GPIO_P21_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P22_MASK        ((uint32_t)0x00400000)
#define GPIO_R_P22_SHIFT       (22)

#define GPIO_P22_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P23_MASK        ((uint32_t)0x00800000)
#define GPIO_R_P23_SHIFT       (23)

#define GPIO_P23_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P24_MASK        ((uint32_t)0x01000000)
#define GPIO_R_P24_SHIFT       (24)

#define GPIO_P24_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P25_MASK        ((uint32_t)0x02000000)
#define GPIO_R_P25_SHIFT       (25)

#define GPIO_P25_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P26_MASK        ((uint32_t)0x04000000)
#define GPIO_R_P26_SHIFT       (26)

#define GPIO_P26_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P27_MASK        ((uint32_t)0x08000000)
#define GPIO_R_P27_SHIFT       (27)

#define GPIO_P27_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P28_MASK        ((uint32_t)0x10000000)
#define GPIO_R_P28_SHIFT       (28)

#define GPIO_P28_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P29_MASK        ((uint32_t)0x20000000)
#define GPIO_R_P29_SHIFT       (29)

#define GPIO_P29_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P30_MASK        ((uint32_t)0x40000000)
#define GPIO_R_P30_SHIFT       (30)

#define GPIO_P30_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_R_P31_MASK        ((uint32_t)0x80000000)
#define GPIO_R_P31_SHIFT       (31)

#define GPIO_P31_SHIFT         ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define GPIO_PAR_R_P0_MASK        ((uint32_t)0x00000001)
#define GPIO_PAR_R_P0_SHIFT       (0)

#define GPIO_PAR_P0_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P1_MASK        ((uint32_t)0x00000002)
#define GPIO_PAR_R_P1_SHIFT       (1)

#define GPIO_PAR_P1_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P2_MASK        ((uint32_t)0x00000004)
#define GPIO_PAR_R_P2_SHIFT       (2)

#define GPIO_PAR_P2_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P3_MASK        ((uint32_t)0x00000008)
#define GPIO_PAR_R_P3_SHIFT       (3)

#define GPIO_PAR_P3_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P4_MASK        ((uint32_t)0x00000010)
#define GPIO_PAR_R_P4_SHIFT       (4)

#define GPIO_PAR_P4_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P5_MASK        ((uint32_t)0x00000020)
#define GPIO_PAR_R_P5_SHIFT       (5)

#define GPIO_PAR_P5_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P6_MASK        ((uint32_t)0x00000040)
#define GPIO_PAR_R_P6_SHIFT       (6)

#define GPIO_PAR_P6_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P7_MASK        ((uint32_t)0x00000080)
#define GPIO_PAR_R_P7_SHIFT       (7)

#define GPIO_PAR_P7_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P8_MASK        ((uint32_t)0x00000100)
#define GPIO_PAR_R_P8_SHIFT       (8)

#define GPIO_PAR_P8_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P9_MASK        ((uint32_t)0x00000200)
#define GPIO_PAR_R_P9_SHIFT       (9)

#define GPIO_PAR_P9_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P10_MASK        ((uint32_t)0x00000400)
#define GPIO_PAR_R_P10_SHIFT       (10)

#define GPIO_PAR_P10_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P11_MASK        ((uint32_t)0x00000800)
#define GPIO_PAR_R_P11_SHIFT       (11)

#define GPIO_PAR_P11_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P12_MASK        ((uint32_t)0x00001000)
#define GPIO_PAR_R_P12_SHIFT       (12)

#define GPIO_PAR_P12_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P13_MASK        ((uint32_t)0x00002000)
#define GPIO_PAR_R_P13_SHIFT       (13)

#define GPIO_PAR_P13_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P14_MASK        ((uint32_t)0x00004000)
#define GPIO_PAR_R_P14_SHIFT       (14)

#define GPIO_PAR_P14_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_PAR_R_P15_MASK        ((uint32_t)0x00008000)
#define GPIO_PAR_R_P15_SHIFT       (15)

#define GPIO_PAR_P15_SHIFT         ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define GPIO_IMPAR_R_P0_MASK        ((uint32_t)0x00010000)
#define GPIO_IMPAR_R_P0_SHIFT       (16)

#define GPIO_IMPAR_P0_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P1_MASK        ((uint32_t)0x00020000)
#define GPIO_IMPAR_R_P1_SHIFT       (17)

#define GPIO_IMPAR_P1_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P2_MASK        ((uint32_t)0x00040000)
#define GPIO_IMPAR_R_P2_SHIFT       (18)

#define GPIO_IMPAR_P2_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P3_MASK        ((uint32_t)0x00080000)
#define GPIO_IMPAR_R_P3_SHIFT       (19)

#define GPIO_IMPAR_P3_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P4_MASK        ((uint32_t)0x00100000)
#define GPIO_IMPAR_R_P4_SHIFT       (20)

#define GPIO_IMPAR_P4_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P5_MASK        ((uint32_t)0x00200000)
#define GPIO_IMPAR_R_P5_SHIFT       (21)

#define GPIO_IMPAR_P5_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P6_MASK        ((uint32_t)0x00400000)
#define GPIO_IMPAR_R_P6_SHIFT       (22)

#define GPIO_IMPAR_P6_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P7_MASK        ((uint32_t)0x00800000)
#define GPIO_IMPAR_R_P7_SHIFT       (23)

#define GPIO_IMPAR_P7_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P8_MASK        ((uint32_t)0x01000000)
#define GPIO_IMPAR_R_P8_SHIFT       (24)

#define GPIO_IMPAR_P8_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P9_MASK        ((uint32_t)0x02000000)
#define GPIO_IMPAR_R_P9_SHIFT       (25)

#define GPIO_IMPAR_P9_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P10_MASK        ((uint32_t)0x04000000)
#define GPIO_IMPAR_R_P10_SHIFT       (26)

#define GPIO_IMPAR_P10_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P11_MASK        ((uint32_t)0x08000000)
#define GPIO_IMPAR_R_P11_SHIFT       (27)

#define GPIO_IMPAR_P11_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P12_MASK        ((uint32_t)0x10000000)
#define GPIO_IMPAR_R_P12_SHIFT       (28)

#define GPIO_IMPAR_P12_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P13_MASK        ((uint32_t)0x20000000)
#define GPIO_IMPAR_R_P13_SHIFT       (29)

#define GPIO_IMPAR_P13_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P14_MASK        ((uint32_t)0x40000000)
#define GPIO_IMPAR_R_P14_SHIFT       (30)

#define GPIO_IMPAR_P14_SHIFT         ((uint32_t)0x00000001)
/*--------*/
/*--------*/
#define GPIO_IMPAR_R_P15_MASK        ((uint32_t)0x80000000)
#define GPIO_IMPAR_R_P15_SHIFT       (31)

#define GPIO_IMPAR_P15_SHIFT         ((uint32_t)0x00000001)
/*--------*/


#endif /* INCLUDE_GPIO_H_ */
