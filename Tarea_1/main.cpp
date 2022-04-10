#include "Maze.h"
#include <time.h>

// En la clase main se tiene un input que pide la cantidad de pruebas, es decir,
// la cantidad de laberintos que se generaran. Se calcula el tiempo de cada uno
// y luego se imprime el promedio total que toma resolver los N laberintos.

int main(){
    unsigned t0, t1;
    double time, time2;
    int N;
    // Si se desea probar con otras dimensiones de laberintos, se debe cambiar el
    // primer parametro (Representa la dimension del laberinto.)
    Maze m(1000, 90);
    cout<<"Ingrese cantidad de pruebas: ";
    cin >> N;
    for(int i = 0; i < N; i++){
        cout<<"Laberinto n: ";
        cout<< (i+1);
        cout << "\n";
        t0 = clock();
        m.solve();
        t1 = clock();
        time2 = (double(t1-t0) / CLOCKS_PER_SEC);
        time = time2 + time;
        cout << "Solved in: " << time2 << "[s]" << endl;
        cout << "\n";
        m.generate();
    }
    cout << "Suma de todos los tiempos: ";
    cout << time;
    cout << "\n";
    time = time / N;
    cout<< "Tiempo promedio:" ;
    cout << time;
    cout << "\n";
    return 0;
}
