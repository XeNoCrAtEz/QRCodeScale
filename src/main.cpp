#include <Arduino.h>
#include "main.h"


Scale scale;


void setup() {
    Serial.begin(115200);
    scale.begin(PIN_SCALE_RX, PIN_SCALE_TX);
}


void loop() {
    double scaleReading = 0;

    if      (scale.get_reading(scaleReading) == Scale::SUCCESS) {
        Serial.println("Scale reading: " + String(scaleReading) + " kg");
    }
    else {
        Serial.println("Scale status error!");
    }
}