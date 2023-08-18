#include <Arduino.h>
#include "Button.h"
#include "ButtonInterface.h"
#include "ButtonDebug.h"

#ifndef DEBUG
#define DEBUG 1
#endif

#if DEBUG
ButtonDebug::SimulationEntry bouton1Table[] = {
    {1000, HIGH},
    {2000, LOW},
    {3000, HIGH},
    {4000, LOW},
    {5000, HIGH},
    {6000, LOW}};

ButtonDebug bouton1(12, bouton1Table, sizeof(bouton1Table) / sizeof(bouton1Table[0]));

#else
Button bouton1 = Button(12, false);
Button bouton2 = Button(14, false);
Button bouton3 = Button(13, false);
#endif
void setup()
{
  // Pour initialiser la liaison série :
  Serial.begin(115200);
  Serial.print("Projet Bouton 1.0\n");
}

void loop()
{
  /*
  int millisAct = millis();
  for(int i = 0; i < 10000; i++){
    bouton1.MAJ();
  }
  int delta = millis() - millisAct;
  Serial.printf("delta %d\n", delta);
*/
#if DEBUG
  bouton1.MAJ();
  bouton1.AfficherDebug();
#else
  bouton1.MAJ();
  bouton1.AfficherDebug();

  bouton2.MAJ();
  bouton2.AfficherDebug();

  bouton3.MAJ();
  bouton3.AfficherDebug();
#endif
  delay(15);
}