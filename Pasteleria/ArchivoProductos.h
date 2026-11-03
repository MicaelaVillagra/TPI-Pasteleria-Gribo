#ifndef ARCHIVOPRODUCTOS_H_INCLUDED
#define ARCHIVOPRODUCTOS_H_INCLUDED
#include "clsProducto.h"

class ArchivoProductos{
private:
    char _nombre[30];

public:
    ArchivoProductos(const char *n="ArchivoProductos.dat");
    Producto leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(Producto obj);
    int buscarRegistro(int leg);
    void listarReg();
};

#endif // ARCHIVOPRODUCTOS_H_INCLUDED
