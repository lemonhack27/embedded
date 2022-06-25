/*
 * ecap.c
 *
 *  Created on: 2018年7月3日
 *      Author: Administrator
 */

#include "ecap.h"

//#include "epwm.h"

// Prototype statements for functions found within this file.
interrupt void ECAP2_ISR(void);
interrupt void ECAP3_ISR(void);
//void Fail(void);
Uint32 Pulse_Count=0; //脉冲个数
Uint32 PWM_Duty=0;    //PWM占空比
Uint32 PWM_Period=0;  //PWM周期

/*******************************************************************************
* 函 数 名         : eCAP2_Init
* 函数功能         : 初始化ECAP以及中断
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void eCAP2_Init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR1.bit.ECAP2ENCLK = 1;  // eCAP1
	EDIS;

	InitECap2Gpio();

	ECap2Regs.ECEINT.all = 0;               // 禁用所有eCAP中断
    ECap2Regs.ECCTL1.bit.CAPLDEN = 0;       // 禁用等待
    ECap2Regs.ECCTL2.bit.TSCTRSTOP = 0;     // 停止计数

    ECap2Regs.TSCTR = 0;                    // 清除计数值
    ECap2Regs.CTRPHS = 0;                   // 清除计数器相位寄存器


#ifdef EC_COUNTINUOUS
    ECap2Regs.ECCTL2.all = 0x003E;      // ECAP控制寄存器2
    ECap2Regs.ECCTL1.all = 0x0010;      // ECAP控制寄存器1
#else

    ECap2Regs.ECCTL2.all = 0x003E;      // ECAP控制寄存器2
    ECap2Regs.ECCTL1.all = 0x0144;      // ECAP控制寄存器1

#endif
    //ECap1Regs.ECCTL2.all = 0x0096;      // ECAP控制寄存器2
    // bit 15-11    00000:  保留
    // bit 10       0:  APWMPOL，在CAP模式无效
    // bit 9        0:  CAP/APWM, 0 = 捕获模式
    // bit 8        0:  SWSYNC, 0 = 无动作
    // bit 7-6          10: SYNCO_SEL, 10 = 禁用同步信号输出
    // bit 5            0:  SYNCI_EN, 0 = 禁用同步
    // bit 4            1:  TSCTRSTOP, 1 = 使能计数器
    // bit 3            0:  RE-ARM, 0 = 无影响
    // bit 2-1      11: STOP_WRAP, CEVT4发生时停止
    // bit 0        0:  CONT/ONESHT, 0 = 连续模式

    //ECap1Regs.ECCTL1.all = 0x01C4;      // ECAP控制寄存器1
    // bit 15-14        00:         FREE/SOFT, 00 = TSCTR立即停止
    // bit 13-9         00000:      PRESCALE, 00000 = 预分频系数为1
    // bit 8            1:  CAPLDEN, 1 = 使能装载控制
    // bit 7            1:  CTRRST4, 1 = 捕获事件CEVT4发生时，复位计数器
    // bit 6            1:  CAP4POL, 1 = 下降沿触发
    // bit 5            0:  CTRRST3, 0 = 捕获事件CEVT3发生时，不复位计数器
    // bit 4            0:  CAP3POL, 0 = 上升沿触发
    // bit 3            0:  CTRRST2, 0 = 捕获事件CEVT2发生时，不复位计数器
    // bit 2            1:  CAP2POL, 1 = 下降沿触发
    // bit 1            0:  CTRRST1, 0 = 捕获事件CEVT1发生时，不复位计数器
    // bit 0            0:  CAP1POL, 0 = 上升沿触发


    ECap2Regs.ECEINT.all = 0x0010;      // Enable desired eCAP interrupts
    // bit 15-8     0:  保留
    // bit 7        0:  CTR=CMP, 0 = 计数匹配 CTR=CMP，禁用中断
    // bit 6        0:  CTR=PRD, 0 = 周期匹配CTR=PRD，禁用中断
    // bit 5            0:  CTROVF, 0 = 计数溢出CTROVF，禁用中断
    // bit 4        0:  CEVT4, 0 = 禁用捕获CEVT4事件中断
    // bit 3            1:  CEVT3, 1 = 使能捕获CEVT3事件中断
    // bit 2            0:  CEVT2, 0 = 禁用捕获CEVT3事件中断
    // bit 1        0:  CEVT1, 0 = 禁用捕获CEVT3事件中断
    // bit 0            0:  保留

	EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.ECAP2_INT= &ECAP2_ISR;
	EDIS;    // This is needed to disable write to EALLOW protected registers

	// Enable CPU INT4 which is connected to ECAP1-4 INT:
	IER |= M_INT4;
	// Enable eCAP INTn in the PIE: Group 3 interrupt 1-6
	PieCtrlRegs.PIEIER4.bit.INTx2 = 1;

	// Enable global Interrupts and higher priority real-time debug events:
	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM
}


/*******************************************************************************
* 函 数 名         : eCAP3_Init
* 函数功能         : 初始化ECAP以及中断
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void eCAP3_Init(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR1.bit.ECAP3ENCLK = 1;  // eCAP1
    EDIS;

    InitECap3Gpio();

    ECap3Regs.ECEINT.all = 0;               // 禁用所有eCAP中断
    ECap3Regs.ECCTL1.bit.CAPLDEN = 0;       // 禁用等待
    ECap3Regs.ECCTL2.bit.TSCTRSTOP = 0;     // 停止计数

    ECap3Regs.TSCTR = 0;                    // 清除计数值
    ECap3Regs.CTRPHS = 0;                   // 清除计数器相位寄存器


#ifdef EC_COUNTINUOUS
    ECap3Regs.ECCTL2.all = 0x003E;      // ECAP控制寄存器2
    ECap3Regs.ECCTL1.all = 0x0010;      // ECAP控制寄存器1
#else

    ECap3Regs.ECCTL2.all = 0x003E;      // ECAP控制寄存器2
    ECap3Regs.ECCTL1.all = 0x0144;      // ECAP控制寄存器1

#endif
    //ECap1Regs.ECCTL2.all = 0x0096;      // ECAP控制寄存器2
    // bit 15-11    00000:  保留
    // bit 10       0:  APWMPOL，在CAP模式无效
    // bit 9        0:  CAP/APWM, 0 = 捕获模式
    // bit 8        0:  SWSYNC, 0 = 无动作
    // bit 7-6          10: SYNCO_SEL, 10 = 禁用同步信号输出
    // bit 5            0:  SYNCI_EN, 0 = 禁用同步
    // bit 4            1:  TSCTRSTOP, 1 = 使能计数器
    // bit 3            0:  RE-ARM, 0 = 无影响
    // bit 2-1      11: STOP_WRAP, CEVT4发生时停止
    // bit 0        0:  CONT/ONESHT, 0 = 连续模式

    //ECap1Regs.ECCTL1.all = 0x01C4;      // ECAP控制寄存器1
    // bit 15-14        00:         FREE/SOFT, 00 = TSCTR立即停止
    // bit 13-9         00000:      PRESCALE, 00000 = 预分频系数为1
    // bit 8            1:  CAPLDEN, 1 = 使能装载控制
    // bit 7            1:  CTRRST4, 1 = 捕获事件CEVT4发生时，复位计数器
    // bit 6            1:  CAP4POL, 1 = 下降沿触发
    // bit 5            0:  CTRRST3, 0 = 捕获事件CEVT3发生时，不复位计数器
    // bit 4            0:  CAP3POL, 0 = 上升沿触发
    // bit 3            0:  CTRRST2, 0 = 捕获事件CEVT2发生时，不复位计数器
    // bit 2            1:  CAP2POL, 1 = 下降沿触发
    // bit 1            0:  CTRRST1, 0 = 捕获事件CEVT1发生时，不复位计数器
    // bit 0            0:  CAP1POL, 0 = 上升沿触发


    ECap3Regs.ECEINT.all = 0x0010;      // Enable desired eCAP interrupts
    // bit 15-8     0:  保留
    // bit 7        0:  CTR=CMP, 0 = 计数匹配 CTR=CMP，禁用中断
    // bit 6        0:  CTR=PRD, 0 = 周期匹配CTR=PRD，禁用中断
    // bit 5            0:  CTROVF, 0 = 计数溢出CTROVF，禁用中断
    // bit 4        0:  CEVT4, 0 = 禁用捕获CEVT4事件中断
    // bit 3            1:  CEVT3, 1 = 使能捕获CEVT3事件中断
    // bit 2            0:  CEVT2, 0 = 禁用捕获CEVT3事件中断
    // bit 1        0:  CEVT1, 0 = 禁用捕获CEVT3事件中断
    // bit 0            0:  保留

    EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.ECAP3_INT= &ECAP3_ISR;
    EDIS;    // This is needed to disable write to EALLOW protected registers

    // Enable CPU INT4 which is connected to ECAP1-4 INT:
    IER |= M_INT4;
    // Enable eCAP INTn in the PIE: Group 3 interrupt 1-6
    PieCtrlRegs.PIEIER4.bit.INTx3 = 1;

    // Enable global Interrupts and higher priority real-time debug events:
    EINT;   // Enable Global interrupt INTM
    ERTM;   // Enable Global realtime interrupt DBGM
}

/*******************************************************************************
* 函 数 名         : ECAP2_ISR
* 函数功能         : 计算占空比和脉冲数量
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
interrupt void ECAP2_ISR(void)
{
    ECap2Regs.ECCLR.bit.INT = 1;                // 清除 ECAP1 中断标志
    ECap2Regs.ECCLR.bit.CEVT4 = 1;              // 清除 CEVT4 标志位


#ifdef EC_COUNTINUOUS
Pulse_Count+=4;
#else
    // 计算PWM占空比（上升沿到下降沿）
    PWM_Duty = (int32)ECap2Regs.CAP2 - (int32)ECap2Regs.CAP1;
    // 计算PWM周期（上升沿到上升沿）
    PWM_Period = (int32)ECap2Regs.CAP3 - (int32)ECap2Regs.CAP1;
#endif
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP4; // PIE组4应答

}

/*******************************************************************************
* 函 数 名         : ECAP3_ISR
* 函数功能         : 计算占空比和脉冲数量
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
interrupt void ECAP3_ISR(void)
{
    ECap3Regs.ECCLR.bit.INT = 1;                // 清除 ECAP1 中断标志
    ECap3Regs.ECCLR.bit.CEVT4 = 1;              // 清除 CEVT4 标志位


#ifdef EC_COUNTINUOUS
Pulse_Count+=4;
#else
    // 计算PWM占空比（上升沿到下降沿）
    PWM_Duty = (int32)ECap3Regs.CAP2 - (int32)ECap3Regs.CAP1;
    // 计算PWM周期（上升沿到上升沿）
    PWM_Period = (int32)ECap3Regs.CAP3 - (int32)ECap3Regs.CAP1;
#endif
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP4; // PIE组4应答

}
