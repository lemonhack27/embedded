/******************************************************************************
�ļ���                     : AVP33x_CpuTimers.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33x��32λCPU��ʱ���Ĵ������壺
             CpuTimer1��CpuTimer2��Ϊʵʱ����ϵͳԤ���ġ�
                                        ����мƻ��������õ�DSP-BIOS������ʵʱ����ϵͳ���벻Ҫ����������ʱ������ע�͵�����������ʱ����
                                        �в�������ش��롣
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_CPU_TIMERS_H
#define AVP33x_CPU_TIMERS_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// CPU��ʱ���Ĵ���λ���壺
//
//
// TCR: ���ƼĴ���λ����:
struct  TCR_BITS {          // λ����
    Uint16    rsvd1:4;      // 3:0   Ԥ��
    Uint16    TSS:1;        // 4     ��ʱ����/ͣ����λ
    Uint16    TRB:1;        // 5     ��ʱ������λ
    Uint16    rsvd2:4;      // 9:6   Ԥ��
    Uint16    SOFT:1;       // 10    ����ģʽλ
    Uint16    FREE:1;       // 11
    Uint16    rsvd3:2;      // 12:13 Ԥ��
    Uint16    TIE:1;        // 14    �ж�ʹ��λ
    Uint16    TIF:1;        // 15    �жϱ�־λ
};

union TCR_REG {
    Uint16           all;
    struct TCR_BITS  bit;
};

// TPR: Ԥ��Ƶ���ͣ��Ĵ���λ����:
struct  TPR_BITS {          // λ����
    Uint16     TDDR:8;      // 7:0   ����ϵ�����ͣ�
    Uint16     PSC:8;       // 15:8  ����������ͣ�
};

union TPR_REG {
    Uint16           all;
    struct TPR_BITS  bit;
};

// TPRH: Ԥ��Ƶ���ߣ��Ĵ���λ����:
struct  TPRH_BITS {         // λ����
    Uint16     TDDRH:8;     // 7:0   ����ϵ�����ͣ�
    Uint16     PSCH:8;      // 15:8  ����������ߣ�
};

union TPRH_REG {
    Uint16           all;
    struct TPRH_BITS bit;
};

// TIM, TIMH: ��ʱ���Ĵ�������:
struct TIM_REG {
    Uint16  LSW;
    Uint16  MSW;
};

union TIM_GROUP {
    Uint32          all;
    struct TIM_REG  half;
};

// PRD, PRDH: ���ڼĴ�������:
struct PRD_REG {
    Uint16  LSW;
    Uint16  MSW;
};

union PRD_GROUP {
    Uint32          all;
    struct PRD_REG  half;
};

//---------------------------------------------------------------------------
// CPU��ʱ���Ĵ����ļ�:
//
struct CPUTIMER_REGS {
    union TIM_GROUP TIM;    // ��ʱ�������Ĵ���
    union PRD_GROUP PRD;    // ��ʱ�����ڼĴ���
    union TCR_REG   TCR;    // ��ʱ�����ƼĴ���
    Uint16          rsvd1;  // ����
    union TPR_REG   TPR;    // ��ʱ��Ԥ��Ƶ�Ĵ������ͣ�
    union TPRH_REG  TPRH;   // ��ʱ��Ԥ��Ƶ�Ĵ������ߣ�
};

//---------------------------------------------------------------------------
// CPU��ʱ����ر�����
//
struct CPUTIMER_VARS {
   volatile struct  CPUTIMER_REGS  *RegsAddr;
   Uint32    InterruptCount;
   float   CPUFreqInMHz;
   float   PeriodInUSec;
};

//---------------------------------------------------------------------------
// ����ԭ�ͺ��ⲿ����:
//
void InitCpuTimers(void);
void ConfigCpuTimer(struct CPUTIMER_VARS *Timer, float Freq, float Period);

extern volatile struct CPUTIMER_REGS CpuTimer0Regs;
extern struct CPUTIMER_VARS CpuTimer0;

// CpuTimer1��CpuTimer2��ΪDSP BIOS������ʵʱ����ϵͳԤ���ġ�����õ���DSP BIOS����ͣʵʱ
// ����ϵͳ����ע�͵�CpuTimer1��CpuTimer2��
extern volatile struct CPUTIMER_REGS CpuTimer1Regs;
extern volatile struct CPUTIMER_REGS CpuTimer2Regs;

extern struct CPUTIMER_VARS CpuTimer1;
extern struct CPUTIMER_VARS CpuTimer2;

//---------------------------------------------------------------------------
// ���õ�CPU��ʱ�������궨�壺
//
// ������ʱ��:
#define StartCpuTimer0()   CpuTimer0Regs.TCR.bit.TSS = 0

// ֹͣ��ʱ��:
#define StopCpuTimer0()   CpuTimer0Regs.TCR.bit.TSS = 1

// ���¼��ض�ʱ��������ֵ:
#define ReloadCpuTimer0() CpuTimer0Regs.TCR.bit.TRB = 1

// ����ʱ����ֵ:
#define ReadCpuTimer0Counter() CpuTimer0Regs.TIM.all

// ����ʱ��������ֵ:
#define ReadCpuTimer0Period() CpuTimer0Regs.PRD.all


// CpuTimer1��CpuTimer2��ΪDSP BIOS������ʵʱ����ϵͳԤ���ġ�����õ���DSP BIOS����ͣʵʱ����ϵͳ��
// ��ע�͵�CpuTimer1��CpuTimer2��

// ������ʱ��:
#define StartCpuTimer1()   CpuTimer1Regs.TCR.bit.TSS = 0
#define StartCpuTimer2()   CpuTimer2Regs.TCR.bit.TSS = 0

// ֹͣ��ʱ��:
#define StopCpuTimer1()   CpuTimer1Regs.TCR.bit.TSS = 1
#define StopCpuTimer2()   CpuTimer2Regs.TCR.bit.TSS = 1

// ���¼��ض�ʱ��������ֵ:
#define ReloadCpuTimer1() CpuTimer1Regs.TCR.bit.TRB = 1
#define ReloadCpuTimer2() CpuTimer2Regs.TCR.bit.TRB = 1

// ����ʱ����ֵ:
#define ReadCpuTimer1Counter() CpuTimer1Regs.TIM.all
#define ReadCpuTimer2Counter() CpuTimer2Regs.TIM.all

// ����ʱ��������ֵ:
#define ReadCpuTimer1Period() CpuTimer1Regs.PRD.all
#define ReadCpuTimer2Period() CpuTimer2Regs.PRD.all


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of AVP33x_CPU_TIMERS_H definition

//===========================================================================
// End of file.
//===========================================================================
