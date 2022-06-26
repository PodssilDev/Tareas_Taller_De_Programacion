#ifndef OPTIMIZER_H
#define OPTIMIZER_H
#include <iostream>
#include <math.h>
#include "Objective.h"
using namespace std;
#define FREEALL delete[] xi; delete[] h; delete[] g; // Destructores
#define EPS 1.0e-10 // Sirve para la precision fracional
#define TOL 1.0e-7 // Sirve para la tolerancia
#define GOLD 1.618034 // Es el Golden Ratio
#define GLIMIT 100.0 // Limita la cantidad de iteraciones
#define TINY 1.0e-20 // Valor muy pequeño
#define SHFT(a,b,c,d) (a)=(b);(b)=(c);(c)=(d); // Sirve para reemplazar variables
#define ITMAX 100 // Limita la cantidad de iteraciones
#define CGOLD 0.3819660 // Es el cuadrado del reciproco del Golden Ratio
#define ZEPS 1.0e-10 // Sirve para rectificar la funcion
static float sqrarg;  // Variable a utilizar para las otras definiciones
#define SQR(a) ((sqrarg=(a)) == 0.0 ? 0.0 : sqrarg*sqrarg) // Verifica si el valor es 0
static double dsqrarg; // Igual que lo anterior, pero de tipo double
#define DSQR(a) ((dsqrarg=(a)) == 0.0 ? 0.0 : dsqrarg*dsqrarg)
static double dmaxarg1,dmaxarg2; // Obtiene el maximo
#define DMAX(a,b) (dmaxarg1=(a),dmaxarg2=(b),(dmaxarg1) > (dmaxarg2) ?\
        (dmaxarg1) : (dmaxarg2))
static double dminarg1,dminarg2; // Obtiene el minimo de dos valores
#define DMIN(a,b) (dminarg1=(a),dminarg2=(b),(dminarg1) < (dminarg2) ?\
        (dminarg1) : (dminarg2))
static float maxarg1,maxarg2; // Obtiene el maximo
#define FMAX(a,b) (maxarg1=(a),maxarg2=(b),(maxarg1) > (maxarg2) ?\
        (maxarg1) : (maxarg2))
static float minarg1,minarg2; // Similar a DMIN, pero flotante
#define FMIN(a,b) (minarg1=(a),minarg2=(b),(minarg1) < (minarg2) ?\
        (minarg1) : (minarg2))
static long lmaxarg1,lmaxarg2; // Similar a DMAX, pero de tipo long
#define LMAX(a,b) (lmaxarg1=(a),lmaxarg2=(b),(lmaxarg1) > (lmaxarg2) ?\
        (lmaxarg1) : (lmaxarg2))
static long lminarg1,lminarg2; // Simiilar a DMIN, pero de tipo long
#define LMIN(a,b) (lminarg1=(a),lminarg2=(b),(lminarg1) < (lminarg2) ?\
        (lminarg1) : (lminarg2))
static int imaxarg1,imaxarg2; // Similar a DMAX, pero de tipo int
#define IMAX(a,b) (imaxarg1=(a),imaxarg2=(b),(imaxarg1) > (imaxarg2) ?\
        (imaxarg1) : (imaxarg2))
static int iminarg1,iminarg2; // Similar a DMIN, pero de tipo int
#define IMIN(a,b) (iminarg1=(a),iminarg2=(b),(iminarg1) < (iminarg2) ?\
        (iminarg1) : (iminarg2))
#define SIGN(a,b) ((b) >= 0.0 ? fabs(a) : -fabs(a)) // Obtiene el signo

// La clase Optimizer representa un optimizador de funciones, la cual resulta util
// para hacer el proceso de la corrupcion algo rapido y eficiente. Requiere un 
// Objective, unos parametros iniciales y una tolerancia
class Optimizer {
public:
    Optimizer(Objective *o, float* p, int n, float ftol, int max_it); // Constructor de la clase
    ~Optimizer(); // Destructor de la clase
    void frprmn();// Metodo que minimiza en N-dimensiones el gradiente conjugado
    void linmin(float* xi); // Metodo que minimiza en la direccion de xi y modifica p y fret
    void mnbrak(float* ax, float* bx, float* cx, float* fa, float* fb, float* fc); // Metodo que encuentra un a, b y c tal que el minimo este entre a y b
    float f1dim(float x); // Metodo utilizado por linmin. Calcula el valor de la funcion en x
    float brent(float ax, float bx, float cx, float tol,float* xmin); // Metodo que utiliza el metodo de Brent para encontrar el minimo de una funcion
    float * getParameter(); // Metodo que retorna p
    void truncate(); // Metodo que elimina los numeros negativos
private:
    float *p; // Es el arreglo de parametros
    float *pcom; // Una copia de p
    float *xicom; // Una copia de xi
    int n; // El tamano del arreglo de parametros
    float ftol; // Es el error hasta donde va a llegar el algoritmo
    int max_it; // Es el numero de iteraciones a seguir
    int iter; // Es el numero de iteraciones al cual llego el algoritmo
    float fret; // Es el minimo valor de la funcion a minimizar al cual se llega
    float fp; // Es el error del gradiente
    Objective *func; // Es el puntero a la funcion que retorna el valor de la funcion a optimizar
};
#endif // OPTIMIZER_H
