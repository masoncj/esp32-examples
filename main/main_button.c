#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_wifi.h"
#include "esp_system.h"


volatile static bool led = 0;



void IRAM_ATTR button_intr(void* arg) {
    uint32_t status = GPIO.status;
    if (status && 1 << GPIO_NUM_0) {
        if (!gpio_get_level(GPIO_NUM_0)) {

            for (volatile int i = 0; i < 10000; ++i) {}  // Cheesy debounce.

            if (!gpio_get_level(GPIO_NUM_0)) {
                led = !led;
                gpio_set_level(GPIO_NUM_5, led);
            }
        }
    }
    GPIO.status_w1tc = status;
}


void app_main(void) {
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_0, GPIO_MODE_INPUT);

    gpio_set_intr_type(GPIO_NUM_0, GPIO_INTR_NEGEDGE);
    gpio_set_pull_mode(GPIO_NUM_0, GPIO_PULLUP_ONLY);
    gpio_intr_enable(GPIO_NUM_0);

    gpio_isr_register(
        button_intr,             // Interrupt handler.
        NULL,                    // Argument to GPIO function.
        ESP_INTR_FLAG_LEVEL2,    // Flags
        NULL                     // Handle to interrupt registration.
    );
}