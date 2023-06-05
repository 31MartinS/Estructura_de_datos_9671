/*
	UFA-ESPE
	Alumnos: Miguel Gutierrez, Sebastian Rivera, Martin Suquillo.
	Fecha de creación: 20/11/2022
	Fecha de modificación: 30/11/2022
	Enunciado: Proyecto con uso de Listas Simples, Dobles y Circulares para generar un Rol de Pago
	Nivel.- 3   NRC: 9671
*/

#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include "registro.cpp"
#include "DatosPersona.cpp"
using namespace std;

class menus{
		private: 
        //ClistaSimple lista;
        DatosPersona datosRol; 
	public:
        virtual int menuIngreso();
        int menuLSDC(); //Menu Escoger lista Simple, Doble, Circular
        int menuTienda(); //Lista Simple
        int menuDoble(); //Lista Doble
        int menuCircular(); //Lista Circular
        int menuPrincipalRol(); //Para Titulos dentro de las listas
        void verificar_user(); //Menu de ingreso usuario
		menus(); //Constructor Vacio
		//menus(ClistaSimple*,DatosPersona*); //Constructor
        char* ingresarDatosEnteros(char *); //Validacion Ingreso Enteros
        char* ingresarDatosFlotantes(char *); //Validacion Ingreso Flotantes
        char* ingresarChar(char *); //Validacion Ingreso Letras
};