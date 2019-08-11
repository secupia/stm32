################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Temp/Project/SW4STM32/startup_stm32f746xx.s 

C_SRCS += \
C:/Temp/Project/SW4STM32/syscalls.c 

OBJS += \
./Application/SW4STM32/startup_stm32f746xx.o \
./Application/SW4STM32/syscalls.o 

C_DEPS += \
./Application/SW4STM32/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
Application/SW4STM32/startup_stm32f746xx.o: C:/Temp/Project/SW4STM32/startup_stm32f746xx.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/SW4STM32/syscalls.o: C:/Temp/Project/SW4STM32/syscalls.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


