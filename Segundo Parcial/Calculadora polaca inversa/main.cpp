#include <iostream>
#include <string>
#include "CalculadoraPolaca.cpp"

void mostrarMenu() {
    std::cout << "Seleccione una opción:" << std::endl;
    std::cout << "1. Calcular expresión en notación polaca inversa" << std::endl;
    std::cout << "2. Convertir expresión infija a postfija" << std::endl;
    std::cout << "3. Convertir expresión infija a prefija" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Opción: ";
}

int main() {
    std::string expresion;
    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese la expresión en notación polaca inversa: ";
                std::cin >> expresion;
                std::cout << "Resultado: " << CalculadoraPolaca::calcularExpresion(expresion) << std::endl;
                break;
            case 2:
                std::cout << "Ingrese la expresión infija: ";
                std::cin >> expresion;
                std::cout << "Expresión postfija: " << CalculadoraPolaca::convertirInfijaAPostfija(expresion) << std::endl;
                break;
            case 3:
                std::cout << "Ingrese la expresión infija: ";
                std::cin >> expresion;
                std::cout << "Expresión prefija: " << CalculadoraPolaca::convertirInfijaAPrefija(expresion) << std::endl;
                break;
            case 0:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (opcion != 0);

    return 0;
}