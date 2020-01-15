#include "CosmosNV2.h"

uint16_t RD, GD, BD, CD, RE, GE, BE, CE;

SensorDeCor sensor_direito(D);
SensorDeCor sensor_esquerdo(E);

void setup() {
  Serial.begin(115200);
  sensor_direito.iniciar();
  sensor_esquerdo.iniciar(); 
}

void loop() {
  sensor_direito.obterValores(&RD, &GD, &BD, &CD);
  sensor_esquerdo.obterValores(&RE, &GE, &BE, &CE);

  Serial.print(F("RE: "));
  Serial.print(RE);
  Serial.print(F("  GE: "));
  Serial.print(GE);
  Serial.print(F("  BE: "));
  Serial.print(BE);
  Serial.print(F("  CE: "));
  Serial.print(CE);

  Serial.print(F("   RD: "));
  Serial.print(RD);
  Serial.print(F("  GD: "));
  Serial.print(GD);
  Serial.print(F("  BD: "));
  Serial.print(BD);
  Serial.print(F("  CD: "));
  Serial.println(CD);
}