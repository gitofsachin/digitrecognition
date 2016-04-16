################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c \
../mylcd.c \
../nokialcd.c \
../startup_gcc.c \
../userinterrupt.c 

OBJS += \
./main.o \
./mylcd.o \
./nokialcd.o \
./startup_gcc.o \
./userinterrupt.o 

C_DEPS += \
./main.d \
./mylcd.d \
./nokialcd.d \
./startup_gcc.d \
./userinterrupt.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -DPART_TM4C123GH6PM -DTARGET_IS_BLIZZARD_RB1 -DARM_MATH_CM4 -I$(HOME)/tivaware -O0 -g3 -Wall -c -fmessage-length=0 -mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -ffunction-sections -fdata-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


