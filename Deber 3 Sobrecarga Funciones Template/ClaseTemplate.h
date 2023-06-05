/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 17/05/2023
	Enunciado: Manejo de plantillas
	Nivel.- 3  NRC: 9671 
*/
#ifndef CLASETEMPLATE_H
#define CLASETEMPLATE_H

template<typename T>
class ClaseTemplate {
private:
    T valor;

public:
    ClaseTemplate(T v);

    // Sobrecarga del operador de incremento (pre-incremento)
    ClaseTemplate<T> operator++();

    // Sobrecarga del operador de incremento (post-incremento)
    ClaseTemplate<T> operator++(int);

    T getValor();
};

#endif






