#include "Node.h"

/* TEST PARA LA CLASE NODO, SE PRUEBAN
Node
getCpu
setCpu
getProcessor
setProcessor
getPrevious
setCost
getCost
isRoot
getPath
print
*/

int main(){
    Node* nodo = new Node(); // TEST NODE
    nodo->setCost(20); // TEST SETCOST
    nodo->setCpu(9); // TEST SETCPU
    nodo->setProcessor(2); // TEST SETPROCESSOR

    cout << "Coordenada i: " << nodo->getCpu() << endl; // TEST GET_I
    cout << "Coordenada j: " << nodo->getProcessor() << endl; // TEST GET_J
    if(nodo->getPrevious() == NULL){ // TEST GETPREVIOUS
        cout << "No hay padre" << endl;
    }
    cout << "Valor: " << nodo->getCost() << endl; // TEST TESTVALUE
    if(nodo->isRoot()){   // TEST ISROOT
        cout << "Es raiz!";
    }
    else{
        cout << nodo->getPath() << endl; // TEST GETPATH
    }
    cout << "\n";
    nodo->print(); // TEST PRINT
    return 0;
}
