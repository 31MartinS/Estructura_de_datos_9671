/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 10/05/2023
	Enunciado: Sobrecarga de funciones y operadores
	Nivel.- 3  NRC: 9671 
*/
#ifndef FRACCION_H
#define FRACCION_H

class fraccion {
private:
    int numerador;
    int denominador;

public:
    fraccion(int numerador = 0, int denominador = 1);
    int getNumerador() const;
    int getDenominador() const;
    void simplificar();
    void imprimir() const;
};

#endif //FRACCION_H