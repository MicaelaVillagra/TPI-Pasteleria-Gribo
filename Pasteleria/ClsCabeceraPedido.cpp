#include <iostream>
#include "ClsCabeceraPedidos.h"
#include <cstring>

using namespace std;

    void CabeceraPedido::setIDPedido(int id){
        _IDPedido=id;
    }
    void CabeceraPedido::setIDCabecera(int id){
        _idCabecera=id;
    }
    void CabeceraPedido::setIDEmpleado (int id){
        _idEmpleado=id;
    }
    void CabeceraPedido::setIDCliente (int id){
        _idCliente=id;
    }
    void CabeceraPedido::setFechaEncargo(Fecha f){
        _fechaEncargo=f;
    }
    void CabeceraPedido::setMetodoPago(const char *m){
        strcpy(_metodoPago,m);
    }
    void CabeceraPedido::setEstado (bool estado){
        _estado=estado;
    }
    int CabeceraPedido::getIDPedido(){
        return _IDPedido;
    }
    int CabeceraPedido::getIDCabecera (){
        return _idCabecera;
    }
    int CabeceraPedido::getIDEmpleado (){
        return _idEmpleado;
    }
    int CabeceraPedido::getIDCliente (){
        return _idCliente;
    }
    Fecha CabeceraPedido::getFechaEncargo(){
        return _fechaEncargo;
    }
    const char *CabeceraPedido::getMetodoPago(){
        return _metodoPago;
    }
    bool CabeceraPedido::getEstado(){
        return _estado;
    }
    void CabeceraPedido::Cargar(){
        Fecha auxF;
        int aux;
        char auxC[20];
        cout<<"INGRESE ID DEL PEDIDO"<<endl;
        cin>>aux;
        setIDPedido(aux);
        cout<<"INGRESE ID DE LA CABECERA"<<endl;
        cin>>aux;
        setIDCabecera(aux);
        cout<<"INGRESE ID DEL EMPLEADO RESPONSABLE DEL PEDIDO"<<endl;
        cin>>aux;
        setIDEmpleado(aux);
        cout<<"INGRESE ID DEL CLIENTE"<<endl;
        cin>>aux;
        setIDCliente(aux);
        cout<<"FECHA DEL PEDIDO: "<<endl;
        auxF.Cargar();
        setFechaEncargo(auxF);
        cout<<"ELEGIR METODO DE PAGO"<<endl;
        cin>>auxC;
        setMetodoPago(auxC);
        setEstado(true);
    }
    void CabeceraPedido::Mostrar(){
        cout<<"ID DEL PEDIDO: "<<getIDPedido()<<endl;
        cout<<"ID DE CABECERA: "<<getIDCabecera()<<endl;
        cout<<"ID DEL EMPLEADO: "<<getIDEmpleado()<<endl;
        cout<<"ID DEL CLIENTE: "<<getIDCliente()<<endl;
        cout<<"FECHA DEL PEDIDO: ";
        getFechaEncargo().Mostrar();
        cout<<endl;
        cout<<"METODO DE PAGO: "<<getMetodoPago()<<endl;
        cout<<"ESTADO: "<<getEstado()<<endl;
    }
