/******************************************************************************
�ļ���                     : AVP33x_PieCtrl.c
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : PIE���ƼĴ�����ʼ��
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#include "AVP33x_Device.h"     // AVP33x Headerfile Include File
#include "AVP33x_Examples.h"   // AVP33x Examples Include File

//---------------------------------------------------------------------------
// InitPieCtrl: 
//---------------------------------------------------------------------------
// ��ʼ��PIE���ƼĴ���
//
void InitPieCtrl(void)
{
    // ��ֹCPU���ж�
    DINT;

    // ��ֹPIE
    PieCtrlRegs.PIECTRL.bit.ENPIE = 0;

	// �������PIE�ж�ʹ�ܼĴ���PIEIER
	PieCtrlRegs.PIEIER1.all = 0;
	PieCtrlRegs.PIEIER2.all = 0;
	PieCtrlRegs.PIEIER3.all = 0;	
	PieCtrlRegs.PIEIER4.all = 0;
	PieCtrlRegs.PIEIER5.all = 0;
	PieCtrlRegs.PIEIER6.all = 0;
	PieCtrlRegs.PIEIER7.all = 0;
	PieCtrlRegs.PIEIER8.all = 0;
	PieCtrlRegs.PIEIER9.all = 0;
	PieCtrlRegs.PIEIER10.all = 0;
	PieCtrlRegs.PIEIER11.all = 0;
	PieCtrlRegs.PIEIER12.all = 0;

	// �������PIE�жϱ�־�Ĵ���PIEIFR
	PieCtrlRegs.PIEIFR1.all = 0;
	PieCtrlRegs.PIEIFR2.all = 0;
	PieCtrlRegs.PIEIFR3.all = 0;	
	PieCtrlRegs.PIEIFR4.all = 0;
	PieCtrlRegs.PIEIFR5.all = 0;
	PieCtrlRegs.PIEIFR6.all = 0;
	PieCtrlRegs.PIEIFR7.all = 0;
	PieCtrlRegs.PIEIFR8.all = 0;
	PieCtrlRegs.PIEIFR9.all = 0;
	PieCtrlRegs.PIEIFR10.all = 0;
	PieCtrlRegs.PIEIFR11.all = 0;
	PieCtrlRegs.PIEIFR12.all = 0;
}	

//---------------------------------------------------------------------------
// EnableInterrupts: 
//---------------------------------------------------------------------------
// �ж�ʹ�ܺ���
//
void EnableInterrupts()
{
    // ʹ��PIE
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;
    		
	// ��PIEģ�����һ�������CPU�жϣ�ʹ��CPU������Ӧ��Ӧ���ж�
	PieCtrlRegs.PIEACK.all = 0xFFFF;  

	// ʹ��CPU�ж�
    EINT;
}

//===========================================================================
// End of file.
//===========================================================================
