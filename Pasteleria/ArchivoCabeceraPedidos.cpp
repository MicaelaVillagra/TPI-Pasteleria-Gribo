#include <iostream>
#include <cstring>
#include "ArchivoCabeceraPedidos.h"

using namespace std;

ArchivoCabeceraPedidos::ArchivoCabeceraPedidos(const char *n){
    strcpy(_nombre,n);
}

CabeceraPedido ArchivoCabeceraPedidos::leerRegistro(int pos){
    FILE *p=fopen(_nombre,"rb");
    CabeceraPedido obj;
    if (p==nullptr){
        cout<<"NO SE PUEDE."<<endl;
        obj.setIDCabecera(-1);
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
    return bytes/sizeof(CabeceraPedido);
}
bool ArchivoCabeceraPedidos::grabarRegistro(CabeceraPedido obj){
    FILE *p = fopen(_nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
int ArchivoCabeceraPedidos::buscarRegistro(int id){
    int cantReg = contarRegistro();
    for(int i=0; i<cantReg; i++){
        CabeceraPedido obj = leerRegistro(i);
        if(obj.getIDCabecera() == id) return i;
    }
    return -1;
}

bool ArchivoCabeceraPedidos::modificarRegistro(CabeceraPedido obj, int pos){
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
        CabeceraPedido obj = leerRegistro(i);
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
    CabeceraPedido obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}
