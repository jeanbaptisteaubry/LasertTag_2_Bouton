#include "ButtonInterface.h"
#include <Arduino.h>
#include "ButtonDebug.h"

ButtonDebug::ButtonDebug(uint8_t _PIN, const SimulationEntry *table, size_t size)
    : ButtonInterface(_PIN), simulationTable(table), tableSize(size) {}

ButtonDebug::ButtonDebug(uint8_t _PIN, bool modePullUp, const SimulationEntry *table, size_t size)
    : ButtonInterface(_PIN, modePullUp), simulationTable(table), tableSize(size) {}

void ButtonDebug::MAJ()
{
    // Serial.println("MAJ");
    int etatBouton;
    long millisAct = millis(); // Stocke la valeur de millis() pour éviter de la lire plusieurs fois
    if (currentSimulationIndex >= tableSize)
    {
        etatBouton = LOW;
    }
    else if (currentSimulationIndex == 0)
    {
        if (millisAct < simulationTable[0].time)
            etatBouton = LOW;
        else
        {
            etatBouton = simulationTable[0].etatPin;
            currentSimulationIndex++;
        }
    }
    else if (millisAct >= simulationTable[currentSimulationIndex].time)
    {
        etatBouton = simulationTable[currentSimulationIndex].etatPin;
        currentSimulationIndex++;
    }
    else
        etatBouton = simulationTable[currentSimulationIndex - 1].etatPin;

    // Serial.printf("MAJ %d %d %d %d %d\n", millisAct, currentSimulationIndex, etatBouton, tableSize, simulationTable[currentSimulationIndex].time);
    logicMaj(etatBouton);
}

void ButtonDebug::AfficherDebug()
{
    if (actionne || relache)
        Serial.printf("%d millis %d actioné %d, relache %d, dureeAction %d, act1SenCours %d, act5SenCours %d, relache1S %d, relache5S %d currentSimulationIndex %d\n", millis(), PIN, actionne, relache, DureeEtatEnCours(), actionne1SenCours, actionne5SenCours, relache1S, relache5S, currentSimulationIndex);
}