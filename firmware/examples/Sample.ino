// This #include statement was automatically added by the Particle IDE.
#include "SHT30/SHT30.h"

SHT30 sensor;
double humidity;
double temperature;

void setup() {
    sensor.setAddress(0);
    Particle.variable("Humidity", humidity);
    Particle.variable("Temperature", temperature);
}

void loop() {
    if(sensor.update()){
        humidity = sensor.humidity;
        temperature = sensor.temperature;
    }
    delay(1000);
}