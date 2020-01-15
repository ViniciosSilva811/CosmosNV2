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
#include "deps/SoftwareWire/SoftwareWire.h"
#include <Wire.h>

// ------------------------------------ CONSTANTES ------------------------------------------ //

#define L1 14
#define L2 15
#define L3 16
#define L4 17
#define L5 19
#define L6 24
#define L7 22

#define B 18
#define C 36

#define D 1
#define E 2

typedef enum
{
  TCS34725_INTEGRATIONTIME_2_4MS  = 0xFF,   /**<  2.4ms - 1 cycle    - Max Count: 1024  */
  TCS34725_INTEGRATIONTIME_24MS   = 0xF6,   /**<  24ms  - 10 cycles  - Max Count: 10240 */
  TCS34725_INTEGRATIONTIME_50MS   = 0xEB,   /**<  50ms  - 20 cycles  - Max Count: 20480 */
  TCS34725_INTEGRATIONTIME_101MS  = 0xD5,   /**<  101ms - 42 cycles  - Max Count: 43008 */
  TCS34725_INTEGRATIONTIME_154MS  = 0xC0,   /**<  154ms - 64 cycles  - Max Count: 65535 */
  TCS34725_INTEGRATIONTIME_700MS  = 0x00    /**<  700ms - 256 cycles - Max Count: 65535 */
}
tcs34725IntegrationTime_t;

typedef enum
{
  TCS34725_GAIN_1X                = 0x00,   /**<  No gain  */
  TCS34725_GAIN_4X                = 0x01,   /**<  2x gain  */
  TCS34725_GAIN_16X               = 0x02,   /**<  16x gain */
  TCS34725_GAIN_60X               = 0x03    /**<  60x gain */
}
tcs34725Gain_t;


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

// ----------------------------------- Classe SensorDeCor ----------------------------------- //

class SensorDeCor {
 public:
  SensorDeCor(uint8_t porta);
  
  boolean  iniciar(void);
  void     obterValores(uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c);

 private:
  boolean _tcs34725Initialised;
  tcs34725Gain_t _tcs34725Gain;
  tcs34725IntegrationTime_t _tcs34725IntegrationTime; 
  uint8_t _sdaPin;
  uint8_t _sclPin;
  SoftwareWire _i2c;

  void     setIntegrationTime(tcs34725IntegrationTime_t it);
  void     setGain(tcs34725Gain_t gain);
  void     write8 (uint8_t reg, uint32_t value);
  uint8_t  read8 (uint8_t reg);
  uint16_t read16 (uint8_t reg);
  void     enable(void);
};

// ------------------------------------------------------------------------------------------ //

#endif

// ---------------------------------------- FIM DO CÓDIGO ----------------------------------- //
