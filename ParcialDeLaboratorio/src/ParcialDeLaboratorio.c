#include <stdio.h>
#include <stdlib.h>
#include "ClientesPedidos.h"
int main(void) {
	setbuf(stdout, NULL);
	int id;
	int idAModificar;
	int idAEliminar;
	int promedioPP;
	int contAlta;
	int contPedidoRecoleccion;
	int contResiduos;
	contAlta=0;
	contPedidoRecoleccion=0;
	contResiduos=0;
	id=1;

	eClientes clientes[ClientesMax];
	ePedidos pedidos[PedidosMax];
	Localidad localidad[ClientesMax];
	InicializarClientesYPedidoVacio(clientes,pedidos, ClientesMax,PedidosMax);
	int opcion;
	do{
			printf("-------------------------------------------------------------------\n"
					"1-Alta a un cliente                                                |\n"
					"2-Modificar datos de cliente                                       |\n"
					"3-Baja de cliente                                                  |\n"
					"4-Crear pedido de reocleccion                                      |\n"
					"5-Procesar residuos                                                |\n"
					"6-Imprimir clientes                                                |\n"
					"7-Imprimir pedidos pendientes                                      |\n"
					"8-Imprimir Pedidos procesados                                      |\n"
					"9-Imprimir cantidad de pedidos PENDIENTES por localidad ingresada  |\n"
					"10-Imprimir promedio de kilos de polipropileno por cliente         |\n"
					"11-Salir                                                           |\n"
					"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
			opcion=CargarEnteroConMaxYMin("Ingresar opcion: ", "¡Error!Ingresar opcion: ",1,11);
			switch(opcion)
			{
			case 1:
				contAlta++;
				IngresarCliente(clientes,localidad,id,ClientesMax);
				break;
			case 2:
				if(contAlta>0)
				{
				idAModificar=CargarEntero("Ingrese el id del empleado que desea modificar: ","¡Error!Ingrese nuevamente el id del empleado que desea modificar: ");
				ModificarDatosDeCliente(clientes,localidad, idAModificar, ClientesMax);
				}else
				{
					printf("Primero debe ingresar un cliente\n");
				}

				break;
			case 3:
				if(contAlta>0)
				{
					idAEliminar=CargarEntero("Ingrese el id del empleado que desea eliminar: ", "¡Error!Ingrese nuevamente el id del empleado que desea eliminar: ");
					EliminarCliente(clientes, idAEliminar, ClientesMax);
					contAlta--;
				}else
				{
					printf("Primero debe ingresar un cliente\n");
				}

				break;
			case 4:
				if(contAlta>0)
				{
					CrearPedidoDeRecoleccion(clientes,localidad, pedidos, ClientesMax,PedidosMax);
					contPedidoRecoleccion++;
				}else
				{
					printf("Primero debe ingresar un cliente\n");
				}

				break;
			case 5:
				if(contAlta>0&&contPedidoRecoleccion>0)
				{
					ProcesarResiduos(clientes, pedidos, ClientesMax,PedidosMax);
					contPedidoRecoleccion--;
					contResiduos++;
				}else
				{
					printf("Primero debe ingresar un cliente o debe tener almenos un pedido de recoleccion\n");
				}

				break;
			case 6:
				if(contAlta>0&&contPedidoRecoleccion>0)
				{
					ImprimirClientes(clientes,localidad, pedidos, ClientesMax,PedidosMax);
				}else
				{
					printf("Primero debe ingresar un cliente o debe tener almenos un pedido de recoleccion\n");
				}

				break;
			case 7:
				if((ImprimirPedidosPendientes(clientes, pedidos, ClientesMax,PedidosMax))==-1)
				{
					printf("No hay pedidos pendientes\n");
				}
				break;
			case 8:
				if(contAlta>0&&contResiduos>0)
				{
					ImprimirPedidosProcesados(clientes, pedidos, ClientesMax,PedidosMax);
				}else
				{
					printf("Primero debe ingresar un cliente, o debe haber almenos un pedido de procesado realizado\n");
				}

				break;
			case 9:
				if(contAlta>0&&contPedidoRecoleccion>0)
				{
					CantidadPedidosPendientesPorLocalidad(clientes,localidad, pedidos, ClientesMax,PedidosMax);
				}else
				{
					printf("Primero debe ingresar un cliente, o debe haber almenos un pedido de recoleccion activo\n");
				}

				break;
			case 10:
				if(contAlta>0&&contResiduos>0)
				{
					if((PromedioDeKilosPP(clientes, pedidos, ClientesMax,PedidosMax,&promedioPP))==-1)
					{
						printf("No se ha ingresado Polipropileno");
					}else
					{
						printf("El promedio de Polipropileno es: %d\n",promedioPP);
					}
				}else
				{
					printf("Primero debe ingresar un cliente, o debe realizar almenos un pedido de procesado\n");
				}


				break;
			}
	}while(opcion>0&&opcion<11);
	return EXIT_SUCCESS;
}

