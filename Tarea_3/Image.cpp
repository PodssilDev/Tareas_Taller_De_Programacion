#include "Image.h"

// La clase Imagen representa a la clase de la Imagen, donde esta Imagen se puede 
// transformar a un archivo de texto .txt para asi poder realizar el proceso de 
// corrucion

// Entrada: Un numero entero que representa el tamano del arreglo de la imagen
// Salida: Crea una instancia de la clase Imagen
// Descripcion: Metodo que crea una instancia de la clase Imagen, recibiendo un
// numero entero que representa el tamano del arreglo de la imagen
Image::Image(int N) {
    this->N = N; // Tamano de la imagen
    image = new float[N * N]; // Creacion del arreglo de la imagen
}

// Entrada: Un arreglo de flotantes p y un numero entero N que representa el tamano del arreglo
// Salida: Crea una instancia de la clase Imagen
// Descripcion: Metodo que crea una instancia de la clase Imagen, recibiendo un
// arreglo de flotantes p que representa la imagen y un numero entero N que
// representa el tamano del arreglo
Image::Image(float *p, int N) {
    this->N = N; // Tamano de la imagen
    image = new float[N * N]; // Se crea un nuevo vector de la imagen
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            image[i * N + j] = p[i * N + j]; // Se igualan los valores de los pixeles de la imagen con los de p
        }
    }
}

// Entrada: No tiene entrada
// Salida: No tiene salida como tal
// descripcion: Metodo que elimina la instancia de la clase Imagen
Image::~Image() {
    delete[] image;
}

// Entrada: Un string que representa el nombre del archivo de texto
// Salida: No tiene salida como tal
// Descripcion: Metodo que carga una imagen en forma de archivo de texto .txt
void Image::loadImageFromTxt(string filename) {
    ifstream infile;
    infile.open(filename); // Se abre el archivo
    if (!infile) {
        cout << "Error al abrir el archivo. ¿Pruebe usando ./make run?" << endl; // Si no se puede abrir el archivo
        exit(1); 
    }
    for (int i = 0; i < N; i++) { // Realiza toda la carga del archivo de texto
        for (int j = 0; j < N; j++) {
            infile >> image[i * N + j];
        }
    }
    infile.close(); // Se cierra el archivo para no tener problemas con el buffer
}

// Entrada: Un string que representa el nombre del archivo de texto
// Salida: No tiene salida como tal
// Descripcion: Metodo que guarda una imagen en forma de archvo de texto
void Image::saveImageToTxt(string filename) {
    ofstream outfile;
    outfile.open(filename); // Se abre el archivo
    if (!outfile) {
        cout << "Error opening file" << endl; // Si no se puede abrir el archivo
        exit(1);
    }
    for (int i = 0; i < N; i++) { // Realiza todo el almacenamiento del archivo de texto
        for (int j = 0; j < N; j++) { 
            outfile << image[i * N + j] << endl;
        }
    }
    outfile.close(); // Se cierra el archivo para no tener problemas con el buffer
}

// Entrada: Dos numeros enteros i,j
// Salida: Una posicion especifica de la imagen
// Descripcion: Metodo que accede a un pixel de la imagen en especifico
float Image::getPixel(int i, int j) {
    return image[i * N + j];
}

// Entrada: Dos numeros enteros i,j y un numero flotante value
// Salida: No tiene salida como tal
// Descripcion: Metodo que modifica un pixel de la imagen, dejandolo igual a value
void Image::setPixel(int i, int j, float value) {
    image[i * N + j] = value;
}

// Entrada: No tiene entrada
// Salida: Un numero entero N
// Descripcion: Metodo que obtiene el tamano del arreglo de la imagen
int Image::getN() {
    return N;
}
