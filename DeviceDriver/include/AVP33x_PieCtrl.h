/******************************************************************************
�ļ���                     : AVP33x_PieCtrl.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xоƬPIEģ��Ĵ�������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_PIE_CTRL_H
#define AVP33x_PIE_CTRL_H

#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
/* PIE���ƼĴ�����PIECTRL��λ���� */
struct PIECTRL_BITS {       // λ����
    Uint16  ENPIE:1;        // 0    PIE�ж�������ʹ�ܿ���λ
    Uint16  PIEVECT:15;     // 15:1 PIE�ж�����
};

union PIECTRL_REG {
    Uint16               all;
    struct PIECTRL_BITS  bit;
};  

//----------------------------------------------------
/* PIE�ж�ʹ�ܼĴ�����PIEIER��λ���� */
struct PIEIER_BITS {        // λ����
    Uint16 INTx1:1;         // 0    INTx.1
    Uint16 INTx2:1;         // 1    INTx.2
    Uint16 INTx3:1;         // 2    INTx.3
    Uint16 INTx4:1;         // 3    INTx.4
    Uint16 INTx5:1;         // 4    INTx.5
    Uint16 INTx6:1;         // 5    INTx.6
    Uint16 INTx7:1;         // 6    INTx.7
    Uint16 INTx8:1;         // 7    INTx.8
    Uint16 rsvd:8;          // 15:8 Ԥ��
};

union PIEIER_REG {
    Uint16              all;
    struct PIEIER_BITS  bit;
}; 

//----------------------------------------------------
/* PIE�жϱ�־�Ĵ�����PIEIFR��λ���� */
struct PIEIFR_BITS {        // λ����
    Uint16 INTx1:1;         // 0    INTx.1
    Uint16 INTx2:1;         // 1    INTx.2
    Uint16 INTx3:1;         // 2    INTx.3
    Uint16 INTx4:1;         // 3    INTx.4
    Uint16 INTx5:1;         // 4    INTx.5
    Uint16 INTx6:1;         // 5    INTx.6
    Uint16 INTx7:1;         // 6    INTx.7
    Uint16 INTx8:1;         // 7    INTx.8
    Uint16 rsvd:8;          // 15:8 Ԥ��
};

union PIEIFR_REG {
    Uint16              all;
    struct PIEIFR_BITS  bit;
};

//----------------------------------------------------
/* PIE�ж�Ӧ��Ĵ�����PIEACK��λ���� */
struct PIEACK_BITS {        // λ����
    Uint16 ACK1:1;          // 0    PIE�ж�������1��Ӧ��־λ
    Uint16 ACK2:1;          // 1    PIE�ж�������2��Ӧ��־λ
    Uint16 ACK3:1;          // 2    PIE�ж�������3��Ӧ��־λ
    Uint16 ACK4:1;          // 3    PIE�ж�������4��Ӧ��־λ
    Uint16 ACK5:1;          // 4    PIE�ж�������5��Ӧ��־λ
    Uint16 ACK6:1;          // 5    PIE�ж�������6��Ӧ��־λ
    Uint16 ACK7:1;          // 6    PIE�ж�������7��Ӧ��־λ
    Uint16 ACK8:1;          // 7    PIE�ж�������8��Ӧ��־λ
    Uint16 ACK9:1;          // 8    PIE�ж�������9��Ӧ��־λ
    Uint16 ACK10:1;         // 9    PIE�ж�������10��Ӧ��־λ
    Uint16 ACK11:1;         // 10   PIE�ж�������11��Ӧ��־λ
    Uint16 ACK12:1;         // 11   PIE�ж�������12��Ӧ��־λ
    Uint16 rsvd:4;          // 15:12 Ԥ��
};

union PIEACK_REG {
    Uint16              all;
    struct PIEACK_BITS  bit;
};

/**************************************/
/*            PIE���ƼĴ����ļ�                                  */
/**************************************/
struct PIE_CTRL_REGS {
    union PIECTRL_REG PIECTRL;      // PIE���ƼĴ���
    union PIEACK_REG  PIEACK;       // PIEӦ��Ĵ���
    union PIEIER_REG  PIEIER1;      // PIE�ж���1ʹ�ܼĴ���
    union PIEIFR_REG  PIEIFR1;      // PIE�ж���1��־�Ĵ���
    union PIEIER_REG  PIEIER2;      // PIE�ж���2ʹ�ܼĴ���
    union PIEIFR_REG  PIEIFR2;      // PIE�ж���2��־�Ĵ���
    union PIEIER_REG  PIEIER3;      // PIE�ж���3ʹ�ܼĴ���
    union PIEIFR_REG  PIEIFR3;      // PIE�ж���3��־�Ĵ���
    union PIEIER_REG  PIEIER4;      // PIE�ж���4ʹ�ܼĴ���
    union PIEIFR_REG  PIEIFR4;      // PIE�ж���4��־�Ĵ���
    union PIEIER_REG  PIEIER5;      // PIE�ж���5ʹ�ܼĴ���
    union PIEIFR_REG  PIEIFR5;      // PIE�ж���5��־�Ĵ���
    union PIEIER_REG  PIEIER6;      // PIE�ж���6ʹ�ܼĴ���
    union PIEIFR_REG  PIEIFR6;      // PIE�ж���6��־�Ĵ���
    union PIEIER_REG  PIEIER7;      // PIE�ж���7ʹ�ܼĴ���
    union PIEIFR_REG  PIEIFR7;      // PIE�ж���7��־�Ĵ���
    union PIEIER_REG  PIEIER8;      // PIE�ж���8ʹ�ܼĴ���
    union PIEIFR_REG  PIEIFR8;      // PIE�ж���8��־�Ĵ���
    union PIEIER_REG  PIEIER9;      // PIE�ж���9ʹ�ܼĴ���
    union PIEIFR_REG  PIEIFR9;      // PIE�ж���9��־�Ĵ���
    union PIEIER_REG  PIEIER10;     // PIE�ж���10ʹ�ܼĴ���
    union PIEIFR_REG  PIEIFR10;     // PIE�ж���10��־�Ĵ���
    union PIEIER_REG  PIEIER11;     // PIE�ж���11ʹ�ܼĴ���
    union PIEIFR_REG  PIEIFR11;     // PIE�ж���11��־�Ĵ���
    union PIEIER_REG  PIEIER12;     // PIE�ж���12ʹ�ܼĴ���
    union PIEIFR_REG  PIEIFR12;     // PIE�ж���12��־�Ĵ���
};     

#define PIEACK_GROUP1   0x0001
#define PIEACK_GROUP2   0x0002
#define PIEACK_GROUP3   0x0004
#define PIEACK_GROUP4   0x0008
#define PIEACK_GROUP5   0x0010
#define PIEACK_GROUP6   0x0020
#define PIEACK_GROUP7   0x0040
#define PIEACK_GROUP8   0x0080
#define PIEACK_GROUP9   0x0100
#define PIEACK_GROUP10  0x0200
#define PIEACK_GROUP11  0x0400
#define PIEACK_GROUP12  0x0800

//---------------------------------------------------------------------------
// PIE���ƼĴ����ⲿ���úͺ�������:
//
extern volatile struct PIE_CTRL_REGS PieCtrlRegs;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of AVP33x_PIE_CTRL_H definition

//===========================================================================
// End of file.
//===========================================================================
