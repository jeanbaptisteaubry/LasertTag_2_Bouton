#include <Arduino.h>
#include "Button.h"
#include "ButtonInterface.h"

Button bouton1 = Button(12,false );
Button bouton2 = Button(14,false );
Button bouton3 = Button(13,false );
void setup() {
  //Pour initialiser la liaison série :
  Serial.begin(115200);
  Serial.print("Projet Bouton 1.0\n") ;

  
}

void loop() {
  /*
  int millisAct = millis();
  for(int i = 0; i < 10000; i++){
    bouton1.MAJ();
  }
  int delta = millis() - millisAct;
  Serial.printf("delta %d\n", delta);
*/
  bouton1.MAJ();
  bouton1.AfficherDebug();

  bouton2.MAJ();
  bouton2.AfficherDebug();

  bouton3.MAJ();
  bouton3.AfficherDebug();
  
}