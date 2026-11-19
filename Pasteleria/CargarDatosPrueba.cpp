#include <iostream>
#include <cstdio>
#include "CargarDatosPrueba.h"
#include "ArchivoProductos.h"
#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoReabastecimiento.h"
#include "ArchivoCabeceraPedidos.h"
#include "ArchivoDetallePedidos.h"

using namespace std;

// ---------- auxiliares ----------

static bool existeArchivo(const char *nombre){
    FILE *p = fopen(nombre, "rb");
    if (p == nullptr) return false;
    fclose(p);
    return true;
}

static void agregarCliente(int id, const char *nombre, const char *dom, int tel){
    ArchivoClientes arc;
    Clientes c;
    c.setID(id);
    c.setNombre(nombre);
    c.setDomicilio(dom);
    c.setTelefono(tel);
    c.setEstado(true);
    arc.grabarRegistro(c);
}

static void agregarEmpleado(int id, const char *nombre, const char *dom, int tel, const char *oficio){
    ArchivoEmpleados arc;
    Empleados e;
    e.setID(id);
    e.setNombre(nombre);
    e.setDomicilio(dom);
    e.setTelefono(tel);
    e.setOficio(oficio);
    e.setEstado(true);
    arc.grabarRegistro(e);
}

static void agregarReab(int id, int idProd, int cant, int d, int m, int a){
    ArchivoReabastecimiento arc;
    Reabastecimiento r(id, idProd, cant, Fecha(d, m, a), true);
    arc.grabarRegistro(r);
}

// estadoPedido: 1 = PENDIENTE, 2 = ENTREGADO, 3 = CANCELADO
static void agregarCabecera(int idCab, int idPedido, int idEmp, int idCli,
                            int d, int m, int a, const char *pago, int estadoPedido){
    ArchivoCabeceraPedidos arc;
    CabeceraPedido cab;
    cab.setIDCabecera(idCab);
    cab.setIDPedido(idPedido);
    cab.setIDEmpleado(idEmp);
    cab.setIDCliente(idCli);
    cab.setFechaEncargo(Fecha(d, m, a));
    cab.setMetodoPago(pago);
    cab.setEstadoPedido(estadoPedido);
    cab.setEstado(true);
    arc.grabarRegistro(cab);
}

// El precio del detalle se guarda como TOTAL de la linea (cantidad x precio unitario)
static void agregarDetalle(int idDet, int idPedido, int idProd, int cant, float precioUnit){
    ArchivoDetallePedidos arc;
    DetallePedido det;
    det.setIDDetalle(idDet);
    det.setIDPedido(idPedido);
    det.setIDProducto(idProd);
    det.setCantidad(cant);
    det.setPrecio(cant * precioUnit);
    det.setEstado(true);
    arc.grabarRegistro(det);
}

// ---------- funcion principal ----------

void cargarDatosPrueba(){

    const char *archivos[] = {"Productos.dat", "Clientes.dat", "Empleados.dat",
                              "Reabastecimiento.dat", "CabeceraPedidos.dat", "DetallePedidos.dat"};
    for (int i = 0; i < 6; i++){
        if (existeArchivo(archivos[i])){
            cout << "Ya existe " << archivos[i] << ". No se cargan datos de prueba para no duplicar." << endl;
            cout << "Borra los .dat si queres empezar de cero." << endl;
            return;
        }
    }

    // ----- PRODUCTOS (6) -----  stock = stock actual, ya incluye los reabastecimientos
    ArchivoProductos arcProd;
    arcProd.grabarRegistro(Productos(1, "Torta de chocolate", 18000, 8,  true));
    arcProd.grabarRegistro(Productos(2, "Cheesecake",         15000, 6,  true));
    arcProd.grabarRegistro(Productos(3, "Lemon pie",          12000, 5,  true));
    arcProd.grabarRegistro(Productos(4, "Budin de limon",      5000, 20, true));
    arcProd.grabarRegistro(Productos(5, "Cookies x6",        4500, 15, true));
    arcProd.grabarRegistro(Productos(6, "Brownie",             2500, 30, true));

    // ----- CLIENTES (5) -----
    agregarCliente(1, "Lucia Fernandez",  "Av. Libertador 1200",  45671234);
    agregarCliente(2, "Martin Gomez",     "Belgrano 350",         46782345);
    agregarCliente(3, "Sofia Ramirez",    "Mitre 875",            47893456);
    agregarCliente(4, "Carlos Benitez",   "San Martin 42",        48904567);
    agregarCliente(5, "Valeria Acosta",   "Rivadavia 2100",       49015678);

    // ----- EMPLEADOS (4) -----
    agregarEmpleado(1, "Ana Torres",     "Moreno 510",    41112233, "pastelero");
    agregarEmpleado(2, "Diego Paz",      "Sarmiento 980", 42223344, "vendedor");
    agregarEmpleado(3, "Camila Rios",    "Alsina 1450",   43334455, "vendedor");
    agregarEmpleado(4, "Jorge Medina",   "Lavalle 300",   44445566, "mantenimiento");

    // ----- REABASTECIMIENTOS (5) -----
    agregarReab(1, 1, 5,  10,  1, 2025);
    agregarReab(2, 2, 4,  10,  1, 2025);
    agregarReab(3, 4, 10, 15,  6, 2025);
    agregarReab(4, 6, 20, 15,  6, 2025);
    agregarReab(5, 3, 6,   3, 11, 2026);

    // ----- PEDIDOS (15): cabecera + detalle -----
    // Precios unitarios: 1=18000 2=15000 3=12000 4=5000 5=4500 6=2500
    // estadoPedido: 1 = pendiente, 2 = entregado, 3 = cancelado

    // 2023
    agregarCabecera(1, 1, 2, 1, 15,  3, 2023, "Efectivo",      2);
    agregarDetalle (1, 1, 1, 1, 18000);
    agregarDetalle (2, 1, 4, 2, 5000);

    agregarCabecera(2, 2, 3, 2, 22,  7, 2023, "Tarjeta",       2);
    agregarDetalle (3, 2, 2, 1, 15000);

    agregarCabecera(3, 3, 2, 3, 23, 12, 2023, "Efectivo",      2);
    agregarDetalle (4, 3, 1, 2, 18000);
    agregarDetalle (5, 3, 5, 3, 4500);

    // 2024
    agregarCabecera(4, 4, 3, 1, 10,  2, 2024, "Transferencia", 2);
    agregarDetalle (6, 4, 3, 1, 12000);
    agregarDetalle (7, 4, 6, 4, 2500);

    agregarCabecera(5, 5, 2, 4, 18,  5, 2024, "Tarjeta",       2);
    agregarDetalle (8, 5, 4, 3, 5000);

    agregarCabecera(6, 6, 2, 2,  5,  9, 2024, "Efectivo",      2);
    agregarDetalle (9, 6, 2, 2, 15000);
    agregarDetalle (10, 6, 5, 1, 4500);

    agregarCabecera(7, 7, 3, 5, 24, 12, 2024, "Tarjeta",       2);
    agregarDetalle (11, 7, 1, 3, 18000);
    agregarDetalle (12, 7, 3, 2, 12000);
    agregarDetalle (13, 7, 6, 6, 2500);

    // 2025
    agregarCabecera(8, 8, 2, 3, 14,  1, 2025, "Efectivo",      2);
    agregarDetalle (14, 8, 4, 2, 5000);

    agregarCabecera(9, 9, 3, 1,  2,  4, 2025, "Transferencia", 3);   // cancelado
    agregarDetalle (15, 9, 1, 1, 18000);

    agregarCabecera(10, 10, 2, 4, 19, 8, 2025, "Tarjeta",      2);
    agregarDetalle (16, 10, 5, 4, 4500);
    agregarDetalle (17, 10, 6, 2, 2500);

    agregarCabecera(11, 11, 3, 2, 30, 11, 2025, "Efectivo",    2);
    agregarDetalle (18, 11, 2, 1, 15000);
    agregarDetalle (19, 11, 3, 1, 12000);

    // 2026
    agregarCabecera(12, 12, 2, 5,  8,  3, 2026, "Tarjeta",     2);
    agregarDetalle (20, 12, 1, 1, 18000);
    agregarDetalle (21, 12, 4, 1, 5000);

    agregarCabecera(13, 13, 3, 1, 21,  6, 2026, "Efectivo",    2);
    agregarDetalle (22, 13, 6, 5, 2500);

    agregarCabecera(14, 14, 2, 3, 30, 10, 2026, "Transferencia", 1); // pendiente
    agregarDetalle (23, 14, 1, 2, 18000);
    agregarDetalle (24, 14, 5, 2, 4500);

    agregarCabecera(15, 15, 3, 4, 17, 11, 2026, "Tarjeta",     1);   // pendiente
    agregarDetalle (25, 15, 2, 1, 15000);
    agregarDetalle (26, 15, 4, 2, 5000);

    cout << "Datos de prueba cargados: 6 productos, 5 clientes, 4 empleados, "
         << "5 reabastecimientos y 15 pedidos." << endl;
}
