
#include "Arduino.h"
#include "OneWire.h"
#include "DallasTemperature.h"
void *_impure_ptr;
extern "C" void app_main()
{
    gpio_pullup_en(GPIO_NUM_4);
    initArduino();
    pinMode(5, OUTPUT);
    OneWire oneWire(4);
    DallasTemperature sensors(&oneWire);
    int level = 0;
    printf("%i temperature sensors found.\n", sensors.getDeviceCount());
    while(1) {
        digitalWrite(5, level);
        level = !level;
        sensors.requestTemperatures();
        printf("Temp: %0.1f\n", sensors.getTempF(0));
        delay(500);
    }
}
