################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Temp/Project/Core/Src/freertos.c \
C:/Temp/Project/Core/Src/stm32f7xx_hal_msp.c \
C:/Temp/Project/Core/Src/stm32f7xx_hal_timebase_tim.c \
C:/Temp/Project/Core/Src/stm32f7xx_it.c 

CPP_SRCS += \
C:/Temp/Project/Core/Src/main.cpp 

OBJS += \
./Application/User/Core/freertos.o \
./Application/User/Core/main.o \
./Application/User/Core/stm32f7xx_hal_msp.o \
./Application/User/Core/stm32f7xx_hal_timebase_tim.o \
./Application/User/Core/stm32f7xx_it.o 

C_DEPS += \
./Application/User/Core/freertos.d \
./Application/User/Core/stm32f7xx_hal_msp.d \
./Application/User/Core/stm32f7xx_hal_timebase_tim.d \
./Application/User/Core/stm32f7xx_it.d 

CPP_DEPS += \
./Application/User/Core/main.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Core/freertos.o: C:/Temp/Project/Core/Src/freertos.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/Core/main.o: C:/Temp/Project/Core/Src/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/Core/stm32f7xx_hal_msp.o: C:/Temp/Project/Core/Src/stm32f7xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/Core/stm32f7xx_hal_timebase_tim.o: C:/Temp/Project/Core/Src/stm32f7xx_hal_timebase_tim.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/Core/stm32f7xx_it.o: C:/Temp/Project/Core/Src/stm32f7xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx '-DUSE_BPP=16' -I"C:/Temp/Project/FATFS/Target" -I"C:/Temp/Project/FATFS/App" -I"C:/Temp/Project/Core/Inc" -I"C:/Temp/Project/TouchGFX/target" -I"C:/Temp/Project/USB_HOST/App" -I"C:/Temp/Project/USB_HOST/Target" -I"C:/Temp/Project/TouchGFX/generated/fonts/include" -I"C:/Temp/Project/TouchGFX/generated/texts/include" -I"C:/Temp/Project/TouchGFX/generated/images/include" -I"C:/Temp/Project/TouchGFX/generated/gui_generated/include" -I"C:/Temp/Project/TouchGFX/gui/include" -I"C:/Temp/Project/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Temp/Project/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Temp/Project/Middlewares/Third_Party/FatFs/src" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Temp/Project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Temp/Project/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Temp/Project/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Temp/Project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


