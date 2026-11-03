#include <iostream>
#include <cstring>
#include "ArchivoCabeceraPedidos.h"

using namespace std;

ArchivoCabeceraPedidos::ArchivoCabeceraPedidos(const char *n="ArchivoCabeceraPedidos.dat"){
    strcpy(_nombre,n);
}

Cabecera ArchivoCabeceraPedidos::leerRegistro(int pos){
    FILE *p=fopen(_nombre,"rb");
    Cabecera obj;
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

int ArchivoCabeceraPedidos::contarRegistro(){
    FILE *p=fopen(_nombre, "rb");
    if (p==nullptr){
        cout<<"ERROR AL CONTAR."<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Cabecera);
}
bool ArchivoCabeceraPedidos::grabarRegistro(Cabecera obj){
    FILE *p = fopen(_nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
int ArchivoCabeceraPedidos::buscarRegistro(int leg){
    int cantReg = contarRegistro();
    for(int i=0; i<cantReg; i++){
        Cabecera obj = leerRegistro(i);
        if(obj.getID() == id) return i;
    }
    return -1;
}

bool ArchivoCabeceraPedidos::modificarRegistro(Cabecera obj, int pos){
    FILE *p = fopen(_nombre, "rb+");

    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool modifico = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return modifico;
}

void ArchivoCabeceraPedidos::listarReg(){
    int cantReg = contarRegistro();
    for(int i=0; i<cantReg; i++){
        Cabecera obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<"======================="<<endl;
        }
    }
}

void ArchivoCabeceraPedidos::bajaRegistro(){
    int id;
    cout<<"INGRESE EL ID DEL REGISTRO A DAR DE BAJA: ";
    cin>>id;
    ArchivoCabeceraPedidos arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE ESA ID EN EL ARCHIVO"<<endl;
        return;
    }
    Cabecera obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}
