#include "Cost.h"

// La clase cost representa a la matriz de Costo, donde cada posicion tiene un numero
// aleatorio representando el costo de la asignacion de esa columna y procesador en 
// especifico. La matriz tiene un tamano determinado por el parametro N.

// Entrada: Un numero entero N correspondiente al tamano de la matriz
// Salida: Una matriz de costo
// Descripcion: Metodo que genera una matriz de costo, de tamano N
Cost::Cost(int N) {
    this->N = N;
    srand(time(NULL));
    cost=nullptr;
    generateCost();
}

// Entrada: No recibe entrada
// Salida: No tiene salida como tal
// Descripcion: Metodo que destruye una matriz de costo
Cost::~Cost() {
    delete[] cost;
}

// Entrada: Tres enteros, dos correspondiente a posiciones y el tercer correspondiente a un valor
// Salida: Actualiza la matriz de costo con un valor
// Descripcion: Metodo que cambia el valor correspondiente a una posicion de la matriz de costo
void Cost::setCost(int i, int j, int value) {
    cost[i][j] = value;
}

// Entrada: Dos enteros, correspondiente a coordenadas (i,j)
// Salida: Un entero, correspondiente al costo de la posicion correspondiente a las coordenadas (i,j)
// Descripcion: Metodo que obtiene el costo de una posicion en especifico de la matriz de costo
int Cost::getCost(int i, int j) {
    return cost[i][j];
}

// Entrada: No recibe entrada
// Salida: Un entero, correspondiente al tamano de la matriz
// Descripcion: Metodo que obtiene el tamano de la matriz de costo
int Cost::getN() {
    return N;
}

// Entrada: No recibe entrada como tal
// Salida: Una generacion de la matriz de costo
// Salida: Metodo que genera un costo aleatorio en cada posicion de la matriz de costo, sin repeticion
void Cost::generateCost() {
    if (cost != nullptr) {
        delete[] cost;
    }
    cost = new int*[N];
    for (int i = 0; i < N; i++) {
        cost[i] = new int[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cost[i][j] = 1+rand() % (N+N/5+1);
            while (isNotNewCost(i, j)) {
                cost[i][j] = 1+rand() % (N+N/5+1);
            }
        }
    }

    int k = 0;
    while(k<N/5) {
        int i = rand() % N;
        int j = rand() % N;
        int backup=cost[i][j];
        cost[i][j]=N/5;
        if (!isNotNewCost(i, j)) {
            //cout << i << " " << j << endl;
            k++;
        } else {
            cost[i][j]=backup;
        }
    }
}

// Entrada: No recibe entrada como tal
// Salida: Una impresion de la matriz de costo
// Descripcion: Metodo que imprime la matriz de costo
void Cost::print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}

// Entrada: Dos enteros, correspondientes a coordenadas (i,j) de una posicion de la matriz
// Salida: Un numero entero, correspondiente a 0 o 1
// Descripcion: Metodo que verifica si el costo ya fue asignado en esa posicion de la 
//              matriz de costo. Si es verdadero, retorna 1. Caso contrario, 0.
int Cost::isNotNewCost(int i, int j) {
    for (int k = 0; k < j; k++) {
        if (cost[i][j] == cost[i][k]) {
            return 1;
        }
    }
    return 0;
}
