/******************************************************************************
�ļ���                     : AVP33x_DefaultIsr.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xоƬĬ�ϵ��жϷ������
                                       ���ļ�����AVP33x��PIE��������ں��жϷ������ͨ������Щ�ں��жϷ�������������оƬ�����ڼ�
                                       �������PIE�����������Ļ�������ڹ̼������ڼ�������жϣ���ʼ�����жϷ����������Ӧ��
                                       ���ſ��������Ľ��У��û����Խ��Լ����жϷ���������滻��ЩĬ�ϵ��жϷ�����򡣲��ң���Щ�жϷ����
                                       ���ж�������ѭ�����룬��Ҳ��Ӧ�ð��������յĹ��̴����С�
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#include "AVP33x_Device.h"     // AVP33x Headerfile Include File
#include "AVP33x_Examples.h"   // AVP33x Examples Include File

//---------------------------------------------------------------------------
// INT13_ISR:CPU��INT13�жϷ������
//
interrupt void INT13_ISR(void)      // INT13��CPU-Timer1
{
    // ����Լ��Ĵ���

    // �����������е��Խ������ڴ˴�ֹͣ����������ISR������Ƴ�
    asm ("      ESTOP0");
    for(;;);
}

//---------------------------------------------------------------------------
// INT13_ISR:CPU��INT14�жϷ������
//
interrupt void INT14_ISR(void)      // CPU-Timer2
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void DATALOG_ISR(void)    // ���ݼ�¼�ж�
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void RTOSINT_ISR(void)    // ʵʱ����ϵͳ�ж�
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void EMUINT_ISR(void)     // �����ж�
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void NMI_ISR(void)        // ���������ж�
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void ILLEGAL_ISR(void)    // �Ƿ���������
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm("          ESTOP0");
    for(;;);

}

interrupt void USER1_ISR(void)      // �û���������1
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER2_ISR(void)      // �û���������2
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER3_ISR(void)      // �û���������3
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER4_ISR(void)      // �û���������4
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER5_ISR(void)      // �û���������5
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER6_ISR(void)      // �û���������6
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER7_ISR(void)      // �û���������7
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER8_ISR(void)      // �û���������8
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER9_ISR(void)      // �û���������9
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER10_ISR(void)     // �û���������10
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER11_ISR(void)     // �û���������11
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

interrupt void USER12_ISR(void)     // �û���������12
{
    // ����Լ��Ĵ���

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// -----------------------------------------------------------
// ��1��PIE�ж� - ӳ�䵽CPU��INT1
// -----------------------------------------------------------

// INT1.1
interrupt void SEQ1INT_ISR(void)    // ADC������1(SEQ1)
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group1;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT1.2
interrupt void SEQ2INT_ISR(void)    // ADC������2(SEQ2)
{
  // ����Լ��Ĵ���

  // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group1;

  // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
  asm("	  ESTOP0");
  for(;;);
}
// INT1.3 - Ԥ��

// INT1.4
interrupt void  XINT1_ISR(void)     // �ⲿ�ж�1���ⲿ�ж�1��
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group1;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT1.5
interrupt void  XINT2_ISR(void)     // �ⲿ�ж�1���ⲿ�ж�2��
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group1;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT1.6
interrupt void  ADCINT_ISR(void)    // ADC�ж�
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group1;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT1.7
interrupt void  TINT0_ISR(void)     // CPU-Timer 0
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group1;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���

    asm ("      ESTOP0");
    for(;;);
}

// INT1.8
interrupt void  WAKEINT_ISR(void)   // ���Ź��ж�
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group1;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}


// -----------------------------------------------------------
// ��2��PIE�ж� - ӳ�䵽CPU��INT2
// -----------------------------------------------------------

// INT2.1
interrupt void EPWM1_TZINT_ISR(void)    // EPWM-1�ж�
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group2;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT2.2
interrupt void EPWM2_TZINT_ISR(void)    // EPWM-2
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group2;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT2.3
interrupt void EPWM3_TZINT_ISR(void)    // EPWM-3
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group2;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}


// INT2.4
interrupt void EPWM4_TZINT_ISR(void)    // EPWM-4
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group2;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT2.5
interrupt void EPWM5_TZINT_ISR(void)    // EPWM-5
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group2;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT2.6
interrupt void EPWM6_TZINT_ISR(void)   // EPWM-6
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group2;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT2.7 - Ԥ��
// INT2.8 - Ԥ��


// -----------------------------------------------------------
// ��3��PIE�ж� - ӳ�䵽CPU��INT3
// -----------------------------------------------------------

// INT 3.1
interrupt void EPWM1_INT_ISR(void)      // EPWM-1
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group3;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT3.2
interrupt void EPWM2_INT_ISR(void)      // EPWM-2
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group3;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT3.3
interrupt void EPWM3_INT_ISR(void)      // EPWM-3
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group3;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT3.4
interrupt void EPWM4_INT_ISR(void)      // EPWM-4
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group3;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT3.5
interrupt void EPWM5_INT_ISR(void)      // EPWM-5
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group3;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT3.6
interrupt void EPWM6_INT_ISR(void)    // EPWM-6
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group3;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT3.7 - Ԥ��
// INT3.8 - Ԥ��


// -----------------------------------------------------------
// ��4��PIE�ж� - ӳ�䵽CPU��INT4
// -----------------------------------------------------------

// INT 4.1
interrupt void ECAP1_INT_ISR(void)      // ECAP-1
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group4;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT4.2
interrupt void ECAP2_INT_ISR(void)      // ECAP-2
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group4;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT4.3
interrupt void ECAP3_INT_ISR(void)      // ECAP-3
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group4;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT4.4
interrupt void ECAP4_INT_ISR(void)      // ECAP-4
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group4;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT4.5
interrupt void ECAP5_INT_ISR(void)      // ECAP-5
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group4;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}
// INT4.6
interrupt void ECAP6_INT_ISR(void)      // ECAP-6
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group4;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}
// INT4.7 - Ԥ��
// INT4.8 - Ԥ��


// -----------------------------------------------------------
// ��5��PIE�ж� - ӳ�䵽CPU��INT5
// -----------------------------------------------------------

// INT 5.1
interrupt void EQEP1_INT_ISR(void)      // EQEP-1
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group5;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT5.2
interrupt void EQEP2_INT_ISR(void)      // EQEP-2
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group5;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT5.3 - Ԥ��
// INT5.4 - Ԥ��
// INT5.5 - Ԥ��
// INT5.6 - Ԥ��
// INT5.7 - Ԥ��
// INT5.8 - Ԥ��


// -----------------------------------------------------------
// ��6��PIE�ж� - ӳ�䵽CPU��INT6
// -----------------------------------------------------------

// INT6.1
interrupt void SPIRXINTA_ISR(void)      // SPI-A
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group6;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT6.2
interrupt void SPITXINTA_ISR(void)     // SPI-A
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group6;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT6.3
interrupt void MRINTB_ISR(void)         // McBSP-B
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group6;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT6.4
interrupt void MXINTB_ISR(void)         // McBSP-B
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group6;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT6.5
interrupt void MRINTA_ISR(void)         // McBSP-A
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group6;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT6.6
interrupt void MXINTA_ISR(void)         // McBSP-A
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group6;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT6.7 - Ԥ��
// INT6.8 - Ԥ��


// -----------------------------------------------------------
// ��7��PIE�ж� - ӳ�䵽CPU��INT7
// -----------------------------------------------------------

// INT7.1
interrupt void DINTCH1_ISR(void)        // DMA
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group7;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT7.2
interrupt void DINTCH2_ISR(void)        // DMA
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group7;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT7.3
interrupt void DINTCH3_ISR(void)        // DMA
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group7;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT7.4
interrupt void DINTCH4_ISR(void)        // DMA
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group7;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT7.5
interrupt void DINTCH5_ISR(void)        // DMA
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group7;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT7.6
interrupt void DINTCH6_ISR(void)        // DMA
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group7;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT7.7 - Ԥ��
// INT7.8 - Ԥ��


// -----------------------------------------------------------
// ��8��PIE�ж� - ӳ�䵽CPU��INT8
// -----------------------------------------------------------

// INT8.1
interrupt void I2CINT1A_ISR(void)       // I2C-A
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group8;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT8.2
interrupt void I2CINT2A_ISR(void)       // I2C-A
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group8;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT8.3 - Ԥ��
// INT8.4 - Ԥ��

// INT8.5
interrupt void SCIRXINTC_ISR(void)      // SCI-C
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group8;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT8.6
interrupt void SCITXINTC_ISR(void)     // SCI-C
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group8;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT8.7 - Ԥ��
// INT8.8 - Ԥ��


// -----------------------------------------------------------
// ��9��PIE�ж� - ӳ�䵽CPU��INT9
// -----------------------------------------------------------

// INT9.1
interrupt void SCIRXINTA_ISR(void)      // SCI-A
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group9;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT9.2
interrupt void SCITXINTA_ISR(void)      // SCI-A
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group9;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT9.3
interrupt void SCIRXINTB_ISR(void)      // SCI-B
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group9;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT9.4
interrupt void SCITXINTB_ISR(void)      // SCI-B
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group9;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT9.5
interrupt void ECAN0INTA_ISR(void)      // eCAN-A
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group9;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT9.6
interrupt void ECAN1INTA_ISR(void)      // eCAN-A
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group9;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT9.7
interrupt void ECAN0INTB_ISR(void)      // eCAN-B
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group9;


    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT9.8
interrupt void ECAN1INTB_ISR(void)      // eCAN-B
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group9;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}


// -----------------------------------------------------------
// ��10��PIE�ж� - ӳ�䵽CPU��INT10
// -----------------------------------------------------------

// INT10.1 - Ԥ��
// INT10.2 - Ԥ��
// INT10.3 - Ԥ��
// INT10.4 - Ԥ��
// INT10.5 - Ԥ��
// INT10.6 - Ԥ��
// INT10.7 - Ԥ��
// INT10.8 - Ԥ��


// -----------------------------------------------------------
// ��11��PIE�ж� - ӳ�䵽CPU��INT11
// -----------------------------------------------------------

// INT11.1 - Ԥ��
// INT11.2 - Ԥ��
// INT11.3 - Ԥ��
// INT11.4 - Ԥ��
// INT11.5 - Ԥ��
// INT11.6 - Ԥ��
// INT11.7 - Ԥ��
// INT11.8 - Ԥ��


// -----------------------------------------------------------
// ��12��PIE�ж� - ӳ�䵽CPU��INT12
// -----------------------------------------------------------

// INT12.1
interrupt void XINT3_ISR(void)      // �ⲿ�ж�XINT3
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group12;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT12.2
interrupt void XINT4_ISR(void)      // �ⲿ�ж�XINT4
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group12;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT12.3
interrupt void XINT5_ISR(void)      // �ⲿ�ж�XINT5
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group12;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}
// INT12.4
interrupt void XINT6_ISR(void)      // �ⲿ�ж�XINT6
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group12;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT12.5
interrupt void XINT7_ISR(void)      // �ⲿ�ж�XINT7
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group12;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

// INT12.6 - Reserved
// INT12.7
interrupt void LVF_ISR(void)        // ��������ж�
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group12;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}
// INT12.8
interrupt void LUF_ISR(void)        // ���������ж�
{
    // ����Լ��Ĵ���

    // Ҫ�ӱ�PIE����ո����жϣ���ȷ�ϴ���PIE�жϵ�piectrlegs.pieak.all=pieak_group12;

    // ��������е��Դ��������ֹͣ�������������жϷ��������Ƴ����Ƴ���
    asm ("      ESTOP0");
    for(;;);
}

//---------------------------------------------------------------------------
// ����Ĭ���ж�:
//
interrupt void PIE_RESERVED(void)       // Ԥ���ռ䣬������
{
  asm ("      ESTOP0");
  for(;;);
}

interrupt void rsvd_ISR(void)           // ������
{
  asm ("      ESTOP0");
  for(;;);
}

//===========================================================================
// End of file.
//===========================================================================
