#ifndef _FILTER_H
#define _FILTER_H

#include "AVP33x_Project.h"


#define NUMBER 25
#define PI 3.1415926
void dsp_filter(void);
//extern Uint16 ADC_TMP;
extern Uint32 AD_ADD[256];

extern Uint32 FIR_Out[256];




#endif
