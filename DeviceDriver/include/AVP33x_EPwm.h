/******************************************************************************
�ļ���                     : AVP33x_EPwm.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33x��ǿ��PWMģ��Ĵ���λ����
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_EPWM_H
#define AVP33x_EPWM_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
/* ʱ�����ƼĴ�����TBCTL��λ���� */
struct TBCTL_BITS {             // λ����
    Uint16 CTRMODE:2;           // 1:0    ����ģʽ����λ
    Uint16 PHSEN:1;             // 2      �����Ĵ���װ����λ�Ĵ���ʹ��λ
    Uint16 PRDLD:1;             // 3      ���ڼĴ���װ�����ڼĴ�����Ӱ�ӼĴ���ʹ��λ
    Uint16 SYNCOSEL:2;          // 5:4    ͬ���ź����ʱ��ѡ��λ
    Uint16 SWFSYNC:1;           // 6      ���ǿ��ͬ�������������λ
    Uint16 HSPCLKDIV:3;         // 9:7    ����ʱ�ӷ�Ƶϵ������λ
    Uint16 CLKDIV:3;            // 12:10  ʱ��ʱ�ӷ�Ƶϵ������λ
    Uint16 PHSDIR:1;            // 13     ��λ�������λ
    Uint16 FREE_SOFT:2;         // 15:14  ����ģʽ����λ
};

union TBCTL_REG {
    Uint16              all;
    struct TBCTL_BITS   bit;
};

//----------------------------------------------------
/* ʱ��״̬�Ĵ���λ��TBSTS������   */
struct TBSTS_BITS {             // λ����
    Uint16 CTRDIR:1;            // 0      ʱ����������״̬λ
    Uint16 SYNCI:1;             // 1      ͬ�������ź�״̬λ
    Uint16 CTRMAX:1;            // 2      ʱ���������Ƿ���������ֵ��0xFFFF����ʶλ
    Uint16 rsvd1:13;            // 15:3   Ԥ��
};

union TBSTS_REG {
   Uint16              all;
   struct TBSTS_BITS   bit;
};

//----------------------------------------------------
/* �ȽϿ��ƼĴ�����CMPCTL��λ����   */
struct CMPCTL_BITS {            // λ����
    Uint16 LOADAMODE:2;         // 0:1    CMPAӰ��װ��ģʽ�£�װ������ѡ�����λ
    Uint16 LOADBMODE:2;         // 3:2    CMPBӰ��װ��ģʽ�£�װ������ѡ�����λ
    Uint16 SHDWAMODE:1;         // 4      �����Ƚ�A�Ĵ�������ģʽ����λ
    Uint16 rsvd1:1;             // 5      Ԥ��
    Uint16 SHDWBMODE:1;         // 6      �����Ƚ�B�Ĵ�������ģʽ����λ
    Uint16 rsvd2:1;             // 7      Ԥ��
    Uint16 SHDWAFULL:1;         // 8      CMPAӰ�ӼĴ�������־λ
    Uint16 SHDWBFULL:1;         // 9      CMPBӰ�ӼĴ�������־λ
    Uint16 rsvd3:6;             // 15:10  Ԥ��
};

union CMPCTL_REG {
   Uint16                all;
   struct CMPCTL_BITS    bit;
};

//----------------------------------------------------
/* �������ƼĴ�����AQCTLx��λ����  */
struct AQCTL_BITS {             // λ����
    Uint16 ZRO:2;               // 1:0    ��ʱ����������ֵ=0ʱ����
    Uint16 PRD:2;               // 3:2    ��ʱ����������ֵ=���ڼĴ�����ֵʱ����
    Uint16 CAU:2;               // 5:4    �����ϼ���ʱ����ʱ����������ֵ=CMPA�Ĵ�����ֵʱ����
    Uint16 CAD:2;               // 7:6    �����¼���ʱ����ʱ����������ֵ=CMPA�Ĵ�����ֵʱ����
    Uint16 CBU:2;               // 9:8    �����ϼ���ʱ����ʱ����������ֵ=CMPB�Ĵ�����ֵʱ����
    Uint16 CBD:2;               // 11:10  �����¼���ʱ����ʱ����������ֵ=CMPB�Ĵ�����ֵʱ����
    Uint16 rsvd:4;              // 15:12  Ԥ��
};

union AQCTL_REG {
   Uint16                all;
   struct AQCTL_BITS     bit;
};

//----------------------------------------------------
/* ������ƶ����Ĵ�����AQSFRC��λ����  */
struct AQSFRC_BITS {            // λ����
    Uint16 ACTSFA:2;            // 1:0    ��һ�������ǿ��A���������ʱ�Ķ���
    Uint16 OTSFA:1;             // 2      һ�������ǿ��ePWMxA���
    Uint16 ACTSFB:2;            // 4:3    ��һ�������ǿ��B���������ʱ�Ķ���
    Uint16 OTSFB:1;             // 5      һ�������ǿ��ePWMxB���
    Uint16 RLDCSF:2;            // 7:6    AQCSF��Ч�Ĵ���װ��Ӱ�ӼĴ���������
    Uint16 rsvd1:8;             // 15:8   Ԥ��
};

union AQSFRC_REG {
    Uint16                 all;
    struct AQSFRC_BITS     bit;
};

//----------------------------------------------------
/* ����������ƶ����Ĵ�����AQCSFRC��λ���� */
struct AQCSFRC_BITS {           // λ����
    Uint16 CSFA:2;              // 1:0    �����������A���
    Uint16 CSFB:2;              // 3:2    �����������B���
    Uint16 rsvd1:12;            // 15:4   Ԥ��
};

union AQCSFRC_REG {
    Uint16                  all;
    struct AQCSFRC_BITS     bit;
};

//----------------------------------------------------
/* �������ƼĴ�����DBCTL��λ���� */
struct DBCTL_BITS {             // λ����
    Uint16 OUT_MODE:2;          // 1:0    ����ģ���������λ
    Uint16 POLSEL:2;            // 3:2    ����ѡ�����λ
    Uint16 IN_MODE:2;           // 5:4    ����ģ���������λ
    Uint16 rsvd1:10;            // 15:4   Ԥ��
};

union DBCTL_REG {
   Uint16                  all;
   struct DBCTL_BITS       bit;
};

//----------------------------------------------------
/* ��������ѡ��Ĵ�����TZSEL��λ����  */
struct TZSEL_BITS {             // λ����
    Uint16  CBC1:1;             // 0      CBC��������1ѡ��TZ1�����ڴ�����������λ
    Uint16  CBC2:1;             // 1      CBC��������2ѡ��TZ2�����ڴ�����������λ
    Uint16  CBC3:1;             // 2      CBC��������3ѡ��TZ3�����ڴ�����������λ
    Uint16  CBC4:1;             // 3      CBC��������4ѡ��TZ4�����ڴ�����������λ
    Uint16  CBC5:1;             // 4      CBC��������5ѡ��TZ5�����ڴ�����������λ
    Uint16  CBC6:1;             // 5      CBC��������6ѡ��TZ6�����ڴ�����������λ
    Uint16  rsvd1:2;            // 7:6    Ԥ��
    Uint16  OSHT1:1;            // 8      One-shot����1����ѡ��TZ1�����δ�������
    Uint16  OSHT2:1;            // 9      One-shot����2����ѡ��TZ2�����δ�������
    Uint16  OSHT3:1;            // 10     One-shot����3����ѡ��TZ3�����δ�������
    Uint16  OSHT4:1;            // 11     One-shot����4����ѡ��TZ4�����δ�������
    Uint16  OSHT5:1;            // 12     One-shot����5����ѡ��TZ5�����δ�������
    Uint16  OSHT6:1;            // 13     One-shot����6����ѡ��TZ5�����δ�������
    Uint16  rsvd2:2;            // 15:14  Ԥ��
};

union TZSEL_REG {
    Uint16                  all;
    struct TZSEL_BITS       bit;
};

//----------------------------------------------------
/* �����������ƼĴ�����TZCTL��λ���� */
struct TZCTL_BITS {             // λ����
    Uint16 TZA:2;               // 1:0    ��������ʱ��TZ1~TZ6����EPWMxA�����״̬����λ
    Uint16 TZB:2;               // 3:2    ��������ʱ��TZ1~TZ6����EPWMxB�����״̬����λ
    Uint16 rsvd:12;             // 15:4   Ԥ��
};

union TZCTL_REG {
    Uint16                  all;
    struct TZCTL_BITS       bit;
};

//----------------------------------------------------
/* ���������ж�ʹ�ܼĴ�����TZEINT��λ���� */
struct TZEINT_BITS {            // λ����
    Uint16  rsvd1:1;            // 0      Ԥ��
    Uint16  CBC:1;              // 1      CBC�ж�ʹ��λ
    Uint16  OST:1;              // 2      One-Shot�ж�ʹ��λ
    Uint16  rsvd2:13;           // 15:3   Ԥ��
};   

union TZEINT_REG {
   Uint16                  all;
   struct TZEINT_BITS      bit;
};

//----------------------------------------------------
/* ���������жϱ�־�Ĵ�����TZFLG��λ���� */
struct TZFLG_BITS {             // λ����
    Uint16  INT:1;              // 0      ȫ���ж�״̬λ
    Uint16  CBC:1;              // 1      CBC�ж�״̬λ
    Uint16  OST:1;              // 2      One-Shot�ж�״̬λ
    Uint16  rsvd2:13;           // 15:3   Ԥ��
};

union TZFLG_REG {
    Uint16                  all;
    struct TZFLG_BITS       bit;
};

//----------------------------------------------------
/* ���������жϱ�־����Ĵ�����TZCLR��λ���� */
struct TZCLR_BITS {             // λ����
    Uint16  INT:1;              // 0      ePWMȫ���жϱ�־�������λ
    Uint16  CBC:1;              // 1      CBC�жϱ�־�������λ
    Uint16  OST:1;              // 2      One-Shot�жϱ�־�������λ
    Uint16  rsvd2:13;           // 15:3   Ԥ��
};

union TZCLR_REG {
    Uint16                  all;
    struct TZCLR_BITS       bit;
};

//----------------------------------------------------
/* ���������ж�ǿ�ƼĴ�����TZFRC��λ���� */
struct TZFRC_BITS {             // λ����
    Uint16  rsvd1:1;            // 0      Ԥ��
    Uint16  CBC:1;              // 1      ���ǿ�����ڣ�CBC���ж�
    Uint16  OST:1;              // 2      ���ǿ�Ƶ��Σ�One-Shot���ж�
    Uint16  rsvd2:13;           // 15:3   Ԥ��
};

union TZFRC_REG {
    Uint16                  all;
    struct TZFRC_BITS       bit;
};

//----------------------------------------------------
/* �¼�����ѡ��Ĵ�����ETSEL��λ���� */
struct ETSEL_BITS {             // λ����
    Uint16  INTSEL:3;           // 2:0    ePWM�ж�ʱ��ѡ�����λ
    Uint16  INTEN:1;            // 3      ePWM�ж�ʹ�ܿ���λ
    Uint16  rsvd1:4;            // 7:4    Ԥ��
    Uint16  SOCASEL:3;          // 10:8   ePWMxSOCA�źŲ�����������λ
    Uint16  SOCAEN:1;           // 11     ePWMxSOCA�źŲ���ʹ�ܿ���λ
    Uint16  SOCBSEL:3;          // 14:12  ePWMxSOCB�źŲ�����������λ
    Uint16  SOCBEN:1;           // 15     ePWMxSOCB�źŲ���ʹ�ܿ���λ
};

union ETSEL_REG {
    Uint16                  all;
    struct ETSEL_BITS       bit;
};

//----------------------------------------------------
/* �¼�������Ƶ�Ĵ�����ETPS��λ���� */
struct ETPS_BITS {              // λ����
    Uint16  INTPRD:2;           // 1:0    EPWMx�жϲ���ʱ�̿���λ
    Uint16  INTCNT:2;           // 3:2    EPWMx�жϲ�����������λ
    Uint16  rsvd1:4;            // 7:4    Ԥ��
    Uint16  SOCAPRD:2;          // 9:8    ePWMxSOCA�źŲ�����������λ
    Uint16  SOCACNT:2;          // 11:10  ePWMxSOCA�źŲ�����������λ
    Uint16  SOCBPRD:2;          // 13:12  ePWMxSOCB�źŲ�����������λ
    Uint16  SOCBCNT:2;          // 15:14  ePWMxSOCB�źŲ�����������λ
};

union ETPS_REG {
    Uint16                  all;
    struct ETPS_BITS        bit;
};

//----------------------------------------------------
/* �¼�������־�Ĵ�����ETPS��λ���� */
struct ETFLG_BITS {             // λ����
    Uint16  INT:1;              // 0	EPWMx�жϱ�־λ
    Uint16  rsvd1:1;            // 1	Ԥ��
    Uint16  SOCA:1;             // 2	ePWMxSOCA�źŲ�����־
    Uint16  SOCB:1;             // 3	ePWMxSOCB�źŲ�����־
    Uint16  rsvd2:12;           // 15:4	Ԥ��
};

union ETFLG_REG {
   Uint16                   all;
   struct ETFLG_BITS        bit;
};

//----------------------------------------------------
/* �¼�������־����Ĵ�����ETCLR��λ���� */
struct ETCLR_BITS {             // λ����
    Uint16  INT:1;              // 0	EPWMx�жϱ�־���λ
    Uint16  rsvd1:1;            // 1	Ԥ��
    Uint16  SOCA:1;             // 2	ePWMxSOCA�źŲ�����־���λ
    Uint16  SOCB:1;             // 3	ePWMxSOCB�źŲ�����־���λ
    Uint16  rsvd2:12;           // 15:4	Ԥ��
};

union ETCLR_REG {
   Uint16                   all;
   struct ETCLR_BITS        bit;
};

//----------------------------------------------------
/* ǿ���¼������Ĵ�����ETFRC��λ���� */
struct ETFRC_BITS {             // λ����
    Uint16  INT:1;              // 0	EPWMx�ж�ǿ�ƿ���λ
    Uint16  rsvd1:1;            // 1	Ԥ��
    Uint16  SOCA:1;             // 2	ePWMxSOCAǿ�ƿ���λ
    Uint16  SOCB:1;             // 3	ePWMxSOCBǿ�ƿ���λ
    Uint16  rsvd2:12;           // 15:4	Ԥ��
};

union ETFRC_REG {
    Uint16                  all;
    struct ETFRC_BITS        bit;
};
//----------------------------------------------------
/* ն�����ƼĴ�����PCCTL��λ���� */
struct PCCTL_BITS {             // λ����
    Uint16  CHPEN:1;            // 0      PWMն��ʹ��
    Uint16  OSHTWTH:4;          // 4:1    ��һ�������ȿ���λ
    Uint16  CHPFREQ:3;          // 7:5    ն��ʱ��Ƶ�ʷ�Ƶϵ������λ
    Uint16  CHPDUTY:3;          // 10:8   ն��ʱ��ռ�ձ�����λ
    Uint16  rsvd1:5;            // 15:11  Ԥ��
};

union PCCTL_REG {
    Uint16                  all;
    struct PCCTL_BITS       bit;
};

//----------------------------------------------------
/* �߾���PWM���ƼĴ�����HRCNFG��λ���� */
struct HRCNFG_BITS {       	    // λ����
    Uint16  EDGMODE:2;     	    // 1:0            ����ģʽѡ��λ
    Uint16  CTLMODE:1;     	    // 2                  ����ģʽѡ��λ
    Uint16  HRLOAD:1;      	    // 3                  Ӱ�ӼĴ������ص����Ĵ�����ʱ��ѡ�����λ
    Uint16  rsvd1:12;      	    // 15:4   Ԥ��
};

union HRCNFG_REG {
   Uint16                  	all;
   struct HRCNFG_BITS       bit;
};

//----------------------------------------------------
/* �߾���PWM��λ��չ���ƼĴ�����TBPHS_HRPWM��λ���� */
struct TBPHS_HRPWM_REG {   	    // λ����
    Uint16  TBPHSHR;     	    // 15:0   HRPWM��λ��չ����λ
    Uint16  TBPHS;              // 31:16  ��λƫ�ÿ���λ
};

union TBPHS_HRPWM_GROUP {
   Uint32                  all;
   struct TBPHS_HRPWM_REG  half;
};

//----------------------------------------------------
/* �߾���PWM�Ƚ���չ���ƼĴ�����CMPA_HRPWM��λ���� */
struct CMPA_HRPWM_REG {   	    // λ����
    Uint16  CMPAHR;     	    // 15:0   HRPWM�Ƚ���չ����λ
    Uint16  CMPA;               // 31:16  CMPA
};

union CMPA_HRPWM_GROUP {
   Uint32                 all;
   struct CMPA_HRPWM_REG  half;
};

/**************************************/
/* ePWM���ƺ�״̬�Ĵ����ļ� */
/**************************************/
struct EPWM_REGS {
   union  TBCTL_REG           TBCTL;   // ʱ�����ƼĴ���
   union  TBSTS_REG           TBSTS;   // ʱ��״̬�Ĵ���
   union  TBPHS_HRPWM_GROUP   TBPHS;   // �߾�����λ�Ĵ���������
   Uint16                     TBCTR;   // ʱ���������Ĵ���
   Uint16                     TBPRD;   // ʱ�����ڼĴ���
   Uint16                     rsvd1;   // 
   union  CMPCTL_REG          CMPCTL;  // �ȽϿ��ƼĴ���
   union  CMPA_HRPWM_GROUP    CMPA;    // �߾��ȱȽϼĴ���A������
   Uint16                     CMPB;    // �ȽϼĴ���B
   union  AQCTL_REG           AQCTLA;  // �������ƼĴ���A
   union  AQCTL_REG           AQCTLB;  // �������ƼĴ���B
   union  AQSFRC_REG          AQSFRC;  // ���ǿ�ƶ������ƼĴ���
   union  AQCSFRC_REG         AQCSFRC; // �������ǿ�ƶ������ƼĴ���
   union  DBCTL_REG           DBCTL;   // �������ƼĴ���
   Uint16                     DBRED;   // ������������ʱ���ƼĴ���
   Uint16                     DBFED;   // �����½�����ʱ���ƼĴ���
   union  TZSEL_REG           TZSEL;   // ��������ѡ��Ĵ���
   Uint16                     rsvd2;   
   union  TZCTL_REG           TZCTL;   // �����������ƼĴ���
   union  TZEINT_REG          TZEINT;  // ���������ж�ʹ�ܿ��ƼĴ���
   union  TZFLG_REG           TZFLG;   // ���������жϱ�־�Ĵ���
   union  TZCLR_REG           TZCLR;   // ���������жϱ�־����Ĵ���
   union  TZFRC_REG    	      TZFRC;   // ���������ж�ǿ�ƼĴ���
   union  ETSEL_REG           ETSEL;   // �¼�����ѡ����ƼĴ���
   union  ETPS_REG            ETPS;    // �¼�������Ƶ���ƼĴ���
   union  ETFLG_REG           ETFLG;   // �¼�������־�Ĵ���
   union  ETCLR_REG           ETCLR;   // �¼�������־����Ĵ���
   union  ETFRC_REG           ETFRC;   // �¼�����ǿ�ƿ��ƼĴ���
   union  PCCTL_REG           PCCTL;   // PWMն�����ƼĴ���
   Uint16                     rsvd3;   // 
   union  HRCNFG_REG          HRCNFG;  // �߾���PWM���ƼĴ���
};


//---------------------------------------------------------------------------
// ePWM�ⲿ���úͺ�������:
//
extern volatile struct EPWM_REGS EPwm1Regs;
extern volatile struct EPWM_REGS EPwm2Regs;
extern volatile struct EPWM_REGS EPwm3Regs;
extern volatile struct EPWM_REGS EPwm4Regs;
extern volatile struct EPWM_REGS EPwm5Regs;
extern volatile struct EPWM_REGS EPwm6Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of AVP33x_EPWM_H definition

//===========================================================================
// End of file.
//===========================================================================
