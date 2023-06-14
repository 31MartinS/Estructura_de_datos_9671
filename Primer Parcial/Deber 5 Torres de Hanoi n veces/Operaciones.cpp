/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 26/05/2023
	Enunciado: Torres de hanoi n veces
	Nivel.- 3  NRC: 9671 
*/

#import <iostream>
#define Operaciones_cpp

void hanoi(int n, char origen, char destino, char auxiliar, function<void(int, char, char)> mover) {
    if (n == 1) {
        mover(1, origen, destino);
    } else {
        hanoi(n - 1, origen, auxiliar, destino, mover);
        mover(n, origen, destino);
        hanoi(n - 1, auxiliar, destino, origen, mover);
    }
}