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
