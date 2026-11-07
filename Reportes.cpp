#include <iostream>
#include <cstring>
#include "Reportes.h"
#include "ArchivoProductos.h"
#include "ArchivoCabeceraPedidos.h"
#include "ArchivoDetallePedidos.h"
#include "ArchivoEmpleados.h"
#include "ArchivoClientes.h"

using namespace std;

///reporte 1 mati

void clienteConMasCompras(){

    ArchivoClientes arcClientes;
    ArchivoCabeceraPedidos arcCabecera;
    Clientes cli;
    CabeceraPedido cab;
    int *vCompras;
    int i, pos, posMax = -1;
    int cantClientes = arcClientes.contarRegistro();
    int cantCabeceras = arcCabecera.contarRegistro();

    if(cantClientes <= 0){
        return;
    }
    vCompras = new int[cantClientes];

    for(i=0; i<cantClientes; i++){
        vCompras[i] = 0;
    }
    for(i=0; i<cantCabeceras; i++){
        cab = arcCabecera.leerRegistro(i);
        if(cab.getEstado() == true){
            pos = arcClientes.buscarRegistro(cab.getIDCliente());
            if(pos != -1){
                vCompras[pos]++;
            }
        }
    }
    for(i=0; i<cantClientes; i++){
        cli = arcClientes.leerRegistro(i);
            if(cli.getEstado() == true && vCompras[i] > 0 && (posMax == -1 || vCompras[i] > vCompras[posMax])){
            posMax = i;
        }
    }
    if(posMax != -1){
        cli = arcClientes.leerRegistro(posMax);
        cout<<"Cliente con mas compras: "<<cli.getNombre()<<endl;
    }
    delete []vCompras;
}

///reporte 2 mati

void metodoPagoMasUtilizado(){

    ArchivoCabeceraPedidos arcCabecera;
    CabeceraPedido cab, aux;
    char metodoMax[20];
    int i, j, cont, contMax = 0;
    int cantCabeceras = arcCabecera.contarRegistro();

    for(i=0; i<cantCabeceras; i++){
        cab = arcCabecera.leerRegistro(i);
            if(cab.getEstado() == true){
                cont = 0;
    for(j=0; j<cantCabeceras; j++){
        aux = arcCabecera.leerRegistro(j);
            if(aux.getEstado() == true && strcmp(aux.getMetodoPago(), cab.getMetodoPago()) == 0){
                cont++;
            }
        }
    if(cont > contMax){
        contMax = cont;
        strcpy(metodoMax, cab.getMetodoPago());
        }
    }
}

    if(contMax > 0){
        cout<<"Metodo de pago mas utilizado: "<<metodoMax<<endl;
    }

}

///######################

void facturacionTotal()
{
    ArchivoDetallePedidos arc;
    DetallePedido obj;
    float preciosave=0.0;
    int cantReg = arc.contarRegistro();
    for (int i=0; i<cantReg; i++)
    {
        obj=arc.leerRegistro(i);
        if (obj.getEstado()==0)
        {
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
    vec = new int[cantReg] {};
    vec2 = new int[cantReg] {};
    for (i=0; i<cantReg; i++)
    {
        obj=arc.leerRegistro(i);
        if (strcmp(obj.getOficio(),"vendedor")==0)
        {
            vec[i]=obj.getID();
        }
    }

    for (j=0; j<cantReg2; j++)
    {
        obj2=arc2.leerRegistro(i);
        for (i=0; i<cantReg; i++)
        {
            if (vec[i]==obj2.getIDEmpleado())
            {
                vec2[i]++;
            }
        }
    }

    for (i=0; i<cantReg; i++)
    {
        if (vec[i]!=0)
        {
            cout<<"EL VENDEDOR DE ID "<<vec[i]<<" VENDIO UN TOTAL DE "<<vec[i]<<" PEDIDOS"<<endl;
        }
    }
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
    ArchivoCabeceraPedidos archCabecera;
    int cantCabeceras = archCabecera.contarRegistro();

    int totalPedidos = 0;
    int entregados = 0;
    int pendientes = 0;

    for (int i = 0; i < cantCabeceras ; i++ )
    {
        CabeceraPedido cab = archCabecera.leerRegistro(i);

        if(cab.getEstado() == true)
        {
            totalPedidos++;
            if(cab.getEstadoPedido() == ENTREGADO)
            {
                entregados++;

            }
            else if (cab.getEstadoPedido() == PENDIENTE)
            {
                pendientes++;
            }
        }

    }
    if(totalPedidos == 0)
    {
        cout <<" No hay pedidos registrados. " << endl;
        return;
    }

    float porcEntregados = (float)entregados * 100 / totalPedidos;
    float porcPendientes = (float)pendientes * 100 / totalPedidos;

    cout << " Total de pedidos : " << totalPedidos << endl;
    cout << " Entregados : " << entregados << " - " <<porcEntregados <<"%"<<endl;
    cout << " Pendientes : " << pendientes << " - " <<porcPendientes <<"%"<<endl;

}
