#include "Hamiltonian.h"

/*
TEST PARA LA CLASE Hamiltonian, SE PRUEBAN LAS SIGUIENTES FUNCIONALIDADES PUBLICAS:
Hamiltonian()
getSize()
createGraph()
printGraph()
solve()
~Hamiltonian()
Interamente se prueban getValue(), verify(), solveMain() y printSolution()
*/
int main(){
    float p = 0.43; // Variable para la probabilidad
    Hamiltonian h(15); // TEST Hamiltonian()
    cout << "Numero de nodos del grafo: " << h.getSize() << endl; // TEST getSize()
    cout << "Buscando con p = " << p << endl;
    h.createGraph(p); // TEST createGraph()
    h.printGraph(); // TEST printGraph()
    if(h.solve() == false){ // TEST solve()
        cout << "Pruebe ejecutando denuevo el TEST para encontrar un ciclo" << endl;
    }
    return 0;
}
