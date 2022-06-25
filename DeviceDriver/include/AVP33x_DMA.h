/******************************************************************************
�ļ���                     : AVP33x_DMA.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33x DMAģ��Ĵ�������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_DMA_H
#define AVP33x_DMA_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// ͨ��ģʽ�Ĵ���λ���壺
struct MODE_BITS {          // λ����
    Uint16 PERINTSEL:5;     // 4:0    �����ж�Դ��ͬ��ѡ��λ(R/W):
                            //        0     ���ж�Դ
						    //        1               �ж�ԴΪSEQ1INT��ͬ���ź�ΪADCSYNC
                            //        2     �ж�ԴΪSEQ2INT����ͬ���ź�
							//        3               �ж�ԴΪXINT1����ͬ���ź�
							//        4               �ж�ԴΪXINT2����ͬ���ź�
							//        5               �ж�ԴΪXINT3����ͬ���ź�
							//        6               �ж�ԴΪXINT4����ͬ���ź�
							//        7               �ж�ԴΪXINT5����ͬ���ź�
							//        8               �ж�ԴΪXINT6����ͬ���ź�
							//        9               �ж�ԴΪXINT7����ͬ���ź�
							//        10            �ж�ԴΪXINT13����ͬ���ź�
							//        11            �ж�ԴΪTINT0����ͬ���ź�
						    //        12            �ж�ԴΪTINT1����ͬ���ź�
						    //        13            �ж�ԴΪTINT2����ͬ���ź�
							//        14            �ж�ԴΪMXEVTA����ͬ���ź�
							//        15            �ж�ԴΪMREVTA����ͬ���ź�
							//        16            �ж�ԴΪMXEVTB����ͬ���ź�
							//        17            �ж�ԴΪMREVTB����ͬ���ź�
	                        //        18            �ж�ԴΪePWM1SOCA����ͬ���ź�
	                        //        19            �ж�ԴΪePWM1SOCB����ͬ���ź�
	                        //        20            �ж�ԴΪePWM2SOCA����ͬ���ź�
	                        //        21            �ж�ԴΪePWM2SOCB����ͬ���ź�
	                        //        22            �ж�ԴΪePWM3SOCA����ͬ���ź�
	                        //        23            �ж�ԴΪePWM3SOCB����ͬ���ź�
	                        //        24            �ж�ԴΪePWM4SOCA����ͬ���ź�
	                        //        25            �ж�ԴΪePWM4SOCB����ͬ���ź�
	                        //        26            �ж�ԴΪePWM5SOCA����ͬ���ź�
	                        //        27            �ж�ԴΪePWM5SOCB����ͬ���ź�
	                        //        28            �ж�ԴΪePWM6SOCA����ͬ���ź�
	                        //        29            �ж�ԴΪePWM6SOCB����ͬ���ź�
	                        //        30:31    ���������ж�Դ��
    Uint16 rsvd1:2;         // 6:5    ����(R=0)
    Uint16 OVRINTE:1;       // 7      ����ж�ʹ��λ(R/W):
                            //        0     ��ֹ����ж�
                            //        1     ʹ������ж�
    Uint16 PERINTE:1;       // 8      �����жϴ���ʹ��λ(R/W):
                            //        0     ��ֹ�����жϴ����ź�
                            //        1     ʹ�������жϴ����ź�
    Uint16 CHINTMODE:1;     // 9      ͨ���ж�ģʽѡ��λ(R/W):
                            //        0     ��һ�δ��Ϳ�ʼ�����ж��¼�
                            //        1     ��һ�δ��ͽ��������ж��¼�
    Uint16 ONESHOT:1;       // 10     ���δ�������λ(R/W):
                            //        0     ÿ���жϴ����ź�����һ��ͻ������
                            //        1     һ���жϴ����ź��������ͻ������
    Uint16 CONTINUOUS:1;    // 11     ������������λ(R/W):
                            //        0     ��TRANSFER_COUNT����ʱ��DMAֹͣ������RUNSTSλ����
                            //        1     ��TRANSFER_COUNT����ʱ��DMA���³�ʼ�������ȴ��´δ����ź�
    Uint16 SYNCE:1;         // 12     ͬ���ź�ʹ��λ(R/W):
                            //        0     ADCSYNC������
                            //        1     ���ͨ�������ж�Դѡ��λ��PERINTSEL��ѡ����ADC����ADCSYNC������ͬ��ADC�ж��ź���DMA���ؼ�����
    Uint16 SYNCSEL:1;       // 13     ͬ��ģʽѡ��λ(R/W):
                            //        0     SRC���ؼ�����������
                            //        1     DST���ؼ�����������
    Uint16 DATASIZE:1;      // 14     DMAͨ�����ݿ�ȿ���λ(R/W):
                            //        0     16λ���ݿ��
                            //        1     32λ���ݿ��
    Uint16 CHINTE:1;        // 15     ͨ���ж�ʹ��λ(R/W):
                            //        0     ��ֹDMA�ж�
                            //        1     ʹ��DMA�ж�
};

union MODE_REG {
    Uint16                all;
    struct MODE_BITS      bit;
};

//----------------------------------------------------
// ͨ�����ƼĴ�����CONTROL��λ����:
struct CONTROL_BITS {       // λ����
    Uint16 RUN:1;           // 0      ͨ������λ(R=0/W=1)
    Uint16 HALT:1;          // 1      ͨ��ֹͣλ(R=0/W=1)
    Uint16 SOFTRESET:1;     // 2      ͨ�������λλ(R=0/W=1)
    Uint16 PERINTFRC:1;     // 3      �����ж�ǿ��λ(R=0/W=1)
    Uint16 PERINTCLR:1;     // 4      �����ж��ź����λ(R=0/W=1)
    Uint16 SYNCFRC:1;       // 5      ͬ���ź�ǿ��λ(R=0/W=1)
    Uint16 SYNCCLR:1;       // 6      ͬ���ź����λ(R=0/W=1)
    Uint16 ERRCLR:1;        // 7      �������λ(R=0/W=1)
    Uint16 PERINTFLG:1;     // 8      �����жϴ����¼���־λ(R):
                            //        0     �������ж��¼�����
                            //        1     �������ж��¼�����
    Uint16 SYNCFLG:1;       // 9      ͬ���źű�־λ(R):
                            //        0     ��ͬ���¼�
                            //        1     ��ͬ���¼�����
    Uint16 SYNCERR:1;       // 10     ͬ�������־λ(R):
                            //        0     ��ͬ�������־
                            //        1     ��ͬ��������
    Uint16 TRANSFERSTS:1;   // 11     ����״̬��־λ(R):
                            //        0     ����Ч�Ĵ��͹���
                            //        1     DMA����ִ��һ�δ��͹���
    Uint16 BURSTSTS:1;      // 12     ͻ������״̬��־λ(R):
                            //        0     ����Ч��ͻ������
                            //        1     DMA����ִ�л����һ��ͻ������
    Uint16 RUNSTS:1;        // 13     ����״̬��־λ(R):
                            //        0     ͨ������ֹ
                            //        1     ͨ����ʹ��
    Uint16 OVRFLG:1;        // 14     �����־λ(R)
                            //        0     ������¼�
                            //        1     ������¼�
    Uint16 rsvd1:1;         // 15     ����(R=0)
};

union CONTROL_REG {
    Uint16                 all;
    struct CONTROL_BITS    bit;
};

//----------------------------------------------------
// DMA���ƼĴ�����DMACTRL��λ���壨��CONTROL��������ģ�:
struct DMACTRL_BITS {       // λ����
    Uint16 HARDRESET:1;     // 0      Ӳ����λλ(R=0/W=1)
    Uint16 PRIORITYRESET:1; // 1      ���ȼ���λλ(R=0/W=1)
    Uint16 rsvd1:14;        // 15:2   Ԥ��(R=0:0)
};

union DMACTRL_REG {
   Uint16                 all;
   struct DMACTRL_BITS    bit;
};

//----------------------------------------------------
// DMA������ƼĴ�����DEBUGCTRL��λ����:
struct DEBUGCTRL_BITS {     // λ����
    Uint16 rsvd1:15;        // 14:0   Ԥ��(R=0:0)
    Uint16 FREE:1;          // 15     ����ģʽ����λ(R/W):
                            //        0     DMA��������֪����ǰDMA��������ɲ��ҵ�ǰDMA������
                            //        1     DMA���ܷ������Ӱ��
};

union DEBUGCTRL_REG {
   Uint16                 all;
   struct DEBUGCTRL_BITS  bit;
};


//----------------------------------------------------
// DMA���ȼ����ƼĴ�����PRIORITYCTRL1��λ����:
struct PRIORITYCTRL1_BITS { // λ����
    Uint16 CH1PRIORITY:1;   // 0      ͨ��1���ȼ�����λ(R/W):
                            //        0     ����ͨ������ͬ���ȼ�
                            //        1     ͨ��1�������ͨ���нϸ����ȼ�
    Uint16 rsvd1:15;        // 15:1   Ԥ��(R=0:0)
};

union PRIORITYCTRL1_REG {
   Uint16                     all;
   struct PRIORITYCTRL1_BITS  bit;
};


//----------------------------------------------------
// DMA���ȼ�״̬�Ĵ�����PRIORITYSTATλ����:
struct PRIORITYSTAT_BITS {      // λ����
    Uint16 ACTIVESTS:3;         // 2:0    ͨ������״̬λ(R):
                                //        0,0,0  ��ͨ��������
                                //        0,0,1  ͨ��1������
                                //        0,1,0  ͨ��2������
                                //        0,1,1  ͨ��3������
                                //        1,0,0  ͨ��4������
                                //        1,0,1  ͨ��5������
                                //        1,1,0  ͨ��6������
    Uint16 rsvd1:1;             // 3      Ԥ��(R=0)
    Uint16 ACTIVESTS_SHADOW:3;  // 6:4    ͨ��״̬ӳ��λ(R):��ֻ��ͨ��1����Ϊ�����ȼ�ʱ���õ���λ�Σ�
                                //        0,0,0  ��ͨ��������
                                //        0,0,1  ���ᷢ����ͨ��1���ᱻ�Լ�����
                                //        0,1,0  ͨ��2���ڹ��������Ǳ�ͨ��1��ϲ�������
                                //        0,1,1  ͨ��3���ڹ��������Ǳ�ͨ��1��ϲ�������
                                //        1,0,0  ͨ��4���ڹ��������Ǳ�ͨ��1��ϲ�������
                                //        1,0,1  ͨ��5���ڹ��������Ǳ�ͨ��1��ϲ�������
                                //        1,1,0  ͨ��6���ڹ��������Ǳ�ͨ��1��ϲ�������
    Uint16 rsvd2:9;             // 15:7   (R=0:0)
};

union PRIORITYSTAT_REG {
   Uint16                     all;
   struct PRIORITYSTAT_BITS   bit;
};

// ͻ�����ͳ��ȿ��ƼĴ�����BURST_SIZE��λ���壺
struct BURST_SIZE_BITS {    // λ����
    Uint16 BURSTSIZE:5;     // 4:0   ͻ�����ͳ��ȿ���λ��0~31(k)��һ��ͻ�����ʹ���k+1���֡�
    Uint16 rsvd1:11;        // 15:5  Ԥ��
};

union BURST_SIZE_REG {
   Uint16                  all;
   struct BURST_SIZE_BITS  bit;
};

// ͻ�����ͼ����Ĵ�����BURST_COUNT��λ���壺
struct BURST_COUNT_BITS {   // λ����
    Uint16 BURSTCOUNT:5;    // 4:0   һ��ͻ��������δ�����͵����ݸ�����0~31(k)��һ��ͻ�������л�ʣ��k����δ�����͡�
    Uint16 rsvd1:11;        // 15:5  Ԥ��
};

union BURST_COUNT_REG {
   Uint16                   all;
   struct BURST_COUNT_BITS  bit;
};


//----------------------------------------------------
// DMAͨ���Ĵ���:
struct CH_REGS {
    union  MODE_REG            MODE;                    // DMAģʽ�Ĵ���
    union  CONTROL_REG         CONTROL;                 // DMA���ƼĴ���

    union  BURST_SIZE_REG      BURST_SIZE;              // ͻ�����ȼĴ���
    union  BURST_COUNT_REG     BURST_COUNT;             // ͻ�����ͼ����Ĵ���
    int16                      SRC_BURST_STEP;          // Դͻ�����Ͳ����Ĵ���
    int16                      DST_BURST_STEP;          // Ŀ��ͻ�����Ͳ����Ĵ���

    Uint16                     TRANSFER_SIZE;           // �⻷���ͳ��ȼĴ���
    Uint16                     TRANSFER_COUNT;          // �⻷���ͼ����Ĵ���
    int16                      SRC_TRANSFER_STEP;       // Դ���Ͳ����Ĵ���
    int16                      DST_TRANSFER_STEP;       // Ŀ�괫�Ͳ����Ĵ���

    Uint16                     SRC_WRAP_SIZE;           // Դ���س��ȼĴ���
    Uint16                     SRC_WRAP_COUNT;          // Դ���ؼ����Ĵ���
    int16                      SRC_WRAP_STEP;           // Դ���ز����Ĵ���

    Uint16                     DST_WRAP_SIZE;           // Ŀ�귵�س��ȼĴ���
    Uint16                     DST_WRAP_COUNT;          // Ŀ�귵�ؼ����Ĵ���
    int16                      DST_WRAP_STEP;           // Ŀ�귵�ز����Ĵ���

    Uint32                     SRC_BEG_ADDR_SHADOW;     // Դ��ʼ��ַָ��ӳ��Ĵ���
    Uint32                     SRC_ADDR_SHADOW;         // Դ��ַָ��ӳ��Ĵ���
    Uint32                     SRC_BEG_ADDR_ACTIVE;     // Դ��ʼ��ַָ�뵱ǰ�Ĵ���
    Uint32                     SRC_ADDR_ACTIVE;         // Դ��ַָ�뵱ǰ�Ĵ���

    Uint32                     DST_BEG_ADDR_SHADOW;     // Ŀ�꿪ʼ��ַָ��ӳ��Ĵ���
    Uint32                     DST_ADDR_SHADOW;         // Ŀ���ַָ��ӳ��Ĵ���
    Uint32                     DST_BEG_ADDR_ACTIVE;     // Ŀ�꿪ʼ��ַָ�뵱ǰ�Ĵ���
    Uint32                     DST_ADDR_ACTIVE;         // Ŀ���ַָ�뵱ǰ�Ĵ���
};

//----------------------------------------------------
// DMA�Ĵ���:
struct DMA_REGS {
    union  DMACTRL_REG         DMACTRL;                 // DMA���ƼĴ���
    union  DEBUGCTRL_REG       DEBUGCTRL;               // DMA������ƼĴ���
    Uint16                     rsvd0;                   // Ԥ��
    Uint16                     rsvd1;                   //
    union  PRIORITYCTRL1_REG   PRIORITYCTRL1;           // DMA���ȼ����ƼĴ���
    Uint16                     rsvd2;                   //
    union  PRIORITYSTAT_REG    PRIORITYSTAT;            // DMA���ȼ�״̬�Ĵ���
    Uint16                     rsvd3[25];               //
    struct CH_REGS             CH1;                     // DMAͨ��1�Ĵ���
    struct CH_REGS             CH2;                     // DMAͨ��2�Ĵ���
    struct CH_REGS             CH3;                     // DMAͨ��3�Ĵ���
    struct CH_REGS             CH4;                     // DMAͨ��4�Ĵ���
    struct CH_REGS             CH5;                     // DMAͨ��5�Ĵ���
    struct CH_REGS             CH6;                     // DMAͨ��6�Ĵ���
};


//---------------------------------------------------------------------------
// DMA���ⲿ���úͺ�������:
//
extern volatile struct DMA_REGS DmaRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of AVP33x_DMA_H definition

//===========================================================================
// End of file.
//===========================================================================
