#include <iostream>
#include <cstring>
#include "ArchivoEmpleados.h"

using namespace std;

ArchivoEmpleados::ArchivoEmpleados(const char *n){
    strcpy(_nombre,n);
}

Empleados ArchivoEmpleados::leerRegistro(int pos){
    FILE *p=fopen(_nombre,"rb");
    Empleados obj;
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

int ArchivoEmpleados::contarRegistro(){
    FILE *p=fopen(_nombre, "rb");
    if (p==nullptr){
        cout<<"ERROR AL CONTAR."<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Empleados);
}
bool ArchivoEmpleados::grabarRegistro(Empleados obj){
    FILE *p = fopen(_nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
int ArchivoEmpleados::buscarRegistro(int id){
    int cantReg = contarRegistro();
    for(int i=0; i<cantReg; i++){
        Empleados obj = leerRegistro(i);
        if(obj.getID() == id) return i;
    }
    return -1;
}

bool ArchivoEmpleados::modificarRegistro(Empleados obj, int pos){
    FILE *p = fopen(_nombre, "rb+");

    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool modifico = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return modifico;
}

void ArchivoEmpleados::listarReg(){
    int cantReg = contarRegistro();
    for(int i=0; i<cantReg; i++){
        Empleados obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<"======================="<<endl;
        }
    }
}

void ArchivoEmpleados::bajaRegistro(){
    int id;
    cout<<"INGRESE EL ID DEL REGISTRO A DAR DE BAJA: ";
    cin>>id;
    ArchivoEmpleados arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE ESA ID EN EL ARCHIVO"<<endl;
        return;
    }
    Empleados obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}
