#include "Matriz.h"

<<<<<<< Updated upstream
Matriz::Matriz() {
    matriz = nullptr;
    dim = 0;
}

Matriz::Matriz(int **matriz, int dim) {
    this->matriz = matriz;
    this->dim = dim;
}

int Matriz::getDim() {
    return dim;
}

void Matriz::setDim(int dim) {
    this->dim = dim;
}

int** Matriz::getMatriz() {
    return matriz;
}

void Matriz::setMatriz(int **matriz) {
    this->matriz = matriz;
=======

template <typename T>
	Matriz<T>::Matriz(T** m, int d) {
    // Implementación del constructor
}

template <typename T>
	int Matriz<T>::getDim() {
}

template <typename T>
	void Matriz<T>::setDim(int d) {
}

template <typename T>
	T** Matriz<T>::getMatriz() {
>>>>>>> Stashed changes
}

template <typename T>
	void Matriz<T>::setMatriz(T** m) {
}