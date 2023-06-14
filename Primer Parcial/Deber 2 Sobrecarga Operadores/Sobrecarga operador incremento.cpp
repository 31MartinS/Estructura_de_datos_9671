/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 17/05/2023
	Enunciado: Manejo de plantillas
	Nivel.- 3  NRC: 9671 
*/
#include <iostream>

class MiClase {

private:
    int valor;

public:
    MiClase(int v) : valor(v) {}

    // Sobrecarga del operador de incremento (pre-incremento)
    MiClase operator++() {
        valor++;
        return *this;
    }

    // Sobrecarga del operador de incremento (post-incremento)
    MiClase operator++(int) {
        MiClase temp(valor);
        valor++;
        return temp;
    }

    int getValor() {
        return valor;
    }
};

int main() {
    MiClase objeto(7);

    std::cout << "Valor inicial: " << objeto.getValor() << std::endl;

    MiClase resultado1 = ++objeto;
    std::cout << "Despues del pre-incremento: " << objeto.getValor() << std::endl;
    std::cout << "Resultado del pre-incremento: " << resultado1.getValor() << std::endl;

    MiClase resultado2 = objeto++;
    std::cout << "Despues del post-incremento: " << objeto.getValor() << std::endl;
    std::cout << "Resultado del post-incremento: " << resultado2.getValor() << std::endl;

    return 0;
}
 