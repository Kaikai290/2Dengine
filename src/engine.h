#ifndef ENGINE_H
#define ENGINE_H

#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"

#include <iostream>

#include "render/shader_manager.h"
#include "render/vertex_array.h"
#include "render/renderer.h"
#include "memory.h"

class Engine{
public:
  GLFWwindow* Window;
  Renderer GameRenderer;
  Memory test; 

public:
  Engine();
  void RunEngine();
  void Output(int Key);

private:
  void WindowInit();
  void ShaderInit();
  void RendererInit();
};

#endif
