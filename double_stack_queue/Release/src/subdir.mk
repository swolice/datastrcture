################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LinkList.c \
../src/LinkStack.c \
../src/main.c \
../src/squeue.c 

OBJS += \
./src/LinkList.o \
./src/LinkStack.o \
./src/main.o \
./src/squeue.o 

C_DEPS += \
./src/LinkList.d \
./src/LinkStack.d \
./src/main.d \
./src/squeue.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


