#include <Arduino.h>
#include <unity.h>

#include "Button.h"


const uint8_t PIN_BTN_PRINT = 26;

void test_pressed() {
    Button printButton(PIN_BTN_PRINT);

    if  (printButton.is_pressed() == Button::PRESSED) Serial.println("Button is pressed!");
    else Serial.println("Button not pressed!");
}


void test_button() {
	RUN_TEST(test_pressed);
}