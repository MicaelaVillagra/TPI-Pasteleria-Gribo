#ifndef CLSREABASTECIMIENTO_H_INCLUDED
#define CLSREABASTECIMIENTO_H_INCLUDED
#include "Fecha.h"

class Reabastecimiento
{
private:
    int _idReabastecimiento;
    int _idProducto;
    int _cantidad;
    Fecha _fechaIngreso;
    bool _estado;

public:
    Reabastecimiento();
    Reabastecimiento(int r, int i, int c, Fecha f, bool e);
    void setIDReabastecimiento(int id);
    void setIDProducto(int id);
    void setCantidad(int c);
    void setFechaIngreso(Fecha f);
    void setEstado(bool e);
    int getIDReabastecimiento();
    int getIDProducto();
    int getCantidad();
    Fecha getFechaIngreso();
    bool getEstado();
    void Mostrar();
    void Cargar();


};

#endif // CLSREABASTECIMIENTO_H_INCLUDED
