#ifndef COST_H
#define COST_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// La clase cost representa a la matriz de Costo, donde cada posicion tiene un numero
// aleatorio representando el costo de la asignacion de esa columna y procesador en 
// especifico. La matriz tiene un tamano determinado por el parametro N.

class Cost  {
private:
    int N; // Tamano de la matriz cuadratica de costo
    int **cost; // Doble puntero para crear las posiciones de la matriz
    int isNotNewCost(int i, int j); // Metodo auxiliar para verificar si un costo es nuevo en la fila i
public:
    Cost(int N); // Metodo que crea la matriz de costo
    ~Cost(); // Metodo que destruye la matriz de costo
    void setCost(int i, int j, int value); // Metodo que coloca un costo a una posicion en especifico
    int getCost(int i, int j); // Metodo que obtiene un costo de una posicion en especifico
    int getN(); // Metodo que obtiene el tamano de la matriz de costo
    void generateCost(); // Metodo que genera una asignacion de costos aleatorias a cada posicion de la matriz
    void print(); // Metodo que imprime la matriz de costo
};

#endif
