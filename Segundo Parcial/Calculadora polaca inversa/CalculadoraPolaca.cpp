#include "CalculadoraPolaca.h"
#include <stack>
#include <sstream>

double CalculadoraPolaca::calcularExpresion(const std::string& expresion) {
    std::stack<double> operandos;
    std::istringstream iss(expresion);
    std::string elemento;

    while (iss >> elemento) {
        if (isdigit(elemento[0])) {
            operandos.push(stod(elemento));
        } else {
            double operando2 = operandos.top();
            operandos.pop();
            double operando1 = operandos.top();
            operandos.pop();
            double resultado = realizarOperacion(elemento[0], operando1, operando2);
            operandos.push(resultado);
        }
    }

    return operandos.top();
}

std::string CalculadoraPolaca::convertirInfijaAPostfija(const std::string& expresion) {
    // Implementación de la conversión infija a postfija
}

std::string CalculadoraPolaca::convertirInfijaAPrefija(const std::string& expresion) {
    // Implementación de la conversión infija a prefija
}

double CalculadoraPolaca::realizarOperacion(char operador, double operando1, double operando2) {
    if (operador == '+') {
        return operando1 + operando2;
    } else if (operador == '-') {
        return operando1 - operando2;
    } else if (operador == '*') {
        return operando1 * operando2;
    } else if (operador == '/') {
        return operando1 / operando2;
    }
}