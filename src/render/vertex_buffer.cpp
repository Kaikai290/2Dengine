#include "vertex_buffer.h"
#include "../engine.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
  glGenBuffers(1, &RendererID);
  glBindBuffer(GL_ARRAY_BUFFER, RendererID);
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
  glDeleteBuffers(1, &RendererID);
}

void VertexBuffer::Bind()
{
  glBindBuffer(GL_ARRAY_BUFFER, RendererID);
}

void VertexBuffer::Unbind()
{
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}
