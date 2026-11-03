#include <iostream>
#include "Fecha.h"
using namespace std;

int main()
{
    //valores por omision
    Fecha f1;
    Fecha f2(3, 11, 2026);
    Fecha f3;

    f1.Mostrar(); cout << endl;
    f2.Mostrar(); cout << endl;

    f3.Cargar();
    f3.Mostrar(); cout << endl;

    f2.setMes(12);
    cout << "Mes nuevo: " << f2.getMes() << endl;

    return 0;
}
