#ifndef ARCHIVOPRODUCTOS_H_INCLUDED
#define ARCHIVOPRODUCTOS_H_INCLUDED
#include "ClsProducto.h"

class ArchivoProductos{
private:
    char _nombre[30];

public:
    ArchivoProductos(const char *n="Productos.dat");
    Productos leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(Productos obj);
    int buscarRegistro(int id);
    bool modificarRegistro(Productos obj, int pos);
    void listarReg();
    void bajaRegistro();
};

#endif // ARCHIVOPRODUCTOS_H_INCLUDED
