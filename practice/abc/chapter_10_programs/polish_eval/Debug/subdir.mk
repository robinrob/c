################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../eval.c \
../fill.c \
../main.c \
../print.c \
../stack.c 

OBJS += \
./eval.o \
./fill.o \
./main.o \
./print.o \
./stack.o 

C_DEPS += \
./eval.d \
./fill.d \
./main.d \
./print.d \
./stack.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


