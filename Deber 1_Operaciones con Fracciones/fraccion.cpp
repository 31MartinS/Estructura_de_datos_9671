/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Enunciado: Deber1 Fracciones
	Nivel.- 3  NRC: 9671 
*/

#include <iostream>
#include "fraccion.h"

Fraccion::Fraccion(int num, int den) : numerador(num), denominador(den) {}

Fraccion Fraccion::suma(const Fraccion& otra) const {
    int num = (numerador * otra.denominador) + (otra.numerador * denominador);
    int den = denominador * otra.denominador;
    return Fraccion(num, den);
}

Fraccion Fraccion::resta(const Fraccion& otra) const {
    int num = (numerador * otra.denominador) - (otra.numerador * denominador);
    int den = denominador * otra.denominador;
    return Fraccion(num, den);
}

Fraccion Fraccion::multiplicacion(const Fraccion& otra) const {
    int num = numerador * otra.numerador;
    int den = denominador * otra.denominador;
    return Fraccion(num, den);
}

Fraccion Fraccion::division(const Fraccion& otra) const {
    int num = numerador * otra.denominador;
    int den = denominador * otra.numerador;
    return Fraccion(num, den);
}

void Fraccion::imprimir() const {
    std::cout << numerador << "/" << denominador << std::endl;
}