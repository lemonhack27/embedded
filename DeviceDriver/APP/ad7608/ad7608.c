/*
 * ad7608.c
 *
 *  Created on: 2022-3-2
 *      Author: Administrator
 */
#include "ad7608.h"

Uint32 AD_SAMPLE[7];
Uint16 SampleCount=0;

#pragma DATA_SECTION(AD_ADD,"ramdata1");
Uint32 AD_ADD[256];

/*******************************************************************************
* �� �� ��         : init_zone0
* ��������         : �ⲿ�ӿ�ģ�飨XINTF����ʼ��
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void init_zone0(void)
{
    //ʹ��XINTFʱ��
    EALLOW;
    SysCtrlRegs.PCLKCR3.bit.XINTFENCLK=1;
    EDIS;

    //����Ӧ��IO����ΪXINTF����ʹ��
    InitXintf16Gpio();

    //���������׼ʱ��ʱ��ΪXTIMCLK=SYSCLKOUT
    EALLOW;
    XintfRegs.XINTCNF2.bit.XTIMCLK=0;
    //д���������Ϊ3
    XintfRegs.XINTCNF2.bit.WRBUFF=3;
    //XCLKOUTʹ�ܣ�Ĭ�ϣ�
    XintfRegs.XINTCNF2.bit.CLKOFF=0;
    //XCLKOUT=XTIMCLK
    XintfRegs.XINTCNF2.bit.CLKMODE=0;

    //����д����ʱ���趨
    XintfRegs.XTIMING0.bit.XWRLEAD=1;//д���ʵĽ���ʱ���еȴ����ڸ����趨λ
    XintfRegs.XTIMING0.bit.XWRACTIVE=2;//д���ʵ���Чʱ���еȴ����ڸ����趨λ
    XintfRegs.XTIMING0.bit.XWRTRAIL=1;//д���ʵĸ���ʱ���еȴ����ڸ����趨λ
    //����0������ʱ���趨
    XintfRegs.XTIMING0.bit.XRDLEAD=1;//�����ʵĽ���ʱ���еȴ����ڸ����趨λ
    XintfRegs.XTIMING0.bit.XRDACTIVE=3;//�����ʵ���Чʱ���еȴ����ڸ����趨λ
    XintfRegs.XTIMING0.bit.XRDTRAIL=0;//�����ʵĸ���ʱ���еȴ����ڸ����趨λ

    //���ж�д����Ľ���ʱ�䡢��Чʱ�䡢����ʱ���Ƿ�ӱ�
    XintfRegs.XTIMING0.bit.X2TIMING=0;//���ӱ�

    //����ʹ���첽����
    XintfRegs.XTIMING0.bit.USEREADY=0;
    XintfRegs.XTIMING0.bit.READYMODE=0;

    //�������߿���趨
    XintfRegs.XTIMING0.bit.XSIZE=3;//�������߿��Ϊ16λ
    EDIS;

    //ǿ����ˮ��ˢ����ȷ���ڷ���֮ǰд�����õ����һ���Ĵ�����
    asm(" RPT #7 || NOP");
}

/*******************************************************************************
* �� �� ��         : AD7608_Init
* ��������         : ��ʼ��AD7608ʹ�õĶ˿��Լ����ж�
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void AD7608_Init(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK=1;//����GPIOʱ��

    //��������ad7608��GPIO�˿�
    //AD7608_CONVST��ת���˿�ѡ���źţ�
    GpioCtrlRegs.GPAMUX1.bit.GPIO5=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO5=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO5=0;//����

    //AD7608_RESET����λ�źţ�
    GpioCtrlRegs.GPAMUX1.bit.GPIO1=0;
    GpioCtrlRegs.GPADIR.bit.GPIO1=1;
    GpioCtrlRegs.GPAPUD.bit.GPIO1=0;

    //XZCS0��Ƭѡ�źţ�
    GpioCtrlRegs.GPBMUX1.bit.GPIO36=0;
    GpioCtrlRegs.GPBDIR.bit.GPIO36=1;
    GpioCtrlRegs.GPBPUD.bit.GPIO36=0;

    //AD7608_BUSY��BUSY�źţ�
    GpioCtrlRegs.GPAMUX2.bit.GPIO24=0;
    GpioCtrlRegs.GPADIR.bit.GPIO24=0;//����״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO24=0;

    //AD7608_RANGE
    GpioCtrlRegs.GPAMUX1.bit.GPIO2=0;
    GpioCtrlRegs.GPADIR.bit.GPIO2=1;
    GpioCtrlRegs.GPAPUD.bit.GPIO2=0;

    //AD7608_OS0
    GpioCtrlRegs.GPAMUX1.bit.GPIO4=0;
    GpioCtrlRegs.GPADIR.bit.GPIO4=1;
    GpioCtrlRegs.GPAPUD.bit.GPIO4=0;

    //AD7608_OS1
    GpioCtrlRegs.GPAMUX1.bit.GPIO5=0;
    GpioCtrlRegs.GPADIR.bit.GPIO5=1;
    GpioCtrlRegs.GPAPUD.bit.GPIO5=0;

    //AD7608_OS2
    GpioCtrlRegs.GPAMUX1.bit.GPIO6=0;
    GpioCtrlRegs.GPADIR.bit.GPIO6=1;
    GpioCtrlRegs.GPAPUD.bit.GPIO6=0;

    //XRDN����ȡ�źţ�.........���ź���AD��������������DSP���š�
    EDIS;


    init_zone0();

    EALLOW;
    GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 24;   // XINT1��GPIO24
    EDIS;

    EALLOW;
    PieVectTable.XINT1=&XINT1_ISR1;
    EDIS;

    PieCtrlRegs.PIEIER1.bit.INTx4 = 1;          // ʹ��PIE��1��INT4

    XIntruptRegs.XINT1CR.bit.POLARITY = 0;      // �½��ش����ж�
    XIntruptRegs.XINT1CR.bit.ENABLE= 1;        // ʹ��XINT1

    IER |= M_INT1;                              // ʹ��CPU�ж�1��INT1��
    EINT;                                       // ��ȫ���ж�
    ERTM;

    AD7608Initialization();

}


/*******************************************************************************
* �� �� ��         : AD7608Initialization
* ��������         : ��ʼ��AD7608оƬ��ʱ���Լ���ʼ״̬
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void AD7608Initialization(void)
{
    GpioDataRegs.GPASET.bit.GPIO2=1;//+_10v��Χ

    GpioDataRegs.GPACLEAR.bit.GPIO4=1;//��ֹ������
    GpioDataRegs.GPACLEAR.bit.GPIO5=1;
    GpioDataRegs.GPACLEAR.bit.GPIO6=1;

    DELAY_US(1000);
    GpioDataRegs.GPACLEAR.bit.GPIO1=1;//reset
    GpioDataRegs.GPBSET.bit.GPIO36=1;//cs
    GpioDataRegs.GPASET.bit.GPIO5=1;//convst
    //GpioDataRegs   RD
    DELAY_US(1000);

    AD7608Reset();

}

/*******************************************************************************
* �� �� ��         : AD7608Reset
* ��������         : ��λ����
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void AD7608Reset(void)
{
    GpioDataRegs.GPASET.bit.GPIO1=1;//reset
    DELAY_US(1);
    GpioDataRegs.GPACLEAR.bit.GPIO1=1;
    DELAY_US(1);
}

/*******************************************************************************
* �� �� ��         : AD7608OneSample
* ��������         : ��ʼ����
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
//void AD7608OneSample(void)
//{
//
////    unsigned char Busy;
//
//    GpioDataRegs.GPACLEAR.bit.GPIO5=1;//convst
//    DELAY_US(1);
//    GpioDataRegs.GPASET.bit.GPIO5=1;
//    DELAY_US(1);
//
////    Busy=GpioDataRegs.GPADAT.bit.GPIO24;
///*
//    while(Busy==1)
//    {
//        DELAY_US(1);
//        Busy=GpioDataRegs.GPADAT.bit.GPIO24;
//    }
//*/
//
//}

/*******************************************************************************
* �� �� ��         : XINT1_ISR1
* ��������         : �жϺ��������ȡ����
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
interrupt void XINT1_ISR1(void)
{

    Uint16 i,j;
    Uint16 addat[BUF_SIZE*2];
//    ADC_TMP=ADC_ADD & 0x4FFF;

    GpioDataRegs.GPBCLEAR.bit.GPIO36=1;//cs


    for(i=0;i<BUF_SIZE*2;i+=2)
    {
        //GpioDataRegs  RD����
        //ADC_TMP=ADC_ADD & 0xFFFF;
        addat[i]=*(AD_ASTART);//17-2
        addat[i+1]=*(AD_ASTART);//1-0
    }

    GpioDataRegs.GPBSET.bit.GPIO36=1;//cs


    for(i=0;i<BUF_SIZE;i++)
    {
        AD_SAMPLE[i]=addat[2*i];
        AD_SAMPLE[i]=AD_SAMPLE[i] << 2;
        AD_SAMPLE[i]+=addat[2*i+1];
    }



    for(i=SampleCount*BUF_SIZE,j=0;i<8+SampleCount*BUF_SIZE;i++,j++)
    {
        AD_ADD[i]=AD_SAMPLE[j];

    }

    SampleCount++;

    if(SampleCount==32)
    {
        SampleCount=0;
        //dsp_filter();
    }

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    EINT;
}
