// filepath: /Borne_c-_SARDOU_KACI/Borne_c-_SARDOU_KACI/include/baseclient.h
#ifndef BASECLIENT_H
#define BASECLIENT_H

#include <string>

class BaseClient {
public:
    BaseClient();
    ~BaseClient();
    bool authentifier(int numCarte);

private:
    int numeroCarte;
};

#endif // BASECLIENT_H