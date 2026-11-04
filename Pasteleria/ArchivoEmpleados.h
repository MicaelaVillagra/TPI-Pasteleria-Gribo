#ifndef ARCHIVOEMPLEADOS_H_INCLUDED
#define ARCHIVOEMPLEADOS_H_INCLUDED
#include "ClsEmpleado.h"


class ArchivoEmpleados{
private:
    char _nombre[30];

public:
    ArchivoEmpleados(const char *n="Empleados.dat");
    Empleados leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(Empleados obj);
    int buscarRegistro(int id);
    bool modificarRegistro(Empleados obj, int pos);
    void listarReg();
    void bajaRegistro();
};

#endif // ARCHIVOEMPLEADOS_H_INCLUDED
