/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 17/05/2023
	Enunciado: Manejo de plantillas
	Nivel.- 3  NRC: 9671 
*/
#include <iostream>
#include "MiClase.cpp"

int main() {
    MiClase objeto(7);

    std::cout << "Valor inicial: " << objeto.getValor() << std::endl;

    MiClase resultado1 = ++objeto;
    std::cout << "Después del pre-incremento: " << objeto.getValor() << std::endl;
    std::cout << "Resultado del pre-incremento: " << resultado1.getValor() << std::endl;

    MiClase resultado2 = objeto++;
    std::cout << "Después del post-incremento: " << objeto.getValor() << std::endl;
    std::cout << "Resultado del post-incremento: " << resultado2.getValor() << std::endl;

    return 0;
}
