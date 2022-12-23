#include <Arduino.h>
#include "Button.h"


Button bouton1 = Button(12,false );
void setup() {
  //Pour initialiser la liaison série :
  Serial.begin(115200);
  Serial.print("Projet Bouton 1.0\n") ;

  
}

void loop() {
  bouton1.MAJ();
  bouton1.AfficherDebug();
  /*
  if (bouton1.actionne == true)
  {
    Serial.printf("Bouton actionne %d\n", bouton1.numberKeyPresses);
  }

  if (bouton1.actionne1SenCours == true)
  {
    Serial.printf("Bouton actionne depuis 1 seconde %d\n", bouton1.numberKeyPresses);
  }

  if (bouton1.actionne5SenCours == true)
  {
    Serial.printf("Bouton actionne depuis 5 secondes %d\n", bouton1.numberKeyPresses);
  }

  if(bouton1.relache == true)
  {
    Serial.printf("Bouton relaché %d\n", bouton1.numberKeyPresses);
  }

  if(bouton1.relache1S == true)
  {
    Serial.printf("Bouton relaché depuis 1 seconde %d\n", bouton1.numberKeyPresses);
  }

  if(bouton1.relache5S == true)
  {
    Serial.printf("Bouton relaché depuis 5 secondes %d\n", bouton1.numberKeyPresses);
  }*/
  // put your main code here, to run repeatedly:
}