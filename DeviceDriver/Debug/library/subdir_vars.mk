################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../library/AVP335.cmd \
../library/AVP33x_Headers_nonBIOS.cmd 

LIB_SRCS += \
../library/SFO_TI_Build.lib \
../library/SFO_TI_Build_V5.lib \
../library/SFO_TI_Build_V5B.lib \
../library/SFO_TI_Build_V5B_fpu.lib \
../library/SFO_TI_Build_V5_fpu.lib \
../library/SFO_TI_Build_fpu.lib \
../library/rts2800_fpu32.lib 

ASM_SRCS += \
../library/AVP33x_ADC_cal.asm \
../library/AVP33x_CSMPasswords.asm \
../library/AVP33x_CodeStartBranch.asm \
../library/AVP33x_DBGIER.asm \
../library/AVP33x_DisInt.asm \
../library/AVP33x_usDelay.asm 

C_SRCS += \
../library/AVP33x_Adc.c \
../library/AVP33x_CpuTimers.c \
../library/AVP33x_DMA.c \
../library/AVP33x_DefaultIsr.c \
../library/AVP33x_ECan.c \
../library/AVP33x_ECap.c \
../library/AVP33x_EPwm.c \
../library/AVP33x_EQep.c \
../library/AVP33x_GlobalVariableDefs.c \
../library/AVP33x_Gpio.c \
../library/AVP33x_I2C.c \
../library/AVP33x_Mcbsp.c \
../library/AVP33x_MemCopy.c \
../library/AVP33x_PieCtrl.c \
../library/AVP33x_PieVect.c \
../library/AVP33x_Sci.c \
../library/AVP33x_Spi.c \
../library/AVP33x_SysCtrl.c \
../library/AVP33x_Xintf.c 

C_DEPS += \
./library/AVP33x_Adc.d \
./library/AVP33x_CpuTimers.d \
./library/AVP33x_DMA.d \
./library/AVP33x_DefaultIsr.d \
./library/AVP33x_ECan.d \
./library/AVP33x_ECap.d \
./library/AVP33x_EPwm.d \
./library/AVP33x_EQep.d \
./library/AVP33x_GlobalVariableDefs.d \
./library/AVP33x_Gpio.d \
./library/AVP33x_I2C.d \
./library/AVP33x_Mcbsp.d \
./library/AVP33x_MemCopy.d \
./library/AVP33x_PieCtrl.d \
./library/AVP33x_PieVect.d \
./library/AVP33x_Sci.d \
./library/AVP33x_Spi.d \
./library/AVP33x_SysCtrl.d \
./library/AVP33x_Xintf.d 

OBJS += \
./library/AVP33x_ADC_cal.obj \
./library/AVP33x_Adc.obj \
./library/AVP33x_CSMPasswords.obj \
./library/AVP33x_CodeStartBranch.obj \
./library/AVP33x_CpuTimers.obj \
./library/AVP33x_DBGIER.obj \
./library/AVP33x_DMA.obj \
./library/AVP33x_DefaultIsr.obj \
./library/AVP33x_DisInt.obj \
./library/AVP33x_ECan.obj \
./library/AVP33x_ECap.obj \
./library/AVP33x_EPwm.obj \
./library/AVP33x_EQep.obj \
./library/AVP33x_GlobalVariableDefs.obj \
./library/AVP33x_Gpio.obj \
./library/AVP33x_I2C.obj \
./library/AVP33x_Mcbsp.obj \
./library/AVP33x_MemCopy.obj \
./library/AVP33x_PieCtrl.obj \
./library/AVP33x_PieVect.obj \
./library/AVP33x_Sci.obj \
./library/AVP33x_Spi.obj \
./library/AVP33x_SysCtrl.obj \
./library/AVP33x_Xintf.obj \
./library/AVP33x_usDelay.obj 

ASM_DEPS += \
./library/AVP33x_ADC_cal.d \
./library/AVP33x_CSMPasswords.d \
./library/AVP33x_CodeStartBranch.d \
./library/AVP33x_DBGIER.d \
./library/AVP33x_DisInt.d \
./library/AVP33x_usDelay.d 

OBJS__QUOTED += \
"library\AVP33x_ADC_cal.obj" \
"library\AVP33x_Adc.obj" \
"library\AVP33x_CSMPasswords.obj" \
"library\AVP33x_CodeStartBranch.obj" \
"library\AVP33x_CpuTimers.obj" \
"library\AVP33x_DBGIER.obj" \
"library\AVP33x_DMA.obj" \
"library\AVP33x_DefaultIsr.obj" \
"library\AVP33x_DisInt.obj" \
"library\AVP33x_ECan.obj" \
"library\AVP33x_ECap.obj" \
"library\AVP33x_EPwm.obj" \
"library\AVP33x_EQep.obj" \
"library\AVP33x_GlobalVariableDefs.obj" \
"library\AVP33x_Gpio.obj" \
"library\AVP33x_I2C.obj" \
"library\AVP33x_Mcbsp.obj" \
"library\AVP33x_MemCopy.obj" \
"library\AVP33x_PieCtrl.obj" \
"library\AVP33x_PieVect.obj" \
"library\AVP33x_Sci.obj" \
"library\AVP33x_Spi.obj" \
"library\AVP33x_SysCtrl.obj" \
"library\AVP33x_Xintf.obj" \
"library\AVP33x_usDelay.obj" 

C_DEPS__QUOTED += \
"library\AVP33x_Adc.d" \
"library\AVP33x_CpuTimers.d" \
"library\AVP33x_DMA.d" \
"library\AVP33x_DefaultIsr.d" \
"library\AVP33x_ECan.d" \
"library\AVP33x_ECap.d" \
"library\AVP33x_EPwm.d" \
"library\AVP33x_EQep.d" \
"library\AVP33x_GlobalVariableDefs.d" \
"library\AVP33x_Gpio.d" \
"library\AVP33x_I2C.d" \
"library\AVP33x_Mcbsp.d" \
"library\AVP33x_MemCopy.d" \
"library\AVP33x_PieCtrl.d" \
"library\AVP33x_PieVect.d" \
"library\AVP33x_Sci.d" \
"library\AVP33x_Spi.d" \
"library\AVP33x_SysCtrl.d" \
"library\AVP33x_Xintf.d" 

ASM_DEPS__QUOTED += \
"library\AVP33x_ADC_cal.d" \
"library\AVP33x_CSMPasswords.d" \
"library\AVP33x_CodeStartBranch.d" \
"library\AVP33x_DBGIER.d" \
"library\AVP33x_DisInt.d" \
"library\AVP33x_usDelay.d" 

ASM_SRCS__QUOTED += \
"../library/AVP33x_ADC_cal.asm" \
"../library/AVP33x_CSMPasswords.asm" \
"../library/AVP33x_CodeStartBranch.asm" \
"../library/AVP33x_DBGIER.asm" \
"../library/AVP33x_DisInt.asm" \
"../library/AVP33x_usDelay.asm" 

C_SRCS__QUOTED += \
"../library/AVP33x_Adc.c" \
"../library/AVP33x_CpuTimers.c" \
"../library/AVP33x_DMA.c" \
"../library/AVP33x_DefaultIsr.c" \
"../library/AVP33x_ECan.c" \
"../library/AVP33x_ECap.c" \
"../library/AVP33x_EPwm.c" \
"../library/AVP33x_EQep.c" \
"../library/AVP33x_GlobalVariableDefs.c" \
"../library/AVP33x_Gpio.c" \
"../library/AVP33x_I2C.c" \
"../library/AVP33x_Mcbsp.c" \
"../library/AVP33x_MemCopy.c" \
"../library/AVP33x_PieCtrl.c" \
"../library/AVP33x_PieVect.c" \
"../library/AVP33x_Sci.c" \
"../library/AVP33x_Spi.c" \
"../library/AVP33x_SysCtrl.c" \
"../library/AVP33x_Xintf.c" 


