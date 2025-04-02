#include "bouton.h"

entrees *bio;
int bshmid;

Bouton::Bouton() {
    bouton_initialiser();
}

void Bouton::bouton_initialiser() {
    bio = acces_memoire(&bshmid);
    bio->bouton_charge = 0;
    bio->bouton_stop = 0;
    if (bio == NULL) {
        printf("Erreur pas de mem sh\n");
    }
}

bool Bouton::appuyer_charge() {
    return bio->bouton_charge == 1;
}

bool Bouton::appuyer_stop() {
    return bio->bouton_stop == 1;
}