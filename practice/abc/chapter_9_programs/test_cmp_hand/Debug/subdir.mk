################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../check.c \
../cmp.c \
../main.c \
../play.c \
../print.c \
../setup.c 

OBJS += \
./check.o \
./cmp.o \
./main.o \
./play.o \
./print.o \
./setup.o 

C_DEPS += \
./check.d \
./cmp.d \
./main.d \
./play.d \
./print.d \
./setup.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


