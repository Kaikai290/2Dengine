#include "entity.h"

Entity::Entity()
: Position(0, 0, 0), Velocity(0, 0, 0) {}

Entity::Entity(Renderer* EntityRenderer)
: EntityRenderer(EntityRenderer), Position(0, 0, 0), Velocity(0, 0, 0) {}

void Entity::Render(){

  EntityRenderer->BindShader();
  EntityRenderer->BindVAO();

  glm::mat4 model         = glm::mat4(1.0f); 
  glm::mat4 view          = glm::mat4(1.0f);
  glm::mat4 projection    = glm::mat4(1.0f);

  view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
  projection = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f); //TODO(Kai): Figure out what to do with the height and width
  //Maybe bind it outside the renderer function if not planning to change the perspective?
  //Maybe not for windows resizing


  EntityRenderer->SetMatrix4("Model", model);
  EntityRenderer->SetMatrix4("View", view);
  EntityRenderer->SetMatrix4("Projection", projection);

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  EntityRenderer->UnbindVAO();
}

