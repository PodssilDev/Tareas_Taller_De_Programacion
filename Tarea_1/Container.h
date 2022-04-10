#include <iostream>
using namespace std;

// "Container" representa a la clase correspondiente a la "CloseList", donde se coloca
// una identificacion para los ya visitados. Por terminos de eficiencia, se utiliza
// una matriz de la misma dimension del laberinto

class Container{
public:
    Container(int size); // Genera la matriz 
    ~Container(); // Destruye la matriz
    void insert(int i, int j); // Marca a un nodo en la matriz
    bool clfind(int i, int j); // Busca en la matriz
private:
    int **arr; // Se utiliza para la creacion de la matriz
    int size; // Se utiliza como la dimension de la matriz
};
