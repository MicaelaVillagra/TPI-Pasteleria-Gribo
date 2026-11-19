#include <iostream>
#include "MenuEmpleados.h"

using namespace std;

MenuEmpleados::MenuEmpleados()
    : Menu(3)
{
    setItem(1, "Cargar empleados");
    setItem(2, "Listar empleados");
    setItem(3, "Dar de baja un empleado");
}

void MenuEmpleados::run()
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
            Empleados obj;
            obj.Cargar();
            if(_archivo.buscarRegistro(obj.getID()) >=0)
            {
                cout <<"Ya existe un empleado con ese ID" << endl;
            }
            else if (_archivo.grabarRegistro(obj))
            {
                cout<< "Empleado guardado" << endl;
            }
            else
            {
                cout << "No se pudo guardar el empleado" << endl;
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
