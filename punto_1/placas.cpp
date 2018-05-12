#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
//#include <random>

using namespace std;

int main () {

    const float L = 5.0;
    const float l = 2.0;
    const float d = 1.0;
    const float h = 5.0/512.0;
    const float Vo = 100.0;
    const float N = 2*((L/h)*(L/h));

    //Dimension matrices DxD
    const int D = (L/h);

    const int cen = D/2;

    //Inicializar matrices New and Old
    //New Matrix
    double **neu = new double*[D];
    for(int i=0;i<D;i++){
         neu[i] = new double[D];
     }

     //Old Matrix
     double **old = new double*[D];
     for(int i=0;i<D;i++){
          old[i] = new double[D];
      }


      //Placa se ubica en centro del espacio
      //Ubicacion de placas paralelas (y)
      //up and down
      int plyu = cen - int((d/h)/2);
      int plyd = cen + int((d/h)/2);

      //Limites ubicacion placas (x)
      //start and end of l
      int sl = cen - int((l/h)/2);
      int el = cen + int((l/h)/2);

      //Llenado inicial (placas) old
      //Y fijas, recorrido en x
      for(int j=sl ; j<el ; j++){
          old[plyu][j] = Vo/2.0;
          old[plyd][j] = -1*Vo/2.0;
      }

      //Bordes Region V = 0
      //Loops 1 - D-1

      int t = 0;
      //Progreso del tiempo
      while( t<N ){

          for(int i=1;i<D-1;i++){
               for(int j=1;j<D-1;j++){
                   double nn = 0.25*(old[i][j+1] + neu[i][j-1] + old[i+1][j] + neu[i-1][j]);
                   double r = nn - old[i][j];
                   neu[i][j] = old[i][j] + 1.3*r;
               }
          }

          t= t + 1;
      }



      //cout << el << endl;

     //print
     for(int i=0;i<D;i++){
         for(int j=0;j<D;j++){
             cout << neu[i][j] << " ";
         }
         cout << endl;
     }

return 0;
}
