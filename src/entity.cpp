#include "entity.h"

Entity::Entity()
: Position(glm::vec3(0.0f)), Velocity(glm::vec3(0.0f)) {}

Entity::Entity(Renderer* EntityRenderer)
: EntityRenderer(EntityRenderer), Position(glm::vec3(0.0f)), Velocity(glm::vec3(0.0f)) {}

void Entity::Render(){

  EntityRenderer->BindShader();
  EntityRenderer->BindVAO();

  glm::mat4 model         = glm::mat4(1.0f); 
  glm::mat4 view          = glm::mat4(1.0f);
  glm::mat4 projection    = glm::mat4(1.0f);

  view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

  projection = glm::ortho(0.0f, 480.0f, 0.0f, 640.0f, -1.0f, 100.0f); //TODO(Kai): Figure out what to do with the height and width
  //projection = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f); //TODO(Kai): Figure out what to do with the height and width
  //Maybe bind it outside the renderer function if not planning to change the perspective?
  //Maybe not for windows resizing

  model = glm::translate(model, Position);
  Size.y = Size.x * (640.0f/480.0f); // Need to sort out the scale to make perfect squares
  model = glm::scale(model, Size);
  EntityRenderer->SetMatrix4("Model", model);
  EntityRenderer->SetMatrix4("View", view);
  EntityRenderer->SetMatrix4("Projection", projection);
  std::cout << Size.x << ", " << Size.y<< std::endl;

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  EntityRenderer->UnbindVAO();
}

