#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include <iostream>
#include <random>
using namespace std;
#include "Image.h"
#define KERNEL_SIZE 5 // Constante que servira para el proceso de corrupcion (Imagen Pequena)
#define SIGMA 0.05 // Constante que servira para el proceso de corrupcion

// La clase ImageProcessor representa a la clase que realiza el procesamiento de la imagen
// y las distintas operaciones con estas, como lo es agregar ruido o corromper la imagen

class ImageProcessor {
public:
    ImageProcessor(); // Constructor de la clase
    ~ImageProcessor(); // Destructor de la clase
    Image* convolve(Image * Kernel, Image * I); // Metodo que realiza una convulsion de una imagen
    Image* addNoise(Image * I); // Metodo que agrega ruido a la imagen
    Image* corrupt(Image* I); // Metodo que corruciona la imagen
    Image* setAllPixel(Image* I, float value); // Metodo que asigna un valor a todos los pixeles de la imagen
    Image* subtract(Image* I1, Image* I2); // Metodo que "resta" de los pixeles de dos imagenes
    Image* add(Image* I1, Image* I2); // Metodo que "suma" los pixeles de dos imagenes
    Image* multiply(float x, Image* I2); // Metodo que pondera los pixeles de una imagen
};
#endif
