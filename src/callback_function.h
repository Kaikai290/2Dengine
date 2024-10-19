#ifndef CALLBACK_FUNCTION_H
#define CALLBACK_FUNCTION_H

#include "engine.h"

class CallbackFunction{
public:
  Engine& mEngine;

public:
  CallbackFunction(Engine& Engine);

  static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif
