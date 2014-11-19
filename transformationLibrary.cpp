#include<iostream>
#include "transformationLibrary.h"
#include "matriz4.h"
#include "objeto.h"
#include <math.h>

Matriz4* loadIdentity(void)
{
    Matriz4 tmatrix;
    return &tmatrix;
}

Matriz4* transfTranslate(double x, double y, double z, vector<Objeto> *obj)
{
    Matriz4 tmatrix;
    tmatrix.m[0].w=x;
    tmatrix.m[1].w=y;
    tmatrix.m[2].w=z;
    tmatrix.m[3].w=1;

    aplicar_transformacao(tmatrix, obj);

    return &tmatrix;
}

Matriz4* transfTranslate(double x, double y, double z, vector<Objeto> *obj, Matriz4 m)
{
  Matriz4 tmatrix;
  tmatrix.m[0].w=x;
  tmatrix.m[1].w=y;
  tmatrix.m[2].w=z;
  tmatrix.m[3].w=1;

  m = m*tmatrix;
  aplicar_transformacao(m, obj);

  return &m;
}

Matriz4* transfRotate(double angulo, int x, int y, int z, vector<Objeto> *obj)
{
    double rads=angulo*(M_PI/180);
    Matriz4 m;
    if (x ==1 && y== 0 && z==0)
    {
        Matriz4 rot(1,0,0,0,
            0,cos(rads),sin(rads),0,
            0,-sin(rads),cos(rads),0,
            0,0,0,1
            );
        m=rot;
    }
    else if(x==0 && y==1 && z==0)
    {
        Matriz4 rot(cos(rads),0,-sin(rads),0,
            0,1,0,0,
            sin(rads),0,cos(rads),0,
            0,0,0,1
            );
        m=rot;
    }
    else if(x==0 && y==0 && z==1)
    {
        Matriz4 rot(cos(rads),-sin(rads),0,0,
            sin(rads),cos(rads),0,0,
            0,0,1,0,
            0,0,0,1
            );
        m=rot;
    }
    else
    {
        std::cerr << "Erro na rotação, nenhum eixo especificado corretamente";
    }

    /* Implemente a multiplicação nos objetos aqui:*/
    aplicar_transformacao(m, obj);

    return &m;
}

Matriz4* transfRotate(double angulo, int x, int y, int z, vector<Objeto> *obj, Matriz4 m)
{
    double rads=angulo*(M_PI/180);

    if (x ==1 && y== 0 && z==0)
    {
        Matriz4 rot(1,0,0,0,
            0,cos(rads),sin(rads),0,
            0,-sin(rads),cos(rads),0,
            0,0,0,1
            );
        m=m*rot;

    }
    else if(x==0 && y==1 && z==0)
    {
        Matriz4 rot(cos(rads),0,-sin(rads),0,
            0,1,0,0,
            sin(rads),0,cos(rads),0,
            0,0,0,1
            );
        m=m*rot;
    }
    else if(x==0 && y==0 && z==1)
    {
        Matriz4 rot(cos(rads),-sin(rads),0,0,
            sin(rads),cos(rads),0,0,
            0,0,1,0,
            0,0,0,1
            );
        m=m*rot;
    }
    else
    {
        std::cerr << "Erro na rotação, nenhum eixo especificado corretamente";
    }

    //A Matriz m vai ter a matriz de rotação então é só
    //multiplicar as faces do Objeto por m;

    /* Implemente a multiplicação nos objetos aqui:*/
    aplicar_transformacao(m, obj);
    return &m;
}

Matriz4* transfScale(double x, double y, double z, vector<Objeto> *obj)
{
    Matriz4 scale(x,0,0,0,
                  0,y,0,0,
                  0,0,z,0,
                  0,0,0,1
                  );
    /* Implemente a multiplicação nos objetos aqui:*/
    aplicar_transformacao(scale, obj);
    return &scale;
}

Matriz4* transfScale(double x, double y, double z, vector<Objeto> *obj, Matriz4 m)
{
    Matriz4 scale(x,0,0,0,
                  0,y,0,0,
                  0,0,z,0,
                  0,0,0,1
                 );
    m=m*scale;
    //A Matriz m vai ter a matriz de escala então é só
    //multiplicar as faces do Objeto por m;

    /* Implemente a multiplicação nos objetos aqui:*/
    aplicar_transformacao(m, obj);
    return &m;
}

void aplicar_transformacao(Matriz4 matriz, vector<Objeto> *objetos) {
  for (int i = 0; i < objetos->size(); i++) {
    for (int j = 0; j < objetos->at(i).faces.size(); j++) {
      for (int k = 0; k < 3; k++) {
        Vertice v = objetos->at(i).faces.at(j).vertice[k];
        Vector4 v4(v.coord[0],v.coord[1],v.coord[2],1);

        v4 = matriz.mult(v4);

        objetos->at(i).faces.at(j).vertice[k].coord[0] = v4.x;
        objetos->at(i).faces.at(j).vertice[k].coord[1] = v4.y;
        objetos->at(i).faces.at(j).vertice[k].coord[2] = v4.z;
      }
    }
  }
}
