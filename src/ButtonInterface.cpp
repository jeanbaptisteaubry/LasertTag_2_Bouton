#include <Arduino.h>
#include "ButtonInterface.h"

ButtonInterface::ButtonInterface(uint8_t _PIN)
{
    PIN = _PIN;
    numberKeyPresses = 0;
    actionne = false;
    relache = true;
    pinMode(PIN, INPUT_PULLUP);
    dureeAction = 0;
}

ButtonInterface::ButtonInterface(uint8_t _PIN, bool modePullUp)
{
    PIN = _PIN;
    numberKeyPresses = 0;
    actionne = false;
    relache = true;
    pinMode(PIN, INPUT_PULLUP);
    if (modePullUp == true)
        // pinMode(PIN, INPUT_PULLUP);
        etatHaut = HIGH;
    else
        etatHaut = 0x0;
    // pinMode(PIN, INPUT_PULLDOWN);
    dureeAction = 0;
}

void ButtonInterface::logicMaj(int etatBouton)
{
    u_long millisAct = millis(); // Stocke la valeur de millis() pour éviter de la lire plusieurs fois

    if (etatBouton == etatHaut) // Teste si le bouton a un niveau logique HAUT
    {
        if (actionne == false)
        {
            actionne = true;
            relache = false;
            relache1S = false;
            relache5S = false;

            numberKeyPresses++;
            appuiConsomme = false;
            lastMillis = millisAct;
        }
        else
        {
            // L'action est en cours et l'on va détecter depuis combien de temps
            if (millisAct - lastMillis > 1000)
                actionne1SenCours = true;
            if (millisAct - lastMillis > 5000)
                actionne5SenCours = true;
        }
        // Serial.printf("etatBouton %d\n", etatBouton);
    }
    else // test si le bouton a un niveau logique différent de HAUT (donc BAS)
    {
        if (actionne == true)
        {
            actionne = false;
            actionne1SenCours = false;
            actionne5SenCours = false;
            dureeAction = millisAct - lastMillis;

            lastMillis = millisAct;
            if (dureeAction > BUTTON_DUREE_ACTION)
            {
                relache = true;
                if (dureeAction > 1000)
                    relache1S = true;
                if (dureeAction > 5000)
                    relache5S = true;
            }
            else
                numberKeyPresses--;
        }
        else
        {
            relache = false;
            relache1S = false;
            relache5S = false;
        }
    }
}

uint32_t ButtonInterface::DureeEtatEnCours()
{
    return millis() - lastMillis;
}

void ButtonInterface::AfficherDebug()
{
    if (actionne || relache)
        Serial.printf("%d actioné %d, relache %d, dureeAction %d, act1SenCours %d, act5SenCours %d, relache1S %d, relache5S %d \n", PIN, actionne, relache, DureeEtatEnCours(), actionne1SenCours, actionne5SenCours, relache1S, relache5S);
}

bool ButtonInterface::consommeAppui()
{
    if(appuiConsomme == false && actionne == true)
    {
        appuiConsomme = true;
        return true;
    }
    return false;
}
