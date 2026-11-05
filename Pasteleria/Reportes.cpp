#include <iostream>
#include "Reportes.h"
#include "ArchivoProductos.h"
#include "ArchivoCabeceraPedidos.h"
#include "ArchivoDetallePedidos.h"

using namespace std;

void Reportes::clienteConMasCompras()
{

}

void Reportes::facturacionTotal()
{

}
void Reportes::ventasPorVendedor()
{

}
void Reportes::metodoPagoMasUtilizado()
{

}

void Reportes::promedioUnidadesPorPedido()
{
    ArchivoDetallePedidos archDetalle;
    int cantDetalles = archDetalle.contarRegistro();
    int totalUnidades = 0;

    for (int i = 0; i < cantDetalles ; i++ )
    {
        DetallePedido det = archDetalle.leerRegistro(i);
        if(det.getEstado() == true)
        {
            totalUnidades += det.getCantidad();
        }
    }

    ArchivoCabeceraPedidos archCabecera;
    int cantCabeceras = archCabecera.contarRegistro();
    int cantPedidos = 0;

    for (int j = 0; j < cantCabeceras ; j++ )
    {
        CabeceraPedido cab = archCabecera.leerRegistro(j);
        if(cab.getEstado() == true)
        {
            cantPedidos++;
        }
    }

    if (cantPedidos == 0)
    {
        cout << "No hay pedidos registrados." << endl;
        return;
    }

    float promedio = (float)totalUnidades / cantPedidos;
    cout << "Promedio de unidades por pedido: " << promedio << endl;
}

void Reportes::productoMasVendido()
{

}

void Reportes::recaudacionAnual()
{

}

void Reportes::porcentajeEntregadosPendientes()
{

}
