/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Guti�rrez Miguel, Rivera Sebasti�n, Suquillo Mart�n
	Fecha de creaci�n: 12/05/2023
	Enunciado: Manejo de plantillas
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