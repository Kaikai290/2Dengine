#include "engine.h"

#include "callback_function.h"
#include "math/vector4.h"

Engine::Engine(){
  WindowInit();
  RendererInit();
  EntityInit();
}



void Engine::WindowInit()
{
  Window = glfwCreateWindow(Height, Width, "Engine", NULL, NULL);
  glfwMakeContextCurrent(Window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
  }
  CallbackFunction Input(*this); 
  glfwSetWindowUserPointer (Window, &Input);
}

void Engine::RendererInit(){
  GameRenderer.RendererInit(); 
}

void Engine::Output(int Key){
  std::cout << Key << std::endl;
}

void Engine::EntityInit(){
  Entity Temp(&GameRenderer);

  GameEntity = Temp;
}

void Engine::RunEngine()
{
  while (!glfwWindowShouldClose(Window)){

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    GameEntity.Render();

    glfwSwapBuffers(Window);
    glfwPollEvents();  }
}
