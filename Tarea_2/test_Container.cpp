#include "Container.h"

// Test para Container, se prueban:
// Container
// insert
// print

int main(){
    int n = 10;
    Container* matriz = new Container(n); // TEST Container

    matriz->insert(4,8); // TEST INSERT
    matriz->insert(3,2); // TEST INSERT
    matriz->insert(1,0); // TEST INSERT
    matriz->insert(9,6); // TEST INSERT
    matriz->insert(5,5); // TEST INSERT
    
    matriz->print(); // TEST PRINT
    return 0;

}
