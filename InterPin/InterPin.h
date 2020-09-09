

#include "Arduino.h"


class InterPin
{
  private:
    // Variables de miembros de clase
    // Estos se inicializan al inicio
    int Pin1, Pin2;                 // el número del Puerto
    long OnTime;                    // milisegundos de tiempo
    long OffTime;                   // milisegundos de tiempo de inactividad 

    // Estos mantienen el estado actual
    int pinState;                   // pinState utilizado para configurar el Puerto
    unsigned long previousMillis;   // almacenará la última vez que se actualizó el Puerto
    
    // Constructor - crea un InterPin 
    // e inicializa las variables miembro y el estado
  public:
    InterPin(int pin1, int pin2, long on, long off);
    void Update();
    void Off();

};
