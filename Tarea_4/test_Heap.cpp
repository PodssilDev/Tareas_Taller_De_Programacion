#include "Heap.h"

/*
TEST PARA LA CLASE Heap, SE PRUEBAN LAS SIGUIENTES FUNCIONALIDADES PUBLICAS: 
Heap()
getSize()
insert()
print()
peek()
pull()
isEmpty()
~Heap()
Interamente se prueban swap(), bubbleup() y bubbledown()
*/

int main() {
    int n=20;
    srand(time(NULL));
    Heap h(n); // TEST Heap()
    cout << "Tamano de la Heap: " << h.getSize() <<endl; // TEST getSize()
    bool assignedArray[n] = {false};
    // Insertamos numeros aleatorios
    for(int i = 0; i < n; i++) {
        int val=rand()%n;
        Node *node = new Node();
        node->setValue(val);
        cout<<"inserting "<<val<<endl;
        h.insert(node); // TEST insert()
        delete node;
    }
    // Vamos a imprimir la Heap
    cout << "Contenido de la Heap: " <<endl;
    h.print(); // TEST print()
    cout << "Cabeza actual de la Heap: " << h.peek()<< endl; // TEST peek()
    // Extraemos uno por uno los elementos de la Heap
    cout << "Extrayendo por orden: " << endl;
    for(int i=0;i<n; i++){
        Node *node = h.pull(); // TEST pull()
        cout<<"Extrayendo "<<node->getValue()<<endl;
    }
    if(h.isEmpty()){ // TEST isEmpty()
        cout << "La Heap se ha vaciado!";
    }
    cout << "\n";
    return 0;
}
