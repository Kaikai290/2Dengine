#include "engine.h"

#include "callback_function.h"

Engine::Engine(){
  WindowInit();
  RendererInit();
}

void Engine::WindowInit()
{
  Window = glfwCreateWindow(640, 480, "Engine", NULL, NULL);
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

void Engine::RunEngine()
{
  while (!glfwWindowShouldClose(Window)){

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    GameRenderer.ShaderProgram.UseShader();
    GameRenderer.BindVAO();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    GameRenderer.UnbindVAO();

    glfwSwapBuffers(Window);
    glfwPollEvents();  }
}
