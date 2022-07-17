#include "Hamiltonian.h"

/*
"Hamiltonian" es la clase mas importante en esta tarea. En ella se crea el grafo
a buscar y se tienen los metodos de solve para asi buscar si el grafo generado tiene
o no un ciclo hamiltoniano. 
*/

/* 
Entrada: Un entero correspondiente a un tamano
Salida: Un Hamiltonian con un tamano especifico
Descripcion: Metodo que crea un Hamiltonian. Un Hamiltonian contiene un tamano,
un vector de vectores de enteros el cual se utilizara para el grafo a crear y un 
vector de enteros correspondiente al camino a armar para el ciclo hamiltoniano.
*/
Hamiltonian::Hamiltonian(int size){
    Hamiltonian::size = size;
    Hamiltonian::graph = vector<vector<int>>(size);
    for(int i = 0; i < size; i++){
        graph[i].insert(graph[i].begin(), size, 0); // Inicializa el grafo con 0s
    }
    Hamiltonian::path = vector<int>(size);
    path.insert(path.begin(), size, -1); // Se inicializa el vector solo con -1s
}

/*
Entrada: No tiene entrada
Salida: No tiene salida como tal, pero se destruye el Hamiltonian
Descripcion: Metodo que destruye un Hamiltonian
*/
Hamiltonian::~Hamiltonian(){
    for(int i = 0; i < size; i++){
        graph[i].clear();
    }
    graph.clear();
    path.clear();
}

/*
Entrada: No tiene entrada
Salida: Un entero que representa el tamano guardado en Hamiltonian
Descripcion: Metodo que obtiene el tamano guardado en Hamiltonian
*/
int Hamiltonian::getSize(){
    return size;
}

/*
Entrada: Un flotante correspondiente a una probabilidad
Salida: No tiene salida como tal, pero se crea el grafo con una probabilidad especifica
Descripcion: Metodo que crea el grafo con una probabilidad especifica. 
*/
void Hamiltonian::createGraph(float p){
    srand(time(NULL)); // Se inicializa el generador de numeros aleatorios
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(double(rand())/RAND_MAX < p){ // Usamos la probabilidad
                graph[i][j] = 1; // Conexion
                graph[j][i] = 1;
            }
            else{
                graph[i][j] = 0;
                graph[j][i] = 0;
            }
        }
    }
}

/*
Entrada: No tiene entrada
Salida: No tiene salida como tal, pero imprime por consola
Descripcion: Metodo que imprime por consola el grafo generado
*/
void Hamiltonian::printGraph(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

/*
Entrada: Un entero correspondiente al numero de un nodo
Salida: Un entero que representa el numero de conexiones del nodo especificado
Descripcion: Metodo que obtiene el numero de conexiones del nodo especificado
*/
int Hamiltonian::getValue(int i){
    return count(graph[i].begin(), graph[i].end(), 1);
}

/*
Entrada: No tiene entrada
Salida: Un booleano que representa si todos los nodos tienen conexiones mayores o 
iguales a 2
Descripcion: Metodo que verifica si todos los nodos tienen conexiones mayores o 
iguales a 2. Si es asi, retorna true. Caso contrario, retorna false.
*/
bool Hamiltonian::verify(){
    for(int i = 0; i < size; i++){
        if(count(graph[i].begin(), graph[i].end(), 1) < 2){
            return false;
        }
    }
    return true;
}

/*
Entrada: No tiene entrada como tal
Salida: No tiene salida como tal, pero imprime por consola
Descripcion: Metodo que imprime por consola el camino del ciclo hamiltoniano encontrado,
junto con un mensaje de exito de color verde.
*/
void Hamiltonian::printSolution(){
	cout << "\033[1;32mSe encontro un ciclo Hamiltoniano!\033[0m\n";
    cout << "El ciclo Hamiltoniano es: ";
	for (int i = 0; i < size; i++){
		cout << path[i] << " ";
    }
    // Unimos el nodo inicial para completar el camino
	cout << path[0] << " ";
	cout << endl;
    path.clear(); // Limpiamos el camino para preparar para la proxima iteracion
}

/*
Entrada: No tiene entrada
Salida: Un booleano que representa si el grafo generado tiene o no un ciclo hamiltoniano
Descripcion: Metodo que busca si el grafo generado tiene o no un ciclo hamiltoniano, 
verificando y guardando el camino generado.
*/
bool Hamiltonian::solveMain(){
    int maxvalue = 0;  // Variable para el valor del Nodo inicial
    int index = 0; // Variable para el numero del Nodo inicial
    Heap* heap = new Heap(size*size); // Heap principal
    Heap* heap2 = new Heap(size*size); // Heap temporal
    for(int i = 0; i < size; i++){ // Obtenemos el valor del Nodo inicial
        int value = getValue(i); // Obtenemos los valores de cada Nodo
        if(value > maxvalue){ // El Nodo inicial es el que tiene mayor valor
            maxvalue = value;
            index = i;
        }
    }
    Node* node = new Node(index,maxvalue); // Se crea un nuevo Nodo
    for(int i = 0; i < size; i++){ // Iterando
        int value = getValue(i); // Se obtiene el valor de cada Nodo
        Node *n = new Node(i ,value); // Se crean nuevos Nodos
        if(n->get_i() != index){ // Si el Nodo no es el inicial
            heap->insert(n); // Se agrega a la Heap el Nodo
        }
    }
    int pos = 1; // Variable para la posicion del camino
    path[0] = node->get_i(); // Se guarda el nodo inicial en el camino
    while(not(heap->isEmpty())){ // Mientras la heap no este vacia
        Node *current = heap->pull(); // Se obtiene el nodo actual
        int v = current->get_i(); // Se obtiene el numero del nodo actual
        // Si el nodo actual no esta en el camino y ademas tiene conexion con el nodo anterior
        if((count(path.begin(), path.begin()+pos, v) != 1) && (graph[path[pos - 1]][v] != 0)){
            path[pos] = v; // Se guarda el numero del Nodo actual en el camino
            pos = pos + 1; // Se incrementa la posicion del camino
            while(not(heap2->isEmpty())){ // Mientras la Heap2 no este vacia
                heap->insert(heap2->pull()); // Volvemos a insertar los nodos de la Heap2 en la Heap
            }
            current->~Node(); // Se elimina el Nodo actual
            node->~Node(); // Se elimina el Nodo inicial
            heap2->~Heap(); // Se elimina la Heap2
            heap2 = new Heap(size*size); // Se vuelve a crear la Heap2
        }
        else{ // Si el nodo actual ya esta en el camino o no tiene conexion con el nodo anterior
            heap2->insert(current); // Lo guardamos temporalmente en Heap2
        }
    }
    heap->~Heap(); // Se elimina la Heap
    heap2->~Heap(); // Se elimina la Heap2
    if (pos == size){ // Si el camino tiene el mismo numero de nodos que el grafo

        if (graph[path[pos - 1]][path[0]] == 1){ // Si el nodo final tiene conexion con el inicial
            return true;
        }
        else{ // Si el nodo final no tiene conexion con el inicial
            return false;
        }
    }
    else{ // Si el camino no tiene el mismo numero de nodos que el grafo
        return false;
    }
    // Si algo fallo o no se pudo encontrar el camino correctamente
    return false;
}

/*
Entrada: No tiene entrada
Salida: Un booleano que representa si el grafo generado tiene o no un ciclo hamiltoniano
Descripcion: Metodo que busca si el grafo generado tiene o no un ciclo hamiltoniano,
en esta primera parte, se realizan algunas verificaciones para descartar si el grafo
tiene o no un ciclo hamiltoniano. Si las verificaciones no fallan, se llama al metodo
solveMain(). Si se obtuvo un ciclo hamiltoniano, se llama al metodo printSolution().
*/
bool Hamiltonian::solve(){
    if(verify() == false){ // Si el grafo no tiene conexiones mayores o iguales a 2
        cout << "\033[0;31mNo se encontro un ciclo Hamiltoniano.\033[0m\n";
        cout << "\n";
        path.clear(); // Limpiamos el camino
        return false;
    }
    if (solveMain() == false ){ // Si no se pudo encontrar un ciclo Hamiltoniano
		cout << "\033[0;31mNo se encontro un ciclo Hamiltoniano.\033[0m\n";
        cout << "\n";
        path.clear(); // Limpiamos el camino
		return false;
	}
    printSolution(); // Si se encontro el ciclo Hamiltoniano, se llama a printSolution()
	return true; // Retornamos true si se encontro el ciclo Hamiltoniano
}
