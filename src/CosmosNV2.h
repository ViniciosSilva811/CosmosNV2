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
#include "deps/Adafruit_VL53L0X/src/Adafruit_VL53L0X.h"
#include <Wire.h>

// ------------------------------------ CONSTANTES ------------------------------------------ //

#define L1 14
#define L2 15
#define L3 16
#define L4 17
#define L5 19
#define L6 24
#define L7 22

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

// ----------------------------- Classe SensorDeDistancia ----------------------------------- //

class SensorDeDistancia
{
  public:
    SensorDeDistancia(uint8_t porta);
    boolean iniciar();
    int ler();
  private:
    uint8_t _porta, shut, endereco;
    Adafruit_VL53L0X sensor;
    VL53L0X_RangingMeasurementData_t distancia;
};

// ------------------------------------------------------------------------------------------ //

#endif

// ---------------------------------------- FIM DO CÓDIGO ----------------------------------- //
