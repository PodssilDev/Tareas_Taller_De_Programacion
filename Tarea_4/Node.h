#include <iostream>
#include <unistd.h>
#include <time.h>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

/*
La clase "Node" representa a un nodo del grafo. Cada nodo tiene un numero
asignado y un "valor" que corresponde a la cantidad de conexiones que tiene.
*/

class Node {
public:
    Node(); // Generador de la clase, crea un nodo con valores por defectos.
    ~Node(); // Destruye unn nodo
    Node(int i, int value); // Crea un nodo con valores especificos
    int get_i(); // Obtiene el numero asociado al Nodo
    int getValue(); // Obtiene el valor del nodo (conexiones con otros nodos)
    void set_i(int i); // Cambia el numero asociado al Nodo
    void setValue(int value); // Modifica el valor del nodo
    void print(); // Imprime un nodo, indicando su numero y valor asociado.
private:
    int i; // Numero asignado al nodo
    int value; // Cantida de conexiones que tiene el nodo con otros nodos del grafo.
};
