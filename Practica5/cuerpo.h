#ifndef CUERPO_H
#define CUERPO_H
#define G 1           //definicion de algunas constantes que serán usadas posteriormente para los calculos
#define pi 3.14159265359

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

class Cuerpo{
private:            //atributos de la clase

    double px;
    double py;
    double vx;
    double vy;
    double ax=0;
    double ay=0;
    int masa;

public:             //metodos de la clase

    void cuerpo();
    double get_px();
    double get_py();
    int get_mass();
    void calc_a(double,double,double,double,int);
    void calc_pos(double);


};

#endif // CUERPO_H
