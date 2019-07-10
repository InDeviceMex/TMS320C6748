/*
 * PSC.c
 *
 *  Created on: 19/04/2019
 *      Author: InDev
 */

#include "PSC.h"


Psc_nStatus PSC0__enEnableDsp(void)
{
    Psc_nStatus enStatus=PSC_enOK;
   // power dsp core.
    enStatus= PSC0__enEnableLPSC(DOMAIN_enD0,LPSC0_enDSP);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;
   // wake up dsp core and release from reset.
    enStatus= PSC0__enEnableCore(DOMAIN_enD0,LPSC0_enDSP);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;

    return PSC_enOK;
}


/*Force module state without handshaking */

Psc_nStatus PSC1__enForceLPSC(Lpsc1_nNumber nLpscNum)
{
    if(nLpscNum>31)
        return PSC_enERROR;
    PSC1_MDCTL_R(nLpscNum)|=0x80000000;
    return PSC_enOK;
}

/*SyncReset Function for PSC1*/
Psc_nStatus PSC1__enSyncReset(Psc_nDomain nPd, Lpsc1_nNumber nLpscNum)
{
    uint32_t u32TimeOut=10000;
    if(nPd>1)
        return PSC_enERROR;
    if(nLpscNum>31)
        return PSC_enERROR;
    if((PSC1_MDSTAT_R(nLpscNum)&0x1F)!=0x01)
    {
        PSC1_MDCTL_R(nLpscNum) =(PSC1_MDCTL_R(nLpscNum)&0xFFFFFFE0)|0x0001;
        PSC1_PTCMD_R = 0x1<<nPd;
        /*Wait for power state transition to finish*/
        while( (PSC1_PTSTAT_R & (0x1<<nPd) ) !=0)
        {
            if(u32TimeOut--==0)
            {
                return PSC_enERROR;
            }
        }
        u32TimeOut=10000;
        while(( PSC1_MDSTAT_R(nLpscNum) & 0x1F) !=0x1)
        {
            if(u32TimeOut--==0)
            {
                return PSC_enERROR;
            }
        }
    }
    return PSC_enOK;
}

/*Enable Function for PSC1*/
Psc_nStatus PSC1__enEnableLPSC(Psc_nDomain nPd, Lpsc1_nNumber nLpscNum)
{
    uint32_t u32TimeOut=10000;
    if(nPd>1)
        return PSC_enERROR;
    if(nLpscNum>31)
        return PSC_enERROR;
    if( (PSC1_MDSTAT_R(nLpscNum) & 0x1F) != 0x3)
    {
        PSC1_MDCTL_R(nLpscNum) = (PSC1_MDCTL_R(nLpscNum) & 0xFFFFFFE0) | 0x0003;
        PSC1_PTCMD_R= 0x1<<nPd;
        while( (PSC1_PTSTAT_R & (0x1<<nPd) ) !=0)
        {
            if(u32TimeOut--==0)
            {
                return PSC_enERROR;
            }
        }
        u32TimeOut=10000;
        while((PSC1_MDSTAT_R(nLpscNum)&0x1F) != 0x3)
        {
            if(u32TimeOut--==0)
            {
                return PSC_enERROR;
            }
        }
    }
    return PSC_enOK;
}


/*LPSC Enable Function for ARM or DSP*/

Psc_nStatus PSC0__enEnableCore(Psc_nDomain nPd, Lpsc0_nNumber nLpscNum)
{
    uint32_t u32TimeOut=10000;
    if(nPd>1)
        return PSC_enERROR;
    if(nLpscNum>15)
        return PSC_enERROR;
    if((PSC0_MDSTAT_R(nLpscNum)&0x11F)!=0x103)
    {
        PSC0_MDCTL_R(nLpscNum)=(PSC0_MDCTL_R(nLpscNum)&0xFFFFFEE0)|0x0103;
        PSC0_PTCMD_R = 0x1<<nPd;
        while( (PSC0_PTSTAT_R & (0x1<<nPd) ) !=0)
        {
            if(u32TimeOut--==0)
            {
                return PSC_enERROR;
            }
        }

        u32TimeOut=10000;
        while( (PSC0_MDSTAT_R(nLpscNum) & 0x11F) !=0x103)
        {
            if(u32TimeOut--==0)
            {
                return PSC_enERROR;
            }
        }
    }
    return PSC_enOK;
}

/*SyncReset Function for PSC0*/
Psc_nStatus PSC0__enSyncReset(Psc_nDomain nPd, Lpsc0_nNumber nLpscNum)
{
    uint32_t u32TimeOut=10000;
    if(nPd>1)
        return PSC_enERROR;
    if(nLpscNum>15)
        return PSC_enERROR;
    if((PSC0_MDSTAT_R(nLpscNum)&0x1F)!=0x01)
    {
        PSC0_MDCTL_R(nLpscNum) =(PSC0_MDCTL_R(nLpscNum)&0xFFFFFFE0)|0x0001;
        PSC0_PTCMD_R = 0x1<<nPd;
        /*Wait for power state transition to finish*/
        while( (PSC0_PTSTAT_R & (0x1<<nPd) ) !=0)
        {
            if(u32TimeOut--==0)
            {
                return PSC_enERROR;
            }
        }
        u32TimeOut=10000;
        while(( PSC0_MDSTAT_R(nLpscNum) & 0x1F) !=0x1)
        {
            if(u32TimeOut--==0)
            {
                return PSC_enERROR;
            }
        }
    }
    return PSC_enOK;
}


Psc_nStatus PSC0__enEnableLPSC(Psc_nDomain nPd, Lpsc0_nNumber nLpscNum)
{
    uint32_t u32TimeOut=10000;
    if(nPd>1)
        return PSC_enERROR;
    if(nLpscNum>15)
        return PSC_enERROR;
    if( (PSC0_MDSTAT_R(nLpscNum) & 0x1F) != 0x3)
    {
        PSC0_MDCTL_R(nLpscNum) = (PSC0_MDCTL_R(nLpscNum) & 0xFFFFFFE0) | 0x0003;
        PSC0_PTCMD_R= 0x1<<nPd;
        while( (PSC0_PTSTAT_R & (0x1<<nPd) ) !=0)
        {
            if(u32TimeOut--==0)
            {
                return PSC_enERROR;
            }
        }
        u32TimeOut=10000;
        while((PSC0_MDSTAT_R(nLpscNum)&0x1F) != 0x3)
        {
            if(u32TimeOut--==0)
            {
                return PSC_enERROR;
            }
        }
    }
    return PSC_enOK;
}


Psc_nStatus PSC__enInit(void)
{
    Psc_nStatus enStatus=PSC_enOK;

    enStatus= PSC0__enEnableLPSC(DOMAIN_enD0,LPSC0_enEMIFA);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;
    enStatus= PSC0__enEnableLPSC(DOMAIN_enD0,LPSC0_enSPI0);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;
    enStatus= PSC0__enEnableLPSC(DOMAIN_enD0,LPSC0_enMMCSD0);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;
    enStatus= PSC0__enEnableLPSC(DOMAIN_enD0,LPSC0_enUART0);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;
    enStatus= PSC0__enEnableLPSC(DOMAIN_enD0,LPSC0_enSCR0);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;
    enStatus= PSC0__enEnableLPSC(DOMAIN_enD0,LPSC0_enSCR1);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;
    enStatus= PSC0__enEnableLPSC(DOMAIN_enD0,LPSC0_enSCR2);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;
    enStatus= PSC0__enEnableLPSC(DOMAIN_enD0,LPSC0_enPRUSS);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;
    enStatus= PSC0__enEnableLPSC(DOMAIN_enD0,LPSC0_enPRUSS);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;
    enStatus= PSC0__enEnableLPSC(DOMAIN_enD0,LPSC0_enEDMA_CC0);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;
    enStatus= PSC0__enEnableLPSC(DOMAIN_enD0,LPSC0_enEDMA_TC0);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;
    enStatus= PSC0__enEnableLPSC(DOMAIN_enD0,LPSC0_enEDMA_TC1);
    if(enStatus!=PSC_enOK)
        return PSC_enERROR;
   //-----------------------------------------
   // PSC1, domain 0 - all modules, always on.
   //-----------------------------------------

   // configure the next state for psc1 modules.

   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enEDMA_CC1);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enUSB20);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enUSB11);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enGPIO);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enUHPI);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enEMAC);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enDDR);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enMCASP0);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enSATA);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enVPIF);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enSPI1);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enI2C1);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enUART1);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enUART2);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enMCBSP0);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enMCBSP1);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enLCDC);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enEPWM);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enMMCSD1);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enUPP);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enECAP);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enEDMA_TC2);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enSCR_F0);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enSCR_F1);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enSCR_F2);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enSCR_F6);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enSCR_F7);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enSCR_F8);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enBR_F7);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;
   enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enSHARED_RAM);
   if(enStatus!=PSC_enOK)
       return PSC_enERROR;

   return (PSC_enOK);
}
