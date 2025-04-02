#include "bouton.h"

 entrees *bio;
 int bshmid;

void bouton_initialiser() {
    bio = acces_memoire(&bshmid);
    bio->bouton_charge = 0;
    bio->bouton_stop = 0;
    if (bio == NULL) {
        printf("Erreur pas de mem sh\n");
    }
}

int bouton_appuyer_charge() {
    if (bio->bouton_charge == 1)
        return 1;
    else
        return 0;
}

int bouton_appuyer_stop() {
    if (bio->bouton_stop == 1)
        return 1;
    else
        return 0;
}