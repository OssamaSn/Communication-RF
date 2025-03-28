#include "rf_recepteur.h"

// Constructeur : on garde le numéro de la broche
RfRecepteur::RfRecepteur(int pin) {
    this->pin = pin;
}

// Initialisation : la broche RF est en lecture
void RfRecepteur::initialiser() {
    pinMode(pin, INPUT);
}

// Lire un caractère transmis en série (bit-banging)
char RfRecepteur::lireCaractere() {
    // Attendre le bit de départ (start bit = LOW)
    while (digitalRead(pin) == HIGH);

    // Aller au milieu du premier bit
    delayMicroseconds(bitDelay + bitDelay / 2);

    char caractere = 0;

    // Lire 8 bits de données
    for (int i = 0; i < 8; i++) {
        bool bit = digitalRead(pin);
        caractere |= (bit << i);  // On place le bit au bon endroit
        delayMicroseconds(bitDelay);
    }

    // Lire le stop bit (on attend simplement)
    delayMicroseconds(bitDelay);

    return caractere;
}

// Lire une trame complète (jusqu'au caractère ';')
bool RfRecepteur::recevoirTrame(char* buffer, int tailleMax) {
    int index = 0;

    while (index < tailleMax - 1) {
        char c = lireCaractere();
        buffer[index++] = c;

        if (c == ';') {
            break;  // Fin de trame détectée
        }
    }

    buffer[index] = '\0'; // Fin de chaîne (important pour Serial.println)
    return true;
}
