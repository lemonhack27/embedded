/*
 * uart.c
 *
 *  Created on: 2018-1-31
 *      Author: Administrator
 */

#include "uart.h"


void UARTa_Init(Uint32 baud)
{
	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.SCIAENCLK = 1;   // SCI-A
	EDIS;

	InitSciaGpio();

	//Initalize the SCI FIFO
	SciaRegs.SCIFFTX.all=0xE040;
	SciaRegs.SCIFFRX.all=0x204f;
	SciaRegs.SCIFFCT.all=0x0;

	// Note: Clocks were turned on to the SCIA peripheral
	// in the InitSysCtrl() function
	SciaRegs.SCICCR.all =0x0007;   // 1 stop bit,  No loopback
								   // No parity,8 char bits,
								   // async mode, idle-line protocol
	SciaRegs.SCICTL1.all =0x0003;  // enable TX, RX, internal SCICLK,
								   // Disable RX ERR, SLEEP, TXWAKE
	SciaRegs.SCICTL2.all =0x0003;
	SciaRegs.SCICTL2.bit.TXINTENA =1;
	SciaRegs.SCICTL2.bit.RXBKINTENA =1;
	SciaRegs.SCIHBAUD    =0x0000;
	SciaRegs.SCILBAUD    =0x000F;
	SciaRegs.SCICCR.bit.LOOPBKENA =1; // Enable loop back
	SciaRegs.SCICTL1.all =0x0023;     // Relinquish SCI from Reset
}

// Transmit a character from the SCI'
void UARTa_SendByte(int a)
{
    SciaRegs.SCITXBUF=a;
    while(SciaRegs.SCIFFRX.bit.RXFFST !=1); // wait for XRDY =1 for empty state
}

