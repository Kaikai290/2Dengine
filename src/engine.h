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
#include "world.h"

class Engine{
public:
  GLFWwindow* Window;
  unsigned int Height = 480;
  unsigned int Width = 640;
  Renderer game_renderer;
  Memory test; 
  glm::mat4 model = glm::mat4(1.0f);
  World Level;

  Entity game_entity;

public:
  Engine();
  void RunEngine();
  void Output(int Key);
  void InputInit(Engine p_Engine); // Delete this function

private:
  void WindowInit();
  void RendererInit();
  void EntityInit();
  void WorldInit();
  void Render();
};

#endif
