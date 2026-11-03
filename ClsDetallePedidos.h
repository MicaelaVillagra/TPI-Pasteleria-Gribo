#ifndef CLSDETALLEPEDIDOS_H_INCLUDED
#define CLSDETALLEPEDIDOS_H_INCLUDED
#pragma once

class DetallePedido{
private:
    int IDPedido;
    int _idDetalle;
    int _idProducto;
    int _cantidad;
    float _precio;
    bool _estado;
public:
    void setIDDetalle(int id);
    void setIDProducto(int id);
    void setCantidad(int cantidad);
    void setPrecio(float precio);
    void setEstado (bool estado);
    int getIDDetalle ();
    int getIDProducto ();
    int getCantidad ();
    float getPrecio ();
    bool getEstado();
    void Cargar();
    void Mostrar();

};

#endif // CLSDETALLEPEDIDOS_H_INCLUDED
