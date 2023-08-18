#ifndef BUTTONDEBUG_h
#define BUTTONDEBUG_h
#include "ButtonInterface.h"
#include <Arduino.h>

 


class ButtonDebug : public ButtonInterface
{
private:
  /* data */
    

   
    size_t tableSize; 
    int currentSimulationIndex = 0;
public:
    struct SimulationEntry {
        uint32_t time;  // Temps (en millis) pour ce changement
        int etatPin;    // Etat du pin à ce moment
    };
     const SimulationEntry* simulationTable;
    ButtonDebug(uint8_t _PIN, const SimulationEntry* table, size_t size);
    ButtonDebug(uint8_t _PIN, bool modePullUp, const SimulationEntry* table, size_t size);
  void MAJ() override; //Mise à jour de l'état du bouton, à faire chaque cycle de setup();
    void AfficherDebug() override; //Mise à jour de l'état du bouton, à faire chaque cycle de setup();
    
    };

#endif