#include "cilindro.h"

Cilindro::Cilindro()
{
}
Cilindro::Cilindro(int cantidad, int capacidad, string tipo){
    this->cantidad=cantidad;
    this->capacidad=capacidad;
    this->tipo=tipo;
}
int Cilindro::Precio(){

    if (this->tipo == "Catalitico"){
       if (this->capacidad == 5)
           return cantidad *7130;
       else if (this->capacidad == 11)
           return cantidad *11600;
       else if (this->capacidad == 15)
           return cantidad *15000;
       else if (this->capacidad == 45)
           return cantidad *43800;
    }else{
        if (this->capacidad == 5)
            return cantidad *6500;
        else if (this->capacidad == 11)
            return cantidad *10250;
        else if (this->capacidad == 15)
            return cantidad *12000;
        else if (this->capacidad == 45)
            return cantidad *40800;
    }
    return 0;
}
int Cilindro::get_Cantidad(){
    return this->cantidad;
}

int Cilindro::get_Capacidad(){
    return this->capacidad;
}

string Cilindro::get_Tipo(){
    return this->tipo;
}
