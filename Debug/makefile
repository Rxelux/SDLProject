################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: SDLProject

dependents:
	-cd /Users/robinpelletier/EclipseProjects/SDLProject/Release && $(MAKE) all

# Tool invocations
SDLProject: $(OBJS) $(USER_OBJS) /Users/robinpelletier/EclipseProjects/SDLProject/Release/SDLProject
	@echo 'Building target: $@'
	@echo 'Invoking: MacOS X C Linker'
	gcc -F/Library/Frameworks -framework SDL2 -framework SDL2_image -framework SDL2_mixer -framework SDL2_ttf -framework Cocoa -o "SDLProject" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) SDLProject
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/Users/robinpelletier/EclipseProjects/SDLProject/Release/SDLProject:

-include ../makefile.targets
