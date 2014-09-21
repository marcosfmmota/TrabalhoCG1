#ifndef FACE_H
#define FACE_H
#include "vertice.h"

class Face
{
public:
    Vertice vertice[3], *centro;
    Face(Vertice v1, Vertice v2, Vertice v3);
private:
    Vertice* calcular_centro();
};

#endif // FACE_H
