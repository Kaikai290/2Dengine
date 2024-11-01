#ifndef WORLD_H
#define WORLD_H

#include<iostream>

#include "render/renderer.h"

class World{
public:
  Renderer *P_WorldRenderer;
  std::string Level;
  unsigned int Height;
  unsigned int Width;

public: 
  World();
  World(Renderer *WorldRenderer, unsigned int Height, unsigned int Width);
  ~World();

  void LoadWorld(std::string FilePath);
  void RenderWorld();
};

#endif
