/******************************************************************************
�ļ���                     : AVP33x_XIntrupt.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xоƬ�ⲿ�ж�ģ��Ĵ�������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_XINTRUPT_H
#define AVP33x_XINTRUPT_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
/* �ⲿ�жϿ��ƼĴ�����XINTCR��λ���� */
struct XINTCR_BITS {
    Uint16   ENABLE:1;      // 0      XINTn��n=1~7���ⲿ�ж�ʹ�ܿ���λ
    Uint16   rsvd1:1;       // 1      Ԥ��
    Uint16   POLARITY:2;    // 3:2    �����ź�ѡ���жϴ������أ�00���½��ش����жϣ�01�������ش����жϣ�10���½��ش����жϣ�11�������غ��½��ض������жϡ���
    Uint16   rsvd2:12;      //15:4    Ԥ��
};

union XINTCR_REG {
    Uint16               all;
    struct XINTCR_BITS   bit;
};  

//----------------------------------------------------
/* �ⲿ�жϿ��ƼĴ�����XNMICR��λ���� */
struct XNMICR_BITS {
    Uint16   ENABLE:1;      // 0      XNMI�ж�ʹ�ܿ���λ
    Uint16   SELECT:1;      // 1      CPU��INT13ѡ���ж�Դ��0��Timer1�ж������ź����ӵ�INT13��1��XNMI_XINT13�ж������ź����ӵ�INT13��
    Uint16   POLARITY:2;    // 3:2    �����ź�XNMIѡ���жϴ�����
    Uint16   rsvd2:12;      // 15:4   Ԥ��
};

union XNMICR_REG {
    Uint16               all;
    struct XNMICR_BITS   bit;
};  

/**************************************/
/*            �ⲿ�жϼĴ����ļ�                                    */
/**************************************/
struct XINTRUPT_REGS {
    union XINTCR_REG XINT1CR;
    union XINTCR_REG XINT2CR;
    union XINTCR_REG XINT3CR;
    union XINTCR_REG XINT4CR;
    union XINTCR_REG XINT5CR;
    union XINTCR_REG XINT6CR;
    union XINTCR_REG XINT7CR;
    union XNMICR_REG XNMICR;
    Uint16           XINT1CTR;
    Uint16           XINT2CTR;
    Uint16           rsvd[5];
    Uint16           XNMICTR;
};

//----------------------------------------------------
// �ⲿ�ж��ⲿ���úͺ�������:
//
extern volatile struct XINTRUPT_REGS XIntruptRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of AVP33x_XINTF_H definition

//===========================================================================
// End of file.
//===========================================================================
