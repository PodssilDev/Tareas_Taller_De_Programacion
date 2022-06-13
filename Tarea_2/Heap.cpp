#include "Heap.h"

// "Heap" corresponde a la clase de la Cola de prioridad, la cual se utiliza para 
//  obtener el nodo de menor costo y asi saber cual es la asignacion optima. 
// Heap recibe un tamaño para poder funcionar.

// Entrada: Un entero N, correspondiente al tamano de la Heap
// Salida: Una Heap de tamano N
// Descripcion: Metodo que crea la Heap. Recibe un tamaño en especifico paa su creacion
Heap::Heap(int size) {
    Heap::size = size;
    count = 0;
    arr = new Node[size];
}

// Entrada: No recibe entrada
// Salida: No tiene salida como tal
// Descripcion: Metodo que destruye la Heap
Heap::~Heap() {
    delete[] arr;
}

// Entrada: No recibe entrada
// Salida: Un entero, correspondiente al tamano de la Heap
// Descripcion: Metodo que obtiene el tamaño de la Heap
int Heap::getSize() {
    return size;
}

// Entrada: Un nodo a insertar
// Salida: No tiene salida como tal, pero actualiza la Heap
// Descripcion: Metodo que inserta un nodo en la Heap. Para ello, recibe un nodo 
// como entrada. Cabe destacar de que internamente, la Heap ordena los nodos 
// dependiendo del valor que tenga este. Si la heap ya esta llena muestra un mensaje.
void Heap::insert(Node *node) {
    if (count == size) {
        cout << "Heap is full" << endl;
        return;
    }
    arr[count] = *node; // Notice: copy the node
    count++;
    bubbleUp();
}

// Entrada: No recibe entrada
// Salida: Si la Heap esta vacia, retorna 0
// Descripcion: Metodo que verifica si es que la Heap esta vacia.
int Heap::isEmpty() {
    return count == 0;
}

// Entrada: No recibe entrada
// Salida: Retorna el costo del primer elemento de la Heap
// Descripcion: Metodo que permite revisar el primer elemento de la Heap y retornar su costo
int Heap::peek() {
    if (isEmpty()) {
        cout << "Heap is empty" << endl;
        return(-1);
    }
    return arr[0].getCost();
}

// Entrada: No tiene una entrada como tal
// Salida: Una impresion de la Heap
// Descripcion: Metodo que imprime el contenido de la Heap, en forma de arbol
void Heap::print() {
    int h = (int)(log(count)/log(2));
    
    for(int a=0;a <= h;a++){
        for(int b=0;b<(1<<a) && ((1<<a)-1+b)<count;b++){
            int k=(1<<a)-1+b;
            cout<<arr[k].getCost()<<" ";
        }
        cout << endl;
    }
}

// Entrada: No recibe entrada como tal
// Salida: Retorna un nodo, correspondiente al de menor tamano
// Descripcion: Metodo que saca el elemento con el menor tamano de la Heap y lo borra 
// de esta.
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

// Entrada: Dos posiciones, correspondientes a entero
// Salida: Actualiza la Heap
// Descripcion: Metodo que intercambia posiciones de la Heap.
void Heap::swap(int i, int j) {
    Node temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Entrada: No recibe entrada como tal
// Salida: No tiene salida como tal
// Descripcion: Metodo que permite que ciertos nodos queden sobre otros nodos
void Heap::bubbleUp(){
    int index = count - 1;
    int parentIndex =  (index - 1) / 2;
    while (index > 0 &&
        parentIndex >= 0 && 
        arr[index].getCost() < arr[parentIndex].getCost()) {
        swap(index, parentIndex);
        index = parentIndex;
        parentIndex =  (index - 1) / 2;
    }
}

// Entrada: No recibe entrada
// Salida: No tiene salida como tal
// Descripcion:  Metodo que permite que ciertos nodos queden bajo otros nodos
void Heap::bubbleDown(){
    int index = 0;
    int leftChildIndex = 1;
    int rightChildIndex = 2;
    while (leftChildIndex < count) {
        if (arr[leftChildIndex].getCost() < arr[index].getCost() || 
            arr[rightChildIndex].getCost() < arr[index].getCost()) {
            if (arr[leftChildIndex].getCost() < arr[rightChildIndex].getCost()) {
                swap(index, leftChildIndex);
                index = leftChildIndex; 
            } else {
                swap(index, rightChildIndex);
                index = rightChildIndex;
            }
            leftChildIndex = index * 2 + 1;
            rightChildIndex = index * 2 + 2;        
        } else {
            break;
        }
    }
}
