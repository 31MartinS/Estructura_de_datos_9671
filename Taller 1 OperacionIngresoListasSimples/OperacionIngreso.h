/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 29/05/2023
	Enunciado: Taller - Ingreso por cabaza y cola a lista simple
	Nivel.- 3  NRC: 9671 
*/
#ifndef OPERACION_INGRESO_H
#define OPERACION_INGRESO_H

#include <iostream>
using namespace std;

struct Nodo {
    string nombre;
    Nodo* siguiente;
};

class OperacionIngreso {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    OperacionIngreso();
    ~OperacionIngreso(); // Destructor para liberar la memoria
    void insertarAlumnoCabeza();
    void insertarAlumnoCola();
    void mostrarAlumnos();
};

#endif
