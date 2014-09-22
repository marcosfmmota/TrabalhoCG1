#include<iostream>
#include "transformationLibrary.h"
#include "matriz4.h"
#include <math.h>
#include <vector>
Matriz4* loadIdentity(void)
{
    Matriz4 tmatrix;
    return &tmatrix;
}

Matriz4* transfTranslate(double x, double y, double z, Objeto obj)
{
    Matriz4 *tmatrix=loadIdentity();
    Vector4 trans (x , y , z , 1);
    tmatrix->m[3]=trans;
    vector<Vector4> vec;
    /* Implemente a multiplicação nos objetos aqui:*/
//    for (int i=0; i<obj.faces.size();++i)
//    {
//        Vector4 aux;
//        aux=obj.vertices.at(i);
//        vec.insert(i,aux);
//    }
//    for(int i=0; i<obj.vertices.size();++i)
//    {
//        Vector4 aux;
//        aux=tmatrix->m * vec.at(i);
//        obj.vertices.insert(i,aux.transformarEmVertice());
//    }
//    obj.calcular_centro();
    return tmatrix;
}

Matriz4* transfTranslate(double x, double y, double z, Objeto obj, Matriz4 m)
{
    Matriz4 translateMatrix;
    Vector4 trans (x , y , z , 1);
    translateMatrix.m[3]=trans;
    m = m*translateMatrix;

    //A Matriz m vai ter a matriz de translação então é só
    //multiplicar as faces do Objeto por m;

    /* Implemente a multiplicação nos objetos aqui:*/

    return &m;
}

Matriz4* transfRotate(double angulo, int x, int y, int z, Objeto obj)
{
    double rads=angulo*(180/M_PI);
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

    return &m;
}

Matriz4* transfRotate(double angulo, int x, int y, int z, Objeto obj, Matriz4 m)
{
    double rads=angulo*(180/M_PI);
    Matriz4 rot;
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

    return &m;
}

Matriz4* transfScale(double x, double y, double z, Objeto obj)
{
    Matriz4 scale(x,0,0,0,
                  0,y,0,0,
                  0,0,z,0,
                  0,0,0,1
                  );
    /* Implemente a multiplicação nos objetos aqui:*/

    return &scale;
}

Matriz4* transfScale(double x, double y, double z, Objeto obj, Matriz4 m)
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

    return &m;
}
