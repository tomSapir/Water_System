#include <Wire.h>
// BME280
#include <Adafruit_BME280.h>

#define SENSOR_PIN  A0
#define LED_PIN     7
#define SPEAKER_PIN 2
// BME280
#define I2C_SCL     5
#define I2C_SDA     4

int sensorValue = 0;  // variable to store the value coming from the humidity sensor
Adafruit_BME280 bme;

// TODO:
// - read about Wire.h
// - read about Adafruit_BME280.h
// - read about I2C in arduino

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);

  Serial.begin(9600);
  Wire.begin();
  if (!bme.begin(0x76)) 
  {
      Serial.println("Could not find a valid BME280 sensor, check wiring!");
      while (1);
  }

}

void loop() 
{
  //Serial.write("write this");

  // read the value from the sensor:
  sensorValue = analogRead(SENSOR_PIN);

  if (sensorValue < 900)
  {
    // turn on the led:
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(SPEAKER_PIN, HIGH);

  }
  else if (sensorValue > 950)
  {
    // turn off the led:
    digitalWrite(LED_PIN, LOW);
    digitalWrite(SPEAKER_PIN, LOW);
  }

  // Get data from BME280 sensor
  float temp = bme.readTemperature();  // C
  float humidity = bme.readHumidity(); // %
  float pressure = bme.readPressure();  // 100.0F, hPa

  Serial.print("Temperature: ");
  Serial.println(temp);

  Serial.print("Humidity: ");
  Serial.println(humidity);

  Serial.print("Pressure: ");
  Serial.println(pressure);
  Serial.println();

  //Serial.println(sensorValue, DEC);
  delay(2000);
}
