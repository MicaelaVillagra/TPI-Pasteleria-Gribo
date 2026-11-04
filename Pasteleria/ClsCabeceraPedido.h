#ifndef CLSCABECERAPEDIDOS_H_INCLUDED
#define CLSCABECERAPEDIDOS_H_INCLUDED
#pragma once
#include "Fecha.h"

class CabeceraPedido{
private:
    int _IDPedido;
    int _idCabecera;
    int _idEmpleado;
    int _idCliente;
    Fecha _fechaEncargo;
    char _metodoPago[20];
    bool _estado;
public:
    void setIDPedido (int id);
    void setIDCabecera(int id);
    void setIDEmpleado (int id);
    void setIDCliente (int id);
    void setFechaEncargo(Fecha f);
    void setMetodoPago(const char *m);
    void setEstado (bool estado);
    int getIDPedido ();
    int getIDCabecera ();
    int getIDEmpleado ();
    int getIDCliente ();
    Fecha getFechaEncargo();
    const char *getMetodoPago();
    bool getEstado();
    void Cargar();
    void Mostrar();

};




#endif // CLSCABECERAPEDIDOS_H_INCLUDED
