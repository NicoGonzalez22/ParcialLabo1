#include "Clientes.h"

int GenerarID(eClientes clientes[],int lenClientes)
{
	int id;
	for(int i=0;i<lenClientes;i++)
	{
		if(clientes[i].estado==VACIO)
		{
			id=i;
			break;
		}
	}
	return id;
}

int IngresarCliente(eClientes clientes[],Localidad localidad[],int id,int lenClientes)
{
	int opcion;
	int contador;
	contador=0;
	int retorno;
	retorno=0;
	if(clientes!=NULL&&id>0)
	{
		for(;id<=lenClientes;id++)
		{
			if(clientes[id].estado==VACIO)
			{
				clientes[id].id=id;
				CargarNombre(clientes[id].nombreEmpresa,"Ingrese el nombre de su empresa: \n","¡Error!Ingrese el nombre de su empresa nuevamente: \n");
				CargarCuit(clientes[id].cuit,"Ingrese su cuit\n","¡Error!Ingrese nuevamente su cuit\n");
				CargarDireccion(clientes[id].direccion,"Ingrese la direccion: \n","¡Error!Ingrese nuevamente la direccion: \n");
				localidad[id].idLocalidad=id;
				do
				{
					printf("1-BUENOS-AIRES\n"
							"2-PROVINCIA-BSAS\n"
							"3-OTRO\n");
					opcion=CargarEntero("Ingrese la opcion deseada","¡Error! Reingrese opcion");
					switch(opcion)
					{
					case 1:
						localidad[id].descripcion=BUENOSAIRES;
						contador++;
						break;
					case 2:
						localidad[id].descripcion=PROVINCIA;
						contador++;
						break;
					case 3:
						localidad[id].descripcion=OTROS;
						contador++;
						break;
					}

				}while(contador==0);
				CargarNombre(localidad[id].localidad,"Ingrese el nombre de su barrio\n","¡Error! Ingrese el nombre de su barrio nuevamente\n");
				clientes[id].estado=CARGADO;
				printf("El id es: %d\n",clientes[id].id);
				break;
			}
		}

		retorno=1;
	}
	return retorno;
}


int ModificarDatosDeCliente(eClientes clientes[],Localidad localidad[],int id,int lenClientes)
{
	int opcion;
	int retorno;
	int contador;
	contador=0;
	retorno=0;

	for(int i=0;i<lenClientes;i++)
	{
		if(i==clientes[i].id&&clientes[i].estado==CARGADO)
		{
			do
			{

				printf("1-Modificar Direccion \n"
						"2-Modificar Localidad \n"
						"3-Salir\n");
				opcion=CargarEnteroConMaxYMin("Ingrese la opcion: ", "¡Error!Ingrese la opcion nuevamente: ",1,3);
				switch(opcion)
				{
					 case 1:
						 CargarDireccion(clientes[id].direccion,"Ingrese la direccion: ","¡Error !Ingrese nuevamente la direccion: ");
					break;
					 case 2:
							do
							{
								printf("1-BUENOS-AIRES"
										"2-PROVINCIA-BSAS"
										"3-OTRO");
								opcion=CargarEntero("Ingrese la opcion deseada","¡Error! Reingrese opcion");
								switch(opcion)
								{
								case 1:
									strcpy(localidad[id].descripcion,"BUENOS-AIRES");
									contador++;
									break;
								case 2:
									strcpy(localidad[id].descripcion,"PROVINCIA-BSAS");
									contador++;
									break;
								case 3:
									strcpy(localidad[id].descripcion,"OTRO");
									contador++;
									break;
								}

							}while(contador>0);
					break;
				}
			}while(opcion>0&&opcion<3);
			retorno=1;
		}

	}
	return retorno;
}

int EliminarCliente(eClientes clientes[],int id,int lenClientes)
{
	int retorno;
	retorno=0;

	for(int i=0;i<lenClientes;i++)
	{
		if(i==clientes[id].id&&clientes[id].estado==CARGADO)
		{
			clientes[id].estado=VACIO;
			retorno=1;
		}
	}
	return retorno;
}
