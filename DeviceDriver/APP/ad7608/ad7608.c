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
* 函 数 名         : init_zone0
* 函数功能         : 外部接口模块（XINTF）初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void init_zone0(void)
{
    //使能XINTF时钟
    EALLOW;
    SysCtrlRegs.PCLKCR3.bit.XINTFENCLK=1;
    EDIS;

    //将对应的IO配置为XINTF外设使用
    InitXintf16Gpio();

    //所有区域基准时间时钟为XTIMCLK=SYSCLKOUT
    EALLOW;
    XintfRegs.XINTCNF2.bit.XTIMCLK=0;
    //写缓冲器深度为3
    XintfRegs.XINTCNF2.bit.WRBUFF=3;
    //XCLKOUT使能（默认）
    XintfRegs.XINTCNF2.bit.CLKOFF=0;
    //XCLKOUT=XTIMCLK
    XintfRegs.XINTCNF2.bit.CLKMODE=0;

    //区域写操作时间设定
    XintfRegs.XTIMING0.bit.XWRLEAD=1;//写访问的建立时间中等待周期个数设定位
    XintfRegs.XTIMING0.bit.XWRACTIVE=2;//写访问的有效时间中等待周期个数设定位
    XintfRegs.XTIMING0.bit.XWRTRAIL=1;//写访问的跟踪时间中等待周期个数设定位
    //区域0读操作时间设定
    XintfRegs.XTIMING0.bit.XRDLEAD=1;//读访问的建立时间中等待周期个数设定位
    XintfRegs.XTIMING0.bit.XRDACTIVE=3;//读访问的有效时间中等待周期个数设定位
    XintfRegs.XTIMING0.bit.XRDTRAIL=0;//读访问的跟踪时间中等待周期个数设定位

    //所有读写区域的建立时间、有效时间、跟踪时间是否加倍
    XintfRegs.XTIMING0.bit.X2TIMING=0;//不加倍

    //区域使用异步采样
    XintfRegs.XTIMING0.bit.USEREADY=0;
    XintfRegs.XTIMING0.bit.READYMODE=0;

    //数据总线宽度设定
    XintfRegs.XTIMING0.bit.XSIZE=3;//数据总线宽度为16位
    EDIS;

    //强制流水线刷新以确保在返回之前写入配置的最后一个寄存器。
    asm(" RPT #7 || NOP");
}

/*******************************************************************************
* 函 数 名         : AD7608_Init
* 函数功能         : 初始化AD7608使用的端口以及打开中断
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void AD7608_Init(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK=1;//开启GPIO时钟

    //设置连接ad7608的GPIO端口
    //AD7608_CONVST（转换端口选择信号）
    GpioCtrlRegs.GPAMUX1.bit.GPIO5=0;//GPIO模式
    GpioCtrlRegs.GPADIR.bit.GPIO5=1;//输出状态
    GpioCtrlRegs.GPAPUD.bit.GPIO5=0;//上拉

    //AD7608_RESET（复位信号）
    GpioCtrlRegs.GPAMUX1.bit.GPIO1=0;
    GpioCtrlRegs.GPADIR.bit.GPIO1=1;
    GpioCtrlRegs.GPAPUD.bit.GPIO1=0;

    //XZCS0（片选信号）
    GpioCtrlRegs.GPBMUX1.bit.GPIO36=0;
    GpioCtrlRegs.GPBDIR.bit.GPIO36=1;
    GpioCtrlRegs.GPBPUD.bit.GPIO36=0;

    //AD7608_BUSY（BUSY信号）
    GpioCtrlRegs.GPAMUX2.bit.GPIO24=0;
    GpioCtrlRegs.GPADIR.bit.GPIO24=0;//输入状态
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

    //XRDN（读取信号）.........该信号由AD发出，不用配置DSP引脚。
    EDIS;


    init_zone0();

    EALLOW;
    GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 24;   // XINT1是GPIO24
    EDIS;

    EALLOW;
    PieVectTable.XINT1=&XINT1_ISR1;
    EDIS;

    PieCtrlRegs.PIEIER1.bit.INTx4 = 1;          // 使能PIE组1的INT4

    XIntruptRegs.XINT1CR.bit.POLARITY = 0;      // 下降沿触发中断
    XIntruptRegs.XINT1CR.bit.ENABLE= 1;        // 使能XINT1

    IER |= M_INT1;                              // 使能CPU中断1（INT1）
    EINT;                                       // 开全局中断
    ERTM;

    AD7608Initialization();

}


/*******************************************************************************
* 函 数 名         : AD7608Initialization
* 函数功能         : 初始化AD7608芯片的时序以及初始状态
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void AD7608Initialization(void)
{
    GpioDataRegs.GPASET.bit.GPIO2=1;//+_10v范围

    GpioDataRegs.GPACLEAR.bit.GPIO4=1;//禁止过采样
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
* 函 数 名         : AD7608Reset
* 函数功能         : 复位函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void AD7608Reset(void)
{
    GpioDataRegs.GPASET.bit.GPIO1=1;//reset
    DELAY_US(1);
    GpioDataRegs.GPACLEAR.bit.GPIO1=1;
    DELAY_US(1);
}

/*******************************************************************************
* 函 数 名         : AD7608OneSample
* 函数功能         : 开始采样
* 输    入         : 无
* 输    出         : 无
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
* 函 数 名         : XINT1_ISR1
* 函数功能         : 中断函数里面读取数据
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
interrupt void XINT1_ISR1(void)
{

    Uint16 i,j;
    Uint16 addat[BUF_SIZE*2];
//    ADC_TMP=ADC_ADD & 0x4FFF;

    GpioDataRegs.GPBCLEAR.bit.GPIO36=1;//cs


    for(i=0;i<BUF_SIZE*2;i+=2)
    {
        //GpioDataRegs  RD操作
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
