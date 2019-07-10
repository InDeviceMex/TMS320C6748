/*
 * IDMA.h
 *
 *  Created on: 14/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_IDMA_H_
#define INCLUDE_IDMA_H_


#include "Core.h"
#include <stdint.h>

#define IDMA0_BASE            ((uint32_t)0x01820000)
#define IDMA1_BASE            ((uint32_t)0x01820100)

typedef __IO struct
{
    __I uint32_t ACTV       :1;
    __I uint32_t PEND       :1;
        uint32_t reserved0  :30;
}IDMA_STAT_TypeDef;

typedef __IO struct
{
    __IO uint32_t M0       :1;
    __IO uint32_t M1       :1;
    __IO uint32_t M2       :1;
    __IO uint32_t M3       :1;
    __IO uint32_t M4       :1;
    __IO uint32_t M5       :1;
    __IO uint32_t M6       :1;
    __IO uint32_t M7       :1;
    __IO uint32_t M8       :1;
    __IO uint32_t M9       :1;
    __IO uint32_t M10       :1;
    __IO uint32_t M11       :1;
    __IO uint32_t M12       :1;
    __IO uint32_t M13       :1;
    __IO uint32_t M14       :1;
    __IO uint32_t M15       :1;
    __IO uint32_t M16      :1;
    __IO uint32_t M17      :1;
    __IO uint32_t M18      :1;
    __IO uint32_t M19      :1;
    __IO uint32_t M20      :1;
    __IO uint32_t M21      :1;
    __IO uint32_t M22      :1;
    __IO uint32_t M23      :1;
    __IO uint32_t M24      :1;
    __IO uint32_t M25      :1;
    __IO uint32_t M26      :1;
    __IO uint32_t M27      :1;
    __IO uint32_t M28      :1;
    __IO uint32_t M29      :1;
    __IO uint32_t M30      :1;
    __IO uint32_t M31      :1;
    __IO uint32_t M32      :1;
}IDMA_MASK_TypeDef;

typedef __IO struct
{
         uint32_t reserved0  :5;
    __IO uint32_t SOURCEADDR :27;
}IDMA_SOURCE_TypeDef;

typedef __IO struct
{
        uint32_t reserved0  :5;
    __IO uint32_t DESTADDR :27;
}IDMA_DEST_TypeDef;

typedef __IO struct
{
   __IO uint32_t COUNT       :4;
        uint32_t reserved0   :24;
   __IO uint32_t INT         :1;
        uint32_t reserved1   :3;
}IDMA_COUNT0_TypeDef;

typedef __IO struct
{
   __IO uint32_t COUNT       :16;
   __IO uint32_t FILL         :1;
        uint32_t reserved0   :11;
   __IO uint32_t INT         :1;
        uint32_t PRI         :3;
}IDMA_COUNT1_TypeDef;


typedef __IO struct
{
    union
    {
        __IO uint32_t       STAT;
        IDMA_STAT_TypeDef   STAT_Bit;
    };
    union
    {
        __IO uint32_t       MASK;
        IDMA_MASK_TypeDef   MASK_Bit;
    };
    union
    {
        __IO uint32_t       SOURCE;
        IDMA_SOURCE_TypeDef SOURCE_Bit;
    };

    union
    {
        __IO uint32_t       DEST;
        IDMA_DEST_TypeDef   DEST_Bit;
    };

    union
    {
        __IO uint32_t       COUNT;
        IDMA_COUNT0_TypeDef  COUNT_Bit;
    };

}IDMA0_TypeDef;


typedef __IO struct
{
    union
    {
        __IO uint32_t       STAT;
        IDMA_STAT_TypeDef   STAT_Bit;
    };
    uint32_t reserved0;
    union
    {
        __IO uint32_t       SOURCE;
        IDMA_SOURCE_TypeDef SOURCE_Bit;
    };

    union
    {
        __IO uint32_t       DEST;
        IDMA_DEST_TypeDef   DEST_Bit;
    };

    union
    {
        __IO uint32_t       COUNT;
        IDMA_COUNT1_TypeDef  COUNT_Bit;
    };

}IDMA1_TypeDef;

#define IDMA0            (((IDMA0_TypeDef*)(IDMA0_BASE)))
#define IDMA0_R(offset)  (*((__IO uint32_t *)(IDMA0_BASE+offset)))
#define IDMA1            (((IDMA1_TypeDef*)(IDMA1_BASE)))
#define IDMA1_R(offset)  (*((__IO uint32_t *)(IDMA1_BASE+offset)))


#define IDMA_STAT_OFFSET      ((uint32_t)0x0000)
#define IDMA_MASK_OFFSET      ((uint32_t)0x0004)
#define IDMA_SOURCE_OFFSET    ((uint32_t)0x0008)
#define IDMA_DEST_OFFSET      ((uint32_t)0x000C)
#define IDMA_COUNT_OFFSET     ((uint32_t)0x0010)




/**********************************************************************************************
************************************** 1 STAT ***********************************************
**********************************************************************************************/
#define IDMA0_STAT                    (((IDMA0_STAT_TypeDef*)(IDMA0_BASE+IDMA_STAT_OFFSET )))
#define IDMA0_STAT_R                  (*((__IO uint32_t *)(IDMA0_BASE+IDMA_STAT_OFFSET)))
#define IDMA1_STAT                    (((IDMA1_STAT_TypeDef*)(IDMA1_BASE+IDMA_STAT_OFFSET )))
#define IDMA1_STAT_R                  (*((__IO uint32_t *)(IDMA1_BASE+IDMA_STAT_OFFSET)))

/*--------*/
#define IDMA_STAT_R_ACTV_MASK        ((uint32_t)0x00000001)
#define IDMA_STAT_R_ACTV_SHIFT         (0)

#define IDMA_STAT_ACTV_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA_STAT_R_PEND_MASK        ((uint32_t)0x00000002)
#define IDMA_STAT_R_PEND_SHIFT         (1)

#define IDMA_STAT_PEND_MASK          ((uint32_t)0x00000001)
/*--------*/



/**********************************************************************************************
************************************** 2 MASK ***********************************************
**********************************************************************************************/
#define IDMA0_MASK                    (((IDMA0_MASK_TypeDef*)(IDMA0_BASE+IDMA_MASK_OFFSET )))
#define IDMA0_MASK_R                  (*((__IO uint32_t *)(IDMA0_BASE+IDMA_MASK_OFFSET)))


#define IDMA0_MASK_R_M(n)           (0x1 << ((n) & 31))
/*--------*/
#define IDMA0_MASK_R_M0_MASK        ((uint32_t)0x00000001)
#define IDMA0_MASK_R_M0_SHIFT         (0)

#define IDMA0_MASK_M0_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M1_MASK        ((uint32_t)0x00000002)
#define IDMA0_MASK_R_M1_SHIFT         (1)

#define IDMA0_MASK_M1_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M2_MASK        ((uint32_t)0x00000004)
#define IDMA0_MASK_R_M2_SHIFT         (2)

#define IDMA0_MASK_M2_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M3_MASK        ((uint32_t)0x00000008)
#define IDMA0_MASK_R_M3_SHIFT         (3)

#define IDMA0_MASK_M3_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M4_MASK        ((uint32_t)0x00000010)
#define IDMA0_MASK_R_M4_SHIFT         (4)

#define IDMA0_MASK_M4_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M5_MASK        ((uint32_t)0x00000020)
#define IDMA0_MASK_R_M5_SHIFT         (5)

#define IDMA0_MASK_M5_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M6_MASK        ((uint32_t)0x00000040)
#define IDMA0_MASK_R_M6_SHIFT         (6)

#define IDMA0_MASK_M6_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M7_MASK        ((uint32_t)0x00000080)
#define IDMA0_MASK_R_M7_SHIFT         (7)

#define IDMA0_MASK_M7_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M8_MASK        ((uint32_t)0x00000100)
#define IDMA0_MASK_R_M8_SHIFT         (8)

#define IDMA0_MASK_M8_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M9_MASK        ((uint32_t)0x00000200)
#define IDMA0_MASK_R_M9_SHIFT         (9)

#define IDMA0_MASK_M9_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M10_MASK        ((uint32_t)0x00000400)
#define IDMA0_MASK_R_M10_SHIFT         (10)

#define IDMA0_MASK_M10_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M11_MASK        ((uint32_t)0x00000800)
#define IDMA0_MASK_R_M11_SHIFT         (11)

#define IDMA0_MASK_M11_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M12_MASK        ((uint32_t)0x00001000)
#define IDMA0_MASK_R_M12_SHIFT         (12)

#define IDMA0_MASK_M12_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M13_MASK        ((uint32_t)0x00002000)
#define IDMA0_MASK_R_M13_SHIFT         (13)

#define IDMA0_MASK_M13_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M14_MASK        ((uint32_t)0x00004000)
#define IDMA0_MASK_R_M14_SHIFT         (14)

#define IDMA0_MASK_M14_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M15_MASK        ((uint32_t)0x00008000)
#define IDMA0_MASK_R_M15_SHIFT         (15)

#define IDMA0_MASK_M15_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define IDMA0_MASK_R_M16_MASK        ((uint32_t)0x00010000)
#define IDMA0_MASK_R_M16_SHIFT         (16)

#define IDMA0_MASK_M16_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M17_MASK        ((uint32_t)0x00020000)
#define IDMA0_MASK_R_M17_SHIFT         (17)

#define IDMA0_MASK_M17_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M18_MASK        ((uint32_t)0x00040000)
#define IDMA0_MASK_R_M18_SHIFT         (18)

#define IDMA0_MASK_M18_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M19_MASK        ((uint32_t)0x00080000)
#define IDMA0_MASK_R_M19_SHIFT         (19)

#define IDMA0_MASK_M19_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M20_MASK        ((uint32_t)0x00100000)
#define IDMA0_MASK_R_M20_SHIFT         (20)

#define IDMA0_MASK_M20_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M21_MASK        ((uint32_t)0x00200000)
#define IDMA0_MASK_R_M21_SHIFT         (21)

#define IDMA0_MASK_M21_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M22_MASK        ((uint32_t)0x00400000)
#define IDMA0_MASK_R_M22_SHIFT         (22)

#define IDMA0_MASK_M22_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M23_MASK        ((uint32_t)0x00800000)
#define IDMA0_MASK_R_M23_SHIFT         (23)

#define IDMA0_MASK_M23_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M24_MASK        ((uint32_t)0x01000000)
#define IDMA0_MASK_R_M24_SHIFT         (24)

#define IDMA0_MASK_M24_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M25_MASK        ((uint32_t)0x02000000)
#define IDMA0_MASK_R_M25_SHIFT         (25)

#define IDMA0_MASK_M25_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define IDMA0_MASK_R_M26_MASK        ((uint32_t)0x04000000)
#define IDMA0_MASK_R_M26_SHIFT         (26)

#define IDMA0_MASK_M26_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M27_MASK        ((uint32_t)0x08000000)
#define IDMA0_MASK_R_M27_SHIFT         (27)

#define IDMA0_MASK_M27_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M28_MASK        ((uint32_t)0x10000000)
#define IDMA0_MASK_R_M28_SHIFT         (28)

#define IDMA0_MASK_M28_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M29_MASK        ((uint32_t)0x20000000)
#define IDMA0_MASK_R_M29_SHIFT         (29)

#define IDMA0_MASK_M29_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M30_MASK        ((uint32_t)0x40000000)
#define IDMA0_MASK_R_M30_SHIFT         (30)

#define IDMA0_MASK_M30_MASK          ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_MASK_R_M31_MASK        ((uint32_t)0x80000000)
#define IDMA0_MASK_R_M31_SHIFT         (31)

#define IDMA0_MASK_M31_MASK          ((uint32_t)0x00000001)
/*--------*/

/**********************************************************************************************
************************************** 3 SOURCE ***********************************************
**********************************************************************************************/
#define IDMA0_SOURCE                    (((IDMA0_SOURCE_TypeDef*)(IDMA0_BASE+IDMA_SOURCE_OFFSET )))
#define IDMA0_SOURCE_R                  (*((__IO uint32_t *)(IDMA0_BASE+IDMA_SOURCE_OFFSET)))
#define IDMA1_SOURCE                    (((IDMA1_SOURCE_TypeDef*)(IDMA1_BASE+IDMA_SOURCE_OFFSET )))
#define IDMA1_SOURCE_R                  (*((__IO uint32_t *)(IDMA1_BASE+IDMA_SOURCE_OFFSET)))

/*--------*/
#define IDMA0_SOURCE_R_SOURCEADDR_MASK        ((uint32_t)0xFFFFFFE0)
#define IDMA0_SOURCE_R_SOURCEADDR_SHIFT         (5)

#define IDMA0_SOURCE_SOURCEADDR_MASK          ((uint32_t)0x07FFFFFF)
/*--------*/

/*--------*/
#define IDMA1_SOURCE_R_SOURCEADDR_MASK        ((uint32_t)0xFFFFFFFF)
#define IDMA1_SOURCE_R_SOURCEADDR_SHIFT         (0)

#define IDMA1_SOURCE_SOURCEADDR_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/

/**********************************************************************************************
************************************** 4 DEST ***********************************************
**********************************************************************************************/
#define IDMA0_DEST                    (((IDMA0_DEST_TypeDef*)(IDMA0_BASE+IDMA_DEST_OFFSET )))
#define IDMA0_DEST_R                  (*((__IO uint32_t *)(IDMA0_BASE+IDMA_DEST_OFFSET)))
#define IDMA1_DEST                    (((IDMA1_DEST_TypeDef*)(IDMA1_BASE+IDMA_DEST_OFFSET )))
#define IDMA1_DEST_R                  (*((__IO uint32_t *)(IDMA1_BASE+IDMA_DEST_OFFSET)))

/*--------*/
#define IDMA0_DEST_R_DESTADDR_MASK        ((uint32_t)0xFFFFFFE0)
#define IDMA0_DEST_R_DESTADDR_SHIFT         (5)

#define IDMA0_DEST_DESTADDR_MASK          ((uint32_t)0x07FFFFFF)
/*--------*/

/*--------*/
#define IDMA1_DEST_R_DESTADDR_MASK        ((uint32_t)0xFFFFFFFF)
#define IDMA1_DEST_R_DESTADDR_SHIFT         (0)

#define IDMA1_DEST_DESTADDR_MASK          ((uint32_t)0xFFFFFFFF)
/*--------*/


/**********************************************************************************************
************************************** 5 COUNT ***********************************************
**********************************************************************************************/
#define IDMA0_COUNT                    (((IDMA0_COUNT_TypeDef*)(IDMA0_BASE+IDMA_COUNT_OFFSET )))
#define IDMA0_COUNT_R                  (*((__IO uint32_t *)(IDMA0_BASE+IDMA_COUNT_OFFSET)))
#define IDMA1_COUNT                    (((IDMA1_COUNT_TypeDef*)(IDMA1_BASE+IDMA_COUNT_OFFSET )))
#define IDMA1_COUNT_R                  (*((__IO uint32_t *)(IDMA1_BASE+IDMA_COUNT_OFFSET)))

/*--------*/
#define IDMA_COUNT_R_INT_MASK        ((uint32_t)0x10000000)
#define IDMA_COUNT_R_INT_SHIFT         (28)

#define IDMA_COUNT_INT_MASK      ((uint32_t)0x00000001)
/*--------*/

/*--------*/
#define IDMA0_COUNT_R_COUNT_MASK        ((uint32_t)0x0000000F)
#define IDMA0_COUNT_R_COUNT_SHIFT         (0)

#define IDMA0_COUNT_COUNT_MASK      ((uint32_t)0x0000000F)
/*--------*/


/*--------*/
#define IDMA1_COUNT_R_COUNT_MASK        ((uint32_t)0x0000FFFF)
#define IDMA1_COUNT_R_COUNT_SHIFT         (0)

#define IDMA1_COUNT_COUNT_MASK          ((uint32_t)0x0000FFFF)
/*--------*/

/*--------*/
#define IDMA1_COUNT_R_FILL_MASK        ((uint32_t)0x00010000)
#define IDMA1_COUNT_R_FILL_SHIFT         (16)

#define IDMA1_COUNT_FILL_MASK          ((uint32_t)0x00000001)
/*--------*/


/*--------*/
#define IDMA1_COUNT_R_PRI_MASK        ((uint32_t)0xE0000000)
#define IDMA1_COUNT_R_PRI_SHIFT         (29)

#define IDMA1_COUNT_PRI_MASK      ((uint32_t)0x00000007)
/*--------*/



typedef enum
{
    IDMA_enOK = 0,
    IDMA_enFULL ,
    IDMA_enERROR ,
}Idma_nStatus;


extern Idma_nStatus IDMA1__enMem2Mem(uint32_t u32Source, uint32_t u32Dest, uint16_t u16Count);
extern Idma_nStatus IDMA1__enMemFill(uint32_t u32FillNumber, uint32_t u32Dest, uint16_t u16Count);

#endif /* INCLUDE_IDMA_H_ */
