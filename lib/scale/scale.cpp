#include "scale.h"

Scale::Scale(uint8_t HWSerialNum)
        : m_serial(HWSerialNum) {}


Scale::Status Scale::begin(uint8_t rx, uint8_t tx) {
    m_serial.begin(BAUDRATE, SERIAL_8N1, rx, tx);

    unsigned long start = millis();
    while (millis() - start < CONN_TIMEOUT) {
        if (m_serial.available() > 0) {
            return (m_status = READY);
        }
    }

    return (m_status = NO_SCALE);
}


Scale::Status Scale::status() {
    return m_status;
}


void Scale::reverse(String& str) {
    int len = str.length();
    for (int i = 0; i <= len/2; i++) {
        char tempChar = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = tempChar;
    }
}


Scale::OpStatus Scale::get_reading(double& result) {
    if (m_status != READY) return STATUS_ERROR;

    // update()
    int count = 0;
    char buffer[CHAR_COUNT+1] = "";
    // read until '='
    while (m_serial.read() != '=');    buffer[count] = '=';    count++;
    
    while (count < CHAR_COUNT-1) {
        if(m_serial.available()) {
            buffer[count] = m_serial.read();
            count++;
        }
    }
    buffer[CHAR_COUNT-1] = '\0';

    String readingStr = String(buffer);
    reverse(readingStr);
    result = readingStr.toDouble();

    return SUCCESS;
    
    
}