################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../D-11-1_PIC16F84A/D-11-1_PIC16F84A_retry.X/D-11-1_PIC16F84A_retry.c 

OBJS += \
./D-11-1_PIC16F84A/D-11-1_PIC16F84A_retry.X/D-11-1_PIC16F84A_retry.o 

C_DEPS += \
./D-11-1_PIC16F84A/D-11-1_PIC16F84A_retry.X/D-11-1_PIC16F84A_retry.d 


# Each subdirectory must supply rules for building sources it contributes
D-11-1_PIC16F84A/D-11-1_PIC16F84A_retry.X/%.o: ../D-11-1_PIC16F84A/D-11-1_PIC16F84A_retry.X/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\MinGW\mingw32\i686-w64-mingw32\include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


