################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
inc/rk6748.obj: ../inc/rk6748.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.3.3/bin/cl6x" -mv6740 --abi=eabi --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.3.3/include" --include_path="D:/Codigos/CCS 7.2/Propios/TMS320C6748/DSP_Applications_Using_C/key_gpio2/inc" --define=c6748 -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="inc/rk6748.d_raw" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

inc/rk6748_gpio.obj: ../inc/rk6748_gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.3.3/bin/cl6x" -mv6740 --abi=eabi --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.3.3/include" --include_path="D:/Codigos/CCS 7.2/Propios/TMS320C6748/DSP_Applications_Using_C/key_gpio2/inc" --define=c6748 -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="inc/rk6748_gpio.d_raw" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

inc/rk6748_timer.obj: ../inc/rk6748_timer.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.3.3/bin/cl6x" -mv6740 --abi=eabi --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.3.3/include" --include_path="D:/Codigos/CCS 7.2/Propios/TMS320C6748/DSP_Applications_Using_C/key_gpio2/inc" --define=c6748 -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="inc/rk6748_timer.d_raw" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

inc/test_key_gpio.obj: ../inc/test_key_gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.3.3/bin/cl6x" -mv6740 --abi=eabi --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.3.3/include" --include_path="D:/Codigos/CCS 7.2/Propios/TMS320C6748/DSP_Applications_Using_C/key_gpio2/inc" --define=c6748 -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="inc/test_key_gpio.d_raw" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

inc/test_led.obj: ../inc/test_led.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.3.3/bin/cl6x" -mv6740 --abi=eabi --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.3.3/include" --include_path="D:/Codigos/CCS 7.2/Propios/TMS320C6748/DSP_Applications_Using_C/key_gpio2/inc" --define=c6748 -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="inc/test_led.d_raw" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


