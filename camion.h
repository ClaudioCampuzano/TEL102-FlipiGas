#ifndef CAMION_H
#define CAMION_H
#include <pedido.h>
#include<iostream>

class Camion
{
private:
    bool enReparto;
    int capacidad;
    int cilindros_restantes;
    string cerro_designado;
    vector<Pedido> pedidos;
public:
    Camion();
    Camion(string cerro_designado,int capacidad);
    void push_Pedido(Pedido pedido);
    string get_Cerro();
    int get_Capacidad();
    vector <Pedido> get_Pedidos();
    bool get_Estado();
    int get_CilindrosRestantes();
    void set_Restar_del_stock(int);
};

#endif // CAMION_H
