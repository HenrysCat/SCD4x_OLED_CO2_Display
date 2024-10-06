This sketch will display readings from an SCD41 CO2, Temperature and Humidity sensor on an esp8266 with attached 128x64 dual colour OLED display.

For esp8266 in Arduino IDE select board as NodeMCU 1.0 (ESP-12E Module)

For esp32 in Arduino IDE select board as ESP32-WROOM-DA Module

You will need these libraries installed

https://gitlab.com/alexpr0/ssd1306wire

https://github.com/sparkfun/SparkFun_SCD4x_Arduino_Library


Wire the sensor as follows

esp8266

D5 = SDA

D6 = SCL

G  = GND

3v = VCC

![esp8266_OLED_SCD4x](https://github.com/user-attachments/assets/a8107330-041d-4b50-8562-1839177a33de)

esp32

D21 = SDA

D22 = SCA

G = GND

3v3 = VCC

![esp32](https://github.com/user-attachments/assets/be00bb1c-07bf-45d5-9122-61298363b003)
