/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 20/05/2023
	Enunciado: Matrices con Template
	Nivel.- 3  NRC: 9671 
*/
#pragma once
#include "Matriz.h"
template <typename Matriz>
class Operaciones{
	public:
		Operaciones();
		Operaciones(Matriz);
		void segmentar();
		void encerar();
		void generar();
		void procesarPot(int);
		void procesarMulti();
		void imprimir();
	private:
		Matriz _matriz;
};