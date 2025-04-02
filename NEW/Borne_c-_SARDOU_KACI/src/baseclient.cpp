// filepath: /Borne_c-_SARDOU_KACI/src/baseclient.cpp
#include "baseclient.h"

BaseClient::BaseClient() {
    // Constructor implementation
}

BaseClient::~BaseClient() {
    // Destructor implementation
}

bool BaseClient::authentifier(int numCarte) {
    int clients[] = {11, 5};
    for (int i = 0; i < 2; i++) {
        if (numCarte == clients[i]) {
            return true;
        }
    }
    return false;
}