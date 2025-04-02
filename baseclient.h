#ifndef BASECLIENT_H
#define BASECLIENT_H

#include <string>

// Classe BaseClient
class BaseClient {
public:
    // Constructeur
    BaseClient();

    // Destructeur
    ~BaseClient();

    // Méthode publique pour authentifier un client
    bool authentifier(int numCarte);

private:
    // Attribut privé pour stocker le numéro de carte
    int numeroCarte;
};

#endif // BASECLIENT_H