################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
APP/tmux611x/%.obj: ../APP/tmux611x/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/ecap" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/ad7608v2" --include_path="E:/programming/DSP2833x_Project/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/I2cEeprom" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/include" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/leds" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/uart" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/printf" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/tmux611x" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/timers" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/ad7608" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/filter" --include_path="E:/programming/DSP2833x_Project/DSP2833x_Libraries/DSP2833x_common/include" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/adc" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/spi" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/24cxx" --include_path="E:/programming/DSP2833x_Project/DeviceDriver/APP/iic" --include_path="E:/programming/DSP2833x_Project/DeviceDriver" --include_path="C:/ti/ccs1010/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="APP/tmux611x/$(basename $(<F)).d_raw" --obj_directory="APP/tmux611x" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


