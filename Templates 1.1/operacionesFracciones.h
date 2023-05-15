#ifndef OPERACIONESFRACCIONES_H
#define OPERACIONESFRACCIONES_H

#include "fraccion.cpp"

template<typename T>
class operacionesFracciones {
public:
    static fraccion sumar(const T& f1, const T& f2);
    static fraccion restar(const T& f1, const T& f2);
    static fraccion multiplicar(const T& f1, const T& f2);
    static fraccion dividir(const T& f1, const T& f2);
    static int mcd(int a, int b);
    static int mcm(int a, int b);
};



#endif