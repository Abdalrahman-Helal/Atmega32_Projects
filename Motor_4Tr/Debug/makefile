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
Motor_4Tr.lss \

FLASH_IMAGE += \
Motor_4Tr.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Motor_4Tr.elf secondary-outputs

# Tool invocations
Motor_4Tr.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Motor_4Tr.map -mmcu=atmega32 -o "Motor_4Tr.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Motor_4Tr.lss: Motor_4Tr.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Motor_4Tr.elf  >"Motor_4Tr.lss"
	@echo 'Finished building: $@'
	@echo ' '

Motor_4Tr.hex: Motor_4Tr.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Motor_4Tr.elf  "Motor_4Tr.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Motor_4Tr.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Motor_4Tr.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Motor_4Tr.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
