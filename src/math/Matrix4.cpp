#include "Matrix4.h"

Matrix4::Matrix4(){
  X1 = X2 = X3 = X4 = 0;
  Y1 = Y2 = Y3 = Y4 = 0;
  Z1 = Z2 = Z3 = Z4 = 0;
  W1 = W2 = W3 = W4 = 0;
}
Matrix4::Matrix4(float Det){
  X1 = Y2 = Z3 = W4 = Det;
  X2 = X3 = X4 = 0.0f;
  Y1 = Y3 = Y4 = 0.0f;
  Z1 = Z2 = Z4 = 0.0f;
  W1 = W2 = W3 = 0.0f;
}

Matrix4::Matrix4(float Other[16]){
  X1 = Other[0];
  X2 = Other[1];
  X3 = Other[2];
  X4 = Other[3];
  Y1 = Other[4];
  Y2 = Other[5];
  Y3 = Other[6];
  Y4 = Other[7];
  Z1 = Other[8];
  Z2 = Other[9];
  Z3 = Other[10];
  Z4 = Other[11];
  W1 = Other[12];
  W2 = Other[13];
  W3 = Other[14];
  W4 = Other[15];
}

Matrix4::Matrix4(float x1, float x2, float x3, float x4,
                 float y1,float  y2, float y3, float y4,
                 float z1, float z2, float z3, float z4,
                 float w1, float w2, float w3, float w4){
  X1 = x1;
  X2 = x2;
  X3 = x3;
  X4 = x4;
  Y1 = y1;
  Y2 = y2;
  Y3 = y3;
  Y4 = y4;
  Z1 = z1;
  Z2 = z2;
  Z3 = z3;
  Z4 = z4;
  W1 = w1;
  W2 = w2;
  W3 = w3;
  W4 = w4;
}



Matrix4 Matrix4::Add(Matrix4 Other){
  return Matrix4(X1 + Other.X1, X2 + Other.X2, X3 + Other.X3, X4 + Other.X4,
                 Y1 + Other.Y1, Y2 + Other.Y2, Y3 + Other.Y3, Y4 + Other.Y4,
                 Z1 + Other.Z1, Z2 + Other.Z2, Z3 + Other.Z3, Z4 + Other.Z4,
                 W1 + Other.W1, W2 + Other.W2, W3 + Other.W3, W4 + Other.W4);
}

Matrix4 Matrix4::Subtract(Matrix4 Other){
  return Matrix4(X1 - Other.X1, X2 - Other.X2, X3 - Other.X3, X4 - Other.X4,
                 Y1 - Other.Y1, Y2 - Other.Y2, Y3 - Other.Y3, Y4 - Other.Y4,
                 Z1 - Other.Z1, Z2 - Other.Z2, Z3 - Other.Z3, Z4 - Other.Z4,
                 W1 - Other.W1, W2 - Other.W2, W3 - Other.W3, W4 - Other.W4);
}
