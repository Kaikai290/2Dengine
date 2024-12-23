#include "index_buffer.h"
#include "../engine.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
    : Count(count)
{
  glGenBuffers(1, &RendererID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, RendererID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
  glDeleteBuffers(1, &RendererID);
}

void IndexBuffer::Bind()
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, RendererID);
}

void IndexBuffer::Unbind()
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
