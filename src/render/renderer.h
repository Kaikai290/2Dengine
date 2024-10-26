#ifndef RENDERER_H
#define RENDERER_H

#include "shader_manager.h"
#include "vertex_array.h"

class Renderer{
public:
  ShaderManager ShaderProgram;
  VertexArray VAO;
public:
  Renderer();

  void RendererInit();
  void BindVAO();
  void UnbindVAO();

  VertexArray GetVAO();
};

#endif
