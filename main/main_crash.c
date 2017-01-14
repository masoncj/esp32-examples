#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_wifi.h"
#include "esp_system.h"

/** Demonstrate use of GDB debug stub.
 *
 * Invoke GDB like:
 *   xtensa-esp32-elf-gdb ./build/app-template.elf -b 115200 -ex 'target remote /dev/cu.usb*'
 *
 * See README.md for details.
 */
void app_main(void)
{
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);
    int level = 0;

    while (true) {
        gpio_set_level(GPIO_NUM_5, level);
        level = !level;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        printf("Crashing....\n");
        volatile uint32_t foo = *(uint32_t*)0;
    }
}
