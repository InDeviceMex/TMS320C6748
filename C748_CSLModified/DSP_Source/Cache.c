/*
 * L1P.c
 *
 *  Created on: 13/04/2019
 *      Author: InDev
 */

#include <Cache.h>

 //   _enable_interrupts();
 //   value=_disable_interrupts();
 //   _restore_interrupts(value);


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


#pragma FUNC_ALWAYS_INLINE( Cache_enEnableL1P)
#pragma FUNC_ALWAYS_INLINE( Cache_enEnableL1D)
#pragma FUNC_ALWAYS_INLINE( Cache_enEnableL2)

Cache_nStatus Cache_enEnableL1P  (Cache_nMemCfg1 u32MemCfg);
Cache_nStatus Cache_enEnableL1D  (Cache_nMemCfg1 u32MemCfg);
Cache_nStatus Cache_enEnableL2   (Cache_nMemCfg2 u32MemCfg);


Cache_nStatus Cache__enEnable(Cache_nMemCfg1 enMemCfgL1P, Cache_nMemCfg1 enMemCfgL1D, Cache_nMemCfg2 enMemCfgL2)
{
    Cache_nStatus nStatus=CACHE_enOK;
    if(Cache_enEnableL1P(enMemCfgL1P)==CACHE_enERROR)
    {
        nStatus|=CACHE_enERRORL1P;
    }
    if(Cache_enEnableL1D(enMemCfgL1D)==CACHE_enERROR)
    {
        nStatus|=CACHE_enERRORL1D;
    }
    if(Cache_enEnableL2(enMemCfgL2)==CACHE_enERROR)
    {
        nStatus|=CACHE_enERRORL2;
    }
    return nStatus;
}

//CACHE L1P

Cache_nStatus Cache_enEnableL1P (Cache_nMemCfg1 enMemCfg)
{
    uint32_t u32RestoreVal;
    if((enMemCfg >7) || (enMemCfg ==0) )
        return CACHE_enERROR;

    u32RestoreVal=_disable_interrupts();
    L1P_CFG_R = (L1P_CFG_R & ~L1P_CFG_R_MODE_MASK) | (enMemCfg & L1P_CFG_R_MODE_MASK);
    L1P_CFG_R;
    _restore_interrupts(u32RestoreVal);

    return CACHE_enOK;
}



void Cache__vInvL1PAll (void)
{
    uint32_t u32RestoreVal;
    u32RestoreVal = _disable_interrupts();
    while(L2_WWC_R != 0)
    {
        _restore_interrupts(u32RestoreVal);
        u32RestoreVal = _disable_interrupts();
    }
    L1P_INV_R=1;
    _restore_interrupts(u32RestoreVal);
    while(L1P_INV_R& 1);
}


void Cache__vInvL1P (uint32_t u32BaseAddr, uint32_t u32ByteSize)
{
    uint32_t u32AlignAddr, u32RestoreVal;
    int32_t  s32WordCnt;
    u32AlignAddr = u32BaseAddr & ~3;
    s32WordCnt = (u32ByteSize + 3 + (u32BaseAddr - u32AlignAddr)) >> 2;

    while(s32WordCnt > 0)
    {
        u32RestoreVal = _disable_interrupts();
        while(L2_WWC_R != 0)
        {
            _restore_interrupts(u32RestoreVal);
            u32RestoreVal = _disable_interrupts();
        }

        L1P_IBAR_R = u32AlignAddr;
        L1P_IWC_R  =(s32WordCnt > CACHE_MAXWC) ? CACHE_MAXWC : s32WordCnt;

        _restore_interrupts(u32RestoreVal);
        while(L1P_IWC_R != 0);
        s32WordCnt -= CACHE_MAXWC;
        u32AlignAddr += (CACHE_MAXWC * sizeof(unsigned int));
    }
    while(L2_WWC_R != 0);
}







//CACHE L1D


Cache_nStatus Cache_enEnableL1D (Cache_nMemCfg1 enMemCfg)
{
    uint32_t u32RestoreVal;
    if((enMemCfg >7) || (enMemCfg ==0) )
        return CACHE_enERROR;

    u32RestoreVal=_disable_interrupts();
    L1D_CFG_R = (L1D_CFG_R & ~L1D_CFG_R_MODE_MASK) | (enMemCfg & L1D_CFG_R_MODE_MASK);
    L1D_CFG_R;
    _restore_interrupts(u32RestoreVal);

    return CACHE_enOK;
}

void Cache__vInvL1DAll (void)
{
    uint32_t u32RestoreVal;

    u32RestoreVal = _disable_interrupts();
    while(L2_WWC_R != 0)
    {
        _restore_interrupts(u32RestoreVal);
        u32RestoreVal = _disable_interrupts();
    }
    L1D_INV_R=1;
    _restore_interrupts(u32RestoreVal);
    while(L1D_INV_R& 1);
}


void Cache__vInvL1D (uint32_t u32BaseAddr, uint32_t u32ByteSize)
{
    uint32_t u32AlignAddr, u32RestoreVal;
    int32_t  s32WordCnt;
    u32AlignAddr = u32BaseAddr & ~3;
    s32WordCnt = (u32ByteSize + 3 + (u32BaseAddr - u32AlignAddr)) >> 2;

    while(s32WordCnt > 0)
    {
        u32RestoreVal = _disable_interrupts();
        while(L2_WWC_R != 0)
        {
            _restore_interrupts(u32RestoreVal);
            u32RestoreVal = _disable_interrupts();
        }

        L1D_IBAR_R = u32AlignAddr;
        L1D_IWC_R  =(s32WordCnt > CACHE_MAXWC) ? CACHE_MAXWC : s32WordCnt;

        _restore_interrupts(u32RestoreVal);
        while(L1D_IWC_R != 0);
        s32WordCnt -= CACHE_MAXWC;
        u32AlignAddr += (CACHE_MAXWC * sizeof(unsigned int));
    }
    while(L2_WWC_R != 0);
}


void Cache__vWbInvL1DAll (void)
{
    uint32_t u32RestoreVal;

    u32RestoreVal = _disable_interrupts();
    while(L2_WWC_R != 0)
    {
        _restore_interrupts(u32RestoreVal);
        u32RestoreVal = _disable_interrupts();
    }
    L1D_WBINV_R=1;
    _restore_interrupts(u32RestoreVal);
    while(L1D_WBINV_R& 1);
}

void Cache__vWbInvL1D (uint32_t u32BaseAddr, uint32_t u32ByteSize)
{
    uint32_t u32AlignAddr, u32RestoreVal;
    int32_t  s32WordCnt;
    u32AlignAddr = u32BaseAddr & ~3;
    s32WordCnt = (u32ByteSize + 3 + (u32BaseAddr - u32AlignAddr)) >> 2;

    while(s32WordCnt > 0)
    {
        u32RestoreVal = _disable_interrupts();
        while(L2_WWC_R != 0)
        {
            _restore_interrupts(u32RestoreVal);
            u32RestoreVal = _disable_interrupts();
        }

        L1D_WIBAR_R = u32AlignAddr;
        L1D_WIWC_R  =(s32WordCnt > CACHE_MAXWC) ? CACHE_MAXWC : s32WordCnt;

        _restore_interrupts(u32RestoreVal);
        while(L1D_WIWC_R != 0);
        s32WordCnt -= CACHE_MAXWC;
        u32AlignAddr += (CACHE_MAXWC * sizeof(unsigned int));
    }
    while(L2_WWC_R != 0);
}


void Cache__vWbL1DAll (void)
{
    uint32_t u32RestoreVal;

    u32RestoreVal = _disable_interrupts();
    while(L2_WWC_R != 0)
    {
        _restore_interrupts(u32RestoreVal);
        u32RestoreVal = _disable_interrupts();
    }
    L1D_WB_R=1;
    _restore_interrupts(u32RestoreVal);
    while(L1D_WB_R& 1);
}


void Cache__vWbL1D (uint32_t u32BaseAddr, uint32_t u32ByteSize)
{
    uint32_t u32AlignAddr, u32RestoreVal;
    int32_t  s32WordCnt;
    u32AlignAddr = u32BaseAddr & ~3;
    s32WordCnt = (u32ByteSize + 3 + (u32BaseAddr - u32AlignAddr)) >> 2;

    while(s32WordCnt > 0)
    {
        u32RestoreVal = _disable_interrupts();
        while(L2_WWC_R != 0)
        {
            _restore_interrupts(u32RestoreVal);
            u32RestoreVal = _disable_interrupts();
        }

        L1D_WBAR_R = u32AlignAddr;
        L1D_WWC_R  =(s32WordCnt > CACHE_MAXWC) ? CACHE_MAXWC : s32WordCnt;

        _restore_interrupts(u32RestoreVal);
        while(L1D_WWC_R != 0);
        s32WordCnt -= CACHE_MAXWC;
        u32AlignAddr += (CACHE_MAXWC * sizeof(unsigned int));
    }
    while(L2_WWC_R != 0);
}




// CACHE L2


Cache_nStatus Cache_enEnableL2 (Cache_nMemCfg2 enMemCfg)
{
    uint32_t u32RestoreVal;
    if((enMemCfg >7) || (enMemCfg ==0) )
        return CACHE_enERROR;

    u32RestoreVal=_disable_interrupts();
    L2_CFG_R = (L2_CFG_R & ~L2_CFG_R_MODE_MASK) | (enMemCfg & L2_CFG_R_MODE_MASK);
    L2_CFG_R;
    _restore_interrupts(u32RestoreVal);

    return CACHE_enOK;
}

#pragma FUNC_ALWAYS_INLINE( Cache__vWbInvL2All)
__inline void Cache__vInvL2All (void)
{
    uint32_t u32RestoreVal;

    u32RestoreVal = _disable_interrupts();
    while(L2_WWC_R != 0)
    {
        _restore_interrupts(u32RestoreVal);
        u32RestoreVal = _disable_interrupts();
    }
    L2_INV_R=1;
    _restore_interrupts(u32RestoreVal);
    while(L2_INV_R& 1);
}


#pragma FUNC_ALWAYS_INLINE( Cache__vWbInvL2All)
__inline void Cache__vInvL2 (uint32_t u32BaseAddr, uint32_t u32ByteSize)
{
    uint32_t u32AlignAddr, u32RestoreVal;
    int32_t  s32WordCnt;
    u32AlignAddr = u32BaseAddr & ~3;
    s32WordCnt = (u32ByteSize + 3 + (u32BaseAddr - u32AlignAddr)) >> 2;

    while(s32WordCnt > 0)
    {
        u32RestoreVal = _disable_interrupts();
        while(L2_WWC_R != 0)
        {
            _restore_interrupts(u32RestoreVal);
            u32RestoreVal = _disable_interrupts();
        }

        L2_IBAR_R = u32AlignAddr;
        L2_IWC_R  =(s32WordCnt > CACHE_MAXWC) ? CACHE_MAXWC : s32WordCnt;

        _restore_interrupts(u32RestoreVal);
        while(L2_IWC_R != 0);
        s32WordCnt -= CACHE_MAXWC;
        u32AlignAddr += (CACHE_MAXWC * sizeof(unsigned int));
    }
    while(L2_WWC_R != 0);
}

#pragma FUNC_ALWAYS_INLINE( Cache__vWbInvL2All)
__inline void Cache__vWbInvL2All (void)
{
    uint32_t u32RestoreVal;

    u32RestoreVal = _disable_interrupts();
    while(L2_WWC_R != 0)
    {
        _restore_interrupts(u32RestoreVal);
        u32RestoreVal = _disable_interrupts();
    }
    L2_WBINV_R=1;
    _restore_interrupts(u32RestoreVal);
    while(L2_WBINV_R& 1);
}

#pragma FUNC_ALWAYS_INLINE( Cache__vWbInvL2)
__inline void Cache__vWbInvL2 (uint32_t u32BaseAddr, uint32_t u32ByteSize)
{
    uint32_t u32AlignAddr, u32RestoreVal;
    int32_t  s32WordCnt;
    u32AlignAddr = u32BaseAddr & ~3;
    s32WordCnt = (u32ByteSize + 3 + (u32BaseAddr - u32AlignAddr)) >> 2;

    while(s32WordCnt > 0)
    {
        u32RestoreVal = _disable_interrupts();
        while(L2_WWC_R != 0)
        {
            _restore_interrupts(u32RestoreVal);
            u32RestoreVal = _disable_interrupts();
        }

        L2_WIBAR_R = u32AlignAddr;
        L2_WIWC_R  =(s32WordCnt > CACHE_MAXWC) ? CACHE_MAXWC : s32WordCnt;

        _restore_interrupts(u32RestoreVal);
        while(L2_WIWC_R != 0);
        s32WordCnt -= CACHE_MAXWC;
        u32AlignAddr += (CACHE_MAXWC * sizeof(unsigned int));
    }
    while(L2_WWC_R != 0);
}


#pragma FUNC_ALWAYS_INLINE( Cache__vWbL2All)
__inline void Cache__vWbL2All (void)
{
    uint32_t u32RestoreVal;

    u32RestoreVal = _disable_interrupts();
    while(L2_WWC_R != 0)
    {
        _restore_interrupts(u32RestoreVal);
        u32RestoreVal = _disable_interrupts();
    }
    L2_WB_R=1;
    _restore_interrupts(u32RestoreVal);
    while(L2_WB_R& 1);
}

#pragma FUNC_ALWAYS_INLINE( Cache__vWbL2)
__inline void Cache__vWbL2 (uint32_t u32BaseAddr, uint32_t u32ByteSize)
{
    uint32_t u32AlignAddr, u32RestoreVal;
    int32_t  s32WordCnt;
    u32AlignAddr = u32BaseAddr & ~3;
    s32WordCnt = (u32ByteSize + 3 + (u32BaseAddr - u32AlignAddr)) >> 2;

    while(s32WordCnt > 0)
    {
        u32RestoreVal = _disable_interrupts();
        while(L2_WWC_R != 0)
        {
            _restore_interrupts(u32RestoreVal);
            u32RestoreVal = _disable_interrupts();
        }

        L2_WBAR_R = u32AlignAddr;
        L2_WWC_R  =(s32WordCnt > CACHE_MAXWC) ? CACHE_MAXWC : s32WordCnt;

        _restore_interrupts(u32RestoreVal);
        while(L2_WWC_R != 0);
        s32WordCnt -= CACHE_MAXWC;
        u32AlignAddr += (CACHE_MAXWC * sizeof(unsigned int));
    }
    while(L2_WWC_R != 0);
}



void Cache__vEnableMARL2 (uint32_t u32BaseAddr, uint32_t u32ByteSize)
{
    volatile uint32_t u32MaxAddr, u32FirstMar, u32LastMar, u32MarNum;

    u32MaxAddr = u32BaseAddr + u32ByteSize - 1;
    u32FirstMar = u32BaseAddr >> 24;
    u32LastMar = u32MaxAddr >> 24;

    for(u32MarNum = u32FirstMar; u32MarNum <= u32LastMar; u32MarNum++)
    {
        L2_MAR_R(u32MarNum) |= 1;
        asm(" NOP");
    }

    /* Read back value to stall CPU */
    L2_MAR_R(u32FirstMar);
}


void Cache__vDisableMARL2 (uint32_t u32BaseAddr, uint32_t u32ByteSize)
{
    volatile uint32_t u32MaxAddr, u32FirstMar, u32LastMar, u32MarNum;

    u32MaxAddr = u32BaseAddr + u32ByteSize - 1;
    u32FirstMar = u32BaseAddr >> 24;
    u32LastMar = u32MaxAddr >> 24;

    for(u32MarNum = u32FirstMar; u32MarNum <= u32LastMar; u32MarNum++)
    {
        L2_MAR_R(u32MarNum) &= ~1;
        asm(" NOP");
    }

    /* Read back value to stall CPU */
    L2_MAR_R(u32FirstMar);
}



