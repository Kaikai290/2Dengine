#include "sprite_manager.h"

SpriteManager::SpriteManager(){
};


void SpriteManager::LoadSprite(const char* FilePath){ 
  glGenTextures(1, &ID);
  glBindTexture(GL_TEXTURE_2D, ID); 
  // set the texture wrapping parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  // set texture filtering parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    


  unsigned char* Data;

  Data = stbi_load(FilePath, &Width, &Height, &nrChannels, 4);
  if(Data) {
    SpriteLoaded = true;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else {
    std::cout << "Failed to Load Texture" << std::endl;
  }
  stbi_image_free(Data);
}

void SpriteManager::UseSprite(){
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, ID);
}
