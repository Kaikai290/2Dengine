#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "vertex_buffer.h"
#include "index_buffer.h"

class VertexArray{
public:
  unsigned int VAO;
  unsigned int Index;

public:
  VertexArray() {}
  VertexArray(unsigned int Index);

  void Bind();
  void Unbind();

private:
  void VertexArrayInit();
};
#endif
