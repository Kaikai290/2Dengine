#ifndef ENTITY_H
#define ENTITY_H

#include "vector3.h"

class Entity{
public:
  Vector3 Position;
  Vector3 Velocity;

public:
  Entity();
  Entity(Vector3 Position, Vector3 Velocity);
}; 
#endif
