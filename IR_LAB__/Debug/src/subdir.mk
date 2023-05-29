################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/EXTI_PROGRAME.c \
../src/GPIO_PROGRAM.c \
../src/IR_PROGRAM.c \
../src/NVIC_PROGRAME.c \
../src/RCC_PROGRAM.c \
../src/SYSTICK_PROGRAME.c \
../src/_initialize_hardware.c \
../src/main_ir.c \
../src/stm32f4xx_hal_msp.c 

OBJS += \
./src/EXTI_PROGRAME.o \
./src/GPIO_PROGRAM.o \
./src/IR_PROGRAM.o \
./src/NVIC_PROGRAME.o \
./src/RCC_PROGRAM.o \
./src/SYSTICK_PROGRAME.o \
./src/_initialize_hardware.o \
./src/main_ir.o \
./src/stm32f4xx_hal_msp.o 

C_DEPS += \
./src/EXTI_PROGRAME.d \
./src/GPIO_PROGRAM.d \
./src/IR_PROGRAM.d \
./src/NVIC_PROGRAME.d \
./src/RCC_PROGRAM.d \
./src/SYSTICK_PROGRAME.d \
./src/_initialize_hardware.d \
./src/main_ir.d \
./src/stm32f4xx_hal_msp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/stm32f4xx_hal_msp.o: ../src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -Wno-missing-prototypes -Wno-missing-declarations -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/stm32f4xx_hal_msp.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


