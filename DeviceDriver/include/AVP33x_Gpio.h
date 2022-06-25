/******************************************************************************
文件名                     : AVP33x_Gpio.h
作者                         : 湖南进芯电子科技有限公司
功能描述                 : AVP33x芯片通用IO引脚定义
创建时间                 : 06-25-2019
版本                         : V1.0
修订时间                 :
修订内容                 :
*******************************************************************************/

#ifndef AVP33x_GPIO_H
#define AVP33x_GPIO_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
/* GPIO A 控制寄存器（GPACTRL）位定义 */
struct GPACTRL_BITS {           // 位描述
    Uint16 QUALPRD0:8;          // 7:0    GPIO0~GPIO7引脚特定的采样周期
    Uint16 QUALPRD1:8;          // 15:8   GPIO8~GPIO15引脚特定的采样周期
    Uint16 QUALPRD2:8;          // 23:16  GPIO16~GPIO23引脚特定的采样周期
    Uint16 QUALPRD3:8;          // 31:24  GPIO24~GPIO31引脚特定的采样周期
};

union GPACTRL_REG {
    Uint32              all;
    struct GPACTRL_BITS bit;
};

//----------------------------------------------------
/* GPIO B 控制寄存器（GPBCTRL）位定义 */
struct GPBCTRL_BITS {           // 位描述
    Uint16 QUALPRD0:8;          // 7:0    GPIO0~GPIO7引脚特定的采样周期
    Uint16 QUALPRD1:8;          // 15:8   GPIO8~GPIO15引脚特定的采样周期
    Uint16 QUALPRD2:8;          // 23:16  GPIO16~GPIO23引脚特定的采样周期
    Uint16 QUALPRD3:8;          // 31:24  GPIO24~GPIO31引脚特定的采样周期
};

union GPBCTRL_REG {
    Uint32              all;
    struct GPBCTRL_BITS bit;
};

//----------------------------------------------------
/* GPIO引脚功能选择控制寄存器位定义 */
struct GPA1_BITS {              // 位描述
    Uint16 GPIO0:2;             // 1:0    GPIO0
    Uint16 GPIO1:2;             // 3:2    GPIO1
    Uint16 GPIO2:2;             // 5:4    GPIO2
    Uint16 GPIO3:2;             // 7:6    GPIO3
    Uint16 GPIO4:2;             // 9:8    GPIO4
    Uint16 GPIO5:2;             // 11:10  GPIO5
    Uint16 GPIO6:2;             // 13:12  GPIO6
    Uint16 GPIO7:2;             // 15:14  GPIO7
    Uint16 GPIO8:2;             // 17:16  GPIO8
    Uint16 GPIO9:2;             // 19:18  GPIO9
    Uint16 GPIO10:2;            // 21:20  GPIO10
    Uint16 GPIO11:2;            // 23:22  GPIO11
    Uint16 GPIO12:2;            // 25:24  GPIO12
    Uint16 GPIO13:2;            // 27:26  GPIO13
    Uint16 GPIO14:2;            // 29:28  GPIO14
    Uint16 GPIO15:2;            // 31:30  GPIO15
};

struct GPA2_BITS {              // 位描述
    Uint16 GPIO16:2;            // 1:0    GPIO16
    Uint16 GPIO17:2;            // 3:2    GPIO17
    Uint16 GPIO18:2;            // 5:4    GPIO18
    Uint16 GPIO19:2;            // 7:6    GPIO19
    Uint16 GPIO20:2;            // 9:8    GPIO20
    Uint16 GPIO21:2;            // 11:10  GPIO21
    Uint16 GPIO22:2;            // 13:12  GPIO22
    Uint16 GPIO23:2;            // 15:14  GPIO23
    Uint16 GPIO24:2;            // 17:16  GPIO24
    Uint16 GPIO25:2;            // 19:18  GPIO25
    Uint16 GPIO26:2;            // 21:20  GPIO26
    Uint16 GPIO27:2;            // 23:22  GPIO27
    Uint16 GPIO28:2;            // 25:24  GPIO28
    Uint16 GPIO29:2;            // 27:26  GPIO29
    Uint16 GPIO30:2;            // 29:28  GPIO30
    Uint16 GPIO31:2;            // 31:30  GPIO31
};

struct GPB1_BITS {              // 位描述
    Uint16 GPIO32:2;            // 1:0    GPIO32
    Uint16 GPIO33:2;            // 3:2    GPIO33
    Uint16 GPIO34:2;            // 5:4    GPIO34
    Uint16 GPIO35:2;            // 7:6    GPIO35
    Uint16 GPIO36:2;            // 9:8    GPIO36
    Uint16 GPIO37:2;            // 11:10  GPIO37
    Uint16 GPIO38:2;            // 13:12  GPIO38
    Uint16 GPIO39:2;            // 15:14  GPIO39
    Uint16 GPIO40:2;            // 17:16  GPIO40
    Uint16 GPIO41:2;            // 19:16  GPIO41
    Uint16 GPIO42:2;            // 21:20  GPIO42
    Uint16 GPIO43:2;            // 23:22  GPIO43
    Uint16 GPIO44:2;            // 25:24  GPIO44
    Uint16 GPIO45:2;            // 27:26  GPIO45
    Uint16 GPIO46:2;            // 29:28  GPIO46
    Uint16 GPIO47:2;            // 31:30  GPIO47
};

struct GPB2_BITS  {             // 位描述
    Uint16 GPIO48:2;            // 1:0    GPIO48
    Uint16 GPIO49:2;            // 3:2    GPIO49
    Uint16 GPIO50:2;            // 5:4    GPIO50
    Uint16 GPIO51:2;            // 7:6    GPIO51
    Uint16 GPIO52:2;            // 9:8    GPIO52
    Uint16 GPIO53:2;            // 11:10  GPIO53
    Uint16 GPIO54:2;            // 13:12  GPIO54
    Uint16 GPIO55:2;            // 15:14  GPIO55
    Uint16 GPIO56:2;            // 17:16  GPIO56
    Uint16 GPIO57:2;            // 19:18  GPIO57
    Uint16 GPIO58:2;            // 21:20  GPIO58
    Uint16 GPIO59:2;            // 23:22  GPIO59
    Uint16 GPIO60:2;            // 25:24  GPIO60
    Uint16 GPIO61:2;            // 27:26  GPIO61
    Uint16 GPIO62:2;            // 29:28  GPIO62
    Uint16 GPIO63:2;            // 31:30  GPIO63
};

struct GPC1_BITS {              // 位描述
    Uint16 GPIO64:2;            // 1:0    GPIO64
    Uint16 GPIO65:2;            // 3:2    GPIO65
    Uint16 GPIO66:2;            // 5:4    GPIO66
    Uint16 GPIO67:2;            // 7:6    GPIO67
    Uint16 GPIO68:2;            // 9:8    GPIO68
    Uint16 GPIO69:2;            // 11:10  GPIO69
    Uint16 GPIO70:2;            // 13:12  GPIO70
    Uint16 GPIO71:2;            // 15:14  GPIO71
    Uint16 GPIO72:2;            // 17:16  GPIO72
    Uint16 GPIO73:2;            // 19:18  GPIO73
    Uint16 GPIO74:2;            // 21:20  GPIO74
    Uint16 GPIO75:2;            // 23:22  GPIO75
    Uint16 GPIO76:2;            // 25:24  GPIO76
    Uint16 GPIO77:2;            // 27:26  GPIO77
    Uint16 GPIO78:2;            // 29:28  GPIO78
    Uint16 GPIO79:2;            // 31:30  GPIO79
};

struct GPC2_BITS {              // 位描述
    Uint16 GPIO80:2;            // 1:0    GPIO80
    Uint16 GPIO81:2;            // 3:2    GPIO81
    Uint16 GPIO82:2;            // 5:4    GPIO82
    Uint16 GPIO83:2;            // 7:6    GPIO83
    Uint16 GPIO84:2;            // 9:8    GPIO84
    Uint16 GPIO85:2;            // 11:10  GPIO85
    Uint16 GPIO86:2;            // 13:12  GPIO86
    Uint16 GPIO87:2;            // 15:14  GPIO87
    Uint16 rsvd:16;             // 31:16  reserved
};

union GPA1_REG {
    Uint32              all;
    struct GPA1_BITS    bit;
};

union GPA2_REG {
    Uint32              all;
    struct GPA2_BITS    bit;
};

union GPB1_REG {
    Uint32              all;
    struct GPB1_BITS    bit;
};

union GPB2_REG {
    Uint32              all;
    struct GPB2_BITS    bit;
};

union GPC1_REG {
    Uint32              all;
    struct GPC1_BITS    bit;
};

union GPC2_REG {
    Uint32              all;
    struct GPC2_BITS    bit;
};

//----------------------------------------------------
/* GPIO A 方向/翻转/置位/清0 控制寄存器位定义 */
struct GPADAT_BITS {            // 位描述
    Uint16 GPIO0:1;             // 0      GPIO0
    Uint16 GPIO1:1;             // 1      GPIO1
    Uint16 GPIO2:1;             // 2      GPIO2
    Uint16 GPIO3:1;             // 3      GPIO3
    Uint16 GPIO4:1;             // 4      GPIO4
    Uint16 GPIO5:1;             // 5      GPIO5
    Uint16 GPIO6:1;             // 6      GPIO6
    Uint16 GPIO7:1;             // 7      GPIO7
    Uint16 GPIO8:1;             // 8      GPIO8
    Uint16 GPIO9:1;             // 9      GPIO9
    Uint16 GPIO10:1;            // 10     GPIO10
    Uint16 GPIO11:1;            // 11     GPIO11
    Uint16 GPIO12:1;            // 12     GPIO12
    Uint16 GPIO13:1;            // 13     GPIO13
    Uint16 GPIO14:1;            // 14     GPIO14
    Uint16 GPIO15:1;            // 15     GPIO15
    Uint16 GPIO16:1;            // 16     GPIO16
    Uint16 GPIO17:1;            // 17     GPIO17
    Uint16 GPIO18:1;            // 18     GPIO18
    Uint16 GPIO19:1;            // 19     GPIO19
    Uint16 GPIO20:1;            // 20     GPIO20
    Uint16 GPIO21:1;            // 21     GPIO21
    Uint16 GPIO22:1;            // 22     GPIO22
    Uint16 GPIO23:1;            // 23     GPIO23
    Uint16 GPIO24:1;            // 24     GPIO24
    Uint16 GPIO25:1;            // 25     GPIO25
    Uint16 GPIO26:1;            // 26     GPIO26
    Uint16 GPIO27:1;            // 27     GPIO27
    Uint16 GPIO28:1;            // 28     GPIO28
    Uint16 GPIO29:1;            // 29     GPIO29
    Uint16 GPIO30:1;            // 30     GPIO30
    Uint16 GPIO31:1;            // 31     GPIO31
};

struct GPBDAT_BITS {            // 位描述
    Uint16 GPIO32:1;            // 0      GPIO32
    Uint16 GPIO33:1;            // 1      GPIO33
    Uint16 GPIO34:1;            // 2      GPIO34
    Uint16 GPIO35:1;            // 3      GPIO35
    Uint16 GPIO36:1;            // 4      GPIO36
    Uint16 GPIO37:1;            // 5      GPIO37
    Uint16 GPIO38:1;            // 6      GPIO38
    Uint16 GPIO39:1;            // 7      GPIO39
    Uint16 GPIO40:1;            // 8      GPIO40
    Uint16 GPIO41:1;            // 9      GPIO41
    Uint16 GPIO42:1;            // 10     GPIO42
    Uint16 GPIO43:1;            // 11     GPIO43
    Uint16 GPIO44:1;            // 12     GPIO44
    Uint16 GPIO45:1;            // 13     GPIO45
    Uint16 GPIO46:1;            // 14     GPIO46
    Uint16 GPIO47:1;            // 15     GPIO47
    Uint16 GPIO48:1;            // 16     GPIO48
    Uint16 GPIO49:1;            // 17     GPIO49
    Uint16 GPIO50:1;            // 18     GPIO50
    Uint16 GPIO51:1;            // 19     GPIO51
    Uint16 GPIO52:1;            // 20     GPIO52
    Uint16 GPIO53:1;            // 21     GPIO53
    Uint16 GPIO54:1;            // 22     GPIO54
    Uint16 GPIO55:1;            // 23     GPIO55
    Uint16 GPIO56:1;            // 24     GPIO56
    Uint16 GPIO57:1;            // 25     GPIO57
    Uint16 GPIO58:1;            // 26     GPIO58
    Uint16 GPIO59:1;            // 27     GPIO59
    Uint16 GPIO60:1;            // 28     GPIO60
    Uint16 GPIO61:1;            // 29     GPIO61
    Uint16 GPIO62:1;            // 30     GPIO62
    Uint16 GPIO63:1;            // 31     GPIO63
};

struct GPCDAT_BITS {            // 位描述
    Uint16 GPIO64:1;            // 0      GPIO64
    Uint16 GPIO65:1;            // 1      GPIO65
    Uint16 GPIO66:1;            // 2      GPIO66
    Uint16 GPIO67:1;            // 3      GPIO67
    Uint16 GPIO68:1;            // 4      GPIO68
    Uint16 GPIO69:1;            // 5      GPIO69
    Uint16 GPIO70:1;            // 6      GPIO70
    Uint16 GPIO71:1;            // 7      GPIO71
    Uint16 GPIO72:1;            // 8      GPIO72
    Uint16 GPIO73:1;            // 9      GPIO73
    Uint16 GPIO74:1;            // 10     GPIO74
    Uint16 GPIO75:1;            // 11     GPIO75
    Uint16 GPIO76:1;            // 12     GPIO76
    Uint16 GPIO77:1;            // 13     GPIO77
    Uint16 GPIO78:1;            // 14     GPIO78
    Uint16 GPIO79:1;            // 15     GPIO79
    Uint16 GPIO80:1;            // 16     GPIO80
    Uint16 GPIO81:1;            // 17     GPIO81
    Uint16 GPIO82:1;            // 18     GPIO82
    Uint16 GPIO83:1;            // 19     GPIO83
    Uint16 GPIO84:1;            // 20     GPIO84
    Uint16 GPIO85:1;            // 21     GPIO85
    Uint16 GPIO86:1;            // 22     GPIO86
    Uint16 GPIO87:1;            // 23     GPIO87
    Uint16 rsvd1:8;             // 31:24  reserved
};

union GPADAT_REG {
    Uint32              all;
    struct GPADAT_BITS  bit;
};

union GPBDAT_REG {
    Uint32              all;
    struct GPBDAT_BITS  bit;
};

union GPCDAT_REG {
    Uint32              all;
    struct GPCDAT_BITS  bit;
};

//----------------------------------------------------
/* GPIO 中断选择（Xint1/XINT2/XNMI）控制寄存器（GPACTRL）位定义 */
struct GPIOXINT_BITS {          // 位描述
    Uint16 GPIOSEL:5;           // 4:0    选择GPIO中断输入源
    Uint16 rsvd1:11;            // 15:5   预留
};

union GPIOXINT_REG {
    Uint16                all;
    struct GPIOXINT_BITS  bit;
};


struct GPIO_CTRL_REGS {
    union  GPACTRL_REG  GPACTRL;    // GPIO A 控制寄存器 (GPIO0 to 31)
    union  GPA1_REG     GPAQSEL1;   // GPIO A 输入引脚模式选择控制寄存器1(GPIO0 to 15)
    union  GPA2_REG     GPAQSEL2;   // GPIO A 输入引脚模式选择控制寄存器2(GPIO16 to 31)
    union  GPA1_REG     GPAMUX1;    // GPIO A 功能选择控制寄存器1(GPIO0 to 15)
    union  GPA2_REG     GPAMUX2;    // GPIO A 功能选择控制寄存器2(GPIO16 to 31)
    union  GPADAT_REG   GPADIR;     // GPIO A 输入输出方向控制寄存器(GPIO0 to 31)
    union  GPADAT_REG   GPAPUD;     // GPIO A 引脚上拉禁止控制寄存器(GPIO0 to 31)
    Uint32              rsvd1;
    union  GPBCTRL_REG  GPBCTRL;    // GPIO B 控制寄存器(GPIO32 to 63)
    union  GPB1_REG     GPBQSEL1;   // GPIO B 输入引脚模式选择控制寄存器1(GPIO32 to 47)
    union  GPB2_REG     GPBQSEL2;   // GPIO B 输入引脚模式选择控制寄存器2(GPIO48 to 63)
    union  GPB1_REG     GPBMUX1;    // GPIO B 功能选择控制寄存器1(GPIO32 to 47)
    union  GPB2_REG     GPBMUX2;    // GPIO B 功能选择控制寄存器2(GPIO48 to 63)
    union  GPBDAT_REG   GPBDIR;     // GPIO B 输入输出方向控制寄存器(GPIO32 to 63)
    union  GPBDAT_REG   GPBPUD;     // GPIO B 引脚上拉禁止控制寄存器(GPIO32 to 63)
    Uint16              rsvd2[8];
    union  GPC1_REG     GPCMUX1;    // GPIO C 功能选择控制寄存器1(GPIO64 to 79)
    union  GPC2_REG     GPCMUX2;    // GPIO C 功能选择控制寄存器2(GPIO80 to 95)
    union  GPCDAT_REG   GPCDIR;     // GPIO C 输入输出方向控制寄存器(GPIO64 to 95)
    union  GPCDAT_REG   GPCPUD;     // GPIO C 引脚上拉禁止控制寄存器(GPIO64 to 95)
};

struct GPIO_DATA_REGS {
    union  GPADAT_REG       GPADAT;         // GPIOA数据寄存器(GPIO0 to 31)
    union  GPADAT_REG       GPASET;         // GPIOA置位控制寄存器(GPIO0 to 31)
    union  GPADAT_REG       GPACLEAR;       // GPIOA清零控制寄存器(GPIO0 to 31)
    union  GPADAT_REG       GPATOGGLE;      // GPIOA电平翻转控制寄存器(GPIO0 to 31)
    union  GPBDAT_REG       GPBDAT;         // GPIOB数据寄存器(GPIO32 to 63)
    union  GPBDAT_REG       GPBSET;         // GPIOB置位控制寄存器(GPIO32 to 63)
    union  GPBDAT_REG       GPBCLEAR;       // GPIOB清零控制寄存器(GPIO32 to 63)
    union  GPBDAT_REG       GPBTOGGLE;      // GPIOB电平反转控制寄存器(GPIO32 to 63)
    union  GPCDAT_REG       GPCDAT;         // GPIOC数据寄存器(GPIO64 to 95)
    union  GPCDAT_REG       GPCSET;         // GPIOC置位控制寄存器(GPIO64 to 95)
    union  GPCDAT_REG       GPCCLEAR;       // GPIOC清零控制寄存器(GPIO64 to 95)
    union  GPCDAT_REG       GPCTOGGLE;      // GPIOC电平反转控制寄存器(GPIO64 to 95)
    Uint16                  rsvd1[8];
};

struct GPIO_INT_REGS {
    union  GPIOXINT_REG     GPIOXINT1SEL;   // XINT1 GPIO输入选择
    union  GPIOXINT_REG     GPIOXINT2SEL;   // XINT2 GPIO输入选择
    union  GPIOXINT_REG     GPIOXNMISEL;    // XNMI_Xint13 GPIO输入选择
    union  GPIOXINT_REG     GPIOXINT3SEL;   // XINT3 GPIO输入选择
    union  GPIOXINT_REG     GPIOXINT4SEL;   // XINT4 GPIO输入选择
    union  GPIOXINT_REG     GPIOXINT5SEL;   // XINT5 GPIO输入选择
    union  GPIOXINT_REG     GPIOXINT6SEL;   // XINT6 GPIO输入选择
    union  GPIOXINT_REG     GPIOXINT7SEL;   // XINT7 GPIO输入选择
    union  GPADAT_REG       GPIOLPMSEL;     // 低功耗模式 GPIO输入选择
};

//---------------------------------------------------------------------------
// GPI/O外部引用和函数声明:
//
extern volatile struct GPIO_CTRL_REGS GpioCtrlRegs;
extern volatile struct GPIO_DATA_REGS GpioDataRegs;
extern volatile struct GPIO_INT_REGS GpioIntRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of AVP33x_GPIO_H definition

//===========================================================================
// End of file.
//===========================================================================
