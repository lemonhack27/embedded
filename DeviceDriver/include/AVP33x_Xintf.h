/******************************************************************************
�ļ���                     : AVP33x_Xintf.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xоƬ�ⲿ���߽ӿ�ģ��Ĵ�������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_XINTF_H
#define AVP33x_XINTF_H


#ifdef __cplusplus
extern "C" {
#endif

void InitXintf(void);
//----------------------------------------------------
/* XINTFʱ��Ĵ�����XTIMING��λ���� */
struct XTIMING_BITS {       // λ����
    Uint16 XWRTRAIL:2;      // 1:0   д���ʵĸ���ʱ���еȴ����ڸ����趨λ
    Uint16 XWRACTIVE:3;     // 4:2   д���ʵ���Чʱ���еȴ����ڸ����趨λ
    Uint16 XWRLEAD:2;       // 6:5   д���ʵĽ���ʱ���еȴ����ڸ����趨λ
    Uint16 XRDTRAIL:2;      // 8:7   �����ʵĸ���ʱ���еȴ����ڸ����趨λ
    Uint16 XRDACTIVE:3;     // 11:9  �����ʵ���Чʱ���еȴ����ڸ����趨λ
    Uint16 XRDLEAD:2;       // 13:12 �����ʵĽ���ʱ���еȴ����ڸ����趨λ
    Uint16 USEREADY:1;      // 14    ����XREADY�źŲ�����ʽ����λ
    Uint16 READYMODE:1;     // 15    XREADY�źŲ�����ʽ����λ��0��ͬ��������1���첽������
    Uint16 XSIZE:2;         // 17:16 XINTF�������߿���趨λ��������Ϊ01b��11b������ֵ��Ч��
    Uint16 rsvd1:4;         // 21:18 Ԥ��
    Uint16 X2TIMING:1;      // 22    ָ��XRDLEAD��XRDACTIVE��XRDTRAIL��XWRLEAD��XWRACTIVE��XWRTRAIL��ʵ��ֵ��Ĵ������趨ֵ�ı�ֵ��
    Uint16 rsvd3:9;         // 31:23 Ԥ��
};

union XTIMING_REG {
    Uint32               all;
    struct XTIMING_BITS  bit;
};

//----------------------------------------------------
/* XINTF���üĴ�����XINTCNF2��λ���� */
struct XINTCNF2_BITS {      // λ����
    Uint16 WRBUFF:2;        // 1:0   д��������ȿ���λ
    Uint16 CLKMODE:1;       // 2     XCLKOUTʱ��Ƶ�ʿ���λ
    Uint16 CLKOFF:1;        // 3     XCLKOUTʹ�ܿ���λ
    Uint16 rsvd1:2;         // 5:4   Ԥ��
    Uint16 WLEVEL:2;        // 7:6   д����Ĵ��������ݸ���
    Uint16 rsvd2:1;         // 8     Ԥ��
    Uint16 HOLD:1;          // 9     �����ⲿ�豸����XHOLD�����źţ�������XHOLDA����ź�
    Uint16 HOLDS:1;         // 10    HOLDn��״̬��־λ
    Uint16 HOLDAS:1;        // 11    HOLDAn��״̬��־λ
    Uint16 rsvd3:4;         // 15:12 Ԥ��
    Uint16 XTIMCLK:3;       // 18:16 ����XTIMCLK��SYSCLKOUT֮��Ĺ�ϵ
    Uint16 rsvd4:13;        // 31:19 Ԥ��
};

union XINTCNF2_REG {
    Uint32                all;
    struct XINTCNF2_BITS  bit;
};

//----------------------------------------------------
/* XINTF�����л����ƼĴ�����XBANK��λ���� */
struct XBANK_BITS {         // λ����
    Uint16  BANK:3;         // 2:0   ָ��ʹ�������л����ܵ�XINTF�洢����
    Uint16  BCYC:3;         // 5:3   �����������л�ʱ�������ʱʱ��
    Uint16  rsvd:10;        // 15:6  Ԥ��
};

union XBANK_REG {
    Uint16             all;
    struct XBANK_BITS  bit;
};

//----------------------------------------------------
/* XINTF��λ�Ĵ�����XBANK��λ���� */
struct XRESET_BITS {
    Uint16  XHARDRESET:1;
    Uint16  rsvd1:15;
};

union XRESET_REG {
    Uint16            all;
    struct XRESET_BITS bit;
};

/**************************************/
/*             XINTF�Ĵ����ļ�                                  */
/**************************************/
struct XINTF_REGS {
    union XTIMING_REG XTIMING0;
    Uint32  rsvd1[5];
    union XTIMING_REG XTIMING6;
    union XTIMING_REG XTIMING7;
    Uint32  rsvd2[2];
    union XINTCNF2_REG XINTCNF2;
    Uint32  rsvd3;
    union XBANK_REG    XBANK;
    Uint16  rsvd4;
    Uint16  XREVISION;
    Uint16  rsvd5[2];
    union XRESET_REG   XRESET;
};

//---------------------------------------------------------------------------
// XINTF�ⲿ���úͺ�������:
//
extern volatile struct XINTF_REGS XintfRegs;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of AVP33x_XINTF_H definition

//===========================================================================
// No more.
//===========================================================================
