#ifndef TILE_H
#define TILE_H

#include "../include/glm/glm.hpp"
#include "../include/glm/gtc/matrix_transform.hpp"
#include "../include/glm/gtc/type_ptr.hpp"

#include "render/renderer.h"

enum TILETYPE{ 
  UNWALKABLE, // 0 is tiles player can not step on
  WALKABLE, // 1 is tiles player can walk on
  DOORWAY, // 2 is used to transistions between worlds/levels
  SPAWN // 3 is where the player will spawn on the map 
}; 

class Tile { 
public:
  glm::vec3 WorldPosition;
  TILETYPE Type; 
  Renderer *P_TileRenderer; //Might not want to story a pointer for each indvidual tile?
  glm::vec3 Size = glm::vec3(40.0f, 40.0f, 1.0f);
  bool Initalized = false; 

public:
  Tile();
  Tile(Renderer *TileRenderer);

  void RenderTile();
};

#endif
