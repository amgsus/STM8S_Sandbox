## TODOs 

* Add a program module (driver) to support embedded 10-bit ADC (analog-to-digital converter):
    * Initialize ADC.
    * Read an analog input (using a "poll" method, i.e. non-blocking call).

* Add PWM driver for both TIM1 & TIM2.

* Add string/number-conversion functions:
    * Hexadecimal to integer (8-bit).
    * Integer (8-bit, 16-bit) to hexadecimal.
    * Integer (8-bit, 16-bit) to string.

* Add WS2812B driver (using NOPs).

* Add a 7-segment display driver for using with HC595 8-bit shift register.

* Add a program module for hardware I2C.