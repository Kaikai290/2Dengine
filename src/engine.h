#ifndef ENGINE_H
#define ENGINE_H

#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"

#include <iostream>

#include "shader_manager.h"
#include "vertex_array.h"

class Engine{
public:
  GLFWwindow* Window;
  ShaderManager ShaderProgram;
  VertexArray VertexArray;

public:
  Engine();
  void RunEngine();
  void Output(int Key);

private:
  void WindowInit();
  void ShaderInit();
};
#endif
