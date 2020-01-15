#include "CosmosNV2.h"

SensorDeToque sensor(B);

boolean estado;

void setup() {
  Serial.begin(9600);
}

void loop() {
  estado = sensor.lerEstado();

  if (estado == 1) {
    Serial.println("Sensor pressionado!");
  }
  else {
    Serial.println("Sensor solto");
  }

  delay(500);
}