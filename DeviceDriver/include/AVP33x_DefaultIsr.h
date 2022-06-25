/******************************************************************************
�ļ���                     : AVP33x_DefaultIsr.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xĬ�ϵ��жϷ��������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_DEFAULT_ISR_H
#define AVP33x_DEFAULT_ISR_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// Ĭ�ϵ��жϷ������������
// 
// ���º���ԭ��������Ĭ�ϵ�PIE������һ��ʹ�õ�Ĭ��ISR���̡���avp33x_pievect.h�ļ��п����ҵ���������
//

// �������ж�:
interrupt void INT13_ISR(void);         // XINT13��CPU-Timer 1
interrupt void INT14_ISR(void);         // CPU-Timer2
interrupt void DATALOG_ISR(void);       // ���ݼ�¼�ж�
interrupt void RTOSINT_ISR(void);       // ʵʱ����ϵͳ�ж�
interrupt void EMUINT_ISR(void);        // �����ж�
interrupt void NMI_ISR(void);           // ���������ж�
interrupt void ILLEGAL_ISR(void);       // �Ƿ����������ж�
interrupt void USER1_ISR(void);         // �û��Զ����ж�1
interrupt void USER2_ISR(void);         // �û��Զ����ж�2
interrupt void USER3_ISR(void);         // �û��Զ����ж�3
interrupt void USER4_ISR(void);         // �û��Զ����ж�4
interrupt void USER5_ISR(void);         // �û��Զ����ж�5
interrupt void USER6_ISR(void);         // �û��Զ����ж�6
interrupt void USER7_ISR(void);         // �û��Զ����ж�7
interrupt void USER8_ISR(void);         // �û��Զ����ж�8
interrupt void USER9_ISR(void);         // �û��Զ����ж�9
interrupt void USER10_ISR(void);        // �û��Զ����ж�10
interrupt void USER11_ISR(void);        // �û��Զ����ж�11
interrupt void USER12_ISR(void);        // �û��Զ����ж�12

// ��1��PIE�жϷ������:
interrupt void  SEQ1INT_ISR(void);      // ADC������1�ж�
interrupt void  SEQ2INT_ISR(void);      // ADC������2�ж�
interrupt void  XINT1_ISR(void);        // �ⲿ�ж�1
interrupt void  XINT2_ISR(void);        // �ⲿ�ж�2
interrupt void  ADCINT_ISR(void);       // ADC�ж�
interrupt void  TINT0_ISR(void);        // Timer0�ж�
interrupt void  WAKEINT_ISR(void);      // ���Ź��ж�

// ��2��PIE�жϷ������:
interrupt void EPWM1_TZINT_ISR(void);   // EPWM-1�ж�
interrupt void EPWM2_TZINT_ISR(void);   // EPWM-2�ж�
interrupt void EPWM3_TZINT_ISR(void);   // EPWM-3�ж�
interrupt void EPWM4_TZINT_ISR(void);   // EPWM-4�ж�
interrupt void EPWM5_TZINT_ISR(void);   // EPWM-5�ж�
interrupt void EPWM6_TZINT_ISR(void);   // EPWM-6�ж�
      
// ��3��PIE�жϷ������:
interrupt void EPWM1_INT_ISR(void);     // EPWM-1�ж�
interrupt void EPWM2_INT_ISR(void);     // EPWM-2�ж�
interrupt void EPWM3_INT_ISR(void);     // EPWM-3�ж�
interrupt void EPWM4_INT_ISR(void);     // EPWM-4�ж�
interrupt void EPWM5_INT_ISR(void);     // EPWM-5�ж�
interrupt void EPWM6_INT_ISR(void);     // EPWM-6�ж�
      
// ��4��PIE�жϷ������:
interrupt void ECAP1_INT_ISR(void);     // ECAP-1�ж�
interrupt void ECAP2_INT_ISR(void);     // ECAP-2�ж�
interrupt void ECAP3_INT_ISR(void);     // ECAP-3�ж�
interrupt void ECAP4_INT_ISR(void);     // ECAP-4�ж�
interrupt void ECAP5_INT_ISR(void);     // ECAP-5�ж�
interrupt void ECAP6_INT_ISR(void);     // ECAP-6�ж�
     
// ��5��PIE�жϷ������:
interrupt void EQEP1_INT_ISR(void);     // EQEP-1�ж�
interrupt void EQEP2_INT_ISR(void);     // EQEP-2�ж�

// ��6��PIE�жϷ������:
interrupt void SPIRXINTA_ISR(void);     // SPI-A�ж�
interrupt void SPITXINTA_ISR(void);     // SPI-A�ж�
interrupt void MRINTA_ISR(void);        // McBSP-A�ж�
interrupt void MXINTA_ISR(void);        // McBSP-A�ж�
interrupt void MRINTB_ISR(void);        // McBSP-B�ж�
interrupt void MXINTB_ISR(void);        // McBSP-B�ж�

// ��7��PIE�жϷ������:
interrupt void DINTCH1_ISR(void);       // DMA-ͨ��1�ж�
interrupt void DINTCH2_ISR(void);       // DMA-ͨ��2�ж�
interrupt void DINTCH3_ISR(void);       // DMA-ͨ��3�ж�
interrupt void DINTCH4_ISR(void);       // DMA-ͨ��4�ж�
interrupt void DINTCH5_ISR(void);       // DMA-ͨ��5�ж�
interrupt void DINTCH6_ISR(void);       // DMA-ͨ��6�ж�

// ��8��PIE�жϷ������:
interrupt void I2CINT1A_ISR(void);      // I2C-A�ж�
interrupt void I2CINT2A_ISR(void);      // I2C-A�ж�
interrupt void SCIRXINTC_ISR(void);     // SCI-C�ж�
interrupt void SCITXINTC_ISR(void);     // SCI-C�ж�

// ��9��PIE�жϷ������:
interrupt void SCIRXINTA_ISR(void);     // SCI-A�ж�
interrupt void SCITXINTA_ISR(void);     // SCI-A�ж�
interrupt void SCIRXINTB_ISR(void);     // SCI-B�ж�
interrupt void SCITXINTB_ISR(void);     // SCI-B�ж�
interrupt void ECAN0INTA_ISR(void);     // eCAN-A�ж�
interrupt void ECAN1INTA_ISR(void);     // eCAN-A�ж�
interrupt void ECAN0INTB_ISR(void);     // eCAN-B�ж�
interrupt void ECAN1INTB_ISR(void);     // eCAN-B�ж�

// ��10��PIE�жϷ������Ԥ����:
 
// ��11��PIE�жϷ������Ԥ����:

// ��12��PIE�жϷ������:
interrupt void  XINT3_ISR(void);        // �ⲿ�ж�3
interrupt void  XINT4_ISR(void);        // �ⲿ�ж�4
interrupt void  XINT5_ISR(void);        // �ⲿ�ж�5
interrupt void  XINT6_ISR(void);        // �ⲿ�ж�6
interrupt void  XINT7_ISR(void);        // �ⲿ�ж�7
interrupt void  LVF_ISR(void);          // ���������ж�
interrupt void  LUF_ISR(void);          // ���������ж�

// Ϊ���Զ��������ж�:
interrupt void PIE_RESERVED(void);      // Ԥ����������
interrupt void rsvd_ISR(void);          // �����õ��ж�
interrupt void INT_NOTUSED_ISR(void);   // δ�õ����ж�

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif    // end of AVP33x_DEFAULT_ISR_H definition

//===========================================================================
// End of file.
//===========================================================================
