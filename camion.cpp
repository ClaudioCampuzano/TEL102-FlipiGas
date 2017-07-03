#include "camion.h"

Camion::Camion()
{

}
Camion::Camion(string cerro_designado, int capacidad){
    this->capacidad=capacidad;
    this->cerro_designado=cerro_designado;
    this->enReparto=false;
}
void Camion::push_Pedido(Pedido pedidos){
    this->pedidos.push_back(pedidos);
}
string Camion::get_Cerro(){
    return this->cerro_designado;
}
int Camion::get_Capacidad(){
    return this->capacidad;
}
vector <Pedido> Camion::get_Pedidos(){
    return this->pedidos;
}
