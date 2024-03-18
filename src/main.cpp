#include <Arduino.h>
#include "main.h"

#include "Adafruit_Thermal.h"


#define PIN_PRINTER_TX 33
#define PIN_PRINTER_RX 32

Scale scale;
HardwareSerial& printer_serial = Serial2;
Adafruit_Thermal printer(&printer_serial);


char init_code_1[2] = {
    0x1B, 0x40,             // init printer
};

char init_code_2[2] = {
    0x1B, 0x36,             // use character set 1
};

char bar_code[7]={
    0x1D, 0x6B, 0x08, 0x03, 0x41, 0x42, 0x43
};

const char QRx[14]={
  0x1D, 0x69, 0x04,         // set magnification QR code = 4 (default)
  0x1D, 0x6A, 0x01,         // set error correction level = 1 (default)
  0x1D, 0x4D, 0x01, 0x41, 0x42, 0x43, 0x00      // print QR code "ABC" with margins 1*2mm
};       


void setup() {
    Serial.begin(115200);
    scale.begin(PIN_SCALE_RX, PIN_SCALE_TX);

    printer_serial.begin(9600, SERIAL_8N1, PIN_PRINTER_RX, PIN_PRINTER_TX);

    printer_serial.write(init_code_1, 2);
    printer_serial.println();
    delay(20);
    printer_serial.write(init_code_2, 2);
    printer_serial.println();
    delay(20);
    printer_serial.println("Print Barcode");
    delay(20);
    printer_serial.write(bar_code,7);     //send “print barcode instruction” to printer       
    printer_serial.println();
    delay(20);
    char white_print_code[3] = {0x1B, 0x69, 0x01};
    printer_serial.write(white_print_code, 3);
    printer_serial.println("Print QR Code");
    char white_print_code_cancel[3] = {0x1B, 0x69, 0x00};
    printer_serial.write(white_print_code_cancel, 3);
    delay(20);
    printer_serial.write(QRx,14);        //send “print QR code instruction” to printer.
    printer_serial.println();
    delay(5000);
}


void loop() {
    double scaleReading = 0;

    if  (scale.get_reading(scaleReading) == Scale::SUCCESS) Serial.println("Scale reading: " + String(scaleReading) + " kg");
    else Serial.println("Scale status error!");

    
}