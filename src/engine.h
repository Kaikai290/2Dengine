#ifndef ENGINE_H
#define ENGINE_H

#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"

#include "../include/glm/glm.hpp"
#include "../include/glm/gtc/matrix_transform.hpp"
#include "../include/glm/gtc/type_ptr.hpp"

#include <iostream>

#include "entity.h"
#include "render/shader_manager.h"
#include "render/vertex_array.h"
#include "render/renderer.h"
#include "memory.h"

class Engine{
public:
  GLFWwindow* Window;
  unsigned int Height = 640;
  unsigned int Width = 480;
  Renderer GameRenderer;
  Memory test; 
  Entity GameEntity;
  glm::mat4 model = glm::mat4(1.0f);

public:
  Engine();
  void RunEngine();
  void Output(int Key);

private:
  void WindowInit();
  void RendererInit();
  void EntityInit();
};

#endif
