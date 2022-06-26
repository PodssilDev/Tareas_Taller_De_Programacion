#include "ImageProcessor.h"

// La clase ImageProcessor representa a la clase que realiza el procesamiento de la imagen
// y las distintas operaciones con estas, como lo es agregar ruido o corromper la imagen

// Entrada: No tiene entrada
// Salida: No tiene salida como tal
// Descripcion: Metodo que crea una instancia de la clase ImageProcessor
ImageProcessor::ImageProcessor(){
}

// Entrada: No tiene entrada
// Salida: No tiene salida como tal
// Descripcion: Metodo que elimina la instancia de la clase ImageProcessor
ImageProcessor::~ImageProcessor(){
}

// Entrada: Una instancia de la clase Image que representa la imagen y otra imagen
// mas pequena
// Salida: Crea una nueva Imagen
// descripcion: Metodo que realiza una convulsion de una imagen
Image * ImageProcessor::convolve(Image * Kernel, Image * I){
    int N = I->getN(); // Obtengo el tamano del arreglo
    int M = (Kernel->getN()-1)/2; // Obtengo el tamano del arreglo de Kernel
    Image* convolved = new Image(N); // Creo una nueva Imagen
    for (int i = 0; i < N; i++) { // Iteramos la imagen
        for (int j = 0; j < N; j++) {
            float sum = 0;
            for (int k = -M; k < M; k++) {
                for (int l = -M; l < M; l++) {
                    if (i + k >= 0 && i + k < N && j + l >= 0 && j + l < N) {
                        // Se realiza la convolusion pixel por pixel
                        sum += I->getPixel(i + k, j + l) * Kernel->getPixel(k + M, l + M);
                    }
                }
            }
            convolved->setPixel(i, j, sum); // Modifica los pixeles con el resultado de la convolusion
        }
    }
    return convolved; // Retorna la nueva Imagen
}

// Entrada: Una imagen y un valor flotante
// Salida: Una nueva Imagen
// Descripcion: Metodo que asigna un valor a todos los pixeles de la imagen y crea una
// nueva imagen considerando lo anterior
Image * ImageProcessor::setAllPixel(Image * I, float value){
    int N = I->getN(); // Obtiene el tamano del arreglo
    Image * newImage = new Image(N); // Crea la nueva Imagen
    for(int i = 0; i < N; i++){ // Iteramos la imagen
        for(int j = 0; j < N; j++){
            newImage->setPixel(i, j, value); // Modifica los pixeles con el valor dado
        }
    }
    return newImage; // Retorna la nueva Imagen
}

// Entrada: Una imagen
// Salida: Una nueva Imagen
// Descripcion: Metodo que agrega ruido a la Imagen, utilizando una distribucion
// normal en el proceso
Image * ImageProcessor::addNoise(Image * I){
    int N = I->getN(); // Obtenemos el tamano del arreglo
    Image * newImage = new Image(N); // Se crea la nueva Imagen
    random_device rd; // Motor de numeros aleatorios
    normal_distribution<float> normal(0, SIGMA); // Creamos una distribucion normal
    for(int i = 0; i < N; i++){ // Iteramos la imagen
        for(int j = 0; j < N; j++){
            newImage->setPixel(i, j, I->getPixel(i, j) + normal(rd)); // Agregamos el ruido
        }
    }
    return newImage;  // Retorna la nueva Imagen
}

// Entrada: Una imagen
// Salida: Una nueva Imagen corrompida
// Descripcion: Metodo que corrompe la Imagen, agregandole ruido y modificando sus
// pixeles
Image * ImageProcessor::corrupt(Image * I){
    int N = I->getN(); // Se obtiene el tamano del arreglo
    Image * newImage; // Se crea la nueva Imagen
    Image* kernel = new Image(KERNEL_SIZE); // Se crea el Kernel
    kernel=setAllPixel(kernel, 1.0/(KERNEL_SIZE*KERNEL_SIZE)); // Se asigna el valor 1/KERNEL_SIZE^2 a todos los pixeles del Kernel
    newImage=convolve(kernel,I); // Se realiza la convolucion entre el Kernel y la IMagen
    newImage=addNoise(newImage); // Se agrega el ruido a la Imagen, dejandola totalmente corrompida
    return newImage; // Se retorna la nueva Imagen
}

// Entrada: Dos imagenes
// Salida: Una nueva Imagen
// Descripcion: Metodo que recibe dos Imagenes y realiza la resta de los pixeles de las dos.
// Guarda el resultado en una nueva Imagen.
Image * ImageProcessor::subtract(Image * I1, Image * I2){
    int N = I1->getN(); // Obtiene el tamano de la imagen 1
    Image * newImage = new Image(N); // Se crea una nueva imagen
    for(int i = 0; i < N; i++){ // Se itera y se realiza la resta de los pixeles de las dos imagenes
        for(int j = 0; j < N; j++){ // Se guarda el resultado en una nueva Imagen
            newImage->setPixel(i, j, I1->getPixel(i, j) - I2->getPixel(i, j));
        }
    }
    return newImage; // Retorna la nueva Imagen
}

// Entrada: Dos imagenes
// Salida: Una nueva Imagen
// Descripcion: Metodo que recibe dos Imagenes y realiza la suma de los pixeles de las dos.
// Guarda el resultado en una nueva Imagen.
Image * ImageProcessor::add(Image * I1, Image * I2){
    int N = I1->getN(); // obtiene el tamano de la imagen 1
    Image * newImage = new Image(N); // Se crea la nueva Imagen
    for(int i = 0; i < N; i++){ // Se itera y se realiza la suma de los pixeles de las dos imagenes
        for(int j = 0; j < N; j++){ // Se guarda el resultado en una nueva Imagen
            newImage->setPixel(i, j, I1->getPixel(i, j) + I2->getPixel(i, j));
        }
    }
    return newImage; // Retorna la nueva Imagen
}

// Entrada: Un flotante y una imagen
// Salida: UNa nueva Imagen
// Descripcion: Metodo que recibe un flotante y una imagen. Los pixeles de la imagen son
// ponderados por el flotante y el resultado se guarda en una nueva Imagen.
Image * ImageProcessor::multiply(float x, Image * I2){
    int N = I2->getN(); // Se obtiene el tamano de la Imagen
    Image * newImage = new Image(N); // Se crea una nueva Imagen
    for(int i = 0; i < N; i++){ // Se itera y se ponderan los pixeles de la imagen
        for(int j = 0; j < N; j++){ // Se guarda el resultado en una nueva Imagen
            newImage->setPixel(i, j, x * I2->getPixel(i, j));
        }
    }
    return newImage; // Retorna la nueva Imagen
}
