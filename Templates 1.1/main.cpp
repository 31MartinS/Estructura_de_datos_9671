#include <iostream>
#include "fraccion.h"
#include "operacionesFracciones.cpp"

int main() {
    int opcion = 0;
    fraccion f1, f2, resultado;

    while (opcion != 7) {
        std::cout << "Ingrese la opcion que desea:\n";
        std::cout << "1. Ingresar fraccion 1\n";
        std::cout << "2. Ingresar fraccion 2\n";
        std::cout << "3. Sumar fracciones\n";
        std::cout << "4. Restar fracciones\n";
        std::cout << "5. Multiplicar fracciones\n";
        std::cout << "6. Dividir fracciones\n";
        std::cout << "7. Salir\n";

        std::cin >> opcion;

        switch (opcion) {
            case 1:
                int numerador, denominador;
                std::cout << "Ingrese el numerador de la fraccion 1: ";
                std::cin >> numerador;
                std::cout << "Ingrese el denominador de la fraccion 1: ";
                std::cin >> denominador;
                f1 = fraccion(numerador, denominador);
                system("cls");
                break;
            case 2:
                std::cout << "Ingrese el numerador de la fraccion 2: ";
                std::cin >> numerador;
                std::cout << "Ingrese el denominador de la fraccion 2: ";
                std::cin >> denominador;
                f2 = fraccion(numerador, denominador);
                system("cls");
                break;
            case 3:
                resultado = operacionesFracciones<fraccion>::sumar(f1, f2);
                std::cout << "La suma es: ";
                resultado.imprimir();
                std::cout << " = " << (double) resultado.getNumerador() / resultado.getDenominador() << std::endl;
                system("pause");
				system("cls");
                break;
            case 4:
                resultado = operacionesFracciones<fraccion>::restar(f1, f2);
                std::cout << "La resta es: ";
                resultado.imprimir();
                std::cout << " = " << (double) resultado.getNumerador() / resultado.getDenominador() << std::endl;
                system("pause");
				system("cls");
                break;
            case 5:
                resultado = operacionesFracciones<fraccion>::multiplicar(f1, f2);
                std::cout << "La multiplicacion es: ";
                resultado.imprimir();
                std::cout << " = " << (double) resultado.getNumerador() / resultado.getDenominador() << std::endl;
                system("pause");
				system("cls");
                break;
	        case 6:
	            resultado = operacionesFracciones<fraccion>::dividir(f1, f2);
	            std::cout << "La division es: ";
	            resultado.imprimir();
	            std::cout << " = " << (double) resultado.getNumerador() / resultado.getDenominador() << std::endl;
                system("pause");
				system("cls");
	            break;
	        case 7:
	            std::cout << "Adios!\n";
	            break;
	        default:
	            std::cout << "Opcion invalida\n";
		    }
		    
		}
		system("cls");
		return 0;
} 