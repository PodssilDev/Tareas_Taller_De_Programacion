#include <iostream>
using namespace std;

// La clase "Node" representa a un estado de la matriz, en otras palabras, un nodo
// es una posicion de la matriz que tiene unas coordenadas i,j, un valor, un valor total,
// un arreglo de booleanos y una referencia al padre de donde se pudo acceder a esa 
// posicion.

class Node {
public:
    Node(); // Metodo que genera un nodo, con todos sus atributos 0 y nulos
    ~Node(); // Metodo que destruye un nodo
    int getTotalCost(); // Metodo que obtiene el costo total del nodo
    int getCost(); // Metodo que obtiene el costo principal del nodo
    Node *getPrevious(); // Metodo que obtiene el nodo padre del nodo
    int getCpu(); // Metodo que obtiene la CPU (Posicion i) asociada al nodo
    int getProcessor(); // Metodo que obtiene el procesador (Posicion J) asignado al nodo
    bool* getAssigned(); // Metodo que obtiene el arreglo de asignaciones del nodo
    void setPrevious(Node *previous); // Metodo que modifica el nodo padre
    void setCost(int cost); // Metodo que modifica el costo principal del nodo
    void setCpu(int cpu); // Metodo que modifica la CPU asociada al nodo
    void setProcessor(int processor); // Metodo que modifica el procesador asociado al nodo
    void setTotalCost(int totalCost); // Metodo que modifica el costo total del nodo
    void setAssigned(int N); // Metodo que modifica el arreglo de asignaciones del nodo
    int isRoot(); // Metodo que verifica si el nodo es raiz (Padre NULL)
    string getPath(); // Metodo que obtiene todos los padres hasta la raiz
    void print(); // Metodo que imprime un nodo
    void prepareNode(int cpu, int processor, bool* assignedArray, Node* previous, int N);
    // El metodo prepareNode prepara a un nodo asignandole valores y asignando al padre si es que tiene

private:
    int cost; //  Corresponde al costo principal del nodo
    int totalCost; // Corresponde al costo total del nodo
    int cpu; // Corresponde a la CPU del nodo
    int processor; // Corresponde al procesador del nodo
    bool *assigned; // Corresponde al arreglo de asignaciones del nodo
    Node *previous; // Corresponde al nodo padre
};
