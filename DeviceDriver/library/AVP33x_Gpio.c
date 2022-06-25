/******************************************************************************
�ļ���                     : AVP33x_Gpio.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xоƬͨ��IOģ���ʼ������������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#include "AVP33x_Device.h"     // AVP33x Headerfile Include File
#include "AVP33x_Examples.h"   // AVP33x Examples Include File

//---------------------------------------------------------------------------
// InitGpio: 
//---------------------------------------------------------------------------
// This function initializes the Gpio to a known (default) state.
//
// For more details on configuring GPIO's as peripheral functions,
// refer to the individual peripheral examples and/or GPIO setup example. 
void InitGpio(void)
{
   EALLOW;
   
   EALLOW;
   
   GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 0;
   GpioCtrlRegs.GPBDIR.bit.GPIO58 = 1;
   GpioCtrlRegs.GPBPUD.bit.GPIO58 = 1;
   GpioDataRegs.GPBDAT.bit.GPIO58 = 0;

   EDIS;

   EDIS;

}	
	
//===========================================================================
// End of file.
//===========================================================================
