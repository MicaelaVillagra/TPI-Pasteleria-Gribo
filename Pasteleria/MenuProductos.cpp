#include <iostream>
#include "MenuProductos.h"

using namespace std;

MenuProductos::MenuProductos()
    : Menu(3)
{
    setItem(1, "Cargar producto");
    setItem(2, "Listar productos");
    setItem(3, "Dar de baja un producto");
}

void MenuProductos::run()
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
            Productos obj;
            obj.Cargar();

            if(_archivo.buscarRegistro(obj.getIdProducto()) >= 0)
            {
                cout << "Ya existe un producto con ese ID." <<endl;
            }
            else if (_archivo.grabarRegistro(obj))
            {
                cout << "Producto guardado." <<endl;
            }
            else
            {
                cout << "No se pudo guardar el producto." << endl;
            }
            break;
        }
        case 2:
        {
            _archivo.listarReg();
            break;
        }
        case 3:
        {
            _archivo.bajaRegistro();
            break;
        }
        }
    }
    while (opcion != 0);
}
