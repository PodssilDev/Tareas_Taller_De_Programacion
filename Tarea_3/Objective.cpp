#include "Objective.h"

// Objective representa la clase que contiene la funcion objetivo. Es una clase
// que es utilzada por Optimizer

// Entrada: No tiene entrada 
// Salida: Un objective
// Descripcion: Metodo que crea una instancia de la clase Objective
Objective::Objective(){
}

// Entrada: Una imagen corrupta y un procesador de imagen
// Salida: Un objective
// Descripcion: Metodo que crea una instancia de la clase Objective, guardando en esta
// la imagen corrupta y un procesador de imagen
Objective::Objective(Image *I_corrupted, ImageProcessor *processor) {
    this->I_corrupted = I_corrupted; // Es la imagen corrupta
    this->processor = processor; // Es un procesador de imagen
}

// Entrada: No tiene entrada
// Salida: No tiene salida como tal
// Descripcion: Metodo que destruye la instancia de la clase Objective
Objective::~Objective(){
}

// Entrada: Un arreglo de flotantes p y un entero n
// Salida: Un flotante
// Descripcion: Metodo que corresponde al calculo del valor de la funcion objectivo
float Objective::F(float* p, int n){
    float f = 0;
    // Calcula 0.5 por la suma de los cuadrados de K*p-Icorrupted
    // I es la imagen corrupta
    int N = I_corrupted->getN(); // Se obtiene el N de la imagen corrupta
    Image *I=new Image(p,N); // Se crea una nueva imagen
    Image * newImage;
    Image* kernel = new Image(KERNEL_SIZE);  // Se crea el kernel
    kernel=processor->setAllPixel(kernel, 1.0/(KERNEL_SIZE*KERNEL_SIZE)); // Se setea el kernel
    newImage=processor->convolve(kernel,I); // Se realiza la convolusion entre kernel y la imagen
    newImage=processor->subtract(newImage,I_corrupted); // Ahora la resta de K*p - Icorrupted
    for(int i = 0; i < N; i++){ // Se itera y se realiza la suma de los cuadrados de los pixeles de la imagen
        for(int j = 0; j < N; j++){
            f += newImage->getPixel(i, j) * newImage->getPixel(i, j);
        }
    }
    return f; // Se retorna el valor de la funcion objectivo
} 

// Entrada: Un arreglo de flotantes p y un arreglo de flotantes xi
// Salida: No tiene salida como tal
// Descripcion: Funcion que calcula el gradiente de la funcion objetivo (xi).
// gradiente = K*(K*p-Icorrupted)
// Notar que el codigo es similar a lo anterior, solo con dos lineas extras
void Objective::dF(float* p, float* xi){
    int N = I_corrupted->getN(); //  Se obtiene el N de la imagen corrupta
    Image *I = new Image(p,N); // Se crea una nueva imagen
    Image *newImage;
    Image *kernel = new Image(KERNEL_SIZE); // Se crea el kernel
    kernel = processor->setAllPixel(kernel, 1.0/(KERNEL_SIZE*KERNEL_SIZE)); // Se setea el kernel
    newImage = processor->convolve(kernel,I); // Se realiza la convolusion entre kernel y la imagen
    newImage = processor->subtract(newImage, I_corrupted); // Ahora la resta de K*p - Icorrupted
    newImage = processor->convolve(kernel, newImage); // Se realiza entre el kernel y la nueva imagen
    for(int i = 0; i < N; i++){ // Iterando
        for(int j = 0; j < N; j++){
            xi[i*N+j] = newImage->getPixel(i,j); // Se modifican los valores de xi, copiando los pixeles de la imagen nueva
        }
    }
}
