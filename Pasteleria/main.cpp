#include <iostream>
#include "Fecha.h"
#include "MenuPrincipal.h"
#include "CargarDatosPrueba.h"

using namespace std;

int main()
{
    cargarDatosPrueba();
    MenuPrincipal menu;
    menu.run();

    return 0;
}
