/******************************************************************************
�ļ���                     : AVP33x_Sci.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xоƬSCIģ��Ĵ�������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_SCI_H
#define AVP33x_SCI_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
/* SCIͨ�ſ��ƼĴ�����SCICCR��λ���� */
struct  SCICCR_BITS {           // λ����
    Uint16 SCICHAR:3;           // 2:0    SCIͨ�����ݳ��ȿ���λ
    Uint16 ADDRIDLE_MODE:1;     // 3      SCI�༶ģʽ����λ
    Uint16 LOOPBKENA:1;         // 4      SCI�Բ�ģʽʹ�ܿ���λ
    Uint16 PARITYENA:1;         // 5      SCI��żУ��ʹ�ܿ���λ
    Uint16 PARITY:1;            // 6      ��/żУ��ѡ�����λ
    Uint16 STOPBITS:1;          // 7      ֹͣλλ������λ
    Uint16 rsvd1:8;             // 15:8   Ԥ��
}; 


union SCICCR_REG {
    Uint16              all;
    struct SCICCR_BITS  bit;
};

//----------------------------------------------------
/* SCI���ƼĴ���1��SCICTL1��λ���� */
struct  SCICTL1_BITS {          // λ����
    Uint16 RXENA:1;             // 0      SCI����ʹ�ܿ���λ
    Uint16 TXENA:1;             // 1      SCI����ʹ�ܿ���λ
    Uint16 SLEEP:1;             // 2      SCI˯��ģʽʹ�ܿ���λ
    Uint16 TXWAKE:1;            // 3      SCI���ͻ��ѷ�ʽѡ�����λ
    Uint16 rsvd:1;              // 4      Ԥ��
    Uint16 SWRESET:1;           // 5      SCI�����λλ
    Uint16 RXERRINTENA:1;       // 6      SCI�����ж�ʱ�ܿ���λ
    Uint16 rsvd1:9;             // 15:7   Ԥ��
}; 

union SCICTL1_REG {
    Uint16               all;
    struct SCICTL1_BITS  bit;
};

//----------------------------------------------------
/* SCI���ƼĴ���2��SCICTL2��λ���� */
struct  SCICTL2_BITS {          // λ����
    Uint16 TXINTENA:1;          // 0      SCI�����ж�ʱ�ܿ���λ
    Uint16 RXBKINTENA:1;        // 1      SCI����/�����ж�ʹ�ܿ���λ
    Uint16 rsvd:4;              // 5:2    Ԥ��
    Uint16 TXEMPTY:1;           // 6      SCI���Ϳձ�־λ
    Uint16 TXRDY:1;             // 7      SCI���ͻ���Ĵ���׼��������־λ
    Uint16 rsvd1:8;             // 15:8   Ԥ��
}; 

union SCICTL2_REG {
    Uint16               all;
    struct SCICTL2_BITS  bit;
};

//----------------------------------------------------
/* SCI����״̬�Ĵ�����SCIRXST��λ���� */
struct  SCIRXST_BITS {          // λ����
    Uint16 rsvd:1;              // 0      Ԥ��
    Uint16 RXWAKE:1;            // 1      SCI���յ�һ�������źŵı�־λ
    Uint16 PE:1;                // 2      SCI��żУ������־λ
    Uint16 OE:1;                // 3      SCI���������־λ
    Uint16 FE:1;                // 4      SCI����֡��ʽ�����־λ
    Uint16 BRKDT:1;             // 5      SCI��ϼ���־λ
    Uint16 RXRDY:1;             // 6      SCI���վ�����־λ
    Uint16 RXERROR:1;           // 7      SCI���մ����־λ
}; 

union SCIRXST_REG {
    Uint16               all;
    struct SCIRXST_BITS  bit;
};

//----------------------------------------------------
/* SCI�������ݻ���Ĵ�����SCIRXBUF��λ���� */
struct  SCIRXBUF_BITS {         // λ����
    Uint16 RXDT:8;              // 7:0    ���յ�������λ
    Uint16 rsvd:6;              // 13:8   Ԥ��
    Uint16 SCIFFPE:1;           // 14     SCIFIFO��żУ������־λ
    Uint16 SCIFFFE:1;           // 15     SCIFIFO֡��ʽ�����־λ
};

union SCIRXBUF_REG {
    Uint16                all;
    struct SCIRXBUF_BITS  bit;
};

//----------------------------------------------------
/* SCI���ȼ����ƼĴ�����SCIPRI��λ���� */
struct  SCIPRI_BITS {           // λ����
    Uint16 rsvd:3;              // 2:0    Ԥ��
    Uint16 FREE:1;              // 3      ������ͣģʽ����λ
    Uint16 SOFT:1;              // 4      ������ͣģʽ����λ
    Uint16 rsvd1:3;             // 7:5    Ԥ��
}; 

union SCIPRI_REG {
    Uint16              all;
    struct SCIPRI_BITS  bit;
};

//----------------------------------------------------
/* SCI����FIFO�Ĵ�����SCIFFTX��λ���� */
struct  SCIFFTX_BITS {          // λ����
    Uint16 TXFFIL:5;            // 4:0    SCI����FIFO��ȿ���λ
    Uint16 TXFFIENA:1;          // 5      SCI����FIFO�ж�ʹ�ܿ���λ
    Uint16 TXFFINTCLR:1;        // 6      SCI����FIFO�жϱ�־�������λ
    Uint16 TXFFINT:1;           // 7      SCI����FIFO�жϱ�־λ
    Uint16 TXFFST:5;            // 12:8   SCI����FIFO�����ݸ���
    Uint16 TXFIFOXRESET:1;      // 13     SCI����FIFO��λ����λ
    Uint16 SCIFFENA:1;          // 14     SCI����FIFOģ�鹦��ʹ�ܿ���λ
    Uint16 SCIRST:1;            // 15     SCIģ�鸴λ����λ
}; 

union SCIFFTX_REG {
    Uint16               all;
    struct SCIFFTX_BITS  bit;
};

//----------------------------------------------------
/* SCI����FIFO�Ĵ�����SCIFFRX��λ���� */
struct  SCIFFRX_BITS {          // λ����
    Uint16 RXFFIL:5;            // 4:0    SCI����FIFO��ȿ���λ
    Uint16 RXFFIENA:1;          // 5      SCI����FIFO�ж�ʹ�ܿ���λ
    Uint16 RXFFINTCLR:1;        // 6      SCI����FIFO�жϱ�־�������λ
    Uint16 RXFFINT:1;           // 7      SCI����FIFO�жϱ�־λ
    Uint16 RXFFST:5;            // 12:8   SCI����FIFO�����ݸ���
    Uint16 RXFIFORESET:1;       // 13     SCI����FIFO��λ����λ
    Uint16 RXFFOVRCLR:1;        // 14     SCI����FIFO�����־�������λ
    Uint16 RXFFOVF:1;           // 15     SCI����FIFO�����־λ
}; 

union SCIFFRX_REG {
    Uint16               all;
    struct SCIFFRX_BITS  bit;
};

// SCI FIFO control register bit definitions:
//----------------------------------------------------
/* SCI FIFO���ƼĴ�����SCIFFCT��λ���� */
struct  SCIFFCT_BITS {          // λ����
    Uint16 FFTXDLY:8;           // 7:0    SCI����FIFO��ʱ����λ
    Uint16 rsvd:5;              // 12:8   Ԥ��
    Uint16 CDC:1;               // 13     SCI�������Զ�У׼ʹ�ܿ���λ
    Uint16 ABDCLR:1;            // 14     ABDλ���ʹ��λ
    Uint16 ABD:1;               // 15     SCI�������Զ�������λ
};

union SCIFFCT_REG {
    Uint16               all;
    struct SCIFFCT_BITS  bit;
};

/**************************************/
/* SCI���ƺ�״̬�Ĵ����ļ� */
/**************************************/
struct  SCI_REGS {
    union SCICCR_REG     SCICCR;    // SCIͨ�ſ��ƼĴ���
    union SCICTL1_REG    SCICTL1;   // SCI���ƼĴ���1
    Uint16               SCIHBAUD;  // SCI�����ʼĴ������ߣ�
    Uint16               SCILBAUD;  // SCI�����ʼĴ������ͣ�
    union SCICTL2_REG    SCICTL2;   // SCI���ƼĴ���2
    union SCIRXST_REG    SCIRXST;   // SCI״̬�Ĵ���
    Uint16               SCIRXEMU;  // SCI���շ��滺��Ĵ���
    union SCIRXBUF_REG   SCIRXBUF;  // SCI�������ݻ���Ĵ���
    Uint16               rsvd1;     // Ԥ��
    Uint16               SCITXBUF;  // SCI�������ݻ���Ĵ���
    union SCIFFTX_REG    SCIFFTX;   // SCI����FIFO�Ĵ���
    union SCIFFRX_REG    SCIFFRX;   // SCI����FIFO�Ĵ���
    union SCIFFCT_REG    SCIFFCT;   // SCI FIFO���ƼĴ���
    Uint16               rsvd2;     // Ԥ��
    Uint16               rsvd3;     // Ԥ��
    union SCIPRI_REG     SCIPRI;    // SCI���ȼ����ƼĴ���
};

//---------------------------------------------------------------------------
// SCI�ⲿ���úͺ�������:
//
extern volatile struct SCI_REGS SciaRegs;
extern volatile struct SCI_REGS ScibRegs;
extern volatile struct SCI_REGS ScicRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of AVP33x_SCI_H definition

//===========================================================================
// End of file.
//===========================================================================
