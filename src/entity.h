#ifndef ENTITY_H
#define ENTITY_H

#include "../include/glm/glm.hpp"
#include "../include/glm/gtc/matrix_transform.hpp"
#include "../include/glm/gtc/type_ptr.hpp"

#include "math/vector3.h"
#include "render/renderer.h"

class Entity{
public:
  glm::vec3 Position;
  glm::vec3 Velocity;

  glm::vec3 Size = glm::vec3(40.0f, 40.0f, 1.0f);
  Renderer* EntityRenderer;

public:
  Entity();
  Entity(Renderer* EntityRenderer);
  Entity(Renderer* EntityRenderer, Vector3 Position, Vector3 Velocity);

  void Render();
}; 
#endif
