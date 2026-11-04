#ifndef ARCHIVOCABECERAPEDIDOS_H_INCLUDED
#define ARCHIVOCABECERAPEDIDOS_H_INCLUDED
#include "ClsCabeceraPedidos.h"

class ArchivoCabeceraPedidos{
private:
    char _nombre[30];

public:
    ArchivoCabeceraPedidos(const char *n="CabeceraPedidos.dat");
    CabeceraPedido leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(CabeceraPedido obj);
    int buscarRegistro(int id);
    bool modificarRegistro(CabeceraPedido obj, int pos);
    void listarReg();
    void bajaRegistro();
};

#endif // ARCHIVOCABECERAPEDIDOS_H_INCLUDED
