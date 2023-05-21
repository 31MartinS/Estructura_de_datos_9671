#include "Matriz.h"

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
}
