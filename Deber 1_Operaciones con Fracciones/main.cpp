/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Enunciado: Deber1 Fracciones
	Nivel.- 3  NRC: 9671 
*/

#include <iostream>
#include "fraccion.cpp"

int main() {
    int num1, den1, num2, den2;

    std::cout << "Ingrese la primera fraccion (numerador/denominador): ";
    std::cin >> num1 >> den1;

    std::cout << "Ingrese la segunda fraccion (numerador/denominador): ";
    std::cin >> num2 >> den2;

    Fraccion fraccion1(num1, den1);
    Fraccion fraccion2(num2, den2);

    Fraccion suma = fraccion1.suma(fraccion2);
    Fraccion resta = fraccion1.resta(fraccion2);
    Fraccion multiplicacion = fraccion1.multiplicacion(fraccion2);
    Fraccion division = fraccion1.division(fraccion2);

    std::cout << "Suma: ";
    suma.imprimir();

    std::cout << "Resta: ";
    resta.imprimir();

    std::cout << "Multiplicacion: ";
    multiplicacion.imprimir();

    std::cout << "Division: ";
    division.imprimir();

    return 0;
}