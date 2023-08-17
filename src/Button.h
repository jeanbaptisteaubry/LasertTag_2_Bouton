#include <Arduino.h>
#include "ButtonInterface.h"
#ifndef BUTTON_H
#define BUTTON_H
 
class Button : public ButtonInterface
{
 

public:
 
  Button(uint8_t _PIN); //Constructeur
  Button(uint8_t _PIN, bool modePullUp); //Constructeur avec précision du mode de pullup du bouton. Les boutons sont normalement ouverts ou fermés, il faut donc préciser le mode de pullup
  void MAJ() override; //Mise à jour de l'état du bouton, à faire chaque cycle de setup();
  
};


#endif