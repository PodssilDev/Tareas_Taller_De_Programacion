#include "Assignment.h"

// La clase Assignment representa a un objeto el cual contiene la matriz de costo
// y el tamano N, el cual corresponde al tamano de la matriz de costo. En esta clase
// se encuentra el metodo para encontrar el menor costo asociado a la asignacion de 
// CPUs y procesos.

// Entrada: Un entero N, correspondiente al tamano de la matriz de costo
// Salida: Retorna a Assignment, el cual contiene a la matriz de costo y el tamano N
// Descripcion: Metodo que crea a Assignment
Assignment::Assignment(int N){
    this->N = N;
    cost = new Cost(N);
}

// Entrada: No requiere de entrada
// Salida: No tiene salida como tal
// Descripcion: Metodo que destruye a Assignment
Assignment::~Assignment(){
    delete cost;
}

// Entrada: No requiere de entrada
// Salida: Una matriz de costo (Tipo de dato Cost)
// Descripcion: Metodo que obtiene la matriz de costo asociada a Assignment
Cost* Assignment::getCost(){
    return cost;
}

// Entrada: No requiere de entrada
// Salida: Un entero N, correspondiente al tamano de la matriz de costo
// Descripcion: Metodo que obtiene el tamano de la matriz de costo asociada a Assignment
int Assignment::getN(){
    return N;
}

// Entrada: Un nodo y la dimension de la matriz de costo
// Salida: Una impresion de la matriz binaria
// Descripcion: Metodo que imprime la matriz binaria de 0 y 1s, la cual corresponde a 
//              la solucion de Solve, pero en forma de matriz. 
void Assignment::printBinaryMatrix(Node *minimum, int N){
    Container *binaryMatrix = new Container(N);
    binaryMatrix->insert(minimum->getCpu(), minimum->getProcessor());
    while (minimum->getPrevious()->getPrevious() != NULL){
        minimum = minimum->getPrevious();
        binaryMatrix->insert(minimum->getCpu(), minimum->getProcessor());
    }
    binaryMatrix->print();
}

// Entrada: Un nodo
// Salida: Una impresion de las distintas asignaciones de CPUs y Procesos
// Descripcion: Metodo que imprime las distintas asignaciones de las CPUs y Procesos
//              Para ello se utilizan los nodos padres hasta llegar a un nodo raiz
void Assignment::printAssignments(Node *minimum){
    if(minimum->getPrevious() == NULL){
        return;
    }
    printAssignments(minimum->getPrevious());
    cout << "A la CPU " << minimum->getCpu() <<" se le asigna el procesador " << minimum->getProcessor() << endl;
}

// Entrada: Una matriz de costo, unas coordenadas (i,j) (cpu y proceso) y un arreglo de enteros que
//          contiene la informacion de si una columna (proceso) ya fue asociado a una CPU
// Salida: Un costo, correspondiente al costo optimo
// Descripcion: Metodo que, utilizando el algoritmo Greedy, calcula el costo minimo de aquellos
//              Nodos donde su procesador no ha sido asignado a alguna CPU
int Assignment::greedyCost(Cost* costMatrix, int cpu, int processor, bool* assigned){
    int cost = 0;
    int minimum = 100000;
    for(int i = cpu + 1; i < N; i++){
        for(int j = 0; j< N; j++){
            if((not(assigned[j])) && costMatrix->getCost(i,j) < minimum) {
                minimum = costMatrix->getCost(i, j);
            }
        }
        cost = cost + minimum;
    }
    return cost;
}

// Entrada: Una matriz de costo
// Salida: Un costo minimo (Si hay algun error, retorna 1)
// Descripcion: Metodo que resuelve el problema de Jobs Assignment, obteniendo el
//              menor costo asociado a la asignacion. Para ello, utiliza los metodos
//              anteriormente descritos junto con los metodos de otras clases. A 
//              continuacion se describe paso a paso cada parte importante del metodo.
int Assignment::solve(Cost* costMatrix){
    // Se inicializa una Heap de tamano N que sera usada para guardar un nodo temporalmente
    Heap* temporalHeap = new Heap(N);
    // Se inicializa una Heap de tamano N donde se guardaran los nodos de cada fila
    Heap *nodesHeap = new Heap(N);
    // Se crea un arreglo de booleanos falsos, donde cada posicion representa una columna
    bool assignedArray[N] = {false};
    // Se inicializan variables que seran utilizadas para recorrer y obtener las siguientes
    // posiciones
    int temp_cpu, temp_processor;
    int nextCpu = 0;
    // Se crea un nodo, el cual corresponde al nodo inicial (cuyas coordenadas son (-1,-1))
    Node* root = new Node();
    // Se prepara el nodo anterior, asignandole las coordenadas
    root->prepareNode(-1,-1,assignedArray,NULL, N);
    // Inserto el nodo en la heap
    nodesHeap->insert(root);
    // Que la Heap se vacie implica que no se pudo encontrar una solucion optima
    while(not(nodesHeap->isEmpty())){
        // Saco el nodo inicial de la Heap (Por ahora, esto es similar a A*)
        Node* minimumNode = nodesHeap->pull();
        // Aumento la CPU, para asi poder recorrer una nueva fila
        nextCpu = (minimumNode->getCpu())+ 1; 
        // Si nextCpu es igual a N, significa que ya llegue ya recorri todas las filas
        if(nextCpu == N){ 
            // Eliminamos las Heaps
            nodesHeap->~Heap();
            temporalHeap->~Heap();
            // Se imprimen las distintas asignaciones de CPU y procesadores
            printAssignments(minimumNode);
            cout << "Matriz Binaria (Solucion): " << endl;
            cout << "\n";
            // Se imprime la matriz Binaria asociada a la solucion
            printBinaryMatrix(minimumNode, N);
            cout << "\n";
            cout << "Costo minimo: " << minimumNode->getCost() << endl;
            // Si todo funciona correctamente, aqui es donde solve() acaba.
            return minimumNode->getCost(); 
        }
        // Recorremos todos los procesadores disponibles
        for(temp_processor = 0; temp_processor < N; temp_processor++){
            // Busco si la columna actual (procesador) NO fue marcada (tomada) por otra CPU 
            if((minimumNode->getAssigned()[temp_processor]) == false){
                // Creo un nuevo nodo al cual lo preparo, luego le calculo su nuevo costo (Branch & Bound)
                // Inserto ese nodo en la Heap
                Node* nextNode = new Node();
                nextNode->prepareNode(nextCpu,temp_processor, minimumNode->getAssigned(), minimumNode, N); 
                nextNode->setTotalCost(minimumNode->getTotalCost() + costMatrix->getCost(nextCpu, temp_processor));
                nextNode->setCost(nextNode->getTotalCost() + greedyCost(costMatrix, nextCpu, temp_processor, nextNode->getAssigned()));
                nodesHeap->insert(nextNode);
            }
        }
        // Creo un nuevo nodo
        Node* newNode = new Node();
        // Asigno al nuevo nodo como aquel nodo menor asignado en la Heap. Se inserta en temporalHeap
        newNode = nodesHeap->pull();
        temporalHeap->insert(newNode);
        // Reinicio la heap, eliminando aquellos nodos que no me sirven
        nodesHeap = new Heap(N);
        // Hago el traspaso de una heap a otra, esto es para no perder al nuevo nodo
        // que sera asignado como minimo
        Node *temp_node = temporalHeap->pull();
        nodesHeap->insert(temp_node);
        // El proceso se repite hasta que se tenga que nextCPU == N
    }
    nodesHeap->~Heap();
    temporalHeap->~Heap();
    cout << "No se pudo encontrar el costo minimo para la matriz de costo";
    return 1;
} 
