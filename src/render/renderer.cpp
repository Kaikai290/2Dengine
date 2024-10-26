#include "renderer.h"
#include "vertex_array.h"

Renderer::Renderer(){
}

void Renderer::RendererInit(){
  ShaderProgram.CreateShader();

  unsigned int id = 1;
  class VertexArray temp(id);
  VAO = temp;
}

void Renderer::BindVAO(){
  VAO.Bind();
}

void Renderer::UnbindVAO(){
  VAO.Unbind();
}

VertexArray Renderer::GetVAO()  {return VAO.Index;}
