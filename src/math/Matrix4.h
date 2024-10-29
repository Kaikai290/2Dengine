#ifndef MATRIX4_H
#define MATRIX4_H

class Matrix4{
public:
  union{
    struct{
      float X1, X2, X3, X4;
      float Y1, Y2, Y3, Y4;
      float Z1, Z2, Z3, Z4;
      float W1, W2, W3, W4;
    };
    struct{
      float Array[16];
    };
  };

public:
  Matrix4();
  Matrix4(float Det);
  Matrix4(float Other[16]);
  Matrix4(float X1, float X2, float X3, float X4,
          float Y1,float  Y2, float Y3, float Y4,
          float Z1, float Z2, float Z3, float Z4,
          float W1, float W2, float W3, float W4);

  Matrix4 Add(Matrix4 Other);
  Matrix4 Subtract(Matrix4 Other);
};

#endif
