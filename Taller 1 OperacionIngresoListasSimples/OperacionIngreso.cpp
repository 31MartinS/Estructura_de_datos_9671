/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 29/05/2023
	Enunciado: Taller - Ingreso por cabaza y cola a lista simple
	Nivel.- 3  NRC: 9671 
*/
#include "OperacionIngreso.h"

OperacionIngreso::OperacionIngreso() {
    cabeza = nullptr;
    cola = nullptr;
}

OperacionIngreso::~OperacionIngreso() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void OperacionIngreso::insertarAlumnoCabeza() {
    string nombre;
    cout << "Ingrese el nombre del alumno a insertar al principio de la lista: ";
    cin >> nombre;

    Nodo* nuevoAlumno = new Nodo;
    nuevoAlumno->nombre = nombre;
    nuevoAlumno->siguiente = cabeza;
    cabeza = nuevoAlumno;

    if (cola == nullptr) {
        cola = nuevoAlumno;
    }

    cout << "Alumno '" << nombre << "' insertado al principio de la lista." << endl;
}

void OperacionIngreso::insertarAlumnoCola() {
    string nombre;
    cout << "Ingrese el nombre del alumno a insertar al final de la lista: ";
    cin >> nombre;

    Nodo* nuevoAlumno = new Nodo;
    nuevoAlumno->nombre = nombre;
    nuevoAlumno->siguiente = nullptr;

    if (cola == nullptr) {
        cabeza = nuevoAlumno;
        cola = nuevoAlumno;
    } else {
        cola->siguiente = nuevoAlumno;
        cola = nuevoAlumno;
    }

    cout << "Alumno '" << nombre << "' insertado al final de la lista." << endl;
}

void OperacionIngreso::mostrarAlumnos() {
    Nodo* actual = cabeza;

    if (actual == nullptr) {
        cout << "La lista de alumnos está vacía." << endl;
    } else {
        cout << "Lista de alumnos:" << endl;
        while (actual != nullptr) {
            cout << actual->nombre << endl;
            actual = actual->siguiente;
        }
        cout << "NULL" << endl; // Mostrar el nodo nulo al final de la lista
    }
}
