/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 20/05/2023
	Enunciado: Matrices con Template
	Nivel.- 3  NRC: 9671 
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include "Operaciones.h"

template <typename Matriz>
Operaciones<Matriz>::Operaciones(Matriz m){
	this->_matriz=m;
}
template <typename Matriz>
void Operaciones<Matriz>::segmentar(){
	int j, **matriz;
	matriz=_matriz.getMatriz();
	matriz=(int**)malloc(_matriz.getDim()*sizeof(int*));
	for(j=0;j<_matriz.getDim();j++){
		*(matriz+j)=(int*)malloc(_matriz.getDim()*sizeof(int*));
	}
	_matriz.setMatriz(matriz);
}
template <typename Matriz>
void Operaciones<Matriz>::encerar(){
	for(int i=0;i<_matriz.getDim();i++){
		for(int j=0;j<_matriz.getDim();j++){
			*(*(_matriz.getMatriz()+i)+j)=0;
		}
	}
}
template <typename Matriz>
void Operaciones<Matriz>::imprimir(){
	printf("La matriz es:\n");
	for(int i=0;i<_matriz.getDim();i++){
		for(int j=0;j<_matriz.getDim();j++){
			printf("%d",*(*(_matriz.getMatriz()+i)+j));
			printf("%*s",j+5,"");
		}
		printf("\n");
	}
}

/*
int **Operaciones::generar(){
	srand(time(NULL));
	int **matriz;
	for(int i=0;i<_matriz.getDim();i++){
		for(int j=0;j<_matriz.getDim();j++)	{
			*(*(matriz+i)+j)=rand()%3;
		}
	}
	return matriz;
}

void Operaciones::procesarPot(int exp, int **matriz){
	for(int e=1;e<=exp;e++){
		for(int i=0;i<_matriz.getDim();i++){
			for(int j=0;j<_matriz.getDim();j++){
				for(int k=0;k<_matriz.getDim();k++){
					*(*(_matriz.getMatrizR()+i)+j)=*(*(_matriz.getMatrizR()+i)+j)+ 
					(*(*(_matriz.getMatriz2()+i)+k) * (*(*(_matriz.getMatriz2()+k)+j)));                				}
			}
		}
	}
}
void Operaciones::procesarMulti(){
	for(int i=0;i<_matriz.getDim();i++){
		for(int j=0;j<_matriz.getDim();j++){
			for(int k=0;k<_matriz.getDim();k++){
				*(*(_matriz.getMatrizR()+i)+j)=	*(*(_matriz.getMatrizR()+i)+j)+ (*(*(_matriz.getMatriz1()+i)+k)*(*(*(_matriz.getMatriz2()+k)+j)));
			}
		}
	}
}
*/