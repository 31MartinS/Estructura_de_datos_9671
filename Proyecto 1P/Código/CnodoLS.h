/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 01/05/2023
	Enunciado: Proyecto 1P
	Nivel.- 3  NRC: 9671 
*/

#ifndef CNODOLS_H
#define CNODOLS_H
#include <iostream>
using namespace std;

class CnodoLS{
    private:
        int entrada;
        CnodoLS *siguiente;

    public:
        CnodoLS(int, CnodoLS *siguiente);
        CnodoLS();
        ~CnodoLS();
        int getEntrada();
        CnodoLS *getSiguiente();
        void setEntrada(int);
        void setSiguiente(CnodoLS *siguiente);
};
#endif