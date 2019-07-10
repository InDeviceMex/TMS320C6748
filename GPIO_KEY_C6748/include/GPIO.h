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




#endif /* INCLUDE_GPIO_H_ */
