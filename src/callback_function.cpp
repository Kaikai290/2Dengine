#include "callback_function.h"

CallbackFunction::CallbackFunction(Engine& Engine)
  : mEngine(Engine)
{
  glfwSetKeyCallback(Engine.Window, key_callback);
}

 void CallbackFunction::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods){
  CallbackFunction* state = (CallbackFunction *)glfwGetWindowUserPointer(window);
  state->mEngine.Output(key);
  //state->mEngine.Inputs();
}
