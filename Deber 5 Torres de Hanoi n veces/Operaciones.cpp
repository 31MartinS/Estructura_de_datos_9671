#import <iostream>
#define Operaciones_cpp

void hanoi(int n, char origen, char destino, char auxiliar, function<void(int, char, char)> mover) {
    if (n == 1) {
        mover(1, origen, destino);
    } else {
        hanoi(n - 1, origen, auxiliar, destino, mover);
        mover(n, origen, destino);
        hanoi(n - 1, auxiliar, destino, origen, mover);
    }
}