// filepath: /Borne_c-_SARDOU_KACI/Borne_c-_SARDOU_KACI/src/generateur_save.cpp
#include "generateur_save.h"
#include "voyant.h"
#include "prise.h"
#include "bouton.h"
#include "lecteurcarte.h"
#include <iostream>

entrees *gio;
int gshmid;
int state = 0;
extern int cardnumber;
int once = 1;

GenerateurSave::GenerateurSave() {
    gio = acces_memoire(&gshmid);
    if (gio == NULL) {
        std::cerr << "Erreur : pas de mémoire partagée pour le générateur." << std::endl;
    }
}

void GenerateurSave::generer_pwm(int pwm) {
    gio->gene_pwm = static_cast<pwm>(pwm); // Cast explicite vers le type pwm
}

void GenerateurSave::contacteur_ouvert() {
    gio->contacteur = 0;
}

void GenerateurSave::contacteur_ferme() {
    gio->contacteur = 1;
}

int GenerateurSave::tension() {
    return gio->tension;
}

void GenerateurSave::charger() {
    Voyant voyant;
    Prise prise;
    Bouton bouton;

    while (true) {
        switch (state) {
            case 0:
                voyant.set_charge(ROUGE);
                prise.deverouillerTrappe();
                generer_pwm(DC);
                if (tension() == 9) {
                    state = 1;
                }
                break;

            case 1:
                prise.setPrise(VERT); // Véhicule connecté, prise branchée
                prise.verouillerTrappe();
                contacteur_ferme();
                voyant.set_charge(VERT);
                state = 2;
                break;

            case 2:
                if (bouton.appuyer_stop()) {
                    contacteur_ouvert();
                    generer_pwm(DC);
                    voyant.set_charge(OFF);
                    state = 3;
                }
                break;

            case 3:
                voyant.set_dispo(VERT);
                prise.deverouillerTrappe();
                state = 4;
                break;

            case 4:
                LecteurCarte lecteurCarte;
                lecteurCarte.attente_insertion_carte();
                if (lecteurCarte.carte_inseree()) {
                    if (lecteurCarte.lecture_numero_carte() == cardnumber) {
                        std::cout << "Connexion réussie ! Vous pouvez débrancher la prise." << std::endl;
                        prise.deverouillerTrappe();
                        state = 0;
                    }
                }
                break;
        }
    }
}