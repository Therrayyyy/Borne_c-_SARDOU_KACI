#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H
#include <lcarte.h>
#include <unistd.h>
#include <stdio.h>
#include "baseclient.h"
#include <stdlib.h>
#include <string.h>

#include "voyant.h"
#include "bouton.h"
#include "prise.h"
#include "generateur_save.h"

void lecteurcarte_initialiser();
void lecteurcarte_lire_carte();
void lecteurcarte_retirer_carte();

#endif // LECTEURCARTE_H
