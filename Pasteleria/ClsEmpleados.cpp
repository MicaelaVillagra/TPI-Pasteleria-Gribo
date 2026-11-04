#include <iostream>
#include <cstring>
#include "ClsPersona.h"
#include "ClsEmpleados.h"
using namespace std;

void Empleados:: setOficio(const char *o){

    strcpy(oficio,o);
}

const char *Empleados:: getOficio(){

    return oficio;
}

void Empleados:: Cargar(){

    Persona::Cargar();
    cin.ignore();
    cout << "Oficio: ";
    cin.getline(oficio, 25);
}

void Empleados:: Mostrar(){

    Persona::Mostrar();
    cout << "Oficio: " << oficio << endl;
}

