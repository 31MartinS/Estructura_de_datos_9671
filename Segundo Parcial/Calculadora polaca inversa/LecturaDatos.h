/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Enunciado: Deber Calculadora Polaca
	Nivel.- 3  NRC: 9671 
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#pragma once
class LecturaDatos{
	public:
	virtual char* lecturaEnteros(char const *msj)  = 0;
	virtual char* lecturaReales(char const *msj) = 0;
	virtual char* lecturaTexto(char const *msj) = 0;
	virtual char* lecturaTextoNumerico(char const *msj) = 0;
};