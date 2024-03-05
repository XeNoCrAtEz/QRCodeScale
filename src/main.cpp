#include <Arduino.h>

const uint8_t PIN_SCALE_TX = 26;
const uint8_t PIN_SCALE_RX = 27;

const uint8_t SCALE_CHAR_BUFFSIZE = 8;


HardwareSerial& scale = Serial1;


void serial_clear(HardwareSerial& scale);
void reverse_string(char* data, int datasize);
void get_scale_reading(HardwareSerial& scale, char* buffer, int buffsize);


void setup() {
    Serial.begin(115200);
    scale.begin(1200, SERIAL_8N1, PIN_SCALE_RX, PIN_SCALE_TX);
}


void loop() {
    char data[SCALE_CHAR_BUFFSIZE] = "";
    get_scale_reading(scale, data, SCALE_CHAR_BUFFSIZE);
    Serial.println(data);
}


void reverse_string(char* data, int datasize) {
    for (int i = 0; i < datasize/2; i++) {
        char tempChar = data[i];
        data[i] = data[datasize-i];
        data[datasize-i] = tempChar;
    }
}


void get_scale_reading(HardwareSerial& scale, char* buffer, int buffsize) {
    int count = 0;
    while (count < buffsize-1) {
        if(scale.available()) {
            buffer[count] = scale.read();
            count++;
        }
    }
    serial_clear(scale);
    buffer[buffsize-1] = '\0';
}


void serial_clear(HardwareSerial& scale) {
    while (scale.available()) Serial.read();
}