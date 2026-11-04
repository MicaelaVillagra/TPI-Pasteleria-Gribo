#include <iostream>
#include "ClsReabastecimiento.h"
using namespace std;

Reabastecimiento::Reabastecimiento()
{
    _idReabastecimiento = 0;
    _idProducto = 0;
    _cantidad = 0;
    _estado = true;

}
Reabastecimiento::Reabastecimiento(int r, int i, int c, Fecha f, bool e)
{
    setIDReabastecimiento(r);
    setIDProducto(i);
    setCantidad(c);
    setFechaIngreso(f);
    setEstado(e);
}

void Reabastecimiento::setIDReabastecimiento(int id)
{
    if (id > 0) {
        _idReabastecimiento = id;
    }
}

void Reabastecimiento::setIDProducto(int id)
{
    if(id > 0)
    {
        _idProducto = id;
    }
}

void Reabastecimiento::setCantidad(int c)
{
    if(c >0)
    {
        _cantidad = c;
    }
}

void Reabastecimiento::setFechaIngreso(Fecha f)
{
    _fechaIngreso = f;
}
void Reabastecimiento::setEstado(bool e)
{
    _estado = e;
}

int Reabastecimiento::getIDReabastecimiento()
{
    return _idReabastecimiento;
}

int Reabastecimiento::getIDProducto()
{
    return _idProducto;
}

int Reabastecimiento::getCantidad()
{
    return _cantidad;
}

bool Reabastecimiento::getEstado()
{
    return _estado;
}

Fecha Reabastecimiento::getFechaIngreso()
{
    return _fechaIngreso;
}

void Reabastecimiento::Cargar()
{
    int id, idProd, cant;

    cout<<"Ingrese el ID de reabastecimiento : "<<endl;
    cin>>id;
    setIDReabastecimiento(id);

    cout<<"Ingrese el ID de Producto : " << endl;
    cin>>idProd;
    setIDProducto(idProd);

    cout<<"Ingrese la cantidad : ";
    cin>>cant;
    setCantidad(cant);

    cout<<"Fecha de ingreso : " << endl;
    _fechaIngreso.Cargar();
    setEstado(true);
}

void Reabastecimiento::Mostrar()
{
    cout << " ID: " << _idReabastecimiento;
    cout << " Producto: " << _idProducto;
    cout << " Cantidad: " << _cantidad;
    cout << " Fecha: ";
    _fechaIngreso.Mostrar();
    cout << endl;
}





