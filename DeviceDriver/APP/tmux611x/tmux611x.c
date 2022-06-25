#include "tmux611x.h"

void TMUX611X_Init(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK=1;//����GPIOʱ��

    //1IN_CTL_1
    GpioCtrlRegs.GPAMUX2.bit.GPIO30=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO30=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO30=0;//����

    //2IN_CTL_1
    GpioCtrlRegs.GPAMUX2.bit.GPIO29=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO29=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO29=0;//����

    //3IN_CTL_1
    GpioCtrlRegs.GPAMUX1.bit.GPIO3=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO3=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO3=0;//����

    //4IN_CTL_1
    GpioCtrlRegs.GPAMUX1.bit.GPIO7=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO7=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO7=0;//����

    //5IN_CTL_1
    GpioCtrlRegs.GPAMUX1.bit.GPIO8=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO8=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO8=0;//����

    //6IN_CTL_1
    GpioCtrlRegs.GPAMUX1.bit.GPIO9=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO9=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO9=0;//����

    //1IN_CTL_2
    GpioCtrlRegs.GPAMUX1.bit.GPIO12=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO12=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO12=0;//����

    //2IN_CTL_2
    GpioCtrlRegs.GPAMUX1.bit.GPIO13=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO13=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO13=0;//����

    //3IN_CTL_2
    GpioCtrlRegs.GPAMUX1.bit.GPIO14=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO14=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO14=0;//����

    //4IN_CTL_2
    GpioCtrlRegs.GPAMUX1.bit.GPIO15=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO15=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO15=0;//����

    //5IN_CTL_2
    GpioCtrlRegs.GPAMUX2.bit.GPIO16=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO16=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO16=0;//����

    //6IN_CTL_2
    GpioCtrlRegs.GPAMUX2.bit.GPIO17=0;//GPIOģʽ
    GpioCtrlRegs.GPADIR.bit.GPIO17=1;//���״̬
    GpioCtrlRegs.GPAPUD.bit.GPIO17=0;//����

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
* �� �� ��         : TMUX611X_Switch_ON
* ��������         : �򿪶�·����������
*               11���ǵ�1����·�������ĵ�1��ͨ����12���ǵ�1����·�������ĵ�2��ͨ����
*               21���ǵ�1����·�������ĵ�3��ͨ����22���ǵ�1����·�������ĵ�4��ͨ��
*               31���ǵ�2����·�������ĵ�1��ͨ����32���ǵ�2����·�������ĵ�2��ͨ��
*               41���ǵ�2����·�������ĵ�3��ͨ��, 42���ǵ�1����·�������ĵ�4��ͨ��
* ��    ��         : SELx
* ��    ��         : ��
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
* �� �� ��         : TMUX611X_Switch_OFF
* ��������         : �رն�·����������
*               11���ǵ�1����·�������ĵ�1��ͨ����12���ǵ�1����·�������ĵ�2��ͨ����
*               21���ǵ�1����·�������ĵ�3��ͨ����22���ǵ�1����·�������ĵ�4��ͨ��
*               31���ǵ�2����·�������ĵ�1��ͨ����32���ǵ�2����·�������ĵ�2��ͨ��
*               41���ǵ�2����·�������ĵ�3��ͨ��, 42���ǵ�1����·�������ĵ�4��ͨ��
* ��    ��         : SELx
* ��    ��         : ��
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
