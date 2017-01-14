#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_wifi.h"
#include "esp_system.h"

void app_main(void)
{
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);
    int level = 0;

    while (true) {
        printf("Hello, world.\n");
        gpio_set_level(GPIO_NUM_5, level);
        level = !level;
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
