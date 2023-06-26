/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Enunciado: Deber Calculadora Polaca
	Nivel.- 3  NRC: 9671 
*/

 #include <iostream>
#include <cstdlib>
#include <conio.h>

#include <windows.h>
using namespace std;
class Menu{
	public:
		void menuPrincipal();
		int menu(const char *titulo,const char *opciones[],int n);
		void gotoxy(int x,int y);
		//int validarCedula(char *cedulaC);
		static bool verificarCedula(const string &cedula);
};
