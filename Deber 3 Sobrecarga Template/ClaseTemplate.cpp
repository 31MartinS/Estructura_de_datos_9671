/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 17/05/2023
	Enunciado: Manejo de plantillas
	Nivel.- 3  NRC: 9671 
*/
#include "ClaseTemplate.h"

template<typename T>
ClaseTemplate<T>::ClaseTemplate(T v) : valor(v) {}

template<typename T>
ClaseTemplate<T> ClaseTemplate<T>::operator++() {
    valor++;
    return *this;
}

template<typename T>
ClaseTemplate<T> ClaseTemplate<T>::operator++(int) {
    ClaseTemplate<T> temp(valor);
    valor++;
    return temp;
}

template<typename T>
T ClaseTemplate<T>::getValor() {
    return valor;
}