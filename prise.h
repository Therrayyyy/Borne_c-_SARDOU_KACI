#ifndef PRISE_H
#define PRISE_H
#include <stdio.h>
#include <unistd.h>
#include <donnees_borne.h>
#include <memoire_borne.h>


void prise_initialiser();
void prise_set_prise(led state);
void prise_deverouiller_trappe();
void prise_verouiller_trappe();

#endif // PRISE_H