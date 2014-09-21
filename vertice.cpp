#include "vertice.h"

Vertice::Vertice() {
    coord[0] = 0;
    coord[1] = 0;
    coord[2] = 0;
}

Vertice::Vertice(float x, float y, float z) {
    coord[0] = x;
    coord[1] = y;
    coord[2] = z;
}

void Vertice::print() {
    std::cout << "(" << coord[0] << "," << coord[1] << "," << coord[2] << ")\n";
}
