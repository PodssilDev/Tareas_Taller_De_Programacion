#include "Hamiltonian.h"

/*
En la clase main se tiene un input que pide la cantidad de iteraciones a realizar.
Se recomienda probar con 50 iteraciones. En cada iteracion, se parte con probabilidad
0,03 para crear el grafico y comprobar si se tiene un ciclo hamiltoniano. Una interacion
se acaba una vez que se logra encontrar un ciclo hamiltoniano y se registra la
probabilidad con la que se encontro el ciclo. Al final se calcula el tiempo promedio
de cada iteracion y la probabilidad promedio de encontrar un ciclo hamiltoniano.
El programa fue optimizado tal que pueda funcionar de manera eficiente con 300 nodos.
*/

int main(){
    float PP = 0; // Variable para la probabilidad promedio
    float p; // Variable para la probabilidad
    unsigned t0, t1; // Variables para el calculo del tiempo
    double time, time2; // Variables para el calculo del tiempo
    int N; // Cantidad de iteraciones
    Hamiltonian h(15); // Se construye un hamiltoniano. AQUI SE PUEDE CAMBIAR EL TAMANO.
    cout << "Ingrese la cantidad de iteraciones: ";
    cin >> N;
    for(int k = 1; k <= N; k++){
        cout << "Iteracion Numero " <<  k << endl;
        p = 1.0 / 30; // Se parte buscando con probabilidad 1/30
        cout << "Buscando con p = " << p << endl;
        h.createGraph(p); // Se crea un grafo con la probabilidad inicial
        //h.printGraph(); // Aqui se puede comprobar como se creo el grafo.
        t0 = clock();
        while(!h.solve()){ // Aqui se busca encontrar un ciclo hamiltoniano
            p += 1.0 / 30; // Si no se encontro, se aumenta la probabilidad
            cout << "Buscando con p = " << p << endl;
            usleep(50000); // Se duerme el programa para no tener problemas con los grafos
            h.createGraph(p); // Se crea otro grafo con la nueva proabbilidad
            //h.printGraph(); 
        }
        t1 = clock();
        time2 = (double(t1 - t0) / CLOCKS_PER_SEC); // Calculo de tiempo de iteracion
        time = time2 + time;
        cout << "Iteracion completada en: " << time2 << "[s]" << endl;
        cout << "\n";
        PP = PP + p; // Se suma la probabilidad a la probabilidad promedio
    }
    PP = PP / N; // Calculo de probabilidad promedio
    cout << "Tiempo promedio: " << time / N << "[s]" << endl;
    cout << "El promedio de la probabilidad es: " <<  PP << endl;
    return 0;
}
