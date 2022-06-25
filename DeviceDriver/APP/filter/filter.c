#include "filter.h"

#pragma DATA_SECTION(FIR_Out,"ramdata2");
Uint32 FIR_Out[256];

float H[NUMBER]={   -0.0185, -0.0283, -0.0122,  0.0199,
                    0.0406,  0.026, -0.021, -0.0648,
                   -0.0586,  0.0216,   0.154,   0.2775,
                     0.3277,   0.2775,   0.154,  0.0216,
                   -0.0586, -0.0648, -0.021,  0.026,
                    0.0406,  0.01991, -0.0122, -0.0283,
                   -0.0185
                     };

Uint32 X[NUMBER]={ 0.0 },FIR_Input,FIR_Output,FIR_In[256];

//int i,In_Number=0,Out_Number=0;

void dsp_filter(void)
{
    int i,j,In_Number=0,Out_Number=0;

    for(i=0;i<256;i++)
        {
            for ( j = NUMBER-1;j>0;j-- )
            {
                X[j] = X[j-1];
            }
            X[0]=AD_ADD[i];
            //InputWave();
            FIR_In[In_Number] = X[0];
            In_Number ++;
            In_Number %= 256;
            for ( j=0;j<NUMBER;j++ )
            {
                FIR_Output += (X[j]*H[j]);
            }
            FIR_Out[Out_Number] = FIR_Output;
            FIR_Output=0;
            Out_Number ++;
            Out_Number %= 256;
        }


}

/*
void InputWave()
{
    X[0] = sin(Theta)+sin(Theta1)+sin(Theta2);
    Theta += Theta_Step;
    Theta1 += Theta_Step1;
    Theta2 += Theta_Step2;
    if (Theta >= 2 * PI )
{
Theta -= 2 * PI;
}
    if (Theta1 >= 2 * PI )
{
Theta1 -= 2 * PI;
}
    if (Theta2 >= 2 * PI )
{
Theta2 -= 2 * PI;
}
}
*/
/*
void FIR()
{
    for ( i=0;i<NUMBER;i++ )
    {
        FIR_Output += (X[i]*H[i]);
    }
}
*/
