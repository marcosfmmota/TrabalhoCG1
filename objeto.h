#ifndef OBJETO_H
#define OBJETO_H

#include "face.h"
#include "vertice.h"

#include <vector>

using namespace std;

class Objeto
{
public:
  Objeto();
  Vertice centro;
  vector<Vertice> vertices;
  vector<Face> faces;
  void calcular_centro();
};

#endif // OBJETO_H
