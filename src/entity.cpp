#include "entity.h"

Entity::Entity()
: Position(glm::vec3(0.0f)), Velocity(glm::vec3(0.0f)) {}

Entity::Entity(Renderer* EntityRenderer)
: EntityRenderer(EntityRenderer), Position(glm::vec3(0.0f)), Velocity(glm::vec3(0.0f)) {
  Texture.LoadSprite("C:/Users/kaiwi/OneDrive/Desktop/Photos/Ktten.jpg");
}

void Entity::Render(){
  EntityRenderer->BindShader();
  EntityRenderer->BindVAO();

  glm::mat4 model         = glm::mat4(1.0f); 
  glm::mat4 view          = glm::mat4(1.0f);
  glm::mat4 projection    = glm::mat4(1.0f);

  view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

  projection = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f); 
  //TODO(Kai): Figure out what to do with the height and width
  //Maybe bind it outside the renderer function if not planning to change the perspective?
  //Maybe not for windows resizing

  model = glm::translate(model, Position);
  model = glm::scale(model, Size);

  EntityRenderer->SetMatrix4("Model", model);
  EntityRenderer->SetMatrix4("View", view);
  EntityRenderer->SetMatrix4("Projection", projection);
  EntityRenderer->SetVector4("Colour", Colour);
  Texture.UseSprite();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  EntityRenderer->UnbindVAO();
}

