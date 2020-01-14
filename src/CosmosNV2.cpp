/* ------------------------------------------------------------------------------------------ *\
|                                                                                              |
|                                                                                              |
|                                    Cosmos NV2 Library                                        |
|                                                                                              |
|                                                                                              |
\* ------------------------------------------------------------------------------------------ */

/*

Author: Vinícios Silva
Meu GitHub: github.com/ViniciosSilva811
Versão: 1.0 Janeiro de 2020

*/

// ----------------------------------- DEPENDÊNCIAS ----------------------------------------- //

#include <Arduino.h>
#include "CosmosNV2.h"

// ------------------------------------ CONSTANTES ------------------------------------------ //

#define ENDERECO_L1 0x31
#define ENDERECO_L2 0x32
#define ENDERECO_L3 0x33
#define ENDERECO_L4 0x34
#define ENDERECO_L5 0x35
#define ENDERECO_L6 0x36
#define ENDERECO_L7 0x37

#define SHUT_L1 23
#define SHUT_L2 25
#define SHUT_L3 27
#define SHUT_L4 29
#define SHUT_L5 31
#define SHUT_L6 33
#define SHUT_L7 35

// ------------------------------- Classe SensorDeLinha ------------------------------------- //

SensorDeLinha::SensorDeLinha(uint8_t pino) {
	_pino = pino;

	pinMode(_pino, INPUT);
}

int SensorDeLinha::ler() {
	return analogRead(_pino);
}

// -------------------------------- Classe SensorDeToque ------------------------------------ //

SensorDeToque::SensorDeToque(uint8_t porta) {
	_porta = porta;
	pinMode(_porta, INPUT_PULLUP);
}

boolean SensorDeToque::lerEstado() {
	return !digitalRead(_porta);
}

// ----------------------------- Classe SensorDeDistancia ----------------------------------- //

SensorDeDistancia::SensorDeDistancia(uint8_t porta) {
	_porta = porta;

	switch (_porta) {
	case L1:
		shut = SHUT_L1;
		endereco = ENDERECO_L1;
		break;
	case L2:
		shut = SHUT_L2;
		endereco = ENDERECO_L2;
		break;
	case L3:
		shut = SHUT_L3;
		endereco = ENDERECO_L3;
		break;
	case L4:
		shut = SHUT_L4;
		endereco = ENDERECO_L4;
		break;
	case L5:
		shut = SHUT_L5;
		endereco = ENDERECO_L5;
		break;
	case L6:
		shut = SHUT_L6;
		endereco = ENDERECO_L6;
		break;
	case L7:
		shut = SHUT_L7;
		endereco = ENDERECO_L7;
		break;
	default:
		break;
	}

	pinMode(shut, OUTPUT);
	digitalWrite(shut, LOW);
}

boolean SensorDeDistancia::iniciar() {
	digitalWrite(shut, HIGH);
  delay(10);

	sensor.begin(endereco);
}

int SensorDeDistancia::ler() {
	sensor.rangingTest(&distancia);

  if (distancia.RangeStatus != 4) {
    return distancia.RangeMilliMeter/10;
  }
  return 819;
}

// ---------------------------------------- FIM DO CÓDIGO ----------------------------------- //
