#include "lecteurcarte.h"

 int cardnumber;

void lecteurcarte_initialiser()
{
    initialisations_ports();
}

void lecteurcarte_lire_carte() {
    int i;
    system("clear");
    printf("Veuillez insérer votre carte\n");
    attente_insertion_carte();
    if (carte_inseree()) {
        cardnumber = lecture_numero_carte();
        printf("Votre identifiant : %d\n", cardnumber);
        if (baseclient_authentifier(cardnumber)) {
            printf("Authentification réussie !\n");
            voyant_blink_charge(VERT);
            printf("\nRetirez votre carte !\nVous avez une minute pour appuyer sur le bouton charge\n");
            for (i = 0; i < 60; i++) {
                sleep(1);
                if (bouton_appuyer_charge()) {
                    voyant_set_dispo(OFF);
                    lecteurcarte_retirer_carte();
                    generateur_save_charger();
                } 
            }
            if (i == 60) {
                printf("Temps écoulé\n");
                i = 0;
            }
            else {
                printf("\nEn cours de charge ...");
            }
        }
        else {
            printf("Authentification échouée, vous n'etes pas client\n");
            voyant_blink_defaut(ROUGE);
        }
    }
}
        

void lecteurcarte_retirer_carte() {
    //printf("N'oubliez pas de reprendre votre carte !\n");
    attente_retrait_carte();
    //liberation_ports();
}
