#include "engine.h"

#include "callback_function.h"
#include "entity.h"
#include "math/vector4.h"

Engine::Engine() {
  WindowInit();
  RendererInit();
  EntityInit();
  WorldInit();
}

void Engine::WindowInit() {
  Window = glfwCreateWindow(Width, Height, "Engine", NULL, NULL);
  glfwMakeContextCurrent(Window);
if (Window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
    }
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
  }
}

void Engine::RendererInit() { 
  GameRenderer.RendererInit();
}

void Engine::EntityInit() {
  GameEntity.ApplyRenderer(&GameRenderer);
  GameEntity.LoadSprite("C:/Users/kaiwi/OneDrive/Desktop/Photos/char.jpg");
}

void Engine::WorldInit() {
  Level.Init(&GameRenderer);
}

void Engine::Output(int Key) {
  std::cout << Key << std::endl;
  if (Key == GLFW_KEY_W) {
    this->GameEntity.Position.y += 10;
  }
  if (Key == GLFW_KEY_S) {
    this->GameEntity.Position.y -= 10;
  }
  if (Key == GLFW_KEY_A) {
    this->GameEntity.Position.x -= 10;
  }
  if (Key == GLFW_KEY_D) {
    this->GameEntity.Position.x += 10;
  }
}

void Engine::RunEngine() {
  while (!glfwWindowShouldClose(Window)) {

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Level.RenderWorld();
    GameEntity.Render();

    glfwSwapBuffers(Window);
    glfwPollEvents();
  }
}
