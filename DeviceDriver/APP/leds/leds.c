/*
 * led.c
 *
 *  Created on: 2018-1-20
 *      Author: Administrator
 */
#include "leds.h"

/*******************************************************************************
* �� �� ��         : LED_Init
* ��������		   : LED��ʼ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void LED_Init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;// ����GPIOʱ��

	//LED1�˿�����
	GpioCtrlRegs.GPBMUX2.bit.GPIO60=0;//����Ϊͨ��GPIO����
	GpioCtrlRegs.GPBDIR.bit.GPIO60=1;//����GPIO����Ϊ���
	GpioCtrlRegs.GPBPUD.bit.GPIO60=0;//ʹ��GPIO��������


	GpioDataRegs.GPBSET.bit.GPIO60=1;

	EDIS;
}
