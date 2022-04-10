#include "Heap.h"

// "Heap" corresponde a la clase de la Cola de prioridad, la cual se utiliza como
// "Open list" para asi poder saber que nodos son por visitar. Heap recibe un 
// tamaño para poder funcionar.

// Metodo que crea la Heap. Recibe un tamaño en especifico paa su creacion
Heap::Heap(int size) {
    Heap::size = size;
    count = 0;
    arr = new Node[size];
}

// Metodo que destruye la Heap
Heap::~Heap() {
    delete[] arr;
}

// Metodo que obtiene el tamaño de la Heap
int Heap::getSize() {
    return size;
}

// Metodo que inserta un nodo en la Heap. Para ello, recibe un nodo como entrada.
// Cabe destacar de que internamente, la Heap ordena los nodos dependiendo del valor
// que tenga este. Si la heap ya esta llena muestra un mensaje.
void Heap::insert(Node *node) {
    if (count == size) {
        cout << "Heap is full" << endl;
        return;
    }
    arr[count] = *node; // Notice: copy the node
    count++;
    bubbleUp();
}

// Metodo que verifica si es que la Heap esta vacia.
int Heap::isEmpty() {
    return count == 0;
}

// Metodo que permite revisar el primer elemento de la Heap.
int Heap::peek() {
    if (isEmpty()) {
        cout << "Heap is empty" << endl;
        return(-1);
    }
    return arr[0].getValue();
}

// Metodo que imprime la Heap, en forma de arbol.
// printing by levels
void Heap::print() {
/* 
    a: index of the level in the heap. Root is at level 0.
    b: index of the column in the level. Root is at column 0.
    k: index of the node in the heap.
    (1<<a) = 2^a. Each row has 2^a nodes.
    (1<<a)-1 + b is the index of the node in the heap.
    k = (1<<a)-1 + b
    The height of the heap is log2(count)=log(count)/log(2).
*/
    int h = (int)(log(count)/log(2));
    
    for(int a=0;a <= h;a++){
        for(int b=0;b<(1<<a) && ((1<<a)-1+b)<count;b++){
            int k=(1<<a)-1+b;
            cout<<arr[k].getValue()<<" ";
        }
        cout << endl;
    }
}

// Metodo que saca el elemento con el menor tamaño de la Heap y lo borra de esta.
Node* Heap::pull() {
    if (isEmpty()) {
        cout << "Heap is empty" << endl;
        return NULL;
    }
    Node *node = new Node(arr[0]);
    arr[0] = arr[count - 1];
    count--;
    bubbleDown();
    return node;
}

// Metodo que intercambia posiciones de la Heap.
void Heap::swap(int i, int j) {
    Node temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Metodo que permite que ciertos nodos queden sobre otros nodos
void Heap::bubbleUp(){
    int index = count - 1;
    int parentIndex =  (index - 1) / 2;
    while (index > 0 &&
        parentIndex >= 0 && 
        arr[index].getValue() < arr[parentIndex].getValue()) {
        swap(index, parentIndex);
        index = parentIndex;
        parentIndex =  (index - 1) / 2;
    }
}

// Metodo que permite que ciertos nodos queden bajo otros nodos
void Heap::bubbleDown(){
    int index = 0;
    int leftChildIndex = 1;
    int rightChildIndex = 2;
    while (leftChildIndex < count) {
        // Find the largest child for swapping
        if (arr[leftChildIndex].getValue() < arr[index].getValue() || 
            arr[rightChildIndex].getValue() < arr[index].getValue()) {
            if (arr[leftChildIndex].getValue() < arr[rightChildIndex].getValue()) {
                swap(index, leftChildIndex);
                index = leftChildIndex; // Move to the left child
            } else {
                swap(index, rightChildIndex);
                index = rightChildIndex; // Move to the right child
            }
            // Update the child index
            leftChildIndex = index * 2 + 1;
            rightChildIndex = index * 2 + 2;        
        } else {
            break; // no need to bubble down
        }
    }
}

// Metodo que busca un nodo en la Heap
// NOTA: Originalmente, este metodo se iba a usar en Solve(), pero 
// probocaba una peor eficiencia y finalmente fue innecesario usarla cuando
// se arreglaron algunos bugs.
bool Heap::find(int i, int j){
    for(int k = 0; k < size; k++){
        if(arr[k].get_i() == i){
            if(arr[k].get_j() == j){
                return true;
            }
        }
    }
    return false;
}

// Metodo que busca si un Nodo esta en la Heap y si es asi, verifica si su valor
// es mayor al nuevo valor
// NOTA: Originalmente, este metodo se iba a usar, pero resultaba muy ineficiente
// y finalmente fue innecesario utilizarlo en Solve().
void Heap::newValue(int i, int j, int nvalue){
    for(int k = 0; k < size; k++){
        if(arr[k].get_i() == i){
            if(arr[k].get_j() == j){
                if(arr[k].getValue() > nvalue){
                    arr[k].setValue(nvalue);
                    break;
                }
            }
        }
    }
}
