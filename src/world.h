#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <fstream>
#include <memory.h>

#include "render/sprite_manager.h"
#include "tile.h"

class World{
public:
  Tile* LevelTiles; //Todo: Use malloc to allow flexible amount of game tiles
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
  bool ViableChar(char c);
};

#endif

