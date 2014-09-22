/*
 * Vector.h
 *
 *  Created on: 18/09/2014
 *      Author: mathe_000
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#include"vertice.h"

class Vector4 {
public:
    double x;
    double y;
    double z;
    double w;
    Vector4 ()
    {
        x=0;
        y=0;
        z=0;
        w=0;
    }

    Vector4( double x, double y, double z, double w ):
		x(x), y(y), z(z), w(w) {}

    //Sobrecarga dos principais operadores
    Vector4 operator + (const Vector4& vec) const //sobrecarga do operador + para somar dois vetores
    {
        return Vector4(x+vec.x,y+vec.y,z+vec.z,w+vec.w);
    }

    Vector4 operator - (const Vector4& vec) const
    {
        return Vector4(x-vec.x,y-vec.y,z-vec.z,w-vec.w);
    }

    //sobrecarga de operadores de indexação
    double& operator [] ( int i ) { return *(&x + i); }
    const double operator [] ( int i ) const { return *(&x + i); }
    //multiplicação por escalar
    Vector4 operator * ( const double s ) const
        { return Vector4( s*x, s*y, s*z, s*w ); }

    friend Vector4 operator * ( const double s, const Vector4& v )
        { return v * s; }
    //multiplicação vetor por vetor
    Vector4 operator * ( const Vector4& v ) const
        { return vec4( x*v.x, y*v.y, z*v.z, w*v.z ); }

    //sobrecarga do operador = para copiar valores
    Vector4& operator =(const Vector4& v)
    {
        x=v.x;
        y=v.y;
        z=v.z;
        w=v.w;
        return *this;
    }

    //sobrecarga do operador = para copiar valores de vertice em um vector4
    Vector4& operator =(const Vertice& vet)
    {
        x=vet.coord[1];
        y=vet.coord[2];
        z=vet.coord[3];
        w=1;
        return *this;
    }

    Vertice transformarEmVertice ()
    {
        Vertice vert(x,y,z);
        return vert;
    }
};

#endif /* VECTOR_H_ */
