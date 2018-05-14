#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
//#include <random>

using namespace std;

const double e = 0.001;

double zqq1(double p1);
double zqq2(double p2);
double zp1(double qq1, double E);
double zp2(double qq1, double qq2, double E);

int main () {

    //dt es igual a h
    double h = 0.006;
    double T = 3000;
    double a = 1.0/(2.0*sqrt(2.0));

    //Condicion inicial
    double qq1 = a;
    double qq2 = -1.0*a;
    double p1 = 0.0;
    double p2 = 0.0;

    //Rk4
    //Yi+1 = Yi + (1/6)*h*(k1+2k2+2k3+k4)
    //Para cada expresion hay k1,2,3,4

    double t =0;
    while(t < T){


     double k1qq1 = h*zqq1(p1);
     double k1qq2 = h*zqq2(p2);
     double k1p1 = h*zp1(qq1, e);
    double k1p2 = h*zp2(qq1, qq2, e);

     double k2qq1 = h*zqq1(p1 + 0.5*k1p1);
     double k2qq2 = h*zqq2(p2 + 0.5*k1p2);
     double k2p1 = h*zp1(qq1 + 0.5*k1qq1, e);
     double k2p2 = h*zp2(qq1 + 0.5*k1qq1, qq2 + 0.5*k1qq2, e);

     double k3qq1 = h*zqq1(p1 + 0.5*k2p1);
     double k3qq2 = h*zqq2(p2 + 0.5*k2p2);
     double k3p1 = h*zp1(qq1 + 0.5*k2qq1, e);
     double k3p2 = h*zp2(qq1 + 0.5*k2qq1, qq2 + 0.5*k2qq2, e);

     double k4qq1 = h*zqq1(p1 + 0.5*k3p1);
     double k4qq2 = h*zqq2(p2 + 0.5*k3p2);
     double k4p1 = h*zp1(qq1 + 0.5*k3qq1, e);
     double k4p2 = h*zp2(qq1 + 0.5*k3qq1, qq2 + 0.5*k3qq2, e);

     //Soluciones deben ser p1,p2,qq1 y qq2
     double qq1f = qq1 + (1.0/6.0)*(k1qq1 + 2.0*k2qq1 + 2.0*k3qq1 + k4qq1);
     double qq2f = qq2 + (1.0/6.0)*(k1qq2 + 2.0*k2qq2 + 2.0*k3qq2 + k4qq2);
     double p1f = p1 + (1.0/6.0)*(k1p1 + 2.0*k2p1 + 2.0*k3p1 + k4p1);
     double p2f = p2 + (1.0/6.0)*(k1p2 + 2.0*k2p2 + 2.0*k3p2 + k4p2);

     if((qq1> 0 and qq1f < 0) or (qq1< 0 and qq1f > 0)){
           cout << qq2 << " " << p2 << endl;
     }

        //Sustitucion avance en el tiempo
        qq1 = qq1f;
        qq2 = qq2f;
        p1 = p1f;
        p2 = p2f;

        t = t+h;
    }

return 0;
}

//Sistemas de ecuaciones

//Parametros double oo no tienen utilidad
// se emplean solo para generalizacion

//1st time derivative q1
double zqq1(double p1){
    return p1;
}

//1st time derivative q2
double zqq2(double p2){
    return p2;
}

//1st time derivative p1
double zp1(double qq1, double E){
    double a = -2.0*qq1;
    double b = (4.0*qq1*qq1) + (E*E);
    double c = pow(b,3.0/2.0);
    return a/c;
}

//1st time derivative p2
double zp2(double qq1, double qq2, double E){
    double a = qq1 - qq2;
    double b = ((qq1 - qq2)*(qq1 - qq2)) + (E*E)/4.0;
    double c = pow(b,3.0/2.0);
    double d = qq1 + qq2;
    double e = ((qq1 + qq2)*(qq1 + qq2)) + (E*E)/4.0;
    double f = pow(e,3.0/2.0);
    return (a/c) - (d/f);
}
