#ifndef ARCHIVOCLIENTES_H_INCLUDED
#define ARCHIVOCLIENTES_H_INCLUDED
#include "ClsCliente.h"

class ArchivoClientes{
private:
    char _nombre[30];

public:
    ArchivoClientes(const char *n="Clientes.dat");
    Clientes leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(Clientes obj);
    int buscarRegistro(int id);
    bool modificarRegistro(Clientes obj, int pos);
    void listarReg();
    void bajaRegistro();
};

#endif // ARCHIVOCLIENTES_H_INCLUDED
