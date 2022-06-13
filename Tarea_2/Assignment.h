#include <iostream>
#include "Cost.h"
#include "Heap.h"
#include "Container.h"

// La clase Assignment representa a un objeto el cual contiene la matriz de costo
// y el tamano N, el cual corresponde al tamano de la matriz de costo. En esta clase
// se encuentra el metodo para encontrar el menor costo asociado a la asignacion de 
// CPUs y procesos.

class Assignment {
public:
    Assignment(int N); // Metodo que recibe un entero N y construye a la clase Assignment
    ~Assignment(); // Metodo que elimina a la clase Assignment
    int solve(Cost* costMatrix); // Metodo que obtiene el costo minimo de asignaciones
    Cost* getCost(); // Metodo que obtiene la matriz de costo relacionada de Assignment
    int getN(); // Metodo que obtiene el tamano de la matriz de costo relacionada de Assignment

private:
    int N; // Tamano de la matriz de costo asociada
    Cost *cost; // Matriz de costo asociada
    int greedyCost(Cost* costMatrix, int cpu, int processor, bool* assigned); // Calcula el costo utilizando algoritmo Greedy
    void printAssignments(Node *minimun); // Imprime las asignaciones correspondientes de procesos y CPUs
    void printBinaryMatrix(Node *minimum, int N); // Imprime la matriz binaria, correspondiente a la solucion
};
