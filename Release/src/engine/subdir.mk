################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/engine/camera.c \
../src/engine/inputs.c \
../src/engine/sprite.c \
../src/engine/timer.c 

OBJS += \
./src/engine/camera.o \
./src/engine/inputs.o \
./src/engine/sprite.o \
./src/engine/timer.o 

C_DEPS += \
./src/engine/camera.d \
./src/engine/inputs.d \
./src/engine/sprite.d \
./src/engine/timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/engine/%.o: ../src/engine/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


