#include "Arduino.h"
#include "InterPin.h"


// Constructor - crea un InterPin 
// e inicializa las variables miembro y el estado
InterPin::InterPin(int pin1, int pin2, long on, long off)
{
  Pin1 = pin1;
  Pin2 = pin2;
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  OnTime = on;
  OffTime = off;
  pinState = LOW;
  previousMillis = 0;
}

void InterPin::Update()
{
  // verifica si es hora de cambiar el estado del PUERTO
  unsigned long currentMillis = millis();
  if ((pinState == HIGH) && (currentMillis - previousMillis >= OnTime))
  {
    pinState = LOW;                 // Apagamos
    previousMillis = currentMillis; // Recordar el tiempo 
    digitalWrite(Pin1, pinState);   // Actualizamos el PUERTO actual 
    digitalWrite(Pin2, !pinState);  // Actualizamos el PUERTO actual
  }
  else if ((pinState == LOW) && (currentMillis - previousMillis >= OffTime))
  {
    pinState = HIGH;                // Enciende
    previousMillis = currentMillis; // Recuerda el tiempo
    digitalWrite(Pin1, pinState);   // Actualizamos el PUERTO actual
    digitalWrite(Pin2, !pinState);  // Actualizamos el PUERTO actual
  }
}

void InterPin::Off()
{
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, LOW);
}
