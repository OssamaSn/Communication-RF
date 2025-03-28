#ifndef RF_EMETTEUR_H
#define RF_EMETTEUR_H

#include <Arduino.h>

// Paramètres de l'émetteur
#define txPin 17                // Broche de transmission RF
#define serialVitesse 9600      // Vitesse du port série
#define bitDelay 200            // Délai entre bits (en microsecondes)

class RfEmetteur {
public:
    RfEmetteur(int pin = txPin);            // Constructeur
    void initialiser();                     // Préparer la broche TX
    void envoyerTrame(const char* trame);   // Envoyer une trame complète

private:
    int pin;
    void envoyerCaractere(char caractere);  // Envoyer un caractère bit à bit
};

#endif
