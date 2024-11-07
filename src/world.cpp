#include "world.h"

#include <fstream>

World::World() {}

World::World(Renderer *WorldRenderer, unsigned int Width, unsigned int Height)
    : Height(Height), Width(Width) {
  for(int i =0; i < 1024; i++) {
    LevelTiles[i].P_TileRenderer = WorldRenderer;
  }
  LoadWorld("W:/2Dengine/res/level/world.lvl");
  LoadSprites();
  BindSpritesToTiles();
}

World::~World() {}

void World::LoadWorld(std::string FilePath) {
  int i = 0;
  int XPos = 0;
  int YPos = 0;

  std::ifstream WorldLevel(FilePath);
  char c;

  while(WorldLevel.get((char) c)) {
    if(i > (sizeof(LevelTiles)/sizeof(*LevelTiles))) {
       std::cout << "Level is greater then max tiles allowed" << std::endl;
       return;
    }
    switch (c) {
      case '0':
        LevelTiles[i].Type = UNWALKABLE;
        LevelTiles[i].WorldPosition.x = (float)XPos * TileSize;
        LevelTiles[i].WorldPosition.y = (float)YPos * TileSize;
        LevelTiles[i].Initalized = true;
        i++;
        XPos++;
        break;
      case '1': 
        LevelTiles[i].Type = WALKABLE;
        LevelTiles[i].WorldPosition.x = (float)XPos * TileSize;
        LevelTiles[i].WorldPosition.y = (float)YPos * TileSize;
        LevelTiles[i].Initalized = true;
        i++;
        XPos++;
        break;
      case '2':
        LevelTiles[i].Type = DOORWAY;
        LevelTiles[i].WorldPosition.x = (float)XPos * TileSize;
        LevelTiles[i].WorldPosition.y = (float)YPos * TileSize;
        LevelTiles[i].Initalized = true;
        i++;
        XPos++;
        break;
      case '3':
        LevelTiles[i].Type = SPAWN;
        LevelTiles[i].WorldPosition.x = (float)XPos * TileSize;
        LevelTiles[i].WorldPosition.y = (float)YPos * TileSize;
        LevelTiles[i].Initalized = true;
        i++;
        XPos++;
        break;
      case '\n':
        XPos = 0;
        YPos++;
        break;
    }
  }
}


void World::RenderWorld() {
  for(int i =0; i < 1024; i++) {
    if(LevelTiles[i].Initalized == true){
      LevelTiles[i].RenderTile();
    }
    else {break;}
  }
}


void World::LoadSprites() {
  Texture.LoadSprite("C:/Users/kaiwi/OneDrive/Desktop/Photos/Tile.jpg");
}

void World::BindSpritesToTiles() {
  for(int i = 0; i < 1024; i++) {
    if(LevelTiles[i].Initalized == true){
      LevelTiles[i].Texture = Texture;
    }
    else {break;}
  }
}

