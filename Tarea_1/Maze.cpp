#include "Maze.h"

/*
La clase Maze consiste en la clase del laberinto. Aqui es donde se genera y se tiene el 
algoritmo A* para encontrar el camino mas eficiente desde la entrada hacia la salida.
*/

// Generador de la clase, utilizando la dimension y el porcentaje de void (caminos)
Maze::Maze(int dim, int p) {
    srand(time(NULL)); // set seed for random number generator
    Maze::dim = dim;
    Maze::void_percentage=p;
    Maze::arr = nullptr;
    Maze::generate();
}

// Destructor de la clase
Maze::~Maze() {
    for (int i = 0; i < dim; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

// Genera el laberinto, y determina que elemento corresponde a cada posicion del laberinto
void Maze::generate() {
  if(arr == nullptr){
    arr = new int*[dim];
    for (int i = 0; i < dim; i++) {
      arr[i] = new int[dim];
      for (int j = 0; j < dim; j++) {
        arr[i][j] = rand() % 100 < void_percentage ? EMPTY : WALL;
        }
      }
    arr[0][0] = IN_DOOR;
    arr[dim-1][dim-1] = OUT_DOOR;
    return;
    }

    // set the entrance and exit
      for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
          arr[i][j] = rand() % 100 < void_percentage ? EMPTY : WALL;
        }
      }
    arr[0][0] = IN_DOOR;
    arr[dim-1][dim-1] = OUT_DOOR;
}

// Imprime el laberinto (Si es sobre 170 x 170, en algunas pantallas la impresion 
// puede verse un poco bugueada)
void Maze :: print(){
  for(int i = 0 ; i < dim; i++){
    for(int j = 0; j < dim; j++){
      if(arr[i][j] == WALL){ 
        cout << "#";
      }
      else if(arr[i][j] == EMPTY){
        cout << " ";
      }
      else if(arr[i][j] == IN_DOOR){
        cout << "2";
      }
      else if(arr[i][j]  == OUT_DOOR){
        cout << "3";
      }
      else if(arr[i][j] == VISITED){
        cout << "\033[1;33mX\033[0m";
      }
    }
    cout << "\n";
  }
}

// Resuelve el laberinto, determinando la el camino mas eficiente desde la entrada hacia
// la salida, o bien, determina si es que no hay un camino efiente o valido. Corresponde
// al Algoritmo A*
void Maze::solve(){
  bool terminado = false; 
  Heap heap = Heap(dim*dim); // Dimension debe ser 1000 * 1000 (dim * dim)
  int value = 0; // Heuristica - valor de los nodos
  Container *closelist = new Container(dim); // Nuestra closelist es una Matriz
  Node *current = new Node(0, 0, value, NULL); // Nodo inicial
  Node *neightbor; // Para los vecinos del nodo actual
  heap.insert(current); // Se inserta el nodo inicial en la Heap

  while(not(heap.isEmpty())){
    current = heap.pull(); // Utilizamos pull para obtener el nodo de menor valor
    closelist->insert(current->get_i(), current->get_j()); // Marco en la matriz el nodo actual
    if(arr[current->get_i()][current->get_j()] == OUT_DOOR){ 
      terminado = true; // Si se encuentra la salida, entonces se acabo el proceso
      break;
    }
    // Se verifica si es un camino valido y se puede mover
    if(((current->get_i()-1) >= 0) && ((arr[(current->get_i())-1][current->get_j()] == EMPTY)|| (arr[(current->get_i())-1][current->get_j()] == OUT_DOOR))){
      value = heuristica((current->get_i()-1), current->get_j(), dim);
      Node *neightbor = new Node((current->get_i()-1), current->get_j(), value, current);
      if(not(closelist->clfind(current->get_i()-1, current->get_j()))){
        heap.insert(neightbor); // Si no esta en la closelist, se agrega a la Heap
      }
    }
    // Se verifica si es un camino valido y se puede mover
    if(((current->get_i()+1) < dim) && ((arr[current->get_i()+1][current->get_j()] == EMPTY)|| (arr[(current->get_i())+1][current->get_j()] == OUT_DOOR))){
      value = heuristica(current->get_i()+1, current->get_j(), dim);
      Node *neightbor = new Node(current->get_i()+1, current->get_j(), value, current);
      if(not(closelist->clfind(current->get_i()+1, current->get_j()))){
        heap.insert(neightbor); // Si no esta en la closelist, se agrega a la Heap
      }
    }
    // Se verifica si es un camino valido y se puede mover
    if(((current->get_j() -1) >= 0) && ((arr[current->get_i()][current->get_j()-1] == EMPTY)|| (arr[(current->get_i())][current->get_j()-1] == OUT_DOOR))){
      value = heuristica(current->get_i(), current->get_j()-1, dim);
      Node *neightbor = new Node(current->get_i(), current->get_j()-1, value, current);
      if(not(closelist->clfind(current->get_i(), current->get_j()-1))){
        heap.insert(neightbor); // Si no esta en la closelist, se agrega a la Heap
      }
    }
    // Se verifica si es un camino valido y se puede mover
    if(((current->get_j() + 1) < dim) && ((arr[current->get_i()][current->get_j()+1] == EMPTY) || (arr[(current->get_i())][current->get_j()+1] == OUT_DOOR))){
      value = heuristica(current->get_i(), current->get_j()+1, dim);
      Node* neightbor = new Node(current->get_i(), current->get_j()+1, value, current);
      if(not(closelist->clfind(current->get_i(), current->get_j()+1))){
        heap.insert(neightbor); // Si no esta en la closelist, se agrega a la Heap
      }
    }
  }
  if (terminado == true){ // Si se encontro un camino
    markMaze(current); // Se marcan los nodos del camino para que se vea el camino en el print
    Maze::print();
    cout << "\n";
    cout << current->getPath();
    cout << "\n";
  }
  else{ // Si no se encontro camino
    Maze::print();
    cout << "\n";
    cout << "No hay camino disponible";
    cout << "\n";
  }
}

// Calcula el "valor" que tiene un nodo del laberinto, de acuerdo a su distancia con 
// la salida. Recibe las posiciones i,j junto con la dimension del laberinto.
int Maze::heuristica(int i, int j, int dim){
  int value = 0;
  value = sqrt(pow(i - (dim-1), 2) + pow(j - (dim-1), 2));
  return value;
}

// Marca los nodos que se agregan en la Close List (Container) para asi marcar el camino
// en la impresion del laberinto
void Maze::markMaze(Node *node){
  while (node->getPrevious() != NULL){
    int i = node -> get_i();
    int j = node->get_j();
    arr[i][j] = VISITED;
    node = node->getPrevious();
  }
}
