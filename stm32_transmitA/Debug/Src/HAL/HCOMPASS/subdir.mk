################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/HCOMPASS/HAL_COMPASS.c 

OBJS += \
./Src/HAL/HCOMPASS/HAL_COMPASS.o 

C_DEPS += \
./Src/HAL/HCOMPASS/HAL_COMPASS.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/HCOMPASS/HAL_COMPASS.o: ../Src/HAL/HCOMPASS/HAL_COMPASS.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F401CCUx -DSTM32 -DSTM32F4 -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/HAL/HCOMPASS/HAL_COMPASS.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

