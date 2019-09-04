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

