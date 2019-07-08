/*
 * CACHe.h
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
extern void Cache__vInvL1PAll    (void);
extern void Cache__vInvL1DAll    (void);
extern void Cache__vWbInvL1DAll  (void);
extern void Cache__vWbL1DAll     (void);
extern void Cache__vInvL2All     (void);
extern void Cache__vWbInvL2All   (void);
extern void Cache__vWbL2All      (void);

extern void Cache__vInvL1P       (uint32_t u32BaseAddr, uint32_t u32ByteSize);
extern void Cache__vInvL1D       (uint32_t u32BaseAddr, uint32_t u32ByteSize);
extern void Cache__vWbInvL1D     (uint32_t u32BaseAddr, uint32_t u32ByteSize);
extern void Cache__vWbL1D        (uint32_t u32BaseAddr, uint32_t u32ByteSize);
extern void Cache__vInvL2        (uint32_t u32BaseAddr, uint32_t u32ByteSize);
extern void Cache__vWbInvL2      (uint32_t u32BaseAddr, uint32_t u32ByteSize);
extern void Cache__vWbL2         (uint32_t u32BaseAddr, uint32_t u32ByteSize);




extern Cache_nStatus Cache__enEnableL1P  (Cache_nMemCfg1 u32MemCfg);
extern Cache_nStatus Cache__enEnableL1D  (Cache_nMemCfg1 u32MemCfg);
extern Cache_nStatus Cache__enEnableL2   (Cache_nMemCfg2 u32MemCfg);

extern void Cache__vEnableMARL2 (uint32_t u32BaseAddr, uint32_t u32ByteSize);
extern void Cache__vDisableMARL2 (uint32_t u32BaseAddr, uint32_t u32ByteSize);




#endif /* INCLUDE_CACHE_H_ */
