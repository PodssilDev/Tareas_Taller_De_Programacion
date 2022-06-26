#ifndef OBJECTIVE_H
#define OBJECTIVE_H
#include "ImageProcessor.h"

// Objective representa la clase que contiene la funcion objetivo. Es una clase
// que es utilzada por Optimizer

class Objective {
public:
    Objective(Image *I_corrupted, ImageProcessor *processor); // Constructor de la clase
    ~Objective(); // Destructor de la clase
    Objective(); // Constructor de la clase
    virtual float F(float* p, int n); // Metodo que corresponde a la funcion a minimizar
    virtual void dF(float* p, float* xi); // Metodo que modifica el vector xi. Es el gradiente de la funcion 
private:
    Image *I_corrupted; // Es la imagen corrupta
    ImageProcessor *processor; // Es una instancia  de ImageProcessor
};
#endif
