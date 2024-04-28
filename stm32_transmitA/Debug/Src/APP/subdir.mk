################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/APP/Car_Control.c \
../Src/APP/Collision_Avoidance.c \
../Src/APP/Motion_Planing.c \
../Src/APP/Path_Tracking.c \
../Src/APP/Scenario_Select.c 

OBJS += \
./Src/APP/Car_Control.o \
./Src/APP/Collision_Avoidance.o \
./Src/APP/Motion_Planing.o \
./Src/APP/Path_Tracking.o \
./Src/APP/Scenario_Select.o 

C_DEPS += \
./Src/APP/Car_Control.d \
./Src/APP/Collision_Avoidance.d \
./Src/APP/Motion_Planing.d \
./Src/APP/Path_Tracking.d \
./Src/APP/Scenario_Select.d 


# Each subdirectory must supply rules for building sources it contributes
Src/APP/Car_Control.o: ../Src/APP/Car_Control.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F401CCUx -DSTM32 -DSTM32F4 -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/APP/Car_Control.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/APP/Collision_Avoidance.o: ../Src/APP/Collision_Avoidance.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F401CCUx -DSTM32 -DSTM32F4 -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/APP/Collision_Avoidance.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/APP/Motion_Planing.o: ../Src/APP/Motion_Planing.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F401CCUx -DSTM32 -DSTM32F4 -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/APP/Motion_Planing.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/APP/Path_Tracking.o: ../Src/APP/Path_Tracking.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F401CCUx -DSTM32 -DSTM32F4 -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/APP/Path_Tracking.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/APP/Scenario_Select.o: ../Src/APP/Scenario_Select.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F401CCUx -DSTM32 -DSTM32F4 -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/APP/Scenario_Select.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

