################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/physics/Transform.c \
../src/physics/body.c \
../src/physics/hitBox.c \
../src/physics/vector.c 

OBJS += \
./src/physics/Transform.o \
./src/physics/body.o \
./src/physics/hitBox.o \
./src/physics/vector.o 

C_DEPS += \
./src/physics/Transform.d \
./src/physics/body.d \
./src/physics/hitBox.d \
./src/physics/vector.d 


# Each subdirectory must supply rules for building sources it contributes
src/physics/%.o: ../src/physics/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


