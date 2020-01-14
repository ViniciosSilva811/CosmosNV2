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

// ------------------------------------------------------------------------------------------ //

#ifndef _CosmosNV2_H_
#define _CosmosNV2_H_

// ----------------------------------- DEPENDÊNCIAS ----------------------------------------- //

#include <Arduino.h>

// ------------------------------- Classe SensorDeLinha ------------------------------------- //

class SensorDeLinha
{
  public:
    SensorDeLinha(uint8_t pino);
    int ler();

  private:
    uint8_t _pino;
};

// -------------------------------- Classe SensorDeToque ------------------------------------ //

class SensorDeToque
{
  public:
    SensorDeToque(uint8_t porta);
    boolean lerEstado();
  private:
    uint8_t _porta;
};

// ------------------------------------------------------------------------------------------ //

#endif

// ---------------------------------------- FIM DO CÓDIGO ----------------------------------- //
