// filepath: /Borne_c-_SARDOU_KACI/include/voyant.h
#ifndef VOYANT_H
#define VOYANT_H

#include <iostream>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include <unistd.h>

class Voyant {
public:
    Voyant();
    void initialiser();
    void set_charge(led state);
    void blink_charge(led state);
    void set_dispo(led state);
    void set_defaut(led state);
    void blink_defaut(led state);

private:
    entrees *vio;
    int vshmid;
};

#endif // VOYANT_H