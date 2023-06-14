/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Enunciado: Deber1 Fracciones
	Nivel.- 3  NRC: 9671 
*/

#ifndef FRACCION_H
#define FRACCION_H

class Fraccion {
private:
    int numerador;
    int denominador;

public:
    Fraccion(int num = 0, int den = 1);
    Fraccion suma(const Fraccion& otra) const;
    Fraccion resta(const Fraccion& otra) const;
    Fraccion multiplicacion(const Fraccion& otra) const;
    Fraccion division(const Fraccion& otra) const;
    void imprimir() const;
};

#endif  // FRACCION_H