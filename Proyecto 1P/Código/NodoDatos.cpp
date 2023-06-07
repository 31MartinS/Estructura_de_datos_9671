/*
	UFA-ESPE
	Alumnos: Miguel Gutierrez, Sebastian Rivera, Martin Suquillo.
	Fecha de creación: 20/11/2022
	Fecha de modificación: 30/11/2022
	Enunciado: Proyecto con uso Dobles generar datos de empleados de un hospital de ancianos
	Nivel.- 3   NRC: 9671
*/
#pragma once
#include <cstring>
#include <string.h>
#include "NodoDatos.h"
using namespace std;
//Constructor Vacio
NodoDatos::NodoDatos(){
}
//Constructor 
NodoDatos::NodoDatos(Cdatos con, NodoDatos* ori=NULL,NodoDatos* sig=NULL){
    this->origen=ori;
    this->siguiente=sig;
    this->conteo=con;
}

//Metodo Get
NodoDatos* NodoDatos::getOrigen(){
    return origen;
}
NodoDatos* NodoDatos::getSiguiente(){
    return siguiente;
}
Cdatos NodoDatos::getConteo(){
    return conteo;
}
//Meotodo Set
void NodoDatos::setOrigen(NodoDatos* ori){
    this->origen=ori;
}
void NodoDatos::setSiguiente(NodoDatos* sig){
    this->siguiente=sig;
}
void NodoDatos::setConteo(Cdatos con){
    this->conteo=con;
}