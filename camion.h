#ifndef CAMION_H
#define CAMION_H
#include <pedidos.h>

class Camion
{
private:
    bool enReparto;
    int capacidad;
    string cerro_designado;
    deque<Pedidos> pedidos;

public:
    Camion();
    Camion(string cerro_designado,int capacidad);
};

#endif // CAMION_H
