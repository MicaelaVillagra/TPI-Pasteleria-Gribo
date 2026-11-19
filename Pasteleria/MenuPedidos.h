#ifndef MENUPEDIDOS_H_INCLUDED
#define MENUPEDIDOS_H_INCLUDED
#include "Menu.h"
#include "ArchivoCabeceraPedidos.h"
#include "ArchivoDetallePedidos.h"
#include "ArchivoProductos.h"

class MenuPedidos : public Menu
{
public:
    MenuPedidos();
    void run();
private:
    ArchivoCabeceraPedidos _archivoCabecera;
    ArchivoDetallePedidos _archivoDetalle;
    ArchivoProductos _archivoProductos;
};

#endif // MENUPEDIDOS_H_INCLUDED
