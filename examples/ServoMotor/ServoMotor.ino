#include "CosmosNV2.h"

ServoMotor servo(S1);

void setup() {
  
}

void loop() {
  servo.gravar(0);
  delay(1000);
  servo.gravar(180);
  delay(1000);
}