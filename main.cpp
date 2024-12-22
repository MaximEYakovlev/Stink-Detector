#include <Arduino.h>

#define GAS_SENSOR_PIN A0 // pin for the gas sensor
#define BUZZER_PIN 2      // pin for the buzzer
#define THRESHOLD 1200    // threshold value for Arduino Due (0-4095 range)

void setup()
{
    pinMode(GAS_SENSOR_PIN, INPUT); // configure the gas sensor pin as input
    pinMode(BUZZER_PIN, OUTPUT);    // configure the buzzer pin as output
    Serial.begin(9600);             // initialize the serial port for debugging
}

void loop()
{
    int sensorValue = analogRead(GAS_SENSOR_PIN); // read the value from the gas sensor (0-4095)
    Serial.print("sensor Value: ");
    Serial.println(sensorValue); // print the sensor value to the serial monitor

    if (sensorValue > THRESHOLD)
    {                                     // check if the sensor value exceeds the threshold
        digitalWrite(BUZZER_PIN, HIGH);   // turn on the buzzer
        Serial.println("odor detected!"); // log a message about the detected odor
    }
    else
    {
        digitalWrite(BUZZER_PIN, LOW); // turn off the buzzer
    }

    delay(500); // wait for 500 ms to stabilize readings
}
