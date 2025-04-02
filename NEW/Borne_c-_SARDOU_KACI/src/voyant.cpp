// filepath: /Borne_c-_SARDOU_KACI/Borne_c-_SARDOU_KACI/src/voyant.cpp
#include "voyant.h"

entrees *vio;
int vshmid;

Voyant::Voyant() {
    vio = acces_memoire(&vshmid);
    if (vio == NULL) {
        printf("Erreur pas de mem sh\n");
    }
    vio->led_charge = OFF;
    vio->led_dispo = VERT;
    vio->led_defaut = OFF;
}

void Voyant::set_charge(led state) {
    if (vio != NULL) {
        vio->led_charge = state;
    }
}

void Voyant::blink_charge(led state) {
    if (vio != NULL) {
        for (int i = 0; i < 8; i++) {
            vio->led_charge = state;
            usleep(500000); // 500 ms
            vio->led_charge = OFF;
            usleep(500000); // 500 ms
        }
    }
}

void Voyant::set_dispo(led state) {
    if (vio != NULL) {
        vio->led_dispo = state;
    }
}

void Voyant::set_defaut(led state) {
    if (vio != NULL) {
        vio->led_defaut = state;
    }
}

void Voyant::blink_defaut(led state) {
    if (vio != NULL) {
        for (int i = 0; i < 8; i++) {
            vio->led_defaut = state;
            usleep(500000); // 500 ms
            vio->led_defaut = OFF;
            usleep(500000); // 500 ms
        }
    }
}