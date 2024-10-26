#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H 

class VertexBuffer{
public:
  unsigned int RendererID;

public:
  VertexBuffer(const void* data, unsigned int size);
  ~VertexBuffer();

  void Bind();
  void Unbind();
};

#endif // !VERTEX_BUFFER_H

