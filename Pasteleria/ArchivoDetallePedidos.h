#ifndef ARCHIVODETALLEPEDIDOS_H_INCLUDED
#define ARCHIVODETALLEPEDIDOS_H_INCLUDED
#include "ClsDetallePedidos.h"


class ArchivoDetallePedidos{
private:
    char _nombre[30];

public:
    ArchivoDetallePedidos(const char *n="DetallePedidos.dat");
    DetallePedido leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(DetallePedido obj);
    int buscarRegistro(int id);
    bool modificarRegistro(DetallePedido obj, int pos);
    void listarReg();
    void bajaRegistro();
};

#endif // ARCHIVODETALLEPEDIDOS_H_INCLUDED
