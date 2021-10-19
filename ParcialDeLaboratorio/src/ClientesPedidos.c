#include "ClientesPedidos.h"
void InicializarClientesYPedidoVacio(eClientes clientes[],ePedidos pedidos[],int lenClientes,int lenPedidos)
{
	for(int i=0;i<lenClientes;i++)
	{
		clientes[i].estado=VACIO;
	}
	for(int j=0;j<lenPedidos;j++)
	{
		pedidos[j].id=0;
		pedidos[j].idPedido[j]=VACIO;
		pedidos[j].kilos[j]=0;
	}
}



int CrearPedidoDeRecoleccion(eClientes clientes[],Localidad localidad[],ePedidos pedidos[],int lenClientes,int lenPedidos)
{
	int idExistente;
	int cantKilos;
	int retorno;
	int idPedido;
	idPedido=1;
	retorno=-1;
	ImprimirCincoDatosSinInt("EMPRESA","CUIT","DIRECCION","LOCALIDAD","ID");
	if(clientes!=NULL&&pedidos!=NULL&&lenClientes>0&&lenPedidos>0)
	{
		for(int i=0;i<lenClientes;i++)
		{
			if(clientes[i].estado==CARGADO)
			{
				ImprimirCincoDatos(clientes[i].nombreEmpresa,clientes[i].cuit,clientes[i].direccion,localidad[i].localidad,clientes[i].id);
			}
		}
		idExistente=CargarEntero("\nIngrese el id del cliente: ","\n¡Error!Ingrese nuevamente el id del cliente: ");
		if(clientes[idExistente].estado==VACIO)
		{
			while(clientes[idExistente].estado==VACIO)
			{
				idExistente=CargarEntero("\nEl id que ingreso no pertenece a ningun cliente, volver a ingresar el id: ","\n¡Error!Ingrese nuevamente el id del cliente: ");
			}
		}
		cantKilos=CargarEntero("\nIngrese la cantidad de kilos totales: ","\n¡Error! Ingrese nuevamente la cantidad de kilos totales: ");

		for(int k=0;k<lenClientes;k++)
		{
			if(k==clientes[idExistente].id&&clientes[idExistente].estado==CARGADO)
			{
				for(;idPedido<lenPedidos;idPedido++)
				{
					if(pedidos[k].idPedido[idPedido]==VACIO)
					{
						pedidos[k].id=idExistente;
						pedidos[k].idPedido[idPedido]=idPedido;
						pedidos[k].kilos[idPedido]=cantKilos;
						pedidos[k].estadoPedido[idPedido]=PENDIENTE;
						pedidos[k].estado[idPedido]=CARGADO;
						printf("\nEl id del pedido es: %d\n",pedidos[k].idPedido[idPedido]);
						break;
						retorno=0;
					}
				}
			}

		}

	}
	return retorno;
}

int ImprimirClientes(eClientes clientes[],Localidad localidad[],ePedidos pedidos[],int lenClientes,int lenPedidos)
{
	int retorno;
	int cantidadPedidosPendientes;
	retorno=-1;
	cantidadPedidosPendientes=0;

	ImprimirCincoDatosSinInt("CUIT","NOMBRE","DIRECCION","LOCALIDAD","CANT PENDIENTE");
	for(int i=0;i<lenClientes;i++)
	{
		if(clientes[i].estado==CARGADO&&clientes[i].id==pedidos[i].id)
		{
			for(int k=0;k<lenPedidos;k++)
			{
				if(pedidos[i].estado[k]==CARGADO&&pedidos[i].estadoPedido[k]==PENDIENTE)
				{
					cantidadPedidosPendientes++;
				}
			}
			ImprimirCincoDatos(clientes[i].cuit,clientes[i].nombreEmpresa,clientes[i].direccion,localidad[i].localidad,cantidadPedidosPendientes);
			retorno=0;
		}
		cantidadPedidosPendientes=0;
	}

	return retorno;
}

int ImprimirPedidosPendientes(eClientes clientes[],ePedidos pedidos[],int lenClientes,int lenPedidos)
{
	int retorno;
	int flag=1;
	retorno=-1;

	for(int i=0;i<lenClientes;i++)
	{
		if(clientes[i].estado==CARGADO)
		{
			for(int j=0;j<lenPedidos;j++)
			{
				if(pedidos[i].estadoPedido[j]==PENDIENTE)
				{
					if(flag==1)
					{
						printf("PEDIDOS PENDIENTES: \n");
						ImprimirTresDatosSinInt("CUIT","DIRECCION","KILOS");
						flag=0;
					}
					ImprimirTresDatos(clientes[i].cuit,clientes[i].direccion,pedidos[i].kilos[j]);
					retorno=0;
				}
			}

		}
	}
	return retorno;
}

int ProcesarResiduos(eClientes clientes[],ePedidos pedidos[],int lenClientes, int lenPedidos)
{
	int retorno;
	int idCliente;
	int idPedido;
	int opcion;
	int auxKilos;
	int flag=1;
	retorno=-1;


	for(int i=0;i<lenClientes;i++)
	{
		for(int j=0;j<lenPedidos;j++)
		{
			if(pedidos[i].estado[j]==CARGADO&&pedidos[i].estadoPedido[j]==PENDIENTE)
			{
				if(flag==1)
				{
					ImprimirCuatroDatos("ID","NOMBRE","KILOS","ID PEDIDO");
					flag=0;
				}
				ImprimirCuatroDatosPrimeroYUltimoInt(pedidos[i].id,clientes[i].nombreEmpresa,pedidos[i].kilos[j],pedidos[i].idPedido[j]);
			}
		}
	}
	idCliente=CargarEntero("\nIngrese el id del cliente: ","\n¡Error!Ingrese nuevamente el id del cliente: ");
	idPedido=CargarEntero("\nIngrese el id del pedido: ","\n¡Error!Ingrese nuevamente el id del pedido: ");
	auxKilos=pedidos[idCliente].kilos[idPedido];
	while(clientes[idCliente].estado!=CARGADO||pedidos[idCliente].estadoPedido[idPedido]!=PENDIENTE)
	{
		if(clientes[idCliente].estado!=CARGADO)
		{
			idCliente=CargarEntero("\nEl id que ingreso no pertenece a un pedido 'Pendiente' ingrese nuevamente:","\n¡Error!Ingrese nuevamente el id del pedido: ");
		}else
		{
			idPedido=CargarEntero("\nIngrese el id del pedido: ","\n¡Error!Ingrese nuevamente el id del pedido: ");
		}
		retorno=0;
	}
	do
	{
		if(auxKilos<0)
		{
			printf("\n¡ERROR! Ingreso mas kilos de los ingresados en su pedido, Debe volver a ingresar los kilos por tipo de plastico: \n");
		}
	printf("Cantidad maxima de kilos a ingresar: %d (Debe ingresar la totalidad para finalizar la opcion)\n"
			"1- HDPE- Polietileno de alta densidad (Envases para lácteos, perfumes, detergentes líquidos, etc.)\n"
			"2- LDPE- Polietileno de baja densidad (Bolsas de congelación de alimentos, tapas flexibles o bolsas de basura.)\n"
			"3- PP-Polipropileno (Plásticos utilizados en la industria automovilística y en la construcción.)\n"
			"4- Salir\n",auxKilos);
	opcion=CargarEnteroConMaxYMin("Ingrese una opcion : ","¡Error!Ingrese nuevamente la opcion: ", 1, 4);
	switch(opcion)
	{
	case 1:
		pedidos[idCliente].kilosHDPE[idPedido]=CargarEntero("Ingrese la cantidad de kilos: ","¡Error!Ingrese nuevamente la cantidad de kilos: ");
		if(pedidos[idCliente].kilosHDPE[idPedido]>auxKilos)
		{
			while(pedidos[idCliente].kilosHDPE[idPedido]>auxKilos)
			{
				pedidos[idCliente].kilosHDPE[idPedido]=CargarEntero("La cantidad de kilos ingresada supera el maximo, reingresar kilos: ","¡Error!Ingrese nuevamente la cantidad de kilos: ");
			}
		}else
		{
			auxKilos=auxKilos-pedidos[idCliente].kilosHDPE[idPedido];
		}
		break;
	case 2:
		pedidos[idCliente].kilosLDPE[idPedido]=CargarEntero("Ingrese la cantidad de kilos: ","¡Error!Ingrese nuevamente la cantidad de kilos: ");
		if(pedidos[idCliente].kilosLDPE[idPedido]>auxKilos)
		{
			while(pedidos[idCliente].kilosLDPE[idPedido]>auxKilos)
			{
				pedidos[idCliente].kilosLDPE[idPedido]=CargarEntero("La cantidad de kilos ingresada supera el maximo, reingresar kilos: ","¡Error!Ingrese nuevamente la cantidad de kilos: ");
			}
		}else
		{
			auxKilos=auxKilos-pedidos[idCliente].kilosLDPE[idPedido];
		}
		break;
	case 3:
		pedidos[idCliente].kilosPP[idPedido]=CargarEntero("Ingrese la cantidad de kilos: ","¡Error!Ingrese nuevamente la cantidad de kilos: ");
		if(pedidos[idCliente].kilosPP[idPedido]>auxKilos)
		{
			while(pedidos[idCliente].kilosPP[idPedido]>auxKilos)
			{
				pedidos[idCliente].kilosPP[idPedido]=CargarEntero("La cantidad de kilos ingresada supera el maximo, reingresar kilos: ","¡Error!Ingrese nuevamente la cantidad de kilos: ");
			}
		}else
		{
			auxKilos=auxKilos-pedidos[idCliente].kilosPP[idPedido];
		}
		break;
	}

	if(auxKilos==0)
	{
		pedidos[idCliente].estadoPedido[idPedido]=COMPLETADO;
		break;
	}
	}while((opcion>0&&opcion<4)&&auxKilos!=0);

	return retorno;
}

int ImprimirPedidosProcesados(eClientes clientes[],ePedidos pedidos[],int lenClientes,int lenPedidos)
{
	int retorno;
	retorno=-1;
	for(int i=0;i<lenClientes;i++)
	{
		if(clientes[i].estado==CARGADO)
		{
			for(int j=0;j<lenPedidos;j++)
			{
				if(pedidos[i].estadoPedido[j]==COMPLETADO)
				{
					printf("\n%s %s %d %d %d\n",clientes[i].cuit,clientes[i].direccion,pedidos[i].kilosHDPE[j],pedidos[i].kilosLDPE[j],pedidos[i].kilosPP[j]);
					retorno=0;
				}
			}

		}
	}
	return retorno;
}

int PromedioDeKilosPP(eClientes clientes[],ePedidos pedidos[],int lenClientes,int lenPedidos,int *promedio)
{
	int totalPP;
	int totalClientes;
	int promedioKilosPP;
	int retorno;
	retorno=-1;
	totalClientes=0;
	totalPP=0;
	if(clientes!=NULL&&pedidos!=NULL&&lenClientes>0&&lenPedidos>0)
	{
		for(int i=0;i<lenClientes;i++)
		{
			for(int j=0;j<lenPedidos;j++)
			{
				if(clientes[i].estado==CARGADO&&pedidos[i].estadoPedido[j]==COMPLETADO&&pedidos[i].kilosPP[j]>0)
				{
					totalPP=totalPP+pedidos[i].kilosPP[j];
					totalClientes++;
					retorno=0;
				}
			}
		}
		promedioKilosPP=totalPP/totalClientes;
		*promedio=promedioKilosPP;
	}
	return retorno;
}

int CantidadPedidosPendientesPorLocalidad(eClientes clientes[],Localidad localidad[],ePedidos pedidos[],int lenClientes,int lenPedidos)
{
	int opcion;
	int contador;
	int retorno;

	//char localidadLocal[TamName];
	int contBs;
	int contProv;
	int contOtros;
	contBs=0;
	contProv=0;
	contOtros=0;
	int cantPendientes;


	//valido=1;
	retorno=-1;
	cantPendientes=0;
	/*ImprimirClientes(clientes,localidad,pedidos,ClientesMax,PedidosMax);
	printf("Por favor ingresar la localidad exactamente como lo dice la tabla\n");
	CargarDireccion(localidadLocal,"Ingrese la localidad :","\n¡Error!Ingrese nuevamente la localidad :");*/


	do
	{
		printf("1-BUENOS-AIRES\n"
				"2-PROVINCIA-BSAS\n"
				"3-OTRO\n");
		opcion=CargarEntero("Ingrese la opcion deseada","¡Error! Reingrese opcion");
		switch(opcion)
		{
		case 1:
			for(int i=0;i<lenClientes;i++)
			{
				for(int j=0;j<lenPedidos;j++)
				{
					if(clientes[i].estado==CARGADO&&pedidos[i].estadoPedido[j]==PENDIENTE&&localidad[i].idLocalidad==clientes[i].id&&localidad[i].descripcion==BUENOSAIRES)
					{
						cantPendientes++;
						contBs++;
					}
				}
			}
			contador++;
			break;
		case 2:
			for(int a=0;a<lenClientes;a++)
			{
				for(int u=0;u<lenPedidos;u++)
				{
					if(clientes[a].estado==CARGADO&&pedidos[a].estadoPedido[u]==PENDIENTE&&localidad[a].idLocalidad==clientes[a].id&&localidad[a].descripcion==PROVINCIA)
					{
						cantPendientes++;
						contProv++;
					}
				}
			}
			contador++;
			break;
		case 3:
			for(int q=0;q<lenClientes;q++)
			{
				for(int w=0;w<lenPedidos;w++)
				{
					if(clientes[q].estado==CARGADO&&pedidos[q].estadoPedido[w]==PENDIENTE&&localidad[q].idLocalidad==clientes[q].id&&localidad[q].descripcion==PROVINCIA)
					{

								cantPendientes++;
								contOtros++;
					}
				}
			}
			contador++;
			break;
		}

	}while(contador==0);

/*	for(int i=0;i<lenClientes;i++)
	{
		for(int z=0;z<lenPedidos;z++)
		{

				if(clientes[i].estado==CARGADO&&(strcmp(clientes[i].localidad,localidadLocal)==0)&&pedidos[i].estadoPedido[z]==PENDIENTE)
				{
					strcpy(auxLocalidad,clientes[i].localidad);

					while(auxLocalidad[k]!='\0'&&localidadLocal[k]!='\0'&&valido==1)
					{
						if(auxLocalidad[k]==localidadLocal[k])
						{
							valido=1;
						}else
						{
							valido=0;
						}
						k++;
					}
					if(valido==1)
					{
						cantPendientes++;
					}
				}
		}

	}*/
	if(contBs>0)
	{
	printf("\nLa cantidad de productos PENDIENTES en la localidad BUENOS AIRES es : %d\n",cantPendientes);
	}else
	{
		if(contProv>0)
		{
			printf("\nLa cantidad de productos PENDIENTES en la localidad PROVINCIA DE BUENOS-AIRES es : %d\n",cantPendientes);
		}else
		{
			if(contOtros>0)
			{
				printf("\nLa cantidad de productos PENDIENTES en la localidad PROVINCIA DE OTROS es : %d\n",cantPendientes);
			}
		}
	}

	return retorno;
}

int ClienteMasPedidosPendientes(eClientes clientes[],Localidad localidad[],ePedidos pedidos[],int lenClientes,int lenPedidos)
{
	int retorno=-1;
	int contUno;
	int contDos;
	int idMax;
	int flag=1;
	contUno=0;
	contDos=0;
	for(int i=0;i<lenClientes;i++)
	{
		if(clientes[i].estado==CARGADO&&clientes[i].id==pedidos[i].id)
		{
			for(int k=0;k<lenPedidos;k++)
			{
				if(pedidos[i].estado[k]==CARGADO&&pedidos[i].estadoPedido[k]==PENDIENTE)
				{
					contUno++;
				}
			}

		}
		for(int q=i+1;q<lenClientes;q++)
		{
			for(int g=0;g<lenPedidos;g++)
			{
				if(pedidos[q].estado[q]==CARGADO&&pedidos[i].estadoPedido[q]==PENDIENTE)
				{
					contDos++;
				}
			}

			if(contUno>contDos)
			{
				idMax=i;
				retorno=0;

			}else
			{
				idMax=q;
				retorno=0;
			}
		}

	}
	return retorno;
}


int ClienteMasPedidosCompletados(eClientes clientes[],Localidad localidad[],ePedidos pedidos[],int lenClientes,int lenPedidos)
{
	int retorno=-1;
	int contUno;
	int contDos;
	int idMax;
	contUno=0;
	contDos=0;
	for(int i=0;i<lenClientes;i++)
	{
		if(clientes[i].estado==CARGADO&&clientes[i].id==pedidos[i].id)
		{
			for(int k=0;k<lenPedidos;k++)
			{
				if(pedidos[i].estado[k]==CARGADO&&pedidos[i].estadoPedido[k]==COMPLETADO)
				{
					contUno++;
				}
			}

		}
		for(int q=i+1;q<lenClientes;q++)
		{
			for(int g=0;g<lenPedidos;g++)
			{
				if(pedidos[q].estado[q]==CARGADO&&pedidos[i].estadoPedido[q]==COMPLETADO)
				{
					contDos++;
				}
			}

			if(contUno>contDos)
			{
				idMax=i;
				retorno=0;
			}else
			{
				idMax=q;
				retorno=0;
			}
		}

	}
	return retorno;


}
