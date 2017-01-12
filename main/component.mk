#
# Main component makefile.
#
# This Makefile can be left empty. By default, it will take the sources in the 
# src/ directory, compile them and link them into lib(subdirectory_name).a 
# in the build directory. This behaviour is entirely configurable,
# please read the ESP-IDF documents if you need to do this.
#

# Choose only one of these main files:
COMPONENT_OBJS := main_gpio.o  # Basic GPIO example
# COMPONENT_OBJS := main_gpio_raw.o  # GPIO using raw registers.
# COMPONENT_OBJS := main_crash.o  # Demo debugger.
# COMPONENT_OBJS := main_arduino.o  # Demo use of Arduino API.
# COMPONENT_OBJS := main_button.o  # Simple button interrupt.
# COMPONENT_OBJS := main_adc.o  # Demo Analog to Digital Converter.
# COMPONENT_OBJS := main_temp.o  # Demo Dallas 1-wire Temperature Sensor.

COMPONENT_OBJS += OneWire.o DallasTemperature.o
COMPONENT_PRIV_INCLUDEDIRS = .
