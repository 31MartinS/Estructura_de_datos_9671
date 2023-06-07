/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 01/05/2023
	Enunciado: Proyecto 1P
	Nivel.- 3  NRC: 9671 
*/
#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include "registro.cpp"
#include "Cdatos.cpp"
#include "ClistaSimple.cpp"
using namespace std;

class menus{
		private: 
        ClistaSimple lista;
        Cdatos datosRol; 
	public:
        virtual int menuIngreso();
        int menuLSDC(); //Menu Escoger lista Simple, Doble, Circular
        int menuTienda(); //Lista Simple
        int menuDoble(); //Lista Doble
        int menuCircular(); //Lista Circular
        int menuPrincipalRol(); //Para Titulos dentro de las listas
        void verificar_user(); //Menu de ingreso usuario
		menus(); //Constructor Vacio
		menus(ClistaSimple*,Cdatos*); //Constructor
        char* ingresarDatosEnteros(char *); //Validacion Ingreso Enteros
        char* ingresarDatosFlotantes(char *); //Validacion Ingreso Flotantes
        char* ingresarChar(char *); //Validacion Ingreso Letras
};