#include <iostream>
#include "MenuPrincipal.h"

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
                cout << "Productos: en construccion " << endl;
                break;
            }
        case 2:
            {
                cout << "Clientes: en construccion " << endl;
                break;
            }
        case 3:
            {
                cout <<"Empleados: en construccion " << endl;
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
                cout << "Reportes: en construccion " << endl;
                break;
            }
        }
    }while (opcion !=0);
}

