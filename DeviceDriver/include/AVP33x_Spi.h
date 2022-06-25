/******************************************************************************
�ļ���                     : AVP33x_Spi.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xоƬSPIģ��Ĵ�������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_SPI_H
#define AVP33x_SPI_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
/* SPI����FIFO�Ĵ�����SPIFFTX��λ���� */
struct  SPIFFTX_BITS {          // λ����
    Uint16 TXFFIL:5;            // 4:0    SPI����FIFO�жϼ������λ
    Uint16 TXFFIENA:1;          // 5      SPI����FIFO�ж�ʹ�ܿ���λ
    Uint16 TXFFINTCLR:1;        // 6      SPI����FIFO�жϱ�־�������λ
    Uint16 TXFFINT:1;           // 7      SPI����FIFO�жϱ�־λ
    Uint16 TXFFST:5;            // 12:8   SPI����FIFO�����ݸ���
    Uint16 TXFIFO:1;            // 13     SPI����FIFO��λ����λ
    Uint16 SPIFFENA:1;          // 14     SPI����FIFO��ǿʹ�ܿ���λ
    Uint16 SPIRST:1;            // 15     SPI��λ����λ
};

union SPIFFTX_REG {
    Uint16               all;
    struct SPIFFTX_BITS  bit;
};

//----------------------------------------------------
/* SPI����FIFO�Ĵ�����SPIFFRX��λ���� */
struct  SPIFFRX_BITS {          // λ����
    Uint16 RXFFIL:5;            // 4:0    SPI����FIFO�жϼ������λ
    Uint16 RXFFIENA:1;          // 5      SPI����FIFO�ж�ʹ�ܿ���λ
    Uint16 RXFFINTCLR:1;        // 6      SPI����FIFO�жϱ�־�������λ
    Uint16 RXFFINT:1;           // 7      SPI����FIFO�жϱ�־λ
    Uint16 RXFFST:5;            // 12:8   SPI����FIFO�����ݸ���
    Uint16 RXFIFORESET:1;       // 13     SPI����FIFO��λ����λ
    Uint16 RXFFOVFCLR:1;        // 14     SPI����FIFO�����־�������λ
    Uint16 RXFFOVF:1;           // 15     SPI����FIFO�����־λ

};

union SPIFFRX_REG {
    Uint16               all;
    struct SPIFFRX_BITS  bit;
};

//----------------------------------------------------
/* SPI FIFO���ƼĴ�����SPIFFCT��λ���� */
struct  SPIFFCT_BITS {          // λ����
    Uint16 TXDLY:8;             // 7:0    SPI FIFO�����ӳٿ���λ
    Uint16 rsvd:8;              // 15:8   Ԥ��
};

union SPIFFCT_REG {
    Uint16               all;
    struct SPIFFCT_BITS  bit;
};

//----------------------------------------------------
/* SPI���üĴ�����SPICCR��λ���� */
struct  SPICCR_BITS {           // λ����
    Uint16 SPICHAR:4;           // 3:0    SPI�ַ����ȿ���λ
    Uint16 SPILBK:1;            // 4      SPI�Բ�ģʽʹ�ܿ���λ
    Uint16 rsvd1:1;             // 5      Ԥ��
    Uint16 CLKPOLARITY:1;       // 6      SPIʱ�Ӽ��Կ���λ
    Uint16 SPISWRESET:1;        // 7      SPI�����λ����λ
    Uint16 rsvd2:8;             // 15:8   Ԥ��
};

union SPICCR_REG {
    Uint16              all;
    struct SPICCR_BITS  bit;
};

//----------------------------------------------------
/* SPI�������ƼĴ�����SPICTL��λ���� */
struct  SPICTL_BITS {           // λ����
    Uint16 SPIINTENA:1;         // 0      SPI�ж�ʹ�ܿ���λ
    Uint16 TALK:1;              // 1      SPI��/��ģʽ�л�����λ
    Uint16 MASTER_SLAVE:1;      // 2      SPI����ģʽ����λ
    Uint16 CLK_PHASE:1;         // 3      SPIʱ����λѡ�����λ
    Uint16 OVERRUNINTENA:1;     // 4      SPI��ʱ�ж�ʹ��
    Uint16 rsvd:11;             // 15:5   Ԥ��
};

union SPICTL_REG {
    Uint16              all;
    struct SPICTL_BITS  bit;
};

//----------------------------------------------------
/* SPI״̬�Ĵ�����SPISTS��λ���� */
struct  SPISTS_BITS {           // λ����
    Uint16 rsvd1:5;             // 4:0    Ԥ��
    Uint16 BUFFULL_FLAG:1;      // 5      SPI���ͻ���Ĵ�������־λ
    Uint16 INT_FLAG:1;          // 6      SPI�жϱ�־λ
    Uint16 OVERRUN_FLAG:1;      // 7      SPI���������־λ
    Uint16 rsvd2:8;             // 15:8   Ԥ��
};

union SPISTS_REG {
    Uint16              all;
    struct SPISTS_BITS  bit;
};

//----------------------------------------------------
/* SPI���ȼ����ƼĴ�����SPIPRI��λ���� */
struct  SPIPRI_BITS {           // λ����
    Uint16 rsvd1:4;             // 3:0    Ԥ��
    Uint16 FREE:1;              // 4      SPI������ͣģʽ����λ
    Uint16 SOFT:1;              // 5      SPI������ͣģʽ����λ
    Uint16 rsvd2:1;             // 6      Ԥ��
    Uint16 rsvd3:9;             // 15:7   Ԥ��
};

union SPIPRI_REG {
    Uint16              all;
    struct SPIPRI_BITS  bit;
};

/**************************************/
/* SPI���ƺ�״̬�Ĵ����ļ� */
/**************************************/
struct  SPI_REGS {
    union SPICCR_REG     SPICCR;        // SPI���üĴ���
    union SPICTL_REG     SPICTL;        // SPI�������ƼĴ���
    union SPISTS_REG     SPISTS;        // SPI״̬�Ĵ���
    Uint16               rsvd1;         // Ԥ��
    Uint16               SPIBRR;        // SPI�����ʼĴ���
    Uint16               rsvd2;         // Ԥ��
    Uint16               SPIRXEMU;      // SPI���滺��Ĵ���
    Uint16               SPIRXBUF;      // SPI���ջ���Ĵ���
    Uint16               SPITXBUF;      // SPI���ͻ���Ĵ���
    Uint16               SPIDAT;        // SPI����/������λ�Ĵ���
    union SPIFFTX_REG    SPIFFTX;       // SPI����FIFO�Ĵ���
    union SPIFFRX_REG    SPIFFRX;       // SPI����FIFO�Ĵ���
    union SPIFFCT_REG    SPIFFCT;       // SPI FIFO���ƼĴ���
    Uint16               rsvd3[2];      // Ԥ��
    union SPIPRI_REG     SPIPRI;        // SPI FIFO���ȼ����ƼĴ���
};

//---------------------------------------------------------------------------
// SPI�ⲿ���úͺ�������:
//
extern volatile struct SPI_REGS SpiaRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of AVP33x_SPI_H definition

//===========================================================================
// End of file.
//===========================================================================
