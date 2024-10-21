#include "engine.h"

#include "vertex_array.h"
#include "vertex_buffer.h"
#include "index_buffer.h"
#include "callback_function.h"

Engine::Engine(){
  WindowInit();
  ShaderInit();
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

void Engine::ShaderInit(){
  // build and compile our shader program
  ShaderProgram.CreateShader();


  unsigned int id = 1;
  class VertexArray temp(id);
  VertexArray = temp;

}

void Engine::Output(int Key){
  std::cout << Key << std::endl;
}

void Engine::RunEngine()
{
  while (!glfwWindowShouldClose(Window)){
    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(ShaderProgram.ShaderProgram);
    VertexArray.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    VertexArray.Unbind();
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(Window);
    glfwPollEvents();  }
}
