/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Guti�rrez Miguel, Rivera Sebasti�n, Suquillo Mart�n
	Fecha de creaci�n: 17/05/2023
	Enunciado: Manejo de plantillas
	Nivel.- 3  NRC: 9671 
*/#ifndef MICLASE_H
#define MICLASE_H

class MiClase {
private:
    int valor;

public:
    MiClase(int v);

    MiClase operator++();
    MiClase operator++(int);

    int getValor();
};

#endif // MICLASE_H
