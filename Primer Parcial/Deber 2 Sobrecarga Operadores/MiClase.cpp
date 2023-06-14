/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 17/05/2023
	Enunciado: Manejo de plantillas
	Nivel.- 3  NRC: 9671 
*/
#include "MiClase.h"

MiClase::MiClase(int v) : valor(v) {}

MiClase MiClase::operator++() {
    valor++;
    return *this;
}

MiClase MiClase::operator++(int) {
    MiClase temp(valor);
    valor++;
    return temp;
}

int MiClase::getValor() {
    return valor;
}
