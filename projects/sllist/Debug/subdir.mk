################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../check.c \
../cnt.c \
../concat.c \
../create.c \
../ins_del.c \
../main.c \
../misc.c \
../print.c \
../sort.c \
../test.c 

OBJS += \
./check.o \
./cnt.o \
./concat.o \
./create.o \
./ins_del.o \
./main.o \
./misc.o \
./print.o \
./sort.o \
./test.o 

C_DEPS += \
./check.d \
./cnt.d \
./concat.d \
./create.d \
./ins_del.d \
./main.d \
./misc.d \
./print.d \
./sort.d \
./test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


