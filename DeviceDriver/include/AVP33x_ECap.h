/******************************************************************************
�ļ���                     : AVP33x_ECap.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33x��ǿ�Ͳ���ģ��Ĵ���λ����
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_ECAP_H
#define AVP33x_ECAP_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// eCAP���ƼĴ�1��ECCTL1��λ����  */
struct ECCTL1_BITS {            // λ����
    Uint16 CAP1POL:1;           // 0      CAP1��׽��ѡ�����λ
    Uint16 CTRRST1:1;           // 1      ��CAP1�¼����Ƿ����ü���������λλ
    Uint16 CAP2POL:1;           // 2      CAP2��׽��ѡ�����λ
    Uint16 CTRRST2:1;           // 3      ��CAP2�¼����Ƿ����ü���������λλ
    Uint16 CAP3POL:1;           // 4      CAP3��׽��ѡ�����λ
    Uint16 CTRRST3:1;           // 5      ��CAP3�¼����Ƿ����ü���������λλ
    Uint16 CAP4POL:1;           // 6      CAP4��׽��ѡ�����λ
    Uint16 CTRRST4:1;           // 7      ��CAP4�¼����Ƿ����ü���������λλ
    Uint16 CAPLDEN:1;           // 8      �ڲ����¼���CAP1-4�Ĵ����ļ���ʹ�ܿ���λ
    Uint16 PRESCALE:5;          // 13:9   �����źŷ�Ƶѡ�����λ
    Uint16 FREE_SOFT:2;         // 15:14  ����ģʽ����λ
};

union ECCTL1_REG {
    Uint16              all;
    struct ECCTL1_BITS  bit;
};

//----------------------------------------------------
// eCAP���ƼĴ�2��ECCTL2��λ���� */
struct ECCTL2_BITS {            // λ����
    Uint16 CONT_ONESHT:1;       // 0      ����ģʽ����λ��0������ģʽ��1������ģʽ��
    Uint16 STOP_WRAP:2;         // 2:1    ����/����ģʽ�µ�ֵֹͣ
    Uint16 REARM:1;             // 3      ����ģʽ�£����¼��ؿ���λ
    Uint16 TSCTRSTOP:1;         // 4      ��������ͣ����λ
    Uint16 SYNCI_EN:1;          // 5      ��������TSCTR��ͬ������ѡ��ģʽ
    Uint16 SYNCO_SEL:2;         // 7:6    ͬ���ź��������ѡ�����λ
    Uint16 SWSYNC:1;            // 8      ���ǿ�Ƽ�����ͬ������λ
    Uint16 CAP_APWM:1;          // 9      CAP��APWMģʽѡ�����λ
    Uint16 APWMPOL:1;           // 10     APWM�������ѡ�����λ
    Uint16 rsvd1:5;             // 15:11  Ԥ��
};

union ECCTL2_REG {
    Uint16              all;
    struct ECCTL2_BITS  bit;
};

//----------------------------------------------------
// eCAP�ж�ʹ�ܼĴ棨ECEINT��λ���� */
struct ECEINT_BITS {            // λ����
    Uint16 rsvd1:1;             // 0      Ԥ��
    Uint16 CEVT1:1;             // 1      ����1�ж�ʹ�ܿ���λ
    Uint16 CEVT2:1;             // 2      ����2�ж�ʹ�ܿ���λ
    Uint16 CEVT3:1;             // 3      ����3�ж�ʹ�ܿ���λ
    Uint16 CEVT4:1;             // 4      ����4�ж�ʹ�ܿ���λ
    Uint16 CTROVF:1;            // 5      ��������ж�ʹ�ܿ���λ
    Uint16 CTR_EQ_PRD:1;        // 6      ����������ƥ���ж�ʹ�ܿ���λ
    Uint16 CTR_EQ_CMP:1;        // 7      �������Ƚ�ƥ���ж�ʹ�ܿ���λ
    Uint16 rsvd2:8;             // 15:8   Ԥ��
};

union ECEINT_REG {
    Uint16              all;
    struct ECEINT_BITS  bit;
};

//----------------------------------------------------
// eCAP�жϱ�־�Ĵ棨ECFLG��λ���� */
struct ECFLG_BITS {             // λ����
    Uint16 INT:1;               // 0      eCAPȫ���жϱ�־
    Uint16 CEVT1:1;             // 1      ����1�жϱ�־λ
    Uint16 CEVT2:1;             // 2      ����2�жϱ�־λ
    Uint16 CEVT3:1;             // 3      ����3�жϱ�־λ
    Uint16 CEVT4:1;             // 4      ����4�жϱ�־λ
    Uint16 CTROVF:1;            // 5      ��������жϱ�־λ
    Uint16 CTR_EQ_PRD:1;        // 6      ����������ƥ���жϱ�־λ
    Uint16 CTR_EQ_CMP:1;        // 7      �������Ƚ�ƥ���жϱ�־λ
    Uint16 rsvd2:8;             // 15:8   Ԥ��
};

union ECFLG_REG {
    Uint16              all;
    struct ECFLG_BITS   bit;
};

/**************************************/
/* eCAP���ƺ�״̬�Ĵ����ļ� */
/**************************************/
struct ECAP_REGS {
    Uint32              TSCTR;      // eCAP�������Ĵ���
    Uint32              CTRPHS;     // eCAP��λ�Ĵ���
    Uint32              CAP1;       // eCAP1�Ĵ���
    Uint32              CAP2;       // eCAP2�Ĵ���
    Uint32              CAP3;       // eCAP3�Ĵ���
    Uint32              CAP4;       // eCAP4�Ĵ���
    Uint16              rsvd1[8];   // Ԥ��
    union   ECCTL1_REG  ECCTL1;     // eCAP���ƼĴ���1
    union   ECCTL2_REG  ECCTL2;     // eCAP���ƼĴ���2
    union   ECEINT_REG  ECEINT;     // eCAP�ж�ʹ�ܿ��ƼĴ�
    union   ECFLG_REG   ECFLG;      // eCAP�жϱ�־�Ĵ���
    union   ECFLG_REG   ECCLR;      // eCAP�жϱ�־����Ĵ���
    union   ECEINT_REG  ECFRC;      // eCAPǿ���жϿ��ƼĴ���
    Uint16              rsvd2[6];   // Ԥ��
};


//---------------------------------------------------------------------------
// eCAP�ⲿ���úͺ�������:
//
extern volatile struct ECAP_REGS ECap1Regs;
extern volatile struct ECAP_REGS ECap2Regs;
extern volatile struct ECAP_REGS ECap3Regs;
extern volatile struct ECAP_REGS ECap4Regs;
extern volatile struct ECAP_REGS ECap5Regs;
extern volatile struct ECAP_REGS ECap6Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of AVP33x_ECAP_H definition

//===========================================================================
// End of file.
//===========================================================================
