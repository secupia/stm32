################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Temp/Project/Middlewares/Third_Party/FatFs/src/diskio.c \
C:/Temp/Project/Middlewares/Third_Party/FatFs/src/ff.c \
C:/Temp/Project/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c \
C:/Temp/Project/Middlewares/Third_Party/FatFs/src/option/syscall.c 

OBJS += \
./Middlewares/FatFs/diskio.o \
./Middlewares/FatFs/ff.o \
./Middlewares/FatFs/ff_gen_drv.o \
./Middlewares/FatFs/syscall.o 

C_DEPS += \
./Middlewares/FatFs/diskio.d \
./Middlewares/FatFs/ff.d \
./Middlewares/FatFs/ff_gen_drv.d \
./Middlewares/FatFs/syscall.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/FatFs/diskio.o: C:/Temp/Project/Middlewares/Third_Party/FatFs/src/diskio.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FatFs/ff.o: C:/Temp/Project/Middlewares/Third_Party/FatFs/src/ff.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FatFs/ff_gen_drv.o: C:/Temp/Project/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FatFs/syscall.o: C:/Temp/Project/Middlewares/Third_Party/FatFs/src/option/syscall.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


