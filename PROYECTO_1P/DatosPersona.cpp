/*
	UFA-ESPE
	Alumnos: Miguel Gutierrez, Sebastian Rivera, Martin Suquillo.
	Fecha de creación: 20/11/2022
	Fecha de modificación: 30/11/2022
	Enunciado: Proyecto con uso de Listas Simples, Dobles y Circulares para generar un Rol de Pago
	Nivel.- 3   NRC: 7999
*/

#pragma once
#include <iostream>
#include "DatosPersona.h"
//Constructor Vacio
DatosPersona::DatosPersona(){
}
//Constructor
DatosPersona::DatosPersona(int ced, string nom, int he, double ant){
    this->cedula=ced;
    this->nombre=nom;
    this->horasExtra=he;
    this->anticipo=ant;
}
DatosPersona::DatosPersona(int ced, string nom, string apel, int he, double ant){
    this->cedula=ced;
    this->nombre=nom;
    this->apellido=apel;
    this->horasExtra=he;
    this->anticipo=ant;
}
DatosPersona::DatosPersona(int ced, string nom, string apel, string carg, double sueld, int he, double ant){
    this->cedula=ced;
    this->nombre=nom;
    this->apellido=apel;
    this->cargo=carg;
    this->sueldo=sueld;
    this->horasExtra=he;
    this->anticipo=ant;
}
//Destructor
DatosPersona::~DatosPersona(){
}

//Meotodos Get
int DatosPersona::getCedula(){
    return this->cedula;
}
string DatosPersona::getNombre(){
    return this->nombre;
}
string DatosPersona::getApellido(){
    return this->apellido;
}
string DatosPersona::getCargo(){
    return this->cargo;
}
double DatosPersona::getSueldo(){
    return this->sueldo;
}
int DatosPersona::getHorasExtra(){
    return this->horasExtra;
}
double DatosPersona::getAnticipo(){
    return this->anticipo;
}

//Metodos Set
void DatosPersona::setCedula(int ced){
    this->cedula=ced;
}
void DatosPersona::setNombre(string nom){
    this->nombre=nom;
}
void DatosPersona::setApellido(string apelli){
    this->apellido=apelli;
}
void DatosPersona::setCargo(string car){
    this->cargo=car;
}
void DatosPersona::setSueldo(double dinero){
    this->sueldo=dinero;
}
void DatosPersona::setHorasExtra(int he){
    this->horasExtra=he;
}
void DatosPersona::setAnticipo(double ant){
    this->anticipo=ant;
}

//Metodo para imprimir el Catalogo
void DatosPersona::imprimirRol(){
    std::cout<<"Imprimir Rol"<<endl;
    std::cout<<this->getCedula();
    std::cout<<this->getNombre();
    std::cout<<this->getApellido();
    std::cout<<this->getCargo();
    std::cout<<this->getSueldo();
    std::cout<<this->getHorasExtra();
    std::cout<<this->getAnticipo();
}
