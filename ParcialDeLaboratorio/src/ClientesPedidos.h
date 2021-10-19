/*
 * ClientesPedidos.h
 *
 *  Created on: 19 oct 2021
 *      Author: Usuario
 */

#ifndef CLIENTESPEDIDOS_H_
#define CLIENTESPEDIDOS_H_
#include "Clientes.h"
#include "Pedidos.h"
/// @fn void InicializarClientesYPedidoVacio(eClientes[], ePedidos[], int, int)
/// @brief Esta funcion se encarga de inicializar los estados de los clientes en vacio, los id de los pedidos, el id del pedido del cliente
/// y los kilos en 0 para;
/// @param clientes Estructura clientes
/// @param pedidos Estructura pedidos
/// @param lenClientes Cantidad maxima clientes
/// @param lenPedidos Cantidad maxima pedidos
void InicializarClientesYPedidoVacio(eClientes clientes[],ePedidos pedidos[],int lenClientes,int lenPedidos);
/// @fn int CrearPedidoDeRecoleccion(eClientes[], ePedidos[], int, int)
/// @brief  Esta funcion imprime la informacion de los clientes con su respectivo id, da a elegir un id y tambien pide
/// una cantidad de kilos a recolectar, define el estado del pedido en PENDIENTE y el estado de la estructura en CARGADO
/// @param clientes Estructura clientes
/// @param pedidos Estructura pedidos
/// @param lenClientes Cantidad maxima clientes
/// @param lenPedidos Cantidad maxima pedidos
/// @return devuelve -1 si la operacion no se pudo completar o 0 si fue realizada con exito
int CrearPedidoDeRecoleccion(eClientes clientes[],Localidad localidad[],ePedidos pedidos[],int lenClientes,int lenPedidos);
/// @fn int ImprimirClientes(eClientes[], ePedidos[], int, int)
/// @brief Esta funcion recorre el array de clientes y de pedidos y cada vez que se encuenta con un estado de cliente
/// cargado, un estado de pedido PENDIENTE y CARGADO se imprime en pantalla el cuit, nombre,direccion,localidad y la cantidad de pedidos pendientes que tiene
/// el cliente
/// @param clientes Estructura clientes
/// @param pedidos Estructura pedidos
/// @param lenClientes Cantidad maxima clientes
/// @param lenPedidos Cantidad maxima pedidos
/// @return devuelve -1 si la operacion no fue realizada con exito o 0 si la operacion fue realizada correctamente
int ImprimirClientes(eClientes clientes[],Localidad localidad[],ePedidos pedidos[],int lenClientes,int lenPedidos);
/// @fn int ImprimirPedidosPendientes(eClientes[], ePedidos[], int, int)
/// @brief Esta funcion imprime todos los pedidos pendientes que tenga cada cliente, imprimiendo su cuit, direccion y los kilos de cada pedido
///
/// @param clientes Estructura clientes
/// @param pedidos Estructura pedidos
/// @param lenClientes Cantidad maxima clientes
/// @param lenPedidos Cantidad maxima pedidos
/// @return devuelve -1 si la operacion no se pudo realizar o 0 si la operacion fue realizada con exito
int ImprimirPedidosPendientes(eClientes clientes[],ePedidos pedidos[],int lenClientes,int lenPedidos);
/// @fn int ProcesarResiduos(eClientes[], ePedidos[], int, int)
/// @brief Esta opcion le pide al usuario que ingrese el id de un cliente y de un pedido PENDIENTE y luego da a elegir los distintos
/// tipos de plasticos para  recolectar, una vez cargados los valores de los plasticos se define el estado del pedido como COMPLETO
/// @param clientes Estructura clientes
/// @param pedidos Estructura pedidos
/// @param lenClientes Cantidad maxima clientes
/// @param lenPedidos Cantidad maxima pedidos
/// @return devuelve -1 si la operacion no se pudo realizar o 0 si la operacion fue realizada con exito
int ProcesarResiduos(eClientes clientes[],ePedidos pedidos[],int lenClientes, int lenPedidos);
/// @fn int ImprimirPedidosProcesados(eClientes[], ePedidos[], int, int)
/// @brief Esta funcion imprime todos los pedidos de cada cliente que este COMPLETADO
///
/// @param clientes Estructura clientes
/// @param pedidos Estructura pedidos
/// @param lenClientes Cantidad maxima clientes
/// @param lenPedidos Cantidad maxima pedidos
/// @return devuelve -1 si la operacion no se pudo realizar o 0 si fue realizada con exito
int ImprimirPedidosProcesados(eClientes clientes[],ePedidos pedidos[],int lenClientes,int lenPedidos);
/// @fn int PromedioDeKilosPP(eClientes[], ePedidos[], int, int, int*)
/// @brief Esta operacion recorre la estructura de clientes y de pedidos en busca de los valores de kilos de PP ingresados por cada cliente
/// una vez obtenido todos los datos se realiza la cantidad total de kilos de PP divido la cantida de clientes que ingresaron tales datos
/// @param clientes Estructura clientes
/// @param pedidos Estructura pedidos
/// @param lenClientes Cantidad maxima clientes
/// @param lenPedidos Cantidad maxima pedidos
/// @param promedio Donde se guarda el resultado de la operacion
/// @return	Devuelve .1 si la operacion no se pudo realizar o 0 si fue realizada con exito
int PromedioDeKilosPP(eClientes clientes[],ePedidos pedidos[],int lenClientes,int lenPedidos,int *promedio);
/// @fn int CantidadPedidosPendientesPorLocalidad(eClientes[], ePedidos[], int, int)
/// @brief Esta operacion imprime todos los pedidos PENDIENTES por cliente y luego pide el ingreso de una localidad para contar
/// la cantidad de pedidos PENDIENTES que tiene dicha localidad, luego imprime la cantidad obtenida
/// @param clientes Estructura clientes
/// @param pedidos Estructura pedidos
/// @param lenClientes Cantidad maxima clientes
/// @param lenPedidos Cantidad maxima pedidos
/// @return devuelve -1 si la operacion no se pudo realizar o 0 si la operacion fue realizada con exito
int CantidadPedidosPendientesPorLocalidad(eClientes clientes[],Localidad localidad[],ePedidos pedidos[],int lenClientes,int lenPedidos);

int ClienteMasPedidosPendientes(eClientes clientes[],Localidad localidad[],ePedidos pedidos[],int lenClientes,int lenPedidos);

int ClienteMasPedidosCompletados(eClientes clientes[],Localidad localidad[],ePedidos pedidos[],int lenClientes,int lenPedidos);

#endif /* CLIENTESPEDIDOS_H_ */
