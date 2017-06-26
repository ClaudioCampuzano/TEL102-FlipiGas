#ifndef PEDIDOS_H
#define PEDIDOS_H
#include <cilindros.h>
#include <deque>

class Pedidos
{
private:
    string nombre_solicitante;
    string  cerro_destino;
    string medio_pago;
    deque<Cilindros> cilindros;
public:
    Pedidos();
    Pedidos(string nombre_solicitante,string cerro_destino,string medio_pago,
            deque<Cilindros> cilindros);
};

#endif // PEDIDOS_H
