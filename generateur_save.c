#include "generateur_save.h"

entrees *gio;
int gshmid;
int state = 0;
extern int cardnumber;
int once=1;

void generateur_save_initialiser() {
    gio = acces_memoire(&gshmid);
    if (gio == NULL) {
        printf("Erreur pas de mem sh\n");
    }
        gio->gene_pwm = STOP;
}

void generateur_save_generer_pwm(int pwm) {
    gio->gene_pwm = pwm;
}

void generateur_save_contacteur_ouvert() {
    gio->contacteur_AC = 0;
}

void generateur_save_contacteur_ferme() {
    gio->contacteur_AC = 1;
}

int generateur_save_tension() {
    return gio->gene_u;
}
void generateur_save_charger() {
    while (1) {
        switch (state) {
            case 0: // Etat A: véhicule électrique non connecté
                voyant_set_charge(ROUGE);
                prise_deverouiller_trappe();
                generateur_save_generer_pwm(DC); // le générateur SAVE fournit une tension de + 12V 
                if (generateur_save_tension() == 9) {
                    state = 1;
                }
                break;
            case 1: // Etat B: véhicule électrique connecté, système d'alimentation non disponible
                prise_set_prise(VERT); // Véhicule électrique connecté, la prise est branchée
                prise_verouiller_trappe();
                generateur_save_contacteur_ouvert();
                if (generateur_save_tension() == 9) {
                    state = 2;
                }
                break;
            case 2: // Etat C: véhicule électrique connecté, système d'alimentation disponible
                generateur_save_generer_pwm(AC_1K);
                generateur_save_contacteur_ferme();
                if (generateur_save_tension() == 6) {
                    //lecteurcarte_initialiser();
                    state = 3;
                }
                break;
            case 3: // Etat D: S2 fermé, tension chute à 6V, batterie en charge
                generateur_save_generer_pwm(AC_CL);
                if (bouton_appuyer_stop()){
                    printf("Inserez votre carte pour interrompre la charge\n");
                    attente_insertion_carte();
                    if (carte_inseree()) {
                        if (lecture_numero_carte()==cardnumber) {
                            printf("Connexion réussie !\nCharge interrompue \n");
                            printf("Vous pouvez debrancher la prise \n");
                            generateur_save_contacteur_ouvert();
                            generateur_save_generer_pwm(DC);
                            voyant_set_charge(VERT);
                            prise_deverouiller_trappe();
                            once=0;
                            state=4;
                        }
                        else {
                            printf("Mauvais identifiant (%d), reprise de la charge\n",lecture_numero_carte());
                            voyant_blink_defaut(ROUGE);
                        }
                    }
                    else {
                    printf("Mauvaise carte!");
                    }
                }
                else if (generateur_save_tension() == 9) {
                    //lecteurcarte_initialiser();
                    printf("Veuillez re-insérer votre carte\n");
                    state = 4;
                    break;
                }      	
                break;        
            case 4: // Etat E: batterie chargée, S2 ouvert
                generateur_save_contacteur_ouvert();
                generateur_save_generer_pwm(DC);
                voyant_set_charge(VERT);
                attente_insertion_carte();
                if (once){
                    if (carte_inseree()) {
                            if (lecture_numero_carte()==cardnumber) {
                                printf("Connexion réussie !\nVous pouvez debrancher la prise \n");
                                prise_deverouiller_trappe();
                            }
                            else {
                                printf("Mauvais identifiant (%d), connexion échouée\n",lecture_numero_carte());
                                voyant_blink_defaut(ROUGE);
                            }
                        }
                        else 
                        printf("Mauvaise carte!");
                        once=0;
                    }
                
                if (generateur_save_tension() == 12) {                    
                    state = 5;
                    printf("Vous pouvez reprendre votre vehicule");
                }
                break;
            case 5: // Etat F: retour à 12V, prise déconnectée
                prise_set_prise(OFF);
                voyant_set_charge(OFF);
                voyant_set_dispo(VERT);
                prise_verouiller_trappe();
                generateur_save_generer_pwm(STOP);
                
                break;
        }
    }
}
