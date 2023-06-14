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
#include <cstring>
#include <string.h>
using namespace std;
class Cdatos{
    private:
        int cedula;
        string nombre;
        string apellido;
        string cargo; //ultimo añadido
        int horasExtra;
        double anticipo;
        double sueldo; //ultimo añadido
    public:
        Cdatos();
        Cdatos(int, string, int, double); //ced,nom,horas, anticipo
        Cdatos(int, string, string, int, double); //ced,nom,apell,horas,anticipo
        Cdatos(int, string, string, string, double, int,double); //ced,nom,apell,cargo,sueldo,horas,anticipo
        ~Cdatos();
        int getCedula();
        string getNombre();
        string getApellido();
        string getCargo(); //añadido
        double getSueldo(); //añadido
        int getHorasExtra();
        double getAnticipo();
        void setCedula(int);
        void setNombre(string);
        void setApellido(string);
        void setCargo(string); //añadido
        void setSueldo(double); //añadido
        void setHorasExtra(int);
        void setAnticipo(double);
        void imprimirRol();
};