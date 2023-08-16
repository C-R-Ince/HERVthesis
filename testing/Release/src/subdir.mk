################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/primerReporter.cpp \
../src/testing.cpp 

CPP_DEPS += \
./src/primerReporter.d \
./src/testing.d 

OBJS += \
./src/primerReporter.o \
./src/testing.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/primerReporter.d ./src/primerReporter.o ./src/testing.d ./src/testing.o

.PHONY: clean-src

