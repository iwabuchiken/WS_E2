################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../main.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
main.o

OBJS_AS_ARGS +=  \
main.o

C_DEPS +=  \
main.d

C_DEPS_AS_ARGS +=  \
main.d

OUTPUT_FILE_PATH +=D-19_s-3_ATmega88P__LED-onoff.elf

OUTPUT_FILE_PATH_AS_ARGS +=D-19_s-3_ATmega88P__LED-onoff.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler



./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.9.2
	$(QUOTE)C:\WORKS\Programs\Atmel\Studio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\WORKS\Programs\Atmel\Studio_7.0\7.0\Packs\atmel\ATmega_DFP\1.0.90\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega88p -B "C:\WORKS\Programs\Atmel\Studio_7.0\7.0\Packs\atmel\ATmega_DFP\1.0.90\gcc\dev\atmega88p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 4.9.2
	$(QUOTE)C:\WORKS\Programs\Atmel\Studio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="D-19_s-3_ATmega88P__LED-onoff.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega88p -B "C:\WORKS\Programs\Atmel\Studio_7.0\7.0\Packs\atmel\ATmega_DFP\1.0.90\gcc\dev\atmega88p"  
	@echo Finished building target: $@
	"C:\WORKS\Programs\Atmel\Studio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "D-19_s-3_ATmega88P__LED-onoff.elf" "D-19_s-3_ATmega88P__LED-onoff.hex"
	"C:\WORKS\Programs\Atmel\Studio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "D-19_s-3_ATmega88P__LED-onoff.elf" "D-19_s-3_ATmega88P__LED-onoff.eep" || exit 0
	"C:\WORKS\Programs\Atmel\Studio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "D-19_s-3_ATmega88P__LED-onoff.elf" > "D-19_s-3_ATmega88P__LED-onoff.lss"
	"C:\WORKS\Programs\Atmel\Studio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "D-19_s-3_ATmega88P__LED-onoff.elf" "D-19_s-3_ATmega88P__LED-onoff.srec"
	"C:\WORKS\Programs\Atmel\Studio_7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "D-19_s-3_ATmega88P__LED-onoff.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "D-19_s-3_ATmega88P__LED-onoff.elf" "D-19_s-3_ATmega88P__LED-onoff.a" "D-19_s-3_ATmega88P__LED-onoff.hex" "D-19_s-3_ATmega88P__LED-onoff.lss" "D-19_s-3_ATmega88P__LED-onoff.eep" "D-19_s-3_ATmega88P__LED-onoff.map" "D-19_s-3_ATmega88P__LED-onoff.srec" "D-19_s-3_ATmega88P__LED-onoff.usersignatures"
	