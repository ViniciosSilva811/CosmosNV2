#include "CosmosNV2.h"

SensorDeDistancia sensor1(L1);
SensorDeDistancia sensor2(L2);
SensorDeDistancia sensor3(L3);

void setup() {
  Serial.begin(115200);
  sensor1.iniciar();
  sensor2.iniciar();
  sensor3.iniciar();
}

void loop() {
  Serial.print("Distancia1: ");
  Serial.print(sensor1.ler());
  Serial.print("\tDistancia2: ");
  Serial.print(sensor2.ler());
  Serial.print("\tDistancia3: ");
  Serial.println(sensor3.ler());
}