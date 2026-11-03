#ifndef ARCHIVOCLIENTES_H_INCLUDED
#define ARCHIVOCLIENTES_H_INCLUDED
#include "clsCliente.h"

class ArchivoClientes{
private:
    char _nombre[30];

public:
    ArchivoClientes(const char *n="ArchivoClientes.dat");
    Cliente leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(Cliente obj);
    int buscarRegistro(int leg);
    void listarReg();
};

#endif // ARCHIVOCLIENTES_H_INCLUDED
