/*
 * ad7608.h
 *
 *  Created on: 2022-3-2
 *      Author: Administrator
 */
#ifndef AD7608_H_
#define AD7608_H_

#include "AVP33x_Project.h"
#include "filter.h"

//extern void dsp_filter(void);

#define SCALE 10
#define BUF_SIZE 8
#define AD_ASTART ((Uint16 *)0x4000)
//#define SAMPLECOUNT 32
extern Uint32 AD_SAMPLE[7];
extern Uint32 AD_ADD[256];

void AD7608_Init(void);
void AD7608Initialization(void);
void AD7608Reset(void);
//void AD7608OneSample(void);
interrupt void XINT1_ISR1(void);

#endif
