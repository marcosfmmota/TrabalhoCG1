#include "matriz4.h"

Matriz4::Matriz4 () {
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

Matriz4::Matriz4 ( const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d )
{ m[0] = a;  m[1] = b;  m[2] = c;  m[3] = d; }

Matriz4::Matriz4( const double d)  //Matriz diagonal
{ m[0].x = d;  m[1].y = d;  m[2].z = d;  m[3].w = d; }

Matriz4::Matriz4( double m00, double m10, double m20, double m30,
         double m01, double m11, double m21, double m31,
         double m02, double m12, double m22, double m32,
         double m03, double m13, double m23, double m33 )
{
    m[0] = Vector4( m00, m10, m20, m30 );
    m[1] = Vector4( m01, m11, m21, m31 );
    m[2] = Vector4( m02, m12, m22, m32 );
    m[3] = Vector4( m03, m13, m23, m33 );
}

void Matriz4::setMatriz(double m00, double m10, double m20, double m30,
                        double m01, double m11, double m21, double m31,
                        double m02, double m12, double m22, double m32,
                        double m03, double m13, double m23, double m33 )
{
   m[0] = Vector4( m00, m10, m20, m30 );
   m[1] = Vector4( m01, m11, m21, m31 );
   m[2] = Vector4( m02, m12, m22, m32 );
   m[3] = Vector4( m03, m13, m23, m33 );
}

Vector4 Matriz4::mult(Vector4 vetor) {
  double x = ((m[0].x*vetor.x)+(m[0].y*vetor.y)+(m[0].z*vetor.z)+(m[0].w*vetor.w));
  double y = ((m[1].x*vetor.x)+(m[1].y*vetor.y)+(m[1].z*vetor.z)+(m[1].w*vetor.w));
  double z = ((m[2].x*vetor.x)+(m[2].y*vetor.y)+(m[2].z*vetor.z)+(m[2].w*vetor.w));
  double w = ((m[3].x*vetor.x)+(m[3].y*vetor.y)+(m[3].z*vetor.z)+(m[3].w*vetor.w));
  return Vector4(x,y,z,w);
}
