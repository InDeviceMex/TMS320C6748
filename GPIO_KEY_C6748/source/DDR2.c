/*
 * DDR2.c
 *
 *  Created on: 22/04/2019
 *      Author: InDev
 */

#include "DDR2.h"


Ddr2_nStatus DDR2__enInit(void)
{
    uint32_t u32TimeOut=50000;
    Psc_nStatus enStatus= PSC_enOK;
    // unlock the system config registers and set the ddr 2x clock source.
    SYSCFG0_KICK0R_R= SYSCFG_KICK0R_R_KICK0_KEY;
    SYSCFG0_KICK1R_R= SYSCFG_KICK1R_R_KICK1_KEY;

    // enable emif3a clock.
    enStatus= PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enDDR);

    if (enStatus!=PSC_enOK)
        return DDR2_enERROR;

    // check if vtp calibration is enabled.
    if (SYSCFG1_VTPIO_CTL_R & SYSCFG_VTPIO_CTL_R_POWERDN_MASK)
    {
       // vtp cal disabled, begin cal.

       // enable input buffer and vtp.
        SYSCFG1_VTPIO_CTL_R|=SYSCFG_VTPIO_CTL_R_IOPWRDN_MASK;
        SYSCFG1_VTPIO_CTL_R&=~SYSCFG_VTPIO_CTL_R_POWERDN_MASK;

       // pulse clrz to init vtp cal.
        SYSCFG1_VTPIO_CTL_R|=SYSCFG_VTPIO_CTL_R_CLKRZ_MASK;
        SYSCFG1_VTPIO_CTL_R&=~SYSCFG_VTPIO_CTL_R_CLKRZ_MASK;
        SYSCFG1_VTPIO_CTL_R|=SYSCFG_VTPIO_CTL_R_CLKRZ_MASK;

       // poll ready bit to wait for cal to complete.
       while (!(SYSCFG1_VTPIO_CTL_R &SYSCFG_VTPIO_CTL_R_READY_MASK))
       {
           if(u32TimeOut--==0)
               return DDR2_enERROR;

       }

       // set lock and power save bits.
       SYSCFG1_VTPIO_CTL_R|=SYSCFG_VTPIO_CTL_R_PWRSAVE_MASK|SYSCFG_VTPIO_CTL_R_LOCK_MASK;
    }

    // config ddr timing.
    DDR2_DRPYC1R_R = 0x000000C4;
    DDR2_SDCR_R = 0x0893C622;
    DDR2_SDCR_R &= ((DDR2_SDCR_R & 0xFF0FFFFF) | 0x00800000);
    DDR2_SDCR_R = ((DDR2_SDCR_R & 0xFF0FFFFF) | 0x02000000);
    DDR2_SDCR_R &= (~0x00008000);

    DDR2_SDTIMR1_R = 0x20923A89;
    DDR2_SDTIMR2_R = 0x0015C720;
    DDR2_SDCR2_R = 0x0;
    DDR2_SDRCR_R = 0x00000492;

    // set ddr2 to sync reset.
    DDR2_SDRCR_R|=0xC0000000;

    // sync reset the ddr clock.

    enStatus=PSC1__enSyncReset(DOMAIN_enD0,LPSC1_enDDR);

    if (enStatus!=PSC_enOK)
        return DDR2_enERROR;
    // enable the clock.
    enStatus=PSC1__enEnableLPSC(DOMAIN_enD0,LPSC1_enDDR);

    if (enStatus!=PSC_enOK)
        return DDR2_enERROR;
    // disable self refresh.
    DDR2_SDRCR_R&=~0xC0000000;

    return (DDR2_enOK);
}
