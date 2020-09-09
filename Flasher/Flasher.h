

#include "Arduino.h"


class Flasher
{
    // Variables de miembros de clase
    // Estos se inicializan al inicio
    int ledPin;                     // el número del pin LED
    long OnTime;                    // milisegundos de tiempo
    long OffTime;                   // milisegundos de tiempo de inactividad 

    // Estos mantienen el estado actual
    int ledState;                   // ledState utilizado para configurar el LED
    unsigned long previousMillis;   // almacenará la última vez que se actualizó el LED
    
    // Constructor - crea un Flasher 
    // e inicializa las variables miembro y el estado
  public:
    Flasher(int pin, long on, long off);
    void Update();

};
