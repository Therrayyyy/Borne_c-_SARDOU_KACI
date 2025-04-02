#ifndef BOUTON_H
#define BOUTON_H

#include <donnees_borne.h>
#include <memoire_borne.h>
#include <stdio.h>

class Bouton {
public:
    Bouton(); // Déclaration du constructeur
    void bouton_initialiser(); // Déclaration de la méthode bouton_initialiser
    bool appuyer_charge(); // Déclaration de la méthode appuyer_charge
    bool appuyer_stop(); // Déclaration de la méthode appuyer_stop

private:
    entrees *bio; // Pointeur vers la mémoire partagée
    int bshmid; // Identifiant de la mémoire partagée
};

#endif // BOUTON_H