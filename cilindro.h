#ifndef CILINDRO_H
#define CILINDRO_H
#include <iostream>

using namespace std;

class Cilindro
{

private:
    int cantidad;
    int capacidad;
    string tipo;
public:
    Cilindro();
    Cilindro(int cantidad, int capacidad, string tipo);
    int Precio();
};

#endif // CILINDRO_H
