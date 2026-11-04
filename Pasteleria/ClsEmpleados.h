#ifndef CLSEMPLEADOS_H_INCLUDED
#define CLSEMPLEADOS_H_INCLUDED
#pragma once
#include "ClsPersona.h"


class Empleados : public Persona {
private:
    char oficio [25];

public:
    void setOficio(const char *o);
    const char *getOficio();
    void Cargar();
    void Mostrar();

};

#endif // CLSEMPLEADOS_H_INCLUDED
