#include "tmux611x.h"

void TMUX611X_Init(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK=1;//开启GPIO时钟

    //1IN_CTL_1
    GpioCtrlRegs.GPAMUX2.bit.GPIO30=0;//GPIO模式
    GpioCtrlRegs.GPADIR.bit.GPIO30=1;//输出状态
    GpioCtrlRegs.GPAPUD.bit.GPIO30=0;//上拉

    //2IN_CTL_1
    GpioCtrlRegs.GPAMUX2.bit.GPIO29=0;//GPIO模式
    GpioCtrlRegs.GPADIR.bit.GPIO29=1;//输出状态
    GpioCtrlRegs.GPAPUD.bit.GPIO29=0;//上拉

    //3IN_CTL_1
    GpioCtrlRegs.GPAMUX1.bit.GPIO3=0;//GPIO模式
    GpioCtrlRegs.GPADIR.bit.GPIO3=1;//输出状态
    GpioCtrlRegs.GPAPUD.bit.GPIO3=0;//上拉

    //4IN_CTL_1
    GpioCtrlRegs.GPAMUX1.bit.GPIO7=0;//GPIO模式
    GpioCtrlRegs.GPADIR.bit.GPIO7=1;//输出状态
    GpioCtrlRegs.GPAPUD.bit.GPIO7=0;//上拉

    //5IN_CTL_1
    GpioCtrlRegs.GPAMUX1.bit.GPIO8=0;//GPIO模式
    GpioCtrlRegs.GPADIR.bit.GPIO8=1;//输出状态
    GpioCtrlRegs.GPAPUD.bit.GPIO8=0;//上拉

    //6IN_CTL_1
    GpioCtrlRegs.GPAMUX1.bit.GPIO9=0;//GPIO模式
    GpioCtrlRegs.GPADIR.bit.GPIO9=1;//输出状态
    GpioCtrlRegs.GPAPUD.bit.GPIO9=0;//上拉

    //1IN_CTL_2
    GpioCtrlRegs.GPAMUX1.bit.GPIO12=0;//GPIO模式
    GpioCtrlRegs.GPADIR.bit.GPIO12=1;//输出状态
    GpioCtrlRegs.GPAPUD.bit.GPIO12=0;//上拉

    //2IN_CTL_2
    GpioCtrlRegs.GPAMUX1.bit.GPIO13=0;//GPIO模式
    GpioCtrlRegs.GPADIR.bit.GPIO13=1;//输出状态
    GpioCtrlRegs.GPAPUD.bit.GPIO13=0;//上拉

    //3IN_CTL_2
    GpioCtrlRegs.GPAMUX1.bit.GPIO14=0;//GPIO模式
    GpioCtrlRegs.GPADIR.bit.GPIO14=1;//输出状态
    GpioCtrlRegs.GPAPUD.bit.GPIO14=0;//上拉

    //4IN_CTL_2
    GpioCtrlRegs.GPAMUX1.bit.GPIO15=0;//GPIO模式
    GpioCtrlRegs.GPADIR.bit.GPIO15=1;//输出状态
    GpioCtrlRegs.GPAPUD.bit.GPIO15=0;//上拉

    //5IN_CTL_2
    GpioCtrlRegs.GPAMUX2.bit.GPIO16=0;//GPIO模式
    GpioCtrlRegs.GPADIR.bit.GPIO16=1;//输出状态
    GpioCtrlRegs.GPAPUD.bit.GPIO16=0;//上拉

    //6IN_CTL_2
    GpioCtrlRegs.GPAMUX2.bit.GPIO17=0;//GPIO模式
    GpioCtrlRegs.GPADIR.bit.GPIO17=1;//输出状态
    GpioCtrlRegs.GPAPUD.bit.GPIO17=0;//上拉

    EDIS;
    TMUX611X_Switch_ON(11);
//    TMUX611X_Switch_ON(12);
//    TMUX611X_Switch_OFF(22);
    TMUX611X_Switch_ON(21);
//    TMUX611X_Switch_OFF(32);
    TMUX611X_Switch_ON(31);
//    TMUX611X_Switch_OFF(42);
    TMUX611X_Switch_ON(41);
//    TMUX611X_Switch_OFF(52);
    TMUX611X_Switch_ON(51);
//    TMUX611X_Switch_OFF(62);
    TMUX611X_Switch_ON(61);
}

/*******************************************************************************
* 函 数 名         : TMUX611X_Switch_ON
* 函数功能         : 打开多路复用器开关
*               11则是第1个多路复用器的第1个通道，12则是第1个多路复用器的第2个通道，
*               21则是第1个多路复用器的第3个通道，22则是第1个多路复用器的第4个通道
*               31则是第2个多路复用器的第1个通道，32则是第2个多路复用器的第2个通道
*               41则是第2个多路复用器的第3个通道, 42则是第1个多路复用器的第4个通道
* 输    入         : SELx
* 输    出         : 无
*******************************************************************************/
void TMUX611X_Switch_ON(int SELx)
{
    switch(SELx)
    {
    case 11:
        GpioDataRegs.GPASET.bit.GPIO30=1;
        GpioDataRegs.GPACLEAR.bit.GPIO12=1;
        break;
    case 12:
        GpioDataRegs.GPACLEAR.bit.GPIO30=1;
        GpioDataRegs.GPASET.bit.GPIO12=1;
        break;
    case 21:
        GpioDataRegs.GPACLEAR.bit.GPIO13=1;
        GpioDataRegs.GPASET.bit.GPIO29=1;
        break;
    case 22:
        GpioDataRegs.GPASET.bit.GPIO13=1;
        GpioDataRegs.GPACLEAR.bit.GPIO29=1;
        break;
    case 31:
        GpioDataRegs.GPASET.bit.GPIO3=1;
        GpioDataRegs.GPACLEAR.bit.GPIO14=1;
        break;
    case 32:
        GpioDataRegs.GPACLEAR.bit.GPIO3=1;
        GpioDataRegs.GPASET.bit.GPIO14=1;
        break;
    case 41:
        GpioDataRegs.GPASET.bit.GPIO7=1;
        GpioDataRegs.GPACLEAR.bit.GPIO15=1;
        break;
    case 42:
        GpioDataRegs.GPACLEAR.bit.GPIO7=1;
        GpioDataRegs.GPASET.bit.GPIO15=1;
        break;
    case 51:
        GpioDataRegs.GPASET.bit.GPIO8=1;
        GpioDataRegs.GPACLEAR.bit.GPIO16=1;
        break;
    case 52:
        GpioDataRegs.GPACLEAR.bit.GPIO8=1;
        GpioDataRegs.GPASET.bit.GPIO16=1;
        break;
    case 61:
        GpioDataRegs.GPASET.bit.GPIO9=1;
        GpioDataRegs.GPACLEAR.bit.GPIO17=1;
        break;
    case 62:
        GpioDataRegs.GPACLEAR.bit.GPIO9=1;
        GpioDataRegs.GPASET.bit.GPIO17=1;
        break;
    default:
        break;
    }
}

/*******************************************************************************
* 函 数 名         : TMUX611X_Switch_OFF
* 函数功能         : 关闭多路复用器开关
*               11则是第1个多路复用器的第1个通道，12则是第1个多路复用器的第2个通道，
*               21则是第1个多路复用器的第3个通道，22则是第1个多路复用器的第4个通道
*               31则是第2个多路复用器的第1个通道，32则是第2个多路复用器的第2个通道
*               41则是第2个多路复用器的第3个通道, 42则是第1个多路复用器的第4个通道
* 输    入         : SELx
* 输    出         : 无
*******************************************************************************/
void TMUX611X_Switch_OFF(int SELx)
{
    switch(SELx)
    {
    case 11:
        GpioDataRegs.GPACLEAR.bit.GPIO30=1;
        break;
    case 12:
        GpioDataRegs.GPACLEAR.bit.GPIO12=1;
        break;
    case 21:
        GpioDataRegs.GPACLEAR.bit.GPIO29=1;
        break;
    case 22:
        GpioDataRegs.GPACLEAR.bit.GPIO13=1;
        break;
    case 31:
        GpioDataRegs.GPACLEAR.bit.GPIO3=1;
        break;
    case 32:
        GpioDataRegs.GPACLEAR.bit.GPIO14=1;
        break;
    case 41:
        GpioDataRegs.GPACLEAR.bit.GPIO7=1;
        break;
    case 42:
        GpioDataRegs.GPACLEAR.bit.GPIO15=1;
        break;
    case 51:
        GpioDataRegs.GPACLEAR.bit.GPIO8=1;
        break;
    case 52:
        GpioDataRegs.GPACLEAR.bit.GPIO16=1;
        break;
    case 61:
        GpioDataRegs.GPACLEAR.bit.GPIO9=1;
        break;
    case 62:
        GpioDataRegs.GPACLEAR.bit.GPIO17=1;
        break;
    default:
        break;
    }
}
