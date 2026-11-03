#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

/**
REEMPLAZAR "clase" CON LA CLASE QUE CORRESPONDA A LA INFORMACION QUE SE QUIERE GUARDAR EN EL ARCHIVO
*/

class Archivo{
private:
    char _nombre[30];

public:
    Archivo(const char *n="Archivo.dat");
    clase leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(clase obj);
    int buscarRegistro(int leg);
    bool modificarRegistro(clase obj, int pos);
    void listarReg();
    void bajaRegistro();
};

#endif // ARCHIVO_H_INCLUDED
