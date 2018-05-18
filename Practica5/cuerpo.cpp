#include <cuerpo.h>             //definicion de los metodos de la clase Cuerpo

void Cuerpo::cuerpo(){

    cout << "Cual es la posicion inicial en x?: ";
    cin >> px;
    cout << "Cual es la posicion inicial en y?: ";
    cin >> py;
    cout << "Cual es la velocidad inicial en x?: ";
    cin >> vx;
    cout << "Cual es la velocidad inicial en y?: ";
    cin>> vy;
    cout << "Cual es la masa del cuerpo?: ";
    cin >> masa;
}
double Cuerpo::get_px(){
    return px;
}

double Cuerpo::get_py(){
    return py;
}

int Cuerpo::get_mass(){
    return masa;
}

void Cuerpo::calc_pos(double t){
    px+=vx*t+((ax*t*t)/2);
    py+=vy*t+((ay*t*t)/2);
    vx+=ax*t;
    vy+=ay*t;
    ax=0;
    ay=0;
}

void Cuerpo::calc_a(double y2,double y1, double x2, double x1, int m){
    double ang_r, r;
    double x=x2-x1,y=y2-y1;
    r=sqrt(x*x+y*y);
    ang_r=atan2(y,x);

    ax+=((G*m*cos(ang_r))/(r*r));
    ay+=((G*m*sin(ang_r))/(r*r));
}

