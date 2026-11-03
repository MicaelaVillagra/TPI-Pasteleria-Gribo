#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED
#pragma once

class Persona {
private:
    int _ID;
    char _nombreApellido [25];
    char _domicilio [25];
    int _telefono;
    bool _estado;

public:
    void setID (int id);
    void setNombre (const char *nombre);
    void setDomicilio (const char *domicilio);
    void setTelefono (int teléfono);
    void setEstado (bool estado);
    int getID ();
    const char *getNombre ();
    const char *getDomicilio ();
    int getTelefono ();
    bool getEstado ();
    void Cargar();
    void Mostrar ();
};






#endif // CLSPERSONA_H_INCLUDED
