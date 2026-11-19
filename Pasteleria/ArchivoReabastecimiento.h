#ifndef ARCHIVOREABASTECIMIENTO_H_INCLUDED
#define ARCHIVOREABASTECIMIENTO_H_INCLUDED
#include "ClsReabastecimiento.h"

class ArchivoReabastecimiento
{

private:
    char _nombre[30];
public:
    ArchivoReabastecimiento(const char *n = "Reabastecimiento.dat");
    Reabastecimiento leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(Reabastecimiento obj);
    int buscarRegistro(int id);
    bool modificarRegistro(Reabastecimiento obj, int pos);
    void listarReg();
    void bajaRegistro();
};


#endif // ARCHIVOREABASTECIMIENTO_H_INCLUDED
