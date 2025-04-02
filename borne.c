#include <stdio.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include <unistd.h>

#include "lecteurcarte.h"
#include "voyant.h"
#include "bouton.h"
#include "baseclient.h"
#include "generateur_save.h"
#include "prise.h"

int main()
{
    lecteurcarte_initialiser();
    voyant_initialiser();
    bouton_initialiser();
    generateur_save_initialiser();
    prise_initialiser();
    
    while (1)
    {
        // Attente de l'insertion de la carte
        lecteurcarte_lire_carte();


     }   

    return 0;   
}
