#include "tile.h"

Tile::Tile(){
}

Tile::Tile(Renderer *TileRenderer)
  : P_TileRenderer(TileRenderer) {
}

void Tile::RenderTile() {
  P_TileRenderer->BindShader();
  P_TileRenderer->BindVAO();

  glm::mat4 model         = glm::mat4(1.0f); 
  glm::mat4 view          = glm::mat4(1.0f);
  glm::mat4 projection    = glm::mat4(1.0f);

  view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

  projection = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f); 
   //TODO(Kai): Figure out what to do with the height and width
  //Maybe bind it outside the renderer function if not planning to change the perspective?
  //Maybe not for windows resizing

  model = glm::translate(model, glm::vec3(WorldPosition.x +20.0f, WorldPosition.y +20.0f, 0.0f));
  model = glm::scale(model, Size);

  P_TileRenderer->SetMatrix4("Model", model);
  P_TileRenderer->SetMatrix4("View", view);
  P_TileRenderer->SetMatrix4("Projection", projection);
  P_TileRenderer->SetVector4("Colour", glm::vec4(WorldPosition.x / 640.0f, WorldPosition.y / 480.0f, /*(WorldPosition.x * WorldPosition.y) / (640.0f * 480.0f)*/ 0.8f, 1.0f));

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  P_TileRenderer->UnbindVAO();
}
