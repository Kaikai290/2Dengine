#ifndef VECTOR4_H
#define VECTOR4_H

#include <iostream>

class Vector4{
public:
  union{
    struct{
      float X, Y, Z, W;
    };
    struct{
      float Array[4];
    };
  };

public:
  Vector4()
    :X(0.0f), Y(0.0f), Z(0.0f), W(0.0f) {}
  Vector4(float x, float y, float z, float w)
    :X(x), Y(y), Z(z), W(w) {}
  Vector4(float x)
    :X(x), Y(x), Z(x), W(x) {}

  void Print() const;

  Vector4 operator+(const Vector4& Y) const;
  Vector4 operator-(const Vector4& Y) const;
  Vector4 operator*(const float& Scalor) const;
  Vector4 operator/(const float& Scalor) const;
};

#endif
