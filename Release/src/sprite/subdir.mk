################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/sprite/sprite.c 

OBJS += \
./src/sprite/sprite.o 

C_DEPS += \
./src/sprite/sprite.d 


# Each subdirectory must supply rules for building sources it contributes
src/sprite/%.o: ../src/sprite/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


