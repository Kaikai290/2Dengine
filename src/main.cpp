#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"

#include <iostream>

#include "callback_function.h"
#include "engine.h"

void RunEngine();

int main(void)
{
#ifdef DEBUG
  std::cout << "Debug mode" << std::endl;
#endif

  glfwInit(); //Todo: Make sure to check if these are succesful!!!!
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Todo: Check what these flags do

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  RunEngine();

  glfwTerminate();
  return 0;
}

void RunEngine(){

  Engine Engine;   
  glViewport(0, 0, Engine.Width, Engine.Height);

  CallbackFunction Input(Engine);
  glfwSetWindowUserPointer(Engine.Window, &Input);
  Engine.RunEngine();
}
