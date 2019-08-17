/*
 * IDMA.c
 *
 *  Created on: 14/04/2019
 *      Author: InDev
 */


#include "IDMA.h"

#pragma FUNC_ALWAYS_INLINE( IDMA1__enMem2Mem)
#pragma FUNC_ALWAYS_INLINE( IDMA1__enMemFill)

Idma_nStatus IDMA1__enMem2Mem(uint32_t u32Source, uint32_t u32Dest, uint16_t u16Count)
{
    if(IDMA1_STAT_R&IDMA_STAT_R_PEND_MASK)
        return IDMA_enERROR;


    IDMA1_SOURCE_R= u32Source& IDMA1_SOURCE_R_SOURCEADDR_MASK;
    IDMA1_DEST_R= u32Dest& IDMA1_DEST_R_DESTADDR_MASK;
    IDMA1_COUNT_R= ((u16Count&0xFFFC))|
            //((u16Count&0xFFFC));//|
           IDMA_COUNT_R_INT_MASK|
           ((0x6u<<IDMA1_COUNT_R_PRI_SHIFT));

    return IDMA_enOK;
}

Idma_nStatus IDMA1__enMemFill(uint32_t u32FillNumber, uint32_t u32Dest, uint16_t u16Count)
{
    if(IDMA1_STAT_R&IDMA_STAT_R_PEND_MASK)
        return IDMA_enERROR;


    IDMA1_SOURCE_R= u32FillNumber& IDMA1_SOURCE_R_SOURCEADDR_MASK;
    IDMA1_DEST_R= u32Dest& IDMA1_DEST_R_DESTADDR_MASK;
    IDMA1_COUNT_R= (u16Count&0xFFFC)|IDMA1_COUNT_R_FILL_MASK;

    return IDMA_enOK;
}
