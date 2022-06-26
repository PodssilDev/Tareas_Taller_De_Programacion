#include "ImageProcessor.h"

// Este test realiza el procesamiento de una imagen con ruido y la corrupcion de la 
// imagen, cargando inicialmente el archivo del .txt y luego guardando la imagen corrompida
// en otro archivo .txt. Notar que este es el test de ImageProcessor, aunque se utilizan
// funciones de Image, aun asi se decidio hacer un test de Image aparte.

int main() {
    int N = 256; // Tamano del arreglo de la imagen (256 x 256)
    ImageProcessor *processor=new ImageProcessor(); // Definimos un nuevo procesador de imagen
    Image* corrupted;
    Image * I=new Image(N); // Nueva imagen
    I->loadImageFromTxt("image.txt"); // Carga la imagen desde un archivo .txt
    I->saveImageToTxt("image_original.txt"); // Guarda una copia de la imagen en un archivo .txt
    corrupted = processor->corrupt(I); // Corrupcion de la imagen
    corrupted->saveImageToTxt("image_corrupted.txt"); // Guarda la imagen corrompida a un archivo .txt
    return 0;
}
