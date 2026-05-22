#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // I2C

void setup() {
  Serial.begin(9600);
  if (!bmp.begin(0x76)) {  // Check if the sensor is connected (default I2C address for BMP280 is 0x76)
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
}

void loop() {
  Serial.print(F("Temperature = "));
  Serial.print(bmp.readTemperature());
  Serial.println(F(" °C"));

  Serial.print(F("Pressure = "));
  Serial.print(bmp.readPressure() / 100.0F);
  Serial.println(F(" hPa"));

  delay(2000); // Wait for 2 seconds before the next reading
}
