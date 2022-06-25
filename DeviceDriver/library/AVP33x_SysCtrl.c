/******************************************************************************
�ļ���                     : AVP33x_SysCtrl.c
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : ϵͳ��ʼ��
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#include "AVP33x_Device.h"     // Headerfile Include File
#include "AVP33x_Examples.h"   // Examples Include File

// ��flash��ʼ���������RAM����
#pragma CODE_SECTION(InitFlash, "ramfuncs");
// ��PLL��ʼ���������RAM����
#pragma CODE_SECTION(InitPll, "ramfuncs");

//---------------------------------------------------------------------------
// InitSysCtrl:
//---------------------------------------------------------------------------
// ϵͳ��ʼ��������
// - ��ֹ���Ź�
// - ����PLL
// - ���ø�������ʼ�պ͵�������ʼ��
// - ʹ������ʱ��
void InitSysCtrl(void)
{
    // ��ֹ���Ź�
    DisableDog();

    // ��ʼ��PLL
    InitPll(DSP28_PLLCR,DSP28_DIVSEL);  // �ⲿʱ��30MHz��30MHz*10/2 = 150MHz

    // ��ʼ������ʱ��
    InitPeripheralClocks();
}

//---------------------------------------------------------------------------
// InitFlash:
//---------------------------------------------------------------------------
// flash��ʼ����������flash�ļĴ�������Ϊһ���̶���״̬��
// ע�⣡������������RAM�����У������������ϲ����Ľ����
void InitFlash(void)
{
    EALLOW;

    // ʹ��flash�Ĺܵ�ģʽ���ɸ��ƴ�����flash�����е�Ч����
    FlashRegs.FOPT.bit.ENPIPE = 1;

    // ����flash���е���С�ȴ�״̬����ο����µ������ֲᡣ
#if CPU_FRQ_150MHZ

    FlashRegs.FBANKWAIT.bit.PAGEWAIT = 5;   // ����ҳ�ȴ�
    FlashRegs.FBANKWAIT.bit.RANDWAIT = 5;   // ����������ʵȴ�
    FlashRegs.FOTPWAIT.bit.OTPWAIT = 8;     // ����OTP�ȴ�

#endif

#if CPU_FRQ_120MHZ

    FlashRegs.FBANKWAIT.bit.PAGEWAIT = 3;   // ����ҳ�ȴ�
    FlashRegs.FBANKWAIT.bit.RANDWAIT = 3;   // ����������ʵȴ�
    FlashRegs.FOTPWAIT.bit.OTPWAIT = 5;     // ����OTP�ȴ�

#endif

    FlashRegs.FSTDBYWAIT.bit.STDBYWAIT = 0x01FF;     // Ĭ�����ã��������
    FlashRegs.FACTIVEWAIT.bit.ACTIVEWAIT = 0x01FF;   // Ĭ�����ã��������

    EDIS;

    asm(" RPT #7 || NOP");                  // �ȴ���ȷ���������ò���д�ɹ�
}

//---------------------------------------------------------------------------
// ServiceDog:
//---------------------------------------------------------------------------
// ���Ź�ι��������
void ServiceDog(void)
{
    EALLOW;
    SysCtrlRegs.WDKEY = 0x0055;
    SysCtrlRegs.WDKEY = 0x00AA;
    EDIS;
}

//---------------------------------------------------------------------------
// DisableDog:
//---------------------------------------------------------------------------
// ��ֹ���Ź�������
void DisableDog(void)
{
    EALLOW;
    SysCtrlRegs.WDCR= 0x0068;
    EDIS;
}

//---------------------------------------------------------------------------
// InitPll:
//---------------------------------------------------------------------------
// ��ʼ��PLL����
void InitPll(Uint16 val, Uint16 divsel)
{

    if (SysCtrlRegs.PLLSTS.bit.MCLKSTS != 0)
    {
        asm("        ESTOP0");
    }

    // ��������PLLCR�Ĵ���֮ǰҪȷ��DIVSELλΪ0
    if (SysCtrlRegs.PLLSTS.bit.DIVSEL != 0)
    {
        EALLOW;
        SysCtrlRegs.PLLSTS.bit.DIVSEL = 0;
        EDIS;
    }

    // ����PLLCR
    if (SysCtrlRegs.PLLCR.bit.DIV != val)
    {
        EALLOW;
        SysCtrlRegs.PLLSTS.bit.MCLKOFF = 1;
        SysCtrlRegs.PLLCR.bit.DIV = val;
        EDIS;

        DisableDog();

        while(SysCtrlRegs.PLLSTS.bit.PLLLOCKS != 1)
        {
            // ������Ź���ʹ�ܣ���Ҫ����������ι�����
            // ServiceDog();
        }

        EALLOW;
        SysCtrlRegs.PLLSTS.bit.MCLKOFF = 0;
        EDIS;
    }

    // ���÷�Ƶϵ��Ϊ1��2
    if((divsel == 1)||(divsel == 2))
    {
        EALLOW;
        SysCtrlRegs.PLLSTS.bit.DIVSEL = divsel;
        EDIS;
    }

    // ���÷�Ƶϵ��Ϊ3����Ҫ������Ϊ2��Ƶ��Ȼ��ȴ���ѹ����������������Ϊ3��Ƶ��
    if(divsel == 3)
    {
        EALLOW;
        SysCtrlRegs.PLLSTS.bit.DIVSEL = 2;
        DELAY_US(50L);
        SysCtrlRegs.PLLSTS.bit.DIVSEL = 3;
        EDIS;
    }
}

//--------------------------------------------------------------------------
// InitPeripheralClocks:
//---------------------------------------------------------------------------
// ��ʼ������ʱ�Ӻ�����
// ���ȣ����ø��ٺ͵�������ʱ�ӵ�Ԥ��Ƶϵ����
// Ȼ��ʹ��Ҫ�õ�������ʱ�ӡ���Ϊ�˽��͹��ģ�û�õ������轨�齫������ʱ�ӹص���
// ��Ҫע����ǣ�����ĸ�����ʱ��δʹ�ܣ�����Ӧ������Ĵ������޷���д�ġ�
void InitPeripheralClocks(void)
{
    EALLOW;

    // ��/��������ʱ��Ԥ��Ƶϵ�����ã�һ�㽨����Ϊ����Ĭ��ֵ
    SysCtrlRegs.HISPCP.all = 0x0001;
    SysCtrlRegs.LOSPCP.all = 0x0002;

    // ����XINTF����ʱ��
    XintfRegs.XINTCNF2.bit.XTIMCLK = 1;         // ����ʱ�ӣ�XTIMCLK = SYSCLKOUT/2
    XintfRegs.XINTCNF2.bit.CLKMODE = 1;         // ʱ�������XCLKOUT = XTIMCLK/2
    XintfRegs.XINTCNF2.bit.CLKOFF = 0;          // ��ֹ����ʱ�����


    // This function is not written to be an example of efficient code.

    SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;       // ADC

	// ADCУ׼(���ڲ�Ʒ�������⣬�˴��������������������ԭ����ADC_cal()����)
	AdcRegs.ADCREFSEL.all = *(Uint16 *)0x380083;  // load gain
	AdcRegs.ADCOFFTRIM.all = *(Uint16 *)0x380085; // load offset


    SysCtrlRegs.PCLKCR0.bit.I2CAENCLK = 1;      // I2C
    SysCtrlRegs.PCLKCR0.bit.SCIAENCLK = 1;      // SCI-A
    SysCtrlRegs.PCLKCR0.bit.SCIBENCLK = 1;      // SCI-B
    SysCtrlRegs.PCLKCR0.bit.SCICENCLK = 1;      // SCI-C
    SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 1;      // SPI-A
    SysCtrlRegs.PCLKCR0.bit.MCBSPAENCLK = 1;    // McBSP-A
    SysCtrlRegs.PCLKCR0.bit.MCBSPBENCLK = 1;    // McBSP-B
    SysCtrlRegs.PCLKCR0.bit.ECANAENCLK=1;       // eCAN-A
    SysCtrlRegs.PCLKCR0.bit.ECANBENCLK=1;       // eCAN-B

    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;      // Disable TBCLK within the ePWM
    SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 1;     // ePWM1
    SysCtrlRegs.PCLKCR1.bit.EPWM2ENCLK = 1;     // ePWM2
    SysCtrlRegs.PCLKCR1.bit.EPWM3ENCLK = 1;     // ePWM3
    SysCtrlRegs.PCLKCR1.bit.EPWM4ENCLK = 1;     // ePWM4
    SysCtrlRegs.PCLKCR1.bit.EPWM5ENCLK = 1;     // ePWM5
    SysCtrlRegs.PCLKCR1.bit.EPWM6ENCLK = 1;     // ePWM6
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;      // Enable TBCLK within the ePWM

    SysCtrlRegs.PCLKCR1.bit.ECAP3ENCLK = 1;     // eCAP3
    SysCtrlRegs.PCLKCR1.bit.ECAP4ENCLK = 1;     // eCAP4
    SysCtrlRegs.PCLKCR1.bit.ECAP5ENCLK = 1;     // eCAP5
    SysCtrlRegs.PCLKCR1.bit.ECAP6ENCLK = 1;     // eCAP6
    SysCtrlRegs.PCLKCR1.bit.ECAP1ENCLK = 1;     // eCAP1
    SysCtrlRegs.PCLKCR1.bit.ECAP2ENCLK = 1;     // eCAP2
    SysCtrlRegs.PCLKCR1.bit.EQEP1ENCLK = 1;     // eQEP1
    SysCtrlRegs.PCLKCR1.bit.EQEP2ENCLK = 1;     // eQEP2

    SysCtrlRegs.PCLKCR3.bit.CPUTIMER0ENCLK = 1; // CPU Timer 0
    SysCtrlRegs.PCLKCR3.bit.CPUTIMER1ENCLK = 1; // CPU Timer 1
    SysCtrlRegs.PCLKCR3.bit.CPUTIMER2ENCLK = 1; // CPU Timer 2

    SysCtrlRegs.PCLKCR3.bit.DMAENCLK = 1;       // DMA Clock
    SysCtrlRegs.PCLKCR3.bit.XINTFENCLK = 1;     // XTIMCLK
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;    // GPIO input clock

    EDIS;
}

//---------------------------------------------------------------------------
// CsmUnlock:
//---------------------------------------------------------------------------
// ��������������û����뽫�����õ������滻���е�0xFFFF�� �����ɹ�����1.
#define STATUS_FAIL          0
#define STATUS_SUCCESS       1

Uint16 CsmUnlock()
{
    volatile Uint16 temp;

    // �û����Ժ���õ������������мĴ����?
    EALLOW;
    CsmRegs.KEY0 = 0xFFFF;
    CsmRegs.KEY1 = 0xFFFF;
    CsmRegs.KEY2 = 0xFFFF;
    CsmRegs.KEY3 = 0xFFFF;
    CsmRegs.KEY4 = 0xFFFF;
    CsmRegs.KEY5 = 0xFFFF;
    CsmRegs.KEY6 = 0xFFFF;
    CsmRegs.KEY7 = 0xFFFF;
    EDIS;

    // �Լ���������������ȡ�����ƥ��������ɹ?
    temp = CsmPwl.PSWD0;
    temp = CsmPwl.PSWD1;
    temp = CsmPwl.PSWD2;
    temp = CsmPwl.PSWD3;
    temp = CsmPwl.PSWD4;
    temp = CsmPwl.PSWD5;
    temp = CsmPwl.PSWD6;
    temp = CsmPwl.PSWD7;

    if (CsmRegs.CSMSCR.bit.SECURE == 0)
        return STATUS_SUCCESS;
    else
        return STATUS_FAIL;
}

//===========================================================================
// End of file.
//===========================================================================
