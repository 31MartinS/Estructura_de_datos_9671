#ifndef CALCULADORAPOLACA_H
#define CALCULADORAPOLACA_H

#include <string>

class CalculadoraPolaca {
public:
    static double calcularExpresion(const std::string& expresion);
    static std::string convertirInfijaAPostfija(const std::string& expresion);
    static std::string convertirInfijaAPrefija(const std::string& expresion);

private:
    static double realizarOperacion(char operador, double operando1, double operando2);
};

#endif  // CALCULADORAPOLACA_H