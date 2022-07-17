#include "Heap.h"
using namespace std;

/*
"Hamiltonian" es la clase mas importante en esta tarea. En ella se crea el grafo
a buscar y se tienen los metodos de solve para asi buscar si el grafo generado tiene
o no un ciclo hamiltoniano. 
*/

class Hamiltonian{
public:
    Hamiltonian(int size); // Crea un Hamiltonian, guardando un tamano especifico
    ~Hamiltonian();	 // Destruye un Hamiltonian
    int getSize(); // Obtiene el tamano guardado en Hamiltonian
    void createGraph(float p); // Crea el grafo con una probabilidad especifica
    void printGraph(); // Imprime el grafo
    bool solve(); // Primera parte de la solucion, realiza verificaciones
private: 
    int size; // Tamano del grafo y el camino a armar
    vector<vector<int>> graph; // Grafo que se va a armar
    vector<int> path; // Camino que se va a armar
    int getValue(int i); // Obtiene cuantas conexiones tiene un nodo
    bool verify(); // Verifica si todos los nodos tienen conexiones mayores o iguales a 2
    bool solveMain(); // Segunda parte de la solucion, busca y encuentra el ciclo hamiltoniano
    void printSolution(); // Imprime el ciclo hamiltoniano
};
