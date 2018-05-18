//Simulacion de un sistema gravitacional



#include <iostream>
#include <cuerpo.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
    ofstream fout;
    string nom_arch;

    cout << "Escriba el nombre del archivo donde quiere guardar los resultados" << endl;
    getline(cin,nom_arch);      //pide el nombre del archivo donde quiere almacenar los datos finales

    fout.open(nom_arch.c_str(),ios::out);
    if (fout.fail()){                           //dice si hubo un error al abrir el archivo para no seguir ejecutando el programa
        cout << "No se pudo abrir el archivo." << endl;
        exit(1);
    }

    int n;
    float dt;
    cout << "Cuantos cuerpos desea modelar?: ";
    cin>> n;
    Cuerpo a[n];            //arreglo de objetos
    for (int i=0; i<n; i++){

       cout << "Para el cuerpo " << i+1 << endl;
       a[i].cuerpo();       //se incializan cada uno de los objetos del arreglo

    }
    cout << "Para un intervalo de cuantos segundos desea simular el sistema?: ";
    cin >> dt;

    for (float t=0.1 ; t<=dt ; t+=0.1){         //en este ciclo se calcula la aceleración, velocidad y posición cada
                                                //0.1 segundos
        for (int i=0; i<n; i++){
            int m;
            double y2,y1,x2,x1;
            for (int j=0 ; j<n ; j++){
                if (j!=i){
                    m = a[j].get_mass();
                    y2=a[j].get_py();
                    y1=a[i].get_py();
                    x2=a[j].get_px();
                    x1=a[i].get_px();
                    a[i].calc_a(y2,y1,x2,x1,m);
                }
            }

        }
        for (int i=0; i<n ; i++){

            a[i].calc_pos(0.1);

            fout<< a[i].get_px() << "\t" << a[i].get_py()<<"\t";
        }

        fout << endl;
    }


    fout.close();
    return 0;
}
