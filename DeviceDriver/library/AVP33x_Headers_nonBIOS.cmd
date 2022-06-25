/******************************************************************************
�ļ���                     : DSP2833x_Headers_nonBIOS.cmd
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : ����Ĵ��������������ļ�
			  ���Non-BIOS��Ӧ�á�
			  ���ڽ�AVP33Xͷ�ļ���ʹ�õ�����ṹ����õ���ȷ���ڴ�ӳ��λ�á�
			  �˰汾���ļ�����PievectorTable�ṹ�壻����BIOSӦ�ó�����ʹ�ò�����pievectortable
			  �ṹ��AVP33x_Headers_nonBIOS.cmd�ļ���
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/


MEMORY
{
 PAGE 0:    /* ����ռ�  */

 PAGE 1:    /* ���ݿռ�  */
 
   DEV_EMU     : origin = 0x000880, length = 0x000180     /* �豸����Ĵ��� */
   FLASH_REGS  : origin = 0x000A80, length = 0x000060     /* FLASH�Ĵ��� */
   CSM         : origin = 0x000AE0, length = 0x000010     /* ����ģ��Ĵ��� */
  
   ADC_MIRROR  : origin = 0x000B00, length = 0x000010     /* AD����Ĵ������� */

   XINTF       : origin = 0x000B20, length = 0x000020     /* �ⲿ���߽ӿڼĴ��� */
   
   CPU_TIMER0  : origin = 0x000C00, length = 0x000008     /* CPU Timer0�Ĵ���  */
   CPU_TIMER1  : origin = 0x000C08, length = 0x000008     /* CPU Timer1�Ĵ��� */
   CPU_TIMER2  : origin = 0x000C10, length = 0x000008     /* CPU Timer2�Ĵ��� */

   PIE_CTRL    : origin = 0x000CE0, length = 0x000020     /* PIE���ƼĴ��� */
   PIE_VECT    : origin = 0x000D00, length = 0x000100     /* PIE������ */

   DMA         : origin = 0x001000, length = 0x000200     /* DMA�Ĵ��� */

   MCBSPA      : origin = 0x005000, length = 0x000040     /* McBSP-A�Ĵ��� */
   MCBSPB      : origin = 0x005040, length = 0x000040     /* McBSP-B�Ĵ��� */

   ECANA       : origin = 0x006000, length = 0x000040     /* eCAN-A���ƺ�״̬�Ĵ��� */
   ECANA_LAM   : origin = 0x006040, length = 0x000040     /* eCAN-A���ؽ������μĴ��� */
   ECANA_MOTS  : origin = 0x006080, length = 0x000040     /* eCAN-A��Ϣ����ʱ����Ĵ��� */
   ECANA_MOTO  : origin = 0x0060C0, length = 0x000040     /* eCAN-A��Ϣ����ʱ�Ĵ��� */
   ECANA_MBOX  : origin = 0x006100, length = 0x000100     /* eCAN-A����Ĵ��� */

   ECANB       : origin = 0x006200, length = 0x000040     /* eCAN-B���ƺ�״̬�Ĵ��� */
   ECANB_LAM   : origin = 0x006240, length = 0x000040     /* eCAN-B���ؽ������μĴ��� */
   ECANB_MOTS  : origin = 0x006280, length = 0x000040     /* eCAN-B��Ϣ����ʱ����Ĵ��� */
   ECANB_MOTO  : origin = 0x0062C0, length = 0x000040     /* eCAN-B��Ϣ����ʱ�Ĵ��� */
   ECANB_MBOX  : origin = 0x006300, length = 0x000100     /* eCAN-B����Ĵ��� */

   EPWM1       : origin = 0x006800, length = 0x000022     /* ��ǿ��PWM1�Ĵ��� */
   EPWM2       : origin = 0x006840, length = 0x000022     /* ��ǿ��PWM2�Ĵ��� */
   EPWM3       : origin = 0x006880, length = 0x000022     /* ��ǿ��PWM3�Ĵ��� */
   EPWM4       : origin = 0x0068C0, length = 0x000022     /* ��ǿ��PWM4�Ĵ��� */
   EPWM5       : origin = 0x006900, length = 0x000022     /* ��ǿ��PWM5�Ĵ��� */
   EPWM6       : origin = 0x006940, length = 0x000022     /* ��ǿ��PWM6�Ĵ��� */

   ECAP1       : origin = 0x006A00, length = 0x000020     /* ��ǿ�Ͳ���1�Ĵ��� */
   ECAP2       : origin = 0x006A20, length = 0x000020     /* ��ǿ�Ͳ���2�Ĵ��� */
   ECAP3       : origin = 0x006A40, length = 0x000020     /* ��ǿ�Ͳ���3�Ĵ��� */
   ECAP4       : origin = 0x006A60, length = 0x000020     /* ��ǿ�Ͳ���4�Ĵ��� */
   ECAP5       : origin = 0x006A80, length = 0x000020     /* ��ǿ�Ͳ���5�Ĵ��� */
   ECAP6       : origin = 0x006AA0, length = 0x000020     /* ��ǿ�Ͳ���6�Ĵ��� */
 
   EQEP1       : origin = 0x006B00, length = 0x000040     /* ��ǿ��QEP1�Ĵ��� */
   EQEP2       : origin = 0x006B40, length = 0x000040     /* ��ǿ��QEP2�Ĵ��� */

   GPIOCTRL    : origin = 0x006F80, length = 0x000040     /* GPIO���ƼĴ��� */
   GPIODAT     : origin = 0x006FC0, length = 0x000020     /* GPIO���ݼĴ��� */
   GPIOINT     : origin = 0x006FE0, length = 0x000020     /* GPIO�жϼ��͹���ģʽ����ѡ��Ĵ��� */
                 
   SYSTEM      : origin = 0x007010, length = 0x000020     /* ϵͳ���ƼĴ��� */
   SPIA        : origin = 0x007040, length = 0x000010     /* SPI-A�Ĵ��� */
   SCIA        : origin = 0x007050, length = 0x000010     /* SCI-A�Ĵ��� */
   XINTRUPT    : origin = 0x007070, length = 0x000010     /* �ⲿ�жϼĴ��� */

   ADC         : origin = 0x007100, length = 0x000020     /* ADC�Ĵ��� */

   SCIB        : origin = 0x007750, length = 0x000010     /* SCI-B�Ĵ��� */

   SCIC        : origin = 0x007770, length = 0x000010     /* SCI-C�Ĵ��� */
   
   I2CA        : origin = 0x007900, length = 0x000040     /* I2C-A�Ĵ��� */
   
   CSM_PWL     : origin = 0x33FFF8, length = 0x000008     /* ����FLASHA. CSM������λ��. */

   PARTID      : origin = 0x380090, length = 0x000001     /* оƬID�Ĵ���λ�� */
}

 
SECTIONS
{
   PieVectTableFile : > PIE_VECT,   PAGE = 1

/*** ����֡0�Ĵ����ṹ�� ***/
   DevEmuRegsFile    : > DEV_EMU,     PAGE = 1
   FlashRegsFile     : > FLASH_REGS,  PAGE = 1
   CsmRegsFile       : > CSM,         PAGE = 1
   AdcMirrorFile     : > ADC_MIRROR,  PAGE = 1 
   XintfRegsFile     : > XINTF,       PAGE = 1
   CpuTimer0RegsFile : > CPU_TIMER0,  PAGE = 1
   CpuTimer1RegsFile : > CPU_TIMER1,  PAGE = 1
   CpuTimer2RegsFile : > CPU_TIMER2,  PAGE = 1  
   PieCtrlRegsFile   : > PIE_CTRL,    PAGE = 1     
   DmaRegsFile       : > DMA,         PAGE = 1 

/*** ����֡3�Ĵ����ṹ�� ***/
   McbspaRegsFile    : > MCBSPA,      PAGE = 1
   McbspbRegsFile    : > MCBSPB,      PAGE = 1

/*** ����֡1�Ĵ����ṹ�� ***/
   ECanaRegsFile     : > ECANA,       PAGE = 1
   ECanaLAMRegsFile  : > ECANA_LAM    PAGE = 1   
   ECanaMboxesFile   : > ECANA_MBOX   PAGE = 1
   ECanaMOTSRegsFile : > ECANA_MOTS   PAGE = 1
   ECanaMOTORegsFile : > ECANA_MOTO   PAGE = 1
   
   ECanbRegsFile     : > ECANB,       PAGE = 1
   ECanbLAMRegsFile  : > ECANB_LAM    PAGE = 1   
   ECanbMboxesFile   : > ECANB_MBOX   PAGE = 1
   ECanbMOTSRegsFile : > ECANB_MOTS   PAGE = 1
   ECanbMOTORegsFile : > ECANB_MOTO   PAGE = 1
   
   EPwm1RegsFile     : > EPWM1        PAGE = 1   
   EPwm2RegsFile     : > EPWM2        PAGE = 1   
   EPwm3RegsFile     : > EPWM3        PAGE = 1   
   EPwm4RegsFile     : > EPWM4        PAGE = 1   
   EPwm5RegsFile     : > EPWM5        PAGE = 1   
   EPwm6RegsFile     : > EPWM6        PAGE = 1
   
   ECap1RegsFile     : > ECAP1        PAGE = 1   
   ECap2RegsFile     : > ECAP2        PAGE = 1   
   ECap3RegsFile     : > ECAP3        PAGE = 1   
   ECap4RegsFile     : > ECAP4        PAGE = 1
   ECap5RegsFile     : > ECAP5        PAGE = 1   
   ECap6RegsFile     : > ECAP6        PAGE = 1

   EQep1RegsFile     : > EQEP1        PAGE = 1   
   EQep2RegsFile     : > EQEP2        PAGE = 1               

   GpioCtrlRegsFile  : > GPIOCTRL     PAGE = 1
   GpioDataRegsFile  : > GPIODAT      PAGE = 1
   GpioIntRegsFile   : > GPIOINT      PAGE = 1
   
/*** ����֡2�Ĵ����ṹ�� ***/
   SysCtrlRegsFile   : > SYSTEM,      PAGE = 1
   SpiaRegsFile      : > SPIA,        PAGE = 1
   SciaRegsFile      : > SCIA,        PAGE = 1
   XIntruptRegsFile  : > XINTRUPT,    PAGE = 1
   AdcRegsFile       : > ADC,         PAGE = 1
   ScibRegsFile      : > SCIB,        PAGE = 1
   ScicRegsFile      : > SCIC,        PAGE = 1
   I2caRegsFile      : > I2CA,        PAGE = 1
              
/*** ���밲ȫģ��Ĵ����ṹ�� ***/
   CsmPwlFile        : > CSM_PWL,     PAGE = 1

/*** оƬID�Ĵ����ṹ�� ***/
   PartIdRegsFile    : > PARTID,      PAGE = 1

}
