#include <iostream>
#include "MenuClientes.h"

using namespace std;

MenuClientes::MenuClientes()
  : Menu(3)
  {
      setItem(1, "Cargar clientes");
      setItem(2, "Listar Clientes");
      setItem(3, "Dar de baja un cliente");
  }

void MenuClientes::run()
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
                Clientes obj;
                obj.Cargar();

                if(_archivo.buscarRegistro(obj.getID()) >= 0)// aca no se como poner)
                {
                    cout <<"Ya existe un cliente con ese ID" << endl;
                }
                    else if(_archivo.grabarRegistro(obj))
                    {
                        cout << "Cliente guardado." <<endl;
                    }
                    else
                    {
                        cout << "No se pudo guardae el cliente." << endl;
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
    }
    while(opcion !=0);
}


