#include "prise.h"

 entrees *pio;
 int pshmid;

void prise_initialiser() {
    pio = acces_memoire(&pshmid);
    pio->led_prise = OFF;
    pio->led_trappe = OFF;
    if (pio == NULL) {
        printf("Erreur pas de mem sh\n");
    }
}

void prise_set_prise(led state) {
    pio->led_prise = state;
}

void prise_deverouiller_trappe() {
    pio->led_trappe = VERT;
}

void prise_verouiller_trappe() {
    pio->led_trappe = OFF;
}
