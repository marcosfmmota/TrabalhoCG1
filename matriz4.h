/*
 * Matriz4.h
 *
 *  Created on: 18/09/2014
 *      Author: mathe_000
 */

#ifndef MATRIZ4_H_
#define MATRIZ4_H_

#include "vector4.h"

class Matriz4 {
public:
    Vector4 m[4];
    //Construtores
    //identidade
    Matriz4 () {
        for(int i = 0; i<4; ++i) {
            if(i == 0)
                m[i] = Vector4(1,0,0,0);
            if(i == 1)
                m[i] = Vector4(0,1,0,0);
            if(i == 2)
                m[i] = Vector4(0,0,1,0);
            if (i == 3)
                m[i] = Vector4(0,0,0,1);
        }
    }

    Matriz4 ( const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d )
    { m[0] = a;  m[1] = b;  m[2] = c;  m[3] = d; }

    Matriz4( const double d)  //Matriz diagonal
    { m[0].x = d;  m[1].y = d;  m[2].z = d;  m[3].w = d; }

    Matriz4( double m00, double m10, double m20, double m30,
             double m01, double m11, double m21, double m31,
             double m02, double m12, double m22, double m32,
             double m03, double m13, double m23, double m33 )
    {
        m[0] = Vector4( m00, m10, m20, m30 );
        m[1] = Vector4( m01, m11, m21, m31 );
        m[2] = Vector4( m02, m12, m22, m32 );
        m[3] = Vector4( m03, m13, m23, m33 );
    }

    //Sobrecarga dos principais operadores de matrizes
    //Subtração de matrizes

    Matriz4 operator - ( const Matriz4& mat ) const
    { return Matriz4( m[0]-mat[0], m[1]-mat[1], m[2]-mat[2], m[3]-mat[3] ); }

    //Multiplicação por escalar

    Matriz4 operator * ( const double s ) const
    { return Matriz4( s*m[0], s*m[1], s*m[2], s*m[3] ); }

    //Operação com matrizes
    Matriz4 operator + (const Matriz4& mat)
    {
        Matriz4 temp;
        temp.m[0]=m[0] + mat.m[0];
        temp.m[1]=m[1] +mat.m[1];
        temp.m[2]=m[2]+mat.m[2];
        temp.m[3]=m[3]+mat.m[3];
        return temp;
    }

    Vector4& operator [] ( int i ) { return m[i]; }
    const Vector4& operator [] ( int i ) const { return m[i]; }

    friend Matriz4 operator * ( const double s, const Matriz4& m )
    { return m * s; }

    //multiplicação matriz4 com matriz4
    Matriz4 operator * ( const Matriz4& m ) const {
        Matriz4  a(0.0);

        for ( int i = 0; i < 4; ++i ) {
            for ( int j = 0; j < 4; ++j ) {
                for ( int k = 0; k < 4; ++k ) {
                    a[i][j] += m[i][k] * m[k][j];
                }
            }
        }
        return a;
    }

    //multiplicação matriz com vector4
    Matriz4 operator *(const Vector4& v) const
    {
        Vector4 result;
        for (int i=0; i<4;++i)
        {
            double aux;
            Vector4 aux2;
            aux2=m[i]*v;
            aux=aux2.x+aux2.y+aux2.z+aux2.w;
            //aviso: o código abaixo é intensionalmente
            //ruim, mas o tempo não permite que eu faça
            //melhor
            if (i==0)
            {
                result.x=aux;
            }
            else if (i==1)
            {
                result.y=aux;
            }
            else if (i==2)
            {
                result.z=aux;
            }
            else
            {
                result.w=aux;
            }
        }
        return result;
    }

    //Sobrecarga do operador =
    Matriz4& operator= (const Matriz4& param)
    {
        m[0]=param.m[0];
        m[1]=param.m[1];
        m[2]=param.m[2];
        m[3]=param.m[3];
        return *this;
    }

    //Transpor Matriz
    Matriz4 transposta( const Matriz4& A ) {
        return Matriz4( A[0][0], A[1][0], A[2][0], A[3][0],
                A[0][1], A[1][1], A[2][1], A[3][1],
                A[0][2], A[1][2], A[2][2], A[3][2],
                A[0][3], A[1][3], A[2][3], A[3][3] );
    }
};

#endif /* MATRIZ4_H_ */
