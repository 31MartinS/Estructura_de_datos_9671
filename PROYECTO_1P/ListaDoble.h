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
#include <string>
#include "NodoDatos.cpp"
using namespace std;

class ListaDoble{
    private:
    NodoDatos *cabeza;
    NodoDatos *actual;
    bool ListaVacia(){
			return (this->cabeza==NULL);
	}   
    public:
    ListaDoble();
    ~ListaDoble();
    void realizarInventario(DatosPersona);
    void agregarDatosPersona(DatosPersona);//insertar por cola
    void retirarDatosPersona(DatosPersona);//eliminar
    DatosPersona buscarDatosPersona(int);
    void mostrar();
    void rolPagos(string,string,string,int,double,double,double); //Nombre,Apellido,Cargo,Cedula,Sueldo,Horas,Anticipo
};