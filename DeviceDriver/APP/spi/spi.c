/*
 * spi.c
 *
 *  Created on: 2018-2-3
 *      Author: Administrator
 */


#include "spi.h"

/*******************************************************************************
* 函 数 名         : spiInit()
* 函数功能         : SPIA初始化工作方式及参数设置，包括数据格式、相位极性、fifo功能
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void spiInit(void)
{
// Initialize SPI FIFO registers
   InitSpiGpio();

   SpiaRegs.SPIFFTX.all=0xE040;//使能SPIFIFO功能；TXFIFO复位；清除 TXFF INT 中断位;TXFIFO 中 断不使能；
   SpiaRegs.SPIFFRX.all=0x204f;//重新使能接收 FIFO 操作；清RXFIFO中断标志位；中断不使能。
   SpiaRegs.SPIFFCT.all=0x0;//这个寄存器是设置FIFO延时的，不需要用到。

   SpiaRegs.SPICCR.all =0x004F; // 复位,下降沿发送，上升沿接收(即时钟极性是：空闲时为高电平),  字长16位。关闭SPI内部LOOP BACK  禁止回送
   SpiaRegs.SPICTL.all =0x0006; // 主机模式, 时钟相位为正常相位,
   SpiaRegs.SPICTL.bit.CLK_PHASE=0;//TALK=1使能主机发送, SPI中断不使能.  时钟相位为：数据在第2个时钟边沿被选择
   SpiaRegs.SPIBRR =0x0003; //波特率由主机决定=9.375MHz 。波特率=LSPCLK/(SPIBRR+1)=150MHz/4/4=9.375MHz
   SpiaRegs.SPICCR.all =0x00CF;//下降沿发送，上升沿接收(即时钟极性是：空闲时为高电平), 字长16位。准备发送或接收  禁止回送模式SPILBK=0
   SpiaRegs.SPIPRI.bit.FREE = 1; // Set so breakpoints don't disturb xmission //仿真用的




   //为中断入口向量赋值
    EALLOW;    // This is needed to write to EALLOW protected registers
    PieVectTable.SPIRXINTA = &spiRxFifoIsr;
    PieVectTable.SPITXINTA = &spiTxFifoIsr;
    EDIS;   // This is needed to disable write to EALLOW protected registers

    // 使能中断
       PieCtrlRegs.PIECTRL.bit.ENPIE = 1;   // Enable the PIE block
       PieCtrlRegs.PIEIER6.bit.INTx1=1;     // Enable PIE Group 6, INT 1
       PieCtrlRegs.PIEIER6.bit.INTx2=1;     // Enable PIE Group 6, INT 2
       IER |= M_INT6;                         // Enable CPU INT6
       EINT;                             // Enable Global Interrupts
       ERTM;
}

//**********************************
/*
  @ Description: 如果发生SPI测试错误，则停止测试
*/
//**********************************
void error(void)
{
    asm("     ESTOP0");  //Test failed!! Stop!
    for (;;);
}

//==========中断服务子函数================================
//**********************************
/*
  @ Description: SPI FIFO发送中断服务子函数
*/
//**********************************
interrupt void spiTxFifoIsr(void)
{
//    Uint16 i;
//    for(i=0;i<8;i++)
//    { SpiaRegs.SPITXBUF=sdata[i];  }   // 发送数据
//    for(i=0;i<8;i++)
//    { sdata[i]++; } // 为下一次发送准备数据

 SpiaRegs.SPIFFTX.bit.TXFFINTCLR=1;  // 清除中断标志位
    PieCtrlRegs.PIEACK.all|=0x20;
}

//**********************************
/*
  @ Description: SPI FIFO接收中断服务子函数
*/
//**********************************
interrupt void spiRxFifoIsr(void)
{
//    Uint16 i;
//    for(i=0;i<8;i++)
//    { rdata[i]=SpiaRegs.SPIRXBUF;  }  //读取接收到的数据
//    for(i=0;i<8;i++)
//    { if(rdata[i] != rdata_point+i) error(); } //检查接收到的数据
//    rdata_point++;
    SpiaRegs.SPIFFRX.bit.RXFFOVFCLR=1;  // 清除溢出中断标志位
    SpiaRegs.SPIFFRX.bit.RXFFINTCLR=1;   // 清除中断标志位
    PieCtrlRegs.PIEACK.all|=M_INT6;
}
//===========================================================================
// End of file
//===========================================================================

