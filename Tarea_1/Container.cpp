#include "Container.h"

// Container representa a la clase correspondiente a la "CloseList", donde se coloca
// una identificacion para los ya visitados. Por terminos de eficiencia, se utiliza
// una matriz de la misma dimension del laberinto

// Para crear la matriz, se recibe la dimension, la cual es la misma del laberinto
// Es bastante similar a la implementacion de Maze
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

// Metodo que destruye la matriz
Container::~Container(){
    for(int i = 0; i < size; i ++){
        delete[] arr[i];
    }
    delete[] arr;
}

// Metodo que cambia el 0 de una posicion en especifica por un 1, en otras
// palabras lo marca como ya visitado. Recibe como entradas las posiciones i,j
// de un nodo del laberinto.
void Container::insert(int i, int j){
    arr[i][j] = 1; // visitado
}

// Metodo que verifica si una posicion del laberinto ya fue visitada. 
// Recibe como entradas las posiciones i,j de un nodo del laberinto y retorna 
// un booleano dependiendo de si fue visitado (tiene un 1 en la matriz) o no.
bool Container::clfind(int i, int j){
    if(arr[i][j] == 1){
        return true;
    }
    else{
        return false;
    }
}
