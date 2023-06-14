/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 26/05/2023
	Enunciado: Torres de hanoi n veces
	Nivel.- 3  NRC: 9671 
*/
#include <iostream>
#include <functional>

void hanoi(int n, char origen, char destino, char auxiliar, std::function<void(int, char, char)> mover) {
    if (n == 1) {
        mover(1, origen, destino);
    } else {
        hanoi(n - 1, origen, auxiliar, destino, mover);
        mover(n, origen, destino);
        hanoi(n - 1, auxiliar, destino, origen, mover);
    }
}

int main() {
    // Solución para 4 discos
    std::cout << "Solucion para 4 discos:\n";
    hanoi(4, 'A', 'C', 'B', [](int disco, char origen, char destino) {
        std::cout << "Mover disco " << disco << " desde " << origen << " hasta " << destino << std::endl;
    });

    std::cout << std::endl;

    // Solución para n discos
    int n;
    std::cout << "Ingrese el numero de discos: ";
    std::cin >> n;

    std::cout << "Solucion para " << n << " discos:\n";
    hanoi(n, 'A', 'C', 'B', [](int disco, char origen, char destino) {
        std::cout << "Mover disco " << disco << " desde " << origen << " hasta " << destino << std::endl;
    });

    return 0;
}
