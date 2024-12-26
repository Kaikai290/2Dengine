#include "world.h"

#include <fstream>
#include <memory.h>

World::World() {}

World::World(Renderer *WorldRenderer, unsigned int Width, unsigned int Height)
    : Height(Height), Width(Width) {
}

World::~World() {
  free(LevelTiles);
}
void World::Init(Renderer *LevelRenderer) {
  LoadWorld("W:/2Dengine/res/level/world.lvl");
  ApplyRendererToTiles(LevelRenderer);
  LoadSprites();
  BindSpritesToTiles();
}

void World::LoadWorld(const char *FilePath) {
  int i = 0;
  int XPos = 0;
  int YPos = 0;

  std::ifstream WorldLevel(FilePath);
  char c;

  LevelTiles = (Tile *)malloc(sizeof(Tile) * 200);

  while(WorldLevel.get(c)) {
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
        LevelTiles[i].Size = glm::vec3(40.0f, 40.0f, 1.0f);
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
  //LevelTiles = (Tile *)malloc(i * sizeof(Tile));
}

void World::ApplyRendererToTiles(Renderer *WorldRenderer) {
  for(int i =0; i < 192; i++) {
    LevelTiles[i].P_TileRenderer = WorldRenderer;
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

