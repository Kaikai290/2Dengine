#include "world.h"

#include <fstream>
#include <sstream>

World::World(){
  LoadWorld("W:/2Dengine/res/level/world.lvl");
}

World::World(Renderer *WorldRenderer, unsigned int Height, unsigned int Width)
  : Height(Height), Width(Width) {
  LoadWorld("W:/2Dengine/res/level/world.lvl");
  P_WorldRenderer = WorldRenderer;
}

World::~World(){
}

void World::LoadWorld(std::string FilePath){
  int i = 0;

  std::ifstream WorldLevel(FilePath);
  if(!WorldLevel.is_open()){
    std::cout << "Failed to open World Level file" << std::endl;
  }

  std::stringstream WorldLevelStream;
  WorldLevelStream << WorldLevel.rdbuf();
  
  Level = WorldLevelStream.str();

  WorldLevel.close();
}

void World::RenderWorld(){

}
