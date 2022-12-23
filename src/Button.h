#include <Arduino.h>

#ifndef BUTTON_H
#define BUTTON_H
#define BUTTON_DUREE_ACTION 10 // en ms, durée minimum pour action sur le bouton soit prise en compte

class Button
{
private:
  uint32_t lastMillis;
  uint32_t dureeAction;

public:
  /* data */
  uint8_t PIN;
  uint32_t numberKeyPresses;
  bool actionne; //A true quand le bouton est actionné
  bool actionne1SenCours; //A true quand le bouton est actionné depuis 1 seconde
  bool actionne5SenCours; //A true quand le bouton est actionné depuis 5 secondes

  bool relache; //A true quand le bouton est relaché
  bool relache1S; //A true quand le bouton est relaché depuis 1 seconde
  bool relache5S; //A true quand le bouton est relaché depuis 5 secondes

  
  int etatHaut = HIGH; //Etat logique du bouton quand il est relaché
  Button(uint8_t _PIN); //Constructeur
  Button(uint8_t _PIN, bool modePullUp); //Constructeur avec précision du mode de pullup du bouton. Les boutons sont normalement ouverts ou fermés, il faut donc préciser le mode de pullup
  void MAJ(); //Mise à jour de l'état du bouton, à faire chaque cycle de setup();
  void AfficherDebug(); //Affiche les informations de debug du bouton
  uint32_t DureeEtatEnCours(); //Retourne la durée en ms depuis le dernier changement d'état du bouton
};


#endif