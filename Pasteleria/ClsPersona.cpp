#include <iostream>
#include <cstring>
#include "ClsPersona.h"

using namespace std;

void Persona::setID(int id){
    if (id > 0){
        _ID = id;
    }
}

void Persona::setNombre(const char *nombre){
    if (strlen(nombre) > 0 && strlen(nombre) < 25){
        strcpy(_nombreApellido, nombre);
    }
}

void Persona::setDomicilio(const char *domicilio){
    if(strlen(domicilio) > 0 && strlen(domicilio) < 25){
        strcpy(_domicilio, domicilio);
    }
}

void Persona::setTelefono(int telefono){
    if (telefono > 0){
        _telefono = telefono;
    }
}

void Persona::setEstado(bool estado){
    _estado = estado;
}

int Persona::getID(){
    return _ID;
}

const char *Persona::getNombre(){
    return _nombreApellido;
}

const char *Persona::getDomicilio(){
    return _domicilio;
}

int Persona::getTelefono(){
    return _telefono;
}

bool Persona::getEstado(){
    return _estado;
}

void Persona::Cargar(){
    cout<<"ID: ";
    cin>>_ID;
    while(_ID <= 0){
        cout<<"El ID debe ser mayor a 0: ";
        cin>>_ID;
    }

    cout<<"Nombre y apellido: ";
    cin>>_nombreApellido;

    cout<<"Domicilio: ";
    cin>>_domicilio;

    cout<<"Telefono: ";
    cin>>_telefono;
    while(_telefono <= 0){
        cout<<"El telefono debe ser mayor a 0: ";
        cin>>_telefono;
    }
    _estado = true;
}

void Persona::Mostrar(){
    cout<<"ID: "<< _ID <<endl;
    cout<<"Nombre y apellido: "<< _nombreApellido <<endl;
    cout<<"Domicilio: "<< _domicilio <<endl;
    cout<<"Telefono: "<< _telefono <<endl;
}
