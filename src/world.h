#ifndef WORLD_H
#define WORLD_H

#include<iostream>

#include "render/sprite_manager.h"
#include "tile.h"

class World{
public:
  Tile* LevelTiles; //Todo: Use malloc to allow flexible amount of game tiles
  Tile oLevelTiles[1024];
  unsigned int Height;
  unsigned int Width;
  unsigned int TileSize = 40;

  SpriteManager Texture;

public: 
  World();
  World(Renderer *WorldRenderer, unsigned int Height, unsigned int Width);
  ~World();

  void Init(Renderer *LevelRenderer);
  void LoadWorld(const char* FilePath);
  void ApplyRendererToTiles(Renderer *WorldRenderer);
  void RenderWorld();
  void LoadSprites();
  void BindSpritesToTiles();
};

#endif

