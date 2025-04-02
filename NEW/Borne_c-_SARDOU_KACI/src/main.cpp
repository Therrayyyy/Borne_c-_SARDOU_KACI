#include <iostream>
#include "lecteurcarte.h"
#include "voyant.h"
#include "bouton.h"
#include "generateur_save.h"
#include "prise.h"
#include "baseclient.h"

int main()
{
    LecteurCarte lecteurcarte;
    Voyant voyant;
    Bouton bouton;
    GenerateurSave generateurSave;
    Prise prise;

    lecteurcarte.initialiser();
    voyant.initialiser();
    bouton.initialiser();
    generateurSave.initialiser();
    prise.initialiser();

    while (true)
    {
        lecteurcarte.lire_carte();
    }

    return 0;
}