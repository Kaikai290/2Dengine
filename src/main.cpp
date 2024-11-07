#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"

#include <iostream>

#include "callback_function.h"
#include "engine.h"

void RunEngine();

int main(void)
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif


  /* Loop until the user closes the window */
  RunEngine();

  glfwTerminate();
  return 0;
}

void RunEngine(){

  Engine cEngine;   
  glViewport(0, 0, cEngine.Width, cEngine.Height);

  CallbackFunction Input(cEngine);
  glfwSetWindowUserPointer(cEngine.Window, &Input);
  cEngine.RunEngine();
}
