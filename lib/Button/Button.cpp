#include "Button.h"


Button::Button(uint8_t pin) 
        : m_pin(pin) {
    pinMode(m_pin, OUTPUT);
    digitalWrite(m_pin, LOW);

    m_status = READY;
}


Button::OpStatus Button::on() {
    if (m_status != READY) return STATUS_ERROR;
    
    if (m_level == HIGH) return PRESSED;
    digitalWrite(m_pin, HIGH);

    return PRESSED;
}


Button::OpStatus Button::off() {
    if (m_status != READY) return STATUS_ERROR;
    
    if (m_level == LOW) return NOT_PRESSED;
    digitalWrite(m_pin, LOW);

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