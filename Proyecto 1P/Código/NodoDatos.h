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