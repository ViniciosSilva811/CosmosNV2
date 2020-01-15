#include "CosmosNV2.h"

SensorDeLinha sensor(A2);

int valor_lido;

void setup() {
  Serial.begin(9600);
  valor_lido = sensor.ler();
}

void loop() {
  Serial.print("Valor lido: ");
  Serial.println(valor_lido);
}