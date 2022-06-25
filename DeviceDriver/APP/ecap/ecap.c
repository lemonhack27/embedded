/*
 * ecap.c
 *
 *  Created on: 2018��7��3��
 *      Author: Administrator
 */

#include "ecap.h"

//#include "epwm.h"

// Prototype statements for functions found within this file.
interrupt void ECAP2_ISR(void);
interrupt void ECAP3_ISR(void);
//void Fail(void);
Uint32 Pulse_Count=0; //�������
Uint32 PWM_Duty=0;    //PWMռ�ձ�
Uint32 PWM_Period=0;  //PWM����

/*******************************************************************************
* �� �� ��         : eCAP2_Init
* ��������         : ��ʼ��ECAP�Լ��ж�
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void eCAP2_Init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR1.bit.ECAP2ENCLK = 1;  // eCAP1
	EDIS;

	InitECap2Gpio();

	ECap2Regs.ECEINT.all = 0;               // ��������eCAP�ж�
    ECap2Regs.ECCTL1.bit.CAPLDEN = 0;       // ���õȴ�
    ECap2Regs.ECCTL2.bit.TSCTRSTOP = 0;     // ֹͣ����

    ECap2Regs.TSCTR = 0;                    // �������ֵ
    ECap2Regs.CTRPHS = 0;                   // �����������λ�Ĵ���


#ifdef EC_COUNTINUOUS
    ECap2Regs.ECCTL2.all = 0x003E;      // ECAP���ƼĴ���2
    ECap2Regs.ECCTL1.all = 0x0010;      // ECAP���ƼĴ���1
#else

    ECap2Regs.ECCTL2.all = 0x003E;      // ECAP���ƼĴ���2
    ECap2Regs.ECCTL1.all = 0x0144;      // ECAP���ƼĴ���1

#endif
    //ECap1Regs.ECCTL2.all = 0x0096;      // ECAP���ƼĴ���2
    // bit 15-11    00000:  ����
    // bit 10       0:  APWMPOL����CAPģʽ��Ч
    // bit 9        0:  CAP/APWM, 0 = ����ģʽ
    // bit 8        0:  SWSYNC, 0 = �޶���
    // bit 7-6          10: SYNCO_SEL, 10 = ����ͬ���ź����
    // bit 5            0:  SYNCI_EN, 0 = ����ͬ��
    // bit 4            1:  TSCTRSTOP, 1 = ʹ�ܼ�����
    // bit 3            0:  RE-ARM, 0 = ��Ӱ��
    // bit 2-1      11: STOP_WRAP, CEVT4����ʱֹͣ
    // bit 0        0:  CONT/ONESHT, 0 = ����ģʽ

    //ECap1Regs.ECCTL1.all = 0x01C4;      // ECAP���ƼĴ���1
    // bit 15-14        00:         FREE/SOFT, 00 = TSCTR����ֹͣ
    // bit 13-9         00000:      PRESCALE, 00000 = Ԥ��Ƶϵ��Ϊ1
    // bit 8            1:  CAPLDEN, 1 = ʹ��װ�ؿ���
    // bit 7            1:  CTRRST4, 1 = �����¼�CEVT4����ʱ����λ������
    // bit 6            1:  CAP4POL, 1 = �½��ش���
    // bit 5            0:  CTRRST3, 0 = �����¼�CEVT3����ʱ������λ������
    // bit 4            0:  CAP3POL, 0 = �����ش���
    // bit 3            0:  CTRRST2, 0 = �����¼�CEVT2����ʱ������λ������
    // bit 2            1:  CAP2POL, 1 = �½��ش���
    // bit 1            0:  CTRRST1, 0 = �����¼�CEVT1����ʱ������λ������
    // bit 0            0:  CAP1POL, 0 = �����ش���


    ECap2Regs.ECEINT.all = 0x0010;      // Enable desired eCAP interrupts
    // bit 15-8     0:  ����
    // bit 7        0:  CTR=CMP, 0 = ����ƥ�� CTR=CMP�������ж�
    // bit 6        0:  CTR=PRD, 0 = ����ƥ��CTR=PRD�������ж�
    // bit 5            0:  CTROVF, 0 = �������CTROVF�������ж�
    // bit 4        0:  CEVT4, 0 = ���ò���CEVT4�¼��ж�
    // bit 3            1:  CEVT3, 1 = ʹ�ܲ���CEVT3�¼��ж�
    // bit 2            0:  CEVT2, 0 = ���ò���CEVT3�¼��ж�
    // bit 1        0:  CEVT1, 0 = ���ò���CEVT3�¼��ж�
    // bit 0            0:  ����

	EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.ECAP2_INT= &ECAP2_ISR;
	EDIS;    // This is needed to disable write to EALLOW protected registers

	// Enable CPU INT4 which is connected to ECAP1-4 INT:
	IER |= M_INT4;
	// Enable eCAP INTn in the PIE: Group 3 interrupt 1-6
	PieCtrlRegs.PIEIER4.bit.INTx2 = 1;

	// Enable global Interrupts and higher priority real-time debug events:
	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM
}


/*******************************************************************************
* �� �� ��         : eCAP3_Init
* ��������         : ��ʼ��ECAP�Լ��ж�
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void eCAP3_Init(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR1.bit.ECAP3ENCLK = 1;  // eCAP1
    EDIS;

    InitECap3Gpio();

    ECap3Regs.ECEINT.all = 0;               // ��������eCAP�ж�
    ECap3Regs.ECCTL1.bit.CAPLDEN = 0;       // ���õȴ�
    ECap3Regs.ECCTL2.bit.TSCTRSTOP = 0;     // ֹͣ����

    ECap3Regs.TSCTR = 0;                    // �������ֵ
    ECap3Regs.CTRPHS = 0;                   // �����������λ�Ĵ���


#ifdef EC_COUNTINUOUS
    ECap3Regs.ECCTL2.all = 0x003E;      // ECAP���ƼĴ���2
    ECap3Regs.ECCTL1.all = 0x0010;      // ECAP���ƼĴ���1
#else

    ECap3Regs.ECCTL2.all = 0x003E;      // ECAP���ƼĴ���2
    ECap3Regs.ECCTL1.all = 0x0144;      // ECAP���ƼĴ���1

#endif
    //ECap1Regs.ECCTL2.all = 0x0096;      // ECAP���ƼĴ���2
    // bit 15-11    00000:  ����
    // bit 10       0:  APWMPOL����CAPģʽ��Ч
    // bit 9        0:  CAP/APWM, 0 = ����ģʽ
    // bit 8        0:  SWSYNC, 0 = �޶���
    // bit 7-6          10: SYNCO_SEL, 10 = ����ͬ���ź����
    // bit 5            0:  SYNCI_EN, 0 = ����ͬ��
    // bit 4            1:  TSCTRSTOP, 1 = ʹ�ܼ�����
    // bit 3            0:  RE-ARM, 0 = ��Ӱ��
    // bit 2-1      11: STOP_WRAP, CEVT4����ʱֹͣ
    // bit 0        0:  CONT/ONESHT, 0 = ����ģʽ

    //ECap1Regs.ECCTL1.all = 0x01C4;      // ECAP���ƼĴ���1
    // bit 15-14        00:         FREE/SOFT, 00 = TSCTR����ֹͣ
    // bit 13-9         00000:      PRESCALE, 00000 = Ԥ��Ƶϵ��Ϊ1
    // bit 8            1:  CAPLDEN, 1 = ʹ��װ�ؿ���
    // bit 7            1:  CTRRST4, 1 = �����¼�CEVT4����ʱ����λ������
    // bit 6            1:  CAP4POL, 1 = �½��ش���
    // bit 5            0:  CTRRST3, 0 = �����¼�CEVT3����ʱ������λ������
    // bit 4            0:  CAP3POL, 0 = �����ش���
    // bit 3            0:  CTRRST2, 0 = �����¼�CEVT2����ʱ������λ������
    // bit 2            1:  CAP2POL, 1 = �½��ش���
    // bit 1            0:  CTRRST1, 0 = �����¼�CEVT1����ʱ������λ������
    // bit 0            0:  CAP1POL, 0 = �����ش���


    ECap3Regs.ECEINT.all = 0x0010;      // Enable desired eCAP interrupts
    // bit 15-8     0:  ����
    // bit 7        0:  CTR=CMP, 0 = ����ƥ�� CTR=CMP�������ж�
    // bit 6        0:  CTR=PRD, 0 = ����ƥ��CTR=PRD�������ж�
    // bit 5            0:  CTROVF, 0 = �������CTROVF�������ж�
    // bit 4        0:  CEVT4, 0 = ���ò���CEVT4�¼��ж�
    // bit 3            1:  CEVT3, 1 = ʹ�ܲ���CEVT3�¼��ж�
    // bit 2            0:  CEVT2, 0 = ���ò���CEVT3�¼��ж�
    // bit 1        0:  CEVT1, 0 = ���ò���CEVT3�¼��ж�
    // bit 0            0:  ����

    EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.ECAP3_INT= &ECAP3_ISR;
    EDIS;    // This is needed to disable write to EALLOW protected registers

    // Enable CPU INT4 which is connected to ECAP1-4 INT:
    IER |= M_INT4;
    // Enable eCAP INTn in the PIE: Group 3 interrupt 1-6
    PieCtrlRegs.PIEIER4.bit.INTx3 = 1;

    // Enable global Interrupts and higher priority real-time debug events:
    EINT;   // Enable Global interrupt INTM
    ERTM;   // Enable Global realtime interrupt DBGM
}

/*******************************************************************************
* �� �� ��         : ECAP2_ISR
* ��������         : ����ռ�ձȺ���������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
interrupt void ECAP2_ISR(void)
{
    ECap2Regs.ECCLR.bit.INT = 1;                // ��� ECAP1 �жϱ�־
    ECap2Regs.ECCLR.bit.CEVT4 = 1;              // ��� CEVT4 ��־λ


#ifdef EC_COUNTINUOUS
Pulse_Count+=4;
#else
    // ����PWMռ�ձȣ������ص��½��أ�
    PWM_Duty = (int32)ECap2Regs.CAP2 - (int32)ECap2Regs.CAP1;
    // ����PWM���ڣ������ص������أ�
    PWM_Period = (int32)ECap2Regs.CAP3 - (int32)ECap2Regs.CAP1;
#endif
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP4; // PIE��4Ӧ��

}

/*******************************************************************************
* �� �� ��         : ECAP3_ISR
* ��������         : ����ռ�ձȺ���������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
interrupt void ECAP3_ISR(void)
{
    ECap3Regs.ECCLR.bit.INT = 1;                // ��� ECAP1 �жϱ�־
    ECap3Regs.ECCLR.bit.CEVT4 = 1;              // ��� CEVT4 ��־λ


#ifdef EC_COUNTINUOUS
Pulse_Count+=4;
#else
    // ����PWMռ�ձȣ������ص��½��أ�
    PWM_Duty = (int32)ECap3Regs.CAP2 - (int32)ECap3Regs.CAP1;
    // ����PWM���ڣ������ص������أ�
    PWM_Period = (int32)ECap3Regs.CAP3 - (int32)ECap3Regs.CAP1;
#endif
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP4; // PIE��4Ӧ��

}
