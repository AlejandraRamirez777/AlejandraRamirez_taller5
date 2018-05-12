#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
//#include <random>

using namespace std;

int main () {

    //Constantes dadas
    const float T = 40.0;
    const float ro = 10.0;
    const int L = 100;
    const float c = sqrt(T/ro);
    const float n_time = 200;

    //Pasos
    float dx = 1;
    float dt = 0.01;
    float CD = dx/dt;
    float r = c/CD;
    //cout << r << endl;


    int M = 101;

    //Inicializar arrays
    //inical,pasado, presente,futuro
     double ini[M];
     double past[M];
     double pres[M];
     double fut[M];

     //EXTREMOS FIJOS

     //u(0,t) = 0 = u(L,t)
     //Para todos los tiempos los extremos son 0
     ini[0] = 0;
     past[0] = 0;
     pres[0] = 0;
     fut[0] = 0;
     ini[L] = 0;
     past[L] = 0;
     pres[L] = 0;
     fut[L] = 0;

    //Condiciones iniciales
    //Primer presente -->inicial
    for(int i=1;i<81;i++){
        ini[i] = (1.25*i)/(float)L;
    }

    for(int i=81;i<M-1;i++){
        ini[i] = 5-((5*i)/(float)L);
    }

    //Primer pasado es igual al primer futuro
    // se calculan a partir de inicial
    //Loops 1 - 100 para no modificar extremos
    for(int i=1;i<M-1;i++){
        fut[i] = ini[i] + 0.5*(r*r)*(ini[i+1] + ini[i-1] -2*ini[i]);
    }

    //Base "Primer paso del tiempo"
    for(int i=1;i<M-1;i++){
        past[i] = ini[i];
        pres[i] = fut[i];
    }


   int t = 0;
    //Progreso del tiempo
    while(t<n_time){

      //print presente
       for(int i=0;i<M;i++){
         cout << i << " " << pres[i] << " " << endl;
       }

        //Calculo futuro
        for(int i=1;i<M-1;i++){
            fut[i] = 2*pres[i] - past[i] + (r*r)*(pres[i+1] + pres[i-1] - 2*pres[i]);
        }

        //Avance en el tiempo
        //Nuevo pasado --> prev presente
        //Nuevo presente --> prev futuro
        for(int i=1;i<M-1;i++){
          past[i] = pres[i];
          pres[i] = fut[i];
        }

        t= t + 1;
    }

    //cout << t << endl;

return 0;
}
