#include <iostream>
#include <cstring>
#include "Reportes.h"
#include "ArchivoProductos.h"
#include "ArchivoCabeceraPedidos.h"
#include "ArchivoDetallePedidos.h"
#include "ArchivoEmpleados.h"

using namespace std;

void clienteConMasCompras()
{

}

void facturacionTotal()
{
    ArchivoDetallePedidos arc;
    DetallePedido obj;
    float preciosave=0.0;
    int cantReg = arc.contarRegistro();
    for (int i=0;i<cantReg;i++){
        obj=arc.leerRegistro(i);
        if (obj.getEstado()==0){
            preciosave+=obj.getPrecio();
        }

    }
    cout<<"HAY UN TOTAL DE "<<preciosave<<" EN VENTAS REALIZADAS"<<endl;
}

void ventasPorVendedor()
{
    ArchivoEmpleados arc;
    ArchivoCabeceraPedidos arc2;
    Empleados obj;
    CabeceraPedido obj2;
    int *vec=nullptr, *vec2=nullptr, i, j;
    int cantReg = arc.contarRegistro();
    int cantReg2 = arc2.contarRegistro();
    vec = new int[cantReg]{};
    vec2 = new int[cantReg]{};
    for (i=0;i<cantReg;i++){
        obj=arc.leerRegistro(i);
        if (strcmp(obj.getOficio(),"vendedor")==0){
            vec[i]=obj.getID();
        }
    }

    for (j=0;j<cantReg2;j++){
        obj2=arc2.leerRegistro(i);
        for (i=0;i<cantReg;i++){
            if (vec[i]==obj2.getIDEmpleado()){
                vec2[i]++;
            }
        }
    }

    for (i=0;i<cantReg;i++){
        if (vec[i]!=0){
            cout<<"EL VENDEDOR DE ID "<<vec[i]<<" VENDIO UN TOTAL DE "<<vec[i]<<" PEDIDOS"<<endl;
        }
    }
}

void metodoPagoMasUtilizado()
{

}

void promedioUnidadesPorPedido()
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

void productoMasVendido()
{

}

void recaudacionAnual()
{

}

void porcentajeEntregadosPendientes()
{

}
