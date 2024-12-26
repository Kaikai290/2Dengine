#ifndef RENDERER_H
#define RENDERER_H

#include "../../include/glad/glad.h"
#include "../../include/GLFW/glfw3.h"

#include "../../include/glm/glm.hpp"
#include "../../include/glm/gtc/matrix_transform.hpp"
#include "../../include/glm/gtc/type_ptr.hpp"

#include "shader_manager.h"
#include "sprite_manager.h"
#include "vertex_array.h"

class Renderer{
public:
  ShaderManager ShaderProgram;
  VertexArray VAO;
  SpriteManager Texture;

public:
  Renderer();

  void RendererInit();
  void BindVAO();
  void UnbindVAO();
  void BindShader();
  void LoadSprite(const char* sprit);
  void UseSprite();

  void SetMatrix4(const char* UniformName, glm::mat4 UniformData);

  void SetVector4(const char* UniformName, glm::vec4 UniformData);


  unsigned int GetShaderID(); 
  VertexArray GetVAO();
};

#endif
