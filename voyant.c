#include "voyant.h"

 entrees *vio;
 int vshmid;

void voyant_initialiser()
{
    vio = acces_memoire(&vshmid);
    if (vio == NULL) {
        printf("Erreur pas de mem sh\n");
    }
    vio->led_charge = OFF;
    vio->led_dispo = VERT;
    vio->led_defaut = OFF;

}

void voyant_set_charge(led state)
{
    if (vio != NULL) {
        vio->led_charge = state;
    }
}

void voyant_blink_charge(led state)
{
    if (vio != NULL) {
        for (int i = 0; i < 8; i++) {
            vio->led_charge = state;
            usleep(500000); // 500 ms
            vio->led_charge = OFF;
            usleep(500000); // 500 ms
        }
    }
}

void voyant_set_dispo(led state)
{
    if (vio != NULL) {
        vio->led_dispo = state;
    }
}

void voyant_set_defaut(led state)
{
    if (vio != NULL) {
        vio->led_defaut = state;
    }
}

void voyant_blink_defaut(led state)
{
    if (vio != NULL) {
        for (int i = 0; i < 8; i++) {
            vio->led_defaut = state;
            usleep(500000); // 500 ms
            vio->led_defaut = OFF;
            usleep(500000); // 500 ms
        }
    }
}