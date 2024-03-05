#include <Arduino.h>
#include <unity.h>

#include "scale.h"


const uint8_t PIN_SCALE_TX = 26;
const uint8_t PIN_SCALE_RX = 27;


void test_scale_get_reading() {
    Scale scale;
    scale.begin(PIN_SCALE_RX, PIN_SCALE_TX);

    double scaleReading = 0;
    if (scale.get_reading(scaleReading) == Scale::SUCCESS) {
        Serial.println("Scale reading: " + String(scaleReading) + " kg");
    }
    else {
        Serial.println("Scale status error!");
    }    
}


void test_scale() {
	RUN_TEST(test_scale_get_reading);
}