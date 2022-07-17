#include "Heap.h"

/*
"Heap" corresponde a la clase de la Cola de prioridad, la cual se utiliza como
"Open list" para asi guardar los nodos del grafo. Heap recibe un 
tamaño para poder funcionar. 
*/

/*
Entrada: Un numero entero que representa el tamano de la Heap
Salida: Una Heap con un tamano especifico
Descripcion: Metodo que crea la Heap. Recibe un tamaño en especifico paa su creacion
*/
Heap::Heap(int size) {
    Heap::size = size;
    count = 0;
    arr = new Node[size];
}

/*
Entrada: No tiene entrada
Salida: No tiene salida como tal, pero se destruye la Heap
Descripcion: Metodo que destruye la Heap
*/
Heap::~Heap() {
    delete[] arr;
}

/*
Entrada: No tiene entrada
Salida: Un entero que representa el tamano de la Heap
Descripcion: Metodo que obtiene el tamaño de la Heap
*/
int Heap::getSize() {
    return size;
}

/*
Entrada: Un nodo
Salida: No tiene salida como tal, pero se agrega un nodo a la Heap
Descripcion: Metodo que inserta un nodo en la Heap. Para ello, recibe 
un nodo como entrada. Cabe destacar de que internamente, la Heap ordena 
los nodos dependiendo del valor que tenga este. Si la heap ya esta llena 
muestra un mensaje.
*/
void Heap::insert(Node *node) {
    if (count == size) {
        cout << "Heap is full" << endl;
        return;
    }
    arr[count] = *node; // Notice: copy the node
    count++;
    bubbleUp();
}

/*
Entrada: No tiene entrada
Salida: Un entero que representa si la Heap esta vacia o no
Descripcion: Metodo que verifica si es que la Heap esta vacia.
*/
int Heap::isEmpty() {
    return count == 0;
}

/*
Entrada: No tiene entrada
Salida: Un entero que reprensenta el valor de un Nodo guardado en la Heap
Desripcion: Metodo que permite revisar el primer elemento de la Heap.
Obtiene el valor del nodo y lo retorna.
*/
int Heap::peek() {
    if (isEmpty()) {
        cout << "Heap is empty" << endl;
        return(-1);
    }
    return arr[0].getValue();
}

/*
Entrada: No tiene entrada
Salida: No tiene salida como tal, pero imprime por consola
Descricion: Metodo que imprime la Heap, en forma de arbol. El primer elemento es el
nodo de menor valor guardado en la Heap.
*/
void Heap::print() {
    int h = (int)(log(count)/log(2));    
    for(int a=0;a <= h;a++){
        for(int b=0;b<(1<<a) && ((1<<a)-1+b)<count;b++){
            int k=(1<<a)-1+b;
            cout<<arr[k].getValue()<<" ";
        }
        cout << endl;
    }
}

/*
Entrada: No tiene entrada
Salida: Un nodo que representa el nodo de menor valor de la Heap
Descripcion: Metodo que saca el elemento con el menor tamaño de la Heap y lo borra 
de esta.
*/
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

/*
Entrada: Dos enteros, correspondientes a posiciones
Salida: No tiene salida como tal, pero actualiza la Heap
Descripcion: Metodo que intercambia posiciones de los nodos en la Heap y la actualiza.
*/
void Heap::swap(int i, int j) {
    Node temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/*
Entrada: No tiene entrada
Salida: No tiene salida como tal, pero actualiza la Heap
Descripcion: Metodo que permite que ciertos nodos queden sobre otros nodos
*/
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

/*
Entrada: No tiene entrada
Salida: No tiene salida como tal, pero actualiza la Heap
Descripcion: Metodo que permite que ciertos nodos queden bajo otros nodos
*/
void Heap::bubbleDown(){
    int index = 0;
    int leftChildIndex = 1;
    int rightChildIndex = 2;
    while (leftChildIndex < count) {
        // Buscamos el hijo a swapear
        if (arr[leftChildIndex].getValue() < arr[index].getValue() || 
            arr[rightChildIndex].getValue() < arr[index].getValue()) {
            if (arr[leftChildIndex].getValue() < arr[rightChildIndex].getValue()) {
                swap(index, leftChildIndex);
                index = leftChildIndex; // Lo movemos a la izquierda
            } else {
                swap(index, rightChildIndex);
                index = rightChildIndex; // Lo movemos a la derecha
            }
            // Se actualiza el index
            leftChildIndex = index * 2 + 1;
            rightChildIndex = index * 2 + 2;        
        } else {
            break; // En este caso, no hay necesidad de modificar
        }
    }
}
