/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 01/05/2023
	Enunciado: Proyecto 1P
	Nivel.- 3  NRC: 9671 
*/

#include "CnodoLS.h"
#include <iostream>

CnodoLS::CnodoLS(int ent, CnodoLS *sig=NULL){
    this->entrada=ent;
    this->siguiente=sig;
}
CnodoLS::~CnodoLS(){
    delete siguiente;
}
int CnodoLS::getEntrada(){
    return entrada;
}

CnodoLS* CnodoLS::getSiguiente(){
    return siguiente;
}
void CnodoLS::setEntrada(int entr){
    this->entrada=entr;
}
void CnodoLS::setSiguiente(CnodoLS *sig){
    this->siguiente=sig;
}