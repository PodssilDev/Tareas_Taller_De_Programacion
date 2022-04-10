#include "Node.h"

/* TEST PARA LA CLASE NODO, SE PRUEBAN
Node
get_i
get_j
getPrevious
getValue
isRoot
getPath
print
*/

int main(){
    Node nodo(50, 89, 189, NULL); // TEST NODE

    cout << "Coordenada i: " << nodo.get_i() << endl; // TEST GET_I
    cout << "Coordenada j: " << nodo.get_j() << endl; // TEST GET_J
    if(nodo.getPrevious() == NULL){ // TEST GETPREVIOUS
        cout << "No hay padre" << endl;
    }
    cout << "Valor: " << nodo.getValue() << endl; // TEST TESTVALUE
    if(nodo.isRoot()){   // TEST ISROOT
        cout << "Es raiz!";
    }
    else{
        cout << nodo.getPath() << endl; // TEST GETPATH
    }
    cout << "\n";
    nodo.print(); // TEST PRINT
    return 0;
}
