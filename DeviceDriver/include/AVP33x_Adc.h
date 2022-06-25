/******************************************************************************
�ļ���                     : AVP33x_Adc.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xоƬADCģ��Ĵ�������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_ADC_H
#define AVP33x_ADC_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// ADC Individual Register Bit Definitions:
//----------------------------------------------------
/* ADCģ����ƼĴ���1��ADCTRL1��λ���� */
struct ADCTRL1_BITS {           // λ����
	Uint16  LDO_CT:3; 			// 2:0 ADC�ڲ�1.5vģ���Դ��ѹ����λ��
								// 000:VLDO; 001:1.3*VLDO/1.5; 010:1.35*VLDO/1.5; 011:1.4*VLDO/1.5;
								// 100:1.45*VLDO/1.5; 101:1.55*VLDO/1.5; 110:1.6*VLDO/1.5; 111:1.65*VLDO/1.5��
	Uint16	LDO_EN:1; 			// 3: ADC�ڲ�1.5vģ���Դʹ��λ��0����ֹ��1��ʹ��
    Uint16  SEQ_CASC:1;         // 4     ������ģʽ����λ��0��˫����ģʽ��1������ģʽ��
    Uint16  SEQ_OVRD:1;         // 5     ���������з�ʽ����λ
    Uint16  CONT_RUN:1;         // 6     ���з�ʽ����λ��0����ͣģʽ��1������ģʽ��
    Uint16  CPS:1;              // 7     ADCʱ��Ԥ�������λ��0��f=HSPCLK/1��1��f=HSPCLK/2��
    Uint16  ACQ_PS:4;           // 11:8  �������ڿ�ȿ���λ
    Uint16  SUSMOD:2;           // 13:12 ������ͣģʽ����λ
    Uint16  RESET:1;            // 14    ADC�����λ����λ
    Uint16  rsvd2:1;            // 15    Ԥ��
};

union ADCTRL1_REG {
   Uint16                all;
   struct ADCTRL1_BITS   bit;
};

//----------------------------------------------------
/* ADCģ����ƼĴ���2��ADCTRL2��λ���� */
struct ADCTRL2_BITS {           // λ����
    Uint16  EPWM_SOCB_SEQ2:1;   // 0     SEQ2��ePWM��SOCB���ο���λ
    Uint16  rsvd1:1;            // 1     Ԥ��
    Uint16  INT_MOD_SEQ2:1;     // 2     SEQ2�ж�ģʽ����λ
    Uint16  INT_ENA_SEQ2:1;     // 3     SEQ2�ж�ʹ��
    Uint16  rsvd2:1;            // 4     Ԥ��
    Uint16  SOC_SEQ2:1;         // 5     SEQ2ת����������λ
    Uint16  RST_SEQ2:1;         // 6     ��λSEQ2
    Uint16  EXT_SOC_SEQ1:1;     // 7     SEQ1�ⲿ���ţ�ADCSOC������ADCת��ʹ��λ
    Uint16  EPWM_SOCA_SEQ1:1;   // 8     SEQ1��ePWM��SOCA���ο���λ
    Uint16  rsvd3:1;            // 9     Ԥ��
    Uint16  INT_MOD_SEQ1:1;     // 10    SEQ1�ж�ģʽ����λ
    Uint16  INT_ENA_SEQ1:1;     // 11    SEQ1�ж�ʹ�ܿ���λ
    Uint16  rsvd4:1;            // 12    Ԥ��
    Uint16  SOC_SEQ1:1;         // 13    SEQ1ת����������λ
    Uint16  RST_SEQ1:1;         // 14    ��λSEQ1
    Uint16  EPWM_SOCB_SEQ:1;    // 15    ����ģʽ��eEPWM��SOCB����ADʹ�ܿ���λ
};

union ADCTRL2_REG {
    Uint16                all;
    struct ADCTRL2_BITS   bit;
};

//----------------------------------------------------
/* ADC�Զ�����״̬�Ĵ�����ADCASEQSR��λ���� */
struct ADCASEQSR_BITS {         // λ����
    Uint16  SEQ1_STATE:4;       // 3:0    SEQ1״̬λ
    Uint16  SEQ2_STATE:3;       // 6:4    SEQ2״̬λ
    Uint16  rsvd1:1;            // 7      Ԥ��
    Uint16  SEQ_CNTR:4;         // 11:8   ������������״̬λ
    Uint16  rsvd2:4;            // 15:12  Ԥ��
};

union ADCASEQSR_REG {
    Uint16                 all;
    struct ADCASEQSR_BITS  bit;
};

//----------------------------------------------------
/* ADC���ת��ͨ�����Ĵ�����ADCMAXCONV��λ���� */
struct ADCMAXCONV_BITS {        // λ����
    Uint16  MAX_CONV1:4;        // 3:0   ���ת��ͨ����
    Uint16  MAX_CONV2:3;        // 6:4   ���ת��ͨ����
    Uint16  rsvd1:9;            // 15:7  Ԥ��
};

union ADCMAXCONV_REG {
    Uint16                  all;
    struct ADCMAXCONV_BITS  bit;
};

//----------------------------------------------------
/* ADC����ͨ��ѡ��������ƼĴ���1��ADCCHSELSEQ1��λ���� */
struct ADCCHSELSEQ1_BITS {      // λ����
    Uint16  CONV00:4;           // 3:0    ��ת��������浽����Ĵ���00
    Uint16  CONV01:4;           // 7:4    ��ת��������浽����Ĵ���01
    Uint16  CONV02:4;           // 11:8   ��ת��������浽����Ĵ���02
    Uint16  CONV03:4;           // 15:12  ��ת��������浽����Ĵ���03
};

union  ADCCHSELSEQ1_REG{
    Uint16                    all;
    struct ADCCHSELSEQ1_BITS  bit;
};

//----------------------------------------------------
/* ADC����ͨ��ѡ��������ƼĴ���2��ADCCHSELSEQ2��λ���� */
struct ADCCHSELSEQ2_BITS {      // λ����
    Uint16  CONV04:4;           // 3:0    ��ת��������浽����Ĵ���04
    Uint16  CONV05:4;           // 7:4    ��ת��������浽����Ĵ���05
    Uint16  CONV06:4;           // 11:8   ��ת��������浽����Ĵ���06
    Uint16  CONV07:4;           // 15:12  ��ת��������浽����Ĵ���07
};

union  ADCCHSELSEQ2_REG{
    Uint16                    all;
    struct ADCCHSELSEQ2_BITS  bit;
};

//----------------------------------------------------
/* ADC����ͨ��ѡ��������ƼĴ���3��ADCCHSELSEQ3��λ���� */
struct ADCCHSELSEQ3_BITS {      // λ����
    Uint16  CONV08:4;           // 3:0    ��ת��������浽����Ĵ���08
    Uint16  CONV09:4;           // 7:4    ��ת��������浽����Ĵ���09
    Uint16  CONV10:4;           // 11:8   ��ת��������浽����Ĵ���10
    Uint16  CONV11:4;           // 15:12  ��ת��������浽����Ĵ���11
};

union  ADCCHSELSEQ3_REG{
    Uint16                    all;
    struct ADCCHSELSEQ3_BITS  bit;
};

//----------------------------------------------------
/* ADC����ͨ��ѡ��������ƼĴ���4��ADCCHSELSEQ4��λ���� */
struct ADCCHSELSEQ4_BITS {      // λ����
    Uint16  CONV12:4;           // 3:0    ��ת��������浽����Ĵ���12
    Uint16  CONV13:4;           // 7:4    ��ת��������浽����Ĵ���13
    Uint16  CONV14:4;           // 11:8   ��ת��������浽����Ĵ���14
    Uint16  CONV15:4;           // 15:12  ��ת��������浽����Ĵ���15
};

union  ADCCHSELSEQ4_REG {
    Uint16                    all;
    struct ADCCHSELSEQ4_BITS  bit;
};

//----------------------------------------------------
/* ADCģ����ƼĴ���3��ADCTRL3��λ���� */
struct ADCTRL3_BITS {           // λ����
    Uint16   SMODE_SEL:1;       // 0      ����ģʽѡ�����λ��0��˳�������1��ͬ��������
    Uint16   ADCCLKPS:4;        // 4:1    ADC�ں�ʱ�ӷ�Ƶϵ������Ϊ
    Uint16   ADCPWDN:1;         // 5      ��ADC����϶��ο���·���ģ���·�������λ
    Uint16   ADCBGRFDN:2;       // 7:6    ADC��϶�Ͳο���·�������λ
	Uint16   rsvd1:1;       	// 8    Ԥ��
	Uint16   CT_SPEED:1;    	// 9     ADCת��λ������ѡ��0��ADCת������12λģʽ��1��ADCת������16λģʽ��
	Uint16   ADC_TEST:1;    	// 10    ADC����У��ʹ��λ��0����ֹ��1��ʹ�ܡ�
	Uint16   GAINTRIM_SEL:1;   	// 11    ADC����������ƫ��ѡ��λ��0��ADC�������������һ���̶�ֵ��1��ADC�������������һ���̶�ֵ��  
	Uint16   OFFTRIM_SEL:1; 	// 12    ADCֱ��ƫ���޵������л�λ��0��ADCֱ��ƫ���޵�����12λ��1��ADCֱ��ƫ���޵�����16λ��
	Uint16   SH_TRIM:1;     	// 13     ADC�ɱ���·��׼��ѹ�Ĳ�ֵ��С����λ��0��ADC�ɱ���·ʹ���ڲ�Ĭ�ϻ�׼��ѹ��ֵ��1��ADC�ɱ���·��׼��ѹ��ֵ��Сһ���̶�������
	Uint16   rsvd2:2;       	// 14-15  Ԥ��
}; 

union  ADCTRL3_REG {
    Uint16                all;
    struct ADCTRL3_BITS   bit;
};

//----------------------------------------------------
/* ADC״̬�ͱ�־�Ĵ�����ADCST��λ���� */
struct ADCST_BITS {             // λ����
    Uint16   INT_SEQ1:1;        // 0      SEQ1�жϱ�־λ��R=0��
    Uint16   INT_SEQ2:1;        // 1      SEQ2�жϱ�־λ��R=0��
    Uint16   SEQ1_BSY:1;        // 2      SEQ1æ״̬��־λ��R=0��
    Uint16   SEQ2_BSY:1;        // 3      SEQ2æ״̬��־λ��R=0��
    Uint16   INT_SEQ1_CLR:1;    // 4      SEQ1�ж��������λ��R/W=0��
    Uint16   INT_SEQ2_CLR:1;    // 5      SEQ2�ж��������λ��R/W=0��
    Uint16   EOS_BUF1:1;        // 6      SEQ1�����򻺳����λ��R=0��
    Uint16   EOS_BUF2:1;        // 7      SEQ1�����򻺳����λ��R=0��
    Uint16   rsvd1:8;           // 15:8   Ԥ����R=0��
};
                             
union  ADCST_REG {            
    Uint16             all;
    struct ADCST_BITS  bit;
};                           

//----------------------------------------------------
/* ADC�ο���ѹѡ��Ĵ�����ADCREFSEL��λ���� */
struct ADCREFSEL_BITS {         // λ����
	Uint16   rsvd1:14;          // 13:0         Ԥ��
	Uint16   REF_SEL:2;         // 15:14      �ο���ѹѡ�����λ
};
union ADCREFSEL_REG {
	Uint16		all;
	struct ADCREFSEL_BITS bit;
};

//----------------------------------------------------
/* ADC�����Ĵ�����ADCOFFTRIM��λ���� */
struct ADCOFFTRIM_BITS{         // λ����
	int16	OFFSET_TRIM:9;      // 8:0            ƫ��
	Uint16	rsvd1:7;            // 15:9         Ԥ��
};

union ADCOFFTRIM_REG{
	Uint16		all;
	struct ADCOFFTRIM_BITS bit;
};

/**************************************/
/* ADC���ƺ�״̬�Ĵ����ļ� */
/**************************************/
struct ADC_REGS {
    union ADCTRL1_REG      ADCTRL1;         // ADCģ����ƼĴ���1
    union ADCTRL2_REG      ADCTRL2;         // ADCģ����ƼĴ���2
    union ADCMAXCONV_REG   ADCMAXCONV;      // ADC���ת��ͨ�������ƼĴ���
    union ADCCHSELSEQ1_REG ADCCHSELSEQ1;    // ADC����ͨ��ѡ��������ƼĴ���1
    union ADCCHSELSEQ2_REG ADCCHSELSEQ2;    // ADC����ͨ��ѡ��������ƼĴ���2
    union ADCCHSELSEQ3_REG ADCCHSELSEQ3;    // ADC����ͨ��ѡ��������ƼĴ���3
    union ADCCHSELSEQ4_REG ADCCHSELSEQ4;    // ADC����ͨ��ѡ��������ƼĴ���4
    union ADCASEQSR_REG    ADCASEQSR;       // ADC�Զ�����״̬�Ĵ���
    Uint16                 ADCRESULT0;      // ADC����Ĵ���0
    Uint16                 ADCRESULT1;      // ADC����Ĵ���1
    Uint16                 ADCRESULT2;      // ADC����Ĵ���2
    Uint16                 ADCRESULT3;      // ADC����Ĵ���3
    Uint16                 ADCRESULT4;      // ADC����Ĵ���4
    Uint16                 ADCRESULT5;      // ADC����Ĵ���5
    Uint16                 ADCRESULT6;      // ADC����Ĵ���6
    Uint16                 ADCRESULT7;      // ADC����Ĵ���7
    Uint16                 ADCRESULT8;      // ADC����Ĵ���8
    Uint16                 ADCRESULT9;      // ADC����Ĵ���9
    Uint16                 ADCRESULT10;     // ADC����Ĵ���10
    Uint16                 ADCRESULT11;     // ADC����Ĵ���11
    Uint16                 ADCRESULT12;     // ADC����Ĵ���12
    Uint16                 ADCRESULT13;     // ADC����Ĵ���13
    Uint16                 ADCRESULT14;     // ADC����Ĵ���14
    Uint16                 ADCRESULT15;     // ADC����Ĵ���15
    union ADCTRL3_REG      ADCTRL3;         // ADCģ����ƼĴ���3
    union ADCST_REG        ADCST;           // ADC״̬�Ĵ���
    Uint16				   rsvd1;
    Uint16                 rsvd2;
    union ADCREFSEL_REG    ADCREFSEL;       // ADC�ο�ѡ��Ĵ���
    union ADCOFFTRIM_REG   ADCOFFTRIM;      // ADCУ���Ĵ���
};

//----------------------------------------------------
/* ADC����Ĵ�����ADC_RESULT��λ���� */
struct ADC_RESULT_MIRROR_REGS
{
    Uint16                 ADCRESULT0;      // ADC����Ĵ���0
    Uint16                 ADCRESULT1;      // ADC����Ĵ���1
    Uint16                 ADCRESULT2;      // ADC����Ĵ���2
    Uint16                 ADCRESULT3;      // ADC����Ĵ���3
    Uint16                 ADCRESULT4;      // ADC����Ĵ���4
    Uint16                 ADCRESULT5;      // ADC����Ĵ���5
    Uint16                 ADCRESULT6;      // ADC����Ĵ���6
    Uint16                 ADCRESULT7;      // ADC����Ĵ���7
    Uint16                 ADCRESULT8;      // ADC����Ĵ���8
    Uint16                 ADCRESULT9;      // ADC����Ĵ���9
    Uint16                 ADCRESULT10;     // ADC����Ĵ���10
    Uint16                 ADCRESULT11;     // ADC����Ĵ���11
    Uint16                 ADCRESULT12;     // ADC����Ĵ���12
    Uint16                 ADCRESULT13;     // ADC����Ĵ���13
    Uint16                 ADCRESULT14;     // ADC����Ĵ���14
    Uint16                 ADCRESULT15;     // ADC����Ĵ���15
};

//---------------------------------------------------------------------------
// ADC�ⲿ���úͺ�������:
//
extern volatile struct ADC_REGS AdcRegs;
extern volatile struct ADC_RESULT_MIRROR_REGS AdcMirror;


#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of AVP33x_ADC_H definition

//===========================================================================
// End of file.
//===========================================================================
