#ifndef GENERATEUR_SAVE_H
#define GENERATEUR_SAVE_H

#include <stdio.h>
#include <unistd.h>
#include <donnees_borne.h>
#include <memoire_borne.h>

#include "voyant.h"
#include "prise.h"
#include "bouton.h"
#include "lecteurcarte.h"

void generateur_save_initialiser();
void generateur_save_generer_pwm(int pwm);
void generateur_save_contacteur_ouvert();
void generateur_save_contacteur_ferme();
void generateur_save_charger();
int generateur_save_tension();

#endif // GENERATEUR_SAVE_H
