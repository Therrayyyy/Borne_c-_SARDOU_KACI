// filepath: /Borne_c-_SARDOU_KACI/include/generateur_save.h
#ifndef GENERATEUR_SAVE_H
#define GENERATEUR_SAVE_H

#include <stdio.h>
#include <unistd.h>
#include "donnees_borne.h"
#include "memoire_borne.h"
#include "voyant.h"
#include "prise.h"
#include "bouton.h"
#include "lecteurcarte.h"

class GenerateurSave {
public:
    GenerateurSave();
    ~GenerateurSave();

    void initialiser();
    void generer_pwm(int pwm);
    void contacteur_ouvert();
    void contacteur_ferme();
    void charger();
    int tension();

private:
    entrees *gio;
    int gshmid;
    int state;
    int once;
};

#endif // GENERATEUR_SAVE_H