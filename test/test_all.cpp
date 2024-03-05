#include <Arduino.h>
#include <unity.h>


void test_scale();


void setUp() {
}


void tearDown() {
}


void setup() {
    Serial.begin(115200);
    
    UNITY_BEGIN();

    test_scale();
    
    UNITY_END();
}


void loop() {
}