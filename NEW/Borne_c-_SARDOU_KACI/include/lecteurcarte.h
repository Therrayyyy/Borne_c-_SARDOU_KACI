// filepath: /Borne_c-_SARDOU_KACI/include/lecteurcarte.h
#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H

#include <string>
#include "baseclient.h"
#include "voyant.h"
#include "bouton.h"
#include "prise.h"
#include "generateur_save.h"

class LecteurCarte {
public:
    LecteurCarte();
    ~LecteurCarte();

    void initialiser();
    void lire_carte();
    void retirer_carte();

private:
    int cardnumber;
};

#endif // LECTEURCARTE_H