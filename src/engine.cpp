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
  #if DEBUG
    std::cout << "GLFW window successfully Initialized" << std::endl;
  #endif
  return;
}

void Engine::RendererInit() { 
  game_renderer.RendererInit();
  #if DEBUG
    std::cout << "Renderers successfully Initialized" << std::endl;
  #endif
  return;
}

void Engine::EntityInit() {
  game_entity.ApplyRenderer(&game_renderer);
  game_entity.LoadSprite("C:/Users/kaiwi/OneDrive/Desktop/Photos/char.jpg");
  #if DEBUG
    std::cout << "Entitys successfully Initialized" << std::endl;
  #endif
}

void Engine::WorldInit() {
  //Level.Init(&GameRenderer);
}

void Engine::Output(int Key) {
  if (Key == GLFW_KEY_W) {
    this->game_entity.Position.y += 10;
  }
  if (Key == GLFW_KEY_S) {
    this->game_entity.Position.y -= 10;
  }
  if (Key == GLFW_KEY_A) {
    this->game_entity.Position.x -= 10;
  }
  if (Key == GLFW_KEY_D) {
    this->game_entity.Position.x += 10;
  }
}

void Engine::Render() {
  game_entity.Render();
}

void Engine::RunEngine() {
  while (!glfwWindowShouldClose(Window)) {

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Render();

    glfwSwapBuffers(Window);
    glfwPollEvents();
  }
}
