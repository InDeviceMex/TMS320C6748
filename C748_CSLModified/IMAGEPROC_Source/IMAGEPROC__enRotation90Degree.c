/*
 * IMAGEPROC__enRotation90Degree.c
 *
 *  Created on: 04/09/2019
 *      Author: Lalo
 */


#include <ImageProcessing.h>
/*

#define OPT (4)
IMAGPROC_nStatus IMAGEPROC__enRotation90Degree(LCDC_TFT_TypeDef *psLayerSource,LCDC_TFT_TypeDef *psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{
    int32_t width=0,height=0,heightSource=0,heightDest=0;

    uint32_t layerAddressDest;
    uint32_t layerAddressSource;

    uint32_t dimX0=dim.X[0];
    uint32_t dimX1=dim.X[1];
    uint32_t dimY0=dim.Y[0];
    uint32_t dimY1=dim.Y[1];

    uint32_t layerSourceWidthTotal=layerSource->layerWidthTotal;
    uint32_t layerSourceWidthTotal2=layerSource->layerWidthTotal<<1;
    uint32_t layerSourceHeightTotal=layerSource->layerHeightTotal;
    uint32_t layerDestWidthTotal2=layerDest->layerWidthTotal<<1;
    uint32_t layerDestWidthTotal=layerDest->layerWidthTotal;
    uint32_t layerDestHeightTotal=layerDest->layerHeightTotal;

    uint32_t dimWidth=dim.width;
    uint32_t dimHeight=dim.height;
    if(layerSource->variableType != layerDest->variableType )
            return 0;


    if(dimX0>layerSourceWidthTotal)
        return 0;
    if(dimX1>layerDestWidthTotal)
        return 0;
    if(dimY0>layerSourceHeightTotal)
        return 0;
    if(dimY1>layerDestHeightTotal)
        return 0;

    if((dimWidth+ dimX0)>layerSourceWidthTotal)
        dimWidth= layerSourceWidthTotal- dimX0;
    if((dimHeight+ dimY0)>layerSourceHeightTotal)
        dimHeight= layerSourceHeightTotal- dimY0;

    if((dimHeight+ dimX1)>layerDestWidthTotal)
        dimHeight= layerDestWidthTotal- dimX1;
    if((dimWidth+ dimY1)>layerDestHeightTotal)
        dimWidth= layerDestHeightTotal- dimY1;

    if(layerSource->variableType == VARIABLETYPE_UCHAR)
    {
        for(height=0; height<dimHeight;height++ )
        {
            for(width=0;width<dimWidth;width++)
            {
                PIXc(layerDest,dimX1+height,dimY1+width) = PIXc(layerSource,dimX0+width,dimY0+height);
            }
        }
    }
    else
    {
        heightSource=(dimY0)*layerSourceWidthTotal+dimX0;
        heightDest=(dimY1)*layerDestWidthTotal+dimX1;
        layerAddressSource=layerSource->layerDataAddress+(heightSource<<1);
        for(height=0; height<dimHeight;height++ )
        {
            layerAddressDest=layerDest->layerDataAddress+(heightDest<<1);
            for(width=0;width<dimWidth;width++)
            {

               *((uint16_t*)layerAddressDest)=*((uint16_t*)layerAddressSource+width);
                layerAddressDest+=layerDestWidthTotal2;

            }
            layerAddressSource+=layerSourceWidthTotal2;
            heightDest++;
        }
    }
    return 1;


}
*/
