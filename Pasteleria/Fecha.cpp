#include <iostream>
#include "Fecha.h"
using namespace std;


bool Fecha::EsBisiesto(int anio){
if (anio%400==0){
    return true;
} else if (anio %100==0){
    return false;
} else if (anio % 4==0){
    return true;
}else {
    return false;
}
}

int Fecha::DiasDelMes(int mes, int anio){
switch (mes){
case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    return 31;
case 4: case 6: case 9: case 11:
    return 30;
case 2:
    if (EsBisiesto(anio)==true){
        return 29;
    }else {
    return 28;
    }
default:
    return 0;
}
}

bool Fecha::EsValida(int dia, int mes, int anio){

if (anio < 1){
    return false;
}
int MaximoDias = DiasDelMes(mes, anio);
if (MaximoDias==0){
    return false;
}
if (dia >= 1 && dia <= MaximoDias){
    return true;
} else {
    return false;
}
}

Fecha::Fecha(int d, int m, int a)
{
    if (EsValida(d, m, a)==true){
    _dia = d;
    _mes = m;
    _anio = a;
}else {
    _dia =1;
    _mes=1;
    _anio=2023;
    cout << "Fecha invalida, se guardo 1/1/2023" << endl;
    }}


void Fecha::setDia(int d)
{   if (EsValida(d, _mes, _anio)== true) {
    _dia = d;
    }else {
    cout << "Dia invalido, no se modifico la fecha. "<< endl;
}}

void Fecha::setMes (int m){
if (EsValida(_dia, m, _anio)== true) {
_mes = m;}
else {
    cout << "Mes invalido, no se modifico la fecha. "<< endl;
}
}

void Fecha::setAnio (int a){
if (EsValida(_dia, _mes, a)== true) {
_anio = a;}
else {
    cout << "Anio invalido, no se modifico la fecha. "<< endl;
}
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

    int nuevoDia;
    int nuevoMes;
    int nuevoAnio;

    cout<<"Ingrese el dia :"<<endl;
    cin>>nuevoDia;
    cout<<"Ingrese el mes : "<<endl;
    cin>>nuevoMes;
    cout<<"Ingrese el anio: " <<endl;
    cin>>nuevoAnio;

    if (EsValida(nuevoDia, nuevoMes, nuevoAnio)==true) {
        _dia = nuevoDia;
        _mes = nuevoMes;
        _anio = nuevoAnio;
    } else {
        cout << "Fecha invalida. No se modifico la fecha." << endl;
    }

}

void Fecha::Mostrar()
{
    cout << _dia << "/" << _mes << "/" << _anio;
}

Fecha :: ~Fecha (){
cout << "SE MURIO EL OBJETO" << endl;
}
