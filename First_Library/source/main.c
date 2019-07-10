

/**
 * main.c
 */
//#include <C6x.h>
#include <include/Cache.h>
#include <include/IDMA.h>
#include <include/BM.h>
#include <include/INTC.h>
#include <include/MPU.h>
#include <include/PLLC.h>
#include <include/PSC.h>
#include <include/SYSCFG.h>
#include <include/DDR2.h>
#include <include/GPIO.h>
#include <include/TIMER.h>

#include <stdio.h>
#include <string.h>

//#pragma DATA_MEM_BANK(x, 4);

void IDMA1_vIsr(void);
void NMI_vIsr(void);
void GPIO0_vIsr(void);
void TIMER2_vIsr(void);

#pragma DATA_SECTION (u32Test, ".datas")
uint32_t u32Test[10]={1,2,3,4,5,6,7,8,9,0};
#pragma DATA_SECTION (u32Test1, ".datas")
uint32_t u32Test1[10]={0xFF,0xAA, 0x65, 0xAAAA, 0x23,0x10,0x1000,0x54656561};
#pragma DATA_SECTION (u32Test2, ".datas")
uint32_t u32Test2[100]={0};

uint32_t counter1=0;
uint32_t counter2=0;
uint32_t filler=0x1;
float fFrequency=2000000;
uint32_t flagTimer1=0;
uint32_t flagTimer2=0;
uint32_t flagTimer3=0;


float freq=2000000;
uint64_t u64freq;
uint32_t u32Type=0;
uint32_t u32Cycles=0;
uint32_t u32Times=0;
void main(void)
{
    printf("-------------------------------------------------------------\r\n");
    printf("C6748 KEY, LED, INTERRUPT and TIMER2 Test start...\r\n\r\n");
    Psc_nStatus enPscStatus=PSC_enOK;
    Cache_nStatus enCacheStatus=CACHE_enOK;
    uint32_t i=0;
    TSCL=0;
    enPscStatus=PSC0__enEnableDsp();
    while (enPscStatus!=PSC_enOK)
    {
        printf("Enable PSC...   Fail\r\n");
    }
    enPscStatus=PSC__enInit();
    while (enPscStatus!=PSC_enOK)
    {
        printf("Enable PSC...   Fail\r\n");
    }
    printf("Enable PSC...   Complete\r\n");
    Cache__vEnableMARL2(0x80000000,0xFFFFFF);
    printf("Enable Cache in Shared SRAM...   Complete\r\n");
    enCacheStatus=Cache__enEnableL1P(MEMCFG1_en32K);
    while (enCacheStatus!=CACHE_enOK)
    {
        printf("Enable Cache L1P...   32KB fail\r\n");
    }
    printf("Enable Cache L1P...   32KB complete\r\n");
    enCacheStatus=Cache__enEnableL1D(MEMCFG1_en32K);
    while (enCacheStatus!=CACHE_enOK)
    {
        printf("Enable Cache L1D...   32KB fail\r\n");
    }
    printf("Enable Cache L1D...   32KB complete\r\n");
    enCacheStatus=Cache__enEnableL2(MEMCFG2_en128K);
    while (enCacheStatus!=CACHE_enOK)
    {
        printf("Enable Cache L2...   128KB fail\r\n");
    }
    printf("Enable Cache L2...   128KB complete\r\n");

    INTC__vDspInit();
    INTC__enCpuIntRegisterRoutine(MASK_enINT4,IDMA1_vIsr);
    INTC__enEventMap2CpuInt(MASK_enINT4,EVENT_enIDMAINT1);
    INTC__enCpuIntEnable(MASK_enINT4);
    printf("Enable IDMA-INT4...   complete\r\n");
    INTC__enCpuIntRegisterRoutine(MASK_enINT5,GPIO0_vIsr);
    INTC__enEventMap2CpuInt(MASK_enINT5,EVENT_enGPIO_B0INT);
    INTC__enCpuIntEnable(MASK_enINT5);
    printf("Enable GPIO0-INT5...   complete\r\n");
    INTC__enCpuIntRegisterRoutine(MASK_enINT6,TIMER2_vIsr);
    INTC__enEventMap2CpuInt(MASK_enINT6,EVENT_enT64P2_TINTALL);
    INTC__enCpuIntEnable(MASK_enINT6);
    printf("Enable TIMER2-INT6...   complete\r\n");



    INTC__enCpuIntRegisterRoutine(MASK_enNMI,NMI_vIsr);
    INTC__enCpuNmiEnable(MASK_enNMI);

    INTC__vIntGlobalEnable();
    IDMA1__enMem2Mem((uint32_t)u32Test1,(uint32_t)u32Test,4*4);
    counter1++;

    SYSCFG0->CFGCHIP3_Bit.ASYNC3_CLKSRC=0;
    SYSCFG0->PINMUX_Bit[6].PINMUX_31_28=8;//GP2_0
    SYSCFG0->PINMUX_Bit[5].PINMUX_31_28=8;//GP2_8
    SYSCFG0->PINMUX_Bit[0].PINMUX_3_0=8;//GP0_15
    SYSCFG0->PINMUX_Bit[13].PINMUX_19_16=8;//GP6_11
    SYSCFG0->PINMUX_Bit[13].PINMUX_15_12=8;//GP6_12

    SYSCFG0->PINMUX_Bit[1].PINMUX_31_28=8;//GP0_0
    SYSCFG0->PINMUX_Bit[1].PINMUX_27_24=8;//GP0_1

    SYSCFG0->PINMUX_Bit[4].PINMUX_11_8=4;//GP0_5=timer 2 out

    TIMER2->TGCR_Bit.PLUSEN=1;
    TIMER2->TCR_Bit.CLKSRC12=0;
    TIMER2->TGCR_Bit.TIMMODE=0;
    TIMER2->TGCR_Bit.TIM12RS=1;
    TIMER2->TGCR_Bit.TIM34RS=1;

    TIMER2->TCR_Bit.PWID12=0;
    TIMER2->TCR_Bit.CP12=1;
    TIMER2->GPINTGPEN_Bit.GPENO12=0;
    TIMER2->GPINTGPEN_Bit.GPENI12=1;
    TIMER2->GPINTGPEN_Bit.GPINT12INVO=0;
    TIMER2->GPINTGPEN_Bit.GPINT12ENO=0;

    TIMER2->INTCTLSTAT_Bit.PRDINTEN12=1;
    TIMER2->PRD12=100-1;
    TIMER2->PRD34=0;
    TIMER2->REL12=100-1;
    TIMER2->REL34=0;
    TIMER2->TIM12=0;
    TIMER2->TIM34=0;
    TIMER2->TCR_Bit.ENAMODE12=3;
    TIMER2->TCR_Bit.ENAMODE34=3;



    GPIO0_DIR_R&=~GPIO_R_P15_MASK;
    GPIO2_DIR_R&=~(GPIO_R_P8_MASK|GPIO_R_P0_MASK);
    GPIO6_DIR_R&=~(GPIO_R_P12_MASK|GPIO_R_P11_MASK);


    GPIO0_SET_FAL_TRIG_R|=(GPIO_R_P1_MASK|GPIO_R_P0_MASK);
    GPIO0_SET_RIS_TRIG_R|=(GPIO_R_P1_MASK|GPIO_R_P0_MASK);
    GPIO0_DIR_R|=(GPIO_R_P1_MASK|GPIO_R_P0_MASK);
    GPIO0_INTSTAT_R=(GPIO_R_P1_MASK|GPIO_R_P0_MASK);
    GPIO_BINTEN_R|=GPIO_R_P0_MASK;



    GPIO0_SET_DATA_R=GPIO_R_P15_MASK;
    GPIO2_CLR_DATA_R=(GPIO_R_P8_MASK|GPIO_R_P0_MASK);
    GPIO6_SET_DATA_R=(GPIO_R_P12_MASK|GPIO_R_P11_MASK);

/*
    PLLC0_OSCDIV->RATIO=10;
    PLLC0->OSCDIV_Bit.OD1EN=1;
    PLLC0->CKEN_Bit.OBSEN=1;
    PLLC0->OCSEL=0x17;
    SYSCFG0->PINMUX_Bit[13].PINMUX_7_4=0;
*/
    while(1)
    {

        u32Test[i+1]=u32Test[i]+i;

        if(i>=8)
        {
            IDMA1__enMem2Mem((uint32_t)u32Test,(uint32_t)u32Test1,10*4);
            counter1++;
            for(i=0; i<600000000; i++);
            GPIO2->OUT_DATA^=1|0x100;
            i=0;
            IDMA1__enMemFill((uint32_t)filler,(uint32_t)u32Test2,100*4);
            Cache__vWbL1D((uint32_t)u32Test,10*4);
         }
        else
        {
            i++;
        }

        if(flagTimer1)
        {
            flagTimer1=0;

        }
        if(flagTimer2)
        {
            if (flagTimer2==1)
            {
            }
            if (flagTimer2==2)
            {

                TIMER2->TGCR_Bit.TIM12RS=0;
                TIMER2->TGCR_Bit.TIM34RS=0;
                TIMER2->TCR_Bit.CP12^=1;
                TIMER2->TGCR_Bit.TIM12RS=1;
                TIMER2->TGCR_Bit.TIM34RS=1;
            }
            flagTimer2=0;

        }
        if(flagTimer3)
        {

            flagTimer3=0;
            freq=200000000.0/fFrequency;
            u64freq = (uint64_t) freq-1;
            TIMER2->TCR_Bit.ENAMODE34=0;
            TIMER2->TGCR_Bit.TIM12RS=0;
            TIMER2->TGCR_Bit.TIM34RS=0;
            TIMER2->PRD12=u64freq &0xFFFFFFFF;
            TIMER2->PRD34=(u64freq>>32) &0xFFFFFFFF;
            TIMER2->TIM12=0;
            TIMER2->TIM34=0;
            u32Cycles++;
            TIMER2->TCR_Bit.PWID12=u32Cycles&3;
            TIMER2->TGCR_Bit.TIM12RS=1;
            TIMER2->TGCR_Bit.TIM34RS=1;
            TIMER2->TCR_Bit.ENAMODE34=3;
            u32Times++;
            printf("Enter To Interrupt GPIO0...   %d\r\n",u32Times);

        }
    }
}


void NMI_vIsr(void)
{
    //INTC__enCpuNmiEnable(MASK_enNMI);
    GPIO6->OUT_DATA^=GPIO_R_P12_MASK;
}

void IDMA1_vIsr(void)
{
   INTC__enEventClear(EVENT_enIDMAINT1);
    counter2++;
}

void TIMER2_vIsr(void)
{
   INTC__enEventClear(EVENT_enT64P2_TINTALL);
   TIMER2->INTCTLSTAT_Bit.PRDINTSTAT12=1;
   counter2++;
}

void GPIO0_vIsr(void)
{
    INTC__enEventClear(EVENT_enGPIO_B0INT);


    flagTimer1=1;
    if(GPIO0_INTSTAT_R & GPIO_R_P0_MASK)
    {
        GPIO0_INTSTAT_R=GPIO_R_P0_MASK;
        if(GPIO0_IN_DATA_R &GPIO_R_P0_MASK)
        {
            flagTimer2=1;
            GPIO6_SET_DATA_R=GPIO_R_P11_MASK;
        }
        else
        {
            flagTimer2=2;
            GPIO6_CLR_DATA_R=GPIO_R_P11_MASK;

        }
    }
    if(GPIO0_INTSTAT_R & GPIO_R_P1_MASK)
    {
        GPIO0_INTSTAT_R=GPIO_R_P1_MASK;
        if(GPIO0_IN_DATA_R&GPIO_R_P1_MASK)
        {
            flagTimer3=1;
            GPIO0_SET_DATA_R=GPIO_R_P15_MASK;
        }
        else
        {

            GPIO0->CLR_DATA=GPIO_R_P15_MASK;
        }
    }

}
