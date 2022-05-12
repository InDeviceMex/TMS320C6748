################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
source/%.obj: ../source/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-c6000_8.3.8/bin/cl6x" -mv6740 --abi=eabi --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-c6000_8.3.8/include" --include_path="E:/GIt/TMS320C6748/GPIO_KEY_C6748/include" --include_path="E:/GIt/TMS320C6748/GPIO_KEY_C6748/inc" --define=c6748 -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

source/%.obj: ../source/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-c6000_8.3.8/bin/cl6x" -mv6740 --abi=eabi --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-c6000_8.3.8/include" --include_path="E:/GIt/TMS320C6748/GPIO_KEY_C6748/include" --include_path="E:/GIt/TMS320C6748/GPIO_KEY_C6748/inc" --define=c6748 -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


