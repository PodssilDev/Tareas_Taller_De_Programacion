#include "Maze.h"

// TEST de maze, se prueban las siguientes funciones:
// Maze
// print
// solve
// generate
// heuristica
// markMaze
int main() {
    Maze m(100,80); // TEST MAZE Y GENERATE
    m.solve(); // TEST SOLVE, PRINT, HEURISTICA Y MARKMAZE
    return 0;

}
// Cabe destacar que en Maze se utiliza generate y en solve se prueban print
// heuristica y markMaze. print nos permite verificar que el camino sea correcto
// y valido gracias a markMaze.
