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
#include "Cdatos.cpp"

class NodoDatos{
    private:
        Cdatos conteo;
        NodoDatos *origen;
        NodoDatos *siguiente;
    public:
        NodoDatos();
        NodoDatos(Cdatos,NodoDatos*, NodoDatos*);
        NodoDatos* getOrigen();
        NodoDatos* getSiguiente();
        Cdatos getConteo();
        void setOrigen(NodoDatos*);
        void setSiguiente(NodoDatos*);
        void setConteo(Cdatos);
    friend class ClistaSimple;
};