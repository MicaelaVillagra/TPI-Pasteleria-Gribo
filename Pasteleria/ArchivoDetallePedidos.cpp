#include <iostream>
#include <cstring>
#include "ArchivoDetallePedidos.h"

using namespace std;

ArchivoDetallePedidos::ArchivoDetallePedidos(const char *n){
    strcpy(_nombre,n);
}

DetallePedido ArchivoDetallePedidos::leerRegistro(int pos){
    FILE *p=fopen(_nombre,"rb");
    DetallePedido obj;
    if (p==nullptr){
        cout<<"NO SE PUEDE."<<endl;
        obj.setIDDetalle(-1);
        return obj;
    }
    fseek(p,pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoDetallePedidos::contarRegistro(){
    FILE *p=fopen(_nombre, "rb");
    if (p==nullptr){
        cout<<"ERROR AL CONTAR."<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(DetallePedido);
}
bool ArchivoDetallePedidos::grabarRegistro(DetallePedido obj){
    FILE *p = fopen(_nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
int ArchivoDetallePedidos::buscarRegistro(int id){
    int cantReg = contarRegistro();
    for(int i=0; i<cantReg; i++){
        DetallePedido obj = leerRegistro(i);
        if(obj.getIDDetalle() == id) return i;
    }
    return -1;
}

bool ArchivoDetallePedidos::modificarRegistro(DetallePedido obj, int pos){
    FILE *p = fopen(_nombre, "rb+");

    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool modifico = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return modifico;
}

void ArchivoDetallePedidos::listarReg(){
    int cantReg = contarRegistro();
    for(int i=0; i<cantReg; i++){
        DetallePedido obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<"======================="<<endl;
        }
    }
}

void ArchivoDetallePedidos::bajaRegistro(){
    int id;
    cout<<"INGRESE EL ID DEL REGISTRO A DAR DE BAJA: ";
    cin>>id;
    ArchivoDetallePedidos arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE ESA ID EN EL ARCHIVO"<<endl;
        return;
    }
    DetallePedido obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}
