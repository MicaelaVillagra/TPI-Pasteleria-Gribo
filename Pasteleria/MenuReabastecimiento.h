#ifndef MENUREABASTECIMIENTO_H_INCLUDED
#define MENUREABASTECIMIENTO_H_INCLUDED
#include "Menu.h"
#include "ArchivoReabastecimiento.h"
#include "ArchivoProductos.h"

class MenuReabastecimiento : public Menu
{
public:
    MenuReabastecimiento();
    void run();
private:
    ArchivoReabastecimiento _archivo;
    ArchivoProductos _archivoProductos;
};

#endif // MENUREABASTECIMIENTO_H_INCLUDED
