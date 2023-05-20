/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 20/05/2023
	Enunciado: Matrices con Template
	Nivel.- 3  NRC: 9671 
*/

#pragma once
#include <iostream>

template <typename T>
class Matriz {
private:
    T** matriz;
    int dim;
public:
    Matriz();
    Matriz(T**, int);
    int getDim();
    void setDim(int);
    T** getMatriz();
    void setMatriz(T**);
};

