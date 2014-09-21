#include "face.h"

Face::Face(Vertice v1, Vertice v2, Vertice v3) {
    vertice[0] = v1;
    vertice[1] = v2;
    vertice[2] = v3;
    centro = calcular_centro();
}

Vertice* Face::calcular_centro() {
    return new Vertice((vertice[0].coord[0] + vertice[1].coord[0] + vertice[2].coord[0])/3,
                (vertice[0].coord[1] + vertice[1].coord[1] + vertice[2].coord[1])/3,
                (vertice[0].coord[2] + vertice[1].coord[2] + vertice[2].coord[2])/3);
}
