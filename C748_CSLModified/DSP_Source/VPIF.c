/*
 * VPIF.c
 *
 *  Created on: 08/08/2019
 *      Author: Lalo
 */

#include "VPIF.h"

void VPIF__vInitReceive(uint32_t u32BufferAddress, uint16_t u16Width)
{
    // disable the channel 0 & 1 and their interrupts.
    VPIF->INTCLR_Bit.FRAME0=1;
    VPIF->INTCLR_Bit.FRAME1=1;

    VPIF->INTEN_Bit.FRAME0=0;
    VPIF->INTEN_Bit.FRAME1=0;

    VPIF->C0CTRL = 0;
    VPIF->C1CTRL = 0;

    // enable the psc and config pinmux for vpif.

    SYSCFG0->PINMUX[14]=0x11111111;//all
    SYSCFG0->PINMUX[15]=0x11111111;//all
    SYSCFG0->PINMUX[16]&=~0xFF;//
    SYSCFG0->PINMUX[16]|=0x11;//

    // config dma request size and emulation control.
    VPIF->REQSIZE = 0x20;//0x20
    VPIF->EMUCTRL = 0x01;

     // config channel 0 & 1 control and capture registers.
    VPIF->C0CTRL=0;
    VPIF->C0CTRL_Bit.DATAWIDTH=0;
    VPIF->C0CTRL_Bit.INTLINE=120;
    VPIF->C0CTRL_Bit.FIELDFRAME=1;
    VPIF->C0CTRL_Bit.INTRPROG=1;
    VPIF->C0CTRL_Bit.INTFRAME=0;
    VPIF->C0CTRL_Bit.CAPMODE=1;

    VPIF->C1CTRL=0;
    VPIF->C1CTRL_Bit.INTRPROG=1;
    VPIF->C1CTRL_Bit.INTFRAME=0;
    VPIF->C1CTRL_Bit.CAPMODE=1;

     // config the data address registers (progressive).
    VPIF_CH0->TLUMA=u32BufferAddress;
    VPIF_CH0->IMGOFFSET=u16Width*2;

    VPIF->C0CTRL_Bit.CHANEN=1;
    VPIF->C1CTRL_Bit.CHANEN=1;
}

