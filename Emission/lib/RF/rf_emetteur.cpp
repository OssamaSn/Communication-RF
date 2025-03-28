#include "rf_emetteur.h"

// Constructeur : on garde le numéro de la broche
RfEmetteur::RfEmetteur(int pin) {
    this->pin = pin;
}

// Initialisation de la broche en sortie
void RfEmetteur::initialiser() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);  // À l'état haut au repos (UART)
}

// Envoi d'une trame complète (ex : "Serre,1,1,22.5,55.0;")
void RfEmetteur::envoyerTrame(const char* trame) {
    const char* copie = trame; // Pour afficher la trame ensuite

    while (*trame) {
        envoyerCaractere(*trame);
        trame++;
    }

    Serial.print("Trame envoyée : ");
    Serial.println(copie); // Affichage dans le moniteur série
}

// Envoi d'un caractère en UART manuel (start bit, 8 bits, stop bit)
void RfEmetteur::envoyerCaractere(char caractere) {
    // Start bit (LOW)
    digitalWrite(pin, LOW);
    delayMicroseconds(bitDelay);

    // 8 bits de données 
    for (int i = 0; i < 8; i++) {
        bool bit = (caractere >> i) & 0x01;
        digitalWrite(pin, bit ? HIGH : LOW);
        delayMicroseconds(bitDelay);
    }

    // Stop bit (HIGH)
    digitalWrite(pin, HIGH);
    delayMicroseconds(bitDelay);
}
