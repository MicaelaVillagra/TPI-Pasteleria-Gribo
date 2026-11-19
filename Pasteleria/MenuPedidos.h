#ifndef MENUPEDIDOS_H_INCLUDED
#define MENUPEDIDOS_H_INCLUDED
#include "Menu.h"
#include "ArchivoCabeceraPedidos.h"
#include "ArchivoDetallePedidos.h"

class MenuPedidos: public Menu{

    public:
        MenuPedidos();
        void run();

    private:
        ArchivoCabeceraPedidos _archivoCabecera;
        ArchivoDetallePedidos _archivoDetalle;
};

#endif // MENUPEDIDOS_H_INCLUDED
