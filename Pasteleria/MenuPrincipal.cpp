#include <iostream>
#include "MenuPrincipal.h"
#include "MenuReportes.h"
#include "MenuProductos.h"
#include "MenuClientes.h"
#include "MenuEmpleados.h"

using namespace std;

MenuPrincipal::MenuPrincipal()
    : Menu(6)
{
    setItem(1, "Productos");
    setItem(2, "Clientes");
    setItem(3, "Empleados");
    setItem(4, "Pedidos");
    setItem(5, "Reabastecimiento");
    setItem(6, "Reportes");
}

void MenuPrincipal::run()
{
    int opcion;

    do
    {
        dibujarMenu();
        opcion = obtenerRespuesta();

        switch(opcion)
        {
        case 1:
        {
            MenuProductos menuProductos;
            menuProductos.run();
            break;
        }
        case 2:
        {
            MenuClientes menuClientes;
            menuClientes.run();
            break;
        }
        case 3:
        {
            MenuEmpleados menuEmpleados;
            menuEmpleados.run();
            break;
        }
        case 4:
        {
            cout << "Pedidos: en construccion " << endl;
            break;
        }
        case 5:
        {
            cout << "Reabastecimiento: en construccion " <<endl;
            break;
        }
        case 6:
        {
            MenuReportes menuReportes;
            menuReportes.run();
            break;
        }
        }
    }
    while (opcion !=0);
}

