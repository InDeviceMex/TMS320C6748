/*
 * ImageProcessing.h
 *
 *  Created on: 08/08/2019
 *      Author: Lalo
 */

#ifndef APP_INCLUDE_IMAGEPROCESSING_H_
#define APP_INCLUDE_IMAGEPROCESSING_H_


#include "core.h"
#include "cache.h"
#include <LCDC.h>
#define PI (3.14159265358979323846)

typedef enum
{
    IMAGPROC_enOK = 0,
    IMAGPROC_enERROR = 1,
}IMAGPROC_nStatus;


IMAGPROC_nStatus IMAGEPROC__enGet16bRGBScaleHSI(LCDC_TFT_TypeDef *restrict psLayerSource,LCDC_TFT_TypeDef *restrict psLayerDest,LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__enGetHSI16bRGBScale(LCDC_TFT_TypeDef *restrict psLayerSource,LCDC_TFT_TypeDef *restrict psLayerDest,LCDC_DIMENSIONS_TypeDef sDim);

IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_16bGrayScale(LCDC_TFT_TypeDef *layerSource, LCDC_TFT_TypeDef *layerDest,LCDC_DIMENSIONS_TypeDef dim);
IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_16bGrayScaleRed(LCDC_TFT_TypeDef * psLayerSource, LCDC_TFT_TypeDef * psLayerDest,LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_16bGrayScaleGreen(LCDC_TFT_TypeDef * psLayerSource, LCDC_TFT_TypeDef * psLayerDest,LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_16bGrayScaleBlue(LCDC_TFT_TypeDef * psLayerSource, LCDC_TFT_TypeDef * psLayerDest,LCDC_DIMENSIONS_TypeDef sDim);

IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bGrayScale(LCDC_TFT_TypeDef * psLayerSource, LCDC_TFT_TypeDef * psLayerDest,LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en8bGrayScale_16bGrayScale(LCDC_TFT_TypeDef *psLayerSource, LCDC_TFT_TypeDef *psLayerDest,LCDC_DIMENSIONS_TypeDef sDim);


IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bRGBPartialScale(LCDC_TFT_TypeDef *psLayerSource, LCDC_TFT_TypeDef*psLayerDestRed, LCDC_TFT_TypeDef * psLayerDestGreen,LCDC_TFT_TypeDef *psLayerDestBlue,LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bRGBScale(LCDC_TFT_TypeDef *psLayerSource, LCDC_TFT_TypeDef*psLayerDestRed, LCDC_TFT_TypeDef * psLayerDestGreen,LCDC_TFT_TypeDef *psLayerDestBlue,LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bRedScale(LCDC_TFT_TypeDef *psLayerSource, LCDC_TFT_TypeDef*psLayerDestRed,LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bRedPartialScale(LCDC_TFT_TypeDef *psLayerSource, LCDC_TFT_TypeDef*psLayerDestRed,LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bGreenScale(LCDC_TFT_TypeDef *psLayerSource, LCDC_TFT_TypeDef*psLayerDestGreen,LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bGreenPartialScale(LCDC_TFT_TypeDef *psLayerSource, LCDC_TFT_TypeDef*psLayerDestGreen,LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bBlueScale(LCDC_TFT_TypeDef *psLayerSource, LCDC_TFT_TypeDef*psLayerDestBlue,LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bBluePartialScale(LCDC_TFT_TypeDef *psLayerSource, LCDC_TFT_TypeDef*psLayerDestRed,LCDC_DIMENSIONS_TypeDef sDim);

IMAGPROC_nStatus IMAGEPROC__en8bRGBPartialScale_16bRGBScale(LCDC_TFT_TypeDef*psLayerSourceRed, LCDC_TFT_TypeDef *psLayerSourceGreen,LCDC_TFT_TypeDef *psLayerSourceBlue,LCDC_TFT_TypeDef *psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en8bRGBScale_16bRGBScale(LCDC_TFT_TypeDef*psLayerSourceRed, LCDC_TFT_TypeDef *psLayerSourceGreen,LCDC_TFT_TypeDef *psLayerSourceBlue,LCDC_TFT_TypeDef *psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en8bRedPartialScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceRed, LCDC_TFT_TypeDef *restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en8bRedScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceRed, LCDC_TFT_TypeDef *restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en8bGreenPartialScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceGreen, LCDC_TFT_TypeDef *restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en8bGreenScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceGreen, LCDC_TFT_TypeDef *restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en8bBluePartialScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceBlue, LCDC_TFT_TypeDef *restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en8bBlueScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceBlue, LCDC_TFT_TypeDef *restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);

IMAGPROC_nStatus IMAGEPROC__en16bSubtraction(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en16bSubtractionABS(LCDC_TFT_TypeDef* psLayerSource1,LCDC_TFT_TypeDef* psLayerSource2, LCDC_TFT_TypeDef* psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en8bSubtraction(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en8bSubtractionABS(LCDC_TFT_TypeDef* psLayerSource1,LCDC_TFT_TypeDef* psLayerSource2, LCDC_TFT_TypeDef* psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);

IMAGPROC_nStatus IMAGEPROC__en16bAddMean(LCDC_TFT_TypeDef* psLayerSource1,LCDC_TFT_TypeDef* psLayerSource2, LCDC_TFT_TypeDef* psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en16bAddPartialConstant(LCDC_TFT_TypeDef* psLayerSource, LCDC_TFT_TypeDef* psLayerDest, LCDC_DIMENSIONS_TypeDef sDim,uint8_t u8Red,uint8_t u8Green,uint8_t u8Blue);
IMAGPROC_nStatus IMAGEPROC__en16bAddConstantComplete(LCDC_TFT_TypeDef* restrict psLayerSource, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color);
IMAGPROC_nStatus IMAGEPROC__en16bAddConstant(LCDC_TFT_TypeDef* restrict psLayerSource, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim,uint8_t u8Red,uint8_t u8Green,uint8_t u8Blue);
IMAGPROC_nStatus IMAGEPROC__en16bAdd(LCDC_TFT_TypeDef* psLayerSource1,LCDC_TFT_TypeDef* psLayerSource2, LCDC_TFT_TypeDef* psLayerDest, LCDC_DIMENSIONS_TypeDef sDim);
IMAGPROC_nStatus IMAGEPROC__en16bAddBlend(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, float fBlend);
IMAGPROC_nStatus IMAGEPROC__en16bAddMeanBlend(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, float fBlend);

IMAGPROC_nStatus IMAGEPROC__en8bAddMean(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, uint8_t u8Umbral);
IMAGPROC_nStatus IMAGEPROC__en8bAdd(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, uint8_t u8Umbral);
IMAGPROC_nStatus IMAGEPROC__en8bAddBlend(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, uint8_t u8Umbral, float fBlend);
IMAGPROC_nStatus IMAGEPROC__en8bAddMeanBlend(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, uint8_t u8Umbral, float fBlend);
IMAGPROC_nStatus IMAGEPROC__en8bAddConstant(LCDC_TFT_TypeDef* restrict psLayerSource, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim,uint8_t u8Constant, uint8_t u8Umbral);
IMAGPROC_nStatus IMAGEPROC__en8bAddMeanConstant(LCDC_TFT_TypeDef* restrict psLayerSource, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim,uint8_t u8Constant, uint8_t u8Umbral);

//todo consider HSI subtraction, addition, multiplication and division


IMAGPROC_nStatus IMAGEPROC__en8bUmbral(LCDC_TFT_TypeDef * psLayerSource,LCDC_TFT_TypeDef * psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, uint8_t u8UmbralCenter, uint8_t u8UmbralLength);


#endif /* APP_INCLUDE_IMAGEPROCESSING_H_ */
