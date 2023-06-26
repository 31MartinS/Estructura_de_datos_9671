/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Enunciado: Deber Calculadora Polaca
	Nivel.- 3  NRC: 9671 
*/

#pragma once
#include "Nodo.cpp"
#include <iostream>
#include <string>
using namespace std;
class Pila{
	private:
		Nodo *primero;
		Nodo *actual;
		bool ListaVacia();		
	public:
		//métodos de los atributos
		Pila();
		void setPrimero(Nodo *);
		void setActual(Nodo *);
		Nodo *getPrimero();
		Nodo *getActual();
		bool getPilaVacia();
		//métodos de orden de la lista
		void push(string);
		void pop();
		void mostrar();
		void buscar(string);
		int contar();
		//void buscar(int);
};
