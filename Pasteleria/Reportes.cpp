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

void clienteConMasCompras()
{

    ArchivoClientes arcClientes;
    ArchivoCabeceraPedidos arcCabecera;
    Clientes cli;
    CabeceraPedido cab;
    int *vCompras;
    int i, pos, posMax = -1;
    int cantClientes = arcClientes.contarRegistro();
    int cantCabeceras = arcCabecera.contarRegistro();

    if(cantClientes <= 0)
    {
        cout << "No hay clientes registrados." << endl;
        return;
    }
    vCompras = new int[cantClientes];

    for(i=0; i<cantClientes; i++)
    {
        vCompras[i] = 0;
    }
    for(i=0; i<cantCabeceras; i++)
    {
        cab = arcCabecera.leerRegistro(i);
        if(cab.getEstado() == true)
        {
            pos = arcClientes.buscarRegistro(cab.getIDCliente());
            if(pos != -1)
            {
                vCompras[pos]++;
            }
        }
    }
    for(i=0; i<cantClientes; i++)
    {
        cli = arcClientes.leerRegistro(i);
        if(cli.getEstado() == true && vCompras[i] > 0 && (posMax == -1 || vCompras[i] > vCompras[posMax]))
        {
            posMax = i;
        }
    }
    if(posMax != -1)
    {
        cli = arcClientes.leerRegistro(posMax);
        cout<<"Cliente con mas compras: "<<cli.getNombre()<<endl;
    }
    else
    {
        cout << "Ningun cliente realizo compras." << endl;
    }
    delete []vCompras;
}

///reporte 2 mati

void metodoPagoMasUtilizado()
{

    ArchivoCabeceraPedidos arcCabecera;
    CabeceraPedido cab, aux;
    char metodoMax[20];
    int i, j, cont, contMax = 0;
    int cantCabeceras = arcCabecera.contarRegistro();

    for(i=0; i<cantCabeceras; i++)
    {
        cab = arcCabecera.leerRegistro(i);
        if(cab.getEstado() == true)
        {
            cont = 0;
            for(j=0; j<cantCabeceras; j++)
            {
                aux = arcCabecera.leerRegistro(j);
                if(aux.getEstado() == true && strcmp(aux.getMetodoPago(), cab.getMetodoPago()) == 0)
                {
                    cont++;
                }
            }
            if(cont > contMax)
            {
                contMax = cont;
                strcpy(metodoMax, cab.getMetodoPago());
            }
        }
    }

    if(contMax > 0)
    {
        cout<<"Metodo de pago mas utilizado: "<<metodoMax<<endl;
        cout<<"Cantidad de pedidos: "<<contMax<<endl;
    }
    else
    {
        cout << "No hay pedidos registrados." << endl;
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
        if (obj.getEstado())
        {
            preciosave += obj.getCantidad() * obj.getPrecio();
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

    if (cantReg == 0)
    {
        cout << "No hay empleados registrados." << endl;
        return;
    }

    vec = new int[cantReg] {};
    vec2 = new int[cantReg] {};

    for (i=0; i<cantReg; i++)
    {
        obj=arc.leerRegistro(i);
        if (obj.getEstado() && strcmp(obj.getOficio(),"vendedor")==0)
        {
            vec[i]=obj.getID();
        }
    }

    for (j=0; j<cantReg2; j++)
    {
        obj2=arc2.leerRegistro(j);
        if (obj2.getEstado())
        {
            for (i=0; i<cantReg; i++)
            {
                if (vec[i]!=0 && vec[i]==obj2.getIDEmpleado())
                {
                    vec2[i]++;
                }
            }
        }
    }

    bool hayVendedores = false;
    for (i=0; i<cantReg; i++)
    {
        if (vec[i]!=0)
        {
            cout<<"EL VENDEDOR DE ID "<<vec[i]<<" VENDIO UN TOTAL DE "<<vec2[i]<<" PEDIDOS"<<endl;
            hayVendedores = true;
        }
    }

    if (!hayVendedores)
    {
        cout << "No hay vendedores registrados." << endl;
    }

    delete []vec;
    delete []vec2;
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
    ArchivoProductos archivoProd("Productos.dat");
    int cantProd = archivoProd.contarRegistro();

    ArchivoDetallePedidos archivoDet("DetallePedidos.dat");
    int cantDet = archivoDet.contarRegistro();

    if (cantProd==0 || cantDet==0)
    {
        cout << "No hay productos o pedidos registrados. "<< endl;
        return;
    }

    int *Ids = new int[cantProd];
    int *Vendidos = new int [cantProd]();

    for (int i =0; i<cantProd; i++)
    {
        Productos prod = archivoProd.leerRegistro(i);
        Ids[i]=prod.getIdProducto();
    }

    for (int j=0; j<cantDet; j++)
    {
        DetallePedido det = archivoDet.leerRegistro(j);

        for (int i = 0; i< cantProd; i++)
        {
            if (Ids [i] == det.getIDProducto())
            {
                Vendidos [i] += det.getCantidad();
                break;
            }
        }
    }

    int posMax=0;
    for (int i=1; i< cantProd; i++)
    {
        if (Vendidos[i]>Vendidos[posMax])
            posMax=i;
    }
    if (Vendidos[posMax]==0)
    {
        cout << "No se vendio ningun producto. "<< endl;
    }
    else
    {
        Productos prod= archivoProd.leerRegistro(posMax);
        cout << "Producto mas vendido: " << prod.getNombre() << endl;
        cout << "ID: "<< prod.getIdProducto()<< endl;
        cout << "Unidades vendidad: " << Vendidos[posMax] << endl;
    }
    delete [] Ids;
    delete [] Vendidos;
}

void recaudacionAnual()
{
    const int primerAnio=2005;
    const int AnioActual = 2026;
    const int CantAnios = AnioActual-primerAnio+1;
    float recaudacion[CantAnios] = {0};

    ArchivoCabeceraPedidos archivoCab("CabeceraPedidos.dat");
    int cantidadRegistrosCab = archivoCab.contarRegistro();
    ArchivoDetallePedidos archivoDet("DetallePedidos.dat");
    int cantidadRegistrosDet = archivoDet.contarRegistro();

    if (cantidadRegistrosCab==0 || cantidadRegistrosDet==0)
    {
        cout << "No hay pedidos registrados. " << endl;
        return;
    }

    for (int i =0; i<cantidadRegistrosCab; i++)
    {
        CabeceraPedido cab = archivoCab.leerRegistro(i);
        int pos = cab.getFechaEncargo().getAnio() - primerAnio;

        if (pos<0 || pos>=CantAnios)
        {
            continue;
        }
        for (int j =0; j<cantidadRegistrosDet; j++)
        {
            DetallePedido det = archivoDet.leerRegistro(j);

            if (det.getIDPedido() == cab.getIDPedido())
            {
                recaudacion[pos] += det.getCantidad() * det.getPrecio();
            }
        }
    }

    int anio;
    cout << "Indique año a consultar: " << endl;
    cin >> anio;

    int pos = anio - primerAnio;
    if (pos < 0 || pos >= CantAnios)
    {
        cout << "El anio debe estar entre " << primerAnio << " y " << AnioActual << endl;
        return;
    }

    if (recaudacion[pos] == 0)
    {
        cout << "No hay registros del anio: " << anio << endl;
    }
    else
    {
        cout << "Recaudacion del anio " << anio << ": $" << recaudacion[pos] << endl;


    }
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
