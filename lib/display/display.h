#ifndef _DISPLAY_H_
#define _DISPLAY_H_


#include <Arduino.h>

#include <SPI.h>
#include <TFT_22_ILI9225.h>


class Display {
public:
    // class status codes
    enum Status {
        READY,
        DISPLAY_FAILED,
        UNKNOWN_ERROR,
    };

    // operation status codes
    enum OpStatus {
        SUCCESS,
        STATUS_ERROR,
    };


private:
    SPIClass m_spi;
    TFT_22_ILI9225 m_tft;
    Status m_status = UNKNOWN_ERROR;


public:    
    Display(
            uint8_t rst, uint8_t mosi, uint8_t clk,
            uint8_t led, uint8_t brightness
        );
    Status status();
    // OpStatus display_splash_screen();
    // OpStatus display_data(const SoilData& soilData);
    // OpStatus clear_display();
};


#endif