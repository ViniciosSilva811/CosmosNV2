
#include "CosmosNV2.h"

Motor motor(M1);

void setup() {
  motor.configurarVelocidade(255);
}

void loop() {
  motor.girar(PARA_FRENTE);
  delay(1000);
  
  motor.parar();
  delay(1000);

  motor.girar(PARA_TRAS);
  delay(1000);
  
  motor.parar();
  delay(1000);
}