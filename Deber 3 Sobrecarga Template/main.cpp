/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 17/05/2023
	Enunciado: Manejo de plantillas
	Nivel.- 3  NRC: 9671 
*/
#include <iostream>
#include "ClaseTemplate.cpp"
#include "Imprimir.h"

int main() {
    
    Validacion valido;
    std::cout << "Ingrese el valor inicial: ";
    int valorInicial = valido.ingresarDatosEnteros();

    ClaseTemplate<int> objeto(valorInicial);

    std::cout << "Valor inicial: " << objeto.getValor() << std::endl;

    ClaseTemplate<int> resultado1 = ++objeto;
    std::cout << "Despues del pre-incremento: " << objeto.getValor() << std::endl;
    std::cout << "Resultado del pre-incremento: " << resultado1.getValor() << std::endl;

    ClaseTemplate<int> resultado2 = objeto++;
    std::cout << "Despues del post-incremento: " << objeto.getValor() << std::endl;
    std::cout << "Resultado del post-incremento: " << resultado2.getValor() << std::endl;

    return 0;
}