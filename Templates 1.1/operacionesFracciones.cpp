
#include "operacionesFracciones.h"

template<typename T>
int operacionesFracciones<T>::mcd(int a, int b) {
    int resto = a % b;
    while (resto != 0) {
        a = b;
        b = resto;
        resto = a % b;
    }
    return b;
}

template<typename T>
int operacionesFracciones<T>::mcm(int a, int b) {
    int resultado = (a * b) / operacionesFracciones<T>::mcd(a, b);
    return resultado;
}

template<typename T>
fraccion operacionesFracciones<T>::sumar(const T& f1, const T& f2) {
    int mcm = operacionesFracciones<T>::mcm(f1.getDenominador(), f2.getDenominador());
    int numerador = f1.getNumerador() * (mcm / f1.getDenominador()) +
                    f2.getNumerador() * (mcm / f2.getDenominador());
    fraccion resultado(numerador, mcm);
    return resultado;
}

template<typename T>
fraccion operacionesFracciones<T>::restar(const T& f1, const T& f2) {
    int mcm = operacionesFracciones<T>::mcm(f1.getDenominador(), f2.getDenominador());
    int numerador = f1.getNumerador() * (mcm / f1.getDenominador()) -
                    f2.getNumerador() * (mcm / f2.getDenominador());
    fraccion resultado(numerador, mcm);
    return resultado;
}

template<typename T>
fraccion operacionesFracciones<T>::multiplicar(const T& f1, const T& f2) {
    int numerador = f1.getNumerador() * f2.getNumerador();
    int denominador = f1.getDenominador() * f2.getDenominador();
    fraccion resultado(numerador, denominador);
    return resultado;
}

template<typename T>
fraccion operacionesFracciones<T>::dividir(const T& f1, const T& f2) {
    int numerador = f1.getNumerador() * f2.getDenominador();
    int denominador = f1.getDenominador() * f2.getNumerador();
    fraccion resultado(numerador, denominador);
    return resultado;
}

