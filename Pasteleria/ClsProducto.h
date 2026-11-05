#ifndef CLSPRODUCTOS_H_INCLUDED
#define CLSPRODUCTOS_H_INCLUDED
#pragma once

class Productos {
    private:
        int _idProducto;
        char _nombre[25];
        float _precio;
        int _stock;
        bool _estado;

    public:
        Productos();
        Productos(int id, const char *n, float p, int s, bool e);
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
