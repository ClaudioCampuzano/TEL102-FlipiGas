#include "pedido.h"
#include <ctime>

Pedido::Pedido()
{}
Pedido::Pedido(string nombre_solicitante, string cerro_destino,
                 string medio_pago, vector<Cilindro> cilindro, int valor_entrega){
    this->nombre_solicitante=nombre_solicitante;
    this->cerro_destino=cerro_destino;
    this->medio_pago=medio_pago;
    this->cilindros= cilindros;
    this->valor_entrega = valor_entrega;
    this->tiempo_entrega = 15 +rand()%45;
    this->entregado = false;
}
int Pedido::get_TiempoEntrega(){
    return this->tiempo_entrega;
}
int Pedido::get_ValorEntrega(){
    return this->valor_entrega;
}
