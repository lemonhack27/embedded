/******************************************************************************
�ļ���                     : AVP33x_DMA.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xоƬDMAģ���ʼ������������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#include "AVP33x_Device.h"     // Headerfile Include File
#include "AVP33x_Examples.h"   // Examples Include File

//---------------------------------------------------------------------------
// DMAInitialize:
//---------------------------------------------------------------------------
// ��ʼ��DMA�Ĵ���
//
void DMAInitialize(void)
{
    EALLOW;

    DmaRegs.DMACTRL.bit.HARDRESET = 1;  // Ӳ����λDMA
    asm (" nop");                       // һ����ʱȷ����λ���
    DmaRegs.DEBUGCTRL.bit.FREE = 1;     // DMA�����ܷ������Ӱ��

    EDIS;
}

//---------------------------------------------------------------------------
// DMACH1AddrConfig:
//---------------------------------------------------------------------------
// DMAͨ��1���͵�ַ���ú���
//
void DMACH1AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source)
{
    EALLOW;
    // ����DMAԴ��ַ
    DmaRegs.CH1.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // ָ��Դ����ʼ��ַ
    DmaRegs.CH1.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

    // ����DMAĿ���ַ
    DmaRegs.CH1.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;	    // ָ��Ŀ�����ʼ��ַ
    DmaRegs.CH1.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;

    EDIS;
}

//---------------------------------------------------------------------------
// DMACH1BurstConfig:
//---------------------------------------------------------------------------
// DMAͨ��1ͻ�����ú���
//
void DMACH1BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep)
{
    EALLOW;

    // ����ͻ���Ĵ���
    DmaRegs.CH1.BURST_SIZE.all = bsize;         // ����һ��ͻ�����͵����ݸ���
    DmaRegs.CH1.SRC_BURST_STEP = srcbstep;	    // ������һ��ͻ�����ͽ�����Դ��ַָ������/���ٵĲ���
    DmaRegs.CH1.DST_BURST_STEP = desbstep;      // ������һ��ͻ�����ͽ�����Ŀ���ַָ������/���ٵĲ���

    EDIS;
}

//---------------------------------------------------------------------------
// DMACH1TransferConfig:
//---------------------------------------------------------------------------
// DMAͨ��1�⻷�������ú���
//
void DMACH1TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep)
{
    EALLOW;

	// �����⻷���ͼĴ���
	DmaRegs.CH1.TRANSFER_SIZE = tsize;          // ������һ�δ��͹�����ͻ�����͵Ĵ���
	DmaRegs.CH1.SRC_TRANSFER_STEP = srctstep;   // ������һ��ͻ�����ͽ�����Դ��ַָ������/���ٵĲ���
	DmaRegs.CH1.DST_TRANSFER_STEP = deststep;   // ������һ��ͻ�����ͽ�����Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH1WrapConfig:
//---------------------------------------------------------------------------
// DMAͨ��1�������ú���
//
void DMACH1WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep)
{
	EALLOW;

	// ���÷��ؼĴ���
	DmaRegs.CH1.SRC_WRAP_SIZE = srcwsize;	    // �����ڷ���Դ�Ŀ�ʼ��ַָ��ǰͻ�����͵Ĵ�����������ֵ��TRANSFER_SIZE����Դ��ַ���᷵�أ���֮��������ֵ��TRANSFER_SIZEС����SRC_TRANSFER_STEP�������á�
    DmaRegs.CH1.SRC_WRAP_STEP = srcwstep;	    // �����ڷ��ؼĴ��������Դ��ַָ������/���ٵĲ���

	DmaRegs.CH1.DST_WRAP_SIZE = deswsize;	    // �����ڷ���Ŀ��Ŀ�ʼ��ַָ��ǰͻ�����͵Ĵ���������ֵ��TRANSFER_SIZE����Ŀ���ַ���᷵�أ���֮��������ֵ��TRANSFER_SIZEС����DST_TRANSFER_STEP�������á�
	DmaRegs.CH1.DST_WRAP_STEP = deswstep;	    // �����ڷ��ؼĴ��������Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH1ModeConfig:
//---------------------------------------------------------------------------
// DMAͨ��1ģʽ���ú���
//
void DMACH1ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte)
{
	EALLOW;

	// ����ģʽ�Ĵ���
	DmaRegs.CH1.MODE.bit.PERINTSEL = persel;	    // �������ж�Դ���͸�DMAͨ��1
	DmaRegs.CH1.MODE.bit.PERINTE = perinte;       	// ʹ�������жϴ����ź�
	DmaRegs.CH1.MODE.bit.ONESHOT = oneshot;       	// ʹ�ܵ��δ�������
	DmaRegs.CH1.MODE.bit.CONTINUOUS = cont;    		// ʹ����������
	DmaRegs.CH1.MODE.bit.SYNCE = synce;         	// ����ͬ���ź�ʹ��
	DmaRegs.CH1.MODE.bit.SYNCSEL = syncsel;       	// ͬ��ģʽѡ��
	DmaRegs.CH1.MODE.bit.OVRINTE = ovrinte;         // ����ж�ʹ��
	DmaRegs.CH1.MODE.bit.DATASIZE = datasize;      	// ѡ��DMAͨ�������ݿ��
	DmaRegs.CH1.MODE.bit.CHINTMODE = chintmode;		// ѡ��ͨ�����ж�ģʽ������һ�δ��͵Ŀ�ʼ���ǽ���ʱ�����жϣ�
	DmaRegs.CH1.MODE.bit.CHINTE = chinte;        	// ͨ���ж�ʹ��

	// �����־
	DmaRegs.CH1.CONTROL.bit.PERINTCLR = 1;  		// �����������ⲿ�ж��¼�������PEIINTFLG����
	DmaRegs.CH1.CONTROL.bit.SYNCCLR = 1;    		// ����������ͬ���¼�������SYNCFLG����
	DmaRegs.CH1.CONTROL.bit.ERRCLR = 1; 	     	// ���ͬ�������־λ������OVRFLG����

	// ��ʼ��PIE����
	PieCtrlRegs.PIEIER7.bit.INTx1 = 1;              // ʹ��DMAͨ��1��PIE���ж�

	EDIS;
}

//---------------------------------------------------------------------------
// StartDMACH1:
//---------------------------------------------------------------------------
// DMAͨ��1��������
//
void StartDMACH1(void)
{
	EALLOW;
	DmaRegs.CH1.CONTROL.bit.RUN = 1;                // ����DMAͨ��1
	EDIS;
}


//---------------------------------------------------------------------------
// DMACH2AddrConfig:
//---------------------------------------------------------------------------
// DMAͨ��2���͵�ַ���ú���
//
void DMACH2AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source)
{
	EALLOW;

	// ����DMAԴ��ַ
	DmaRegs.CH2.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // ָ��Դ����ʼ��ַ
	DmaRegs.CH2.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

	// ����DMAĿ���ַ
	DmaRegs.CH2.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;	    // ָ��Ŀ�����ʼ��ַ
	DmaRegs.CH2.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


	EDIS;
}

//---------------------------------------------------------------------------
// DMACH2BurstConfig:
//---------------------------------------------------------------------------
// DMAͨ��2ͻ�����ú���
//
void DMACH2BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep)
{
	EALLOW;

	// ����ͻ���Ĵ���
	DmaRegs.CH2.BURST_SIZE.all = bsize;         // ����һ��ͻ�����͵����ݸ���
	DmaRegs.CH2.SRC_BURST_STEP = srcbstep;		// ������һ��ͻ�����ͽ�����Դ��ַָ������/���ٵĲ���
	DmaRegs.CH2.DST_BURST_STEP = desbstep;      // ������һ��ͻ�����ͽ�����Ŀ���ַָ������/���ٵĲ���


	EDIS;
}

//---------------------------------------------------------------------------
// DMACH2TransferConfig:
//---------------------------------------------------------------------------
// DMAͨ��2�⻷�������ú���
//
void DMACH2TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep)
{
	EALLOW;

	// �����⻷���ͼĴ���
	DmaRegs.CH2.TRANSFER_SIZE = tsize;          // ������һ�δ��͹�����ͻ�����͵Ĵ���
	DmaRegs.CH2.SRC_TRANSFER_STEP = srctstep;	// ������һ��ͻ�����ͽ�����Դ��ַָ������/���ٵĲ���
	DmaRegs.CH2.DST_TRANSFER_STEP = deststep;	// ������һ��ͻ�����ͽ�����Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH2WrapConfig:
//---------------------------------------------------------------------------
// DMAͨ��2�������ú���
//
void DMACH2WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep)
{
	EALLOW;

	// ���÷��ؼĴ���
	DmaRegs.CH2.SRC_WRAP_SIZE = srcwsize;		// �����ڷ���Դ�Ŀ�ʼ��ַָ��ǰͻ�����͵Ĵ���
    DmaRegs.CH2.SRC_WRAP_STEP = srcwstep;		// �����ڷ��ؼĴ��������Դ��ַָ������/���ٵĲ���

	DmaRegs.CH2.DST_WRAP_SIZE = deswsize;		// �����ڷ���Ŀ��Ŀ�ʼ��ַָ��ǰͻ�����͵Ĵ���
	DmaRegs.CH2.DST_WRAP_STEP = deswstep;		// �����ڷ��ؼĴ��������Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH2ModeConfig:
//---------------------------------------------------------------------------
// DMAͨ��2ģʽ���ú���
//
void DMACH2ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte)
{
	EALLOW;

	// ����ģʽ�Ĵ���
	DmaRegs.CH2.MODE.bit.PERINTSEL = persel;	    // �������ж�Դ���͸�DMAͨ��2
	DmaRegs.CH2.MODE.bit.PERINTE = perinte;       	// ʹ�������жϴ����ź�
	DmaRegs.CH2.MODE.bit.ONESHOT = oneshot;       	// ʹ�ܵ��δ�������
	DmaRegs.CH2.MODE.bit.CONTINUOUS = cont;    		// ʹ����������
	DmaRegs.CH2.MODE.bit.SYNCE = synce;         	// ����ͬ���ź�ʹ��
	DmaRegs.CH2.MODE.bit.SYNCSEL = syncsel;       	// ͬ��ģʽѡ��
	DmaRegs.CH2.MODE.bit.OVRINTE = ovrinte;         // ����ж�ʹ��
	DmaRegs.CH2.MODE.bit.DATASIZE = datasize;      	// ѡ��DMAͨ�������ݿ��
	DmaRegs.CH2.MODE.bit.CHINTMODE = chintmode;		// ѡ��ͨ�����ж�ģʽ������һ�δ��͵Ŀ�ʼ���ǽ���ʱ�����жϣ�
	DmaRegs.CH2.MODE.bit.CHINTE = chinte;        	// ͨ���ж�ʹ��

	// �����־
	DmaRegs.CH2.CONTROL.bit.PERINTCLR = 1;  		// �����������ⲿ�ж��¼�������PEIINTFLG����
	DmaRegs.CH2.CONTROL.bit.SYNCCLR = 1;    		// ����������ͬ���¼�������SYNCFLG����
	DmaRegs.CH2.CONTROL.bit.ERRCLR = 1; 	     	// ���ͬ�������־λ������OVRFLG����

	// ��ʼ��PIE����
	PieCtrlRegs.PIEIER7.bit.INTx2 = 1;              // ʹ��DMAͨ��2��PIE���ж�

	EDIS;
}

//---------------------------------------------------------------------------
// StartDMACH2:
//---------------------------------------------------------------------------
// DMAͨ��2��������
//
void StartDMACH2(void)
{
	EALLOW;
	DmaRegs.CH2.CONTROL.bit.RUN = 1;                // ����DMAͨ��2
	EDIS;
}


//---------------------------------------------------------------------------
// DMACH3AddrConfig:
//---------------------------------------------------------------------------
// DMAͨ��3���͵�ַ���ú���
//
void DMACH3AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source)
{
	EALLOW;

	// ����DMAԴ��ַ
	DmaRegs.CH3.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // ָ��Դ����ʼ��ַ
	DmaRegs.CH3.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

	// ����DMAĿ���ַ
	DmaRegs.CH3.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;	    // ָ��Ŀ�����ʼ��ַ
	DmaRegs.CH3.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH3BurstConfig:
//---------------------------------------------------------------------------
// DMAͨ��3ͻ�����ú���
//
void DMACH3BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep)
{
	EALLOW;

	// ����ͻ���Ĵ���
	DmaRegs.CH3.BURST_SIZE.all = bsize;	                // ����һ��ͻ�����͵����ݸ���
	DmaRegs.CH3.SRC_BURST_STEP = srcbstep;			    // ������һ��ͻ�����ͽ�����Դ��ַָ������/���ٵĲ���
	DmaRegs.CH3.DST_BURST_STEP = desbstep;              // ������һ��ͻ�����ͽ�����Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH3TransferConfig:
//---------------------------------------------------------------------------
// DMAͨ��3�⻷�������ú���
//
void DMACH3TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep)
{
	EALLOW;

	// �����⻷���ͼĴ���
	DmaRegs.CH3.TRANSFER_SIZE = tsize;                  // ������һ�δ��͹�����ͻ�����͵Ĵ���
	DmaRegs.CH3.SRC_TRANSFER_STEP = srctstep;			// ������һ��ͻ�����ͽ�����Դ��ַָ������/���ٵĲ���
	DmaRegs.CH3.DST_TRANSFER_STEP = deststep;			// ������һ��ͻ�����ͽ�����Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH3WrapConfig:
//---------------------------------------------------------------------------
// DMAͨ��3�������ú���
//
void DMACH3WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep)
{
	EALLOW;

	// ���÷��ؼĴ���
	DmaRegs.CH3.SRC_WRAP_SIZE = srcwsize;       // �����ڷ���Դ�Ŀ�ʼ��ַָ��ǰͻ�����͵Ĵ���
    DmaRegs.CH3.SRC_WRAP_STEP = srcwstep;		// �����ڷ��ؼĴ��������Դ��ַָ������/���ٵĲ���

	DmaRegs.CH3.DST_WRAP_SIZE = deswsize;		// �����ڷ���Ŀ��Ŀ�ʼ��ַָ��ǰͻ�����͵Ĵ���
	DmaRegs.CH3.DST_WRAP_STEP = deswstep;		// �����ڷ��ؼĴ��������Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH3ModeConfig:
//---------------------------------------------------------------------------
// DMAͨ��3ģʽ���ú���
//
void DMACH3ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte)
{
	EALLOW;

	// ����ģʽ�Ĵ���
	DmaRegs.CH3.MODE.bit.PERINTSEL = persel;	    // �������ж�Դ���͸�DMAͨ��3
	DmaRegs.CH3.MODE.bit.PERINTE = perinte;       	// ʹ�������жϴ����ź�
	DmaRegs.CH3.MODE.bit.ONESHOT = oneshot;       	// ʹ�ܵ��δ�������
	DmaRegs.CH3.MODE.bit.CONTINUOUS = cont;    		// ʹ����������
	DmaRegs.CH3.MODE.bit.SYNCE = synce;         	// ����ͬ���ź�ʹ��
	DmaRegs.CH3.MODE.bit.SYNCSEL = syncsel;       	// ͬ��ģʽѡ��
	DmaRegs.CH3.MODE.bit.OVRINTE = ovrinte;         // ����ж�ʹ��
	DmaRegs.CH3.MODE.bit.DATASIZE = datasize;      	// ѡ��DMAͨ�������ݿ��
	DmaRegs.CH3.MODE.bit.CHINTMODE = chintmode;		// ѡ��ͨ�����ж�ģʽ������һ�δ��͵Ŀ�ʼ���ǽ���ʱ�����жϣ�
	DmaRegs.CH3.MODE.bit.CHINTE = chinte;        	// ͨ���ж�ʹ��

	// �����־
	DmaRegs.CH3.CONTROL.bit.PERINTCLR = 1;  		// �����������ⲿ�ж��¼�������PEIINTFLG����
	DmaRegs.CH3.CONTROL.bit.SYNCCLR = 1;    		// ����������ͬ���¼�������SYNCFLG����
	DmaRegs.CH3.CONTROL.bit.ERRCLR = 1; 	     	// ���ͬ�������־λ������OVRFLG����

	// ��ʼ��PIE����
	PieCtrlRegs.PIEIER7.bit.INTx3 = 1;              // ʹ��DMAͨ��3��PIE���ж�

	EDIS;
}

//---------------------------------------------------------------------------
// StartDMACH3:
//---------------------------------------------------------------------------
// DMAͨ��3��������
//
void StartDMACH3(void)
{
	EALLOW;
	DmaRegs.CH3.CONTROL.bit.RUN = 1;                // ����DMAͨ��3
	EDIS;
}


//---------------------------------------------------------------------------
// DMACH4AddrConfig:
//---------------------------------------------------------------------------
// DMAͨ��4���͵�ַ���ú���
//
void DMACH4AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source)
{
	EALLOW;

	// ����DMAԴ��ַ
	DmaRegs.CH4.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;	// ָ��Դ����ʼ��ַ
	DmaRegs.CH4.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

	// ����DMAĿ���ַ
	DmaRegs.CH4.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;	    // ָ��Ŀ�����ʼ��ַ
	DmaRegs.CH4.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH4BurstConfig:
//---------------------------------------------------------------------------
// DMAͨ��4ͻ�����ú���
//
void DMACH4BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep)
{
	EALLOW;

	// ����ͻ���Ĵ���
	DmaRegs.CH4.BURST_SIZE.all = bsize;	        // ����һ��ͻ�����͵����ݸ���
	DmaRegs.CH4.SRC_BURST_STEP = srcbstep;		// ������һ��ͻ�����ͽ�����Դ��ַָ������/���ٵĲ���
	DmaRegs.CH4.DST_BURST_STEP = desbstep;      // ������һ��ͻ�����ͽ�����Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH4TransferConfig:
//---------------------------------------------------------------------------
// DMAͨ��4�⻷�������ú���
//
void DMACH4TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep)
{
	EALLOW;

	// �����⻷���ͼĴ���
	DmaRegs.CH4.TRANSFER_SIZE = tsize;          // ������һ�δ��͹�����ͻ�����͵Ĵ���
	DmaRegs.CH4.SRC_TRANSFER_STEP = srctstep;	// ������һ��ͻ�����ͽ�����Դ��ַָ������/���ٵĲ���
	DmaRegs.CH4.DST_TRANSFER_STEP = deststep;	// ������һ��ͻ�����ͽ�����Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH4WrapConfig:
//---------------------------------------------------------------------------
// DMAͨ��4�������ú���
//
void DMACH4WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep)
{
	EALLOW;

	// ���÷��ؼĴ���
	DmaRegs.CH4.SRC_WRAP_SIZE = srcwsize;	    // �����ڷ���Դ�Ŀ�ʼ��ַָ��ǰͻ�����͵Ĵ���
    DmaRegs.CH4.SRC_WRAP_STEP = srcwstep;		// �����ڷ��ؼĴ��������Դ��ַָ������/���ٵĲ���

	DmaRegs.CH4.DST_WRAP_SIZE = deswsize;		// �����ڷ���Ŀ��Ŀ�ʼ��ַָ��ǰͻ�����͵Ĵ���
	DmaRegs.CH4.DST_WRAP_STEP = deswstep;		// �����ڷ��ؼĴ��������Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH4ModeConfig:
//---------------------------------------------------------------------------
// DMAͨ��4ģʽ���ú���
//
void DMACH4ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte)
{
	EALLOW;

	// ����ģʽ�Ĵ���
	DmaRegs.CH4.MODE.bit.PERINTSEL = persel;	    // �������ж�Դ���͸�DMAͨ��4
	DmaRegs.CH4.MODE.bit.PERINTE = perinte;       	// ʹ�������жϴ����ź�
	DmaRegs.CH4.MODE.bit.ONESHOT = oneshot;       	// ʹ�ܵ��δ�������
	DmaRegs.CH4.MODE.bit.CONTINUOUS = cont;    		// ʹ����������
	DmaRegs.CH4.MODE.bit.SYNCE = synce;         	// ����ͬ���ź�ʹ��
	DmaRegs.CH4.MODE.bit.SYNCSEL = syncsel;       	// ͬ��ģʽѡ��
	DmaRegs.CH4.MODE.bit.OVRINTE = ovrinte;         // ����ж�ʹ��
	DmaRegs.CH4.MODE.bit.DATASIZE = datasize;      	// ѡ��DMAͨ�������ݿ��
	DmaRegs.CH4.MODE.bit.CHINTMODE = chintmode;		// ѡ��ͨ�����ж�ģʽ������һ�δ��͵Ŀ�ʼ���ǽ���ʱ�����жϣ�
	DmaRegs.CH4.MODE.bit.CHINTE = chinte;        	// ͨ���ж�ʹ��

	// �����־
	DmaRegs.CH4.CONTROL.bit.PERINTCLR = 1;  		// �����������ⲿ�ж��¼�������PEIINTFLG����
	DmaRegs.CH4.CONTROL.bit.SYNCCLR = 1;    		// ����������ͬ���¼�������SYNCFLG����
	DmaRegs.CH4.CONTROL.bit.ERRCLR = 1; 	     	// ���ͬ�������־λ������OVRFLG����

	// ��ʼ��PIE����
	PieCtrlRegs.PIEIER7.bit.INTx4 = 1;              // ʹ��DMAͨ��4��PIE���ж�

	EDIS;
}

//---------------------------------------------------------------------------
// StartDMACH4:
//---------------------------------------------------------------------------
// DMAͨ��4��������
//
void StartDMACH4(void)
{
	EALLOW;
	DmaRegs.CH4.CONTROL.bit.RUN = 1;                // ����DMAͨ��4
	EDIS;
}


//---------------------------------------------------------------------------
// DMACH5AddrConfig:
//---------------------------------------------------------------------------
// DMAͨ��5���͵�ַ���ú���
//
void DMACH5AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source)
{
	EALLOW;

	// ����DMAԴ��ַ
	DmaRegs.CH5.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;	// ָ��Դ����ʼ��ַ
	DmaRegs.CH5.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

	// ����DMAĿ���ַ
	DmaRegs.CH5.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;	    // ָ��Ŀ�����ʼ��ַ
	DmaRegs.CH5.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


	EDIS;
}

//---------------------------------------------------------------------------
// DMACH5BurstConfig:
//---------------------------------------------------------------------------
// DMAͨ��5ͻ�����ú���
//
void DMACH5BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep)
{
	EALLOW;

	// ����ͻ���Ĵ���
	DmaRegs.CH5.BURST_SIZE.all = bsize;         // ����һ��ͻ�����͵����ݸ���
	DmaRegs.CH5.SRC_BURST_STEP = srcbstep;		// ������һ��ͻ�����ͽ�����Դ��ַָ������/���ٵĲ���
	DmaRegs.CH5.DST_BURST_STEP = desbstep;      // ������һ��ͻ�����ͽ�����Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH5TransferConfig:
//---------------------------------------------------------------------------
// DMAͨ��5�⻷�������ú���
//
void DMACH5TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep)
{
	EALLOW;

	// �����⻷���ͼĴ���
	DmaRegs.CH5.TRANSFER_SIZE = tsize;          // ������һ�δ��͹�����ͻ�����͵Ĵ���
	DmaRegs.CH5.SRC_TRANSFER_STEP = srctstep;	// ������һ��ͻ�����ͽ�����Դ��ַָ������/���ٵĲ���
	DmaRegs.CH5.DST_TRANSFER_STEP = deststep;	// ������һ��ͻ�����ͽ�����Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH5WrapConfig:
//---------------------------------------------------------------------------
// DMAͨ��5�������ú���
//
void DMACH5WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep)
{
	EALLOW;

	// ���÷��ؼĴ���
	DmaRegs.CH5.SRC_WRAP_SIZE = srcwsize;       // �����ڷ���Դ�Ŀ�ʼ��ַָ��ǰͻ�����͵Ĵ���
    DmaRegs.CH5.SRC_WRAP_STEP = srcwstep;		// �����ڷ��ؼĴ��������Դ��ַָ������/���ٵĲ���

	DmaRegs.CH5.DST_WRAP_SIZE = deswsize;		// �����ڷ���Ŀ��Ŀ�ʼ��ַָ��ǰͻ�����͵Ĵ���
	DmaRegs.CH5.DST_WRAP_STEP = deswstep;		// �����ڷ��ؼĴ��������Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH5ModeConfig:
//---------------------------------------------------------------------------
// DMAͨ��5ģʽ���ú���
//
void DMACH5ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte)
{
	EALLOW;

	// ����ģʽ�Ĵ���
	DmaRegs.CH5.MODE.bit.PERINTSEL = persel;	    // �������ж�Դ���͸�DMAͨ��5
	DmaRegs.CH5.MODE.bit.PERINTE = perinte;       	// ʹ�������жϴ����ź�
	DmaRegs.CH5.MODE.bit.ONESHOT = oneshot;       	// ʹ�ܵ��δ�������
	DmaRegs.CH5.MODE.bit.CONTINUOUS = cont;    		// ʹ����������
	DmaRegs.CH5.MODE.bit.SYNCE = synce;         	// ����ͬ���ź�ʹ��
	DmaRegs.CH5.MODE.bit.SYNCSEL = syncsel;       	// ͬ��ģʽѡ��
	DmaRegs.CH5.MODE.bit.OVRINTE = ovrinte;         // ����ж�ʹ��
	DmaRegs.CH5.MODE.bit.DATASIZE = datasize;      	// ѡ��DMAͨ�������ݿ��
	DmaRegs.CH5.MODE.bit.CHINTMODE = chintmode;		// ѡ��ͨ�����ж�ģʽ������һ�δ��͵Ŀ�ʼ���ǽ���ʱ�����жϣ�
	DmaRegs.CH5.MODE.bit.CHINTE = chinte;        	// ͨ���ж�ʹ��

	// �����־
	DmaRegs.CH5.CONTROL.bit.PERINTCLR = 1;  		// �����������ⲿ�ж��¼�������PEIINTFLG����
	DmaRegs.CH5.CONTROL.bit.SYNCCLR = 1;    		// ����������ͬ���¼�������SYNCFLG����
	DmaRegs.CH5.CONTROL.bit.ERRCLR = 1; 	     	// ���ͬ�������־λ������OVRFLG����

	// ��ʼ��PIE����
	PieCtrlRegs.PIEIER7.bit.INTx5 = 1;              // ʹ��DMAͨ��5��PIE���ж�

	EDIS;
}

//---------------------------------------------------------------------------
// StartDMACH5:
//---------------------------------------------------------------------------
// DMAͨ��5��������
//
void StartDMACH5(void)
{
	EALLOW;
	DmaRegs.CH5.CONTROL.bit.RUN = 1;                 // ����DMAͨ��5
	EDIS;
}


//---------------------------------------------------------------------------
// DMACH6AddrConfig:
//---------------------------------------------------------------------------
// DMAͨ��6���͵�ַ���ú���
//
void DMACH6AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source)
{
	EALLOW;

	// ����DMAԴ��ַ
	DmaRegs.CH6.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;	// ָ��Դ����ʼ��ַ
	DmaRegs.CH6.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

	// ����DMAĿ���ַ
	DmaRegs.CH6.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;	    // ָ��Ŀ�����ʼ��ַ
	DmaRegs.CH6.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH6BurstConfig:
//---------------------------------------------------------------------------
// DMAͨ��6ͻ�����ú���
//
void DMACH6BurstConfig(Uint16 bsize,Uint16 srcbstep, int16 desbstep)
{
	EALLOW;

	// ����ͻ���Ĵ���
	DmaRegs.CH6.BURST_SIZE.all = bsize;	        // ����һ��ͻ�����͵����ݸ���
	DmaRegs.CH6.SRC_BURST_STEP = srcbstep;		// ������һ��ͻ�����ͽ�����Դ��ַָ������/���ٵĲ���
	DmaRegs.CH6.DST_BURST_STEP = desbstep;      // ������һ��ͻ�����ͽ�����Ŀ���ַָ������/���ٵĲ���


	EDIS;
}

//---------------------------------------------------------------------------
// DMACH6TransferConfig:
//---------------------------------------------------------------------------
// DMAͨ��6�⻷�������ú���
//
void DMACH6TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep)
{
	EALLOW;

	// �����⻷���ͼĴ���
	DmaRegs.CH6.TRANSFER_SIZE = tsize;          // ������һ�δ��͹�����ͻ�����͵Ĵ���
	DmaRegs.CH6.SRC_TRANSFER_STEP = srctstep;	// ������һ��ͻ�����ͽ�����Դ��ַָ������/���ٵĲ���
	DmaRegs.CH6.DST_TRANSFER_STEP = deststep;	// ������һ��ͻ�����ͽ�����Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH6WrapConfig:
//---------------------------------------------------------------------------
// DMAͨ��6�������ú���
//
void DMACH6WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep)
{
	EALLOW;

	// ���÷��ؼĴ���
	DmaRegs.CH6.SRC_WRAP_SIZE = srcwsize;	    // �����ڷ���Դ�Ŀ�ʼ��ַָ��ǰͻ�����͵Ĵ���
    DmaRegs.CH6.SRC_WRAP_STEP = srcwstep;		// �����ڷ��ؼĴ��������Դ��ַָ������/���ٵĲ���

	DmaRegs.CH6.DST_WRAP_SIZE = deswsize;		// �����ڷ���Ŀ��Ŀ�ʼ��ַָ��ǰͻ�����͵Ĵ���
	DmaRegs.CH6.DST_WRAP_STEP = deswstep;		// �����ڷ��ؼĴ��������Ŀ���ַָ������/���ٵĲ���

	EDIS;
}

//---------------------------------------------------------------------------
// DMACH6ModeConfig:
//---------------------------------------------------------------------------
// DMAͨ��6ģʽ���ú���
//
void DMACH6ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte)
{
	EALLOW;

	// ����ģʽ�Ĵ���
	DmaRegs.CH6.MODE.bit.PERINTSEL = persel;	    // �������ж�Դ���͸�DMAͨ��6
	DmaRegs.CH6.MODE.bit.PERINTE = perinte;       	// ʹ�������жϴ����ź�
	DmaRegs.CH6.MODE.bit.ONESHOT = oneshot;       	// ʹ�ܵ��δ�������
	DmaRegs.CH6.MODE.bit.CONTINUOUS = cont;    		// ʹ����������
	DmaRegs.CH6.MODE.bit.SYNCE = synce;         	// ����ͬ���ź�ʹ��
	DmaRegs.CH6.MODE.bit.SYNCSEL = syncsel;       	// ͬ��ģʽѡ��
	DmaRegs.CH6.MODE.bit.OVRINTE = ovrinte;         // ����ж�ʹ��
	DmaRegs.CH6.MODE.bit.DATASIZE = datasize;      	// ѡ��DMAͨ�������ݿ��
	DmaRegs.CH6.MODE.bit.CHINTMODE = chintmode;		// ѡ��ͨ�����ж�ģʽ������һ�δ��͵Ŀ�ʼ���ǽ���ʱ�����жϣ�
	DmaRegs.CH6.MODE.bit.CHINTE = chinte;        	// ͨ���ж�ʹ��

	// Clear any spurious flags:
	DmaRegs.CH6.CONTROL.bit.PERINTCLR = 1;  		// �����������ⲿ�ж��¼�������PEIINTFLG����
	DmaRegs.CH6.CONTROL.bit.SYNCCLR = 1;    		// ����������ͬ���¼�������SYNCFLG����
	DmaRegs.CH6.CONTROL.bit.ERRCLR = 1; 	     	// ���ͬ�������־λ������OVRFLG����

	// Initialize PIE vector for CPU interrupt:
	PieCtrlRegs.PIEIER7.bit.INTx6 = 1;              // ʹ��DMAͨ��6��PIE���ж�

	EDIS;
}

//---------------------------------------------------------------------------
// StartDMACH6:
//---------------------------------------------------------------------------
// DMAͨ��6��������
//
void StartDMACH6(void)
{
	EALLOW;
	DmaRegs.CH6.CONTROL.bit.RUN = 1;                // ����DMAͨ��6
	EDIS;
}

//===========================================================================
// No more.
//===========================================================================
