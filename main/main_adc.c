#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include <driver/adc.h>


/** Demonstrate use of analog to digital converter (ADC).
 *
 * See README for details, including connection information.
 */
void app_main(void)
{
    // Set LED pin (pin 5) to output mode.
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);

    int level = 0;

    // Configure analog to digital convert to use 12-bit samples and no attenuation.
    adc1_config_width(ADC_WIDTH_12Bit);
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_0db);
    while (true) {
        // Turn the LED alternately on or off every cycle.
        gpio_set_level(GPIO_NUM_5, level);
        level = !level;

        // Read the voltage on PIN expressed as an integer from 0 to 4096).
        int val = adc1_get_voltage(ADC1_CHANNEL_0);

        // Print this value to the console.
        printf("%i.\n", val);

        // Wait 500 msecs (puts this main task to sleep).
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
