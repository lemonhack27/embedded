/*
 * ad7608.h
 *
 *  Created on: 2022-3-2
 *      Author: Administrator
 */
#ifndef AD7608V2_H_
#define AD7608V2_H_

#include "AVP33x_Project.h"

#define AD7608_RST_LOW      GpioDataRegs.GPACLEAR.bit.GPIO1=1
#define AD7608_RST_HIGH     GpioDataRegs.GPASET.bit.GPIO1=1

#define AD7608_CNVST_LOW    GpioDataRegs.GPACLEAR.bit.GPIO0=1
#define AD7608_CNVST_HIGH   GpioDataRegs.GPASET.bit.GPIO0=1

#define AD7608_CS0_LOW      GpioDataRegs.GPBCLEAR.bit.GPIO36=1
#define AD7608_CS0_HIGH     GpioDataRegs.GPBSET.bit.GPIO36=1

#define AD7608_OS0_LOW      GpioDataRegs.GPACLEAR.bit.GPIO4=1   //过采样
#define AD7608_OS0_HIGH     GpioDataRegs.GPASET.bit.GPIO4=1

#define AD7608_OS1_LOW      GpioDataRegs.GPACLEAR.bit.GPIO5=1
#define AD7608_OS1_HIGH     GpioDataRegs.GPASET.bit.GPIO5=1

#define AD7608_OS2_LOW      GpioDataRegs.GPACLEAR.bit.GPIO6=1
#define AD7608_OS2_HIGH     GpioDataRegs.GPASET.bit.GPIO6=1

#define AD7608_BUSY_READ    GpioDataRegs.GPADAT.bit.GPIO24

#define AD7608_RANGE_10V    GpioDataRegs.GPASET.bit.GPIO2=1    //范围正负10
#define AD7608_RANGE_5V     GpioDataRegs.GPACLEAR.bit.GPIO2=1   //5V

#define AD7608_DOUTA_READ   GpioDataRegs.GPCDAT.bit.GPIO72
#define AD7608_DOUTB_READ   GpioDataRegs.GPCDAT.bit.GPIO71

#define AD_ASTART (*((volatile  Uint16 *)0x4000))

void AD7608_Init(void);
void AD7608Initialization(void);
void AD7608Reset(void);
void AD7608OneSample(void);

void Ad7608Test(void);




#endif
