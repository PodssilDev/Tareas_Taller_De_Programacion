#include "Cost.h"

// TEST de Cost, se prueban las siguientes funciones:
// cost
// print
int main() {
    Cost* costMatrix = new Cost(5);
    for(int i = 0; i < 3; i++){
        costMatrix->print();
        cout << "\n";
        cout << "Matriz de costo aleatoria";
        cout << "\n";
        costMatrix->generateCost();
    }
    return 0;

}
// Cabe destacar de que cost es utilizada en todo lo que es el algoritmo practicamente
