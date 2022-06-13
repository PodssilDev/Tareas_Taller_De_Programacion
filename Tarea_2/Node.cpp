#include "Node.h"

// La clase "Node" representa a un estado de la matriz, en otras palabras, un nodo
// es una posicion de la matriz que tiene unas coordenadas i,j, un valor, un valor total,
// un arreglo de booleanos y una referencia al padre de donde se pudo acceder a esa 
// posicion.

// Entrada: No recibe entrada
// Salida: Retorna un nodo
// Descripcion: Metodo que genera un nodo
Node::Node() {
    this->cost = 0;
    this->totalCost = 0;
    this->cpu = 0;
    this->processor = 0;
    this->assigned = NULL;
    this->previous = NULL;
}

// Entrada: No recibe entrada
// Salida: No tiene salida como tal
// Descripcion: Metodo que destruye el nodo
Node::~Node () {
}

// Entrada: No recibe entrada
// Salida: Retorna un entero, correspondiente al costo total
// Descripcion: Metodo que obtiene el costo total de un nodo
int Node::getTotalCost(){
    return this->totalCost;
}

// Entrada: No recibe entrada
// Salida: Retorna un entero, correspondiente al costo principal
// Descripcion: Metodo que obtiene el costo principal del nodo
int Node::getCost(){
    return this->cost;
}

// Entrada: No recibe entrada
// Salida: Retorna un nodo, correspondiente al padre del nodo
// Descripcion: Metodo que obtiene el nodo padre del nodo
Node* Node::getPrevious() {
    return this->previous;
}

// Entrada: No recibe entrada
// Salida: Retorna un entero, correspondiente a una Cpu (Posicion i) del nodo
// Descripcion: Metodo que obtiene la CPU asociada al nodo
int Node::getCpu(){
    return this->cpu;
}

// Entrada: No recibe entrada
// Salida: Retorna un entero, correspondiente al procesador (Posicion j) del nodo
// Descripcion: Metodo que obtiene el procesador asociado al nodo
int Node::getProcessor(){
    return this->processor;
}

// Entrada: No recibe entrada
// Salida: Retorna el arreglo de booleanos asociado al nodo
// Descripcion: Metodo que obtiene el arreglo de asignaciones del Nodo
bool* Node::getAssigned(){
    return this->assigned;
}

// Entrada: Un entero, correspondiente a una CPU
// Salida: Un nodo actualizado, con una nueva CPU
// Descripcion: Metodo que modifica la CPU asociada a un Nodo
void Node::setCpu(int cpu){
    this->cpu = cpu;
}

// Entrada: Un entero, correspondiente a un nuevo procesador
// Salida: Un nodo actualizado, con un nuevo procesador
// Descripcion: Metodo que modifica el procesador asociado a un Nodo
void Node::setProcessor(int processor){
    this->processor = processor;
}

// Entrada: Un Nodo, correspondinte al padre del nodo
// Salida: Un nodo actualizado, con un nuevo padre
// Descripcion: Metodo que modifica el padre del nodo
void Node::setPrevious(Node* previous) {
    this->previous = previous;
}

// Entrada: Un entero, correspondiente a un nuevo costo total
// Salida: Un nodo actualizado, con un nuevo costo total
// Descripcion: Metodo que cambia el costo total de un nodo
void Node::setTotalCost(int totalCost) {
    this->totalCost = totalCost;
}

// Entrada: Un entero, correspondiente a un costo principal
// Salida: Un nodo actualizado, con un nuevo costo principal
// Descripcion: Metodo que cambia el costo principal del nodo
void Node::setCost(int cost) {
    this->cost = cost;
}

// Entrada: Un numero entero N
// Salida: Un nodo actualizado, con un nuevo arreglo de booleanos
// Descripcion: Metodo que cambia el arreglo de booleanos del nodo
void Node::setAssigned(int N){
    this->assigned = new bool[N];
}

// Entrada: No recibe entrada 
// Salida: un entero
// Descripcion: Metodo que verifica si un nodo es una raiz
int Node::isRoot() {
    return this->previous == NULL;
}

// Entrada: No recibe entrada
// Salida: Una impresion de un nodo
// Descripcion: Metodo que imprime un nodo, indicando sus posiciones y costo principal
void Node::print() {
    cout << "(" << this->cpu << "," << this->processor << ")[" << this->cost << "]" << endl;
}

// Entrada: No recibe entrada
// Salida: Un string, correspondiente a un camino
// Descripcion: Metodo que obtiene los nodos padres hasta la raiz del nodo actual
string Node::getPath() {
    string s="("+to_string(this->cpu)+","+to_string(this->processor)+")";
    if (this->previous != NULL) {
        s=s+this->previous->getPath();
    }
    return(s); 
}

// Entrada: Tres enteros, dos correspondiente a coordenadas (i,j), el tamano de la matriz, 
// un nodo padre y un arreglo de booleanos
// Salida: Un nodo con todos sus atributos actualizados
// Descripcion: Metodo que prepara a un nodo, agregandole las posiciones (i,j) correspondientes
// Ademas, asigna el padre y copia el arreglo de asignaciones de este al hijo, para que asi
// el hijo tenga conocimiento de cuales son las asignaciones si es que es elegido como el
// nodo minimo.
void Node::prepareNode(int cpu, int processor, bool* assignedArray, Node* previous, int N){
    this->setAssigned(N); // Creo el nuevo arreglo para el nodo
    for(int j = 0; j < N; j++){ // Copio el arreglo del padre al hijo
        this->assigned[j] = assignedArray[j];
    }
    if(processor != -1){ // Si el procesador se puede asignar
        this->assigned[processor] = true;
    }
    setCpu(cpu);
    setProcessor(processor);
    setPrevious(previous);
}

