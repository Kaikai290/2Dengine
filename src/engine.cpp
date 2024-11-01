#include "engine.h"

#include "callback_function.h"
#include "entity.h"
#include "math/vector4.h"

Engine::Engine() {
  WindowInit();
  RendererInit();
  EntityInit();
  Level = World(&GameRenderer, Height, Width);
}

void Engine::WindowInit() {
  Window = glfwCreateWindow(Height, Width, "Engine", NULL, NULL);
  glfwMakeContextCurrent(Window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
  }
  //CallbackFunction Input(*this);
  //glfwSetWindowUserPointer(Window, &Input);
}

void Engine::InputInit(Engine p_Engine){
  CallbackFunction Input(p_Engine);
  glfwSetWindowUserPointer(Window, &Input);
}

void Engine::RendererInit() { GameRenderer.RendererInit(); }

void Engine::EntityInit() {
  Entity Temp(&GameRenderer);

  GameEntity = Temp;
}

void Engine::Output(int Key) { 
  std::cout << Key << std::endl;
  if (Key == GLFW_KEY_W){
    this->GameEntity.Position.y += 10;
  }
  if (Key == GLFW_KEY_S){
    this->GameEntity.Position.y -= 10;
  }
  if (Key == GLFW_KEY_A){
    this->GameEntity.Position.x -= 10;
  }
  if (Key == GLFW_KEY_D){
    this->GameEntity.Position.x += 10;
  }
}

void Engine::RunEngine() {
  while (!glfwWindowShouldClose(Window)) {

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glm::mat4 ortho = glm::ortho(0.0f, (float)Width, 0.0f, (float)Height, 0.1f, 100.0f);


    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f); //TODO(Kai): Figure out what to do with the height and widthglm::mat4 model = glm::mat4(1.0f);
    glm::mat4 model         = glm::mat4(1.0f); 
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f)); 
    GameEntity.Render();
    GameEntity.Render();
    glfwSwapBuffers(Window);
    glfwPollEvents();
  }
}
