#include "vector3.h"

Vector3 operator+(const Vector3 X, const Vector3 Y){
  return Vector3(X.X + Y.X, X.Y + Y.Y, X.Z + Y.Z);
}
