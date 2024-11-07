#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include "../../include/glad/glad.h"
#include "../../include/GLFW/glfw3.h"


#include "../../include/stb_image/stb_image.h"

#include <iostream>

class SpriteManager{
public:
  unsigned int ID;
  int Width, Height, nrChannels;
  bool SpriteLoaded = false;

public:
  SpriteManager();

  void LoadSprite(const char* FilePath);
  void UseSprite();
};

#endif
