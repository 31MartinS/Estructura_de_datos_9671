/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 20/05/2023
	Enunciado: Matrices con Template
	Nivel.- 3  NRC: 9671 
*/
#include <iostream>
#include "Matriz.cpp"
#include "Operaciones.cpp"
/*int ingresar(char *);
int ingresar(char *msj){
	int dim;
	printf("\n%s\n",msj);
	scanf("%d",&dim);
	return dim;
}
void iniciar(int);
void iniciar(int  dim){
	int pot;
	int **mR=nullptr;
	int **m1=nullptr;
	int **m2=nullptr;
	Matriz matriz1(m1, dim);
	Operaciones operaciones1(matriz1);
	operaciones1.segmentar();
	operaciones1.encerar();
	operaciones1.imprimir();
	/*
	m1=operaciones.generar();
	m2=operaciones.generar();
	operaciones.imprimir(m1);
	operaciones.imprimir(m2);*/
/*}*/
/*
int main(int argc, char** argv) {
	int dim;
	dim=ingresar("Ingrese la dimension de la matriz");
	iniciar(dim);
	
	return 0;
}*/


template <typename T>
Matriz<T> ::ingresar(char* msj) {
	int dim;
	printf("\n%s\n", msj);
	scanf("%d", &dim);
	
	T** matriz = new T*[dim];
	for (int i = 0; i < dim; i++) {
		matriz[i] = new T[dim];
	}
	
	return Matriz<T>(matriz, dim);
}

template <typename T>
void iniciar(int dim) {
	Matriz<T> matriz1 = ingresar<T>("Ingrese la matriz");
	Operaciones<Matriz<T>> operaciones1(matriz1);
	operaciones1.segmentar();
	operaciones1.encerar();
	operaciones1.imprimir();
}

int main(int argc, char** argv) {
	int dim;
	dim = ingresar<int>("Ingrese la dimension de la matriz");
	iniciar<int>(dim);

	return 0;
}