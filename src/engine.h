#ifndef ENGINE_H
#define ENGINE_H

#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"

#include <iostream>

#include "shader_manager.h"
#include "vertex_array.h"
#include "renderer.h"

class Engine{
public:
  GLFWwindow* Window;
  Renderer GameRenderer;

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
