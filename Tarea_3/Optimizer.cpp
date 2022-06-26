#include "Optimizer.h"

// La clase Optimizer representa un optimizador de funciones, la cual resulta util
// para hacer el proceso de la corrupcion algo rapido y eficiente. Requiere un 
// Objective, unos parametros iniciales y una tolerancia

/*
p : son los parametros del modelo, imagen aplanada 
como un un vector de 256*256
n : tamaño del vector
ftol : tolerancia con que termina el Algoritmo
iter: retorna cuantas iteraciones realizo
fret: retorna el valor de la funcion
func: funcion que se va a minimizar
dfunc : gradiente de la funcion
max_it : maximum iterations
*/

// Entrada: Un objective, un arreglo de flotantes, un entero, un flotante y un entero
// Salida: Un Optimizer
// Descripcion: Crea una instancia de la clase Optimizer
Optimizer::Optimizer(Objective *o, float* p, int n, float ftol, int max_it) {
    this->p=p; // Es el arreglo de parametros
    this->func=o; // Es el puntero a funcion que retorna el valor de la funcion a optimizar
    this->n=n; // El tamano del arreglo de parametros
    this->ftol=ftol; // Es el error hasta donde va a llegar el algoritmo
    this->max_it=max_it; // Es el numero de iteraciones a seguir
    this->iter=0; // Es el numero de iteraciones al cual llego el algoritmo
    this->fret=0; // Es el minimo valor de la funcion a minimizar al cual se llega
    this->fp=0; // Es el error del gradiente
}

// Entrada: No tiene entrada
// Salida: No tiene salida como tal
// Descripcion: Destructor de la clase Optimizer
Optimizer::~Optimizer() {
}

// Entrada: No tiene entrada
// Salida: No tiene salida como tal
// Descripcion: Metodo que elimina los numeros negativos de p
void Optimizer::truncate(){
  for(int i = 0; i < n; i++){ // Iterando por los valores de P
    if(p[i]< 0){
      p[i] = 0; // Si el valor es negativo, lo ponemos a cero
    }
  }
}

// Entrada: No tiene entrada
// Salida: No tiene salida como tal
// Descripcion: Metodo que minimiza en N-dimensiones el gradiente conjugado, a traves de 
// un numero de iteraciones. A traves de este metodo se utilizan otros, como truncate,
// linmin, brent, mnbrak y f1dim.
void Optimizer::frprmn() {
  // Se declaran valores y variables a utilizar
  int j=0,its=0;
  float gg=0,gam=0,fp=0,dgg=0;
  float* g,*h,*xi;
  this->iter=0;
  this->fret=0;
  this->fp=0;
  g = new float[n]; // Declara un nuevo vector de flotantes
  h = new float[n]; // Declara un nuevo vector de flotantes
  xi = new float[n]; // Declara un nuevo vector de flotantes
  fp = func->F(p,n); // Calcula la funcion a minimizar
  func->dF(p,xi); // Calcula el gradiente
  for (j=0; j<n; j++) { // Iterando
    g[j] = -xi[j];
    xi[j]=h[j]=g[j];  // Asigna a xi el valor de - el gradiente
  }
  for (its=1; its<=max_it; its++) { // For principal hasta un maximo de iteraciones
    cout << "iteracion: " << its << endl;
    this->iter=its;
    // El vector p, fret se actualiza en el linmin
    linmin(xi); // Aqui modificamos p para obtener un minimo en la direccion xi 
    truncate(); // Aqui se anulan todos los valores negativos en p
    // Si el error es suficientemente bajo, termina
    if (2.0*fabs(this->fret-fp) <= ftol*(fabs(this->fret)+fabs(fp)+EPS)) {
      FREEALL
      return;
    }
    fp=func->F(p,n);  // Esta funcion asigna en xi el valor del gradiente 
    this->func->dF(p, xi); // Se retorna un puntero
    dgg=gg=0.0;
    // Parte de la construction de la direccion en que se va a minimizar
    for (j=0; j<n; j++) {
      gg += g[j]*g[j];
      dgg += (xi[j]+g[j])*xi[j];
    }
    if (gg == 0.0) {  // Aqui el gradiente se hace 0 entonces estamos en un minimo
      FREEALL
      return;
    }
    gam=dgg/gg;
     // Parte de la direccion en que se va a minimizar
    for (j=0; j<n; j++) {
      g[j] = -xi[j];
      xi[j]=h[j]=g[j]+gam*h[j];
    }
  }
  // En caso de que supere el maximo de iteraciones, se termina
  cout << "Too many iterations in frprmn%s\n";
  FREEALL
  return;
}

// Entrada: Un arreglo de flotantes xi
// Salida: No tiene salida como tal
// Descripcion: Metodo que minimiza en N-dimensiones el gradiente conjugado
void Optimizer::linmin(float* xi) {
  int j, ncom;
  float xx, xmin, fx, fb, fa, bx, ax;
  ncom = n;
  pcom = new float[n]; // Creamos un nuevo vector de tamano n
  xicom = new float[n]; // Creamos un nuevo vector de tamano n
  for (j = 1; j <= n; j++) // Realizamos una copia de p y xi
  {
    pcom[j] = p[j];  // Copiamos los valores de p a pcom
    xicom[j] = xi[j]; // Copiamos los valores de xi a xicom
  }
  ax = 0.0;
  xx = 1.0;
  mnbrak(&ax, &xx, &bx, &fa, &fx, &fb); // Encuentra un a, b y c tal que el minimo este entre a y b
  fret = brent(ax, xx, bx,TOL, &xmin); // Se encuentra el minimo sin derivadas
  printf("brent xmin: %.10f\n", xmin);
  for (j = 1; j <= n; j++)
  {
    xi[j] *= xmin; // Se van multiplicando los valores de xmin * xi
    p[j] += xi[j]; // Se van sumando los valores de xi con p
  }
  delete [] pcom; // Elimina los vectores usados
  delete [] xicom;
}

// Entrada: Seis punteros a flotantes que representan los valores de a, b y c, f(a), f(b) y f(c)
// Salida: No tiene salida como tal
// Descripcion: Metodo que encuentra un a, b y c tal que el minimo este entre a y b.
// En palabras simples, va recorriendo la funcion hasta llegar al punto mas minimo.
void Optimizer::mnbrak(float* ax, float* bx, float* cx, float* fa, float* fb, float* fc) {
  float ulim,u,r,q,fu,dum;
  if (*fb > *fa) { 
    SHFT(dum,*ax,*bx,dum) // Cambia las posiciones de a y b 
    SHFT(dum,*fb,*fa,dum) // De esta forma puede ir hacia abajo desde a hasta b
  }
  *cx=(*bx)+GOLD*(*bx-*ax); // Se obtiene c, utilizando el Golden Ratio
  *fc=f1dim(*cx); 
  while (*fb > *fc) { // Este siglo se utiliza  para calcular a b y c extrapolando.
    r=(*bx-*ax)*(*fb-*fc);
    q=(*bx-*cx)*(*fb-*fa);
    u=(*bx)-((*bx-*cx)*q-(*bx-*ax)*r)/
      (2.0*SIGN(FMAX(fabs(q-r),TINY),q-r));  // TINY evita cualquier problema con 0
    ulim=(*bx)+GLIMIT*(*cx-*bx);
    if ((*bx-u)*(u-*cx) > 0.0) { // Entre a y c
      fu=f1dim(u);
      if (fu < *fc) { // Se obtiene un minimo entre b y c
        *ax=(*bx);
        *bx=u;
        *fa=(*fb);
        *fb=fu;
        return;
      } else
        if (fu > *fb) { // Se obtiene un minimo entre a y u
          *cx=u;
          *fc=fu;
          return;
        }
      u=(*cx)+GOLD*(*cx-*bx); // Ajuste parabolico
      fu=f1dim(u);
    } else
      if ((*cx-u)*(u-ulim) > 0.0) { // Ajuste parabolico entre c y ulim
        fu=f1dim(u);
        if (fu < *fc) {
          SHFT(*bx,*cx,u,*cx+GOLD*(*cx-*bx));
          SHFT(*fb,*fc,fu,f1dim(u));
        }
      } else
        if ((u-ulim)*(ulim-*cx) >= 0.0) { // Se limita u hasta ulim
          u=ulim;
          fu=f1dim(u);

        } else {
          u=(*cx)+GOLD*(*cx-*bx); // Aumnento por defecto
          fu=f1dim(u);
        }
    SHFT(*ax,*bx,*cx,u) // Se elimina el punto mas antiguo
    SHFT(*fa,*fb,*fc,fu)
  }
}

// Entrada: Un flotante x
// Salida: Un flotante f(x)
// Descripcion: Metodo que deja en una dimension y calcula la suma de pcom + x*xicom
// (wrapper)
float Optimizer::f1dim(float x) {
  int j;
  float f,*xt;
  xt = new float[this->n]; // Se crea un nuevo vector
  for (j=0; j<=this->n; j++) {
    xt[j]=pcom[j]+x*xicom[j]; // Se copia el valor de pcom y se multiplica por xicom
  }
  f = this->func->F(xt,this->n); // Calcula la funcion a minimizar 
  delete[] xt;
  return f; // Se retorna el valor de la funcion
}

// Entrada:  Un flotante ax, un flotante bx, un flotante cx, un flotante tol, un puntero a 
// flotante xmin
// Salida: Un flotante, el cual es el valor minimo
// Descripcion: Metodo que encuentra el minimo sin derivadas, utilizando el metodo de
// Brent, el cual es un metodo que mezcla distintos metodos de optimizacion para asi encontrar
// de manera eficiente el minimo de una funcion
float Optimizer::brent(float ax, float bx, float cx, float tol,float* xmin){
  int iter;
  float a,b,d=0.0,etemp,fu,fv,fw,fx,p,q,r,tol1,tol2,u,v,w,x,xm;
  float e=0.0; // Distancia movida
  a=(ax < cx ? ax : cx); // A y b deben estar en orden ascendiente
  b=(ax > cx ? ax : cx);
  x=w=v=bx;
  fw=fv=fx=f1dim(x);  // Se utiliza f1dim para obtener el valor de la funcion
  for (iter=1; iter<=ITMAX; iter++) {
    xm=0.5*(a+b);
    tol2=2.0*(tol1=tol*fabs(x)+ZEPS);
    if (fabs(x-xm) <= (tol2-0.5*(b-a))) {
      *xmin=x;
      return fx; // Si el proceso fue realizado correctamente, se retorna fx
    }
    if (fabs(e) > tol1) { // Ajuste parabolico
      r=(x-w)*(fx-fv);
      q=(x-v)*(fx-fw);
      p=(x-v)*q-(x-w)*r;
      q=2.0*(q-r);
      if (q > 0.0) {
        p = -p;
      }
      q=fabs(q);
      etemp=e;
      e=d;
      if (fabs(p) >= fabs(0.5*q*etemp) || p <= q*(a-x) || p >= q*(b-x)) {
        // Lo anterior determina si el ajuste parabolico es valido o no
        d=CGOLD*(e=(x >= xm ? a-x : b-x));
      } else {
        d=p/q; // Calculos matematicos
        u=x+d;
        if (u-a < tol2 || b-u < tol2) {
          d=SIGN(tol1,xm-x);
        }
      }
    } else {
      d=CGOLD*(e=(x >= xm ? a-x : b-x));
    }
    u=(fabs(d) >= tol1 ? x+d : x+SIGN(tol1,d));
    fu=f1dim(u); // Se llama a f1dim para obtener el valor de la funcion 
    if (fu <= fx) {
      if (u >= x) {
        a=x;
      } else {
        b=x;
      }
      SHFT(v,w,x,u) // Cambio de posiciones
      SHFT(fv,fw,fx,fu) // Cambio de posiciones
    } else {
      if (u < x) {
        a=u;
      } else {
        b=u;
      }
      if (fu <= fw || w == x) {
        v=w; // Mas calculos matematicos
        w=u;
        fv=fw;
        fw=fu;
      } else
        if (fu <= fv || v == x || v == w) {
          v=u;
          fv=fu; // Mas calculos matematicos, el proceso continua iterando
        }
    }
  }
  *xmin=x;
  return fx; // Si el proceso fue correcto no se deberia llegar aca
}
