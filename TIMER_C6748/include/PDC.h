/*
 * PD.h
 *
 *  Created on: 16/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_PDC_H_
#define INCLUDE_PDC_H_

#include "Core.h"
#include <stdint.h>

#define PDC_BASE            ((uint32_t)0x01810000)

typedef __IO struct
{
         uint32_t reserved0 :16;
    __IO uint32_t MEGPD       :1;
         uint32_t reserved1 :15;
}PDC_CMD_TypeDef;

typedef __IO struct
{
    union
    {
        __IO uint32_t         CMD;
        PDC_CMD_TypeDef       CMD_Bit;
    };
}PDC_TypeDef;


#define PDC            (((PDC_TypeDef*)(PDC_BASE)))
#define PDC_R(offset)  (*((__IO uint32_t *)(PDC_BASE+offset)))


#define PDC_CMD_OFFSET      ((uint32_t)0x0000)


/**********************************************************************************************
************************************** 1 CMD ***********************************************
**********************************************************************************************/
#define PDC_CMD                    (((PDC_CMD_TypeDef*)(PDC_BASE+PDC_CMD_OFFSET )))
#define PDC_CMD_R                  (*((__IO uint32_t *)(PDC_BASE+PDC_CMD_OFFSET)))

/*--------*/
#define PDC_CMD_R_MEGPD_MASK        ((uint32_t)0x00010000)
#define PDC_CMD_R_MEGPD_SHIFT       (16)

#define PDC_CMD_MEGPD_MASK          ((uint32_t)0x00000001)
/*--------*/


#endif /* INCLUDE_PDC_H_ */
