#ifndef OBJETO_H
#define OBJETO_H

#include "face.h"
#include "vertice.h"

#include <vector>

class Objeto
{
public:
  Objeto();
  Vertice centro;
  //void calcular_centro(vector<Face> *faces);
};

#endif // OBJETO_H
