/******************************************************************************
�ļ���                     : AVP33x_DevEmu.h
����                         : ���Ͻ�о���ӿƼ����޹�˾
��������                 : AVP33xоƬ����Ĵ�������
����ʱ��                 : 06-25-2019
�汾                         : V1.0
�޶�ʱ��                 :
�޶�����                 :
*******************************************************************************/

#ifndef AVP33x_DEV_EMU_H
#define AVP33x_DEV_EMU_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// оƬ����Ĵ���λ����:
//
// оƬ���üĴ���λ����
struct DEVICECNF_BITS  {    // λ����
    Uint16 rsvd1:3;         // 2:0   Ԥ��
    Uint16 VMAPS:1;         // 3     VMAP״̬
    Uint16 rsvd2:1;         // 4     Ԥ��
    Uint16 XRSn:1;          // 5     XRSn�ź�״̬
    Uint16 rsvd3:10;        // 15:6
    Uint16 rsvd4:3;         // 18:16
    Uint16 ENPROT:1;        // 19    ʹ��/��ֹ�ܵ�����
    Uint16 rsvd5:7;         // 26:20 Ԥ��
    Uint16 TRSTN:1;         // 27    TRSTn�ź�״̬
    Uint16 rsvd6:4;         // 31:28 Ԥ��
};

union DEVICECNF_REG {
    Uint32                 all;
    struct DEVICECNF_BITS  bit;
};

// ��ID
struct CLASSID_BITS   {     // λ����
    Uint16 CLASSNO:8;       // 7:0   ����
    Uint16 PARTTYPE:8;      // 15:8  �豸����
};

union CLASSID_REG {
    Uint16               all;
    struct CLASSID_BITS  bit;
};

struct DEV_EMU_REGS {
    union DEVICECNF_REG DEVICECNF;  // �豸����
    union CLASSID_REG   CLASSID;    // ��ID
    Uint16              REVID;      // �豸ID
    Uint16              PROTSTART;  // ��д��������
    Uint16              PROTRANGE;  // ��д������Χ
    Uint16              rsvd2[202];
};

// оƬID
struct PARTID_BITS   {      // λ����
    Uint16 PARTNO:8;        // 7:0   оƬ���
    Uint16 PARTTYPE:8;      // 15:8  оƬ����
};

union PARTID_REG {
    Uint16               all;
    struct PARTID_BITS   bit;
};

struct PARTID_REGS {
    union PARTID_REG PARTID;// оƬID
};


//---------------------------------------------------------------------------
// �豸����Ĵ����ⲿ���úͺ�������:
//
extern volatile struct DEV_EMU_REGS DevEmuRegs;
extern volatile struct PARTID_REGS PartIdRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of AVP33x_DEV_EMU_H definition

//===========================================================================
// End of file.
//===========================================================================
