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

	Matriz4( float m00, float m10, float m20, float m30,
		  float m01, float m11, float m21, float m31,
		  float m02, float m12, float m22, float m32,
		  float m03, float m13, float m23, float m33 )
		{
		    m[0] = Vector4( m00, m10, m20, m30 );
		    m[1] = Vector4( m01, m11, m21, m31 );
		    m[2] = Vector4( m02, m12, m22, m32 );
		    m[3] = Vector4( m03, m13, m23, m33 );
		}

	Matriz4 operator + (const Matriz4& m) const 
	{

	}
	Matriz4 operator * ( const Matriz4& m ) const {
		Matriz4  a();

		for ( int i = 0; i < 4; ++i ) {
			for ( int j = 0; j < 4; ++j ) {
				for ( int k = 0; k < 4; ++k ) {
					a[i][j] += m[i][k] * m[k][j];
				}
			}
		}

		return a;
	}

		Matriz4 transposta( const Matriz4& A ) {
		    return Matriz4( A[0][0], A[1][0], A[2][0], A[3][0],
				 A[0][1], A[1][1], A[2][1], A[3][1],
				 A[0][2], A[1][2], A[2][2], A[3][2],
				 A[0][3], A[1][3], A[2][3], A[3][3] );
		}
};

#endif /* MATRIZ4_H_ */
