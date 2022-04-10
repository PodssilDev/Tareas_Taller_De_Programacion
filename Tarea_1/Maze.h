#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Heap.h"
#include "Container.h"
#include <cmath>
#include <stdlib.h>
using namespace std;

// Definimos las constantes que representan partes del Laberinto
#define IN_DOOR 2
#define OUT_DOOR 3
#define WALL 1
#define EMPTY 0
#define VISITED 4

/*
La clase Maze consiste en la clase del laberinto. Aqui es donde se genera y se tiene el 
algoritmo A* para encontrar el camino mas eficiente desde la entrada hacia la salida.
*/
class Maze {
public:
    Maze(int dim, int p); // Generador de la clase
    ~Maze(); // Destruye el laberinto
    void print(); // Imprime el laberinto (Y marca con color el camino si es que hay)
    void solve(); // Resuelve y encuentra el camino mas eficiente del laberinto
    void generate(); // Genera un laberinto aleatorio
    int heuristica(int i, int j, int dim); // Calcula el valor de un nodo del laberinto
    void markMaze(Node *node); // Marca una posicion del laberinto para reflejarlo en el print
private:
    int dim; // Se utiliza una dimension para generar un laberinto
    int **arr; // Se utiliza una matriz para generar un laberinto
    int void_percentage; // Se utiliza un porcentaje de "void" para generar los caminos
};
