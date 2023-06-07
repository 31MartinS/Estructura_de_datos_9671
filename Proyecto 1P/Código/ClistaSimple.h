/*
	UFA-ESPE
	Alumnos: Miguel Gutierrez, Sebastian Rivera, Martin Suquillo.
	Fecha de creación: 20/11/2022
	Fecha de modificación: 30/11/2022
	Enunciado: Proyecto con uso Dobles generar datos de empleados de un hospital de ancianos
	Nivel.- 3   NRC: 9671
*/
#pragma once
#include "CnodoLS.h"
#include "Cdatos.cpp"
#include "NodoDatos.cpp"
#include <iostream>

class ClistaSimple{
    private:
        int contador=0;
        CnodoLS *referencial;
        CnodoLS *origen;
        NodoDatos *cabecera;
        NodoDatos *referencial2;
        bool ListaVacia(){
            return (this->origen==NULL);
        }
        bool listaVacia(){
            return(this->cabecera==NULL);
        }
    public:
        ClistaSimple();
        virtual void insertarCab(int);
       virtual void insertarCol(int);
        virtual void imprimir();
       virtual void eliminarCab(int);
        virtual void eliminarCol(int);
        virtual void buscar(int);
       virtual int tamanioLista();
        virtual void insertarMCM(int);
       virtual char* ingresarDatosEnteros(char *);
        virtual void modificarValor(int,int);
//
        void agregarListado(Cdatos);
        void imprimirListado();
        void buscarCedula();
        void rolPagos(int,double,double);
        Cdatos buscarCed(int);

        ~ClistaSimple();
        NodoDatos* getCabecera();
//
        void separarUnidades();
};