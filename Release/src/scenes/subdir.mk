################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/scenes/lvl1.c 

OBJS += \
./src/scenes/lvl1.o 

C_DEPS += \
./src/scenes/lvl1.d 


# Each subdirectory must supply rules for building sources it contributes
src/scenes/%.o: ../src/scenes/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


