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



//CACHE L1P

Cache_nStatus Cache__enEnableL1P (Cache_nMemCfg1 enMemCfg)
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


Cache_nStatus Cache__enEnableL1D (Cache_nMemCfg1 enMemCfg)
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


Cache_nStatus Cache__enEnableL2 (Cache_nMemCfg2 enMemCfg)
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

void Cache__vInvL2All (void)
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


void Cache__vInvL2 (uint32_t u32BaseAddr, uint32_t u32ByteSize)
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

void Cache__vWbInvL2All (void)
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

void Cache__vWbInvL2 (uint32_t u32BaseAddr, uint32_t u32ByteSize)
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


void Cache__vWbL2All (void)
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

void Cache__vWbL2 (uint32_t u32BaseAddr, uint32_t u32ByteSize)
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
    uint32_t u32MaxAddr, u32FirstMar, u32LastMar, u32MarNum;

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
    uint32_t u32MaxAddr, u32FirstMar, u32LastMar, u32MarNum;

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



