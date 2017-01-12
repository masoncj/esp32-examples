#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include <driver/adc.h>


void app_main(void)
{
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);
    int level = 0;

    adc1_config_width(ADC_WIDTH_12Bit);
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_11db);
    while (true) {
        gpio_set_level(GPIO_NUM_5, level);
        level = !level;
        int val = adc1_get_voltage(ADC1_CHANNEL_0);
        printf("%i.\n", val);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
