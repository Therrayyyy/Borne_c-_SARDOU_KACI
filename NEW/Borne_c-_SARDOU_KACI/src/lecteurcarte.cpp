#include "lecteurcarte.h"
#include "baseclient.h"
#include "voyant.h"
#include "bouton.h"
#include "generateur_save.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

int cardnumber;

LecteurCarte::LecteurCarte() {
    // Constructor implementation if needed
}

void LecteurCarte::initialiser() {
    initialisations_ports();
}

void LecteurCarte::lire_carte() {
    int i;
    system("clear");
    std::cout << "Veuillez insérer votre carte" << std::endl;
    attente_insertion_carte();
    if (carte_inseree()) {
        cardnumber = lecture_numero_carte();
        std::cout << "Votre identifiant : " << cardnumber << std::endl;
        BaseClient client;
        if (client.authentifier(cardnumber)) {
            std::cout << "Authentification réussie !" << std::endl;
            voyant_blink_charge(VERT);
            std::cout << "\nRetirez votre carte !\nVous avez une minute pour appuyer sur le bouton charge" << std::endl;
            for (i = 0; i < 60; i++) {
                sleep(1);
                if (bouton_appuyer_charge()) {
                    voyant_set_dispo(OFF);
                    retirer_carte();
                    generateur_save_charger();
                } 
            }
            if (i == 60) {
                std::cout << "Temps écoulé" << std::endl;
                i = 0;
            } else {
                std::cout << "\nEn cours de charge ..." << std::endl;
            }
        } else {
            std::cout << "Authentification échouée, vous n'etes pas client" << std::endl;
            voyant_blink_defaut(ROUGE);
        }
    }
}

void LecteurCarte::retirer_carte() {
    //std::cout << "N'oubliez pas de reprendre votre carte !" << std::endl;
    attente_retrait_carte();
    //liberation_ports();
}