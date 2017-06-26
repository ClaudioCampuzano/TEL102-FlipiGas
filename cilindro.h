#ifndef CILINDRO_H
#define CILINDRO_H
#include <iostream>
#include <deque>

using namespace std;

class Cilindro
{

private:
    int cantidad_de_cilindros;
    int capacidad;
    string tipo;
public:
    Cilindro();
    Cilindro(int cantidad_de_cilindros, int capacidad, string tipo);
};

#endif // CILINDRO_H
