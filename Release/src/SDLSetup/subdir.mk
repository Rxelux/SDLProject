################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SDLSetup/SDLSetup.c 

OBJS += \
./src/SDLSetup/SDLSetup.o 

C_DEPS += \
./src/SDLSetup/SDLSetup.d 


# Each subdirectory must supply rules for building sources it contributes
src/SDLSetup/%.o: ../src/SDLSetup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


