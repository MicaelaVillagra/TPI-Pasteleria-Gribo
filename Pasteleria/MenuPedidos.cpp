#include <iostream>
#include "MenuPedidos.h"

using namespace std;

MenuPedidos::MenuPedidos(): Menu(6){

    setItem(1,"Cargar cabecera de pedido");
    setItem(2,"Cargar detalle de pedido");
    setItem(3,"Listar cabeceras de pedidos");
    setItem(4,"Listar detalles de pedidos");
    setItem(5,"Dar de baja una cabecera de pedido");
    setItem(6,"Dar de baja un detalle de pedido");
}

void MenuPedidos::run(){

    int opcion;

    do{
        dibujarMenu();
        opcion = obtenerRespuesta();

        switch(opcion){

        case 1:
        {
            CabeceraPedido obj;
            obj.Cargar();

            if(_archivoCabecera.buscarRegistro(obj.getIDCabecera()) >= 0){
                cout << "Ya existe una cabecera con ese ID." << endl;
            }

            else if(_archivoCabecera.grabarRegistro(obj)){
                cout << "Cabecera guardada." << endl;
            }

            else{
                cout << "No se pudo guardar la cabecera." << endl;
            }
            break;
        }
        case 2:
        {
            DetallePedido obj;
            obj.Cargar();

            if(_archivoDetalle.buscarRegistro(obj.getIDDetalle()) >= 0){
                cout<<"Ya existe un detalle con ese ID"<<endl;
            }
            else if(_archivoDetalle.grabarRegistro(obj)){
                cout<<"Detalle guardado"<< endl;
            }
            else{
                cout<<"No se pudo guardar el detalle"<< endl;
            }
            break;
        }
        case 3:
        {
            _archivoCabecera.listarReg();
            break;
        }
        case 4:
        {
            _archivoDetalle.listarReg();
            break;
        }
        case 5:
        {
            _archivoCabecera.bajaRegistro();
            break;
        }
        case 6:
        {
            _archivoDetalle.bajaRegistro();
            break;
        }
        }
        if(opcion != 0){
            pausar();
        }
    }
    while(opcion != 0);
}
