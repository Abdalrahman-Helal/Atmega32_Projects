################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Keypad/subdir.mk
-include APP/subdir.mk
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
SimpleCalc.lss \

FLASH_IMAGE += \
SimpleCalc.hex \

EEPROM_IMAGE += \
SimpleCalc.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: SimpleCalc.elf secondary-outputs

# Tool invocations
SimpleCalc.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SimpleCalc.map -mmcu=atmega32 -o "SimpleCalc.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SimpleCalc.lss: SimpleCalc.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SimpleCalc.elf  >"SimpleCalc.lss"
	@echo 'Finished building: $@'
	@echo ' '

SimpleCalc.hex: SimpleCalc.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SimpleCalc.elf  "SimpleCalc.hex"
	@echo 'Finished building: $@'
	@echo ' '

SimpleCalc.eep: SimpleCalc.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SimpleCalc.elf  "SimpleCalc.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SimpleCalc.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SimpleCalc.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SimpleCalc.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
