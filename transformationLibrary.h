#ifndef TRANSFORMATIONLIBRARY_H
#define TRANSFORMATIONLIBRARY_H
#include "matriz4.h"
#include "objeto.h"

Matriz4* loadIdentity (void);
Matriz4* transfTranslate (double ,double, double, vector<Objeto>*);
Matriz4* transfTranslate(double, double, double, vector<Objeto>*, Matriz4);

Matriz4* transfRotate(double , int, int, int, vector<Objeto>*);
Matriz4* transfRotate(double, int, int, int, vector<Objeto>*, Matriz4);

Matriz4* transfScale(double , double, double, vector<Objeto>*);
Matriz4* transfScale(double, double, double, vector<Objeto>*, Matriz4);

//Matriz4* transfShear(double , int, int, int, Objeto);
//Matriz4* transfShear(double, int, int, int,Objeto,Matriz4);

void aplicar_transformacao(Matriz4 matriz, vector<Objeto> *objetos);

#endif // TRANSFORMATIONLIBRARY_H
