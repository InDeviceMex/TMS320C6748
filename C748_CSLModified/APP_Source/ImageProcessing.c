/*
 * ImageProcessing.c
 *
 *  Created on: 09/08/2019
 *      Author: Lalo
 */

#include <ImageProcessing.h>


IMAGPROC_nStatus IMAGEPROC__enGet16bRGBScaleHSI(LCDC_TFT_TypeDef *restrict psLayerSource,LCDC_TFT_TypeDef *restrict psLayerDest,LCDC_DIMENSIONS_TypeDef sDim)
{
    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDest=0;

    register uint32_t u32LayerHueDest;
    register uint32_t u32LayerIntensityDest;
    register uint32_t u32LayerSaturationDest;
    register uint32_t u32LayerAddressSource;

    register int16_t s16Red = 0;
    register int16_t s16Green = 0;
    register int16_t s16Blue = 0;

    register  uint16_t u16Aux = 0;
    register int16_t s16Min = 0;
    register int16_t s16Difference = 0;
    register int32_t s32Sum = 0;

    register float fAuxHue=0;
    register float fAuxHuePartial1=0;
    register float fAuxHuePartial2=0;
    register float fAuxHuePartial3=0;
    register  float fAuxIntensity=0;
    register float fAuxSaturation=0;
    register float fAuxSaturationPartial=0;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDest->variableType != VARIABLETYPE_enFLOAT))
            return IMAGPROC_enERROR;


    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;


    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    u32LayerHueDest=psLayerDest->layerDataHue+(u32HeightDest<<2);
    u32LayerIntensityDest=psLayerDest->layerDataIntensity+(u32HeightDest<<2);
    u32LayerSaturationDest=psLayerDest->layerDataSaturation+(u32HeightDest<<2);
    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);

            s16Red=((u16Aux>>11)&0x1F)<<3;
            s16Green=((u16Aux>>5)&0x3F)<<2;
            s16Blue=((u16Aux)&0x1F)<<3;

            if(s16Red!=s16Blue)
            {
                if(s16Red!=s16Green) // s16Red!=s16Blue  s16Red!= s16Green
                {
                    s32Sum= (s16Red+s16Green);
                    s32Sum+=s16Blue;

                    fAuxIntensity= s32Sum/3.0;

                    s16Min=s16Red;
                    if (s16Green<s16Min)
                        s16Min=s16Green;
                    if (s16Blue<s16Min)
                        s16Min=s16Blue;

                    fAuxSaturationPartial=(float)s16Min;
                    fAuxSaturationPartial/=fAuxIntensity;
                    fAuxSaturation=1.0-fAuxSaturationPartial;

                    s16Difference= s16Red<<1;
                    s16Difference-= s16Blue;
                    s16Difference-= s16Green;
                    s16Difference>>=1;
                    fAuxHuePartial1=(float)s16Difference;

                    s32Sum=s16Red-s16Blue;
                    s32Sum*=s16Green-s16Blue;

                    s16Difference+=s32Sum;

                    fAuxHuePartial2=(float)s32Sum;//(((float)s16Red-(float)s16Blue)*((float)s16Green-(float)s16Blue));

                    s32Sum=s16Red-s16Green;
                    s32Sum*=s32Sum;
                    fAuxHuePartial2+=(float)s32Sum;//(((float)s16Red-(float)s16Green)*((float)s16Red-(float)s16Green));
                    fAuxHuePartial2=sqrtsp_i(fAuxHuePartial2);
                    fAuxHuePartial3=fAuxHuePartial1/fAuxHuePartial2;
                    fAuxHue=acossp_i(fAuxHuePartial3);
                    fAuxHue*=57.295779513;
                    if (s16Blue>s16Green)
                        fAuxHue=360.0-fAuxHue;
                }
                else //s16Red!= s16Blue s16Red==s16Green
                {
                    s32Sum= s16Red<<1;
                    s32Sum+=s16Blue;

                    fAuxIntensity= s32Sum/3.0;

                    s16Min=s16Red;
                    if (s16Blue<s16Min)
                        s16Min=s16Blue;

                    fAuxSaturation=(float)s16Min;
                    fAuxSaturation/=fAuxIntensity;
                    fAuxSaturation=1.0-fAuxSaturation;

                    s16Difference = s16Red- s16Blue;
                    s16Difference>>=1;
                    fAuxHuePartial1=(float)s16Difference;

                    s16Difference= s16Red-s16Blue;
                    s16Difference*=s16Difference;

                    fAuxHuePartial2=(float)s16Difference;
                    fAuxHuePartial2=sqrtsp_i(fAuxHuePartial2);
                    fAuxHuePartial3=fAuxHuePartial1/fAuxHuePartial2;
                    fAuxHue=acossp_i(fAuxHuePartial3);
                    fAuxHue*=57.295779513;
                    if (s16Blue>s16Red)
                        fAuxHue=360.0-fAuxHue;
                }
            }
            else if(s16Red!=s16Green) //s16Red==s16Blue s16Red!= s16Green
            {
                s32Sum=s16Red<<1;
                s32Sum+=s16Green;

                fAuxIntensity= s32Sum/3.0;

                s16Min=s16Red;
                if (s16Green<s16Min)
                    s16Min=s16Green;

                fAuxSaturation=(float)s16Min;
                fAuxSaturation/=fAuxIntensity;
                fAuxSaturation=1.0-fAuxSaturation;



                s16Difference = s16Red- s16Green;
                s16Difference>>=1;
                fAuxHuePartial1=(float)s16Difference;


                s32Sum=s16Red-s16Green;
                s16Difference=s32Sum-1;
                s16Difference*=s32Sum;

                fAuxHuePartial2=(float)s16Difference;
                fAuxHuePartial2=sqrtsp_i(fAuxHuePartial2);
                fAuxHuePartial3=fAuxHuePartial1/fAuxHuePartial2;
                fAuxHue=acossp_i(fAuxHuePartial3);
                fAuxHue*=57.295779513;
                fAuxHue/=PI;
                if (s16Red>s16Green)
                    fAuxHue=360.0-fAuxHue;

            }
            else //s16Red== s16Green == s16Blue
            {
                fAuxSaturation=0.0;
                fAuxHue=0.0;
            }


            *((float*)u32LayerHueDest+u16Width)=fAuxHue;
            *((float*)u32LayerIntensityDest+u16Width)=fAuxIntensity;
            *((float*)u32LayerSaturationDest+u16Width)=fAuxSaturation;
        }
        u32LayerHueDest+=u32LayerDestWidthTotal<<2;
        u32LayerIntensityDest+=u32LayerDestWidthTotal<<2;
        u32LayerSaturationDest+=u32LayerDestWidthTotal<<2;
        //u32LayerAddressDest+=u32LayerDestWidthTotal;
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
    }
    return IMAGPROC_enOK;

}


IMAGPROC_nStatus IMAGEPROC__enGetHSI16bRGBScale(LCDC_TFT_TypeDef *restrict psLayerSource,LCDC_TFT_TypeDef *restrict psLayerDest,LCDC_DIMENSIONS_TypeDef sDim)
{
    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDest=0;

    register uint32_t u32LayerHueSource;
    register uint32_t u32LayerIntensitySource;
    register uint32_t u32LayerSaturationSource;
    register uint32_t u32LayerAddressDest;

    register uint16_t u16Red = 0;
    register uint16_t u16Green = 0;
    register uint16_t u16Blue = 0;

    register uint16_t u16Aux=0;
    register float fAuxHue=0;
    register float fAuxHueRad=0;
    register float fAuxHue60=(60*PI)/180;
    register float fAuxIntensity=0;
    register float fAuxSaturation=0;

    register float fRed = 0;
    register float fGreen = 0;
    register float fBlue = 0;

    register uint16_t u16dimX0=sDim.X[0];
    register uint16_t u16dimX1=sDim.X[1];
    register uint16_t u16dimY0=sDim.Y[0];
    register uint16_t u16dimY1=sDim.Y[1];

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;
    register  uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    if((psLayerSource->variableType != VARIABLETYPE_enFLOAT) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;


    if(u16dimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16dimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;
    if(u16dimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16dimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16dimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16dimX0;
    if((u16DimHeight+ u16dimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16dimY0;

    if((u16DimWidth+ u16dimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16dimX1;
    if((u16DimHeight+ u16dimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16dimY1;



    u32HeightSource=(u16dimY0)*u32LayerSourceWidthTotal+u16dimX0;
    u32HeightDest=(u16dimY1)*u32LayerDestWidthTotal+u16dimX1;

    u32LayerHueSource=psLayerSource->layerDataHue+(u32HeightSource<<2);
    u32LayerIntensitySource=psLayerSource->layerDataIntensity+(u32HeightSource<<2);
    u32LayerSaturationSource=psLayerSource->layerDataSaturation+(u32HeightSource<<2);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {
            fAuxHue=*((float*)u32LayerHueSource+u16Width);
            fAuxIntensity=*((float*)u32LayerIntensitySource+u16Width);
            fAuxSaturation=*((float*)u32LayerSaturationSource+u16Width);

            if(fAuxIntensity==0)
            {
                u16Red= 0;
                u16Green= 0;
                u16Blue= 0;
            }
            else if (fAuxSaturation==0)
            {
                u16Aux=(uint16_t)fAuxIntensity;

                u16Red= (u16Aux<<8)&0xF800;
                u16Green= (u16Aux<<3)&0x07E0;
                u16Blue= (u16Aux>>3)&0x1F;

            }
            else
            {

                if(fAuxHue<0.0)
                    fAuxHue+=360.0;

                if(fAuxHue<=120.0 )
                {
                    fAuxHueRad=fAuxHue*0.0174532925f;
                    fRed=fAuxSaturation*(float)cossp_i(fAuxHueRad);
                    fRed/=(float)cossp_i(fAuxHue60-fAuxHueRad);
                    fRed+=1.0;
                    fRed/=3.0;

                    fBlue=1.0-fAuxSaturation;
                    fBlue/=3.0;

                    fGreen=1.0-(fRed+fBlue);

                }

                else if(fAuxHue<=240.0 )
                {
                    fAuxHue-=120.0;
                    fAuxHueRad=fAuxHue*0.0174532925f;

                    fGreen=fAuxSaturation*(float)cossp_i(fAuxHueRad);
                    fGreen/=(float)cossp_i(fAuxHue60-fAuxHueRad);
                    fGreen+=1.0;
                    fGreen/=3.0;

                    fRed=1.0-fAuxSaturation;
                    fRed/=3.0;

                    fBlue=1.0-(fRed+fGreen);

                }
                else
                {
                    fAuxHue-=240.0;
                    fAuxHueRad=fAuxHue*0.0174532925f;

                    fBlue=fAuxSaturation*(float)cossp_i(fAuxHueRad);
                    fBlue/=(float)cossp_i(fAuxHue60-fAuxHueRad);
                    fBlue+=1.0;
                    fBlue/=3.0;

                    fGreen=1.0-fAuxSaturation;
                    fGreen/=3.0;

                    fRed=1.0-(fBlue+fGreen);
                }



                fRed*=(fAuxIntensity*3.0);
                u16Red= (uint16_t)fRed;
                if(u16Red>0xFF)
                    u16Red=0xFF;
                u16Red<<=8;
                u16Red&=0xF800;


                fGreen*=(fAuxIntensity*3.0);
                u16Green= (uint16_t)fGreen;
                if(u16Green>0xFF)
                    u16Green=0xFF;
                u16Green<<=3;
                u16Green&=0x07E0;


                fBlue*=(fAuxIntensity*3.0);
                u16Blue= (uint16_t)fBlue;
                if(u16Blue>0xFF)
                    u16Blue=0xFF;
                u16Blue>>=3;
                u16Blue&=0x001F;
            }


            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Red|u16Green|u16Blue;
        }
        u32LayerHueSource+=u32LayerSourceWidthTotal<<2;
        u32LayerIntensitySource+=u32LayerSourceWidthTotal<<2;
        u32LayerSaturationSource+=u32LayerSourceWidthTotal<<2;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }
    return IMAGPROC_enOK;

}


IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_16bGrayScale(LCDC_TFT_TypeDef* restrict psLayerSource, LCDC_TFT_TypeDef* restrict psLayerDest,LCDC_DIMENSIONS_TypeDef sDim)
{
    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDest=0;

    register uint32_t u32LayerAddressSource=0;
    register uint32_t u32LayerAddressDest=0;

    register uint8_t u8Red = 0;
    register uint8_t u8Green = 0;
    register uint8_t u8Blue = 0;
    register uint8_t u8Add=0;


    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    register uint16_t u16Aux=0;

    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;


    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;


    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);
    #pragma UNROLL(4)
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {

       #pragma UNROLL(8)
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);

            u8Red= (u16Aux>>11)&0x1F;
            u8Red<<=1;
            u8Green= (u16Aux>>5)&0x3F;
            u8Blue=(u16Aux&0x1F)<<1;

            u8Add= (u8Red+u8Green);
            u8Add+=u8Blue;
            u8Add/=3;

            u16Aux=(u8Add<<10)&0xF800;
            u16Aux|=(u8Add<<5)&0x07E0;
            u16Aux|=(u8Add>>1)&0x1F;

            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Aux;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);
    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_16bGrayScaleRed(LCDC_TFT_TypeDef * restrict psLayerSource, LCDC_TFT_TypeDef * restrict psLayerDest,LCDC_DIMENSIONS_TypeDef sDim)
{
    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDest=0;
    register uint16_t u16Aux=0;
    register uint16_t u16Red=0;
    register uint32_t u32LayerAddressSource;
    register uint32_t u32LayerAddressDest;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register  uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;


    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);
            u16Aux&=0xF800;
            u16Red=u16Aux;
            u16Red|=(u16Aux>>11);
            u16Red|=(u16Aux>>5);
            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Red;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }
    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);
    return IMAGPROC_enOK;
}

IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_16bGrayScaleGreen(LCDC_TFT_TypeDef * restrict psLayerSource, LCDC_TFT_TypeDef * restrict psLayerDest,LCDC_DIMENSIONS_TypeDef sDim)
{
    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDest=0;
    register uint16_t u16Aux=0;
    register  uint16_t u16Green=0;
    register uint32_t u32LayerAddressSource;
    register uint32_t u32LayerAddressDest;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;
    register  uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;


    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);
            u16Aux&=0x07E0;
            u16Green=u16Aux;
            u16Green|=(u16Aux>>6);
            u16Green|=(u16Aux<<5)&0xF800;
            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Green;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }
    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);
    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_16bGrayScaleBlue(LCDC_TFT_TypeDef * restrict psLayerSource, LCDC_TFT_TypeDef * restrict psLayerDest,LCDC_DIMENSIONS_TypeDef sDim)
{
    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDest=0;
    register  uint16_t u16Aux=0;
    register  uint16_t u16Blue=0;
    register uint32_t u32LayerAddressSource;
    register uint32_t u32LayerAddressDest;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register  uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;


    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);
            u16Aux&=0x001F;
            u16Blue=u16Aux;
            u16Blue|=(u16Aux<<6);
            u16Blue|=(u16Aux<<11);
            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Blue;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }
    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);
    return IMAGPROC_enOK;
}



IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bGrayScale(LCDC_TFT_TypeDef *restrict psLayerSource, LCDC_TFT_TypeDef *restrict psLayerDest,LCDC_DIMENSIONS_TypeDef sDim)
{
    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDest=0;

    register uint32_t u32LayerAddressSource;
    register uint32_t psLayerAddressDest;
    register uint8_t u8Red = 0;
    register uint8_t u8Green = 0;
    register uint8_t u8Blue = 0;
    register uint8_t u8Add=0;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t psLayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register  uint32_t psLayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t psLayerSourceHeightTotal=psLayerSource->layerHeightTotal;
    register uint32_t psLayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    register uint16_t u16Aux=0;

    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDest->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>psLayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>psLayerDestWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimY0>psLayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>psLayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>psLayerSourceWidthTotal)
        u16DimWidth= psLayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>psLayerSourceHeightTotal)
        u16DimHeight= psLayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>psLayerDestWidthTotal)
        u16DimWidth= psLayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>psLayerDestHeightTotal)
        u16DimHeight= psLayerDestHeightTotal- u16DimY1;


    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);

    u32HeightSource=(u16DimY0)*psLayerSourceWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*psLayerDestWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    psLayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest);
    #pragma UNROLL(4)
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        #pragma UNROLL(8)
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);
            u8Red=(uint8_t)((uint16_t)(u16Aux&0xF800)>>10)&0x3F;
            u8Green=(uint8_t)((uint16_t)(u16Aux&0x07E0)>>5)&0x3F;
            u8Blue=(uint8_t)((uint16_t)u16Aux<<1)&0x3F;


            u8Add= (u8Red+u8Green);
            u8Add+=u8Blue;
            u8Add/=3;
            u8Add<<=2;
            *((uint8_t*)psLayerAddressDest+u16Width)= u8Add;
        }
        u32LayerAddressSource+=psLayerSourceWidthTotal<<1;
        psLayerAddressDest+=psLayerDestWidthTotal;
    }
    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal);
    return IMAGPROC_enOK;

}


IMAGPROC_nStatus IMAGEPROC__en8bGrayScale_16bGrayScale(LCDC_TFT_TypeDef *restrict psLayerSource, LCDC_TFT_TypeDef *restrict psLayerDest,LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDest=0;

    register uint32_t u32LayerAddressSource;
    register  uint32_t u32LayerAddressDest;

    register  uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    register uint16_t u16All=0;
    register uint8_t  u8Aux=0;
    if((psLayerSource->variableType != VARIABLETYPE_enUCHAR) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal);
    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);
    #pragma UNROLL(4)
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        #pragma UNROLL(8)
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {
            u8Aux=*((uint8_t*)u32LayerAddressSource+u16Width);
            u16All =((uint16_t)u8Aux<<8)&0xF800;
            u16All|=((uint16_t)u8Aux<<3)&0x07E0;
            u16All|=((uint16_t)u8Aux>>3)&0x001F;
            *((uint16_t*)u32LayerAddressDest+u16Width)= u16All;

        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }
    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);
    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en8bRGBPartialScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceRed, LCDC_TFT_TypeDef *restrict psLayerSourceGreen,LCDC_TFT_TypeDef *restrict psLayerSourceBlue,LCDC_TFT_TypeDef *psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightDest=0,u32HeightSourceRed=0,u32HeightSourceGreen=0,u32HeightSourceBlue=0;

    register uint32_t u32LayerAddressSourceRed;
    register uint32_t u32LayerAddressSourceGreen;
    register uint32_t u32LayerAddressSourceBlue;
    register uint32_t u32LayerAddressDest;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimX3=sDim.X[3];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];
    register  uint16_t u16DimY3=sDim.Y[3];

    register uint32_t u32LayerSourceRedWidthTotal=psLayerSourceRed->layerWidthTotal;
    register uint32_t u32LayerSourceGreenWidthTotal=psLayerSourceGreen->layerWidthTotal;
    register uint32_t u32LayerSourceBlueWidthTotal=psLayerSourceBlue->layerWidthTotal;
    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerSourceRedHeightTotal=psLayerSourceRed->layerHeightTotal;
    register uint32_t u32LayerSourceGreenHeightTotal=psLayerSourceGreen->layerHeightTotal;
    register uint32_t u32LayerSourceBlueHeightTotal=psLayerSourceBlue->layerHeightTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint16_t u16Result=0;
    register uint8_t u8Red = 0;
    register uint8_t u8Green = 0;
    register uint8_t u8Blue = 0;

    if((psLayerDest->variableType != VARIABLETYPE_enUSHORT) || (psLayerSourceRed->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerSourceGreen->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerSourceBlue->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;

    if(u16DimX3>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceRedWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerSourceBlueWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSourceGreenWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY3>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY0>u32LayerSourceRedHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSourceGreenHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerSourceBlueHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX3)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX3;
    if((u16DimHeight+ u16DimY3)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY3;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceRedWidthTotal)
        u16DimWidth= u32LayerSourceRedWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceRedHeightTotal)
        u16DimHeight= u32LayerSourceRedHeightTotal- u16DimY0;


    if((u16DimWidth+ u16DimX1)>u32LayerSourceGreenWidthTotal)
        u16DimWidth= u32LayerSourceGreenWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSourceGreenHeightTotal)
        u16DimHeight= u32LayerSourceGreenHeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerSourceBlueWidthTotal)
        u16DimWidth= u32LayerSourceBlueWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerSourceBlueHeightTotal)
        u16DimHeight= u32LayerSourceBlueHeightTotal- u16DimY2;



    Cache__vInvL2 (psLayerSourceRed->layerDataAddress, psLayerSourceRed->layerWidthTotal*psLayerSourceRed->layerHeightTotal);
    Cache__vInvL2 (psLayerSourceGreen->layerDataAddress, psLayerSourceGreen->layerWidthTotal*psLayerSourceGreen->layerHeightTotal);
    Cache__vInvL2 (psLayerSourceBlue->layerDataAddress, psLayerSourceBlue->layerWidthTotal*psLayerSourceBlue->layerHeightTotal);

    u32HeightSourceRed=(u16DimY0)*u32LayerSourceRedWidthTotal+u16DimX0;
    u32HeightSourceGreen=(u16DimY1)*u32LayerSourceGreenWidthTotal+u16DimX1;
    u32HeightSourceBlue=(u16DimY2)*u32LayerSourceBlueWidthTotal+u16DimX2;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX3;

    u32LayerAddressSourceRed=psLayerSourceRed->layerDataAddress+(u32HeightSourceRed);
    u32LayerAddressSourceGreen=psLayerSourceGreen->layerDataAddress+(u32HeightSourceGreen);
    u32LayerAddressSourceBlue=psLayerSourceBlue->layerDataAddress+(u32HeightSourceBlue);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u8Red=*((uint8_t*)u32LayerAddressSourceRed+u16Width);
            u8Green=*((uint8_t*)u32LayerAddressSourceGreen+u16Width);
            u8Blue=*((uint8_t*)u32LayerAddressSourceBlue+u16Width);

            u16Result =((uint16_t)u8Red<<11)&0xF800;
            u16Result|=((uint16_t)u8Green<<5)&0x07E0;
            u16Result|=((uint16_t)u8Blue)&0x001F;
             *((uint16_t*)u32LayerAddressDest+u16Width)= u16Result;
        }
        u32LayerAddressSourceRed+=u32LayerSourceRedWidthTotal;
        u32LayerAddressSourceGreen+=u32LayerSourceGreenWidthTotal;
        u32LayerAddressSourceBlue+=u32LayerSourceBlueWidthTotal;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }
    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);
    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en8bRGBScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceRed, LCDC_TFT_TypeDef *restrict psLayerSourceGreen,LCDC_TFT_TypeDef *restrict psLayerSourceBlue,LCDC_TFT_TypeDef *psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightDest=0,u32HeightSourceRed=0,u32HeightSourceGreen=0,u32HeightSourceBlue=0;

    register uint32_t u32LayerAddressSourceRed;
    register uint32_t u32LayerAddressSourceGreen;
    register uint32_t u32LayerAddressSourceBlue;
    register uint32_t u32LayerAddressDest;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimX3=sDim.X[3];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];
    register uint16_t u16DimY3=sDim.Y[3];

    register uint32_t u32LayerSourceRedWidthTotal=psLayerSourceRed->layerWidthTotal;
    register uint32_t u32LayerSourceGreenWidthTotal=psLayerSourceGreen->layerWidthTotal;
    register uint32_t u32LayerSourceBlueWidthTotal=psLayerSourceBlue->layerWidthTotal;
    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerSourceRedHeightTotal=psLayerSourceRed->layerHeightTotal;
    register  uint32_t u32LayerSourceGreenHeightTotal=psLayerSourceGreen->layerHeightTotal;
    register uint32_t u32LayerSourceBlueHeightTotal=psLayerSourceBlue->layerHeightTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint16_t u16Result=0;
    register uint8_t u8Red = 0;
    register uint8_t u8Green = 0;
    register uint8_t u8Blue = 0;

    if((psLayerDest->variableType != VARIABLETYPE_enUSHORT) || (psLayerSourceRed->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerSourceGreen->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerSourceBlue->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;

    if(u16DimX3>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceRedWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerSourceBlueWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSourceGreenWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY3>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY0>u32LayerSourceRedHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSourceGreenHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerSourceBlueHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX3)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX3;
    if((u16DimHeight+ u16DimY3)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY3;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceRedWidthTotal)
        u16DimWidth= u32LayerSourceRedWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceRedHeightTotal)
        u16DimHeight= u32LayerSourceRedHeightTotal- u16DimY0;


    if((u16DimWidth+ u16DimX1)>u32LayerSourceGreenWidthTotal)
        u16DimWidth= u32LayerSourceGreenWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSourceGreenHeightTotal)
        u16DimHeight= u32LayerSourceGreenHeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerSourceBlueWidthTotal)
        u16DimWidth= u32LayerSourceBlueWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerSourceBlueHeightTotal)
        u16DimHeight= u32LayerSourceBlueHeightTotal- u16DimY2;



    Cache__vInvL2 (psLayerSourceRed->layerDataAddress, psLayerSourceRed->layerWidthTotal*psLayerSourceRed->layerHeightTotal);
    Cache__vInvL2 (psLayerSourceGreen->layerDataAddress, psLayerSourceGreen->layerWidthTotal*psLayerSourceGreen->layerHeightTotal);
    Cache__vInvL2 (psLayerSourceBlue->layerDataAddress, psLayerSourceBlue->layerWidthTotal*psLayerSourceBlue->layerHeightTotal);

    u32HeightSourceRed=(u16DimY0)*u32LayerSourceRedWidthTotal+u16DimX0;
    u32HeightSourceGreen=(u16DimY1)*u32LayerSourceGreenWidthTotal+u16DimX1;
    u32HeightSourceBlue=(u16DimY2)*u32LayerSourceBlueWidthTotal+u16DimX2;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX3;

    u32LayerAddressSourceRed=psLayerSourceRed->layerDataAddress+(u32HeightSourceRed);
    u32LayerAddressSourceGreen=psLayerSourceGreen->layerDataAddress+(u32HeightSourceGreen);
    u32LayerAddressSourceBlue=psLayerSourceBlue->layerDataAddress+(u32HeightSourceBlue);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u8Red=*((uint8_t*)u32LayerAddressSourceRed+u16Width);
            u8Green=*((uint8_t*)u32LayerAddressSourceGreen+u16Width);
            u8Blue=*((uint8_t*)u32LayerAddressSourceBlue+u16Width);

            u16Result =((uint16_t)u8Red<<8)&0xF800;
            u16Result|=((uint16_t)u8Green<<3)&0x07E0;
            u16Result|=((uint16_t)u8Blue>>3)&0x001F;
             *((uint16_t*)u32LayerAddressDest+u16Width)= u16Result;
        }
        u32LayerAddressSourceRed+=u32LayerSourceRedWidthTotal;
        u32LayerAddressSourceGreen+=u32LayerSourceGreenWidthTotal;
        u32LayerAddressSourceBlue+=u32LayerSourceBlueWidthTotal;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }
    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);
    return IMAGPROC_enOK;
}



IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bRGBScale(LCDC_TFT_TypeDef *restrict psLayerSource, LCDC_TFT_TypeDef*restrict psLayerDestRed, LCDC_TFT_TypeDef * restrict psLayerDestGreen,LCDC_TFT_TypeDef *restrict psLayerDestBlue,LCDC_DIMENSIONS_TypeDef sDim)
{

    register  uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDestRed=0,u32HeightDestGreen=0,u32HeightDestBlue=0;

    register uint32_t u32LayerAddressDestRed;
    register uint32_t u32LayerAddressDestGreen;
    register uint32_t u32LayerAddressDestBlue;
    register uint32_t u32LayerAddressSource;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimX3=sDim.X[3];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];
    register uint16_t u16DimY3=sDim.Y[3];

    register uint32_t u32LayerDestRedWidthTotal=psLayerDestRed->layerWidthTotal;
    register uint32_t u32LayerDestGreenWidthTotal=psLayerDestGreen->layerWidthTotal;
    register uint32_t u32LayerDestBlueWidthTotal=psLayerDestBlue->layerWidthTotal;
    register uint32_t u32LayerDestRedHeightTotal=psLayerDestRed->layerHeightTotal;
    register uint32_t u32LayerDestGreenHeightTotal=psLayerDestGreen->layerHeightTotal;
    register uint32_t u32LayerDestBlueHeightTotal=psLayerDestBlue->layerHeightTotal;

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint16_t u16Aux=0;
    register uint8_t u8Red = 0;
    register uint8_t u8Green = 0;
    register uint8_t u8Blue = 0;

    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDestRed->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerDestGreen->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerDestBlue->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestRedWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestBlueWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX3>u32LayerDestGreenWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestRedHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestGreenHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY3>u32LayerDestBlueHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestRedWidthTotal)
        u16DimWidth= u32LayerDestRedWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestRedHeightTotal)
        u16DimHeight= u32LayerDestRedHeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestGreenWidthTotal)
        u16DimWidth= u32LayerDestGreenWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestGreenHeightTotal)
        u16DimHeight= u32LayerDestGreenHeightTotal- u16DimY2;


    if((u16DimWidth+ u16DimX3)>u32LayerDestBlueWidthTotal)
        u16DimWidth= u32LayerDestBlueWidthTotal- u16DimX3;
    if((u16DimHeight+ u16DimY3)>u32LayerDestBlueHeightTotal)
        u16DimHeight= u32LayerDestBlueHeightTotal- u16DimY3;

    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDestRed=(u16DimY1)*u32LayerDestRedWidthTotal+u16DimX1;
    u32HeightDestGreen=(u16DimY2)*u32LayerDestGreenWidthTotal+u16DimX2;
    u32HeightDestBlue=(u16DimY3)*u32LayerDestBlueWidthTotal+u16DimX3;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDestRed=psLayerDestRed->layerDataAddress+(u32HeightDestRed);
    u32LayerAddressDestGreen=psLayerDestGreen->layerDataAddress+(u32HeightDestGreen);
    u32LayerAddressDestBlue=psLayerDestBlue->layerDataAddress+(u32HeightDestBlue);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);

            u8Red=(u16Aux&0xF800)>>8;
            u8Green=(u16Aux&0x07E0)>>3;
            u8Blue=(u16Aux&0x001F)<<3;
            *((uint8_t*)u32LayerAddressDestRed+u16Width)= u8Red;
            *((uint8_t*)u32LayerAddressDestGreen+u16Width)= u8Green;
            *((uint8_t*)u32LayerAddressDestBlue+u16Width)= u8Blue;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDestRed+=u32LayerDestRedWidthTotal;
        u32LayerAddressDestGreen+=u32LayerDestGreenWidthTotal;
        u32LayerAddressDestBlue+=u32LayerDestBlueWidthTotal;
    }
    Cache__vWbL2 (psLayerDestRed->layerDataAddress, psLayerDestRed->layerWidthTotal*psLayerDestRed->layerHeightTotal);
    Cache__vWbL2 (psLayerDestGreen->layerDataAddress, psLayerDestGreen->layerWidthTotal*psLayerDestGreen->layerHeightTotal);
    Cache__vWbL2 (psLayerDestBlue->layerDataAddress, psLayerDestBlue->layerWidthTotal*psLayerDestBlue->layerHeightTotal);

    return IMAGPROC_enOK;
}



IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bRGBPartialScale(LCDC_TFT_TypeDef *restrict psLayerSource, LCDC_TFT_TypeDef*restrict psLayerDestRed, LCDC_TFT_TypeDef * restrict psLayerDestGreen,LCDC_TFT_TypeDef *restrict psLayerDestBlue,LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDestRed=0,u32HeightDestGreen=0,u32HeightDestBlue=0;

    register uint32_t u32LayerAddressDestRed;
    register uint32_t u32LayerAddressDestGreen;
    register uint32_t u32LayerAddressDestBlue;
    register uint32_t u32LayerAddressSource;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimX3=sDim.X[3];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];
    register uint16_t u16DimY3=sDim.Y[3];

    register uint32_t u32LayerDestRedWidthTotal=psLayerDestRed->layerWidthTotal;
    register uint32_t u32LayerDestGreenWidthTotal=psLayerDestGreen->layerWidthTotal;
    register uint32_t u32LayerDestBlueWidthTotal=psLayerDestBlue->layerWidthTotal;
    register uint32_t u32LayerDestRedHeightTotal=psLayerDestRed->layerHeightTotal;
    register uint32_t u32LayerDestGreenHeightTotal=psLayerDestGreen->layerHeightTotal;
    register uint32_t u32LayerDestBlueHeightTotal=psLayerDestBlue->layerHeightTotal;

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint16_t u16Aux=0;
    register uint8_t u8Red = 0;
    register uint8_t u8Green = 0;
    register uint8_t u8Blue = 0;

    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDestRed->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerDestGreen->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerDestBlue->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestRedWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestBlueWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX3>u32LayerDestGreenWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestRedHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestGreenHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY3>u32LayerDestBlueHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestRedWidthTotal)
        u16DimWidth= u32LayerDestRedWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestRedHeightTotal)
        u16DimHeight= u32LayerDestRedHeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestGreenWidthTotal)
        u16DimWidth= u32LayerDestGreenWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestGreenHeightTotal)
        u16DimHeight= u32LayerDestGreenHeightTotal- u16DimY2;


    if((u16DimWidth+ u16DimX3)>u32LayerDestBlueWidthTotal)
        u16DimWidth= u32LayerDestBlueWidthTotal- u16DimX3;
    if((u16DimHeight+ u16DimY3)>u32LayerDestBlueHeightTotal)
        u16DimHeight= u32LayerDestBlueHeightTotal- u16DimY3;
    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDestRed=(u16DimY1)*u32LayerDestRedWidthTotal+u16DimX1;
    u32HeightDestGreen=(u16DimY2)*u32LayerDestGreenWidthTotal+u16DimX2;
    u32HeightDestBlue=(u16DimY3)*u32LayerDestBlueWidthTotal+u16DimX3;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDestRed=psLayerDestRed->layerDataAddress+(u32HeightDestRed);
    u32LayerAddressDestGreen=psLayerDestGreen->layerDataAddress+(u32HeightDestGreen);
    u32LayerAddressDestBlue=psLayerDestBlue->layerDataAddress+(u32HeightDestBlue);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);

            u8Red=(u16Aux&0xF800)>>11;
            u8Green=(u16Aux&0x07E0)>>5;
            u8Blue=(u16Aux&0x001F);
            *((uint8_t*)u32LayerAddressDestRed+u16Width)= u8Red;
            *((uint8_t*)u32LayerAddressDestGreen+u16Width)= u8Green;
            *((uint8_t*)u32LayerAddressDestBlue+u16Width)= u8Blue;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDestRed+=u32LayerDestRedWidthTotal;
        u32LayerAddressDestGreen+=u32LayerDestGreenWidthTotal;
        u32LayerAddressDestBlue+=u32LayerDestBlueWidthTotal;
    }
    Cache__vWbL2 (psLayerDestRed->layerDataAddress, psLayerDestRed->layerWidthTotal*psLayerDestRed->layerHeightTotal);
    Cache__vWbL2 (psLayerDestGreen->layerDataAddress, psLayerDestGreen->layerWidthTotal*psLayerDestGreen->layerHeightTotal);
    Cache__vWbL2 (psLayerDestBlue->layerDataAddress, psLayerDestBlue->layerWidthTotal*psLayerDestBlue->layerHeightTotal);

    return IMAGPROC_enOK;
}



IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bRedScale(LCDC_TFT_TypeDef *restrict psLayerSource, LCDC_TFT_TypeDef*restrict psLayerDestRed,LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDestRed=0;

    register uint32_t u32LayerAddressDestRed;
    register uint32_t u32LayerAddressSource;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerDestRedWidthTotal=psLayerDestRed->layerWidthTotal;
    register uint32_t u32LayerDestRedHeightTotal=psLayerDestRed->layerHeightTotal;

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint16_t u16Aux=0;
    register uint8_t u8Red = 0;

    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDestRed->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestRedWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestRedHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestRedWidthTotal)
        u16DimWidth= u32LayerDestRedWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestRedHeightTotal)
        u16DimHeight= u32LayerDestRedHeightTotal- u16DimY1;
    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDestRed=(u16DimY1)*u32LayerDestRedWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDestRed=psLayerDestRed->layerDataAddress+(u32HeightDestRed);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);

            u8Red=(u16Aux&0xF800)>>8;
            *((uint8_t*)u32LayerAddressDestRed+u16Width)= u8Red;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDestRed+=u32LayerDestRedWidthTotal;
    }
    Cache__vWbL2 (psLayerDestRed->layerDataAddress, psLayerDestRed->layerWidthTotal*psLayerDestRed->layerHeightTotal);

    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bRedPartialScale(LCDC_TFT_TypeDef *restrict psLayerSource, LCDC_TFT_TypeDef*restrict psLayerDestRed,LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDestRed=0;

    register uint32_t u32LayerAddressDestRed;
    register uint32_t u32LayerAddressSource;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerDestRedWidthTotal=psLayerDestRed->layerWidthTotal;
    register uint32_t u32LayerDestRedHeightTotal=psLayerDestRed->layerHeightTotal;

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint16_t u16Aux=0;
    register uint8_t u8Red = 0;

    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDestRed->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestRedWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestRedHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestRedWidthTotal)
        u16DimWidth= u32LayerDestRedWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestRedHeightTotal)
        u16DimHeight= u32LayerDestRedHeightTotal- u16DimY1;
    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDestRed=(u16DimY1)*u32LayerDestRedWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDestRed=psLayerDestRed->layerDataAddress+(u32HeightDestRed);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);

            u8Red=(u16Aux&0xF800)>>11;
            *((uint8_t*)u32LayerAddressDestRed+u16Width)= u8Red;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDestRed+=u32LayerDestRedWidthTotal;
    }
    Cache__vWbL2 (psLayerDestRed->layerDataAddress, psLayerDestRed->layerWidthTotal*psLayerDestRed->layerHeightTotal);

    return IMAGPROC_enOK;
}




IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bGreenScale(LCDC_TFT_TypeDef *restrict psLayerSource, LCDC_TFT_TypeDef*restrict psLayerDestGreen,LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDestGreen=0;

    register uint32_t u32LayerAddressDestGreen;
    register uint32_t u32LayerAddressSource;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerDestGreenWidthTotal=psLayerDestGreen->layerWidthTotal;
    register uint32_t u32LayerDestGreenHeightTotal=psLayerDestGreen->layerHeightTotal;

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint16_t u16Aux=0;
    register uint8_t u8Green = 0;

    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDestGreen->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestGreenWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestGreenHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestGreenWidthTotal)
        u16DimWidth= u32LayerDestGreenWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestGreenHeightTotal)
        u16DimHeight= u32LayerDestGreenHeightTotal- u16DimY1;
    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDestGreen=(u16DimY1)*u32LayerDestGreenWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDestGreen=psLayerDestGreen->layerDataAddress+(u32HeightDestGreen);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);

            u8Green=(u16Aux&0x07E0)>>3;
            *((uint8_t*)u32LayerAddressDestGreen+u16Width)= u8Green;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDestGreen+=u32LayerDestGreenWidthTotal;
    }
    Cache__vWbL2 (psLayerDestGreen->layerDataAddress, psLayerDestGreen->layerWidthTotal*psLayerDestGreen->layerHeightTotal);

    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bGreenPartialScale(LCDC_TFT_TypeDef *restrict psLayerSource, LCDC_TFT_TypeDef*restrict psLayerDestGreen,LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDestGreen=0;

    register uint32_t u32LayerAddressDestGreen;
    register uint32_t u32LayerAddressSource;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerDestGreenWidthTotal=psLayerDestGreen->layerWidthTotal;
    register uint32_t u32LayerDestGreenHeightTotal=psLayerDestGreen->layerHeightTotal;

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint16_t u16Aux=0;
    register uint8_t u8Green = 0;

    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDestGreen->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestGreenWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestGreenHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestGreenWidthTotal)
        u16DimWidth= u32LayerDestGreenWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestGreenHeightTotal)
        u16DimHeight= u32LayerDestGreenHeightTotal- u16DimY1;
    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDestGreen=(u16DimY1)*u32LayerDestGreenWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDestGreen=psLayerDestGreen->layerDataAddress+(u32HeightDestGreen);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);

            u8Green=(u16Aux&0x07E0)>>5;
            *((uint8_t*)u32LayerAddressDestGreen+u16Width)= u8Green;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDestGreen+=u32LayerDestGreenWidthTotal;
    }
    Cache__vWbL2 (psLayerDestGreen->layerDataAddress, psLayerDestGreen->layerWidthTotal*psLayerDestGreen->layerHeightTotal);

    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bBlueScale(LCDC_TFT_TypeDef *restrict psLayerSource, LCDC_TFT_TypeDef*restrict psLayerDestBlue,LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDestBlue=0;

    register uint32_t u32LayerAddressDestBlue;
    register uint32_t u32LayerAddressSource;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerDestBlueWidthTotal=psLayerDestBlue->layerWidthTotal;
    register uint32_t u32LayerDestBlueHeightTotal=psLayerDestBlue->layerHeightTotal;

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint16_t u16Aux=0;
    register uint8_t u8Blue = 0;

    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDestBlue->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestBlueWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestBlueHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestBlueWidthTotal)
        u16DimWidth= u32LayerDestBlueWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestBlueHeightTotal)
        u16DimHeight= u32LayerDestBlueHeightTotal- u16DimY1;
    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDestBlue=(u16DimY1)*u32LayerDestBlueWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDestBlue=psLayerDestBlue->layerDataAddress+(u32HeightDestBlue);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);

            u8Blue=(u16Aux&0x001F)<<3;
            *((uint8_t*)u32LayerAddressDestBlue+u16Width)= u8Blue;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDestBlue+=u32LayerDestBlueWidthTotal;
    }
    Cache__vWbL2 (psLayerDestBlue->layerDataAddress, psLayerDestBlue->layerWidthTotal*psLayerDestBlue->layerHeightTotal);

    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en16bRGBScale_8bBluePartialScale(LCDC_TFT_TypeDef *restrict psLayerSource, LCDC_TFT_TypeDef*restrict psLayerDestBlue,LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDestBlue=0;

    register uint32_t u32LayerAddressDestBlue, u32LayerAddressSource;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerDestBlueWidthTotal=psLayerDestBlue->layerWidthTotal;
    register uint32_t u32LayerDestBlueHeightTotal=psLayerDestBlue->layerHeightTotal;

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint16_t u16Aux=0;
    register uint8_t u8Blue = 0;

    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDestBlue->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestBlueWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestBlueHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestBlueWidthTotal)
        u16DimWidth= u32LayerDestBlueWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestBlueHeightTotal)
        u16DimHeight= u32LayerDestBlueHeightTotal- u16DimY1;
    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDestBlue=(u16DimY1)*u32LayerDestBlueWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDestBlue=psLayerDestBlue->layerDataAddress+(u32HeightDestBlue);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Aux=*((uint16_t*)u32LayerAddressSource+u16Width);

            u8Blue=(u16Aux&0x001F);
            *((uint8_t*)u32LayerAddressDestBlue+u16Width)= u8Blue;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDestBlue+=u32LayerDestBlueWidthTotal;
    }
    Cache__vWbL2 (psLayerDestBlue->layerDataAddress, psLayerDestBlue->layerWidthTotal*psLayerDestBlue->layerHeightTotal);

    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en8bRedPartialScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceRed, LCDC_TFT_TypeDef *restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{


    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightDest=0,u32HeightSourceRed=0;

    register uint32_t psLayerAddressDest,psLayerAddressSourceRed;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceRedWidthTotal=psLayerSourceRed->layerWidthTotal;
    register uint32_t u32LayerSourceRedHeightTotal=psLayerSourceRed->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    register uint16_t u16Red = 0;
    if((psLayerSourceRed->variableType != VARIABLETYPE_enUCHAR) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceRedWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceRedHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceRedWidthTotal)
        u16DimWidth= u32LayerSourceRedWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceRedHeightTotal)
        u16DimHeight= u32LayerSourceRedHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSourceRed->layerDataAddress, psLayerSourceRed->layerWidthTotal*psLayerSourceRed->layerHeightTotal);
    u32HeightSourceRed=(u16DimY0)*u32LayerSourceRedWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    psLayerAddressSourceRed=psLayerSourceRed->layerDataAddress+(u32HeightSourceRed);
    psLayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {
            u16Red=*((uint8_t*)psLayerAddressSourceRed+u16Width);
            u16Red<<=11;
            u16Red&=0xF800;
            *((uint16_t*)psLayerAddressDest+u16Width)&=~0xF800;
            *((uint16_t*)psLayerAddressDest+u16Width)|=u16Red;
        }
        psLayerAddressSourceRed+=u32LayerSourceRedWidthTotal;
        psLayerAddressDest+=u32LayerDestWidthTotal<<1;
    }
    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;

}


IMAGPROC_nStatus IMAGEPROC__en8bRedScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceRed, LCDC_TFT_TypeDef *restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{


    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightDest=0,u32HeightSourceRed=0;

    register uint32_t psLayerAddressDest,psLayerAddressSourceRed;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceRedWidthTotal=psLayerSourceRed->layerWidthTotal;
    register uint32_t u32LayerSourceRedHeightTotal=psLayerSourceRed->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    register uint16_t u16Red = 0;
    if((psLayerSourceRed->variableType != VARIABLETYPE_enUCHAR) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceRedWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceRedHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceRedWidthTotal)
        u16DimWidth= u32LayerSourceRedWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceRedHeightTotal)
        u16DimHeight= u32LayerSourceRedHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSourceRed->layerDataAddress, psLayerSourceRed->layerWidthTotal*psLayerSourceRed->layerHeightTotal);
    u32HeightSourceRed=(u16DimY0)*u32LayerSourceRedWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    psLayerAddressSourceRed=psLayerSourceRed->layerDataAddress+(u32HeightSourceRed);
    psLayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {
            u16Red=*((uint8_t*)psLayerAddressSourceRed+u16Width);
            u16Red<<=8;
            u16Red&=0xF800;
            *((uint16_t*)psLayerAddressDest+u16Width)&=~0xF800;
            *((uint16_t*)psLayerAddressDest+u16Width)|=u16Red;
        }
        psLayerAddressSourceRed+=u32LayerSourceRedWidthTotal;
        psLayerAddressDest+=u32LayerDestWidthTotal<<1;
    }
    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;

}


IMAGPROC_nStatus IMAGEPROC__en8bGreenPartialScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceGreen, LCDC_TFT_TypeDef *restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{


    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightDest=0,u32HeightSourceGreen=0;

    register uint32_t psLayerAddressDest,psLayerAddressSourceGreen;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceGreenWidthTotal=psLayerSourceGreen->layerWidthTotal;
    register uint32_t u32LayerSourceGreenHeightTotal=psLayerSourceGreen->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    register uint16_t u16Green = 0;
    if((psLayerSourceGreen->variableType != VARIABLETYPE_enUCHAR) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceGreenWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceGreenHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceGreenWidthTotal)
        u16DimWidth= u32LayerSourceGreenWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceGreenHeightTotal)
        u16DimHeight= u32LayerSourceGreenHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSourceGreen->layerDataAddress, psLayerSourceGreen->layerWidthTotal*psLayerSourceGreen->layerHeightTotal);
    u32HeightSourceGreen=(u16DimY0)*u32LayerSourceGreenWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    psLayerAddressSourceGreen=psLayerSourceGreen->layerDataAddress+(u32HeightSourceGreen);
    psLayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {
            u16Green=*((uint8_t*)psLayerAddressSourceGreen+u16Width);
            u16Green<<=5;
            u16Green&=0x07E0;
            *((uint16_t*)psLayerAddressDest+u16Width)&=~0x07E0;
            *((uint16_t*)psLayerAddressDest+u16Width)|=u16Green;
        }
        psLayerAddressSourceGreen+=u32LayerSourceGreenWidthTotal;
        psLayerAddressDest+=u32LayerDestWidthTotal<<1;
    }
    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;

}


IMAGPROC_nStatus IMAGEPROC__en8bGreenScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceGreen, LCDC_TFT_TypeDef *restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{


    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightDest=0,u32HeightSourceGreen=0;

    register uint32_t psLayerAddressDest,psLayerAddressSourceGreen;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceGreenWidthTotal=psLayerSourceGreen->layerWidthTotal;
    register uint32_t u32LayerSourceGreenHeightTotal=psLayerSourceGreen->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    register uint16_t u16Green = 0;
    if((psLayerSourceGreen->variableType != VARIABLETYPE_enUCHAR) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceGreenWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceGreenHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceGreenWidthTotal)
        u16DimWidth= u32LayerSourceGreenWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceGreenHeightTotal)
        u16DimHeight= u32LayerSourceGreenHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSourceGreen->layerDataAddress, psLayerSourceGreen->layerWidthTotal*psLayerSourceGreen->layerHeightTotal);
    u32HeightSourceGreen=(u16DimY0)*u32LayerSourceGreenWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    psLayerAddressSourceGreen=psLayerSourceGreen->layerDataAddress+(u32HeightSourceGreen);
    psLayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {
            u16Green=*((uint8_t*)psLayerAddressSourceGreen+u16Width);
            u16Green<<=3;
            u16Green&=0x07E0;
            *((uint16_t*)psLayerAddressDest+u16Width)&=~0x07E0;
            *((uint16_t*)psLayerAddressDest+u16Width)|=u16Green;
        }
        psLayerAddressSourceGreen+=u32LayerSourceGreenWidthTotal;
        psLayerAddressDest+=u32LayerDestWidthTotal<<1;
    }
    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;

}

IMAGPROC_nStatus IMAGEPROC__en8bBluePartialScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceBlue, LCDC_TFT_TypeDef *restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{


    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightDest=0,u32HeightSourceBlue=0;

    register uint32_t psLayerAddressDest,psLayerAddressSourceBlue;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceBlueWidthTotal=psLayerSourceBlue->layerWidthTotal;
    register uint32_t u32LayerSourceBlueHeightTotal=psLayerSourceBlue->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    register uint16_t u16Blue = 0;
    if((psLayerSourceBlue->variableType != VARIABLETYPE_enUCHAR) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceBlueWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceBlueHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceBlueWidthTotal)
        u16DimWidth= u32LayerSourceBlueWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceBlueHeightTotal)
        u16DimHeight= u32LayerSourceBlueHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSourceBlue->layerDataAddress, psLayerSourceBlue->layerWidthTotal*psLayerSourceBlue->layerHeightTotal);
    u32HeightSourceBlue=(u16DimY0)*u32LayerSourceBlueWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    psLayerAddressSourceBlue=psLayerSourceBlue->layerDataAddress+(u32HeightSourceBlue);
    psLayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {
            u16Blue=*((uint8_t*)psLayerAddressSourceBlue+u16Width);
            u16Blue&=0x001F;
            *((uint16_t*)psLayerAddressDest+u16Width)&=~0x001F;
            *((uint16_t*)psLayerAddressDest+u16Width)|=u16Blue;
        }
        psLayerAddressSourceBlue+=u32LayerSourceBlueWidthTotal;
        psLayerAddressDest+=u32LayerDestWidthTotal<<1;
    }
    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;

}


IMAGPROC_nStatus IMAGEPROC__en8bBlueScale_16bRGBScale(LCDC_TFT_TypeDef*restrict psLayerSourceBlue, LCDC_TFT_TypeDef *restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{


    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightDest=0,u32HeightSourceBlue=0;

    register uint32_t psLayerAddressDest,psLayerAddressSourceBlue;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceBlueWidthTotal=psLayerSourceBlue->layerWidthTotal;
    register uint32_t u32LayerSourceBlueHeightTotal=psLayerSourceBlue->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    register uint16_t u16Blue = 0;
    if((psLayerSourceBlue->variableType != VARIABLETYPE_enUCHAR) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceBlueWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceBlueHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceBlueWidthTotal)
        u16DimWidth= u32LayerSourceBlueWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceBlueHeightTotal)
        u16DimHeight= u32LayerSourceBlueHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSourceBlue->layerDataAddress, psLayerSourceBlue->layerWidthTotal*psLayerSourceBlue->layerHeightTotal);
    u32HeightSourceBlue=(u16DimY0)*u32LayerSourceBlueWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    psLayerAddressSourceBlue=psLayerSourceBlue->layerDataAddress+(u32HeightSourceBlue);
    psLayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {
            u16Blue=*((uint8_t*)psLayerAddressSourceBlue+u16Width);
            u16Blue>>=3;
            u16Blue&=0x001F;
            *((uint16_t*)psLayerAddressDest+u16Width)&=~0x001F;
            *((uint16_t*)psLayerAddressDest+u16Width)|=u16Blue;
        }
        psLayerAddressSourceBlue+=u32LayerSourceBlueWidthTotal;
        psLayerAddressDest+=u32LayerDestWidthTotal<<1;
    }
    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;

}



IMAGPROC_nStatus IMAGEPROC__en16bSubtractionABS(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource1=0,u32HeightSource2=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource1;
    register uint32_t u32LayerAddressSource2;

    register uint16_t u16Value1 = 0;
    register uint16_t u16Value2 = 0;
    register uint16_t u16Aux = 0;

    register int8_t s8Blue1 = 0;
    register int8_t s8Green1 = 0;
    register int8_t s8Red1 = 0;
    register int8_t s8Blue2 = 0;
    register int8_t s8Green2 = 0;
    register int8_t s8Red2 = 0;

    register uint32_t u32HeightDest=0;
    register uint16_t u16Result = 0;


    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];

    register uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
    register uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
    register uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
    register uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    if((psLayerSource1->variableType != VARIABLETYPE_enUSHORT) || (psLayerSource2->variableType != VARIABLETYPE_enUSHORT)
            || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal*2);
    Cache__vInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal*2);

    u32HeightSource1=(u16DimY0)*u32LayerSource1WidthTotal+u16DimX0;
    u32HeightSource2=(u16DimY1)*u32LayerSource2WidthTotal+u16DimX1;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX2;

    u32LayerAddressSource1=psLayerSource1->layerDataAddress+(u32HeightSource1<<1);
    u32LayerAddressSource2=psLayerSource2->layerDataAddress+(u32HeightSource2<<1);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Value1=*((uint16_t*)u32LayerAddressSource1+u16Width);
            u16Value2=*((uint16_t*)u32LayerAddressSource2+u16Width);

            u16Aux=u16Value1&0x001F;
            s8Blue1 =(int8_t)u16Aux;

            u16Aux=u16Value1&0x07E0;
            u16Aux>>=5;
            s8Green1=(int8_t)u16Aux;

            u16Aux =u16Value1&0xF800;
            u16Aux >>=11;
            s8Red1=(int8_t)u16Aux;

            u16Aux=u16Value2&0x001F;
            s8Blue2 =(int8_t)u16Aux;

            u16Aux=u16Value2&0x07E0;
            u16Aux>>=5;
            s8Green2=(int8_t)u16Aux;

            u16Aux =u16Value2&0xF800;
            u16Aux >>=11;
            s8Red2=(int8_t)u16Aux;

            s8Blue1-=s8Blue2;
            s8Green1-=s8Green2;
            s8Red1-=s8Red2;
            if(s8Blue1<0)
                s8Blue1*=-1;
            if(s8Blue1>0x1F)
                s8Blue1=0x1F;
            if(s8Green1<0)
                s8Green1*=-1;
            if(s8Green1>0x3F)
                s8Green1=0x3F;
            if(s8Red1<0)
                s8Red1*=-1;
            if(s8Red1>0x1F)
                s8Red1=0x1F;


            u16Result=(uint16_t)(((uint16_t)s8Red1<<11)|((uint16_t)s8Green1<<5)|(uint16_t)s8Blue1);
            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Result;
        }
        u32LayerAddressSource1+=u32LayerSource1WidthTotal<<1;
        u32LayerAddressSource2+=u32LayerSource2WidthTotal<<1;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;
}



IMAGPROC_nStatus IMAGEPROC__en16bSubtraction(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource1=0,u32HeightSource2=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource1;
    register uint32_t u32LayerAddressSource2;

    register uint16_t u16Value1 = 0;
    register uint16_t u16Value2 = 0;
    register uint16_t u16Aux = 0;

    register int8_t s8Blue1 = 0;
    register int8_t s8Green1 = 0;
    register int8_t s8Red1 = 0;
    register int8_t s8Blue2 = 0;
    register int8_t s8Green2 = 0;
    register int8_t s8Red2 = 0;

    register uint32_t u32HeightDest=0;
    register uint16_t u16Result = 0;


    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];

    register uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
    register uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
    register uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
    register uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    if((psLayerSource1->variableType != VARIABLETYPE_enUSHORT) || (psLayerSource2->variableType != VARIABLETYPE_enUSHORT)
            || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal*2);
    Cache__vInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal*2);

    u32HeightSource1=(u16DimY0)*u32LayerSource1WidthTotal+u16DimX0;
    u32HeightSource2=(u16DimY1)*u32LayerSource2WidthTotal+u16DimX1;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX2;

    u32LayerAddressSource1=psLayerSource1->layerDataAddress+(u32HeightSource1<<1);
    u32LayerAddressSource2=psLayerSource2->layerDataAddress+(u32HeightSource2<<1);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Value1=*((uint16_t*)u32LayerAddressSource1+u16Width);
            u16Value2=*((uint16_t*)u32LayerAddressSource2+u16Width);

            u16Aux=u16Value1&0x001F;
            s8Blue1 =(int8_t)u16Aux;

            u16Aux=u16Value1&0x07E0;
            u16Aux>>=5;
            s8Green1=(int8_t)u16Aux;

            u16Aux =u16Value1&0xF800;
            u16Aux >>=11;
            s8Red1=(int8_t)u16Aux;

            u16Aux=u16Value2&0x001F;
            s8Blue2 =(int8_t)u16Aux;

            u16Aux=u16Value2&0x07E0;
            u16Aux>>=5;
            s8Green2=(int8_t)u16Aux;

            u16Aux =u16Value2&0xF800;
            u16Aux >>=11;
            s8Red2=(int8_t)u16Aux;

            s8Blue1-=s8Blue2;
            s8Green1-=s8Green2;
            s8Red1-=s8Red2;

            if(s8Blue1<0)
                s8Blue1=0;
            s8Blue1&=0x1F;
            if(s8Green1<0)
                s8Green1=0;
            s8Green1&=0x3F;
            if(s8Red1<0)
                s8Red1=0;
            s8Red1&=0x1F;


            u16Result=(uint16_t)(((uint16_t)s8Red1<<11)|((uint16_t)s8Green1<<5)|(uint16_t)s8Blue1);
            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Result;
        }
        u32LayerAddressSource1+=u32LayerSource1WidthTotal<<1;
        u32LayerAddressSource2+=u32LayerSource2WidthTotal<<1;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en8bSubtraction(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource1=0,u32HeightSource2=0,u32HeightDest=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource1;
    register uint32_t u32LayerAddressSource2;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];

    register uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
    register uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
    register uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
    register uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register int16_t s16Value = 0;
    register uint8_t u8Value1 = 0;
    register uint8_t u8Value2 = 0;
    if((psLayerSource1->variableType != VARIABLETYPE_enUCHAR) || (psLayerSource2->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerDest->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal);
    Cache__vInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal);

    u32HeightSource1=(u16DimY0)*u32LayerSource1WidthTotal+u16DimX0;
    u32HeightSource2=(u16DimY1)*u32LayerSource2WidthTotal+u16DimX1;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX2;

    u32LayerAddressSource1=psLayerSource1->layerDataAddress+(u32HeightSource1);
    u32LayerAddressSource2=psLayerSource2->layerDataAddress+(u32HeightSource2);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u8Value1=*((uint8_t*)u32LayerAddressSource1+u16Width);
            u8Value2=*((uint8_t*)u32LayerAddressSource2+u16Width);

            s16Value=((int16_t)u8Value1-(int16_t)u8Value2);

            if(s16Value<0)
                s16Value=0;

            if(s16Value>0xFF)
                s16Value=0xFF;

            *((uint8_t*)u32LayerAddressDest+u16Width)= (uint8_t)s16Value;

        }
        u32LayerAddressSource1+=u32LayerSource1WidthTotal;
        u32LayerAddressSource2+=u32LayerSource2WidthTotal;
        u32LayerAddressDest+=u32LayerDestWidthTotal;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal);

    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en8bSubtractionABS(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource1=0,u32HeightSource2=0,u32HeightDest=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource1;
    register uint32_t u32LayerAddressSource2;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];

    register uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
    register uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
    register uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
    register uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register int16_t s16Value = 0;
    register uint8_t u8Value1 = 0;
    register uint8_t u8Value2 = 0;
    if((psLayerSource1->variableType != VARIABLETYPE_enUCHAR) || (psLayerSource2->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerDest->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal);
    Cache__vInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal);

    u32HeightSource1=(u16DimY0)*u32LayerSource1WidthTotal+u16DimX0;
    u32HeightSource2=(u16DimY1)*u32LayerSource2WidthTotal+u16DimX1;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX2;

    u32LayerAddressSource1=psLayerSource1->layerDataAddress+(u32HeightSource1);
    u32LayerAddressSource2=psLayerSource2->layerDataAddress+(u32HeightSource2);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u8Value1=*((uint8_t*)u32LayerAddressSource1+u16Width);
            u8Value2=*((uint8_t*)u32LayerAddressSource2+u16Width);

            s16Value=((int16_t)u8Value1-(int16_t)u8Value2);

            if(s16Value<0)
                s16Value*=-1;
            if(s16Value>0xFF)
                s16Value=0xFF;

            *((uint8_t*)u32LayerAddressDest+u16Width)= (uint8_t)s16Value;

        }
        u32LayerAddressSource1+=u32LayerSource1WidthTotal;
        u32LayerAddressSource2+=u32LayerSource2WidthTotal;
        u32LayerAddressDest+=u32LayerDestWidthTotal;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal);

    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en16bAddMean(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource1=0,u32HeightSource2=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource1;
    register uint32_t u32LayerAddressSource2;

    register uint16_t u16Value1 = 0;
    register uint16_t u16Value2 = 0;
    register uint32_t u32Byte1 = 0;
    register uint32_t u32Byte2 = 0;

    register uint32_t u32Blue = 0;
    register uint32_t u32Green = 0;
    register uint32_t u32Red = 0;

    register uint32_t u32Aux = 0;
    register uint32_t u32HeightDest=0;
    register uint16_t u16Result = 0;


    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];

    register uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
    register uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
    register uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
    register uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    if((psLayerSource1->variableType != VARIABLETYPE_enUSHORT) || (psLayerSource2->variableType != VARIABLETYPE_enUSHORT)
            || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal*2);
    Cache__vInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal*2);

    u32HeightSource1=(u16DimY0)*u32LayerSource1WidthTotal+u16DimX0;
    u32HeightSource2=(u16DimY1)*u32LayerSource2WidthTotal+u16DimX1;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX2;

    u32LayerAddressSource1=psLayerSource1->layerDataAddress+(u32HeightSource1<<1);
    u32LayerAddressSource2=psLayerSource2->layerDataAddress+(u32HeightSource2<<1);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Value1=*((uint16_t*)u32LayerAddressSource1+u16Width);
            u16Value2=*((uint16_t*)u32LayerAddressSource2+u16Width);

            u32Blue =u16Value1&0x001F;
            u32Green=u16Value1&0x07E0;
            u32Red =u16Value1&0xF800;
            u32Green<<=3;
            u32Red <<=5;
            u32Byte1=u32Red|u32Green|u32Blue;


            u32Blue =u16Value2&0x001F;
            u32Green=u16Value2&0x07E0;
            u32Red =u16Value2&0xF800;
            u32Green<<=3;
            u32Red <<=5;
            u32Byte2=u32Red|u32Green|u32Blue;

            u32Aux=_avgu4(u32Byte1,u32Byte2);

            u32Blue=u32Aux &0x001F;
            u32Green=(u32Aux>>3)&0x07E0;
            u32Red =(u32Aux>>5)&0xF800;

            u16Result=(uint16_t)(u32Red|u32Green|u32Blue);
            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Result;
        }
        u32LayerAddressSource1+=u32LayerSource1WidthTotal<<1;
        u32LayerAddressSource2+=u32LayerSource2WidthTotal<<1;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en16bAddPartialConstant(LCDC_TFT_TypeDef* restrict psLayerSource, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim,uint8_t u8Red,uint8_t u8Green,uint8_t u8Blue)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDest=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource;

    register uint16_t u16Value = 0;
    register uint32_t u32Byte1 = 0;
    register uint32_t u32Byte2 = 0;

    register uint32_t u32Blue = 0;
    register uint32_t u32Green = 0;
    register uint32_t u32Red = 0;

    register uint32_t u32Aux = 0;
    register uint16_t u16Result = 0;


    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;


    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);
    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);

    u32Byte2=((u8Red&0x1F)<<16)|((u8Green&0x3F)<<8)|(u8Blue&0x1F);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Value=*((uint16_t*)u32LayerAddressSource+u16Width);

            u32Blue =u16Value&0x001F;
            u32Green=u16Value&0x07E0;
            u32Red =u16Value&0xF800;
            u32Green<<=3;
            u32Red <<=5;
            u32Byte1=u32Red|u32Green|u32Blue;

            u32Aux=_avgu4(u32Byte1,u32Byte2);

            u32Blue=u32Aux &0x001F;
            u32Green=(u32Aux>>3)&0x07E0;
            u32Red =(u32Aux>>5)&0xF800;

            u16Result=(uint16_t)(u32Red|u32Green|u32Blue);
            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Result;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;
}



IMAGPROC_nStatus IMAGEPROC__en16bAddConstantComplete(LCDC_TFT_TypeDef* restrict psLayerSource, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim,uint16_t u16Color)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDest=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource;

    register uint16_t u16Value = 0;
    register uint32_t u32Byte1 = 0;
    register uint32_t u32Byte2 = 0;

    register uint32_t u32Blue = 0;
    register uint32_t u32Green = 0;
    register uint32_t u32Red = 0;

    register uint32_t u32Aux = 0;
    register uint16_t u16Result = 0;


    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;


    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);
    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);

    u32Byte2=(((uint32_t)u16Color<<5)&0x1F0000)|(((uint32_t)u16Color<<3)&0x003F00)|(((uint32_t)u16Color)&0x00001F);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Value=*((uint16_t*)u32LayerAddressSource+u16Width);

            u32Blue =u16Value&0x001F;
            u32Green=u16Value&0x07E0;
            u32Red =u16Value&0xF800;
            u32Green<<=3;
            u32Red <<=5;
            u32Byte1=u32Red|u32Green|u32Blue;

            u32Aux=_avgu4(u32Byte1,u32Byte2);

            u32Blue=u32Aux &0x001F;
            u32Green=(u32Aux>>3)&0x07E0;
            u32Red =(u32Aux>>5)&0xF800;

            u16Result=(uint16_t)(u32Red|u32Green|u32Blue);
            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Result;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;
}



IMAGPROC_nStatus IMAGEPROC__en16bAddConstant(LCDC_TFT_TypeDef* restrict psLayerSource, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim,uint8_t u8Red,uint8_t u8Green,uint8_t u8Blue)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDest=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource;

    register uint16_t u16Value = 0;
    register uint32_t u32Byte1 = 0;
    register uint32_t u32Byte2 = 0;

    register uint32_t u32Blue = 0;
    register uint32_t u32Green = 0;
    register uint32_t u32Red = 0;

    register uint32_t u32Aux = 0;
    register uint16_t u16Result = 0;


    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    if((psLayerSource->variableType != VARIABLETYPE_enUSHORT) || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;


    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal*2);
    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource<<1);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);

    u32Byte2=(((uint32_t)u8Red<<13)&0x1F0000)|(((uint32_t)u8Green<<6)&0x003F00)|(((uint32_t)u8Blue>>3)&0x00001F);
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Value=*((uint16_t*)u32LayerAddressSource+u16Width);

            u32Blue =u16Value&0x001F;
            u32Green=u16Value&0x07E0;
            u32Red =u16Value&0xF800;
            u32Green<<=3;
            u32Red <<=5;
            u32Byte1=u32Red|u32Green|u32Blue;

            u32Aux=_avgu4(u32Byte1,u32Byte2);

            u32Blue=u32Aux &0x001F;
            u32Green=(u32Aux>>3)&0x07E0;
            u32Red =(u32Aux>>5)&0xF800;

            u16Result=(uint16_t)(u32Red|u32Green|u32Blue);
            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Result;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal<<1;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en16bAdd(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource1=0,u32HeightSource2=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource1;
    register uint32_t u32LayerAddressSource2;

     register uint16_t u16Value1 = 0;
     register uint16_t u16Value2 = 0;

     register uint16_t u16Blue1 = 0;
     register uint16_t u16Green1 = 0;
     register uint16_t u16Red1 = 0;
     register uint16_t u16Blue2 = 0;
     register uint16_t u16Green2 = 0;
     register uint16_t u16Red2 = 0;

     register uint32_t u32Blue = 0;
     register uint32_t u32Green = 0;
     register uint32_t u32Red = 0;

    register uint32_t u32Aux = 0;
    register uint32_t u32HeightDest=0;
    register uint16_t u16Result = 0;
    register float    fResult = 0;
    register float    fAux = 0;


    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];

    register uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
    register uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
    register uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
    register uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;
    if((psLayerSource1->variableType != VARIABLETYPE_enUSHORT) || (psLayerSource2->variableType != VARIABLETYPE_enUSHORT)
            || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal*2);
    Cache__vInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal*2);

    u32HeightSource1=(u16DimY0)*u32LayerSource1WidthTotal+u16DimX0;
    u32HeightSource2=(u16DimY1)*u32LayerSource2WidthTotal+u16DimX1;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX2;

    u32LayerAddressSource1=psLayerSource1->layerDataAddress+(u32HeightSource1<<1);
    u32LayerAddressSource2=psLayerSource2->layerDataAddress+(u32HeightSource2<<1);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Value1=*((uint16_t*)u32LayerAddressSource1+u16Width);
            u16Value2=*((uint16_t*)u32LayerAddressSource2+u16Width);


            u16Blue1 =u16Value1&0x001F;
            u16Blue2 =u16Value2&0x001F;
            u32Blue=(u16Blue1<<16)|u16Blue2;
            u32Aux=(uint32_t)_dotp2(u32Blue,u32Blue);
            fAux=(float)u32Aux;
            fResult=sqrtsp_i(fAux);
            u16Blue1=(uint16_t)fResult;
            if(u16Blue1>0x1F)
                u16Blue1=0x1F;

            u16Green1 =(u16Value1&0x07E0)>>5;
            u16Green2 =(u16Value2&0x07E0)>>5;
            u32Green=(u16Green1<<16)|u16Green2;
            u32Aux=(uint32_t)_dotp2(u32Green,u32Green);
            fAux=(float)u32Aux;
            fResult=sqrtsp_i(fAux);
            u16Green1=(uint16_t)fResult;
            if(u16Green1>0x3F)
                u16Green1=0x3F;
            u16Green1<<=5;

            u16Red1 =(u16Value1&0xF800)>>11;
            u16Red2 =(u16Value2&0xF800)>>11;
            u32Red=(u16Red1<<16)|u16Red2;
            u32Aux=(uint32_t)_dotp2(u32Red,u32Red);
            fAux=(float)u32Aux;
            fResult=sqrtsp_i(fAux);
            u16Red1=(uint16_t)fResult;
            if(u16Red1>0x1F)
                u16Red1=0x1F;
            u16Red1<<=11;

            u16Result=(uint16_t)(u16Red1|u16Green1|u16Blue1);
            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Result;
        }
        u32LayerAddressSource1+=u32LayerSource1WidthTotal<<1;
        u32LayerAddressSource2+=u32LayerSource2WidthTotal<<1;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;
}




IMAGPROC_nStatus IMAGEPROC__en16bAddBlend(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, float fBlend)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource1=0,u32HeightSource2=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource1;
    register uint32_t u32LayerAddressSource2;

    register uint16_t u16Value1 = 0;
    register uint16_t u16Value2 = 0;

    register uint16_t u16Blue1 = 0;
    register uint16_t u16Green1 = 0;
    register uint16_t u16Red1 = 0;
    register uint16_t u16Blue2 = 0;
    register uint16_t u16Green2 = 0;
    register uint16_t u16Red2 = 0;
    register uint32_t u32HeightDest=0;
    register uint16_t u16Result = 0;
    register float    fResult = 0;
    register float    fAux1 = 0;
    register float    fAux2 = 0;
    register float    fBlend1 = 1-fBlend;


    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];

    register uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
    register uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
    register uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
    register uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;


    if((fBlend>1.0) || (fBlend<0))
        return IMAGPROC_enERROR;

    if((psLayerSource1->variableType != VARIABLETYPE_enUSHORT) || (psLayerSource2->variableType != VARIABLETYPE_enUSHORT)
            || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal*2);
    Cache__vInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal*2);

    u32HeightSource1=(u16DimY0)*u32LayerSource1WidthTotal+u16DimX0;
    u32HeightSource2=(u16DimY1)*u32LayerSource2WidthTotal+u16DimX1;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX2;

    u32LayerAddressSource1=psLayerSource1->layerDataAddress+(u32HeightSource1<<1);
    u32LayerAddressSource2=psLayerSource2->layerDataAddress+(u32HeightSource2<<1);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);
    #pragma UNROLL(4)
    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
    #pragma UNROLL(4)
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Value1=*((uint16_t*)u32LayerAddressSource1+u16Width);
            u16Value2=*((uint16_t*)u32LayerAddressSource2+u16Width);


            u16Blue1 =u16Value1&0x001F;
            u16Blue2 =u16Value2&0x001F;
            fAux1=(float)u16Blue1;
            fAux2=(float)u16Blue2;
            fAux1*=fAux1;
            fAux1*=fBlend;
            fAux2*=fAux2;
            fAux1+=fAux2*fBlend1;
            fResult=sqrtsp_i(fAux1);
            u16Blue1=(uint16_t)fResult;
            if(u16Blue1>0x1F)
                u16Blue1=0x1F;

            u16Green1 =(u16Value1&0x07E0)>>5;
            u16Green2 =(u16Value2&0x07E0)>>5;
            fAux1=(float)u16Green1;
            fAux2=(float)u16Green2;
            fAux1*=fAux1;
            fAux1*=fBlend;
            fAux2*=fAux2;
            fAux1+=fAux2*fBlend1;
            fResult=sqrtsp_i(fAux1);
            u16Green1=(uint16_t)fResult;
            if(u16Green1>0x3F)
                u16Green1=0x3F;
            u16Green1<<=5;

            u16Red1 =(u16Value1&0xF800)>>11;
            u16Red2 =(u16Value2&0xF800)>>11;
            fAux1=(float)u16Red1;
            fAux2=(float)u16Red2;
            fAux1*=fAux1;
            fAux1*=fBlend;
            fAux2*=fAux2;
            fAux1+=fAux2*fBlend1;
            fResult=sqrtsp_i(fAux1);
            u16Red1=(uint16_t)fResult;
            if(u16Red1>0x1F)
                u16Red1=0x1F;
            u16Red1<<=11;

            u16Result=(uint16_t)(u16Red1|u16Green1|u16Blue1);
            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Result;
        }
        u32LayerAddressSource1+=u32LayerSource1WidthTotal<<1;
        u32LayerAddressSource2+=u32LayerSource2WidthTotal<<1;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;
}



IMAGPROC_nStatus IMAGEPROC__en16bAddMeanBlend(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, float fBlend)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource1=0,u32HeightSource2=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource1;
    register uint32_t u32LayerAddressSource2;

    register uint16_t u16Value1 = 0;
    register uint16_t u16Value2 = 0;

    register uint16_t u16Blue1 = 0;
    register uint16_t u16Green1 = 0;
    register uint16_t u16Red1 = 0;
    register uint16_t u16Blue2 = 0;
    register uint16_t u16Green2 = 0;
    register uint16_t u16Red2 = 0;
    register uint32_t u32HeightDest=0;
    register uint16_t u16Result = 0;
    register float    fAux1 = 0;
    register float    fAux2 = 0;
    register float    fBlend1 = 1-fBlend;


    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];

    register uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
    register uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
    register uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
    register uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;


    if((fBlend>1.0) || (fBlend<0))
        return IMAGPROC_enERROR;

    if((psLayerSource1->variableType != VARIABLETYPE_enUSHORT) || (psLayerSource2->variableType != VARIABLETYPE_enUSHORT)
            || (psLayerDest->variableType != VARIABLETYPE_enUSHORT))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal*2);
    Cache__vInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal*2);

    u32HeightSource1=(u16DimY0)*u32LayerSource1WidthTotal+u16DimX0;
    u32HeightSource2=(u16DimY1)*u32LayerSource2WidthTotal+u16DimX1;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX2;

    u32LayerAddressSource1=psLayerSource1->layerDataAddress+(u32HeightSource1<<1);
    u32LayerAddressSource2=psLayerSource2->layerDataAddress+(u32HeightSource2<<1);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest<<1);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Value1=*((uint16_t*)u32LayerAddressSource1+u16Width);
            u16Value2=*((uint16_t*)u32LayerAddressSource2+u16Width);


            u16Blue1 =u16Value1&0x001F;
            u16Blue2 =u16Value2&0x001F;
            fAux1=(float)u16Blue1;
            fAux2=(float)u16Blue2;
            fAux1*=fBlend;
            fAux1+=fAux2*fBlend1;
            u16Blue1=(uint16_t)fAux1;
            if(u16Blue1>0x1F)
                u16Blue1=0x1F;

            u16Green1 =(u16Value1&0x07E0)>>5;
            u16Green2 =(u16Value2&0x07E0)>>5;
            fAux1=(float)u16Green1;
            fAux2=(float)u16Green2;
            fAux1*=fBlend;
            fAux1+=fAux2*fBlend1;
            u16Green1=(uint16_t)fAux1;
            if(u16Green1>0x3F)
                u16Green1=0x3F;
            u16Green1<<=5;

            u16Red1 =(u16Value1&0xF800)>>11;
            u16Red2 =(u16Value2&0xF800)>>11;
            fAux1=(float)u16Red1;
            fAux2=(float)u16Red2;
            fAux1*=fBlend;
            fAux1+=fAux2*fBlend1;
            u16Red1=(uint16_t)fAux1;
            if(u16Red1>0x1F)
                u16Red1=0x1F;
            u16Red1<<=11;

            u16Result=(uint16_t)(u16Red1|u16Green1|u16Blue1);
            *((uint16_t*)u32LayerAddressDest+u16Width)= u16Result;
        }
        u32LayerAddressSource1+=u32LayerSource1WidthTotal<<1;
        u32LayerAddressSource2+=u32LayerSource2WidthTotal<<1;
        u32LayerAddressDest+=u32LayerDestWidthTotal<<1;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal*2);

    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en8bAdd(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, uint8_t u8Umbral)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource1=0,u32HeightSource2=0,u32HeightDest=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource1;
    register uint32_t u32LayerAddressSource2;

    register uint32_t u32Aux = 0;
    register float    fResult = 0;
    register float    fAux = 0;




    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];

    register uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
    register uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
    register uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
    register uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint32_t u32Value = 0;
    register uint8_t u8Value1 = 0;
    register uint8_t u8Value2 = 0;
    register uint8_t  u8Result = 0;
    if((psLayerSource1->variableType != VARIABLETYPE_enUCHAR) || (psLayerSource2->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerDest->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal);
    Cache__vInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal);

    u32HeightSource1=(u16DimY0)*u32LayerSource1WidthTotal+u16DimX0;
    u32HeightSource2=(u16DimY1)*u32LayerSource2WidthTotal+u16DimX1;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX2;

    u32LayerAddressSource1=psLayerSource1->layerDataAddress+(u32HeightSource1);
    u32LayerAddressSource2=psLayerSource2->layerDataAddress+(u32HeightSource2);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u8Value1=*((uint8_t*)u32LayerAddressSource1+u16Width);
            u8Value2=*((uint8_t*)u32LayerAddressSource2+u16Width);


            u32Value=(u8Value1<<16)|u8Value2;
            u32Aux=(uint32_t)_dotp2(u32Value,u32Value);
            fAux=(float)u32Aux;
            fResult=sqrtsp_i(fAux);
            u8Result=(uint8_t)fResult;
            if(u8Result>u8Umbral)
                u8Result=u8Umbral;

            *((uint8_t*)u32LayerAddressDest+u16Width)= u8Result;
        }
        u32LayerAddressSource1+=u32LayerSource1WidthTotal;
        u32LayerAddressSource2+=u32LayerSource2WidthTotal;
        u32LayerAddressDest+=u32LayerDestWidthTotal;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal);

    return IMAGPROC_enOK;
}



IMAGPROC_nStatus IMAGEPROC__en8bAddMean(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, uint8_t u8Umbral)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource1=0,u32HeightSource2=0,u32HeightDest=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource1;
    register uint32_t u32LayerAddressSource2;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];

    register uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
    register uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
    register uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
    register uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint16_t u16Value = 0;
    register uint8_t u8Value1 = 0;
    register uint8_t u8Value2 = 0;
    register uint8_t  u8Result = 0;
    if((psLayerSource1->variableType != VARIABLETYPE_enUCHAR) || (psLayerSource2->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerDest->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal);
    Cache__vInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal);

    u32HeightSource1=(u16DimY0)*u32LayerSource1WidthTotal+u16DimX0;
    u32HeightSource2=(u16DimY1)*u32LayerSource2WidthTotal+u16DimX1;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX2;

    u32LayerAddressSource1=psLayerSource1->layerDataAddress+(u32HeightSource1);
    u32LayerAddressSource2=psLayerSource2->layerDataAddress+(u32HeightSource2);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u8Value1=*((uint8_t*)u32LayerAddressSource1+u16Width);
            u8Value2=*((uint8_t*)u32LayerAddressSource2+u16Width);

            u16Value=(u8Value1+u8Value2+1)>>1;
            u8Result=(uint8_t)u16Value;
            if(u8Result>u8Umbral)
                u8Result=u8Umbral;

            *((uint8_t*)u32LayerAddressDest+u16Width)= u8Result;
        }
        u32LayerAddressSource1+=u32LayerSource1WidthTotal;
        u32LayerAddressSource2+=u32LayerSource2WidthTotal;
        u32LayerAddressDest+=u32LayerDestWidthTotal;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal);

    return IMAGPROC_enOK;
}

IMAGPROC_nStatus IMAGEPROC__en8bAddBlend(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, uint8_t u8Umbral, float fBlend)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource1=0,u32HeightSource2=0,u32HeightDest=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource1;
    register uint32_t u32LayerAddressSource2;

    register float fBlend1= 1-fBlend;
    register float fValue1= 0;
    register float fValue2= 0;
    register float fResult = 0;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];

    register uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
    register uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
    register uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
    register uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint8_t u8Value1 = 0;
    register uint8_t u8Value2 = 0;
    register uint8_t  u8Result = 0;


    if((fBlend>1.0) || (fBlend<0))
        return IMAGPROC_enERROR;

    if((psLayerSource1->variableType != VARIABLETYPE_enUCHAR) || (psLayerSource2->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerDest->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal);
    Cache__vInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal);

    u32HeightSource1=(u16DimY0)*u32LayerSource1WidthTotal+u16DimX0;
    u32HeightSource2=(u16DimY1)*u32LayerSource2WidthTotal+u16DimX1;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX2;

    u32LayerAddressSource1=psLayerSource1->layerDataAddress+(u32HeightSource1);
    u32LayerAddressSource2=psLayerSource2->layerDataAddress+(u32HeightSource2);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u8Value1=*((uint8_t*)u32LayerAddressSource1+u16Width);
            u8Value2=*((uint8_t*)u32LayerAddressSource2+u16Width);

            fValue1=(float)u8Value1;
            fValue2=(float)u8Value2;

            fValue1*=fValue1;
            fValue1*=fBlend;
            fValue2*=fValue2;
            fValue1+=fValue2*fBlend1;
            fResult=sqrtsp_i(fValue1);

            u8Result=(uint8_t)fResult;
            if(u8Result>u8Umbral)
                u8Result=u8Umbral;

            *((uint8_t*)u32LayerAddressDest+u16Width)= u8Result;
        }
        u32LayerAddressSource1+=u32LayerSource1WidthTotal;
        u32LayerAddressSource2+=u32LayerSource2WidthTotal;
        u32LayerAddressDest+=u32LayerDestWidthTotal;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal);

    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en8bAddMeanBlend(LCDC_TFT_TypeDef* restrict psLayerSource1,LCDC_TFT_TypeDef* restrict psLayerSource2, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim, uint8_t u8Umbral, float fBlend)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource1=0,u32HeightSource2=0,u32HeightDest=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource1;
    register uint32_t u32LayerAddressSource2;

    register float fBlend1= 1-fBlend;
    register float fValue1= 0;
    register float fValue2= 0;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimX2=sDim.X[2];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];
    register uint16_t u16DimY2=sDim.Y[2];

    register uint32_t u32LayerSource1WidthTotal=psLayerSource1->layerWidthTotal;
    register uint32_t u32LayerSource2WidthTotal=psLayerSource2->layerWidthTotal;
    register uint32_t u32LayerSource1HeightTotal=psLayerSource1->layerHeightTotal;
    register uint32_t u32LayerSource2HeightTotal=psLayerSource2->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint8_t u8Value1 = 0;
    register uint8_t u8Value2 = 0;
    register uint8_t  u8Result = 0;

    if((fBlend>1.0) || (fBlend<0))
        return IMAGPROC_enERROR;

    if((psLayerSource1->variableType != VARIABLETYPE_enUCHAR) || (psLayerSource2->variableType != VARIABLETYPE_enUCHAR)
            || (psLayerDest->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSource1WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerSource2WidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX2>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSource1HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerSource2HeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY2>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSource1WidthTotal)
        u16DimWidth= u32LayerSource1WidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSource1HeightTotal)
        u16DimHeight= u32LayerSource1HeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerSource2WidthTotal)
        u16DimWidth= u32LayerSource2WidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerSource2HeightTotal)
        u16DimHeight= u32LayerSource2HeightTotal- u16DimY1;


    if((u16DimWidth+ u16DimX2)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX2;
    if((u16DimHeight+ u16DimY2)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY2;

    Cache__vInvL2 (psLayerSource1->layerDataAddress, psLayerSource1->layerWidthTotal*psLayerSource1->layerHeightTotal);
    Cache__vInvL2 (psLayerSource2->layerDataAddress, psLayerSource2->layerWidthTotal*psLayerSource2->layerHeightTotal);

    u32HeightSource1=(u16DimY0)*u32LayerSource1WidthTotal+u16DimX0;
    u32HeightSource2=(u16DimY1)*u32LayerSource2WidthTotal+u16DimX1;
    u32HeightDest=(u16DimY2)*u32LayerDestWidthTotal+u16DimX2;

    u32LayerAddressSource1=psLayerSource1->layerDataAddress+(u32HeightSource1);
    u32LayerAddressSource2=psLayerSource2->layerDataAddress+(u32HeightSource2);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u8Value1=*((uint8_t*)u32LayerAddressSource1+u16Width);
            u8Value2=*((uint8_t*)u32LayerAddressSource2+u16Width);

            fValue1=(float)u8Value1;
            fValue2=(float)u8Value2;

            fValue1*=fBlend;
            fValue1+=fValue2*fBlend1;
            u8Result=(uint8_t)fValue1;
            if(u8Result>u8Umbral)
                u8Result=u8Umbral;

            *((uint8_t*)u32LayerAddressDest+u16Width)= u8Result;
        }
        u32LayerAddressSource1+=u32LayerSource1WidthTotal;
        u32LayerAddressSource2+=u32LayerSource2WidthTotal;
        u32LayerAddressDest+=u32LayerDestWidthTotal;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal);

    return IMAGPROC_enOK;
}




IMAGPROC_nStatus IMAGEPROC__en8bAddConstant(LCDC_TFT_TypeDef* restrict psLayerSource, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim,uint8_t u8Constant, uint8_t u8Umbral)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDest=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint16_t u16Value = 0;
    if((psLayerSource->variableType != VARIABLETYPE_enUCHAR) || (psLayerDest->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Value=*((uint8_t*)u32LayerAddressSource+u16Width);

            u16Value+=u8Constant;
            if(u16Value>u8Umbral)
                u16Value=u8Umbral;

            *((uint8_t*)u32LayerAddressDest+u16Width)= u16Value;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal;
        u32LayerAddressDest+=u32LayerDestWidthTotal;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal);

    return IMAGPROC_enOK;
}


IMAGPROC_nStatus IMAGEPROC__en8bAddMeanConstant(LCDC_TFT_TypeDef* restrict psLayerSource, LCDC_TFT_TypeDef* restrict psLayerDest, LCDC_DIMENSIONS_TypeDef sDim,uint8_t u8Constant, uint8_t u8Umbral)
{

    register uint16_t u16Width=0,u16Height=0;
    register uint32_t u32HeightSource=0,u32HeightDest=0;

    register uint32_t u32LayerAddressDest;
    register uint32_t u32LayerAddressSource;

    register uint16_t u16DimX0=sDim.X[0];
    register uint16_t u16DimX1=sDim.X[1];
    register uint16_t u16DimY0=sDim.Y[0];
    register uint16_t u16DimY1=sDim.Y[1];

    register uint32_t u32LayerSourceWidthTotal=psLayerSource->layerWidthTotal;
    register uint32_t u32LayerSourceHeightTotal=psLayerSource->layerHeightTotal;

    register uint32_t u32LayerDestWidthTotal=psLayerDest->layerWidthTotal;
    register uint32_t u32LayerDestHeightTotal=psLayerDest->layerHeightTotal;

    register uint16_t u16DimWidth=sDim.width;
    register uint16_t u16DimHeight=sDim.height;

    register uint16_t u16Value = 0;
    if((psLayerSource->variableType != VARIABLETYPE_enUCHAR) || (psLayerDest->variableType != VARIABLETYPE_enUCHAR))
            return IMAGPROC_enERROR;
    if(u16DimX0>u32LayerSourceWidthTotal)
        return IMAGPROC_enERROR;
    if(u16DimX1>u32LayerDestWidthTotal)
        return IMAGPROC_enERROR;

    if(u16DimY0>u32LayerSourceHeightTotal)
        return IMAGPROC_enERROR;
    if(u16DimY1>u32LayerDestHeightTotal)
        return IMAGPROC_enERROR;

    if((u16DimWidth+ u16DimX0)>u32LayerSourceWidthTotal)
        u16DimWidth= u32LayerSourceWidthTotal- u16DimX0;
    if((u16DimHeight+ u16DimY0)>u32LayerSourceHeightTotal)
        u16DimHeight= u32LayerSourceHeightTotal- u16DimY0;

    if((u16DimWidth+ u16DimX1)>u32LayerDestWidthTotal)
        u16DimWidth= u32LayerDestWidthTotal- u16DimX1;
    if((u16DimHeight+ u16DimY1)>u32LayerDestHeightTotal)
        u16DimHeight= u32LayerDestHeightTotal- u16DimY1;

    Cache__vInvL2 (psLayerSource->layerDataAddress, psLayerSource->layerWidthTotal*psLayerSource->layerHeightTotal);

    u32HeightSource=(u16DimY0)*u32LayerSourceWidthTotal+u16DimX0;
    u32HeightDest=(u16DimY1)*u32LayerDestWidthTotal+u16DimX1;

    u32LayerAddressSource=psLayerSource->layerDataAddress+(u32HeightSource);
    u32LayerAddressDest=psLayerDest->layerDataAddress+(u32HeightDest);

    for(u16Height=0;u16Height<u16DimHeight;u16Height++)
    {
        for(u16Width=0;u16Width<u16DimWidth;u16Width++)
        {

            u16Value=*((uint8_t*)u32LayerAddressSource+u16Width);

            u16Value+=u8Constant;
            u16Value>>=1;
            if(u16Value>u8Umbral)
                u16Value=u8Umbral;

            *((uint8_t*)u32LayerAddressDest+u16Width)= u16Value;
        }
        u32LayerAddressSource+=u32LayerSourceWidthTotal;
        u32LayerAddressDest+=u32LayerDestWidthTotal;
    }

    Cache__vWbL2 (psLayerDest->layerDataAddress, psLayerDest->layerWidthTotal*psLayerDest->layerHeightTotal);

    return IMAGPROC_enOK;
}




