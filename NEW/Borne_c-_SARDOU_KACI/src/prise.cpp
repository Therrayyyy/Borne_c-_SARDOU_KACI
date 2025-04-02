// filepath: /Borne_c-_SARDOU_KACI/Borne_c-_SARDOU_KACI/src/prise.cpp
#include "prise.h"

Prise::Prise() {
    pio = acces_memoire(&pshmid);
    pio->led_prise = OFF;
    pio->led_trappe = OFF;
    if (pio == NULL) {
        printf("Erreur pas de mem sh\n");
    }
}

void Prise::setPrise(led state) {
    pio->led_prise = state;
}

void Prise::deverouillerTrappe() {
    pio->led_trappe = VERT;
}

void Prise::verouillerTrappe() {
    pio->led_trappe = OFF;
}