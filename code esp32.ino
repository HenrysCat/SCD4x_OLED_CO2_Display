#include <Wire.h>
#include <SSD1306Wire.h>
#include <SparkFun_SCD4x_Arduino_Library.h>

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDRESS 0x3C

// Define pins for I2C (you can change these if needed)
#define SDA_PIN 21
#define SCL_PIN 22

SSD1306Wire display(OLED_ADDRESS, SDA_PIN, SCL_PIN); // SDA (21), SCL (22)

// SCD4x instance
SCD4x mySensor;

void setup() {
  Serial.begin(115200);
  Serial.println(F("SCD4x Example"));

  // Initialize hardware I2C
  Wire.begin(SDA_PIN, SCL_PIN); // SDA -> 21, SCL -> 22

  // Initialize the OLED display
  display.init();
  display.flipScreenVertically(); // Rotate the display 180 degrees
  display.clear();
  display.display();

  Serial.println(F("OLED display initialized."));

  // Show initial message on OLED
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, 0, "OLED Test, wait 2 sec");
  display.display();

  delay(2000); // Pause for 2 seconds to see the test message

  // Clear the buffer again before starting the loop
  display.clear();
  display.display(); // Show cleared display

  // Initialize the SCD4x sensor with hardware I2C
  if (!mySensor.begin(Wire)) {
    Serial.println(F("Sensor not detected. Please check wiring. Continuing without sensor..."));
  } else {
    Serial.println(F("SCD4x sensor initialized."));
  }
}

void loop() {
  if (mySensor.readMeasurement()) {
    // Get CO2 reading and add 20
    float co2_reading = mySensor.getCO2() + 20;
    float temperature = mySensor.getTemperature();
    float humidity = mySensor.getHumidity();

    // Print measurements for debugging
    Serial.print("CO2: ");
    Serial.print(co2_reading);
    Serial.print(" ppm, ");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, ");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Clear the display buffer
    display.clear();

    // Display CO2 reading
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "CO2: " + String(co2_reading) + " ppm");

    // Display temperature
    display.drawString(0, 22, "Temp: " + String(temperature, 2) + " °C");

    // Display humidity
    display.drawString(0, 46, "Humidity: " + String(humidity, 2) + "%");

    // Display on OLED
    display.display();
  } else {
    Serial.print(F("."));
  }

  delay(10000); // Wait for 10 seconds between measurements
}
