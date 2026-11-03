#ifndef ARCHIVODETALLEPEDIDOS_H_INCLUDED
#define ARCHIVODETALLEPEDIDOS_H_INCLUDED
#include "clsDetalle.h"


class ArchivoDetallePedidos{
private:
    char _nombre[30];

public:
    ArchivoDetallePedidos(const char *n="ArchivoDetallePedidos.dat");
    Detalle leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(Detalle obj);
    int buscarRegistro(int leg);
    void listarReg();
};

#endif // ARCHIVODETALLEPEDIDOS_H_INCLUDED
