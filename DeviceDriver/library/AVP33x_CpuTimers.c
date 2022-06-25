/******************************************************************************
�ļ���                     : AVP33x_CpuTimers.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xоƬ32λCPU��ʱ��ģ���ʼ������������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#include "AVP33x_Device.h"     // Headerfile Include File
#include "AVP33x_Examples.h"   // Examples Include File

struct CPUTIMER_VARS CpuTimer0;

// ����õ�BIOS������ʵʱ����ϵͳ����ע�������������
struct CPUTIMER_VARS CpuTimer1;
struct CPUTIMER_VARS CpuTimer2;

//---------------------------------------------------------------------------
// InitCpuTimers:
//---------------------------------------------------------------------------
// ��ʼ��CPU��ʱ���Ĵ�������
//
void InitCpuTimers(void)
{

    /* CPU��ʱ��0��ʼ��*/

    CpuTimer0.RegsAddr = &CpuTimer0Regs;    // ��ʼ����ַָ��ָ����Ӧ�Ķ�ʱ���Ĵ���
    CpuTimer0Regs.PRD.all  = 0xFFFFFFFF;    // ��ʼ����ʱ�����ڼĴ���Ϊ���ֵ
    CpuTimer0Regs.TPR.all  = 0;             // ��ʼ��Ԥ��Ƶϵ��Ϊ1�����͵���ϵͳʱ��
    CpuTimer0Regs.TPRH.all = 0;
    CpuTimer0Regs.TCR.bit.TSS = 1;          // ֹͣCPU��ʱ��0
    CpuTimer0Regs.TCR.bit.TRB = 1;          // �����ڼĴ�����ֵ�������붨ʱ���Ĵ�����TIMH:TIM��PSCH:PSC��
    CpuTimer0.InterruptCount = 0;           // ��λ�жϼ�����


    /* CPU��ʱ��1��CPU��ʱ��2��ʼ����CPU��ʱ��1��CPU��ʱ��2��ΪBIOS������ʵʱ����ϵͳԤ���ģ�������ⷽ������벻Ҫ�������ʱ����*/

    CpuTimer1.RegsAddr = &CpuTimer1Regs;    // ��ʼ����ַָ��ָ����Ӧ�Ķ�ʱ���Ĵ���
    CpuTimer2.RegsAddr = &CpuTimer2Regs;
    CpuTimer1Regs.PRD.all  = 0xFFFFFFFF;    // ��ʼ����ʱ�����ڼĴ���Ϊ���ֵ
    CpuTimer2Regs.PRD.all  = 0xFFFFFFFF;
    CpuTimer1Regs.TCR.bit.TSS = 1;          // ֹͣCPU��ʱ��0
    CpuTimer2Regs.TCR.bit.TSS = 1;
    CpuTimer1Regs.TCR.bit.TRB = 1;          // �����ڼĴ�����ֵ�������붨ʱ���Ĵ�����TIMH:TIM��PSCH:PSC��
    CpuTimer2Regs.TCR.bit.TRB = 1;
    CpuTimer1.InterruptCount = 0;           // ��λ�жϼ�����
    CpuTimer2.InterruptCount = 0;
}

//---------------------------------------------------------------------------
// ConfigCpuTimer:
//---------------------------------------------------------------------------
// ��ʱ�����ú�����
// �����������"Freq"��"Period"��ʼ����ѡ�õĶ�ʱ����"Freq"�ĵ�λ��MHz��"Period"�ĵ�λ��us������
// �������ú󣬶�ʱ������ֹͣ״̬����Ҫ����������ʱ�����ܿ�ʼ��ʱ���ܡ�
//
void ConfigCpuTimer(struct CPUTIMER_VARS *Timer, float Freq, float Period)
{
    Uint32  temp;

    // ��ʼ����ʱ����
    Timer->CPUFreqInMHz = Freq;
    Timer->PeriodInUSec = Period;
    temp = (long) (Freq * Period);
    Timer->RegsAddr->PRD.all = temp;

    // ����Ԥ��Ƶϵ��Ϊ1������ʱʱ��=ϵͳʱ��
    Timer->RegsAddr->TPR.all  = 0;
    Timer->RegsAddr->TPRH.all  = 0;

    // ��ʼ����ʱ�����ƼĴ���
    Timer->RegsAddr->TCR.bit.TSS = 1;   // 0������������1��ֹͣ����
    Timer->RegsAddr->TCR.bit.TRB = 1;   // ���ض�ʱ��
    Timer->RegsAddr->TCR.bit.SOFT = 1;
    Timer->RegsAddr->TCR.bit.FREE = 1;  // �������λ�ڼ�������0ʱֹͣ
    Timer->RegsAddr->TCR.bit.TIE = 1;   // ��ʱ���ж�ʹ�ܿ���λ��0����ֹ��1��ʹ�ܣ�

    // ��λ�жϼ�����
    Timer->InterruptCount = 0;
}

//===========================================================================
// End of file.
//===========================================================================
