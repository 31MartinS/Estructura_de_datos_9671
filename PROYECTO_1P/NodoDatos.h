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
#include "DatosPersona.cpp"

class NodoDatos{
    private:
        DatosPersona conteo;
        NodoDatos *origen;
        NodoDatos *siguiente;
    public:
        NodoDatos();
        NodoDatos(DatosPersona,NodoDatos*, NodoDatos*);
        NodoDatos* getOrigen();
        NodoDatos* getSiguiente();
        DatosPersona getConteo();
        void setOrigen(NodoDatos*);
        void setSiguiente(NodoDatos*);
        void setConteo(DatosPersona);
    friend class ClistaSimple;
};