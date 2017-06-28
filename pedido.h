#ifndef PEDIDO_H
#define PEDIDO_H
#include <cilindro.h>
#include <vector>

class Pedido
{
private:
    string nombre_solicitante;
    string  cerro_destino;
    string medio_pago;
    int tiempo_entrega;
    int valor_entrega;
    vector<Cilindro> cilindros;
    bool entregado;
public:
    Pedido();
    Pedido(string nombre_solicitante,string cerro_destino,string medio_pago,
            vector<Cilindro> cilindros,int valor_entrega);
    int get_TiempoEntrega();
    int get_ValorEntrega();
};

#endif // PEDIDOS_H
