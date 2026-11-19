#include <iostream>
#include "MenuReportes.h"
#include "Reportes.h"

using namespace std;

MenuReportes::MenuReportes()
: Menu(8)
{
    setItem(1, "Cliente con mas compras");
    setItem(2, "Facturacion total");
    setItem(3, "Ventas por vendedor");
    setItem(4, "Metodo de pago mas utilizado");
    setItem(5, "Promedio de unidades por pedido");
    setItem(6, "Producto mas vendido");
    setItem(7, "Recaudacion anual");
    setItem(8, "Porcentaje de pedidos entregados y pendientes");
}

void MenuReportes::run()
{
    int opcion;

    do
    {
        dibujarMenu();
        opcion = obtenerRespuesta();

        switch(opcion)
        {
        case 1:
            {
                clienteConMasCompras();
                break;
            }
        case 2:
            {
                facturacionTotal();
                break;
            }
        case 3:
            {
                ventasPorVendedor();
                break;
            }
        case 4:
            {
                metodoPagoMasUtilizado();
                break;
            }
        case 5:
            {
                promedioUnidadesPorPedido();
                break;
            }
        case 6:
            {
                productoMasVendido();
                break;
            }
        case 7:
            {
                recaudacionAnual();
                break;
            }
        case 8:
            {
                porcentajeEntregadosPendientes();
                break;
            }
        }
        if (opcion != 0)
        {
            pausar();
        }
    }while(opcion !=0);
}
