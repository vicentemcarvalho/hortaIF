################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/vic/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.14/libraries/Wire/src/Wire.cpp 

LINK_OBJ += \
./libraries/Wire/src/Wire.cpp.o 

CPP_DEPS += \
./libraries/Wire/src/Wire.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/Wire/src/Wire.cpp.o: /home/vic/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.14/libraries/Wire/src/Wire.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/vic/sloeber/arduinoPlugin/tools/arduino/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"/home/vic/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.14/cores/arduino" -I"/home/vic/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.14/variants/mega" -I"/home/vic/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.14/libraries/Wire" -I"/home/vic/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.14/libraries/Wire/src" -I"/home/vic/Downloads/IFPI/arduino/MyRealTimeClock" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '


