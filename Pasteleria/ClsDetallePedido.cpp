#include <iostream>
#include "ClsDetallePedido.h"

using namespace std;

void DetallePedido::setIDPedido(int id){
    IDPedido=id;
}
void DetallePedido::setIDDetalle(int id){
    _idDetalle=id;
}
void DetallePedido::setIDProducto(int id){
    _idProducto=id;
}
void DetallePedido::setCantidad(int cantidad){
    _cantidad=cantidad;
}
void DetallePedido::setPrecio(float precio){
    _precio=precio;
}
void DetallePedido::setEstado (bool estado){
    _estado=estado;
}
int DetallePedido::getIDPedido (){
    return IDPedido;
}
int DetallePedido::getIDDetalle (){
    return _idDetalle;
}
int DetallePedido::getIDProducto (){
    return _idProducto;
}
int DetallePedido::getCantidad (){
    return _cantidad;
}
float DetallePedido::getPrecio (){
    return _precio;
}
bool DetallePedido::getEstado(){
    return _estado;
}
void DetallePedido::Cargar(){
    int aux;
    float auxF;
    cout<<"INGRESE LA ID DEL PEDIDO"<<endl;
    cin>>aux;
    setIDPedido(aux);
    cout<<"INGRESE LA ID DEL DETALLE"<<endl;
    cin>>aux;
    setIDDetalle(aux);
    cout<<"INGRESE LA ID DEL PRODUCTO"<<endl;
    cin>>aux;
    setIDProducto(aux);
    cout<<"INGRESE LA CANTIDAD QUE SE VENDIO EN ESTE PEDIDO"<<endl;
    cin>>aux;
    setCantidad(aux);
    cout<<"INGRESE EL PRECIO DEL PEDIDO"<<endl;
    cin>>auxF;
    setPrecio(auxF);
    setEstado(true);
}
void DetallePedido::Mostrar(){
    cout<<"ID DEL PEDIDO: "<<getIDPedido()<<endl;
    cout<<"ID DEL DETALLE: "<<getIDDetalle()<<endl;
    cout<<"ID DEL PRODUCTO: "<<getIDProducto()<<endl;
    cout<<"CANTIDAD VENDIDA EN ESTE PEDIDO: "<<getCantidad()<<endl;
    cout<<"PRECIO DEL PEDIDO: "<<getPrecio()<<endl;
    cout<<"ESTADO: "<<getEstado()<<endl;
}
