/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 20/05/2023
	Enunciado: Matrices con Template
	Nivel.- 3  NRC: 9671 
*/

#pragma once

class Matriz {
private:
    int **matriz;
    int dim;

public:
    Matriz();
    Matriz(int **matriz, int dim);
    int getDim();
    void setDim(int dim);
    int** getMatriz();
    void setMatriz(int **matriz);
};
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
