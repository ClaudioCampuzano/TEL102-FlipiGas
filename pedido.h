#ifndef PEDIDO_H
#define PEDIDO_H
#include <cilindro.h>

class Pedido
{
private:
    string nombre_solicitante;
    string  cerro_destino;
    string medio_pago;
    deque<Cilindro> cilindros;
    int tiempo_entrega;
    int valor_entrega;
public:
    Pedido();
    Pedido(string nombre_solicitante,string cerro_destino,string medio_pago,
            deque<Cilindro> cilindros,int valor_entrega);
};

#endif // PEDIDOS_H