#include <iostream>
#include <cstring>

using namespace std;

Archivo(const char *n="Archivo.dat"){
    strcpy(_nombre,n);
}

clase leerRegistro(int pos){
    FILE *p=fopen(_nombre,"rb");
    clase obj;
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

int contarRegistro(){
    FILE *p=fopen(_nombre, "rb");
    if (p==nullptr){
        cout<<"ERROR AL CONTAR."<<endl;
        return -1;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(clase);
}
bool grabarRegistro(clase obj){
    FILE *p = fopen(_nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
int buscarRegistro(int leg){
    int cantReg = contarRegistro();
    for(int i=0; i<cantReg; i++){
        clase obj = leerRegistro(i);
        if(obj.getID() == id) return i;
    }
    return -1;
}

bool modificarRegistro(clase obj, int pos){
    FILE *p = fopen(_nombre, "rb+");

    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool modifico = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return modifico;
}

void listarReg(){
    int cantReg = contarRegistro();
    for(int i=0; i<cantReg; i++){
        clase obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<"======================="<<endl;
        }
    }
}

void bajaRegistro(){
    int id;
    cout<<"INGRESE EL ID DEL REGISTRO A DAR DE BAJA: ";
    cin>>id;
    Archivo arc;
    int pos = arc.buscarRegistro(id);
    if(pos < 0){
        cout<<"NO EXISTE ESA ID EN EL ARCHIVO"<<endl;
        return;
    }
    Pasajes obj = arc.leerRegistro(pos);
    obj.setEstado(false);
    arc.modificarRegistro(obj, pos);
}
