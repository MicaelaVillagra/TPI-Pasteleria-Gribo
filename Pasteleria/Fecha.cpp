#include <iostream>
#include "Fecha.h"
using namespace std;


Fecha::Fecha(int d, int m, int a)
{
    _dia = d;
    _mes = m;
    _anio = a;
}

void Fecha::setDia(int d)
{
    _dia = d;
}

void Fecha::setMes(int m)
{
    _mes = m;
}

void Fecha::setAnio(int a)
{
    _anio = a;
}

int Fecha::getDia()
{
    return _dia;

}
int Fecha::getMes()
{
    return _mes;
}
int Fecha::getAnio()
{
    return _anio;
}

void Fecha::Cargar()
{
    cout<<"Ingrese el dia :"<<endl;
    cin>>_dia;
    cout<<"Ingrese el mes : "<<endl;
    cin>>_mes;
    cout<<"Ingrese el anio: " <<endl;
    cin>>_anio;
}

void Fecha::Mostrar()
{
    cout << _dia << "/" << _mes << "/" << _anio;
}
