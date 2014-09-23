#include "objeto.h"

Objeto::Objeto()
{
}

Vertice Objeto::calcular_centro()
{
  float x,y,z;
  x = y = z = 0;
  for (int i = 0; i < vertices.size(); i++) {
      x += vertices.at(i).coord[0];
      y += vertices.at(i).coord[1];
      z += vertices.at(i).coord[2];
  }
  x = x/vertices.size();
  y = y/vertices.size();
  z = z/vertices.size();

  centro.coord[0] = x;
  centro.coord[1] = y;
  centro.coord[2] = z;

  return centro;
}
