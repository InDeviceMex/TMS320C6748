#include <types.h>
#include "rk6748.h"
#include "rk6748_emif.h"


// emifa pinmux defines.
#define PINMUX_EMIFA_REG_1      (8)
#define PINMUX_EMIFA_MASK_1     (0xFFFFFFFF)
#define PINMUX_EMIFA_VAL_1      (0x11111111)
#define PINMUX_EMIFA_REG_2      (9)
#define PINMUX_EMIFA_MASK_2     (0xFFFFFFFF)
#define PINMUX_EMIFA_VAL_2      (0x11111111)
#define PINMUX_EMIFA_REG_3      (11)
#define PINMUX_EMIFA_MASK_3     (0xFFFFFFFF)
#define PINMUX_EMIFA_VAL_3      (0x11111111)
#define PINMUX_EMIFA_REG_4      (12)
#define PINMUX_EMIFA_MASK_4     (0xFFFFFFFF)
#define PINMUX_EMIFA_VAL_4      (0x11111111)
#define PINMUX_EMIFA_REG_5      (10)
#define PINMUX_EMIFA_MASK_5     (0xFFFFFF00)
#define PINMUX_EMIFA_VAL_5      (0x11111100)
#define PINMUX_EMIFA_REG_6      (5)
#define PINMUX_EMIFA_MASK_6     (0x0F000000)
#define PINMUX_EMIFA_VAL_6      (0x01000000)
#define PINMUX_EMIFA_REG_7      (7)
#define PINMUX_EMIFA_MASK_7     (0x0FFF0FFF)
#define PINMUX_EMIFA_VAL_7      (0x08110111)



void EMIFA_init(void)
{       
    RK6748_lpscTransition(PSC0, DOMAIN0, LPSC_EMIFA, PSC_ENABLE);
    RK6748_pinmuxConfig(PINMUX_EMIFA_REG_1, PINMUX_EMIFA_MASK_1, PINMUX_EMIFA_VAL_1);
    RK6748_pinmuxConfig(PINMUX_EMIFA_REG_2, PINMUX_EMIFA_MASK_2, PINMUX_EMIFA_VAL_2);
    RK6748_pinmuxConfig(PINMUX_EMIFA_REG_3, PINMUX_EMIFA_MASK_3, PINMUX_EMIFA_VAL_3);
    RK6748_pinmuxConfig(PINMUX_EMIFA_REG_4, PINMUX_EMIFA_MASK_4, PINMUX_EMIFA_VAL_4);
    RK6748_pinmuxConfig(PINMUX_EMIFA_REG_5, PINMUX_EMIFA_MASK_5, PINMUX_EMIFA_VAL_5);
    RK6748_pinmuxConfig(PINMUX_EMIFA_REG_6, PINMUX_EMIFA_MASK_6, PINMUX_EMIFA_VAL_6);
    RK6748_pinmuxConfig(PINMUX_EMIFA_REG_7, PINMUX_EMIFA_MASK_7, PINMUX_EMIFA_VAL_7);
    // config for 16-bit data bus.
    CLRBIT(EMIFA->CE2CFG,ASIZE_MASK);
    SETBIT(EMIFA->CE2CFG, ASIZE);
    CLRBIT(EMIFA->CE3CFG,ASIZE_MASK);
    SETBIT(EMIFA->CE3CFG, ASIZE);
	CLRBIT(EMIFA->CE4CFG,ASIZE_MASK);
    SETBIT(EMIFA->CE4CFG, ASIZE);

    setReg(EMIFA->CE2CFG,TA_MASK,3,TA_OFFSET);
    setReg(EMIFA->CE2CFG,R_HOLD_MASK,3,R_HOLD_OFFSET);
    setReg(EMIFA->CE2CFG,R_STROBE_MASK,20,R_STROBE_OFFSET);
    setReg(EMIFA->CE2CFG,R_SETUP_MASK,1,R_SETUP_OFFSET);
    setReg(EMIFA->CE2CFG,W_HOLD_MASK,1,W_HOLD_OFFSET);
    setReg(EMIFA->CE2CFG,W_STROBE_MASK,6,W_STROBE_OFFSET);
    setReg(EMIFA->CE2CFG,W_SETUP_MASK,2,W_SETUP_OFFSET);
    setReg(EMIFA->CE2CFG,EW_MASK,0,EW_OFFSET);
    setReg(EMIFA->CE2CFG,SS_MASK,0,SS_OFFSET);

	setReg(EMIFA->CE3CFG,TA_MASK,3,TA_OFFSET);
    setReg(EMIFA->CE3CFG,R_HOLD_MASK,3,R_HOLD_OFFSET);
    setReg(EMIFA->CE3CFG,R_STROBE_MASK,20,R_STROBE_OFFSET);
    setReg(EMIFA->CE3CFG,R_SETUP_MASK,1,R_SETUP_OFFSET);
    setReg(EMIFA->CE3CFG,W_HOLD_MASK,1,W_HOLD_OFFSET);
    setReg(EMIFA->CE3CFG,W_STROBE_MASK,6,W_STROBE_OFFSET);
    setReg(EMIFA->CE3CFG,W_SETUP_MASK,2,W_SETUP_OFFSET);
    setReg(EMIFA->CE3CFG,EW_MASK,0,EW_OFFSET);
    setReg(EMIFA->CE3CFG,SS_MASK,0,SS_OFFSET);

	//CS4_16C554,??¨¦¨´2?¨¨?¦Ì¨¨¡äy?¨¹?¨²¡ê?¨¬¨¢??PRU¡ã¨¢¨ºy?YD¡ì?¨º
	setReg(EMIFA->CE4CFG,TA_MASK,1,TA_OFFSET);
    setReg(EMIFA->CE4CFG,R_HOLD_MASK,1,R_HOLD_OFFSET);
    setReg(EMIFA->CE4CFG,R_STROBE_MASK,3,R_STROBE_OFFSET);
    setReg(EMIFA->CE4CFG,R_SETUP_MASK,1,R_SETUP_OFFSET);
    setReg(EMIFA->CE4CFG,W_HOLD_MASK,1,W_HOLD_OFFSET);
    setReg(EMIFA->CE4CFG,W_STROBE_MASK,1,W_STROBE_OFFSET);
    setReg(EMIFA->CE4CFG,W_SETUP_MASK,1,W_SETUP_OFFSET);
    setReg(EMIFA->CE4CFG,EW_MASK,0,EW_OFFSET);
    setReg(EMIFA->CE4CFG,SS_MASK,0,SS_OFFSET);

}
//TODO:Read some data form address (in_addrbase+in_addr) to dest_buffer[x:x+in_length])
UINT32 EmifaRead(UINT32 in_addrbase,UINT32 in_addr, UINT16 *dest_buffer, UINT32 in_length)
{
   UINT16 *src;
   UINT32 i;

   src = (UINT16 *)(in_addr+in_addr);
   for (i = 0; i < in_length; i++)
   {
     *dest_buffer++ = *src++;
   }
   
   return (ERR_NO_ERROR);
}

//TODO:Write some data form dest_buffer[x:x+in_length]) to address (in_addrbase+in_addr)
UINT32 EmifaWrite(UINT32 in_addrbase,UINT32 in_addr, UINT16 *src_buffer, UINT32 in_length)
{
   UINT16 *src;
   UINT32 i;

   src = (UINT16 *)(in_addr+in_addrbase);
   
   for (i = 0; i < in_length; i++)
   {
     *src++ = *src_buffer++;
   }
   
   return ERR_NO_ERROR;
}



