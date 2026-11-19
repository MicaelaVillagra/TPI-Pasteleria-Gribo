#include <iostream>
#include <cstring>
#include "ArchivoReabastecimiento.h"

using namespace std;

ArchivoReabastecimiento::ArchivoReabastecimiento(const char *n)
{
    strcpy(_nombre, n);
}

Reabastecimiento ArchivoReabastecimiento::leerRegistro(int pos)
{
    Reabastecimiento obj;
    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        cout << " NO SE PUDO ABRIR EL ARCHIVO." <<endl;
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoReabastecimiento::contarRegistro()
{
    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return 0;
    }
    fseek(p,0,2);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Reabastecimiento);
}

bool ArchivoReabastecimiento::grabarRegistro(Reabastecimiento obj)
{
    FILE *p = fopen(_nombre, "ab");
    if(p == nullptr)
    {
        return false;
    }
    bool escribo = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribo;
}

int ArchivoReabastecimiento::buscarRegistro(int id)
{
    int cantReg = contarRegistro();
    for (int i = 0; i < cantReg ; i++ )
        {
            Reabastecimiento obj = leerRegistro(i);
            if(obj.getIDReabastecimiento() == id)
            {
                return i;
            }
        }
        return -1;
}

bool ArchivoReabastecimiento::modificarRegistro(Reabastecimiento obj, int pos)
{
    FILE *p = fopen(_nombre, "rb+");
    if(p == nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool modifico = fwrite(&obj, sizeof obj, 1,p);
    fclose(p);
    return modifico;
}

void ArchivoReabastecimiento::listarReg()
{
    int cantReg = contarRegistro();
    int mostrados = 0;

    for (int i = 0; i < cantReg ; i++ )
        {
            Reabastecimiento obj = leerRegistro(i);
            if(obj.getEstado())
            {
                obj.Mostrar();
                cout<< "================================" << endl;
                mostrados++;
            }
        }
        if(mostrados == 0)
        {
            cout << "No hay reabastecimientos cargados." << endl;
        }
}

void ArchivoReabastecimiento::bajaRegistro()
{
    int id;
    cout << "Ingrese el ID del reabastecimiento a dar de baja : " ;
    cin >> id;

    int pos = buscarRegistro(id);
    if(pos < 0)
    {
        cout << "No existe un reabastecimiento con ese ID." <<endl;
        return;
    }
    Reabastecimiento obj = leerRegistro(pos);
    if(obj.getEstado() == false)
    {
        cout<< "El reabastecimiento ya esta dado ded baja." << endl;
        return;
    }

    obj.setEstado(false);
    if(modificarRegistro(obj, pos))
    {
        cout << "Reabastecimiento dado de baja. " << endl;
    }else
    {
        cout << "No se pudo dar de baja." << endl;
    }
}
