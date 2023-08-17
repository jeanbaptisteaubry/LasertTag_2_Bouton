#include <Arduino.h>
#include "Button.h"

Button::Button(uint8_t _PIN) :  ButtonInterface(_PIN)
{
  
}

Button::Button(uint8_t _PIN, bool modePullUp) : ButtonInterface(_PIN, modePullUp) {
  
}

void Button::MAJ()
{
  int etatBouton = digitalRead(PIN);
  logicMaj(etatBouton);
}
 