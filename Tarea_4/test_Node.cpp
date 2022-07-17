#include "Node.h"

/*
TEST PARA LA CLASE Node, SE PRUEBAN LOS SIGUIENTES METODOS DE LA CLASE
Node()
get_i()
set_i()
getValue()
setValue()
print()
~Node()
*/

int main(){
    int i, value; 
    Node* nodo = new Node(); // TEST Node()
    cout << "Nodo creado con valores por defecto" << endl;
    nodo->print(); // TEST print()
    cout << "Ingrese el numero del nodo: ";
    cin >> i;
    cout << "Ingrese el valor del nodo: ";
    cin >> value;
    nodo->set_i(i); // TEST set_i() 
    nodo->setValue(value); // TEST setValue()
    cout << "Numero de nodo asociado: " << nodo->get_i() << endl; // TEST get_i()
    cout << "Numero de conexiones con otros nodos:  " << nodo->getValue() << endl; // TEST getValue()
    cout << "\n";
    cout << "Imprimiendo nodo: " << endl;
    nodo->print(); // TEST PRINT
    nodo->~Node(); // TEST ~Node()
    return 0;
}
