#include "CosmosNV2.h"

SensorDeLinha sensor(A1);

int valor_lido;

void setup() {
  Serial.begin(115200);
}

void loop() {
  valor_lido = sensor.ler();
  Serial.print("Valor lido: ");
  Serial.println(valor_lido);
}