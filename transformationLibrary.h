#ifndef TRANSFORMATIONLIBRARY_H
#define TRANSFORMATIONLIBRARY_H
#include "matriz4.h"

Matriz4* loadIdentity (void);
Matriz4* transfTranslate (double ,double, double, Objeto);
Matriz4* transfTranslate(double, double, double,Objeto, Matriz4);

Matriz4* transfRotate(double , int, int, int, Objeto);
Matriz4* transfRotate(double, int, int, int, Objeto, Matriz4);

Matriz4* transfScale(double , double, double, Objeto);
Matriz4* transfScale(double, double, double, Objeto, Matriz4);

//Matriz4* transfShear(double , int, int, int, Objeto);
//Matriz4* transfShear(double, int, int, int,Objeto,Matriz4);

#endif // TRANSFORMATIONLIBRARY_H
