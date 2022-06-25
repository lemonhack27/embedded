/*
 * ad7608.c
 *
 *  Created on: 2022-3-2
 *      Author: Administrator
 */
#include "ad7608v2.h"


//#pragma DATA_SECTION(AD_ADD,"ramdata1");
long AD_ADD0[64],AD_ADD1[64],AD_ADD2[64],AD_ADD3[64],AD_ADD4[64],AD_ADD5[64],AD_ADD6[64],AD_ADD7[64];

float32 AD_RES[256];

int ad[16];
Uint16 sampleCount=0;
//Uint16 testSample1[256],testSample2[256],testSample3[256],//6��������AD����
//       testSample4[256],testSample5[256],testSample6[256];
//int i;
interrupt void ISRTimer0(void);

//static int j = 0;

/*******************************************************************************
* �� �� ��         : init_zone0
* ��������         : �ⲿ�ӿ�ģ�飨XINTF����ʼ��
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
//void init_zone0(void)
//{
//    //ʹ��XINTFʱ��
//    EALLOW;
//    SysCtrlRegs.PCLKCR3.bit.XINTFENCLK=1;
//    EDIS;
//
//    //����Ӧ��IO����ΪXINTF����ʹ��
//    InitXintf16Gpio();
//
//    //���������׼ʱ��ʱ��ΪXTIMCLK=SYSCLKOUT
//    EALLOW;
//    XintfRegs.XINTCNF2.bit.XTIMCLK=0;
//    //д���������Ϊ3
//    XintfRegs.XINTCNF2.bit.WRBUFF=3;
//    //XCLKOUTʹ�ܣ�Ĭ�ϣ�
//    XintfRegs.XINTCNF2.bit.CLKOFF=0;
//    //XCLKOUT=XTIMCLK
//    XintfRegs.XINTCNF2.bit.CLKMODE=0;
//
//    //����д����ʱ���趨
//    XintfRegs.XTIMING0.bit.XWRLEAD=1;//д���ʵĽ���ʱ���еȴ����ڸ����趨λ
//    XintfRegs.XTIMING0.bit.XWRACTIVE=2;//д���ʵ���Чʱ���еȴ����ڸ����趨λ
//    XintfRegs.XTIMING0.bit.XWRTRAIL=1;//д���ʵĸ���ʱ���еȴ����ڸ����趨λ
//    //����0������ʱ���趨
//    XintfRegs.XTIMING0.bit.XRDLEAD=1;//�����ʵĽ���ʱ���еȴ����ڸ����趨λ
//    XintfRegs.XTIMING0.bit.XRDACTIVE=3;//�����ʵ���Чʱ���еȴ����ڸ����趨λ
//    XintfRegs.XTIMING0.bit.XRDTRAIL=0;//�����ʵĸ���ʱ���еȴ����ڸ����趨λ
//
//    //���ж�д����Ľ���ʱ�䡢��Чʱ�䡢����ʱ���Ƿ�ӱ�
//    XintfRegs.XTIMING0.bit.X2TIMING=0;//���ӱ�
//
//    //����ʹ���첽����
//    XintfRegs.XTIMING0.bit.USEREADY=0;
//    XintfRegs.XTIMING0.bit.READYMODE=0;
//
//    //�������߿���趨
//    XintfRegs.XTIMING0.bit.XSIZE=3;//�������߿��Ϊ16λ
//    EDIS;
//
//    //ǿ����ˮ��ˢ����ȷ���ڷ���֮ǰд�����õ����һ���Ĵ�����
//    asm(" RPT #7 || NOP");
//}

/*******************************************************************************
* �� �� ��         : AD7608_Init
* ��������         : ��ʼ��AD7608ʹ�õĶ˿��Լ����ж�
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void AD7608_Init(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR3.bit.XINTFENCLK = 1;
    EDIS;
    InitXintf();
    InitXintf16Gpio();

    EALLOW;
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK=1;//����GPIOʱ��

    //��������ad7608��GPIO�˿�
    //AD7608_CONVST��ת���˿�ѡ���źţ�
    GpioCtrlRegs.GPAMUX1.bit.GPIO0=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO0=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO0=0;//����

    //AD7608_RESET����λ�źţ�
    GpioCtrlRegs.GPAMUX1.bit.GPIO1=0;
    GpioCtrlRegs.GPADIR.bit.GPIO1=1;
    GpioCtrlRegs.GPAPUD.bit.GPIO1=0;

//    //XZCS0��Ƭѡ�źţ�
//    GpioCtrlRegs.GPBMUX1.bit.GPIO36=0;
//    GpioCtrlRegs.GPBDIR.bit.GPIO36=1;
//    GpioCtrlRegs.GPBPUD.bit.GPIO36=0;

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
    AD7608_RANGE_10V;//+_10v��Χ

    AD7608_OS0_LOW;//��ֹ������
    AD7608_OS1_LOW;
    AD7608_OS2_LOW;

    DELAY_US(1000);
    AD7608_RST_LOW;//reset
 //   AD7608_CS0_HIGH;//cs
    AD7608_CNVST_HIGH;//convst

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
    AD7608_RST_HIGH;//reset
    DELAY_US(1);
    AD7608_RST_LOW;
    DELAY_US(1);
}

/*******************************************************************************
* �� �� ��         : AD7608OneSample
* ��������         : ��ʼ����
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void AD7608OneSample(void)
{

    unsigned char i;


    AD7608_CNVST_LOW;
    DELAY_US(10);
    AD7608_CNVST_HIGH;
    DELAY_US(1);

    while(AD7608_BUSY_READ==1)
    {

    }

//    while(AD7608_BUSY_READ==0);
//    DELAY_US(1);
    AD7608_CS0_LOW;

//    for(k=0;k<18;k++)
//    {
//        buf[k]=*(AD_ASTART);
//        TempA=(TempA<<1) + AD7608_DOUTA_READ;
//        TempB=(TempB<<1) + AD7608_DOUTB_READ;
//    }
    for(i=0;i<6;i++)
    {
        ad[i]=AD_ASTART;
    }
//    testSample1[sampleCount]=ad[0];//�����������
//    testSample2[sampleCount]=ad[1];
//    testSample3[sampleCount]=ad[2];
//    testSample4[sampleCount]=ad[3];
//    testSample5[sampleCount]=ad[4];
//    testSample6[sampleCount]=ad[5];
    sampleCount++;
    if(sampleCount >= 255) sampleCount=0;

    AD7608_CS0_HIGH;

}

interrupt void ISRTimer0(void)
{
    int j = 0;
    int tempa,tempb;
    //unsigned int ;
    //bool subflag=false;

    AD7608_CNVST_LOW;
    DELAY_US(10);
    AD7608_CNVST_HIGH;
    DELAY_US(1);

    while(AD7608_BUSY_READ==1)
    {

    }

//    while(AD7608_BUSY_READ==0);
//    DELAY_US(1);
 //   AD7608_CS0_LOW;

//    for(k=0;k<18;k++)
//    {
//        buf[k]=*(AD_ASTART);
//        TempA=(TempA<<1) + AD7608_DOUTA_READ;
//        TempB=(TempB<<1) + AD7608_DOUTB_READ;
//    }

        ad[0]=AD_ASTART;
        ad[1]=AD_ASTART;
        ad[2]=AD_ASTART;
        ad[3]=AD_ASTART;
        ad[4]=AD_ASTART;
        ad[5]=AD_ASTART;
        ad[6]=AD_ASTART;
        ad[7]=AD_ASTART;
        ad[8]=AD_ASTART;
        ad[9]=AD_ASTART;
        ad[10]=AD_ASTART;
        ad[11]=AD_ASTART;
        ad[12]=AD_ASTART;
        ad[13]=AD_ASTART;
        ad[14]=AD_ASTART;
        ad[15]=AD_ASTART;

        AD_ADD0[sampleCount]=ad[0];
        AD_ADD0[sampleCount]=AD_ADD0[sampleCount]<<2;
        ad[1]=ad[1]>>14;
        AD_ADD0[sampleCount]+=ad[1];

        AD_ADD1[sampleCount]=ad[2];
        AD_ADD1[sampleCount]=AD_ADD1[sampleCount]<<2;
        ad[3]=ad[3]>>14;
        AD_ADD0[sampleCount]+=ad[3];

        AD_ADD2[sampleCount]=ad[4];
        ad[4]=ad[4]<<2;
        AD_ADD2[sampleCount]=AD_ADD2[sampleCount]<<2;
        ad[5]=ad[5]>>14;
        AD_ADD2[sampleCount]+=ad[5];

        AD_ADD3[sampleCount]=ad[6];
        AD_ADD3[sampleCount]=AD_ADD3[sampleCount]<<2;
        ad[7]=ad[7]>>14;
        AD_ADD3[sampleCount]+=ad[7];

        AD_ADD4[sampleCount]=ad[8];
        AD_ADD4[sampleCount]=AD_ADD4[sampleCount]<<2;
        ad[9]=ad[9]>>14;
        AD_ADD4[sampleCount]+=ad[9];

        AD_ADD5[sampleCount]=ad[10];
        AD_ADD5[sampleCount]=AD_ADD5[sampleCount]<<2;
        ad[11]=ad[11]>>14;
        AD_ADD5[sampleCount]+=ad[11];

        AD_ADD6[sampleCount]=ad[12];
        AD_ADD6[sampleCount]=AD_ADD6[sampleCount]<<2;
        ad[13]=ad[13]>>14;
        AD_ADD6[sampleCount]+=ad[13];

        AD_ADD7[sampleCount]=ad[14];
        AD_ADD7[sampleCount]=AD_ADD7[sampleCount]<<2;
        ad[15]=ad[15]>>14;
        AD_ADD7[sampleCount]+=ad[15];

        sampleCount++;
        if(sampleCount >= 64) sampleCount=0;
//    for(j=0;j<16;j++)
//    {
//        ad[j]=AD_ASTART;
//        if(j%2==0)
//        {
//            tempa=ad[j];
//        }
//        else
//        {
//            tempb=ad[j];
//            if(j==1)
//            {
//                AD_ADD0[sampleCount]=tempa;
//                AD_ADD0[sampleCount]=AD_ADD0[sampleCount]<<2;
//                tempb=tempb>>14;
//                AD_ADD0[sampleCount]+=tempb;
//            }
//            if(j==3)
//            {
//                AD_ADD1[sampleCount]=tempa;
//                AD_ADD1[sampleCount]=AD_ADD1[sampleCount]<<2;
//                tempb=tempb>>14;
//                AD_ADD1[sampleCount]+=tempb;
//            }
//            if(j==5)
//            {
//                AD_ADD2[sampleCount]=tempa;
//                AD_ADD2[sampleCount]=AD_ADD2[sampleCount]<<2;
//                tempb=tempb>>14;
//                AD_ADD2[sampleCount]+=tempb;
//            }
//            if(j==7)
//            {
//                AD_ADD3[sampleCount]=tempa;
//                AD_ADD3[sampleCount]=AD_ADD3[sampleCount]<<2;
//                tempb=tempb>>14;
//                AD_ADD3[sampleCount]+=tempb;
//            }
//            if(j==9)
//            {
//                AD_ADD4[sampleCount]=tempa;
//                AD_ADD4[sampleCount]=AD_ADD4[sampleCount]<<2;
//                tempb=tempb>>14;
//                AD_ADD4[sampleCount]+=tempb;
//            }
//            if(j==11)
//            {
//                AD_ADD5[sampleCount]=tempa;
//                AD_ADD5[sampleCount]=AD_ADD5[sampleCount]<<2;
//                tempb=tempb>>14;
//                AD_ADD5[sampleCount]+=tempb;
//            }
//            if(j==13)
//            {
//                AD_ADD6[sampleCount]=tempa;
//                AD_ADD6[sampleCount]=AD_ADD6[sampleCount]<<2;
//                tempb=tempb>>14;
//                AD_ADD6[sampleCount]+=tempb;
//            }
//            if(j==15)
//            {
//                AD_ADD7[sampleCount]=tempa;
//                AD_ADD7[sampleCount]=AD_ADD7[sampleCount]<<2;
//                tempb=tempb>>14;
//                AD_ADD7[sampleCount]+=tempb;
//
//                sampleCount++;
//                if(sampleCount >= 64) sampleCount=0;
//            }
//        }
////        AD_ADD[sampleCount]=tempa;
////        AD_ADD[sampleCount]=AD_ADD[sampleCount]<<2;
////            tempb=tempb>>14;
////            AD_ADD[sampleCount]+=tempb;
//            //AD_RES[sampleCount]=(float32)(AD_ADD[sampleCount])*10.0/131027.0;
////            AD_RES[sampleCount]=tempa*65536+tempb;
////        sampleCount++;
////        if(sampleCount >= 64) sampleCount=0;
//
//    }
//    testSample1[sampleCount]=ad[0];//�����������
//    testSample2[sampleCount]=ad[1];
//    testSample3[sampleCount]=ad[2];
//    testSample4[sampleCount]=ad[3];
//    testSample5[sampleCount]=ad[4];
//    testSample6[sampleCount]=ad[5];
    AD7608_CS0_HIGH;

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    CpuTimer0Regs.TCR.bit.TIF=1; // ��ʱ����ָ��ʱ�䣬��־λ��λ�������־
    CpuTimer0Regs.TCR.bit.TRB=1;  // ����Timer0�Ķ�ʱ����
}

void Ad7608Test(void)
{
    InitSysCtrl();
    AD7608_Init();
    DINT;//��ֹ�ж�
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();
    EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.TINT0 = &ISRTimer0;
    EDIS;    // This is needed to disable write to EALLOW protected registers
    InitCpuTimers();   // For this example, only initialize the Cpu Timers
    ConfigCpuTimer(&CpuTimer0, 100, 987); //�ڶ�ʱ���ڽ��в���,������1.5KHz

    IER |= M_INT1;
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
    EINT;
    ERTM;//ʹ�ܵ����¼�
    /*EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0; // GPIO0 = GPIO0
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;
    EDIS;
    GpioDataRegs.GPADAT.bit.GPIO0 = 0;*/
    AD7608_RST_HIGH;
    DELAY_US(100000);
    AD7608_RST_LOW;
    StartCpuTimer0();
    while(1);
}

