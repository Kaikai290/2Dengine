#ifndef ENTITY_H
#define ENTITY_H

#include "iostream"

#include "../include/glm/glm.hpp"
#include "../include/glm/gtc/matrix_transform.hpp"
#include "../include/glm/gtc/type_ptr.hpp"

#include "math/vector3.h"
#include "render/renderer.h"
#include "render/sprite_manager.h"

class Entity{
public:
  std::string name;

  glm::vec3 Position;
  glm::vec3 Velocity;
  glm::vec4 Colour = glm::vec4(0.2f, 0.6f, 0.1f, 0.1f);

  glm::vec3 Size = glm::vec3(40.0f * 4.f, 40.0f*4.f, 1.0f);
  Renderer* EntityRenderer = nullptr;
  SpriteManager Texture;

public:
  Entity();
  Entity(std::string Name);

  void LoadSprite(const char* FilePath);
  void ApplyRenderer(Renderer* Renderer);
  void Render();
  void InitCheck();
}; 
#endif
