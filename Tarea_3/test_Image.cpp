#include "Image.h"

// ESTE ES UN TEST EXTRA QUE SOLAMENTE SIRVE PARA
// FUNCIONAR QUE GETPIXEL Y SETPIXEL FUNCIONEN
// CORRECTAMENTE POR SI SOLOS

int main(){
    float valor;
    Image *I = new Image(256);
    float pixel = I->getPixel(2,3); // Se prueba getPixel
    if(pixel == 0){
        cout << "getPixel funciona correctamente" << endl;
        cout << "El valor del pixel es: " << pixel << endl;
    }
    cout << "Ingrese el valor flotante para modificar el pixel" << endl;
    cin >> valor;
    I->setPixel(2,3,valor);
    pixel = I->getPixel(2,3); // Se prueba setPixel
    if(pixel == valor){
        cout << "setPixel funciona correctamente" << endl;
        cout << "El pixel ahora tiene el valor de: " << valor << endl;
    }
    return 0;
}