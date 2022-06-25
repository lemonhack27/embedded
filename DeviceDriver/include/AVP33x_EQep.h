/******************************************************************************
�ļ���                     : AVP33x_EQep.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33x��ǿ����������ģ��Ĵ���λ����
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_EQEP_H
#define AVP33x_EQEP_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
/* QEP������ƼĴ�����QDECCTL��λ���� */
struct QDECCTL_BITS {           // λ����
    Uint16 rsvd1:5;             // 4:0    Ԥ��
    Uint16 QSP:1;               // 5      QEPS���뼫�Կ���λ
    Uint16 QIP:1;               // 6      QEPI���뼫�Կ���λ
    Uint16 QBP:1;               // 7      QEPB���뼫�Կ���λ
    Uint16 QAP:1;               // 8      QEPA���뼫�Կ���λ
    Uint16 IGATE:1;             // 9      ��������ѡͨʹ�ܿ���λ
    Uint16 SWAP:1;              // 10     ����ʱ�ӱ任����ʹ�ܿ���λ
    Uint16 XCR:1;               // 11     �ⲿʱ�Ӽ���ģʽѡ�����λ��0�����±��ض�������1�������ؼ�����
    Uint16 SPSEL:1;             // 12     ͬ���ź�����ѡ�����λ��0��Index�������������1��Strobe�������������
    Uint16 SOEN:1;              // 13     ͬ���ź����ʹ�ܿ���λ��0����ֹλ�ñȽ�ͬ���ź������1��ʹ��λ�ñȽ�ͬ���ź������
    Uint16 QSRC:2;              // 15:14  λ�ü�����Դѡ�����λ��00����������ģʽ��01��ֱ�Ӽ���ģʽ��10�����ϼ���ģʽ��11�����¼���ģʽ��
};

union QDECCTL_REG {
    Uint16              all;
    struct QDECCTL_BITS   bit;
};

//----------------------------------------------------
/* QEP���ƼĴ�����QEPCTL��λ���� */
struct QEPCTL_BITS {            // λ����
    Uint16 WDE:1;               // 0      QEP���Ź�ʹ�ܿ���λ��0����ֹQEP���Ź���1��ʹ��QEP���Ź���
    Uint16 UTE:1;               // 1      QEP��λ��ʱ��ʹ�ܿ���λ��0����ֹ��ʱ����1��ʹ�ܶ�ʱ����
    Uint16 QCLM:1;              // 2      QEP��������ģʽ����λ
    Uint16 QPEN:1;              // 3      ����λ�ü�����ʹ�ܿ���λ
    Uint16 IEL:2;               // 5:4    �����¼�����λ�ü�����
    Uint16 SEL:1;               // 6      �����¼�����λ�ü�����
    Uint16 SWI:1;               // 7      �����ʼ��λ�ü�����
    Uint16 IEI:2;               // 9:8    �����¼���ʼλ�ü�����
    Uint16 SEI:2;               // 11:10  �����¼���ʼλ�ü�����
    Uint16 PCRM:2;              // 13:12  λ�ü�������λģʽ
    Uint16 FREE_SOFT:2;         // 15:14  ����ģʽ����λ
};

union QEPCTL_REG {
    Uint16               all;
    struct QEPCTL_BITS   bit;
};         

//----------------------------------------------------
/* QEP������ƼĴ�����QCAPCTL��λ���� */
struct QCAPCTL_BITS {           // λ����
    Uint16 UPPS:4;              // 3:0    ��λλ���¼���Ƶϵ������λ
    Uint16 CCPS:3;              // 6:4    QEP����ʱ�ӷ�Ƶϵ��
    Uint16 rsvd1:8;             // 14:7   Ԥ��
    Uint16 CEN:1;               // 15     QEP������ʹ�ܿ���λ
};

union QCAPCTL_REG {
    Uint16               all;
    struct QCAPCTL_BITS  bit;
}; 

//----------------------------------------------------
/* QEP����λ�ñȽϿ��ƼĴ�����QCAPCTL��λ���� */
struct QPOSCTL_BITS {           // λ����
    Uint16 PCSPW:12;            // 11:0   ѡ��λ�ñȽ�ͬ����������ȿ���λ
    Uint16 PCE:1;               // 12     λ�ñȽϹ���ʹ�ܿ���λ��0����ֹ��1��ʹ�ܣ�
    Uint16 PCPOL:1;             // 13     ͬ���ź��������
    Uint16 PCLOAD:1;            // 14     λ�ñȽ�Ӱ��ӳ�����ģʽ����λ
    Uint16 PCSHDW:1;            // 15     λ�ñȽ�Ӱ��ӳ��ʹ�ܿ���λ
};

union QPOSCTL_REG {
    Uint16               all;
    struct QPOSCTL_BITS  bit;
};         

//----------------------------------------------------
/* QEP�ж�ʹ�ܼĴ�����QEINT��λ���� */
struct QEINT_BITS {             // λ����
    Uint16 rsvd1:1;             // 0      Ԥ��
    Uint16 PCE:1;               // 1      λ�ü����������ж�ʹ�ܿ���λ
    Uint16 QPE:1;               // 2      ������λ�����ж�ʹ�ܿ���λ
    Uint16 QDC:1;               // 3      ���Ź�����ı��ж�ʹ�ܿ���λ
    Uint16 WTO:1;               // 4      ���Ź���ʱ�ж�ʹ�ܿ���λ
    Uint16 PCU:1;               // 5      λ�ü��������ж�ʹ�ܿ���λ
    Uint16 PCO:1;               // 6      λ�ü��������ж�ʹ�ܿ���λ
    Uint16 PCR:1;               // 7      λ�ñȽ�׼���ж�ʹ�ܿ���λ
    Uint16 PCM:1;               // 8      λ�ñȽ�ƥ���ж�ʹ�ܿ���λ
    Uint16 SEL:1;               // 9      λ���¼������ж�ʹ�ܿ���λ
    Uint16 IEL:1;               // 10     �����¼������ж�ʹ�ܿ���λ
    Uint16 UTO:1;               // 11     ��λʱ���¼��ж�ʹ�ܿ���λ
    Uint16 rsvd2:4;             // 15:12  Ԥ��
};

union QEINT_REG {
    Uint16               all;
    struct QEINT_BITS    bit;
};

//----------------------------------------------------
/* QEP�жϱ�־�Ĵ�����QFLG��λ���� */
struct QFLG_BITS {              // λ����
    Uint16 INT:1;               // 0      QEPȫ���жϱ�־λ
    Uint16 PCE:1;               // 1      λ�ü����������жϱ�־λ
    Uint16 PHE:1;               // 2      ������λ�����жϱ�־λ
    Uint16 QDC:1;               // 3      ���Ź�����ı��жϱ�־λ
    Uint16 WTO:1;               // 4      ���Ź���ʱ�жϱ�־λ
    Uint16 PCU:1;               // 5      λ�ü��������жϱ�־λ
    Uint16 PCO:1;               // 6      λ�ü��������жϱ�־λ
    Uint16 PCR:1;               // 7      λ�ñȽ�׼���жϱ�־λ
    Uint16 PCM:1;               // 8      λ�ñȽ�ƥ���жϱ�־λ
    Uint16 SEL:1;               // 9      λ���¼������жϱ�־λ
    Uint16 IEL:1;               // 10     �����¼������жϱ�־λ
    Uint16 UTO:1;               // 11     ��λʱ���¼��жϱ�־λ
    Uint16 rsvd2:4;             // 15:12  Ԥ��
};

union QFLG_REG {
    Uint16               all;
    struct QFLG_BITS     bit;
};

//----------------------------------------------------
/* QEP�ж�ǿ�ƼĴ�����QFRC��λ���� */
struct QFRC_BITS {              // λ����
    Uint16 reserved:1;          // 0      Ԥ��
    Uint16 PCE:1;               // 1      ǿ��λ�ü����������жϿ���λ
    Uint16 PHE:1;               // 2      ǿ��������λ�����жϿ���λ
    Uint16 QDC:1;               // 3      ǿ�ƿ��Ź�����ı��жϿ���λ
    Uint16 WTO:1;               // 4      ǿ�ƿ��Ź���ʱ�жϿ���λ
    Uint16 PCU:1;               // 5      ǿ��λ�ü��������жϿ���λ
    Uint16 PCO:1;               // 6      ǿ��λ�ü��������жϿ���λ
    Uint16 PCR:1;               // 7      ǿ��λ�ñȽ�׼���жϿ���λ
    Uint16 PCM:1;               // 8      ǿ��λ�ñȽ�ƥ���жϿ���λ
    Uint16 SEL:1;               // 9      ǿ��λ���¼������жϿ���λ
    Uint16 IEL:1;               // 10     ǿ�������¼������жϿ���λ
    Uint16 UTO:1;               // 11     ǿ�Ƶ�λʱ���¼��жϿ���λ
    Uint16 rsvd2:4;             // 15:12  Ԥ��
};

union QFRC_REG {
    Uint16               all;
    struct QFRC_BITS     bit;
};

//----------------------------------------------------
/* QEP״̬�Ĵ�����QEPSTS��λ���� */
struct QEPSTS_BITS {            // λ����
    Uint16 PCEF:1;              // 0      λ�ü���������״̬��־λ
    Uint16 FIMF:1;              // 1      ��һ��������Ǳ�־λ
    Uint16 CDEF:1;              // 2      ����������־λ
    Uint16 COEF:1;              // 3      ������������־λ
    Uint16 QDLF:1;              // 4      QEP���������־λ
    Uint16 QDF:1;               // 5      ���������־λ
    Uint16 FIDF:1;              // 6      ��һ��������Ƿ����־λ
    Uint16 UPEVNT:1;            // 7      ��λλ���¼���־λ
    Uint16 rsvd1:8;             // 15:8   Ԥ��
};

union QEPSTS_REG {
    Uint16               all;
    struct QEPSTS_BITS   bit;
};

/**************************************/
/* QEP���ƺ�״̬�Ĵ����ļ� */
/**************************************/
struct EQEP_REGS {
    Uint32              QPOSCNT;    // QEPλ�ü������Ĵ���
    Uint32              QPOSINIT;   // QEPλ�ü�������ʼ���Ĵ���
    Uint32              QPOSMAX;    // QEP���λ�ü������Ĵ���
    Uint32              QPOSCMP;    // QEPλ�ñȽϼĴ���
    Uint32              QPOSILAT;   // QEP����λ�ü��ؼĴ���
    Uint32              QPOSSLAT;   // QEP���λ�ü��ؼĴ���
    Uint32              QPOSLAT;    // QEPλ�ü��ؼĴ���
    Uint32              QUTMR;      // QEP��λʱ��Ĵ���
    Uint32              QUPRD;      // QEP��λ���ڼĴ���
    Uint16              QWDTMR;     // QEP���Ź���ʱ�����Ĵ���
    Uint16              QWDPRD;     // QEP���Ź����ڼĴ���
    union  QDECCTL_REG  QDECCTL;    // QEP������ƼĴ���
    union  QEPCTL_REG   QEPCTL;     // QEP���ƼĴ���
    union  QCAPCTL_REG  QCAPCTL;    // QEP������ƼĴ���
    union  QPOSCTL_REG  QPOSCTL;    // QEPλ�ñȽϿ��ƼĴ���
    union  QEINT_REG    QEINT;      // QEP�жϿ��ƼĴ���
    union  QFLG_REG     QFLG;       // QEP�жϱ�־�Ĵ���
    union  QFLG_REG     QCLR;       // QEP�жϱ�־����Ĵ���
    union  QFRC_REG     QFRC;       // QEP�ж�ǿ�ƼĴ���
    union  QEPSTS_REG   QEPSTS;     // QEP״̬�Ĵ���
    Uint16              QCTMR;      // QEP����ʱ���Ĵ���
    Uint16              QCPRD;      // QEP�������ڼĴ���
    Uint16              QCTMRLAT;   // QEP����ʱ����Ĵ���
    Uint16              QCPRDLAT;   // QEP������������Ĵ���
    Uint16              rsvd1[30];  // Ԥ��
};

//---------------------------------------------------------------------------
// QEP�ⲿ���úͺ�������:
//
extern volatile struct EQEP_REGS EQep1Regs;
extern volatile struct EQEP_REGS EQep2Regs;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of AVP33x_EQEP_H definition

//===========================================================================
// End of file.
//===========================================================================
