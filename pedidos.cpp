#include "pedidos.h"

Pedidos::Pedidos()
{

}
Pedidos::Pedidos(string nombre_solicitante, string cerro_destino,
                 string medio_pago, deque<Cilindros> cilindros){
    this->nombre_solicitante=nombre_solicitante;
    this->cerro_destino=cerro_destino;
    this->medio_pago=medio_pago;
    this->cilindros= cilindros;
}
