#ifndef ENTITY_H
#define ENTITY_H

#include "../include/glm/glm.hpp"
#include "../include/glm/gtc/matrix_transform.hpp"
#include "../include/glm/gtc/type_ptr.hpp"

#include "math/vector3.h"
#include "render/renderer.h"

class Entity{
public:
  Vector3 Position;
  Vector3 Velocity;

  Renderer* EntityRenderer;

public:
  Entity();
  Entity(Renderer* EntityRenderer);
  Entity(Renderer* EntityRenderer, Vector3 Position, Vector3 Velocity);

  void Render();
}; 
#endif
