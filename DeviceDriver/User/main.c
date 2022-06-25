/*
 * main.c
 *
 *  Created on: 2022-2-27
 *      Author: Administrator
 */
#include "AVP33x_Project.h"


#include "24cxx.h"
#include "spi.h"
#include "adc.h"
#include "ecap.h"
//#include "ad7608.h"
//#include "filter.h"
#include "timers.h"
#include "tmux611x.h"
#include "leds.h"
#include "I2cEeprom.h"
#include "ad7608v2.h"

//Uint16 addr = 0;
//Uint16 RecvBuf[16]={0};
//Uint16 TranBuf[16]={0,1,2,3,4,5,6,7,8,9,0xA,0xB,0xC,0xD,0xE,0xF};
/*******************************************************************************
* 函 数 名         : main
* 函数功能         : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main()
{
    InitSysCtrl();
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();

//    LED_Init();
//    AT24CXX_Init();
//    spi_fifo_init();
//    Eerom_Gpio_Init();
//    InitEeprom();
//    eCAP2_Init();
    eCAP3_Init();
    AD7608_Init();
    TMUX611X_Init();

//    TIM0_Init(150, 100000);//0.01s定时中断
//    Ad7608Test();
    //Eepromtest();
    while(1){
//        Ad7608Test();
    }

}


//===========================================================================
// No more.
//===========================================================================


