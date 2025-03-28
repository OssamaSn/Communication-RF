#include <Arduino.h>
#include "rf_emetteur.h"

// Création de l'objet émetteur
RfEmetteur emetteur;

void setup() {
    Serial.begin(serialVitesse);   // Moniteur série pour debug
    emetteur.initialiser();        // Préparer la broche TX
}

void loop() {
    const char* trame = "Serre,1,1,22.5,55.0;";
    emetteur.envoyerTrame(trame);  // Envoi RF
    delay(2000);                   // Pause de 2 secondes
}
