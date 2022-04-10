#include "Container.h"

// Test para Container, se prueban:
// Container
// insert
// clfind

int main(){
    int n = 44;
    Container matriz(n); // TEST CONTAINER

    matriz.insert(4,8); // TEST INSERT
    
    if(matriz.clfind(4,8)){ // TEST CLFIND
        cout << "4,8 esta marcado en Container!" << endl;
    }
    if (matriz.clfind(8, 5)){
        cout << "It's a secret to everybody" << endl;
    }
    return 0;

}
