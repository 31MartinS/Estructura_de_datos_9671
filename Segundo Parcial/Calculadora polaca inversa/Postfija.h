/*************************
UFA - ESPE
AUTORES: Matías Padrón,Sebastian Torres, Cristhoper Villamarin, Paola Moncayo, Camilo Orrico, Jeimy Morales, Ariel Guevera
FECHA DE CREACIÓN: 01/01/2022
FECHA DE MODIFICACIÓN: 05/01/2022
Grupo1-Notaciones
GITHUB: Grupo-1-Estructura-de-datos-7999
 *************************/
#include <iostream>
#include "Pila.cpp"
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <string>


using namespace std;

class Postfija
{
	typedef Postfija Post;
	
	private:
		int posi;
		Pila pila;
		string *opera = new string[posi]; 
	public:
		string* inAPost(string);
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
}; typedef Postfija Post;
