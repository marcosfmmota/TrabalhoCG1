#ifndef VERTICE_H
#define VERTICE_H
#include <iostream>

class Vertice
{
public:
    float coord[3];
    Vertice();
    Vertice(float x, float y, float z);
    void print();
};

#endif // VERTICE_H
