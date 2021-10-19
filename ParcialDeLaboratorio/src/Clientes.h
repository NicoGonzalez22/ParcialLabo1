/*
 * Clientes.h
 *
 *  Created on: 19 oct 2021
 *      Author: Usuario
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_
#include "Localidad.h"
#define ClientesMax 50
#define CARGADO 1
#define VACIO 0
typedef struct
{
	int id;
	char nombreEmpresa[TamName];
	char cuit[TamCuit];
	char direccion[TamName];
	char localidad[TamName];
	int estado;
}eClientes;

/// @fn int IngresarCliente(eClientes[], int, int)
/// @brief Recibe como parametro el id generado con la funcion GENERAR ID y pide al usuario
/// nombre,cuit,direccion y localidad para almacenarla en la direccion de memoria indicada por el id
///
/// @param clientes Estructura clientes
/// @param id	Id generado por la funcion id
/// @param lenClientes Cantidad maxima de clientes
/// @return devuelve 0 si no se puedo realizar la operacion o 1 si fue realizara con exito
int IngresarCliente(eClientes clientes[],Localidad localidad[],int id,int lenClientes);
/// @fn int GenerarID(eClientes[], int)
/// @brief esta funcion realiza un recorrido por la estructura Clientes, su trabajo es indicar la primera posicion de memoria libre para ocupar
///
/// @param clientes Estructura de clientes
/// @param lenClientes Cantidad maxima de clientes
/// @return devuelve el id generado
int GenerarID(eClientes clientes[],int lenClientes);
/// @fn int ModificarDatosDeCliente(eClientes[], int, int)
/// @brief Esta funcion pide al usuario ingresar el id del cliente a modificar
/// busca el valor del id en el array de estrucura cliente y cuando lo encuentra
/// dale distintos tipos de opciones a elegir para modificar al usuario
/// @param clientes Estructura clientes
/// @param id	Id ingresado
/// @param lenClientes Cantidad maxima de clientes
/// @return devuelve 0 si no se pudo realizar la operacion o 1 si se realizo con exito
int ModificarDatosDeCliente(eClientes clientes[],Localidad localidad[],int id,int lenClientes);
/// @fn int EliminarCliente(eClientes[], int, int)
/// @brief Esta funcion recibe como parametro el id del usuario a eliminar
/// busca el id en el array de estrucura de clientes y define el estado del cliente en vacio.
/// @param clientes Estructura clientes
/// @param id	Id ingresado
/// @param lenClientes Cantidad maxima de clientes
/// @return devuelve 0 si no se pudo realizar la operacion o 1 si se realizo con exito
int EliminarCliente(eClientes clientes[],int id,int lenClientes);


#endif /* CLIENTES_H_ */
