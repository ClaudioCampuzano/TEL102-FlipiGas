#ifndef CILINDROS_H
#define CILINDROS_H


class Cilindros
{

private:
    int cantidad_de_cilindros;
    int tamaño_cilindro;
    string tipo;
public:
    Cilindros();
    Cilindros(int cantidad_de_cilindros, int tamaño_cilindro, string tipo);
};

#endif // CILINDROS_H
