#ifndef WORLD_H
#define WORLD_H

#include<iostream>

#include "render/sprite_manager.h"
#include "tile.h"

class World{
public:
  Tile LevelTiles[1024]; //May increase the number of tiles not sure what a good amount would be
  unsigned int Height;
  unsigned int Width;
  unsigned int TileSize = 40;

  SpriteManager Texture;

public: 
  World();
  World(Renderer *WorldRenderer, unsigned int Height, unsigned int Width);
  ~World();

  void LoadWorld(std::string FilePath);
  void RenderWorld();
  void LoadSprites();
  void BindSpritesToTiles();
};

#endif
