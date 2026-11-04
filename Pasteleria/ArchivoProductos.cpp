#include <iostream>
#include <cstring>
#include "ArchivoProductos.h"

using namespace std;

ArchivoProductos::ArchivoProductos(const char *n){ // aca le saque el valor por omision que va en el h
    strcpy(_nombre,n);
}

Productos ArchivoProductos::leerRegistro(int pos){
    FILE *p=fopen(_nombre,"rb");
    Productos obj;
    if (p==nullptr){
        cout<<"NO SE PUEDE."<<endl;
        obj.setIdProducto(-1);
        return obj;
    }
    fseek(p,pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoProductos::contarRegistro(){
    FILE *p=fopen(_nombre, "rb");
    if (p==nullptr){
        cout<<"ERROR AL CONTAR."<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Productos);
}
bool ArchivoProductos::grabarRegistro(Productos obj){
    FILE *p = fopen(_nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
int ArchivoProductos::buscarRegistro(int id){
    int cantReg = contarRegistro();
    for(int i=0; i<cantReg; i++){
        Productos obj = leerRegistro(i);
        if(obj.getIdProducto() == id) return i;
    }
    return -1;
}

bool ArchivoProductos::modificarRegistro(Productos obj, int pos){
    FILE *p = fopen(_nombre, "rb+");

    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool modifico = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return modifico;
}

void ArchivoProductos::listarReg(){
    int cantReg = contarRegistro();
    for(int i=0; i<cantReg; i++){
        Productos obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<"======================="<<endl;
        }
    }
}

void ArchivoProductos::bajaRegistro(){
    int id;
    cout<<"INGRESE EL ID DEL REGISTRO A DAR DE BAJA: ";
    cin>>id;
    ArchivoProductos arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE ESA ID EN EL ARCHIVO"<<endl;
        return;
    }
    Productos obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}
