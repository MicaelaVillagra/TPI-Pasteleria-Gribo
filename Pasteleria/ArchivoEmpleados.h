#ifndef ARCHIVOEMPLEADOS_H_INCLUDED
#define ARCHIVOEMPLEADOS_H_INCLUDED
#include "clsEmpleado.h"


class ArchivoEmpleados{
private:
    char _nombre[30];

public:
    ArchivoEmpleados(const char *n="ArchivoEmpleados.dat");
    Empleado leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(Empleado obj);
    int buscarRegistro(int leg);
    void listarReg();
};

#endif // ARCHIVOEMPLEADOS_H_INCLUDED
