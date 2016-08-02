################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/binary_tree3.c \
../src/main.c \
../src/seqlist2.c 

OBJS += \
./src/binary_tree3.o \
./src/main.o \
./src/seqlist2.o 

C_DEPS += \
./src/binary_tree3.d \
./src/main.d \
./src/seqlist2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


