#include "renderer.h"
#include "shader_manager.h"
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

void Renderer::BindShader(){
  ShaderProgram.UseShader();
}

void Renderer::SetMatrix4(const char* UniformName, glm::mat4 UniformData){
  glUniformMatrix4fv(glGetUniformLocation(this->GetShaderID(), UniformName), 1, GL_FALSE, (const GLfloat *)glm::value_ptr(UniformData));
}

void Renderer::SetVector4(const char* UniformName, glm::vec4 UniformData){
  glUniform4f(glGetUniformLocation(this->GetShaderID(), UniformName), UniformData.x, UniformData.y, UniformData.z, UniformData.w);
}

VertexArray Renderer::GetVAO()  {return VAO.Index;}

unsigned int Renderer::GetShaderID() {return ShaderProgram.ShaderProgram;}
