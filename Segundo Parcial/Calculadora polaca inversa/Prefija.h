/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Enunciado: Deber Calculadora Polaca
	Nivel.- 3  NRC: 9671 
*/

#include <iostream>
#include "Pila.cpp"
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Prefija
{
	typedef Prefija Pre;
	
	private:
		int posi;
		Pila pila;
		string *opera = new string[posi]; 
	public:
		string* inAPre(string);
		int getPosi();
		float resuelve(string);
		float suma(float,float);
		float resta(float,float);
		float multi(float,float);
		float divi(float,float);
		float pot(float,float);
		float sen(float);
		float cose(float);
		float tange(float);
		float arccose(float);
		float arcsen(float);
		float arctange(float);
		float senh(float);
		float coseh(float);
		float tangeh(float);
		int priorizar(string);
		
		float raiz(float);
}; typedef Prefija Pre;