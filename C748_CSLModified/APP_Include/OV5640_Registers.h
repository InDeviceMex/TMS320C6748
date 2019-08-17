/*
 * OV5640_Registers.h
 *
 *  Created on: 06/08/2019
 *      Author: Lalo
 */

#ifndef APP_INCLUDE_OV5640_REGISTERS_H_
#define APP_INCLUDE_OV5640_REGISTERS_H_


#include <stdint.h>

extern const uint8_t OV5640_u8ValueEXPOSURE[7][6];
extern const uint8_t OV5640_u8ModeLIGHT[5][7];
extern const uint8_t OV5640_u8ValueSATURATION[7][6];
extern const uint8_t OV5640_u8ValueSPECIALEFFECTS[7][3];
extern const uint16_t OV5640_u16RegistersJPEG[][2];
extern const uint16_t OV5640_u16RegistersRGB565[45][2];
extern const uint16_t OV5640_u16RegistersInit[208][2];
extern const uint8_t OV5640_u8ConfigAF[4077];
#endif /* APP_INCLUDE_OV5640_REGISTERS_H_ */
