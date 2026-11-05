#include <iostream>
#include <cstring>
#include "ClsProducto.h"
using namespace std;


Productos::Productos()
{
    _idProducto = 0 ;
     strcpy(_nombre, "");
    _precio= 0;
    _stock = 0;
    _estado = true;
}

Productos::Productos(int id,const char *n, float p, int s, bool e )
{
    setIdProducto(id);
    setNombre(n);
    setPrecio(p);
    setStock(s);
    setEstado(e);
}

void Productos::setIdProducto(int id)
{
    if(id >0)
    {
        _idProducto = id
    }
}

void Productos::setNombre(const char *n)
{
    if (strlen(n) > 0 && strlen(n) < 25)
    {
        strcpy(_nombre, n);
    }
}
void Productos::setPrecio(float p)
{
    if(p > 0)
    {
        _precio = p;
    }
}

void Productos::setStock(int s)
{
    if(s >= 0)
    {
        _stock = s;
    }
}

void Productos::setEstado(bool e)
{
    _estado = e;
}

int Productos::getIdProducto()
{
    return _idProducto;

}

const char *Productos::getNombre()
{
    return _nombre;
}

float Productos::getPrecio()
{
    return _precio;
}

int Productos::getStock()
{
    return _stock;
}

bool Productos::getEstado()
{
    return _estado;
}

void Productos::Cargar()
{
    int id, s;
    char n[25];
    float p;

    cout<<"Ingrese el ID del Producto : "<<endl;
    cin>>id;
    setIdProducto(id);

    cout<<"Ingrese nombre : " <<endl;
    cin.ignore();
    cin.getline(n,25);
    setNombre(n);

    cout<<"Precio : "<<endl;
    cin>>p;
    setPrecio(p);

    cout<<"Cantidad disponible :"<<endl;
    cin>>s;
    setStock(s);

    setEstado(true);
}

void Productos::Mostrar()
{
    cout<<"ID Producto : "<< _idProducto <<endl;
    cout<<"Producto : " << _nombre<<end;
    cout<<"Precio Producto : " <<  _precio <<endl;
    cout<<"Cantidad disponible : " << _stock << endl;;
}
