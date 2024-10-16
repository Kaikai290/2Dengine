#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"

#include <iostream>

class ShaderManager{
public:
  unsigned int ShaderProgram;
public:
  ShaderManager();

  void CreateShader();
};

#endif // !SHADER_MANAGER_H

