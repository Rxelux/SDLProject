################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gameObjects/camera.c \
../src/gameObjects/player.c \
../src/gameObjects/tileMap.c 

OBJS += \
./src/gameObjects/camera.o \
./src/gameObjects/player.o \
./src/gameObjects/tileMap.o 

C_DEPS += \
./src/gameObjects/camera.d \
./src/gameObjects/player.d \
./src/gameObjects/tileMap.d 


# Each subdirectory must supply rules for building sources it contributes
src/gameObjects/%.o: ../src/gameObjects/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


