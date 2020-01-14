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

// ---------------------------------------- FIM DO CÓDIGO ----------------------------------- //
