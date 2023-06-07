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
#include <string>
#include "NodoDatos.cpp"
using namespace std;

class ClistaDoble{
    private:
    NodoDatos *cabeza;
    NodoDatos *actual;
    bool ListaVacia(){
			return (this->cabeza==NULL);
	}   
    public:
    ClistaDoble();
    ~ClistaDoble();
    void realizarInventario(Cdatos);
    void agregarCdatos(Cdatos);//insertar por cola
    void retirarCdatos(Cdatos);//eliminar
    void imprimirRegistros();
    Cdatos buscarCdatos(int);
    void mostrar();
    void registro(string,string,string,int,double,double,double); //Nombre,Apellido,Cargo,Cedula,Sueldo,Horas,Anticipo
};