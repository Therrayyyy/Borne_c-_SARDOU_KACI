#include <baseclient.h>

int baseclient_authentifier(int numcarte) {
    int clients[] ={11,5};
    for (int i=0;i<2;i++){
        if (numcarte==clients[i])
        {
            return 1;
            break;
        }
    }
    return 0;
}
