#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#define PedidosMax 101
#define PENDIENTE 1
#define COMPLETADO 2
typedef struct
{
	int id;
	int idPedido[PedidosMax];
	int kilos[PedidosMax];
	int estadoPedido[PedidosMax];
	int estado[PedidosMax];
	int kilosHDPE[PedidosMax];
	int kilosLDPE[PedidosMax];
	int kilosPP[PedidosMax];
}ePedidos;

#endif /* PEDIDOS_H_ */
