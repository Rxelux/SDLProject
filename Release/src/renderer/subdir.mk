################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/renderer/initialize.c \
../src/renderer/renderer.c 

OBJS += \
./src/renderer/initialize.o \
./src/renderer/renderer.o 

C_DEPS += \
./src/renderer/initialize.d \
./src/renderer/renderer.d 


# Each subdirectory must supply rules for building sources it contributes
src/renderer/%.o: ../src/renderer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


