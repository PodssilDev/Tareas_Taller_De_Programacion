#include "Assignment.h"

// En la clase main se tiene un input que pide la cantidad de pruebas, es decir,
// la cantidad de matrices que se generaran. Se calcula el tiempo de cada uno
// y luego se imprime el promedio total que toma resolver las N matrices.
// Para efectos de la tarea, se tienen matrices de 500 x 500, aunque esto puede 
// reducirse si se desea. Se recomienda probar con 25 iteraciones, para evitar
// posibles errores de memoria.

int main(){
    unsigned t0, t1;
    double time, time2;
    int N;
    // Si se desea probar con otras dimensiones para la matriz, se debe cambiar el
    // parametro de assignado (Representa la dimension de la matriz de costo.)
    Assignment assignado(500);
    Cost* costMatrix = assignado.getCost();
    cout<<"Ingrese cantidad de pruebas: ";
    cin >> N;
    for(int i = 0; i < N; i++){
        cout<<"Matriz n: ";
        cout<< (i+1);
        cout << "\n";
        costMatrix->print();
        t0 = clock();
        assignado.solve(costMatrix);
        t1 = clock();
        time2 = (double(t1-t0) / CLOCKS_PER_SEC);
        time = time2 + time;
        cout << "Solved in: " << time2 << "[s]" << endl;
        cout << "\n";
        costMatrix->generateCost();
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
