/*
 * Cache.h
 *
 *  Created on: 14/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_CACHE_H_
#define INCLUDE_CACHE_H_

#include "L1D.h"
#include "L1P.h"
#include "L2.h"

#define CACHE_MAXWC      (0xFFE0)

typedef enum
{
    CACHE_enOK = 0,
    CACHE_enERROR = 1,
    CACHE_enERRORL1P = 2,
    CACHE_enERRORL1D = 4,
    CACHE_enERRORL2 = 8,
}Cache_nStatus;


typedef enum
{
    MEMCFG1_enDISABLE = 0,
    MEMCFG1_en4K = 1,
    MEMCFG1_en8K = 2,
    MEMCFG1_en16K = 3,
    MEMCFG1_en32K = 4,
    MEMCFG1_enMaXIMUM = 5,
}Cache_nMemCfg1;

typedef enum
{
    MEMCFG2_enDISABLE = 0,
    MEMCFG2_en32K = 1,
    MEMCFG2_en64K = 2,
    MEMCFG2_en128K = 3,
    MEMCFG2_en256K = 4,
    MEMCFG2_enMaXIMUM = 5,
}Cache_nMemCfg2;


#pragma FUNC_ALWAYS_INLINE( Cache__vInvL1PAll)
#pragma FUNC_ALWAYS_INLINE( Cache__vInvL1DAll)
#pragma FUNC_ALWAYS_INLINE( Cache__vWbInvL1DAll)
#pragma FUNC_ALWAYS_INLINE( Cache__vWbL1DAll)
#pragma FUNC_ALWAYS_INLINE( Cache__vInvL2All)
#pragma FUNC_ALWAYS_INLINE( Cache__vWbInvL2All)
#pragma FUNC_ALWAYS_INLINE( Cache__vWbL2All)
#pragma FUNC_ALWAYS_INLINE( Cache__vInvL1P)
#pragma FUNC_ALWAYS_INLINE( Cache__vInvL1D)
#pragma FUNC_ALWAYS_INLINE( Cache__vWbInvL1D)
#pragma FUNC_ALWAYS_INLINE( Cache__vWbL1D)
#pragma FUNC_ALWAYS_INLINE( Cache__vInvL2)
#pragma FUNC_ALWAYS_INLINE( Cache__vWbInvL2)
#pragma FUNC_ALWAYS_INLINE( Cache__vWbL2)
#pragma FUNC_ALWAYS_INLINE( Cache__enEnable)
#pragma FUNC_ALWAYS_INLINE( Cache__vEnableMARL2)
#pragma FUNC_ALWAYS_INLINE( Cache__vDisableMARL2)

void Cache__vInvL1PAll    (void);
void Cache__vInvL1DAll    (void);
void Cache__vWbInvL1DAll  (void);
void Cache__vWbL1DAll     (void);
void Cache__vInvL2All     (void);
void Cache__vWbInvL2All   (void);
void Cache__vWbL2All      (void);

void Cache__vInvL1P       (uint32_t u32BaseAddr, uint32_t u32ByteSize);
void Cache__vInvL1D       (uint32_t u32BaseAddr, uint32_t u32ByteSize);
void Cache__vWbInvL1D     (uint32_t u32BaseAddr, uint32_t u32ByteSize);
void Cache__vWbL1D        (uint32_t u32BaseAddr, uint32_t u32ByteSize);
void Cache__vInvL2        (uint32_t u32BaseAddr, uint32_t u32ByteSize);
void Cache__vWbInvL2      (uint32_t u32BaseAddr, uint32_t u32ByteSize);
void Cache__vWbL2         (uint32_t u32BaseAddr, uint32_t u32ByteSize);



Cache_nStatus Cache__enEnable(Cache_nMemCfg1 enMemCfgL1P, Cache_nMemCfg1 enMemCfgL1D, Cache_nMemCfg2 enMemCfgL2);


void Cache__vEnableMARL2 (uint32_t u32BaseAddr, uint32_t u32ByteSize);
void Cache__vDisableMARL2 (uint32_t u32BaseAddr, uint32_t u32ByteSize);




#endif /* INCLUDE_CACHE_H_ */
