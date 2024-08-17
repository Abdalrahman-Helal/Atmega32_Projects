################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Optocoupler.lss \

FLASH_IMAGE += \
Optocoupler.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Optocoupler.elf secondary-outputs

# Tool invocations
Optocoupler.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Optocoupler.map -mmcu=atmega32 -o "Optocoupler.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Optocoupler.lss: Optocoupler.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Optocoupler.elf  >"Optocoupler.lss"
	@echo 'Finished building: $@'
	@echo ' '

Optocoupler.hex: Optocoupler.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Optocoupler.elf  "Optocoupler.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Optocoupler.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Optocoupler.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Optocoupler.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
