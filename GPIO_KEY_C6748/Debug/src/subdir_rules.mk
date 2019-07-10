################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
src/main_key_gpio.obj: ../src/main_key_gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.3.3/bin/cl6x" -mv6740 --abi=eabi --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.3.3/include" --include_path="D:/Codigos/CCS 7.2/Propios/TMS320C6748/DSP_Applications_Using_C/key_gpio2/inc" --define=c6748 -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="src/main_key_gpio.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


