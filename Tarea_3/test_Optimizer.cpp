#include <iostream>
#include "Objective.h"
#include "Optimizer.h"
using namespace std;

// Este test funciona para probar tanto las funciones de Objective y de Optimizer.
// Es una traduccion del test_frprmn entregado en clases. Notar que en este test, se
// utilizan principalmente las funciones F y DF de objective, y de optimizer
// principalmente se utilizan frprmn, la cual en su proceso utiliza truncate, linmin
// mnbrak y brent. Se utiliza herencia en el proceso para que el test funcione
// correctamente. Notar ademas que este test fue escrito en la clase del dia 01/06/2022

// Para esta clase, se utiliza herencia.
class test_Optimizer : public Objective {
  private:
    int n;
  public:
    test_Optimizer(int n){
      this->n = n;
    }
    virtual float F(float x[], int n) { // Funcion a minimizar
      float r=0.5;
      for(int i=0; i<n+1; i++) {
        r=r+0.5*(x[i]-i)*(x[i]-i)/(i+1);
      }
      return r;
    }
    virtual void dF(float x[], float xi[]) { // Gradiente de la funcion a minimizar
      for(int i=0; i<n+1; i++) {
        xi[i]=(x[i]-i)/(i+1);
      }
    }
};

int main() { // Se realiza un proceso similar a main, solo que se imprime el resultado de las iteraciones
  int N = 10; // Se define el tamano de los arreglos
  float ftol = 1e-8; // Se define la tolerancia
  int max_it = 100; // Se define el numero maximo de iteraciones
  float *f=new float[N*N]; // Se crea un nuevo arreglo
  Objective *o=new test_Optimizer(N*N); // Se crea un nuevo objective
  Optimizer *optimizer=new Optimizer(o,f,N*N,ftol,max_it); // Se crea un nuevo optimizer
  optimizer->frprmn(); // Se llama a frprmn para realizar todo el proceso de restauracion
  int i = 0;
  while(i < N*N){ // Se imprimen los valores de f
    cout << "Valor " << i<< ": " << f[i] << endl; 
    i++;
  }
  return 0;
}
