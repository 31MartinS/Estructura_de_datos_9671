/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 01/05/2023
	Enunciado: Proyecto 1P
	Nivel.- 3  NRC: 9671 
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