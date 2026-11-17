#ifndef MENUCLIENTES_H_INCLUDED
#define MENUCLIENTES_H_INCLUDED
#include "Menu.h"
#include "ArchivoClientes.h"

class MenuClientes : public Menu
{
public:
    MenuClientes();
    void run();
private:
    ArchivoClientes _archivo;
};

#endif // MENUCLIENTES_H_INCLUDED
