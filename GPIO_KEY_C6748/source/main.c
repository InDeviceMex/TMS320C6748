

/**
 * main.c
 */
//#include <C6x.h>
#include <Cache.h>
#include <IDMA.h>
#include <BM.h>
#include <INTC.h>
#include <MPU.h>
#include <PLLC.h>
#include <PSC.h>
#include <SYSCFG.h>
#include <DDR2.h>
#include <GPIO.h>

#include <stdio.h>
#include <string.h>

//#pragma DATA_MEM_BANK(x, 4);

void IDMA1_vIsr(void);

#pragma DATA_SECTION (u32Test, ".datas")
uint32_t u32Test[10]={1,2,3,4,5,6,7,8,9,0};
#pragma DATA_SECTION (u32Test1, ".datas")
uint32_t u32Test1[10]={0xFF,0xAA, 0x65, 0xAAAA, 0x23,0x10,0x1000,0x54656561};
#pragma DATA_SECTION (u32Test2, ".datas")
uint32_t u32Test2[100]={0};

uint32_t counter1=0;
uint32_t counter2=0;
uint32_t filler=0x1;
void main(void)
{
  //  printf("------------------------------------------------------------\r\n");
  //  printf("              C6748 KEY GPIO Test start...\r\n\r\n");
    Psc_nStatus enPscStatus=PSC_enOK;
    Cache_nStatus enCacheStatus=CACHE_enOK;
    uint32_t i=0;
    enPscStatus=PSC0__enEnableDsp();
    //while (enPscStatus!=PSC_enOK);
    enPscStatus=PSC__enInit();
    //while (enPscStatus!=PSC_enOK);
    Cache__vEnableMARL2(0x80000000,0xFFFFFF);
    enCacheStatus=Cache__enEnableL1P(MEMCFG1_en32K);
    while (enCacheStatus!=CACHE_enOK);
    enCacheStatus=Cache__enEnableL1D(MEMCFG1_en32K);
    while (enCacheStatus!=CACHE_enOK);
    enCacheStatus=Cache__enEnableL2(MEMCFG2_en128K);
    while (enCacheStatus!=CACHE_enOK);

    INTC__vDspInit();
    INTC__enCpuIntRegisterRoutine(MASK_enINT4,IDMA1_vIsr);
    INTC__enEventMap2CpuInt(MASK_enINT4,EVENT_enIDMAINT1);
    INTC__enCpuIntEnable(MASK_enINT4);
    INTC__vIntGlobalEnable();
    IDMA1__enMem2Mem((uint32_t)u32Test1,(uint32_t)u32Test,4*4);
    counter1++;


    SYSCFG0->PINMUX_Bit[6].PINMUX_31_28=8;//GP2_0
    SYSCFG0->PINMUX_Bit[5].PINMUX_31_28=8;//GP2_8
    SYSCFG0->PINMUX_Bit[0].PINMUX_3_0=8;//GP0_15
    SYSCFG0->PINMUX_Bit[13].PINMUX_19_16=8;//GP6_11

    SYSCFG0->PINMUX_Bit[1].PINMUX_31_28=8;//GP0_0
    SYSCFG0->PINMUX_Bit[1].PINMUX_27_24=8;//GP0_1


    GPIO0->DIR&=~0x8000;
    GPIO2->DIR&=~0x101;
    GPIO6->DIR&=~0x0800;

    GPIO0->DIR|=0x0003;

    GPIO0->CLR_DATA|=0x8000;
    GPIO2->CLR_DATA=1|0x100;
    GPIO6->CLR_DATA|=0x0800;


    PLLC0_OSCDIV->RATIO=10;
    PLLC0->OSCDIV_Bit.OD1EN=1;
    PLLC0->CKEN_Bit.OBSEN=1;
    PLLC0->OCSEL=0x17;
    SYSCFG0->PINMUX_Bit[13].PINMUX_7_4=0;
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
            i++;

        if(GPIO0->IN_DATA&0x0001)
        {
            GPIO6->SET_DATA|=0x0800;
        }
        else
        {
            GPIO6->CLR_DATA|=0x0800;
        }
        if(GPIO0->IN_DATA&0x0002)
        {

            GPIO0->SET_DATA|=0x8000;
        }
        else
        {

            GPIO0->CLR_DATA|=0x8000;
        }
    }
}



void IDMA1_vIsr(void)
{
    INTC__enEventClear(EVENT_enIDMAINT1);
    counter2++;
}
