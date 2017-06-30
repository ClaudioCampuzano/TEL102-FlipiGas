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
    vector<Pedido> pedidos;
public:
    Camion();
    Camion(string cerro_designado,int capacidad);
    void set_Pedidos(vector<Pedido> pedidos);
    string get_Cerro();
    int get_Capacidad();
    vector <Pedido> get_Pedidos();
};

#endif // CAMION_H
