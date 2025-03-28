#ifndef RF_RECEPTEUR_H
#define RF_RECEPTEUR_H

#include <Arduino.h>

// Paramètres du récepteur
#define rxPin 16                  // Broche de réception RF (DATA)
#define serialVitesse 9600        // Vitesse du port série
#define bitDelay 200              // Délai entre bits (en microsecondes)
#define maxTrameLength 80         // Taille maximale d'une trame

class RfRecepteur {
public:
    RfRecepteur(int pin = rxPin);                // Constructeur
    void initialiser();                          // Préparer la broche RF
    bool recevoirTrame(char* buffer, int tailleMax); // Lire une trame entière

private:
    int pin;
    char lireCaractere();                        // Lire un caractère complet (start + 8 bits + stop)
};

#endif
