#include <Arduino.h>
#include <unity.h>

#include "switch.h"


const uint8_t PIN_LED_PRINT = 26;


void test_blink() {
    Switch printLED(PIN_LED_PRINT);

    for (uint8_t count = 0; count < 5; count++) {
        printLED.on();
        delay(500);
        printLED.off();
        delay(500);
    }
}


void test_switch() {
	RUN_TEST(test_blink);
}