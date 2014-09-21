/*
 * Vector.h
 *
 *  Created on: 18/09/2014
 *      Author: mathe_000
 */

#ifndef VECTOR_H_
#define VECTOR_H_

class Vector4 {
public:
	float x;
	float y;
	float z;
	float w;

	Vector4( float x, float y, float z, float w ):
		x(x), y(y), z(z), w(w) {}
};

#endif /* VECTOR_H_ */
