/*
	UFA-ESPE
	Alumnos: Miguel Gutierrez, Sebastian Rivera, Martin Suquillo.
	Fecha de creación: 20/11/2022
	Fecha de modificación: 30/11/2022
	Enunciado: Proyecto con uso Dobles generar datos de empleados de un hospital de ancianos
	Nivel.- 3   NRC: 9671
*/
#pragma once
#include <iostream>
#include "Cdatos.h"
//Constructor Vacio
Cdatos::Cdatos(){
}
//Constructor
Cdatos::Cdatos(int ced, string nom, int he, double ant){
    this->cedula=ced;
    this->nombre=nom;
    this->horasExtra=he;
    this->anticipo=ant;
}
Cdatos::Cdatos(int ced, string nom, string apel, int he, double ant){
    this->cedula=ced;
    this->nombre=nom;
    this->apellido=apel;
    this->horasExtra=he;
    this->anticipo=ant;
}
Cdatos::Cdatos(int ced, string nom, string apel, string carg, double sueld, int he, double ant){
    this->cedula=ced;
    this->nombre=nom;
    this->apellido=apel;
    this->cargo=carg;
    this->sueldo=sueld;
    this->horasExtra=he;
    this->anticipo=ant;
}
//Destructor
Cdatos::~Cdatos(){
}

//Meotodos Get
int Cdatos::getCedula(){
    return this->cedula;
}
string Cdatos::getNombre(){
    return this->nombre;
}
string Cdatos::getApellido(){
    return this->apellido;
}
string Cdatos::getCargo(){
    return this->cargo;
}
double Cdatos::getSueldo(){
    return this->sueldo;
}
int Cdatos::getHorasExtra(){
    return this->horasExtra;
}
double Cdatos::getAnticipo(){
    return this->anticipo;
}

//Metodos Set
void Cdatos::setCedula(int ced){
    this->cedula=ced;
}
void Cdatos::setNombre(string nom){
    this->nombre=nom;
}
void Cdatos::setApellido(string apelli){
    this->apellido=apelli;
}
void Cdatos::setCargo(string car){
    this->cargo=car;
}
void Cdatos::setSueldo(double dinero){
    this->sueldo=dinero;
}
void Cdatos::setHorasExtra(int he){
    this->horasExtra=he;
}
void Cdatos::setAnticipo(double ant){
    this->anticipo=ant;
}

//Metodo para imprimir el Catalogo
void Cdatos::imprimirRol(){
    std::cout<<"Imprimir Rol"<<endl;
    std::cout<<this->getCedula();
    std::cout<<this->getNombre();
    std::cout<<this->getApellido();
    std::cout<<this->getCargo();
    std::cout<<this->getSueldo();
    std::cout<<this->getHorasExtra();
    std::cout<<this->getAnticipo();
}
