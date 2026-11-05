#include <iostream>
#include "ClsCliente.h"

using namespace std;

void Clientes::Cargar()
{
    cout<<" Cargar cliente : " << endl;
    Persona::Cargar();
}

void Clientes::Mostrar()
{
    cout<< "Cliente : ";
    Persona::Mostrar();
    cout << endl;
}
