################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gameObjects/buttonsMap.c \
../src/gameObjects/buttonsMenu.c \
../src/gameObjects/buttonsOption.c \
../src/gameObjects/map.c \
../src/gameObjects/menuBG.c \
../src/gameObjects/player.c \
../src/gameObjects/scarf.c \
../src/gameObjects/textCredits.c \
../src/gameObjects/textMenu.c \
../src/gameObjects/textTimer.c \
../src/gameObjects/tileMap.c 

OBJS += \
./src/gameObjects/buttonsMap.o \
./src/gameObjects/buttonsMenu.o \
./src/gameObjects/buttonsOption.o \
./src/gameObjects/map.o \
./src/gameObjects/menuBG.o \
./src/gameObjects/player.o \
./src/gameObjects/scarf.o \
./src/gameObjects/textCredits.o \
./src/gameObjects/textMenu.o \
./src/gameObjects/textTimer.o \
./src/gameObjects/tileMap.o 

C_DEPS += \
./src/gameObjects/buttonsMap.d \
./src/gameObjects/buttonsMenu.d \
./src/gameObjects/buttonsOption.d \
./src/gameObjects/map.d \
./src/gameObjects/menuBG.d \
./src/gameObjects/player.d \
./src/gameObjects/scarf.d \
./src/gameObjects/textCredits.d \
./src/gameObjects/textMenu.d \
./src/gameObjects/textTimer.d \
./src/gameObjects/tileMap.d 


# Each subdirectory must supply rules for building sources it contributes
src/gameObjects/%.o: ../src/gameObjects/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


