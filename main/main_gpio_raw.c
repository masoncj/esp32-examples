#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_wifi.h"
#include "esp_system.h"

void app_main(void)
{
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);
    int level = 0;

    uint32_t* GPIO_w1ts = (uint32_t*)0x3ff44008;
    uint32_t* GPIO_w1tc = (uint32_t*)0x3ff4400c;

    while (true) {
        printf("Hello, world.\n");
        if (level) {
            *GPIO_w1ts = 1 << 5;
        } else {
            *GPIO_w1tc = 1 << 5;
        }
        level = !level;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
