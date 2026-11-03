#ifndef ARCHIVOCABECERAPEDIDOS_H_INCLUDED
#define ARCHIVOCABECERAPEDIDOS_H_INCLUDED
#include "clsCabecera.h"

class ArchivoCabeceraPedidos{
private:
    char _nombre[30];

public:
    ArchivoCabeceraPedidos(const char *n="ArchivoCabeceraPedidos.dat");
    Cabecera leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(Cabecera obj);
    int buscarRegistro(int leg);
    void listarReg();
};

#endif // ARCHIVOCABECERAPEDIDOS_H_INCLUDED
