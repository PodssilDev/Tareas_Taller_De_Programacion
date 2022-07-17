#include "Hamiltonian.h"

/*
TEST de EFICIENCIA. Aqui se prueba la eficiencia del programa.
Se prueban 50 iteraciones con un grafo de 300 nodos. Se muestra el tiempo promedio
de cada iteracion una vez que finalizan las 50 iteraciones.
*/

int main(){
    float PP = 0; // Variable para la probabilidad promedio
    float p; // Variable para la probabilidad
    unsigned t0, t1; // Variables para el calculo del tiempo
    double time, time2; // Variables para el calculo del tiempo
    Hamiltonian h(300); // Se construye un hamiltoniano. AQUI SE PUEDE CAMBIAR EL TAMANO.
    for(int k = 1; k <= 50; k++){
        cout << "Iteracion Numero " <<  k << endl;
        p = 1.0 / 30; // Se parte buscando con probabilidad 1/30
        cout << "Buscando con p = " << p << endl;
        h.createGraph(p); // Se crea un grafo con la probabilidad inicial
        t0 = clock();
        while(!h.solve()){ // Aqui se busca encontrar un ciclo hamiltoniano
            p += 1.0 / 30; // Si no se encontro, se aumenta la probabilidad
            cout << "Buscando con p = " << p << endl;
            usleep(50000); // Se duerme el programa para no tener problemas con los grafos
            h.createGraph(p); // Se crea otro grafo con la nueva proabbilidad
        }
        t1 = clock();
        time2 = (double(t1 - t0) / CLOCKS_PER_SEC); // Calculo de tiempo de iteracion
        time = time2 + time;
        cout << "Solved in: " << time2 << "[s]" << endl;
        cout << "\n";
        PP = PP + p; // Se suma la probabilidad a la probabilidad promedio
    }
    PP = PP / 50; // Calculo de probabilidad promedio
    cout << "Tiempo total: " << time << "[s]" << endl;
    cout << "Tiempo promedio: " << time / 50 << "[s]" << endl;
    cout << "El promedio de la probabilidad es: " <<  PP << endl;
    return 0;
}
