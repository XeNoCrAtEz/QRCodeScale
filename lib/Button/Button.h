#ifndef __SWITCH_H__
#define __SWITCH_H__


#include <Arduino.h>


class Button {
public:
    // class status codes
    enum Status {
        READY,
        RELEASED,
        UNKNOWN_ERROR,
    };
    
    // Operation status codes
    enum OpStatus {
        PRESSED,
        NOT_PRESSED,
        STATUS_ERROR,
    };


private:
    Status m_status = UNKNOWN_ERROR;
    uint8_t m_level = HIGH;
    uint8_t m_pin = -1;


public:
    Button(uint8_t pin);
    OpStatus is_pressed();
    Status release();
    Status status();


};


#endif