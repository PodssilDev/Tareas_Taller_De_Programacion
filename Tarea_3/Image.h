#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// La clase Imagen representa a la clase de la Imagen, donde esta Imagen se puede 
// transformar a un archivo de texto .txt para asi poder realizar el proceso de 
// corrucion

class Image {
public:
    Image(int N); // Constructor de la clase imagen
    Image(float *p, int N); // Constructor de la clase Imagen
    ~Image(); // Destructor de la clase
    void loadImageFromTxt(string filename); // Metodo que carga una imagen en forma de archivo de texto
    void saveImageToTxt(string filename); // Metodo que guarda una imagen en forma de archvo de texto
    float getPixel(int i, int j); // Metodo que accede a un pixel de la imagen en especifico
    void setPixel(int i, int j, float value); // Metodo que modifica un pixel de la imagen
    int getN(); // Metodo que obtiene el tamano del arreglo de la imagen
private:
    int N; // Tamano del arreglo de la imagen
    float *image; // Representa la imagen, en forma de arreglo
};
#endif
