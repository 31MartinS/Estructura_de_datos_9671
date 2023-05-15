#include <iostream>
#include "fraccion.h"

fraccion::fraccion(int numerador, int denominador) {
    this->numerador = numerador;
    this->denominador = denominador;
    simplificar();
}

int fraccion::getNumerador() const {
    return numerador;
}

int fraccion::getDenominador() const {
    return denominador;
}

void fraccion::simplificar() {
    int i = 2;
    while (i <= numerador && i <= denominador) {
        if (numerador % i == 0 && denominador % i == 0) {
            numerador /= i;
            denominador /= i;
        }
        else {
            i++;
        }
    }
}

void fraccion::imprimir() const {
    std::cout << numerador << "/" << denominador;
}