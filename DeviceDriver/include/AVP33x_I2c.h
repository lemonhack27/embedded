/******************************************************************************
�ļ���                     : AVP33x_I2c.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xоƬI2Cģ��Ĵ�������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_I2C_H
#define AVP33x_I2C_H


#ifdef __cplusplus
extern "C" {
#endif


//----------------------------------------------------
/* I2C�ж������Ĵ�����I2CISRC��λ���� */
struct I2CISRC_BITS {           // λ����
    Uint16 INTCODE:3;           // 2:0    �ж�Դ
    Uint16 rsvd1:13;            // 15:3   Ԥ��
};

union I2CISRC_REG {
    Uint16                 all;
    struct I2CISRC_BITS    bit;
};

//----------------------------------------------------
/* I2C�ж�ʹ�ܼĴ�����I2CIER��λ���� */
struct I2CIER_BITS {            // λ����
    Uint16 ARBL:1;              // 0      �����ٲ�ʧ���ж�ʹ�ܿ���λ
    Uint16 NACK:1;              // 1      ��Ӧ���ź��ж�ʹ�ܿ���λ
    Uint16 ARDY:1;              // 2      �Ĵ�������׼�������ж�ʹ�ܿ���λ
    Uint16 RRDY:1;              // 3      �������ݾ����ж�ʹ�ܿ���λ
    Uint16 XRDY:1;              // 4      �������ݾ����ж�ʹ�ܿ���λ
    Uint16 SCD:1;               // 5      ֹͣ�ź��ж�ʹ�ܿ���λ
    Uint16 AAS:1;               // 6      �ӻ���ַ�ж�ʹ�ܿ���λ
    Uint16 rsvd:9;              // 15:7   Ԥ��
};

union I2CIER_REG {
    Uint16                 all;
    struct I2CIER_BITS     bit;
};

//----------------------------------------------------
/* I2C״̬�Ĵ�����I2CSTR��λ���� */
struct I2CSTR_BITS {            // λ����
    Uint16 ARBL:1;              // 0      �ٲ�ʧ���жϱ�־λ
    Uint16 NACK:1;              // 1      ��Ӧ���жϱ�־λ
    Uint16 ARDY:1;              // 2      �Ĵ�������׼�������жϱ�־λ
    Uint16 RRDY:1;              // 3      �������ݾ����жϱ�־λ
    Uint16 XRDY:1;              // 4      �������ݾ����жϱ�־λ
    Uint16 SCD:1;               // 5      ֹͣ�źű�־λ
    Uint16 rsvd1:2;             // 7:6    Ԥ��
    Uint16 AD0:1;               // 8      ȫ0��ַ��־λ
    Uint16 AAS:1;               // 9      �ӻ���ַ��־λ
    Uint16 XSMT:1;              // 10     ������λ�Ĵ����ձ�־λ
    Uint16 RSFULL:1;            // 11     ������λ�Ĵ�������־λ
    Uint16 BB:1;                // 12     ����æ��־λ
    Uint16 NACKSNT:1;           // 13     ������Ӧ���־λ
    Uint16 SDIR:1;              // 14     �ӽڵ㷽���־λ
    Uint16 rsvd2:1;             // 15     Ԥ��
};

union I2CSTR_REG {
    Uint16                 all;
    struct I2CSTR_BITS     bit;
};

//----------------------------------------------------
/* I2Cģʽ�Ĵ�����I2CMDR��λ���� */
struct I2CMDR_BITS {            // λ����
    Uint16 BC:3;                // 2:0    I2C�շ�����λ������λ
    Uint16 FDF:1;               // 3      ȫ���ݸ�ʽʹ�ܿ���λ
    Uint16 STB:1;               // 4      ��ʼ�ֽ�ģʽ����λ
    Uint16 IRS:1;               // 5      I2Cģ�鸴λ����λ
    Uint16 DLB:1;               // 6      I2C�Բ�ģʽʹ�ܿ���λ
    Uint16 RM:1;                // 7      I2Cѭ��ģʽ����λ��������I2C���ڵ�ʹ�ã�
    Uint16 XA:1;                // 8      �����ַʹ�ܿ���λ
    Uint16 TRX:1;               // 9      ����/����ģʽ����λ
    Uint16 MST:1;               // 10     ��/��ģʽ�л�����λ
    Uint16 STP:1;               // 11     ֹͣλ��������I2C���ڵ�ʹ�ã�
    Uint16 rsvd1:1;             // 12     Ԥ��
    Uint16 STT:1;               // 13     ��ʼλ��������I2C���ڵ�ʹ�ã�
    Uint16 FREE:1;              // 14     ����ģʽ����λ
    Uint16 NACKMOD:1;           // 15     ��Ӧ��ģʽ����λ
};

union I2CMDR_REG {
    Uint16                 all;
    struct I2CMDR_BITS     bit;
};

//----------------------------------------------------
/* I2C��չģʽ���ƼĴ�����I2CEMDR��λ���� */
struct I2CEMDR_BITS {           // λ����
    Uint16 BCM:1;               // 0      ������ģʽ����λ
    Uint16 rsvd:15;             // 15     Ԥ��
};

union I2CEMDR_REG {
    Uint16                 all;
    struct I2CEMDR_BITS     bit;
};

//----------------------------------------------------
/* I2CԤ��Ƶ�Ĵ�����I2CPSC��λ���� */
struct I2CPSC_BITS {            // λ����
    Uint16 IPSC:8;              // 7:0    Ԥ��Ƶϵ������λ
    Uint16 rsvd1:8;             // 15:8   Ԥ��
};

union I2CPSC_REG {
    Uint16                 all;
    struct I2CPSC_BITS     bit;
};

//----------------------------------------------------
/* I2C����FIFO���ƼĴ�����I2CFFTX��λ���� */
struct I2CFFTX_BITS {           // λ����
    Uint16 TXFFIL:5;            // 4:0    ����FIFO��ȿ���λ
    Uint16 TXFFIENA:1;          // 5      ����FIFO�ж�ʹ�ܿ���λ
    Uint16 TXFFINTCLR:1;        // 6      ����FIFO�жϱ�־�������λ
    Uint16 TXFFINT:1;           // 7      ����FIFO�жϱ�־λ
    Uint16 TXFFST:5;            // 12:8   ����FIFO�����ݸ���
    Uint16 TXFFRST:1;           // 13     ����FIFO��λ����λ
    Uint16 I2CFFEN:1;           // 14     ����FIFOģ��ʹ�ܿ���λ
    Uint16 rsvd1:1;             // 15     Ԥ��

};

union I2CFFTX_REG {
    Uint16                 all;
    struct I2CFFTX_BITS    bit;
};

//----------------------------------------------------
/* I2C����FIFO���ƼĴ�����I2CFFRX��λ���� */
struct I2CFFRX_BITS {           // λ����
    Uint16 RXFFIL:5;            // 4:0    ����FIFO��ȿ���λ
    Uint16 RXFFIENA:1;          // 5      ����FIFO�ж�ʹ�ܿ���λ
    Uint16 RXFFINTCLR:1;        // 6      ����FIFO�жϱ�־�������λ
    Uint16 RXFFINT:1;           // 7      ����FIFO�жϱ�־λ
    Uint16 RXFFST:5;            // 12:8   ����FIFO�����ݸ���
    Uint16 RXFFRST:1;           // 13     ����FIFOģ��ʹ�ܿ���λ
    Uint16 rsvd1:2;             // 15:14  Ԥ��
};

union I2CFFRX_REG {
    Uint16                 all;
    struct I2CFFRX_BITS    bit;
};

/**************************************/
/* I2C���ƺ�״̬�Ĵ����ļ� */
/**************************************/
struct I2C_REGS {
    Uint16              I2COAR;     // I2C�����ַ�Ĵ���
    union  I2CIER_REG   I2CIER;     // I2C�ж�ʹ�ܿ��ƼĴ���
    union  I2CSTR_REG   I2CSTR;     // I2C�ж�״̬���ƼĴ���
    Uint16              I2CCLKL;    // I2Cʱ�ӷ�Ƶ�Ĵ��������֣�
    Uint16              I2CCLKH;    // I2Cʱ�ӷ�Ƶ�Ĵ��������֣�
    Uint16              I2CCNT;     // I2C���ݼ����Ĵ���
    Uint16              I2CDRR;     // I2C���ݽ��ռĴ���
    Uint16              I2CSAR;     // I2C�ӵ�ַ�Ĵ���
    Uint16              I2CDXR;     // I2C���ݷ��ͼĴ���
    union  I2CMDR_REG   I2CMDR;     // I2Cģʽ�Ĵ���
    union  I2CISRC_REG  I2CISRC;    // I2C�ж�Դ�Ĵ���
    union  I2CEMDR_REG  I2CEMDR;    // I2C��չģʽ�Ĵ���
    union  I2CPSC_REG   I2CPSC;     // I2CԤ��Ƶ�Ĵ���
    Uint16              rsvd2[19];  // Ԥ��
    union  I2CFFTX_REG  I2CFFTX;    // I2C����FIFO�Ĵ���
    union  I2CFFRX_REG  I2CFFRX;    // I2C����FIFO�Ĵ���
};

//---------------------------------------------------------------------------
// I2C�ⲿ���úͺ�������:
//
extern volatile struct I2C_REGS I2caRegs;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of AVP33x_I2C_H definition

//===========================================================================
// End of file.
//===========================================================================
