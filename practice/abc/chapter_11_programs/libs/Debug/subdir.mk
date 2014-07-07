################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../gcalloc.o \
../gfopen.o 

C_SRCS += \
../gcalloc.c \
../gfopen.c \
../main.c 

OBJS += \
./gcalloc.o \
./gfopen.o \
./main.o 

C_DEPS += \
./gcalloc.d \
./gfopen.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


