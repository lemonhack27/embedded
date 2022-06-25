/*
 * spi.c
 *
 *  Created on: 2018-2-3
 *      Author: Administrator
 */


#include "spi.h"

/*******************************************************************************
* �� �� ��         : spiInit()
* ��������         : SPIA��ʼ��������ʽ���������ã��������ݸ�ʽ����λ���ԡ�fifo����
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void spiInit(void)
{
// Initialize SPI FIFO registers
   InitSpiGpio();

   SpiaRegs.SPIFFTX.all=0xE040;//ʹ��SPIFIFO���ܣ�TXFIFO��λ����� TXFF INT �ж�λ;TXFIFO �� �ϲ�ʹ�ܣ�
   SpiaRegs.SPIFFRX.all=0x204f;//����ʹ�ܽ��� FIFO ��������RXFIFO�жϱ�־λ���жϲ�ʹ�ܡ�
   SpiaRegs.SPIFFCT.all=0x0;//����Ĵ���������FIFO��ʱ�ģ�����Ҫ�õ���

   SpiaRegs.SPICCR.all =0x004F; // ��λ,�½��ط��ͣ������ؽ���(��ʱ�Ӽ����ǣ�����ʱΪ�ߵ�ƽ),  �ֳ�16λ���ر�SPI�ڲ�LOOP BACK  ��ֹ����
   SpiaRegs.SPICTL.all =0x0006; // ����ģʽ, ʱ����λΪ������λ,
   SpiaRegs.SPICTL.bit.CLK_PHASE=0;//TALK=1ʹ����������, SPI�жϲ�ʹ��.  ʱ����λΪ�������ڵ�2��ʱ�ӱ��ر�ѡ��
   SpiaRegs.SPIBRR =0x0003; //����������������=9.375MHz ��������=LSPCLK/(SPIBRR+1)=150MHz/4/4=9.375MHz
   SpiaRegs.SPICCR.all =0x00CF;//�½��ط��ͣ������ؽ���(��ʱ�Ӽ����ǣ�����ʱΪ�ߵ�ƽ), �ֳ�16λ��׼�����ͻ����  ��ֹ����ģʽSPILBK=0
   SpiaRegs.SPIPRI.bit.FREE = 1; // Set so breakpoints don't disturb xmission //�����õ�




   //Ϊ�ж����������ֵ
    EALLOW;    // This is needed to write to EALLOW protected registers
    PieVectTable.SPIRXINTA = &spiRxFifoIsr;
    PieVectTable.SPITXINTA = &spiTxFifoIsr;
    EDIS;   // This is needed to disable write to EALLOW protected registers

    // ʹ���ж�
       PieCtrlRegs.PIECTRL.bit.ENPIE = 1;   // Enable the PIE block
       PieCtrlRegs.PIEIER6.bit.INTx1=1;     // Enable PIE Group 6, INT 1
       PieCtrlRegs.PIEIER6.bit.INTx2=1;     // Enable PIE Group 6, INT 2
       IER |= M_INT6;                         // Enable CPU INT6
       EINT;                             // Enable Global Interrupts
       ERTM;
}

//**********************************
/*
  @ Description: �������SPI���Դ�����ֹͣ����
*/
//**********************************
void error(void)
{
    asm("     ESTOP0");  //Test failed!! Stop!
    for (;;);
}

//==========�жϷ����Ӻ���================================
//**********************************
/*
  @ Description: SPI FIFO�����жϷ����Ӻ���
*/
//**********************************
interrupt void spiTxFifoIsr(void)
{
//    Uint16 i;
//    for(i=0;i<8;i++)
//    { SpiaRegs.SPITXBUF=sdata[i];  }   // ��������
//    for(i=0;i<8;i++)
//    { sdata[i]++; } // Ϊ��һ�η���׼������

 SpiaRegs.SPIFFTX.bit.TXFFINTCLR=1;  // ����жϱ�־λ
    PieCtrlRegs.PIEACK.all|=0x20;
}

//**********************************
/*
  @ Description: SPI FIFO�����жϷ����Ӻ���
*/
//**********************************
interrupt void spiRxFifoIsr(void)
{
//    Uint16 i;
//    for(i=0;i<8;i++)
//    { rdata[i]=SpiaRegs.SPIRXBUF;  }  //��ȡ���յ�������
//    for(i=0;i<8;i++)
//    { if(rdata[i] != rdata_point+i) error(); } //�����յ�������
//    rdata_point++;
    SpiaRegs.SPIFFRX.bit.RXFFOVFCLR=1;  // �������жϱ�־λ
    SpiaRegs.SPIFFRX.bit.RXFFINTCLR=1;   // ����жϱ�־λ
    PieCtrlRegs.PIEACK.all|=M_INT6;
}
//===========================================================================
// End of file
//===========================================================================

