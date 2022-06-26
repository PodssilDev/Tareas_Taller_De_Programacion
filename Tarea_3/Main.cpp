#include "Optimizer.h" // Optimizer incluye a objective y objective incluye a ImageProcessor
#include "Image.h"

// Archivo principal. Se realiza el proceso de restauracion de la imagen y se calcula
// el tiempo de ejecucion. A diferencia de tareas anteriores, esta vez, no hay multiples
// iteraciones (Ademas de que eso causaria errores de memoria)
// Ya que este archivo requiere de crearTxt.py, se recomienda utilizar make run luego
// de compilar los archivos.

int main() {
    unsigned t0, t1;
    double time, time2;
    int N = 256; // Se setea el tamano de la imagen
    int K;
    float ftol = 1e-12; // Se setea la tolerancia
    int max_it = 100; // Se setea el maximo de iteraciones
    Image  *I_corrupted = new Image(N); // Se crea una nueva imagen
    I_corrupted->loadImageFromTxt("image_corrupted.txt"); // Se carga la imagen
    Objective *o = new Objective(I_corrupted, new ImageProcessor());
    float *f = new float[N*N]; // Se crea un arreglo de tamano N*N
    cout << "Ingrese el numero de pruebas para el programa: " << endl;
    cin >> K;
    for(int i = 0; i < K; i++){
        t0 = clock(); // Para el calculo del tiempo // Se crea un objetivo
        Optimizer *optimizer = new Optimizer(o,f,N*N,ftol,max_it); // Se crea un optimizador
        optimizer->frprmn(); // Se llama a frpmn para hacer todo el proceso de restauracion
        t1 = clock(); // Para el calculo del tiempo
        time = (double(t1-t0)/CLOCKS_PER_SEC); // Se calcula el tiempo de ejecucion
        cout << "Tiempo de ejecucion: " << time << "[s]" << endl;
    }
    Image *I_restored = new Image(f,N); // Se crea una nueva imagen con los valores de f
    I_restored->saveImageToTxt("restored.txt");   // Se guarda la imagen restaurada a  un .txt
    time2 = time / K;
    cout << "Tiempo promedio: " << time2 << "[s]" << endl;
    return 0;
}
