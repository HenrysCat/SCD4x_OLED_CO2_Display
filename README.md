This sketch will display readings from an SCD41 CO2, Temperature and Humidity sensor on an esp8266 with attached 128x64 dual colour OLED display.

In Arduino IDE select board as NodeMCU 1.0 (ESP-12E Module)


You will need these libraries installed

https://gitlab.com/alexpr0/ssd1306wire

https://github.com/sparkfun/SparkFun_SCD4x_Arduino_Library


Wire the sensor as follows

Board - Sensor
D5 = SDA
D6 = SCL
G  = GND
3v = VCC
