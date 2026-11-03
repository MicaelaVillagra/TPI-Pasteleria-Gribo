#ifndef CLSPRODUCTOS_H_INCLUDED
#define CLSPRODUCTOS_H_INCLUDED
#pragma once

class Productos {
    private:
        int IDProducto;
        char Producto [25];
        float PrecioProducto;
        int CantDisponible;
        bool Estado;

    public:
        void setIdProducto(int id);
        void setNombre(const char *n);
        void setPrecio(float p);
        void setStock(int s);
        void setEstado(bool e);

        int getIdProducto();
        const char *getNombre();
        float getPrecio();
        int getStock();
        bool getEstado();

        void Cargar();
        void Mostrar();

};





#endif // CLSPRODUCTOS_H_INCLUDED
