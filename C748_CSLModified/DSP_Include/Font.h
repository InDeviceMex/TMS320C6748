/*
 * fuentes.h
 *
 *  Created on: 11/03/2016
 *      Author: Lalo
 */

#ifndef FONT_H_
#define FONT_H_


#include "stdint.h"

typedef struct
{
  const uint16_t *ascii;
  uint32_t width;
  uint32_t height;
  uint32_t bits;
  int8_t   cor;

} FONT_TypeDef;

typedef struct
{
  unsigned char *string;
  FONT_TypeDef *font;
  uint16_t posX;
  uint16_t posY;
  uint16_t colorFG;
  uint16_t colorBG;
} STRING_TypeDef;


extern const uint16_t FONT_u16_16x24[];
extern const uint16_t FONT_u16_8x16[];
extern const uint16_t FONT_u16_8x16_MS_Gothic[];
extern const uint16_t FONT_u16_8x16_System[];
extern const uint16_t FONT_u16_12x12 [];
extern const uint16_t FONT_u16_8x12 [];
extern const uint16_t FONT_u16_11x16[] ;
extern const uint16_t FONT_u16_8x8 [] ;
extern const uint16_t FONT_u16_6x8[] ;
extern const uint16_t FONT_u16_5x7[];

extern FONT_TypeDef FONT_s16x24;
extern FONT_TypeDef FONT_s11x16;
extern FONT_TypeDef FONT_s8x16;
extern FONT_TypeDef FONT_s8x16_MS_Gothic;
extern FONT_TypeDef FONT_s8x16_System;
extern FONT_TypeDef FONT_s12x12;
extern FONT_TypeDef FONT_s8x12 ;
extern FONT_TypeDef FONT_s8x8;
extern FONT_TypeDef FONT_s6x8;
extern FONT_TypeDef FONT_s5x7;


typedef enum
{
	FONT_enSize_16x24	=0,
	FONT_enSize_11x16	=1,
	FONT_enSize_8x16	=2,
	FONT_enSize_12x12	=3,
	FONT_enSize_8x12	=4,
	FONT_enSize_8x8	=5,
	FONT_enSize_6x8	=6,
	FONT_enSize_5x7	=7,
	FONT_enSize_8x16_MS_Gothic	=8,
	FONT_enSize_8x16_System	=9,

}FONT_nSize;


#endif /* FONT_H_ */
