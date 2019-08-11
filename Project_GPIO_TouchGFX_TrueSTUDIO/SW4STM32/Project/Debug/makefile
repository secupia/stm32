################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/USB_Host_Library/subdir.mk
-include Middlewares/TouchGFX/subdir.mk
-include Middlewares/FreeRTOS/subdir.mk
-include Middlewares/FatFs/subdir.mk
-include Drivers/STM32F7xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Application/User/USB_Host_Library/Target/subdir.mk
-include Application/User/USB_Host_Library/App/subdir.mk
-include Application/User/TouchGFX/target/subdir.mk
-include Application/User/TouchGFX/gui/screen3_screen/subdir.mk
-include Application/User/TouchGFX/gui/screen2_screen/subdir.mk
-include Application/User/TouchGFX/gui/screen1_screen/subdir.mk
-include Application/User/TouchGFX/gui/model/subdir.mk
-include Application/User/TouchGFX/gui/common/subdir.mk
-include Application/User/TouchGFX/generated/texts/subdir.mk
-include Application/User/TouchGFX/generated/images/__designer/subdir.mk
-include Application/User/TouchGFX/generated/images/subdir.mk
-include Application/User/TouchGFX/generated/gui_generated/screen3_screen/subdir.mk
-include Application/User/TouchGFX/generated/gui_generated/screen2_screen/subdir.mk
-include Application/User/TouchGFX/generated/gui_generated/screen1_screen/subdir.mk
-include Application/User/TouchGFX/generated/gui_generated/common/subdir.mk
-include Application/User/TouchGFX/generated/fonts/subdir.mk
-include Application/User/FatFs/Target/subdir.mk
-include Application/User/FatFs/App/subdir.mk
-include Application/User/Core/subdir.mk
-include Application/SW4STM32/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Project.elf

# Tool invocations
Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU G++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -L"C:\Temp\Project\Middlewares\ST\TouchGFX\touchgfx\lib\core\cortex_m7\gcc"  -specs=nosys.specs -specs=nano.specs -T"../STM32F746NGHx_FLASH.ld" -Wl,-Map=output.map -Wl,--gc-sections -fno-exceptions -fno-rtti -o "Project.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating hex and Printing size information:'
	arm-none-eabi-objcopy -O ihex "Project.elf" "Project.hex"
	arm-none-eabi-size "Project.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
