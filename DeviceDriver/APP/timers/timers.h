
#ifndef TIMERS_H_
#define TIMERS_H_


#include "AVP33x_Project.h"
#include "ad7608.h"
#include "filter.h"
#include "spi.h"




extern Uint32 FIR_Out[256];

void TIM0_Init(float Freq, float Period);
interrupt void TIM0_IRQn(void);

void TIM1_Init(float Freq, float Period);
interrupt void TIM1_IRQn(void);

void TIM2_Init(float Freq, float Period);
interrupt void TIM2_IRQn(void);


#endif /* TIME_H_ */
