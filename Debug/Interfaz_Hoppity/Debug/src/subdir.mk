################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Estadisticas.c \
../src/FuncionesHoppity.c \
../src/INTELIGENCIA.c \
../src/Inteligencia.c \
../src/Interfaz_Hoppity.c 

C_DEPS += \
./src/Estadisticas.d \
./src/FuncionesHoppity.d \
./src/INTELIGENCIA.d \
./src/Inteligencia.d \
./src/Interfaz_Hoppity.d 

OBJS += \
./src/Estadisticas.o \
./src/FuncionesHoppity.o \
./src/INTELIGENCIA.o \
./src/Inteligencia.o \
./src/Interfaz_Hoppity.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/gio-unix-2.0 -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/fribidi -I/usr/include/atk-1.0 -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libpng16 -I/usr/include/x86_64-linux-gnu -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Estadisticas.d ./src/Estadisticas.o ./src/FuncionesHoppity.d ./src/FuncionesHoppity.o ./src/INTELIGENCIA.d ./src/INTELIGENCIA.o ./src/Inteligencia.d ./src/Inteligencia.o ./src/Interfaz_Hoppity.d ./src/Interfaz_Hoppity.o

.PHONY: clean-src

