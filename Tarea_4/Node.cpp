#include "Node.h"

/*
La clase "Node" representa a un nodo del grafo. Cada nodo tiene un numero
asignado y un "valor" que corresponde a la cantidad de conexiones que tiene.
*/

/*
Entrada: No tiene entrada
Salida: Un Nodo con valores por defecto
Descripcion: Metodo que crea un Nodo con valores por defecto, inicializados en 0.
*/
Node::Node() {
    this->i = 0;
    this->value = 0;
}

/*
Entrada: Recibe dos enteros, un numero de nodo y un valor
Salida: Un nodo con valores especificos
Descripcion: Metodo que crea un Nodo con valores especificos
*/
Node::Node(int i, int value) {
    this->i = i;
    this->value = value;
}

/*
Entrada: No tiene entrada
Salida: No tiene salida como tal, pero se destruye el nodo
Descripcion: Metodo que destruye un Nodo
*/
Node::~Node () {
}

/*
Entrada: No tiene entrada
Salida: Un entero que representa el numero asignado al nodo
Descripcion: Metodo que obtiene el numero asignado al nodo
*/
int Node::get_i() {
    return this->i;
}

/*
Entrada: No tiene entrada
Salida: Un entero que representa el valor del nodo
Descripcion: Metodo que obtiene el valor del nodo, el cual es el numero de conexiones
que el nodo del grafo tiene con otros nodos.
*/
int Node::getValue() {
    return this->value;
}

/*
Entrada: Recibe un entero que representa el numero de nodo
Salida: No tiene salida como tal, pero se cambia el numero de nodo
Descripcion: Metodo que cambia el numero de nodo
*/
void Node::set_i(int i) {
    this->i = i;
}

/*
Entrada: Un entero que representa el valor del nodo
Salida: No tiene salida como tal, pero se modifica el valor del nodo
Descripcion: Metodo que cambia el valor del nodo.
*/
void Node::setValue(int value) {
    this->value = value;
}

/*
Entrada: No tiene entrada
Salida: No tiene salida como tal, pero se imprime el nodo y se muestra por consola
Descripcion: Metodo que imprime un nodo por consola, indicando su numero y valor asociado.
*/
void Node::print() {
    cout << "(" << this->i << ")[" << this->value << "]" << endl;
}
