#include "Arduino.h"
void *_impure_ptr;

extern "C" void app_main()
{
    initArduino();
    pinMode(5, OUTPUT);
    int level = 0;
    while(1) {
        digitalWrite(5, level);
        level = !level;
        delay(500);
    }
}