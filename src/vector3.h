#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3{
public:
  float X;
  float Y;
  float Z;

public:
  Vector3()
    :X(0.0f), Y(0.0f), Z(0.0f) {}
  Vector3(float x, float y, float z)
    :X(x), Y(y), Z(z) {}
};

#endif
