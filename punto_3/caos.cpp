#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
//#include <random>

using namespace std;

double zqq1(double p1);
double zqq2(double p2);
double zp1(double qq1, double E);
double zp2(double qq1, double qq2, double E);

int main () {

    const float dt = 0.006;
    const float t = 3000;
    const float a = 1/(2.0*sqrt(2));
    const float e = 0.001;




return 0;
}

double zqq1(double p1){
    return p1;
}

double zqq2(double p2){
    return p2;
}

double zp1(double qq1, double E){
    double a = -2.0*qq1;
    double b = (4.0*qq1*qq1) + (E*E);
    double c = pow(b,3.0/2.0);
    return a/c;
}

double zp2(double qq1, double qq2, double E){
    double a = qq1 - qq2;
    double b = ((qq1 - qq2)*(qq1 - qq2)) + (E*E)/4.0;
    double c = pow(b,3.0/2.0);
    double d = qq1 + qq2;
    double e = ((qq1 + qq2)*(qq1 + qq2)) + (E*E)/4.0;
    double f = pow(e,3.0/2.0);
    return (a/c) - (d/f);
}
