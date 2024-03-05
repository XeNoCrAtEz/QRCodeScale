#ifndef __SCALE_H__
#define __SCALE_H__


#include <Arduino.h>


class Scale {
private:
    enum ScaleParams {
        CONN_TIMEOUT = 1000,    // ms
        BAUDRATE = 1200,
        CHAR_COUNT = 8,
    };

public:
    // class status codes
    enum Status {
        READY,
        NO_SCALE,
        UNKNOWN_ERROR,
    };

    // operation status codes
    enum OpStatus {
        SUCCESS,
        STATUS_ERROR,
    };


private:
    HardwareSerial m_serial;

    Status m_status = UNKNOWN_ERROR;


private:
    void reverse(String& string);

public:
    Scale(uint8_t HWSerialNum=1);

    OpStatus get_reading(double& result);
    Status begin(uint8_t rx, uint8_t tx);
    Status status();


};


#endif