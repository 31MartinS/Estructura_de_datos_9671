/*
	UFA-ESPE
	Alumnos: Miguel Gutierrez, Sebastian Rivera, Martin Suquillo.
	Fecha de creación: 20/11/2022
	Fecha de modificación: 30/11/2022
	Enunciado: Proyecto con uso Dobles generar datos de empleados de un hospital de ancianos
	Nivel.- 3   NRC: 9671
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