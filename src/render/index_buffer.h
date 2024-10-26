#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

class IndexBuffer{
public:
  unsigned int RendererID;
  unsigned int Count;

public:
  IndexBuffer(const unsigned int* data, unsigned int count);
  ~IndexBuffer();

  void Bind();
  void Unbind();
};

#endif 

