#include <iostream>
#include <cstring>
#include "ArchivoClientes.h"

using namespace std;

ArchivoClientes::ArchivoClientes(const char *n){
    strcpy(_nombre,n);
}

Clientes ArchivoClientes::leerRegistro(int pos){
    FILE *p=fopen(_nombre,"rb");
    Clientes obj;
    if (p==nullptr){
        cout<<"NO SE PUEDE."<<endl;
        obj.setID(-1);
        return obj;
    }
    fseek(p,pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoClientes::contarRegistro(){
    FILE *p=fopen(_nombre, "rb");
    if (p==nullptr){
        cout<<"ERROR AL CONTAR."<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Clientes);
}
bool ArchivoClientes::grabarRegistro(Clientes obj){
    FILE *p = fopen(_nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
int ArchivoClientes::buscarRegistro(int id){
    int cantReg = contarRegistro();
    for(int i=0; i<cantReg; i++){
        Clientes obj = leerRegistro(i);
        if(obj.getID() == id) return i;
    }
    return -1;
}

bool ArchivoClientes::modificarRegistro(Clientes obj, int pos){
    FILE *p = fopen(_nombre, "rb+");

    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool modifico = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return modifico;
}

void ArchivoClientes::listarReg(){
    int cantReg = contarRegistro();
    for(int i=0; i<cantReg; i++){
        Clientes obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<"======================="<<endl;
        }
    }
}

void ArchivoClientes::bajaRegistro(){
    int id;
    cout<<"INGRESE EL ID DEL REGISTRO A DAR DE BAJA: ";
    cin>>id;
    ArchivoClientes arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE ESA ID EN EL ARCHIVO"<<endl;
        return;
    }
    Clientes obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}
