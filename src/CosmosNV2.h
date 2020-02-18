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
Versão: 2.0 Fevereiro de 2020

*/

// ------------------------------------------------------------------------------------------ //

#ifndef _CosmosNV2_H_
#define _CosmosNV2_H_

// ----------------------------------- DEPENDÊNCIAS ----------------------------------------- //

#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include "Adafruit_VL53L0X.h"
#include "deps/SoftwareWire/SoftwareWire.h"
#include "Adafruit_SSD1306.h"

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

#define M1 1
#define M2 2

#define PARA_FRENTE 1
#define PARA_TRAS   2

#define S1 12
#define S2 11
#define S3 10
#define S4 9
#define S5 8

#define PRETO   0
#define BRANCO  1
#define INVERSO 2

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

// ------------------------------------ Classe Buzzer --------------------------------------- //

class Buzzer
{
  public:
    Buzzer();
    void soar_bipe();
    void soar_dois_bipes();
};

// ------------------------------------- Classe Motor --------------------------------------- //

class Motor
{
  public:
    Motor(uint8_t porta);
    void configurarVelocidade(uint8_t valor);
    void girar(uint8_t sentido);
    void parar();

  private:
    uint8_t _porta;
    uint8_t _sentido;
    uint8_t _velocidade;
    uint8_t a, b;
};

// ----------------------------------- Classe ServoMotor ------------------------------------ //

class ServoMotor
{
  public:
    ServoMotor(uint8_t porta);
    void anexar(uint8_t porta);
    void desanexar();
    void gravar(uint8_t angulo);
  private:
    Servo servo;
};

// ----------------------------------- Classe Tela --------------------------------------- //

class Tela
{
  public:
    Tela();
    void iniciar();
    void configurarCursor(uint16_t x, uint16_t y);
    void mostrar();
    void limpar();

    void configurarTamanhoDoTexto(uint8_t tamanho);
    void configurarCorDoTexto(uint16_t cor);
    void escrever(const char* texto);
    void escrever(int numero);
    void escrever(float numero);
    void escrever(long numero);
    void escrever(unsigned long numero);

    void desenharImagem(uint16_t x, uint16_t y, const uint8_t imagem[], uint16_t altura, 
                        uint16_t largura, uint16_t cor);
  private:
    Adafruit_SSD1306 display;
};

// ------------------------------------------------------------------------------------------ //

#endif

// ---------------------------------------- FIM DO CÓDIGO ----------------------------------- //
