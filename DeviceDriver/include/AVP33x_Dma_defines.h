/******************************************************************************
�ļ���                     : AVP33x_Dma_defines.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : DMAģ���õ��ĺ궨��
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_DMA_DEFINES_H
#define AVP33x_DMA_DEFINES_H


#ifdef __cplusplus
extern "C" {
#endif

// ģʽ�Ĵ���
//==========================
// �����ж�Դѡ��λ��Ϊ������DMAͨ��ѡ����ʵ��ⲿ�ж��źŴ���Դ��
#define DMA_SEQ1INT 1
#define DMA_SEQ2INT 2
#define DMA_XINT1   3
#define DMA_XINT2   4
#define DMA_XINT3   5
#define DMA_XINT4   6
#define DMA_XINT5   7
#define DMA_XINT6   8
#define DMA_XINT7   9
#define DMA_XINT13  10
#define DMA_TINT0   11
#define DMA_TINT1   12
#define DMA_TINT2   13
#define DMA_MXEVTA  14
#define DMA_MREVTA  15
#define DMA_MXREVTB 16
#define DMA_MREVTB  17
// ����ж�ʹ��λ
#define	OVRFLOW_DISABLE	0x0         // ��ֹ����ж�
#define	OVEFLOW_ENABLE	0x1         // ʹ������ж�
// �����жϴ���ʹ��λ
#define	PERINT_DISABLE	0x0         // ��ֹ�����жϴ����ź�
#define	PERINT_ENABLE   0x1         // ʹ�������жϴ����ź�
// ͨ���ж�ģʽѡ��λ
#define	CHINT_BEGIN		0x0         // ��һ�δ��Ϳ�ʼ�����ж��¼�
#define	CHINT_END     	0x1         // ��һ�δ��ͽ��������ж��¼�
// ���δ�������λ
#define	ONESHOT_DISABLE	0x0         // ÿ���жϴ����ź�����һ��ͻ������
#define	ONESHOT_ENABLE	0x1         // һ���жϴ����ź��������ͻ������
// ������������λ
#define	CONT_DISABLE	0x0         // ��TRANSFER_COUNT����ʱ��DMAֹͣ������RUNSTSλ����
#define	CONT_ENABLE 	0x1         // ��TRANSFER_COUNT����ʱ��DMA���³�ʼ�������ȴ��´δ����ź�
// ͬ���ź�ʹ��λ
#define	SYNC_DISABLE	0x0         // ADCSYNC������
#define	SYNC_ENABLE     0x1         // ���ͨ�������ж�Դѡ��λ��PERINTSEL��ѡ����ADC����ADCSYNC������ͬ��ADC�ж��ź���DMA���ؼ�����
// ͬ��ģʽѡ��λ
#define	SYNC_SRC		0x0         // SRC���ؼ�����������
#define	SYNC_DST        0x1         // DST���ؼ�����������
// DMAͨ�����ݿ�ȿ���λ
#define	SIXTEEN_BIT    	0x0         // 16λ���ݿ��
#define	THIRTYTWO_BIT   0x1         // 32λ���ݿ��
// ͨ���ж�ʹ��λ
#define	CHINT_DISABLE	0x0         // ��ֹDMA�ж�
#define	CHINT_ENABLE   	0x1         // ʹ��DMA�ж�


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of AVP33x_EPWM_DEFINES_H

//===========================================================================
// End of file.
//===========================================================================
