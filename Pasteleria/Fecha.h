#pragma once
#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{

private:
    int _dia;
    int _mes;
    int _anio;

    bool EsBisiesto (int anio);
    int DiasDelMes (int mes, int anio);
    bool EsValida (int dia, int mes, int anio);

public:
    Fecha(int d=1, int m=1, int a=1993);
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    int getDia();
    int getMes();
    int getAnio();
    void Cargar();
    void Mostrar();

    ~Fecha ();

};


#endif // FECHA_H_INCLUDED
