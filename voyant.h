#ifndef VOYANT_H
#define VOYANT_H

#include <stdio.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include <unistd.h>

void voyant_initialiser();
void voyant_set_charge(led state);
void voyant_blink_charge(led state);
void voyant_set_dispo(led state);
void voyant_set_defaut(led state);
void voyant_blink_defaut(led state);

#endif // VOYANT_H
