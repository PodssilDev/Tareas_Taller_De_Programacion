#include "Container.h"

// Container representa a la clase correspondiente a la Matriz Binaria, donde se coloca
// una identificacion para las asignaciones definidas. Por terminos de eficiencia, se utiliza
// una matriz de la misma dimension del laberinto. Un 1 representa una asignacion y un 0
// significa no asignado.

// Entrada: Un numero entero N, correspondiente a la dimension de la matriz
// Salida: Una matriz llena de 0s
// Descripcion: Para crear la matriz, se recibe la dimension, la cual es la misma 
//              de la matriz de  costo. Es bastante similar a la implementacion de Cost.
Container::Container(int size){
    Container::size = size;
    arr = new int*[size];
    for(int i = 0; i < size; i++){
        arr[i] = new int[size];
        for (int j = 0; j < size;j++){
            // generamos una matriz solo de 0s
            arr[i][j] = 0;
        }
    }
}

// Entrada: No tiene entrada asociada
// Salida: No tiene una salida como tal
// Metodo que destruye la matriz binaria
Container::~Container(){
    for(int i = 0; i < size; i ++){
        delete[] arr[i];
    }
    delete[] arr;
}

// Entrada: Dos enteros, correspondientes a las posiciones (i,j) de una asignacion
// Salida: Una actualizacion de una posicion de la matriz binaria
// Descripcion: Metodo que cambia el 0 de una posicion en especifica por un 1, en otras
//              palabras lo marca como ya visitado. Recibe como entradas las posiciones 
//              i,j de un nodo de la matriz.
void Container::insert(int i, int j){
    arr[i][j] = 1;
}

// Entrada: No tiene una entrada 
// Salida: Una impresion de la matriz binaria
// Descripcion: Metodo que imprime la matriz de binaria.
void Container::print(){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
