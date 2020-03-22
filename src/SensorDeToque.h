
#include <Arduino.h>

// -------------------------------- Classe SensorDeToque ------------------------------------ //

class SensorDeToque
{
  public:
    SensorDeToque();
    SensorDeToque(uint8_t porta);
    boolean lerEstado();
  private:
    uint8_t _porta;
};
