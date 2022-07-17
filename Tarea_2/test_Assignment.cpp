#include "Assignment.h"

// TEST de Assignment, se prueban las siguientes funciones:
// Assignment
// getCost
// Solve
int main() {
    Assignment assignado(100);
    Cost* costMatrix = assignado.getCost();
    assignado.solve(costMatrix);
    return 0;
}
// Cabe destacar de que Assignment se utiliza en todo el programa principal.
