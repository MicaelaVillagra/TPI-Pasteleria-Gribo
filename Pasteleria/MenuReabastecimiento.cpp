#include <iostream>
#include "MenuReabastecimiento.h"

using namespace std;

MenuReabastecimiento::MenuReabastecimiento()
    : Menu(3)
{
    setItem(1, "Registrar reabastecimiento");
    setItem(2, "Listar Reabastecimiento");
    setItem(3, "Dar de baja un reabastecimiento");
}

void MenuReabastecimiento::run()
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
            Reabastecimiento obj;
            obj.Cargar();

            if(obj.getIDReabastecimiento() == 0 || obj.getCantidad() == 0)
            {
                cout <<"El ID y la cantidad deben ser mayores a 0 (cero). " << endl;
                break;
            }

            int posProd = _archivoProductos.buscarRegistro(obj.getIDProducto());
            if(_archivo.buscarRegistro(obj.getIDReabastecimiento()) >= 0)
            {
                cout << "Ya existe un reabastecimiento con ese ID." <<endl;
                break;
            }

            Productos prod = _archivoProductos.leerRegistro(posProd);
            if(prod.getEstado() == false)
            {
                cout<< "Ese producto esta dado de baja" << endl;
                break;
            }

            if(_archivo.grabarRegistro(obj))
            {
                prod.setStock(prod.getStock() + obj.getCantidad());
                _archivoProductos.modificarRegistro(prod, posProd);
                cout<< "Reabastecimiento registrado. Nuevo stock : " << prod.getStock() << endl;
            }
            else
            {
                cout << "No se pudo guardar el reabastecimiento" <<endl;
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
        if (opcion != 0)
        {
            pausar();
        }
    } while(opcion != 0);
}
