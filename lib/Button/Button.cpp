#include "Button.h"


Button::Button(uint8_t pin) 
        : m_pin(pin) {
    pinMode(m_pin, OUTPUT);
    digitalWrite(m_pin, LOW);

    m_status = READY;
}


Button::OpStatus Button::is_pressed() {
    if (m_status != READY) return STATUS_ERROR;
    
    if (digitalRead(m_pin) == LOW) return PRESSED;

    return NOT_PRESSED;
}


Button::Status Button::release() {
    pinMode(m_pin, INPUT);
    m_status = RELEASED;
    return RELEASED;
}


Button::Status Button::status() {
    return m_status;
}