################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../D-17_PICWriter_PIC16F84A/D-17_PICWriter_PIC16F84A.X/D-17_s-1.c 

OBJS += \
./D-17_PICWriter_PIC16F84A/D-17_PICWriter_PIC16F84A.X/D-17_s-1.o 

C_DEPS += \
./D-17_PICWriter_PIC16F84A/D-17_PICWriter_PIC16F84A.X/D-17_s-1.d 


# Each subdirectory must supply rules for building sources it contributes
D-17_PICWriter_PIC16F84A/D-17_PICWriter_PIC16F84A.X/%.o: ../D-17_PICWriter_PIC16F84A/D-17_PICWriter_PIC16F84A.X/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\MinGW\mingw32\i686-w64-mingw32\include" -I"C:\WORKS\Programs\Microchip\XC8\v1.33\include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


