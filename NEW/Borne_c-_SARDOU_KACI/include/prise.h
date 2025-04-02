// filepath: /Borne_c-_SARDOU_KACI/include/prise.h
#ifndef PRISE_H
#define PRISE_H

#include <stdio.h>
#include <unistd.h>
#include "donnees_borne.h"
#include "memoire_borne.h"

class Prise {
public:
    Prise();
    void initialiser();
    void set_prise(led state);
    void deverouiller_trappe();
    void verouiller_trappe();

private:
    entrees *pio;
    int pshmid;
};

#endif // PRISE_H