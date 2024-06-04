#include "pico/stdlib.h"

int main() {
    const uint LED_PIN = 22;
    const uint LED_PIN_21 = 21;
    gpio_init(LED_PIN);
    gpio_init(LED_PIN_21);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(LED_PIN_21, GPIO_OUT);

    // sets the mask to change 22 and 21 at the same time
    uint32_t mask = (1 << 22) | (1 << 21);
    uint32_t value_1 = 1 << 21;
    uint32_t value_2 = 1 << 22;

    // the following loop sets high on 21 while sets low on 22 and viceversa
    while (true) {
        gpio_put_masked(mask, value_1);
        sleep_ms(250);
        gpio_put_masked(mask, value_2);
        sleep_ms(250);
    }

}

/** OUTPUT TWO GPIO lines one after another, page 58
 * const uint LED_PIN = 22;
    const uint LED_PIN_21 = 21;
    gpio_init(LED_PIN);
    gpio_init(LED_PIN_21);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(LED_PIN_21, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        gpio_put(LED_PIN_21, 1);
        sleep_ms(250);

        gpio_put(LED_PIN, 0);
        gpio_put(LED_PIN_21, 0);
        sleep_ms(250);
    }
 * */
