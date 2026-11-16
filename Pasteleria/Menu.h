#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <string>

class Menu
{
public:
    Menu(int cantidadItems);
    void setItem(int indice, std::string texto);
    void dibujarMenu();
    int obtenerRespuesta();
    ~Menu();
private:
    std::string* _vOpciones;
    int _cantItems;
};


#endif // MENU_H_INCLUDED
