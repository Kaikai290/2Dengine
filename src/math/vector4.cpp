#include "vector4.h"

void Vector4::Print() const{
  std::cout << X << ", "<< Y << ", "<< Z << ", "<< W << std::endl;
}
Vector4 Vector4::operator+(const Vector4& Y) const{
  return Vector4(this->X + Y.X, this->Y + Y.Y, this->Z + Y.Z, this->W + Y.W);
}

Vector4 Vector4::operator-(const Vector4& Y) const{
  return Vector4(this->X - Y.X, this->Y - Y.Y, this->Z - Y.Z, this->W - Y.W);
}

Vector4 Vector4::operator*(const float& Scalor) const{
  return Vector4(this->X * Scalor, this->Y * Scalor, this->Z * Scalor, this->W * Scalor);
}

Vector4 Vector4::operator/(const float& Scalor) const{
  return Vector4(this->X / Scalor, this->Y / Scalor, this->Z / Scalor, this->W / Scalor);
}


