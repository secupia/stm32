################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c \
C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/croutine.c \
C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c \
C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c \
C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/list.c \
C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/port.c \
C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/queue.c \
C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/tasks.c \
C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/timers.c 

OBJS += \
./Middlewares/FreeRTOS/cmsis_os.o \
./Middlewares/FreeRTOS/croutine.o \
./Middlewares/FreeRTOS/event_groups.o \
./Middlewares/FreeRTOS/heap_4.o \
./Middlewares/FreeRTOS/list.o \
./Middlewares/FreeRTOS/port.o \
./Middlewares/FreeRTOS/queue.o \
./Middlewares/FreeRTOS/tasks.o \
./Middlewares/FreeRTOS/timers.o 

C_DEPS += \
./Middlewares/FreeRTOS/cmsis_os.d \
./Middlewares/FreeRTOS/croutine.d \
./Middlewares/FreeRTOS/event_groups.d \
./Middlewares/FreeRTOS/heap_4.d \
./Middlewares/FreeRTOS/list.d \
./Middlewares/FreeRTOS/port.d \
./Middlewares/FreeRTOS/queue.d \
./Middlewares/FreeRTOS/tasks.d \
./Middlewares/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/FreeRTOS/cmsis_os.o: C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/croutine.o: C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/croutine.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/event_groups.o: C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/heap_4.o: C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/list.o: C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/list.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/port.o: C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/port.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/queue.o: C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/queue.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/tasks.o: C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/tasks.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/FreeRTOS/timers.o: C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/timers.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


