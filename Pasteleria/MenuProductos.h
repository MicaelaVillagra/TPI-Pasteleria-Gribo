#ifndef MENUPRODUCTOS_H_INCLUDED
#define MENUPRODUCTOS_H_INCLUDED
#include "Menu.h"
#include "ArchivoProductos.h"

class MenuProductos : public Menu
{
public:
    MenuProductos();
    void run();
private:
    ArchivoProductos _archivo;
};


#endif // MENUPRODUCTOS_H_INCLUDED
