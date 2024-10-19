#ifndef ENGINE
#define ENGINE

#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"

#include <iostream>

#include "shader_manager.h"

class Engine{
public:
  GLFWwindow* Window;
  unsigned int VBO, VAO, EBO;
  ShaderManager ShaderProgram;

public:
  Engine();
  void RunEngine();
  void Output(int Key);

private:
  void WindowInit();
  void ShaderInit();
};
#endif
