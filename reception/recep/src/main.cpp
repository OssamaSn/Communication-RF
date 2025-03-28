#include <Arduino.h>
#include "rf_recepteur.h"

// Création de l'objet récepteur avec la broche GPIO 16
RfRecepteur recepteur;

void setup() {
    Serial.begin(serialVitesse);   // Initialisation de la liaison série
    recepteur.initialiser();       // Préparation de la broche RF
}

void loop() {
    char message[maxTrameLength]; // Buffer pour stocker la trame reçue

    // Lire une trame RF et l'afficher si elle est complète
    if (recepteur.recevoirTrame(message, sizeof(message))) {
        Serial.print("Trame reçue : ");
        Serial.println(message);
    }

    delay(200); // Petite pause entre les lectures
}
