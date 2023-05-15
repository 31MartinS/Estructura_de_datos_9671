#ifndef FRACCION_H
#define FRACCION_H

class fraccion {
private:
    int numerador;
    int denominador;

public:
    fraccion(int numerador = 0, int denominador = 1);
    int getNumerador() const;
    int getDenominador() const;
    void simplificar();
    void imprimir() const;
};

#endif //FRACCION_H