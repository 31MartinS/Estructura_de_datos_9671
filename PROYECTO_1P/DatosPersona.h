/*
	UFA-ESPE
	Alumnos: Ricardo Rivadeneira, Sebastian Rivera.
	Fecha de creación: 20/11/2022
	Fecha de modificación: 30/11/2022
	Enunciado: Proyecto con uso de Listas Simples, Dobles y Circulares para generar un Rol de Pago
	Nivel.- 3   NRC: 7999
*/
#pragma once
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
class DatosPersona{
    private:
        int cedula;
        string nombre;
        string apellido;
        string cargo; //ultimo añadido
        int horasExtra;
        double anticipo;
        double sueldo; //ultimo añadido
    public:
        DatosPersona();
        DatosPersona(int, string, int, double); //ced,nom,horas, anticipo
        DatosPersona(int, string, string, int, double); //ced,nom,apell,horas,anticipo
        DatosPersona(int, string, string, string, double, int,double); //ced,nom,apell,cargo,sueldo,horas,anticipo
        ~DatosPersona();
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