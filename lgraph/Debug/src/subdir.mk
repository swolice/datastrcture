################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LGraph.c \
../src/LinkList.c \
../src/LinkQueue.c \
../src/main.c 

OBJS += \
./src/LGraph.o \
./src/LinkList.o \
./src/LinkQueue.o \
./src/main.o 

C_DEPS += \
./src/LGraph.d \
./src/LinkList.d \
./src/LinkQueue.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


