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
    const float L = 100.0;
    const float c = sqrt(T/ro);

    //Pasos
    float dx = 1;
    float dt = 0.01;

    int M = 101;
    int N = 3;

    //Inicializar matriz
     double **mat = new double*[M];
     int i;
     for(int i=0;i<M;i++){
         mat[i] = new double[N];
     }

     //EXTREMOS FIJOS




    //Condiciones iniciales t=0
    for(int i=0;i<81;i++){
        mat[i][0] = (1.25*i)/L;
    }

    for(int i=81;i<101;i++){
        mat[i][0] = (5-5*i)/L;
    }



   //print
    for(int i=0;i<M;i++){
             for(int j=0;j<1;j++){
              cout << mat[i][j] << " ";
             }
        cout << endl;
    }

return 0;
}
