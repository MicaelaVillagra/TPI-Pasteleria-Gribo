#ifndef MENUEMPLEADOS_H_INCLUDED
#define MENUEMPLEADOS_H_INCLUDED
#include "Menu.h"
#include "ArchivoEmpleados.h"

class MenuEmpleados : public Menu
{
public :
    MenuEmpleados();
    void run();
private:
    ArchivoEmpleados _archivo;
};


#endif // MENUEMPLEADOS_H_INCLUDED
