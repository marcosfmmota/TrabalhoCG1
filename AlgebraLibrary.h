#ifndef ALGEBRALIBRARY_H
#define ALGEBRALIBRARY_H

#include<GL/gl.h>

namespace AlgebraLibrary {
    //Definição dos vetores de tamanho 3 e 4
    class Vector3
    {
    private:
        GLfloat x;
        GLfloat y;
        GLfloat w;
    };

    class Vector4
    {
    private :
        GLfloat x;
        GLfloat y;
        GLfloat w;
        GLfloat z;

    };

    //Definição das matrizes 4x4 e 3x3
    class Matrix3
    {
    private:
        Vector3 n[3];
    };

    class Matrix4
    {
    private:
        Vector4 n[4];
    };

}
#endif // ALGEBRALIBRARY_H
