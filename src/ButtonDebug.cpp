#include "ButtonInterface.h"
#include <Arduino.h>
#include "ButtonDebug.h"


ButtonDebug::ButtonDebug(uint8_t _PIN, const SimulationEntry* table, size_t size) 
    : ButtonInterface(_PIN), simulationTable(table), tableSize(size) { }

ButtonDebug::ButtonDebug(uint8_t _PIN, bool modePullUp, const SimulationEntry* table, size_t size) 
    : ButtonInterface(_PIN, modePullUp), simulationTable(table), tableSize(size) { }


void ButtonDebug::MAJ()
{
    int etatBouton;
  if(currentSimulationIndex >= tableSize) {
    etatBouton = LOW;
  }
  else if(currentSimulationIndex == 0) {
     if(millis() >= simulationTable[0].time)
     etatBouton = LOW;
  }
  else if(millis() >= simulationTable[currentSimulationIndex].time) {
    etatBouton = simulationTable[currentSimulationIndex].etatPin;
    currentSimulationIndex++;
  } 
  logicMaj(etatBouton);
}