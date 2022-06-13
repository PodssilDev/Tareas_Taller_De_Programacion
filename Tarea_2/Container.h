#include <iostream>
using namespace std;

// Container representa a la clase correspondiente a la Matriz Binaria, donde se coloca
// una identificacion para las asignaciones definidas. Por terminos de eficiencia, se 
// utiliza una matriz de la misma dimension del laberinto. Un 1 representa una 
// asignacion y un 0 significa no asignado.

class Container{
public:
    Container(int size); // Genera la matriz binaria
    ~Container(); // Destruye la matriz binaria
    void insert(int i, int j); // Marca a un nodo en la matriz, utilizando sus coordenadas
    void print(); // Imprime la matriz binaria
private:
    int **arr; // Se utiliza para la creacion de la matriz
    int size; // Se utiliza como la dimension de la matriz
};
