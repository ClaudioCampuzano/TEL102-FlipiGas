#ifndef CAMION_H
#define CAMION_H
#include <pedido.h>
#include<iostream>

class Camion
{
private:
    bool enReparto;
    int capacidad;
    string cerro_designado;
    deque<Pedido> pedidos;

public:
    Camion();
    Camion(string cerro_designado,int capacidad);
};

#endif // CAMION_H
