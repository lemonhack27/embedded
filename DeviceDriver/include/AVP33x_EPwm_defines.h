/******************************************************************************
�ļ���                     : AVP33x_EPwm_defines.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : ePWMģ���õ��ĺ궨��
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_EPWM_DEFINES_H
#define AVP33x_EPWM_DEFINES_H


#ifdef __cplusplus
extern "C" {
#endif

// ʱ�����ƼĴ�����غ궨��
//==========================
// ����ģʽ����λ
#define	TB_COUNT_UP		0x0     // ʱ�����������ϼ���ģʽ
#define	TB_COUNT_DOWN	0x1     // ʱ�����������¼���ģʽ
#define	TB_COUNT_UPDOWN	0x2     // ʱ������������-�¼���ģʽ
#define	TB_FREEZE		0x3     // ʱ��������ֹͣ��������λ���Ĭ��״̬��
// �����Ĵ���װ����λ�Ĵ���ʹ��λ
#define	TB_DISABLE		0x0     // �����Ĵ�����װ����λ�Ĵ�����ֵ
#define	TB_ENABLE		0x1     // ��ͬ���źŵ���ʱ�������Ĵ���װ����λ�Ĵ�����ֵ
// ���ڼĴ���װ��Ӱ�ӼĴ�������λ
#define	TB_SHADOW		0x0     // ����������ֵΪ0ʱ�����ڼĴ�����װ��Ӱ�ӼĴ�����ֵ
#define	TB_IMMEDIATE	0x1     // ��ʹ��Ӱ�ӼĴ�����һ����������ֱֵ�Ӿͱ�װ�ص����ڼĴ�����
// ͬ���ź��������λ
#define	TB_SYNC_IN		0x0     // ��ePWMxSYNCI�źų���ʱ�����ͬ���ź�
#define	TB_CTR_ZERO		0x1     // ��ʱ��������ֵ=0ʱ�����ͬ���ź�
#define	TB_CTR_CMPB		0x2     // ��ʱ��������ֵ=�Ƚ�ֵʱ�����ͬ���ź�
#define	TB_SYNC_DISABLE	0x3     // ��ֹ���ͬ���ź�
// ʱ��ʱ�ӷ�Ƶ����λ
#define	TB_DIV1			0x0     // ����Ƶ
#define	TB_DIV2			0x1     // 2��Ƶ
#define	TB_DIV4			0x2     // 4��Ƶ
// ��λ�������λ
#define	TB_DOWN			0x0     // ͬ���źŵ���ʱ�����¼���
#define	TB_UP			0x1     // ͬ���źŵ���ʱ�����ϼ���

// CMPCTL (Compare Control)
//==========================
// LOADAMODE and LOADBMODE bits
#define	CC_CTR_ZERO		0x0
#define	CC_CTR_PRD		0x1
#define	CC_CTR_ZERO_PRD	0x2
#define	CC_LD_DISABLE	0x3
// SHDWAMODE and SHDWBMODE bits
#define	CC_SHADOW		0x0
#define	CC_IMMEDIATE	0x1

// AQCTLA and AQCTLB (Action Qualifier Control)
//=============================================
// ZRO, PRD, CAU, CAD, CBU, CBD bits
#define	AQ_NO_ACTION	0x0
#define	AQ_CLEAR		0x1
#define	AQ_SET			0x2
#define	AQ_TOGGLE		0x3

// DBCTL (Dead-Band Control)
//==========================
// OUT MODE bits
#define	DB_DISABLE		0x0
#define	DBA_ENABLE		0x1
#define	DBB_ENABLE		0x2
#define	DB_FULL_ENABLE	0x3
// POLSEL bits
#define	DB_ACTV_HI		0x0
#define	DB_ACTV_LOC		0x1
#define	DB_ACTV_HIC		0x2
#define	DB_ACTV_LO		0x3
// IN MODE
#define DBA_ALL         0x0
#define DBB_RED_DBA_FED 0x1
#define DBA_RED_DBB_FED 0x2
#define DBB_ALL         0x3

// CHPCTL (chopper control)
//==========================
// CHPEN bit
#define	CHP_DISABLE		0x0
#define	CHP_ENABLE		0x1
// CHPFREQ bits
#define	CHP_DIV1		0x0
#define	CHP_DIV2		0x1
#define	CHP_DIV3		0x2
#define	CHP_DIV4		0x3
#define	CHP_DIV5		0x4
#define	CHP_DIV6		0x5
#define	CHP_DIV7		0x6
#define	CHP_DIV8		0x7
// CHPDUTY bits
#define	CHP1_8TH		0x0
#define	CHP2_8TH		0x1
#define	CHP3_8TH		0x2
#define	CHP4_8TH		0x3
#define	CHP5_8TH		0x4
#define	CHP6_8TH		0x5
#define	CHP7_8TH		0x6

// TZSEL (Trip Zone Select)
//==========================
// CBCn and OSHTn bits
#define	TZ_DISABLE		0x0
#define	TZ_ENABLE		0x1

// TZCTL (Trip Zone Control)
//==========================
// TZA and TZB bits
#define	TZ_HIZ			0x0
#define	TZ_FORCE_HI		0x1
#define	TZ_FORCE_LO		0x2
#define	TZ_NO_CHANGE	0x3

// ETSEL (Event Trigger Select)
//=============================
#define	ET_CTR_ZERO		0x1
#define	ET_CTR_PRD		0x2
#define	ET_CTRU_CMPA	0x4
#define	ET_CTRD_CMPA	0x5
#define	ET_CTRU_CMPB	0x6
#define	ET_CTRD_CMPB	0x7

// ETPS (Event Trigger Pre-scale)
//===============================
// INTPRD, SOCAPRD, SOCBPRD bits
#define	ET_DISABLE		0x0
#define	ET_1ST			0x1
#define	ET_2ND			0x2
#define	ET_3RD			0x3


//--------------------------------
// HRPWM (High Resolution PWM)
//================================
// HRCNFG
#define	HR_Disable		0x0
#define	HR_REP			0x1
#define	HR_FEP			0x2
#define	HR_BEP			0x3

#define	HR_CMP			0x0
#define	HR_PHS			0x1

#define	HR_CTR_ZERO		0x0
#define	HR_CTR_PRD		0x1


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of AVP33x_EPWM_DEFINES_H

//===========================================================================
// End of file.
//===========================================================================
