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
    if (this->tipo == "Catalico"){
       if (this->capacidad == 5)
           return 10000;
       else if (this->capacidad == 11)
           return 20000;
       else if (this->capacidad == 15)
           return 25000;
       else
           return 40000;
    }else{
        if (this->capacidad == 5)
            return 8000;
        else if (this->capacidad == 11)
            return 18000;
        else if (this->capacidad == 15)
            return 23000;
        else
            return 35000;
    }
}
