#include <iostream>
#include <math.h>
#include "Node.h"
using namespace std;

// "Heap" corresponde a la clase de la Cola de prioridad, la cual se utiliza para 
//  obtener el nodo de menor costo y asi saber cual es la asignacion optima. 
// Heap recibe un tamaño para poder funcionar.

class Heap {
public:
    Heap(int size); // Crea la Heap 
    ~Heap(); // Destruye la heap
    int isEmpty(); // Verifica si la Heap esta vacia
    void insert(Node *node); // Inserta un nodo en la Heap
    Node* pull(); // Saca y elimina de la Heap al nodo de menor valor
    int peek(); // Verifica el nodo de menor valor
    int getSize(); // Obtiene el tamano de la Heap
    void print(); // Imprime la Heap
private:
    Node *arr; // Arreglo que se utiliza para la Heap 
    int size; // Tamano de la heap
    int count; // Permite contar y rapidamente agregar elementos a la heap
    void swap(int i, int j); // Intercambia posiciones de la Heap
    void bubbleUp(); // Permite que ciertos nodos esten sobre otros
    void bubbleDown(); // Permite que ciertos nodos esten bajo otros
};
