

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
#include <TIMER.h>

#include <stdio.h>
#include <string.h>

//#pragma DATA_MEM_BANK(x, 4);


#pragma DATA_SECTION (u32Test, ".datas")
uint32_t u32Test[10]={1,2,3,4,5,6,7,8,9,0};
#pragma DATA_SECTION (u32Test1, ".datas")
uint32_t u32Test1[10]={0xFF,0xAA, 0x65, 0xAAAA, 0x23,0x10,0x1000,0x54656561};
#pragma DATA_SECTION (u32Test2, ".datas")
uint32_t u32Test2[100]={0};

uint32_t filler=0x1;
void main(void)
{
    printf("-------------------------------------------------------------\r\n");
    printf("C6748 IDMA and CACHE Test start...\r\n\r\n");
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

    IDMA1__enMem2Mem((uint32_t)u32Test1,(uint32_t)u32Test,4*4);

    while(1)
    {


        if(i>=8)
        {
            IDMA1__enMem2Mem((uint32_t)u32Test,(uint32_t)u32Test1,10*4);
            for(i=0; i<60000; i++);
            IDMA1__enMemFill((uint32_t)filler,(uint32_t)u32Test2,100*4);
         }
        else
        {
            u32Test[i+1]=u32Test[i]+i*23;
            i++;
        }

    }
}

