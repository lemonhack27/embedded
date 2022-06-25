/******************************************************************************
�ļ���                     : AVP33x_PieVect.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xоƬPIE�������ʼ������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#include "AVP33x_Device.h"     // AVP33x Headerfile Include File
#include "AVP33x_Examples.h"   // AVP33x Examples Include File


const struct PIE_VECT_TABLE PieVectTableInit = {

    PIE_RESERVED,       // 0  Ԥ���ռ�
    PIE_RESERVED,       // 1  Ԥ���ռ�
    PIE_RESERVED,       // 2  Ԥ���ռ�
    PIE_RESERVED,       // 3  Ԥ���ռ�
    PIE_RESERVED,       // 4  Ԥ���ռ�
    PIE_RESERVED,       // 5  Ԥ���ռ�
    PIE_RESERVED,       // 6  Ԥ���ռ�
    PIE_RESERVED,       // 7  Ԥ���ռ�
    PIE_RESERVED,       // 8  Ԥ���ռ�
    PIE_RESERVED,       // 9  Ԥ���ռ�
    PIE_RESERVED,       // 10 Ԥ���ռ�
    PIE_RESERVED,       // 11 Ԥ���ռ�
    PIE_RESERVED,       // 12 Ԥ���ռ�

// �������ж�
    INT13_ISR,          // XINT13��CPU��ʱ��1
    INT14_ISR,          // CPU��ʱ��2
    DATALOG_ISR,        // ���ݼ�¼�ж�
    RTOSINT_ISR,        // ʵʱ����ϵͳ�ж�
    EMUINT_ISR,         // �����ж�
    NMI_ISR,            // ���������ж�
    ILLEGAL_ISR,        // �Ƿ����������ж�
    USER1_ISR,          // �û���������1
    USER2_ISR,          // �û���������2
    USER3_ISR,          // �û���������3
    USER4_ISR,          // �û���������4
    USER5_ISR,          // �û���������5
    USER6_ISR,          // �û���������6
    USER7_ISR,          // �û���������7
    USER8_ISR,          // �û���������8
    USER9_ISR,          // �û���������9
    USER10_ISR,         // �û���������10
    USER11_ISR,         // �û���������11
    USER12_ISR,         // �û���������12

// ��1��PIE�ж�����
    SEQ1INT_ISR,        // 1.1 ADC SEQ1�ж�
    SEQ2INT_ISR,        // 1.2 ADC SEQ2�ж�
    rsvd_ISR,           // 1.3 Ԥ��
    XINT1_ISR,          // 1.4 �ⲿ�ж�XINT1
    XINT2_ISR,          // 1.5 �ⲿ�ж�XINT2
    ADCINT_ISR,         // 1.6 ADC�ж�
    TINT0_ISR,          // 1.7 CPU��ʱ��0�ж�
    WAKEINT_ISR,        // 1.8 ���Ź��ж�

// ��2��PIE�ж�����
    EPWM1_TZINT_ISR,    // 2.1 EPWM-1 TZ�ж�
    EPWM2_TZINT_ISR,    // 2.2 EPWM-2 TZ�ж�
    EPWM3_TZINT_ISR,    // 2.3 EPWM-3 TZ�ж�
    EPWM4_TZINT_ISR,    // 2.4 EPWM-4 TZ�ж�
    EPWM5_TZINT_ISR,    // 2.5 EPWM-5 TZ�ж�
    EPWM6_TZINT_ISR,    // 2.6 EPWM-6 TZ�ж�
    rsvd_ISR,           // 2.7 Ԥ��
    rsvd_ISR,           // 2.8 Ԥ��
      
// ��3��PIE�ж�����
    EPWM1_INT_ISR,      // 3.1 EPWM-1�ж�
    EPWM2_INT_ISR,      // 3.2 EPWM-2�ж�
    EPWM3_INT_ISR,      // 3.3 EPWM-3�ж�
    EPWM4_INT_ISR,      // 3.4 EPWM-4�ж�
    EPWM5_INT_ISR,      // 3.5 EPWM-5�ж�
    EPWM6_INT_ISR,      // 3.6 EPWM-6�ж�
    rsvd_ISR,           // 3.7 Ԥ��
    rsvd_ISR,           // 3.8 Ԥ��
      
// ��4��PIE�ж�����
    ECAP1_INT_ISR,      // 4.1 ECAP-1�ж�
    ECAP2_INT_ISR,      // 4.2 ECAP-2�ж�
    ECAP3_INT_ISR,      // 4.3 ECAP-3�ж�
    ECAP4_INT_ISR,      // 4.4 ECAP-4�ж�
    ECAP5_INT_ISR,      // 4.5 ECAP-5�ж�
    ECAP6_INT_ISR,      // 4.6 ECAP-6�ж�
    rsvd_ISR,           // 4.7 Ԥ��
    rsvd_ISR,           // 4.8 Ԥ��
      
// ��5��PIE�ж�����
    EQEP1_INT_ISR,      // 5.1 EQEP-1�ж�
    EQEP2_INT_ISR,      // 5.2 EQEP-2�ж�
    rsvd_ISR,           // 5.3 Ԥ��
    rsvd_ISR,           // 5.4 Ԥ��
    rsvd_ISR,           // 5.5 Ԥ��
    rsvd_ISR,           // 5.6 Ԥ��
    rsvd_ISR,           // 5.7 Ԥ��
    rsvd_ISR,           // 5.8 Ԥ��

// ��6��PIE�ж�����
    SPIRXINTA_ISR,      // 6.1 SPI-A�ж�
    SPITXINTA_ISR,      // 6.2 SPI-A�ж�
    MRINTA_ISR,         // 6.3 McBSP-A�ж�
    MXINTA_ISR,         // 6.4 McBSP-A�ж�
    MRINTB_ISR,         // 6.5 McBSP-B�ж�
    MXINTB_ISR,         // 6.6 McBSP-B�ж�
    rsvd_ISR,           // 6.7 Ԥ��
    rsvd_ISR,           // 6.8 Ԥ��
      
// ��7��PIE�ж�����
    DINTCH1_ISR,        // 7.1 DMAͨ��1�ж�
    DINTCH2_ISR,        // 7.2 DMAͨ��2�ж�
    DINTCH3_ISR,        // 7.3 DMAͨ��3�ж�
    DINTCH4_ISR,        // 7.4 DMAͨ��4�ж�
    DINTCH5_ISR,        // 7.5 DMAͨ��5�ж�
    DINTCH6_ISR,        // 7.6 DMAͨ��6�ж�
    rsvd_ISR,           // 7.7 Ԥ��
    rsvd_ISR,           // 7.8 Ԥ��

// ��8��PIE�ж�����
    I2CINT1A_ISR,       // 8.1 I2C�ж�
    I2CINT2A_ISR,       // 8.2 I2C�ж�
    rsvd_ISR,           // 8.3 Ԥ��
    rsvd_ISR,           // 8.4 Ԥ��
    SCIRXINTC_ISR,      // 8.5 SCI-C�ж�
    SCITXINTC_ISR,      // 8.6 SCI-C�ж�
    rsvd_ISR,           // 8.7 Ԥ��
    rsvd_ISR,           // 8.8 Ԥ��
      
// ��9��PIE�ж�����
    SCIRXINTA_ISR,      // 9.1 SCI-A�ж�
    SCITXINTA_ISR,      // 9.2 SCI-A�ж�
    SCIRXINTB_ISR,      // 9.3 SCI-B�ж�
    SCITXINTB_ISR,      // 9.4 SCI-B�ж�
    ECAN0INTA_ISR,      // 9.5 eCAN-A�ж�
    ECAN1INTA_ISR,      // 9.6 eCAN-A�ж�
    ECAN0INTB_ISR,      // 9.7 eCAN-B�ж�
    ECAN1INTB_ISR,      // 9.8 eCAN-B�ж�
      
// ��10��PIE�ж�����
    rsvd_ISR,           // 10.1 Ԥ��
    rsvd_ISR,           // 10.2 Ԥ��
    rsvd_ISR,           // 10.3 Ԥ��
    rsvd_ISR,           // 10.4 Ԥ��
    rsvd_ISR,           // 10.5 Ԥ��
    rsvd_ISR,           // 10.6 Ԥ��
    rsvd_ISR,           // 10.7 Ԥ��
    rsvd_ISR,           // 10.8 Ԥ��
            
// ��11��PIE�ж�����
    rsvd_ISR,           // 11.1 Ԥ��
    rsvd_ISR,           // 11.2 Ԥ��
    rsvd_ISR,           // 11.3 Ԥ��
    rsvd_ISR,           // 11.4 Ԥ��
    rsvd_ISR,           // 11.5 Ԥ��
    rsvd_ISR,           // 11.6 Ԥ��
    rsvd_ISR,           // 11.7 Ԥ��
    rsvd_ISR,           // 11.8 Ԥ��
        
// ��12��PIE�ж�����
    XINT3_ISR,          // 12.1 �ⲿ�ж�XINT3
    XINT4_ISR,          // 12.2 �ⲿ�ж�XINT4
    XINT5_ISR,          // 12.3 �ⲿ�ж�XINT5
    XINT6_ISR,          // 12.4 �ⲿ�ж�XINT6
    XINT7_ISR,          // 12.5 �ⲿ�ж�XINT7
    rsvd_ISR,           // 12.6 Ԥ��
    LVF_ISR,            // 12.7 Ԥ��
    LUF_ISR,            // 12.8 Ԥ��
};

//---------------------------------------------------------------------------
// InitPieVectTable: 
//---------------------------------------------------------------------------
// ��ʼ��PIE�ж�����������������boot��ɺ�ִ�У�
//
void InitPieVectTable(void)
{
    int16	i;
    Uint32 *Source = (void *) &PieVectTableInit;
    volatile Uint32 *Dest = (void *) &PieVectTable;

    EALLOW;
    for(i=0; i < 128; i++)
        *Dest++ = *Source++;
    EDIS;

    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;  // ʹ��PIE�ж�������
			
}

//===========================================================================
// End of file.
//===========================================================================
