/*
 * BM.h
 *
 *  Created on: 16/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_BM_H_
#define INCLUDE_BM_H_


#include "Core.h"
#include <stdint.h>

#define BM_BASE            ((uint32_t)0x01841000)

typedef __IO struct
{
    __IO uint32_t MAXWAIT   :6;
         uint32_t reserved0 :10;
    __IO uint32_t PRI       :3;
         uint32_t reserved1 :13;
}BM_CPUARB_TypeDef;

typedef __IO struct
{
    __IO uint32_t MAXWAIT   :6;
         uint32_t reserved0 :26;
}BM_UCARB_TypeDef;

typedef __IO struct
{
    __IO uint32_t MAXWAIT   :6;
         uint32_t reserved0 :26;
}BM_IDMAARB_TypeDef;

typedef __IO struct
{
    __IO uint32_t MAXWAIT   :6;
         uint32_t reserved0 :26;
}BM_SDMAARB_TypeDef;

typedef __IO struct
{
         uint32_t reserved0 :16;
    __IO uint32_t PRI       :3;
         uint32_t reserved1 :13;
}BM_MDMAARB_TypeDef;


typedef __IO struct
{
    union
    {
        __IO uint32_t       CPUARBU;
        BM_CPUARB_TypeDef   CPUARBU_Bit;
    };
    union
    {
        __IO uint32_t        IDMAARBU;
        BM_IDMAARB_TypeDef   IDMAARBU_Bit;
    };
    union
    {
        __IO uint32_t       SDMAARBU;
        BM_SDMAARB_TypeDef  SDMAARBU_Bit;
    };
    union
    {
        __IO uint32_t       UCARBU;
        BM_UCARB_TypeDef    UCARBU_Bit;
    };
    uint32_t reserved0[15];
    union
    {
        __IO uint32_t       CPUARBD;
        BM_CPUARB_TypeDef   CPUARBD_Bit;
    };
    union
    {
        __IO uint32_t        IDMAARBD;
        BM_IDMAARB_TypeDef   IDMAARBD_Bit;
    };
    union
    {
        __IO uint32_t       SDMAARBD;
        BM_SDMAARB_TypeDef  SDMAARBD_Bit;
    };
    union
    {
        __IO uint32_t       UCARBD;
        BM_UCARB_TypeDef    UCARBD_Bit;
    };
    uint32_t reserved1[108];
    union
    {
        __IO uint32_t       CPUARBE;
        BM_CPUARB_TypeDef   CPUARBE_Bit;
    };
    union
    {
        __IO uint32_t        IDMAARBE;
        BM_IDMAARB_TypeDef   IDMAARBE_Bit;
    };
    union
    {
        __IO uint32_t       SDMAARBE;
        BM_SDMAARB_TypeDef  SDMAARBE_Bit;
    };
    union
    {
        __IO uint32_t         MDMAARBE;
        BM_MDMAARB_TypeDef    MDMAARBE_Bit;
    };
}BM_TypeDef;



#define BM            (((BM_TypeDef*)(BM_BASE)))
#define BM_R(offset)  (*((__IO uint32_t *)(BM_BASE+offset)))


#define BM_CPUARBU_OFFSET      ((uint32_t)0x0000)
#define BM_IDMAARBU_OFFSET     ((uint32_t)0x0004)
#define BM_SDMAARBU_OFFSET     ((uint32_t)0x0008)
#define BM_UCARBU_OFFSET       ((uint32_t)0x000C)
#define BM_CPUARBD_OFFSET      ((uint32_t)0x0040)
#define BM_IDMAARBD_OFFSET     ((uint32_t)0x0044)
#define BM_SDMAARBD_OFFSET     ((uint32_t)0x0048)
#define BM_UCARBD_OFFSET       ((uint32_t)0x004C)
#define BM_CPUARBE_OFFSET      ((uint32_t)0x0200)
#define BM_IDMAARBE_OFFSET     ((uint32_t)0x0204)
#define BM_SDMAARBE_OFFSET     ((uint32_t)0x0208)
#define BM_MDMAARBE_OFFSET     ((uint32_t)0x020C)




/**********************************************************************************************
************************************** 1 CPUARB ***********************************************
**********************************************************************************************/
#define BM_CPUARBU                    (((BM_CPUARB_TypeDef*)(BM_BASE+BM_CPUARBU_OFFSET )))
#define BM_CPUARBU_R                  (*((__IO uint32_t *)(BM_BASE+BM_CPUARBU_OFFSET)))
#define BM_CPUARBD                    (((BM_CPUARB_TypeDef*)(BM_BASE+BM_CPUARBD_OFFSET )))
#define BM_CPUARBD_R                  (*((__IO uint32_t *)(BM_BASE+BM_CPUARBD_OFFSET)))
#define BM_CPUARBE                    (((BM_CPUARB_TypeDef*)(BM_BASE+BM_CPUARBE_OFFSET )))
#define BM_CPUARBE_R                  (*((__IO uint32_t *)(BM_BASE+BM_CPUARBE_OFFSET)))

/*--------*/
#define BM_CPUARB_R_MAXWAIT_MASK        ((uint32_t)0x0000003F)
#define BM_CPUARB_R_MAXWAIT_SHIFT       (0)

#define BM_CPUARB_MAXWAIT_MASK          ((uint32_t)0x0000003F)
/*--------*/

/*--------*/
#define BM_CPUARB_R_PRI_MASK        ((uint32_t)0x00070000)
#define BM_CPUARB_R_PRI_SHIFT       (16)

#define BM_CPUARB_PRI_MASK          ((uint32_t)0x00000007)
/*--------*/

/**********************************************************************************************
************************************** 2 IDMAARB ***********************************************
**********************************************************************************************/
#define BM_IDMAARBU                    (((BM_IDMAARB_TypeDef*)(BM_BASE+BM_IDMAARBU_OFFSET )))
#define BM_IDMAARBU_R                  (*((__IO uint32_t *)(BM_BASE+BM_IDMAARBU_OFFSET)))
#define BM_IDMAARBD                    (((BM_IDMAARB_TypeDef*)(BM_BASE+BM_IDMAARBD_OFFSET )))
#define BM_IDMAARBD_R                  (*((__IO uint32_t *)(BM_BASE+BM_IDMAARBD_OFFSET)))
#define BM_IDMAARBE                    (((BM_IDMAARB_TypeDef*)(BM_BASE+BM_IDMAARBE_OFFSET )))
#define BM_IDMAARBE_R                  (*((__IO uint32_t *)(BM_BASE+BM_IDMAARBE_OFFSET)))

/*--------*/
#define BM_IDMAARB_R_MAXWAIT_MASK        ((uint32_t)0x0000003F)
#define BM_IDMAARB_R_MAXWAIT_SHIFT       (0)

#define BM_IDMAARB_MAXWAIT_MASK          ((uint32_t)0x0000003F)
/*--------*/



/**********************************************************************************************
************************************** 3 SDMAARB ***********************************************
**********************************************************************************************/
#define BM_SDMAARBU                    (((BM_SDMAARB_TypeDef*)(BM_BASE+BM_SDMAARBU_OFFSET )))
#define BM_SDMAARBU_R                  (*((__IO uint32_t *)(BM_BASE+BM_SDMAARBU_OFFSET)))
#define BM_SDMAARBD                    (((BM_SDMAARB_TypeDef*)(BM_BASE+BM_SDMAARBD_OFFSET )))
#define BM_SDMAARBD_R                  (*((__IO uint32_t *)(BM_BASE+BM_SDMAARBD_OFFSET)))
#define BM_SDMAARBE                    (((BM_SDMAARB_TypeDef*)(BM_BASE+BM_SDMAARBE_OFFSET )))
#define BM_SDMAARBE_R                  (*((__IO uint32_t *)(BM_BASE+BM_SDMAARBE_OFFSET)))

/*--------*/
#define BM_SDMAARB_R_MAXWAIT_MASK        ((uint32_t)0x0000003F)
#define BM_SDMAARB_R_MAXWAIT_SHIFT       (0)

#define BM_SDMAARB_MAXWAIT_MASK          ((uint32_t)0x0000003F)
/*--------*/


/**********************************************************************************************
************************************** 4 UCARB ***********************************************
**********************************************************************************************/
#define BM_UCARBU                    (((BM_UCARB_TypeDef*)(BM_BASE+BM_UCARBU_OFFSET )))
#define BM_UCARBU_R                  (*((__IO uint32_t *)(BM_BASE+BM_UCARBU_OFFSET)))
#define BM_UCARBD                    (((BM_UCARB_TypeDef*)(BM_BASE+BM_UCARBD_OFFSET )))
#define BM_UCARBD_R                  (*((__IO uint32_t *)(BM_BASE+BM_UCARBD_OFFSET)))

/*--------*/
#define BM_UCARB_R_MAXWAIT_MASK        ((uint32_t)0x0000003F)
#define BM_UCARB_R_MAXWAIT_SHIFT       (0)

#define BM_UCARB_MAXWAIT_MASK          ((uint32_t)0x0000003F)
/*--------*/


/**********************************************************************************************
************************************** 5 MDMAARB ***********************************************
**********************************************************************************************/
#define BM_MDMAARBE                    (((BM_MDMAARB_TypeDef*)(BM_BASE+BM_MDMAARBE_OFFSET )))
#define BM_MDMAARBE_R                  (*((__IO uint32_t *)(BM_BASE+BM_MDMAARBE_OFFSET)))

/*--------*/
#define BM_CPUARB_R_PRI_MASK        ((uint32_t)0x00070000)
#define BM_CPUARB_R_PRI_SHIFT       (16)

#define BM_CPUARB_PRI_MASK          ((uint32_t)0x00000007)
/*--------*/




#endif /* INCLUDE_BM_H_ */
