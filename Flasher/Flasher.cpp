#include "Arduino.h"
#include "Flasher.h"


// Constructor - crea un Flasher 
// e inicializa las variables miembro y el estado
Flasher::Flasher(int pin, long on, long off)
{
  ledPin = pin;
  pinMode(ledPin, OUTPUT);
  OnTime = on;
  OffTime = off;
  ledState = LOW;
  previousMillis = 0;
}

void Flasher::Update()
{
  // verifica si es hora de cambiar el estado del LED
  unsigned long currentMillis = millis();
  if ((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
  {
    ledState = LOW;                 // Apagamos
    previousMillis = currentMillis; // Recordar el tiempo 
    digitalWrite(ledPin, ledState); // Actualiza el LED actual
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
  {
    ledState = HIGH;                // Enciende
    previousMillis = currentMillis; // Recuerda el tiempo
    digitalWrite(ledPin, ledState); // Actualiza el LED actual	
  }
}
