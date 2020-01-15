
#include "CosmosNV2.h"

Motor motor_direito(M1);
Motor motor_esquerdo(M2);

void setup() {
  motor_direito.configurarVelocidade(255);
  motor_esquerdo.configurarVelocidade(255);
}

void loop() {
  ir_para_frente();
  delay(2000);

  parar();
  delay(1000);

  ir_para_tras();
  delay(2000);

  parar();
  delay(1000);

  girar_para_direita();
  delay(1000);

  girar_para_esquerda();
  delay(2000);

  girar_para_direita();
  delay(1000);

  parar();
  delay(1000);
}

void ir_para_frente() {
  motor_direito.girar(PARA_FRENTE);
  motor_esquerdo.girar(PARA_FRENTE);
}

void ir_para_tras() {
  motor_direito.girar(PARA_TRAS);
  motor_esquerdo.girar(PARA_TRAS);
}

void girar_para_direita() {
  motor_direito.girar(PARA_TRAS);
  motor_esquerdo.girar(PARA_FRENTE);
}

void girar_para_esquerda() {
  motor_direito.girar(PARA_FRENTE);
  motor_esquerdo.girar(PARA_TRAS);
}

void parar() {
  motor_direito.parar();
  motor_esquerdo.parar();
}
