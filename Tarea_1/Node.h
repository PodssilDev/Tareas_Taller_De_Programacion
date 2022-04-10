#include <iostream>

using namespace std;

// La clase "Node" representa a un estado del laberinto, en otras palabras, un nodo
// es una posicion del laberinto que tiene unas coordenadas i,j, un valor y una
// referencia al padre de donde se pudo acceder a esa posicion.

class Node {
public:
    Node(); // Generador de la clase
    ~Node(); // Destruye el nodo
    Node(Node* node); // Crea un nodo
    Node(int i, int j, int value, Node* previous); // Crea un nodo con valores especificos

    int get_i(); // Obtiene la posicion i del Nodo
    int get_j(); // Obtiene la posicion j del Nodo
    Node *getPrevious(); // Obtiene el nodo padre
    int getValue(); // Obtiene el valor del nodo
    int getDepth(); // Obtiene la distancia de la entrada al nodo actual
    
    void setPrevious(Node *previous); // Modifica el nodo padre
    void setDepth(int depth); // Modifica la distancia de la entrada al nodo actual
    void setValue(int value); // Modifica el valor del nodo
    
    int isRoot(); // Verifica si el nodo es raiz (Padre NULL)
    string getPath(); // Obtiene todos los padres hasta la raiz
    void print(); // Imprime un nodo

private:
    int i; // fila
    int j; //  columna
    int value; // Valor del nodo
    int depth; // Distancia de la entrada hacia el nodo
    Node *previous; // Nodo padre
};
