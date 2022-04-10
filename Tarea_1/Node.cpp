#include "Node.h"

// La clase "Node" representa a un estado del laberinto, en otras palabras, un nodo
// es una posicion del laberinto que tiene unas coordenadas i,j, un valor y una
// referencia al padre de donde se pudo acceder a esa posicion.

// Metodo que genera un nodo
Node::Node() {
    this->i = 0;
    this->j = 0;
    this->value = 0;
    this->depth = -1;
    this->previous = NULL;
}

// Metodo que genera un nodo
Node::Node(Node* node) {
    this->i = node->i;
    this->j = node->j;
    this->value = node->value;
    this->depth = node->depth;
    this->previous = node->previous;
}

// Metodo que genera un nodo utilizando unas coordenadas i,j, un valor y un nodo padre
Node::Node(int i, int j, int value, Node* parent) {
    this->i = i;
    this->j = j;
    this->value = value;
    this->previous = parent;
}

// Metodo que destruye el nodo
Node::~Node () {
}

// Metodo que obtiene la posicion i del nodo
int Node::get_i() {
    return this->i;
}

// Metodo que obtiene la posicion j del nodo
int Node::get_j() {
    return this->j;
}

// Metodo que obtiene el nodo padre del nodo
Node* Node::getPrevious() {
    return this->previous;
}

// Metodo que obtiene el valor del nodo
int Node::getValue() {
    return this->value;
}

// Metodo que modifica el padre del nodo
void Node::setPrevious(Node* previous) {
    this->previous = previous;
}

// Metodo que cambia la distancia de la entrada hacia el nodo
void Node::setDepth(int depth) {
    this->depth = depth;
}

// Metodo que cambia el valor del nodo
void Node::setValue(int value) {
    this->value = value;
}

// Metodo que verifica si es que un nodo es una raiz
int Node::isRoot() {
    return this->previous == NULL;
}

// Metodo que imprime un Nodo 
void Node::print() {
    cout << "(" << this->i << "," << this->j << ")[" << this->value << "]" << endl;
}

// Metodo que obtiene la distancia de la entrada hacia el nodo
int Node::getDepth() {
    return(this->depth);    
}

// Metodo que obtiene los nodos padres hasta la raiz del nodo actual
string Node::getPath() {
    string s="("+to_string(this->i)+","+to_string(this->j)+")";
    if (this->previous != NULL) {
        s=s+this->previous->getPath();
    }
    return(s); 
}
