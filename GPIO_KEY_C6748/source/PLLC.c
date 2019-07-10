/*
 * PLLC.c
 *
 *  Created on: 19/04/2019
 *      Author: InDev
 */

#include "PLLC.h"

static void PLLC_vDevicePLLC0(uint32_t u32ClkMode, uint32_t u32Pllm, uint32_t u32PostDiv,uint32_t u32PllDiv1, uint32_t u32PllDiv3, uint32_t u32PllDiv7 ) ;
static void PLLC_vDevicePLLC1(uint32_t u32Pllm,uint32_t u32PostDiv,uint32_t u32PllDiv1, uint32_t PLLDIV2, uint32_t u32PllDiv3 ) ;


void PLLC_vDevicePLLC0(uint32_t u32ClkMode, uint32_t u32Pllm, uint32_t u32PostDiv,uint32_t u32PllDiv1, uint32_t u32PllDiv3, uint32_t u32PllDiv7 )
{

   uint32_t i=0;

   /* Clear PLL lock bit */
   SYSCFG0_CFGCHIP0_R &= ~(SYSCFG_CFGCHIP0_R_PLL_MASTER_LOCK_MASK);

   /* Set PLLENSRC '0',bit 5, PLL Enable(PLLEN) selection is controlled through MMR */
   PLLC0_PLLCTL_R &= ~(PLLC_PLLCTL_R_PLLENSRC_MASK);

   /* PLLCTL.EXTCLKSRC bit 9 should be left at 0 for Freon */
   PLLC0_PLLCTL_R &= ~(PLLC0_PLLCTL_R_EXTCLKSRC_MASK);

   /* Set PLLEN=0 to put in bypass mode*/
   PLLC0_PLLCTL_R &= ~(PLLC_PLLCTL_R_PLLEN_MASK);

   /*wait for 4 cycles to allow PLLEN mux switches properly to bypass clock*/
   for(i=0; i<PLLEN_MUX_SWITCH; i++) {;}

   /* Select the Clock Mode bit 8 as External Clock or On Chip Oscilator*/
   PLLC0_PLLCTL_R &= 0xFFFFFEFF;
   PLLC0_PLLCTL_R |= (u32ClkMode << 8);

   /*Clear PLLRST bit to reset the PLL */
   PLLC0_PLLCTL_R &= ~(PLLC_PLLCTL_R_PLLRST_MASK);

   /* Disable the PLL output*/
   PLLC0_PLLCTL_R |= (0x00000010);

   /* PLL initialization sequence
   Power up the PLL by setting PWRDN bit set to 0 */
   PLLC0_PLLCTL_R &= ~(PLLC_PLLCTL_R_PLLPWRDN_MASK);

   /* Enable the PLL output*/
   PLLC0_PLLCTL_R &= ~(0x00000010);

   /*PLL stabilisation time- take out this step , not required here when PLL in bypassmode*/
   for(i=0; i<PLL_STABILIZATION_TIME; i++) {;}

   /*Program the required multiplier value in u32Pllm*/
   PLLC0_PLLM_R    = u32Pllm; /* Make PLLMULTIPLEIR as bootpacket*/

   /* Prediv setup -Not required */
   //  PLLC0_PREDIV = 0x8000 | PREDIV; /* Make u32PostDiv as bootpacket*/

   /*If desired to scale all the SYSCLK frequencies of a given PLLC, program the u32PostDiv ratio*/
   PLLC0_POSTDIV_R = PLLC_POSTDIV_R_POSTDEN_MASK | u32PostDiv; /* Make u32PostDiv as bootpacket*/

   /*Check for the GOSTAT bit in PLLSTAT to clear to 0 to indicate that no GO operation is currently in progress*/
   while((PLLC0_PLLSTAT_R & PLLC_PLLSTAT_R_GOSTAT_MASK)==1){}

   /*Program the RATIO field in PLLDIVx with the desired divide factors. In addition, make sure in this step you leave the PLLDIVx.DxEN bits set so clocks are still enabled (default).*/
   PLLC0_PLLDIV1_R = PLLC_PLLDIV1_R_D1EN_MASK | u32PllDiv1;   /* Make u32PllDiv1 as bootpacket, do it for other PLLDIVx to if required*/
   PLLC0_PLLDIV2_R = PLLC_PLLDIV2_R_D2EN_MASK | (((u32PllDiv1+1)*2)-1);
   PLLC0_PLLDIV4_R = PLLC_PLLDIV4_R_D4EN_MASK | (((u32PllDiv1+1)*4)-1);
   PLLC0_PLLDIV6_R = PLLC_PLLDIV6_R_D6EN_MASK | u32PllDiv1;
   PLLC0_PLLDIV3_R = PLLC_PLLDIV3_R_D3EN_MASK | u32PllDiv3;   /* Make u32PllDiv3 as bootpacket, do it for other PLLDIVx to if required*/
   PLLC0_PLLDIV7_R = PLLC_PLLDIV7_R_D7EN_MASK | u32PllDiv7;   /* Make u32PllDiv7 as bootpacket, do it for other PLLDIVx to if required*/


   /*Set the GOSET bit in PLLCMD to 1 to initiate a new divider transition.*/
   PLLC0_PLLCMD_R |= PLLC_PLLCMD_R_GOSET_MASK;

   /*Wait for the GOSTAT bit in PLLSTAT to clear to 0 (completion of phase alignment).*/
   while((PLLC0_PLLSTAT_R & PLLC_PLLSTAT_R_GOSTAT_MASK)==1) { }

   /*Wait for PLL to reset properly. See PLL spec for PLL reset time - This step is not required here -step11*/
   for(i=0; i<PLL_RESET_TIME_CNT; i++) {;}   /*128 MXI Cycles*/

   /*Set the PLLRST bit in PLLCTL to 1 to bring the PLL out of reset*/
   PLLC0_PLLCTL_R |= PLLC_PLLCTL_R_PLLRST_MASK;

   /*Wait for PLL to lock. See PLL spec for PLL lock time*/
   for(i=0; i<PLL_LOCK_TIME_CNT; i++) {;} /*Make PLL_LOCK_TIME_CNT as boot Packet*/

   /*Set the PLLEN bit in PLLCTL to 1 to remove the PLL from bypass mode*/
   PLLC0_PLLCTL_R |=  PLLC_PLLCTL_R_PLLEN_MASK;

   /* SET PLL lock bit*/
   SYSCFG0_CFGCHIP0_R |= SYSCFG_CFGCHIP0_R_PLL_MASTER_LOCK_MASK;
}


/**********************************************************************************
DDR PLLC1 init:

***********************************************************************************/

void PLLC_vDevicePLLC1(uint32_t u32Pllm,uint32_t u32PostDiv,uint32_t u32PllDiv1, uint32_t PLLDIV2, uint32_t u32PllDiv3 )
{

   uint32_t i=0;

   /* Clear PLL lock bit */
   SYSCFG0_CFGCHIP3_R &= ~(SYSCFG_CFGCHIP3_R_PLL1_MASTER_LOCK_MASK);

   /* Set PLLENSRC '0',bit 5, PLL Enable(PLLEN) selection is controlled through MMR */
   PLLC1_PLLCTL_R &= ~(PLLC_PLLCTL_R_PLLENSRC_MASK);

   /* PLLCTL.EXTCLKSRC bit 9 should be left at 0 for Freon */
   PLLC1_PLLCTL_R &= ~(PLLC0_PLLCTL_R_EXTCLKSRC_MASK);

   /* Set PLLEN=0 to put in bypass mode*/
   PLLC1_PLLCTL_R &= ~(PLLC_PLLCTL_R_PLLEN_MASK);

   /*wait for 4 cycles to allow PLLEN mux switches properly to bypass clock*/
   for(i=0; i<PLLEN_MUX_SWITCH; i++) {;}

   /* Select the Clock Mode bit 8 as External Clock or On Chip Oscilator*/
   /* PLLC1_PLLCTL_R &= 0xFFFFFEFF;
   PLLC1_PLLCTL_R |= (u32ClkMode << 8); */

   /*Clear PLLRST bit to reset the PLL */
   PLLC1_PLLCTL_R &= ~(PLLC_PLLCTL_R_PLLRST_MASK);

   /* Disable the PLL output*/
   PLLC1_PLLCTL_R |= (0x00000010);

   /* PLL initialization sequence
   Power up the PLL by setting PWRDN bit set to 0 */
   PLLC1_PLLCTL_R &= ~(PLLC_PLLCTL_R_PLLPWRDN_MASK);

   /* Enable the PLL output*/
   PLLC1_PLLCTL_R &= ~(0x00000010);

   /*PLL stabilisation time- take out this step , not required here when PLL in bypassmode*/
   for(i=0; i<PLL_STABILIZATION_TIME; i++) {;}

   /*Program the required multiplier value in u32Pllm*/
   PLLC1_PLLM_R    = u32Pllm; /* Make PLLMULTIPLEIR as bootpacket*/

   /*If desired to scale all the SYSCLK frequencies of a given PLLC, program the u32PostDiv ratio*/
   PLLC1_POSTDIV_R = PLLC_POSTDIV_R_POSTDEN_MASK | u32PostDiv; /* Make u32PostDiv as bootpacket*/

   /*Check for the GOSTAT bit in PLLSTAT to clear to 0 to indicate that no GO operation is currently in progress*/
   while((PLLC1_PLLSTAT_R & PLLC_PLLSTAT_R_GOSTAT_MASK)==PLLC_PLLSTAT_R_GOSTAT_MASK){}

   /*Program the RATIO field in PLLDIVx with the desired divide factors. In addition, make sure in this step you leave the PLLDIVx.DxEN bits set so clocks are still enabled (default).*/
   PLLC1_PLLDIV1_R = PLLC_PLLDIV1_R_D1EN_MASK | u32PllDiv1;   /* Make u32PllDiv1 as bootpacket, do it for other PLLDIVx to if required*/
   PLLC1_PLLDIV2_R = PLLC_PLLDIV2_R_D2EN_MASK | PLLDIV2;   /* Make PLLDIV2 as bootpacket, do it for other PLLDIVx to if required*/
   PLLC1_PLLDIV3_R = PLLC_PLLDIV3_R_D3EN_MASK | u32PllDiv3;   /* Make u32PllDiv3 as bootpacket, do it for other PLLDIVx to if required*/

   /*Set the GOSET bit in PLLCMD to 1 to initiate a new divider transition.*/
   PLLC1_PLLCMD_R |= PLLC_PLLCMD_R_GOSET_MASK;

   /*Wait for the GOSTAT bit in PLLSTAT to clear to 0 (completion of phase alignment).*/
   while((PLLC1_PLLSTAT_R & PLLC_PLLSTAT_R_GOSTAT_MASK)==PLLC_PLLSTAT_R_GOSTAT_MASK) { }

   /*Wait for PLL to reset properly. See PLL spec for PLL reset time - */
   for(i=0; i<PLL_RESET_TIME_CNT; i++) {;}   /*128 MXI Cycles*/

   /*Set the PLLRST bit in PLLCTL to 1 to bring the PLL out of reset*/
   PLLC1_PLLCTL_R |= PLLC_PLLCTL_R_PLLRST_MASK;

   /*Wait for PLL to lock. See PLL spec for PLL lock time*/
   for(i=0; i<PLL_LOCK_TIME_CNT; i++) {;} /*Make PLL_LOCK_TIME_CNT as boot Packet*/

   /*Set the PLLEN bit in PLLCTL to 1 to remove the PLL from bypass mode*/
   PLLC1_PLLCTL_R |=  PLLC_PLLCTL_R_PLLEN_MASK;

   /* SET PLL lock bit*/
   SYSCFG0_CFGCHIP3_R |= SYSCFG_CFGCHIP3_R_PLL1_MASTER_LOCK_MASK;

}


void PLLC__vSetCore400Mhz(void)
{
    PLLC_vDevicePLLC0(1,15,0,0,3,7);
}
